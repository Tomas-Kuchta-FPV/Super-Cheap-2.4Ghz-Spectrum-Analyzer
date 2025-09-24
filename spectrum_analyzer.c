#include "nvs_flash.h"
#include "esp_console.h"
#include "esp_phy_cert_test.h"
#include "esp_system.h"
#include "esp_event.h"
#include <sys/time.h>
#include "esp_log.h"
#include <rom/ets_sys.h>

extern void chip_v7_set_chan(int);
extern void disable_agc(void);
extern void enable_agc(void);
extern void phy_i2c_master_mem_txcap(void);
extern void phy_set_freq(unsigned int p1, int p2);
extern void rom_iq_est_disable(void);
extern void rom_iq_est_enable(unsigned int param_1);
extern void rftest_init();

// no idea what this does, or where it is from, but something needs it
void pd_apb_peri(int x)
{
    // and apparently a nop works just fine
    return;
}

unsigned int calc_phy_freq(unsigned int target_freq_mhz)
{
    // 1 step in p1 of phy_set_freq is 1 MHz
    // 2300000 equals 2144 MHz
    return target_freq_mhz - 2144 + 2300000;
}

void app_main(void)
{

    ESP_ERROR_CHECK(nvs_flash_init());

    // necessary to get the hardware up and running
    rftest_init();

    // taken verbatim from phy_rx_cal.so
    // maybe it is a gain value?
    int some_factor = 0xe;

    for (;;)
    {
        for (int i = 2350; i < 2550; i += 2)
        {
            // for some reason, this has to be called each loop
            // chip_v7_set_chan(1);
            // disable auto gain control
            disable_agc();
            // set actual frequency
            phy_set_freq(calc_phy_freq(i), 0);
            // no idea what this does, but without it, it does not work
            phy_i2c_master_mem_txcap();

            // let's turn this off for better effect
            // disable_agc();

            // dummy reading
            // somehow necessary after setting frequency
            // ets_delay_us(5);
            // rom_iq_est_enable(1 << some_factor);
            // ets_delay_us(5);
            // rom_iq_est_disable();

            // actual reading
            // we need to enable-read-disable to get fresh values
            // (maybe triggers some adc?)
            rom_iq_est_enable(1 << some_factor);
            ets_delay_us(5);
            // adapted from rxiq_get_mis_new
            int power = *((int *)0x600a0490) >> ((some_factor - 3) & 0x1f);
            // output power level
            printf("%d:%d\n", i, power);
            // and disable again
            rom_iq_est_disable();

            // TODO / further work:
            // could we get the i-q stuff this way?!
            // some other interesting regs that rxiq_get_mis_new reads for the iq mismatch:
            //   uVar5 = param_1 - 2;
            //   iVar7 = _DAT_600a0484 >> (uVar5 & 0x1f);
            //   iVar9 = _DAT_600a0478 >> (uVar5 & 0x1f);
            //   iVar8 = _DAT_600a0480 >> (uVar5 & 0x1f);
            //   iVar10 = _DAT_600a047c >> (uVar5 & 0x1f);
        }

        // separator between series
        printf("===\n");
        ets_delay_us(20 * 1000);
    }
}