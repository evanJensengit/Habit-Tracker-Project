//
//  sorted.cpp
//  accountability_reader
//
//  Created by Evan Jensen on 9/9/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

#include "weeklydata.h"
weeklydata::weeklydata(ifstream& file) {
   
   
  
 //  day1.displayDay();
   for (int i = 0; i < (sizeof(week)/sizeof(*week)); i++) {
   singleDayData day(file);
      //singleDayData day1 = new singleDayData(ifstream);
      week[i] = day;
   }
}
