
// 0324_2View.cpp: CMy03242View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0324_2.h"
#endif

#include "0324_2Doc.h"
#include "0324_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03242View

IMPLEMENT_DYNCREATE(CMy03242View, CView)

BEGIN_MESSAGE_MAP(CMy03242View, CView)
END_MESSAGE_MAP()

// CMy03242View 构造/析构

CMy03242View::CMy03242View() noexcept
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
}

CMy03242View::~CMy03242View()
{
}

BOOL CMy03242View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03242View 绘图

void CMy03242View::OnDraw(CDC* pDC)
{
	CMy03242Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
}


// CMy03242View 诊断

#ifdef _DEBUG
void CMy03242View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03242View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03242Doc* CMy03242View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03242Doc)));
	return (CMy03242Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03242View 消息处理程序
