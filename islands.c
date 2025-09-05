#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct rect
{
    int x1, y1;
    int x2, y2;
} rect;


int **static_to_dynamic(int w, int h, int sm[][w])
{
    int **dm = (int**)malloc(sizeof(int*)*h);
    for (int i = 0; i < h; i++)
    {
        dm[i] = (int*)malloc(sizeof(int)*w);
        for (int j = 0; j < w; j++)
        {
            dm[i][j] = sm[i][j];
        }
    }

    return dm;
}

void print_matrix(int w, int h, int **m)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int get_neighbour_label(int **labeled, int w, int h, int x, int y)
{
    if (y > 0 && labeled[y-1][x] != 0)
        return labeled[y-1][x];

    if (y < h-1 && labeled[y+1][x] != 0)
        return labeled[y+1][x];

    if (x > 0 && labeled[y][x-1] != 0)
        return labeled[y][x-1];

    if (x < w-1 && labeled[y][x+1] != 0)
        return labeled[y][x+1];

    return 0;
}

void replace_all_labels(int **labeled, int w, int h, int target_label, int new_label)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if (labeled[y][x] == target_label)
                labeled[y][x] = new_label;
        }
    }
}

void replace_neighbour(int **labeled, int w, int h, int label, int x_neighbour, int y_neighbour)
{
    int neighbour = labeled[y_neighbour][x_neighbour];
    if (neighbour != 0 && neighbour != label)
        replace_all_labels(labeled, w, h, neighbour, label);
}

void replace_neighbours(int **labeled, int w, int h, int x, int y, int label)
{
    if (y > 0)
    {
        replace_neighbour(labeled, w, h, label, x, y-1);
    }
    if (y < h-1)
    {
        replace_neighbour(labeled, w, h, label, x, y+1);
    }
    if (x > 0)
    {
        replace_neighbour(labeled, w, h, label, x-1, y);
    }
    if (x < w-1)
    {
        replace_neighbour(labeled, w, h, label, x+1, y);
    }
}

int **label_islands(int **matrix, int w, int h)
{
    int **labeled = (int**)malloc(sizeof(int*)*h);
    for (int i = 0; i < h; i++)
        labeled[i] = (int*)malloc(sizeof(int)*w);

    int count = 0;
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if (matrix[y][x] == 1 && labeled[y][x] == 0)
            {
                int label = get_neighbour_label(labeled, w, h, x, y);
                if (label == 0)
                    label = ++count;

                labeled[y][x] = label;
            }
        }
    }

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            int label = labeled[y][x];
            if (label > 0)
                replace_neighbours(labeled, w, h, x, y, label);
        }
    }
    return labeled;
}

rect find_rect(int **labeled, int w, int h, int label)
{
    int min_x = w+1, min_y = h+1;
    int max_x = -1, max_y = -1;

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if (labeled[y][x] == label)
            {
                labeled[y][x] = 0;
                if (x < min_x) min_x = x;
                if (x > max_x) max_x = x;
                if (y < min_y) min_y = y;
                if (y > max_y) max_y = y;
            }
        }
    }

    if (min_x >= w || min_y >= h)
        return (rect){-1, -1, -1, -1};

    rect r = (rect){min_x, min_y, max_x, max_y};
    return r;
}

rect *find_rects(int **labeled, int w, int h, int *n_rects)
{
    int count = 0;
    int allocated = 1;
    rect *rects = (rect*)malloc(sizeof(rect)*allocated);

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            int label = labeled[y][x];
            if (label > 0)
            {
                if (count == allocated)
                {
                    allocated++;
                    rects = (rect*)realloc(rects, sizeof(rect)*allocated);
                }
                rects[count] = find_rect(labeled, w, h, label);
                count++;
            }
        }
    } 

    *n_rects = count;
    return rects;
}

int main()
{
    char **matrix = static_to_dynamic(N, N, (int[N][N]){
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 1, 1, 0, 0},
        {0, 1, 1, 1, 0, 0, 1, 1, 1, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 1, 1, 1},
        {0, 1, 1, 1, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    });
    print_matrix(N, N, matrix);

    printf("\nLABELED:\n");

    int **labeled = label_islands(matrix, N, N);
    print_matrix(N, N, labeled);

    int n_rects = 0;
    rect *rects = find_rects(labeled, N, N, &n_rects);
    printf("N RECTS %d\n", n_rects);
    for (int i = 0; i < n_rects; i++)
    {
        rect r = rects[i];
        printf("rect (%d, %d) (%d, %d)\n", r.x1+1, r.y1+1, r.x2+1, r.y2+1);
    }

    print_matrix(N, N, labeled);

    for (int i = 0; i < N; i++)
    {
        free(matrix[i]);
        free(labeled[i]);
    }
    free(matrix);
    free(labeled);
    free(rects);
}