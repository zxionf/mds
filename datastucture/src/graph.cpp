#include <vector>
#include <optional>
#include <iostream>
#include <format>
#include <limits>

namespace zx
{
    struct to_edge
    {
        unsigned int to;
        double cost;
    };

    template <typename T>
    class graph
    {
    private:
        std::vector<std::optional<T>> _vertices;
        std::vector<std::vector<to_edge>> _adjacency_list;
        unsigned int _vertex_count = 0;
        unsigned int _edge_count = 0;

    public:
        auto vertex_count() const { return _vertex_count; }
        auto edge_count() const { return _edge_count; }

        auto get_vertex_id(const T& vertex) const -> std::optional<unsigned int>
        {
            for (std::size_t i = 0; i < _vertices.size(); ++i)
                if (_vertices[i].has_value() && _vertices[i].value() == vertex)
                    return static_cast<unsigned int>(i);
            return std::nullopt;
        }

        auto add_vertex(const T& vertex) -> unsigned int
        {
            auto id = static_cast<unsigned int>(_vertices.size());
            _vertices.emplace_back(vertex);
            _adjacency_list.emplace_back();
            ++_vertex_count;
            return id;
        }

        void add_edge(const T& from, const T& to, double cost)
        {
            auto from_id = get_vertex_id(from);
            auto to_id = get_vertex_id(to);
            if (from_id && to_id)
            {
                _adjacency_list[from_id.value()].push_back({to_id.value(), cost});
                ++_edge_count;
            }
        }

        auto get_cost_by_id(unsigned int from, unsigned int to) const -> std::optional<double>
        {
            const auto& edge_list = _adjacency_list[from];
            for (const auto& e : edge_list)
                if (e.to == to)
                    return e.cost;
            return std::nullopt;
        }

        auto get_edge_cost(const T& from, const T& to) const -> std::optional<double>
        {
            auto from_id = get_vertex_id(from);
            auto to_id = get_vertex_id(to);
            if (from_id && to_id)
                return get_cost_by_id(from_id.value(), to_id.value());
            return std::nullopt;
        }

        void remove_edge(const T& from, const T& to)
        {
            auto from_id = get_vertex_id(from);
            auto to_id = get_vertex_id(to);
            if (!from_id || !to_id) return;

            auto& edge_list = _adjacency_list[from_id.value()];
            for (auto iter = edge_list.begin(); iter != edge_list.end(); ++iter)
                if (iter->to == to_id.value())
                {
                    edge_list.erase(iter);
                    --_edge_count;
                    return;
                }
        }

        void remove_vertex(const T& vertex)
        {
            auto v_id = get_vertex_id(vertex);
            if (!v_id) return;

            unsigned int vid = v_id.value();

            for (auto& edge_list : _adjacency_list)
            {
                auto it = edge_list.begin();
                while (it != edge_list.end())
                {
                    if (it->to == vid)
                    {
                        it = edge_list.erase(it);
                        --_edge_count;
                    }
                    else
                    {
                        ++it;
                    }
                }
            }

            _edge_count -= _adjacency_list[vid].size();
            _adjacency_list[vid].clear();

            _vertices[vid] = std::nullopt;
            --_vertex_count;
        }

        auto get_vertex(unsigned int id) const -> const T*
        {
            if (id < _vertices.size() && _vertices[id].has_value())
                return &_vertices[id].value();
            return nullptr;
        }
    };
}

int main()
{
    zx::graph<char> graph;
    auto a_id = graph.add_vertex('a');
    auto b_id = graph.add_vertex('b');
    auto c_id = graph.add_vertex('c');

    graph.add_edge('a', 'b', 2);
    graph.add_edge('a', 'c', 1);
    graph.add_edge('b', 'c', 3);

    graph.remove_vertex('b');

    auto print_cost = [](const std::optional<double>& opt) {
        if (opt.has_value())
            return std::format("{}", opt.value());
        else
            return std::string("inf (no edge)");
    };

    std::cout << std::format("Cost of edge <a, b>: {}\n", print_cost(graph.get_cost_by_id(a_id, b_id)));
    std::cout << std::format("Cost of edge <a, c>: {}\n", print_cost(graph.get_cost_by_id(a_id, c_id)));
    std::cout << std::format("Cost of edge <b, c>: {}\n", print_cost(graph.get_cost_by_id(b_id, c_id)));
}