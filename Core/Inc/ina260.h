/*
 * ina260.h
 *
 *  Created on: Sep 1, 2021
 *      Author: micro
 */

#ifndef INC_INA260_H_
#define INC_INA260_H_

/******************************* Register Map  ********************************/
#define INA260_REG_CONFIG       	 0x00  /*!< Configuration Register      */
#define INA260_REG_CURRENT   		 0x01  /*!< Current Result Register        */
#define INA260_REG_VOLTAGE           0x02  /*!< Power Result register */
#define INA260_REG_POWER             0x03  /*!< Energy Result register */
#define INA260_REG_MASK_ENABLE       0x06  /*!< Charge Result register */
#define INA260_REG_ALERT_LIMIT       0x07  /*!< Temperature Over-Limit Threshold register */
#define INA260_REG_MANUFACTURER_ID   0xFE  /*!< Manufacturer ID register */
#define INA260_REG_DEVICE_ID         0xFF  /*!< Device ID register */

/*******************  Bit definition for Configuration register  **************/
#define INA260_REG_CFG_RESET_Pos        (15U)
#define INA260_REG_CFG_RESET_Msk        (0x1U << INA260_REG_CFG_RESET_Pos)      /*!< 0x8000 */
#define INA260_REG_CFG_RESET            INA260_REG_CFG_RESET_Msk                /*!< Reset Bit */
#define INA260_REG_CFG_AVG_Pos        (9U)
#define INA260_REG_CFG_AVG_Msk        (0x7U << INA260_REG_CFG_AVG_Pos)      /*!< 0x8000 */
#define INA260_REG_CFG_AVG            INA260_REG_CFG_AVG_Msk                /*!< Reset Bit */
#define INA260_REG_CFG_VBUSCT_Pos        (6U)
#define INA260_REG_CFG_VBUSCT_Msk        (0x7U << INA260_REG_CFG_VBUSCT_Pos)      /*!< 0x8000 */
#define INA260_REG_CFG_VBUSCT            INA260_REG_CFG_VBUSCT_Msk                /*!< Reset Bit */
#define INA260_REG_CFG_ISHCT_Pos        (3U)
#define INA260_REG_CFG_ISHCT_Msk        (0x7U << INA260_REG_CFG_ISHCT_Pos)      /*!< 0x8000 */
#define INA260_REG_CFG_ISHCT            INA260_REG_CFG_ISHCT_Msk                /*!< Reset Bit */
#define INA260_REG_CFG_MODE_Pos        (0U)
#define INA260_REG_CFG_MODE_Msk        (0x7U << INA260_REG_CFG_MODE_Pos)      /*!< 0x8000 */
#define INA260_REG_CFG_MODE            INA260_REG_CFG_MODE_Msk                /*!< Reset Bit */


/*******************  Bit definition for Bus Voltage register  ****************/
#define INA260_REG_VBUS_DATA_Pos        (0U)
#define INA260_REG_VBUS_DATA_Msk        (0x7FFFU << INA260_REG_VBUS_DATA_Pos)   /*!< 0x7FFF */
#define INA260_REG_VBUS_DATA            INA260_REG_VBUS_DATA_Msk                /*!< Measured bus voltage */


/*********************  Bit definition for Power register  ********************/
#define INA260_REG_PWR_DATA_Pos         (0U)
#define INA260_REG_PWR_DATA_Msk         (0xFFFFU << INA260_REG_PWR_DATA_Pos)    /*!< 0xFFFF */
#define INA260_REG_PWR_DATA             INA260_REG_PWR_DATA_Msk                 /*!< Measured power */

/*****************  Bit definition for Current register  **********************/
#define INA260_REG_CURRENT_DATA_Pos     (0U)
#define INA260_REG_CURRENT_DATA_Msk     (0x7FFFU << INA260_REG_CURRENT_DATA_Pos) /*!< 0x7FFF */
#define INA260_REG_CURRENT_DATA         INA260_REG_CURRENT_DATA_Msk              /*!< Measured current */
#define INA260_REG_CURRENT_SIGN_Pos     (15U)
#define INA260_REG_CURRENT_SIGN_Msk     (0x1U << INA260_REG_CURRENT_SIGN_Pos)   /*!< 0x8000 */
#define INA260_REG_CURRENT_SIGN         INA260_REG_CURRENT_SIGN_Msk             /*!< Sign */

#define INA260_REG_CFG_MODE_0           (0x1U << INA260_REG_CFG_MODE_Pos)       /*!< 0x0001 */
#define INA260_REG_CFG_MODE_1           (0x2U << INA260_REG_CFG_MODE_Pos)       /*!< 0x0002 */
#define INA260_REG_CFG_MODE_2           (0x4U << INA260_REG_CFG_MODE_Pos)       /*!< 0x0004 */

#define INA260_REG_CFG_VBUSCT_0           (0x1U << INA260_REG_CFG_VBUSCT)       /*!< 0x0001 */
#define INA260_REG_CFG_VBUSCT_1           (0x2U << INA260_REG_CFG_VBUSCT)       /*!< 0x0002 */
#define INA260_REG_CFG_VBUSCT_2           (0x4U << INA260_REG_CFG_VBUSCT)       /*!< 0x0004 */

#define INA260_REG_CFG_ISHCT_0           (0x1U << INA260_REG_CFG_ISHCT)       /*!< 0x0001 */
#define INA260_REG_CFG_ISHCT_1           (0x2U << INA260_REG_CFG_ISHCT)       /*!< 0x0002 */
#define INA260_REG_CFG_ISHCT_2           (0x4U << INA260_REG_CFG_ISHCT)       /*!< 0x0004 */

#define INA260_REG_CFG_AVG_0           (0x1U << INA260_REG_CFG_AVG)       /*!< 0x0001 */
#define INA260_REG_CFG_AVG_1           (0x2U << INA260_REG_CFG_AVG)       /*!< 0x0002 */
#define INA260_REG_CFG_AVG_2           (0x4U << INA260_REG_CFG_AVG)       /*!< 0x0004 */

/** @defgroup INA260_MODE  INA260 operating mode
  * @{
  */
#define INA260_MODE_POWER_DOWN       (uint16_t)0x0000U                                 /*!< Turn off current into the INA230 inputs               */
#define INA260_MODE_TRIGGERED_SHUNT INA260_REG_CFG_MODE_0                             /*!< Shunt Voltage, Single shot conversion                 */
#define INA260_MODE_TRIGGERED_VBUS   INA260_REG_CFG_MODE_1                             /*!< Bus voltage, Single shot conversion                   */
#define INA260_MODE_TRIGGERED_SHUNT_VBUS   (INA260_REG_CFG_MODE_0 | INA260_REG_CFG_MODE_1)                              /*!< Bus voltage, Single shot conversion                   */

#define INA260_MODE_CONTINOUS_SHUNT (INA260_REG_CFG_MODE_2 | INA260_REG_CFG_MODE_0)   /*!< Shunt Voltage, Continuous conversion                  */
#define INA260_MODE_CONTINOUS_VBUS   (INA260_REG_CFG_MODE_2 | INA260_REG_CFG_MODE_1)   /*!< Bus voltage, Continuous conversion                    */
#define INA260_MODE_CONTINOUS_SHUNT_VBUS   (INA260_REG_CFG_MODE_2 | INA260_REG_CFG_MODE_1 | INA260_REG_CFG_MODE_0)                            /*!< Bus voltage, Single shot conversion                   */

/** @defgroup INA260_VBUSCT INA260 Vbus ADC conversion time
  * @{
  */
#define INA260_VBUSCT_140     (uint16_t)0x0000U                                       /*!< ADC conversion time: 140 us  */
#define INA260_VBUSCT_204     INA260_REG_CFG_VBUSCT_0                               /*!< ADC conversion time: 204 us  */
#define INA260_VBUSCT_332     INA260_REG_CFG_VBUSCT_1                               /*!< ADC conversion time: 332 us  */
#define INA260_VBUSCT_588     (INA260_REG_CFG_VBUSCT_1 | INA260_REG_CFG_VBUSCT_0) /*!< ADC conversion time: 588 us  */
#define INA260_VBUSCT_1100    INA260_REG_CFG_VBUSCT_2                               /*!< ADC conversion time: 1100 us */
#define INA260_VBUSCT_2116    (INA260_REG_CFG_VBUSCT_2| INA260_REG_CFG_VBUSCT_0)  /*!< ADC conversion time: 2116 us */
#define INA260_VBUSCT_4156    (INA260_REG_CFG_VBUSCT_2| INA260_REG_CFG_VBUSCT_1)  /*!< ADC conversion time: 4156 us */
#define INA260_VBUSCT_8244    INA260_REG_CFG_VBUSCT                                 /*!< ADC conversion time: 8244 us */

/** @defgroup INA229_VSHCT INA229 shunt ADC conversion time
  * @{
  */
#define INA260_ISHCT_140     (uint16_t)0x0000U                                       /*!< ADC conversion time: 140 us  */
#define INA260_ISHCT_204    INA260_REG_CFG_ISHCT_0                               /*!< ADC conversion time: 204 us  */
#define INA260_ISHCT_332     INA260_REG_CFG_ISHCT_1                               /*!< ADC conversion time: 332 us  */
#define INA260_ISHCT_588     (INA260_REG_CFG_ISHCT_1 | INA260_REG_CFG_ISHCT_0) /*!< ADC conversion time: 588 us  */
#define INA260_ISHCT_1100    INA260_REG_CFG_ISHCT_2                               /*!< ADC conversion time: 1100 us */
#define INA260_ISHCT_2116    (INA260_REG_CFG_ISHCT_2| INA260_REG_CFG_ISHCT_0)  /*!< ADC conversion time: 2116 us */
#define INA260_ISHCT_4156    (INA260_REG_CFG_ISHCT_2| INA260_REG_CFG_ISHCT_1)  /*!< ADC conversion time: 4156 us */
#define INA260_ISHCT_8244    INA260_REG_CFG_ISHCT                                 /*!< ADC conversion time: 8244 us */



/** @defgroup INA260_AVG INA260 number of averages
  * @{
  */
#define INA260_AVG_1      (uint16_t)0x0000U                                       /*!< Number of averages: 1    */
#define INA260_AVG_4      INA260_REG_CFG_AVG_0                               /*!< Number of averages: 4    */
#define INA260_AVG_16     INA260_REG_CFG_AVG_1                               /*!< Number of averages: 16   */
#define INA260_AVG_64     (INA260_REG_CFG_AVG_1 | INA260_REG_CFG_AVG_0) /*!< Number of averages: 64   */
#define INA260_AVG_128    INA260_REG_CFG_AVG_2                               /*!< Number of averages: 128  */
#define INA260_AVG_256    (INA260_REG_CFG_AVG_2| INA260_REG_CFG_AVG_0)  /*!< Number of averages: 256  */
#define INA260_AVG_512    (INA260_REG_CFG_AVG_2| INA260_REG_CFG_AVG_1)  /*!< Number of averages: 512  */
#define INA260_AVG_1024   INA260_REG_CFG_AVG                                 /*!< Number of averages: 1024 */


#endif /* INC_INA260_H_ */

uint16_t ina260_ReadReg(uint16_t Reg);
void ina260_WriteReg(uint16_t Reg, uint16_t Data);
void ina260_Init();
uint16_t ina260_ReadManufacturerID();
uint16_t ina260_ReadDeviceID();
int16_t ina260_GetCurrent();
int16_t ina260_GetVBus();
