#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;
using namespace chrono;

using Matrix = vector<vector<float>>;

const int CACHE_LINES = 8192;   // 32KB / 4 bytes (1 float)
const int LINE_SIZE   = 4;      // 1 float = 4 bytes

// Simple LRU Cache for matrix elements
class Cache {
public:
    Cache() : hitCount(0), missCount(0) {}

    bool access(int addr) {
        if (cacheMap.find(addr) != cacheMap.end()) {
            // Hit: move to front
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[addr]);
            ++hitCount;
            return true;
        }

        // Miss: insert into cache
        if (cacheList.size() == CACHE_LINES) {
            // Evict LRU
            int lruAddr = cacheList.back();
            cacheList.pop_back();
            cacheMap.erase(lruAddr);
        }

        cacheList.push_front(addr);
        cacheMap[addr] = cacheList.begin();
        ++missCount;
        return false;
    }

    void stats() const {
        int total = hitCount + missCount;
        double hitRate = total ? (100.0 * hitCount / total) : 0;
        cout << fixed << setprecision(2);
        cout << "\nCache Stats:\n";
        cout << "------------\n";
        cout << "Hits        : " << hitCount << "\n";
        cout << "Misses      : " << missCount << "\n";
        cout << "Hit Rate    : " << hitRate << " %\n";
    }

private:
    list<int> cacheList;  // Most recent at front
    unordered_map<int, list<int>::iterator> cacheMap;
    int hitCount;
    int missCount;
};

// Unique address for matrix element (row-major)
int addr(int base, int row, int col, int width) {
    return base + row * width + col;
}

// Tensor Core-style matrix multiply with cache
Matrix tensorCoreMatmulCache(const Matrix& A, const Matrix& B, Cache& cache, int baseA, int baseB, int baseC, int tile = 16) {
    int M = A.size();
    int K = A[0].size();
    int N = B[0].size();

    Matrix C(M, vector<float>(N, 0.0f));

    for (int i = 0; i < M; i += tile) {
        for (int j = 0; j < N; j += tile) {
            for (int k = 0; k < K; k += tile) {
                for (int ii = 0; ii < tile && i + ii < M; ++ii) {
                    for (int jj = 0; jj < tile && j + jj < N; ++jj) {
                        float sum = 0.0f;
                        for (int kk = 0; kk < tile && k + kk < K; ++kk) {
                            int aAddr = addr(baseA, i + ii, k + kk, K);
                            int bAddr = addr(baseB, k + kk, j + jj, N);
                            cache.access(aAddr);
                            cache.access(bAddr);
                            sum += A[i + ii][k + kk] * B[k + kk][j + jj];
                        }
                        int cAddr = addr(baseC, i + ii, j + jj, N);
                        cache.access(cAddr);  // write
                        C[i + ii][j + jj] += sum;
                    }
                }
            }
        }
    }

    return C;
}

// Generate random matrix
Matrix randomMatrix(int rows, int cols) {
    Matrix mat(rows, vector<float>(cols));
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(-1.0, 1.0);

    for (auto& row : mat)
        for (auto& val : row)
            val = static_cast<float>(dist(gen));
    return mat;
}

int main() {
    int M = 64, K = 64, N = 64;   // Size chosen to fit in cache

    Matrix A = randomMatrix(M, K);
    Matrix B = randomMatrix(K, N);
    Cache cache;

    int baseA = 0;
    int baseB = M * K;
    int baseC = baseB + K * N;

    auto start = high_resolution_clock::now();
    Matrix C = tensorCoreMatmulCache(A, B, cache, baseA, baseB, baseC);
    auto end = high_resolution_clock::now();

    double elapsedMs = duration_cast<duration<double, milli>>(end - start).count();

    double flops = 2.0 * M * N * K;
    double gflops = flops / (elapsedMs * 1e6);

    cout << "\nMatrix Multiply with Cache (32KB):\n";
    cout << "----------------------------------\n";
    cout << "Matrix Size        : " << M << "×" << K << " × " << K << "×" << N << "\n";
    cout << "Elapsed Time (ms)  : " << elapsedMs << "\n";
    cout << "Performance        : " << gflops << " GFLOPS\n";

    cache.stats();

    cout << "\nSample Output C[0][0] = " << C[0][0] << "\n";

    return 0;
}
