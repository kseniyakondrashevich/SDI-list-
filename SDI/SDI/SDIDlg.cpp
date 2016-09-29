
// SDIDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "SDI.h"
#include "SDIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CSDIDlg



CSDIDlg::CSDIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SDI_DIALOG, pParent)
	, m_uneven(FALSE)
	, m_even(FALSE)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSDIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_UNEVEN, m_uneven);
	DDX_Check(pDX, IDC_EVEN, m_even);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_str);
	DDV_MaxChars(pDX, m_str, 30);
}

BEGIN_MESSAGE_MAP(CSDIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CSDIDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_UNEVEN, &CSDIDlg::OnBnClickedUneven)
	ON_BN_CLICKED(IDC_EVEN, &CSDIDlg::OnBnClickedEven)
	ON_BN_CLICKED(IDC_ADD, &CSDIDlg::OnBnClickedAdd)
	ON_LBN_DBLCLK(IDC_LIST1, &CSDIDlg::OnLbnDblclkList1)
END_MESSAGE_MAP()


// ����������� ��������� CSDIDlg

BOOL CSDIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	m_uneven = 0;
	m_even = 0;

	m_list.AddString(L"������ ������");
	m_list.AddString(L"������ ������");
	m_list.AddString(L"������ ������");
	m_list.AddString(L"��������� ������");
	


	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CSDIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CSDIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CSDIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSDIDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CSDIDlg::OnBnClickedUneven()
{
	// TODO: Add your control notification handler code here
	if (!m_uneven)
	{
		m_uneven = 1;
		if (m_even)
			for (int i = 0; i < m_list.GetCount(); i++)
				m_list.SetSel(i);
		else for (int i = 0; i < m_list.GetCount(); i++)
			m_list.SetSel(i, ((i % 2) == 0));
	}
	else if (m_uneven)
	{
		m_uneven = 0;
		for (int i = 0; i < m_list.GetCount(); i+=2)
			m_list.SetSel(i, 0);
	}
}


void CSDIDlg::OnBnClickedEven()
{
	// TODO: Add your control notification handler code here
	if (!m_even)
	{
		m_even = 1;
		if (m_uneven)
			for (int i = 0; i < m_list.GetCount(); i++)
				m_list.SetSel(i);
		else for (int i = 0; i < m_list.GetCount(); i++)
			m_list.SetSel(i, ((i % 2) != 0));
	}
	else if (m_even)
	{
		m_even = 0;
		for (int i = 1; i < m_list.GetCount(); i+=2)
			m_list.SetSel(i, 0);
	}
}


void CSDIDlg::OnBnClickedAdd()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_list.AddString(m_str);
	m_str = "";
	UpdateData(FALSE);
}


void CSDIDlg::OnLbnDblclkList1()
{
	// TODO: Add your control notification handler code here
	m_list.DeleteString(m_list.GetCaretIndex());
}
