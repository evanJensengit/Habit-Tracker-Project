//
//  sleep.cpp
//  accountability_reader
//
//  Created by Evan Jensen on 12/30/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

#include "sleep.h"

//----------------------------------------------------------------------------
//operator<< overload
//calls print(ostream&) method
ostream & operator<<(ostream & output, const Sleep & sleepObj) {
   sleepObj.print(output);
   return output;
}
//----------------------------------------------------------------------------

Sleep::Sleep() {
   wakeTime = 0;
   bedTime = 0;
   dataDescription = "Bedtime/wakeup";
   
}
//----------------------------------------------------------------------------

Sleep::~Sleep() { }


//----------------------------------------------------------------------------

bool Sleep::setData(istream &infile) {
   string sleepTimes;
   getline(infile, sleepTimes, '-');
   bedTime = stoi(sleepTimes);
   infile >> wakeTime;
   getline(infile, sleepTimes);
   
   return true;
}

//----------------------------------------------------------------------------
//print method
ostream& Sleep::print(ostream& output) const {
   output << dataDescription << ": " << wakeTime << "-" << bedTime;
   return output;
}
//----------------------------------------------------------------------------

void Sleep::printDataMemberNames() const {
   cout << dataDescription << endl;
}
//----------------------------------------------------------------------------

Track* Sleep::create() {
   return new Sleep;
}
//----------------------------------------------------------------------------

string Sleep::getDataDescription() {
   return dataDescription;
}
