// Filename: BinaryFileRecord.h
// Date: 04/30/2020
// Author: Jason Lim
// Class: CS 3377.501, Spring 2020
// Version: 1.0
// Copyright: 2020, All Rights Reserved.
//
// Description: This file contains the class used to read the records from the binary file that don't include the header.


#ifndef BINARYFILERECORD_H
#define BINARYFILERECORD_H

#include<stdint.h>
using namespace std;

const int maxRecordStringLength = 25;

class BinaryFileRecord
{

public:

uint8_t strLength;
char stringBuffer[maxRecordStringLength];


};


#endif
