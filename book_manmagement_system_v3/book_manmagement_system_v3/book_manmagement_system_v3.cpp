
// book_manmagement_system_v3.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "book_manmagement_system_v3.h"
#include "LogDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cbook_manmagement_system_v3App

BEGIN_MESSAGE_MAP(Cbook_manmagement_system_v3App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Cbook_manmagement_system_v3App ����

Cbook_manmagement_system_v3App::Cbook_manmagement_system_v3App()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� Cbook_manmagement_system_v3App ����

Cbook_manmagement_system_v3App theApp;


// Cbook_manmagement_system_v3App ��ʼ��

BOOL Cbook_manmagement_system_v3App::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CLogDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

//CDialog::OnOk()
//	CEdit* userName;
//CEdit* passWord;
//sqlite3* db;
//char* sql;
//char *errMsg;
//char **dbResult;
//int nRow = 0, nColumn = 0;
//int rc;

////ȡ�������û���
//CString str1;
//userName = (CEdit*)GetDlgItem(IDC_EDIT_USER_NAME); // �����ʲô���
//userName->GetWindowText(str1);

////ȡ����������
//CString str2;
//passWord = (CEdit*)GetDlgItem(IDC_EDIT_USER_NAME); 
//passWord->GetWindowText(str2);

//rc = sqlite3_open("password.db", &db);//�����ݿ�

//if (rc)/*�޷�������ݿ�ֵΪ�յ����*/
//{
//	sqlite3_close(db);  //��ʧ�ܣ�
//	MessageBox(_T("���ݿ��ʧ�ܣ�������ٲ�����"), NULL, MB_ICONSTOP);
//	return ;
//}

//sql = "SELECT * FROM password";//����sql

//sqlite3_get_table(db,sql,&dbResult,&nRow,&nColumn,&errMsg);//ȡ�����ݿ����ݣ�&dbResult��ά����

//CString cstr1(dbResult[1*nColumn]);//ת��
//CString cstr2(dbResult[1*nColumn+1]);//Ϊʲô����û��ʵ��ȡֵ <zd002>
////userName->SetWindowText(cstr1);//CString��
////passWord->SetWindowText(cstr2);

//if(str1 != ���ݿ��û���){
//	MessageBox(_T("�û�������"), NULL, MB_ICONSTOP);
//}else if(str2 != ���ݿ�����)
//{
//	MessageBox(_T("�û�������"), NULL, MB_ICONSTOP);
//}else
//{
//	//�رյ�ǰ���ڣ���������Ա���� <zd001>
//	sqlite3_free_table(dbResult); //�ͷ��ڴ�
//	sqlite3_close(db);			 //�ر����ݿ�
//}
