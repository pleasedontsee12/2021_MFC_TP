#pragma once


// pickpay 대화 상자

class pickpay : public CDialogEx
{
	DECLARE_DYNAMIC(pickpay)

public:
	pickpay(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~pickpay();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_E_PICKPAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton4();
	virtual BOOL OnInitDialog();

	CString dishname1[10];
	CString dishname2[10];
	CString dishname3[10];
	CString dishname4[10];
	CString dishname5[10];
	CString dishname6[10];
	
	UINT dishprice1[10];
	UINT dishprice2[10];
	UINT dishprice3[10];
	UINT dishprice4[10];
	UINT dishprice5[10];
	UINT dishprice6[10];
	
	UINT quantity1[10];
	UINT quantity2[10];
	UINT quantity3[10];
	UINT quantity4[10];
	UINT quantity5[10];
	UINT quantity6[10];
	
	UINT menucount1;
	UINT menucount2;
	UINT menucount3;
	UINT menucount4;
	UINT menucount5;
	UINT menucount6;

	CString paydialogmenu[10][10];
	CString paydialogprice[10][10];
	CString paydialogquantity[10][10];
};
