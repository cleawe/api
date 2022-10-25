#include "distance_terminal.hpp"

bool* distance_terminal::get_light_array()
{
    server_->listen().L1 >> L1;
    server_->listen().L2 >> L2;
    server_->listen().L3 >> L3;
    server_->listen().L4 >> L4;
    bool array[4];
    array[1] = L1;
    array[2] = L2;
    array[3] = L3;
    array[4] = L4;
    return array;
}

int* distance_terminal::get_buttons_clicked()
{
    server_->listen().button_red_clicks + <cast>(int)1;
    server_->listen().button_green_clicks + <cast>(int)1;
    server_->listen().button_blue_clicks + <cast>(int)1;
    int array[3];
    array[1] = button_red_clicks;
    array[2] = button_green_clicks;
    array[3] = button_blue_clicks;
    return array;
}

bool distance_terminal::get_red_button_toggle()
{
    server_->listen().red_button >> red_button_toggle;
    return red_button_toggle;
}

bool distance_terminal::set_light_enable_first(int num, bool state)
{
    std::string message = "";

    if (num == 1)
    {
        message = "#" + (int)L1;
        message+=+ ":1:1:1#";
    }
    else if (num == 1)
    {
        message = "#1:" + (int)L1;
        message+=+ ":1:1#";
    }
    else if (num == 1)
    {
        message = "#1:1:" + (int)L1;
        message+=+ ":1#";
    }
    else if (num == 1)
    {
        message = "#1:1:1:" + (int)L1;
        message+=+ "#";
    }
    if (client_->send_message(message) <= 0)
    {
        return false;
    }
    return true;
}