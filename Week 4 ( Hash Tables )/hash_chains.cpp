#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;

struct Query
{
    string type, s;
    size_t ind;
};
struct node
{
    string key;
    node *next;
};

class QueryProcessor
{
    int bucket_count;
    // store all strings in one vector
    vector<node *> elems;

    size_t hash_func(const string &s) const
    {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count) : bucket_count(bucket_count)
    {

        elems.resize(bucket_count, NULL);
    }

    Query readQuery() const
    {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const
    {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query &query)
    {

        if (query.type == "check")
        {
            vector<string> res;
            node *ptr = elems[query.ind];
            while (ptr != NULL)
            {
                res.push_back(ptr->key);
                ptr = ptr->next;
            }

            for (int i = res.size() - 1; i >= 0; i--)
            {
                std::cout << res[i] << " ";
            }
            std::cout << "\n";
        }
        else
        {

            int n = hash_func(query.s);
            if (query.type == "add")
            {
                //std::cout << "add called\n";

                node * ptr = elems[n];
                if (ptr == NULL)
                {
                    elems[n] = new node;
                    elems[n]->key = query.s;
                    elems[n]->next = NULL;


                }
                else{

                    node * prev = ptr;

                    while (ptr != NULL)
                    {
                        prev = ptr;
                        if (ptr->key  == query.s)
                        {
                            return;
                        }
                        
                       ptr = ptr->next;
                    }

                    ptr = prev;
                    ptr->next = new node;
                    ptr = ptr->next;
                    ptr->key = query.s;
                    ptr->next = NULL;
                    
                }   
                
            }
            else if(query.type == "del"){

               // std::cout << "del called\n";
               node * ptr = elems[n];
               node * prev = NULL;
               if (ptr == NULL)
               {
                   return;
               }
               else
               {
                   while (ptr != NULL)
                   {
                       
                       if (ptr->key == query.s)
                       {
                            if (prev == NULL)
                            {
                                ptr = elems[n];
                                elems[n] = elems[n]->next;
                                delete ptr;
                            }
                            else{

                                prev->next = ptr->next;
                                delete ptr;
                            }
                            return;
                       }
                       prev = ptr;
                       ptr = ptr->next;
                   }
                   
               }
               
               


            }
            else if(query.type == "find"){

                //std::cout << "find called\n";
                node * ptr = elems[n];
                while (ptr != NULL)
                {
                     if (ptr->key == query.s)
                       {
                           writeSearchResult(1);
                           return;
                       }
                    ptr = ptr->next;
                }
                if (ptr == NULL)
                {
                    writeSearchResult(0);
                }
                
                
            }
            
        }
    }

    void processQueries()
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
