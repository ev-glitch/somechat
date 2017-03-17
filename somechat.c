#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

// define chat client modes
#define CLIENT_EXIT 99
#define CLIENT_CMD 11
#define CLIENT_CHAT 22

int start_chat()
{
    ssize_t read = 0;
    FILE* stream = stdin;
    char* line = NULL;
    size_t len = 0;
// Start networking code here:
    struct addrinfo* remote_client = NULL;
    struct addrinfo remote_client = getaddrinfo(const char *node, const char* service, const struct addrinfo* hints, struct addrinfo** res);

    do
    {
        printf("Chat>> ");
        if( (read = getline(&line, &len, stream)) == -1)
            exit(-1);
        printf("Read %d chars, \"%s\"\n", len, line);

    } while( len != 0);

    return 0;
    
}
// chat_connect will generate a duplex socket between two hosts on
// an agreed upon port and begin exchanging chat messages.

/*  chat_connect()
{
    socket(AF_INET, SOCK_STREAM, );
*/

// chat_request takes host information from the user and sends a
// datagram request to the host on port XXX 

/*  chat_request()
    {
    sendto()
*/

// chat_service will listen on port XX for new datagram requests to 
// chat.

/*  chat_service()
*/
    
// chat_listener takes a duplex socket and monitors for incoming 
// messages.

/*  chat_listener()
*/

int main(int argc, char *argv[])
{
    char input = '\0';
    // setup standardized options for commandline init.
    // getopt(argc, argv, "options" );

    // Stand in variables for networking:
    char* host = "127.0.0.1";
    char* ipv6_host = "::1";
    int port = 5666;
    printf("Connecting to host %s, port %d.\n", host, port);

    char  client_mode    = CLIENT_CMD;
    char* client_prompt = "Command>> ";
    ssize_t client_read = 0;
    char* client_input = NULL;
    size_t client_input_len = 0;
    FILE* chat_stream = stdin;
    struct protoent* tcp_proto_data = getprotobyname("tcp");
    struct protoent* udp_proto_data = getprotobyname("udp");
    do {
        // print prompt
        printf("%s", client_prompt);

        // get new input
        if( (client_read = getline(&client_input, &client_input_len, chat_stream)) == -1) exit(-1);
        printf("client_read = \"%s\"\n", client_read);

        // Process input according to client_mode
        if( client_mode == CLIENT_CMD)
        {    
            // Process a command entry
            if(str_cmp(client_read, "exit"))    { client_mode = CLIENT_EXIT; } else
            if(str_cmp(client_read, "chat"))    { client_mode = CLIENT_CHAT; } else
            if(str_cmp(client_read, "command")) { client_mode = CLIENT_CMD; }


        } else if( client_mode == CLIENT_CHAT)
        {
            start_chat();
            return 0;
        }
        else if( client_mode == CLIENT_EXIT)
            return 0;

        

    } while( input != 'Q' );

    // read socket
    
    // get input from command line

    // ncurses?
    return 0;

}

