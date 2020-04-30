
// MFC3.3.2View.h: CMFC332View 类的接口
//

#pragma once


class CMFC332View : public CView
{
protected: // 仅从序列化创建
	CMFC332View() noexcept;
	DECLARE_DYNCREATE(CMFC332View)

// 特性
public:
	CMFC332Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC332View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC3.3.2View.cpp 中的调试版本
inline CMFC332Doc* CMFC332View::GetDocument() const
   { return reinterpret_cast<CMFC332Doc*>(m_pDocument); }
#endif

