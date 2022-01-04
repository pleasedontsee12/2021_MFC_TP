#pragma once


// menu 대화 상자

class menu : public CDialogEx
{
	DECLARE_DYNAMIC(menu)

public:
	menu(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~menu();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_D_MENU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_orderlist;
	CEdit m_totalprice;
	virtual BOOL OnInitDialog();
	CButton m_menu01;
	CButton m_menu02;
	CButton m_menu03;
	CButton m_menu04;
	CButton m_menu05;
	CButton m_menu06;
	CButton m_menu07;
	CButton m_menu08;
	CButton m_menu09;
	CButton m_menu10;
	UINT m_UtotalPrice = 0;
	UINT m_ttp = 0;
	BOOL m_bExistDish;	
	UINT menutablenum = 0;
	CString m_StringtotalPrice;
	CString tablemenu1;
	CString tablemenu2;
	CString tablemenu3;
	CString tablemenu4;
	CString tablemenu5;
	CString tablemenu6;
	CString tablemenu7;
	CString tablemenu8;
	CString tablemenu9;
	CString tablemenu10;
	CString tablemenu;
	

	CString menudialogmenu[10][10];
	CString menudialogprice[10][10];
	CString menudialogquantity[10][10];
	CString tablecount[10];

	afx_msg void OnBnClickedOrdercheck();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClicked1016();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClicked1014();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClicked1017();
	afx_msg void OnBnClicked1012();
	afx_msg void OnBnClicked1013();
//	afx_msg void OnLvnItemchangedList3(NMHDR* pNMHDR, LRESULT* pResult);
};
