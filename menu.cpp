// menu.cpp: 구현 파일
//

#include "pch.h"
#include "login.h"
#include "menu.h"
#include "afxdialogex.h"
#include "table.h"
#include "cardpay.h"
#include "pickpay.h"

#include "mysql.h"
#include <Winsock2.h>

#pragma comment(lib, "libmysql.lib")
#pragma comment(lib, "ws2_32.lib")

#define DB_ADDRESS "34.64.209.235"
#define DB_ID "root"
#define DB_PASS "1317"
#define DB_NAME "teamproject"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// menu 대화 상자

IMPLEMENT_DYNAMIC(menu, CDialogEx)

menu::menu(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_D_MENU, pParent)
{

}

menu::~menu()
{
}

void menu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_orderlist);
	DDX_Control(pDX, IDC_EDIT2, m_totalprice);
	DDX_Control(pDX, IDC_BUTTON1, m_menu01);
	DDX_Control(pDX, IDC_BUTTON2, m_menu02);
	DDX_Control(pDX, 1016, m_menu03);
	DDX_Control(pDX, IDC_BUTTON8, m_menu04);
	DDX_Control(pDX, IDC_BUTTON16, m_menu05);
	DDX_Control(pDX, 1014, m_menu06);
	DDX_Control(pDX, IDC_BUTTON9, m_menu07);
	DDX_Control(pDX, 1017, m_menu08);
	DDX_Control(pDX, 1012, m_menu09);
	DDX_Control(pDX, 1013, m_menu10);
}


BEGIN_MESSAGE_MAP(menu, CDialogEx)
	ON_BN_CLICKED(IDC_ORDERCHECK, &menu::OnBnClickedOrdercheck)
	ON_BN_CLICKED(IDC_BUTTON1, &menu::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON18, &menu::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON2, &menu::OnBnClickedButton2)
	ON_BN_CLICKED(1016, &menu::OnBnClicked1016)
	ON_BN_CLICKED(IDC_BUTTON8, &menu::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON16, &menu::OnBnClickedButton16)
	ON_BN_CLICKED(1014, &menu::OnBnClicked1014)
	ON_BN_CLICKED(IDC_BUTTON9, &menu::OnBnClickedButton9)
	ON_BN_CLICKED(1017, &menu::OnBnClicked1017)
	ON_BN_CLICKED(1012, &menu::OnBnClicked1012)
	ON_BN_CLICKED(1013, &menu::OnBnClicked1013)
//	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST3, &menu::OnLvnItemchangedList3)
END_MESSAGE_MAP()


// menu 메시지 처리기


BOOL menu::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	CRect rt; // 리스트 컨트롤의 크기를 가져올 변수
	SetWindowText(_T("식당 테이블 매출 관리 프로그램"));

	SetBackgroundColor(RGB(255, 255, 255));

	m_orderlist.GetWindowRect(&rt);

	m_orderlist.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT); // 리스트 컨트롤에 선표시 및 Item 선택시 한행 전체 선택

	m_orderlist.InsertColumn(0, TEXT("메뉴 이름"), LVCFMT_CENTER, rt.Width() * 0.4); // 첫번째

	m_orderlist.InsertColumn(1, TEXT("수량"), LVCFMT_CENTER, rt.Width() * 0.3); // 두번째

	m_orderlist.InsertColumn(2, TEXT("가격"), LVCFMT_CENTER, rt.Width() * 0.3); // 세번째

	m_totalprice.SetWindowText(_T("0"));
	m_orderlist.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	CFont font;
	font.CreatePointFont(200, _T("바탕"));
	// m_yearAndMonth.SetFont(&font);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void menu::OnBnClickedOrdercheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//pickpay* ppy = (pickpay*)GetParent();
	pickpay* ppy = (pickpay*)AfxGetMainWnd();
	table* tablecaption = (table*)GetParent();
	CString tablenum;
	int itemCnt = m_orderlist.GetItemCount();    //행의 수를 얻어옴
	m_StringtotalPrice.Format(_T("%d"), m_UtotalPrice);
	tablemenu = tablemenu1 + tablemenu2 + tablemenu3 + tablemenu4 + tablemenu5 + tablemenu6 + tablemenu7 + tablemenu8 + tablemenu9 + tablemenu10;


	if (itemCnt == 0) {
		tablecaption->m_table1pay.EnableWindow(FALSE);
	}

	else {
		switch (tablecaption->tablenum) {
		case 1: {
			for (int i = 0; i < m_orderlist.GetItemCount(); i++) {
				

				menudialogmenu[1][i] = m_orderlist.GetItemText(i, 0);
				menudialogquantity[1][i] = m_orderlist.GetItemText(i, 1);
				menudialogprice[1][i] = m_orderlist.GetItemText(i, 2);

				table* tbl = (table*)GetParent();
				tbl->mtest[1][i] = menudialogmenu[1][i];
				tbl->qtest[1][i] = menudialogquantity[1][i];
				tbl->ptest[1][i] = menudialogprice[1][i];

			}
			  tablecaption->m_table1.GetWindowText(tablenum);
			  tablecaption->m_table1.SetWindowText(tablenum + _T("\n")  + tablemenu + _T("\n") + _T("\n") + m_StringtotalPrice + _T("원"));
			  tablecaption->m_table1pay.EnableWindow(TRUE);
			  tablecaption->m_table1.EnableWindow(FALSE);
			  OnOK();
			  break;
		}

		case 2: {
			for (int i = 0; i < m_orderlist.GetItemCount(); i++) {
			
				menudialogmenu[2][i] = m_orderlist.GetItemText(i, 0);
				menudialogquantity[2][i] = m_orderlist.GetItemText(i, 1);
				menudialogprice[2][i] = m_orderlist.GetItemText(i, 2);

				table* tbl = (table*)GetParent();
				tbl->mtest[2][i] = menudialogmenu[2][i];
				tbl->qtest[2][i] = menudialogquantity[2][i];
				tbl->ptest[2][i] = menudialogprice[2][i];

			}
			tablecaption->m_table2.GetWindowText(tablenum);
			tablecaption->m_table2.SetWindowText(tablenum + _T("\n") + tablemenu + _T("\n") + _T("\n") + m_StringtotalPrice + _T("원"));
			tablecaption->m_table2pay.EnableWindow(TRUE);
			tablecaption->m_table2.EnableWindow(FALSE);
			OnOK();
			break;
		}

		case 3: {
			for (int i = 0; i < m_orderlist.GetItemCount(); i++) {

				menudialogmenu[3][i] = m_orderlist.GetItemText(i, 0);
				menudialogquantity[3][i] = m_orderlist.GetItemText(i, 1);
				menudialogprice[3][i] = m_orderlist.GetItemText(i, 2);

				table* tbl = (table*)GetParent();
				tbl->mtest[3][i] = menudialogmenu[3][i];
				tbl->qtest[3][i] = menudialogquantity[3][i];
				tbl->ptest[3][i] = menudialogprice[3][i];

			}
			tablecaption->m_table3.GetWindowText(tablenum);
			tablecaption->m_table3.SetWindowText(tablenum + _T("\n")+ tablemenu + _T("\n") + _T("\n") + m_StringtotalPrice + _T("원"));
			tablecaption->m_table3pay.EnableWindow(TRUE);
			tablecaption->m_table3.EnableWindow(FALSE);
			OnOK();
			break;
		}
		case 4: {
			for (int i = 0; i < m_orderlist.GetItemCount(); i++) {

				menudialogmenu[4][i] = m_orderlist.GetItemText(i, 0);
				menudialogquantity[4][i] = m_orderlist.GetItemText(i, 1);
				menudialogprice[4][i] = m_orderlist.GetItemText(i, 2);

				table* tbl = (table*)GetParent();
				tbl->mtest[4][i] = menudialogmenu[4][i];
				tbl->qtest[4][i] = menudialogquantity[4][i];
				tbl->ptest[4][i] = menudialogprice[4][i];

			}
			
			tablecaption->m_table4.GetWindowText(tablenum);
			tablecaption->m_table4.SetWindowText(tablenum + _T("\n")+ tablemenu + _T("\n") + _T("\n") + m_StringtotalPrice + _T("원"));
			tablecaption->m_table4pay.EnableWindow(TRUE);
			tablecaption->m_table4.EnableWindow(FALSE);
			OnOK();
			break;
		}
		case 5: {
			for (int i = 0; i < m_orderlist.GetItemCount(); i++) {

				menudialogmenu[5][i] = m_orderlist.GetItemText(i, 0);
				menudialogquantity[5][i] = m_orderlist.GetItemText(i, 1);
				menudialogprice[5][i] = m_orderlist.GetItemText(i, 2);

				table* tbl = (table*)GetParent();
				tbl->mtest[5][i] = menudialogmenu[5][i];
				tbl->qtest[5][i] = menudialogquantity[5][i];
				tbl->ptest[5][i] = menudialogprice[5][i];

			}
			tablecaption->m_table5.GetWindowText(tablenum);
			tablecaption->m_table5.SetWindowText(tablenum + _T("\n") + tablemenu + _T("\n") + _T("\n") + m_StringtotalPrice + _T("원"));
			tablecaption->m_table5pay.EnableWindow(TRUE);
			tablecaption->m_table5.EnableWindow(FALSE);
			OnOK();
			break;
		}
		case 6: {
			for (int i = 0; i < m_orderlist.GetItemCount(); i++) {

				menudialogmenu[6][i] = m_orderlist.GetItemText(i, 0);
				menudialogquantity[6][i] = m_orderlist.GetItemText(i, 1);
				menudialogprice[6][i] = m_orderlist.GetItemText(i, 2);

				table* tbl = (table*)GetParent();
				tbl->mtest[6][i] = menudialogmenu[6][i];
				tbl->qtest[6][i] = menudialogquantity[6][i];
				tbl->ptest[6][i] = menudialogprice[6][i];

			}

			tablecaption->m_table6.GetWindowText(tablenum);
			tablecaption->m_table6.SetWindowText(tablenum + _T("\n") + tablemenu + _T("\n") + _T("\n") + m_StringtotalPrice + _T("원"));
			tablecaption->m_table6pay.EnableWindow(TRUE);
			tablecaption->m_table6.EnableWindow(FALSE);
			OnOK();
			break;
		}
		}
	}
}

void menu::OnBnClickedButton18()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	tablemenu1 = _T("");
	tablemenu2 = _T("");
	tablemenu3 = _T("");
	tablemenu4 = _T("");
	tablemenu5 = _T("");
	tablemenu6 = _T("");
	tablemenu7 = _T("");
	tablemenu8 = _T("");
	tablemenu9 = _T("");
	tablemenu10 = _T("");
	m_orderlist.DeleteAllItems();
	m_totalprice.SetWindowText(_T("0"));
	m_UtotalPrice = 0;
}

void menu::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	table* tablenum = (table*)GetParent();

	int count = 0;
	CString str;
	CString dishname;
	CString price;       //가격
	CString quantity;    //수량
	m_menu01.GetWindowText(str);

	AfxExtractSubString(dishname, str, 0, ' ');
	AfxExtractSubString(price, str, 1, ' ');
	price = price.Left(price.GetLength());
	int itemCnt = m_orderlist.GetItemCount();    //행의 수를 얻어옴
	int i;

	for (i = 0; i < itemCnt; i++) {
		if (m_orderlist.GetItemText(i, 0) == dishname) {
			m_bExistDish = TRUE;
			break;
		}
	}

	if (m_bExistDish) {
		int getQuantity = _ttoi(m_orderlist.GetItemText(i, 1));
		int getPrice = _ttoi(m_orderlist.GetItemText(i, 2));

		getQuantity += 1;
		getPrice += _ttoi(price);


		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);

		price.Format(_T("%d"), getPrice);
		quantity.Format(_T("%d"), getQuantity);
		m_orderlist.SetItemText(i, 1, quantity);
		m_orderlist.SetItemText(i, 2, price);
		dishname = _T("\n") + dishname;
		tablemenu1 = dishname + quantity;
		m_bExistDish = FALSE;               //이부분은 FALSE로 안하면 문제가 생기므로 초기화
	}

	else {    //만약 FALSE라면 1번만 실행
		m_orderlist.InsertItem(count, dishname);
		m_orderlist.SetItemText(count, 1, _T("1"));
		m_orderlist.SetItemText(count, 2, price);
		count++;

		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);
		dishname = _T("\n") + dishname;
		tablemenu1 = dishname + quantity;
	}

	
}



void menu::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	table* tablenum = (table*)GetParent();

	int count = 0;
	CString str;
	CString dishname;
	CString price;       //가격
	CString quantity;    //수량
	m_menu02.GetWindowText(str);

	AfxExtractSubString(dishname, str, 0, ' ');
	AfxExtractSubString(price, str, 1, ' ');
	price = price.Left(price.GetLength());
	int itemCnt = m_orderlist.GetItemCount();    //행의 수를 얻어옴
	int i;

	for (i = 0; i < itemCnt; i++) {
		if (m_orderlist.GetItemText(i, 0) == dishname) {
			m_bExistDish = TRUE;
			break;
		}
	}

	if (m_bExistDish) {
		int getQuantity = _ttoi(m_orderlist.GetItemText(i, 1));
		int getPrice = _ttoi(m_orderlist.GetItemText(i, 2));

		getQuantity += 1;
		getPrice += _ttoi(price);


		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);

		price.Format(_T("%d"), getPrice);
		quantity.Format(_T("%d"), getQuantity);
		m_orderlist.SetItemText(i, 1, quantity);
		m_orderlist.SetItemText(i, 2, price);
		dishname = _T("\n") + dishname;
		tablemenu2 = dishname + quantity;
		m_bExistDish = FALSE;               //이부분은 FALSE로 안하면 문제가 생기므로 초기화
	}

	else {    //만약 FALSE라면 1번만 실행
		m_orderlist.InsertItem(count, dishname);
		m_orderlist.SetItemText(count, 1, _T("1"));
		m_orderlist.SetItemText(count, 2, price);
		count++;

		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);
		dishname = _T("\n") + dishname;
		tablemenu2 = dishname + quantity;
	}


}


void menu::OnBnClicked1016()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	table* tablenum = (table*)GetParent();

	int count = 0;
	CString str;
	CString dishname;
	CString price;       //가격
	CString quantity;    //수량
	m_menu03.GetWindowText(str);

	AfxExtractSubString(dishname, str, 0, ' ');
	AfxExtractSubString(price, str, 1, ' ');
	price = price.Left(price.GetLength());
	int itemCnt = m_orderlist.GetItemCount();    //행의 수를 얻어옴
	int i;

	for (i = 0; i < itemCnt; i++) {
		if (m_orderlist.GetItemText(i, 0) == dishname) {
			m_bExistDish = TRUE;
			break;
		}
	}

	if (m_bExistDish) {
		int getQuantity = _ttoi(m_orderlist.GetItemText(i, 1));
		int getPrice = _ttoi(m_orderlist.GetItemText(i, 2));

		getQuantity += 1;
		getPrice += _ttoi(price);


		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);

		price.Format(_T("%d"), getPrice);
		quantity.Format(_T("%d"), getQuantity);
		m_orderlist.SetItemText(i, 1, quantity);
		m_orderlist.SetItemText(i, 2, price);
		dishname = _T("\n") + dishname;
		tablemenu3 = dishname + quantity;
		m_bExistDish = FALSE;               //이부분은 FALSE로 안하면 문제가 생기므로 초기화
	}

	else {    //만약 FALSE라면 1번만 실행
		m_orderlist.InsertItem(count, dishname);
		m_orderlist.SetItemText(count, 1, _T("1"));
		m_orderlist.SetItemText(count, 2, price);
		count++;

		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);
		dishname = _T("\n") + dishname;
		tablemenu3 = dishname + quantity;
	}


}


void menu::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	table* tablenum = (table*)GetParent();

	int count = 0;
	CString str;
	CString dishname;
	CString price;       //가격
	CString quantity;    //수량
	m_menu04.GetWindowText(str);

	AfxExtractSubString(dishname, str, 0, ' ');
	AfxExtractSubString(price, str, 1, ' ');
	price = price.Left(price.GetLength());
	int itemCnt = m_orderlist.GetItemCount();    //행의 수를 얻어옴
	int i;

	for (i = 0; i < itemCnt; i++) {
		if (m_orderlist.GetItemText(i, 0) == dishname) {
			m_bExistDish = TRUE;
			break;
		}
	}

	if (m_bExistDish) {
		int getQuantity = _ttoi(m_orderlist.GetItemText(i, 1));
		int getPrice = _ttoi(m_orderlist.GetItemText(i, 2));

		getQuantity += 1;
		getPrice += _ttoi(price);


		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);

		price.Format(_T("%d"), getPrice);
		quantity.Format(_T("%d"), getQuantity);
		m_orderlist.SetItemText(i, 1, quantity);
		m_orderlist.SetItemText(i, 2, price);
		dishname = _T("\n") + dishname;
		tablemenu4 = dishname + quantity;
		m_bExistDish = FALSE;               //이부분은 FALSE로 안하면 문제가 생기므로 초기화
	}

	else {    //만약 FALSE라면 1번만 실행
		m_orderlist.InsertItem(count, dishname);
		m_orderlist.SetItemText(count, 1, _T("1"));
		m_orderlist.SetItemText(count, 2, price);
		count++;

		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);
		dishname = _T("\n") + dishname;
		tablemenu4 = dishname + quantity;
	}


}


void menu::OnBnClickedButton16()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	table* tablenum = (table*)GetParent();

	int count = 0;
	CString str;
	CString dishname;
	CString price;       //가격
	CString quantity;    //수량
	m_menu05.GetWindowText(str);

	AfxExtractSubString(dishname, str, 0, ' ');
	AfxExtractSubString(price, str, 1, ' ');
	price = price.Left(price.GetLength());
	int itemCnt = m_orderlist.GetItemCount();    //행의 수를 얻어옴
	int i;

	for (i = 0; i < itemCnt; i++) {
		if (m_orderlist.GetItemText(i, 0) == dishname) {
			m_bExistDish = TRUE;
			break;
		}
	}

	if (m_bExistDish) {
		int getQuantity = _ttoi(m_orderlist.GetItemText(i, 1));
		int getPrice = _ttoi(m_orderlist.GetItemText(i, 2));

		getQuantity += 1;
		getPrice += _ttoi(price);


		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);

		price.Format(_T("%d"), getPrice);
		quantity.Format(_T("%d"), getQuantity);
		m_orderlist.SetItemText(i, 1, quantity);
		m_orderlist.SetItemText(i, 2, price);
		dishname = _T("\n") + dishname;
		tablemenu5 = dishname + quantity;
		m_bExistDish = FALSE;               //이부분은 FALSE로 안하면 문제가 생기므로 초기화
	}

	else {    //만약 FALSE라면 1번만 실행
		m_orderlist.InsertItem(count, dishname);
		m_orderlist.SetItemText(count, 1, _T("1"));
		m_orderlist.SetItemText(count, 2, price);
		count++;

		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);
		dishname = _T("\n") + dishname;
		tablemenu5 = dishname + quantity;
	}

}


void menu::OnBnClicked1014()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	table* tablenum = (table*)GetParent();

	int count = 0;
	CString str;
	CString dishname;
	CString price;       //가격
	CString quantity;    //수량
	m_menu06.GetWindowText(str);

	AfxExtractSubString(dishname, str, 0, ' ');
	AfxExtractSubString(price, str, 1, ' ');
	price = price.Left(price.GetLength());
	int itemCnt = m_orderlist.GetItemCount();    //행의 수를 얻어옴
	int i;

	for (i = 0; i < itemCnt; i++) {
		if (m_orderlist.GetItemText(i, 0) == dishname) {
			m_bExistDish = TRUE;
			break;
		}
	}

	if (m_bExistDish) {
		int getQuantity = _ttoi(m_orderlist.GetItemText(i, 1));
		int getPrice = _ttoi(m_orderlist.GetItemText(i, 2));

		getQuantity += 1;
		getPrice += _ttoi(price);


		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);

		price.Format(_T("%d"), getPrice);
		quantity.Format(_T("%d"), getQuantity);
		m_orderlist.SetItemText(i, 1, quantity);
		m_orderlist.SetItemText(i, 2, price);
		dishname = _T("\n") + dishname;
		tablemenu6 = dishname + quantity;
		m_bExistDish = FALSE;               //이부분은 FALSE로 안하면 문제가 생기므로 초기화
	}

	else {    //만약 FALSE라면 1번만 실행
		m_orderlist.InsertItem(count, dishname);
		m_orderlist.SetItemText(count, 1, _T("1"));
		m_orderlist.SetItemText(count, 2, price);
		count++;

		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);
		dishname = _T("\n") + dishname;
		tablemenu6 = dishname + quantity;
	}


}


void menu::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	table* tablenum = (table*)GetParent();

	int count = 0;
	CString str;
	CString dishname;
	CString price;       //가격
	CString quantity;    //수량
	m_menu07.GetWindowText(str);

	AfxExtractSubString(dishname, str, 0, ' ');
	AfxExtractSubString(price, str, 1, ' ');
	price = price.Left(price.GetLength());
	int itemCnt = m_orderlist.GetItemCount();    //행의 수를 얻어옴
	int i;

	for (i = 0; i < itemCnt; i++) {
		if (m_orderlist.GetItemText(i, 0) == dishname) {
			m_bExistDish = TRUE;
			break;
		}
	}

	if (m_bExistDish) {
		int getQuantity = _ttoi(m_orderlist.GetItemText(i, 1));
		int getPrice = _ttoi(m_orderlist.GetItemText(i, 2));

		getQuantity += 1;
		getPrice += _ttoi(price);


		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);

		price.Format(_T("%d"), getPrice);
		quantity.Format(_T("%d"), getQuantity);
		m_orderlist.SetItemText(i, 1, quantity);
		m_orderlist.SetItemText(i, 2, price);
		dishname = _T("\n") + dishname;
		tablemenu7 = dishname + quantity;
		m_bExistDish = FALSE;               //이부분은 FALSE로 안하면 문제가 생기므로 초기화
	}

	else {    //만약 FALSE라면 1번만 실행
		m_orderlist.InsertItem(count, dishname);
		m_orderlist.SetItemText(count, 1, _T("1"));
		m_orderlist.SetItemText(count, 2, price);
		count++;

		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);
		dishname = _T("\n") + dishname;
		tablemenu7 = dishname + quantity;
	}



}


void menu::OnBnClicked1017()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	table* tablenum = (table*)GetParent();

	int count = 0;
	CString str;
	CString dishname;
	CString price;       //가격
	CString quantity;    //수량
	m_menu08.GetWindowText(str);

	AfxExtractSubString(dishname, str, 0, ' ');
	AfxExtractSubString(price, str, 1, ' ');
	price = price.Left(price.GetLength());
	int itemCnt = m_orderlist.GetItemCount();    //행의 수를 얻어옴
	int i;

	for (i = 0; i < itemCnt; i++) {
		if (m_orderlist.GetItemText(i, 0) == dishname) {
			m_bExistDish = TRUE;
			break;
		}
	}

	if (m_bExistDish) {
		int getQuantity = _ttoi(m_orderlist.GetItemText(i, 1));
		int getPrice = _ttoi(m_orderlist.GetItemText(i, 2));

		getQuantity += 1;
		getPrice += _ttoi(price);


		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);

		price.Format(_T("%d"), getPrice);
		quantity.Format(_T("%d"), getQuantity);
		m_orderlist.SetItemText(i, 1, quantity);
		m_orderlist.SetItemText(i, 2, price);
		dishname = _T("\n") + dishname;
		tablemenu8 = dishname + quantity;
		m_bExistDish = FALSE;               //이부분은 FALSE로 안하면 문제가 생기므로 초기화
	}

	else {    //만약 FALSE라면 1번만 실행
		m_orderlist.InsertItem(count, dishname);
		m_orderlist.SetItemText(count, 1, _T("1"));
		m_orderlist.SetItemText(count, 2, price);
		count++;

		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);
		dishname = _T("\n") + dishname;
		tablemenu8 = dishname + quantity;
	}



}


void menu::OnBnClicked1012()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	table* tablenum = (table*)GetParent();

	int count = 0;
	CString str;
	CString dishname;
	CString price;       //가격
	CString quantity;    //수량
	m_menu09.GetWindowText(str);

	AfxExtractSubString(dishname, str, 0, ' ');
	AfxExtractSubString(price, str, 1, ' ');
	price = price.Left(price.GetLength());
	int itemCnt = m_orderlist.GetItemCount();    //행의 수를 얻어옴
	int i;

	for (i = 0; i < itemCnt; i++) {
		if (m_orderlist.GetItemText(i, 0) == dishname) {
			m_bExistDish = TRUE;
			break;
		}
	}

	if (m_bExistDish) {
		int getQuantity = _ttoi(m_orderlist.GetItemText(i, 1));
		int getPrice = _ttoi(m_orderlist.GetItemText(i, 2));

		getQuantity += 1;
		getPrice += _ttoi(price);


		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);

		price.Format(_T("%d"), getPrice);
		quantity.Format(_T("%d"), getQuantity);
		m_orderlist.SetItemText(i, 1, quantity);
		m_orderlist.SetItemText(i, 2, price);
		dishname = _T("\n") + dishname;
		tablemenu9 = dishname + quantity;
		m_bExistDish = FALSE;               //이부분은 FALSE로 안하면 문제가 생기므로 초기화
	}

	else {    //만약 FALSE라면 1번만 실행
		m_orderlist.InsertItem(count, dishname);
		m_orderlist.SetItemText(count, 1, _T("1"));
		m_orderlist.SetItemText(count, 2, price);
		count++;

		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);
		dishname = _T("\n") + dishname;
		tablemenu9 = dishname + quantity;
	}



}


void menu::OnBnClicked1013()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	table* tablenum = (table*)GetParent();

	int count = 0;
	CString str;
	CString dishname;
	CString price;       //가격
	CString quantity;    //수량
	m_menu10.GetWindowText(str);

	AfxExtractSubString(dishname, str, 0, ' ');
	AfxExtractSubString(price, str, 1, ' ');
	price = price.Left(price.GetLength());
	int itemCnt = m_orderlist.GetItemCount();    //행의 수를 얻어옴
	int i;

	for (i = 0; i < itemCnt; i++) {
		if (m_orderlist.GetItemText(i, 0) == dishname) {
			m_bExistDish = TRUE;
			break;
		}
	}

	if (m_bExistDish) {
		int getQuantity = _ttoi(m_orderlist.GetItemText(i, 1));
		int getPrice = _ttoi(m_orderlist.GetItemText(i, 2));

		getQuantity += 1;
		getPrice += _ttoi(price);


		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);

		price.Format(_T("%d"), getPrice);
		quantity.Format(_T("%d"), getQuantity);
		m_orderlist.SetItemText(i, 1, quantity);
		m_orderlist.SetItemText(i, 2, price);
		dishname = _T("\n") + dishname;
		tablemenu10 = dishname + quantity;
		m_bExistDish = FALSE;               //이부분은 FALSE로 안하면 문제가 생기므로 초기화
	}

	else {    //만약 FALSE라면 1번만 실행
		m_orderlist.InsertItem(count, dishname);
		m_orderlist.SetItemText(count, 1, _T("1"));
		m_orderlist.SetItemText(count, 2, price);
		count++;

		m_UtotalPrice += _ttoi(price);
		price.Format(_T("%d"), m_UtotalPrice);
		m_totalprice.SetWindowText(price);
		dishname = _T("\n") + dishname;
		tablemenu10 = dishname + quantity;
	}



}

