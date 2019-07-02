#include "pch.h"
#include "UserDataDlg.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "resource.h"

#include "InMoney.h"
#include "OutMoney.h"
#include "ChangePasswordDlg.h"

/*
	�������ģʽΪDebug����ִ�����º궨��
	Debugģʽ�ĳ�����Խ��е���
*/
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//��ʼӳ�䱾�Ի����ڵ��¼�
BEGIN_MESSAGE_MAP(UserDataDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_USERDATA_EXIT, &UserDataDlg::OnClickedButtonUserdataExit)//ӳ�䡰�˳���ť��������¼�
	ON_BN_CLICKED(IDC_BUTTON_USERDATA_LOGOUT, &UserDataDlg::OnClickedButtonUserdataLogout)//ӳ�䡰ע����ť��������¼�
	ON_BN_CLICKED(IDC_BUTTON_INMONEY, &UserDataDlg::OnClickedButtonInmoney)//ӳ�䡰���ť��������¼�
	ON_BN_CLICKED(IDC_BUTTON_OUTMONEY, &UserDataDlg::OnClickedButtonOutmoney)
	ON_BN_CLICKED(IDC_BUTTON_CHANGEPASSWORD, &UserDataDlg::OnClickedButtonChangepassword)
END_MESSAGE_MAP()
//���Ի����ڵ��¼�ӳ�����

UserDataDlg::UserDataDlg(CWnd* pParent /*=nullptr*/)//���˻����������ڵĹ��췽��������Ϊ���򸸴���ָ��Ϊ��
	: CDialogEx(IDD_USERDATA_DIALOG, pParent)//˽�м̳С�C��չ���ڡ��࣬Ϊ���˻����������ڰ���Դ
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);//Ϊ���˻��������������ͼ��
}

BOOL UserDataDlg::OnInitDialog() //�����ڳ�ʼ��ʱִ�д˺���
{
	this->SetIcon(m_hIcon, FALSE);//Ϊ��������ͼ��
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
	if (MessageBox(_T("ȷ��Ҫ�˳���"), _T("��ʾ"), MB_YESNO | MB_DEFBUTTON2) == IDYES)
	{
		this->SendMessage(WM_CLOSE);
	}
}


void UserDataDlg::OnClickedButtonUserdataLogout()
{
	if (MessageBox(_T("ȷ��Ҫע����"), _T("��ʾ"), MB_YESNO | MB_DEFBUTTON2) == IDYES)
	{
		CMFCApplication1Dlg mainDlg;
		this->SendMessage(WM_CLOSE);
		mainDlg.DoModal();
	}
	
}


void UserDataDlg::OnClickedButtonInmoney()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	InMoneyDlg inMoneyDlg;
	inMoneyDlg.DoModal();
}


void UserDataDlg::OnClickedButtonOutmoney()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OutMoneyDlg outMoneyDlg;
	outMoneyDlg.DoModal();
}


void UserDataDlg::OnClickedButtonChangepassword()
{
	ChangePasswordDlg chPasswdDlg;
	chPasswdDlg.DoModal();
}
