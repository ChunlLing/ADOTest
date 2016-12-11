// UsersDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ZgdaSys.h"
#include "UsersDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUsersDlg dialog


CUsersDlg::CUsersDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUsersDlg::IDD, pParent)
{
	isadd = false;
	//{{AFX_DATA_INIT(CUsersDlg)
	m_name = _T("");
	m_password = _T("");
	m_type = _T("");
	//}}AFX_DATA_INIT
}


void CUsersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUsersDlg)
	DDX_Control(pDX, IDC_NAME, m_editname);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDX_Text(pDX, IDC_TYPE, m_type);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUsersDlg, CDialog)
	//{{AFX_MSG_MAP(CUsersDlg)
	ON_BN_CLICKED(IDC_RECORD_FIRST, OnRecordFirst)
	ON_BN_CLICKED(IDC_RECORD_PRE, OnRecordPre)
	ON_BN_CLICKED(IDC_RECORD_NEXT, OnRecordNext)
	ON_BN_CLICKED(IDC_RECORD_LAST, OnRecordLast)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_BN_CLICKED(IDC_RECORD_ADD, OnRecordAdd)
	ON_BN_CLICKED(IDC_RECORD_DEL, OnRecordDel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUsersDlg message handlers

BOOL CUsersDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	con.OnInitADOConn();
	m_editname.SetReadOnly(false);
	CString vSQL="select * from usertable";
	con.ExecuteSQL(vSQL);
	con.m_pRecordset->MoveFirst();
	DisplayRecord();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CUsersDlg::OnOK() 
{
	// TODO: Add extra validation here
	con.ExitConnect();
	CDialog::OnOK();

}

void CUsersDlg::OnRecordFirst() 
{
	// TODO: Add your control notification handler code here
	con.m_pRecordset->MoveFirst();
	DisplayRecord();

}

void CUsersDlg::OnRecordPre() 
{
	// TODO: Add your control notification handler code here
	con.m_pRecordset->MovePrevious();
	DisplayRecord();

}

void CUsersDlg::OnRecordNext() 
{
	// TODO: Add your control notification handler code here
	con.m_pRecordset->MoveNext();
	DisplayRecord();

}

void CUsersDlg::OnRecordLast() 
{
	// TODO: Add your control notification handler code here
	con.m_pRecordset->MoveLast();
	DisplayRecord();

}

void CUsersDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_name.IsEmpty())
	{
		AfxMessageBox("�û�������Ϊ��!");
		return;
	}
	if(m_password.IsEmpty())
	{
		AfxMessageBox("���벻��Ϊ��!");
		return;
	}
	if(m_type.IsEmpty())
	{
		AfxMessageBox("�û����Ͳ���Ϊ��!");
		return;
	}
	if(isadd)
{
con.m_pRecordset->AddNew();//���Ӽ�¼���޴�����������Ϊ�޸ļ�¼
isadd=false;
}
m_editname.SetReadOnly(true);//�ָ������༭���ֻ������
	con.m_pRecordset->PutCollect("username",(_bstr_t)m_name);
	con.m_pRecordset->PutCollect("password",(_bstr_t)m_password);
	con.m_pRecordset->PutCollect("usertype",(_bstr_t)m_type);
	con.m_pRecordset->Update();

}

void CUsersDlg::OnRecordAdd() 
{
	// TODO: Add your control notification handler code here
	m_editname.SetReadOnly(false);//���Ӽ�¼ʱȥ��ֻ��
	isadd=true;//isaddΪtrue��ʾ���Ӽ�¼
	m_name="";
	m_password="";
	m_type="";
	UpdateData(false);

}

void CUsersDlg::OnRecordDel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString sql;
	sql.Format("delete from usertable where username='%s'",m_name);
	con.ExecuteSQL(sql);//ִ��SQL����
//���²�ѯ
	con.OnInitADOConn();
	CString vSQL="select * from usertable";
	con.ExecuteSQL(vSQL);
	con.m_pRecordset->MoveFirst();
	DisplayRecord();

}

void CUsersDlg::DisplayRecord()
{

	if(con.m_pRecordset->adoEOF&&con.m_pRecordset->BOF)
	{
		m_name="";
		m_password="";
		m_type="";
	}
	else
	{
		if(con.m_pRecordset->BOF) //�ƶ����˿�ͷ,������ƶ�
		{
			con.m_pRecordset->MoveNext();
		}
		else //����ǰ��
		{
			if(con.m_pRecordset->adoEOF)
			{
				con.m_pRecordset->MoveLast();
			}
		}
	}
	m_name=(LPCTSTR)_bstr_t(con.m_pRecordset->GetCollect("username"));
	m_password=(LPCTSTR)_bstr_t(con.m_pRecordset->GetCollect("password"));
	m_type=(LPCTSTR)_bstr_t(con.m_pRecordset->GetCollect("usertype"));
	UpdateData(false);
	UpdateData(FALSE);  

}
