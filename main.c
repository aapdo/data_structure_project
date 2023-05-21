#include "search/search_engine.h"

int main() {
    char c, fname[20];
    char w1[100], * w2;
    int wcount;
    printf("************* Command ************\n");
    printf("R: Read data, S: Search data \n");
    printf("P: Print inorder, Q: Quit \n");
    printf("**********************************\n");
    while (1) {
        fflush(stdin);
        printf("\nCommand> ");
        c = getchar();
        getchar();
        c = toupper(c);
        switch (c) {
            case 'R':
                printf("\n Dictionary file name: ");
                scanf("%s", fname);
                wcount = build_dictionary(fname);
                printf(" Total number of words: %d \n", wcount);
                break;
            case 'S':
                printf("\n Word: ");
                scanf("%s", w1);
                w2 = bst_search(w1);
                if (w2) printf(" Meaning: %s \n", w2);
                else printf(" No such word ! \n");
                break;
            case 'P':
                printf("\n");
                bst_show_inorder(root);
                break;
            case 'Q':
                printf("\n");
                exit(0);
            default: break;
        }
    }
}

int build_dictionary(char* fname) {
    FILE *fp = fopen(fname, "r");
    int count = 0;
    char buffer1[100], buffer2[100];

    if(fp == NULL) {
        printf("파일 읽기 실패\n");
        return -1;
    }
    while(fscanf(fp, "%s %s", buffer1, buffer2) == 2) {
        bst_insert(buffer1, buffer2);
        count++;
    }
    fclose(fp);
    return count;
}

void bst_insert(char* w1, char* w2) {
    tree_pointer child = (tree_pointer)malloc(sizeof(tree_node));
    strcpy(child->w1, w1);
    strcpy(child->w2, w2);
    child->left = NULL;
    child->right = NULL;
    if (root == NULL) {
        root = child;
        return;
    }
    
    tree_pointer cur = root;

    while(cur) {
        if(strcmp(w1, cur->w1) <= 0) {
            if(cur->left == NULL) {
                cur->left = child;
                break;
            }
            cur = cur->left;    
        } else {
            if (cur->right == NULL) {
                cur->right = child;
                break;
            }
            cur = cur->right;
        }
    }
}

char* bst_search(char* w1) {
    tree_pointer ptr = root;

    while (strcmp(w1, ptr->w1) != 0)
    {
        if(strcmp(w1, ptr->w1) < 0) {
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        } 
    }
    return ptr->w2;
}

void bst_show_inorder(tree_pointer ptr) {
    if(ptr) { 
        bst_show_inorder(ptr->left);
        printf("%s %s\n", ptr->w1, ptr->w2); 
        bst_show_inorder(ptr->right);
    }
}
