
// MFCTestDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCTest.h"
#include "MFCTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()


// CMFCTestDlg 对话框



CMFCTestDlg::CMFCTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_APP_EXIT, &CMFCTestDlg::OnAppExit)
	ON_WM_DROPFILES()
	ON_COMMAND(ID_FILE_NEW, &CMFCTestDlg::OnFileNew)
	ON_COMMAND(57664, &CMFCTestDlg::OnAppAbout)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CMFCTestDlg 消息处理程序

BOOL CMFCTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCTestDlg::OnOK()
{
	TRACE(L" 你按下了回车键！"); 
	MessageBox(L"这是一个确定 取消的消息框！", L"标题", MB_OKCANCEL);
}


void CMFCTestDlg::OnCancel()
{
	if (MessageBox(L"警告：确定将退出！", L"警告", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL)
		return;
	CDialogEx::OnCancel();

}


void CMFCTestDlg::OnAppExit()
{
	// TODO: 在此添加命令处理程序代码
	EndDialog(IDCANCEL);
}

//鼠标将文本文件拖动到编辑区时 
//文档编辑区的属性Accept File选项要设置为True
//选择消息为WM_DropFiles
void CMFCTestDlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	TCHAR sFile[256];
#if 0
	int nCount = DragQueryFile(hDropInfo, -1, NULL, 0);//第二个参数-1表示求拖了几个文件
	//当依次拖了几个文件时
	int i = 0;
	while (i < nCount) 
	{
		DragQueryFile(hDropInfo, i, sFile, _countof(sFile)); //依次获取文件名到sFile
		++i;
	}
#endif

	//不管拖几个，只打开第一个
	DragQueryFile(hDropInfo, 0, sFile, _countof(sFile)); //依次获取文件名到sFile
	CFile file;
	//打开的文件编码非UNICODE 而界面是UNICODE 



	CDialogEx::OnDropFiles(hDropInfo);
}


void CMFCTestDlg::OnFileNew()
{
	MessageBox(L"你要新建什么呢？");
	// TODO: 在此添加命令处理程序代码
}


//关于按键 About消息 触发的事件
void CMFCTestDlg::OnAppAbout()
{
	// TODO: 在此添加命令处理程序代码
	CAboutDlg dlg;
	dlg.DoModal();
}


//窗口大小改变时
void CMFCTestDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	CWnd* p = GetDlgItem(IDC_EDIT1);
	if (p)
	{
		TRACE(L"窗口大小改变了 ");
//		TRACE(L"窗口大小改变了 长：%L  宽:%L",cx,cy);

		CRect rect;
		GetClientRect(rect);//窗口是以客户区为坐标系
		p->MoveWindow(rect);

	}


	// TODO: 在此处添加消息处理程序代码
}
