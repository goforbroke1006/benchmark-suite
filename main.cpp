#include <iostream>
#include <string>

#include "ReusablePool.h"
#include "btest.h"

#include <map>

class Cat {
public:
    Cat()
            : mName("unknown"),
              mAge(0),
              mColor("black"),
              mVisits({}) {
        //std::cout << "Cat()" << std::endl;


        mPhrase = mColor + " cat '" + mName + "' says 'Meow!' "
                  + "(" + std::to_string(mAge) + " y.o.)"
                  + "It has visited doctor about " + std::to_string(mVisits.size()) + " times";
    }

    ~Cat() {
        //std::cout << "~Cat()" << std::endl;
    }

    std::string say() {
        return mPhrase;
    }

private:
    std::string mName;
    int mAge;
    std::string mColor;
    std::map<std::string, std::string> mVisits;

    std::string mPhrase;
};

int main() {

    const size_t samplesCount = 1000000;

    BENCHMARK_TEST(CreateCats, WithUsualAllocation, {
        for (size_t i = 0; i < samplesCount; ++i) {
            Cat *cat01 = new Cat();
            cat01->say();
            delete cat01;
        }
    })

    BENCHMARK_TEST(CreateCats, WithPool, {
        for (size_t i = 0; i < samplesCount; ++i) {
            Cat *cat01 = ReusablePool<Cat>::getInstance().acquireReusable();
            cat01->say();
            ReusablePool<Cat>::getInstance().releaseReusable(cat01);
        }
    })

    return 0;
}


