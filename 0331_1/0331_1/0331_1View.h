
// 0331_1View.h: CMy03311View 类的接口
//

#pragma once


class CMy03311View : public CView
{
protected: // 仅从序列化创建
	CMy03311View() noexcept;
	DECLARE_DYNCREATE(CMy03311View)

// 特性
public:
	CMy03311Doc* GetDocument() const;

// 操作
public:
	CString s;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy03311View();
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
};

#ifndef _DEBUG  // 0331_1View.cpp 中的调试版本
inline CMy03311Doc* CMy03311View::GetDocument() const
   { return reinterpret_cast<CMy03311Doc*>(m_pDocument); }
#endif

