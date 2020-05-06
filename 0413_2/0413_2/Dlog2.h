#pragma once


// Dlog2 对话框

class Dlog2 : public CDialogEx
{
	DECLARE_DYNAMIC(Dlog2)

public:
	Dlog2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Dlog2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int a;
	int b;
};
