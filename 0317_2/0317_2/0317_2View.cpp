
// 0317_2View.cpp: CMy03172View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0317_2.h"
#endif

#include "0317_2Doc.h"
#include "0317_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03172View

IMPLEMENT_DYNCREATE(CMy03172View, CView)

BEGIN_MESSAGE_MAP(CMy03172View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMy03172View 构造/析构

CMy03172View::CMy03172View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy03172View::~CMy03172View()
{
}

BOOL CMy03172View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03172View 绘图

void CMy03172View::OnDraw(CDC* pDC)
{
	CMy03172Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->m_tagRec);
	
}


// CMy03172View 诊断

#ifdef _DEBUG
void CMy03172View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03172View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03172Doc* CMy03172View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03172Doc)));
	return (CMy03172Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03172View 消息处理程序


void CMy03172View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy03172Doc* pDoc = GetDocument();
	pDoc->m_tagRec.left = 100;
	pDoc->m_tagRec.top = 100;
	pDoc->m_tagRec.right = 300;
	pDoc->m_tagRec.bottom = 300;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}


void CMy03172View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy03172Doc* pDoc = GetDocument();
	CRect clientRec;
	GetClientRect(&clientRec);
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->m_tagRec.left > 0)
		{
			pDoc->m_tagRec.left -= 5;
			pDoc->m_tagRec.right -= 5;
		}
		break;
	case VK_RIGHT:
		if (pDoc->m_tagRec.right <=(clientRec.right-clientRec.left))
		{
			pDoc->m_tagRec.left += 5;
			pDoc->m_tagRec.right += 5;
		}
		break;
	case VK_UP:
		if (pDoc->m_tagRec.bottom > 0)
		{
			pDoc->m_tagRec.bottom -= 5;
			pDoc->m_tagRec.top -= 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->m_tagRec.top >=(clientRec.top - clientRec.bottom))
		{
			pDoc->m_tagRec.top += 5;
			pDoc->m_tagRec.bottom += 5;
		}
		break;
	}
	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy03172View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy03172Doc* pDoc = GetDocument();
	CRect clientRec;
	GetClientRect(&clientRec);//获得窗口尺寸大小
	switch (nChar)
	{
	case 'home':
		if (pDoc->m_tagRec.left > 0 & pDoc->m_tagRec.top > 0)
		{
			pDoc->m_tagRec.left -=5;
			//pDoc->m_tagRec.top += 5;
			pDoc->m_tagRec.right -= 5;
			//pDoc->m_tagRec.bottom += 5;
		}
		break;
	case 'end':
		if (pDoc->m_tagRec.right <= (clientRec.right - clientRec.left) &pDoc->m_tagRec.top >= (clientRec.top - clientRec.bottom))
		{
			pDoc->m_tagRec.left += 5;
			//pDoc->m_tagRec.top -= 5;
			pDoc->m_tagRec.right -= 5;
			//pDoc->m_tagRec.bottom += 5;
		}
		break;
	}
	InvalidateRect(NULL, TRUE);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
