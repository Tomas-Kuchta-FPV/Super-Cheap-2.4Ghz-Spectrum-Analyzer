# 2.4 GHz Spectrum Analyzer (Low-Cost Edition)

This project aims to create the most affordable spectrum analyzer for 2.4 GHz frequencies.

## BOM

| Item                 | Price | Link                                                  |
| -------------------- | ----- | ----------------------------------------------------- |
| 2.8 Inch TFT Display | $6.44 | https://www.aliexpress.com/item/1005003797803015.html |
| ESP32-C6             | $5.00 | https://www.aliexpress.com/item/1005006988459132.html |

### Alternatives

[ESP32-C6 SuperMini](https://www.aliexpress.com/item/1005008953214925.html)  
[ESP32-C6 with place for IPEX connector](https://www.aliexpress.com/item/1005007046508383.html)  

## Software

I'm taking a lot of inspiration from project [esp-erimentation](https://gitlab.com/ignne/esp-erimentation). Which is a projects that aims to poke at ESPs wireless driver and do thing that never been done on an ESP like [Talking to Space using cw by Andreas Spiess](https://www.youtube.com/watch?v=a5U1nnoJs6o).  
I'm going to be taking inpirarion from their spectrum-analyzer.  

## My motivation

I like playing with technology. And 2.4Ghz Spectrum peeks my interest, beacause there is a lot of cool stuff like WiFi, Bluetooth, Zigbee, ELRS and many more...Oh and also microwaves :).  

When I saw Andreases video it peaked my interest as I like to hack stuff. But at the time I didn't have the reqired skill set.  
But I did play with the examples thanks to Andreas for making kindof a guide on how to install.  
The Spectrum Analyzer demo lit a spark in me and I got another ESP32C6 to try AM modulation and I saw it on the waterfall. It was amazing!  
Then I tried a lot of stuff the main highliht being microwaves. Because these things emit a lot of RF I saw even ones from neibors.  

After almos halve a year we are here. I have ordeder screens (1.8, 2.4, 3.5 inch) to test which will be the best in term of price/weight ratio and I picked none of them. Because I qite like the 2.8inch one. But I should make the code easy to port onto other screens.  

