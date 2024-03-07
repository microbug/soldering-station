#ifndef THERMOCOUPLE_H_
#define THERMOCOUPLE_H_

#define TC_COEFF_UV_PER_K 21.0F  // From EEVblog forum (conservative / low estimate)
#define TC_COEFF_K_PER_V (1.0F / (1.0E-6F * TC_COEFF_UV_PER_K))

#define TC_AMP_RF 17950.0F
#define TC_AMP_RG 100.0F
#define TC_AMP_GAIN (1.0F + (TC_AMP_RF / TC_AMP_RG))

float tc_voltage_to_temperature(float V);


#endif /* THERMOCOUPLE_H_ */
