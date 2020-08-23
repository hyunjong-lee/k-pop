#include <fmt/format.h>
#include <hnsw/hnsw.h>

#include <iostream>
#include <vector>
#include <tuple>

int main() {
    std::vector<double> input = {1.2, 2.3, 3.4, 4.5};
    fmt::print("Mean: {}, Moment: {}\n",  input[0], input[1]);

    auto hnsw = new kpop::HNSW();

    return 0;
}