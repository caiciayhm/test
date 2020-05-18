
// 0225_2View.cpp: CMy02252View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0225_2.h"
#endif

#include "0225_2Doc.h"
#include "0225_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy02252View

IMPLEMENT_DYNCREATE(CMy02252View, CView)

BEGIN_MESSAGE_MAP(CMy02252View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy02252View 构造/析构

CMy02252View::CMy02252View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy02252View::~CMy02252View()
{
}

BOOL CMy02252View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy02252View 绘图

void CMy02252View::OnDraw(CDC* /*pDC*/)
{
	CMy02252Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy02252View 诊断

#ifdef _DEBUG
void CMy02252View::AssertValid() const
{
	CView::AssertValid();
}

void CMy02252View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy02252Doc* CMy02252View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy02252Doc)));
	return (CMy02252Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy02252View 消息处理程序


void CMy02252View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy02252Doc* pDoc = GetDocument();
	int c = pDoc->count;
	c+= 1;
	pDoc->count = c;
	CView::OnLButtonDown(nFlags, point);
}


void CMy02252View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy02252Doc* pDoc = GetDocument();
	CString s;
	int c = pDoc->count;
	s.Format(_T("%d"), c);
	CClientDC dc(this);
	dc.TextOutW(200, 100, s);
	CView::OnRButtonDown(nFlags, point);
}
