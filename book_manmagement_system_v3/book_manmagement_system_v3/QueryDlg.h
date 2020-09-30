#pragma once
#include "afxwin.h"


// CQueryDlg 对话框

class CQueryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CQueryDlg)

public:
	CQueryDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CQueryDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_QUERY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	CString strBookId;
	CString m_strBookId;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	//CString GetBookID();
	CString GetBookID(){return m_strBookId;}
	CEdit m_Id;
	CEdit m_Name;
	CEdit m_Prc;
	CEdit m_Num;
};
