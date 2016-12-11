// ZgdaSys.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ZgdaSys.h"

#include "MainFrm.h"
#include "ZgdaSysDoc.h"
#include "ZgdaSysView.h"

#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZgdaSysApp

BEGIN_MESSAGE_MAP(CZgdaSysApp, CWinApp)
	//{{AFX_MSG_MAP(CZgdaSysApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZgdaSysApp construction

CZgdaSysApp::CZgdaSysApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CZgdaSysApp object

CZgdaSysApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CZgdaSysApp initialization

BOOL CZgdaSysApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CZgdaSysDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CZgdaSysView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	::CoInitialize(NULL);

	/************************************************/
	
	//调用用户登录对话框
	CLoginDlg dlg;
	int n;
	for(int i=1;i<=3;i++)//允许输入三次
	{
		dlg.DoModal();
		n=dlg.m_n;
		if(n==1){
			PASSWORD=dlg.m_password;//取得密码
			USERNAME=dlg.m_name;//取得用户名
			USERTYPE=dlg.m_type;//取得用户类型
			break;
		}
		if(n==0)
			exit(0);//单击取消按钮时退出系统
		if(n==2)
		    AfxMessageBox("密码错或该用户不存在，请重新输入");
	}
	if(i>3)
		exit(0);//退出程序
	
	/************************************************/

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CZgdaSysApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CZgdaSysApp message handlers

CommonClass::CommonClass()
{
}
void CommonClass::OnInitADOConn()
{
	try
	{
       m_pConnection.CreateInstance("ADODB.Connection");
	   _bstr_t strConnect="Provider=Microsoft.JET.OLEDB.4.0;Data source=zgda.mdb";
	   m_pConnection->Open(strConnect,"","",adModeUnknown);
//AfxMessageBox("数据库连接成功");
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

BOOL CommonClass::ExecuteSQL(_bstr_t bstrSQL)
{
	try
	{
        if(m_pConnection==NULL)
	     	OnInitADOConn();
        m_pConnection->Execute(bstrSQL,NULL,adCmdText);//执行SQL语句
		return true;
	}
	catch(_com_error e)
	{
		e.Description();
		return false;
	}
}

void CommonClass::ExitConnect()
{
	if(m_pRecordset!=NULL)
		m_pRecordset->Close();//先关闭记录集
	m_pConnection->Close();//关闭连接
}

void CommonClass::ExecuteSQL(CString vSQL)
{
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	m_pConnection->CursorLocation = adUseClient;
	m_pRecordset->Open(vSQL.GetBuffer(0), m_pConnection.GetInterfacePtr(), adOpenDynamic,adLockOptimistic, adCmdText);
}
