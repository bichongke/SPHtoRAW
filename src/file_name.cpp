//
//  file_name.cpp
//  
//
//  Created by xiaobao on 2/12/14.
//
//

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include "file_name.h"
#include "common.h"
#include "define.h"


using namespace std;

string getFileName(char *input_basename, char *start, char *interval, int order, int mode){

  string temp_str;
  int temp_length1, temp_length2;
  
  string filename;
  string suffix;
  if(!mode){
    suffix = ".sph";
    filename = SPH_FILE_NAME;
  }
  else{
    suffix = ".raw";
    filename = RAW_FILE_NAME;                      //first part
  }
  
  filename.append(input_basename);                 //second part
  
  temp_str = start;
  int star = StringToInt(temp_str);
  temp_length1 = temp_str.length();
  
  temp_str = interval;
  int inte = StringToInt(temp_str);
  
  int timestep_int = star + inte * order;
  temp_str = IntToString(timestep_int);
  temp_length2 = temp_str.length();
  
  for(int i = 0; i < (temp_length1-temp_length2); i++)
    filename.append("0");                           //third part-I

  filename.append(temp_str);                        //third part-II
  
  filename.append(suffix);                          //final (fourth) part
  
  return filename;  
}

