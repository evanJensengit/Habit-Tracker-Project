//
//  sorted.cpp
//  accountability_reader
//
//  Created by Evan Jensen on 9/9/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//
//overload the cout for the week and the day did it!!
//get the last entry first and the first entry last
//why do "new" why is that helpful? is it just to prevent stack overflow?

#include "WeeklyData.h"

ostream& operator<<(ostream& output, const WeeklyData& dt) {
   for (int i = 0; i < dt.WEEK_LENGTH; i++) {
      output << *dt.week[i] << endl;
   }
   return output;
}

//----------------------------------------------------------------------------
WeeklyData::WeeklyData() {}

WeeklyData::~WeeklyData() {
   for (int i = 0; i < WEEK_LENGTH; i++) {
      delete week[i];
      week[i] = nullptr;
   }
}



//----------------------------------------------------------------------------

void WeeklyData::setPrimerData(ifstream& file) {
   string line;
   if (file.is_open()) {
      singleDayData* day = new singleDayData(file);
      week[0] = day;
      for (int i = 1; i < WEEK_LENGTH - 1; i++) {
         //then have a copy constructor where we pass in Day
         week[i] = new singleDayData(day);
         if (file.eof()) break;
      }
   displayWeek();
   }
   else cout << "Unable to open file";
}

//----------------------------------------------------------------------------

void WeeklyData::setRecordData(ifstream & infile) {
   
}
//----------------------------------------------------------------------------
void WeeklyData::sortAndLogData() {
   
}
//----------------------------------------------------------------------------
//displayWeek
void WeeklyData::displayWeek() {
cout << *this << endl;
   //   for (int i = 0; i < WEEK_LENGTH; i++) {
//      week[i]->displayDay();
//   }
}

//----------------------------------------------------------------------------
//log the week data
void WeeklyData::logData(const WeeklyData& currentWeek) {
   ofstream myOfile;
   myOfile.open ("accountability.txt", std::ios_base::app);
   myOfile.close();
}


