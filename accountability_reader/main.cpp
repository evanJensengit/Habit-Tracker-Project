//
//  main.cpp
//  accountability_reader
//
//  Created by Evan Jensen on 9/9/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//
//it has to be submitted in the google doc in a practical way
//to avoid redundant functions to deal with the data
//somehow pull the time from online so that it updates weekly with
//data of this last week.




#include "WeeklyData.h"
#include "singleDayData.h"

using namespace std;

int main() {
  
   string line;
   ifstream(myfile1)("primer.txt");

   WeeklyData theWeek;
   theWeek.setPrimerData(myfile1);
   ifstream myfile2 ("justDate.txt");
   theWeek.startProgram(myfile2);

   myfile1.close();
   myfile2.close();
}
