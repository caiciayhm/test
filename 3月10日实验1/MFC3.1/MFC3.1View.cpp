
// MFC3.1View.cpp: CMFC31View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.1.h"
#endif

#include "MFC3.1Doc.h"
#include "MFC3.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC31View

IMPLEMENT_DYNCREATE(CMFC31View, CView)

BEGIN_MESSAGE_MAP(CMFC31View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC31View 构造/析构

CMFC31View::CMFC31View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC31View::~CMFC31View()
{
}

BOOL CMFC31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC31View 绘图

void CMFC31View::OnDraw(CDC* /*pDC*/)
{
	CMFC31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC31View 诊断

#ifdef _DEBUG
void CMFC31View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC31Doc* CMFC31View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC31Doc)));
	return (CMFC31Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC31View 消息处理程序


void CMFC31View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s = _T("左键正被按下");
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
}


void CMFC31View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s = _T("右键正被抬起");
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonUp(nFlags, point);
}
