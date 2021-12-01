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

// ----------------------------------------- TLE -------------------------------------------------//

// Problem ---- Per iteration more comparisons && no code resuablility

// bool leftree(vector<Node> tree, int max, int root)
// {
//   // cout << "entered in tree\n";
//   if (root == -1)
//   {
//     // cout << "root = -1\n";
//     return 1;
//   }

//   if (tree[root].left != -1)
//   {

//     if (tree[tree[root].left].key > tree[root].key)
//     {
//       // cout << "left > root\n";
//       return false;
//     }
//   }
//   else if (tree[root].right != -1)
//   {

//     if (tree[tree[root].right].key < tree[root].key)
//     {
//       // cout << "right < root\n";
//       return false;
//     }
//   }
//   else if (tree[root].key > max)
//   {
//     // cout << "key > max\n";
//     return false;
//   }

//   else
//   {
//     if (root != tree[0].left)
//     {
//       return true;
//     }
//   }
//   // cout << "Checking for = " << tree[tree[root].left].key << std::endl;

//   if (tree[root].left != -1)
//   {

//     bool left = leftree(tree, max, tree[root].left);
//     if (left == false)
//     {
//       // cout << "left is false\n";
//       return false;
//     }
//   }

//   if (tree[root].right != -1)
//   {

//     // cout << "Checking for = " << tree[tree[root].right].key << std::endl;
//     bool right = leftree(tree, max, tree[root].right); //
//     if (right == false)
//     {
//       // cout << "right is false\n";
//       return false;
//     }
//   }

//   // cout << "returned true\n";
//   return true;
// }
// bool righttree(vector<Node> tree, int min, int root)
// {
//   // cout << "entered in tree\n";
//   if (root == -1)
//   {
//     // cout << "root = -1\n";
//     return 1;
//   }

//   if (tree[root].left != -1)
//   {

//     if (tree[tree[root].left].key > tree[root].key)
//     {
//       // cout << "left > root\n";
//       return false;
//     }
//   }
//   else if (tree[root].right != -1)
//   {

//     if (tree[tree[root].right].key < tree[root].key)
//     {
//       // cout << "right < root\n";
//       return false;
//     }
//   }
//   else if (tree[root].key < min)
//   {
//     // cout << "key < max\n";
//     return false;
//   }

//   else
//   {
//     if (root != tree[0].left)
//     {
//       return true;
//     }
//   }
//   // cout << "Checking for = " << tree[tree[root].left].key << std::endl;

//   if (tree[root].left != -1)
//   {

//     bool left = righttree(tree, min, tree[root].left);
//     if (left == false)
//     {
//       // cout << "left is false\n";
//       return false;
//     }
//   }

//   if (tree[root].right != -1)
//   {

//     // cout << "Checking for = " << tree[tree[root].right].key << std::endl;
//     bool right = righttree(tree, min, tree[root].right); //
//     if (right == false)
//     {
//       // cout << "right is false\n";
//       return false;
//     }
//   }

//   // cout << "returned true\n";
//   return true;
// }

// bool IsBinarySearchTree(const vector<Node> &tree)
// {
//   // Implement correct algorithm here

//   int min = tree[0].key;
//   int max = tree[0].key;

//   int root = tree[0].left;

//   if (tree[0].left != -1)
//   {
//     /* code */

//     if (tree[tree[0].left].key > tree[0].key )
//     {
//       return false;
//     }
//   }
//   if (tree[0].right != -1)
//   {

//     if (tree[tree[0].right].key < tree[0].key)
//     {
//       return false;
//     }
//   }

//   if (leftree(tree, max, root) == 0)
//   {
//     return false;
//   }

//   root = tree[0].right;
//   if (righttree(tree, min, root) == 0)
//   {
//     return false;
//   }

//   return true;
// }

// ----------------------------------------- correct code with inorder traversal ; time = 0.07/2.00 -------------------------------------------------//

// Possible problem - Traversed whole tree first

bool IsBinarySearchTree(int root, vector<Node> &tree)
{
  static int min = INT_MIN;

  if (root == -1)
  {

    return 1;
  }
  IsBinarySearchTree(tree[root].left, tree);
  if (tree[root].key < min)
  { 
     cout << "INCORRECT "<< endl;
     exit(0);
  }
  else{
    
    min = tree[root].key;
  }

  IsBinarySearchTree(tree[root].right, tree);

  return true;
}

// -------------------------------------------- Correct code with min-max logic ; time = 0.11 / 2.00 ------------------------- //

// bool isbs(vector<Node> &tree , int min , int  max , int root){

//   if ( root == -1)
//   {
//       return 1;
//   }
//   if (min != INT_MIN && tree[root].key <= min)
//   {
//       return false;
//   }
//   if (max !=  INT_MAX && tree[root].key >= max)
//   {
//       return false;
//   }

//   bool left = isbs(tree , min , tree[root].key ,tree[root].left);
//   bool right = isbs(tree , tree[root].key , max ,tree[root].right);

//   return left and right;

// }
// bool IsBinarySearchTree( vector<Node> &tree)
// {
//     if (!isbs( tree , INT_MIN , INT_MAX , 0))
//     {
//        return false;
//     }

//     return true;
// }

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

  if (IsBinarySearchTree(0 , tree ))
  {

    cout << "CORRECT" << endl;
  }
  else
  {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
