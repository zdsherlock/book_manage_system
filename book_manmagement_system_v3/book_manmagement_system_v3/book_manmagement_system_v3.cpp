
// book_manmagement_system_v3.cpp : 定义应用程序的类行为。
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


// Cbook_manmagement_system_v3App 构造

Cbook_manmagement_system_v3App::Cbook_manmagement_system_v3App()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 Cbook_manmagement_system_v3App 对象

Cbook_manmagement_system_v3App theApp;


// Cbook_manmagement_system_v3App 初始化

BOOL Cbook_manmagement_system_v3App::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CLogDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
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

////取出输入用户名
//CString str1;
//userName = (CEdit*)GetDlgItem(IDC_EDIT_USER_NAME); // 这个是什么语句
//userName->GetWindowText(str1);

////取出输入密码
//CString str2;
//passWord = (CEdit*)GetDlgItem(IDC_EDIT_USER_NAME); 
//passWord->GetWindowText(str2);

//rc = sqlite3_open("password.db", &db);//打开数据库

//if (rc)/*无法检测数据库值为空的情况*/
//{
//	sqlite3_close(db);  //打开失败！
//	MessageBox(_T("数据库打开失败，请检查后再操作！"), NULL, MB_ICONSTOP);
//	return ;
//}

//sql = "SELECT * FROM password";//定义sql

//sqlite3_get_table(db,sql,&dbResult,&nRow,&nColumn,&errMsg);//取出数据库数据；&dbResult二维数组

//CString cstr1(dbResult[1*nColumn]);//转译
//CString cstr2(dbResult[1*nColumn+1]);//为什么这里没有实现取值 <zd002>
////userName->SetWindowText(cstr1);//CString类
////passWord->SetWindowText(cstr2);

//if(str1 != 数据库用户名){
//	MessageBox(_T("用户名错误"), NULL, MB_ICONSTOP);
//}else if(str2 != 数据库密码)
//{
//	MessageBox(_T("用户名错误"), NULL, MB_ICONSTOP);
//}else
//{
//	//关闭当前窗口，弹出管理员界面 <zd001>
//	sqlite3_free_table(dbResult); //释放内存
//	sqlite3_close(db);			 //关闭数据库
//}
