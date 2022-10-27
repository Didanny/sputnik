#include <iostream>

//#include <torch/extension.h>

#include "sputnik/cuda_utils.h"
//#include "sputnik/matrix_utils.h"
#include "sputnik/spmm/cuda_spmm.h"
//#include "sputnik/spmm/spmm_config.h"
//#include "sputnik/test_utils.h"

//#include "sputnik/cuda_utils.h"
//#include "sputnik/matrix_utils.h"
//#include "sputnik/spmm/cuda_spmm.h"
//#include "sputnik/spmm/spmm_config.h"
//#include "sputnik/test_utils.h"

// #include "cuda_fp16.h"

int main(int argc, char** argv) 
{
    std::cout << "Hello World!" << std::endl;
    sputnik::CudaSpmm(1,2,3,4);
    return 0;
}
