﻿
// 0302_4View.h: CMy03024View 类的接口
//

#pragma once


class CMy03024View : public CView
{
protected: // 仅从序列化创建
	CMy03024View() noexcept;
	DECLARE_DYNCREATE(CMy03024View)

// 特性
public:
	CMy03024Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy03024View();
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

#ifndef _DEBUG  // 0302_4View.cpp 中的调试版本
inline CMy03024Doc* CMy03024View::GetDocument() const
   { return reinterpret_cast<CMy03024Doc*>(m_pDocument); }
#endif

