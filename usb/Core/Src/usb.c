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

	//2. Program the following fields in the OTG_GUSBCFG register

	USB_OTG_FS->GUSBCFG |= USB_OTG_GUSBCFG_HNPCAP; //Enable HNP capability
	USB_OTG_FS->GUSBCFG |= USB_OTG_GUSBCFG_SRPCAP; //Enable SRP capability

	//Set OTG_FS/OTG_HS timeout calibration field
	USB_OTG_FS->GUSBCFG &= ~USB_OTG_GUSBCFG_TOCAL; //*****change this field if using external PHY

	//Set USB turn around time field
	USB_OTG_FS->GUSBCFG &= ~USB_OTG_GUSBCFG_TRDT;
	USB_OTG_FS->GUSBCFG |= (0x6 << USB_OTG_GUSBCFG_TRDT_Pos);

	//3. The software must unmask the following bits in the OTG_GINTMSK register

	USB_OTG_FS->GINTMSK |= USB_OTG_GINTMSK_OTGINT;
	USB_OTG_FS->GINTMSK |= USB_OTG_GINTMSK_MMISM;


}

void host_init(void){

	USB_OTG_FS->GINTMSK |= USB_OTG_GINTMSK_PRTIM;

	USB_OTG_FS->HCFG &= ~USB_OTG_HCFG_FSLSPCS;
	USB_OTG_FS->HCFG |= USB_OTG_HCFG_FSLSPCS_0;

	//3. Program the PPWR bit in OTG_HPRT to 1. This drives VBUS on the USB.
	USB_OTG_FS->HPRT |= USB_OTG_HPRT_PPWR;
	//4. Wait for the PCDET interrupt in OTG_HPRT0. This indicates that a device is connecting to the port.
	while(!(USB_OTG_FS->HPRT & USB_OTG_HPRT_PENCHNG));
	//5. Program the PRST bit in OTG_HPRT to 1. This starts the reset process.
	USB_OTG_FS->HPRT |= USB_OTG_HPRT_PRST;
	//6. Wait at least 10 ms for the reset process to complete.

	//7. Program the PRST bit in OTG_HPRT to 0.
	USB_OTG_FS->HPRT &= ~USB_OTG_HPRT_PRST;
	//8. Wait for the PENCHNG interrupt in OTG_HPRT.
	while(!(USB_OTG_FS->HPRT & USB_OTG_HPRT_PENCHNG));
	//9. Read the PSPD bit in OTG_HPRT to get the enumerated speed.
	uint8_t port_speed = (USB_OTG_FS->HPRT & USB_OTG_HPRT_PSPD);
	//10. Program the HFIR register with a value corresponding to the selected PHY clock 1

	//11. Program the FSLSPCS field in the OTG_HCFG register following the speed of the
	//device detected in step 9. If FSLSPCS has been changed a port reset must be
	//performed.

	//12. Program the OTG_GRXFSIZ register to select the size of the receive FIFO.

	//
}

void device_init(void){

	USB_OTG_FS->DCFG |= USB_OTG_DCFG_DSPD;
	USB_OTG_FS->DCFG |= USB_OTG_DCFG_NZLSOHSK;
	USB_OTG_FS->DCFG &= ~USB_OTG_DCFG_PFIVL;

	//2. Program the Device threshold control register. This is required only if you are using
	//DMA mode and you are planning to enable thresholding.

	//3. Clear the DCTL.SDIS bit. The core issues a connect after this bit is cleared.
	USB_OTG_FS->DCTL &= ~USB_OTG_DCTL_SDIS;

	USB_OTG_FS->GINTMSK |= USB_OTG_GINTMSK_USBRST;
	USB_OTG_FS->GINTMSK |= USB_OTG_GINTMSK_ENUMDNEM;
	USB_OTG_FS->GINTMSK |= USB_OTG_GINTMSK_ESUSPM;
	USB_OTG_FS->GINTMSK |= USB_OTG_GINTMSK_USBSUSPM;
	USB_OTG_FS->GINTMSK |= USB_OTG_GINTMSK_SOFM;

	//Wait for a reset to be detected
	while(!(USB_OTG_FS->GINTSTS & USB_OTG_GINTSTS_USBRST));

	//Wait for the end of reset on the USB
	while(!(USB_OTG_FS->GINTSTS & USB_OTG_GINTSTS_ENUMDNE));

//	read the OTG_DSTS
//	register to determine the enumeration speed and perform the steps listed in Endpoint
//	initialization on enumeration completion on page 1226.
	uint8_t enum_speed = (USB_OTG_FS->DSTS & USB_OTG_DSTS_ENUMSPD);
}

bool current_mode(void){

	return (USB_OTG_FS->GINTSTS & USB_OTG_GINTSTS_CMOD);
}

void USB_Init(void){

	//Initialize the NVIC interrupts


	//Enable USB macrocell

}

void USB_LP_IRQHandler(void){


}
