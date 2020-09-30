// AddDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "book_manmagement_system_v3.h"
#include "AddDlg.h"
#include "afxdialogex.h"


// CAddDlg 对话框

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


// CAddDlg 消息处理程序


void CAddDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
		CString strBookId;
		CString strBookName;
		CString strBookPr;
		CString strBookStk;
		CString strSql;

		m_addId.GetWindowText(strBookId);//获取ID
		m_addBookName.GetWindowText(strBookName);//获取书名
		m_addPrice.GetWindowText(strBookPr);//获取书的价格
		m_addStk.GetWindowText(strBookStk);//获取输入的库存数

		strSql.Format(_T("INSERT INTO book(id,book_name,price,inventory) VALUES(%s,'%s',%s,%s)"),strBookId,strBookName,strBookPr,strBookStk);
		
		s_strSql = strSql;

	CDialogEx::OnOK();
}
