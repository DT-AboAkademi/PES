#ifndef UART_H
#define UART_H

void UART_Init();
void UART_SendByte(tByte c);

void UART_Write(char *);
tByte UART_Read(char *, tByte max);

#endif // UART_H

