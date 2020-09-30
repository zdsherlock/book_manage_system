// LogDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "book_manmagement_system_v3.h"
#include "LogDlg.h"
#include "afxdialogex.h"
#include "AdminDlg.h"


// CLogDlg �Ի���

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




// CLogDlg ��Ϣ�������

BEGIN_MESSAGE_MAP(CLogDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN_IN, &CLogDlg::OnBnClickedButtonLoginIn)
	ON_BN_CLICKED(IDCANCEL, &CLogDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


void CLogDlg::OnBnClickedButtonLoginIn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�����������
	CString strName;
	CString strPasswd;

	m_userName.GetWindowText(strName);//����������û���
	m_passWord.GetWindowText(strPasswd);//�������������

	//���ݿ��������
	sqlite3* db;
	int rc;
	char* sql;
	char *errMsg;
	char **dbResult;
	int nRow = 0, nColumn = 0;

	//�����ݿ�
	rc = sqlite3_open("password.db",&db);
	if (rc)//���ݿⲻ����ʱ��ı���
	{
		MessageBox(_T("���ݲ�����"));
	}

	sql = "SELECT * FROM password"; //����SQL���

	sqlite3_get_table(db,sql,&dbResult,&nRow,&nColumn,&errMsg);

	CString Name(dbResult[1*nColumn+1]);	//���ݿ��е��û���
	CString Passwd(dbResult[1*nColumn+2]);	//���ݿ��е�����
	sqlite3_free_table(dbResult);
	//��������Ա����
	if( strName.IsEmpty()||strPasswd.IsEmpty() )
	{	
		MessageBox(_T("�û������벻��Ϊ��"));
	}
	else if( Name != strName || Passwd != strPasswd )
	{
		MessageBox(_T("�û������������"));
	}
	else
	{
		CAdminDlg dlg;
		dlg.DoModal();
	}//�����쳣���������� <zd006>
	CAdminDlg dlg;
	dlg.DoModal();
}


void CLogDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
