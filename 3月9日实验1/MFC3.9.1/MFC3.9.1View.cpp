
// MFC3.9.1View.cpp: CMFC391View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.9.1.h"
#endif

#include "MFC3.9.1Doc.h"
#include "MFC3.9.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC391View

IMPLEMENT_DYNCREATE(CMFC391View, CView)

BEGIN_MESSAGE_MAP(CMFC391View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC391View 构造/析构

CMFC391View::CMFC391View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC391View::~CMFC391View()
{
}

BOOL CMFC391View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC391View 绘图

void CMFC391View::OnDraw(CDC* pDC)
{
	CMFC391Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr;
	this->GetClientRect(cr);
	pDC->Ellipse(cr);
}


// CMFC391View 诊断

#ifdef _DEBUG
void CMFC391View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC391View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC391Doc* CMFC391View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC391Doc)));
	return (CMFC391Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC391View 消息处理程序


void CMFC391View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r = rand() % (40 - 5) + 5;
	CRect cr(point.x - r, point.y - r, point.x + r, point.y + r);
	CView::OnLButtonDown(nFlags, point);
}
