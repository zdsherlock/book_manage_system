// AddDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "book_manmagement_system_v3.h"
#include "AddDlg.h"
#include "afxdialogex.h"


// CAddDlg �Ի���

IMPLEMENT_DYNAMIC(CAddDlg, CDialogEx)

CAddDlg::CAddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddDlg::IDD, pParent)
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ADD_ID, m_addId);
	DDX_Control(pDX, IDC_EDIT_ADD_NAME, m_addBookName);
	DDX_Control(pDX, IDC_EDIT_ADD_PR, m_addPrice);
	DDX_Control(pDX, IDC_EDIT_ADD_STK, m_addStk);
}


BEGIN_MESSAGE_MAP(CAddDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddDlg ��Ϣ�������


void CAddDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		CString strBookId;
		CString strBookName;
		CString strBookPr;
		CString strBookStk;
		CString strSql;

		m_addId.GetWindowText(strBookId);//��ȡID
		m_addBookName.GetWindowText(strBookName);//��ȡ����
		m_addPrice.GetWindowText(strBookPr);//��ȡ��ļ۸�
		m_addStk.GetWindowText(strBookStk);//��ȡ����Ŀ����

		strSql.Format(_T("INSERT INTO book(id,book_name,price,inventory) VALUES(%s,'%s',%s,%s)"),strBookId,strBookName,strBookPr,strBookStk);
		
		s_strSql = strSql;

	CDialogEx::OnOK();
}
