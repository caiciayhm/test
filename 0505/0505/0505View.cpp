
// 0505View.cpp : CMy0505View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0505.h"
#endif

#include "0505Set.h"
#include "0505Doc.h"
#include "0505View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0505View

IMPLEMENT_DYNCREATE(CMy0505View, CRecordView)

BEGIN_MESSAGE_MAP(CMy0505View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_EN_CHANGE(IDC_EDIT2, &CMy0505View::OnEnChangeEdit2)
END_MESSAGE_MAP()

// CMy0505View 构造/析构

CMy0505View::CMy0505View()
	: CRecordView(CMy0505View::IDD)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, years(_T(""))
	, mobnumber(_T(""))
{
	m_pSet = NULL;
	// TODO:  在此处添加构造代码

}

CMy0505View::~CMy0505View()
{
}

void CMy0505View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_4);
}

BOOL CMy0505View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMy0505View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_My0505Set;
	CRecordView::OnInitialUpdate();

}


// CMy0505View 打印

BOOL CMy0505View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0505View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy0505View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy0505View 诊断

#ifdef _DEBUG
void CMy0505View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMy0505View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMy0505Doc* CMy0505View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0505Doc)));
	return (CMy0505Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0505View 数据库支持
CRecordset* CMy0505View::OnGetRecordset()
{
	return m_pSet;
}



// CMy0505View 消息处理程序


void CMy0505View::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
