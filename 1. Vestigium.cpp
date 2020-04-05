#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, i, j;
	cin >> t;
	int val = 0;
	while(t--)
	{
		++val;
		cin >> n;
		vector<vector<int>> vec(n, vector<int>(n));
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin >> vec[i][j];
			}
		}
		
		int k = 0;
		int dsum = 0, rc=0, cc = 0;
		for(i=0;i<n;i++)
		{
			unordered_map<int,int>row;
			unordered_map<int,int>col;
			j = i;
			
			dsum+=vec[i][j];
			
			for(k=0;k<n;k++)
			{
				++row[vec[i][k]];
			}
			
			for(k=0;k<n;k++)
			{
				++col[vec[k][j]];
			}
			
			for(auto x:row)
			{
				if(x.second > 1)
				{
					++rc;
					break;
				}
			}
			
			for(auto x:col)
			{
				if(x.second > 1)
				{
					++cc;
					break;
				}
			}
			
		}
		
		cout << "Case #" << val << ": " << dsum << " " << rc << " " << cc << "\n"; 
		
		
	}
	

}

