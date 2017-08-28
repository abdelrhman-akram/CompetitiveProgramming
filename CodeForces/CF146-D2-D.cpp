#include <bits/stdc++.h>
#define ll long long
using namespace std;
string res="";
int main()
{
    //ios_base::sync_with_stdio(0);
  //  cin.tie(0),cout.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if (abs(c-d)>1)
    return cout<<-1,0;
    if (c==d){
    	if (a-c<=0)
    		res+='7',b--;
    	while(c--)
    	res+="47",a--,b--;
    	if (a>0)
    		res+='4',a--;
    	if(a<0||b<0)
    		return cout<<-1,0;
    }
    else if (c==d+1){
    	while(c--)
    		res+="47",a--,b--;
    	if (a<0||b<0)
    		return cout<<-1,0;
    }
    else if (d==c+1){
    	while(d--)
    		res+="74",a--,b--;
    	if (a<0||b<0)
    	   	return cout<<-1,0;
    }
    int last=0;
    for (int i=res.size()-1;i>=0;i--)
    	if (res[i]=='7'){
    	last=i;
    	break;
    }
    for (int i=0;i<res.size();i++)
    {
    	if (res[i]=='4'&&a>0)
    		while(a--)printf("4");
    		if (i==last&&b>0)
    			while(b-->0)printf("7");
    		printf("%c",res[i]);
    }
    return 0;
}
