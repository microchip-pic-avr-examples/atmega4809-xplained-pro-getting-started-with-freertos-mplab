/*
(C) 2018 Microchip Technology Inc. and its subsidiaries.

Subject to your compliance with these terms, you may use Microchip software and
any derivatives exclusively with Microchip products. It is your responsibility
to comply with third party license terms applicable to your use of third party
software (including open source software) that may accompany Microchip software.

THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER EXPRESS,
IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES
OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER
RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF
THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT ALLOWED
BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS
SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY
TO MICROCHIP FOR THIS SOFTWARE.
*/

#include <avr/io.h>
#include <stdio.h>

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "stream_buffer.h"
#include "message_buffer.h"
#include "semphr.h"

/* Tasks */
#include "keyboard.h"
#include "LED.h"
#include "clock.h"
#include "terminal.h"

/* Services */
#include "spi0.h"
#include "oled.h"

/* Private data */
static char str_buff[20];

/* Private Function Prototypes */
static void system_init();

/* Function Prototypes */
void tsk_main(void *pvParams);
void tsk_term_rx(void *pvParams);

/* Global Data */
QueueHandle_t         led_queue;
QueueHandle_t         key_queue;
SemaphoreHandle_t     oled_semaphore;
MessageBufferHandle_t terminal_tx_buffer;
StreamBufferHandle_t  terminal_rx_buffer;

int main(void)
{
	system_init();
	spi0_init();
	oled_init();
	LEDs_init();

	/* Initialize global inter-task communication infrastructure */
	led_queue          = xQueueCreate(10, 1);
	key_queue          = xQueueCreate(10, 1);
	oled_semaphore     = xSemaphoreCreateMutex();
	terminal_rx_buffer = xStreamBufferCreate(50, 1);
	terminal_tx_buffer = xMessageBufferCreate(50);

	/* Task Registration and creation */
	xTaskCreate(tsk_main, "main", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	xTaskCreate(tsk_keyboard, "kbrd", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
	xTaskCreate(tsk_LED, "LEDs", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
	xTaskCreate(tsk_status_LED, "stsLed", configMINIMAL_STACK_SIZE, NULL, 0, NULL);
	xTaskCreate(tsk_term_tx, "TermTsk", configMINIMAL_STACK_SIZE, NULL, 0, NULL);
	xTaskCreate(tsk_clk, "clk", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
	xTaskCreate(tsk_term_rx, "TermRx", configMINIMAL_STACK_SIZE, NULL, 0, NULL);

	vTaskStartScheduler();
	return 0;
}

void tsk_main(void *pvParams)
{
	key_msg_t key_msg;

	/* Receive data from Queue and suspend if no data ready */
	while (xQueueReceive(key_queue, &key_msg, portMAX_DELAY)) {
		/* Control LED according to reported key message - Key0 unused*/
		if (key_msg.key != 0) {
			xQueueSendToBack(led_queue, &key_msg, 0);
		}

		/* Build string to be displayed on OLED */
		sprintf(str_buff, "Button %d %s", key_msg.key, key_msg.state ? "Pushed" : "Released");
		sprintf(str_buff, "%-19s", str_buff);

		/* Get access to OLED and write string */
		if (xSemaphoreTake(oled_semaphore, pdMS_TO_TICKS(100)) == pdTRUE) {
			oled_write(str_buff, 1);
			xSemaphoreGive(oled_semaphore);
		}
	}
}

/* Private Methods */
static void system_init()
{
	/* Set clock prescaler to div2 */
	_PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, CLKCTRL_PEN_bm);
}
