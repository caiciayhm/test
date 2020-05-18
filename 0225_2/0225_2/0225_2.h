
// 0225_2.h: 0225_2 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMy02252App:
// 有关此类的实现，请参阅 0225_2.cpp
//

class CMy02252App : public CWinApp
{
public:
	CMy02252App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy02252App theApp;
