//
//  Roster.h
//  
//  Uses a dynamic array to contain Judges and Defendants along with their Docket information.
//
//  Created by Hardik Patel on 12/9/13.
//
//

#ifndef ____Roster__
#define ____Roster__

#include <iostream>
#include "Person.h"
#include "Defendant.h"
#include "Judge.h"
#include "Docket.h"

const int MAX_SIZE = 150; //Represents the max size of the array

class Roster
{
private:
    Person **personArray; //Dynamic array to hold Person objects
    int countSize; //Keeps track of the size of a roster
    int arraySize; //Helps set up a resized array
public:
    Roster(); //Constructor
    ~Roster(); //Destructor
    Roster(const Roster&); //copy constructor
    
    //------------------------------------------------------------------------------
    //	Pre-condition:  Input file must be present
    //  Post-condition: Roster object should be filled with judges and defendants
    //------------------------------------------------------------------------------
    void inputFmFile();
    
    //------------------------------------------------------------------------------
    //	Pre-condition:  Person object must exist
    //  Post-condition: Person objects will be added to the roster
    //------------------------------------------------------------------------------
    void add(Person&);
    
    //------------------------------------------------------------------------------
    //	Pre-condition:  Roster object must exist with judges and defendants
    //  Post-condition: Displays the information of each judge, defendant, and docket
    //------------------------------------------------------------------------------
    string display();
    
    //------------------------------------------------------------------------------
    //	Pre-condition: Two Roster objects must exist
    //  Post-condition: The caller object will be identical to the operand
    //------------------------------------------------------------------------------
    Roster& operator= (const Roster&);
};



#endif /* defined(____Roster__) */
