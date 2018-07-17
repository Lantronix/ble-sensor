#ifndef __BLESENSOR_INIT_H
#define __BLESENSOR_INIT_H

#include "message_queue.h"

#define MAX_DEVICE_NAME_LEN                 25
#define MAX_DEVICE_MFR_LEN                  10
#define MAX_DEVICE_MODEL_LEN                10
#define MAX_DEVICE_DISCOVER                 20
#define MAC_ADDRESS_LENGTH                  6
#define MAX_DEVICE_SERIAL_NUMBER_LEN        (MAC_ADDRESS_LENGTH * 2 + 1)

#define BT_DEVICE_NAME_PREFIX               "xPico250"

#define BLE_DEVICE_FLAG_INUSE             0x01
#define BLE_DEVICE_FLAG_SCANNED           0x02
#define BLE_DEVICE_FLAG_CONNECTING        0x04
#define BLE_DEVICE_FLAG_CONNECTED         0x08

#define BLE_MESSAGE_CONNECT              1
#define BLE_MESSAGE_DISCONNECT           2
#define BLE_MESSAGE_DISCOVER             3

typedef struct
{
    uint8_t dev_name[MAX_DEVICE_NAME_LEN];
    uint8_t dev_appearance_name[2];
    uint8_t dev_manufacturer[MAX_DEVICE_MFR_LEN];
    uint8_t dev_model[MAX_DEVICE_MODEL_LEN];
    uint8_t dev_sn[MAX_DEVICE_SERIAL_NUMBER_LEN];
    uint8_t dev_mac[MAC_ADDRESS_LENGTH];
} bt_device_info;

struct bleSensor_module_data
{
  bt_device_info dev_info;
  wiced_bt_cfg_settings_t bt_config_settings;
};

typedef PACKED struct ble_device_data
{
  uint8_t flags;
  uint8_t device_address[BD_ADDR_LEN];
  int8_t rssi;
  uint8_t addr_type;
  uint8_t dev_name[MAX_DEVICE_NAME_LEN];
  uint16_t appearance;
  uint16_t conn_id;
  uint16_t hr;
} ble_device_data;

extern ble_device_data s_bleScanResults[MAX_DEVICE_DISCOVER];

extern struct message_queue* ble_queue;
extern struct ltrx_trigger ble_queue_trigger;

struct ble_message
{
  uint8_t command;
  struct ble_device_data* device;
};

#endif
