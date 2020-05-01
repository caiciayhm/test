
// MFC3.10.3View.cpp: CMFC3103View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.10.3.h"
#endif

#include "MFC3.10.3Doc.h"
#include "MFC3.10.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3103View

IMPLEMENT_DYNCREATE(CMFC3103View, CView)

BEGIN_MESSAGE_MAP(CMFC3103View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3103View 构造/析构

CMFC3103View::CMFC3103View() noexcept
{
	// TODO: 在此处添加构造代码
	
	ca.SetSize(3);
}

CMFC3103View::~CMFC3103View()
{
}

BOOL CMFC3103View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3103View 绘图

void CMFC3103View::OnDraw(CDC* pDC)
{
	CMFC3103Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr1(20, 20, 100, 100);
	CRect cr2(100, 100, 150, 150);
	CRect cr3(150, 150, 300, 300);
	pDC->Rectangle(cr1);
	pDC->Rectangle(cr2);
	pDC->Rectangle(cr3);
}


// CMFC3103View 诊断

#ifdef _DEBUG
void CMFC3103View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3103View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3103Doc* CMFC3103View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3103Doc)));
	return (CMFC3103Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3103View 消息处理程序


void CMFC3103View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CRect cr1(20, 20, 100, 100);
	CRect cr2(100, 100, 150, 150);
	CRect cr3(150, 150, 300, 300);
	CClientDC dc(this);
	int a = rand() % 50 + 5;
	int b = rand() % 50 + 5;
	CString s;
	if (cr1.PtInRect(CPoint(point.x, point.y)))
	{		
		s.Format(_T("%d"),a);
		dc.TextOutW(point.x, point.y, s);
	}
	else if (cr2.PtInRect(CPoint(point.x, point.y)))
	{
		s.Format(_T("%d"), b);
		dc.TextOutW(point.x, point.y, s);
	}
	else if (cr3.PtInRect(CPoint(point.x, point.y)))
	{
		s.Format(_T("%d"),a +b);
		dc.TextOutW(point.x, point.y, s);
	}
	else
	{
		dc.TextOutW(point.x, point.y, _T("点击无效"));
	}
	CView::OnLButtonDown(nFlags, point);
}
