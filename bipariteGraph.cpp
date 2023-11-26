#include <iostream>
#include <vector>
#include <queue>

enum Color
{
    UNCOLORED,
    RED,
    BLUE
};

bool isBipartiteDFS(int node, Color currentColor, std::vector<Color> &colors, const std::vector<std::vector<int>> &graph)
{
    if (colors[node] != UNCOLORED)
    {
        return colors[node] == currentColor;
    }

    colors[node] = currentColor;

    for (int neighbor : graph[node])
    {
        if (!isBipartiteDFS(neighbor, (currentColor == RED) ? BLUE : RED, colors, graph))
        {
            return false;
        }
    }

    return true;
}

bool isBipartite(const std::vector<std::vector<int>> &graph)
{
    int n = graph.size();
    std::vector<Color> colors(n, UNCOLORED);

    for (int i = 0; i < n; ++i)
    {
        if (colors[i] == UNCOLORED && !isBipartiteDFS(i, RED, colors, graph))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n1;
    std::cin >> n1;
    std::vector<std::vector<int>> graph1(n1);
    for (int i = 0; i < n1; ++i)
    {
        int count;
        std::cin >> count;
        for (int j = 0; j < count; ++j)
        {
            int neighbor;
            std::cin >> neighbor;
            graph1[i].push_back(neighbor);
        }
    }
    std::cout << (isBipartite(graph1) ? "true" : "false") << std::endl;
    return 0;
}
