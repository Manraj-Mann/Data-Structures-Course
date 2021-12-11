#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::string;
using std::vector;
struct node
{
    string name;
    int number;
};
//////////////////////////// ----------- Used Direct Addressing ---------- //////////////////////////////////
struct Query
{

    string type, name;
    int number;
};

vector<node *> hashtable(10000000, NULL);

vector<Query> read_queries()
{
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string> &result)
{
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query> &queries)
{
    vector<string> result;
   
    for (size_t i = 0; i < queries.size(); ++i)
    {

        if (queries[i].type == "add")
        {
            node *ptr;

            if (hashtable[queries[i].number] == NULL)
            {
                ptr = new node;
            }
            else
            {
                ptr = hashtable[queries[i].number];
            }

            ptr->name = queries[i].name;
            ptr->number = queries[i].number;

            hashtable[queries[i].number] = ptr;

        }
        else if (queries[i].type == "del")
        {
            
            if (hashtable[queries[i].number] != NULL)
            {
                hashtable[queries[i].number] = NULL;
            }
           
        }
        else if (queries[i].type == "find")
        {
            string response = "not found";
            if (hashtable[queries[i].number] != NULL)
            {
                 response = hashtable[queries[i].number]->name;
            }
           
             result.push_back(response);
        }
    }

    return result;
}

int main()
{
    write_responses(process_queries(read_queries()));
    return 0;
}
