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

//for operator<< overload, could passed in *& of object so then
//could use object->tracks[i] instead of *object.tracks[i]


#include "WeeklyData.h"
#include "singleDayData.h"

using namespace std;

int main() {
  
   ifstream(myfile1)("primer.txt");// creates a ifstream object connected to the data in primer.txt

   WeeklyData theWeek;
   theWeek.setPrimerData(myfile1);//takes in primer.txt to prime the program to read in the habits the user wants to track
   ifstream myfile2 ("justDate.txt"); //data file with just the dates
   theWeek.setRecordData(myfile2);

   myfile1.close();
   myfile2.close();
}
