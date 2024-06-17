#pragma once
class AAdmin
{
public:
	AAdmin();
	AAdmin(string jobn,string name,string idinfo,string password);
	string jobnum;
	string namme;
	string idinfo;
	void FtoP(ifstream& in);
	string password;
	void PtoF(ofstream& out);
};

