#ifndef _Y_GLOBAL_H_
#define _Y_GLOBAL_H_

#include "main.h"
/*
	�궨������
*/
#define VERSION 202511051  // �汾����
#define ACTION_USE_ROM 0  // 1:������ʹ���ڲ����鶯����	0:������ʹ����λ�����ض�����
#define CYCLE 1000		  // PWMģ������
#define PS2_LED_RED 0x73  // PS2�ֱ����ģʽ
#define PS2_LED_GRN 0x41  // PS2�ֱ��̵�ģʽ
#define PSX_BUTTON_NUM 16 // �ֱ�������Ŀ
#define PS2_MAX_LEN 32	  // �ֱ���������ֽ���
#define FLAG_VERIFY 0x25  // У���־
#define ACTION_SIZE 256	  // һ�������Ĵ洢��С

#define SERVO_NUM 8 /* ������� */

#define MODULE "YH-KSTM32"

#define W25Q64_INFO_ADDR_SAVE_STR (((8 << 10) - 4) << 10) //(8*1024-4)*1024		//eeprom_info�ṹ��洢��λ��

extern u8 AI_mode;
extern u8 OLED_mode;
extern u8 mode_run;
extern u8 forbid_turn;//ѭ��ģʽ�����ͼ
extern u8 group_do_ok;

extern uint8_t uart_receive_num;


extern  uint8_t uartTransmitting ;

#define CMD_RETURN_SIZE 1024

#define PRE_CMD_SIZE 128

#define UART_FLUSH_TIMEOUT 1000 // ��ʱֵ������ϵͳʱ�ӵ���

typedef struct
{
	u32 version;
	u32 dj_record_num;
	char pre_cmd[PRE_CMD_SIZE + 1];
	int dj_bias_pwm[SERVO_NUM + 1];
	uint8_t color_base_flag;
	int color_red_base;
	int color_grn_base;
	int color_blu_base;

	uint16_t ps2_cmd_size; /* ps2ָ�����ݴ�С */
} eeprom_info_t;

extern eeprom_info_t eeprom_info;
extern char cmd_return[CMD_RETURN_SIZE];

uint16_t str_contain_str(char *str, char *str2);
int abs_int(int int1);
void selection_sort(int *a, int len);
void replace_char(char *str, char ch1, char ch2);
void int_exchange(int *int1, int *int2);
float abs_float(float value);

void parse_action(char *uart_receive_buf);
void parse_cmd(char *cmd);

int kinematics_move(float x, float y, float z, int time);
int kinematics_move_extend(float x, float y, float z, float pitch, float roll, float grab, int time);
void set_servo(int index, int pwm, int time);
void zx_uart_send_str(char *str);

void soft_reset(void);
void parse_string(char *str);
void rewrite_eeprom(void);
void save_action(char *str);
void app_action_run(void);
void do_group_once(int group_num);
#endif
