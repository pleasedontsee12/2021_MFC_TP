// table.cpp: 구현 파일
//

#include "pch.h"
#include "login.h"
#include "table.h"
#include "afxdialogex.h"
#include "menu.h"
#include "pickpay.h"
#include "cardpay.h"

// table 대화 상자

IMPLEMENT_DYNAMIC(table, CDialogEx)

table::table(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_C_TABLE, pParent)
{

}

table::~table()
{
}

void table::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON14, m_table1);
	DDX_Control(pDX, IDC_BUTTON16, m_table2);
	DDX_Control(pDX, IDC_BUTTON13, m_table3);
	DDX_Control(pDX, IDC_BUTTON10, m_table4);
	DDX_Control(pDX, IDC_BUTTON11, m_table5);
	DDX_Control(pDX, IDC_BUTTON15, m_table6);
	DDX_Control(pDX, IDC_PAYMENT, m_table1pay);
	DDX_Control(pDX, IDC_PAYMENT2, m_table2pay);
	DDX_Control(pDX, IDC_PAYMENT3, m_table3pay);
	DDX_Control(pDX, IDC_PAYMENT4, m_table4pay);
	DDX_Control(pDX, IDC_PAYMENT5, m_table5pay);
	DDX_Control(pDX, IDC_PAYMENT6, m_table6pay);
	DDX_Control(pDX, IDC_BUTTON5, m_danddobtn);
	DDX_Control(pDX, IDC_BUTTON6, m_danddobtn2);
}


BEGIN_MESSAGE_MAP(table, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON14, &table::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_PAYMENT, &table::OnBnClickedPayment)
	ON_BN_CLICKED(IDC_BUTTON16, &table::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_PAYMENT2, &table::OnBnClickedPayment2)
	ON_BN_CLICKED(IDC_BUTTON13, &table::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_PAYMENT3, &table::OnBnClickedPayment3)
	ON_BN_CLICKED(IDC_BUTTON10, &table::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_PAYMENT4, &table::OnBnClickedPayment4)
	ON_BN_CLICKED(IDC_BUTTON11, &table::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_PAYMENT5, &table::OnBnClickedPayment5)
	ON_BN_CLICKED(IDC_BUTTON15, &table::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_PAYMENT6, &table::OnBnClickedPayment6)
END_MESSAGE_MAP()


// table 메시지 처리기


void table::OnBnClickedButton14()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	tablenum = 1;
	menu dlg;
	dlg.DoModal();
}


void table::OnBnClickedPayment()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	tablenum = 1;
	pickpay dlg;
	dlg.DoModal();

}


void table::OnBnClickedButton16()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	tablenum = 2;
	menu dlg;
	dlg.DoModal();
}


void table::OnBnClickedPayment2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	tablenum = 2;
	pickpay dlg;
	dlg.DoModal();

}


void table::OnBnClickedButton13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	tablenum = 3;
	menu dlg;
	dlg.DoModal();
}


void table::OnBnClickedPayment3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	tablenum = 3;
	pickpay dlg;
	dlg.DoModal();

}


void table::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	tablenum = 4;
	menu dlg;
	dlg.DoModal();
}


void table::OnBnClickedPayment4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	tablenum = 4;
	pickpay dlg;
	dlg.DoModal();
}


void table::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	tablenum = 5;
	menu dlg;
	dlg.DoModal();
}


void table::OnBnClickedPayment5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	tablenum = 5;
	pickpay dlg;
	dlg.DoModal();
}


void table::OnBnClickedButton15()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	tablenum = 6;
	menu dlg;
	dlg.DoModal();
}


void table::OnBnClickedPayment6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	tablenum = 6;
	pickpay dlg;
	dlg.DoModal();
}


BOOL table::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetBackgroundColor(RGB(255, 255, 255));

	
	m_table1.EnableWindowsTheming(FALSE);
	m_table1.SetFaceColor(RGB(255,255,255), true);

	m_table1pay.LoadBitmaps(IDB_ORDER, IDB_ORDER, IDB_ORDER, IDB_ORDER);
	m_table1pay.SizeToContent();

	m_table2pay.LoadBitmaps(IDB_ORDER, IDB_ORDER, IDB_ORDER, IDB_ORDER);
	m_table2pay.SizeToContent();

	m_table3pay.LoadBitmaps(IDB_ORDER, IDB_ORDER, IDB_ORDER, IDB_ORDER);
	m_table3pay.SizeToContent();

	m_table4pay.LoadBitmaps(IDB_ORDER, IDB_ORDER, IDB_ORDER, IDB_ORDER);
	m_table4pay.SizeToContent();

	m_table5pay.LoadBitmaps(IDB_ORDER, IDB_ORDER, IDB_ORDER, IDB_ORDER);
	m_table5pay.SizeToContent();

	m_table6pay.LoadBitmaps(IDB_ORDER, IDB_ORDER, IDB_ORDER, IDB_ORDER);
	m_table6pay.SizeToContent();

	m_table2.EnableWindowsTheming(FALSE);
	m_table2.SetFaceColor(RGB(255, 255, 255), true);

	m_table3.EnableWindowsTheming(FALSE);
	m_table3.SetFaceColor(RGB(255, 255, 255), true);

	m_table4.EnableWindowsTheming(FALSE);
	m_table4.SetFaceColor(RGB(255, 255, 255), true);

	m_table5.EnableWindowsTheming(FALSE);
	m_table5.SetFaceColor(RGB(255, 255, 255), true);

	m_table6.EnableWindowsTheming(FALSE);
	m_table6.SetFaceColor(RGB(255, 255, 255), true);

	m_danddobtn.LoadBitmaps(IDB_danddo5, IDB_danddo5, IDB_danddo5, IDB_danddo5);
	m_danddobtn.SizeToContent();

	m_danddobtn2.LoadBitmaps(IDB_danddo6, IDB_danddo6, IDB_danddo6, IDB_danddo6);
	m_danddobtn2.SizeToContent();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
