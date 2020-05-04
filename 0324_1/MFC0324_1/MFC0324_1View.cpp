
// MFC0324_1View.cpp: CMFC03241View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC0324_1.h"
#endif

#include "MFC0324_1Doc.h"
#include "MFC0324_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC03241View

IMPLEMENT_DYNCREATE(CMFC03241View, CView)

BEGIN_MESSAGE_MAP(CMFC03241View, CView)
	ON_COMMAND(ID_SHOWNAME, &CMFC03241View::OnShowname)
END_MESSAGE_MAP()

// CMFC03241View 构造/析构

CMFC03241View::CMFC03241View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC03241View::~CMFC03241View()
{
}

BOOL CMFC03241View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC03241View 绘图

void CMFC03241View::OnDraw(CDC* /*pDC*/)
{
	CMFC03241Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC03241View 诊断

#ifdef _DEBUG
void CMFC03241View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC03241View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC03241Doc* CMFC03241View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC03241Doc)));
	return (CMFC03241Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC03241View 消息处理程序


void CMFC03241View::OnShowname()
{
	// TODO: 在此添加命令处理程序代码
	CString s;
	s = "杨红敏";
	CClientDC dc(this);
	dc.TextOutW(200, 300, s);
}
