#include "sol3.h"
#include "touch_encoder.h"

void keyboard_post_init_kb(void)
{
    touch_encoder_init();
    keyboard_post_init_user();
}

void housekeeping_task_kb(void)
{
    touch_encoder_update();
}

//void dip_switch_update_kb(uint8_t index, bool active) {
//    dip_switch_update_user(index, active);
//}
