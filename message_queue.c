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
#include "ltrx_definitions.h"  /* Delivered with SDK. */
#include "bleSensor_module_defs.h" /* Automatically generated by make. */
#include "ltrx_tlog.h"

#include "message_queue.h"

struct element
{
  struct element *next;
  void *value;
  size_t size;
};

struct message_queue
{
  struct element *first;
  struct element *last;
};

struct message_queue* init_queue(void)
{
  struct message_queue* s_queue = MALLOC_ZEROED(sizeof(struct message_queue));
  s_queue->first = NULL;
  s_queue->last = NULL;
  return s_queue;
}

void destroy_queue(struct message_queue* s_queue)
{
  ltrx_free(s_queue);
}

bool new_message(struct message_queue* s_queue, void* value, size_t size)
{
  void *new_message = MALLOC_ZEROED(size);
  struct element *element_ptr = MALLOC_ZEROED(sizeof(struct element));

  if(new_message != NULL && element_ptr != NULL) {
    memcpy(new_message, value, size);
    element_ptr->value = new_message;
    element_ptr->size = size;
    element_ptr->next = NULL;
    if (s_queue->first == NULL) {
      s_queue->first = element_ptr;
    } else {
      (*s_queue->last).next = (struct element *)element_ptr;
    }
    s_queue->last = element_ptr;
    return true;
  } else {
    return false;
  }
}

bool get_message(struct message_queue* s_queue, void* value)
{
  if(s_queue->first == NULL && s_queue->last == NULL) {
    value = NULL;
    return false;
  }
  struct element *old_message = s_queue->first;
  s_queue->first = (struct element *)old_message->next;
  if(s_queue->first == NULL) {
    s_queue->last = NULL;
  }
  memcpy(value, old_message->value, old_message->size);
  ltrx_free(old_message->value);
  ltrx_free(old_message);
  return true;
}
