/*****************************************************************************/
/*                              Legal                                        */
/*****************************************************************************/

/*
** Copyright �2017-2018. Lantronix, Inc. All Rights Reserved.
** By using this software, you are agreeing to the terms of the Software
** Development Kit (SDK) License Agreement included in the distribution package
** for this software (the �License Agreement�).
** Under the License Agreement, this software may be used solely to create
** custom applications for use on the Lantronix xPico 250 product.
** THIS SOFTWARE AND ANY ACCOMPANYING DOCUMENTATION IS PROVIDED "AS IS".
** LANTRONIX SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED
** TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, NON-INFRINGEMENT AND FITNESS
** FOR A PARTICULAR PURPOSE.
** LANTRONIX HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES,
** ENHANCEMENTS, OR MODIFICATIONS TO THIS SOFTWARE.
** IN NO EVENT SHALL LANTRONIX BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT,
** SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS,
** ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF
** LANTRONIX HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <stdio.h>
#include <string.h>

#include "wiced_bt_ble.h"
#include "wiced_bt_gatt.h"
#include "wiced_bt_cfg.h"
#include "bt_target.h"
#include "wiced_bt_stack.h"
#include "gattdefs.h"
#include "sdpdefs.h"

#include "ltrx_bt_essential.h"

#include "ltrx_compile_defines.h" /* Delivered with SDK. */
#include "ltrx_cpm.h"  /* Delivered with SDK. */
#include "ltrx_definitions.h"  /* Delivered with SDK. */
#include "ltrx_network.h"  /* Delivered with SDK. */
#include "ltrx_stream.h"  /* Delivered with SDK. */
#include "ltrx_tlog.h"  /* Delivered with SDK. */
#include "ltrx_http.h"
#include "bleSensor.h"
#include "restApi.h"

static bool webApiCbFunc(struct ltrx_http_client *client);

static const char* http_header = "HTTP/1.1 200 OK\r\nConnection: close\r\nContent-Type: application/json\r\n\r\n";

static bool webApiCbFunc(struct ltrx_http_client *client)
{
  char buf[40];
  size_t size;
  struct ltrx_ip_socket *socket = ltrx_http_get_socket(client);

  const char *path = ltrx_http_get_request_path(client);

  if(memcmp(path,"/getScanResults", 15) == 0){
    uint8_t firstElement = true;
    size = strlen(http_header);
    ltrx_ip_socket_send(socket,(const char *)http_header,size, false);
    ltrx_ip_socket_send(socket,"[",1,false);
    for(uint8_t i=0;i<MAX_DEVICE_DISCOVER;++i) {
      if(s_bleScanResults[i].flags & (BLE_DEVICE_FLAG_INUSE) ) {
        if (firstElement == true) {
          ltrx_ip_socket_send(socket,"{",1,false);
          firstElement = false;
        } else {
          ltrx_ip_socket_send(socket,",{",2,false);
        }
        size = snprintf(buf, sizeof(buf),"\"name\":\"%s\",",s_bleScanResults[i].dev_name);
        ltrx_ip_socket_send(socket, buf, size, false);
        ltrx_ip_socket_send(socket,"\"address\":\"",11,false);
        size =snprintf(buf,sizeof(buf),"%02X:%02X:%02X:%02X:%02X:%02X",
                s_bleScanResults[i].device_address[0],
                s_bleScanResults[i].device_address[1],
                s_bleScanResults[i].device_address[2],
                s_bleScanResults[i].device_address[3],
                s_bleScanResults[i].device_address[4],
                s_bleScanResults[i].device_address[5]
              );
        ltrx_ip_socket_send(socket, buf, size, false);
        size = snprintf(buf, sizeof(buf),"\",\"rssi\":%d",s_bleScanResults[i].rssi);
        ltrx_ip_socket_send(socket, buf, size, false);
        size = snprintf(buf, sizeof(buf),",\"appearance\":%u",s_bleScanResults[i].appearance);
        ltrx_ip_socket_send(socket, buf, size, false);
        size = snprintf(buf, sizeof(buf),",\"flags\":\"%02X\"",s_bleScanResults[i].flags);
        ltrx_ip_socket_send(socket, buf, size, false);
        size = snprintf(buf, sizeof(buf),",\"heartrate\":%d",s_bleScanResults[i].hr);
        ltrx_ip_socket_send(socket, buf, size, false);
        ltrx_ip_socket_send(socket, "}", 1, false);
      }
    }
    ltrx_ip_socket_send(socket, "]", 1, true);
  } else if(memcmp(path,"/startScan",10) == 0) {
    struct ble_message message = {
      .command = 0x01
    };
    new_message(ble_queue, &message, sizeof(struct ble_message));
  }
  return true;
}

static const struct ltrx_http_dynamic_callback cb = {
	.uriPath  = "/bleScan",
	.callback = webApiCbFunc
};

void enableRestApi()
{
  ltrx_http_dynamic_callback_register(&cb);
}
