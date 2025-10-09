#ifndef CAR_H
#define CAR_H

#include "PassengerPerevozchik.h"

    class Car : public PassengerPerevozchik {
    private:
        int passengerCapacity;  // вместимость
        double fuelConsumption; // расход на 100 километриков

    public:
        Car();
        Car(const std::string& n, double s, double c, double d, int capacity, double consumption);


        void setPassengerCapacity(int capacity);
        int getPassengerCapacity() const;
        void setFuelConsumption(double consumption);
        double getFuelConsumption() const;

        // переопределяемые методы
        double calculateCost() const override;
        double calculateTime() const override;

        // переопред. ввод вывод
        std::ostream& output(std::ostream& os) const override;
        std::istream& input(std::istream& is) override;


        //оператор присваивания
        Car& operator=(const Car& other);
    };



#endif