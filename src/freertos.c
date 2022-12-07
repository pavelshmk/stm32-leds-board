#include <FreeRTOS.h>
#include <task.h>

void configureTimerForRunTimeStats(void) {

}

unsigned long getRunTimeCounterValue(void) {
    return 0;
}

void vApplicationTickHook(void) {
}

void vApplicationIdleHook(void) {
}

void vApplicationMallocFailedHook(void) {
    taskDISABLE_INTERRUPTS();
    for(;;);
}

void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName) {
    (void) pcTaskName;
    (void) pxTask;

    taskDISABLE_INTERRUPTS();
    for(;;);
}