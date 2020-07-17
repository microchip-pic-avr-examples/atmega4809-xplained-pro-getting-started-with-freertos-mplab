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

#include "spi0.h"
#include "ssd1306.h"

void oled_init(void);
void oled_clear(uint16_t columns);
void oled_write(char *str, uint8_t line);

void oled_init(void)
{
	DISPLAY_SS_PORT.DIRSET       = DISPLAY_SS_PIN;
	DISPLAY_RESET_PORT.DIRSET    = DISPLAY_RESET_PIN;
	DISPLAY_DATA_CMD_PORT.DIRSET = DISPLAY_DATA_CMD_PIN;

	ssd1306_init();
	ssd1306_set_display_start_line_address(0);

	oled_clear(8 * 128);
	ssd1306_set_page_address(0);
}

void oled_clear(uint16_t columns)
{
	for (uint16_t column_address = 0; column_address < columns; column_address++) {
		if (column_address % 128 == 0) {
			ssd1306_set_page_address(column_address / 128);
			ssd1306_set_column_address(0);
		}
		/* Clear screen */
		ssd1306_write_data(0x00);
	}
}

void oled_write(char *str, uint8_t line)
{
	ssd1306_set_page_address(line);
	ssd1306_set_column_address(0);
	ssd1306_write_text(str);
}
