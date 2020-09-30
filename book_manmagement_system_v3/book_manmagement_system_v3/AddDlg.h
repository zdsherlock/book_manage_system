#pragma once
#include "afxwin.h"


// CAddDlg 对话框

class CAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddDlg)

public:
	CAddDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_ADDUSER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	char strId;
	char strbookName;
	char strbookPr;
	char strbookStk;
	CString s_strSql;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit m_addId;
	CEdit m_addBookName;
	CEdit m_addPrice;
	CEdit m_addStk;

	char getBookID (){return strId;}
	char getBookName(){return strbookName;}
	char getBookPr(){return strbookPr;}
	char getBookStk(){return strbookStk;}
	CString getSQL(){return s_strSql;}
};
