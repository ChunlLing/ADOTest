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
	m_n=2;//�����ڸ��û������벻��ȷ
	CommonClass  con;
	con.OnInitADOConn();
	UpdateData(true);
	//��ѯ�û�������������ϵļ�¼
	if(m_name!=""&&m_password!="")//�û����������Ϊ�ǿ�ʱ���в�ѯ
	{
		CString vSQL="select * from usertable where username='"
			+m_name+"' and password='"+m_password+"'";
		con.ExecuteSQL(vSQL);
		long count=con.m_pRecordset->GetRecordCount();//������������ļ�¼��
		if(count>=1)//���û�������������ϵļ�¼
		{
			_bstr_t str;
			str= con.m_pRecordset->GetCollect("usertype");//ȡ���û�����
			m_type.Format("%s",(LPCTSTR)str);//���û�����ת��ΪCString��
			m_n=1;//�û������������ȷ
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
