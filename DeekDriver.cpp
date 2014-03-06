//
//  DeekDriver.cpp
//  
//
//  Created by Hardik Patel on 12/11/13.
//
//

#include "Roster.h"
#include "Person.h"
#include "Defendant.h"
#include "Judge.h"
#include "Docket.h"

int main (void)
{
    Roster roster1, roster2;
    Judge judgeJudy, judgeMuscle;
    Defendant oj, oj2;
    
    roster1.inputFmFile();
    
    roster2 = roster1;
    
    cin >> judgeJudy;
    cout << "Created first judge" << endl;
    
    cin >> judgeMuscle;
    cout << "Created second judge" <<endl;
    
    cin >> oj;
    
    cin >> oj2;
    
    cout << "Created one defendant" << endl;
    
    roster1.add(judgeJudy);
    cout << "Added first judge to roster1" << endl;
    
    roster2.add(judgeMuscle);
    cout << "Added second judge to roster2" << endl;
    
    roster1.add(oj);
    cout << "Added first defendant to roster1" << endl;
    
    roster2.add(oj2);
    cout << "Added second defendant to roster2" << endl;
    
    cout<< "copy constructor invoked roster3(roster1)..." << endl;
    Roster roster3(roster1);
    
    cout << "\nRoster 1 after changes is...\n" << endl;
    cout << roster1.display() << endl;
    cout << "\nRoster 2 after changes is...\n" << endl;
    cout << roster2.display() << endl;
    cout << "\nRoster 3 after changes is...\n" << endl;
    cout << roster3.display() << endl;
    
    return 0;
}