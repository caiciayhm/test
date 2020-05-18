
// 0331_2View.cpp: CMy03312View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0331_2.h"
#endif

#include "0331_2Doc.h"
#include "0331_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03312View

IMPLEMENT_DYNCREATE(CMy03312View, CView)

BEGIN_MESSAGE_MAP(CMy03312View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy03312View 构造/析构

CMy03312View::CMy03312View() noexcept
{
	// TODO: 在此处添加构造代码
	
}

CMy03312View::~CMy03312View()
{
}

BOOL CMy03312View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03312View 绘图

void CMy03312View::OnDraw(CDC* /*pDC*/)
{
	CMy03312Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy03312View 打印

BOOL CMy03312View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03312View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03312View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03312View 诊断

#ifdef _DEBUG
void CMy03312View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03312View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03312Doc* CMy03312View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03312Doc)));
	return (CMy03312Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03312View 消息处理程序


void CMy03312View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnChar(nChar, nRepCnt, nFlags);
	CClientDC dc(this);
	s = s + (char)nChar;
	dc.TextOutW(point1.x, point1.y, s);
}


void CMy03312View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCaretPos(point2);
	s.Empty();
	point1 = point2;

	CView::OnLButtonDown(nFlags, point);
}
