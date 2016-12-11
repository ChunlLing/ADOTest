// ZggzQueryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ZgdaSys.h"
#include "ZggzQueryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZggzQueryDlg dialog


CZggzQueryDlg::CZggzQueryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZggzQueryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZggzQueryDlg)
	m_edit = _T("");
	m_combo1 = -1;
	m_combo2 = _T("");
	//}}AFX_DATA_INIT
}


void CZggzQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZggzQueryDlg)
	DDX_Control(pDX, IDC_LIST1, m_ZggzList);
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	DDX_CBIndex(pDX, IDC_COMBO1, m_combo1);
	DDX_CBString(pDX, IDC_COMBO2, m_combo2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CZggzQueryDlg, CDialog)
	//{{AFX_MSG_MAP(CZggzQueryDlg)
	ON_BN_CLICKED(ID_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZggzQueryDlg message handlers

BOOL CZggzQueryDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ZggzList.SetExtendedStyle(m_ZggzList.GetExtendedStyle()|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_ZggzList.InsertColumn(0, _T("编号"), LVCFMT_LEFT, 100);
	m_ZggzList.InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 120);
	m_ZggzList.InsertColumn(2, _T("工资"), LVCFMT_LEFT, 100);
	m_ZggzList.InsertColumn(3, _T("奖金"), LVCFMT_LEFT, 100);

	con.OnInitADOConn();//连接数据库

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CZggzQueryDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str="";
	switch(m_combo1)
	{
	case 0:str="zggz.id='"+m_edit+"'";break;		
	case 1:str="zggz.name='"+m_edit+"'";break;		
	case 2:str="zggz.wage"+m_combo2+m_edit;break;		
	case 3:str="zggz.bonus"+m_combo2+m_edit;break;
	}
	CString vSQL;
	vSQL.Format("select * from zggz where %s",str);
	con.ExecuteSQL(vSQL);
	if(con.m_pRecordset->adoEOF)
	{
		AfxMessageBox("无满足条件的记录");
		return;
	}
	con.m_pRecordset->MoveFirst();
	int nItem=0;
	m_ZggzList.DeleteAllItems();
	while(!con.m_pRecordset->adoEOF)
	{
		nItem = m_ZggzList.GetItemCount();
		m_ZggzList.InsertItem(nItem, (LPCTSTR)_bstr_t(con.m_pRecordset->GetCollect("id")));
		m_ZggzList.SetItemText(nItem, 1, (LPCTSTR)_bstr_t(con.m_pRecordset->GetCollect("name")));
		m_ZggzList.SetItemText(nItem, 2, (LPCTSTR)_bstr_t(con.m_pRecordset->GetCollect("wage")));
		m_ZggzList.SetItemText(nItem, 3, (LPCTSTR)_bstr_t(con.m_pRecordset->GetCollect("bonus")));
		con.m_pRecordset->MoveNext();
	}

}

BOOL CZggzQueryDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	con.ExitConnect();
	return CDialog::DestroyWindow();
}
