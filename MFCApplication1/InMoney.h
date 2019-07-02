#pragma once
/**
	本文件定义了“储蓄界面”的类，用以生成“储蓄界面”窗口
*/
#include <afxdialogex.h>
class InMoneyDlg ://“储蓄界面”类
	public CDialogEx//公有继承了“C扩展窗口”类
{
public:
	
#ifdef AFX_DESIGN_TIME	
	enum { IDD = IDD_INMONEY };//告诉VS的设计器，本界面的资源值
#endif

protected:
	HICON m_hIcon;//图标
	virtual BOOL OnInitDialog();//当窗口被初始化时执行此函数

public:
	InMoneyDlg(CWnd* pParent = nullptr);//当窗口被构造时执行此函数，设置父窗口，如果参数为空，则没有父窗口
	DECLARE_MESSAGE_MAP()//对此类的内容进行实现
	afx_msg void OnBnClickedButtonInmoneyCancel();//当“取消”按钮被点击时执行此函数
	afx_msg void OnClickedButtonInmoneyOk();//当“确认存入”按钮被点击时执行此函数
};

