import torch
from torch.utils.cpp_extension import load

spmm = load(name='spmm', 
            sources=['cu_spmm.cpp', 'cuda_spmm.cu'],
            extra_include_paths=['/home/dannya1/sputnik'],
            verbose=True)

print(spmm.dummy())

cuda1 = torch.device('cuda:0')
row_indices = torch.tensor([1, 2, 3, 0, 4], dtype=torch.int32, device=cuda1)
values = torch.tensor([2, 2, 3, 4, 2, 5, 5, 8, 17, 10, 16, 14], dtype=torch.float32, device=cuda1)
row_offsets = torch.tensor([0, 2, 6, 9, 11, 12], dtype=torch.int32, device=cuda1)
column_indices = torch.tensor([0, 3, 0, 1, 2, 3, 0, 3, 4, 2, 3, 4], dtype=torch.int32, device=cuda1)
B = torch.ones([5, 2], dtype=torch.float32, device=cuda1)

print(spmm.cuda_spmm(row_indices, values, row_offsets, column_indices, B))

