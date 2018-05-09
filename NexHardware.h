/**
 * @file NexHardware.h
 *
 * The definition of base API for using Nextion. 
 *
 * @author  Wu Pengfei (email:<pengfei.wu@itead.cc>)
 * @date    2015/8/11
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */
#ifndef __NEXHARDWARE_H__
#define __NEXHARDWARE_H__
#include <Arduino.h>
#include "NexConfig.h"
#include "NexTouch.h"

/**
 * @addtogroup CoreAPI 
 * @{ 
 */



 
/**
 * Init Nextion.  
 * 
 * @return true if success, false for failure. 
 */

bool nexInit(void);

/**
 * Listen touch event and calling callbacks attached before.
 * 
 * Supports push and pop at present. 
 *
 * @param nex_listen_list - index to Nextion Components list. 
 * @return none. 
 *
 * @warning This function must be called repeatedly to response touch events
 *  from Nextion touch panel. Actually, you should place it in your loop function. 
 */
void nexLoop(NexTouch *nex_listen_list[]);

/**
 * @}
 */

bool recvRetNumber(uint32_t *number, uint32_t timeout = 100);
uint16_t recvRetString(char *buffer, uint16_t len, uint32_t timeout = 100);
void sendCommand(const char* cmd);
bool recvRetCommandFinished(uint32_t timeout = 100);
/** Codigo añadido
 * Detecta si el dispositivo esta en sleepMode
 * sleeModeNextion devuelve si el dispositivo entro automaticamente en modo sleep
 * setSleepNextion te permite modificar la variable que almacena si esta en modo sleep o no, util cuando el dispositivo despierta por comando y automaticamente
 */
bool sleepModeNextion();
bool setSleepNextion(bool status);

/** Fin Codigo añadido
 */
 
#endif /* #ifndef __NEXHARDWARE_H__ */
