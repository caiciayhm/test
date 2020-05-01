
// 0302_4View.cpp: CMy03024View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0302_4.h"
#endif

#include "0302_4Doc.h"
#include "0302_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03024View

IMPLEMENT_DYNCREATE(CMy03024View, CView)

BEGIN_MESSAGE_MAP(CMy03024View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy03024View 构造/析构

CMy03024View::CMy03024View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy03024View::~CMy03024View()
{
}

BOOL CMy03024View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03024View 绘图

void CMy03024View::OnDraw(CDC* pDC)
{
	CMy03024Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect rect;
	this->GetClientRect(rect);
	CBrush nevbrush(RGB(100, 50, 200));
	CBrush *poldbrush;
	poldbrush = pDC->SelectObject(&nevbrush);
	pDC->Ellipse(rect);
	
	
}


// CMy03024View 诊断

#ifdef _DEBUG
void CMy03024View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03024View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03024Doc* CMy03024View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03024Doc)));
	return (CMy03024Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03024View 消息处理程序


void CMy03024View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CView::OnLButtonDown(nFlags, point);
}
