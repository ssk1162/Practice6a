
// Practice6aView.h: CPractice6aView 클래스의 인터페이스
//
enum DRAW_MODE { LINE_MODE, ELLIPSE_MODE, BEZIER_MODE };
#pragma once


class CPractice6aView : public CView
{
protected: // serialization에서만 만들어집니다.
	CPractice6aView() noexcept;
	DECLARE_DYNCREATE(CPractice6aView)

// 특성입니다.
public:
	CPractice6aDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CPractice6aView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLine();
	afx_msg void OnEllipse();
	afx_msg void OnBezier();
	afx_msg void OnLineColor();
	afx_msg void OnFaceColor();
	afx_msg void OnFdiagonal();
	afx_msg void OnCross();
	afx_msg void OnVertical();
	int m_nDrawMode;
	int m_nHatchStyle;
	afx_msg void OnUpdateLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEllipse(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBezier(CCmdUI* pCmdUI);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Practice6aView.cpp의 디버그 버전
inline CPractice6aDoc* CPractice6aView::GetDocument() const
   { return reinterpret_cast<CPractice6aDoc*>(m_pDocument); }
#endif

