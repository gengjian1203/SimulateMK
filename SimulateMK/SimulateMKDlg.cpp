
// SimulateMKDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SimulateMK.h"
#include "SimulateMKDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define TIME_NUM_SHOW 1001
#define TIME_NUM_API 1002
#define TIME_NUM_DM 1003

#define DELAY_POINT 50

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSimulateMKDlg �Ի���

CSimulateMKDlg::CSimulateMKDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSimulateMKDlg::IDD, pParent)
	, m_bM1(FALSE)
	, m_nX1(0)
	, m_nY1(0)
	, m_bC1(FALSE)
	, m_nNum1(0)
	, m_bM2(FALSE)
	, m_nX2(0)
	, m_nY2(0)
	, m_bC2(FALSE)
	, m_nNum2(0)
	, m_bM3(FALSE)
	, m_nX3(0)
	, m_nY3(0)
	, m_bC3(FALSE)
	, m_nNum3(0)
	, m_bM4(FALSE)
	, m_nX4(0)
	, m_nY4(0)
	, m_bC4(FALSE)
	, m_nNum4(0)
	, m_bM5(FALSE)
	, m_nX5(0)
	, m_nY5(0)
	, m_bC5(FALSE)
	, m_nNum5(0)
	, m_nDelay(0)
	, m_bLoop(FALSE)
	, m_strMemAddress(_T(""))
	, m_nMemValue(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimulateMKDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_START, m_btnStart);
	DDX_Control(pDX, IDC_BTN_STOP, m_btnStop);
	DDX_Control(pDX, IDC_BTN_REGSVRDM, m_btnRegsvrdm);
	DDX_Control(pDX, IDC_EDIT_HWND, m_editHwnd);
	DDX_Control(pDX, IDC_EDIT_CLASS, m_editClass);
	DDX_Control(pDX, IDC_EDIT_TITLE, m_editTitle);
	DDX_Control(pDX, IDC_EDIT_DISPLAY, m_editDisplay);
	DDX_Control(pDX, IDC_EDIT_MOUSE, m_editMouse);
	DDX_Control(pDX, IDC_EDIT_KEYPAD, m_editKeypad);
	DDX_Control(pDX, IDC_EDIT_PUBLIC, m_editPublic);
	DDX_Control(pDX, IDC_EDIT_MODE, m_editMode);
	DDX_Control(pDX, IDC_BTN_BIND, m_btnBind);
	DDX_Control(pDX, IDC_BTN_UNBIND, m_btnUnBind);
	DDX_Control(pDX, IDC_BTN_FINDD, m_btnFindD);
	DDX_Control(pDX, IDC_BTN_CAPTURE, m_btnCapture);
	DDX_Control(pDX, IDC_CHECK_DM, m_checkDM);
	DDX_Check(pDX, IDC_CHECK_M1, m_bM1);
	DDX_Text(pDX, IDC_EDIT_X1, m_nX1);
	DDX_Text(pDX, IDC_EDIT_Y1, m_nY1);
	DDX_Check(pDX, IDC_CHECK_C1, m_bC1);
	DDX_Text(pDX, IDC_EDIT_NUM1, m_nNum1);
	DDX_Check(pDX, IDC_CHECK_M2, m_bM2);
	DDX_Text(pDX, IDC_EDIT_X2, m_nX2);
	DDX_Text(pDX, IDC_EDIT_Y2, m_nY2);
	DDX_Check(pDX, IDC_CHECK_C2, m_bC2);
	DDX_Text(pDX, IDC_EDIT_NUM2, m_nNum2);
	DDX_Check(pDX, IDC_CHECK_M3, m_bM3);
	DDX_Text(pDX, IDC_EDIT_X3, m_nX3);
	DDX_Text(pDX, IDC_EDIT_Y3, m_nY3);
	DDX_Check(pDX, IDC_CHECK_C3, m_bC3);
	DDX_Text(pDX, IDC_EDIT_NUM3, m_nNum3);
	DDX_Check(pDX, IDC_CHECK_M4, m_bM4);
	DDX_Text(pDX, IDC_EDIT_X4, m_nX4);
	DDX_Text(pDX, IDC_EDIT_Y4, m_nY4);
	DDX_Check(pDX, IDC_CHECK_C4, m_bC4);
	DDX_Text(pDX, IDC_EDIT_NUM4, m_nNum4);
	DDX_Check(pDX, IDC_CHECK_M5, m_bM5);
	DDX_Text(pDX, IDC_EDIT_X5, m_nX5);
	DDX_Text(pDX, IDC_EDIT_Y5, m_nY5);
	DDX_Check(pDX, IDC_CHECK_C5, m_bC5);
	DDX_Text(pDX, IDC_EDIT_NUM5, m_nNum5);
	DDX_Text(pDX, IDC_EDIT_DELAY, m_nDelay);
	DDX_Check(pDX, IDC_CHECK_LOOP, m_bLoop);
	DDX_Text(pDX, IDC_EDIT_MEM_ADDRESS, m_strMemAddress);
	DDX_Text(pDX, IDC_EDIT_MEM_VALUE, m_nMemValue);
	DDX_Control(pDX, IDC_BTN_MEM_API_READ, m_btnMemAPIRead);
	DDX_Control(pDX, IDC_BTN_MEM_DM_READ, m_btnMemDMRead);
	DDX_Control(pDX, IDC_BTN_MEM_API_WRITE, m_btnMemAPIWrite);
	DDX_Control(pDX, IDC_BTN_MEM_DM_WRITE, m_btnMemDMWrite);
}

BEGIN_MESSAGE_MAP(CSimulateMKDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_MESSAGE(WM_HOTKEY, OnHotKey)
	ON_BN_CLICKED(IDC_BTN_GETPOINT, &CSimulateMKDlg::OnBnClickedBtnGetPoint)
	ON_BN_CLICKED(IDC_BTN_START, &CSimulateMKDlg::OnBnClickedBtnStart)
	ON_BN_CLICKED(IDC_BTN_STOP, &CSimulateMKDlg::OnBnClickedBtnStop)
	ON_BN_CLICKED(IDC_BTN_REGSVRDM, &CSimulateMKDlg::OnBnClickedBtnRegsvrdm)
	ON_BN_CLICKED(IDC_BTN_FINDA, &CSimulateMKDlg::OnBnClickedBtnFinda)
	ON_BN_CLICKED(IDC_BTN_FINDD, &CSimulateMKDlg::OnBnClickedBtnFindd)
	ON_BN_CLICKED(IDC_BTN_BIND, &CSimulateMKDlg::OnBnClickedBtnBind)
	ON_BN_CLICKED(IDC_BTN_UNBIND, &CSimulateMKDlg::OnBnClickedBtnUnbind)
	ON_BN_CLICKED(IDC_BTN_CAPTURE, &CSimulateMKDlg::OnBnClickedBtnCapture)
	ON_BN_CLICKED(IDC_BTN_SHOW, &CSimulateMKDlg::OnBnClickedBtnShow)
	ON_WM_TIMER()

	ON_BN_CLICKED(IDC_BTN_MEM_API_READ, &CSimulateMKDlg::OnBnClickedBtnMemApiRead)
	ON_BN_CLICKED(IDC_BTN_MEM_API_WRITE, &CSimulateMKDlg::OnBnClickedBtnMemApiWrite)
	ON_BN_CLICKED(IDC_BTN_MEM_DM_READ, &CSimulateMKDlg::OnBnClickedBtnMemDmRead)
	ON_BN_CLICKED(IDC_BTN_MEM_DM_WRITE, &CSimulateMKDlg::OnBnClickedBtnMemDmWrite)
END_MESSAGE_MAP()


// CSimulateMKDlg ��Ϣ�������

BOOL CSimulateMKDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	::CoInitialize(NULL);//��ʼ���߳�COM��

	ReadInI();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CSimulateMKDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSimulateMKDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSimulateMKDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int CSimulateMKDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	::RegisterHotKey(GetSafeHwnd(), 1510, MOD_CONTROL, VK_F10);
	::RegisterHotKey(GetSafeHwnd(), 1511, MOD_CONTROL, VK_F11);
	::RegisterHotKey(GetSafeHwnd(), 1512, MOD_CONTROL, VK_F12);

	return 0;
}

void CSimulateMKDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	SaveInI();

	::UnregisterHotKey(GetSafeHwnd(), 1510);
	::UnregisterHotKey(GetSafeHwnd(), 1511);
	::UnregisterHotKey(GetSafeHwnd(), 1512);

	dm.UnBindWindow();
}

// ��Ϣ��Ӧ��д
BOOL CSimulateMKDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}
	if (pMsg->wParam == VK_RETURN)
	{
		return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

// �ȼ���Ϣ��Ӧ����
LRESULT CSimulateMKDlg::OnHotKey(WPARAM wParam, LPARAM lParam)
{
	switch(wParam)
	{
	case 1510:
		{
			OnBnClickedBtnGetPoint();
			break;
		}
	case 1511:
		{
			OnBnClickedBtnStart();
			break;
		}
	case 1512:
		{
			//ʹ�ñ�����ڳ�����ǰ��
			CWnd::SetForegroundWindow();
			OnBnClickedBtnStop();
			break;
		}
	default:
		{
			break;
		}
	}
	return true;
}

void CSimulateMKDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch(nIDEvent)
	{
	case TIME_NUM_SHOW:
		{
			funShow();
			break;
		}
	case TIME_NUM_API:
		{
			funAPISimulate();
			break;
		}
	case TIME_NUM_DM:
		{
			funDMSimulate();
			break;
		}
	default:
		{
			break;
		}
	}
	CDialogEx::OnTimer(nIDEvent);
}

void CSimulateMKDlg::OnBnClickedBtnGetPoint()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	CString strPoint;

	if(m_checkDM.GetCheck())
	{
		VARIANT x, y;

		dm.GetCursorPos(&x, &y);
		strPoint.Format(_T("ȡ��(%d, %d��"), x.intVal, y.intVal);
	}
	else
	{
		CPoint point;

		GetCursorPos(&point);
		strPoint.Format(_T("ȡ��(%d, %d��"), point.x, point.y);
	}
	this->SetDlgItemTextW(IDC_STATIC_POINT, strPoint);

}

void CSimulateMKDlg::OnBnClickedBtnStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_btnStart.IsWindowEnabled())
	{
		this->UpdateData(true);
		m_btnStart.EnableWindow(false);
		m_btnStop.EnableWindow(true);
		//AfxMessageBox(_T("Startttttt"));

		if (m_checkDM.GetCheck())
		{
			SetTimer(TIME_NUM_DM, m_nDelay, NULL);
		}
		else
		{
			SetCursorPos(0, 0);
			SetTimer(TIME_NUM_API, m_nDelay, NULL);
		}
	}
}

void CSimulateMKDlg::OnBnClickedBtnStop()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_btnStop.IsWindowEnabled())
	{
		m_btnStart.EnableWindow(true);
		m_btnStop.EnableWindow(false);
		//AfxMessageBox(_T("stop!!!!!!"));
		KillTimer(TIME_NUM_API);
		KillTimer(TIME_NUM_DM);
	}

}

void CSimulateMKDlg::OnBnClickedBtnRegsvrdm()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	WinExec("regsvr32 dm.dll /s", SW_SHOW);
	dm.CreateDispatch(_T("dm.dmsoft"));
	//MessageBox(dm.Ver(), _T(""), MB_OK);
	if ("" == dm.Ver())
	{
		this->SetDlgItemTextW(IDC_STATIC_DMVER, _T("��"));
		return;
	}
	else
	{
		this->SetDlgItemTextW(IDC_STATIC_DMVER, dm.Ver());
	}
	// �ؼ�����
	m_btnRegsvrdm.EnableWindow(false);
	m_editHwnd.EnableWindow(true);
	m_editClass.EnableWindow(true);
	m_editTitle.EnableWindow(true);
	m_editDisplay.EnableWindow(true);
	m_editMouse.EnableWindow(true);
	m_editKeypad.EnableWindow(true);
	m_editPublic.EnableWindow(true);
	m_editMode.EnableWindow(true);
	m_btnBind.EnableWindow(true);
	m_btnFindD.EnableWindow(true);
	m_btnCapture.EnableWindow(true);
	m_checkDM.EnableWindow(true);
	m_btnMemDMRead.EnableWindow(true);
	m_btnMemDMWrite.EnableWindow(true);
}

void CSimulateMKDlg::OnBnClickedBtnFinda()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hWnd;
	CString strClass,strTitle,strHwnd;
	
	m_editClass.GetWindowTextW(strClass);
	m_editTitle.GetWindowTextW(strTitle);
	hWnd = ::FindWindowW(strClass, strTitle);
	strHwnd.Format(_T("%d"), hWnd);
	m_editHwnd.SetWindowTextW(strHwnd);

}

void CSimulateMKDlg::OnBnClickedBtnFindd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	long hWnd;
	CString strClass,strTitle,strHwnd;
	
	m_editClass.GetWindowTextW(strClass);
	m_editTitle.GetWindowTextW(strTitle);
	hWnd = dm.FindWindowW(strClass, strTitle);
	strHwnd.Format(_T("%d"), hWnd);
	m_editHwnd.SetWindowTextW(strHwnd);
}


void CSimulateMKDlg::OnBnClickedBtnBind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strHwnd, strDisplay, strMouse, strKeypad, strPublic, strMode;

	m_editHwnd.GetWindowTextW(strHwnd);
	m_editDisplay.GetWindowTextW(strDisplay);
	m_editMouse.GetWindowTextW(strMouse);
	m_editKeypad.GetWindowTextW(strKeypad);
	m_editPublic.GetWindowTextW(strPublic);
	m_editMode.GetWindowTextW(strMode);

	if ("" == strPublic)
	{
		int dm_ret = dm.BindWindow(_ttoi(strHwnd.GetBuffer()), strDisplay, strMouse, strKeypad, _ttoi(strMode.GetBuffer()));
		if (dm_ret)
		{
			m_btnBind.EnableWindow(false);
			m_btnUnBind.EnableWindow(true);
			m_checkDM.EnableWindow(true);
			this->SetDlgItemTextW(IDC_STATIC_BIND, _T("�Ѱ�"));
		}
		else
		{
			this->SetDlgItemTextW(IDC_STATIC_BIND, _T("��ʧ��"));
		}
	}
	else
	{
		int dm_ret = dm.BindWindowEx(_ttoi(strHwnd.GetBuffer()), strDisplay, strMouse, strKeypad, strPublic, _ttoi(strMode.GetBuffer()));
		if (dm_ret)
		{
			m_btnBind.EnableWindow(false);
			m_btnUnBind.EnableWindow(true);
			m_checkDM.EnableWindow(true);
			this->SetDlgItemTextW(IDC_STATIC_BIND, _T("Ex�Ѱ�"));
		}
		else
		{
			this->SetDlgItemTextW(IDC_STATIC_BIND, _T("��ʧ��"));
		}
	}

}

void CSimulateMKDlg::OnBnClickedBtnUnbind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->SetDlgItemTextW(IDC_STATIC_BIND, _T("δ��"));
	m_btnBind.EnableWindow(true);
	m_btnUnBind.EnableWindow(false);
	m_checkDM.EnableWindow(false);
	m_checkDM.SetCheck(0);
	dm.UnBindWindow();
}

void CSimulateMKDlg::OnBnClickedBtnCapture()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int dm_ret = dm.CapturePng(0, 0, 1024, 768, _T("Test.png"));
	if (dm_ret)
	{
		AfxMessageBox(_T("��ͼ�ɹ�������ΪTest.png"));
	}
	else
	{
		AfxMessageBox(_T("��ͼʧ��"));
	}
}


void CSimulateMKDlg::OnBnClickedBtnShow()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strShow;
	this->UpdateData(true);

	this->GetDlgItemTextW(IDC_BTN_SHOW, strShow);
	// ��ȡhdc
	int nHwnd;
	CString strHwnd;
	m_editHwnd.GetWindowTextW(strHwnd);
	nHwnd = _ttoi(strHwnd.GetBuffer());
	HDC hdc = ::GetDC((HWND)nHwnd);

	if (_T("Ԥ") == strShow)
	{
		this->SetDlgItemTextW(IDC_BTN_SHOW, _T("ͣ"));
		penMove = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
		penClick = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
		//penOld = SelectObject(hdc, penMove);
		funShowText();

		SetTimer(TIME_NUM_SHOW, 100, NULL);
	}
	else
	{
		this->SetDlgItemTextW(IDC_BTN_SHOW, _T("Ԥ"));
		::ReleaseDC((HWND)nHwnd, hdc);

		KillTimer(TIME_NUM_SHOW);
	}
	
}

void CSimulateMKDlg::SaveInI(void)
{
	this->UpdateData(true);
	CString const strPath(".//Set.ini");
	CString strTmp;

	strTmp.Format(_T("%d"), m_bM1);
	::WritePrivateProfileStringW(_T("STEP"), _T("MOVE1"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_nX1);
	::WritePrivateProfileStringW(_T("STEP"), _T("X1"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_nY1);
	::WritePrivateProfileStringW(_T("STEP"), _T("Y1"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_bC1);
	::WritePrivateProfileStringW(_T("STEP"), _T("CLICK1"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_nNum1);
	::WritePrivateProfileStringW(_T("STEP"), _T("NUM1"), strTmp, strPath);

	strTmp.Format(_T("%d"), m_bM2);
	::WritePrivateProfileStringW(_T("STEP"), _T("MOVE2"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_nX2);
	::WritePrivateProfileStringW(_T("STEP"), _T("X2"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_nY2);
	::WritePrivateProfileStringW(_T("STEP"), _T("Y2"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_bC2);
	::WritePrivateProfileStringW(_T("STEP"), _T("CLICK2"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_nNum2);
	::WritePrivateProfileStringW(_T("STEP"), _T("NUM2"), strTmp, strPath);

	strTmp.Format(_T("%d"), m_bM3);
	::WritePrivateProfileStringW(_T("STEP"), _T("MOVE3"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_nX3);
	::WritePrivateProfileStringW(_T("STEP"), _T("X3"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_nY3);
	::WritePrivateProfileStringW(_T("STEP"), _T("Y3"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_bC3);
	::WritePrivateProfileStringW(_T("STEP"), _T("CLICK3"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_nNum3);
	::WritePrivateProfileStringW(_T("STEP"), _T("NUM3"), strTmp, strPath);

	strTmp.Format(_T("%d"), m_bM4);
	::WritePrivateProfileStringW(_T("STEP"), _T("MOVE4"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_nX4);
	::WritePrivateProfileStringW(_T("STEP"), _T("X4"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_nY4);
	::WritePrivateProfileStringW(_T("STEP"), _T("Y4"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_bC4);
	::WritePrivateProfileStringW(_T("STEP"), _T("CLICK4"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_nNum4);
	::WritePrivateProfileStringW(_T("STEP"), _T("NUM4"), strTmp, strPath);

	strTmp.Format(_T("%d"), m_bM5);
	::WritePrivateProfileStringW(_T("STEP"), _T("MOVE5"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_nX5);
	::WritePrivateProfileStringW(_T("STEP"), _T("X5"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_nY5);
	::WritePrivateProfileStringW(_T("STEP"), _T("Y5"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_bC5);
	::WritePrivateProfileStringW(_T("STEP"), _T("CLICK5"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_nNum5);
	::WritePrivateProfileStringW(_T("STEP"), _T("NUM5"), strTmp, strPath);

	strTmp.Format(_T("%d"), m_nDelay);
	::WritePrivateProfileStringW(_T("STEP"), _T("DELAY"), strTmp, strPath);
	strTmp.Format(_T("%d"), m_bLoop);
	::WritePrivateProfileStringW(_T("STEP"), _T("LOOP"), strTmp, strPath);

	m_editDisplay.GetWindowTextW(strTmp);
	::WritePrivateProfileStringW(_T("DM"), _T("DISPLAY"), strTmp, strPath);
	m_editMouse.GetWindowTextW(strTmp);
	::WritePrivateProfileStringW(_T("DM"), _T("MOUSE"), strTmp, strPath);
	m_editKeypad.GetWindowTextW(strTmp);
	::WritePrivateProfileStringW(_T("DM"), _T("KEYPAD"), strTmp, strPath);
	m_editPublic.GetWindowTextW(strTmp);
	::WritePrivateProfileStringW(_T("DM"), _T("PUBLIC"), strTmp, strPath);
	m_editMode.GetWindowTextW(strTmp);
	::WritePrivateProfileStringW(_T("DM"), _T("MODE"), strTmp, strPath);
}

void CSimulateMKDlg::ReadInI(void)
{
	CString const strPath(".//Set.ini");
	CString strTmp;

	m_bM1 = ::GetPrivateProfileInt(_T("STEP"), _T("MOVE1"), 0, strPath);
	m_nX1 = ::GetPrivateProfileInt(_T("STEP"), _T("X1"), 0, strPath);
	m_nY1 = ::GetPrivateProfileInt(_T("STEP"), _T("Y1"), 0, strPath);
	m_bC1 = ::GetPrivateProfileInt(_T("STEP"), _T("CLICK1"), 0, strPath);
	m_nNum1 = ::GetPrivateProfileInt(_T("STEP"), _T("NUM1"), 0, strPath);

	m_bM2 = ::GetPrivateProfileInt(_T("STEP"), _T("MOVE2"), 0, strPath);
	m_nX2 = ::GetPrivateProfileInt(_T("STEP"), _T("X2"), 0, strPath);
	m_nY2 = ::GetPrivateProfileInt(_T("STEP"), _T("Y2"), 0, strPath);
	m_bC2 = ::GetPrivateProfileInt(_T("STEP"), _T("CLICK2"), 0, strPath);
	m_nNum2 = ::GetPrivateProfileInt(_T("STEP"), _T("NUM2"), 0, strPath);

	m_bM3 = ::GetPrivateProfileInt(_T("STEP"), _T("MOVE3"), 0, strPath);
	m_nX3 = ::GetPrivateProfileInt(_T("STEP"), _T("X3"), 0, strPath);
	m_nY3 = ::GetPrivateProfileInt(_T("STEP"), _T("Y3"), 0, strPath);
	m_bC3 = ::GetPrivateProfileInt(_T("STEP"), _T("CLICK3"), 0, strPath);
	m_nNum3 = ::GetPrivateProfileInt(_T("STEP"), _T("NUM3"), 0, strPath);

	m_bM4 = ::GetPrivateProfileInt(_T("STEP"), _T("MOVE4"), 0, strPath);
	m_nX4 = ::GetPrivateProfileInt(_T("STEP"), _T("X4"), 0, strPath);
	m_nY4 = ::GetPrivateProfileInt(_T("STEP"), _T("Y4"), 0, strPath);
	m_bC4 = ::GetPrivateProfileInt(_T("STEP"), _T("CLICK4"), 0, strPath);
	m_nNum4 = ::GetPrivateProfileInt(_T("STEP"), _T("NUM4"), 0, strPath);

	m_bM5 = ::GetPrivateProfileInt(_T("STEP"), _T("MOVE5"), 0, strPath);
	m_nX5 = ::GetPrivateProfileInt(_T("STEP"), _T("X5"), 0, strPath);
	m_nY5 = ::GetPrivateProfileInt(_T("STEP"), _T("Y5"), 0, strPath);
	m_bC5 = ::GetPrivateProfileInt(_T("STEP"), _T("CLICK5"), 0, strPath);
	m_nNum5 = ::GetPrivateProfileInt(_T("STEP"), _T("NUM5"), 0, strPath);

	m_nDelay = ::GetPrivateProfileInt(_T("STEP"), _T("DELAY"), 0, strPath);
	m_bLoop = ::GetPrivateProfileInt(_T("STEP"), _T("LOOP"), 0, strPath);

	::GetPrivateProfileStringW(_T("DM"), _T("DISPLAY"), _T(""), strTmp.GetBuffer(256), 256, strPath);
	strTmp.ReleaseBuffer();
	m_editDisplay.SetWindowTextW(strTmp);
	::GetPrivateProfileStringW(_T("DM"), _T("MOUSE"), _T(""), strTmp.GetBuffer(256), 256, strPath);
	strTmp.ReleaseBuffer();
	m_editMouse.SetWindowTextW(strTmp);
	::GetPrivateProfileStringW(_T("DM"), _T("KEYPAD"), _T(""), strTmp.GetBuffer(256), 256, strPath);
	strTmp.ReleaseBuffer();
	m_editKeypad.SetWindowTextW(strTmp);
	::GetPrivateProfileStringW(_T("DM"), _T("PUBLIC"), _T(""), strTmp.GetBuffer(256), 256, strPath);
	strTmp.ReleaseBuffer();
	m_editPublic.SetWindowTextW(strTmp.GetBuffer());
	::GetPrivateProfileStringW(_T("DM"), _T("MODE"), _T(""), strTmp.GetBuffer(256), 256, strPath);
	strTmp.ReleaseBuffer();
	m_editMode.SetWindowTextW(strTmp);

	this->UpdateData(false);
}

void CSimulateMKDlg::funShowText(void)
{
	CString strSum("");
	CString strTmp("");

	// �������·��
	if (m_bM1)
	{
		strTmp.Format(_T("�ƶ���(%d, %d)\n"), m_nX1, m_nY1);
		strSum+=strTmp;
		if (m_bC1)
		{
			strTmp.Format(_T("������%d��\n"), m_nNum1);
			strSum+=strTmp;
		}
	}

	if (m_bM2)
	{
		strTmp.Format(_T("�ƶ���(%d, %d)\n"), m_nX2, m_nY2);
		strSum+=strTmp;
		if (m_bC2)
		{
			strTmp.Format(_T("������%d��\n"), m_nNum2);
			strSum+=strTmp;
		}
	}

	if (m_bM3)
	{
		strTmp.Format(_T("�ƶ���(%d, %d)\n"), m_nX3, m_nY3);
		strSum+=strTmp;
		if (m_bC3)
		{
			strTmp.Format(_T("������%d��\n"), m_nNum3);
			strSum+=strTmp;
		}
	}

	if (m_bM4)
	{
		strTmp.Format(_T("�ƶ���(%d, %d)\n"), m_nX4, m_nY4);
		strSum+=strTmp;
		if (m_bC4)
		{
			strTmp.Format(_T("������%d��\n"), m_nNum4);
			strSum+=strTmp;
		}
	}

	if (m_bM5)
	{
		strTmp.Format(_T("�ƶ���(%d, %d)\n"), m_nX5, m_nY5);
		strSum+=strTmp;
		if (m_bC5)
		{
			strTmp.Format(_T("������%d��\n"), m_nNum5);
			strSum+=strTmp;
		}
	}

	if (m_bLoop)
	{
		strTmp.Format(_T("===ѭ��==="));
	}
	else
	{
		strTmp.Format(_T("===ֹͣ==="));
	}

	strSum+=strTmp;

	this->SetDlgItemTextW(IDC_STATIC_SHOW, strSum);
}

void CSimulateMKDlg::DrawPoint(HDC hdc, int nCount, int nX, int nY, BOOL bC)
{
	CString strTmp;
	SelectObject(hdc, penMove);
	Rectangle(hdc, nX - 6, nY - 6, nX + 6, nY + 6);
	if (bC)
	{
		SelectObject(hdc, penClick);
		Ellipse(hdc, nX - 6, nY - 6, nX + 6, nY + 6);
	}
	strTmp.Format(_T("%d"), nCount);
	TextOutW(hdc, nX - 3, nY - 5, strTmp, 1);

}

void CSimulateMKDlg::funShow(void)
{
	//this->UpdateData(true);
	// ��ȡhdc
	int nHwnd;
	CString strHwnd;
	m_editHwnd.GetWindowTextW(strHwnd);
	nHwnd = _ttoi(strHwnd.GetBuffer());
	HDC hdc = ::GetDC((HWND)nHwnd);

	CFont font;
	int nTmp = 1;
	font.CreatePointFont(85, _T("����"));
	SelectObject(hdc, font);
	SetBkMode(hdc, TRANSPARENT);
	
	// �������·��
	if (m_bM1)
	{
		DrawPoint(hdc, nTmp, m_nX1, m_nY1, m_bC1);
		nTmp++;
	}

	if (m_bM2)
	{
		DrawPoint(hdc, nTmp, m_nX2, m_nY2, m_bC2);
		nTmp++;
	}

	if (m_bM3)
	{
		DrawPoint(hdc, nTmp, m_nX3, m_nY3, m_bC3);
		nTmp++;
	}

	if (m_bM4)
	{
		DrawPoint(hdc, nTmp, m_nX4, m_nY4, m_bC4);
		nTmp++;
	}

	if (m_bM5)
	{
		DrawPoint(hdc, nTmp, m_nX5, m_nY5, m_bC5);
		nTmp++;
	}
}

void CSimulateMKDlg::funAPIOnePoint(int nX, int nY, BOOL bC, int nNum)
{
	SetCursorPos(nX, nY);
	Sleep(DELAY_POINT);
	if (bC)
	{
		while(nNum > 0)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, nX, nY, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, nX, nY, 0, 0);
			nNum--;
			Sleep(DELAY_POINT);
		}
	}
}

void CSimulateMKDlg::funAPISimulate(void)
{
	// MOUSEEVENTF_ABSOLUTE  �������  MOUSEEVENTF_MOVE
	if (m_bM1)
	{
		funAPIOnePoint(m_nX1, m_nY1, m_bC1, m_nNum1);
	}
	if (m_bM2)
	{
		funAPIOnePoint(m_nX2, m_nY2, m_bC2, m_nNum2);
	}
	if (m_bM3)
	{
		funAPIOnePoint(m_nX3, m_nY3, m_bC3, m_nNum3);
	}
	if (m_bM4)
	{
		funAPIOnePoint(m_nX4, m_nY4, m_bC4, m_nNum4);
	}
	if (m_bM5)
	{
		funAPIOnePoint(m_nX5, m_nY5, m_bC5, m_nNum5);
	}

	if (!m_bLoop)
	{
		OnBnClickedBtnStop();
	}
}

void CSimulateMKDlg::funDMOnePoint(int nX, int nY, BOOL bC, int nNum)
{
	dm.MoveTo(nX, nY);
	Sleep(DELAY_POINT);
	if (bC)
	{
		while(nNum > 0)
		{
			dm.LeftClick();
			nNum--;
			Sleep(DELAY_POINT);
		}
	}
}


void CSimulateMKDlg::funDMSimulate(void)
{
	if (m_bM1)
	{
		funDMOnePoint(m_nX1, m_nY1, m_bC1, m_nNum1);
	}
	if (m_bM2)
	{
		funDMOnePoint(m_nX2, m_nY2, m_bC2, m_nNum2);
	}
	if (m_bM3)
	{
		funDMOnePoint(m_nX3, m_nY3, m_bC3, m_nNum3);
	}
	if (m_bM4)
	{
		funDMOnePoint(m_nX4, m_nY4, m_bC4, m_nNum4);
	}
	if (m_bM5)
	{
		funDMOnePoint(m_nX5, m_nY5, m_bC5, m_nNum5);
	}

	if (!m_bLoop)
	{
		OnBnClickedBtnStop();
	}
}

void CSimulateMKDlg::OnBnClickedBtnMemApiRead()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

}

void CSimulateMKDlg::OnBnClickedBtnMemApiWrite()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CSimulateMKDlg::OnBnClickedBtnMemDmRead()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strHwnd;
	this->UpdateData(true);
	m_editHwnd.GetWindowTextW(strHwnd);
	m_nMemValue = dm.ReadInt(_ttoi(strHwnd.GetBuffer()), m_strMemAddress, 0);
	this->UpdateData(false);
}

void CSimulateMKDlg::OnBnClickedBtnMemDmWrite()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strHwnd;
	this->UpdateData(true);
	m_editHwnd.GetWindowTextW(strHwnd);
	if ( dm.WriteInt(_ttoi(strHwnd.GetBuffer()), m_strMemAddress, 0, m_nMemValue) )
	{
		AfxMessageBox(_T("д��8λ���ݳɹ���"));
	}
	else
	{
		AfxMessageBox(_T("д��ʧ�ܣ�"));
	}
}
