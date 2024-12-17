 #include<iostream>
 using namespace std;
 #define size 10
 int n;
 template<class T>
 void selection(T a[size])
 {
 int min,i,j;
 T temp;
 for(i=0;i<n-1;i++)
 {
 min=i;
 for(j=i+1;j<n;j++)
 {
 if(a[j]<a[min])
 min=j;
 }
 temp=a[i];
 a[i]=a[min];
 a[min]=temp;
 }
 cout<<"\n The sorted list is ....\n";
 for(i=0;i<n;i++)
 cout<<"\t"<<a[i];
 }
 int main()
 {
 int i,a[size];
 float b[size];
 cout<<"\n Selection sort";
 cout<<"\n Handling integer elements";
 cout<<"\n How many elements are there?";
 cin>>n;
 cout<<"Enter the integer numbers ";
 for(i=0;i<n;i++)
 cin>>a[i];
 selection(a);
cout<<"\n Handling float elements";
 cout<<"\n How many elements are there?";
 cin>>n;
 for(i=0;i<n;i++)
 cin>>b[i];
 selection(b);
 return 0;
 }