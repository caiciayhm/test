
// 0505View.h : CMy0505View ��Ľӿ�
//

#pragma once

class CMy0505Set;

class CMy0505View : public CRecordView
{
protected: // �������л�����
	CMy0505View();
	DECLARE_DYNCREATE(CMy0505View)

public:
	enum{ IDD = IDD_MY0505_FORM };
	CMy0505Set* m_pSet;

// ����
public:
	CMy0505Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy0505View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	long ID;
	CString name;
	CString number;
	CString years;
	CString mobnumber;
};

#ifndef _DEBUG  // 0505View.cpp �еĵ��԰汾
inline CMy0505Doc* CMy0505View::GetDocument() const
   { return reinterpret_cast<CMy0505Doc*>(m_pDocument); }
#endif

