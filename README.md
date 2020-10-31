# benchmark-suite

Benchmark macros sample


### Toolchains

#### gcc / c++ 9.3.0

    CreateCats / WithUsualAllocation : 674291514 ns
    CreateCats / WithUsualAllocation : 0 bytes
    CreateCats / WithUsualAllocation : 5000000 allocs
    CreateCats / WithPool : 75283685 ns
    CreateCats / WithPool : 0 bytes
    CreateCats / WithPool : 1000005 allocs

#### Cygwin 3.1.7

    CreateCats / WithUsualAllocation : 1163816700 ns
    CreateCats / WithUsualAllocation : 0 bytes
    CreateCats / WithUsualAllocation : 9000000 allocs
    CreateCats / WithPool : 28233100 ns
    CreateCats / WithPool : 0 bytes
    CreateCats / WithPool : 10 allocs

#### MinGW 5.4

    CreateCats / WithUsualAllocation : 6465976000 ns
    CreateCats / WithUsualAllocation : 86016 bytes
    CreateCats / WithUsualAllocation : 1000000 allocs
    CreateCats / WithPool : 459105000 ns
    CreateCats / WithPool : 0 bytes
    CreateCats / WithPool : 2 allocs

#### Microsoft Visual Studio 2019

    CreateCats / WithUsualAllocation : 10553474400 ns
    CreateCats / WithUsualAllocation : 53248 bytes
    CreateCats / WithUsualAllocation : 22000000 allocs
    CreateCats / WithPool : 863304800 ns
    CreateCats / WithPool : 0 bytes
    CreateCats / WithPool : 2000022 allocs