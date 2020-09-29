//
//  sorted.cpp
//  accountability_reader
//
//  Created by Evan Jensen on 9/9/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//
//overload the cout for the week and the day
#include "weeklydata.h"

ostream& operator<<(ostream& output, const weeklydata& dt) {
   for (int i = 0; i < dt.weekSize; i++) {
      output << dt.week[i] << endl;
   }
   return output;
}

//----------------------------------------------------------------------------
weeklydata::weeklydata() {}

//----------------------------------------------------------------------------
weeklydata::weeklydata(ifstream& file) {
   string line;
   if (file.is_open())
   {
   getline(file, line);
   
   weekDate = line;
   
   for (int i = 0; i < weekSize; i++) {
      singleDayData day(file);
      week[i] = day;
      //singleDayData day1 = new singleDayData(ifstream); is this necessary?
      }
   }
   else cout << "Unable to open file";
}

//----------------------------------------------------------------------------
void weeklydata::startProgram(ifstream& file) {
   weeklydata week(file);
   cout << week << endl;
}

//----------------------------------------------------------------------------
void weeklydata::displayWeek() {
   for (int i = 0; i < weekSize; i++) {
      week[i].displayDay();
   }
}

//----------------------------------------------------------------------------
//log the week data
void weeklydata::logData(const weeklydata& currentWeek) {
   ofstream myOfile;
   myOfile.open ("accountability.txt", std::ios_base::app);
   myOfile.close();
}


