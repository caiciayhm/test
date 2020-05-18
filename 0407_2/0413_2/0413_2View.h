
// 0413_2View.h: CMy04132View 类的接口
//

#pragma once


class CMy04132View : public CView
{
protected: // 仅从序列化创建
	CMy04132View() noexcept;
	DECLARE_DYNCREATE(CMy04132View)

// 特性
public:
	CMy04132Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy04132View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowdlog();
};

#ifndef _DEBUG  // 0413_2View.cpp 中的调试版本
inline CMy04132Doc* CMy04132View::GetDocument() const
   { return reinterpret_cast<CMy04132Doc*>(m_pDocument); }
#endif

