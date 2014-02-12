#include "sph.h"
#include "endian_change.h"

using namespace std;

int SPH::scanHeader(ifstream &ifs, int number)
{
  int dummy;

  if(endian_t){
    ifs.read((char*)&dummy,sizeof(int));
    ifs.read((char*)&svType,sizeof(int));
    ifs.read((char*)&dType,sizeof(int));
    ifs.read((char*)&dummy,sizeof(int));
  }else{
   ifs.read(reinterpret_cast<char*>(&dummy),sizeof(int));      endswap(&dummy);
   ifs.read(reinterpret_cast<char*>(&svType),      sizeof(int));      endswap(&svType);
   ifs.read(reinterpret_cast<char*>(&dType),sizeof(int));      endswap(&dType);
   ifs.read(reinterpret_cast<char*>(&dummy),sizeof(int));      endswap(&dummy);
  }
  //  printf("\tsv=%d d=%d %d  \n",svType, dType, dummy);
  
  
  switch (dType) {
  case SINGLE:
    if(endian_t){
      ifs.read((char*)&dummy,sizeof(int));
      ifs.read((char*)&ix,sizeof(int));
      ifs.read((char*)&jx,sizeof(int));
      ifs.read((char*)&kx,sizeof(int)); 
      ifs.read((char*)&dummy, sizeof(int));
    }else{
     ifs.read(reinterpret_cast<char*>(&dummy),sizeof(int));     endswap(&dummy);
     ifs.read(reinterpret_cast<char*>(&ix),        sizeof(int));     endswap(&ix);
     ifs.read(reinterpret_cast<char*>(&jx),sizeof(int));     endswap(&jx);
     ifs.read(reinterpret_cast<char*>(&kx),sizeof(int));     endswap(&kx);
     ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));           endswap(&dummy);
    }
    nmax = (unsigned int) (ix * jx * kx);
    break;
  case DOUBLE:
    long lix, ljx, lkx;
    cout << "\tlong case" << endl;
    if(endian_t){
      ifs.read((char*)&dummy,sizeof(int));
      ifs.read((char*)&lix,sizeof(long));
      ifs.read((char*)&ljx,sizeof(long));
      ifs.read((char*)&lkx,sizeof(long)); 
      ifs.read((char*)&dummy, sizeof(int));
    }else{
     ifs.read(reinterpret_cast<char*>(&dummy),sizeof(int));      endswap(&dummy);
     ifs.read(reinterpret_cast<char*>(&lix),sizeof(long));     endswap(&lix);
     ifs.read(reinterpret_cast<char*>(&ljx),sizeof(long));     endswap(&ljx);
     ifs.read(reinterpret_cast<char*>(&lkx),sizeof(long));     endswap(&lkx);
     ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));            endswap(&dummy);
    }
    nmax = (unsigned int)lix * ljx * lkx;
    break;
  }
  
  printf("ix=%d jx=%d kx=%d\n",ix,jx,kx);
  
  if ( 0 == nmax ) {
    cout << "File header error nmax=0" << endl;
    return -1;
  }
  
  if ( (dType!=SINGLE) && (dType!=DOUBLE) ) {
    cout << "Presicion code error : dType= " << dType << endl;
    return -1;
  }
  
   switch (svType) {
   case SCALAR:
   cout << "\tScalar file : ";
   break;
   case VECTOR:
   cout << "\tVector file : ";
   break;
   default:
   cout << "SV code error : svType= " << svType << endl;
   break;
   }

   cout << "\tix= " << ix << " jx= " << jx << " kx= " << kx << endl;
  if (svType==VECTOR) nmax = nmax*3;
  
  if (dType==DOUBLE) return -1;
  
  return dType;

}

int SPH::scanHeader_special(ifstream &ifs, int number)
{
  int dummy;

  if(endian_t){
    ifs.read((char*)&dummy,sizeof(int));
    ifs.read((char*)&svType,sizeof(int));
    ifs.read((char*)&dType,sizeof(int));
    ifs.read((char*)&dummy,sizeof(int));
  }else{
   ifs.read(reinterpret_cast<char*>(&dummy),sizeof(int));      endswap(&dummy);
   ifs.read(reinterpret_cast<char*>(&svType),      sizeof(int));      endswap(&svType);
   ifs.read(reinterpret_cast<char*>(&dType),sizeof(int));      endswap(&dType);
   ifs.read(reinterpret_cast<char*>(&dummy),sizeof(int));      endswap(&dummy);
  }
  //  printf("\tsv=%d d=%d %d  \n",svType, dType, dummy);
  
  
  switch (dType) {
  case SINGLE:
    if(endian_t){
      ifs.read((char*)&dummy,sizeof(int));
      ifs.read((char*)&ix,sizeof(int));
      ifs.read((char*)&jx,sizeof(int));
      ifs.read((char*)&kx,sizeof(int)); 
      ifs.read((char*)&dummy, sizeof(int));
    }else{
     ifs.read(reinterpret_cast<char*>(&dummy),sizeof(int));     endswap(&dummy);
     ifs.read(reinterpret_cast<char*>(&ix),        sizeof(int));     endswap(&ix);
     ifs.read(reinterpret_cast<char*>(&jx),sizeof(int));     endswap(&jx);
     ifs.read(reinterpret_cast<char*>(&kx),sizeof(int));     endswap(&kx);
     ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));           endswap(&dummy);
    }
    nmax = (unsigned int) (ix * jx * kx);
    break;
  case DOUBLE:
    long lix, ljx, lkx;
    cout << "\tlong case" << endl;
    if(endian_t){
      ifs.read((char*)&dummy,sizeof(int));
      ifs.read((char*)&lix,sizeof(long));
      ifs.read((char*)&ljx,sizeof(long));
      ifs.read((char*)&lkx,sizeof(long)); 
      ifs.read((char*)&dummy, sizeof(int));
    }else{
     ifs.read(reinterpret_cast<char*>(&dummy),sizeof(int));      endswap(&dummy);
     ifs.read(reinterpret_cast<char*>(&lix),sizeof(long));     endswap(&lix);
     ifs.read(reinterpret_cast<char*>(&ljx),sizeof(long));     endswap(&ljx);
     ifs.read(reinterpret_cast<char*>(&lkx),sizeof(long));     endswap(&lkx);
     ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));            endswap(&dummy);
    }
    nmax = (unsigned int)lix * ljx * lkx;
    break;
  }
  
  //  printf("ix=%d jx=%d kx=%d\n",ix,jx,kx);
  
  if ( 0 == nmax ) {
    cout << "File header error nmax=0" << endl;
    return -1;
  }
  
  if ( (dType!=SINGLE) && (dType!=DOUBLE) ) {
    cout << "Presicion code error : dType= " << dType << endl;
    return -1;
  }
  
   // switch (svType) {
   // case SCALAR:
   // cout << "\tScalar file : ";
   // break;
   // case VECTOR:
   // cout << "\tVector file : ";
   // break;
   // default:
   // cout << "SV code error : svType= " << svType << endl;
   // break;
   // }

  cout << "\tiData size is x= " << ix << " y= " << jx << " z= " << kx << endl;
  if (svType==VECTOR) nmax = nmax*3;
  
  if (dType==DOUBLE) return -1;
  
  return dType;

}


void SPH::min_max(int nmax, float *var)
{
	float min=1.0e6, max=-1.0e6;
	
	for (int i=0; i<nmax; i++) {
		min = ( min>(*var) ) ? *var : min;
		max = ( max<(*var) ) ? *var : max;
		var++;
	}
	printf("\tmin=%f   max=%f\n", min, max);
}

void SPH::writeFile(ofstream &ofs, int &step, float &time, float* var)
{
	int dummy;

	dummy = 8;
	ofs.write((char*)&dummy,	sizeof(int));
  ofs.write((char*)&svType, sizeof(int));
  ofs.write((char*)&dType,	sizeof(int));
  ofs.write((char*)&dummy,	sizeof(int));
	
	dummy = 12;
	ofs.write((char*)&dummy,sizeof(int));
	ofs.write((char*)&ix,		sizeof(int));
	ofs.write((char*)&jx,		sizeof(int));
	ofs.write((char*)&kx,		sizeof(int)); 
	ofs.write((char*)&dummy,sizeof(int));
	
	dummy = 8;
	ofs.write((char*)&dummy,	sizeof(int));
  ofs.write((char*)&step,  sizeof(int));
  ofs.write((char*)&time,	 sizeof(int));
  ofs.write((char*)&dummy,	sizeof(int));
	
	dummy = sizeof(float)*nmax;
	ofs.write((char*)&dummy, sizeof(int) );
	ofs.write((char*)var,    sizeof(float)*nmax);
	ofs.write((char*)&dummy, sizeof(int) );
	
}

bool SPH::readFile_simple(ifstream &ifs, float* var, int unit){
  int dummy, g;
  double ddmy;
  int step;
  int time;  
  int iSize, jSize, kSize;
  float xorg, yorg, zorg;
  float xpitch, ypitch, zpitch; 

  if(endian_t){
    ifs.read((char*)&dummy,sizeof(int));          
    ifs.read((char*)&dummy, sizeof(int));          
    ifs.read((char*)&dummy, sizeof(int));          
    ifs.read((char*)&dummy, sizeof(int));          
  }
  else{
   ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));          endswap(&dummy); // 
   ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));          endswap(&dummy);// 
   ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));          endswap(&dummy);// 
   ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));          endswap(&dummy);// 
  }
  switch (dType) {
  case SINGLE:
    if(endian_t){
      ifs.read((char*)&dummy,sizeof(int));     // 
      ifs.read((char*)&iSize,sizeof(int));     // 
      ifs.read((char*)&jSize,sizeof(int));     // 
      ifs.read((char*)&kSize,sizeof(int));     // 
      ifs.read((char*)&dummy, sizeof(int));     // 
    }else{
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));     endswap(&dummy);// 
      ifs.read(reinterpret_cast<char*>(&iSize), sizeof(int));     endswap(&iSize);// 
      ifs.read(reinterpret_cast<char*>(&jSize), sizeof(int));     endswap(&jSize);// 
      ifs.read(reinterpret_cast<char*>(&kSize), sizeof(int));     endswap(&kSize);// 
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));     endswap(&dummy);// 
    }

    if(endian_t){
      ifs.read((char*)&dummy, sizeof(int));     // 
      ifs.read((char*)&xorg, sizeof(float));   // 
      ifs.read((char*)&yorg,sizeof(float));   // 
      ifs.read((char*)&zorg,sizeof(float));   // 
      ifs.read((char*)&dummy, sizeof(int));     // 
    }else{
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));     endswap(&dummy);// 
      ifs.read(reinterpret_cast<char*>(&xorg), sizeof(float));    endswap(&xorg);// 
      ifs.read(reinterpret_cast<char*>(&yorg), sizeof(float));    endswap(&yorg);// 
      ifs.read(reinterpret_cast<char*>(&zorg), sizeof(float));    endswap(&zorg);// 
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));     endswap(&dummy);// 
    }

    if(endian_t){
      ifs.read((char*)&dummy,sizeof(int));     
      ifs.read((char*)&xpitch,sizeof(float));   
      ifs.read((char*)&ypitch,sizeof(float));   
      ifs.read((char*)&zpitch,sizeof(float));   
      ifs.read((char*)&dummy, sizeof(int));     
    }else{
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));     endswap(&dummy);// 
      ifs.read(reinterpret_cast<char*>(&xpitch), sizeof(float));  endswap(&xpitch);// 
      ifs.read(reinterpret_cast<char*>(&ypitch), sizeof(float));  endswap(&ypitch);// 
      ifs.read(reinterpret_cast<char*>(&zpitch),sizeof(float));   endswap(&zpitch);// 
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));     endswap(&dummy);// 
    }

    if(endian_t){
      ifs.read((char*)&dummy,sizeof(int));     // 
      ifs.read((char*)&step,sizeof(int));     // 
      ifs.read((char*)&time,sizeof(float));   // 
      ifs.read((char*)&dummy, sizeof(int));     // 
    }else{
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));     endswap(&dummy);// 
      ifs.read(reinterpret_cast<char*>(&step), sizeof(int));      endswap(&step);// 
      ifs.read(reinterpret_cast<char*>(&time), sizeof(float));    endswap(&time);// 
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));     endswap(&dummy);// 
    }
    break;
  case DOUBLE:
    if(endian_t){
      ifs.read((char*)&dummy,sizeof(int));
      ifs.read((char*)&dummy,sizeof(long));
      ifs.read((char*)&dummy,sizeof(long));
      ifs.read((char*)&dummy,sizeof(long)); 
      ifs.read((char*)&dummy, sizeof(int));
    }else{
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));     endswap(&dummy);
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(long));    endswap(&dummy);
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(long));    endswap(&dummy);
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(long));    endswap(&dummy);
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));     endswap(&dummy);
    }
    
    if(endian_t){
      ifs.read((char*)&dummy, sizeof(int));
      ifs.read((char*)&ddmy, sizeof(double));
      ifs.read((char*)&ddmy,sizeof(double));
      ifs.read((char*)&ddmy,sizeof(double)); 
      ifs.read((char*)&dummy, sizeof(int));
    }else{
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));             endswap(&dummy);
      ifs.read(reinterpret_cast<char*>(&ddmy), sizeof(double));           endswap(&ddmy);
      ifs.read(reinterpret_cast<char*>(&ddmy),sizeof(double));    endswap(&ddmy);
      ifs.read(reinterpret_cast<char*>(&ddmy), sizeof(double));           endswap(&ddmy);
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));             endswap(&dummy);
    }

    if(endian_t){
      ifs.read((char*)&dummy,sizeof(int));
      ifs.read((char*)&ddmy,sizeof(double));
      ifs.read((char*)&ddmy,sizeof(double));
      ifs.read((char*)&ddmy,sizeof(double)); 
      ifs.read((char*)&dummy, sizeof(int));
    }else{
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));             endswap(&dummy);
      ifs.read(reinterpret_cast<char*>(&ddmy), sizeof(double));           endswap(&ddmy);
      ifs.read(reinterpret_cast<char*>(&ddmy), sizeof(double));           endswap(&ddmy);
      ifs.read(reinterpret_cast<char*>(&ddmy), sizeof(double));           endswap(&ddmy);
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));             endswap(&dummy);
    }

    if(endian_t){
      ifs.read((char*)&dummy,sizeof(int));
      ifs.read((char*)&dummy,sizeof(int));
      ifs.read((char*)&ddmy,sizeof(double));
      ifs.read((char*)&dummy, sizeof(int));
    }else{
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));             endswap(&dummy);
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));             endswap(&dummy);   
      ifs.read(reinterpret_cast<char*>(&ddmy), sizeof(double));           endswap(&ddmy);
      ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int));             endswap(&dummy);
    }
    break;
  }
  if(endian_t){
   ifs.read((char*)&dummy, sizeof(int) );                    //
  }else{
   ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int) );                    endswap(&dummy);//
  }

  if(endian_t){
    ifs.read((char*)var,    sizeof(float)*unit);
  }else{
    ifs.read(reinterpret_cast<char*>(var),    sizeof(float)*unit);
    for(int i = 0 ; i < unit; i++){
      endswap(&(var[i]));
    }
  }

  if ( (g=ifs.gcount()) != (int)(sizeof(float)*unit)) {
    cout << "\tProblem occurs during reading data\n"
	 << "\tread bytes = " << g << endl;
    return false;
  }

  if(endian_t){
    ifs.read((char*)&dummy, sizeof(int) );
  }else{
    ifs.read(reinterpret_cast<char*>(&dummy), sizeof(int) );                    endswap(&dummy);
  }

  return true;

}
