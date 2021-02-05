#include<iostream>
#include<climits>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of integers in list: ";
    cin>>n;
    int nums[n];
    int maxi = INT_MIN, mini = INT_MAX;
    double  sum=0.0;
    cout<<"Enter integers:\n";
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
        sum += nums[i];
        if (nums[i]>maxi)
        {
            maxi = nums[i];
        }
        if (nums[i]<mini)
        {
            mini = nums[i];
        }
        
    }
    double mean = sum/n;
    int range = maxi-mini;
    cout<<"\nMean: "<<mean;
    cout<<"\nMaximum: "<<maxi;
    cout<<"\nMinimum: "<<mini;
    cout<<"\nRange: "<<range;
    return 0;
}
