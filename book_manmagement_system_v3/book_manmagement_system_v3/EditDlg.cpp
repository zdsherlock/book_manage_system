// EditDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "book_manmagement_system_v3.h"
#include "EditDlg.h"
#include "afxdialogex.h"


// CEditDlg �Ի���

IMPLEMENT_DYNAMIC(CEditDlg, CDialogEx)

CEditDlg::CEditDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEditDlg::IDD, pParent)
{

}

CEditDlg::~CEditDlg()
{
}

void CEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ID, m_edit_addId);
	DDX_Control(pDX, IDC_EDIT_BOOK_NAME, m_edit_addBookName);
	DDX_Control(pDX, IDC_EDIT_PR, m_edit_addPr);
	DDX_Control(pDX, IDC_EDIT_STK, m_edit_addStk);
}


BEGIN_MESSAGE_MAP(CEditDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CEditDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CEditDlg ��Ϣ�������


void CEditDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strBookId;
	CString strBookName;
	CString strBookPr;
	CString strBookStk;
	CString strSql;

	m_edit_addId.GetWindowText(strBookId);
	m_edit_addBookName.GetWindowText(strBookName);
	m_edit_addPr.GetWindowText(strBookPr);
	m_edit_addStk.GetWindowText(strBookStk);

	strSql.Format(_T("UPDATE book SET book_name = '%s' , price = %s , inventory = %s WHERE ID = %s"),strBookName,strBookPr,strBookStk,strBookId);
	s_strSql = strSql;

	CDialogEx::OnOK();
}
