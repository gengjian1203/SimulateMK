
// SimulateMKDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "Cdmsoft.h"

// CSimulateMKDlg 对话框
class CSimulateMKDlg : public CDialogEx
{
// 构造
public:
	CSimulateMKDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SIMULATEMK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
// 框架
private:
	// 通用指令组
	BOOL m_bM1;
	int m_nX1;
	int m_nY1;
	BOOL m_bC1;
	int m_nNum1;
	BOOL m_bM2;
	int m_nX2;
	int m_nY2;
	BOOL m_bC2;
	int m_nNum2;
	BOOL m_bM3;
	int m_nX3;
	int m_nY3;
	BOOL m_bC3;
	int m_nNum3;
	BOOL m_bM4;
	int m_nX4;
	int m_nY4;
	BOOL m_bC4;
	int m_nNum4;
	BOOL m_bM5;
	int m_nX5;
	int m_nY5;
	BOOL m_bC5;
	int m_nNum5;
	int m_nDelay;
	BOOL m_bLoop;
	// 指令执行区
	CButton m_btnStart;
	CButton m_btnStop;
	CButton m_btnRegsvrdm;
	CEdit m_editHwnd;
	CEdit m_editClass;
	CEdit m_editTitle;
	CEdit m_editDisplay;
	CEdit m_editMouse;
	CEdit m_editKeypad;
	CEdit m_editPublic;
	CEdit m_editMode;
	CButton m_btnBind;
	CButton m_btnUnBind;
	CButton m_btnFindD;
	CButton m_btnCapture;
	CButton m_checkDM;
	// 内存读写区
	CString m_strMemAddress;
	int m_nMemValue;
	CButton m_btnMemAPIRead;
	CButton m_btnMemDMRead;
	CButton m_btnMemAPIWrite;
	CButton m_btnMemDMWrite;

private:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	// 消息响应重写
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	// 热键消息响应函数
	afx_msg LRESULT OnHotKey(WPARAM wParam, LPARAM lParam);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedBtnGetPoint();
	afx_msg void OnBnClickedBtnStart();
	afx_msg void OnBnClickedBtnStop();
	afx_msg void OnBnClickedBtnRegsvrdm();
	afx_msg void OnBnClickedBtnFinda();
	afx_msg void OnBnClickedBtnFindd();
	afx_msg void OnBnClickedBtnBind();
	afx_msg void OnBnClickedBtnUnbind();
	afx_msg void OnBnClickedBtnCapture();
	afx_msg void OnBnClickedBtnShow();
	afx_msg void OnBnClickedBtnMemApiRead();
	afx_msg void OnBnClickedBtnMemApiWrite();
	afx_msg void OnBnClickedBtnMemDmRead();
	afx_msg void OnBnClickedBtnMemDmWrite();
// 自定义
private:
	Cdmsoft dm;
	HPEN penMove;
	HPEN penClick;
	HPEN penOld;
private:
	void SaveInI(void);
	void ReadInI(void);
	void funShowText(void);
	void DrawPoint(HDC hdc, int nCount, int nX, int nY, BOOL bC);
	void funShow(void);
	void funAPIOnePoint(int nX, int nY, BOOL bC, int nNum);
	void funAPISimulate(void);
	void funDMOnePoint(int nX, int nY, BOOL bC, int nNum);
	void funDMSimulate(void);
public:

};
