// QueryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "book_manmagement_system_v3.h"
#include "QueryDlg.h"
#include "afxdialogex.h"
#include "AdminDlg.h"


// CQueryDlg �Ի���

IMPLEMENT_DYNAMIC(CQueryDlg, CDialogEx)

CQueryDlg::CQueryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CQueryDlg::IDD, pParent)
{

}

CQueryDlg::~CQueryDlg()
{
}

void CQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_QUERY_ID, m_Id);
	DDX_Control(pDX, IDC_EDIT_QUERY_NAME, m_Name);
	DDX_Control(pDX, IDC_EDIT_QUERY_PR, m_Prc);
	DDX_Control(pDX, IDC_EDIT_QUERY_STK, m_Num);
}


BEGIN_MESSAGE_MAP(CQueryDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CQueryDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CQueryDlg ��Ϣ�������

BOOL CQueryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();//��������ĳ�Ա���������û���<zd005>

	return TRUE;
}

void CQueryDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strBookId;
	m_Id.GetWindowText(strBookId);//����������û���

	m_strBookId = strBookId;
	CDialogEx::OnOK();
}

