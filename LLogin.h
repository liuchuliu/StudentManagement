#pragma once
#include "afxdialogex.h"


// LLogin 对话框

class LLogin : public CDialogEx
{
	DECLARE_DYNAMIC(LLogin)

public:
	LLogin(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LLogin();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LLogin };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString job;
	CString nname;
	CString idi;
	CString mpassword;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
