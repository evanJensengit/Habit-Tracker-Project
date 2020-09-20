//
//  singleDayData.hpp
//  accountability_reader
//
//  Created by Evan Jensen on 9/9/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

//data read in is in the format of:
//Week: sept 7 - 14
//Date: sept 12
//Weekday: sat
//Time: 113 am
//Wrkt: no
//Bedtime/wake up: 12 - 2
//Chapters of bible read: matt 6
//Study csci: no
//Therapy work: no
//Meditation: y 12 mins breath
//Full body stretching: no
//Connection: call maurice
//Journaling: y
//^this is followed by 6 more day entries
//
//if there is a day but no entries for that day
//the day will be assumed to have not been logged
//if there is not AT LEAST 7 outlines of the day e.g
//"Date:
//Weekday:
//...."
//the program will reject the data and will print to the console
//"insufficient data inputted" 


#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#ifndef singleDayData_h
#define singleDayData_h

class singleDayData {
public:
   singleDayData();
   singleDayData(ifstream&);
   singleDayData createDay(ifstream&);
private:
   string day[11];
   
};
#include <stdio.h>

#endif /* singleDayData_h */
