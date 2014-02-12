====================================================================================
Usage:
sph2raw    vel_00000    25500       500      10

"sph2raw"    : execute file
"vel_00000"  : the common parts of datasets
"25500"      : the start time step of dataset
"500"        : the interval size between 2 neighbour time steps
"10"         : the number of time step that you want to convert from sph to raw

====================================================================================
NOTICE:

BEFORE make or make install
-----------------------------------------------------------------------
Please change the definition of ENDIAN_TYPE according to your dataset.
0 : big endian
1 : little endian

-----------------------------------------------------------------------
You can also change the directory in define.h



