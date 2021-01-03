//
//  trackMetric.cpp
//  accountability_reader
//
//  Created by Evan Jensen on 12/31/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

#include "trackMetric.h"

//----------------------------------------------------------------------------
// operator<<
ostream& operator<<(ostream& output, const TrackMetric& dataObj) {
   dataObj.print(output);
   return output;
}

TrackMetric::TrackMetric() { }

TrackMetric::~TrackMetric() { }


