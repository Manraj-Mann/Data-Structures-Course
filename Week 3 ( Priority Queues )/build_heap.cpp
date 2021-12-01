#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::make_pair;
using std::pair;
using std::swap;
using std::vector;

class HeapBuilder
{
private:
  vector<int> data_;
  vector<pair<int, int>> swaps_;

  void WriteResponse() const
  {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i)
    {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData()
  {
    int n;
    cin >> n;
    data_.resize(n);
    for (int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  int parent(int i)
  {

    return (i - 1) / 2;
  }
  int leftchild(int i)
  {

    return 2*i +1 ;
  }
  int rightchild(int i)
  {

    return 2*i +2 ;
  }

  void shift(int k)
  {

      int min = k;

      int l = leftchild(k);

      if( l < data_.size() && data_[min] > data_[l]){

          min = l;
          
      }

      int r = rightchild(k);

      if( r < data_.size() && data_[min] > data_[r]){

          min = r;
          
      }

      if (k != min )
      {
         swap(data_[k] , data_[min]);
         pair<int , int>  p = { k , min};
         swaps_.push_back(p);
         shift(min);
      }
      
    

    
  }

  void GenerateSwaps()
  {
    swaps_.clear();

    for (int i = data_.size()/2; i >= 0; i--)
    {
      shift(i);
    }
  }

public:
  void Solve()
  {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
