// 
// btstack_config.h for SAMV71 + ATWILC3000
//

#ifndef __BTSTACK_CONFIG
#define __BTSTACK_CONFIG

#define HAVE_INIT_SCRIPT
#define HAVE_EMBEDDED_TICK
#define HAVE_UART_DMA_SET_FLOWCONTROL

#define ENABLE_BLE
#define ENABLE_CLASSIC

#define ENABLE_LOG_INFO
#define ENABLE_LOG_ERROR
#define ENABLE_LE_PERIPHERAL
#define ENABLE_LE_CENTRAL

#define HCI_ACL_PAYLOAD_SIZE 1021

// memory config
#define MAX_NR_HCI_CONNECTIONS 1
#define MAX_NR_L2CAP_SERVICES  2
#define MAX_NR_L2CAP_CHANNELS  2
#define MAX_NR_RFCOMM_MULTIPLEXERS 1
#define MAX_NR_RFCOMM_SERVICES 2
#define MAX_NR_RFCOMM_CHANNELS 1
#define MAX_NR_DB_MEM_DEVICE_LINK_KEYS  2
#define MAX_NR_DB_MEM_SERVICES 1
#define MAX_NR_SM_LOOKUP_ENTRIES 1
#define MAX_NR_SERVICE_RECORD_ITEMS 2
#define MAX_NR_LE_DEVICE_DB_ENTRIES 1

#endif

