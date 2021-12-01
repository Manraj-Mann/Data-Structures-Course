#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::pair;
using std::vector;

class JobQueue
{
private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  vector<pair<long long, long long>> workers_heap;

  void WriteResponse() const
  {
    for (long long i = 0; i < jobs_.size(); ++i)
    {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData()
  {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for (int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }
  int leftchild(long long i)
  {

    return 2 * i + 1;
  }
  int rightchild(long long i)
  {

    return 2 * i + 2;
  }

  void shift(int k)
  {

    int min = k;

    int l = leftchild(k);
    int r = rightchild(k);

    // if (l < workers_heap.size() && workers_heap[min].second == workers_heap[l].second)
    // {
    //   if (workers_heap[min].first > workers_heap[l].first)
    //   {

    //     std::swap(workers_heap[k], workers_heap[min]);

    //   }
    // }

    // if (r < workers_heap.size() && workers_heap[min].second == workers_heap[r].second)
    // {
    //   if (workers_heap[min].first > workers_heap[r].first)
    //   {

    //     std::swap(workers_heap[k], workers_heap[min]);
    //   }
    // }

    if (l < workers_heap.size() && workers_heap[min].second > workers_heap[l].second)
    {

      min = l;
    }
    else if(l < workers_heap.size() && workers_heap[min].second == workers_heap[l].second && workers_heap[min].first > workers_heap[l].first){

      min = l;
    }


    if (r < workers_heap.size() && l < workers_heap.size() && workers_heap[l].second == workers_heap[r].second && workers_heap[l].first > workers_heap[r].first)
    {
      min = r;
    }
    else if(r < workers_heap.size() && workers_heap[min].second == workers_heap[r].second && workers_heap[min].first > workers_heap[r].first){

      min = r;

    }
    

    if (r < workers_heap.size() && workers_heap[min].second > workers_heap[r].second)
    {
      min = r;
    }

    if (k != min)
    {
      std::swap(workers_heap[k], workers_heap[min]);
      shift(min);
    }
    // if (top_priority().first > workers_heap[leftchild(0)].first && top_priority().second == workers_heap[leftchild(0)].second)
    // {

    //   std::swap(workers_heap[0], workers_heap[leftchild(0)]);
    // }
    // else if (top_priority().first > workers_heap[rightchild(0)].first && top_priority().second == workers_heap[rightchild(0)].second)
    // {
    //   std::swap(workers_heap[0], workers_heap[rightchild(0)]);
    // }
  }

  void change_priority(long long duration)
  {
    workers_heap[0].second = workers_heap[0].second + duration;

    // for (int i = 0; i < num_workers_; i++)
    // {
    //     if(workers_heap[i].second != 0){

    //       workers_heap[i].second = workers_heap[i].second - 1;

    //     }
    // }
  }

  pair<long long, long long> top_priority()
  {

    return workers_heap[0];
  }

  void build_heap()
  {

    for (long long i = num_workers_ / 2; i >= 0; i--)
    {
      shift(i);
    }
  }

  void AssignJobs()
  {
    for (long long i = 0; i < num_workers_; i++)
    {
      workers_heap.push_back({i, 0});
    }

    for (int i = 0; i < jobs_.size(); i++)
    {
      pair<long long, long long> worker = top_priority();
      assigned_workers_.push_back(worker.first);
      start_times_.push_back(worker.second);
      change_priority(jobs_[i]); 
     // build_heap();
     shift(0);
    }
  }

public:
  void Solve()
  {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}

// 1.- you need to create a vector or an array of pairs incluiding the worker number and the ammount of secconds spent processing jobs

// 2.- loop for each process and add the top process to the answer array for each job.

// 3.- inside the same loop add the ammount of secconds to the first process to the ammount of secconds processing jobs

// 4.- Call siftdown each time.

// On the siftDown method it is the same as the siftdown presented on the lectures but you must add an else if for each branch if the ammount of seconds is the same and the process is larger. The else ifs go right after each check for left and right. The siftdown stays the same elsewhere