#pragma once


// cardpay1 대화 상자

class cardpay1 : public CDialogEx
{
	DECLARE_DYNAMIC(cardpay1)

public:
	cardpay1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~cardpay1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_F_CARDPAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCardpayb();
	afx_msg void OnBnClickedCardpayb2();
//	virtual BOOL OnInitDialog();
	virtual BOOL OnInitDialog();
};
