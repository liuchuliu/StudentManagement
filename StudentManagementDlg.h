﻿
// StudentManagementDlg.h: 头文件
//

#pragma once
#include "InterfaceDesign.h"

// CStudentManagementDlg 对话框
class CStudentManagementDlg : public CDialogEx
{
// 构造
public:
	CStudentManagementDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDENTMANAGEMENT_DIALOG };
#endif

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
public:
	CListCtrl slist;
	CComboBox s_class;
	CComboBox s_course;
	CComboBox s_weighted;
	CFont sfont;
	bool online = false;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton7();
	InterfaceDesign InterD;
	afx_msg void OnBnClickedButton1();
	void ListRenew();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton8();
	CComboBox AorS;
};
