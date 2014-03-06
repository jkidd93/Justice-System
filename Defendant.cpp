//
//  Defendant.cpp
//  
//
//  Created by Hardik Patel on 12/9/13.
//
//

#include "Defendant.h"

//Default blank constructor
Defendant::Defendant()
{
    
}

//Constructor with the required paramters for a Defendant. Contains the Docket object since
//Defendants also have dockets. Calls the base class constructor of Person
Defendant::Defendant(string defName, string defAge, string defDob, string defSex, string defRace, Docket& docketDoc) : Person(caseId)
{
    name = defName;
    age = defAge;
    dob = defDob;
    sex = defSex;
    race = defRace;
    docket = docketDoc;
}

//Displays only the Defendants information as well as a Docket's information
string Defendant::display()
{
    string result = "";
    result = "\n\nThe Defendant Information is:\n name: " + name + "\tage: " + age + "\tdob: " + dob + "\tsex: " + sex + "\trace: " + race + "\n" + docket.display();
    return result;
}

//Overloaded >> operator to fill in data for a Defendant object.
istream& operator>> (istream& lhs, Defendant& rhs)
{
    cout << "Enter defendant data" << endl;
    
    lhs >> rhs.name;
    lhs >> rhs.age;
    lhs >> rhs.dob;
    lhs >> rhs.sex;
    lhs >> rhs.race;
    lhs >> rhs.docket;
    
    return lhs;
}

//Returns a new Person pointer object pointing to a Defendant
Person* Defendant::createPointer()
{
    Person* defPointer = new Defendant(this->name, this->age, this->dob, this->sex, this->race, this->docket);
    
    return defPointer;
}

