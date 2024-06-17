// CCourse.cpp: 实现文件
//

#include "pch.h"
#include "StudentManagement.h"
#include "afxdialogex.h"
#include "CCourse.h"


// CCourse 对话框

IMPLEMENT_DYNAMIC(CCourse, CDialogEx)

CCourse::CCourse(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CCourse, pParent)
{

}

CCourse::~CCourse()
{
}

void CCourse::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, clist);
}


BEGIN_MESSAGE_MAP(CCourse, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCourse::OnBnClickedButton1)
END_MESSAGE_MAP()


// CCourse 消息处理程序


void CCourse::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}


BOOL CCourse::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	DWORD dwStyle = clist.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	clist.SetExtendedStyle(dwStyle);
	clist.InsertColumn(0, TEXT("课程"), 0, 100);
	clist.InsertColumn(1, TEXT("学分"), 0, 90);
	clist.InsertColumn(2, TEXT("学时"), 0, 100);
	clist.InsertColumn(3, TEXT("任课教师"), 0, 100);
	clist.InsertColumn(4, TEXT("课程类型"), 0, 100);
	ListRenew();
	return TRUE; 
}

void CCourse::ListRenew()
{
	CString FilePath = _T(".\\课程信息.txt");
	ifstream in(FilePath, ios::in);
	int num;
	string tmp1,tmp2,tmp3,tmp4,tmp5;
	clist.DeleteAllItems();
	CString str;
	in >> num;
	for (int i = 0; i < num; i++)
	{
		in >> tmp1 >> tmp2 >> tmp3 >> tmp4 >> tmp5;
		clist.InsertItem(i, tmp1.c_str());
		clist.SetItemText(i, 1, tmp2.c_str());
		clist.SetItemText(i, 2, tmp3.c_str());
		clist.SetItemText(i, 3, tmp4.c_str());
		clist.SetItemText(i, 4, tmp5.c_str());
	}
}
