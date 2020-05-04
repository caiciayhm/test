
// MFC0324_1View.h: CMFC03241View 类的接口
//

#pragma once


class CMFC03241View : public CView
{
protected: // 仅从序列化创建
	CMFC03241View() noexcept;
	DECLARE_DYNCREATE(CMFC03241View)

// 特性
public:
	CMFC03241Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC03241View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // MFC0324_1View.cpp 中的调试版本
inline CMFC03241Doc* CMFC03241View::GetDocument() const
   { return reinterpret_cast<CMFC03241Doc*>(m_pDocument); }
#endif

