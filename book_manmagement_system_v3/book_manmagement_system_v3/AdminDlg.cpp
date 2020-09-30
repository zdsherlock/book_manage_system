// AdminDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "book_manmagement_system_v3.h"
#include "AdminDlg.h"
#include "afxdialogex.h"
#include "AddDlg.h"
#include "EditDlg.h"
#include "QueryDlg.h"


// CAdminDlg �Ի���

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
	 CDialogEx::OnInitDialog();//��������ĳ�Ա���������û���<zd005>

	 DWORD dwStyle = m_ListAdmin.GetExtendedStyle();   //listcontrol����  
	 dwStyle |= LVS_EX_FULLROWSELECT;
	 dwStyle |= LVS_EX_GRIDLINES;
	 m_ListAdmin.SetExtendedStyle(dwStyle);
	 m_ListAdmin.InsertColumn(0, _T("ID"), LVCFMT_CENTER, 50);
	 m_ListAdmin.InsertColumn(1, _T("����"), LVCFMT_CENTER, 60);
	 m_ListAdmin.InsertColumn(2, _T("�۸�"), LVCFMT_CENTER, 60);
	 m_ListAdmin.InsertColumn(3, _T("���"), LVCFMT_CENTER, 60);

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

// CAdminDlg ��Ϣ�������
void CAdminDlg::OnBnClickedButtonAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CAddDlg dlg;
	dlg.DoModal();//��ʾ��Ӵ���

	//��ȡ����ֵ
	CString strSql = dlg.getSQL();

	adminSql(strSql);
	
	update();

}

void CAdminDlg::OnBnClickedButtonEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��ʾ�޸Ĵ���
	CEditDlg dlg;
	dlg.DoModal();

	//���½���ֵ;
	CString strSql = dlg.getSql();
	adminSql(strSql);

	update();
}

void CAdminDlg::OnBnClickedButtonDel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ɾ��������߼�˼��<zd003>
	POSITION pos =m_ListAdmin.GetFirstSelectedItemPosition();
	if (pos == NULL)
		MessageBox(_T("��ѡ����Ҫ��������"));
	else
	{
		 CString strSql;
		 CString strId;
		 int iIndex  = m_ListAdmin.GetNextSelectedItem(pos);  
		 strId = m_ListAdmin.GetItemText(iIndex,0);
		 m_ListAdmin.DeleteItem(iIndex);  
		 MessageBox(_T("ɾ���ɹ�"));
		 strSql.Format(_T("DELETE FROM book WHERE ID = %s"),strId);

		 adminSql(strSql);
	}

	update();
}

void CAdminDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}

void CAdminDlg::OnBnClickedButtonQuery()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
			m_ListAdmin.SetItemState(i,LVIS_DROPHILITED,LVIS_DROPHILITED);//Ϊʲô�������ȡֵ���¼�������ʱ��Ӧ�û�û������<zd009>
			break;
		}
	}
}

//�Զ��庯��update()
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
	//�����ݿ�
	int rc;
	sqlite3 *db;

	rc = sqlite3_open("test3.db",&db);//�����ݿ�

	if(rc)
	{
		MessageBox(_T("���ݿ�򿪴���open"));
	}

	USES_CONVERSION;
	char*strSql=T2A(sql);

	rc = sqlite3_exec(db,strSql,0,0,0);//����SQL���

	if(rc != SQLITE_OK)
	{
		MessageBox(_T("���ݿ�򿪴���exec"));
	}

	sqlite3_close;//�ر����ݿ�
}

