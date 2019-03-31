#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x=1;

map<string,ll> loadMap()
{
	map<string,ll> m;
	ifstream fin;
	fin.open("Identifier.txt");
	ll ind;
	string s;
	while((fin>>s)&&(fin>>ind))
	{
		m[s]=ind;
		x=ind+1;
	}
	fin.close();
	return m;
}

bool check(string s)
{
	if( !( s[0]=='_' || (s[0]>=65 && s[0]<=90) || (s[0]>=97 && s[0]<=122)) )
		return 0;
	for(int i=0;i<s.length();i++)
		if(!((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) || s[i]=='_' || (s[i]>=48 && s[i]<=57)))
			return 0;
	return 1;
}
int main()
{
	string strings[] =
		{"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for",
		"goto","if","int","long","register","return","short","signed","sizeof","sattic","struct","switch","typedef","union",
		"unsigned","void","volatile","while"};
	set<string> keywords;
	for(int i=0;i<32;i++)
		keywords.insert(strings[i]);
	map<string,ll> symbolTable=loadMap();
	string s;
	ofstream fout;
	fout.open("Identifier.txt",std::ios_base::app);
	while(1)
	{
		cout<<"Enter String: ";
		cin>>s;
		if(s=="exit")
			break;
		if(keywords.find(s)!=keywords.end())
		{
			cout<<"Reserved keyword!!Not a Identifier.\n\n";
			continue;
		}
		if(check(s))
		{
			cout<<"Valid Identifier.\n";
			if(symbolTable[s]==0)
			{
				symbolTable[s]=x++;
				fout<<s<<" "<<x-1<<endl;
				cout<<"Entry created.\nNew INDEX= "<<symbolTable[s]<<endl;
			}
			else
				cout<<"Already Exists.\nINDEX ="<<symbolTable[s]<<endl;
		}
		else
			cout<<"Invalid Identifier.\n";
		cout<<endl;
	}
	fout.close();
}
