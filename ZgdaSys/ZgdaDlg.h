//{{AFX_INCLUDES()
#include "adodc.h"
#include "datagrid.h"
//}}AFX_INCLUDES
#if !defined(AFX_ZGDADLG_H__45376727_7C40_4AC8_8074_40BE27CA142B__INCLUDED_)
#define AFX_ZGDADLG_H__45376727_7C40_4AC8_8074_40BE27CA142B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ZgdaDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CZgdaDlg dialog

class CZgdaDlg : public CDialog
{
// Construction
public:
	CZgdaDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CZgdaDlg)
	enum { IDD = IDD_DIALOG1 };
	CAdodc	m_adodc;
	int		m_combo1;
	CString	m_combo2;
	CString	m_edit;
	CDataGrid	m_DataGrid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZgdaDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CZgdaDlg)
	afx_msg void OnButton1();
	afx_msg void OnRecordAdd();
	afx_msg void OnButtonCopy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZGDADLG_H__45376727_7C40_4AC8_8074_40BE27CA142B__INCLUDED_)
