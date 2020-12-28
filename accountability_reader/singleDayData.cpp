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
ostream& operator<<(ostream& output , const singleDayData& dt ) {
   for (int i = 0; i < NUMBER_OF_TRACKS; i++) {
      output << dt.tracks[i] << endl;
   }
   return output;
}

//----------------------------------------------------------------------------
singleDayData::singleDayData() {}

//----------------------------------------------------------------------------
singleDayData::singleDayData(ifstream& infile) {
   string trackType;
   string badInput;
   bool success;
   if (infile.is_open())
   {
     for (int i = 0; i < NUMBER_OF_TRACKS; i++) {
        getline(infile, trackType, ':');
        if (infile.eof()) break;
        Track* ptr = trackFactory.createTrack(trackType);
        if (ptr == nullptr) {
           getline(infile, badInput);
        }
        else {
           success = ptr->setData(infile);
           if (!success) {
              getline(infile, badInput);
           }
           else if(success) {
              tracks[i] = ptr;
           }
        }
     }
     
   }
   else cout << "Unable to open file";
}

//----------------------------------------------------------------------------
//to be cont create day
singleDayData singleDayData::createDay(ifstream& file) {
   singleDayData day;
   return day;
}

//----------------------------------------------------------------------------
//operator= overload
//singleDayData& singleDayData::operator=(const singleDayData& toCopy) {
//   if (&toCopy != this) {
//      for (int i = 0; i < NUMBER_OF_TRACKS; i++) {
//         tracks[i] = toCopy.day[i];
//      }
//   }
//   return *this;
//}
//----------------------------------------------------------------------------
//display day
//displays the day 
void singleDayData::displayDay() {
   for (int i = 0; i < NUMBER_OF_TRACKS; i++) {
      cout << tracks[i] << endl;
   }
}



