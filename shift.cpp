#include<bits/stdc++.h>
using namespace std;
int main()
{
   cout<< "shift reduce parser" << "\n";
   cout<< "given grammar" << "\n";
   cout<< "E->2E2" << "\n";
   cout<< "E->3E3" << "\n";
   cout<< "E->4"   << "\n";
  cout<< "Enter input str" << "\n";
  string s;
   cin>>s;
  s = s + '$';
cout<< "stack           input              Action"<< "\n";
string st="";
st.push_back('$');

int i=0;
string act = "shift";
 while(i<s.size()-1)
{

cout<< st << "        "<< s.substr(i,s.size()) << "           " << act << "\n";
  st.push_back(s[i]);
 i++;
while(true)
{
    char a='#',b='#',c='#' ;
   if(st.back()!='$')
    {
        a = st.back();
        st.pop_back();
    }
     if(st.back()!='$')
        {
            b = st.back();
            st.pop_back();
        }
       if(st.back()!='$')
            {
                c = st.back(); st.pop_back();
            }
     if(a=='4')
{
  st.push_back(c); st.push_back(b);
  st.push_back('E');
cout<< st << "        "<< s.substr(i,s.size()) << "           " << "Reduce" << "\n";
}
else if(a=='2' && b=='E' && c =='2')
  {
    st.push_back('E');
cout<< st << "        "<< s.substr(i,s.size()) << "           " << "Reduce" << "\n";
  }
else if(a=='3' && b=='E' && c =='3')
  {
    st.push_back('E');
cout<< st << "        "<< s.substr(i,s.size()) << "           " << "Reduce" << "\n";
  }
else
{
if(c!='#')
st.push_back(c);
if(b!='#')
    st.push_back(b);
 if(a!='#')
  st.push_back(a);
break;
}
}
}
if(st.back()=='E')
{
 cout<< st << "        "<< s.substr(i,s.size()) << "           " << "Accepted" << "\n";
 }
else
 cout<< st << "        "<< s.substr(i,s.size()) << "           " << "NOT Accepted" << "\n";

return 0;
}
