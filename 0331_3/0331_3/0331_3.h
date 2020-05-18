
// 0331_3.h: 0331_3 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMy03313App:
// 有关此类的实现，请参阅 0331_3.cpp
//

class CMy03313App : public CWinApp
{
public:
	CMy03313App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy03313App theApp;
