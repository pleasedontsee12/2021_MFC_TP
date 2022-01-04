// cardpay.cpp: 구현 파일
//

#include "pch.h"
#include "login.h"
#include "cardpay.h"
#include "afxdialogex.h"
#include "pickpay.h"
#include "table.h"
#include "menu.h"

// cardpay 대화 상자

IMPLEMENT_DYNAMIC(cardpay, CDialogEx)

cardpay::cardpay(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_F_CARDPAY, pParent)
{

}

cardpay::~cardpay()
{
}

void cardpay::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(cardpay, CDialogEx)
	ON_BN_CLICKED(IDC_CARDPAYB, &cardpay::OnBnClickedCardpayb)
	ON_BN_CLICKED(IDC_CARDPAYB2, &cardpay::OnBnClickedCardpayb2)
END_MESSAGE_MAP()


// cardpay 메시지 처리기



void cardpay::OnBnClickedCardpayb()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	AfxMessageBox(_T("결제 되었습니다."));
	/*
	table* tbl = (table*)GetParent();
	tbl->paysuccess = TRUE;
	*/
	paysuc = 1;
	pickpay* pkp = (pickpay*)GetParent();
	pkp->OnBnClickedButton3();
	

	OnOK();
}


void cardpay::OnBnClickedCardpayb2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("결제가 취소 되었습니다."));
	
	/*
	table* tbl = (table*)GetParent();
	tbl->paysuccess = FALSE;
	*/

	paysuc = 0;
	pickpay* pkp = (pickpay*)GetParent();
	pkp->OnBnClickedCancel();
	


	OnOK();
}


BOOL cardpay::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	m_cardsum.SetWindowText(table1paysum);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
