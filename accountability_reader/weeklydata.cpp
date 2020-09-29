//
//  sorted.cpp
//  accountability_reader
//
//  Created by Evan Jensen on 9/9/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//
//overload the cout for the week and the day
#include "weeklydata.h"

weeklydata::weeklydata() {}

weeklydata::weeklydata(ifstream& file) {
   string line;
   getline(file, line);
   
   weekDate = line;
   
   for (int i = 0; i < weekSize; i++) {
      singleDayData day(file);
      week[i] = day;
      
      //singleDayData day1 = new singleDayData(ifstream); is this necessary?
   }
}

void weeklydata::startProgram(ifstream& file) {
   weeklydata week(file);
   
}

void weeklydata::displayWeek() {
   for (int i = 0; i < weekSize; i++) {
     week[i].displayDay();
   }
}


