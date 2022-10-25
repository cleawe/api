#include "signal_lamp.hpp"

bool signal_lamp::set_light_enable_first(int num, bool state)
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

bool signal_lamp::set_light_enable(bool L1, bool L2, bool L3, bool L4)
{
    if (client_->send_message(str.conc{"#", L1, ":", L2, ":", L3, ":", L4, "#"}) <= 0)
    {
        return false;
    }
    return true;
}

bool signal_lamp::get_light(int num)
{
    return L...<cast_unique>num;
}