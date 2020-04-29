// Filename: binaryHeader.h
// Date: 04/30/2020
// Author: Jason Lim
// Email: jhl180002@utdallas.edu
// Class: CS 3377.501, Spring 2020
// Version: 1.0
// Copyright: All Rights Reserved
//
// Description: This header file holds two classes that are used to receive the header and// and record from the binary file.
//

#ifndef BINARYHEADER_H
#define BINARYHEADER_H

#include <stdint.h>
using namespace std;

class BinaryFileHeader
{

public:

 uint32_t magicNumber;
 uint32_t versionNumber;
 uint64_t numRecords;

};


#endif
