#ifndef _SPH2FDV_SPH_H_
#define _SPH2FDV_SPH_H_

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <unistd.h>
#include <stdlib.h>

#include "define.h"

using namespace std;


class SPH {
private:
	int		dType;
	float ox, oy, oz, dx, dy, dz;
	
public:
	int		ix, jx, kx, svType;
	unsigned int  nmax;
	int endian_t;
		
public:
	SPH() {
		ix = jx = kx = svType = dType = 0;
		nmax = 0;
		ox = oy = oz = dx = dy = dz = 0.0;
		endian_t = ENDIAN_TYPE;//0:change, 1:dont change
	}
	
	int scanHeader(ifstream &ifs, int number);
	int scanHeader_special(ifstream &ifs, int number);

	bool readFile_simple(ifstream &ifs, float* var, int unit);
	unsigned int getSize(void) { return nmax;	}
	void min_max(int nmax, float *var);
	void writeFile(ofstream &ofs, int &step, float &time, float* var);
};

#endif // _SPH2FDV_SPH_H_
