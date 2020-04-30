
// MFC3.3.2View.cpp: CMFC332View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.3.2.h"
#endif

#include "MFC3.3.2Doc.h"
#include "MFC3.3.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC332View

IMPLEMENT_DYNCREATE(CMFC332View, CView)

BEGIN_MESSAGE_MAP(CMFC332View, CView)
END_MESSAGE_MAP()

// CMFC332View 构造/析构

CMFC332View::CMFC332View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC332View::~CMFC332View()
{
}

BOOL CMFC332View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC332View 绘图

void CMFC332View::OnDraw(CDC* pDC)
{
	CMFC332Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int B = pDoc->A;
	CString a;
	a.Format(_T("%d"), B);
	pDC->TextOutW(200, 300, pDoc->S);
	pDC->TextOutW(200, 200, a);
}


// CMFC332View 诊断

#ifdef _DEBUG
void CMFC332View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC332View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC332Doc* CMFC332View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC332Doc)));
	return (CMFC332Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC332View 消息处理程序
