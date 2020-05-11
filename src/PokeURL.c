#include "PokeURL.h"

#define USAGE                                                       \
    "Usage:\n"                                                      \
    "  PokeURL [option] [file]\n"                                   \
    "Options:\n"                                                    \
    "  -r                   Reverse root domain alphabetic sort\n"  \
    "  -f                   Frequency of root visited sort then alphabetical sort\n" \
    "  -F                   Reverse frequency of root sort then alphabetical sort\n" \
    "  -h                   Help menu\n"                            \
    "\n"                                                            \
    "In-program commands:\n"                                        \
    "  ALL                  Display all root domains with subpages underneath\n" \
    "  ROOT                 Display all root domains with their frequency\n" \
    "  {root}               Display given root domain, its frequency, and the pages associated with it\n" \
    "  quit                 Exit the program\n"                     \
    "\n"                                                            \
    "If omitted, the default file is resources/.urls\n\n"

/* OPTIONS DESCRIPTOR ====================================================*/
static struct option gLongOptions[] = {
    {"reverse", no_argument, NULL, 'r'},
    {"frequency", no_argument, NULL, 'f'},
    {"rev_freq", no_argument, NULL, 'F'},
    {"help", no_argument, NULL, 'h'}};


/* Main ====================================================*/
int main(int argc, char **argv){
    int option_char = 0;
    int rflg = 0, fflg = 0, Fflg=0, errflg = 0;
    char *file = "resource/.urls";

    while ((option_char = getopt_long(argc, argv, "rfFh", gLongOptions, NULL)) != -1){
        switch (option_char)
        {
        case 'r': // Reverse root domain alphabetical sort
            rflg++; 
            break;
        
        case 'f': // Frequency of root visited then alphabetical sort
            if(Fflg){
                errflg++;
            } else{
                fflg++;
            }
            break;
        case 'F': // Reverse frequency then alphabetical sort
            if(fflg){
                errflg++;
            } else{
                Fflg++;
            }
            break;
        case 'h': // help
            fprintf(stdout, "%s", USAGE);
            break;
        default:
            fprintf(stderr, "%s", USAGE);
            exit(1);
            break;
        }
    }

    // Detects mutually exclusive option errors
    if(errflg){
        fprintf(stderr, "-f and -F are mutually exclusive\n\n%s", USAGE);
        exit(1);
    }

    // Detects if the user provided a filename
    if(optind < argc){
        file = argv[optind];
    }

    // Detect input error
    if (NULL == file)
    {
        fprintf(stderr, "%s @ %d: invalid filename\n", __FILE__, __LINE__);
        exit(1);
    }

    // Ensure file exists
    int urlfile_fd = open(file, O_RDONLY, S_IRUSR);
    if(urlfile_fd == -1){
        fprintf(stderr, "%s @ %d: error opening file\n", __FILE__, __LINE__);
        exit(1);
    }

    // Run Sorting Algorithm

    //TODO

    close(urlfile_fd);

    char input[30];
    while(1){
        printf("Select:> ");
        fgets(input, 30, stdin);

        if(strstr(input, "\n") == NULL){
            int c; while((c = getchar()) != '\n' && c != EOF){ } //clear stdin if there is extra
        }
        input[strcspn(input, "\n")] = 0; //remove trailing newline        

        if(strncmp(input, "exit", 30) == 0 || strncmp(input, "EXIT", 30) == 0 
            || strncmp(input, "quit", 30) == 0 || strncmp(input, "QUIT", 30) == 0){
            fprintf(stdout, "Quitting program... Have a wonderful day!\n");
            exit(0);
        }
    }

    return 0;
}