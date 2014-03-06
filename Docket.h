//
//  Docket.h
//  
//  This class represents a Docket containing case information. Will be used in the Defendant class.
//
//  Created by Hardik Patel on 12/9/13.
//
//

#ifndef ____Docket__
#define ____Docket__

#include <iostream>
using namespace std;

class Docket
{
private:
    //Represents all the information required for a legal Docket
    string charge6105, charge6106, charge6108, charge907;
    string bail, attorney, mcDocketNum, mcFileDate, mcStatus, verdict, jail, sentence;
public:
    Docket(); //Default Docket constructor
    Docket(string, string, string, string, string, string, string, string, string, string, string, string); //Constructor with required parameters for a Docket object
    
    //------------------------------------------------------------------------------
    //	Pre-condition:  A Docket object must exist with required data
    //  Post-condition: Docket object's information will be displayed
    //------------------------------------------------------------------------------
    string display();
    
    //------------------------------------------------------------------------------
    //	Pre-condition:  Docket object must be created
    //  Post-condition: The Docket object will be filled with the required data
    //------------------------------------------------------------------------------
    friend istream& operator>> (istream&, Docket&);
};

#endif /* defined(____Docket__) */
