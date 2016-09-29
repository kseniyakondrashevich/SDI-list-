
// SDIDlg.h : ���� ���������
//

#pragma once
#include "afxwin.h"
#include "afxcoll.h"


// ���������� ���� CSDIDlg
class CSDIDlg : public CDialogEx
{
// ��������
public:
	CSDIDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SDI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	BOOL m_uneven;
	BOOL m_even;
	CListBox m_list;
	CStringArray m_selected;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedUneven();
	afx_msg void OnBnClickedEven();
	CString m_str;
	afx_msg void OnBnClickedAdd();
	afx_msg void OnLbnDblclkList1();
};
