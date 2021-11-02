#pragma once
#include <afxdialogex.h>

class About : public CDialogEx
{
	public:

		About() noexcept;


	protected:
		virtual void DoDataExchange(CDataExchange* pDX);
		
		DECLARE_MESSAGE_MAP()

};