#include <string>
#include <sstream>

#include "common.h"
#include <cmath>

using namespace std;

string IntToString(int number)
{
  ostringstream os;
  os << number;
  return os.str();
}

int StringToInt(string str)
{
  istringstream is(str);
  int result;

  is >> result;

  return result;
}


int int_pow(int x, int index){
  int result = 1;
  for(int i = 0; i < index; i++)
    result = result * x;
  return result;
}


double speed_length(double x, double y, double z){
  return(sqrt(x*x+y*y+z*z));
}
