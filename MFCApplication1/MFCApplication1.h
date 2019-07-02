
// MFCApplication1.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// CMFCApplication1App:
// 有关此类的实现，请参阅 MFCApplication1.cpp
//

class CMFCApplication1App //代表本程序的类，此类的对象有且只能有一个
	: public CWinApp//公有继承了“CWinApp”类
{
public:
	CMFCApplication1App();//程序被打开时会执行此构造函数
	~CMFCApplication1App();//程序被关闭时会执行此析构函数

// 重写
public:
	virtual BOOL InitInstance();//当本程序被实例化时执行此函数

// 实现

	DECLARE_MESSAGE_MAP()//对此类的内容进行实现
};

extern CMFCApplication1App theApp;//定义了此类的对象“theApp”，这个对象代表着程序本身，有且只能有一个
