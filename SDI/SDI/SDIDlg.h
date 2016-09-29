
// SDIDlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"
#include "afxcoll.h"


// диалоговое окно CSDIDlg
class CSDIDlg : public CDialogEx
{
// Создание
public:
	CSDIDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SDI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
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
