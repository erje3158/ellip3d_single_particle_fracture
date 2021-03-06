//
//  userinput.cpp
//  Jensen_code
//
//  Created by Erik Jensen 8/11/2017.
//  Copyright �� 2017 Erik Jensen. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "userInput.h"

using namespace std;

demInput::~demInput(void)
{
  //cout << endl << endl << "demInput is being destroyed" << endl << endl;
}

//Read data from input file
void demInput::readData(const char * inputFile)
{
  string line; ifstream input(inputFile);
  while ( getline(input,line) )
    {
      if ( line == "$Particle Overlap"  ) { input >> this->maxOverlap ;}
      if ( line == "$DEM Constitutive"  ) { input >> this->youngsMod  ;
                                            input >> this->poisRatio  ;}
      if ( line == "$Time Parameters"   ) { input >> this->timestep   ;
                                            input >> this->totalSteps ;
                                            input >> this->printInt   ;
                                            input >> this->numSnaps   ;}
      if ( line == "$Particle Contact"  ) { input >> this->damping    ;
                                            input >> this->friction   ;}
      if ( line == "$Particle Fracture" ) { input >> this->sigmaComp  ;
                                            input >> this->tensileCrit;
                                            input >> this->fracTough  ;}
    }
  input.close();
}

//Print user inputs for review
void demInput::echoData()
{
  cout << endl << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "SUMMARY OF INPUTS:"                        << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << endl;
  cout << "Particle Overlap:"                         << endl;
  cout << "   maxOverlap     = " << this->maxOverlap  << endl;
  cout << endl;  
  cout << "DEM Constitutive:"                         << endl;
  cout << "   youngsMod      = " << this->youngsMod   << endl;
  cout << "   poisRatio      = " << this->poisRatio   << endl;
  cout << endl;
  cout << "Time Parameters:"                          << endl;
  cout << "   timestep       = " << this->timestep    << endl;
  cout << "   totalSteps     = " << this->totalSteps  << endl;
  cout << "   printInt       = " << this->printInt    << endl;
  cout << "   numSnaps       = " << this->numSnaps    << endl;
  cout << endl;
  cout << "Particle Contact:"                         << endl;
  cout << "   damping        = " << this->damping     << endl;
  cout << "   friction       = " << this->friction    << endl;
  cout << endl;
  cout << "Particle Fracture:"                        << endl;
  cout << "   sigmaComp      = " << this->sigmaComp   << endl;
  cout << "   tensileCrit    = " << this->tensileCrit << endl;
  cout << "   fracTough      = " << this->fracTough   << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << endl << endl << endl;
}

void demInput::checkData()
{
  if (this->youngsMod <= 0.0)
  {
    cout << endl << endl;
    cout << "ERROR! ~~~~~~~~~~~~~~~~" << endl;
    cout << "youngsMod must be > 0" << endl;
    cout << endl << endl;
    exit(0);
  }
  if (this->timestep <= 0.0)
  {
    cout << endl << endl;
    cout << "ERROR! ~~~~~~~~~~~~~~~~" << endl;
    cout << "timestep must be > 0" << endl;
    cout << endl << endl;
    exit(0);
  }
}


