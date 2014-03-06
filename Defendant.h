//
//  Defendant.h
//  
//  This class represents a Defendant from the justice system. Is inherited from Person. Contains Docket information.
//
//  Created by Hardik Patel on 12/9/13.
//
//

#ifndef ____Defendant__
#define ____Defendant__

#include <iostream>
#include "Person.h"
#include "Docket.h"
using namespace std;

class Defendant : public Person //Inherited from Person class
{
private:
    string name, age, dob, sex, race; //Represents information of a Defendant
    Docket docket; //A Defendant will also contain the information of the Docket
public:
    Defendant(); //Default Defendant constructor
    Defendant(string, string, string, string, string, Docket&); //Constructor with the required fields for a Defendant object
    
    //------------------------------------------------------------------------------
    //	Pre-condition:  A Defendant object must exist with the required data
    //  Post-condition: The Defendant's information will be displayed
    //------------------------------------------------------------------------------
    string display();
    
    //------------------------------------------------------------------------------
    //	Pre-condition:  A Defendant object must merely exist
    //  Post-condition: The Defendant object will be filled with the required data
    //------------------------------------------------------------------------------
    friend istream& operator>> (istream&, Defendant&);
    
    //------------------------------------------------------------------------------
    //	Pre-condition:  Valid Person object must exist
    //  Post-condition: Returns a new Person pointer object pointing to a Defendant
    //------------------------------------------------------------------------------
    Person* createPointer();
    
    
};

#endif /* defined(____Defendant__) */