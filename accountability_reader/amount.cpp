//
//  amount.cpp
//  accountability_reader
//
//  Created by Evan Jensen on 1/2/21.
//  Copyright © 2021 Evan Jensen. All rights reserved.
//

#include "amount.h"
//----------------------------------------------------------------------------
//operator<< overload
//calls print(ostream&) method
ostream & operator<<(ostream & output, const Amount & AmountObj) {
   AmountObj.print(output);
   return output;
}
//----------------------------------------------------------------------------

Amount::Amount() {
   dataDescription = "Amount";
   amount = 0;
   metricOfAmount = "";
   
}
//----------------------------------------------------------------------------

Amount::~Amount() { }


//----------------------------------------------------------------------------

bool Amount::setData(string amountString) {
   
   size_t found = amountString.find(" ");
   string readAmount;
   if (found != string::npos) {
      readAmount = amountString.substr(0, found);
      amount = stoi(readAmount);
      //+ 1 so it doesnt include the space
      metricOfAmount = amountString.substr(found + 1);
      return true;
   }
   return false;
}

//----------------------------------------------------------------------------
//print method
ostream& Amount::print(ostream& output) const {
   output << dataDescription << ": " << amount << metricOfAmount;
   return output;
}
//----------------------------------------------------------------------------

void Amount::printDataMemberNames() const {
   cout << dataDescription << endl;
}
//----------------------------------------------------------------------------

TrackMetric* Amount::create() {
   return new Amount;
}
//----------------------------------------------------------------------------

string Amount::getDataDescription() {
   return dataDescription;
}

