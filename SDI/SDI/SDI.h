
// SDI.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������
#include "SDIDlg.h"

// CSDIApp:
// � ���������� ������� ������ ��. SDI.cpp
//

class CSDIApp : public CWinApp
{
public:
	CSDIApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CSDIApp theApp;