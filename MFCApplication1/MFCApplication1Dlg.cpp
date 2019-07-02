
// MFCApplication1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#include "RegisterDialog.h"
#include "UserDataDlg.h"

//如果编译模式为“Debug”，则编译Debug版程序供调试使用
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


class CAboutDlg // 用于应用程序“关于”菜单项的 CAboutDlg 对话框
	: public CDialogEx//私有继承“C扩展窗口”类
{
public:
	CAboutDlg();//当“帮助”对话框被构造时，执行此构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };//告诉VS的设计器，本界面的资源值
#endif
	protected:
	CRect m_rect;//坐标
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()//对此类的内容进行实现
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);//当“鼠标左键抬起”时，执行此函数
	virtual BOOL OnInitDialog();//当对话框被创建时，执行此函数
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);//当鼠标移动时，执行此函数
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);//当颜色被改变时，执行此函数
};

CAboutDlg::CAboutDlg() //“帮助”对话框的构造函数
	: CDialogEx(IDD_ABOUTBOX)//私有继承“C窗口扩展”类，并绑定此类和窗口资源
{

}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

//开始映射本对话框内的事件
BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_LBUTTONUP()//映射“鼠标左键抬起”事件
	ON_WM_MOUSEMOVE()//映射“鼠标移动”事件
	ON_WM_CTLCOLOR()//映射“改变颜色”事件
END_MESSAGE_MAP()
//本对话框内的事件映射结束


// CMFCApplication1Dlg 对话框
CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)//当窗口被构造时执行此函数，设置父窗口，如果参数为空，则没有父窗口
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)//私有继承“C扩展窗口”类，并为此类绑定窗口资源
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);//为本窗口设置图标
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

//开始映射本对话框内的事件
BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()//映射“系统消息”事件
	ON_WM_PAINT()//映射“绘制界面”事件
	ON_WM_QUERYDRAGICON()//映射“改变鼠标”事件
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnClickedButton1)//映射“‘登录’按钮被点击”事件
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnClickedButton3)//映射“‘退出’按钮被点击”事件
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnClickedButton2)//映射“‘注册’按钮被点击”事件
	ON_COMMAND(IDCLOSE, &CMFCApplication1Dlg::OnIdclose)//映射“发送指令”事件
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnClickedButton5)//映射“‘制作人员名单’按钮被点击”事件
END_MESSAGE_MAP()
//本对话框内的事件映射结束


// CMFCApplication1Dlg 消息处理程序
BOOL CMFCApplication1Dlg::OnInitDialog()//当窗口被初始化时执行此函数
{
	CDialogEx::OnInitDialog();//当窗口被初始化时执行此函数

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);//获取系统菜单
	if (pSysMenu != nullptr)//如果成功获取系统菜单
	{
		BOOL bNameValid;//判断值是否存在
		CString strAboutMenu;//定义字符串“strAboutMenu”，作为标题栏右键菜单的选项
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);//将“关于”界面载入标题栏右键菜单
		ASSERT(bNameValid);//如果不存在系统菜单或关于界面的资源，则终止程序，并抛出异常
		if (!strAboutMenu.IsEmpty())//如果“关于”菜单是空的
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);//将“关于”界面载入标题栏右键菜单
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);//将“关于”界面载入标题栏右键菜单
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)//当系统消息被执行时，执行此函数
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)//如果存在“关于”选项
	{
		CAboutDlg dlgAbout;//创建“关于”对话框界面
		dlgAbout.DoModal();//创建“关于”对话框模态窗口
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);//当系统消息被执行时，执行此函数
	}
}


// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()//绘制界面
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);//向窗口发送绘制图标消息

		//开始获取图标位置，以便使图标居中
		int cxIcon = GetSystemMetrics(SM_CXICON);//获取图标水平坐标
		int cyIcon = GetSystemMetrics(SM_CYICON);//获取图标垂直坐标
		CRect rect;//创建坐标类对象
		GetClientRect(&rect);//绑定坐标类对象
		int x = (rect.Width() - cxIcon + 1) / 2;// 使图标在工作区矩形中居中
		int y = (rect.Height() - cyIcon + 1) / 2;// 使图标在工作区矩形中居中
		//图标已居中

		dc.DrawIcon(x, y, m_hIcon);// 绘制图标
	}
	else
	{
		CDialogEx::OnPaint();//绘制界面
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);//设置光标样式
}


void CMFCApplication1Dlg::OnClickedButton1()//当“登录”按钮被点击时，执行此函数
{
	FileRW file("userdata");//打开文件“userdata”，此文件为用户数据文件
	CEdit *pBox1,*passwordBox;//定义输入框指针，以便获取输入框内的内容


	//定义用户数据所在行数为-1，在接下来的步骤中，如果找到用户数据则获取用户数据所在行数
	//如果没有找到用户数据，则为-1不变
	int userLineNumber=-1;

	pBox1 = (CEdit*)GetDlgItem(IDC_EDIT1);//将指针指向文本框1（用户名/身份证/卡号）
	passwordBox = (CEdit*)GetDlgItem(IDC_EDIT2);//将指针指向文本框2（密码）
	CString box1Text,passwordBoxText;//定义字符串，文本框1的内容（用户名/身份证/卡号）、文本框2的内容（密码）
	pBox1->GetWindowText(box1Text);//获取文本框1的内容到“box1Text”
	passwordBox->GetWindowText(passwordBoxText);//获取文本框2的内容到“passwordBoxText”
	ArrayList<CString>* col1 = file.getColumn(0);//获取所有用户名
	ArrayList<CString>* col3 = file.getColumn(2);//获取所有身份证
	ArrayList<CString>* col5 = file.getColumn(4);//获取所有卡号

	//用（用户名/身份证/卡号）开始查询是否有此用户
	for (int i = 0; i < col1->size(); i++) {
		if (col1->get(i).Compare(box1Text)==0 ||
			col3->get(i).Compare(box1Text)==0 ||
			col5->get(i).Compare(box1Text)==0) {
			userLineNumber = i;
			break;
		}
	}
	//查询结束，找到用户则变量“userLineNumber”为用户所在行数，没有找到不做任何改变

	if (userLineNumber != -1) {//如果找到了用户
		BOOL passwordTrue = FALSE;//定义变量，用来判断密码是否正确（默认不正确）
		FileRW userlinenumberFile("userlinenumber");//打开文件“userlinenumber”，此文件保存用户所在行数，由程序自动创建/删除
		CString userLineNumberStr;//定义字符串用来存储用户所在行数
		userLineNumberStr.Format(_T("%d"),userLineNumber);//将用户所在行数存进字符串
		userlinenumberFile.write(userLineNumberStr);//将用户所在行数写入文件
		ArrayList<CString>* col2 = file.getColumn(1);//获取所有密码

		//开始查询此用户的密码是否正确
		for (int i = 0; i < col2->size(); i++) {
			if (col2->get(i).Compare(passwordBoxText)==0) {
				passwordTrue = TRUE;
				break;
			}
		}
		//查询完毕，密码正确则“passwordTrue”的值为“TRUE”，否则为“FALSE”

		if (passwordTrue) {//如果密码输入正确
			HWND hWnd = ::FindWindow(NULL, _T("银行管理系统"));//寻找名为“银行管理系统”的窗口
			SendMessageA(hWnd,WM_CLOSE,0,0);//向名为“银行管理系统”的窗口发送“关闭窗口”消息
			UserDataDlg userDataDialog;//创建“用户操作界面”类的对象
			userDataDialog.DoModal();//创建“用户操作界面”模态窗口
			delete col1, col2, col3, col5;//删除不再使用的数组
		}else {
			MessageBox(_T("密码错误"),_T("登陆失败"),MB_OK);//弹出消息框（参数1：消息框的内容，参数2：消息框的标题，参数3：为消息框添加确定按钮）
			delete col1, col3, col5;//删除不再使用的数组
		}
	}else {
		MessageBox(_T("未找到您的信息，请检查输入是否有误！"));//弹出消息框
		delete col1, col3, col5;//删除不再使用的数组
	}
}


void CMFCApplication1Dlg::OnClickedButton3()//当“退出”按钮被点击时执行此函数
{
	OnIdclose();//关闭窗口
}


void CMFCApplication1Dlg::OnClickedButton2()//当“注册”按钮被点击时执行此函数
{
	RegisterDialog regDlg;//定义“注册界面”类的对象
	regDlg.DoModal();//创建“注册界面”模态窗口
}


void CMFCApplication1Dlg::OnIdclose()//当窗口被关闭时执行此函数
{
	//弹出消息框
	if (MessageBox(_T("确定要退出吗？"), _T("提示"), MB_YESNO | MB_DEFBUTTON2) == IDYES)//当用户点击“确定”时
	{
		AfxGetMainWnd()->SendMessage(WM_CLOSE);//获取主窗口，并向其发送“关闭窗口”消息
	}
}


void CMFCApplication1Dlg::OnClickedButton5()//当“制作人员名单”按钮被点击时执行此函数
{
	system("start ProducersList.exe");//用系统shell打开“制作人员名单”程序
}


void CAboutDlg::OnLButtonUp(UINT nFlags, CPoint point)//当鼠标左键抬起时，执行此函数
{
	//如果鼠标在指定区域内
	if (point.x > m_rect.left && point.x < m_rect.right && point.y<m_rect.bottom && point.y>m_rect.top)
	{
		ShellExecute(NULL, NULL, _T("README.html"), NULL, NULL, SW_NORMAL);//执行系统命令
	}
	CDialog::OnLButtonUp(nFlags, point);//当鼠标左键抬起时执行此函数
}

BOOL CAboutDlg::OnInitDialog()//当窗口被建立时，执行此函数
{
	GetDlgItem(IDC_STATIC_HREF)->GetWindowRect(&m_rect);//获取“帮助文档”的位置
	ScreenToClient(&m_rect);//将静态文本框设置成超链接
	return TRUE;//返回一个值让程序可以顺利运行，本行代码没有什么用
}


void CAboutDlg::OnMouseMove(UINT nFlags, CPoint point)//当鼠标移动时，执行此函数
{
	CDialogEx::OnMouseMove(nFlags, point);//当鼠标移动时，执行此函数
	if (point.x > m_rect.left && point.x < m_rect.right && point.y < m_rect.bottom && point.y > m_rect.top)//如果鼠标在指定范围内
	{
		HCURSOR hCursor;//创建鼠标指针对象
		hCursor = ::LoadCursor(NULL, IDC_HAND);//链接鼠标指针资源（小手）
		::SetCursor(hCursor);//设置鼠标指针样式（小手）
	}

}


HBRUSH CAboutDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)//为超链接上色
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);//创建画刷对象


	if (pWnd->GetDlgCtrlID() == IDC_STATIC_HREF)//如果是“帮助文档”静态文本的话
	{
		pDC->SetTextColor(RGB(64, 148, 199));//为文字上色（蓝色）
	}


	//如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
