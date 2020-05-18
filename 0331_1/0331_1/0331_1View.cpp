
// 0331_1View.cpp: CMy03311View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0331_1.h"
#endif

#include "0331_1Doc.h"
#include "0331_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03311View

IMPLEMENT_DYNCREATE(CMy03311View, CView)

BEGIN_MESSAGE_MAP(CMy03311View, CView)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMy03311View 构造/析构

CMy03311View::CMy03311View() noexcept
{
	// TODO: 在此处添加构造代码
	s = "";
}

CMy03311View::~CMy03311View()
{
}

BOOL CMy03311View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03311View 绘图

void CMy03311View::OnDraw(CDC* pDC)
{
	CMy03311Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->cr);
}


// CMy03311View 诊断

#ifdef _DEBUG
void CMy03311View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03311View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03311Doc* CMy03311View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03311Doc)));
	return (CMy03311Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03311View 消息处理程序


void CMy03311View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy03311Doc* pDoc = GetDocument();
	CClientDC dc(this);
    s = s + (char)nChar;
	dc.TextOutW(pDoc->cr.left + 10, pDoc->cr.top + 10, s);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
