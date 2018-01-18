#ifndef F0CKS_LED_H
#define F0CKS_LED_H

#include "stdint.h"

typedef enum
{
  LED_ON_LOW  =  0x00U,   // LED ON with LOW state
  LED_ON_HIGH  =  0x01U    // LED ON with HIGH state

}LED_PolartityTypeDef;

typedef enum
{
  LED_OFF      =  0x00U,
  LED_ON      =  0x01U
}LED_StateTypeDef;

typedef struct
{
  uint32_t              port;
  uint16_t              pin;
  LED_PolartityTypeDef  polarity;

}LED_ConfigurationTypeDef;

/**
  * @brief  LED handle Structure definition
  */
typedef struct
{
  LED_ConfigurationTypeDef  configuration;
  uint8_t                    state;

}LED_HandleTypeDef;

int8_t F0cks_LED_Init( LED_HandleTypeDef *handler, LED_ConfigurationTypeDef config);
int8_t F0cks_LED_Set_State(LED_HandleTypeDef *handler, LED_StateTypeDef state);
int8_t F0cks_LED_Toggle(LED_HandleTypeDef *handler);
int8_t F0cks_GPIO_Write(uint32_t port, uint16_t pin, uint16_t state);


#endif //F0CKS_LED_H
