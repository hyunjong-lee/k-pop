#ifndef K_POP_BASE_NODE_H_
#define K_POP_BASE_NODE_H_

#include <cmath>
#include <vector>
#include <mutex>

namespace kpop {

class Node {
public:

    Node(const std::vector<float>& data)
    : data_(data)
    {
        idMutex_.lock();
        id_ = ID_GENERATOR;
        ID_GENERATOR++;
        idMutex_.unlock();
    }

    const float distance(const Node& node) const {
        float sum = 0.0f;
        for (size_t i = 0; i < data_.size(); i++)
        {
            sum += std::pow<float>(data_[i] - node.data_[i], 2);
        }
        return std::sqrt(sum);
    }  // L2 distance

private:
    unsigned int ID_GENERATOR = 0;
    std::mutex idMutex_;

    unsigned int id_;  // unique within a process
    const std::vector<float> data_;
};

}  // namespace kpop

#endif  // K_POP_BASE_NODE_H_