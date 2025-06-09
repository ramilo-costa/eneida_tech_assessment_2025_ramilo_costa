/*
The following code example illustrates a DMA channel 0 interrupt configuration.
When the DMA channel 0 interrupt is generated, the CPU will jump to the vector assigned to
DMA0 interrupt.
*/
IEC1CLR=0x00010000; // disable DMA channel 0 interrupts
IFS1CLR=0x00010000; // clear any existing DMA channel 0 interrupt flag

DMACONSET=0x00008000; // enable the DMA controller
DCH0CON=0x03; // channel off, priority 3, no chaining

DCH0ECON=0; // no start or stop irq’s, no pattern match

// program the transfer
DCH0SSA=0x1d010000; // transfer source physical address
DCH0DSA=0x1d020000; // transfer destination physical address
DCH0SSIZ=200; // source size 200 bytes
DCH0DSIZ=200; // destination size 200 bytes
DCH0CSIZ=200; // 200 bytes transferred per event

DCH0INTCLR=0x00ff00ff; // clear existing events, disable all interrupts
DCH0INTSET=0x00090000; // enable Block Complete and error interrupts

IPC9CLR=0x0000001f; // clear the DMA channel 0 priority and sub-priority
IPC9SET=0x00000016; // set IPL 5, sub-priority 2
IEC1SET=0x00010000; // enable DMA channel 0 interrupt

DCH0CONSET=0x80; // turn channel on

// initiate a transfer
DCH0ECONSET=0x00000080; // set CFORCE to 1
// do something else
// will get an interrupt when


/*
The following code example demonstrates a simple Interrupt Service Routine for DMA channel 0
interrupts. The user’s code at this vector should perform any application specific operations
and must clear the DMA0 interrupt flags before exiting.
*/
void __ISR(_DMA_0_VECTOR, ipl5) __DMA0Interrupt(void)
{
int dmaFlags=DCH0INT&0xff; // read the interrupt flags
/*
perform application specific operations in response to any interrupt flag set
*/
DCH0INTCLR=0x000000ff; // clear the DMA channel interrupt flags
IFS1CLR = 0x00010000; // Be sure to clear the DMA0 interrupt flags
// before exiting the service routine.
}