// Filename: hexUtility.cc
// Date: 04/30/2020
// Author: Jason Lim
// Class: Cs 3377.501, Spring 2020
// Version: 1.0
// Copyright: 2020, All Rights Reserved.
//
// Description: This source file holds a function that converts the magic number from the binary file to a hexadecimal value.

#include <sstream>
using namespace std;

string toHex(int magicNum)
{

stringstream ss;

ss << "0x" << std::uppercase <<  std::hex << magicNum; // Add an 0x to the front and convert the integer value to a hexadecimal value

string result = ss.str(); // Convert the hexadecimal to a string hexadecimal

return result; // Return the string hexadecimal
}
