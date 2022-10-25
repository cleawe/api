#pragma once
#include <iostream>
#include "udp_connector.hpp"

class device {
public:
    device(int id, std::string ip_address, int port)
    {
        id_ = id;
        ip_address_ = ip_address;
        port_ = port;
        client_ = &UDPClient(port_, ip_address);
        server_ = &UDPServer(port_);
    };
    void send_message(std::string message);
    std::string slisten(bool enabled);
    UDPClient* client_;
    UDPServer* server_;
private:
    int id_;
    std::string ip_address_;
    int port_;
};