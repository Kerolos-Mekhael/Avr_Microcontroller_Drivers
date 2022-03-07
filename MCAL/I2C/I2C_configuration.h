#ifndef I2C_CONF_H
#define I2C_CONF_H


#define PRESCALER						1

#define BIT_RATE						(((CLOCK / SCL_FREQUENCY)-16)/ (2*PRESCALER))




#endif
