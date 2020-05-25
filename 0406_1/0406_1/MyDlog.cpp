// MyDlog.cpp: 实现文件
//

#include "pch.h"
#include "0406_1.h"
#include "MyDlog.h"
#include "afxdialogex.h"


// MyDlog 对话框

IMPLEMENT_DYNAMIC(MyDlog, CDialogEx)

MyDlog::MyDlog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDlog::~MyDlog()
{
}

void MyDlog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDlog, CDialogEx)
END_MESSAGE_MAP()


// MyDlog 消息处理程序
