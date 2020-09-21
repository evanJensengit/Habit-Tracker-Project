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




#include "weeklydata.h"
#include "singleDayData.h"

using namespace std;

int main() {
   
   
   ofstream myOfile;
   myOfile.open ("accountability.txt", std::ios_base::app);
   myOfile.close();
  
   string line;
   ifstream myfile ("accountabilityInput.txt");
   singleDayData day(myfile);
   
   singleDayData day1;
   day1.displayDay();
   
   
   
   
   
   if (myfile.is_open())
   {
      while ( getline (myfile, line) )
      {
         cout << line << '\n';
      }
      myfile.close();
   }
   
   else cout << "Unable to open file";

   
   return 0;
}