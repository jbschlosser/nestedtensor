#pragma once
#include <cuda_runtime.h>
#include <nestedtensor/csrc/cuda/attention.h>
#include <nestedtensor/csrc/cuda/common.h>
#include <nestedtensor/csrc/cuda/cuda_kernels.h>
#include <string>
#include <type_traits>
#include <ATen/ATen.h>
#include <ATen/cuda/CUDAContext.h>
#include <cublas_v2.h>
#include <torch/extension.h>
namespace effectivetransformer {
template <typename DataType_>
at::Tensor bt_mha(
    DataType_* from_tensor,
    DataType_* query_buf_,
    DataType_* key_buf_,
    DataType_* value_buf_,
    DataType_* to_tensor,
    DataType_* attr_bias_Q,
    DataType_* attr_bias_K,
    DataType_* attr_bias_V,
    DataType_* attr_output_kernel,
    int* batch_idx,
    int* word_idx,
    DataType_* attr_mask,
    int64_t batch_size_,
    int64_t head_num_,
    int64_t seq_len_,
    int64_t size_per_head_,
    DataType_* buf,
    DataType_ scaler,
    int* prefix_sum_ptr,
    int* input_mask_ptr,
    int word_num);
}
