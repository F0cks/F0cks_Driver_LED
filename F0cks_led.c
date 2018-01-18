#include "F0cks_led.h"

int8_t F0cks_LED_Init( LED_HandleTypeDef *handler, LED_ConfigurationTypeDef config)
{
  int8_t error = 0;

  /* Store configuration in handler */
  handler->configuration.pin      =  config.pin;
  handler->configuration.port      =  config.port;
  handler->configuration.polarity  =  config.polarity;

  /* Set LED OFF by default */
  error += F0cks_LED_Set_State(handler, LED_OFF);

  return error;
}

int8_t F0cks_LED_Set_State(LED_HandleTypeDef *handler, LED_StateTypeDef state)
{
  int8_t error = 0;

  handler->state = state;
  if( (uint8_t)state == (uint8_t)handler->configuration.polarity )
  {
    error += F0cks_GPIO_Write(
          handler->configuration.port,
          handler->configuration.pin,
          1
        );
  }
  else
  {
    error += F0cks_GPIO_Write(
          handler->configuration.port,
          handler->configuration.pin,
          0
        );
  }

  return error;
}

int8_t F0cks_LED_Toggle(LED_HandleTypeDef *handler)
{
	int8_t error = 0;

	error += F0cks_LED_Set_State(handler, !handler->state);

	return error;
}
