#include <iostream>
#include <string>
#include "gvizlib.h"

using namespace std;

DotGraph dg;
int nextid;

void myCreateNode(int id, string label)
{
  dg.createNode("n" + to_string(id), label, "white");
}

void myCreateEdge(int from, int to)
{
  dg.createDEdge("n" + to_string(from), "n" + to_string(to), "", "black");
}


int main()
{
  int n; cin >> n;
  dg.setNodeSetting("shape=box, fontname=\"Meiryo\"");
  myCreateNode(0, "dp[i + 2]");
  myCreateNode(1, "dp[i + 1]");
  myCreateNode(2, "dp[i]");
  myCreateEdge(2, 0);
  myCreateEdge(1, 0);
  dg.outToPng("test.png", "dot", true);
  return 0;
}
