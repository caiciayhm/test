// Dlog2.cpp: 实现文件
//

#include "pch.h"
#include "0413_2.h"
#include "Dlog2.h"
#include "afxdialogex.h"


// Dlog2 对话框

IMPLEMENT_DYNAMIC(Dlog2, CDialogEx)

Dlog2::Dlog2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Dlog2::~Dlog2()
{
}

void Dlog2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);

}


BEGIN_MESSAGE_MAP(Dlog2, CDialogEx)
END_MESSAGE_MAP()


// Dlog2 消息处理程序
