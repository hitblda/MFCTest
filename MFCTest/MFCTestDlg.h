
// MFCTestDlg.h: 头文件
//

#pragma once
#include "CPopDlg.h"


// CMFCTestDlg 对话框
class CMFCTestDlg : public CDialogEx
{
	inline static BOOL IsHidden(const WIN32_FIND_DATA& c_file)
	{
		if (c_file.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)
			return TRUE;
		if (!_tcscmp(c_file.cFileName, L"."))
			return TRUE;
		if (!_tcscmp(c_file.cFileName, L".."))
			return TRUE;

		return false;
	}

	static LPCTSTR  mWeek[];
// 构造
public:
	CMFCTestDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();

	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAppExit();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnFileNew();
	afx_msg void OnAppAbout();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnEditUndo();
	afx_msg void OnEditCut();
	afx_msg void OnEditCopy();
	afx_msg void OnEditPaste();
	afx_msg void OnEditClear();
	afx_msg void OnEditFind();
	afx_msg void OnEditReplace();
	afx_msg void OnEditSelectAll();
	afx_msg void OnEditTime();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	void ReadAnsi(CFile& file);
	void ReadUnicode(CFile& file);
	void ReadUTF8(CFile& file);
	afx_msg void OnViewList();
	CPopDlg m_popDlg;
	virtual void PreSubclassWindow();
	UINT m_value1;
	UINT m_value2;
	UINT m_value3;
	afx_msg void OnBnClickedSend();
	afx_msg void OnEnChangevedit1();
	afx_msg void OnEnChangevedit2();
	afx_msg void OnBnClickedOk();
};
