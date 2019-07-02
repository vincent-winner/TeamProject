
// MFCApplication1Dlg.h: 头文件
//

#pragma once


// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg // 声明“主对话框”类
	: public CDialogEx// 公有继承了“C扩展窗口”类
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// //当窗口被构造时执行此函数，设置父窗口，如果参数为空，则没有父窗口

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };//告诉VS的设计器，本界面的资源值
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;//图标

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();//当窗口被初始化时执行此函数
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);//当“系统消息”命令被执行时执行此函数
	afx_msg void OnPaint();//绘制界面
	afx_msg HCURSOR OnQueryDragIcon();//设置鼠标样式
	DECLARE_MESSAGE_MAP()//对此类的内容进行实现
public:
	afx_msg void OnClickedButton1();//当“登录”按钮被点击时执行此函数
	afx_msg void OnClickedButton3();//当“退出”按钮被点击时执行此函数
	afx_msg void OnClickedButton2();//当“注册”按钮被点击时执行此函数
	afx_msg void OnIdclose();//当窗口关闭时，执行此函数
	afx_msg void OnClickedButton5();//当“制作人员名单”按钮被点击时执行此函数
};
