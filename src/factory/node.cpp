#include "include/base/node.h"
#include "include/factory/node.h"

namespace kpop {

template <typename size>
const Node<size>& NodeFactory<size>::CreateNode(float* data)
{
    return nullptr;
}

}  // namespace kpop