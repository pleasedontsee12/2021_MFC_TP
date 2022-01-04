#pragma once


// table 대화 상자
class pickpay;
class table : public CDialogEx
{
	DECLARE_DYNAMIC(table)

public:
	table(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~table();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_C_TABLE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedPayment();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedPayment2();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedPayment3();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedPayment4();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedPayment5();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedPayment6();
	CMFCButton m_table1;
	CMFCButton m_table2;
	CMFCButton m_table3;
	CMFCButton m_table4;
	CMFCButton m_table5;
	CMFCButton m_table6;
	CBitmapButton m_table1pay;
	CBitmapButton m_table2pay;
	CBitmapButton m_table3pay;
	CBitmapButton m_table4pay;
	CBitmapButton m_table5pay;
	CBitmapButton m_table6pay;
	int tablenum = 0;
	BOOL paysuccess = FALSE;
	void Delete();
	virtual BOOL OnInitDialog();
	CBitmapButton m_danddobtn;
	CBitmapButton m_danddobtn2;

	CString mtest[10][10];
	CString qtest[10][10];
	CString ptest[10][10];
	CString menucount[10];
};
