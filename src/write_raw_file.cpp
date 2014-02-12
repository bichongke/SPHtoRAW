//
//  write_raw_file.cpp
//  
//
//  Created by xiaobao on 2/12/14.
//
//

#include <iostream>
#include <fstream>

#include "write_raw_file.h"

using namespace std;


void write_to_raw(double *src, char* filename, int size){
  ofstream ofs(filename, ios::out | ios::binary);
  if(!ofs){
    cout << "   Can't open " << filename << " file" << endl;
    exit (1);
  }
  
  ofs.write((char*)src, sizeof(double)*size);
}

