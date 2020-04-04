#include <iostream>

using namespace std;

void print_parent(int cnt);

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int T,i,cnt,t=0;
	string s;
	
	cin >> T;
	
	while(t<T)
	{
		t++;
		
		cin >> s;
		
		cout << "Case #" << t << ": ";
		
		print_parent(s[0]-'0');
		cout << s[0];
		
		for(i=1; i<s.size(); i++)
		{
			cnt = (s[i]-'0') - (s[i-1]-'0');
			print_parent(cnt);
			cout << s[i];
		}
		
		print_parent((s[i-1]-'0')*-1);
		
		cout << "\n";
	}
}

void print_parent(int cnt)
{
	int i;
	
	if(cnt > 0)
		for(i=0; i<cnt; i++)
			cout << "(";
	
	else if(cnt < 0)
		for(i=0; i>cnt; i--)
			cout << ")";
}
