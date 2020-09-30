#pragma once
#include "afxwin.h"


// CAddDlg �Ի���

class CAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddDlg)

public:
	CAddDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADDUSER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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
