#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int sock;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8000);
    addr.sin_addr.s_addr = inet_addr("192.168.111.10");

    sendto(sock, "a1\n", 13, 0,(struct sockaddr *)&addr, sizeof(addr));
    close(sock);
    return 0;
}
