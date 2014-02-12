#ifndef _READ_SPH_H_
#define _READ_SPH_H_

#include <iostream>

using namespace std;


bool read_one_sph_file(char* filename, double *var, int size);
int get_size(char* filename);

#endif
