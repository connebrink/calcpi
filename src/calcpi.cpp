
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

const int R_SUCCESS = 0;
const int R_INVALID_CONDITIONS = -1;

using namespace std;

enum CalcPiType {
  CON_VIETE,
  CON_LEIBNIZ,
  CON_EULER,
  CON_RAMA,
  GRP_NORMAL,
  GRP_MONTECARLO,
  UNKNOWN
};

struct CalcRunConditions {
  CalcPiType type;
  long iterations;
  bool showGraph;
  bool isComplete;
};

CalcRunConditions readRunConditions(int argCount, char **argStr) {
  CalcRunConditions runConditions;
  runConditions.type = CalcPiType::UNKNOWN;
  runConditions.iterations = 0;
  runConditions.isComplete = false;
  runConditions.showGraph = false;
  for (int i = 0; i < argCount; ++i) {
    string param {argStr[i]};
    transform(param.begin(), param.end(), param.begin(),
	      [](auto c){return tolower(c);});
    if (param.find("-t:") != string::npos) {
      string cType {param.substr(3,param.length())};
      if (cType == "viete")
	runConditions.type = CalcPiType::CON_VIETE;
      if (cType == "leibniz")
	runConditions.type = CalcPiType::CON_LEIBNIZ;
      if (cType == "euler")
	runConditions.type = CalcPiType::CON_EULER;
      if (cType == "rama")
	runConditions.type = CalcPiType::CON_RAMA;
      if (cType == "normal")
	runConditions.type = CalcPiType::GRP_NORMAL;
      if (cType == "montecarlo")
	runConditions.type = CalcPiType::GRP_MONTECARLO;
    }
    if (param.find("-n:") != string::npos)
      runConditions.iterations = stol(param.substr(3,param.length()));
    if (param.find("-g") != string::npos)
      runConditions.showGraph = true;
  }
  return runConditions;
}

void printHelp() {
  cout << "calcpi -t:<type> -n:<iterations> -g\n";
}

int main(int argc, char *argv[])
{
  auto runConditions = readRunConditions(argc, argv);
  if (runConditions.isComplete == false) {
    printHelp();
    return R_INVALID_CONDITIONS;
  }
  return R_SUCCESS;
}
