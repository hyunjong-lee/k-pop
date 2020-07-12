#include <cmath>
#include <queue>
#include <functional>

#include "include/hnsw.h"

namespace kpop {

template <typename Connector>
bool HNSW::insert(const Node& node, Connector reconnect)
{
    int sampleLayer = floor(-log(random()) * layerLimit_);

    std::set<Node> entries { entry_ };
    for (int i = maxLayer_; i >= sampleLayer - 1; --i)
    {
        searchLayer(node, entries, i);
    }

    for (int i = std::min(maxLayer_, sampleLayer); i >= 0; i--)
    {
        searchLayer(node, entries, i);
        reconnect(node, entries, connectLimit_);
    }

    if (maxLayer_ < sampleLayer)
    {
        maxLayer_ = sampleLayer;
        entry_ = node;
    }

    return true;
}

std::vector<Node> HNSW::search(const Node& query)
{
    return std::vector<Node>();
}

void HNSW::searchLayer(
    const Node& query,
    std::set<Node>& entries,
    int layer
)
{
    std::set<Node> visited;
    std::priority_queue<Node, std::greater<Node>> candidates;
    std::priority_queue<Node> result;

    while (true)
    {
        const auto& top = *entries.begin();
        entries.erase(entries.begin());

        if (top.distance(query) > result.top().distance(query))
            break;

        const auto& connected = getConnected(top, layer);
        for (size_t i = 0; i < connected.size(); ++i)
        {
            const auto& e = connected[i];
            if (visited.find(e) != visited.end())
                continue;

            visited.insert(e);
            if (result.size() < connectLimit_)
            {
                result.push(e);
                candidates.push(e);
            }
            else if (e.distance(query) < result.top().distance(query))
            {
                result.push(e);
                candidates.push(e);
                if (result.size() > connectLimit_)
                {
                    result.pop();
                }
            }
        }
    }
}

std::vector<Node> getConnected(const Node& node, int layer)
{
    return layers_[layer].getConnected(node);
}

std::vector<Node> HNSW::SimpleSelect(
    const Node& query,
    std::set<Node>& entries
)
{
    return std::vector<Node>();
}

std::vector<Node> HNSW::HeuristicSelect(
    const Node& query,
    std::set<Node>& entries
)
{
    return std::vector<Node>();
}

}  // namespace kpop