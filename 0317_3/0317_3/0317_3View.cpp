
// 0317_3View.cpp: CMy03173View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0317_3.h"
#endif

#include "0317_3Doc.h"
#include "0317_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03173View

IMPLEMENT_DYNCREATE(CMy03173View, CView)

BEGIN_MESSAGE_MAP(CMy03173View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy03173View 构造/析构

CMy03173View::CMy03173View() noexcept
{
	// TODO: 在此处添加构造代码
	N = 5;
	set = true;
	t = true;
	for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t, 0, t + 20, 20);
		cr.Add(rect);

	}
}

CMy03173View::~CMy03173View()
{
}

BOOL CMy03173View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03173View 绘图

void CMy03173View::OnDraw(CDC* pDC)
{
	CMy03173Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set)
	{
		for (int i = 0; i < N; i++)
		{
			SetTimer(i, rand() % 400 + 100, NULL);
			set = false;
		}
		
	}
	// TODO: 在此处为本机数据添加绘制代码
	
	for (int i = 0; i < N; i++)
	{
		
		pDC->Ellipse(cr[i]);
	}
}


// CMy03173View 诊断

#ifdef _DEBUG
void CMy03173View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03173View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03173Doc* CMy03173View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03173Doc)));
	return (CMy03173Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03173View 消息处理程序


void CMy03173View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int i = nIDEvent;
	CRect rect;
	this->GetClientRect(&rect);
	if (t)
	{
		if ((rect.bottom >= cr[i].bottom))
		{
			cr[i].top += 10;
			cr[i].bottom += 10;
		}
		else t = false;
	}
	else
	{
	   if ((rect.top <= cr[i].top))
		{
			cr[i].top -= 10;
			cr[i].bottom -= 10;
		}
       else t = true;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}
