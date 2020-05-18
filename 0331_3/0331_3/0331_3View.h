
// 0331_3View.h: CMy03313View 类的接口
//

#pragma once


class CMy03313View : public CView
{
protected: // 仅从序列化创建
	CMy03313View() noexcept;
	DECLARE_DYNCREATE(CMy03313View)

// 特性
public:
	CMy03313Doc* GetDocument() const;

// 操作
public:
	CPoint point,cpoint;
	CString s, str;
	int x, flag, h;
	CRect cr;
	CArray <CString,CString&> m;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy03313View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0331_3View.cpp 中的调试版本
inline CMy03313Doc* CMy03313View::GetDocument() const
   { return reinterpret_cast<CMy03313Doc*>(m_pDocument); }
#endif

