#include <stdio.h>
#include <stdlib.h>

// A dynamic array-based binary max heap implementation in C

typedef struct {
    int *data;      // Pointer to heap array
    int size;       // Number of elements currently in heap
    int capacity;   // Maximum capacity of heap array
} Heap;

// Initialize a new heap with given initial capacity
Heap* heap_create(int capacity) {
    Heap *h = malloc(sizeof(Heap));
    if (!h) {
        fprintf(stderr, "Memory allocation failed for heap\n");
        exit(EXIT_FAILURE);
    }
    h->data = malloc(sizeof(int) * capacity);
    if (!h->data) {
        fprintf(stderr, "Memory allocation failed for heap data\n");
        free(h);
        exit(EXIT_FAILURE);
    }
    h->size = 0;
    h->capacity = capacity;
    return h;
}

// Swap two elements in the heap array
static void heap_swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Bubble up the element at index i to restore max-heap property
static void heapify_up(Heap *h, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->data[i] > h->data[parent]) {
            heap_swap(&h->data[i], &h->data[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

// Bubble down the element at index i to restore max-heap property
static void heapify_down(Heap *h, int i) {
    int left, right, largest;
    while (1) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        largest = i;

        if (left < h->size && h->data[left] > h->data[largest]) {
            largest = left;
        }
        if (right < h->size && h->data[right] > h->data[largest]) {
            largest = right;
        }
        if (largest != i) {
            heap_swap(&h->data[i], &h->data[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

// Resize the heap's underlying array when capacity is reached
static void heap_resize(Heap *h) {
    int new_capacity = h->capacity * 2;
    int *new_data = realloc(h->data, sizeof(int) * new_capacity);
    if (!new_data) {
        fprintf(stderr, "Reallocation failed when resizing heap\n");
        exit(EXIT_FAILURE);
    }
    h->data = new_data;
    h->capacity = new_capacity;
}

// Insert a new value into the heap
void heap_insert(Heap *h, int value) {
    if (h->size == h->capacity) {
        heap_resize(h);
    }
    h->data[h->size] = value;
    heapify_up(h, h->size);
    h->size++;
}

// Peek at the maximum (root) element without removing it
int heap_peek(Heap *h) {
    if (h->size == 0) {
        fprintf(stderr, "Heap is empty, cannot peek\n");
        exit(EXIT_FAILURE);
    }
    return h->data[0];
}

// Remove and return the maximum element from the heap
int heap_extract_max(Heap *h) {
    if (h->size == 0) {
        fprintf(stderr, "Heap is empty, cannot extract\n");
        exit(EXIT_FAILURE);
    }
    int max_value = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    heapify_down(h, 0);
    return max_value;
}

// Free heap resources
void heap_destroy(Heap *h) {
    free(h->data);
    free(h);
}

// Example usage
int main(void) {
    Heap *h = heap_create(10);
    int values[] = { 5, 3, 17, 10, 84, 19, 6, 22, 9 };
    int n = sizeof(values) / sizeof(values[0]);

    printf("Inserting values into heap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
        heap_insert(h, values[i]);
    }
    printf("\n");

    printf("Heap max-heap order extraction: ");
    while (h->size > 0) {
        printf("%d ", heap_extract_max(h));
    }
    printf("\n");

    heap_destroy(h);
    return 0;
}

