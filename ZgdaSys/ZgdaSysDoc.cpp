// ZgdaSysDoc.cpp : implementation of the CZgdaSysDoc class
//

#include "stdafx.h"
#include "ZgdaSys.h"

#include "ZgdaSysDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZgdaSysDoc

IMPLEMENT_DYNCREATE(CZgdaSysDoc, CDocument)

BEGIN_MESSAGE_MAP(CZgdaSysDoc, CDocument)
	//{{AFX_MSG_MAP(CZgdaSysDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZgdaSysDoc construction/destruction

CZgdaSysDoc::CZgdaSysDoc()
{
	// TODO: add one-time construction code here

}

CZgdaSysDoc::~CZgdaSysDoc()
{
}

BOOL CZgdaSysDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CZgdaSysDoc serialization

void CZgdaSysDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CZgdaSysDoc diagnostics

#ifdef _DEBUG
void CZgdaSysDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CZgdaSysDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CZgdaSysDoc commands
