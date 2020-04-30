
// MFC3.2.2View.cpp: CMFC322View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.2.2.h"
#endif

#include "MFC3.2.2Doc.h"
#include "MFC3.2.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC322View

IMPLEMENT_DYNCREATE(CMFC322View, CView)

BEGIN_MESSAGE_MAP(CMFC322View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC322View 构造/析构

CMFC322View::CMFC322View() noexcept
{
	// TODO: 在此处添加构造代码
	ca.SetSize(256);
}

CMFC322View::~CMFC322View()
{
}

BOOL CMFC322View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC322View 绘图

void CMFC322View::OnDraw(CDC* pDC)
{
	CMFC322Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca.GetAt (i));
}


// CMFC322View 诊断

#ifdef _DEBUG
void CMFC322View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC322View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC322Doc* CMFC322View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC322Doc)));
	return (CMFC322Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC322View 消息处理程序


void CMFC322View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r = rand() % (50 - 5) + 5;
	
	CRect cr(point.x - r, point.y - r, point.x + r, point.y + r);
	ca.Add(cr);
	this->Invalidate();
	CClientDC dc(this);
	dc.Ellipse(cr);
	CView::OnLButtonDown(nFlags, point);
}
