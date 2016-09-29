
// SDI.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы
#include "SDIDlg.h"

// CSDIApp:
// О реализации данного класса см. SDI.cpp
//

class CSDIApp : public CWinApp
{
public:
	CSDIApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CSDIApp theApp;