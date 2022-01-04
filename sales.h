#pragma once


// sales 대화 상자

class sales : public CDialogEx
{
	DECLARE_DYNAMIC(sales)

public:
	sales(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~sales();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_G_Sales2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEdit m_yearAndMonth;
	CListCtrl m_calendarList;
	afx_msg void OnBnClickedLeft();
	afx_msg void OnBnClickedRight();
	afx_msg void OnBnClickedTablecnt();
	afx_msg void OnBnClickedMonthsales();
	afx_msg void OnBnClickedSalescnt();
	afx_msg void OnDblclk1043(NMHDR* pNMHDR, LRESULT* pResult);
	LPNMITEMACTIVATE m_rowItem;
	UINT pick = 1;
	afx_msg void OnLvnItemchanged1043(NMHDR* pNMHDR, LRESULT* pResult);
};
