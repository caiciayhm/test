
// MFC3.3.1View.h: CMFC331View 类的接口
//

#pragma once


class CMFC331View : public CView
{
protected: // 仅从序列化创建
	CMFC331View() noexcept;
	DECLARE_DYNCREATE(CMFC331View)

// 特性
public:
	CMFC331Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC331View();
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

#ifndef _DEBUG  // MFC3.3.1View.cpp 中的调试版本
inline CMFC331Doc* CMFC331View::GetDocument() const
   { return reinterpret_cast<CMFC331Doc*>(m_pDocument); }
#endif

