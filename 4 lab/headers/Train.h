#ifndef TRAIN_H
#define TRAIN_H

#include "PassengerPerevozchik.h"

class Train : public PassengerPerevozchik {
private:
    int wagonCount;
    std::string comfortClass;

public:
    Train();
    Train(const std::string& n, double s, double c, double d, int wagons, const std::string& comfort);

    void setWagonCount(int count);
    int getWagonCount() const;
    void setComfortClass(const std::string& comfort);
    std::string getComfortClass() const;
    void setMenu() override;
    double calculateCost() const override;
    double calculateTime() const override;
    void shapka() const override;
    void print() const override;
    
    friend std::ostream& operator<<(std::ostream& os, const Train& obj) {
        os << obj.getName();
        return os;
    }
};

std::istream& operator>>(std::istream& is, Train& train);

#endif