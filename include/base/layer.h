#ifndef K_POP_BASE_LAYER_H_
#define K_POP_BASE_LAYER_H_

#include <vector>

#include "include/base/node.h"

namespace kpop {

class Layer {
public:
    const std::vector<const Node&> getConnected(const Node& node) const
    {
        return std::vector<const Node&>();
    }

private:

};

}  // namespace kpop

#endif  // K_POP_BASE_LAYER_H_