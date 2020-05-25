
// 0406_1View.h: CMy04061View 类的接口
//

#pragma once


class CMy04061View : public CView
{
protected: // 仅从序列化创建
	CMy04061View() noexcept;
	DECLARE_DYNCREATE(CMy04061View)

// 特性
public:
	CMy04061Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy04061View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowdlg();
};

#ifndef _DEBUG  // 0406_1View.cpp 中的调试版本
inline CMy04061Doc* CMy04061View::GetDocument() const
   { return reinterpret_cast<CMy04061Doc*>(m_pDocument); }
#endif

