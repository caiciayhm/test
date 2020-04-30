
// MFC3.2View.cpp: CMFC32View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.2.h"
#endif

#include "MFC3.2Doc.h"
#include "MFC3.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC32View

IMPLEMENT_DYNCREATE(CMFC32View, CView)

BEGIN_MESSAGE_MAP(CMFC32View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC32View 构造/析构

CMFC32View::CMFC32View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC32View::~CMFC32View()
{
}

BOOL CMFC32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC32View 绘图

void CMFC32View::OnDraw(CDC* pDC)
{
	CMFC32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC32View 诊断

#ifdef _DEBUG
void CMFC32View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC32Doc* CMFC32View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC32Doc)));
	return (CMFC32Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC32View 消息处理程序


void CMFC32View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC32Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("A+B=%d"), pDoc->A + pDoc->B);
	CClientDC dc(this);
	dc.TextOutW(20, 30, s);
	CView::OnLButtonDown(nFlags, point);
}
