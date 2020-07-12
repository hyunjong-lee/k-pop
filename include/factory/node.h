#ifndef K_POP_NODE_FACTORY_H_
#define K_POP_NODE_FACTORY_H_

#include <vector>
#include "include/base/node.h"

namespace kpop {

template<typename size>
class NodeFactory {
public:

    const Node<size>& CreateNode(float* data)
    {
        return new Node<size>(data);
    }

private:
};

}  // namespace kpop

#endif  // K_POP_NODE_FACTORY_H_