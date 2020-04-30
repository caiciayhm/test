
// MFC3.9.2View.h: CMFC392View 类的接口
//

#pragma once


class CMFC392View : public CView
{
protected: // 仅从序列化创建
	CMFC392View() noexcept;
	DECLARE_DYNCREATE(CMFC392View)

// 特性
public:
	CMFC392Doc* GetDocument() const;

// 操作
public:
	CArray<CRect, CRect&> ca;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC392View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3.9.2View.cpp 中的调试版本
inline CMFC392Doc* CMFC392View::GetDocument() const
   { return reinterpret_cast<CMFC392Doc*>(m_pDocument); }
#endif

