#pragma once
#include"AAdmin.h"
#include"SScore.h"
#include "Studentsss.h"
class InterfaceDesign
{
public:
	vector<AAdmin> ATeachers;
	vector<SScore> process;
	vector<SScore> Final;
	vector<SScore> Sscores;
	bool LLogin(AAdmin Att);
	bool LLogin2(Studentsss stu);
	bool StuSave(CString FilePath);
	void amend(int index, SScore info, SScore info2);
	void Add(SScore Myinfo, SScore Myinfo2);
	vector<Studentsss> stuss;
	Studentsss curstu;
	SScore cur;
};

