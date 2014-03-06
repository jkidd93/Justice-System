//
//  Docket.cpp
//  
//
//  Created by Hardik Patel on 12/9/13.
//
//

#include "Docket.h"

//Default blank constructor
Docket::Docket()
{
    
}

//Docket constructor with required paramter fields
Docket::Docket(string charge1, string charge2, string charge3, string charge4, string docBail, string docAttorney, string docNum, string docDate, string docStatus, string docVerdict, string docJail, string docSentence)
{
    charge6105 = charge1;
    charge6106 = charge2;
    charge6108 = charge3;
    charge907 = charge4;
    bail = docBail;
    attorney = docAttorney;
    mcDocketNum = docNum;
    mcFileDate = docDate;
    mcStatus = docStatus;
    verdict = docVerdict;
    jail = docJail;
    sentence = docSentence;
}

//Displays only the Docket's information
string Docket::display()
{
    string result = "";
    result = "\nThe Docket Information is:\ncharge6105: " + charge6105 + "\tcharge6106: " + charge6106 + "\tcharge6108: " + charge6108 + "\tcharge907: " + charge907 + "\tbail: " + bail + "\tDefense Attorney: " + attorney + "\tmcDocketNum: " + mcDocketNum + "\tmcFileDate: " + mcFileDate + "\tmcStatus: " + mcStatus + "\tverdict: " + verdict + "\tjail: " + jail + "\tsentence: " + sentence;
    
    return result;
}

//Overloaded >> operator to obtain the required fields for a Docket object
istream& operator>> (istream& lhs, Docket& rhs)
{
    cout << "Enter Docket Information" << endl;
    
    lhs >> rhs.charge6105;
    lhs >> rhs.charge6106;
    lhs >> rhs.charge6108;
    lhs >> rhs.charge907;
    lhs >> rhs.bail;
    lhs >> rhs.attorney;
    lhs >> rhs.mcDocketNum;
    lhs >> rhs.mcFileDate;
    lhs >> rhs.mcStatus;
    lhs >> rhs.verdict;
    lhs >> rhs.jail;
    lhs >> rhs.sentence;
    
    return lhs;
}