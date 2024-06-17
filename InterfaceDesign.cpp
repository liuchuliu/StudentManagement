#include "pch.h"
#include "InterfaceDesign.h"

bool InterfaceDesign::LLogin(AAdmin Att)
{
    CString FilePath1 = _T(".\\admin.txt");
    CString FilePath2 = _T(".\\score.txt");
    ifstream in1(FilePath1, ios::in);
    ifstream in2(FilePath2, ios::in);
    int num;
    ATeachers.clear();
    if (in1.is_open())
    {
        in1 >> num;
        for (int i = 0; i < num; i++)
        {
            AAdmin tmp;
            tmp.FtoP(in1);
            ATeachers.push_back(tmp);
        }
    }
    for (int i = 0; i < ATeachers.size(); i++)
    {
        if (Att.jobnum == ATeachers[i].jobnum && Att.namme == ATeachers[i].namme && Att.idinfo == ATeachers[i].idinfo && Att.password == ATeachers[i].password)
        {
            int num2;
            Sscores.clear();
            process.clear();
            Final.clear();
            if (in2.is_open())
            {
                in2 >> num2;
                for (int j = 0; j < num2; j++)
                {
                    SScore s, sp, sf;
                    string sn, sg, scl;
                    in2 >> sn >> sg >> scl;
                    s.sname = sn;
                    s.sgender = sg;
                    s.sclass = scl;
                    sp.sname = sn;
                    sp.sgender = sg;
                    sp.sclass = scl;
                    sf.sname = sn;
                    sf.sgender = sg;
                    sf.sclass = scl;
                    int temp1;
                    int temp2;
                    in2 >> temp1 >> temp2;
                    sp.sc1 = temp1;
                    sf.sc1 = temp2;
                    s.sc1 = (temp1 + temp2) / 2;
                    in2 >> temp1 >> temp2;
                    sp.sc2 = temp1;
                    sf.sc2 = temp2;
                    s.sc2 = (temp1 + temp2) / 2;
                    in2 >> temp1 >> temp2;
                    sp.sc3 = temp1;
                    sf.sc3 = temp2;
                    s.sc3 = (int)(((double)temp1) * 0.45 + ((double)temp2) * 0.55);
                    in2 >> temp1 >> temp2;
                    sp.sc4 = temp1;
                    sf.sc4 = temp2;
                    s.sc4 = (int)(((double)temp1) * 0.65 + ((double)temp2) * 0.35);
                    Sscores.push_back(s);
                    process.push_back(sp);
                    Final.push_back(sf);
                }
            }
            return true;
        }
    }
    return false;
}

bool InterfaceDesign::LLogin2(Studentsss stu)
{
    CString FilePath1 = _T(".\\student.txt");
    CString FilePath2 = _T(".\\score.txt");
    ifstream in1(FilePath1, ios::in);
    ifstream in2(FilePath2, ios::in);
    int num;
    stuss.clear();
    if (in1.is_open())
    {
        in1 >> num;
        for (int i = 0; i < num; i++)
        {
            Studentsss tmp;
            string o1, o2, o3;
            in1 >> o1 >> o2 >> o3;
            tmp.name = o1;
            tmp.banji = o2;
            tmp.mima = o3;
            stuss.push_back(tmp);

        }
    }
    for (int i = 0; i < stuss.size(); i++)
    {
        if (stu.banji == stuss[i].banji && stu.mima == stuss[i].mima && stu.name == stuss[i].name)
        {
            curstu = stu;
            int num2;
            Sscores.clear();
            process.clear();
            Final.clear();
            if (in2.is_open())
            {
                in2 >> num2;
                for (int j = 0; j < num2; j++)
                {
                    SScore s, sp, sf;
                    string sn, sg, scl;
                    in2 >> sn >> sg >> scl;
                    s.sname = sn;
                    s.sgender = sg;
                    s.sclass = scl;
                    sp.sname = sn;
                    sp.sgender = sg;
                    sp.sclass = scl;
                    sf.sname = sn;
                    sf.sgender = sg;
                    sf.sclass = scl;
                    int temp1;
                    int temp2;
                    in2 >> temp1 >> temp2;
                    sp.sc1 = temp1;
                    sf.sc1 = temp2;
                    s.sc1 = (temp1 + temp2) / 2;
                    in2 >> temp1 >> temp2;
                    sp.sc2 = temp1;
                    sf.sc2 = temp2;
                    s.sc2 = (temp1 + temp2) / 2;
                    in2 >> temp1 >> temp2;
                    sp.sc3 = temp1;
                    sf.sc3 = temp2;
                    s.sc3 = (int)(((double)temp1) * 0.45 + ((double)temp2) * 0.55);
                    in2 >> temp1 >> temp2;
                    sp.sc4 = temp1;
                    sf.sc4 = temp2;
                    s.sc4 = (int)(((double)temp1) * 0.65 + ((double)temp2) * 0.35);
                    if (s.sname == stu.name)
                    {
                        Sscores.push_back(s);
                        process.push_back(sp);
                        Final.push_back(sf);
                        break;
                    }
                    
                }
                cur = Sscores[0];
            }
            return true;
        }
    }
    return false;
}

bool InterfaceDesign::StuSave(CString FilePath)
{
    ofstream out(FilePath, ios::out);
    if (out.is_open())
    {
        out << Sscores.size() << endl;
        for (int i = 0; i < Sscores.size(); i++)
        {

            out << Sscores[i].sname << "\t" << Sscores[i].sgender << "\t" << Sscores[i].sclass << "\t" << process[i].sc1 << "\t" << Final[i].sc1 << "\t" << process[i].sc2 << "\t" << Final[i].sc2 << "\t" << process[i].sc3 << "\t" << Final[i].sc3 << "\t" << process[i].sc4 << "\t" << Final[i].sc4 << "\n";
        }
        out.close();
        return true;
    }
    return false;
}

void InterfaceDesign::amend(int index, SScore info, SScore info2)
{
    process[index] = info;
    Final[index] = info2;
    Sscores[index].sc1 = (process[index].sc1 + Final[index].sc1) / 2;
    Sscores[index].sc2 = (process[index].sc2 + Final[index].sc2) / 2;
    Sscores[index].sc3 = (int)(((double)process[index].sc3) * 0.45 + ((double)Final[index].sc3) * 0.55);
    Sscores[index].sc4 = (int)(((double)process[index].sc4) * 0.65 + ((double)Final[index].sc4) * 0.35);
}

void InterfaceDesign::Add(SScore Myinfo, SScore Myinfo2)
{
    CString FilePath1 = _T(".\\student.txt");
    ifstream in1(FilePath1, ios::in);
    ofstream out(FilePath1, ios::out);
    process.push_back(Myinfo);
    Final.push_back(Myinfo2);
    int index = process.size() - 1;
    SScore tmp;
    tmp.sname = Myinfo.sname;
    tmp.sgender = Myinfo.sgender;
    tmp.sclass = Myinfo.sclass;
    tmp.sc1 = (process[index].sc1 + Final[index].sc1) / 2;
    tmp.sc2 = (process[index].sc2 + Final[index].sc2) / 2;
    tmp.sc3 = (int)(((double)process[index].sc3) * 0.45 + ((double)Final[index].sc3) * 0.55);
    tmp.sc4 = (int)(((double)process[index].sc4) * 0.65 + ((double)Final[index].sc4) * 0.35);
    Sscores.push_back(tmp);
    
    int num;
    stuss.clear();
    if (in1.is_open())
    {
        in1 >> num;
        for (int i = 0; i < num; i++)
        {
            Studentsss tmp1;
            string o1, o2, o3;
            in1 >> o1 >> o2 >> o3;
            tmp1.name = o1;
            tmp1.banji = o2;
            tmp1.mima = o3;
            stuss.push_back(tmp1);
        }
    }
    Studentsss tertp;
    tertp.name = Myinfo.sname;
    tertp.banji = Myinfo.sclass;
    tertp.mima = "123456";
    stuss.push_back(tertp);
    out << stuss.size()<<endl;
    for (int i = 0; i < stuss.size(); i++)
    {
        out << stuss[i].name << "\t" << stuss[i].banji << "\t" << stuss[i].mima << endl;
    }
}
