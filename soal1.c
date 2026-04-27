#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Weather
{
    int x;
    struct Weather *next;
} Weather ;

Weather *createNode(int x){ 
    Weather *newNode = (struct Weather*)malloc(sizeof(Weather));
    newNode->x = x;
    newNode->next = NULL;
    return newNode;
}

Weather *addNode(int x, Weather *head){
    if (head == NULL)
    {
        return createNode(x);
    }
    else
    {
        Weather *currentNode = head;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = createNode(x);
        return head;
    }
}

Weather *sortWeather(Weather *head){ //Mengambil referensi dari geeksforgeeks : https://www.geeksforgeeks.org/dsa/c-program-bubble-sort-linked-list/
    int swapped, i;
    struct Weather *ptr1 = head;
    struct Weather *ptr2 = NULL;
    if (ptr1->next == NULL)
    {
        return head;
    }
    else
    {
        do
    {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != ptr2)
        {
            if (ptr1->x > ptr1->next->x)
            {
                int temp = ptr1->x;
                ptr1->x = ptr1->next->x;
                ptr1->next->x = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);
    return head;
    }
    
}

void *findMedian(Weather *head){
    int count = 0;
    float median = 0;
        Weather *currentNode = head;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
            count++;
        }
        count++;
        printf("COUNT %d", count);
        if (count%2 == 0)
        {
            currentNode = head;
            for (int i = 0; i <= count/2; i++)
            {
                if (i == count/2 - 1)
                {
                    median = currentNode->x;
                }
                else if (i == count/2)
                {
                    median = median + currentNode->x;
                }
                currentNode = currentNode->next; 
            }
            median = median/2;
        }
        else if (count%2 != 0)
        {
            currentNode = head;
            for (int i = 0; i < count/2 - 1; i++)
            {
                currentNode = currentNode->next;
            }
            if (count > 1)
            {
                median = currentNode->next->x;
            }
            else
            {
                median = currentNode->x;
            }
        }
        currentNode = head;
        printf(" SORTED ");
        while (currentNode->next != NULL)
        {
            printf("%d ", currentNode->x);
            currentNode = currentNode->next;
        }
        printf("%d", currentNode->x);
        if (count%2 == 0)
        {
            printf(" MEDIAN %.2f", median);
        }
        else
        {
            printf(" MEDIAN %.0f", median);
        }
           
    }

void *printArray(Weather *head){
    Weather *currentNode = head;
    while (currentNode->next != NULL)
    {
        printf("%d ", currentNode->x);
        currentNode = currentNode->next;
    }
    printf("%d", currentNode->x);
    
}

int main(){
    int temp = 0;
    Weather *report = NULL;
    while (temp != -1)
    {
        scanf("%d", &temp);
        if (temp != -1)
        {
            report = addNode(temp, report);
        }
        else
        {
            break;
        }
    }
    sortWeather(report);
    findMedian(report);
}
