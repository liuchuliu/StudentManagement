// AAmend.cpp: 实现文件
//

#include "pch.h"
#include "StudentManagement.h"
#include "afxdialogex.h"
#include "AAmend.h"


// AAmend 对话框

IMPLEMENT_DYNAMIC(AAmend, CDialogEx)

AAmend::AAmend(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AAmend, pParent)
	, sname(_T(""))
	, sgen(_T(""))
	, sclasss(_T(""))
	, ss1(0)
	, ss2(0)
	, ss3(0)
	, ss4(0)
	, sf1(0)
	, sf2(0)
	, sf3(0)
	, sf4(0)
{

}

AAmend::~AAmend()
{
}

void AAmend::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, sname);
	DDX_Text(pDX, IDC_EDIT6, sgen);
	DDX_Text(pDX, IDC_EDIT7, sclasss);
	DDX_Text(pDX, IDC_EDIT2, ss1);
	DDX_Text(pDX, IDC_EDIT3, ss2);
	DDX_Text(pDX, IDC_EDIT4, ss3);
	DDX_Text(pDX, IDC_EDIT5, ss4);
	DDX_Text(pDX, IDC_EDIT8, sf1);
	DDX_Text(pDX, IDC_EDIT9, sf2);
	DDX_Text(pDX, IDC_EDIT10, sf3);
	DDX_Text(pDX, IDC_EDIT11, sf4);
}


BEGIN_MESSAGE_MAP(AAmend, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &AAmend::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &AAmend::OnBnClickedButton2)
END_MESSAGE_MAP()


// AAmend 消息处理程序


void AAmend::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	bool f = 0;
	if (sname == TEXT("") || sgen == TEXT("") || sclasss == TEXT(""))
	{
		MessageBox(TEXT("存在输入空，请补充"), TEXT("提示"));
		f = 1;
	}
	if (sclasss != "1" && sclasss != "2"&& sclasss != "3" && sclasss != "4")
	{
		MessageBox(TEXT("请在现有班级中添加学生成绩信息"), TEXT("提示"));
		f = 1;
	}
	if (sgen != "男" && sgen != "女")
	{
		MessageBox(TEXT("请输入正常性别"), TEXT("提示"));
		f = 1;
	}
	if (ss1 < 0 || ss2 < 0 || ss3 < 0 || ss4 < 0)
	{
		MessageBox(TEXT("请输入合理过程分数"), TEXT("提示"));
		f = 1;
	}
	if (sf1 < 0 || sf2 < 0 || sf3 < 0 || sf4 < 0)
	{
		MessageBox(TEXT("请输入合理期末分数"), TEXT("提示"));
		f = 1;
	}
	if (ss1 > 100 || ss2 > 100 || ss3 > 100 || ss4 > 100)
	{
		MessageBox(TEXT("请输入合理过程分数"), TEXT("提示"));
		f = 1;
	}
	if (sf1 > 100 || sf2 > 100 || sf3 > 100 || sf4 > 100)
	{
		MessageBox(TEXT("请输入合理期末分数"), TEXT("提示"));
		f = 1;
	}
	if(f == 0)
	{
		OnOK();
		return;
	}
}


void AAmend::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}
