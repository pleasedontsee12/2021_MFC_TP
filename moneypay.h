#pragma once


// moneypay 대화 상자

class moneypay : public CDialogEx
{
	DECLARE_DYNAMIC(moneypay)

public:
	moneypay(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~moneypay();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_F_MONEYPAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCardpayb();
	afx_msg void OnBnClickedCardpayb2();
	virtual BOOL OnInitDialog();
};
