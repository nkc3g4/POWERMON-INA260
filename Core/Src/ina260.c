#include "i2c.h"
#include "ina260.h"

#define DIV_ROUND_CLOSEST(__DIVIDEND__, __DIVISOR__) (((__DIVIDEND__) + ((__DIVISOR__)/2)) / (__DIVISOR__))
#define INA260_ADDRESS (0x40 << 1)

uint16_t ina260_ReadReg(uint16_t Reg)
{
  uint8_t pData[2];
  uint16_t data;
  I2C2_ReadBuffer(INA260_ADDRESS, Reg, I2C_MEMADD_SIZE_8BIT, pData, sizeof(uint16_t));
  data = (pData[0] << 8) | pData[1];
  return data;
}


void ina260_WriteReg(uint16_t Reg, uint16_t Data)
{
  uint8_t pData[2];

  pData[0] = Data >> 8;    /* MSB 1st */
  pData[1] = Data & 0xff;  /* LSB 2nd */
  I2C2_WriteBuffer(INA260_ADDRESS,Reg, I2C_MEMADD_SIZE_8BIT, pData, sizeof(uint16_t));

}


void ina260_Reset()
{
  uint16_t cfg = 0;

  /*  Read programmed configuration  */
  cfg = ina260_ReadReg(INA260_REG_CONFIG);

  /* Set Reset bit bit */
  cfg |= INA260_REG_CFG_RESET;
  ina260_WriteReg(INA260_REG_CONFIG, cfg);
}


void ina260_Init()
{
  //MX_I2C2_Init();

  uint16_t cfg = 0;

  /* Reset all registers are to default values */
  ina260_Reset();

  /* Set INA260 configuration */
  cfg = INA260_MODE_CONTINOUS_SHUNT_VBUS | INA260_VBUSCT_588 | INA260_ISHCT_588 | INA260_AVG_16;

  ina260_WriteReg(INA260_REG_CONFIG, cfg);
}

uint16_t ina260_ReadManufacturerID()
{
  return ina260_ReadReg(INA260_REG_MANUFACTURER_ID);
}

uint16_t ina260_ReadDeviceID()
{
  return ina260_ReadReg(INA260_REG_DEVICE_ID);
}



int16_t ina260_GetCurrent()
{
  int16_t current = ((int16_t)ina260_ReadReg(INA260_REG_CURRENT) >> 3) * 10;

  return current;
}


/**
  * @brief  Read the bus voltage
  * @param  Address INA229 address on communication Bus.
  * @retval BusVoltage Bus voltage value (in mV)
  */
int16_t ina260_GetVBus()
{
  int16_t val;
  val = (ina260_ReadReg(INA260_REG_VOLTAGE) >> 3) * 10;

  return (uint32_t)val;
}


