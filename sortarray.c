#include<stdio.h>
void main()
{
  int m,n,k,d,temp,i,j;
  printf("Enter the size of first array:");
  scanf("%d",&m);
  printf("Enter the size of second array:");
  scanf("%d",&n);
   d=m+n;
  int a[m],b[n],c[d];
  printf("Enter the elements of first sorted array:");
  for( i=0;i<m;i++)
  {
    scanf("%d",&a[i]);
   
   }
  printf("Enter the elements of second sorted array:");
  for( j=0;j<n;j++)
  {
    scanf("%d",&b[j]);
  }
  k=0;i=0;j=0;
  while((i<m)&&(i<n))
     {
       if(a[i]>b[j])
       {
         c[k]=b[j];
         k++;
         j++;
        }
        else
        {
          c[k]=a[i];
          k++;
          i++;
         }
      }
   while(i<m)
   {
     c[k]=a[i];
     i++;
     k++;
    }
   while(j<n)
   {
     c[k]=b[j];
      j++;
      k++;
   }
printf("\nThe sorted merged array is:");
for(k=0;k<d;k++)
{
  printf("%d\t",c[k]);
}
}