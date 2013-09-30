/*
 * drv_softserial.h
 *
 *  Created on: 23 Aug 2013
 *      Author: Hydra
 */

#pragma once

#define SOFT_SERIAL_BUFFER_SIZE 256

typedef struct softSerial_s {
    serialPort_t port;

    const timerHardware_t *rxTimerHardware;
    volatile uint8_t rxBuffer[SOFT_SERIAL_BUFFER_SIZE];

    const timerHardware_t *txTimerHardware;
    volatile uint8_t txBuffer[SOFT_SERIAL_BUFFER_SIZE];
    
    uint8_t          isSearchingForStopBit;
    uint8_t          rxBitSelectionMask;
    uint8_t          isSearchingForStartBit;
    uint8_t          isTransmittingData;
    uint8_t          timerRxCounter;
    uint8_t          timerTxCounter;
    uint8_t          bitsLeftToReceive;
    uint8_t          bitsLeftToTransmit;
    uint16_t         internalRxBuffer;  // excluding start/stop bits
    uint16_t         internalTxBuffer;  // includes start and stop bits

} softSerial_t;

extern const struct serialPortVTable softSerialVTable[];

void setupSoftSerial1(uint32_t baud);

uint8_t serialReadByte(softSerial_t *softSerial);
uint8_t serialAvailable(softSerial_t *softSerial);

void softSerialWriteByte(serialPort_t *instance, uint8_t ch);
void serialPrint(softSerial_t *softSerial, const char *str);

extern timerHardware_t* serialTimerHardware;
extern softSerial_t softSerialPorts[];
