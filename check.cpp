#include<bits/stdc++.h>
using namespace std;

int rec(vector<vector<long long>> &input,vector<vector<vector<long long>>> &ans,long long i,long long j)
{
    ans[i][j][18]=-1;

//    cout<<"Reached "<<i<<" "<<j<<endl;
//
//	for(long i=0;i<input.size();i++)
//        {for(long j=0;j<input[0].size();j++)
//            {
//                cout<<i<<" "<<j<<" : ";
//                cout<<ans[i][j][18]<<"                ";
//            }    cout<<endl;
//            }


	long long a=0,b=0,c=0,sum,num = input[i][j];
    if(num%10000019==0) {num/=10000019;a++;}
    if(num%1361==0) {num/=1361;b++;}
    if(num%1361==0) {num/=1361;b++;}
    if(num%107==0) {num/=107;c++;}
    if(num%107==0) {num/=107;c++;}

	if(i==input.size()-1 && j==input[0].size()-1)
	{
	    //cout<<" reached"<<endl;
	    sum = (a*9) + (b*3) + c;
        ans[i][j][sum]+=1;
		return 0;
	}

	if(i==input.size()-1)
	{
	    if(ans[i][j+1][18]==0) rec(input,ans,i,j+1);//cout<<"Called "<<i<<" "<<j+1<<" by "<<i<<" "<<j<<endl;}
        for(int k=0;k<18;k++)
        {
            if(ans[i][j+1][k]>0)
            {
                int a1,b1,c1,temp=k;
                a1=(temp/9)+a; temp=temp%9;
                b1=(temp/3)+b; temp=temp%3;
                c1=temp+c;
                if(a1>1) a1=1;
                if(b1>2) b1=2;
                if(c1>2) c1=2;
                sum = (a1*9) + (b1*3) + c1;
                if(sum<18)
                ans[i][j][sum]=(ans[i][j][sum]+ans[i][j+1][k])%1000000007;
            }
        }
        return 0;
	}

	if(j==input[0].size()-1)
	{
	    if(ans[i+1][j][18]==0) rec(input,ans,i+1,j);//cout<<"Called "<<i+1<<" "<<j<<" by "<<i<<" "<<j<<endl;}
        for(int k=0;k<18;k++)
        {
            if(ans[i+1][j][k]>0)
            {
                int a1,b1,c1,temp=k;
                a1=(temp/9)+a; temp=temp%9;
                b1=(temp/3)+b; temp=temp%3;
                c1=temp+c;
                if(a1>1) a1=1;
                if(b1>2) b1=2;
                if(c1>2) c1=2;
                sum = (a1*9) + (b1*3) + c1;
                if(sum<18)
                ans[i][j][sum]=(ans[i][j][sum]+ans[i+1][j][k])%1000000007;
            }
        }
        return 0;
	}

	if(ans[i+1][j][18]==0) rec(input,ans,i+1,j);//cout<<"Called "<<i+1<<" "<<j<<" by "<<i<<" "<<j<<endl;}

    if(ans[i][j+1][18]==0) rec(input,ans,i,j+1);//cout<<"Called "<<i<<" "<<j+1<<" by "<<i<<" "<<j<<endl;}

    for(int k=0;k<18;k++)
    {
        if(ans[i+1][j][k]>0)
        {
            int a1,b1,c1,temp=k;
            a1=(temp/9)+a; temp=temp%9;
            b1=(temp/3)+b; temp=temp%3;
            c1=temp+c;
            if(a1>1) a1=1;
            if(b1>2) b1=2;
            if(c1>2) c1=2;
            sum = (a1*9) + (b1*3) + c1;
            if(sum<18)
            ans[i][j][sum]=(ans[i][j][sum]+ans[i+1][j][k])%1000000007;
        }
    }

    for(int k=0;k<18;k++)
    {
        if(ans[i][j+1][k]>0)
            {
                int a1,b1,c1,temp=k;
                a1=(temp/9)+a; temp=temp%9;
                b1=(temp/3)+b; temp=temp%3;
                c1=temp+c;
                if(a1>1) a1=1;
                if(b1>2) b1=2;
                if(c1>2) c1=2;
                sum = (a1*9) + (b1*3) + c1;
                if(sum<18)
                ans[i][j][sum]=(ans[i][j][sum]+ans[i][j+1][k])%1000000007;
            }
    }

    return 0;
}
int main()
{
	long long n,m,sum=0;
	cin>>n>>m;
	vector<vector<long long>> input (n, vector<long long> (m, 0));
	for(long i=0;i<n;i++)
		for(long j=0;j<m;j++)
			cin>>input[i][j];
	vector<vector<vector<long long>>> ans (n, vector<vector<long long>> (m, vector<long long> (19,0)));
	rec(input,ans,0,0);
	for(long i=0;i<17;i++)
        sum = (sum+ans[0][0][i])%1000000007;
//	for(long i=0;i<n;i++)
//        for(long j=0;j<m;j++)
//            {
//                cout<<i<<" "<<j<<" : ";
//                for(long k=0;k<19;k++) cout<<ans[i][j][k]<<" ";
//                cout<<endl;
//            }
	cout<<sum<<endl;
	return 0;
}
