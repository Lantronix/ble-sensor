/*
 * Copyright 2017, Cypress Semiconductor Corporation or a subsidiary of 
 * Cypress Semiconductor Corporation. All Rights Reserved.
 * 
 * This software, associated documentation and materials ("Software"),
 * is owned by Cypress Semiconductor Corporation
 * or one of its subsidiaries ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products. Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */

/** @file
 * Header file that includes all API & helper functions
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************
 * @cond      Macros
 ******************************************************/

#ifndef RESULT_ENUM
#define RESULT_ENUM( prefix, name, value )  prefix ## name = (value)
#endif /* ifndef RESULT_ENUM */

/*
 * Values: 0 - 999
 */
#define WICED_RESULT_LIST( prefix ) \
    RESULT_ENUM( prefix, SUCCESS,                        0 ),   /**< Success */                        \
    RESULT_ENUM( prefix, PENDING,                        1 ),   /**< Pending */                        \
    RESULT_ENUM( prefix, TIMEOUT,                        2 ),   /**< Timeout */                        \
    RESULT_ENUM( prefix, PARTIAL_RESULTS,                3 ),   /**< Partial results */                \
    RESULT_ENUM( prefix, ERROR,                          4 ),   /**< Error */                          \
    RESULT_ENUM( prefix, BADARG,                         5 ),   /**< Bad Arguments */                  \
    RESULT_ENUM( prefix, BADOPTION,                      6 ),   /**< Mode not supported */             \
    RESULT_ENUM( prefix, UNSUPPORTED,                    7 ),   /**< Unsupported function */           \
    RESULT_ENUM( prefix, OUT_OF_HEAP_SPACE,              8 ),   /**< Dynamic memory space exhausted */ \
    RESULT_ENUM( prefix, NOTUP,                          9 ),   /**< Interface is not currently Up */  \
    RESULT_ENUM( prefix, UNFINISHED,                    10 ),   /**< Operation not finished yet */     \
    RESULT_ENUM( prefix, CONNECTION_LOST,               11 ),   /**< Connection to server lost */      \
    RESULT_ENUM( prefix, NOT_FOUND,                     12 ),   /**< Item not found */                 \
    RESULT_ENUM( prefix, PACKET_BUFFER_CORRUPT,         13 ),   /**< Packet buffer corrupted */        \
    RESULT_ENUM( prefix, ROUTING_ERROR,                 14 ),   /**< Routing error */                  \
    RESULT_ENUM( prefix, BADVALUE,                      15 ),   /**< Bad value */                      \
    RESULT_ENUM( prefix, WOULD_BLOCK,                   16 ),   /**< Function would block */           \
    RESULT_ENUM( prefix, ABORTED,                       17 ),   /**< Operation aborted */              \
    RESULT_ENUM( prefix, CONNECTION_RESET,              18 ),   /**< Connection has been reset */      \
    RESULT_ENUM( prefix, CONNECTION_CLOSED,             19 ),   /**< Connection is closed */           \
    RESULT_ENUM( prefix, NOT_CONNECTED,                 20 ),   /**< Connection is not connected */    \
    RESULT_ENUM( prefix, ADDRESS_IN_USE,                21 ),   /**< Address is in use */              \
    RESULT_ENUM( prefix, NETWORK_INTERFACE_ERROR,       22 ),   /**< Network interface error */        \
    RESULT_ENUM( prefix, ALREADY_CONNECTED,             23 ),   /**< Socket is already connected */    \
    RESULT_ENUM( prefix, INVALID_INTERFACE,             24 ),   /**< Interface specified in invalid */ \
    RESULT_ENUM( prefix, SOCKET_CREATE_FAIL,            25 ),   /**< Socket creation failed */         \
    RESULT_ENUM( prefix, INVALID_SOCKET,                26 ),   /**< Socket is invalid */              \
    RESULT_ENUM( prefix, CORRUPT_PACKET_BUFFER,         27 ),   /**< Packet buffer is corrupted */     \
    RESULT_ENUM( prefix, UNKNOWN_NETWORK_STACK_ERROR,   28 ),   /**< Unknown network stack error */    \
    RESULT_ENUM( prefix, NO_STORED_AP_IN_DCT,           29 ),   /**< DCT contains no AP credentials */ \
    RESULT_ENUM( prefix, STA_JOIN_FAILED,               30 ),   /**< Join failed */                    \
    RESULT_ENUM( prefix, PACKET_BUFFER_OVERFLOW,        31 ),   /**< Packet buffer overflow */         \
    RESULT_ENUM( prefix, ALREADY_INITIALIZED,           32 ),   /**< Module has already been inited */

#define BT_RESULT_LIST( prefix ) \
        RESULT_ENUM( prefix, SUCCESS,                      0 ),   /**< Success */                                               \
        RESULT_ENUM( prefix, PENDING,                      1 ),   /**< Pending */                                               \
        RESULT_ENUM( prefix, TIMEOUT,                      2 ),   /**< Timeout */                                               \
        RESULT_ENUM( prefix, PARTIAL_RESULTS,              3 ),   /**< Partial results */                                       \
        RESULT_ENUM( prefix, ERROR,                        4 ),   /**< Error */                                                 \
        RESULT_ENUM( prefix, BADARG,                       5 ),   /**< Bad Arguments */                                         \
        RESULT_ENUM( prefix, BADOPTION,                    6 ),   /**< Mode not supported */                                    \
        RESULT_ENUM( prefix, UNSUPPORTED,                  7 ),   /**< Unsupported function */                                  \
        RESULT_ENUM( prefix, OUT_OF_HEAP_SPACE,            8 ),   /**< Dynamic memory space exhausted */                        \
        RESULT_ENUM( prefix, NOTUP,                        9 ),   /**< Interface is not currently up */                        \
        RESULT_ENUM( prefix, LIST_EMPTY,                8010 ),   /**< List is empty */                                         \
        RESULT_ENUM( prefix, ITEM_NOT_IN_LIST,          8011 ),   /**< Item not found in the list */                            \
        RESULT_ENUM( prefix, PACKET_DATA_OVERFLOW,      8012 ),   /**< Data overflow beyond the packet end */                   \
        RESULT_ENUM( prefix, PACKET_POOL_EXHAUSTED,     8013 ),   /**< All packets in the pool is in use */                     \
        RESULT_ENUM( prefix, PACKET_POOL_FATAL_ERROR,   8014 ),   /**< Packet pool fatal error such as permanent packet leak */ \
        RESULT_ENUM( prefix, UNKNOWN_PACKET,            8015 ),   /**< Unknown packet */                                        \
        RESULT_ENUM( prefix, PACKET_WRONG_OWNER,        8016 ),   /**< Packet is owned by another entity */                     \
        RESULT_ENUM( prefix, BUS_UNINITIALISED,         8017 ),   /**< Bluetooth bus isn't initialised */                       \
        RESULT_ENUM( prefix, MPAF_UNINITIALISED,        8018 ),   /**< MPAF framework isn't initialised */                      \
        RESULT_ENUM( prefix, RFCOMM_UNINITIALISED,      8019 ),   /**< RFCOMM protocol isn't initialised */                     \
        RESULT_ENUM( prefix, STACK_UNINITIALISED,       8020 ),   /**< SmartBridge isn't initialised */                         \
        RESULT_ENUM( prefix, SMARTBRIDGE_UNINITIALISED, 8021 ),   /**< Bluetooth stack isn't initialised */                     \
        RESULT_ENUM( prefix, ATT_CACHE_UNINITIALISED,   8022 ),   /**< Attribute cache isn't initialised */                     \
        RESULT_ENUM( prefix, MAX_CONNECTIONS_REACHED,   8023 ),   /**< Maximum number of connections is reached */              \
        RESULT_ENUM( prefix, SOCKET_IN_USE,             8024 ),   /**< Socket specified is in use */                            \
        RESULT_ENUM( prefix, SOCKET_NOT_CONNECTED,      8025 ),   /**< Socket is not connected or connection failed */          \
        RESULT_ENUM( prefix, ENCRYPTION_FAILED,         8026 ),   /**< Encryption failed */                                     \
        RESULT_ENUM( prefix, SCAN_IN_PROGRESS,          8027 ),   /**< Scan is in progress */                                   \
        RESULT_ENUM( prefix, CONNECT_IN_PROGRESS,       8028 ),   /**< Connect is in progress */                                \
        RESULT_ENUM( prefix, DISCONNECT_IN_PROGRESS,    8029 ),   /**< Disconnect is in progress */                             \
        RESULT_ENUM( prefix, DISCOVER_IN_PROGRESS,      8030 ),   /**< Discovery is in progress */                              \
        RESULT_ENUM( prefix, GATT_TIMEOUT,              8031 ),   /**< GATT timeout occured*/                                   \
        RESULT_ENUM( prefix, ATTRIBUTE_VALUE_TOO_LONG,  8032 ),   /**< Attribute value too long */                              \
        RESULT_ENUM( prefix, BUSY,                      8033 ),   /**< Busy */                                                  \
        RESULT_ENUM( prefix, NO_RESOURCES,              8034 ),   /**< No resources to issue command     */                     \
        RESULT_ENUM( prefix, ILLEGAL_VALUE,             8035 ),   /**< Illegal parameter value           */                     \
        RESULT_ENUM( prefix, WRONG_MODE,                8036 ),   /**< Device in wrong mode for request  */                     \
        RESULT_ENUM( prefix, UNKNOWN_ADDR,              8037 ),   /**< Unknown remote BD address         */                     \
        RESULT_ENUM( prefix, BAD_VALUE_RET,             8038 ),   /**< A bad value was received from HCI */                     \
        RESULT_ENUM( prefix, NOT_AUTHORIZED,            8039 ),   /**< Authorization failed              */                     \
        RESULT_ENUM( prefix, DEV_RESET,                 8040 ),   /**< Device has been reset             */                     \
        RESULT_ENUM( prefix, CMD_STORED,                8041 ),   /**< request is stored in control block */                    \
        RESULT_ENUM( prefix, ILLEGAL_ACTION,            8042 ),   /**< state machine gets illegal command */                    \
        RESULT_ENUM( prefix, DELAY_CHECK,               8043 ),   /**< delay the check on encryption */                         \
        RESULT_ENUM( prefix, SCO_BAD_LENGTH,            8044 ),   /**< Bad SCO over HCI data length */                          \
        RESULT_ENUM( prefix, SUCCESS_NO_SECURITY,       8045 ),   /**< security passed, no security set  */                     \
        RESULT_ENUM( prefix, FAILED_ON_SECURITY,        8046 ),   /**< security failed                   */                     \
        RESULT_ENUM( prefix, REPEATED_ATTEMPTS,         8047 ),   /**< repeated attempts for LE security requests */            \
        RESULT_ENUM( prefix, MODE4_LEVEL4_NOT_SUPPORTED,8048 ),   /**< Secure Connections Only Mode can't be supported */       \
        RESULT_ENUM( prefix, USE_DEFAULT_SECURITY,      8049 ),   /**< Use  default security*/                                  \
        RESULT_ENUM( prefix, KEY_MISSING,               8050 ),   /**< Key Missing */                                           \
        RESULT_ENUM( prefix, ENCRYPT_DISABLED,          8051 ),   /**< Encryption is disabled */                                \
        RESULT_ENUM( prefix, UNKNOWN_EVENT,             8052 ),   /**< Unknown event is received */

/******************************************************
 * @endcond    Enumerations
 ******************************************************/

/**
 * WICED Result Type
 */
typedef enum
{
    WICED_RESULT_LIST     ( WICED_            )  /*     0 -   999 */
    BT_RESULT_LIST        ( WICED_BT_         )  /*  8000 -  8999 */
} wiced_result_t;

#ifndef USE_BOOL_UINT32
/**
 * Boolean values
 */
typedef enum
{
    WICED_FALSE = 0,
    WICED_TRUE  = 1
} wiced_bool_t;
#else
/**
 * Boolean values
 * wiced_bool_t typedef to enum allows compiler to potentially optimize the size,
 * This can create issues when other pre-build code like BT patch ROM typedef wiced_bool_t
 * to other types.
 */
enum wiced_bool
{
    WICED_FALSE = 0,
    WICED_TRUE  = 1
};
typedef unsigned int wiced_bool_t;
#endif

/******************************************************
 *            Structures
 ******************************************************/

/******************************************************
 *            Function Declarations
 ******************************************************/

#ifdef __cplusplus
} /*extern "C" */
#endif
