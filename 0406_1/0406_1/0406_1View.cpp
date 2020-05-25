
// 0406_1View.cpp: CMy04061View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0406_1.h"
#endif

#include "0406_1Doc.h"
#include "0406_1View.h"
#include "MyDlog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04061View

IMPLEMENT_DYNCREATE(CMy04061View, CView)

BEGIN_MESSAGE_MAP(CMy04061View, CView)
	ON_COMMAND(ID_Showdlg, &CMy04061View::OnShowdlg)
END_MESSAGE_MAP()

// CMy04061View 构造/析构

CMy04061View::CMy04061View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy04061View::~CMy04061View()
{
}

BOOL CMy04061View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy04061View 绘图

void CMy04061View::OnDraw(CDC* /*pDC*/)
{
	CMy04061Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy04061View 诊断

#ifdef _DEBUG
void CMy04061View::AssertValid() const
{
	CView::AssertValid();
}

void CMy04061View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy04061Doc* CMy04061View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy04061Doc)));
	return (CMy04061Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy04061View 消息处理程序


void CMy04061View::OnShowdlg()
{
	MyDlog dlg;
	int t = dlg.DoModal();

	if (t == IDOK)
	{
		CString s = _T("你已退出对话框");
		CClientDC dc(this);
		dc.TextOutW(200, 300, s);
	}

	// TODO: 在此添加命令处理程序代码
}
