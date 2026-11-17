// 1. BFS(Breadth First Search)
// Concept: Visits vertices level by level using a queue.

#include <stdio.h>
    int main()
{
    int a[10][10], q[10], v, i, j, s;
    int visited[10] = {0}, f = 0, r = 0;

    printf("Enter vertices: ");
    scanf("%d", &v);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            scanf("%d", &a[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    q[r++] = s;
    visited[s] = 1;

    printf("BFS: ");
    while (f < r)
    {
        s = q[f++];
        printf("%d ", s);

        for (i = 0; i < v; i++)
            if (a[s][i] && !visited[i])
            {
                q[r++] = i;
                visited[i] = 1;
            }
    }
    return 0;
}

// 2. DFS CODE

#include <stdio.h>

    int a[10][10],
    visited[10], n;

void dfs(int v)
{
    int i;
    printf("%d ", v);
    visited[v] = 1;

    for (i = 0; i < n; i++)
        if (a[v][i] == 1 && visited[i] == 0)
            dfs(i);
}

int main()
{
    int i, j, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    printf("DFS Traversal: ");
    dfs(s);

    return 0;
}


// 3. Bubble Sort using clock()
// Concept : Compares adjacent elements and swaps them if they are in the wrong order.


#include <stdio.h>
#include <time.h>

int main()
{
    int a[100], n, i, j, temp;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    start = clock();

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    end = clock();

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nExecution time: %f seconds", time_taken);

    return 0;
}

//4 . selection sort

#include <stdio.h>
#include <time.h>

int main()
{
    int a[100], n, i, j, min, temp;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    start = clock();

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    end = clock();

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nExecution time: %f seconds", time_taken);

    return 0;
}

//5 Merge sort


#include <stdio.h>

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int b[100];

    i = low;
    j = mid + 1;
    k = low;

    while ((i <= mid) && (j <= high))
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, n - 1);

    printf("Sorted array:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

// 6. string matching


#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], pattern[50];
    int i, j, n, m, found = 0;

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern to search: ");
    scanf("%s", pattern);

    n = strlen(text);
    m = strlen(pattern);

    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }

        if (j == m)
        {
            printf("Pattern found at position %d\n", i + 1);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("Pattern not found");
    }

    return 0;
}

// 7. C Program for Prim's Algorithm (Minimum Spanning Tree)


#include <stdio.h>

int main()
{
    int cost[10][10], visited[10] = {0};
    int n, i, j, edges = 0;
    int min, a, b, mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }

    visited[0] = 1;

    while (edges < n - 1)
    {
        min = 999;

        for (i = 0; i < n; i++)
        {
            if (visited[i] == 1)
            {
                for (j = 0; j < n; j++)
                {
                    if ((visited[j] == 0) && (cost[i][j] < min))
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (min == 999)
        {
            printf("MST not possible");
            return 0;
        }

        printf("%d - %d = %d\n", a, b, min);

        mincost = mincost + min;
        visited[b] = 1;
        edges++;
    }

    printf("Minimum cost = %d", mincost);

    return 0;
}

//8. C Program for Kruskal's Algorithm (Minimum Spanning Tree)


#include <stdio.h>

int main()
{
    int cost[10][10], parent[10];
    int n, i, j, a, b, u, v;
    int min, edges = 0, mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        parent[i] = -1;
    }

    while (edges < n - 1)
    {
        min = 999;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        while (parent[u] != -1)
        {
            u = parent[u];
        }

        while (parent[v] != -1)
        {
            v = parent[v];
        }

        if (u != v)
        {
            printf("%d - %d = %d\n", a, b, min);

            mincost = mincost + min;
            parent[v] = u;
            edges++;
        }

        cost[a][b] = 999;
        cost[b][a] = 999;
    }

    printf("Minimum cost = %d", mincost);

    return 0;
}

//9/ C Program for Dijkstra's Algorithm (Shortest Path)
#include <stdio.h>

int main()
{
    int cost[10][10], dist[10], visited[10] = {0};
    int n, i, j, src, min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    for (i = 0; i < n; i++)
    {
        dist[i] = cost[src][i];
    }

    dist[src] = 0;
    visited[src] = 1;

    for (i = 1; i < n; i++)
    {
        min = 999;
        u = -1;

        for (j = 0; j < n; j++)
        {
            if ((visited[j] == 0) && (dist[j] < min))
            {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
        {
            break;
        }

        visited[u] = 1;

        for (j = 0; j < n; j++)
        {
            if ((visited[j] == 0) &&
                (cost[u][j] != 999) &&
                (dist[u] + cost[u][j] < dist[j]))
            {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    printf("\nShortest distances:\n");

    for (i = 0; i < n; i++)
    {
        if (dist[i] == 999)
        {
            printf("%d to %d = INF\n", src, i);
        }
        else
        {
            printf("%d to %d = %d\n", src, i, dist[i]);
        }
    }

    return 0;
}


//10//  sequential search

#include <stdio.h>

int main()
{
    int a[100], n, i, key, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("Element found at position %d", i + 1);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Element not found");
    }

    return 0;
}

