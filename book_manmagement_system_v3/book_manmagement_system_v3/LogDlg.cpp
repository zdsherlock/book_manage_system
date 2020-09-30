// LogDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "book_manmagement_system_v3.h"
#include "LogDlg.h"
#include "afxdialogex.h"
#include "AdminDlg.h"


// CLogDlg 对话框

IMPLEMENT_DYNAMIC(CLogDlg, CDialogEx)

CLogDlg::CLogDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLogDlg::IDD, pParent)
{

}

CLogDlg::~CLogDlg()
{
}

void CLogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_USER_NAME, m_userName);
	DDX_Control(pDX, IDC_EDIT_PASS_WORD, m_passWord);
}




// CLogDlg 消息处理程序

BEGIN_MESSAGE_MAP(CLogDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN_IN, &CLogDlg::OnBnClickedButtonLoginIn)
	ON_BN_CLICKED(IDCANCEL, &CLogDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


void CLogDlg::OnBnClickedButtonLoginIn()
{
	// TODO: 在此添加控件通知处理程序代码
	//窗体相关声明
	CString strName;
	CString strPasswd;

	m_userName.GetWindowText(strName);//窗体输入的用户名
	m_passWord.GetWindowText(strPasswd);//窗体输入的密码

	//数据库相关声明
	sqlite3* db;
	int rc;
	char* sql;
	char *errMsg;
	char **dbResult;
	int nRow = 0, nColumn = 0;

	//打开数据库
	rc = sqlite3_open("password.db",&db);
	if (rc)//数据库不存在时候的保险
	{
		MessageBox(_T("数据不存在"));
	}

	sql = "SELECT * FROM password"; //定义SQL语句

	sqlite3_get_table(db,sql,&dbResult,&nRow,&nColumn,&errMsg);

	CString Name(dbResult[1*nColumn+1]);	//数据库中的用户名
	CString Passwd(dbResult[1*nColumn+2]);	//数据库中的密码
	sqlite3_free_table(dbResult);
	//弹出管理员界面
	if( strName.IsEmpty()||strPasswd.IsEmpty() )
	{	
		MessageBox(_T("用户名密码不能为空"));
	}
	else if( Name != strName || Passwd != strPasswd )
	{
		MessageBox(_T("用户名或密码错误"));
	}
	else
	{
		CAdminDlg dlg;
		dlg.DoModal();
	}//代码异常，测试跳出 <zd006>
	CAdminDlg dlg;
	dlg.DoModal();
}


void CLogDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
