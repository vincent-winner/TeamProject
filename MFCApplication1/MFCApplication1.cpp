
// MFCApplication1.cpp: 定义应用程序的类行为。
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"

#include "FileRW_MFC.h"

//如果编译模式为“Debug”，则编译Debug版程序供调试使用
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1App
//开始映射本对话框内的事件
BEGIN_MESSAGE_MAP(CMFCApplication1App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)//映射“点击帮助”事件
END_MESSAGE_MAP()
//本对话框内的事件映射结束

CMFCApplication1App::~CMFCApplication1App()//当本程序结束时，执行此函数
{
	DeleteFileW(_T("userlinenumber"));//删除“userlinenumber”文件
}


// CMFCApplication1App 构造
CMFCApplication1App::CMFCApplication1App()//当本程序被创建时，执行此函数
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
	FileRW file("userlinenumber");//打开文件“userlinenumber”
	file.write(CString(""));//向文件内写入空的字符串（目的是为了新建一个空的文件）
}


// 唯一的 CMFCApplication1App 对象

CMFCApplication1App theApp;


// CMFCApplication1App 初始化

BOOL CMFCApplication1App::InitInstance()//当本程序被实例化时执行此函数
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。  否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();//创建应用程序实例（在Windows系统中执行本程序）


	AfxEnableControlContainer();//允许对容器进行控制

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 激活“Windows Native”视觉管理器，以便在 MFC 控件中启用主题
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CMFCApplication1Dlg dlg;//创建“主窗口界面”对象
	m_pMainWnd = &dlg;//将“m_pMainWnd”指针指向“主窗口界面”对象
	INT_PTR nResponse = dlg.DoModal();//创建“主窗口界面”模态窗口
	if (nResponse == IDOK)//当点击“确定”来关闭对话窗时
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)//当点击“取消”来关闭对话窗时
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}
	else if (nResponse == -1)//当创建对话框失败时
	{
		TRACE(traceAppMsg, 0, "警告: 对话框创建失败，应用程序将意外终止。\n");
		TRACE(traceAppMsg, 0, "警告: 如果您在对话框上使用 MFC 控件，则无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

	//关闭VS产生的一些不必要的错误
#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

