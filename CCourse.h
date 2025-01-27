﻿#pragma once
#include "afxdialogex.h"


// CCourse 对话框

class CCourse : public CDialogEx
{
	DECLARE_DYNAMIC(CCourse)

public:
	CCourse(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CCourse();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CCourse };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl clist;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	void ListRenew();
};
