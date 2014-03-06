//
//  Roster.cpp
//  
//
//  Created by Hardik Patel on 12/9/13.
//
//

#include "Roster.h"
#include <fstream>
#include <iostream>

//Default constructor contains a size of 0 and creates a dynamic array of Persons
Roster::Roster()
{
    countSize = 0;
    arraySize = MAX_SIZE;
    personArray = new Person* [MAX_SIZE];
    for(int i = 0; i < MAX_SIZE; i++)
    {
        personArray[i] = NULL;
    }
}

//Copy constructor for Roster
Roster::Roster(const Roster& rhs)
{
    arraySize = rhs.arraySize + 10;
    countSize = 0;
    personArray = new Person* [arraySize]; //Creates new, resized array
    
    for(int i = 0; i < arraySize; i++)
    {
        personArray[i] = NULL;
    }
    for(int i = 0; i < rhs.countSize; i++)
    {
        personArray[i] = (rhs.personArray[i])->createPointer();
        countSize++;
    }
}

//Destructor for Roster
Roster::~Roster()
{
    if(personArray != NULL)
    {
    for(int i = 0; i < countSize; i++)
    {
        if(personArray[i] != NULL)
        {
            delete personArray[i];
        }
    }
    delete [] personArray;
    personArray = NULL;
    }
}

//Opens the file and reads in the data. Creates  Docket, Judge, and Defendant objects and adds them
//into the roster. Note that the Defendant object contains the Docket object.
void Roster::inputFmFile()
{
    
    string blank1;
    string wholeLine;
    string fileName;
    ifstream inStr;
    bool fileWorked = true;
    
    //Opens the file
    do
	{
		cout << "Enter name of file to read from: ";
		getline(cin, fileName);
        
		inStr.open(fileName.c_str());
		if (inStr.fail())
		{
			cerr << "Error opening file. Try again." << endl;
			inStr.clear();
			fileWorked = false;
		}
		else
			fileWorked = true;
	} while (!fileWorked);
    
    //Skips the first few arbitrary lines of data
    for(int i = 0; i < 18; i++)
    {
        getline(inStr, blank1, ',');
    }
    
    getline(inStr, blank1, '\r');
    
    //Reads in the data
    for(int i = 0; i < 60; i++)
    {
        getline(inStr, wholeLine, ',');
        string caseId = wholeLine;
        
        getline(inStr, wholeLine, ',');
        string defName = wholeLine;
        
        getline(inStr, wholeLine, ',');
        string age = wholeLine;
        
        getline(inStr, wholeLine, ',');
        string dob = wholeLine;
        
        getline(inStr, wholeLine, ',');
        string sex = wholeLine;
        
        getline(inStr, wholeLine, ',');
        string race = wholeLine;
        
        getline(inStr, wholeLine, ',');
        string charge6105 = wholeLine;
        
        getline(inStr, wholeLine, ',');
        string charge6106 = wholeLine;
        
        getline(inStr, wholeLine, ',');
        string charge6108 = wholeLine;
        
        getline(inStr, wholeLine, ',');
        string charge907 = wholeLine;
        
        getline(inStr, wholeLine, ',');
        string bail = wholeLine;
        
        getline(inStr, wholeLine, ',');
        string attorney = wholeLine;
        
        getline(inStr, wholeLine, ',');
        string docketNum = wholeLine;
        
        getline(inStr, wholeLine, ',');
        string fileDate = wholeLine;
        
        getline(inStr, wholeLine, ',');
        string judgeName = wholeLine;
        
        getline(inStr, wholeLine, ',');
        string status = wholeLine;
        
        getline(inStr, wholeLine, ',');
        string verdict = wholeLine;
        
        getline(inStr, wholeLine, ',');
        string jail = wholeLine;
        
        getline(inStr, wholeLine, '\r');
        string sentence = wholeLine;
       
        //Creates new objects. Person, Defendant, and Judge objects are dynamic.
        Docket docket = Docket(charge6105, charge6106, charge6108, charge907, bail, attorney, docketNum, fileDate, status, verdict, jail, sentence);
        Defendant* def = new Defendant(defName, age, dob, sex, race, docket);
        Judge* judge = new Judge(judgeName);
        
        personArray[countSize] = judge; //adds the judge into a roster
        countSize++;
        personArray[countSize] = def; //adds the defendant into a roster
        countSize++;
    }
}

//Displays the information of an entire Roster
string Roster::display()
{
    string result = "";
    for(int i = 0; i < countSize; i++)
    {
        result += personArray[i]->display();
    }
    
    return result;
}

//Sets one Roster equal to another Roster
Roster& Roster::operator= (const Roster& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    else //If the calling object is different from the operand, proccessing continues
    {
        if(personArray != NULL) //Frees previous memory
        {
            for(int i = 0; i < arraySize; i++) //Note: arraySize used instead of countSize
            {
                if(personArray[i] != NULL)
                    delete personArray[i];
            }
            delete [] personArray;
        }
        countSize = 0; //countSize is initialized, since a new Person array will be created
        arraySize = rhs.arraySize; //Note: arraySize used instead of countSize
        personArray = new Person*[arraySize + 10];
        
        //Objects are only filled up to the rhs.countSize, not arraySize. rhs.countSize will be used.
        for(int i = 0; i < rhs.countSize; i++)
        {
            personArray[i] = (rhs.personArray[i])->createPointer();
            countSize++;
        }
        return *this;
    }
}

//Adds Person object into the Roster. Supports inheritance.
//Defendants and Judges can be added as well.
void Roster:: add(Person& person)
{
    personArray[countSize] = person.createPointer();
    countSize++;
}

