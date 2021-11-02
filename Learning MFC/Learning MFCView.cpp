#include "framework.h"
#ifndef SHARED_HANDLERS
#include "Learning MFC.h"
#endif

#include "About.h"
#include "Learning MFCDoc.h"
#include "Learning MFCView.h"
#include "Screen.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CLearningMFCView, CView)

BEGIN_MESSAGE_MAP(CLearningMFCView, CView)
	
	ON_COMMAND(ID_APP_ABOUT, &CLearningMFCView::OnAppAbout)
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_APP_EXIT, &CLearningMFCView::OnAppExit)

	ON_WM_CREATE()
	ON_WM_SIZE()

END_MESSAGE_MAP()

CLearningMFCView::CLearningMFCView() noexcept
{
	
}

CLearningMFCView::~CLearningMFCView()
{

}

BOOL CLearningMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

void CLearningMFCView::OnAppAbout()
{
	About aboutBox;
	aboutBox.DoModal();
}

void CLearningMFCView::OnAppExit()
{
	auto result = MessageBox(L"Are you sure you want to exit?",
		L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
	if (result == IDYES)
	{
		OnDestroy();
		PostQuitMessage(0);
	}
}

void CLearningMFCView::OnDraw(CDC* /*pDC*/)
{
	CLearningMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	Screen::Instance()->Refresh();
	Screen::Instance()->Present();

}

int CLearningMFCView::OnCreate(LPCREATESTRUCT lpcs)
{
	if (CView::OnCreate(lpcs) == -1)
	{
		return -1;
	}

	if (Screen::Instance()->Initialize(GetSafeHwnd()))
	{
		return -1;
	}

	ModifyStyleEx(WS_EX_CLIENTEDGE, 0);

	return 1;
}

void CLearningMFCView::OnSize(UINT nType, int width, int height)
{
	Screen::Instance()->SetViewport(0, 0, width, height);
}


BOOL CLearningMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	return DoPreparePrinting(pInfo);
}

void CLearningMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	
}

void CLearningMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	
}

#ifdef _DEBUG
void CLearningMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CLearningMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLearningMFCDoc* CLearningMFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLearningMFCDoc)));
	return (CLearningMFCDoc*)m_pDocument;
}
#endif