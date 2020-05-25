#pragma once


// MyDlog 对话框

class MyDlog : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlog)

public:
	MyDlog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MyDlog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
