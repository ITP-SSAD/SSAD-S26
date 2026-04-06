#include <iostream>

using namespace std;

// Light class
class Light {
public:
    void on() {
        cout << "Lights are on." << endl;
    }
    void off() {
        cout << "Lights are off." << endl;
    }
};

// Thermostat class
class Thermostat {
public:
    void setTemperature(const string& mode) {
        if (mode == "eco") {
            cout << "Thermostat is set to eco mode." << endl;
        } else if (mode == "comfort") {
            cout << "Thermostat is set to a comfortable temperature." << endl;
        }
    }
};

// SecurityCamera class
class SecurityCamera {
public:
    void activate() {
        cout << "Security cameras activated." << endl;
    }
    void deactivate() {
        cout << "Security cameras deactivated." << endl;
    }
};

// SmartHomeFacade class
class SmartHomeFacade {
    Light light;
    Thermostat thermostat;
    SecurityCamera securityCamera;

public:
    void leavingHome() {
        cout << "Activating 'Leaving Home' scenario..." << endl;
        light.off();
        thermostat.setTemperature("eco");
        securityCamera.activate();
    }

    void arrivingHome() {
        cout << "Activating 'Arriving Home' scenario..." << endl;
        light.on();
        thermostat.setTemperature("comfort");
        securityCamera.deactivate();
    }
};

int main() {
    SmartHomeFacade smartHome;
    // Simulate leaving home
    smartHome.leavingHome();
    cout << "-----------------------------\n";
    // Simulate arriving home
    smartHome.arrivingHome();

    return 0;
}
