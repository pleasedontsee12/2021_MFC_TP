#pragma once


// cardpay 대화 상자

class cardpay : public CDialogEx
{
	DECLARE_DYNAMIC(cardpay)

public:
	cardpay(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~cardpay();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_F_CARDPAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCardpayb();
	afx_msg void OnBnClickedCardpayb2();
	CEdit m_cardsum;
	CEdit m_cardcheck;
	virtual BOOL OnInitDialog();
	CString table1paysum;
	int paysuc = 1;
};
