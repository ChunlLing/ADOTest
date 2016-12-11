// ZgdaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ZgdaSys.h"
#include "ZgdaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZgdaDlg dialog


CZgdaDlg::CZgdaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZgdaDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZgdaDlg)
	m_combo1 = -1;
	m_combo2 = _T("");
	m_edit = _T("");
	//}}AFX_DATA_INIT
}


void CZgdaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZgdaDlg)
	DDX_Control(pDX, IDC_ADODC1, m_adodc);
	DDX_CBIndex(pDX, IDC_COMBO1, m_combo1);
	DDX_CBString(pDX, IDC_COMBO2, m_combo2);
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_DATAGRID1, m_DataGrid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CZgdaDlg, CDialog)
	//{{AFX_MSG_MAP(CZgdaDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_RECORD_ADD, OnRecordAdd)
	ON_BN_CLICKED(IDC_BUTTON_COPY, OnButtonCopy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZgdaDlg message handlers


void CZgdaDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str="";
	switch(m_combo1)
	{
	case 0:str="zgda.id='"+m_edit+"'";break;		
	case 1:str="zgda.name='"+m_edit+"'";break;		
	case 2:str="zgda.sex='"+m_edit+"'";break;		
	case 3:str="zgda.wage"+m_combo2+m_edit;break;		
	case 4:str="zgda.age"+m_combo2+m_edit;break;
	}
	m_adodc.SetRecordSource("select * from zgda where "+str);
	m_adodc.Refresh();

}

void CZgdaDlg::OnRecordAdd() 
{
	// TODO: Add your control notification handler code here
	//������ӣ������һ�г���һ�ռ�¼�����ڸ��������¼�����뿪ʱ��ӳɹ�
	m_DataGrid.SetAllowAddNew(TRUE);
	m_DataGrid.SetAllowDelete(TRUE);//����ɾ����ѡ��һ�к�delete��ɾ��
	m_adodc.Refresh();

}

void CZgdaDlg::OnButtonCopy() 
{
	// TODO: Add your control notification handler code here
	CommonClass con;
	con.OnInitADOConn();//�������ݿ�	
	m_DataGrid.SetCaption("����zgda��ṹ���±�copyframe");//����DataGrid����
	_bstr_t vSQL;
	vSQL="select * into copyframe from zgda where wage=0";//���ɱ��SQL���
	con.ExecuteSQL(vSQL);//ִ��SQL���
	con.ExitConnect();//�˳�����
	m_adodc.SetRecordSource("select * from copyframe");//���������µ�����Դ
	con.m_pConnection->CursorLocation = adUseClient;//��ʾ���
	m_adodc.Refresh();//ˢ��

}
