
// Practice6aView.cpp: CPractice6aView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Practice6a.h"
#endif

#include "Practice6aDoc.h"
#include "Practice6aView.h"
#include "MainFrm.h";

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice6aView

IMPLEMENT_DYNCREATE(CPractice6aView, CView)

BEGIN_MESSAGE_MAP(CPractice6aView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPractice6aView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_LINE, &CPractice6aView::OnLine)
	ON_COMMAND(ID_ELLIPSE, &CPractice6aView::OnEllipse)
	ON_COMMAND(ID_BEZIER, &CPractice6aView::OnBezier)
	ON_COMMAND(ID_LINE_COLOR, &CPractice6aView::OnLineColor)
	ON_COMMAND(ID_FACE_COLOR, &CPractice6aView::OnFaceColor)
	ON_COMMAND(ID_FDIAGONAL, &CPractice6aView::OnFdiagonal)
	ON_COMMAND(ID_CROSS, &CPractice6aView::OnCross)
	ON_COMMAND(ID_VERTICAL, &CPractice6aView::OnVertical)
	ON_UPDATE_COMMAND_UI(ID_LINE, &CPractice6aView::OnUpdateLine)
	ON_UPDATE_COMMAND_UI(ID_ELLIPSE, &CPractice6aView::OnUpdateEllipse)
	ON_UPDATE_COMMAND_UI(ID_BEZIER, &CPractice6aView::OnUpdateBezier)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CPractice6aView 생성/소멸

CPractice6aView::CPractice6aView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPractice6aView::~CPractice6aView()
{
}

BOOL CPractice6aView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPractice6aView 그리기

void CPractice6aView::OnDraw(CDC* /*pDC*/)
{
	CPractice6aDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CPractice6aView 인쇄


void CPractice6aView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPractice6aView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPractice6aView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPractice6aView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CPractice6aView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice6aView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPractice6aView 진단

#ifdef _DEBUG
void CPractice6aView::AssertValid() const
{
	CView::AssertValid();
}

void CPractice6aView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice6aDoc* CPractice6aView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice6aDoc)));
	return (CPractice6aDoc*)m_pDocument;
}
#endif //_DEBUG


// CPractice6aView 메시지 처리기


void CPractice6aView::OnLine()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nDrawMode = LINE_MODE;
}


void CPractice6aView::OnEllipse()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nDrawMode = ELLIPSE_MODE;
}


void CPractice6aView::OnBezier()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nDrawMode = BEZIER_MODE;
}


void CPractice6aView::OnLineColor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	AfxMessageBox(_T("선의 색상을 변경합니다"));
	
}


void CPractice6aView::OnFaceColor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	AfxMessageBox(_T("면의 색상을 변경합니다"));
	
}


void CPractice6aView::OnFdiagonal()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nHatchStyle = HS_FDIAGONAL;
}


void CPractice6aView::OnCross()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nHatchStyle = HS_CROSS;
}


void CPractice6aView::OnVertical()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nHatchStyle = HS_VERTICAL;
}


void CPractice6aView::OnUpdateLine(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_nDrawMode == LINE_MODE ? 1 : 0);
}


void CPractice6aView::OnUpdateEllipse(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_nDrawMode == ELLIPSE_MODE ? 1 : 0);
}


void CPractice6aView::OnUpdateBezier(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_nDrawMode == BEZIER_MODE ? 1 : 0);
}


void CPractice6aView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	// 메인프레임의 포인터 얻음
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

	CString strPoint;
	strPoint.Format(_T("마우스 위치 x: %d, y: %d"), point.x, point.y);

	// 새로 추가한 팬에 마우스 위치 출력
	pFrame->m_wndStatusBar.SetPaneText(1, strPoint);

	CView::OnMouseMove(nFlags, point);
}
