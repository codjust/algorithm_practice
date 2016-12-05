/*************************************************************************
	> File Name: client.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年12月05日 星期一 18时32分52秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <unistd.h>

int main()
{
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM,0);
    if(sockfd <0)
    {
        cout<<"socket created failed!";
        return 0;
    }

    sockaddr_in client_addr;
    client_addr.sin_family = AF_INET;
    client_addr.sin_port  = htons(9999);
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int isConn = connect(sockfd,(struct sockaddr*)&client_addr,sizeof(client_addr));
    if(isConn<0)
    {
        cout<<"connect server failed.";
        return 0;
    }

    cout<<"connect to server:"<<endl;
    
    char buf[5];
    recv(sockfd,buf,5,0);
    printf("client recv:%s\n",buf);

    close(sockfd);

    return 0;
}
