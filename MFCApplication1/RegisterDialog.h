#pragma once
#include <afxdialogex.h>
class RegisterDialog ://“注册界面”类
	public CDialogEx//公有继承了“C扩展窗口”类
{
protected:
	HICON m_hIcon;//图标
	virtual BOOL OnInitDialog();//当窗口被初始化时执行此函数
public:
	RegisterDialog(CWnd* pParent = nullptr);//当窗口被构造时执行此函数，设置父窗口，如果参数为空，则没有父窗口


	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REGISTER };//告诉VS的设计器，本界面的资源值
#endif


	afx_msg void OnUpdateIddRegister(CCmdUI* pCmdUI);//当本界面句柄被更新时会执行此函数
	DECLARE_MESSAGE_MAP()//对此类的内容进行实现
	afx_msg void OnClickedCancleButton();//当“取消”按钮被点击时，执行此函数
	afx_msg void OnIddRegister();//当句柄被注册时执行此函数
	afx_msg void OnClickedRegisterButton();//当“注册”按钮被点击时，执行此函数
};

