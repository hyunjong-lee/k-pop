#ifndef K_POP_BASE_NODE_H_
#define K_POP_BASE_NODE_H_

#include <cmath>

namespace kpop {

template<typename size>
class Node {
public:

    Node(float* data)
    : data_(data)
    {}

    const float distance(const Node& node) const {
        float sum = 0.0f;
        for (size_t i = 0; i < size; i++)
        {
            sum += std::pow<float>(data_[i] - node.data_[i], 2);
        }
        return std::sqrt<float>(sum);

    }  // L2 distance

private:
    unsigned int id_;  // unique within a process
    float* data_;
};

}  // namespace kpop

#endif  // K_POP_BASE_NODE_H_