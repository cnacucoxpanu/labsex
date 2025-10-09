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

        double calculateCost() const override;
        double calculateTime() const override;

        std::ostream& output(std::ostream& os) const override;
        std::istream& input(std::istream& is) override;

        Train& operator=(const Train& other);
    };

#endif