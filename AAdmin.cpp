#include "pch.h"
#include "AAdmin.h"

AAdmin::AAdmin()
{
}

AAdmin::AAdmin(string jobn, string name, string idinfo, string password)
{
	this->jobnum = jobn;
	this->namme = name;
	this->idinfo = idinfo;
	this->password = password;
}

void AAdmin::FtoP(ifstream& in)
{
	in >> jobnum >> namme >> idinfo >> password;
}

void AAdmin::PtoF(ofstream& out)
{
	out << jobnum << "\t" << namme << "\t" << idinfo << "\t" << password << "\n";
}
