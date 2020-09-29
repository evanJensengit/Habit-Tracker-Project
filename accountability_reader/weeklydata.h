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
#include "singleDayData.h"
#include <string>
using namespace std;

class weeklydata {
public:
   weeklydata();
   weeklydata(ifstream&);
   weeklydata sortFile(ifstream&);
   void startProgram(ifstream&);
   

private:
   singleDayData week[7];
   int weekSize;
   string weekDate;
   void displayWeek();

};
#endif /* sorted_hpp */
