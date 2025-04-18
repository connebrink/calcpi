
#include <iostream>
#include <string>
#include <math.h>

const int R_SUCCESS = 0;
const int R_INVALID_CONDITIONS = -1;

using namespace std;

enum CalcPiType {
  CON_VIETE,
  CON_LEIBNIZ,
  CON_EULER,
  CON_RAMA,
  GRP_NORMAL,
  GRP_MONTECARLO
};

struct CalcRunConditions {
  CalcPiType type;
  long iterations;
  bool isComplete;
};

CalcRunConditions readRunConditions(int argCount, char argStr) {
  CalcRunConditions runConditions;
  runConditions.isComplete = false;
  return runConditions;
}

void printHelp() {
  cout << "calcpi -t:<type> -n:<iterations>\n";
}

int main(int argc, char *argv[])
{
  auto runConditions = readRunConditions(argc, argc);
  if (runConditions.isComplete == false) {
    printHelp();
    return R_INVALID_CONDITIONS;
  }
  return R_SUCCESS;
}
