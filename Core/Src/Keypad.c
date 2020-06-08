#include "Keypad.h"

char read_pad(void) {//polling
//	const char key[] = {
//			'1','2','3','A',
//			'4','5','6','B',
//			'7','8','9','C',
//			'*','0','#','D' };

	//1 rzad
	HAL_GPIO_WritePin(R1_PORT, R1_PIN, GPIO_PIN_RESET);//wiersz stan niski
	HAL_GPIO_WritePin(R2_PORT, R2_PIN, GPIO_PIN_SET);//wiersz stan wysoki
	HAL_GPIO_WritePin(R3_PORT, R3_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R4_PORT, R4_PIN, GPIO_PIN_SET);

	if (!(HAL_GPIO_ReadPin(C1_PORT, C1_PIN))) {//kolumna stan niski
		while (!(HAL_GPIO_ReadPin(C1_PORT, C1_PIN)));//dopoki przycisk nie jest wcisniety
			return '1';
	}
	if (!(HAL_GPIO_ReadPin(C2_PORT, C2_PIN))) {
		while (!(HAL_GPIO_ReadPin(C2_PORT, C2_PIN)));
			return '2';
	}
	if (!(HAL_GPIO_ReadPin(C3_PORT, C3_PIN))) {
		while (!(HAL_GPIO_ReadPin(C3_PORT, C3_PIN)));
			return '3';
	}
	if (!(HAL_GPIO_ReadPin(C4_PORT, C4_PIN))) {
		while (!(HAL_GPIO_ReadPin(C4_PORT, C4_PIN)));
			return 'A';
	}

	//2 rzad
	HAL_GPIO_WritePin(R1_PORT, R1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R2_PORT, R2_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(R3_PORT, R3_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R4_PORT, R4_PIN, GPIO_PIN_SET);

	if (!(HAL_GPIO_ReadPin(C1_PORT, C1_PIN))) {
		while (!(HAL_GPIO_ReadPin(C1_PORT, C1_PIN)));
			return '4';
	}
	if (!(HAL_GPIO_ReadPin(C2_PORT, C2_PIN))) {
		while (!(HAL_GPIO_ReadPin(C2_PORT, C2_PIN)));
			return '5';
	}
	if (!(HAL_GPIO_ReadPin(C3_PORT, C3_PIN))) {
		while (!(HAL_GPIO_ReadPin(C3_PORT, C3_PIN)));
			return '6';
	}
	if (!(HAL_GPIO_ReadPin(C4_PORT, C4_PIN))) {
		while (!(HAL_GPIO_ReadPin(C4_PORT, C4_PIN)));
			return 'B';
	}

	//3 rzad
	HAL_GPIO_WritePin(R1_PORT, R1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R2_PORT, R2_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R3_PORT, R3_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(R4_PORT, R4_PIN, GPIO_PIN_SET);

	if (!(HAL_GPIO_ReadPin(C1_PORT, C1_PIN))) {
		while (!(HAL_GPIO_ReadPin(C1_PORT, C1_PIN)));
			return '7';
	}
	if (!(HAL_GPIO_ReadPin(C2_PORT, C2_PIN))) {
		while (!(HAL_GPIO_ReadPin(C2_PORT, C2_PIN)));
			return '8';
	}
	if (!(HAL_GPIO_ReadPin(C3_PORT, C3_PIN))) {
		while (!(HAL_GPIO_ReadPin(C3_PORT, C3_PIN)));
			return '9';
	}
	if (!(HAL_GPIO_ReadPin(C4_PORT, C4_PIN))) {
		while (!(HAL_GPIO_ReadPin(C4_PORT, C4_PIN)));
			return 'C';
	}

	//4 rzad
	HAL_GPIO_WritePin(R1_PORT, R1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R2_PORT, R2_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R3_PORT, R3_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R4_PORT, R4_PIN, GPIO_PIN_RESET);

	if (!(HAL_GPIO_ReadPin(C1_PORT, C1_PIN))) {
		while (!(HAL_GPIO_ReadPin(C1_PORT, C1_PIN)));
			return '*';
	}
	if (!(HAL_GPIO_ReadPin(C2_PORT, C2_PIN))) {
		while (!(HAL_GPIO_ReadPin(C2_PORT, C2_PIN)));
			return '0';
	}
	if (!(HAL_GPIO_ReadPin(C3_PORT, C3_PIN))) {
		while (!(HAL_GPIO_ReadPin(C3_PORT, C3_PIN)));
			return '#';
	}
	if (!(HAL_GPIO_ReadPin(C4_PORT, C4_PIN))) {
		while (!(HAL_GPIO_ReadPin(C4_PORT, C4_PIN)));
			return 'D';
	}
	return 'E';
}
