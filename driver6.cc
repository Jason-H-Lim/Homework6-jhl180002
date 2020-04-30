/*
 * File:   driver6.cc
 * Author: Jason Lim
 * Email:  jlh180002@utdallas.edu
 * Class:  CS 3377.501, Spring 2020
 * Version: 1.0
 * Copyright: 2020, All Rights Reserved
 *
 * Description: This program creates a 5x3 matrix containing records obtained from a binary file.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "cdk.h"
#include "binaryHeader.h"
#include "binaryRecord.h"
#include <boost/lexical_cast.hpp>

#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;

extern string toHex(int magicNum);

int main()
{

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix
  stringstream ss; // String stream object used to manipulate data from the binary file
 
  const char 	*rowTitles[MATRIX_HEIGHT + 1] = {"A0", "a", "b", "c", "d", "e"}; // Holds the name of each row
  const char 	*columnTitles[MATRIX_WIDTH + 1] = { "CO", "a", "b", "c"}; // Holds the name of each column
  int		boxWidths[MATRIX_WIDTH + 1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH}; // Holds the size of each cell in the matrix
  int		boxTypes[MATRIX_WIDTH + 1] = {vMIXED, vMIXED, vMIXED, vMIXED}; // Holds what kind of data is held in each cell

  BinaryFileHeader *record = new BinaryFileHeader(); // Pointer to the BinaryFileHeader class defined in binaryHeader.h
  
  BinaryFileRecord *record2 = new BinaryFileRecord(); // Pointer to the BinaryFileRecord class defined in binaryRecord.h

  ifstream binaryFile ("/scratch/perkins/cs3377.bin", ios::in | ios::binary); // ifstream object to read in the data from the binary file
  
  binaryFile.read((char *) record, sizeof(BinaryFileHeader)); // Reading the header record from the binary file

  string magicNum, version, records; // Local variables to hold the data from the binary file originally defined the BinaryFileHeader class
  
  int numStr = record->numRecords; // Holds the total number of records in the binary file
  
  if(numStr > 4){ // If the number of records is greater than 4, have the matrix only display the first 4 records.
   numStr = 4;
  }


  window = initscr(); // Initializing the CDK screen
  cdkscreen = initCDKScreen(window);

  initCDKColor(); // Giving the CDK screen some color

  // Creating the actual matrix.
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,
			  MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
			  boxTypes, 1, 1, ' ', ROW, true, true, false);

  // If the matrix cannot be created
  if (myMatrix == NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  int temp = record->magicNumber; // Local variable to hold the magic number record from the binary file
  string result = toHex(temp);

  // Creating variables to hold the header record from the binary file
  magicNum = "Magic: " + result;
  version = "Version: " + boost::lexical_cast<string>(record->versionNumber);
  records = "NumRecords: " + boost::lexical_cast<string>(record->numRecords);
 
  // Variables used to display certain values in certain cells of the matrix
  int lenCellrow = 2, lenCellcol = 1, strCell = 2;
  
  int counter = 0; // Counter to display all the non-header records
 
  while(counter < numStr){ // While 4 non-header records have not been read

   binaryFile.read((char *) record2, sizeof(BinaryFileRecord)); // Read each non-header record
   int strLength = record2->strLength; 
   string str = "", stringlen = "";
   for(int i = 0; i < strLength; i++) // Iterate through each character for each string and add them to another string
   {
    
    str += record2->stringBuffer[i];

   }
   
   stringlen = "strlen: " + boost::lexical_cast<string>(strLength); // Save the length of each string in stringlen

   setCDKMatrixCell(myMatrix, lenCellrow, lenCellcol, stringlen.c_str()); // Add stringlen to each expected matrix position
   setCDKMatrixCell(myMatrix, lenCellrow++, strCell, str.c_str()); // Add the string itself to each expected matrix position
   
   counter++; // Increase the number of strings read from the binary file
  }
  
  setCDKMatrixCell(myMatrix, 1, 1, magicNum.c_str()); // Add the magic number in the cell at (1,1)
  setCDKMatrixCell(myMatrix, 1, 2, version.c_str()); // Add the version number in the cell at (1,2)
  setCDKMatrixCell(myMatrix, 1, 3, records.c_str()); // Add the number of records in the cell at (1,3)
  
  drawCDKMatrix(myMatrix, true); // Draw the matrix with the values inside
  
  binaryFile.close(); // Close the input stream from the binary file

  // Clearing the memory by deleting the pointers to each record class
  delete record;
  delete record2;
  
  sleep (5); // Pause the screen to display the matrix

  endCDK(); // End the program to display the matrix

  return 0;
} // End the program
