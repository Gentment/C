.PHONY:all
all:tcpClient tcpServer

tcpClient:tcpClient.cpp
	g++ -o $@ $^ -static
tcpServer:tcpServer.cpp
	g++ -o $@ $^ -static
.PHONY:clean
clean:
	rm tcpClient tcpServer
