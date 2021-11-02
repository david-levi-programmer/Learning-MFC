#pragma once

class CLearningMFCView : public CView
{
public:
	CLearningMFCDoc* GetDocument() const;

	virtual void OnDraw(CDC* pDC);
	virtual int OnCreate(LPCREATESTRUCT lpcs);
	virtual void OnSize(UINT nType, int width, int height);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);	
	
	afx_msg void OnAppAbout();
	void OnAppExit();

	virtual ~CLearningMFCView();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CLearningMFCView() noexcept;
	DECLARE_DYNCREATE(CLearningMFCView)
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	DECLARE_MESSAGE_MAP()

};

#ifndef _DEBUG 
inline CLearningMFCDoc* CLearningMFCView::GetDocument() const
   { return reinterpret_cast<CLearningMFCDoc*>(m_pDocument); }
#endif