//Implement FIFO page replacement algorithm
#include<iostream>
using namespace std;
int n,number_of_frames;
int in[100];
int p[50];
int hit=0;
int i,j,k;
int pgfaultcnt=0;
int checkPageFault(int data)
{
    hit=0;
    for(j=0; j<number_of_frames; j++)
    {
        if(p[j]==data)
        {
            hit=1;
            break;
        }
    }
 
    return hit;
}
 
void dispPages()
{
    for (k=0; k<number_of_frames; k++)
    {
        if(p[k]!=9999)
            cout<<p[k]<<" ";
    }
 
}
 
void page_replace()
{
    for(i=0; i<n; i++)
    {
        cout<<"\n for : "<<in[i]<<" ->   ";
 
        if(checkPageFault(in[i])==0)
        {
 
            for(k=0; k<number_of_frames-1; k++)
            {
			
                p[k]=p[k+1];
 			}
            p[k]=in[i];
            pgfaultcnt++;
            dispPages();
        }
        else{
            cout<<"Page Hit";
            
		}
    }
    cout<<"\nTotal no of page faults: "<<pgfaultcnt;
}
 
int main()
{
    cout<<"\nEnter length of page reference sequence: ";
    cin>>n;
    cout<<"\nEnter the page reference sequence: ";
    for(i=0; i<n; i++)
        cin>>in[i];
    cout<<"\nEnter no of frames: ";
    cin>>number_of_frames;
	for(i=0; i<number_of_frames; i++)
	{
        p[i]=9999;
	}
	page_replace();
}

