﻿
// MFC3.2.1View.cpp: CMFC321View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.2.1.h"
#endif

#include "MFC3.2.1Doc.h"
#include "MFC3.2.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC321View

IMPLEMENT_DYNCREATE(CMFC321View, CView)

BEGIN_MESSAGE_MAP(CMFC321View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC321View 构造/析构

CMFC321View::CMFC321View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC321View::~CMFC321View()
{
}

BOOL CMFC321View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC321View 绘图

void CMFC321View::OnDraw(CDC* pDC)
{
	CMFC321Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC321View 诊断

#ifdef _DEBUG
void CMFC321View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC321View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC321Doc* CMFC321View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC321Doc)));
	return (CMFC321Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC321View 消息处理程序


void CMFC321View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r = rand() % (50- 5) + 5;
	CClientDC dc(this);
	CRect cr(point.x-r,point.y-r,point.x+r,point.y+r);
	dc.Ellipse(cr);
	CView::OnLButtonDown(nFlags, point);
}
