#include "pch.h"
#include "UserDataDlg.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "resource.h"

#include "InMoney.h"
#include "OutMoney.h"
#include "ChangePasswordDlg.h"

/*
	如果编译模式为Debug，则执行以下宏定义
	Debug模式的程序可以进行调试
*/
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//开始映射本对话框内的事件
BEGIN_MESSAGE_MAP(UserDataDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_USERDATA_EXIT, &UserDataDlg::OnClickedButtonUserdataExit)//映射“退出按钮被点击”事件
	ON_BN_CLICKED(IDC_BUTTON_USERDATA_LOGOUT, &UserDataDlg::OnClickedButtonUserdataLogout)//映射“注销按钮被点击”事件
	ON_BN_CLICKED(IDC_BUTTON_INMONEY, &UserDataDlg::OnClickedButtonInmoney)//映射“储蓄按钮被点击”事件
	ON_BN_CLICKED(IDC_BUTTON_OUTMONEY, &UserDataDlg::OnClickedButtonOutmoney)
	ON_BN_CLICKED(IDC_BUTTON_CHANGEPASSWORD, &UserDataDlg::OnClickedButtonChangepassword)
END_MESSAGE_MAP()
//本对话框内的事件映射结束

UserDataDlg::UserDataDlg(CWnd* pParent /*=nullptr*/)//“账户操作”窗口的构造方法，参数为空则父窗口指针为空
	: CDialogEx(IDD_USERDATA_DIALOG, pParent)//私有继承“C扩展窗口”类，为“账户操作”窗口绑定资源
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);//为“账户操作”窗口添加图标
}

BOOL UserDataDlg::OnInitDialog() //当窗口初始化时执行此函数
{
	this->SetIcon(m_hIcon, FALSE);//为窗口设置图标
	FileRW file("userdata"),userLineNumberFile("userlinenumber");
	ArrayList<CString>* userNameArr = file.getColumn(0);
	ArrayList<CString>* idArr = file.getColumn(2);
	ArrayList<CString>* moneyArr = file.getColumn(3);
	CString userLineNumStr = userLineNumberFile.getColumn(0)->get(0);
	int userLineNum = _ttoi(userLineNumStr);
	GetDlgItem(IDC_STATIC_USERNAME)->SetWindowText(userNameArr->get(userLineNum));
	GetDlgItem(IDC_STATIC_ID)->SetWindowText(idArr->get(userLineNum));
	GetDlgItem(IDC_STATIC_MONEY)->SetWindowText(moneyArr->get(userLineNum));
	return TRUE;
}



void UserDataDlg::OnClickedButtonUserdataExit()
{
	if (MessageBox(_T("确定要退出吗？"), _T("提示"), MB_YESNO | MB_DEFBUTTON2) == IDYES)
	{
		this->SendMessage(WM_CLOSE);
	}
}


void UserDataDlg::OnClickedButtonUserdataLogout()
{
	if (MessageBox(_T("确定要注销吗？"), _T("提示"), MB_YESNO | MB_DEFBUTTON2) == IDYES)
	{
		CMFCApplication1Dlg mainDlg;
		this->SendMessage(WM_CLOSE);
		mainDlg.DoModal();
	}
	
}


void UserDataDlg::OnClickedButtonInmoney()
{
	// TODO: 在此添加控件通知处理程序代码
	InMoneyDlg inMoneyDlg;
	inMoneyDlg.DoModal();
}


void UserDataDlg::OnClickedButtonOutmoney()
{
	// TODO: 在此添加控件通知处理程序代码
	OutMoneyDlg outMoneyDlg;
	outMoneyDlg.DoModal();
}


void UserDataDlg::OnClickedButtonChangepassword()
{
	ChangePasswordDlg chPasswdDlg;
	chPasswdDlg.DoModal();
}
