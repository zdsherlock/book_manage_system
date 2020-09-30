#pragma once
#include "afxcmn.h"


// CAdminDlg �Ի���

class CAdminDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAdminDlg)

public:
	CAdminDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAdminDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADMIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButtonDel();
	afx_msg void OnBnClickedCancel();
	CListCtrl m_ListAdmin;
	afx_msg void OnBnClickedButtonQuery();
	void update();
	void adminSql(CString sql);
};
