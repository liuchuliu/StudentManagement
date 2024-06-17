#pragma once
class SScore
{
public:
	SScore();
	SScore(string name, string gender, string sclass, int sc1, int sc2, int sc3, int sc4);
	string sname;
	string sgender;
	string sclass;
	void PtoF(ofstream& out);
	int sc1;
	int sc2;
	int sc3;
	int sc4;
	void FtoP(ifstream& in);
};

