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
//setData
//can add another method that takes in the sleep times, use some calculation
//to discern if the sleep times are am/pm
bool Sleep::setData(string theSleepTimes) {
   string delimiter = "-";
   string wakeTimeStr = theSleepTimes.substr(0, theSleepTimes.
                                             find(delimiter));
   wakeTime = stoi(wakeTimeStr);
   
   string bedTimeStr = theSleepTimes.substr(theSleepTimes.
                                            find(delimiter)+1);
   bedTime = stoi(bedTimeStr);
   
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

TrackMetric* Sleep::create() {
   return new Sleep;
}
//----------------------------------------------------------------------------

string Sleep::getDataDescription() {
   return dataDescription;
}
