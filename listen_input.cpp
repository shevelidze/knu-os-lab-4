#include <linux/input.h>
#include <fstream>
#include <iostream>
#include <string>

#include "event_codes.hpp"

const int KEYS_SIZE = 249;

int main()
{
    std::string device_name;
    std::cout << "Input event: ";
    std::cin >> device_name;

    std::ifstream device_stream("/dev/input/" + device_name);

    if (!device_stream)
    {
        std::cout << "Failed to open device!";
        return 1;
    }

    input_event event;

    while (device_stream.read((char *)&event, sizeof(input_event)))
    {
        if (event.type == EV_KEY && event.value == 1 && event.code < 249)
        {
            std::cout << EVENT_CODES[event.code] << "\n";
        }
    }

    device_stream.close();

    return 0;
}