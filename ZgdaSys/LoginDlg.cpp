// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ZgdaSys.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	m_name = _T("");
	m_password = _T("");
	//}}AFX_DATA_INIT
	m_n = 0;
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnOK() 
{
	// TODO: Add extra validation here
	m_n=2;//不存在该用户或密码不正确
	CommonClass  con;
	con.OnInitADOConn();
	UpdateData(true);
	//查询用户名与密码均符合的记录
	if(m_name!=""&&m_password!="")//用户名与密码均为非空时进行查询
	{
		CString vSQL="select * from usertable where username='"
			+m_name+"' and password='"+m_password+"'";
		con.ExecuteSQL(vSQL);
		long count=con.m_pRecordset->GetRecordCount();//获得满足条件的记录数
		if(count>=1)//有用户名与密码均符合的记录
		{
			_bstr_t str;
			str= con.m_pRecordset->GetCollect("usertype");//取得用户类型
			m_type.Format("%s",(LPCTSTR)str);//将用户类型转换为CString型
			m_n=1;//用户名与密码均正确
		} 
	}	
	con.ExitConnect();
	CDialog::OnOK();

}

void CLoginDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	m_n = 0;
	CDialog::OnCancel();
}
