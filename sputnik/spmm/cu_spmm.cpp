#include <torch/extension.h>
#include <iostream>
#include <vector>
#include <pybind11/pybind11.h>

#include "sputnik/spmm/cuda_spmm.h"

std::vector<torch::Tensor> dummy() {
    auto a = torch::ones(5);
    auto b = torch::zeros(5);

    return {a,b};    
}

torch::Tensor cuda_spmm(
    torch::Tensor row_indices,
    torch::Tensor values,
    torch::Tensor row_offsets,
    torch::Tensor column_indices,
    torch::Tensor dense_matrix)
{
    const auto m = row_indices.size(0);
    const auto k = dense_matrix.size(0);
    const auto n = dense_matrix.size(1);
    const auto nonzeros = values.size(0);

    auto device_id = dense_matrix.device().index(); 
    auto options = torch::TensorOptions().dtype(torch::kFloat32).device(torch::kCUDA, device_id);
    auto out = torch::empty({m, n}, options);

    sputnik::CudaSpmm(
        m, k , n, nonzeros,
	    row_indices.data_ptr<int>(),
	    values.data_ptr<float>(),
	    row_offsets.data_ptr<int>(),
	    column_indices.data_ptr<int>(),
	    dense_matrix.data_ptr<float>(),
	    out.data_ptr<float>(),
	    0
	);

    return out;
}

PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
    m.def("dummy", &dummy, "Dummy");
    m.def("cuda_spmm", &cuda_spmm, "Sparse Matrix-Matrix Multiply (CUDA)");
}


