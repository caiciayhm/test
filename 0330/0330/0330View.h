﻿
// 0330View.h: CMy0330View 类的接口
//

#pragma once


class CMy0330View : public CView
{
protected: // 仅从序列化创建
	CMy0330View() noexcept;
	DECLARE_DYNCREATE(CMy0330View)

// 特性
public:
	CMy0330Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy0330View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // 0330View.cpp 中的调试版本
inline CMy0330Doc* CMy0330View::GetDocument() const
   { return reinterpret_cast<CMy0330Doc*>(m_pDocument); }
#endif

