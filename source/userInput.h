#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class demInput
{
public:
  double maxOverlap;

  double youngsMod;
  double poisRatio;

  double timestep;
  int totalSteps;
  int printInt;
  int numSnaps;

  double damping;
  double friction;

  double sigmaCrit;
  double sigmaComp;
  double tensileCrit;
  double sigmaF;

  demInput()
  {
    maxOverlap   = 0.0;

    youngsMod    = 0.0;
    poisRatio    = 0.0;

    timestep     = 0.0;
    totalSteps   =   0;
    printInt     =   0;
    numSnaps     =   0;

    damping      = 0.0;
    friction     = 0.0;

    sigmaCrit    = 0.0;
    sigmaComp    = 0.0;
    tensileCrit  = 0.0;
    sigmaF       = 0.0;
  }

  ~demInput();

  void readData(const char * inputFile);
  void echoData();
  void checkData();

};
