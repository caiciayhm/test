
// 0331_3View.cpp: CMy03313View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0331_3.h"
#endif

#include "0331_3Doc.h"
#include "0331_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03313View

IMPLEMENT_DYNCREATE(CMy03313View, CView)

BEGIN_MESSAGE_MAP(CMy03313View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy03313View 构造/析构

CMy03313View::CMy03313View() noexcept
{
	// TODO: 在此处添加构造代码
	s = "";
	str = "";
	cpoint.x = 605;
	cpoint.y = 203;
	x = 605;
	h = 0;
	flag = 0;
	cr.left = 600;
	cr.top = 200;
	cr.right = 800;
	cr.bottom = 225;
}

CMy03313View::~CMy03313View()
{
}

BOOL CMy03313View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03313View 绘图

void CMy03313View::OnDraw(CDC* pDC)
{
	CMy03313Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(cr);
	if (flag)
	{
		for (int i = 0; i < flag; i++)
			pDC->TextOutW(605, 203 + (i*h), m[i]);
	}
}


// CMy03313View 打印

BOOL CMy03313View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03313View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03313View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03313View 诊断

#ifdef _DEBUG
void CMy03313View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03313View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03313Doc* CMy03313View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03313Doc)));
	return (CMy03313Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03313View 消息处理程序

void CMy03313View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	char c = nChar;
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	h =tm.tmHeight;
	str = s;
	s += c;
	CSize z = x += 9;
	if (x >= cr.right)
	{
		m.Add(str);
		flag += 1;
		s.Empty();
		cpoint.y += tm.tmHeight;
		cr.bottom += tm.tmHeight;
		Invalidate();
		x = 605;
	}
	dc.TextOutW(cpoint.x,cpoint.y, s);
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMy03313View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCaretPos(point);
	s.Empty();
	cpoint = point;
	CView::OnLButtonDown(nFlags, point);
}
