#pragma once
#include <afxdialogex.h>
class RegisterDialog ://��ע����桱��
	public CDialogEx//���м̳��ˡ�C��չ���ڡ���
{
protected:
	HICON m_hIcon;//ͼ��
	virtual BOOL OnInitDialog();//�����ڱ���ʼ��ʱִ�д˺���
public:
	RegisterDialog(CWnd* pParent = nullptr);//�����ڱ�����ʱִ�д˺��������ø����ڣ��������Ϊ�գ���û�и�����


	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REGISTER };//����VS������������������Դֵ
#endif


	afx_msg void OnUpdateIddRegister(CCmdUI* pCmdUI);//����������������ʱ��ִ�д˺���
	DECLARE_MESSAGE_MAP()//�Դ�������ݽ���ʵ��
	afx_msg void OnClickedCancleButton();//����ȡ������ť�����ʱ��ִ�д˺���
	afx_msg void OnIddRegister();//�������ע��ʱִ�д˺���
	afx_msg void OnClickedRegisterButton();//����ע�ᡱ��ť�����ʱ��ִ�д˺���
};

