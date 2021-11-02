#include "About.h"
#include "Resource.h"

BEGIN_MESSAGE_MAP(About, CDialogEx)

	

END_MESSAGE_MAP()

About::About() noexcept : CDialogEx(IDD_ABOUTBOX) {}

void About::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}