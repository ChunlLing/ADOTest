#if !defined(AFX_ZGGZQUERYDLG_H__FC9FFF1A_EA2F_4D9A_8C28_9A8BA30E0E61__INCLUDED_)
#define AFX_ZGGZQUERYDLG_H__FC9FFF1A_EA2F_4D9A_8C28_9A8BA30E0E61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ZggzQueryDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CZggzQueryDlg dialog
#include "ZgdaSys.h"

class CZggzQueryDlg : public CDialog
{
// Construction
public:
	CZggzQueryDlg(CWnd* pParent = NULL);   // standard constructor
	CommonClass  con;

// Dialog Data
	//{{AFX_DATA(CZggzQueryDlg)
	enum { IDD = IDD_DIALOG4 };
	CListCtrl	m_ZggzList;
	CString	m_edit;
	int		m_combo1;
	CString	m_combo2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZggzQueryDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CZggzQueryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZGGZQUERYDLG_H__FC9FFF1A_EA2F_4D9A_8C28_9A8BA30E0E61__INCLUDED_)
