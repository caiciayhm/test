
// 0225_2View.h: CMy02252View 类的接口
//

#pragma once


class CMy02252View : public CView
{
protected: // 仅从序列化创建
	CMy02252View() noexcept;
	DECLARE_DYNCREATE(CMy02252View)

// 特性
public:
	CMy02252Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy02252View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0225_2View.cpp 中的调试版本
inline CMy02252Doc* CMy02252View::GetDocument() const
   { return reinterpret_cast<CMy02252Doc*>(m_pDocument); }
#endif

