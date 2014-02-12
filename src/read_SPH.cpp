#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdlib.h>

#include "sph.h"
#include "define.h"

using namespace std;

bool read_one_sph_file(char* filename, double *var, int size){
  int dType = 0;
  // Make instance
  SPH P;
  
  float *temp = new float[size];
  
  ifstream ifs_data(filename, ios::in | ios::binary);
  P.readFile_simple(ifs_data, temp, size);
  ifs_data.close();
  
  for(int i = 0; i < size; i++)
    var[i] = temp[i];
  
  delete []temp;

  return true;
}


int get_size(char* filename){
  int dType = 0;
  // Make instance
  SPH P;
  
  // Scan header
  ifstream ifs(filename, ios::in | ios::binary);
  if (!ifs) {
    cout << "   Can't open " << filename << " file" << endl;
    return 0;
  }
  if ( -1 == (dType=P.scanHeader_special(ifs, 0)) ) {
    cout << "\tHeader error\n" << endl;
    return -1;
  }
  ifs.close();

  int result = (int)(P.nmax/3);
  return result;
}
