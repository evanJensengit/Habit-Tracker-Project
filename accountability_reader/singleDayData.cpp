//
//  singleDayData.cpp
//  accountability_reader
//
//  Created by Evan Jensen on 9/9/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//
//make the data a good case and get that working first
//in the week we have to pull the week from the first line and then
//pass the file to the singleDayData constructor

#include "singleDayData.h"

singleDayData::singleDayData() {
   for (int i = 0; i < daySize; i++) {
   }
}

singleDayData::singleDayData(ifstream& file) {
   string line;
   
   if (file.is_open())
   {
      
      //getline(file, line); to get the week
      int count = 0;
      while ( line != "---------")
      {
         getline(file, line);
         cout << line << endl;
//         for (int i = 0; i < 11; i++) {
//            day[i] = line;
//         }
         day[count] = line;
         count++;
         
         
      }
     
   }
   else cout << "Unable to open file";
}

//to be cont create day
singleDayData singleDayData::createDay(ifstream& file) {
   singleDayData day;
   return day;
}

//operator= overload
singleDayData& singleDayData::operator=(const singleDayData& toCopy) {
   if (&toCopy != this) {
      for (int i = 0; i < daySize; i++) {
         day[i] = toCopy.day[i];
      }
   }
   return *this;
}
//display day
//displays the day 
void singleDayData::displayDay() {
   for (int i = 0; i < daySize; i++) {
      cout << day[i] << endl;
   }
}



