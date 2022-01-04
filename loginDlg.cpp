
// loginDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "login.h"
#include "loginDlg.h"
#include "afxdialogex.h"
#include "mainmenu.h"

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


// CloginDlg 대화 상자



CloginDlg::CloginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOGIN_DIALOG, pParent)
	, m_id(_T(""))
	, m_pw(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CloginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_idEdit);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT3, m_pw);
	DDX_Control(pDX, IDC_EDIT3, m_pwEdit);
	DDX_Control(pDX, IDC_BUTTON1, m_danddo);
	DDX_Control(pDX, IDC_BUTTON2, m_danddo123);
}

BEGIN_MESSAGE_MAP(CloginDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CloginDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CloginDlg 메시지 처리기

BOOL CloginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	SetBackgroundColor(RGB(255, 255, 255));
	m_danddo123.LoadBitmaps(IDB_danddo1, IDB_danddo1, IDB_danddo1, IDB_danddo1);
	m_danddo123.SizeToContent();
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CloginDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CloginDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CloginDlg::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	OnBnClickedButton1();

}

void CloginDlg::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CDialogEx::OnCancel();
}





void CloginDlg::OnBnClickedButton1()
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

	CString ID;
	CString PW;
	m_idEdit.GetWindowText(ID);
	m_pwEdit.GetWindowText(PW);
	char* query;
	query = "SELECT * FROM teamproject.login";
	mysql_query(conn, query);
	TRACE(query + '\n');
	m_res = mysql_store_result(conn);
	if (m_res == NULL) {
		TRACE(_T("내용 없음\n"));
	}
	else {
		while ((m_row = mysql_fetch_row(m_res)) != NULL) {
			CString tmp(m_row[0]);
			CString tmp1(m_row[1]);
			if (tmp == ID && tmp1 == PW) {
				MessageBox(_T("로그인 성공"));
				mainmenu dlg;
				dlg.DoModal();
			}
		}
		MessageBox(_T("로그인 실패"));
		mysql_free_result(m_res);
	}
	mysql_close(conn);
}

