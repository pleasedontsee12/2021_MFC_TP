// sales.cpp: 구현 파일
//

#include "pch.h"
#include "login.h"
#include "sales.h"
#include "afxdialogex.h"
#include "salesanalysis.h"

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

int day[2][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int isLeafYear(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0 ? 1 : 0;
}

int convertDateToDays(int year, int month) {
	int days = 0;

	for (int i = 1; i < year; i++) {
		days += isLeafYear(i) ? 366 : 365;
	}
	for (int i = 1; i < month; i++) {
		days += day[isLeafYear(year)][i - 1];
	}
	return days;
}


// sales 대화 상자

IMPLEMENT_DYNAMIC(sales, CDialogEx)

sales::sales(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_G_Sales2, pParent)
{

}

sales::~sales()
{
}

void sales::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, 1018, m_yearAndMonth);
	DDX_Control(pDX, 1043, m_calendarList);
}


BEGIN_MESSAGE_MAP(sales, CDialogEx)
	ON_BN_CLICKED(IDC_LEFT, &sales::OnBnClickedLeft)
	ON_BN_CLICKED(IDC_RIGHT, &sales::OnBnClickedRight)
	ON_BN_CLICKED(IDC_TABLECNT, &sales::OnBnClickedTablecnt)
	ON_BN_CLICKED(IDC_MONTHSALES, &sales::OnBnClickedMonthsales)
	ON_BN_CLICKED(IDC_SALESCNT, &sales::OnBnClickedSalescnt)
	ON_NOTIFY(NM_DBLCLK, 1043, &sales::OnDblclk1043)
	ON_NOTIFY(LVN_ITEMCHANGED, 1043, &sales::OnLvnItemchanged1043)
END_MESSAGE_MAP()


// sales 메시지 처리기


BOOL sales::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetBackgroundColor(RGB(255, 255, 255));
	CFont font;
	font.CreatePointFont(200, _T("바탕"));
	m_yearAndMonth.SetFont(&font);
	CTime tm;
	tm = CTime::GetCurrentTime();
	CString currentYM = tm.Format(_T("%Y-%m"));
	m_yearAndMonth.SetWindowText(currentYM);

	m_calendarList.SetExtendedStyle(m_calendarList.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT); //격자 추가 
	m_calendarList.InsertColumn(0, _T(""));
	m_calendarList.InsertColumn(1, _T("일"), LVCFMT_CENTER, 120);
	m_calendarList.InsertColumn(2, _T("월"), LVCFMT_CENTER, 120);
	m_calendarList.InsertColumn(3, _T("화"), LVCFMT_CENTER, 120);
	m_calendarList.InsertColumn(4, _T("수"), LVCFMT_CENTER, 120);
	m_calendarList.InsertColumn(5, _T("목"), LVCFMT_CENTER, 120);
	m_calendarList.InsertColumn(6, _T("금"), LVCFMT_CENTER, 120);
	m_calendarList.InsertColumn(7, _T("토"), LVCFMT_CENTER, 120);

	m_calendarList.SetColumnWidth(7, LVSCW_AUTOSIZE_USEHEADER); //이거는 칼럼의 너비를 맞춰주기위해


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void sales::OnBnClickedLeft()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_calendarList.DeleteAllItems();
	CString date;
	CString year;
	CString month;

	m_yearAndMonth.GetWindowText(date);
	AfxExtractSubString(year, date, 0, '-');
	AfxExtractSubString(month, date, 1, '-');
	month.Format(_T("%d"), _ttoi(month) - 1);

	if (_ttoi(month) <= 0) {
		month = _T("12");
		year.Format(_T("%d"), _ttoi(year) - 1);
	}

	m_yearAndMonth.SetWindowText(year + _T("-") + month);

}


void sales::OnBnClickedRight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_calendarList.DeleteAllItems();
	CString date;
	CString year;
	CString month;
	m_yearAndMonth.GetWindowText(date);
	AfxExtractSubString(year, date, 0, '-');
	AfxExtractSubString(month, date, 1, '-');
	month.Format(_T("%d"), _ttoi(month) + 1);

	if (_ttoi(month) > 12) {
		month = _T("1");
		year.Format(_T("%d"), _ttoi(year) + 1);
	}

	m_yearAndMonth.SetWindowText(year + _T("-") + month);


}


void sales::OnBnClickedTablecnt()
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

	m_calendarList.SetRedraw(FALSE); //깜빡임 중지
	m_calendarList.DeleteAllItems(); //모든항목삭제

	CString date;
	CString year;
	CString month;

	m_yearAndMonth.GetWindowText(date);
	AfxExtractSubString(year, date, 0, '-');
	AfxExtractSubString(month, date, 1, '-');

	int UYear = _ttoi(year);
	int UMonth = _ttoi(month);

	int days = convertDateToDays(UYear, UMonth);
	int startOfDate = days % 7;
	int count = 0;
	int row = 0;
	m_calendarList.InsertItem(row, _T(""));
	m_calendarList.InsertItem(++row, _T(""));
	m_calendarList.InsertItem(++row, _T(""));
	m_calendarList.InsertItem(++row, _T(""));

	for (int i = 0; i <= startOfDate; i++) {
		m_calendarList.SetItemText(row - 3, i + 1, _T(""));
		count++;
	}

	CString tmp;
	CFont font;
	font.CreatePointFont(100, _T("바탕"));
	m_calendarList.SetFont(&font);
	for (int i = 1; i <= day[isLeafYear(UYear)][UMonth - 1]; i++) {
		if (count % 7 == 0) {
			row++;
			m_calendarList.InsertItem(row, _T(""));
			m_calendarList.InsertItem(++row, _T(""));
			m_calendarList.InsertItem(++row, _T(""));
			m_calendarList.InsertItem(++row, _T(""));
		}

		CString selectDate;
		selectDate.Format(_T("%s-%d"), (LPCTSTR)date, i);
		query.Format(_T("SELECT count(DISTINCT tid) from teamproject.order_details where orderdate='%s'"), (LPCTSTR)selectDate);
		mysql_query(conn, (LPSTR)(LPCTSTR)query);
		TRACE(query + '\n');
		m_res = mysql_store_result(conn);
		if (m_res == NULL) {
			TRACE(_T("내용 없음\n"));

		}
		else {
			m_row = mysql_fetch_row(m_res);
			if (CString(m_row[0]) != _T("0")) {
				m_calendarList.SetItemText(row - 1, (count % 7) + 1, CString(m_row[0]) + _T(" TABLES"));
			}
		}

		tmp.Format(_T("%d"), i);
		m_calendarList.SetItemText(row - 3, (count % 7) + 1, tmp);
		count++;
	}
	mysql_close(conn);
	m_calendarList.SetRedraw(TRUE);

}


void sales::OnBnClickedMonthsales()
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


	m_calendarList.SetRedraw(FALSE); //깜빡임 중지
	m_calendarList.DeleteAllItems(); //모든항목삭제

	CString date;
	CString year;
	CString month;
	int count = 0; // day(날짜) 
	int row = 0; //listctrl 행

	m_yearAndMonth.GetWindowText(date);
	AfxExtractSubString(year, date, 0, '-');
	AfxExtractSubString(month, date, 1, '-');

	int UYear = _ttoi(year);
	int UMonth = _ttoi(month);

	int days = convertDateToDays(UYear, UMonth);
	int startOfDate = days % 7; //시작은 일요일부터
	m_calendarList.InsertItem(row, _T(""));
	m_calendarList.InsertItem(++row, _T(""));
	m_calendarList.InsertItem(++row, _T(""));
	m_calendarList.InsertItem(++row, _T(""));

	//공백이 있으면 채움
	for (int i = 0; i <= startOfDate; i++) {
		m_calendarList.SetItemText(row - 3, i + 1, _T(""));
		count++;
	}

	CString tmp;
	CFont font;
	font.CreatePointFont(100, _T("바탕"));
	m_calendarList.SetFont(&font);
	for (int i = 1; i <= day[isLeafYear(UYear)][UMonth - 1]; i++) {
		if (count % 7 == 0) {  //일주일이 넘어갈때마다 행 4개씩 추가
			row++;
			m_calendarList.InsertItem(row, _T(""));
			m_calendarList.InsertItem(++row, _T(""));
			m_calendarList.InsertItem(++row, _T(""));
			m_calendarList.InsertItem(++row, _T(""));
		}

		tmp.Format(_T("%d"), i);
		m_calendarList.SetItemText(row - 3, (count % 7) + 1, tmp);

		CString selectDate;
		selectDate.Format(_T("%s-%d"), (LPCTSTR)date, i);
		query.Format(_T("select sum(dishprice) from teamproject.order_details where orderdate='%s'"), (LPCTSTR)selectDate); //query문 작성
		mysql_query(conn, (LPSTR)(LPCTSTR)query);  //query 실행
		TRACE(query + '\n'); //query가 잘되는지 출력창에서 확인하기
		m_res = mysql_store_result(conn); //얻어온 값을 결과에 저장
		if (m_res == NULL) {
			TRACE(_T("내용 없음\n"));
		}
		else {
			m_row = mysql_fetch_row(m_res); //결과가 하나이므로 반복문은 안써도됨 
			CString totalPrice(m_row[0]);
			int priceLen = totalPrice.GetLength();
			for (int i = priceLen; i > 3; i -= 3) { //3자리 콤마
				totalPrice.Insert(i - 3, _T(","));
			}
			m_calendarList.SetItemText(row - 1, (count % 7) + 1, totalPrice);
		}
		count++;
	}

	m_calendarList.SetRedraw(TRUE); //TRUE를 하면 다시그림
	mysql_close(conn);
}


void sales::OnBnClickedSalescnt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void sales::OnDblclk1043(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (pNMItemActivate->iItem % 4 == 0) { //날짜를 클릭했을 때만
		m_rowItem = pNMItemActivate; // SalesAnalysis에서 쓰기위해 바인딩
		salesanalysis dlg;
		dlg.DoModal();
	}

	/*
	CString tmp;
	if (pNMItemActivate->iItem != -1) {
		for (int i = 0; i < m_calendarList.GetItemCount(); i++) {
			tmp += m_calendarList.GetItemText(pNMItemActivate->iItem, i) + _T("\n");
		}
	}
	*/
	*pResult = 0;
}


void sales::OnLvnItemchanged1043(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}
