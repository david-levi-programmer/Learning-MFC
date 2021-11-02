#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       

class CLearningMFCApp : public CWinApp
{
public:
	CLearningMFCApp() noexcept;
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CLearningMFCApp theApp;