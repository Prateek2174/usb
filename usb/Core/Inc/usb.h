/*
 * usb.h
 *
 *  Created on: Jul 25, 2025
 *      Author: prate
 */

#ifndef INC_USB_H_
#define INC_USB_H_

#include <stdbool.h>

#define USB_OTG_DEVICE ((USB_OTG_DeviceTypeDef *)(USB_OTG_FS_PERIPH_BASE + USB_OTG_DEVICE_BASE))
#define USB_OTG_IN     ((USB_OTG_INEndpointTypeDef *)(USB_OTG_FS_PERIPH_BASE + USB_OTG_IN_ENDPOINT_BASE))
#define USB_OTG_OUT    ((USB_OTG_OUTEndpointTypeDef *)(USB_OTG_FS_PERIPH_BASE + USB_OTG_OUT_ENDPOINT_BASE))
#define USB_OTG_HOST   ((USB_OTG_HostTypeDef *)(USB_OTG_FS_PERIPH_BASE + USB_OTG_HOST_BASE))

void usb_core_init(void);
void usb_host_init(void);
void usb_device_init(void);
bool usb_current_mode(void);
void USB_Init(void);
void USB_LP_IRQHandler(void);

void usb_endpoint_init_on_enum(void);
void usb_endpoint_init_on_reset(void);
void usb_endpoint_init_on_setaddress(uint8_t addr);
void usb_endpoint_init_on_setconfig(void);
void usb_endpoint_init_on_setinterface(void);
void usb_endpoint_activate(void);
void usb_endpoint_deactivate(void);
void usb_packet_read(void);


#endif /* INC_USB_H_ */
