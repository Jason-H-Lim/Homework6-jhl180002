/*
 * Usage of CDK Matrix
 *
 * File:   example1.cc
 * Author: Jason Lim
 * Email:  jlh180002@utdallas.edu
 * Class:  CS 3377.501, Spring 2020
 * Version: 1.0
 * Copyright: 2020, All Rights Reserved
 *
 * Description: This program creates a 5x3 matrix containing records from a binary file
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "cdk.h"
#include "binaryHeader.h"

#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;

int main()
{

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix
  stringstream ss;
  int temp = 0;

  const char 		*rowTitles[MATRIX_HEIGHT + 1] = {"A0", "a", "b", "c", "d", "e"};
  const char 		*columnTitles[MATRIX_WIDTH + 1] = { "CO", "a", "b", "c"};
  int		boxWidths[MATRIX_WIDTH + 1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH + 1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  BinaryFileHeader *record = new BinaryFileHeader();

  ifstream binaryFile ("/scratch/perkins/cs3377.bin", ios::in | ios::binary);

  binaryFile.read((char *) record, sizeof(BinaryFileHeader));

  string magicNum, version, records; 

  /*
   * Initialize the Cdk screen.
   *
   * Make sure the putty terminal is large enough
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix.  Need to manually cast (const char**) to (char **)
  */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,
			  MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
			  boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix == NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);

  /*
   * Display a message
   */
  
  temp = record->magicNumber;
  

  ss << "0x" << std::uppercase << std::hex << temp;

  string result = ss.str();

  magicNum = "Magic: " + result;
  version = "Version: " + boost::lexical_cast<string>(record->versionNumber);
  records = "NumRecords: " + boost::lexical_cast<string>(record->numRecords);
  
  setCDKMatrixCell(myMatrix, 1, 1, magicNum.c_str());
  setCDKMatrixCell(myMatrix, 1, 2, version.c_str());
  setCDKMatrixCell(myMatrix, 1, 3, records.c_str());

  drawCDKMatrix(myMatrix, true);    /* required  */
  
  binaryFile.close();
  /* so we can see results */
  sleep (5);


  // Cleanup screen
  endCDK();
}
