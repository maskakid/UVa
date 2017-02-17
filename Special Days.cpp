/*NCPC 2017
  http://algo.codemarshal.org/contests/cuet-ncpc-2017-preli/problems/B
*/

#include<bits/stdc++.h>
using namespace std;

int day[17]= {13,14,21,8,21,26,1,14,1,19,18,20,31,19,10,16,25};
char mon[][12]= {"February","February","February","March","March","March","April","April","May","June","July", "August","October","November","December","December","December"};

char month[][12]= {"January","February", "March", "April" ,"May", "June" ,"July" ,"August", "September","October","November","December"};

char A[][50]= {"Pohela Falgun","Valentine's Day","International Mother Language Day","International Women's Day","International Color Day","Bangladesh Independence Day","April Fools Day","Pohela Boishakh","May Day","Father's Day","Mandela Day","World Mosquito Day","Halloween","World Toilet Day","Human Rights Day","Victory Day of Bangladesh","Christmas Day"};
char ch[12];
int d;

int valid(char ch[5] )
{
    int id=0;
    for(int i=0; i<12; i++)
    {
        if(strcmp(ch,month[i]) ==0 )
        {

            id=i;
            break;
        }
    }
    return id;
}

int main()
{
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        cin>>ch>>d;
        int id=valid(ch);

        int idx=0;

        for(int i=0 ; i<17; i++)
        {
            if( d<=day[i] and id<=valid(mon[i]))
            {
                idx=i;
                break;
            }
        }
        printf("Case %d: %s\n",cas++,A[idx]);
    }

    return 0;
}
