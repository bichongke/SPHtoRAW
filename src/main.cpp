#include <iostream>
#include <string>
#include <cstring>

#include "common.h"
#include "file_name.h"
#include "read_sph.h"
#include "sph_to_raw.h"
#include "write_raw_file.h"

using namespace std;

//==============variable==============//
int size;
int number_of_files;
string sph_filename_str;
char* sph_filename_char;
string raw_filename_str;
char* raw_filename_char;
double *sph_data;
double *raw_data;


//==========================================//
//                 main function            //
//==========================================//
int main(int argc, char **argv){
  
  number_of_files = StringToInt(argv[4]);
  
  for(int i = 0; i < number_of_files; i++){
    sph_filename_str = getFileName(argv[1], argv[2], argv[3], i, 0);
    sph_filename_char = new char[sph_filename_str.length()+1];
    strcpy(sph_filename_char, sph_filename_str.c_str());
    
    cout<<endl; cout<<"Converting the "<<i<<"th time step ...";
    
    if(i == 0){
      size = get_size(sph_filename_char);
    }
    
    sph_data = new double[size*3];
    read_one_sph_file(sph_filename_char, sph_data, size*3);
    raw_data = new double[size];
    convert_sph_to_raw(sph_data, raw_data, size);
    
    raw_filename_str = getFileName(argv[1], argv[2], argv[3], i, 1);
    raw_filename_char = new char[raw_filename_str.length()+1];
    strcpy(raw_filename_char, raw_filename_str.c_str());

    write_to_raw(raw_data, raw_filename_char, size);
    
    //free memory;
    delete []sph_filename_char;
    delete []sph_data;
    delete []raw_data;
  }
  
  cout<<"Datasets are successufully converted!!"<<endl;
    
  return 0;
}
