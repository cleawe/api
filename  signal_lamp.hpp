#include "devices.hpp"

class signal_lamp : public device
{
public:
    distance_terminal(int id, std::string ip_address, int port) : device(id, ip_address, port){}
    int* get_buttons_clicked();
    bool get_red_button_toggle();
    bool set_light_enable_first(int num, bool state);
    bool* get_light_array();
private:
    bool L1;
    bool L2;
    bool L3;
    bool L4;
};