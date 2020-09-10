//
//  sorted.hpp
//  accountability_reader
//
//  Created by Evan Jensen on 9/9/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

//how can we have the data output as a table?

#ifndef sorted_hpp
#define sorted_hpp
#include <fstream>
#include <stdio.h>
#include "singleDayData.h"

using namespace std;
class weeklydata {
public:
   weeklydata();
   weeklydata sortFile(ifstream);  //takes in file to be read
                              //sorted function creates
                              //a sorted class object that
                              //will display the week
private:
   
   int daysLogged;
   
   

};
#endif /* sorted_hpp */
