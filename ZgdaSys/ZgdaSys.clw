; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CZggzQueryDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ZgdaSys.h"
LastPage=0

ClassCount=12
Class1=CZgdaSysApp
Class2=CZgdaSysDoc
Class3=CZgdaSysView
Class4=CMainFrame

ResourceCount=9
Resource1=IDD_USERS
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CZgdaDlg
Resource3=IDD_USER
Class7=CLoginDlg
Resource4=IDD_ZggzDlg
Class8=CChangePasswordDlg
Resource5=IDR_MAINFRAME
Class9=CUserDlg
Resource6=IDD_CHANGE_PASSWORD
Class10=CUsersDlg
Resource7=IDD_DIALOG2
Class11=CZggzDlg
Resource8=IDD_DIALOG1
Class12=CZggzQueryDlg
Resource9=IDD_DIALOG4

[CLS:CZgdaSysApp]
Type=0
HeaderFile=ZgdaSys.h
ImplementationFile=ZgdaSys.cpp
Filter=N
LastObject=CZgdaSysApp

[CLS:CZgdaSysDoc]
Type=0
HeaderFile=ZgdaSysDoc.h
ImplementationFile=ZgdaSysDoc.cpp
Filter=N

[CLS:CZgdaSysView]
Type=0
HeaderFile=ZgdaSysView.h
ImplementationFile=ZgdaSysView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CZgdaSysView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=ZgdaSys.cpp
ImplementationFile=ZgdaSys.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_ZGDA_DLG
Command18=ID_ZGGZ_DLG
Command19=ID_CHANGEPASSWORD
Command20=ID_USERDLG
Command21=ID_USERSDLG
CommandCount=21

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_DIALOG1]
Type=1
Class=CZgdaDlg
ControlCount=13
Control1=IDOK,button,1342242817
Control2=IDC_ADODC1,{67397AA3-7FB1-11D0-B148-00A0C922E820},1342177280
Control3=IDC_DATAGRID1,{CDE57A43-8B86-11D0-B3C6-00A0C90AEA82},1342242816
Control4=IDC_COMBO1,combobox,1344339971
Control5=IDC_COMBO2,combobox,1344339971
Control6=IDC_EDIT1,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_BUTTON1,button,1342242816
Control11=IDC_RECORD_ADD,button,1342242816
Control12=IDC_BUTTON_COPY,button,1342242816
Control13=IDC_SPIN1,msctls_updown32,1342177312

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[CLS:CZgdaDlg]
Type=0
HeaderFile=ZgdaDlg.h
ImplementationFile=ZgdaDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CZgdaDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG2]
Type=1
Class=CLoginDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_NAME,edit,1350631552
Control6=IDC_PASSWORD,edit,1350631584

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLoginDlg
VirtualFilter=dWC

[DLG:IDD_CHANGE_PASSWORD]
Type=1
Class=CChangePasswordDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_NAME,edit,1350633600
Control8=IDC_OLDPASSWORD,edit,1350631584
Control9=IDC_NEWPASSWORD,edit,1350631584
Control10=IDC_CONFIRMPASSWORD,edit,1350631584

[CLS:CChangePasswordDlg]
Type=0
HeaderFile=ChangePasswordDlg.h
ImplementationFile=ChangePasswordDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CChangePasswordDlg

[DLG:IDD_USER]
Type=1
Class=CUserDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_DATAGRID1,{CDE57A43-8B86-11D0-B3C6-00A0C90AEA82},1342242816
Control4=IDC_ADODC1,{67397AA3-7FB1-11D0-B148-00A0C922E820},1342177280

[CLS:CUserDlg]
Type=0
HeaderFile=UserDlg.h
ImplementationFile=UserDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CUserDlg

[CLS:CUsersDlg]
Type=0
HeaderFile=UsersDlg.h
ImplementationFile=UsersDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CUsersDlg

[DLG:IDD_USERS]
Type=1
Class=CUsersDlg
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_NAME,edit,1350631552
Control6=IDC_PASSWORD,edit,1350631552
Control7=IDC_TYPE,edit,1350631552
Control8=IDC_RECORD_FIRST,button,1342242816
Control9=IDC_RECORD_PRE,button,1342242816
Control10=IDC_RECORD_NEXT,button,1342242816
Control11=IDC_RECORD_LAST,button,1342242816
Control12=IDC_SAVE,button,1342242816
Control13=IDC_RECORD_ADD,button,1342242816
Control14=IDC_RECORD_DEL,button,1342242816

[CLS:CZggzDlg]
Type=0
HeaderFile=ZggzDlg.h
ImplementationFile=ZggzDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CZggzDlg

[DLG:IDD_ZggzDlg]
Type=1
Class=CZggzDlg
ControlCount=18
Control1=IDC_RECORD_QUERY,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_FIRST,button,1342242816
Control8=IDC_PREV,button,1342242816
Control9=IDC_NEXT,button,1342242816
Control10=IDC_LAST,button,1342242816
Control11=IDC_ID,edit,1350631552
Control12=IDC_NAME,edit,1350631552
Control13=IDC_WAGE,edit,1350631552
Control14=IDC_BONUS,edit,1350631552
Control15=IDC_ADD,button,1342242816
Control16=IDC_DEL,button,1342242816
Control17=IDC_MOD,button,1342242816
Control18=IDC_RECORD_SAVE,button,1342242816

[DLG:IDD_DIALOG4]
Type=1
Class=CZggzQueryDlg
ControlCount=9
Control1=IDCANCEL,button,1342242816
Control2=IDC_LIST1,SysListView32,1350631425
Control3=IDC_COMBO1,combobox,1344339971
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=ID_BUTTON1,button,1342242816
Control9=IDC_COMBO2,combobox,1344339970

[CLS:CZggzQueryDlg]
Type=0
HeaderFile=ZggzQueryDlg.h
ImplementationFile=ZggzQueryDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CZggzQueryDlg

