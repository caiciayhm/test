﻿
// 0302_4.h: 0302_4 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMy03024App:
// 有关此类的实现，请参阅 0302_4.cpp
//

class CMy03024App : public CWinApp
{
public:
	CMy03024App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy03024App theApp;
