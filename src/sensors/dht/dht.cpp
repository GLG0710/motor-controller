#include "dht.h"

namespace Dht {
    // Privados
    static DHT dht(Pins::DHT22, DHTTYPE);
    static Data data;
    static uint32_t lastDHT = 0;

    static void setData(uint32_t now) {
        if(now - lastDHT >= DHT_MS) {
            lastDHT = now;

            const float temp = dht.readTemperature();
            const float humi = dht.readHumidity();

            if(!isnan(temp))
                data.temp = temp;

            if(!isnan(humi))
                data.humi = humi;
        }
    }

    // Públicos
    void setup() {
        dht.begin();
    }

    void loop(uint32_t now) {
        setData(now);
    }

    float getTemp() {
        return data.temp;
    }

    float getHumi() {
        return data.humi;
    }
}