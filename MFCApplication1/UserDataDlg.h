#pragma once
#include <afxdialogex.h>
class UserDataDlg ://���˻��������������
	public CDialogEx//���м̳��ˡ�C��չ���ڡ���
{
protected:
	HICON m_hIcon;//ͼ��
	virtual BOOL OnInitDialog();////�����ڱ���ʼ��ʱִ�д˺���
public:
	UserDataDlg(CWnd* pParent = nullptr);//�����ڱ�����ʱִ�д˺��������ø����ڣ��������Ϊ�գ���û�и�����
	DECLARE_MESSAGE_MAP()//�Դ�������ݽ���ʵ��

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USERDATA_DIALOG };//����VS������������������Դֵ
#endif
	afx_msg void OnClickedButtonUserdataExit();//�����˳�����ť�����ʱ��ִ�д˺���
	afx_msg void OnClickedButtonUserdataLogout();//����ע������ť�����ʱ��ִ�д˺���
	afx_msg void OnClickedButtonInmoney();//���������ť�����ʱ��ִ�д˺���
	afx_msg void OnClickedButtonOutmoney();
	afx_msg void OnClickedButtonChangepassword();
};

