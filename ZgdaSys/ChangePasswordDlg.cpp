// ChangePasswordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ZgdaSys.h"
#include "ChangePasswordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChangePasswordDlg dialog


CChangePasswordDlg::CChangePasswordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChangePasswordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChangePasswordDlg)
	m_confirmpassword = _T("");
	m_username = _T("");
	m_newpassword = _T("");
	m_oldpassword = _T("");
	//}}AFX_DATA_INIT
}


void CChangePasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangePasswordDlg)
	DDX_Control(pDX, IDC_OLDPASSWORD, m_verifyold);
	DDX_Control(pDX, IDC_CONFIRMPASSWORD, m_verifyconfirm);
	DDX_Text(pDX, IDC_CONFIRMPASSWORD, m_confirmpassword);
	DDX_Text(pDX, IDC_NAME, m_username);
	DDX_Text(pDX, IDC_NEWPASSWORD, m_newpassword);
	DDX_Text(pDX, IDC_OLDPASSWORD, m_oldpassword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChangePasswordDlg, CDialog)
	//{{AFX_MSG_MAP(CChangePasswordDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangePasswordDlg message handlers

void CChangePasswordDlg::OnOK() 
{
	// TODO: Add extra validation here
	CommonClass con;
	con.OnInitADOConn();
	UpdateData(true);
	if(m_oldpassword!=password)
	{
		MessageBox("旧密码不正确");
		m_oldpassword="";//清空旧密码编辑框
		m_verifyold.SetFocus();//将光标定位于原密码编辑框
		UpdateData(false);	
	}
	else if(m_newpassword!=m_confirmpassword)
	{
		MessageBox("密码不一致，请重输");
		//m_newpassword="";
		m_confirmpassword="";
		m_verifyconfirm.SetFocus();
		UpdateData(false);	
	}
	else//查询满足条件的用户
	{
		CString vSQL="select * from usertable  where username='"+username+"'  and password='"+password+"'";
		con.ExecuteSQL(vSQL);
		//将新密码对话框中输入的数据（m_newpassword的值）写到字段password中
		con.m_pRecordset->PutCollect("password",(_bstr_t)m_newpassword);
		con.m_pRecordset->Update();//将记录集中数据写入到数据源中
		con.ExitConnect();
		CDialog::OnOK();
	}

	CDialog::OnOK();
}

BOOL CChangePasswordDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CZgdaSysApp *app=(CZgdaSysApp*)AfxGetApp();
	m_username=app->USERNAME;//用户名编辑框中的内容为用户登录时的用户名
	username=app->USERNAME;
	password=app->PASSWORD;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
