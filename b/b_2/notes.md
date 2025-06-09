# B2?

## You are optimizing data transfer on a microcontroller of the PIC32MZ family. 
## Explain how to configure DMA to move data from ADC to memory. 
I'd assume the ADC is already configured and working. <BR>
Next assumption is that the ADC is configured to trigger an interrupt once conversion is done. This means that we are not pooling data rather using interrupts. <BR>
I'd set the DMA enabling it <BR>
Set one of the 8 DMA channels <BR>
Set source and destination address <BR>
Set source data size <BR>
Set DMA channel interrupt <BR>
Set the channel to ON <BR>
Start the transfer <BR>
Once transfer is completed or a error occured an interrupt will be triggered <BR>
Handle the interrupt using an ISR <BR><BR>

In the resources\dma_transfer_example.c there is an example retrieve from Microchip application notes <BR>

A learning remark is that after looking the code provided by Microchip I noticed the some steps were missing <BR><BR>

## Describe a real use case for DMA, with other peripherals, and list the main advantages of this approach.
Video streaming can be a good example of DMA use <BR>
Transmitting image data to a display through SPI (usually SPI is used due to its high speed) with DMA make it faster. I can use DMA to read data from memory and write it to SPI register with no need of CPU


#### Main advantages
Free the CPU from the load of handling data transfer <BR>
By freeing the CPU, there is less power consumption <BR>
Parallel operation as I can use DMA to send data from UART to memory while CPU is working on something else <BR>
Faster data transfer as I access memory directly without the need of the CPU <BR>
