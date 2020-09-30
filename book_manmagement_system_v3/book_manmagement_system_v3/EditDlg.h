#pragma once
#include "afxwin.h"


// CEditDlg �Ի���

class CEditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditDlg)

public:
	CEditDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	char strId;
	char strBookName;
	char strBookPr;
	char strBookStk;
	CString s_strSql;
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit_addId;
	CEdit m_edit_addBookName;
	CEdit m_edit_addPr;
	CEdit m_edit_addStk;
	afx_msg void OnBnClickedOk();
	CString getSql(){return s_strSql;}
};
