/*
 * usb.c
 *
 *  Created on: Jul 25, 2025
 *      Author: prate
 */
#include "stm32f4xx.h"
#include "stm32f446xx.h"

void core_init(void){

	USB_OTG_FS->GAHBCFG |= USB_OTG_GAHBCFG_GINT; //Unmask core interrupts
	USB_OTG_FS->GINTMSK |= USB_OTG_GINTMSK_RXFLVLM; //Enable Rx FIFO non-empty

	//Enable and choose at what FIFO level of Tx the interrupt fires
	USB_OTG_FS->GINTMSK |= USB_OTG_GINTMSK_PTXFEM;
	USB_OTG_FS->GAHBCFG |= USB_OTG_GAHBCFG_PTXFELVL;

	//Program OTG_GUSBCFG register
	USB_OTG_FS->GUSBCFG |= USB_OTG_GUSBCFG_HNPCAP; //Enable HNP capability
	USB_OTG_FS->GUSBCFG |= USB_OTG_GUSBCFG_SRPCAP; //Enable SRP capability

	//Set OTG_FS/OTG_HS timeout calibration field
	USB_OTG_FS->GUSBCFG &= ~USB_OTG_GUSBCFG_TOCAL;
	//?????????????????????????????????????????????????leave as zero

	//Set USB turn around time field
	USB_OTG_FS->GUSBCFG &= ~USB_OTG_GUSBCFG_TRDT;
	//set this


}

void USB_Init(void){

	//Initialize the NVIC interrupts


	//Enable USB macrocell

}

void USB_LP_IRQHandler(void){


}
