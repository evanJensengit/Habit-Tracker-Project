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
WeeklyData::WeeklyData(ifstream& file) { }

void WeeklyData::setData(ifstream& file) {
   string line;
   if (file.is_open())
   {
      for (int i = 0; i < WEEK_LENGTH; i++) {
         singleDayData* day = new singleDayData(file);
         //cout << *day;
         week[i] = day;
         if (file.eof()) break;
      }
   }
   else cout << "Unable to open file";
}


//----------------------------------------------------------------------------
void WeeklyData::startProgram(ifstream& file) {
   setData(file);
   cout << *this;
   
   //logData
}

//----------------------------------------------------------------------------
void WeeklyData::displayWeek() {
   for (int i = 0; i < WEEK_LENGTH; i++) {
      week[i]->displayDay();
   }
}

//----------------------------------------------------------------------------
//log the week data
void WeeklyData::logData(const WeeklyData& currentWeek) {
   ofstream myOfile;
   myOfile.open ("accountability.txt", std::ios_base::app);
   myOfile.close();
}


