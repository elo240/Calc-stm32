#include "stm32f3xx_hal.h"

void lcd_init(void);   // inicjalizacja

void lcd_send_cmd(char cmd);  // wyslij rozkaz

void lcd_send_data(char data);  // wyslij dane

void lcd_send_string(char* str);  // wyslij rozkaz string

void lcd_put_cur(int row, int col);  // umiesc kursor na pozycji row (0 or 1), col (0-15);

void lcd_clear(void);//wyczysc

void show_calc(double first, double second, char* operation);//pokaz kalukulator

void show_reader(char* line1,char* line2);//pokaz czytnik
