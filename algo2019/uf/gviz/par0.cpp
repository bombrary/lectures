#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <fstream>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/adjacency_list.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS> Graph;
typedef std::pair<int, int> Edge;

class mylabel_writer {
public:
  mylabel_writer(int _N) : N(_N) { }
  template<class Vertex>
  void operator()(std::ostream& out, const Vertex& v) const
  {
    out << "[label=" << (v + 1) << "]";
  }
private:
  int N;
};

class mygraph_writer {
public:
  void operator()(std::ostream& out) const {
    out << "graph [rankdir=RL]" << std::endl;
    out << "node [shape=circle]";
  }
};

int main()
{
  std::vector<std::vector<int>> groups {
      {1, 3, 5, 7, 8, 10, 12},
      {4, 6, 9, 11},
      {2}
  };
  std::vector<Edge> edges;
  for (auto& group : groups) {
    for (int i = 0; i < group.size() - 1; i++) {
      edges.push_back(Edge(group[i + 1] - 1, group[i] - 1));
    }
  }
  const int N = accumulate(groups.begin(), groups.end(), 0,
      [](int acc, auto x) { return acc + x.size(); });
  std::cout << N << std::endl;
  Graph g(edges.begin(), edges.end(), N);

  std::ofstream file("test.dot");
  boost::write_graphviz(file, g, mylabel_writer(N), boost::default_writer(), mygraph_writer());
}
