#pragma once
/**
	���ļ������ˡ�������桱���࣬�������ɡ�������桱����
*/
#include <afxdialogex.h>
class OutMoneyDlg ://��������桱��
	public CDialogEx//���м̳��ˡ�C��չ���ڡ���
{
public:

#ifdef AFX_DESIGN_TIME	
	enum { IDD = IDD_OUTMONEY };//����VS������������������Դֵ
#endif

protected:
	HICON m_hIcon;//ͼ��
	virtual BOOL OnInitDialog();//�����ڱ���ʼ��ʱִ�д˺���

public:
	OutMoneyDlg(CWnd* pParent = nullptr);//�����ڱ�����ʱִ�д˺��������ø����ڣ��������Ϊ�գ���û�и�����
	DECLARE_MESSAGE_MAP()//�Դ�������ݽ���ʵ��
	afx_msg void OnClickedButtonOutmoneyCancel();
	afx_msg void OnClickedButtonOutmoneyOk();
};