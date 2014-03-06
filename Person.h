//
//  Person.h
//  
//  Represents a Person in the justice system. Is the Parent class of Judges and Defendants.
//
//  Created by Hardik Patel on 12/9/13.
//
//

#ifndef ____Person__
#define ____Person__

#include <iostream>
using namespace std;

/*
    This class will represent the parent of a Defendant and Judge. The Judge and Defendant classes are inherited from the Person class. Polymorphism will be used extensively. All Defendants and Judges are also Persons in this program. The display() method is the same name in the Defendant and Judge classes, however the program will know when to display a Defendant or Judge's information.
 */
class Person
{
protected:
    string caseId; //the caseId is the common factor shared with all people in the data. That is why it was used as the attribute of the Person class. A "name" field was not used as an attribute of Person because the defendant names and judge names belong in their respective Defendant and Judge classes, while the attorney name belong in the Docket class.
    
public:
    Person(); //Default Person construtor
    Person(string); //Person constructor with parameter for a caseId
    
    //------------------------------------------------------------------------------
    //	Pre-condition:  Person object must be created
    //  Post-condition: Any Person's, even a Defendant's and Judge's information will
    //                  be displayed because of the "virtual" keyword.
    //------------------------------------------------------------------------------
    virtual string display();
    
    //------------------------------------------------------------------------------
    //	Pre-condition:  Person object must be created
    //  Post-condition: Person object will contain the required caseId data
    //------------------------------------------------------------------------------
    friend istream& operator>> (istream&, Person&);
    
    //------------------------------------------------------------------------------
    //	Pre-condition:  Person object must be created
    //  Post-condition: Returns a new Person pointer object pointing to a Person
    //------------------------------------------------------------------------------
    virtual Person* createPointer();
    
};

#endif /* defined(____Person__) */
