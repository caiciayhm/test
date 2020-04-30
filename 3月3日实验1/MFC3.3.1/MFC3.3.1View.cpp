
// MFC3.3.1View.cpp: CMFC331View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.3.1.h"
#endif

#include "MFC3.3.1Doc.h"
#include "MFC3.3.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC331View

IMPLEMENT_DYNCREATE(CMFC331View, CView)

BEGIN_MESSAGE_MAP(CMFC331View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC331View 构造/析构

CMFC331View::CMFC331View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC331View::~CMFC331View()
{
}

BOOL CMFC331View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC331View 绘图

void CMFC331View::OnDraw(CDC* pDC)
{
	CMFC331Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString S = _T("我是杨红敏");
	int A = 123;
	CString  s;
	pDC->TextOutW(200, 200, S);
	s.Format(_T("%d"), A);
    pDC->TextOutW(200, 100, s);
}


// CMFC331View 诊断

#ifdef _DEBUG
void CMFC331View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC331View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC331Doc* CMFC331View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC331Doc)));
	return (CMFC331Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC331View 消息处理程序


void CMFC331View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
}
