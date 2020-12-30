//
//  trackfactory.hpp
//  accountability_reader
//
//  Created by Evan Jensen on 12/26/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//
//gotta have an array of linked list or array of BST Tree
#ifndef trackfactory_h
#define trackfactory_h

#include <iostream>
#include "date.h"
#include "Track.h"
#include <vector>
using namespace std;


class TrackFactory {
public:
   static const int MAXSIZE = 47;
   TrackFactory(); //constructor
   ~TrackFactory(); //destructor deallocates actions data member
   
   //creates action and maps action to actions hash table data member
   Track* createTrack(string) const;
protected:
   Track* tracks[MAXSIZE]; // stores available
   int hash(string) const;
};

#endif /* trackfactory_hpp */
