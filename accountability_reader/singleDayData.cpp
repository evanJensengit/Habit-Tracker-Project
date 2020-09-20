//
//  singleDayData.cpp
//  accountability_reader
//
//  Created by Evan Jensen on 9/9/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

#include "singleDayData.h"

singleDayData::singleDayData() {
   
}

singleDayData::singleDayData(ifstream& file) {
   string line;
   if (file.is_open())
   {
      getline(file, line);
      while ( line != "---------")
      {
         getline(file, line);
         cout << line << endl;
         for (int i = 0; i < 11; i++) {
            day[i] = line; 
         }
         
      }
     
   }
   
   else cout << "Unable to open file";
}

singleDayData singleDayData::createDay(ifstream& file) {
   singleDayData day;
   return day;
}
