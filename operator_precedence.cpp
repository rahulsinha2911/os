#include<bits/stdc++.h>
using namespace std;
stack<string> st,myst;
string input,temp="",top;
int i=0,var=0;
int check(string a,string b)
{
	if(a=="$" && b=="$")
		return 1;
	if(a=="id"&&(b=="+"||b=="*"||b=="$"))
		return 2;
	if(a=="*"&&(b=="+"||b=="$"))
		return 2;
	if(a=="+"&&b=="$")
		return 2;
	 if(a==b && b=="id")
		return 4;
	return 3;
}
int main()
{
	cout<<"GRAMMAR is -\nE->E+E\nE->E*E\nE->id\n Enter Input String:\n ";
	cin>>input;
	input+="$";
	st.push("$");
	cout<<"\nstack \t input \tAction\n";
	for(i=0;i<input.length();)
	{
		string s1="";
		while(!st.empty())
		{
			top=st.top();
			st.pop();
			myst.push(top);
		}
		while(!myst.empty())
		{
			top=myst.top();
			s1+=top;
			myst.pop();
			st.push(top);
		}
		top=st.top();
		cout<<s1<<"\t"<<input<<"\t";
		s1="";
		if(input[i]=='i' && input[i+1]=='d')
		{
			input[i]=' ';
			input[i+1]=' ';
			i+=2;
			var=2;
			s1="id";
		}
		else
		{
			s1=input[i];
			input[i]=' ';
			var=1;
			i++;
		}
		switch(check(s1,top))
		{
			case 1:
			cout<<temp<<"Accept"<<endl;
			temp=""; break;
			case 2:	
			st.push(s1);
			cout<<temp<<top<<"<"<<s1<<endl;
			temp="";break;
			case 3:
			cout<<temp<<top<<">"<<s1<<endl;
			temp="";
			if(top=="id")
				temp="E->id , ";
			else if(top=="*")
				temp="E->E*E , ";
			else if(top=="+")
				temp="E->E+E , ";
			if(var==2)
			{
				i-=var;
				input[i]='i';
				input[i+1]='d';
			}
			if(var==1)
			{
				i-=var;
				input[i]=s1[0];
			}
			st.pop();break;
			default:
			cout<<"\nError\n";return 0;
		}
	}
}
