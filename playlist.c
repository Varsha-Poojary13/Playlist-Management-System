#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song
{
    int id;
    char name[50];
    struct Song *next;
    struct Song *prev;
};

struct Song *head = NULL;

void addSong()
{
    struct Song *newSong, *temp;

    newSong = (struct Song *)malloc(sizeof(struct Song));

    printf("Enter Song ID: ");
    scanf("%d", &newSong->id);

    printf("Enter Song Name: ");
    scanf("%s", newSong->name);

    newSong->next = NULL;
    newSong->prev = NULL;

    if (head == NULL)
    {
        head = newSong;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newSong;
        newSong->prev = temp;
    }

    printf("Song added to playlist.\n");
}

void displayForward()
{
    struct Song *temp = head;

    if (head == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    printf("\nPlaylist (Next Traversal):\n");

    while (temp != NULL)
    {
        printf("ID: %d  Song: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

void displayBackward()
{
    struct Song *temp = head;

    if (head == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("\nPlaylist (Previous Traversal):\n");

    while (temp != NULL)
    {
        printf("ID: %d  Song: %s\n", temp->id, temp->name);
        temp = temp->prev;
    }
}

void deleteSong()
{
    int id;
    struct Song *temp = head;

    if (head == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    printf("Enter Song ID to delete: ");
    scanf("%d", &id);

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            free(temp);

            printf("Song deleted.\n");
            return;
        }

        temp = temp->next;
    }

    printf("Song not found.\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Playlist Management System ---\n");
        printf("1. Add Song\n");
        printf("2. Display Playlist (Next)\n");
        printf("3. Display Playlist (Previous)\n");
        printf("4. Delete Song\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addSong();
                break;

            case 2:
                displayForward();
                break;

            case 3:
                displayBackward();
                break;

            case 4:
                deleteSong();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
