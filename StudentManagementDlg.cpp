
// StudentManagementDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "StudentManagement.h"
#include "StudentManagementDlg.h"
#include "afxdialogex.h"
#include "LLogin.h"
#include "CCourse.h"
#include "AAmend.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CStudentManagementDlg 对话框



CStudentManagementDlg::CStudentManagementDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUDENTMANAGEMENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStudentManagementDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, slist);
	DDX_Control(pDX, IDC_COMBO1, s_class);
	DDX_Control(pDX, IDC_COMBO2, s_course);
	DDX_Control(pDX, IDC_COMBO3, s_weighted);
	DDX_Control(pDX, IDC_COMBO4, AorS);
}

BEGIN_MESSAGE_MAP(CStudentManagementDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON7, &CStudentManagementDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON1, &CStudentManagementDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON9, &CStudentManagementDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON6, &CStudentManagementDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON10, &CStudentManagementDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON5, &CStudentManagementDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CStudentManagementDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON8, &CStudentManagementDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CStudentManagementDlg 消息处理程序

BOOL CStudentManagementDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	AorS.AddString(TEXT("管理员"));
	AorS.AddString(TEXT("学生"));
	AorS.SetCurSel(0);
	sfont.CreatePointFont(262, _T("黑体"), NULL);
	GetDlgItem(IDC_STATIC)->SetFont(&sfont);
	s_class.AddString(TEXT("1班"));
	s_class.AddString(TEXT("2班"));
	s_class.AddString(TEXT("3班"));
	s_class.AddString(TEXT("4班"));
	s_class.AddString(TEXT("全部班级"));
	s_class.SetCurSel(4);
	s_course.AddString(TEXT("MA01"));
	s_course.AddString(TEXT("CS01"));
	s_course.AddString(TEXT("AE01"));
	s_course.AddString(TEXT("PY02"));
	s_course.AddString(TEXT("全部课程"));
	s_course.SetCurSel(4);
	s_weighted.AddString(TEXT("是"));
	s_weighted.AddString(TEXT("否"));
	s_weighted.SetCurSel(1);
	DWORD dwStyle = slist.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	slist.SetExtendedStyle(dwStyle);  
	slist.InsertColumn(0, TEXT("姓名"), 0, 60);
	slist.InsertColumn(1, TEXT("性别"), 0, 50);
	slist.InsertColumn(2, TEXT("班级"), 0, 50);
	slist.InsertColumn(3, TEXT("MA01P"), 0, 60);
	slist.InsertColumn(6, TEXT("CS01P"), 0, 60);
	slist.InsertColumn(9, TEXT("AE01P"), 0, 60);
	slist.InsertColumn(12, TEXT("PY02P"), 0, 60);
	slist.InsertColumn(4, TEXT("MA01F"), 0, 60);
	slist.InsertColumn(7, TEXT("CS01F"), 0, 60);
	slist.InsertColumn(10, TEXT("AE01F"), 0, 60);
	slist.InsertColumn(13, TEXT("PY02F"), 0, 60);
	slist.InsertColumn(5, TEXT("MA01"), 0, 60);
	slist.InsertColumn(8, TEXT("CS01"), 0, 60);
	slist.InsertColumn(11, TEXT("AE01"), 0, 60);
	slist.InsertColumn(14, TEXT("PY02"), 0, 60);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CStudentManagementDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CStudentManagementDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CStudentManagementDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CStudentManagementDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (online == true)
	{
		CCourse cc;
		if (cc.DoModal() == IDOK)
		{

		}
	}
	else
	{
		MessageBox(TEXT("当前未登录"), TEXT("提示"));
	}
}


void CStudentManagementDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (online == false)
	{
		CString ty;
		int index = AorS.GetCurSel();
		s_class.GetLBText(index, ty);
		if (index == 1)
		{
			LLogin dl;
			if (dl.DoModal() == IDOK)
			{
				Studentsss ssd(dl.nname.GetBuffer(), dl.idi.GetBuffer(), dl.mpassword.GetBuffer());
				online = InterD.LLogin2(ssd);
				if (online)
				{
					MessageBox(TEXT("登录成功"), TEXT("提示"));
					AorS.ShowWindow(SW_HIDE);
					ListRenew();
				}
				else
				{
					MessageBox(TEXT("信息错误，请重新登录"), TEXT("提示"));
				}
			}
			 
		}
		else
		{
			LLogin dl;
			if (dl.DoModal() == IDOK)
			{
				AAdmin df(dl.job.GetBuffer(), dl.nname.GetBuffer(), dl.idi.GetBuffer(), dl.mpassword.GetBuffer());
				online = InterD.LLogin(df);
				if (online)
				{
					MessageBox(TEXT("登录成功"), TEXT("提示"));
					ListRenew();
				}
				else
				{
					MessageBox(TEXT("信息错误，请重新登录"), TEXT("提示"));
				}
			}
		}
		
	}
	else
	{
		MessageBox(TEXT("请勿重复登录"), TEXT("提示"));
	}
}

void CStudentManagementDlg::ListRenew()
{
	slist.DeleteAllItems();
	CString str;
	for (int i = 0; i < InterD.Sscores.size(); i++)
	{
		slist.InsertItem(i, InterD.Sscores[i].sname.c_str());
		slist.SetItemText(i, 1, InterD.Sscores[i].sgender.c_str());
		slist.SetItemText(i, 2, InterD.Sscores[i].sclass.c_str());
		str.Format(TEXT("%d"), InterD.process[i].sc1);
		slist.SetItemText(i, 3, str);
		str.Format(TEXT("%d"), InterD.Final[i].sc1);
		slist.SetItemText(i, 4, str);
		str.Format(TEXT("%d"), InterD.Sscores[i].sc1);
		slist.SetItemText(i, 5, str);
		str.Format(TEXT("%d"), InterD.process[i].sc2);
		slist.SetItemText(i, 6, str);
		str.Format(TEXT("%d"), InterD.Final[i].sc2);
		slist.SetItemText(i, 7, str);
		str.Format(TEXT("%d"), InterD.Sscores[i].sc2);
		slist.SetItemText(i, 8, str);
		str.Format(TEXT("%d"), InterD.process[i].sc3);
		slist.SetItemText(i, 9, str);
		str.Format(TEXT("%d"), InterD.Final[i].sc3);
		slist.SetItemText(i, 10, str);
		str.Format(TEXT("%d"), InterD.Sscores[i].sc3);
		slist.SetItemText(i, 11, str);
		str.Format(TEXT("%d"), InterD.process[i].sc4);
		slist.SetItemText(i, 12, str);
		str.Format(TEXT("%d"), InterD.Final[i].sc4);
		slist.SetItemText(i, 13, str);
		str.Format(TEXT("%d"), InterD.Sscores[i].sc4);
		slist.SetItemText(i, 14, str);
	}
}


void CStudentManagementDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	if (online == true)
	{
		CString FilePath = _T(".\\帮助文档.txt");
		ifstream in(FilePath, ios::in);
		string ans = "";
		string tmp;
		while (in >> tmp && tmp != "eof")
		{
			ans += tmp;
			ans += "\n";
		}
		MessageBox(ans.c_str(), TEXT("帮助"));
	}
	else
	{
		MessageBox(TEXT("当前未登录"), TEXT("提示"));
	}
}


void CStudentManagementDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (online == true)
	{
		CString ty;
		int index = AorS.GetCurSel();
		AorS.GetLBText(index, ty);
		if (index == 1)
		{
			string aans = "";
			string nam = InterD.curstu.name;
			for (int i = 0; i < InterD.Sscores.size(); i++)
			{
				if (nam == InterD.Sscores[i].sname)
				{
					int num = 0;
					if (InterD.Sscores[i].sc1 < 60)
					{
						num++;
					}
					if (InterD.Sscores[i].sc2 < 60)
					{
						num++;
					}
					if (InterD.Sscores[i].sc3 < 60)
					{
						num++;
					}
					if (InterD.Sscores[i].sc4 < 60)
					{
						num++;
					}
					if (num >= 2)
					{
						aans += InterD.Sscores[i].sname;
						aans += " 挂科不少于一个，无法满足要求，可能会延迟毕业\n";
					}
					else
					{
						aans += InterD.Sscores[i].sname;
						aans += " 挂科少于一个，可顺利毕业\n";
					}
					MessageBox(aans.c_str(), TEXT("学业预警"));
					break;
				}
			}
		}
		else
		{
			int len = InterD.Sscores.size();
			string aans = "";
			for (int i = 0; i < len; i++)
			{
				int num = 0;
				if (InterD.Sscores[i].sc1 < 60)
				{
					num++;
				}
				if (InterD.Sscores[i].sc2 < 60)
				{
					num++;
				}
				if (InterD.Sscores[i].sc3 < 60)
				{
					num++;
				}
				if (InterD.Sscores[i].sc4 < 60)
				{
					num++;
				}
				if (num >= 2)
				{
					aans += InterD.Sscores[i].sname;
					aans += " 挂科不少于一个，无法满足要求，可能会延迟毕业\n";
				}
				else
				{
					aans += InterD.Sscores[i].sname;
					aans += " 挂科少于一个，可顺利毕业\n";
				}
			}
			MessageBox(aans.c_str(), TEXT("学业预警"));
		}
	}
	else
	{
		MessageBox(TEXT("当前未登录"), TEXT("提示"));
	}
}


void CStudentManagementDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	if (online == true)
	{
		CString ty;
		int index = AorS.GetCurSel();
		AorS.GetLBText(index, ty);
		if (index == 1)
		{
			string nam = InterD.curstu.name;
			for (int i = 0; i < InterD.Sscores.size(); i++)
			{
				if (nam == InterD.Sscores[i].sname)
				{
					string ans = "";
					double ave = 0;
					ave += InterD.Sscores[i].sc1;
					ave += InterD.Sscores[i].sc2;
					ave += InterD.Sscores[i].sc3;
					ave += InterD.Sscores[i].sc4;
					ave /= 4;
					if (ave >= 80)
					{
						ans += "平均成绩超过及格线20分以上，优秀\n";
					}
					else if (ave >= 60 && ave < 80)
					{
						ans += "平均成绩在及格线上,良好\n";
					}
					else
					{
						ans += "平均成绩在及格线之下，有待提高\n";
					}
					double ave_w = 0;
					ave_w += (InterD.Sscores[i].sc1 * 0.3);
					ave_w += (InterD.Sscores[i].sc2 * 0.3);
					ave_w += (InterD.Sscores[i].sc3 * 0.3);
					ave_w += (InterD.Sscores[i].sc4 * 0.1);
					if (ave_w >= 80)
					{
						ans += "加权成绩超过及格线20分以上，优秀\n";
					}
					else if (ave_w >= 60 && ave < 80)
					{
						ans += "加权成绩在及格线上,良好\n";
					}
					else
					{
						ans += "加权成绩在及格线下，较差\n";
					}
					int num = 0;
					if (InterD.Sscores[i].sc1 < 60)
					{
						num++;
					}
					if (InterD.Sscores[i].sc2 < 60)
					{
						num++;
					}
					if (InterD.Sscores[i].sc3 < 60)
					{
						num++;
					}
					if (InterD.Sscores[i].sc4 < 60)
					{
						num++;
					}
					CString mm;
					mm.Format(TEXT("%s 成绩分析\n%s\n%d门课程综合成绩未到达及格线"), InterD.Sscores[i].sname.c_str(), ans.c_str(), num);
					MessageBox(mm, TEXT("成绩分析"));
					break;
				}
			}
		}
		else
		{
			int index = slist.GetSelectionMark();
			if (index > -1)
			{
				string ans = "";
				double ave = 0;
				ave += InterD.Sscores[index].sc1;
				ave += InterD.Sscores[index].sc2;
				ave += InterD.Sscores[index].sc3;
				ave += InterD.Sscores[index].sc4;
				ave /= 4;
				if (ave >= 80)
				{
					ans += "平均成绩超过及格线20分以上，优秀\n";
				}
				else if (ave >= 60 && ave < 80)
				{
					ans += "平均成绩在及格线上,良好\n";
				}
				else
				{
					ans += "平均成绩在及格线之下，有待提高\n";
				}
				double ave_w = 0;
				ave_w += (InterD.Sscores[index].sc1 * 0.3);
				ave_w += (InterD.Sscores[index].sc2 * 0.3);
				ave_w += (InterD.Sscores[index].sc3 * 0.3);
				ave_w += (InterD.Sscores[index].sc4 * 0.1);
				if (ave_w >= 80)
				{
					ans += "加权成绩超过及格线20分以上，优秀\n";
				}
				else if (ave_w >= 60 && ave < 80)
				{
					ans += "加权成绩在及格线上,良好\n";
				}
				else
				{
					ans += "加权成绩在及格线下，较差\n";
				}
				int num = 0;
				if (InterD.Sscores[index].sc1 < 60)
				{
					num++;
				}
				if (InterD.Sscores[index].sc2 < 60)
				{
					num++;
				}
				if (InterD.Sscores[index].sc3 < 60)
				{
					num++;
				}
				if (InterD.Sscores[index].sc4 < 60)
				{
					num++;
				}
				CString mm;
				mm.Format(TEXT("%s 成绩分析\n%s\n%d门课程综合成绩未到达及格线"), InterD.Sscores[index].sname.c_str(), ans.c_str(), num);
				MessageBox(mm, TEXT("成绩分析"));
			}
			else
			{
				MessageBox(TEXT("请选择学生进行成绩分析"), TEXT("提示"));
			}
		}
	}
	else
	{
		MessageBox(TEXT("当前未登录"), TEXT("提示"));
	}
}


void CStudentManagementDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码,成绩修改
	if (online == true)
	{
		CString ty;
		int index = AorS.GetCurSel();
		s_class.GetLBText(index, ty);
		if (index == 1)
		{
			MessageBox(TEXT("学生无此权限"), TEXT("提示"));
		}
		else
		{
			int index = slist.GetSelectionMark();
			if (index > -1)
			{
				AAmend md;
				CString str;
				str.Format(TEXT("%s"), InterD.Sscores[index].sname.c_str());
				md.sname = str;
				str.Format(TEXT("%s"), InterD.Sscores[index].sgender.c_str());
				md.sgen = str;
				str.Format(TEXT("%s"), InterD.Sscores[index].sclass.c_str());
				md.sclasss = str;
				md.ss1 = InterD.process[index].sc1;
				md.ss2 = InterD.process[index].sc2;
				md.ss3 = InterD.process[index].sc3;
				md.ss4 = InterD.process[index].sc4;
				md.sf1 = InterD.Final[index].sc1;
				md.sf2 = InterD.Final[index].sc2;
				md.sf3 = InterD.Final[index].sc3;
				md.sf4 = InterD.Final[index].sc4;
				if (md.DoModal() == IDOK)
				{
					SScore spp(md.sname.GetBuffer(), md.sgen.GetBuffer(), md.sclasss.GetBuffer(), md.ss1, md.ss2, md.ss3, md.ss4);
					SScore sff(md.sname.GetBuffer(), md.sgen.GetBuffer(), md.sclasss.GetBuffer(), md.sf1, md.sf2, md.sf3, md.sf4);
					InterD.amend(index, spp, sff);
					ListRenew();
					CString FilePath = _T(".\\score.txt");
					InterD.StuSave(FilePath);
				}
			}
			else
			{
				MessageBox(TEXT("请先选择欲修改的学生"), TEXT("提示"));
			}
		}
		{

		}
	}
	else
	{
		MessageBox(TEXT("当前未登录"), TEXT("提示"));
	}
}


void CStudentManagementDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (online == true)
	{
		CString ty;
		int index = AorS.GetCurSel();
		s_class.GetLBText(index, ty);
		if (index == 1)
		{
			MessageBox(TEXT("学生无此权限"), TEXT("提示"));
		}
		else
		{
			AAmend md;
			if (md.DoModal() == IDOK)
			{
				SScore ssr(md.sname.GetBuffer(), md.sgen.GetBuffer(), md.sclasss.GetBuffer(), md.ss1, md.ss2, md.ss3, md.ss4);
				SScore sFr(md.sname.GetBuffer(), md.sgen.GetBuffer(), md.sclasss.GetBuffer(), md.sf1, md.sf2, md.sf3, md.sf4);
				InterD.Add(ssr, sFr);
				ListRenew();
				CString FilePath = _T(".\\score.txt");
				InterD.StuSave(FilePath);
			}
		}
	}
	else
	{
		MessageBox(TEXT("当前未登录"), TEXT("提示"));
	}
}


void CStudentManagementDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	if (online)
	{
		CString ty;
		int index = AorS.GetCurSel();
		s_class.GetLBText(index, ty);
		if (index == 1)
		{
			MessageBox(TEXT("学生无此权限"), TEXT("提示"));
		}
		else
		{
			CString str1, str2, str3;
			int num = 0;
			double sum = 0;
			double mmax = 0;
			double mmin = 101;
			double ave = 0;
			int stupass = 0;
			double pass = 0;
			int index1 = s_class.GetCurSel();
			s_class.GetLBText(index1, str1);
			int index2 = s_course.GetCurSel();
			s_course.GetLBText(index2, str2);
			int index3 = s_weighted.GetCurSel();
			s_weighted.GetLBText(index3, str3);
			vector<double> se_score;
			if (index3 == 1)
			{
				se_score.clear();
				for (int i = 0; i < InterD.Sscores.size(); i++)
				{
					if (stoi(InterD.Sscores[i].sclass) == index1 + 1 || index1 == 4)
					{
						double ss;
						switch (index2)
						{
						case 0:
							se_score.push_back(InterD.Sscores[i].sc1); break;
						case 1:
							se_score.push_back(InterD.Sscores[i].sc2); break;
						case 2:
							se_score.push_back(InterD.Sscores[i].sc3); break;
						case 3:
							se_score.push_back(InterD.Sscores[i].sc4); break;
						case 4:
							ss = ((double)(InterD.Sscores[i].sc1 + InterD.Sscores[i].sc2 + InterD.Sscores[i].sc3 + InterD.Sscores[i].sc4)) / 4;
							se_score.push_back(ss);
							break;
						default:
							break;
						}
					}
				}
				for (int i = 0; i < se_score.size(); i++)
				{
					sum += se_score[i];
					if (se_score[i] >= 60)
					{
						stupass++;
					}
					mmax = max(mmax, se_score[i]);
					mmin = min(mmin, se_score[i]);
				}
				num = se_score.size();
				ave = sum / num;
				pass = ((double)stupass) / num;
			}
			else if (index3 == 0)
			{
				se_score.clear();
				for (int i = 0; i < InterD.Sscores.size(); i++)
				{
					if (stoi(InterD.Sscores[i].sclass) == index1 + 1 || index1 == 4)
					{
						double ss;
						switch (index2)
						{
						case 0:
							se_score.push_back(InterD.Sscores[i].sc1); break;
						case 1:
							se_score.push_back(InterD.Sscores[i].sc2); break;
						case 2:
							se_score.push_back(InterD.Sscores[i].sc3); break;
						case 3:
							se_score.push_back(InterD.Sscores[i].sc4); break;
						case 4:
							ss = InterD.Sscores[i].sc1 * 0.3 + InterD.Sscores[i].sc2 * 0.3 + InterD.Sscores[i].sc3 * 0.3 + InterD.Sscores[i].sc4 * 0.1;
							se_score.push_back(ss);
							break;
						default:
							break;
						}
					}
				}
				for (int i = 0; i < se_score.size(); i++)
				{
					sum += se_score[i];
					if (se_score[i] >= 60)
					{
						stupass++;
					}
					mmax = max(mmax, se_score[i]);
					mmin = min(mmin, se_score[i]);
				}
				num = se_score.size();
				ave = sum / num;
				pass = ((double)stupass) / num;
			}
			CString answer;
			answer.Format(TEXT("最高分：%2f\n最低分：%2f\n均分：%2f\n及格比例：%2f"), mmax, mmin, ave, pass);
			MessageBox(answer, TEXT("成绩统计"));
		}
	}
	else
	{
		MessageBox(TEXT("当前未登录"), TEXT("提示"));
	}
}
