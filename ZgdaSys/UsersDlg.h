#if !defined(AFX_USERSDLG_H__BDAF3C38_A124_40CD_A105_ED6ECCAA7FA3__INCLUDED_)
#define AFX_USERSDLG_H__BDAF3C38_A124_40CD_A105_ED6ECCAA7FA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UsersDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUsersDlg dialog

class CUsersDlg : public CDialog
{
// Construction
public:
	boolean isadd;
	void DisplayRecord();

	CommonClass con;
	CUsersDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUsersDlg)
	enum { IDD = IDD_USERS };
	CEdit	m_editname;
	CString	m_name;
	CString	m_password;
	CString	m_type;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUsersDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUsersDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPre();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnSave();
	afx_msg void OnRecordAdd();
	afx_msg void OnRecordDel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERSDLG_H__BDAF3C38_A124_40CD_A105_ED6ECCAA7FA3__INCLUDED_)
