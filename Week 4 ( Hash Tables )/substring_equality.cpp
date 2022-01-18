#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solver
{
	string s;
	long long m1 = 1000000007;
	long long m2 = 1000000009;
	vector<long long> table1;
	vector<long long> table2;
	unsigned long long x = rand() % 1000000000;
	vector<long long> y1;
	vector<long long> y2;

public:
	Solver(string s) : s(s)
	{

		table1.resize(s.size() + 1);
		table2.resize(s.size() + 1);

		y1.resize(s.size() + 1);
		y2.resize(s.size() + 1);

		precomp(table1, m1);
		precomp(table2, m2);
		precomute_pow(y1, m1);
		precomute_pow(y2, m2);
		// print_table(table1);
		// print_table(table2);
		// print_table(y1);
		// print_table(y2);
	}
	// ------------------------ Computer powers in advance ------------------ //
	void precomute_pow(vector<long long> &y, long long m)
	{

		y[0] = 1;

		for (int i = 1; i < y.size(); i++)
		{
			y[i] = ((y[i - 1]) * (x))%m;
		}
	}
	
	// ------------------------ Computer powers in advance ------------------ //
	void print_table(vector<long long> &table)
	{

		// std::cout << "\n-----------------------------------------\n";
		for (int i = 0; i < table.size(); i++)
		{
			std::cout << "table[" << i << "] = " << table[i] << " \n";
		}
		// std::cout << "\n|-----------------------------------------\n";
	}

	// ------------------------ Finding hash value  ------------------ //
	long long hashvalue(vector<long long> &table, long long m, long long start, long long l)
	{
		long long y;
		if (m == m1)
		{
			y = y1[l];
		}
		else
		{
			y = y2[l];
		}

		//	std::cout<<"\ny = "<<y<<"\n";

		long long hash_value = (((table[start + l] - (y * table[start])) % m) + m ) % m;
			//std::cout<<"hash value = "<<hash_value<<"\n";
		while (hash_value < 0)
		{
			hash_value += m;
		}
		hash_value = hash_value % m;
			//std::cout<<"hash value = "<<hash_value<<"\n";

		return hash_value;
	}
	void precomp(vector<long long> &table, long long m)
	{
		table[0] = 0;

		for (size_t i = 1; i <= s.size(); i++)
		{
			table[i] = ( (x * table[i - 1]) % m + ((int)s[i - 1]))  % m;
		}
	}
	bool ask(long long a, long long b, long long l)
	{

		long long a_hash1 = hashvalue(table1, m1, a, l);
		long long a_hash2 = hashvalue(table2, m2, a, l);
		long long b_hash1 = hashvalue(table1, m1, b, l);
		long long b_hash2 = hashvalue(table2, m2, b, l);
                                                                            
		if ((a_hash1 == b_hash1) && (a_hash2 == b_hash2))
		{

			return true;
		}

		return false;
	}
	bool ask2(int a, int b, int l)
	{
		return s.substr(a, l) == s.substr(b, l);
	}
};

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	long long q;
	cin >> s >> q;
	Solver solver(s);

	for (int i = 0; i < q; i++)
	{
		long long a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}