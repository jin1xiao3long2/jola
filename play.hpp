#include <muduo/net/TcpServer.h>

class EchoServer
{
public:
    EchoServer(muduo::net::EventLoop* loop, const muduo::net::InetAddress& listenAddr) :loop_(loop), server_(loop, listenAddr, "EchoServer"){
        server_.setConnectionCallback(boost::bind(&EchoServer::onConnection, this, _1));
        server_.setMessageCallback(boost::bind(&EchoServer::onMessage, this, _1, _2, _3));
    }

    void start();

private:
    void onConnection(const muduo::net::TcpConnectionPtr& conn){
        LOG_INFO << "EchoServer - " << con->peerAddress().toIpPort() << "->"
                 << conn->localAddress().toIpPort() << " is "
                 << (conn->connected() ? "UP" : "DOWN");
    }

    void onMessage(const muduo::net::TcpConnectionPtr& conn, muduo::net::Buffer* buf, muduo::Timestamp time){
        muduo::string msg(buf->retrieveAllAsString());
        LOG_INFO << conn->name() << " echo " << msg.size() << " bytes, "
                 << "data received at " << time.toString();
        conn->send(msg);
    }

    muduo::net::EventLoop *loop_;
    muduo::net::TcpServer server_;
};