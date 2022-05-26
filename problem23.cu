// output example
/*
result[0] = 16.81, result[1] = 16.81, result[2] = 16.81, result[3] = 16.81, result[4] = 16.81, 
result[4194299] = 16.81, result[4194300] = 16.81, result[4194301] = 16.81, result[4194302] = 16.81, result[4194303] = 16.81, 
Success! All values calculated correctly.
*/

#include <stdio.h>

__global__
void initWith(double num, double *vector, int N)
{
    int index = threadIdx.x + blockIdx.x * blockDim.x;
    int stride = blockDim.x * gridDim.x;

    for(int i = index; i < N; i += stride)
    {
        vector[i] = num;
    }
}

__global__
void saxpy(double *a, double *b, double *result, int N)
{
    int index = threadIdx.x + blockIdx.x * blockDim.x;
    int stride = blockDim.x * gridDim.x;

    for(int i = index; i < N; i += stride)
        result[i] = 2 * a[i] + b[i];
}

// first check
void checkFiveElements(double *result, int N)
{    
    // Print out the first and last 5 values of result for a quality check
    for( int i = 0; i < 5; ++i )
        printf("result[%d] = %.2f, ", i, result[i]);
    printf ("\n");
    
    for( int i = N - 5; i < N; ++i )
        printf("result[%d] = %.2f, ", i, result[i]);
    printf ("\n");
}

// second check
void checkAllElements(double target, double *result, int N)
{    
    for(int i = 0; i < N; ++i)
    {
        if(result[i] != target)
        {
            printf("FAIL: vector[%d] - %0.0f does not equal %0.0f\n", i, result[i], target);
            exit(1);
        }
    }
    
    printf("Success! All values calculated correctly.\n");
}

int main()
{
    double *a, *b, *result;
    int deviceId;
    int numberOfSMs;

    // get number of Sms
    cudaGetDevice(&deviceId);
    cudaDeviceGetAttribute(&numberOfSMs, cudaDevAttrMultiProcessorCount, deviceId);

    int N = 2048 * 2048; // Number of elements in each vector
    size_t size = N * sizeof(double); // The total number of bytes per vector

    // Allocate memory 
    cudaMallocManaged(&a, size);
    cudaMallocManaged(&b, size);
    cudaMallocManaged(&result, size);

    cudaMemPrefetchAsync(a, size, deviceId);
    cudaMemPrefetchAsync(b, size, deviceId);
    cudaMemPrefetchAsync(result, size, deviceId);

    // Number of threads and blocks
    size_t threadsPerBlock = 256;
    size_t numberOfBlocks = 32 * numberOfSMs;
    
    // For error handling
    cudaError_t saxpyErr;
    cudaError_t asyncErr;

    // Initialize vectors
    initWith<<<numberOfBlocks, threadsPerBlock>>>(4.84, a, N);
    initWith<<<numberOfBlocks, threadsPerBlock>>>(7.13, b, N);
    initWith<<<numberOfBlocks, threadsPerBlock>>>(0, result, N);

    saxpy<<<numberOfBlocks, threadsPerBlock>>>(a, b, result, N);

    // handle errors
    saxpyErr = cudaGetLastError();
    if(saxpyErr != cudaSuccess) printf("Error: %s\n", cudaGetErrorString(saxpyErr));
    
    // Wait for the GPU to finish
    asyncErr = cudaDeviceSynchronize(); 
    if(asyncErr != cudaSuccess) printf("Error: %s\n", cudaGetErrorString(asyncErr));
    
    cudaMemPrefetchAsync(result, size, cudaCpuDeviceId);
    checkFiveElements(result, N);
    checkAllElements(2 * a[0] + b[0], result, N);

    // Free all our allocated memory
    cudaFree(a);
    cudaFree(b);
    cudaFree(result);
}
