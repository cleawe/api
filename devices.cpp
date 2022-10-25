#include "devices.hpp"

void device::send_message(std::string message)
{
    client_->send_message(message);
}

int device::slisten(bool enabled)
{
    if (server_ != nullptr && !enabled)
    {
        delete[] server_;
        server_ = &UDPServer(port_);
    }

    return server_->listen();
}