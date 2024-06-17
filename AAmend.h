#pragma once
#include "afxdialogex.h"


// AAmend 对话框

class AAmend : public CDialogEx
{
	DECLARE_DYNAMIC(AAmend)

public:
	AAmend(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AAmend();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AAmend };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString sname;
	CString sgen;
	CString sclasss;
	int ss1;
	int ss2;
	int ss3;
	int ss4;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	int sf1;
	int sf2;
	int sf3;
	int sf4;
};
