// ZgdaSysView.h : interface of the CZgdaSysView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZGDASYSVIEW_H__4CE1F707_0780_47C3_8705_BF8A0D0795EC__INCLUDED_)
#define AFX_ZGDASYSVIEW_H__4CE1F707_0780_47C3_8705_BF8A0D0795EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CZgdaSysView : public CView
{
protected: // create from serialization only
	CZgdaSysView();
	DECLARE_DYNCREATE(CZgdaSysView)

// Attributes
public:
	CZgdaSysDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZgdaSysView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CZgdaSysView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CZgdaSysView)
	afx_msg void OnZgdaDlg();
	afx_msg void OnChangepassword();
	afx_msg void OnUserdlg();
	afx_msg void OnUsersdlg();
	afx_msg void OnZggzDlg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ZgdaSysView.cpp
inline CZgdaSysDoc* CZgdaSysView::GetDocument()
   { return (CZgdaSysDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZGDASYSVIEW_H__4CE1F707_0780_47C3_8705_BF8A0D0795EC__INCLUDED_)
