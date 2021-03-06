#include <c_types.h>
#include <spi_flash.h>

void ICACHE_FLASH_ATTR
user_rf_pre_init(void)
{
    ets_uart_printf("RF PREINIT\n");
}


uint32 ICACHE_FLASH_ATTR user_rf_cal_sector_set(void) {
    extern char flashchip;
    SpiFlashChip *flash = (SpiFlashChip*)(&flashchip + 4);
    // We know that sector size in 4096
    //uint32_t sec_num = flash->chip_size / flash->sector_size;
    uint32_t sec_num = flash->chip_size >> 12;
    ets_uart_printf("Flash %d bytes calibration data @ %x\n",
        flash->chip_size, sec_num-5);
    return sec_num - 5;
}
