
// MFC3.3.3View.cpp: CMFC333View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.3.3.h"
#endif

#include "MFC3.3.3Doc.h"
#include "MFC3.3.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC333View

IMPLEMENT_DYNCREATE(CMFC333View, CView)

BEGIN_MESSAGE_MAP(CMFC333View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC333View 构造/析构

CMFC333View::CMFC333View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC333View::~CMFC333View()
{
}

BOOL CMFC333View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC333View 绘图

void CMFC333View::OnDraw(CDC* /*pDC*/)
{
	CMFC333Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC333View 诊断

#ifdef _DEBUG
void CMFC333View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC333View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC333Doc* CMFC333View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC333Doc)));
	return (CMFC333Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC333View 消息处理程序


void CMFC333View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC333Doc* pDoc = GetDocument();
	pDoc->count++;
	
	CView::OnLButtonDown(nFlags, point);
}


void CMFC333View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC333Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("%d"), pDoc->count);
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	
	CView::OnRButtonDown(nFlags, point);
}
