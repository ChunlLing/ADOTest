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
		MessageBox("�����벻��ȷ");
		m_oldpassword="";//��վ�����༭��
		m_verifyold.SetFocus();//����궨λ��ԭ����༭��
		UpdateData(false);	
	}
	else if(m_newpassword!=m_confirmpassword)
	{
		MessageBox("���벻һ�£�������");
		//m_newpassword="";
		m_confirmpassword="";
		m_verifyconfirm.SetFocus();
		UpdateData(false);	
	}
	else//��ѯ�����������û�
	{
		CString vSQL="select * from usertable  where username='"+username+"'  and password='"+password+"'";
		con.ExecuteSQL(vSQL);
		//��������Ի�������������ݣ�m_newpassword��ֵ��д���ֶ�password��
		con.m_pRecordset->PutCollect("password",(_bstr_t)m_newpassword);
		con.m_pRecordset->Update();//����¼��������д�뵽����Դ��
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
	m_username=app->USERNAME;//�û����༭���е�����Ϊ�û���¼ʱ���û���
	username=app->USERNAME;
	password=app->PASSWORD;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
