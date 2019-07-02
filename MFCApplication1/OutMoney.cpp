#include "pch.h"
#include "OutMoney.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"

#include "UserDataDlg.h"
//如果编译模式为“Debug”，则编译Debug版程序供调试使用
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//开始映射本对话框内的事件
BEGIN_MESSAGE_MAP(OutMoneyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OUTMONEY_CANCEL, &OutMoneyDlg::OnClickedButtonOutmoneyCancel)
	ON_BN_CLICKED(IDC_BUTTON_OUTMONEY_OK, &OutMoneyDlg::OnClickedButtonOutmoneyOk)
END_MESSAGE_MAP()
//本对话框内的事件映射结束


OutMoneyDlg::OutMoneyDlg(CWnd* pParent /*=nullptr*/)//	“输入储蓄金额”窗口的构造方法，参数为空则父窗口指针为空
	: CDialogEx(IDD_OUTMONEY, pParent)//		为“输入储蓄金额”窗口绑定资源
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);//为“输入储蓄金额”窗口添加图标
}



void OutMoneyDlg::OnClickedButtonOutmoneyCancel()
{
	this->SendMessage(WM_CLOSE);
}

BOOL OutMoneyDlg::OnInitDialog() // 当对话框初始化时执行此函数
{
	this->SetIcon(m_hIcon, FALSE);// 为“输入储蓄金额”窗口设置图标
	return TRUE;//返回一个没有意义的1
}

void OutMoneyDlg::OnClickedButtonOutmoneyOk()
{
	//开始获取输入框内金钱数量
	CEdit* moneyEdit;//创建输入框类型指针
	moneyEdit = (CEdit*)GetDlgItem(IDC_EDIT_OUTMONEY_NUMBER);//将输入框类型指针指向输入框
	CString moneyEditText;//创建字符串，用来存储输入框内的金额
	moneyEdit->GetWindowText(moneyEditText);//将输入框内的金额存进“moneyEditText”变量中
	double inputMoney = _ttof(moneyEditText);//将“字符串”类型的金额转换成“double”类型，供计算使用
	//输入框内金钱数量获取结束

	FileRW file("userdata"), userLineNumberFile("userlinenumber");//打开文件“userdata”和“userlinenumber”
	CString userLineNumberStr = userLineNumberFile.getColumn(0)->get(0);//将“userlinenumber”文件的内容存进字符串
	int userLineNumber = _ttoi(userLineNumberStr);//将userlinenumber的内容转化为整数
	ArrayList<CString>* moneyArr = file.getColumn(3);//获取所有人的金额
	double money = _ttof (moneyArr->get(userLineNumber));//将当前用户的金额（字符串）转换为double类型，供计算使用
	money -= inputMoney;//当前用户的金额-=输入的金额
	
	CString resultMoneyStr;//创建字符串“resultMoneyStr”
	resultMoneyStr.Format(_T("%lf"), money);//将最终金额写进字符串“resultMoneyStr”
	moneyArr->set(userLineNumber, resultMoneyStr);//将当前用户的金额修改为计算之后的金额

	if ((moneyEditText.Compare(_T("")) == 0)) {//如果输入为空
		MessageBox(_T("您的输入为空"), _T("警告"), MB_OK);//弹出对话框（参数1：对话框内容，参数2：对话框标题，参数3：确定按钮）
		delete moneyArr;//删除用来存储所有用户金钱的数组
	}
	else {
		if (!(moneyEditText == moneyEditText.SpanIncluding(_T("0123456789.")))) {//如果输入的内容有除了数字和小数点以外的字符
			MessageBox(_T("您的输入包含非法字符"), _T("警告"), MB_OK);//弹出对话框（参数1：对话框内容，参数2：对话框标题，参数3：确定按钮）
			delete moneyArr;//删除用来存储所有用户金钱的数组
		}
		else {
			file.writeColumn(3, moneyArr);//向文件写入所有用户的金钱信息
			delete moneyArr;//删除用来存储所有用户金钱的数组
			MessageBox(_T("取出：") + moneyEditText + _T("  RMB(CNY)"), _T("取款成功"), MB_OK);//弹出对话框（参数1：对话框内容，参数2：对话框标题，参数3：确定按钮）
			HWND hWnd = ::FindWindow(NULL, _T("账户操作"));//获取标题为“账户操作”的窗口
			EndDialog(0);//向模态对话框发送关闭消息
			SendMessageA(hWnd, WM_CLOSE, NULL, NULL);//向标题为“账户操作”的窗口，发送“关闭本窗口”命令
			UserDataDlg userDataDlg;//创建“用户界面”的窗口7
			userDataDlg.DoModal();//创建模态窗口
		}
	}
}
