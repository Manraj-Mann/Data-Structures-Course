#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node
{
public:
  int key;
  Node *parent;
  std::vector<Node *> children;

  Node()
  {
    this->parent = NULL;
  }

  void setParent(Node *theParent)
  {
    parent = theParent;
    parent->children.push_back(this);
  }
};

int main_with_large_stack_space()
{
  std::ios_base::sync_with_stdio(0);
  int n, root;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++)
  {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index == -1)
    {
      root = child_index;
    }

    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    nodes[child_index].key = child_index;
  }

  // Replace this code with a faster implementation
  // int maxHeight = 0;
  // for (int leaf_index = 0; leaf_index < n; leaf_index++) {
  //   int height = 0;
  //   for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
  //     height++;
  //   maxHeight = std::max(maxHeight, height);
  // }

  int height = 0, cur_lvl_nodes = 1, next_level_nodes = 0;

  std::queue<Node> que;
  Node pare = nodes[root];

  que.push(nodes[root]);

  while (que.empty() != 1)
  {
    Node node = que.front();
    que.pop();
    // std::cout<<"poped "<<node.key<<" cur lvl = "<<cur_lvl_nodes<<std::endl;

    cur_lvl_nodes--;

    next_level_nodes += node.children.size();
    
    if (cur_lvl_nodes == 0)
    {
      height++;
      cur_lvl_nodes = next_level_nodes;
      next_level_nodes = 0;
    }
    for (int i = 0; i < node.children.size(); i++)
    {
      // std::cout << "\nPushed " << ((node.children[i])->key) << std::endl;
      que.push(*(node.children[i]));
    }
  }

  std::cout << height;

  // std::cout << maxHeight << std::endl;

  return 0;
}

int main(int argc, char **argv)
{
  return main_with_large_stack_space();
}