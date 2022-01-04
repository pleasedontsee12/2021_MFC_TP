// pickpay.cpp: 구현 파일
//

#include "pch.h"
#include "login.h"
#include "pickpay.h"
#include "afxdialogex.h"
#include "moneypay.h"
#include "cardpay1.h"
#include "table.h"
#include "menu.h"

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
// pickpay 대화 상자

IMPLEMENT_DYNAMIC(pickpay, CDialogEx)

pickpay::pickpay(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_E_PICKPAY, pParent)
{

}

pickpay::~pickpay()
{
}

void pickpay::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(pickpay, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &pickpay::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON12, &pickpay::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON3, &pickpay::OnBnClickedButton3)
	ON_BN_CLICKED(IDCANCEL, &pickpay::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON4, &pickpay::OnBnClickedButton4)
END_MESSAGE_MAP()


// pickpay 메시지 처리기

void pickpay::OnBnClickedButton12() // 현금 클릭
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	MYSQL_ROW m_row;
	MYSQL_RES* m_res;
	MYSQL* conn = mysql_init(NULL);

	mysql_init(conn);

	if (!mysql_real_connect(conn, DB_ADDRESS, DB_ID, DB_PASS, DB_NAME, 3306, NULL, 0)) {
		CString str = (LPCTSTR)mysql_error(conn);
		TRACE(str);
	}
	else {
		mysql_query(conn, "set names euckr");
		TRACE(_T("DB 연동 성공\n"));
	}


	CString query;
	query = "SELECT * FROM teamproject.order_details";
	mysql_query(conn, (LPSTR)(LPCTSTR)query);
	TRACE(query + '\n');
	m_res = mysql_store_result(conn);

	table* tbl = (table*)GetParent();

	CString str;
	CString streuslt;

	moneypay dlg;
	dlg.DoModal();

	//orderdate
	CTime tm;
	tm = CTime::GetCurrentTime();
	
	/*
	CString currentYM = tm.Format(_T("%Y-%m"));
	CString day = tm.Format(_T("%d"));
	day = day.Right(1);
	CString orderdate = currentYM + _T("-") + day;
	*/

	CString ymd = CTime::GetCurrentTime().Format("%Y-%m-%d");

	//dishname / dishprice / quantity

	// insert into order_details values(tid,orderdate,dishname,dishprice,quantity)
	// tid  / orderdate / dishname / dishprice / quantity

	switch (tbl->tablenum)
	{
	case 1: {
		//query.Format("insert into order_details values (%d,%s,%s,%d,%d)",tbl->tablenum,orderdate,);
		tbl->m_table1.GetWindowText(str);
		tbl->m_table1.EnableWindow(TRUE);
		tbl->m_table1pay.EnableWindow(FALSE);
		tbl->m_table1.SetWindowText(_T("1번 테이블"));

		for (int i = 0; i < 10; i++) {
			paydialogmenu[1][i] = tbl->mtest[1][i];
			paydialogprice[1][i] = tbl->ptest[1][i];
			paydialogquantity[1][i] = tbl->qtest[1][i];
		}

		for (int i = 0; i < 10; i++) {
			query.Format(_T(" insert into order_details values(%d,'%s','%s',%s,%s)"), 
				tbl->tablenum, ymd, paydialogmenu[1][i], paydialogprice[1][i], paydialogquantity[1][i]);
			mysql_query(conn, (LPSTR)(LPCTSTR)query);
			TRACE(query + '\n');
		}



		break;
	}
	case 2: {
		tbl->m_table2.GetWindowText(str);
		tbl->m_table2.EnableWindow(TRUE);
		tbl->m_table2pay.EnableWindow(FALSE);
		tbl->m_table2.SetWindowText(_T("2번 테이블"));

		for (int i = 0; i < 10; i++) {
			paydialogmenu[2][i] = tbl->mtest[2][i];
			paydialogprice[2][i] = tbl->ptest[2][i];
			paydialogquantity[2][i] = tbl->qtest[2][i];
		}

		for (int i = 0; i < 10; i++) {
			query.Format(_T(" insert into order_details values(%d,'%s','%s',%s,%s)"), 
				tbl->tablenum, ymd, paydialogmenu[2][i], paydialogprice[2][i], paydialogquantity[2][i]);
			mysql_query(conn, (LPSTR)(LPCTSTR)query);
			TRACE(query + '\n');
		}

		break;
	}
	case 3: {
		tbl->m_table3.GetWindowText(str);
		tbl->m_table3.EnableWindow(TRUE);
		tbl->m_table3pay.EnableWindow(FALSE);
		tbl->m_table3.SetWindowText(_T("3번 테이블"));

		for (int i = 0; i < 10; i++) {
			paydialogmenu[3][i] = tbl->mtest[3][i];
			paydialogprice[3][i] = tbl->ptest[3][i];
			paydialogquantity[3][i] = tbl->qtest[3][i];
		}

		for (int i = 0; i < 10; i++) {
			query.Format(_T(" insert into order_details values(%d,'%s','%s',%s,%s)"), 
				tbl->tablenum, ymd, paydialogmenu[3][i], paydialogprice[3][i], paydialogquantity[3][i]);
			mysql_query(conn, (LPSTR)(LPCTSTR)query);
			TRACE(query + '\n');
		}

		break;
	}
	case 4: {
		tbl->m_table4.GetWindowText(str);
		tbl->m_table4.EnableWindow(TRUE);
		tbl->m_table4pay.EnableWindow(FALSE);
		tbl->m_table4.SetWindowText(_T("4번 테이블"));

		for (int i = 0; i < 10; i++) {
			paydialogmenu[4][i] = tbl->mtest[4][i];
			paydialogprice[4][i] = tbl->ptest[4][i];
			paydialogquantity[4][i] = tbl->qtest[4][i];
		}

		for (int i = 0; i < 10; i++) {
			query.Format(_T(" insert into order_details values(%d,'%s','%s',%s,%s)"), 
				tbl->tablenum, ymd, paydialogmenu[4][i], paydialogprice[4][i], paydialogquantity[4][i]);
			mysql_query(conn, (LPSTR)(LPCTSTR)query);
			TRACE(query + '\n');
		}

		break;
	}
	case 5: {
		tbl->m_table5.GetWindowText(str);
		tbl->m_table5.EnableWindow(TRUE);
		tbl->m_table5pay.EnableWindow(FALSE);
		tbl->m_table5.SetWindowText(_T("5번 테이블"));

		for (int i = 0; i < 10; i++) {
			paydialogmenu[5][i] = tbl->mtest[5][i];
			paydialogprice[5][i] = tbl->ptest[5][i];
			paydialogquantity[5][i] = tbl->qtest[5][i];
		}

		for (int i = 0; i < 10; i++) {
			query.Format(_T(" insert into order_details values(%d,'%s','%s',%s,%s)"), 
				tbl->tablenum, ymd, paydialogmenu[5][i], paydialogprice[5][i], paydialogquantity[5][i]);
			mysql_query(conn, (LPSTR)(LPCTSTR)query);
			TRACE(query + '\n');
		}

		break;
	}
	case 6: {
		tbl->m_table6.GetWindowText(str);
		tbl->m_table6.EnableWindow(TRUE);
		tbl->m_table6pay.EnableWindow(FALSE);
		tbl->m_table6.SetWindowText(_T("6번 테이블"));

		for (int i = 0; i < 10; i++) {
			paydialogmenu[6][i] = tbl->mtest[6][i];
			paydialogprice[6][i] = tbl->ptest[6][i];
			paydialogquantity[6][i] = tbl->qtest[6][i];
		}

		for (int i = 0; i < 10; i++) {
			query.Format(_T(" insert into order_details values(%d,'%s','%s',%s,%s)"), 
				tbl->tablenum, ymd, paydialogmenu[6][i], paydialogprice[6][i], paydialogquantity[6][i]);
			mysql_query(conn, (LPSTR)(LPCTSTR)query);
			TRACE(query + '\n');
		}


		break;
	}

	}

	mysql_close(conn);
	OnOK();


}


void pickpay::OnBnClickedButton1() // 카드 클릭
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MYSQL_ROW m_row;
	MYSQL_RES* m_res;
	MYSQL* conn = mysql_init(NULL);

	mysql_init(conn);

	if (!mysql_real_connect(conn, DB_ADDRESS, DB_ID, DB_PASS, DB_NAME, 3306, NULL, 0)) {
		CString str = (LPCTSTR)mysql_error(conn);
		TRACE(str);
	}
	else {
		mysql_query(conn, "set names euckr");
		TRACE(_T("DB 연동 성공\n"));
	}


	CString query;
	query = "SELECT * FROM teamproject.order_details";
	mysql_query(conn, (LPSTR)(LPCTSTR)query);
	TRACE(query + '\n');
	m_res = mysql_store_result(conn);

	table* tbl = (table*)GetParent();

	CString str;
	CString streuslt;

	cardpay1 dlg;
	dlg.DoModal();

	//orderdate
	CTime tm;
	tm = CTime::GetCurrentTime();

	CString currentYM = tm.Format(_T("%Y-%m"));
	CString day = tm.Format(_T("%d"));
	day = day.Right(1);

	CString orderdate = currentYM + _T("-") + day;


	switch (tbl->tablenum)
	{
	case 1: {
		//query.Format("insert into order_details values (%d,%s,%s,%d,%d)",tbl->tablenum,orderdate,);
		tbl->m_table1.GetWindowText(str);
		tbl->m_table1.EnableWindow(TRUE);
		tbl->m_table1pay.EnableWindow(FALSE);
		tbl->m_table1.SetWindowText(_T("1번 테이블"));

		for (int i = 0; i < 10; i++) {
			paydialogmenu[1][i] = tbl->mtest[1][i];
			paydialogprice[1][i] = tbl->ptest[1][i];
			paydialogquantity[1][i] = tbl->qtest[1][i];
		}

		for (int i = 0; i < 10; i++) {
			query.Format(_T(" insert into order_details values(%d,'%s','%s',%s,%s)"),
				tbl->tablenum, orderdate, paydialogmenu[1][i], paydialogprice[1][i], paydialogquantity[1][i]);
			mysql_query(conn, (LPSTR)(LPCTSTR)query);
			TRACE(query + '\n');
		}



		break;
	}
	case 2: {
		tbl->m_table2.GetWindowText(str);
		tbl->m_table2.EnableWindow(TRUE);
		tbl->m_table2pay.EnableWindow(FALSE);
		tbl->m_table2.SetWindowText(_T("2번 테이블"));

		for (int i = 0; i < 10; i++) {
			paydialogmenu[2][i] = tbl->mtest[2][i];
			paydialogprice[2][i] = tbl->ptest[2][i];
			paydialogquantity[2][i] = tbl->qtest[2][i];
		}

		for (int i = 0; i < 10; i++) {
			query.Format(_T(" insert into order_details values(%d,'%s','%s',%s,%s)"),
				tbl->tablenum, orderdate, paydialogmenu[2][i], paydialogprice[2][i], paydialogquantity[2][i]);
			mysql_query(conn, (LPSTR)(LPCTSTR)query);
			TRACE(query + '\n');
		}

		break;
	}
	case 3: {
		tbl->m_table3.GetWindowText(str);
		tbl->m_table3.EnableWindow(TRUE);
		tbl->m_table3pay.EnableWindow(FALSE);
		tbl->m_table3.SetWindowText(_T("3번 테이블"));

		for (int i = 0; i < 10; i++) {
			paydialogmenu[3][i] = tbl->mtest[3][i];
			paydialogprice[3][i] = tbl->ptest[3][i];
			paydialogquantity[3][i] = tbl->qtest[3][i];
		}

		for (int i = 0; i < 10; i++) {
			query.Format(_T(" insert into order_details values(%d,'%s','%s',%s,%s)"),
				tbl->tablenum, orderdate, paydialogmenu[3][i], paydialogprice[3][i], paydialogquantity[3][i]);
			mysql_query(conn, (LPSTR)(LPCTSTR)query);
			TRACE(query + '\n');
		}

		break;
	}
	case 4: {
		tbl->m_table4.GetWindowText(str);
		tbl->m_table4.EnableWindow(TRUE);
		tbl->m_table4pay.EnableWindow(FALSE);
		tbl->m_table4.SetWindowText(_T("4번 테이블"));

		for (int i = 0; i < 10; i++) {
			paydialogmenu[4][i] = tbl->mtest[4][i];
			paydialogprice[4][i] = tbl->ptest[4][i];
			paydialogquantity[4][i] = tbl->qtest[4][i];
		}

		for (int i = 0; i < 10; i++) {
			query.Format(_T(" insert into order_details values(%d,'%s','%s',%s,%s)"),
				tbl->tablenum, orderdate, paydialogmenu[4][i], paydialogprice[4][i], paydialogquantity[4][i]);
			mysql_query(conn, (LPSTR)(LPCTSTR)query);
			TRACE(query + '\n');
		}

		break;
	}
	case 5: {
		tbl->m_table5.GetWindowText(str);
		tbl->m_table5.EnableWindow(TRUE);
		tbl->m_table5pay.EnableWindow(FALSE);
		tbl->m_table5.SetWindowText(_T("5번 테이블"));

		for (int i = 0; i < 10; i++) {
			paydialogmenu[5][i] = tbl->mtest[5][i];
			paydialogprice[5][i] = tbl->ptest[5][i];
			paydialogquantity[5][i] = tbl->qtest[5][i];
		}

		for (int i = 0; i < 10; i++) {
			query.Format(_T(" insert into order_details values(%d,'%s','%s',%s,%s)"),
				tbl->tablenum, orderdate, paydialogmenu[5][i], paydialogprice[5][i], paydialogquantity[5][i]);
			mysql_query(conn, (LPSTR)(LPCTSTR)query);
			TRACE(query + '\n');
		}

		break;
	}
	case 6: {
		tbl->m_table6.GetWindowText(str);
		tbl->m_table6.EnableWindow(TRUE);
		tbl->m_table6pay.EnableWindow(FALSE);
		tbl->m_table6.SetWindowText(_T("6번 테이블"));

		for (int i = 0; i < 10; i++) {
			paydialogmenu[6][i] = tbl->mtest[6][i];
			paydialogprice[6][i] = tbl->ptest[6][i];
			paydialogquantity[6][i] = tbl->qtest[6][i];
		}

		for (int i = 0; i < 10; i++) {
			query.Format(_T(" insert into order_details values(%d,'%s','%s',%s,%s)"),
				tbl->tablenum, orderdate, paydialogmenu[6][i], paydialogprice[6][i], paydialogquantity[6][i]);
			mysql_query(conn, (LPSTR)(LPCTSTR)query);
			TRACE(query + '\n');
		}


		break;
	}

	}

	mysql_close(conn);
	OnOK();

}


void pickpay::OnBnClickedButton4() // 주문 취소
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	table* tbl = (table*)GetParent();
	CString str;

	switch (tbl->tablenum)
	{
	case 1:
		tbl->m_table1.EnableWindow(TRUE);
		tbl->m_table1pay.EnableWindow(FALSE);
		tbl->m_table1.SetWindowText(_T("1번 테이블"));
		break;

	case 2:
		tbl->m_table2.EnableWindow(TRUE);
		tbl->m_table2pay.EnableWindow(FALSE);
		tbl->m_table2.SetWindowText(_T("2번 테이블"));
		break;

	case 3:
		tbl->m_table3.EnableWindow(TRUE);
		tbl->m_table3pay.EnableWindow(FALSE);
		tbl->m_table3.SetWindowText(_T("3번 테이블"));
		break;

	case 4:
		tbl->m_table4.EnableWindow(TRUE);
		tbl->m_table4pay.EnableWindow(FALSE);
		tbl->m_table4.SetWindowText(_T("4번 테이블"));
		break;

	case 5:
		tbl->m_table5.EnableWindow(TRUE);
		tbl->m_table5pay.EnableWindow(FALSE);
		tbl->m_table5.SetWindowText(_T("5번 테이블"));
		break;

	case 6:
		tbl->m_table6.EnableWindow(TRUE);
		tbl->m_table6pay.EnableWindow(FALSE);
		tbl->m_table6.SetWindowText(_T("6번 테이블"));
		break;
	}

	AfxMessageBox(_T("주문이 취소되었습니다."));
	OnOK();
	
	
}


void pickpay::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	OnOK();

}


void pickpay::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.



	OnOK();

}




BOOL pickpay::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	SetBackgroundColor(RGB(255, 255, 255));

	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
