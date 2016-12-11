// ZgdaSys.h : main header file for the ZGDASYS application
//

#if !defined(AFX_ZGDASYS_H__B3F5673D_07A4_4373_8DD9_7C4DE6E5E4FC__INCLUDED_)
#define AFX_ZGDASYS_H__B3F5673D_07A4_4373_8DD9_7C4DE6E5E4FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CZgdaSysApp:
// See ZgdaSys.cpp for the implementation of this class
//

class CZgdaSysApp : public CWinApp
{
public:
	CZgdaSysApp();

	CString USERNAME;
	CString PASSWORD;
	CString USERTYPE;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZgdaSysApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CZgdaSysApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
class CommonClass//定义公共类CommonClass
{
public:
	void ExecuteSQL(CString vSQL);
	_ConnectionPtr m_pConnection; //连接对象智能指针
	_RecordsetPtr m_pRecordset; //记录集指针
	void ExitConnect();//退出连接
	BOOL ExecuteSQL(_bstr_t bstrSQL);//用于执行SQL语句
	void OnInitADOConn();//连接数据库
	CommonClass();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZGDASYS_H__B3F5673D_07A4_4373_8DD9_7C4DE6E5E4FC__INCLUDED_)
