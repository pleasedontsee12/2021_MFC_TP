// cardpay1.cpp: 구현 파일
//

#include "pch.h"
#include "login.h"
#include "cardpay1.h"
#include "afxdialogex.h"
#include "pickpay.h"
#include "table.h"


// cardpay1 대화 상자

IMPLEMENT_DYNAMIC(cardpay1, CDialogEx)

cardpay1::cardpay1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_F_CARDPAY, pParent)
{

}

cardpay1::~cardpay1()
{
}

void cardpay1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(cardpay1, CDialogEx)
	ON_BN_CLICKED(IDC_CARDPAYB, &cardpay1::OnBnClickedCardpayb)
	ON_BN_CLICKED(IDC_CARDPAYB2, &cardpay1::OnBnClickedCardpayb2)
END_MESSAGE_MAP()


// cardpay1 메시지 처리기


void cardpay1::OnBnClickedCardpayb()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("결제 되었습니다."));


	OnOK();
}


void cardpay1::OnBnClickedCardpayb2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}




BOOL cardpay1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	SetBackgroundColor(RGB(255, 255, 255));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
