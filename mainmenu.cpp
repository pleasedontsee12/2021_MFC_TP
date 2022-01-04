// mainmenu.cpp: 구현 파일
//

#include "pch.h"
#include "login.h"
#include "mainmenu.h"
#include "afxdialogex.h"
#include "table.h"
#include "sales.h"

// mainmenu 대화 상자

IMPLEMENT_DYNAMIC(mainmenu, CDialogEx)

mainmenu::mainmenu(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BB_MENU, pParent)
{

}

mainmenu::~mainmenu()
{
}

void mainmenu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON4, m_danddo2);
	DDX_Control(pDX, IDC_BUTTON6, m_danddo3);
	DDX_Control(pDX, IDC_BUTTON5, m_danddo4);
}


BEGIN_MESSAGE_MAP(mainmenu, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &mainmenu::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &mainmenu::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &mainmenu::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &mainmenu::OnBnClickedButton6)
END_MESSAGE_MAP()


// mainmenu 메시지 처리기


void mainmenu::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	table dlg;
	dlg.DoModal();
}


void mainmenu::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	::PostQuitMessage(WM_QUIT);

}


void mainmenu::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

}


void mainmenu::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

}


void mainmenu::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	sales dlg;
	dlg.DoModal();
}


BOOL mainmenu::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	SetBackgroundColor(RGB(255, 255, 255));
	
	m_danddo2.LoadBitmaps(IDB_danddo2, IDB_danddo2, IDB_danddo2, IDB_danddo2);
	m_danddo2.SizeToContent(); 

	m_danddo3.LoadBitmaps(IDB_danddo3, IDB_danddo3, IDB_danddo3, IDB_danddo3);
	m_danddo3.SizeToContent();

	m_danddo4.LoadBitmaps(IDB_danddo4, IDB_danddo4, IDB_danddo4, IDB_danddo4);
	m_danddo4.SizeToContent();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void mainmenu::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
