/*
 * usb.h
 *
 *  Created on: Jul 25, 2025
 *      Author: prate
 */

#ifndef INC_USB_H_
#define INC_USB_H_

void core_init(void);
void host_init(void);
void device_init(void);
bool current_mode(void);
void USB_Init(void);
void USB_LP_IRQHandler(void);


#endif /* INC_USB_H_ */
