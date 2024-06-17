#include "pch.h"
#include "SScore.h"

SScore::SScore()
{
}

SScore::SScore(string name, string gender, string sclass, int sc1, int sc2, int sc3, int sc4)
{
	this->sname = name;
	this->sgender = gender;
	this->sclass = sclass;
	this->sc1 = sc1;
	this->sc2 = sc2;
	this->sc3 = sc3;
	this->sc4 = sc4;
}

void SScore::PtoF(ofstream& out)
{
	out << sname << "\t" << sgender << "\t" << sclass << "\t" << sc1 << "\t" << sc2 << "\t" << sc3 << "\t" << sc4 << "\n";
}

void SScore::FtoP(ifstream& in)
{
	in >> sname;
	in >> sgender;
	in >> sclass;
	in >> sc1 >> sc2 >> sc3 >> sc4;
}