// CPopDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCTest.h"
#include "CPopDlg.h"
#include "afxdialogex.h"


// CPopDlg 对话框

IMPLEMENT_DYNAMIC(CPopDlg, CDialogEx)

CPopDlg::CPopDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PopDlg, pParent)
{

}

CPopDlg::~CPopDlg()
{
}

void CPopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPopDlg, CDialogEx)
END_MESSAGE_MAP()


// CPopDlg 消息处理程序
