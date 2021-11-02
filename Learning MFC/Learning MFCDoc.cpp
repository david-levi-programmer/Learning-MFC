#include "framework.h"
#ifndef SHARED_HANDLERS
#include "Learning MFC.h"
#endif
#include "Learning MFCDoc.h"
#include <propkey.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CLearningMFCDoc, CDocument)

BEGIN_MESSAGE_MAP(CLearningMFCDoc, CDocument)
END_MESSAGE_MAP()

CLearningMFCDoc::CLearningMFCDoc() noexcept
{
	
}

CLearningMFCDoc::~CLearningMFCDoc()
{

}

BOOL CLearningMFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}

void CLearningMFCDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		
	}
	else
	{
		
	}
}

#ifdef SHARED_HANDLERS

void CLearningMFCDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

void CLearningMFCDoc::InitializeSearchContent()
{
	CString strSearchContent;

	SetSearchContent(strSearchContent);
}

void CLearningMFCDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif 

#ifdef _DEBUG
void CLearningMFCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLearningMFCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif