#include "pch.h"
#include "RegisterDialog.h"
#include "MFCApplication1.h"
#include "resource.h"

/*
	如果编译模式为Debug，则执行以下宏定义
	Debug模式的程序可以进行调试
*/
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//开始映射本对话框内的事件
BEGIN_MESSAGE_MAP(RegisterDialog, CDialogEx)
	ON_UPDATE_COMMAND_UI(IDD_REGISTER, &RegisterDialog::OnUpdateIddRegister)//映射“更新窗口命令”事件
	ON_BN_CLICKED(IDC_CANCLE_BUTTON, &RegisterDialog::OnClickedCancleButton)//映射“取消按钮被按下”事件
	ON_COMMAND(IDD_REGISTER, &RegisterDialog::OnIddRegister)//映射“命令”事件
	ON_BN_CLICKED(IDC_REGISTER_BUTTON, &RegisterDialog::OnClickedRegisterButton)//映射“注册按钮被按下”事件
END_MESSAGE_MAP()
//本对话框内的事件映射结束



RegisterDialog::RegisterDialog(CWnd* pParent /*=nullptr*/)//“注册界面”窗口的构造方法，参数为空则父窗口指针为空
	: CDialogEx(IDD_REGISTER, pParent)//私有继承“C扩展窗口”类，为“注册界面”窗口绑定资源
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);//为“注册界面”窗口添加图标
}


void RegisterDialog::OnUpdateIddRegister(CCmdUI* pCmdUI)//更新句柄时执行此函数
{
}


void RegisterDialog::OnClickedCancleButton()//当取消按钮被点击时执行下列函数
{
	this->SendMessage(WM_CLOSE);//向“注册界面”窗口发送“关闭窗口”消息
}


BOOL RegisterDialog::OnInitDialog()//当窗口初始化时执行此函数
{
	this->SetIcon(m_hIcon,FALSE);//为窗口设置图标
	return TRUE;//返回一个值让程序可以正常运行，此语句没有用
}

void RegisterDialog::OnIddRegister()//句柄被添加时执行此函数
{
	
}


void RegisterDialog::OnClickedRegisterButton()//点击注册按钮时会执行此函数
{
	ArrayList<CString>* arrayList_Line = new ArrayList<CString>();//建立一个数组将文件中所有内容存入数组
	CString userName, password, id, cardId;//用户名，密码，身份证，卡号
	CEdit* cedit;//编辑框对象
	cedit = (CEdit*)GetDlgItem(IDC_EDIT1);//绑定编辑框对象
	cedit->GetWindowText(userName);//获取文本框内信息
	userName.ReleaseBuffer();//调整字符串缓冲区
	cedit = (CEdit*)GetDlgItem(IDC_EDIT2);//绑定编辑框对象
	cedit->GetWindowText(password);//获取文本框内信息
	password.ReleaseBuffer();//调整字符串缓冲区
	cedit = (CEdit*)GetDlgItem(IDC_EDIT3);//绑定编辑框对象
	cedit->GetWindowText(id);//获取文本框内信息
	id.ReleaseBuffer();//调整字符串缓冲区
	srand((size_t)time(NULL));//设置随机数种子

	//开始设置随机卡号
	for (int i = 0; i < 11; i++) {
		cardId += char(rand() % 10 + '0');
	}
	//随机卡号设置完成

	arrayList_Line->add(userName);//将姓名添加进数组
	arrayList_Line->add(password);//将密码添加进数组
	arrayList_Line->add(id);//将身份证号添加进数组
	arrayList_Line->add(CString("0"));//设置新用户余额为0
	arrayList_Line->add(cardId);//将用户卡号添进数组

	FileRW file("userdata");//打开文件userdata

	BOOL isExists=FALSE;//判断账户是否存在，FALSE为不存在，可以进行添加账户操作，TRUE为已经存在，不可以进行添加用户操作
	ArrayList<CString>* col1 = file.getColumn(0);//获取所有用户名
	ArrayList<CString>* col3 = file.getColumn(2);//获取所有身份证号
	ArrayList<CString>* col5 = file.getColumn(4);//获取所有卡号
	for (int i = 0; i < col1->size(); i++) {
		if (col1->get(i).Compare(userName)==0 ||//判断用户名是否已经被注册
			col3->get(i).Compare(id)==0||//判断身份证是否已经被使用
			col5->get(i).Compare(cardId)==0) {//判断卡号是否已经被注册
			isExists = TRUE;//如果以上三条信息有任意一条存在，则判断该账户已经被建立
			delete col1, col3, col5;//删除没用的数组
			break;
		}
	}

	if (!(userName=="" || password=="" || id=="")) {//如何输入不为空
		if (!isExists) {//如果账户已经存在
			file.addln(file.composeCString(arrayList_Line));//将数组写进文件
			MessageBox(_T("您的卡号为：") + cardId, _T("注册成功"), MB_OK);//弹出消息框
			delete arrayList_Line;//删除数组
			this->SendMessage(WM_CLOSE);//向本窗口关闭窗口消息
		}else {
			MessageBox(_T("您的用户名、身份证或卡号已经被使用，请重新注册"), _T("注册失败"), MB_OK);//弹出消息框
			delete arrayList_Line;//删除数组
		}
	}
	else {
		MessageBox(_T("您的输入信息为空或包含不可识别的字符，请重新输入"), _T("注册失败"), MB_OK);//弹出消息框
		delete arrayList_Line;//删除数组
	}
	
}
