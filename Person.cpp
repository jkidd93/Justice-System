//
//  Person.cpp
//  
//
//  Created by Hardik Patel on 12/9/13.
//
//

#include "Person.h"

//Default blank constructor
Person::Person()
{
    
}

//Constructor with the paramter for a case ID
Person::Person(string idNum)
{
    caseId = idNum;
}

//Displays the information for a Person. Supports inheritance so if the display() method is called
//for a Defendant of Judge object later in the code, their respective information will be displayed
//and not just the information for a regular "Person"
string Person::display()
{
    string result = "";
    result = "\n\nThe Person Information is:\n PersonCaseID is: " + caseId;
    return result;
}

//Overload >> operator to obtain caseId field
istream& operator >>(istream& lhs, Person& rhs)
{
    
    cout << "Enter the Person data: " << endl;
    lhs >> rhs.caseId;
    
    return lhs;
}

//Creates a new Person pointer object pointing to a person
Person* Person::createPointer()
{
    Person* personPointer = new Person(this->caseId);
    
    return personPointer;
}



