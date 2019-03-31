#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x=1;
map<string,pair<ll,string> > loadMap()
{
	map<string,pair<ll,string> > m;
	ifstream fin;
	fin.open("Operators.txt");
	ll ind;
	string op,name;
	while((fin>>op)&&(fin>>ind)&&(fin>>name))
	{
		m[op].first=ind;
		x=ind+1;
		m[op].second=name;
	}
	fin.close();
	return m;
}

int main()
{
	map<string,pair<ll,string> > symbolTable=loadMap();
	string s;
	ofstream fout;
	fout.open("Operators.txt",std::ios_base::app);
	while(1)
	{
		cout<<"Enter Operator: ";
		cin>>s;
		if(s=="exit")
			break;
		if(symbolTable[s].first>0)
		{
			cout<<symbolTable[s].second<<endl;
			cout<<"Entry exists!.\nIndex is="<<symbolTable[s].first<<endl<<endl;
			continue;
		}
		if(s.length()>=3)
		{
			cout<<"Invalid Operator.\n\n";
			continue;
		}
		bool valid=0;
		string res="";
		switch(s[0])
		{
			case '+':
				if(s.length()==1)
				{
					valid=1;
					res="Adition_";
				}
				else if(s[1]=='+')
				{
					valid=1;
					res="Increment_";
				}
				else if(s[1]=='=')
				{
					valid=1;
					res="Addition_Assignment_";
				}
				break;
			case '-':
				if(s.length()==1)
				{
					valid=1;
					res="Subtraction_";
				}
				else if(s[1]=='-')
				{
					valid=1;
					res="Decrement_";
				}
				else if(s[1]=='=')
				{
					valid=1;
					res="Subtraction_Assignment_";
				}
				break;
			case '*':
				if(s.length()==1)
				{
					valid=1;
					res="Multiplication_";
				}
				else if(s[1]=='=')
				{
					valid=1;
					res="Multiplication_Assignment_";
				}
				break;
			case '/':
				if(s.length()==1)
				{
					valid=1;
					res="Division_";
				}
				else if(s[1]=='=')
				{
					valid=1;
					res="Division_Assignment_";
				}
				break;
			case '%':
				if(s.length()==1)
				{
					valid=1;
					res="Modulus_";
				}
				else if(s[1]=='=')
				{
					valid=1;
					res="Modulus_Assignment_";
				}
				break;
			case '=':
				if(s.length()==1)
				{
					valid=1;
					res="Assignment_";
				}
				else if(s[1]=='=')
				{
					valid=1;
					res="Comparision_";
				}
				break;
			case '>':
				if(s.length()==1)
				{
					valid=1;
					res="Greater_than_";
				}
				else if(s[1]=='=')
				{
					valid=1;
					res="Greater_than_or_equal_to_";
				}
				break;
			case '<':
				if(s.length()==1)
				{
					valid=1;
					res="Less_than_";
				}
				else if(s[1]=='=')
				{
					valid=1;
					res="Less_than_or_equal_to_";
				}
				break;
			case '!':
				if(s.length()==1)
				{
					valid=1;
					res="Negation_";
				}
				else if(s[1]=='=')
				{
					valid=1;
					res="Not_equal_to_";
				}
				break;
			default:
				cout<<"Invalid Operator.\n";
		}
		if(!valid)
			cout<<"Invalid Operator.\n";
		else
		{
			res=res+"Operator.";
			cout<<res<<endl;
			if(symbolTable[s].first==0)
			{
				symbolTable[s].first=x++;
				symbolTable[s].second=res;
				fout<<s<<"\t"<<x-1<<"\t"<<res<<endl;
				cout<<"Entry created.\nNew Index= "<<symbolTable[s].first<<endl;
			}
			else
				cout<<"Entry Exists.\nIndex= "<<symbolTable[s].first<<endl;
		}
		cout<<endl;
	}
	fout.close();
}
