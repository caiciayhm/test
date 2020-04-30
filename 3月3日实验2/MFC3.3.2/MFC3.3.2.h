﻿
// MFC3.3.2.h: MFC3.3.2 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMFC332App:
// 有关此类的实现，请参阅 MFC3.3.2.cpp
//

class CMFC332App : public CWinApp
{
public:
	CMFC332App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC332App theApp;
