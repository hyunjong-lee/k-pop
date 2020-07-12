#ifndef K_POP_BASE_SIMILAR_H_
#define K_POP_BASE_SIMILAR_H_

#include <vector>

#include "node.h"

namespace kpop {

class Similar {
    virtual ~Similar() {}
    virtual bool insert(const Node& node) = 0;
    virtual std::vector<Node> search(const Node& query) = 0;
};

}  // namespace kpop

#endif  // K_POP_BASE_SIMILAR_H_