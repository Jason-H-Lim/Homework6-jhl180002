// Filename: BinaryFileRecord.h
// Date: 04/30/2020
// Author: Jason Lim
// Class: CS 3377.501, Spring 2020
// Version: 1.0
// Copyright: 2020, All Rights Reserved.
//
// Description: This file contains a class along with class variables that are used to read the non-header records from the binary file.


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
