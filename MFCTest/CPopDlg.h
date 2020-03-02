#pragma once


// CPopDlg 对话框

class CPopDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPopDlg)

public:
	CPopDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CPopDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PopDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
