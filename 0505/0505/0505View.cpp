
// 0505View.cpp : CMy0505View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_EN_CHANGE(IDC_EDIT2, &CMy0505View::OnEnChangeEdit2)
END_MESSAGE_MAP()

// CMy0505View ����/����

CMy0505View::CMy0505View()
	: CRecordView(CMy0505View::IDD)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, years(_T(""))
	, mobnumber(_T(""))
{
	m_pSet = NULL;
	// TODO:  �ڴ˴���ӹ������

}

CMy0505View::~CMy0505View()
{
}

void CMy0505View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_4);
}

BOOL CMy0505View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMy0505View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_My0505Set;
	CRecordView::OnInitialUpdate();

}


// CMy0505View ��ӡ

BOOL CMy0505View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0505View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0505View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy0505View ���

#ifdef _DEBUG
void CMy0505View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMy0505View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMy0505Doc* CMy0505View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0505Doc)));
	return (CMy0505Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0505View ���ݿ�֧��
CRecordset* CMy0505View::OnGetRecordset()
{
	return m_pSet;
}



// CMy0505View ��Ϣ�������


void CMy0505View::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
