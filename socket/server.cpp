/*************************************************************************
	> File Name: server.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年12月05日 星期一 17时30分35秒
 ************************************************************************/

#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdio.h>
#include <unistd.h>
using namespace std;

int main()
{
    int server_sockfd;//服务器套接字
    int client_sockfd;//接受的客户端套接字

    sockaddr_in my_addr;//服务端地址结构体
    sockaddr_in client_addr;//客户端地址结构体


    my_addr.sin_family = AF_INET;//设置IP通信
    my_addr.sin_addr.s_addr=INADDR_ANY;//允许任意链接到本地地址
    my_addr.sin_port = htons(9999);

    if((server_sockfd = socket(AF_INET,SOCK_STREAM,0))<0)
    {
        cout<<"socket fd create failed!"<<endl;
        return 0;
    }

    int size = sizeof(my_addr);
    if(bind(server_sockfd,(struct sockaddr*)(&my_addr),size)<0)
    {
        cout<<"bind failed!";
        return 0;
    }

    listen(server_sockfd,5);//监听，队列长度为5
    cout<<"server listening...";
    socklen_t sin_len = sizeof(struct sockaddr);
    client_sockfd = accept(server_sockfd,(struct sockaddr*)&client_addr,&sin_len);
    if(client_sockfd<0)
    {
        cout<<"accept failed.";
        return 0;
    }

    char buf[]="hello";
    size_t len = sizeof(buf);
    send(client_sockfd,buf,sizeof(buf),0);
    
    close(client_sockfd);
    close(server_sockfd);
    return 0;
}
