#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3 
#define MAX_PAGES 20 

int frames[MAX_FRAMES]; 
int counts[MAX_FRAMES]; 

void initialize() {
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
        counts[i] = 0; 
    }
}

void displayFrames() {
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (frames[i] != -1)
            printf("%d ", frames[i]);
        else
            printf("- ");
    }
    printf("\n");
}

int findLFU() {
    int min = counts[0];
    int lfu_frame = 0;

    for (int i = 1; i < MAX_FRAMES; i++) {
        if (counts[i] < min) {
            min = counts[i];
            lfu_frame = i;
        }
    }

    return lfu_frame;
}

void LFU(int pages[], int n) {
    int page_faults = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                found = 1;
                counts[j]++;
                printf("page %d is already in memory\n",page);
                break;
            }
        }

        if (!found) {
            int lfu_frame = findLFU();
            frames[lfu_frame] = page;
            counts[lfu_frame] = 1;
            page_faults++;
            printf("page %d is loaded in frame %d\n",page,lfu_frame);
        }
        displayFrames();
    }

    printf("Total Page Faults: %d\n", page_faults);
}

int main() {
    int pages[MAX_PAGES];

    int n;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    initialize(); 
    LFU(pages, n);

    return 0;
}