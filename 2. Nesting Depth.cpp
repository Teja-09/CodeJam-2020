#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, i, n;
	cin >> t;
	string s;
	int c = 1;
	while(t--)
	{
		vector<int>val;
		string ans;
		int temp, flag = 0, count = 0;
		
		cin >> s;
		n = s.size();
		
		for(i=0;i<n;i++)
		{
			val.push_back(s[i]-'0');
		}
		temp = val[0];
		while(temp)
		{
			ans.append("(");
			temp--;
		}
		ans.append(to_string(val[0]));
		for(i=0;i<n-1;i++)
		{
			if(val[i] - val[i+1] == 0)
			{
				ans.append(to_string(val[i+1]));			
			}	
			else if(val[i] - val[i+1] > 0)
			{
				temp = val[i] - val[i+1];
				while(temp)
				{
					ans.append(")");
					--temp;
				}
				ans.append(to_string(val[i+1]));
			}
			else if(val[i] - val[i+1] < 0)
			{
				temp = val[i+1] - val[i];
				while(temp)
				{
					ans.append("(");
					--temp;
				}
				ans.append(to_string(val[i+1]));
			}
		}
		temp = val[n-1];
		while(temp)
		{
			ans.append(")");
			--temp;
		}
		cout << "Case #" << c << ": " << ans << "\n";
		++c;
		
	}

}

