#include<stdio.h>
#define INF 987654321

int D[135][135];
int P[135][135];
int n, m;

void path(int q, int r) {
   if(P[q][r]) {
      path(q, P[q][r]);
      printf("%d ",P[q][r]);
      path(P[q][r], r);
   }
}

int main(void){
   scanf("%d %d", &n, &m);
   for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
         if(i != j)
            D[i][j] = INF;
   
   for(int i=0; i<m; i++) {
      int u,v,w;
      scanf("%d %d %d", &u, &v, &w);
      D[u][v] = w;
   }

   //floyd2
   for(int k=1; k<=n; k++) 
      for(int i=1; i<=n; i++)
         for(int j=1; j<=n; j++)
            if(D[i][k] + D[k][j] < D[i][j]) {
               P[i][j] = k;
               D[i][j] = D[i][k] + D[k][j];
            }

   for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
         if(D[i][j] == INF)
            printf("INF ");
         else
            printf("%d ",D[i][j]);
      }
      printf("\n");
   }
   for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++)
         printf("%d ",P[i][j]);
      printf("\n");
   }
   
   int tc; 
   scanf("%d", &tc);
   while(tc--) {
      int q, r;
      scanf("%d %d", &q, &r);
      
      printf("%d ",q);
      path(q,r);
      printf("%d ",r);
         
      if(D[q][r] == INF)
         printf("INF ");
      else
         printf("%d ", D[q][r]);
      printf("\n");
   }

   return 0;
}
