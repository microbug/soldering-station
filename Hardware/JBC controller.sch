EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Transistor_BJT:BC846 Q1
U 1 1 610ED3AF
P 3950 2300
F 0 "Q1" H 4141 2346 50  0000 L CNN
F 1 "BC846" H 4141 2255 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 4150 2225 50  0001 L CIN
F 3 "https://assets.nexperia.com/documents/data-sheet/BC846_SER.pdf" H 3950 2300 50  0001 L CNN
	1    3950 2300
	1    0    0    -1  
$EndComp
$Comp
L MCU_ST_STM32L0:STM32L011F4Px U2
U 1 1 610EE10A
P 4350 4550
F 0 "U2" H 4700 3750 50  0000 C CNN
F 1 "STM32L011F4Px" H 4950 3650 50  0000 C CNN
F 2 "Package_SO:TSSOP-20_4.4x6.5mm_P0.65mm" H 3950 3850 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00206508.pdf" H 4350 4550 50  0001 C CNN
	1    4350 4550
	1    0    0    -1  
$EndComp
$Comp
L JBC~controller~symbols:AD8538AR U4
U 1 1 610F0B7E
P 8150 1450
F 0 "U4" H 8494 1496 50  0000 L CNN
F 1 "AD8538AR" H 8494 1405 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5_HandSoldering" H 8200 1500 50  0001 C CNN
F 3 "" H 8200 1600 50  0001 C CNN
	1    8150 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_SGD Q2
U 1 1 610F1E79
P 4700 1900
F 0 "Q2" H 4905 1854 50  0000 L CNN
F 1 "SI4101DY" H 4905 1945 50  0000 L CNN
F 2 "JBC controller footprints:SI4101DY" H 4900 2000 50  0001 C CNN
F 3 "~" H 4700 1900 50  0001 C CNN
	1    4700 1900
	1    0    0    1   
$EndComp
Text Label 1100 2050 2    50   ~ 0
TIP_COM
Text Label 1100 2150 2    50   ~ 0
TIP_V+
Text Label 1100 2250 2    50   ~ 0
TIP_TC
$Comp
L Device:R R4
U 1 1 610F585F
P 4800 1450
F 0 "R4" H 4870 1496 50  0000 L CNN
F 1 "10m" H 4870 1405 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 4730 1450 50  0001 C CNN
F 3 "~" H 4800 1450 50  0001 C CNN
	1    4800 1450
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Current:INA181 U3
U 1 1 610F695A
P 5800 1400
F 0 "U3" H 6144 1446 50  0000 L CNN
F 1 "INA181A1" H 6144 1355 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 5850 1450 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/ina181.pdf" H 5950 1550 50  0001 C CNN
	1    5800 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 1500 5500 1500
Connection ~ 4800 1300
Wire Wire Line
	4800 1300 5500 1300
$Comp
L Connector:Conn_01x02_Female J2
U 1 1 610F9EE4
P 1300 1100
F 0 "J2" H 1192 775 50  0000 C CNN
F 1 "XT30" H 1192 866 50  0000 C CNN
F 2 "Connector_AMASS:AMASS_XT30PW-M_1x02_P2.50mm_Horizontal" H 1300 1100 50  0001 C CNN
F 3 "~" H 1300 1100 50  0001 C CNN
	1    1300 1100
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 610FB05B
P 1000 1100
F 0 "#PWR03" H 1000 850 50  0001 C CNN
F 1 "GND" H 1005 927 50  0000 C CNN
F 2 "" H 1000 1100 50  0001 C CNN
F 3 "" H 1000 1100 50  0001 C CNN
	1    1000 1100
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR02
U 1 1 610FD42B
P 1000 1000
F 0 "#PWR02" H 1000 850 50  0001 C CNN
F 1 "VCC" H 1015 1173 50  0000 C CNN
F 2 "" H 1000 1000 50  0001 C CNN
F 3 "" H 1000 1000 50  0001 C CNN
	1    1000 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 1000 1100 1000
Wire Wire Line
	1000 1100 1100 1100
$Comp
L power:VCC #PWR016
U 1 1 61102033
P 4050 1250
F 0 "#PWR016" H 4050 1100 50  0001 C CNN
F 1 "VCC" H 4065 1423 50  0000 C CNN
F 2 "" H 4050 1250 50  0001 C CNN
F 3 "" H 4050 1250 50  0001 C CNN
	1    4050 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 1600 4800 1650
Wire Wire Line
	5250 1650 4800 1650
Wire Wire Line
	5250 1500 5250 1650
$Comp
L power:GND #PWR01
U 1 1 61103885
P 650 2050
F 0 "#PWR01" H 650 1800 50  0001 C CNN
F 1 "GND" H 655 1877 50  0000 C CNN
F 2 "" H 650 2050 50  0001 C CNN
F 3 "" H 650 2050 50  0001 C CNN
	1    650  2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	650  2050 1100 2050
Text Label 4900 2200 0    50   ~ 0
TIP_V+
Wire Wire Line
	4800 2100 4800 2200
Wire Wire Line
	4800 2200 4900 2200
$Comp
L Device:R R2
U 1 1 61105ACF
P 4050 1450
F 0 "R2" H 4120 1496 50  0000 L CNN
F 1 "470" H 4120 1405 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 3980 1450 50  0001 C CNN
F 3 "~" H 4050 1450 50  0001 C CNN
	1    4050 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 1250 4050 1300
Wire Wire Line
	4050 1300 4800 1300
$Comp
L power:GND #PWR017
U 1 1 61109391
P 4050 2500
F 0 "#PWR017" H 4050 2250 50  0001 C CNN
F 1 "GND" H 4055 2327 50  0000 C CNN
F 2 "" H 4050 2500 50  0001 C CNN
F 3 "" H 4050 2500 50  0001 C CNN
	1    4050 2500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR022
U 1 1 6110C4FD
P 5700 1700
F 0 "#PWR022" H 5700 1450 50  0001 C CNN
F 1 "GND" H 5705 1527 50  0000 C CNN
F 2 "" H 5700 1700 50  0001 C CNN
F 3 "" H 5700 1700 50  0001 C CNN
	1    5700 1700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR023
U 1 1 6110C8D9
P 5900 1700
F 0 "#PWR023" H 5900 1450 50  0001 C CNN
F 1 "GND" H 5905 1527 50  0000 C CNN
F 2 "" H 5900 1700 50  0001 C CNN
F 3 "" H 5900 1700 50  0001 C CNN
	1    5900 1700
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR021
U 1 1 6110D6F8
P 5700 1000
F 0 "#PWR021" H 5700 850 50  0001 C CNN
F 1 "+3.3V" H 5715 1173 50  0000 C CNN
F 2 "" H 5700 1000 50  0001 C CNN
F 3 "" H 5700 1000 50  0001 C CNN
	1    5700 1000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR028
U 1 1 6110EFA7
P 8050 1750
F 0 "#PWR028" H 8050 1500 50  0001 C CNN
F 1 "GND" H 8055 1577 50  0000 C CNN
F 2 "" H 8050 1750 50  0001 C CNN
F 3 "" H 8050 1750 50  0001 C CNN
	1    8050 1750
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR027
U 1 1 6110F5C7
P 8050 1050
F 0 "#PWR027" H 8050 900 50  0001 C CNN
F 1 "+3.3V" H 8065 1223 50  0000 C CNN
F 2 "" H 8050 1050 50  0001 C CNN
F 3 "" H 8050 1050 50  0001 C CNN
	1    8050 1050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 61110017
P 5950 1050
F 0 "C4" V 5698 1050 50  0000 C CNN
F 1 "100n" V 5789 1050 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 5988 900 50  0001 C CNN
F 3 "~" H 5950 1050 50  0001 C CNN
	1    5950 1050
	0    1    1    0   
$EndComp
Wire Wire Line
	5700 1000 5700 1050
Wire Wire Line
	5700 1050 5800 1050
Connection ~ 5700 1050
Wire Wire Line
	5700 1050 5700 1100
$Comp
L power:GND #PWR025
U 1 1 61113738
P 6150 1050
F 0 "#PWR025" H 6150 800 50  0001 C CNN
F 1 "GND" H 6155 877 50  0000 C CNN
F 2 "" H 6150 1050 50  0001 C CNN
F 3 "" H 6150 1050 50  0001 C CNN
	1    6150 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 1050 6100 1050
$Comp
L Device:R R6
U 1 1 61115177
P 8200 2150
F 0 "R6" V 7993 2150 50  0000 C CNN
F 1 "20k" V 8084 2150 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 8130 2150 50  0001 C CNN
F 3 "~" H 8200 2150 50  0001 C CNN
	1    8200 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	8350 2150 8500 2150
Wire Wire Line
	8500 2150 8500 1450
Wire Wire Line
	8500 1450 8450 1450
$Comp
L Device:R R5
U 1 1 611175EC
P 7750 2550
F 0 "R5" H 7680 2504 50  0000 R CNN
F 1 "100" H 7680 2595 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 7680 2550 50  0001 C CNN
F 3 "~" H 7750 2550 50  0001 C CNN
	1    7750 2550
	-1   0    0    1   
$EndComp
Wire Wire Line
	8050 2150 7750 2150
Wire Wire Line
	7750 2150 7750 1550
Wire Wire Line
	7750 1550 7850 1550
$Comp
L power:GND #PWR026
U 1 1 611186CF
P 7750 2700
F 0 "#PWR026" H 7750 2450 50  0001 C CNN
F 1 "GND" H 7755 2527 50  0000 C CNN
F 2 "" H 7750 2700 50  0001 C CNN
F 3 "" H 7750 2700 50  0001 C CNN
	1    7750 2700
	1    0    0    -1  
$EndComp
Text Label 7750 1350 2    50   ~ 0
TIP_TC
Wire Wire Line
	7750 1350 7850 1350
Wire Wire Line
	8500 1450 8700 1450
Connection ~ 8500 1450
$Comp
L Device:C C5
U 1 1 61120714
P 8200 2350
F 0 "C5" V 8450 2350 50  0000 C CNN
F 1 "1n" V 8350 2350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 8238 2200 50  0001 C CNN
F 3 "~" H 8200 2350 50  0001 C CNN
	1    8200 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	7750 2400 7750 2350
Connection ~ 7750 2150
Wire Wire Line
	8050 2350 7750 2350
Connection ~ 7750 2350
Wire Wire Line
	7750 2350 7750 2150
Wire Wire Line
	8350 2350 8500 2350
Wire Wire Line
	8500 2350 8500 2150
Connection ~ 8500 2150
Text Notes 8350 2500 0    50   ~ 0
f_c = 8kHz
Text Label 8900 1450 0    50   ~ 0
TIP_TC_AMP
$Comp
L Device:R R1
U 1 1 6112C62D
P 3500 2300
F 0 "R1" V 3293 2300 50  0000 C CNN
F 1 "10k" V 3384 2300 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 3430 2300 50  0001 C CNN
F 3 "~" H 3500 2300 50  0001 C CNN
	1    3500 2300
	0    1    1    0   
$EndComp
Wire Wire Line
	3650 2300 3700 2300
Wire Wire Line
	4850 4550 4750 4550
Text Label 4850 4050 0    50   ~ 0
TIP_TC_AMP
Wire Wire Line
	4850 4050 4750 4050
Text Label 4850 4550 0    50   ~ 0
TIP_PWM
Text Label 3250 2300 2    50   ~ 0
TIP_PWM
Wire Wire Line
	3250 2300 3350 2300
Text Label 6350 1400 0    50   ~ 0
HEATER_CURRENT_AMP
Text Label 4850 4150 0    50   ~ 0
HEATER_CURRENT_AMP
Wire Wire Line
	4850 4150 4750 4150
$Comp
L Device:C C2
U 1 1 61139E93
P 4000 3700
F 0 "C2" V 3748 3700 50  0000 C CNN
F 1 "100n" V 3839 3700 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 4038 3550 50  0001 C CNN
F 3 "~" H 4000 3700 50  0001 C CNN
	1    4000 3700
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J1
U 1 1 6113BCC6
P 1150 5050
F 0 "J1" H 1100 5200 50  0000 R CNN
F 1 "Conn_01x04_Male" H 1150 5300 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 1150 5050 50  0001 C CNN
F 3 "~" H 1150 5050 50  0001 C CNN
	1    1150 5050
	1    0    0    1   
$EndComp
$Comp
L Regulator_Linear:LM1117-3.3 U1
U 1 1 6113D502
P 2200 4850
F 0 "U1" H 2200 5092 50  0000 C CNN
F 1 "LM1117-3.3" H 2200 5001 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 2200 4850 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 2200 4850 50  0001 C CNN
	1    2200 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 4850 1450 4850
$Comp
L power:GND #PWR010
U 1 1 611400D7
P 1850 4950
F 0 "#PWR010" H 1850 4700 50  0001 C CNN
F 1 "GND" H 1855 4777 50  0000 C CNN
F 2 "" H 1850 4950 50  0001 C CNN
F 3 "" H 1850 4950 50  0001 C CNN
	1    1850 4950
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR09
U 1 1 6114230E
P 1450 5050
F 0 "#PWR09" H 1450 4900 50  0001 C CNN
F 1 "VCC" V 1465 5178 50  0000 L CNN
F 2 "" H 1450 5050 50  0001 C CNN
F 3 "" H 1450 5050 50  0001 C CNN
	1    1450 5050
	0    1    1    0   
$EndComp
Wire Wire Line
	1350 4950 1850 4950
Wire Wire Line
	1400 5150 1350 5150
$Comp
L power:GND #PWR012
U 1 1 6114B81C
P 2200 5150
F 0 "#PWR012" H 2200 4900 50  0001 C CNN
F 1 "GND" H 2205 4977 50  0000 C CNN
F 2 "" H 2200 5150 50  0001 C CNN
F 3 "" H 2200 5150 50  0001 C CNN
	1    2200 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 6114C62E
P 2650 5000
F 0 "C1" H 2765 5046 50  0000 L CNN
F 1 "10u" H 2765 4955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 2688 4850 50  0001 C CNN
F 3 "~" H 2650 5000 50  0001 C CNN
	1    2650 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 4850 2500 4850
$Comp
L power:GND #PWR014
U 1 1 6114DCCB
P 2650 5150
F 0 "#PWR014" H 2650 4900 50  0001 C CNN
F 1 "GND" H 2655 4977 50  0000 C CNN
F 2 "" H 2650 5150 50  0001 C CNN
F 3 "" H 2650 5150 50  0001 C CNN
	1    2650 5150
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR013
U 1 1 6114E323
P 2650 4750
F 0 "#PWR013" H 2650 4600 50  0001 C CNN
F 1 "+3.3V" H 2665 4923 50  0000 C CNN
F 2 "" H 2650 4750 50  0001 C CNN
F 3 "" H 2650 4750 50  0001 C CNN
	1    2650 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 4750 2650 4800
Connection ~ 2650 4850
Text Notes 1100 5150 2    50   ~ 0
VOUT\nGND\nVIN\nEN
$Comp
L Device:C C3
U 1 1 6115A5C8
P 4600 3700
F 0 "C3" V 4348 3700 50  0000 C CNN
F 1 "100n" V 4439 3700 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 4638 3550 50  0001 C CNN
F 3 "~" H 4600 3700 50  0001 C CNN
	1    4600 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	4150 3700 4250 3700
Wire Wire Line
	4250 3700 4250 3850
Wire Wire Line
	4250 3700 4300 3700
Connection ~ 4250 3700
Wire Wire Line
	4350 3700 4350 3850
Connection ~ 4350 3700
Wire Wire Line
	4350 3700 4450 3700
$Comp
L power:+3.3V #PWR019
U 1 1 6115E4FC
P 4300 3550
F 0 "#PWR019" H 4300 3400 50  0001 C CNN
F 1 "+3.3V" H 4315 3723 50  0000 C CNN
F 2 "" H 4300 3550 50  0001 C CNN
F 3 "" H 4300 3550 50  0001 C CNN
	1    4300 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 3550 4300 3700
Connection ~ 4300 3700
Wire Wire Line
	4300 3700 4350 3700
$Comp
L power:GND #PWR020
U 1 1 61160A31
P 4750 3700
F 0 "#PWR020" H 4750 3450 50  0001 C CNN
F 1 "GND" H 4755 3527 50  0000 C CNN
F 2 "" H 4750 3700 50  0001 C CNN
F 3 "" H 4750 3700 50  0001 C CNN
	1    4750 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 61160DCC
P 3850 3700
F 0 "#PWR015" H 3850 3450 50  0001 C CNN
F 1 "GND" H 3855 3527 50  0000 C CNN
F 2 "" H 3850 3700 50  0001 C CNN
F 3 "" H 3850 3700 50  0001 C CNN
	1    3850 3700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J3
U 1 1 61164CCE
P 1300 1600
F 0 "J3" H 1272 1574 50  0000 R CNN
F 1 "Conn_01x04_Male" H 1272 1483 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Horizontal" H 1300 1600 50  0001 C CNN
F 3 "~" H 1300 1600 50  0001 C CNN
	1    1300 1600
	-1   0    0    -1  
$EndComp
Text Label 1000 1500 2    50   ~ 0
GND
Text Label 1000 1600 2    50   ~ 0
SWDCLK
Text Label 1000 1700 2    50   ~ 0
SWDIO
Text Label 1000 1800 2    50   ~ 0
NRESET
Wire Wire Line
	1000 1800 1100 1800
Wire Wire Line
	1000 1700 1100 1700
Wire Wire Line
	1000 1600 1100 1600
Wire Wire Line
	1000 1500 1100 1500
Text Label 4850 5150 0    50   ~ 0
SWDCLK
Text Label 4850 5050 0    50   ~ 0
SWDIO
Wire Wire Line
	4850 5050 4750 5050
Wire Wire Line
	4750 5150 4850 5150
Text Label 4850 4950 0    50   ~ 0
I2C_SDA
Wire Wire Line
	4850 4950 4750 4950
Text Label 4850 4850 0    50   ~ 0
I2C_SCL
Text Label 3750 4050 2    50   ~ 0
NRESET
Wire Wire Line
	3750 4050 3850 4050
Text Notes 1600 1100 0    50   ~ 0
Power connector\n(20V 4.5A)
Text Notes 1600 1550 0    50   ~ 0
Programming header
Text Notes 1450 2150 0    50   ~ 0
Handle connector\n(top two pins are high-current)
Wire Wire Line
	8050 1150 8050 1100
$Comp
L Device:C C6
U 1 1 611AB97B
P 8300 1100
F 0 "C6" V 8048 1100 50  0000 C CNN
F 1 "100n" V 8139 1100 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 8338 950 50  0001 C CNN
F 3 "~" H 8300 1100 50  0001 C CNN
	1    8300 1100
	0    1    1    0   
$EndComp
Wire Wire Line
	8150 1100 8050 1100
Connection ~ 8050 1100
Wire Wire Line
	8050 1100 8050 1050
$Comp
L power:GND #PWR029
U 1 1 611AF3AD
P 8500 1100
F 0 "#PWR029" H 8500 850 50  0001 C CNN
F 1 "GND" H 8505 927 50  0000 C CNN
F 2 "" H 8500 1100 50  0001 C CNN
F 3 "" H 8500 1100 50  0001 C CNN
	1    8500 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 1100 8450 1100
Text Label 1850 3100 2    50   ~ 0
TIP_ACTIVE
Text Label 4850 4250 0    50   ~ 0
TIP_ACTIVE
Wire Wire Line
	4850 4250 4750 4250
$Comp
L Switch:SW_Push SW2
U 1 1 611C104A
P 6300 3600
F 0 "SW2" H 6300 3885 50  0000 C CNN
F 1 "FSMRA3JH" H 6300 3794 50  0000 C CNN
F 2 "Button_Switch_THT:SW_Tactile_SPST_Angled_PTS645Vx58-2LFS" H 6300 3800 50  0001 C CNN
F 3 "~" H 6300 3800 50  0001 C CNN
	1    6300 3600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 611C156D
P 6300 3950
F 0 "SW3" H 6300 4235 50  0000 C CNN
F 1 "FSMRA3JH" H 6300 4144 50  0000 C CNN
F 2 "Button_Switch_THT:SW_Tactile_SPST_Angled_PTS645Vx58-2LFS" H 6300 4150 50  0001 C CNN
F 3 "~" H 6300 4150 50  0001 C CNN
	1    6300 3950
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW4
U 1 1 611C1B68
P 6300 4300
F 0 "SW4" H 6300 4585 50  0000 C CNN
F 1 "FSMRA3JH" H 6300 4494 50  0000 C CNN
F 2 "Button_Switch_THT:SW_Tactile_SPST_Angled_PTS645Vx58-2LFS" H 6300 4500 50  0001 C CNN
F 3 "~" H 6300 4500 50  0001 C CNN
	1    6300 4300
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW5
U 1 1 611C20A8
P 6300 4650
F 0 "SW5" H 6300 4935 50  0000 C CNN
F 1 "FSMRA3JH" H 6300 4844 50  0000 C CNN
F 2 "Button_Switch_THT:SW_Tactile_SPST_Angled_PTS645Vx58-2LFS" H 6300 4850 50  0001 C CNN
F 3 "~" H 6300 4850 50  0001 C CNN
	1    6300 4650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR018
U 1 1 611C416A
P 4250 5350
F 0 "#PWR018" H 4250 5100 50  0001 C CNN
F 1 "GND" H 4255 5177 50  0000 C CNN
F 2 "" H 4250 5350 50  0001 C CNN
F 3 "" H 4250 5350 50  0001 C CNN
	1    4250 5350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR024
U 1 1 611C60CE
P 6050 4750
F 0 "#PWR024" H 6050 4500 50  0001 C CNN
F 1 "GND" H 6055 4577 50  0000 C CNN
F 2 "" H 6050 4750 50  0001 C CNN
F 3 "" H 6050 4750 50  0001 C CNN
	1    6050 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 4750 6050 4650
Wire Wire Line
	6050 3600 6100 3600
Wire Wire Line
	6100 3950 6050 3950
Connection ~ 6050 3950
Wire Wire Line
	6050 3950 6050 3600
Wire Wire Line
	6100 4300 6050 4300
Connection ~ 6050 4300
Wire Wire Line
	6050 4300 6050 3950
Wire Wire Line
	6100 4650 6050 4650
Connection ~ 6050 4650
Wire Wire Line
	6050 4650 6050 4300
Text Label 6600 3600 0    50   ~ 0
BTN_MENU
Text Label 6600 3950 0    50   ~ 0
BTN_UP
Text Label 6600 4300 0    50   ~ 0
BTN_DOWN
Text Label 6600 4650 0    50   ~ 0
BTN_ENTER
Wire Wire Line
	6500 4650 6600 4650
Wire Wire Line
	6500 4300 6600 4300
Wire Wire Line
	6600 3950 6500 3950
Wire Wire Line
	6600 3600 6500 3600
Text Label 3850 4750 2    50   ~ 0
BTN_MENU
Text Label 3850 4850 2    50   ~ 0
BTN_UP
Text Label 3850 5050 2    50   ~ 0
BTN_DOWN
Text Label 3850 5150 2    50   ~ 0
BTN_ENTER
Text Notes 1900 4500 2    50   ~ 0
Output capacitance\non DC-DC module
$Comp
L Connector:Conn_01x04_Male J5
U 1 1 61209B8D
P 1300 2700
F 0 "J5" H 1272 2674 50  0000 R CNN
F 1 "Conn_01x04_Male" H 1272 2583 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 1300 2700 50  0001 C CNN
F 3 "~" H 1300 2700 50  0001 C CNN
	1    1300 2700
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 6120AD41
P 1100 2600
F 0 "#PWR04" H 1100 2350 50  0001 C CNN
F 1 "GND" V 1105 2472 50  0000 R CNN
F 2 "" H 1100 2600 50  0001 C CNN
F 3 "" H 1100 2600 50  0001 C CNN
	1    1100 2600
	0    1    1    0   
$EndComp
Text Label 1100 2800 2    50   ~ 0
I2C_SDA
Text Label 1100 2900 2    50   ~ 0
I2C_SCL
$Comp
L power:+5V #PWR08
U 1 1 612121B0
P 1450 4850
F 0 "#PWR08" H 1450 4700 50  0001 C CNN
F 1 "+5V" H 1465 5023 50  0000 C CNN
F 2 "" H 1450 4850 50  0001 C CNN
F 3 "" H 1450 4850 50  0001 C CNN
	1    1450 4850
	1    0    0    -1  
$EndComp
Connection ~ 1450 4850
Wire Wire Line
	1450 4850 1650 4850
$Comp
L power:+5V #PWR05
U 1 1 61213717
P 1100 2700
F 0 "#PWR05" H 1100 2550 50  0001 C CNN
F 1 "+5V" V 1115 2828 50  0000 L CNN
F 2 "" H 1100 2700 50  0001 C CNN
F 3 "" H 1100 2700 50  0001 C CNN
	1    1100 2700
	0    -1   -1   0   
$EndComp
Text Notes 1600 2650 0    50   ~ 0
LCD (I2C is 5V-tolerant)
Wire Wire Line
	4850 4850 4750 4850
Wire Wire Line
	4050 2000 4050 2100
Wire Notes Line
	2800 650  550  650 
Wire Notes Line
	550  4250 3050 4250
Wire Notes Line
	3150 3250 5800 3250
Wire Notes Line
	5800 3250 5800 5650
Wire Notes Line
	5800 5650 3150 5650
Wire Notes Line
	3150 5650 3150 3250
Wire Notes Line
	7250 3250 7250 5100
Wire Notes Line
	7250 5100 5900 5100
Wire Notes Line
	5900 5100 5900 3250
Wire Notes Line
	5900 3250 7250 3250
Wire Notes Line
	2900 2750 7250 2750
Wire Notes Line
	7250 2750 7250 650 
Wire Notes Line
	7250 650  2900 650 
Wire Notes Line
	2900 650  2900 2750
Wire Notes Line
	7350 3000 9550 3000
Wire Notes Line
	9550 3000 9550 650 
Wire Notes Line
	9550 650  7350 650 
Wire Notes Line
	7350 650  7350 3000
Text Notes 550  650  0    100  ~ 0
Connections
Text Notes 2900 650  0    100  ~ 0
Heater driver and current amp
Text Notes 550  4250 0    100  ~ 0
Regulators
Text Notes 3150 3250 0    100  ~ 0
Microcontroller
Text Notes 5900 3250 0    100  ~ 0
Buttons
Text Notes 7350 650  0    100  ~ 0
Thermocouple amp
$Comp
L Connector:TestPoint TP1
U 1 1 61389E0E
P 1100 2050
F 0 "TP1" V 1100 2238 50  0000 L CNN
F 1 "TestPoint" V 1145 2238 50  0001 L CNN
F 2 "TestPoint:TestPoint_Plated_Hole_D3.0mm" H 1300 2050 50  0001 C CNN
F 3 "~" H 1300 2050 50  0001 C CNN
	1    1100 2050
	0    1    1    0   
$EndComp
$Comp
L Connector:TestPoint TP2
U 1 1 6138A2B5
P 1100 2150
F 0 "TP2" V 1100 2338 50  0000 L CNN
F 1 "TestPoint" V 1145 2338 50  0001 L CNN
F 2 "TestPoint:TestPoint_Plated_Hole_D3.0mm" H 1300 2150 50  0001 C CNN
F 3 "~" H 1300 2150 50  0001 C CNN
	1    1100 2150
	0    1    1    0   
$EndComp
Text Notes 4800 2350 0    47   ~ 0
Tip resistance is about 2.4 Ohm
Text Label 1100 3150 2    50   ~ 0
PA3
Text Label 1100 3250 2    50   ~ 0
PA4
Text Label 1100 3350 2    50   ~ 0
PA6
Text Label 1100 3450 2    50   ~ 0
PA7
Wire Notes Line
	550  3550 2800 3550
Text Label 4850 4350 0    50   ~ 0
PA3
Text Label 4850 4450 0    50   ~ 0
PA4
Text Label 4850 4650 0    50   ~ 0
PA6
Text Label 4850 4750 0    50   ~ 0
PA7
Wire Wire Line
	4850 4750 4750 4750
Wire Wire Line
	4850 4650 4750 4650
Wire Wire Line
	4850 4450 4750 4450
Wire Wire Line
	4850 4350 4750 4350
$Comp
L Connector:Conn_01x05_Male J6
U 1 1 61432CEE
P 1300 3250
F 0 "J6" H 1272 3274 50  0000 R CNN
F 1 "Conn_01x05_Male" H 1272 3183 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 1300 3250 50  0001 C CNN
F 3 "~" H 1300 3250 50  0001 C CNN
	1    1300 3250
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 6143A2FF
P 1100 3050
F 0 "#PWR06" H 1100 2800 50  0001 C CNN
F 1 "GND" V 1105 2922 50  0000 R CNN
F 2 "" H 1100 3050 50  0001 C CNN
F 3 "" H 1100 3050 50  0001 C CNN
	1    1100 3050
	0    1    1    0   
$EndComp
Wire Notes Line
	2800 650  2800 3550
Wire Notes Line
	550  650  550  3550
$Comp
L Connector:Conn_01x01_Male J4
U 1 1 6110EDC9
P 1300 2250
F 0 "J4" H 1272 2182 50  0000 R CNN
F 1 "Conn_01x01_Male" H 1272 2273 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 1300 2250 50  0001 C CNN
F 3 "~" H 1300 2250 50  0001 C CNN
	1    1300 2250
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J7
U 1 1 6110F440
P 2050 3100
F 0 "J7" H 2022 3032 50  0000 R CNN
F 1 "Conn_01x01_Male" H 2022 3123 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 2050 3100 50  0001 C CNN
F 3 "~" H 2050 3100 50  0001 C CNN
	1    2050 3100
	-1   0    0    1   
$EndComp
Text Notes 5250 4850 0    50   ~ 0
LCD has\npull-ups
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 61135267
P 1100 5950
F 0 "H1" V 1245 5953 50  0000 C CNN
F 1 "MountingHole_Pad" V 1246 5953 50  0001 C CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_DIN965_Pad" H 1100 5950 50  0001 C CNN
F 3 "~" H 1100 5950 50  0001 C CNN
	1    1100 5950
	0    -1   -1   0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 611383C1
P 1100 6250
F 0 "H2" V 1245 6253 50  0000 C CNN
F 1 "MountingHole_Pad" V 1246 6253 50  0001 C CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_DIN965_Pad" H 1100 6250 50  0001 C CNN
F 3 "~" H 1100 6250 50  0001 C CNN
	1    1100 6250
	0    -1   -1   0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H3
U 1 1 611386CF
P 1100 6550
F 0 "H3" V 1245 6553 50  0000 C CNN
F 1 "MountingHole_Pad" V 1246 6553 50  0001 C CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_DIN965_Pad" H 1100 6550 50  0001 C CNN
F 3 "~" H 1100 6550 50  0001 C CNN
	1    1100 6550
	0    -1   -1   0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H4
U 1 1 611389B6
P 1100 6850
F 0 "H4" V 1245 6853 50  0000 C CNN
F 1 "MountingHole_Pad" V 1246 6853 50  0001 C CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_DIN965_Pad" H 1100 6850 50  0001 C CNN
F 3 "~" H 1100 6850 50  0001 C CNN
	1    1100 6850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR07
U 1 1 61138D41
P 1200 6950
F 0 "#PWR07" H 1200 6700 50  0001 C CNN
F 1 "GND" H 1205 6777 50  0000 C CNN
F 2 "" H 1200 6950 50  0001 C CNN
F 3 "" H 1200 6950 50  0001 C CNN
	1    1200 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 5950 1200 6250
Connection ~ 1200 6250
Wire Wire Line
	1200 6250 1200 6550
Connection ~ 1200 6550
Wire Wire Line
	1200 6550 1200 6850
Connection ~ 1200 6850
Wire Wire Line
	1200 6850 1200 6950
Wire Wire Line
	4800 1700 4800 1650
Connection ~ 4800 1650
Connection ~ 4050 1300
$Comp
L Device:R R3
U 1 1 611B3B95
P 4050 1850
F 0 "R3" H 4120 1896 50  0000 L CNN
F 1 "2k2" H 4120 1805 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 3980 1850 50  0001 C CNN
F 3 "~" H 4050 1850 50  0001 C CNN
	1    4050 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 1700 4050 1650
Wire Wire Line
	4500 1900 4500 1650
Wire Wire Line
	4500 1650 4350 1650
Connection ~ 4050 1650
Wire Wire Line
	4050 1650 4050 1600
$Comp
L Switch:SW_SPDT SW1
U 1 1 611D67DB
P 1650 5500
F 0 "SW1" H 1650 5785 50  0000 C CNN
F 1 "JS202011AQN" H 1650 5694 50  0000 C CNN
F 2 "Button_Switch_THT:SW_CuK_JS202011AQN_DPDT_Angled" H 1650 5500 50  0001 C CNN
F 3 "~" H 1650 5500 50  0001 C CNN
	1    1650 5500
	1    0    0    -1  
$EndComp
NoConn ~ 1850 5600
Wire Wire Line
	1350 5050 1450 5050
Wire Wire Line
	1400 5150 1400 5500
Wire Wire Line
	1400 5500 1450 5500
$Comp
L power:GND #PWR011
U 1 1 611E6CE4
P 1950 5400
F 0 "#PWR011" H 1950 5150 50  0001 C CNN
F 1 "GND" H 1955 5227 50  0000 C CNN
F 2 "" H 1950 5400 50  0001 C CNN
F 3 "" H 1950 5400 50  0001 C CNN
	1    1950 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 5400 1850 5400
Wire Notes Line
	3050 5700 550  5700
Wire Notes Line
	3050 4250 3050 5700
Wire Notes Line
	550  4250 550  5700
Text Notes 2050 5500 0    50   ~ 0
Main power switch
$Comp
L Connector:TestPoint TP6
U 1 1 61218915
P 4350 1650
F 0 "TP6" H 4408 1722 50  0000 L CNN
F 1 "TestPoint" H 4408 1677 50  0001 L CNN
F 2 "TestPoint:TestPoint_Pad_D2.5mm" H 4550 1650 50  0001 C CNN
F 3 "~" H 4550 1650 50  0001 C CNN
	1    4350 1650
	1    0    0    -1  
$EndComp
Connection ~ 4350 1650
Wire Wire Line
	4350 1650 4050 1650
$Comp
L Connector:TestPoint TP8
U 1 1 61219984
P 8700 1450
F 0 "TP8" H 8758 1522 50  0000 L CNN
F 1 "TestPoint" H 8758 1477 50  0001 L CNN
F 2 "TestPoint:TestPoint_Pad_D2.5mm" H 8900 1450 50  0001 C CNN
F 3 "~" H 8900 1450 50  0001 C CNN
	1    8700 1450
	1    0    0    -1  
$EndComp
Connection ~ 8700 1450
Wire Wire Line
	8700 1450 8900 1450
$Comp
L Connector:TestPoint TP4
U 1 1 6121D90B
P 2650 4800
F 0 "TP4" V 2650 4988 50  0000 L CNN
F 1 "TestPoint" H 2708 4827 50  0001 L CNN
F 2 "TestPoint:TestPoint_Pad_D2.5mm" H 2850 4800 50  0001 C CNN
F 3 "~" H 2850 4800 50  0001 C CNN
	1    2650 4800
	0    1    1    0   
$EndComp
Connection ~ 2650 4800
Wire Wire Line
	2650 4800 2650 4850
$Comp
L Connector:TestPoint TP3
U 1 1 6122228A
P 1650 4850
F 0 "TP3" H 1708 4922 50  0000 L CNN
F 1 "TestPoint" H 1708 4877 50  0001 L CNN
F 2 "TestPoint:TestPoint_Pad_D2.5mm" H 1850 4850 50  0001 C CNN
F 3 "~" H 1850 4850 50  0001 C CNN
	1    1650 4850
	1    0    0    -1  
$EndComp
Connection ~ 1650 4850
Wire Wire Line
	1650 4850 1900 4850
$Comp
L Connector:TestPoint TP5
U 1 1 6122323C
P 3700 2300
F 0 "TP5" H 3758 2372 50  0000 L CNN
F 1 "TestPoint" H 3758 2327 50  0001 L CNN
F 2 "TestPoint:TestPoint_Pad_D2.5mm" H 3900 2300 50  0001 C CNN
F 3 "~" H 3900 2300 50  0001 C CNN
	1    3700 2300
	1    0    0    -1  
$EndComp
Connection ~ 3700 2300
Wire Wire Line
	3700 2300 3750 2300
$Comp
L Connector:TestPoint TP7
U 1 1 6122ACF4
P 6300 1300
F 0 "TP7" H 6358 1372 50  0000 L CNN
F 1 "TestPoint" H 6358 1327 50  0001 L CNN
F 2 "TestPoint:TestPoint_Pad_D2.5mm" H 6500 1300 50  0001 C CNN
F 3 "~" H 6500 1300 50  0001 C CNN
	1    6300 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 1300 6300 1400
Wire Wire Line
	6100 1400 6300 1400
Wire Wire Line
	6300 1400 6350 1400
Connection ~ 6300 1400
$EndSCHEMATC
