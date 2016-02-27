#ifndef _TASK_H_
#define _TASK_H_

typedef enum{
	MODEM_TURN_ON = 0,
	MODEM_INIT_COMM,
	MODEM_WAIT_INIT_COMM,
	MODEM_READ_IMEI,
	MODEM_CONFIG_1,
	MODEM_CONFIG_2,
	MODEM_CONFIG_3,
	MODEM_CONNECT_SIM,
	MODEM_WAIT_CONNECT_SIM,
	MODEM_DELAY_REGISTER_NETWORK,
	MODEM_REGISTER_NETWORK,
	MODEM_DELETE_ALL_SMS,
	MODEM_GET_CSQ,
	MODEM_SET_GPRS_PROFILE,
	MODEM_SET_GPRS_APN,
	MODEM_SET_GPRS_USER,
	MODEM_SET_GPRS_PASS,
	MODEM_SET_GPRS_DYNAMIC_IP,
	MODEM_WAIT_GPRS_PROFILE,
	MODEM_SYS_WAIT_COVERAGE,
	MODEM_SYS_COVERAGE_OK
} GSM_PHASE_TYPE;

typedef enum{
	TASK_SYS_WAKEUP = 0,
	TASK_RETRY,
	TASK_WAIT_RETRY,
	TASK_WAIT_GSM_MODEM_INIT,
	TASK_GSM_ENABLE,
	TASK_GET_CSQ,
	TASK_GET_BATERY,
	TASK_GSM_GPRS_DISABLE,
	TASK_GSM_GPRS_ENABLE,
	TASK_GSM_GPRS_CHECK,
	TASK_GSM_GPRS_OK,
	TASK_GPRS_GET_CELL_LOCATION,
	TASK_GPRS_WAIT_GET_CELLOCATION,
	TASK_GPRS_INIT_TCP_SOCKET,
	TASK_GPRS_CREAT_TCP_SOCKET,
	TASK_GPRS_WAIT_TCP_SOCKET,
	TASK_GPRS_WAIT_GOT_SERVER_IP,
	TASK_GPRS_SERVER_CONNECT,
	TASK_GPRS_COLLECT_DATA,
	TASK_GPRS_SEND_DATA_HEADER,
	TASK_GPRS_SEND_DATA,
	TASK_GPRS_CHECK_ACK_SEND_DATA,
	TASK_GPRS_CHECK_RECV_DATA,
	TASK_GPRS_SERVER_DISCONECT,
	TASK_GSM_WAIT_GPRS_DISABLE,
	TASK_GSM_STOP,
	TASK_SYS_SLEEP
} GPRS_PHASE_TYPE;

extern uint8_t sendFirstPacket;

typedef enum {
	NO_TASK = 0,
	SEND_SOS_DATA_TASK,
	SEND_POWER_CMD_TASK,
	SEND_GPS_DATA_TASK,
	UPLOAD_CONFIG_TASK
} GPRS_TASK_TYPE;

uint8_t Gprs_Task(void);
void GprsTask_Init(void);
GPRS_PHASE_TYPE GprsTask_GetPhase(void);
GPRS_TASK_TYPE GprsTask_GetTask(void);
void GprsTask_WakeUp(void);
uint8_t GprsTask_StartTask(GPRS_TASK_TYPE task);
void GprsTask_Stop(void);

void Gsm_Task(void);
GSM_PHASE_TYPE GsmTask_GetPhase(void);
void GsmTask_Init(void);

#endif
