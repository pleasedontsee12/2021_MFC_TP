// salesanalysis.cpp: 구현 파일
//

#include "pch.h"
#include "login.h"
#include "salesanalysis.h"
#include "afxdialogex.h"
#include "sales.h"

#include "mysql.h"
#include <Winsock2.h>

#pragma comment(lib, "libmysql.lib")
#pragma comment(lib, "ws2_32.lib")

#define DB_ADDRESS "34.64.209.235"
#define DB_ID "root"
#define DB_PASS "1317"
#define DB_NAME "teamproject"

// salesanalysis 대화 상자

IMPLEMENT_DYNAMIC(salesanalysis, CDialogEx)

salesanalysis::salesanalysis(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_G_salesanalysis, pParent)
{

}

salesanalysis::~salesanalysis()
{
}

void salesanalysis::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_analysisListCtrl);
}


BEGIN_MESSAGE_MAP(salesanalysis, CDialogEx)
END_MESSAGE_MAP()


// salesanalysis 메시지 처리기


BOOL salesanalysis::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetBackgroundColor(RGB(255, 255, 255));


	m_analysisListCtrl.SetRedraw(FALSE);

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

	sales* sales1 = (sales*)GetParent();
	LPNMITEMACTIVATE resource = sales1->m_rowItem;

	m_analysisListCtrl.ModifyStyle(LVS_OWNERDRAWFIXED, 0, 0); //창의 스타일을 수정함
	m_analysisListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	CRect rect;
	m_analysisListCtrl.GetWindowRect(&rect);

	m_analysisListCtrl.InsertColumn(0, _T("날짜 & 음식"), LVCFMT_LEFT, (int)(rect.Width() * 0.74));
	m_analysisListCtrl.InsertColumn(1, _T("수량"), LVCFMT_CENTER, (int)(rect.Width() * 0.2));

	CString number; //날(day) 저장 변수
	CString date, tmpDate;
	sales1->m_yearAndMonth.GetWindowText(tmpDate);
	int row = 0;

	if (resource->iItem != -1) {
		for (int i = 0; i < 7; i++) {
			number.Format(_T("%s"), (LPCTSTR)sales1->m_calendarList.GetItemText(resource->iItem, i + 1));
			
			if (0 < _ttoi(number) && _ttoi(number) < 32) {
				date.Format(_T("%s-%s"), (LPCTSTR)tmpDate, (LPCTSTR)sales1->m_calendarList.GetItemText(resource->iItem, i + 1));
				query.Format(_T("select dishname, sum(quantity) from teamproject.order_details where orderdate='%s' group by dishname"), (LPCTSTR)date);
				mysql_query(conn, (LPSTR)(LPCTSTR)query);
				TRACE(query + _T("\r\n"));
				m_res = mysql_store_result(conn);
			
				if (m_res == NULL) {
					TRACE(_T("내용 없음\n"));
				}
			
				else {
					m_analysisListCtrl.InsertItem(row++, date);
				
					while ((m_row = mysql_fetch_row(m_res)) != NULL) {
						m_analysisListCtrl.InsertItem(row, CString(m_row[0]));
						m_analysisListCtrl.SetItemText(row, 1, CString(m_row[1]));
						row++;
					}
					m_analysisListCtrl.InsertItem(row++, _T("")); //날짜 당 공백
				}
			}
		}
	}

	m_analysisListCtrl.SetRedraw(TRUE);
	mysql_close(conn);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
