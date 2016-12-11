// ZggzDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ZgdaSys.h"
#include "ZggzDlg.h"
#include "ZggzQueryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZggzDlg dialog


CZggzDlg::CZggzDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZggzDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZggzDlg)
	m_bonus = 0;
	m_name = _T("");
	m_wage = 0.0f;
	m_id = _T("");
	//}}AFX_DATA_INIT
	con.OnInitADOConn();
	CString vSQL="select * from zggz";
	con.ExecuteSQL(vSQL);
	con.m_pRecordset->MoveFirst();
	ChangeControl();
	m_nOperate = 0;

}


void CZggzDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZggzDlg)
	DDX_Text(pDX, IDC_BONUS, m_bonus);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_WAGE, m_wage);
	DDX_Text(pDX, IDC_ID, m_id);
	DDV_MaxChars(pDX, m_id, 7);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CZggzDlg, CDialog)
	//{{AFX_MSG_MAP(CZggzDlg)
	ON_BN_CLICKED(IDC_FIRST, OnFirst)
	ON_BN_CLICKED(IDC_PREV, OnPrev)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_LAST, OnLast)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_MOD, OnMod)
	ON_BN_CLICKED(IDC_RECORD_SAVE, OnRecordSave)
	ON_BN_CLICKED(IDC_RECORD_QUERY, OnRecordQuery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZggzDlg message handlers

void CZggzDlg::ChangeControl()
{

	_variant_t str;
	m_id=(LPCTSTR)_bstr_t(con.m_pRecordset->GetCollect("id"));
	str=con.m_pRecordset->GetCollect("name");
	m_name=str.bstrVal;
	str=con.m_pRecordset->GetCollect("wage");
	m_wage=str.fltVal;
	str=con.m_pRecordset->GetCollect("bonus");
	m_bonus=str.lVal;

}

void CZggzDlg::OnOK() 
{
	// TODO: Add extra validation here
	con.ExitConnect();
	CDialog::OnOK();
}

void CZggzDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	con.ExitConnect();
	CDialog::OnCancel();
}

void CZggzDlg::OnFirst() 
{
	// TODO: Add your control notification handler code here
	con.m_pRecordset->MoveFirst();
	ChangeControl();
	UpdateData(false);

}

void CZggzDlg::OnPrev() 
{
	// TODO: Add your control notification handler code here
	con.m_pRecordset->MovePrevious();
	if(con.m_pRecordset->BOF)
		con.m_pRecordset->MoveFirst();
	ChangeControl();
	UpdateData(false);

}

void CZggzDlg::OnNext() 
{
	// TODO: Add your control notification handler code here
	con.m_pRecordset->MoveNext();
	if(con.m_pRecordset->adoEOF)
		con.m_pRecordset->MoveFirst();
	ChangeControl();
	UpdateData(false);

}

void CZggzDlg::OnLast() 
{
	// TODO: Add your control notification handler code here
	con.m_pRecordset->MoveLast();
	ChangeControl();
	UpdateData(false);

}

void CZggzDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	con.m_pRecordset->MoveLast();
	m_id=(LPCTSTR)_bstr_t(con.m_pRecordset->GetCollect("id"));
	int n=_ttoi(m_id)+1;
	m_id.Format("%d",n);
	m_name="";
	m_wage=0;
	m_bonus=0;
	UpdateData(false);
	m_nOperate=1;

}

void CZggzDlg::OnDel() 
{
	// TODO: Add your control notification handler code here
	if(AfxMessageBox("是否要删除当前记录",1)!=1) return;
	UpdateData(true);
	if(m_id.IsEmpty())
	{
		AfxMessageBox("编号不能为空");
		return;
	}
	CString sql;
	sql.Format("delete from zggz where id='%s'",m_id);//AfxMessageBox(sql);
	con.ExecuteSQL(_bstr_t(sql));
	con.m_pRecordset->Requery(0);
	con.m_pRecordset->MoveFirst();
	ChangeControl();
	UpdateData(false);

}

void CZggzDlg::OnMod() 
{
	// TODO: Add your control notification handler code here
	m_nOperate=2;
	CEdit *pEdit=(CEdit*)GetDlgItem(IDC_ID);
	pEdit->SetReadOnly(true);

}

void CZggzDlg::OnRecordSave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_id.IsEmpty())
	{
		AfxMessageBox("编号不能为空");
		return;
	}
	if(m_name.IsEmpty())
	{
		AfxMessageBox("姓名不能为空");
		return;
	}
	if(m_nOperate==1)
	{
		CString sql;
		sql.Format("Insert into zggz values('%s','%s',%.0f,%d)",m_id,m_name,m_wage,m_bonus);
		con.ExecuteSQL(_bstr_t(sql));
		m_nOperate=0;
		con.m_pRecordset->Requery(0);
	}
	if(m_nOperate==2)
	{
		CEdit *pEdit=(CEdit*)GetDlgItem(IDC_ID);
		pEdit->SetReadOnly(false);
		CString sql;
		sql.Format("Update zggz set name='%s',wage=%.0f,bonus=%d where id='%s'",m_name,m_wage,m_bonus,m_id);
		//AfxMessageBox(sql);
		con.ExecuteSQL(_bstr_t(sql));
		m_nOperate=0;
		con.m_pRecordset->Requery(0);
	}

}

void CZggzDlg::OnRecordQuery() 
{
	// TODO: Add your control notification handler code here
	CZggzQueryDlg dlg;
	dlg.DoModal();

}
