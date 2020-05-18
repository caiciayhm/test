
// 0225_1View.cpp: CMy02251View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0225_1.h"
#endif

#include "0225_1Doc.h"
#include "0225_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy02251View

IMPLEMENT_DYNCREATE(CMy02251View, CView)

BEGIN_MESSAGE_MAP(CMy02251View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy02251View 构造/析构

CMy02251View::CMy02251View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy02251View::~CMy02251View()
{
}

BOOL CMy02251View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy02251View 绘图

void CMy02251View::OnDraw(CDC* /*pDC*/)
{
	CMy02251Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy02251View 诊断

#ifdef _DEBUG
void CMy02251View::AssertValid() const
{
	CView::AssertValid();
}

void CMy02251View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy02251Doc* CMy02251View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy02251Doc)));
	return (CMy02251Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy02251View 消息处理程序


void CMy02251View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy02251Doc* pDoc = GetDocument();
	CString s;
	s = pDoc->s;
	CClientDC dc(this);
	dc.TextOutW(200, 100, s);
	CView::OnLButtonDown(nFlags, point);
}
