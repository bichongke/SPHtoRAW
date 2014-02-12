//
//  sph_to_raw.cpp
//  
//
//  Created by chongke bi on 2/10/14.
//
//

#include <iostream>
#include "sph_to_raw.h"
#include "common.h"

using namespace std;

void convert_sph_to_raw(double *src, double *dest, int size){
  for(int i = 0; i < size; i++)
    dest[i] = speed_length(src[i*3], src[i*3+1], src[i*3+2]);
}