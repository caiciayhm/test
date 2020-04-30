
// MFC3.9.2View.cpp: CMFC392View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.9.2.h"
#endif

#include "MFC3.9.2Doc.h"
#include "MFC3.9.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC392View

IMPLEMENT_DYNCREATE(CMFC392View, CView)

BEGIN_MESSAGE_MAP(CMFC392View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC392View 构造/析构

CMFC392View::CMFC392View() noexcept
{
	// TODO: 在此处添加构造代码
	ca.SetSize(256);
}

CMFC392View::~CMFC392View()
{
}

BOOL CMFC392View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC392View 绘图

void CMFC392View::OnDraw(CDC* pDC)
{
	CMFC392Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca.GetAt(i));
}


// CMFC392View 诊断

#ifdef _DEBUG
void CMFC392View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC392View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC392Doc* CMFC392View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC392Doc)));
	return (CMFC392Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC392View 消息处理程序


void CMFC392View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r = rand() % (40 - 5) + 5;
	int t = rand() % (40 - 5) + 5;
	CRect cr(point.x-r , point.y-t, point.x+r, point.y+t );
	ca.Add(cr);
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
