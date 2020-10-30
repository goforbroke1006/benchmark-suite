//
// Created by GOFORBROKE on 30.10.2020.
//

#ifndef BENCHMARK_SUITE_REUSABLEPOOL_H
#define BENCHMARK_SUITE_REUSABLEPOOL_H

#include <vector>

template<typename Reusable>
class ReusablePool {
public:
    ReusablePool(const ReusablePool &reusablePool) = delete;

    static ReusablePool<Reusable> &getInstance() {
        static ReusablePool<Reusable> instance;
        return instance;
    }

    Reusable *acquireReusable() {
        Reusable *result = nullptr;
        for (auto &reusablePtr : mBuffer) {
            if (reusablePtr != nullptr) {
                result = reusablePtr;
                reusablePtr = nullptr;
                break;
            }
        }
        if (nullptr == result && mBuffer.size() < mMaxPoolSize) {
            result = new Reusable();
            mBuffer.resize(mBuffer.size() + 1);
        }
        return result;
    }

    void releaseReusable(Reusable *reusable) {
        for (auto &reusablePtr : mBuffer) {
            if (reusablePtr == nullptr) {
                reusablePtr = reusable;
                break;
            }
        }
    }

    void setMaxPoolSize(size_t size) {
        mMaxPoolSize = size;
    }

    ~ReusablePool() {
        for (auto &ptr : mBuffer) {
            if (nullptr != ptr)
                delete ptr;
        }
    }

private:
    ReusablePool() = default;



//    static ReusablePool *instance;

    std::vector<Reusable *> mBuffer;
    size_t mMaxPoolSize = 128;
};

//ReusablePool::


#endif //BENCHMARK_SUITE_REUSABLEPOOL_H
