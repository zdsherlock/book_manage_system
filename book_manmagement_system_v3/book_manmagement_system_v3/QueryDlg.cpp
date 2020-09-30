// QueryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "book_manmagement_system_v3.h"
#include "QueryDlg.h"
#include "afxdialogex.h"
#include "AdminDlg.h"


// CQueryDlg 对话框

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


// CQueryDlg 消息处理程序

BOOL CQueryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();//在派生类的成员函数，调用基类<zd005>

	return TRUE;
}

void CQueryDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strBookId;
	m_Id.GetWindowText(strBookId);//窗体输入的用户名

	m_strBookId = strBookId;
	CDialogEx::OnOK();
}

