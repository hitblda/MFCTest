
// MFCTestDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCTest.h"
#include "MFCTestDlg.h"
#include "afxdialogex.h"
#include <atlbase.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

LPCTSTR CMFCTestDlg::mWeek[] =
{
	_T("星期日"),
	_T("星期一"),
	_T("星期二"),
	_T("星期三"),
	_T("星期四"),
	_T("星期五"),
	_T("星期六"),
	NULL
};

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
public:
	afx_msg void OnEditGo();
//	afx_msg void OnDropFiles(HDROP hDropInfo);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

	ON_COMMAND(ID_EDIT_GO, &CAboutDlg::OnEditGo)
//	ON_WM_DROPFILES()
END_MESSAGE_MAP()


// CMFCTestDlg 对话框



CMFCTestDlg::CMFCTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCTEST_DIALOG, pParent)
	, m_value1(0)
	, m_value2(0)
	, m_value3(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_vEDIT1, m_value1);
	DDX_Text(pDX, IDC_vEDIT2, m_value2);
	DDX_Text(pDX, IDC_vEDIT3, m_value3);
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
	ON_COMMAND(ID_EDIT_UNDO, &CMFCTestDlg::OnEditUndo)
	ON_COMMAND(ID_EDIT_CUT, &CMFCTestDlg::OnEditCut)
	ON_COMMAND(ID_EDIT_COPY, &CMFCTestDlg::OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, &CMFCTestDlg::OnEditPaste)
	ON_COMMAND(ID_EDIT_CLEAR, &CMFCTestDlg::OnEditClear)
	ON_COMMAND(ID_EDIT_FIND, &CMFCTestDlg::OnEditFind)
	ON_COMMAND(ID_EDIT_REPLACE, &CMFCTestDlg::OnEditReplace)
	ON_COMMAND(ID_EDIT_SELECT_ALL, &CMFCTestDlg::OnEditSelectAll)
	ON_COMMAND(ID_EDIT_TIME, &CMFCTestDlg::OnEditTime)
	ON_COMMAND(ID_FILE_OPEN, &CMFCTestDlg::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &CMFCTestDlg::OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, &CMFCTestDlg::OnFileSaveAs)
	ON_COMMAND(ID_VIEW_LIST, &CMFCTestDlg::OnViewList)
	ON_BN_CLICKED(IDC_SEND, &CMFCTestDlg::OnBnClickedSend)
	ON_EN_CHANGE(IDC_vEDIT1, &CMFCTestDlg::OnEnChangevedit1)
	ON_EN_CHANGE(IDC_vEDIT2, &CMFCTestDlg::OnEnChangevedit2)
	ON_BN_CLICKED(IDC_OK, &CMFCTestDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCTestDlg 消息处理程序

BOOL CMFCTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog(); 

#if 0
	//获取资源
	CWnd* p1 = AfxGetMainWnd();
	CWnd* p2 = theApp.m_pMainWnd;
	//HINSTANCE handler = AfxGetInstanceHandle();
	//HINSTANCE handler = AfxGetApp()->m_hInstance;
	CWinApp* pApp = AfxGetApp();
	pApp->LoadIconW(IDR_MAINFRAME); //
	//AfxGetInstanceHandle();

	//获取主窗口
	//CWnd* handler = AfxGetMainWnd();
	CWinApp* handler = AfxGetApp();
	handler->LoadIconW(IDR_MAINFRAME);
#endif
	////拖拽失效
	//ChangeWindowMessageFilter(WM_DROPFILES, MSGFLT_ADD);
	//ChangeWindowMessageFilter(0x0049, MSGFLT_ADD);       // 0x0049 == WM_COPYGLOBALDATA
	
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

	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST2);
/*	void ListInsertColumn(int nIndex,  //第几个位置的索引
		LPCTSTR sHeader,	//标志
		int nFormat,	//左对齐？右对齐
		int nWidth)	{...}
*/
	//HWND hWnd = GetDlgItem(this, IDC_LIST2);
//	pList->InsertColumn(0, _T("第五列"), 0, 60);
	pList->InsertColumn(1, _T("文件名"), 0, 200);//左对齐
	pList->InsertColumn(2, _T("类型"), 0, 80);
	pList->InsertColumn(3, _T("大小"), 0, 60);
	pList->InsertColumn(4, _T("修改日期"), 1, 230); //右对齐
	pList->SetTextBkColor(RGB(255, 255, 255));
	
#if 0

	TCHAR s[64];
	HWND hWnd = GetDlgItem(handler,IDC_LIST2);
	GetDlgItemText(handler, IDC_NUMB, s, _countof(s));
	List_InsertItem(hWnd, 0, s);
#endif
	

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
	if (!file.Open(sFile, CFile::modeRead))
	{
		//文件权限不够打不开、文件正在被操作被占用了
		MessageBox(L"文件不存在！");
	}
	MessageBox(L"文件正常读取中！");
	int nRet;
	while (nRet = file.Read(sFile, sizeof(sFile))) //read读，返回的是读到的字节数
	{
		TRACE(L"按字节数计算，个数为：%d", nRet);
		int tmp = _countof(sFile);
		TRACE(L"按TCHAR数计算，个数为：%d", tmp);

		//读取文件最后加上结束位
		sFile[nRet] = (TCHAR )L"\0";
		//打开的文件编码非UNICODE 而界面是UNICODE 

	}


	
	file.Close();
	CDialogEx::OnDropFiles(hDropInfo);
}

void UTF8toANSI(LPSTR strUTF8)
{
	//获取转换为多个字节之后需要的缓冲区大小，创建多字节缓冲区
	UINT nLen = MultiByteToWideChar(CP_UTF8, NULL, strUTF8, -1, NULL, NULL);
	WCHAR* wszBuffer = new WCHAR[nLen + 1];
	nLen = MultiByteToWideChar(CP_UTF8, NULL, strUTF8, -1, wszBuffer, nLen);
	wszBuffer[nLen] = 0;

	nLen = WideCharToMultiByte(939, NULL, wszBuffer, -1, NULL, NULL, NULL, NULL);
	CHAR* szBuffer = new CHAR[nLen + 1];
	nLen = WideCharToMultiByte(939, NULL, wszBuffer, -1, szBuffer, nLen, NULL, NULL);
	szBuffer[nLen] = 0;

	strUTF8 = szBuffer;
	//内存清除
	delete[] wszBuffer;
	delete[] szBuffer;
}

void ANSItoUFT8(LPSTR strANSI)
{
	//获取转换为多个字节之后需要的缓冲区大小，创建多字节缓冲区
	UINT nLen = MultiByteToWideChar(936, NULL, strANSI, -1, NULL, NULL);
	WCHAR* wszBuffer = new WCHAR[nLen + 1];
	nLen = MultiByteToWideChar(936, NULL, strANSI, -1, wszBuffer, nLen);
	wszBuffer[nLen] = 0;

	nLen = WideCharToMultiByte(CP_UTF8, NULL, wszBuffer, -1, NULL, NULL, NULL, NULL);
	CHAR* szBuffer = new CHAR[nLen + 1];
	nLen = WideCharToMultiByte(CP_UTF8, NULL, wszBuffer, -1, szBuffer, nLen, NULL, NULL);
	szBuffer[nLen] = 0;

	strANSI = szBuffer;
	//内存清除
	delete[] wszBuffer;
	delete[] szBuffer;
}


void CMFCTestDlg::ReadAnsi(CFile& file)
{
	// TODO: 在此处添加实现代码.
	file.Seek(0, CFile::begin);
	char buff[1024];
	UINT nRet = 0;
	CString str = 0;
	while (nRet = file.Read(buff, sizeof(buff) - 1))
	{
		buff[nRet] = *(L"\0");
		str += buff;
	}
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	pEdit->ReplaceSel(str); //以该文本替换编辑处
}

void CMFCTestDlg::ReadUnicode(CFile& file)
{
	file.Seek(2, CFile::begin);//从头部开始的第三个开始读
	LONGLONG nLen = file.GetLength();
	TCHAR* p = new TCHAR[nLen/2 + 1];
	nLen = file.Read(p, nLen);
	p[nLen/2] = *(L"\0");
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	pEdit->ReplaceSel(p); //以该文本替换编辑处

	delete[]p;
}

void CMFCTestDlg::ReadUTF8(CFile& file)
{
	char buff[1024];
	UINT nRet = 0;
	CString str = 0;

	file.Seek(3, CFile::begin);//从头部开始的第三个开始读
	LONGLONG nLen = file.GetLength();
	char* p = new char[nLen+1];
	nLen = file.Read(p, nLen);
	p[nLen] = *(L"\0");
	TCHAR* pText = new TCHAR[nLen / 2 + 2];

	MultiByteToWideChar(CP_UTF8, NULL, p, -1, pText, nLen / 2 + 2);

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	pEdit->ReplaceSel(str); //以该文本替换编辑处

	delete[]p;
	delete[]pText;
}



void CMFCTestDlg::OnFileOpen()
{
	BOOL isOpen = TRUE;		//是否打开(否则为保存)
	CString defaultDir = L"E:/works";	//默认打开的文件路径
	CString fileName = L""; //默认打开的文件名
	//CString filter = L"文件 (*.txt; *.doc; *.ppt; *.xls)|*.txt;*.doc;*.ppt;*.xls||";	//文件过虑的类型
	CString filter = L"文件 (*.txt; *.c; *.cpp)|*.txt;*.c;*.cpp;*||";	//文件过虑的类型
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = L"E:/works/test.doc";
	INT_PTR result = openFileDlg.DoModal();
	CString filePath = defaultDir + "/步行者机器人资料.doc";
	if (result == IDOK) {
		filePath = openFileDlg.GetPathName();
	}
	CWnd::SetDlgItemTextW(IDC_EDIT, filePath);

	CFile file;
	file.Open(openFileDlg.GetPathName(), CFile::modeReadWrite);//打开上面的路径，读到我们想要了解的那个文件
	
	//文件类型的判断，以二进制先读2个字节出来
	TCHAR sFile[256];
	if (file.Read(sFile, 2) == 2)
	{
		switch (sFile[0])
		{
		case 0xBBEF:
			ReadUTF8(file);
			break;
		case 0xFFFE:
			ReadUnicode(file);
			break;
		default:
			/*filePath = L"格式不是UTF8 也不是Unicode（UTF16 littleEnd）";
			CWnd::SetDlgItemTextW(IDC_EDIT, filePath);*/
			//
			ReadAnsi(file);
			break;
		}
	}
	file.Close();
}

void CMFCTestDlg::OnFileSave()
{
	BOOL isOpen = TRUE;		//是否打开(否则为保存)
	CString defaultDir = L"E:\\FileTest";	//默认打开的文件路径
	CString fileName = L"test.doc";			//默认打开的文件名
	CString filter = L"文件 (*.doc; *.ppt; *.xls)|*.doc;*.ppt;*.xls||";	//文件过虑的类型
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = L"E:\\FileTest\\test.doc";
	INT_PTR result = openFileDlg.DoModal();
	CString filePath = defaultDir + "\\" + fileName;
	if (result == IDOK) {
		filePath = openFileDlg.GetPathName();
	}
	//CWnd::SetDlgItemTextW(IDC_EDIT, filePath);
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	pEdit->ReplaceSel(filePath); //以该文本替换编辑处

}

void CMFCTestDlg::OnFileSaveAs()
{
	//BOOL isOpen = FALSE;		//是否打开(否则为保存)
	//CString defaultDir = L"E:\\FileTest";	//默认打开的文件路径
	//CString fileName = L"test.doc";			//默认打开的文件名
	//CString filter = L"文件 (*.doc; *.ppt; *.xls)|*.doc;*.ppt;*.xls||";	//文件过虑的类型
	//CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter, NULL);
	//openFileDlg.GetOFN().lpstrInitialDir = L"E:\\FileTest\\test.doc";
	//INT_PTR result = openFileDlg.DoModal();
	//CString filePath = defaultDir + "\\" + fileName;
	//if (result == IDOK) {
	//	filePath = openFileDlg.GetPathName();
	//}
	////CWnd::SetDlgItemTextW(IDC_EDIT, filePath);
	//CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	//pEdit->ReplaceSel(filePath); //以该文本替换编辑处
	
	TCHAR Data[1024];
	CString m_txtName = L"test.doc";
	CStdioFile file;
	CString filepath;
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	CFileDialog fileDlg(FALSE, _T("txt"), m_txtName, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);

	if (IDOK == fileDlg.DoModal())
	{
		filepath = fileDlg.GetPathName();
		file.Open(filepath, CFile::modeCreate | CFile::modeWrite | CFile::typeText);
		CString str;
		for (int i = 0; i < _countof(Data); ++i)
		{
			str.Format(_T("%d %d\n"), i + 1, Data[i]);
			file.WriteString(str);
		}
		file.Close();
	}

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
	dlg.DoModal(); //
}


//窗口大小改变时
void CMFCTestDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
//	CWnd* p = GetDlgItem(IDC_EDIT);
//	if (p)
//	{
//		TRACE(L"窗口大小改变了 ");
////		TRACE(L"窗口大小改变了 长：%L  宽:%L",cx,cy);
//
//		CRect rect;
//		GetClientRect(rect);//窗口是以客户区为坐标系
//		p->MoveWindow(rect);
//
//	}


	// TODO: 在此处添加消息处理程序代码
}


void CMFCTestDlg::OnEditUndo()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	pEdit->Undo();
}


void CMFCTestDlg::OnEditCut()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	pEdit->Cut();
}


void CMFCTestDlg::OnEditCopy()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	pEdit->Copy();
}


void CMFCTestDlg::OnEditPaste()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	pEdit->Paste();
}


void CMFCTestDlg::OnEditClear()
{
	// TODO: 在此添加命令处理程序代码
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	pEdit->Clear(); 
}


void CMFCTestDlg::OnEditFind()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	//pEdit->Find();
}


void CMFCTestDlg::OnEditReplace()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	//pEdit->ReplaceSel();
}


void CAboutDlg::OnEditGo()
{
	// TODO: 在此添加命令处理程序代码
}


void CMFCTestDlg::OnEditSelectAll()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	pEdit->SetSel(0,-1); //全选
}


void CMFCTestDlg::OnEditTime()
{
	COleDateTime tm = COleDateTime::GetCurrentTime();
	CString str = tm.Format(L"%H:%M:%S %Y%m%d %W");

	////如下方法最简单，但效果是覆盖式的
	//SetDlgItemText(IDC_EDIT, str);
	CEdit *pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	pEdit->ReplaceSel(str); //以该文本替换编辑处

	// TODO: 在此添加命令处理程序代码
}



void CMFCTestDlg::OnViewList()
{

	// 点击，新的弹出对话框
	CPopDlg mPopDlg;
	mPopDlg.DoModal();

	//CPopDlg* pDlg = new CPopDlg;
	//pDlg->Create(IDD_PopDlg,CWnd::GetDesktopWindow());
	//pDlg->ShowWindow(SW_SHOW);

	//CListCtrl* pList = (CListCtrl*)mPopDlg.GetDlgItem(IDC_popLIST1);
	//CListCtrl* pList = (CListCtrl*)mPopDlg.GetDlgItem(IDD_PopDlg);
	//pList->InsertColumn(0, L"工号，0，100");

}


void CMFCTestDlg::PreSubclassWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	//CPopDlg* p_popDlg = new CPopDlg;
	//GetParent()->GetDlgItem(IDC_EDIT);
	//p_popDlg->Create(IDD_PopDlg, GetParent()->GetDlgItem(IDD_PopDlg));
	//CListCtrl *pList =(CListCtrl*)m_popDlg.GetDlgItem(IDC_PopList);
	//pList->InsertColumn(0, L"工号，0，100");


	//m_popDlg.Detach();
	CDialogEx::PreSubclassWindow();
}


void CMFCTestDlg::OnBnClickedSend()
{
	// TODO: 在此添加控件通知处理程序代码
	int n1, n2, n3;
	TCHAR ch1[12], ch2[12], ch3[12];
	::SendMessage(GetDlgItem(IDC_vEDIT1)->m_hWnd, WM_GETTEXT, 12, (LPARAM)ch1);
	::SendMessage(GetDlgItem(IDC_vEDIT2)->m_hWnd, WM_GETTEXT, 12, (LPARAM)ch2);
	n1 = _ttoi(ch1);
	n2 = _ttoi(ch2);
	n3 = n1 + n2;

	_itow_s(n3,ch3,10);
	::SendMessage(GetDlgItem(IDC_vEDIT3)->m_hWnd, WM_SETTEXT, 0, (LPARAM)ch3);
}


void CMFCTestDlg::OnEnChangevedit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	
}


void CMFCTestDlg::OnEnChangevedit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
} 

#include <io.h>
//#include <AtlBase.h>
void CMFCTestDlg::OnBnClickedOk()
{
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST2);
	pList->DeleteAllItems();//否则会 点击一次，显示的效果累加显示一次
	//struct _finddata_t c_file;  //_finddata_t可以根据机器是32位还是64位而定 
	//struct _wfinddata_t c_file;  //宽字符串
	WIN32_FIND_DATA c_file;  //MFC 中的搜索结构体

	CString str;
	CString szAddr;
	GetDlgItemText(IDC_ADDR, szAddr); //获取控件的输入，作为显示的路径

	//intptr_t hFile = -1; //WinAPI
	HANDLE hFile ; //采用MFC 
	int i = 0;



	//if ((hFile = _findfirst("C:\\*.*", &c_file)) == -1L)  //获得的是 窄字符串
	//if ( (hFile = _wfindfirst(szAddr+ L"\\*.*", &c_file)) == -1L) //WInAPI
	if ( (hFile = FindFirstFile(szAddr+ L"\\*.*", &c_file)) == INVALID_HANDLE_VALUE)
		//查找C盘下所有的文件 ;但只是本层目录下
	{
		MessageBox(L"No *.* fiels in current directroy!");
		return;
	}
	do
	{
//		文件属性里面添加新的属性  c_file.attrib |= _A_RDONLY;
//		文件属性里面删除属性  c_file.attrib &= ~_A_RDONLY;

		
		if (!(IsHidden(c_file)))
		{
			//窄字符串转宽字符串
			//USES_CONVERSION;
			//pList->InsertItem(i, A2T(c_file.name), IDC_LIST2);
			pList->InsertItem(i, (c_file.cFileName), IDC_LIST2);
			if (FILE_ATTRIBUTE_DIRECTORY & c_file.dwFileAttributes) //是文件夹
			{
				pList->SetItemText(i, 1, L"文件夹");
			}
			else
			{
				str = c_file.cFileName;
				int n = str.ReverseFind(_T('.')); //逆向查找直到.为止
				if (n > 0)
				{
					pList->SetItemText(i, 1, str.Mid(n + 1) + L"文件"); //Mid(n+1)是不显示.
				}

				//INT mSize,msL,msH;
				//mSize = (c_file.nFileSizeLow) / 1024;
				//if( (mSize >= 1000)&&(mSize<1000000))
				//{
				//	msL = mSize % 1024;
				//	mSize /= 1024;
				//	str.Format(L"%d,%dK",mSize, msL);
				//}
				//else if (mSize > 1000000)
				//{
				//	msL = mSize % 1024;
				//	mSize = mSize / 1024;
				//	msH = mSize % 1024;
				//	mSize /= 1024;

				//	str.Format(L"%d,%d,%dK", mSize, msH, msL);
				//}
				//else if (mSize < 1000)
				//{
				//	str.Format(L"%dK",mSize);
				//}
				str.Format(L"%dK", (c_file.nFileSizeLow) / 1024);
				pList->SetItemText(i, 2, str);
			}
			COleDateTime time(c_file.ftLastWriteTime);
			str.Format(L"%d年%d月%d日%s%d分:%d秒", time.GetYear(), time.GetMonth(), time.GetDay(), 
				mWeek[time.GetDayOfWeek()-1],time.GetMinute(),time.GetSecond());
			pList->SetItemText(i, 3, str);

			i++;
		}

		//TRACE((c_file.attrib & _A_RDONLY) ? "Y" : "N");
		//TRACE((c_file.attrib & _A_HIDDEN) ? "Y" : "N");
		//TRACE((c_file.attrib & _A_SYSTEM) ? "Y" : "N");
		//TRACE((c_file.attrib & _A_ARCH) ? "Y" : "N");
		//char s[256];
		//char buffer[256];
		//ctime_s(buffer, _countof(buffer), &c_file.time_write);
		//sprintf_s(s,sizeof(s),"%-12s %.24s %91d\n", c_file.name, buffer, c_file.size);

	} while (FindNextFile(hFile, &c_file));
	FindClose(hFile);
	
}
