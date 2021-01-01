//
//  sorted.hpp
//  accountability_reader
//
//  Created by Evan Jensen on 9/9/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

//how can we have the data output as a table?


#ifndef weeklydata_h
#define weeklydata_h
#include <fstream>
#include <stdio.h>
#include <string>
#include <iostream>
#include "singleDayData.h"
using namespace std;

class WeeklyData {
   friend ostream& operator<<(ostream&, const WeeklyData& );
public:
   static const int WEEK_LENGTH = 7;
   WeeklyData();
   ~WeeklyData();
   void setRecordData(ifstream&);
   void setPrimerData(ifstream&);
   void sortAndLogData();
  
   

private:
   singleDayData* week[WEEK_LENGTH];
   string weekDate;
   void displayWeek();
   void logData(const WeeklyData&);
};
#endif /* sorted_hpp */
