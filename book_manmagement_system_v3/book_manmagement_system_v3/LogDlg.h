#pragma once
#include "afxwin.h"


// CLogDlg �Ի���

class CLogDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLogDlg)

public:
	CLogDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLogDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_LOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButtonLoginIn();
	afx_msg void OnBnClickedCancel();
	CEdit m_userName;
	CEdit m_passWord;
};
