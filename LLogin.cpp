// LLogin.cpp: 实现文件
//

#include "pch.h"
#include "StudentManagement.h"
#include "afxdialogex.h"
#include "LLogin.h"


// LLogin 对话框

IMPLEMENT_DYNAMIC(LLogin, CDialogEx)

LLogin::LLogin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LLogin, pParent)
	, job(_T(""))
	, nname(_T(""))
	, idi(_T(""))
	, mpassword(_T(""))
{

}

LLogin::~LLogin()
{
}

void LLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, job);
	DDX_Text(pDX, IDC_EDIT2, nname);
	DDX_Text(pDX, IDC_EDIT3, idi);
	DDX_Text(pDX, IDC_EDIT4, mpassword);
}


BEGIN_MESSAGE_MAP(LLogin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &LLogin::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &LLogin::OnBnClickedButton2)
END_MESSAGE_MAP()


// LLogin 消息处理程序


void LLogin::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (job == TEXT("") || nname == TEXT("") || idi == TEXT("") || mpassword == TEXT(""))
	{
		MessageBox(TEXT("登录信息不足，请补充"), TEXT("提示"));
	}
	else
	{
		OnOK();
		return;
	}
}


void LLogin::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}
