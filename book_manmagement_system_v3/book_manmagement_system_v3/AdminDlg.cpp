// AdminDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "book_manmagement_system_v3.h"
#include "AdminDlg.h"
#include "afxdialogex.h"
#include "AddDlg.h"
#include "EditDlg.h"
#include "QueryDlg.h"


// CAdminDlg 对话框

IMPLEMENT_DYNAMIC(CAdminDlg, CDialogEx)

CAdminDlg::CAdminDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAdminDlg::IDD, pParent)
{

}

CAdminDlg::~CAdminDlg()
{
}

void CAdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListAdmin);
}


BOOL CAdminDlg::OnInitDialog()
{
	 CDialogEx::OnInitDialog();//在派生类的成员函数，调用基类<zd005>

	 DWORD dwStyle = m_ListAdmin.GetExtendedStyle();   //listcontrol部分  
	 dwStyle |= LVS_EX_FULLROWSELECT;
	 dwStyle |= LVS_EX_GRIDLINES;
	 m_ListAdmin.SetExtendedStyle(dwStyle);
	 m_ListAdmin.InsertColumn(0, _T("ID"), LVCFMT_CENTER, 50);
	 m_ListAdmin.InsertColumn(1, _T("书名"), LVCFMT_CENTER, 60);
	 m_ListAdmin.InsertColumn(2, _T("价格"), LVCFMT_CENTER, 60);
	 m_ListAdmin.InsertColumn(3, _T("库存"), LVCFMT_CENTER, 60);

	 update();

	 return TRUE;
}

BEGIN_MESSAGE_MAP(CAdminDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CAdminDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &CAdminDlg::OnBnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CAdminDlg::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDCANCEL, &CAdminDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CAdminDlg::OnBnClickedButtonQuery)
END_MESSAGE_MAP()

// CAdminDlg 消息处理程序
void CAdminDlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码

	CAddDlg dlg;
	dlg.DoModal();//显示添加窗体

	//获取输入值
	CString strSql = dlg.getSQL();

	adminSql(strSql);
	
	update();

}

void CAdminDlg::OnBnClickedButtonEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	//显示修改窗体
	CEditDlg dlg;
	dlg.DoModal();

	//更新界面值;
	CString strSql = dlg.getSql();
	adminSql(strSql);

	update();
}

void CAdminDlg::OnBnClickedButtonDel()
{
	// TODO: 在此添加控件通知处理程序代码
	//删除命令的逻辑思考<zd003>
	POSITION pos =m_ListAdmin.GetFirstSelectedItemPosition();
	if (pos == NULL)
		MessageBox(_T("请选择您要操作的书"));
	else
	{
		 CString strSql;
		 CString strId;
		 int iIndex  = m_ListAdmin.GetNextSelectedItem(pos);  
		 strId = m_ListAdmin.GetItemText(iIndex,0);
		 m_ListAdmin.DeleteItem(iIndex);  
		 MessageBox(_T("删除成功"));
		 strSql.Format(_T("DELETE FROM book WHERE ID = %s"),strId);

		 adminSql(strSql);
	}

	update();
}

void CAdminDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

void CAdminDlg::OnBnClickedButtonQuery()
{
	// TODO: 在此添加控件通知处理程序代码
	CString iUn;
	CQueryDlg dlg;
	dlg.DoModal();

	iUn = dlg.GetBookID();
	int lRow;
	lRow = m_ListAdmin.GetItemCount();

	for(int i = 0; i <= lRow; i++)
	{
		if (iUn == m_ListAdmin.GetItemText(i,0))
		{
			m_ListAdmin.SetItemState(i,LVIS_DROPHILITED,LVIS_DROPHILITED);//为什么这里可以取值，事件触发的时候应该还没有数据<zd009>
			break;
		}
	}
}

//自定义函数update()
void CAdminDlg::update()
{
	sqlite3* db;
	char* sql;
	char *errMsg;
	char **dbResult;
	int nRow = 0, nColumn = 0;
	int rc;

	sqlite3_open("test3.db",&db);

	sql = "SELECT * FROM book ORDER BY id";

	rc = sqlite3_exec(db,sql,0,0,0);

	sql = "SELECT * FROM book";

	sqlite3_get_table(db,sql,&dbResult,&nRow,&nColumn,&errMsg);

	int iList = 0;

	m_ListAdmin.DeleteAllItems();

	for (int i = 1; i<(nRow+1); i++)
	{
		for ( int j = 0; j < nColumn; j++ )
		{
			CString strSql;
			strSql = dbResult[i*nColumn+j];
			if ( j == 0 )
			{
				m_ListAdmin.InsertItem(iList, strSql);
			}
			else
			{
				m_ListAdmin.SetItemText(iList, j, strSql);
			}
		}
		++iList;
	}
	
	sqlite3_close;
}

void CAdminDlg::adminSql(CString sql)
{
	//打开数据库
	int rc;
	sqlite3 *db;

	rc = sqlite3_open("test3.db",&db);//打开数据库

	if(rc)
	{
		MessageBox(_T("数据库打开错误open"));
	}

	USES_CONVERSION;
	char*strSql=T2A(sql);

	rc = sqlite3_exec(db,strSql,0,0,0);//解析SQL语句

	if(rc != SQLITE_OK)
	{
		MessageBox(_T("数据库打开错误exec"));
	}

	sqlite3_close;//关闭数据库
}

