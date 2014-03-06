//
//  Judge.cpp
//  
//
//  Created by Hardik Patel on 12/9/13.
//
//

#include "Judge.h"

//Default blank constructor
Judge::Judge()
{
    
}

//Constructor with name paramter. Calls the base class constructor of Person
Judge::Judge(string Name) : Person(caseId)
{
    judgeName = Name;
}

//Displays only the Judge's data
string Judge::display()
{
    string result = "";
    result = "\n\nThe Judge Information mcJudgeName is: " + judgeName;
    return result;
}

//Obtains the required data for a judge
istream& operator>> (istream& lhs, Judge& rhs)
{
    cout << "Enter Judge Name" << endl;
    
    lhs >> rhs.judgeName;
    return lhs;
}


//Returns a new Person pointer object pointing to a Judge
Person* Judge::createPointer()
{
    Person* judgePointer = new Judge(this->judgeName);
    
    return judgePointer;
}