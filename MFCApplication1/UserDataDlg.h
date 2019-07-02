#pragma once
#include <afxdialogex.h>
class UserDataDlg ://“账户操作”界面的类
	public CDialogEx//公有继承了“C扩展窗口”类
{
protected:
	HICON m_hIcon;//图标
	virtual BOOL OnInitDialog();////当窗口被初始化时执行此函数
public:
	UserDataDlg(CWnd* pParent = nullptr);//当窗口被构造时执行此函数，设置父窗口，如果参数为空，则没有父窗口
	DECLARE_MESSAGE_MAP()//对此类的内容进行实现

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USERDATA_DIALOG };//告诉VS的设计器，本界面的资源值
#endif
	afx_msg void OnClickedButtonUserdataExit();//当“退出”按钮被点击时，执行此函数
	afx_msg void OnClickedButtonUserdataLogout();//当“注销”按钮被点击时，执行此函数
	afx_msg void OnClickedButtonInmoney();//当“储蓄”按钮被点击时，执行此函数
	afx_msg void OnClickedButtonOutmoney();
	afx_msg void OnClickedButtonChangepassword();
};

