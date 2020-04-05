#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, pair<int,int>> &a, pair<int, pair<int,int>> &b)
{
	return (a.second.first < b.second.first);
}

bool revcomp(pair<int,string> &a, pair<int,string> &b)
{
	return (a.first < b.first);
}

int main()
{
	int t, n, i, j, c, h = 1;
	cin >> t;
	while(t--)
	{
		int flag = 0;
		string ans;
		cin >> n;
		vector<pair<int, pair<int,int>>>vec;
		int temp1, temp2;
		for(i=0;i<n;i++)
		{
			cin >> temp1 >> temp2;
			vec.push_back(make_pair(i, make_pair(temp1, temp2)));
		}
		sort(vec.begin(), vec.end(), comp);
				
		vector<pair<int,string>>test;
		n = vec.size();
		if(n > 1)
		{
			c = vec[0].second.second;
			j = vec[1].second.second;
			test.push_back(make_pair(vec[0].first, "C"));
			test.push_back(make_pair(vec[1].first, "J"));
			ans.append("CJ");	
		}
		else if(n == 1)
		{
			j = vec[0].second.second;
			test.push_back(make_pair(vec[0].first, "J"));
			ans.append("J");
		}
		
		for(i=2;i<vec.size();i++)
		{
			if(vec[i].second.first >= j)
			{
				j = vec[i].second.second;
				test.push_back(make_pair(vec[i].first, "J"));
				ans.append("J");
			}
			else if(vec[i].second.first >= c)
			{
				c = vec[i].second.second;
				test.push_back(make_pair(vec[i].first, "C"));
				ans.append("C");
			}
			else
			{
				flag = 1;
				ans = "IMPOSSIBLE";
				break;
			}
		}
		
		sort(test.begin(), test.end(), revcomp);

		if(flag)
		{
			cout << "Case #" << h << ": " << ans << "\n";
		}
		else
		{
			string fi;
			for(i=0;i<test.size();i++)
			{
				fi.append(test[i].second);
			}
			cout << "Case #" << h << ": " << fi << "\n";
		}
		
		++h;
		
	}


}

