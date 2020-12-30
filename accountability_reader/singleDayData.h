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




#ifndef singleDayData_h
#define singleDayData_h
#include <string>
#include <iostream>
#include <fstream>
#include "trackfactory.h"

using namespace std;
static const int NUMBER_OF_TRACKS = 1;

class singleDayData {
   friend ostream& operator<<(ostream&, const singleDayData& );
public:
   singleDayData();
   ~singleDayData();
   singleDayData(ifstream&);
   singleDayData createDay(ifstream&);
   //singleDayData& operator=(const singleDayData&);
   void displayDay();
   string* getDay();
private:
   Track* tracks[NUMBER_OF_TRACKS];
   TrackFactory trackFactory;
};


#endif /* singleDayData_h */
