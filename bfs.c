#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int adj[MAX][MAX];
int state[MAX];
int queue[MAX];

int n,front=-1,rear=-1;

void create_graph();
void insert(int vertex);
int isempty();
int delete();
void bfs_traversal();
void BFS(int v);

int main(){
    create_graph();
    bfs_traversal();
    return 0;
}

void create_graph(){
    int max_edge,count,origin,destin;
    printf("enter the number of vertices : ");
    scanf("%d",&n);
    max_edge=n*(n-1);
    for(count=1;count<=max_edge;count++){
        printf("enter the vertices %d (-1 -1 to quit) : ",count);
        scanf("%d%d",&origin,&destin);
        if((origin==-1)&&(destin==-1)){
            break;
        }
        if(origin>=n || destin >=n || origin < 0 || destin < 0){
            printf("invalid edge !");
            count--;
        }
        else{
            adj[origin][destin]=1;
        }
    }
}
void insert(int vertex){
    if(rear==MAX-1){
        printf("full");
    }
    else{
        if(front==-1)
        front=0;
        rear++;
        queue[rear]=vertex;
    }
}
int isempty(){
    if(front==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int delete(){
    int delete_item;
    if((front==-1)|| (front>rear)){
        printf("empty");
        exit(0);
    }
    delete_item=queue[front];
    front++;
    return delete_item;
}
void bfs_traversal(){
    int v;
    for(v=0;v<n;v++)
    state[v]=initial;
    printf("enter the start vertex : ");
    scanf("%d",&v);
    BFS(v);
    
}
void BFS(int v){
    int i;
    printf("BFS TRAVERSAL");
    insert(v);
    state[v]=waiting;
    while(!isempty()){
        v=delete();
        printf("%d",v);
        state[v]=visited;
        for(i=0;i<n;i++){
            if(adj[v][i]==1 && state[i]==initial){
                insert(i);
                state[i]=waiting;
            }
        }
    }
    printf("\n");
}
    