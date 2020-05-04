
// 0324_2View.h: CMy03242View 类的接口
//

#pragma once


class CMy03242View : public CView
{
protected: // 仅从序列化创建
	CMy03242View() noexcept;
	DECLARE_DYNCREATE(CMy03242View)

// 特性
public:
	CMy03242Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy03242View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 0324_2View.cpp 中的调试版本
inline CMy03242Doc* CMy03242View::GetDocument() const
   { return reinterpret_cast<CMy03242Doc*>(m_pDocument); }
#endif

