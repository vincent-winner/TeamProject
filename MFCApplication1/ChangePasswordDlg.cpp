#include "pch.h"
#include "ChangePasswordDlg.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"

#include "UserDataDlg.h"

//如果编译模式为“Debug”，则编译Debug版程序供调试使用
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//开始映射本对话框内的事件
BEGIN_MESSAGE_MAP(ChangePasswordDlg, CDialogEx)

	ON_BN_CLICKED(IDC_BUTTON_CHANGEPASSWORD_CANCEL, &ChangePasswordDlg::OnBnClickedButtonChangepasswordCancel)
	ON_BN_CLICKED(IDC_BUTTON_CHANGEPASSWORD_OK, &ChangePasswordDlg::OnBnClickedButtonChangepasswordOk)
END_MESSAGE_MAP()
//本对话框内的事件映射结束

ChangePasswordDlg::ChangePasswordDlg(CWnd* pParent /*=nullptr*/)//	“修改密码”窗口的构造方法，参数为空则父窗口指针为空
	: CDialogEx(IDD_CHANGEPASSWORD, pParent)//		为“修改密码”窗口绑定资源
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);//为“修改密码”窗口添加图标
}

BOOL ChangePasswordDlg::OnInitDialog() // 当对话框初始化时执行此函数
{
	this->SetIcon(m_hIcon, FALSE);// 为“修改密码”窗口设置图标
	return TRUE;//返回一个没有意义的1
}


void ChangePasswordDlg::OnBnClickedButtonChangepasswordCancel()//当“取消”按钮被按下时，会执行此函数
{
	this->SendMessage(WM_CLOSE);//向本窗口发送“关闭窗口”消息
	
}


void ChangePasswordDlg::OnBnClickedButtonChangepasswordOk()//当“确认修改”按钮被按下时，会执行此函数
{
	FileRW file("userdata"), userLineNumberFile("userlinenumber");//打开文件“userdata”和“userlinenumber”
	CString userLineNumberStr = userLineNumberFile.getColumn(0)->get(0);//将“userlinenumber”文件的内容存进字符串
	int userLineNumber = _ttoi(userLineNumberStr);//将userlinenumber的内容转化为整数

	ArrayList<CString>* passwordArr = file.getColumn(1);//获取所有人的密码

	//开始获取文本框内容
	CEdit *oldPwdBox,*newPwdBox,*reInputPwdBox;//创建输入框类型指针,用来指向文本输入框
	oldPwdBox = (CEdit*)GetDlgItem(IDC_EDIT_CHANGEPASSWORD_OLDPASSWORD);//将输入框类型指针指向输入框
	newPwdBox = (CEdit*)GetDlgItem(IDC_EDIT_CHANGEPASSWORD_NEWPASSWORD);//将输入框类型指针指向输入框
	reInputPwdBox = (CEdit*)GetDlgItem(IDC_EDIT_CHANGEPASSWORD_REINPUTPASSWORD);//将输入框类型指针指向输入框
	CString oldPwdText, newPwdText, reInputPwdText;//创建字符串，用来存储输入框内的密码（旧密码，新密码，重新输入新密码）
	oldPwdBox->GetWindowText(oldPwdText);//将输入框内的密码存进字符串
	newPwdBox->GetWindowText(newPwdText);//将输入框内的密码存进字符串
	reInputPwdBox->GetWindowText(reInputPwdText);//将输入框内的密码存进字符串
	//停止获取文本框内容

	BOOL oldPasswordIsTrue = FALSE;//用来判断旧密码是否正确
	BOOL passwordIsSame=FALSE;//用来判断两次密码是否输入一致

	CString trueOldPassword = passwordArr->get(userLineNumber);//将正确的原密码存入字符串
	if (trueOldPassword.Compare(oldPwdText) == 0) {//如果输入的旧密码是正确的
		oldPasswordIsTrue = TRUE;//旧密码是正确的
	}

	if (newPwdText.Compare(reInputPwdText) == 0) {//如果两次面输入一致
		passwordIsSame = TRUE;//密码输入相同
	}

	if (!oldPasswordIsTrue) {//如果旧密码是错误的
		MessageBox(_T("旧密码输入错误"),_T("提示"),MB_OK);//弹出提示框
		delete passwordArr;
	}else {//如果旧密码是正确的
		if (!passwordIsSame) {//如果两次密码输入不相同
			MessageBox(_T("两次密码输入不相同"), _T("提示"), MB_OK);//弹出提示框
			delete passwordArr;
		}else {//如果旧密码正确，且两次密码输入相同
			passwordArr->set(userLineNumber, newPwdText);//将数组中的密码修改
			file.writeColumn(1,passwordArr);//将数组写入文件
			MessageBox(_T("新密码为： ")+newPwdText,_T("提示"),MB_OK);//弹出提示框
			delete passwordArr;//删除密码数组
			this->SendMessage(WM_CLOSE);//向本窗口发送“关闭窗口”消息
		}
	}
}
