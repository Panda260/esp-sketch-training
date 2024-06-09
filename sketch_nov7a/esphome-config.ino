esphome:
  name: schule
  friendly_name: schule

esp32:
  board: esp32dev
  framework:
    type: arduino

# Enable logging
logger:

# Enable Home Assistant API
api:
  encryption:
    key: "UJN3z+Nil37eZqZhoQvpI5pBQVppJCgTNZFm2E/9rdg="

ota:
  password: "2e2816efd8afd1b3b1a0c588d1f8290f"

wifi:
  ssid: !secret wifi_ssid
  password: !secret wifi_password

  # Enable fallback hotspot (captive portal) in case wifi connection fails
  ap:
    ssid: "Schule Fallback Hotspot"
    password: "ualo97EobzLV"

captive_portal:
    
sensor:
  - platform: dht
    model: "AM2302"
    pin: 4
    temperature:
      name: "Temperatur"
    humidity:
      name: "Humidity"
    update_interval: 5s
