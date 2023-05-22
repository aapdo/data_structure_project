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
                //wcount = build_dictionary(fname);
                printf(" Total number of words: %d \n", wcount);
                break;
            case 'S':
                printf("\n Word: ");
                scanf("%s", w1);
                //w2 = bst_search(w1);
                if (w2) printf(" Meaning: %s \n", w2);
                else printf(" No such word ! \n");
                break;
            case 'P':
                printf("\n");
                //bst_show_inorder(root);
                break;
            case 'Q':
                printf("\n");
                exit(0);
            default: break;
        }
    }
}

