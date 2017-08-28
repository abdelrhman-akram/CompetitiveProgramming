#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Histogram {
public:
	vector <string> draw(vector <string> title, vector <int> value) {
		int mi=0,ms=0;
		for (int i=0;i<value.size();i++){
			mi=max(mi,value[i]);
			if (i!=value.size()-1){
				int space=title[i+1].size()/2;
				if (title[i+1].size()%2==0)
					space--;
				space+=(title[i].size()/2);
				space++;
			ms=max(ms,space);
			}
		}
	    vector<string>res;
	    for (int i=mi;i>=1;i--){
	    	string line,out="";
	    	line.resize(200);
	    	int last=0,temp=0;
	    	for (int j=0;j<value.size();j++){
	    		if (value[j]>=i)
	    		{
	    			if (title[j].size()%2==0)
	    				line[(title[j].size()/2)-1+temp]='X',last=temp+title[j].size()/2-1;
	    			else
	    				line[(title[j].size()/2)+temp]='X',last=temp+title[j].size()/2;
	    		}
	    		temp+=title[j].size();
	    		if (j!=value.size()-1){
	    						int space=title[j+1].size()/2;
	    						if (title[j+1].size()%2==0)
	    							space--;
	    						space+=(title[j].size()/2);
	    		for (int k=0;k<ms-space;k++)
	    			temp++;
	    		}
	    	}
	    	for (int i=0;i<=last;i++){
                    if (line[i]=='\0')
                        out+=' ';
            else
	    		out+=line[i];
	    	}
	    	res.push_back(out);
	    }
	    string t="";
	    for (int i=0;i<title.size();i++)
	    {
	    	t+=title[i];

	    	if (i!=title.size()-1){
	    	int space=(title[i+1].size()/2+title[i].size()/2);
	    	if (title[i+1].size()%2==0)
	    		space--;
	    	if (i!=title.size()-1)
	    	for (int j=0;j<ms-space;j++)
	    		t+=' ';
	    	}
	    }
	    res.push_back(t);
		return res;
	}
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return 0;
}
