#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string n;

    cin>>n;

    int i, total;
    
    int len = n.size();
    for(i=0; i < len; i++)
    {
        total += n[i] - '\0';
    }

    cout<<total % 3<<endl;
}