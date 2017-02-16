#include <stdio.h>
#include <unistd.h>

int start_chat()
{
    ssize_t read = 0;
    FILE* stream = stdin;
    char* line = NULL;
    size_t len = 0;

    do
    {
        printf("Chat>> ");
        if( (read = getline(&line, &len, stream)) == -1)
            exit(-1);
        printf("Read %d chars, \"%s\"\n", len, line);
    } while( len != 0);

    return 0;
    
}


int main(int argc, char *argv[])
{
    char input = '\0';
    // How does a professional programmer begin a new program?
    // getopt(argc, argv, "options" );

    // Stand in variables for networking:
    char* host = "127.0.0.1";
    char* ipv6_host = "::1";
    int port = 5666;
    printf("Connecting to host %s, port %d.\n", host, port);

    //connect();    
    do {
        // blah blah
        printf("Please give me input: ");
        input = getc(stdin);
        getc(stdin);
        if(input == 'C')
        {
            start_chat();
        }

    } while( input != 'Q' );

    // read socket
    
    // get input from command line

    // ncurses?
    return 0;

}

