
// book_manmagement_system_v3Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "book_manmagement_system_v3.h"
#include "book_manmagement_system_v3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

//class CAboutDlg : public CDialogEx
//{
//public:
//	CAboutDlg();
//
//// �Ի�������
//	enum { IDD = IDD_ABOUTBOX };
//
//	protected:
//	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
//
//// ʵ��
//protected:
//	DECLARE_MESSAGE_MAP()
//public:
//	afx_msg void OnBnClickedButtonAdd();
//	afx_msg void OnBnClickedCancel();
//};
//
//CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
//{
//}
//
//void CAboutDlg::DoDataExchange(CDataExchange* pDX)
//{
//	CDialogEx::DoDataExchange(pDX);
//}
//
//BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_BN_CLICKED(IDC_BUTTON_ADD, &CAboutDlg::OnBnClickedButtonAdd)
//	ON_BN_CLICKED(IDCANCEL, &CAboutDlg::OnBnClickedCancel)
//END_MESSAGE_MAP()


// Cbook_manmagement_system_v3Dlg �Ի���




Cbook_manmagement_system_v3Dlg::Cbook_manmagement_system_v3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cbook_manmagement_system_v3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cbook_manmagement_system_v3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cbook_manmagement_system_v3Dlg, CDialogEx)
	//ON_BN_CLICKED(IDC_BUTTON_ADD, &Cbook_manmagement_system_v3Dlg::OnBnClickedButtonAdd)
	//ON_BN_CLICKED(IDCANCEL, &Cbook_manmagement_system_v3Dlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// Cbook_manmagement_system_v3Dlg ��Ϣ�������

BOOL Cbook_manmagement_system_v3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cbook_manmagement_system_v3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		//CAboutDlg dlgAbout;
		//dlgAbout.DoModal();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cbook_manmagement_system_v3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cbook_manmagement_system_v3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CEDIT��ȡֵ
	//CEdit* userName;
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
	//
	////ȡ����������
	//CString str2;
	//passWord = (CEdit*)GetDlgItem(IDC_EDIT_USER_NAME); 
	//passWord->GetWindowText(str2);

	// rc = sqlite3_open("password.db", &db);//�����ݿ�

	//if (rc)/*�޷�������ݿ�ֵΪ�յ����*/
	//{
	//	sqlite3_close(db);  //��ʧ�ܣ�
	//	MessageBox(_T("���ݿ��ʧ�ܣ�������ٲ�����"), NULL, MB_ICONSTOP);
	//	return ;
	//}
	//
	//sql = "SELECT * FROM password";//����sql
	//
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
	//}

	//sqlite3_free_table(dbResult); //�ͷ��ڴ�
	//sqlite3_close(db);			 //�ر����ݿ�
