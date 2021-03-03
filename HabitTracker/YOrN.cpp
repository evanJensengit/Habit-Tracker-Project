//
//  YOrN.cpp
//  accountability_reader
//
//  Created by Evan Jensen on 1/2/21.
//  Copyright © 2021 Evan Jensen. All rights reserved.
//

#include "YOrN.h"
//----------------------------------------------------------------------------
//operator<< overload
//calls print(ostream&) method
ostream & operator<<(ostream & output, const YOrN & YOrNObj) {
   YOrNObj.print(output);
   return output;
}
//----------------------------------------------------------------------------

YOrN::YOrN() {
   dataDescription = "YOrN";
   yesOrNo = "";
   
}
//----------------------------------------------------------------------------

YOrN::~YOrN() { }


//----------------------------------------------------------------------------

bool YOrN::setData(string y_or_n) {
   yesOrNo = y_or_n;
   return true;
}

//----------------------------------------------------------------------------
//print method
ostream& YOrN::print(ostream& output) const {
   output << dataDescription << ": " << yesOrNo;
   return output;
}
//----------------------------------------------------------------------------

void YOrN::printDataMemberNames() const {
   cout << dataDescription << endl;
}
//----------------------------------------------------------------------------

TrackMetric* YOrN::create() {
   return new YOrN;
}
//----------------------------------------------------------------------------

string YOrN::getDataDescription() {
   return dataDescription;
}

string YOrN:: getYesOrNo () const {
   return yesOrNo;
}
