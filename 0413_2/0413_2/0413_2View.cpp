
// 0413_2View.cpp: CMy04132View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0413_2.h"
#endif

#include "0413_2Doc.h"
#include "0413_2View.h"
#include "Dlog2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04132View

IMPLEMENT_DYNCREATE(CMy04132View, CView)

BEGIN_MESSAGE_MAP(CMy04132View, CView)
	ON_COMMAND(ID_SHOWDLOG, &CMy04132View::OnShowdlog)
END_MESSAGE_MAP()

// CMy04132View 构造/析构

CMy04132View::CMy04132View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy04132View::~CMy04132View()
{
}

BOOL CMy04132View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy04132View 绘图

void CMy04132View::OnDraw(CDC* /*pDC*/)
{
	CMy04132Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy04132View 诊断

#ifdef _DEBUG
void CMy04132View::AssertValid() const
{
	CView::AssertValid();
}

void CMy04132View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy04132Doc* CMy04132View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy04132Doc)));
	return (CMy04132Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy04132View 消息处理程序


void CMy04132View::OnShowdlog()
{
	// TODO: 在此添加命令处理程序代码
     Dlog2 dlg;
	int t =dlg.DoModal();

	if (t == IDOK)
	{
		int A, B;
		A = dlg.a;
		B = dlg.b;
		int C = A + B;
		CString s;
		s.Format(_T("和为：%d"), C);
		CClientDC dc(this);
		dc.TextOutW(200, 100, s);

	}

}
