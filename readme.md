# SpecLite 2.4

**Super Cheap 2.4 GHz Spectrum Analyzer**

SpecLite 2.4 is an experimental project aiming to create the most affordable and accessible 2.4 GHz spectrum analyzer — built around the ESP32-C6 and a low-cost 2.8" TFT display.
The goal is simple: make spectrum analysis on the 2.4 GHz ISM band easy, hackable, and cheap enough that anyone can build one.

## BOM

| Item                 | Price | Link                                                  |
| -------------------- | ----- | ----------------------------------------------------- |
| 2.8 Inch TFT Display | $5.59 | https://www.aliexpress.com/item/1005003797803015.html |
| ESP32-C6             | $5.00 | https://www.aliexpress.com/item/1005006988459132.html |

### Alternatives

[ESP32-C6 SuperMini](https://www.aliexpress.com/item/1005008953214925.html)  
[ESP32-C6 with place for IPEX connector](https://www.aliexpress.com/item/1005007046508383.html)  

## Software

I'm taking a lot of inspiration from project [esp-erimentation](https://gitlab.com/ignne/esp-erimentation) so thank to these guys.  
Which is a projects that aims to poke at ESPs wireless driver and do thing that never been done on an ESP like [Talking to Space using cw by Andreas Spiess](https://www.youtube.com/watch?v=a5U1nnoJs6o).  
I’ll be building on their spectrum analyzer as a source of inspiration.

### GamePlan

1. Choose a graphics library.
2. Make minimal XY plot.
3. Implement SA esp-erimentation code.
4. Make GUI for settings like freqency and span.

- Benchmark the Update rate along the way. It can probably be calculated I don't have the skill to do that.  

### How to compile

#### esp-erimentation

> You may fing more information in video from [Andreas Spiess (timestamped)](https://youtu.be/a5U1nnoJs6o?t=327)

1. Download esp-idf version v5.2.1 - [official guide](https://docs.espressif.com/projects/esp-idf/en/release-v5.2/esp32/get-started/index.html#manual-installation)

2. Apply the patch:
    1. Download the file [esp32c6-rftest-hack.patch](https://gitlab.com/ignne/esp-erimentation/-/raw/main/additional-data/esp32c6-rftest-hack.patch?ref_type=heads&inline=false)
    2. Move it to ~/esp/v5.2.1/esp-idf
    3. Apply it with `git apply esp32c6-rftest-hack.patch` whie inside the esp-ifd directory.

You should be able to compile now. :)

## Motivation

I’ve always enjoyed experimenting with technology, and the 2.4 GHz band is especially fascinating to me. It’s packed with interesting signals — Wi-Fi, Bluetooth, Zigbee, ELRS, and even microwaves.  

When I first watched Andreas Spiess’ video on talking to space with CW, it really caught my attention. At that time, I didn’t have the skills to dive deep, but I still played around with the provided examples, thanks to Andreas’ installation guide.  

While exploring the examples, the Spectrum Analyzer really stood out from the rest.  
Running the spectrum analyzer demo was a turning point: I managed to transmit AM with an ESP32-C6 and actually saw it appear on the waterfall. That moment was incredible. From there, I kept experimenting, with the highlight being detecting microwave emissions — not just from my own, but even from neighbors’.  

Now, after nearly half a year of the ESPs being in a drawer, I’ve reached the stage of testing displays. I ordered 1.8", 2.4", and 3.5" screens to find the best balance of price and usability. In the end, I settled on the 2.8" display, but I plan to keep the code flexible so it can easily support other screen sizes.

## Atribution

- [esp-erimentation](https://gitlab.com/ignne/esp-erimentation)  
