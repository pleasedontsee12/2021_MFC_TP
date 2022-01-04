#pragma once


// salesanalysis 대화 상자

class salesanalysis : public CDialogEx
{
	DECLARE_DYNAMIC(salesanalysis)

public:
	salesanalysis(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~salesanalysis();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_G_salesanalysis };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_analysisListCtrl;
};
