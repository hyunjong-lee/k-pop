#ifndef K_POP_HNSW_H_
#define K_POP_HNSW_H_

#include <cmath>
#include <set>

#include "base/similar.h"
#include "base/layer.h";

namespace kpop {

class HNSW : public Similar {
public:

    template <typename Connector>
    bool insert(const Node& node, Connector connect);

    std::vector<Node> search(const Node& query);

private:
    void searchLayer(
        const Node& query,
        std::set<Node>& entries,
        int layer
    );

    std::vector<Node> getConnected(
        const Node& node,
        int layer
    );

    std::vector<Node> SimpleSelect(
        const Node& query,
        std::set<Node>& candidates
    );

    std::vector<Node> HeuristicSelect(
        const Node& query,
        std::set<Node>& candidates
    );

    const int connectLimit_ = 10;  // M 
    const int searchLimit_ = 100;  // efConstruct
    int layerLimit_ = std::log(connectLimit_);  // layerMult

    Node entry_;
    int maxLayer_;

    std::vector<Layer> layers_;
};

}  // namespace kpop

#endif  // K_POP_HNSW_H_