// moneypay.cpp: 구현 파일
//

#include "pch.h"
#include "login.h"
#include "moneypay.h"
#include "afxdialogex.h"
#include "pickpay.h"
#include "table.h"

// moneypay 대화 상자

IMPLEMENT_DYNAMIC(moneypay, CDialogEx)

moneypay::moneypay(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_F_MONEYPAY, pParent)
{

}

moneypay::~moneypay()
{
}

void moneypay::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(moneypay, CDialogEx)
	ON_BN_CLICKED(IDC_CARDPAYB, &moneypay::OnBnClickedCardpayb)
	ON_BN_CLICKED(IDC_CARDPAYB2, &moneypay::OnBnClickedCardpayb2)
END_MESSAGE_MAP()


// moneypay 메시지 처리기


void moneypay::OnBnClickedCardpayb()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("결제 되었습니다."));
	table* tbl = (table*)GetParent();



	
	
	OnOK();
}


void moneypay::OnBnClickedCardpayb2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	OnOK();
}


BOOL moneypay::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	SetBackgroundColor(RGB(255, 255, 255));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
