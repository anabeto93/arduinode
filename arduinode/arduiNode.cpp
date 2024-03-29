/* 
 * Copyright (c) 2011, Jan Clement
 * licenced under the GPL
 *
 * Author: Jan Clement <jan.clement@audiokits.de>
 *
 * This file is part of the arduiNode library
 * http://code.google.com/p/arduinode/
 */

#include "arduiNode.h"

#define STATUSLEDPIN 7

boolean NODETYPE;

void arduiNodeSetup(boolean NODETYP) {
  NODETYPE = NODETYP;
  init_pt_rcv();		// init proto rcv var called in isr
  init_pt_snd();		// init proto snd var...
  #if SERIALCONSOLE
  Serial.print("superNode v0.1");
  #endif
  if(NODETYPE == MASTER) {
    myself.id  = 1;
    myself.htm = 0;
    #if SERIALCONSOLE
    Serial.println(" MASTER");
    #endif
  }
  else {
    myself.id  = 0;
    myself.htm = 255;
    #if SERIALCONSOLE
    Serial.println(" SLAVE");
    #endif
  }
  
  enable_IR_rx();
  
  pinMode(STATUSLEDPIN, OUTPUT);	// STATUS LED
  rxtx_ctrl_init();
  rcvPktType = 255;
}


void led(unsigned char led){
  digitalWrite(STATUSLEDPIN, led);
}