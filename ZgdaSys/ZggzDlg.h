#if !defined(AFX_ZGGZDLG_H__BA1B2641_4B09_43F4_9A58_0D1A11096665__INCLUDED_)
#define AFX_ZGGZDLG_H__BA1B2641_4B09_43F4_9A58_0D1A11096665__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ZggzDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CZggzDlg dialog

class CZggzDlg : public CDialog
{
// Construction
public:
	int m_nOperate;
	void ChangeControl();
	CZggzDlg(CWnd* pParent = NULL);   // standard constructor

	CommonClass  con;

// Dialog Data
	//{{AFX_DATA(CZggzDlg)
	enum { IDD = IDD_ZggzDlg };
	long	m_bonus;
	CString	m_name;
	float	m_wage;
	CString	m_id;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZggzDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CZggzDlg)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnFirst();
	afx_msg void OnPrev();
	afx_msg void OnNext();
	afx_msg void OnLast();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnMod();
	afx_msg void OnRecordSave();
	afx_msg void OnRecordQuery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZGGZDLG_H__BA1B2641_4B09_43F4_9A58_0D1A11096665__INCLUDED_)
