//
//  Judge.h
//  
//  This class represents a Judge from the justice system. Is inherited from Person.
//
//  Created by Hardik Patel on 12/9/13.
//
//

#ifndef ____Judge__
#define ____Judge__

#include <iostream>
#include "Person.h"
using namespace std;

class Judge: public Person //Inherited from Person class
{
private:
    string judgeName; //The name for a judge
public:
    Judge(); //Default Judge constructor
    Judge(string); //Judge constructor with parameter for a name
    
    //------------------------------------------------------------------------------
    //	Pre-condition:  Judge object must be present containing the required data
    //  Post-condition: Judge's information will be displayed
    //------------------------------------------------------------------------------
    string display();
    
    //------------------------------------------------------------------------------
    //	Pre-condition:  A Judge object should have been created
    //  Post-condition: The Judge object will contain the required data
    //------------------------------------------------------------------------------
    friend istream& operator>> (istream&, Judge&);
    
    //------------------------------------------------------------------------------
    //	Pre-condition:  Person object must be created
    //  Post-condition: Returns a new Person pointer object pointing to a Judge
    //------------------------------------------------------------------------------
    Person* createPointer();
};

#endif /* defined(____Judge__) */
