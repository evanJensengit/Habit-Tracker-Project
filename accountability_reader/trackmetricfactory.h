//
//  trackfactory.hpp
//  accountability_reader
//
//  Created by Evan Jensen on 12/26/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

#ifndef trackmetricfactory_h
#define trackmetricfactory_h

#include <iostream>
#include "date.h"
#include "sleep.h"
#include "trackMetric.h"
#include <vector>
using namespace std;


class TrackMetricFactory {
public:
   static const int MAXSIZE = 47;
   TrackMetricFactory(); //constructor
   ~TrackMetricFactory(); //destructor deallocates actions data member
   
   //creates action and maps action to actions hash table data member
   TrackMetric* createTrackMetric(string) const;
protected:
   TrackMetric* trackMetrics[MAXSIZE]; // stores available
   int hash(string) const;
};

#endif /* trackfactory_hpp */
