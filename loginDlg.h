
// loginDlg.h: 헤더 파일
//

#pragma once


// CloginDlg 대화 상자
class CloginDlg : public CDialogEx
{
// 생성입니다.
public:
	CloginDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_idEdit;
	CString m_id;
	CString m_pw;
	virtual void OnOK();
//	virtual void OnCancel();
	afx_msg void OnBnClickedButton1();
	CEdit m_pwEdit;
	virtual void OnCancel();
	CBitmapButton m_danddo;
	CBitmapButton m_danddo123;
};
