#pragma once


// mainmenu 대화 상자

class mainmenu : public CDialogEx
{
	DECLARE_DYNAMIC(mainmenu)

public:
	mainmenu(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~mainmenu();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BB_MENU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	CBitmapButton m_danddo2;
	afx_msg void OnBnClickedButton6();
	CBitmapButton m_danddo3;
	CBitmapButton m_danddo4;
};
