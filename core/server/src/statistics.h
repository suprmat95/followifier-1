#ifndef CORE_STATISTICS_H
#define CORE_STATISTICS_H

#include "point.h"
#include <string>
#include <unordered_map>
#include "../gen/message.pb.h"
#include "receiver.h"
#define ONE_METER_RSSI -67

class statistics {
public:
    static Point getPosition(std::string, std::unordered_map <std::string, followifier::ESP32Metadata>&);

private:

    static bool checkPoint(double, double, std::unordered_map <std::string, followifier::ESP32Metadata>& );
    static double estimatedDistance(double);
};


#endif //CORE_STATISTICS_H
