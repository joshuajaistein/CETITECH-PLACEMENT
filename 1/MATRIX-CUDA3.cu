#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
#include <chrono>


using std::cout;
using std::generate;
using std::vector;
using namespace std::chrono;


__global__ void matrixMul(const int *a, const int *b, int *c, int N) {
  int row = blockIdx.y * blockDim.y + threadIdx.y;
  int col = blockIdx.x * blockDim.x + threadIdx.x;

  c[row * N + col] = 0;
  for (int k = 0; k < N; k++) {
    c[row * N + col] += a[row * N + k] * b[k * N + col];
  }
}

int main() {

  int N = 4096;

  auto start = high_resolution_clock::now();


  size_t bytes = N * N * sizeof(int);

  vector<int> h_a(N * N);
  vector<int> h_b(N * N);
  vector<int> h_c(N * N);

  generate(h_a.begin(), h_a.end(), []() { return rand() % 100; });
  generate(h_b.begin(), h_b.end(), []() { return rand() % 100; });

  int *d_a, *d_b, *d_c;
  cudaMalloc(&d_a, bytes);
  cudaMalloc(&d_b, bytes);
  cudaMalloc(&d_c, bytes);

  cudaMemcpy(d_a, h_a.data(), bytes, cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, h_b.data(), bytes, cudaMemcpyHostToDevice);

  int THREADS = 32;

  int BLOCKS = N / THREADS;

  dim3 threads(THREADS, THREADS);
  dim3 blocks(BLOCKS, BLOCKS);

  matrixMul<<<blocks, threads>>>(d_a, d_b, d_c, N);

  cudaMemcpy(h_c.data(), d_c, bytes, cudaMemcpyDeviceToHost);

  cout << "COMPLETED SUCCESSFULLY\n";

  // Free memory on device
  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_c);


  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "\nMULTIPLICATION TIME : "<< duration.count() << " microseconds";


  return 0;
}
