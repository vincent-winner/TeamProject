#pragma once
#include <afxdialogex.h>
class ChangePasswordDlg :
	public CDialogEx
{
public:

#ifdef AFX_DESIGN_TIME	
	enum { IDD = IDD_INMONEY };//����VS������������������Դֵ
#endif


protected:
	HICON m_hIcon;//ͼ��
	virtual BOOL OnInitDialog();//�����ڱ���ʼ��ʱִ�д˺���

public:
	ChangePasswordDlg(CWnd* pParent = nullptr);//�����ڱ�����ʱִ�д˺��������ø����ڣ��������Ϊ�գ���û�и�����
	DECLARE_MESSAGE_MAP()//�Դ�������ݽ���ʵ��
	afx_msg void OnBnClickedButtonChangepasswordCancel();
	afx_msg void OnBnClickedButtonChangepasswordOk();
};

