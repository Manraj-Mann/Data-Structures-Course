#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node
{
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};
bool isbs(vector<Node> &tree, int min, int max, int root)
{

  if (root == -1)
  {
    return 1;
  }
  if (min != INT_MIN && tree[root].key < min)
  {
    return false;
  }
  if (max != INT_MAX && tree[root].key >= max)
  {
    return false;
  }

  bool left = isbs(tree, min, tree[root].key, tree[root].left);
  bool right = isbs(tree, tree[root].key, max, tree[root].right);

  return left and right;
}
bool IsBinarySearchTree(vector<Node> &tree)
{
  // Implement correct algorithm here

  if (!isbs(tree, INT_MIN, INT_MAX, 0))
  {
    return false;
  }

  return true;
  return true;
}

int main()
{
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i)
  {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }

  if (nodes == 0)
  {

    cout << "CORRECT" << endl;
    return 0;
  }
  if (IsBinarySearchTree(tree))
  {
    cout << "CORRECT" << endl;
  }
  else
  {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
