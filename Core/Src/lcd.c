#include "lcd.h"
#include <string.h>
extern I2C_HandleTypeDef hi2c1;

#define SLAVE_ADDRESS_LCD 0x4E//adres zgodnie z ukladem PCF8574

void lcd_send_cmd(char cmd)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (cmd & 0xf0);
	data_l = ((cmd << 4) & 0xf0);
	data_t[0] = data_u | 0x0C;  //en=1, rs=0
	data_t[1] = data_u | 0x08;  //en=0, rs=0
	data_t[2] = data_l | 0x0C;  //en=1, rs=0
	data_t[3] = data_l | 0x08;  //en=0, rs=0
	HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDRESS_LCD, (uint8_t*)data_t, 4, 100);
}

void lcd_send_data(char data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (data & 0xf0);
	data_l = ((data << 4) & 0xf0);
	data_t[0] = data_u | 0x0D;  //en=1, rs=1
	data_t[1] = data_u | 0x09;  //en=0, rs=1
	data_t[2] = data_l | 0x0D;  //en=1, rs=1
	data_t[3] = data_l | 0x09;  //en=0, rs=1
	HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDRESS_LCD, (uint8_t*)data_t, 4, 100);
}

void lcd_clear(void)
{
	lcd_send_cmd(0x80);
	for (int i = 0; i < 70; i++)
	{
		lcd_send_data(' ');//czyszczenie jako pisanie spacji na kazdej pozycji
	}
}

void lcd_put_cur(int row, int col)
{
	switch (row)
	{
	case 0:
		col |= 0x80;//suma 1 rzedu liczby i kolumny
		break;
	case 1:
		col |= 0xC0;//suma 2 rzedu liczby i kolumny
		break;
	}

	lcd_send_cmd(col);
}


void lcd_init(void)
{
	// 4 bit initialisation
	HAL_Delay(50);
	lcd_send_cmd(0x30);
	HAL_Delay(5);
	lcd_send_cmd(0x30);
	HAL_Delay(1);
	lcd_send_cmd(0x30);
	HAL_Delay(10);
	lcd_send_cmd(0x20); // 4bit mode 1line
	HAL_Delay(10);

	// display initialisation
	lcd_send_cmd(0x28); // 4bit 2 lines
	HAL_Delay(1);
	lcd_send_cmd(0x08); // blank the display
	HAL_Delay(1);
	lcd_send_cmd(0x01);  // clear display
	HAL_Delay(2);
	lcd_send_cmd(0x06); //increment automatically, no display shift
	HAL_Delay(1);
	lcd_send_cmd(0x0C); //restore display (cursor hidden)
}

void lcd_send_string(char* str)
{
	while (*str) lcd_send_data(*str++);
}

void show_calc(double first, double second, char* operation) {
	char firstchar[15];
	char secondchar[15];
	sprintf(firstchar, "%lf", first);
	lcd_put_cur(0, 16 - strlen(firstchar));
	lcd_send_string(firstchar);//wyswietl first;

	if(operation!='C'){//jezeli wybrano operacje
		lcd_put_cur(1, 0);
		lcd_send_data(operation);//wyswietl operation;

		sprintf(secondchar, "%lf", second);
		lcd_put_cur(1, 16 - strlen(secondchar));
		lcd_send_string(secondchar);//wyswietl second;
	}
}
void show_reader(char* line1, char* line2) {
	lcd_clear();
	lcd_put_cur(0, 0);
	lcd_send_string(line1);//wyswietl 1 linie;
	lcd_put_cur(1, 0);
	lcd_send_string(line2);//wyswietl 2 linie;
}
