/*
AUTHOR: Goethe Cruz
FILENAME: lab_4.c
SPECIFICATION: STACKS
FOR: Cs 2413 Data Structure Section D52

------------------------------------------------------------------------------------------------------
NAME: main
INPUT: int argc, pointer character argv[]
OUTPUT: functions below
PURPOSE: Display a menu and, utilizing the following functions, allow the user to read, display, and find the 
shortest distance between each node and the shortest path to the disired node from a given starting point

NAME: create_graph
INPUT: char file_name[]
OUTPUT: void
PURPOSE: Retrieve and read the file to create the graph from the data given

NAME: find_node_index
INPUT: char node
OUTPUT: integer -1
PURPOSE: Allocate the proper memory to each of the representative letters 'A', 'B', 'C', and 'D'

NAME: display
INPUT: void
OUTPUT: void
PURPOSE: Display the graph that was created and read

NAME: shortest_dist
INPUT: char node
OUTPUT: void
PURPOSE: Utilizes "min_distance" and "dijstra" to calculate the shortest distance between two nodes

NAME: dijkstra
INPUT: int graph[][] & int source
OUTPUT: integer
PURPOSE: Utilize Dijkstra's algorythm with this function

NAME: min_distance
INPUT: int dist[] & int s_set[]
OUTPUT: min_i...Minimum index
PURPOSE: Find the shortest distance between the desired nodes within the graph
*/
#include <stdio.h>

#define MAX 9999

int dist[4];
int matrix[4][4] = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};

void create_graph(char file_name[]);
int find_node_index(char node);
void display();
void shortest_distance(char node);
int dikjstra(int graph[4][4], int source);
int min_distance(int dist[], int s_set[]);

int main(int argc, char* argv[])
{
    int run = 1;
    int choice;
    char s_node;
    while(run)
    {
        printf("Graph Program\n");
        printf("1. Create Graph\n");
        printf("2. Display Graph\n");
        printf("3. Find Shortest Distance\n");
        printf("4. Exit Program\n");
        printf("Enter Choice: \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create_graph(argv[1]);
                printf("Graph Created From CSV File\n");
                break;
            case 2:
                display();
                printf("\n\n");
                break;
            case 3:
                printf("Choose Source Node: \n");
                scanf("%s", &s_node);
                shortest_distance(s_node);
                printf("\n\n");
                break;
            case 4:
                printf("Exiting Program\n");
                run = 0;
                break;
        }
    }
    return 0;
}

void create_graph(char file_name[])
{
    FILE* fp = fopen("data.csv", "r");
    char source;
    char destination;
    int weight;

    while(fscanf(fp, "%c, %c, %d", &source, &destination, &weight))
    {
        int s = find_node_index(source);
        int d = find_node_index(destination);
        matrix[s][d] = weight;
        matrix[d][s] = weight;
    }
}

int find_node_index(char node)
{
    char node_names[4] = {'A', 'B', 'C', 'D'};
    for(int i = 0; i < 4; i = i + 1)
    {
        if(node_names[i] == node)
        {
            return i;
        }
    }
    return(-1);
}

void display()
{
    printf("Displaying...\n");
    printf("\tA\tB\tC\tD\n");
    char node_names[4] = {'A', 'B', 'C', 'D'};
    for(int i = 0; i < 4; i = i + 1)
    {
        printf("%c", node_names[i]);
        for(int j = 0; j < 4; j = j + 1)
        {
            printf("\t%d", matrix[i][j]);
            if(j == 3)
            {
                printf("\n");
            }
        }
    }
}

void shortest_dist(char node)
{
    int i;
    char destination_nodes[4] = {'A', 'B', 'C', 'D'};
    int start = 0;

    int matrix[4][4] = {{0, 8, 22, 0}, {8, 0, 7, 15}, {22, 7, 0, 18}, {0, 15, 18, 0}};
    int visited[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    printf("Source Node\t||Destination Node||\tShortest Distance\n");
    //char destination_nodes[4] = {'A', 'B', 'C', 'D'};
    
    for(i = 0; i < 4; i = i + 1)
    {
        if(node == destination_nodes[i])
        {
            start = i;
        }
    }
    //Now, perform dijkstras algorithm for the selected node
    dikjstra(matrix, start); 
    for(i = 0; i < 4; i = i + 1)
    {
        printf("\t%c\t\t\t\t%c\t\t\t\t%d\n", node, destination_nodes[i], dist[i]);
    }
}

int dijkstra(int graph[4][4], int source)
{
    int i;
    int arb;
    int count = 0;
    //Shortest distance from source to the index
    int dist[4];
    //Then, Set the shortest path
    int s_set[4];

    //Initialize Distances to infinity and set the shortest path to 0
    for(i = 0; i < 4; i = i + 1)
    {
        dist[i] = MAX;
        s_set[i] = 0;
    }
    dist[source] = 0;

    for(count = 0; count < 3; count = count + 1)
    {
        arb = min_distance(dist, s_set);
        //Now we select the vertex that is visited
        s_set[arb] = 1;

        for(i = 0; i < 4; i = i + 1)
        {
            if(!s_set[i] && graph[arb][i] && dist[arb] != MAX && dist[arb] + graph[arb][i] < dist[i])
            {
                dist[i] = dist[arb] + graph[arb][i];
            }
        }
    }
    return 0;
}

int min_distance(int dist[], int s_set[])
{
    //Initialize minimun value and the index
    int min_val = MAX;
    int min_i;
    int i;

    for(i = 0; i < 4; i = i + 1)
    {
        if(s_set[i] == 0 && dist[i] <= min_val)
        {
            min_val = dist[i];
            min_i = i;
        }
    }
    return min_i;
}