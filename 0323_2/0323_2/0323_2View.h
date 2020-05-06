﻿
// 0323_2View.h: CMy03232View 类的接口
//

#pragma once


class CMy03232View : public CView
{
protected: // 仅从序列化创建
	CMy03232View() noexcept;
	DECLARE_DYNCREATE(CMy03232View)

// 特性
public:
	CMy03232Doc* GetDocument() const;

// 操作
public:
	CPoint point;
	CRect rect;
	int r = 0;
	int t = 1;
	int a, b, c;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy03232View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowyuan();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 0323_2View.cpp 中的调试版本
inline CMy03232Doc* CMy03232View::GetDocument() const
   { return reinterpret_cast<CMy03232Doc*>(m_pDocument); }
#endif

