// ZgdaSysView.cpp : implementation of the CZgdaSysView class
//

#include "stdafx.h"
#include "ZgdaSys.h"

#include "ZgdaSysDoc.h"
#include "ZgdaSysView.h"

#include "ZgdaDlg.h"
#include "ZggzDlg.h"
#include "ChangePasswordDlg.h"
#include "UserDlg.h"
#include "UsersDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZgdaSysView

IMPLEMENT_DYNCREATE(CZgdaSysView, CView)

BEGIN_MESSAGE_MAP(CZgdaSysView, CView)
	//{{AFX_MSG_MAP(CZgdaSysView)
	ON_COMMAND(ID_ZGDA_DLG, OnZgdaDlg)
	ON_COMMAND(ID_CHANGEPASSWORD, OnChangepassword)
	ON_COMMAND(ID_USERDLG, OnUserdlg)
	ON_COMMAND(ID_USERSDLG, OnUsersdlg)
	ON_COMMAND(ID_ZGGZ_DLG, OnZggzDlg)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZgdaSysView construction/destruction

CZgdaSysView::CZgdaSysView()
{
	// TODO: add construction code here

}

CZgdaSysView::~CZgdaSysView()
{
}

BOOL CZgdaSysView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CZgdaSysView drawing

void CZgdaSysView::OnDraw(CDC* pDC)
{
	CZgdaSysDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CZgdaSysView printing

BOOL CZgdaSysView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CZgdaSysView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CZgdaSysView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CZgdaSysView diagnostics

#ifdef _DEBUG
void CZgdaSysView::AssertValid() const
{
	CView::AssertValid();
}

void CZgdaSysView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZgdaSysDoc* CZgdaSysView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZgdaSysDoc)));
	return (CZgdaSysDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CZgdaSysView message handlers

void CZgdaSysView::OnZgdaDlg() 
{
	// TODO: Add your command handler code here
	CZgdaDlg dlg;
	dlg.DoModal();

}

void CZgdaSysView::OnChangepassword() 
{
	// TODO: Add your command handler code here
	CChangePasswordDlg dlg;	
	CZgdaSysApp *app=(CZgdaSysApp*)AfxGetApp();//定义应用程序在对象
	dlg.m_username=app->USERNAME;//初始化修改密码对话框中的用户名编辑框
	dlg.DoModal();

}

void CZgdaSysView::OnUserdlg() 
{
	// TODO: Add your command handler code here
	CZgdaSysApp *app=(CZgdaSysApp*)AfxGetApp();
	CUserDlg dlg;
	/************************************************/
	if(app->USERTYPE=="1")//用户类型为1时调用对话框
	/************************************************/
		dlg.DoModal();

}

void CZgdaSysView::OnUsersdlg() 
{
	// TODO: Add your command handler code here
	CZgdaSysApp *app=(CZgdaSysApp*)AfxGetApp();
	CUsersDlg dlg;
	/************************************************/
	if(app->USERTYPE=="1")//用户类型为1时调用对话框
	/************************************************/
		dlg.DoModal();

}

void CZgdaSysView::OnZggzDlg() 
{
	// TODO: Add your command handler code here
	CZggzDlg dlg;
	dlg.DoModal();
}
