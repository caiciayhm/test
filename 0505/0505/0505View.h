
// 0505View.h : CMy0505View 类的接口
//

#pragma once

class CMy0505Set;

class CMy0505View : public CRecordView
{
protected: // 仅从序列化创建
	CMy0505View();
	DECLARE_DYNCREATE(CMy0505View)

public:
	enum{ IDD = IDD_MY0505_FORM };
	CMy0505Set* m_pSet;

// 特性
public:
	CMy0505Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy0505View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // 0505View.cpp 中的调试版本
inline CMy0505Doc* CMy0505View::GetDocument() const
   { return reinterpret_cast<CMy0505Doc*>(m_pDocument); }
#endif

