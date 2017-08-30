                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.6.0 #9615 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module timerTick
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _CLK_PeripheralClockConfig
                                     12 	.globl _TIM4_ClearFlag
                                     13 	.globl _TIM4_GetCounter
                                     14 	.globl _TIM4_ITConfig
                                     15 	.globl _TIM4_Cmd
                                     16 	.globl _TIM4_TimeBaseInit
                                     17 	.globl _TIM4_DeInit
                                     18 	.globl _timeTickUs
                                     19 	.globl _timeTickMs
                                     20 	.globl _timeBack
                                     21 	.globl _timeGet
                                     22 	.globl _TIMER_Init
                                     23 	.globl _TIMER_Inc
                                     24 	.globl _TIMER_InitTime
                                     25 	.globl _TIMER_CheckTimeUS
                                     26 	.globl _TIMER_CheckTimeMS
                                     27 ;--------------------------------------------------------
                                     28 ; ram data
                                     29 ;--------------------------------------------------------
                                     30 	.area DATA
      000001                         31 _timeGet::
      000001                         32 	.ds 2
      000003                         33 _timeBack::
      000003                         34 	.ds 2
      000005                         35 _timeTickMs::
      000005                         36 	.ds 4
      000009                         37 _timeTickUs::
      000009                         38 	.ds 1
                                     39 ;--------------------------------------------------------
                                     40 ; ram data
                                     41 ;--------------------------------------------------------
                                     42 	.area INITIALIZED
                                     43 ;--------------------------------------------------------
                                     44 ; absolute external ram data
                                     45 ;--------------------------------------------------------
                                     46 	.area DABS (ABS)
                                     47 ;--------------------------------------------------------
                                     48 ; global & static initialisations
                                     49 ;--------------------------------------------------------
                                     50 	.area HOME
                                     51 	.area GSINIT
                                     52 	.area GSFINAL
                                     53 	.area GSINIT
                                     54 ;--------------------------------------------------------
                                     55 ; Home
                                     56 ;--------------------------------------------------------
                                     57 	.area HOME
                                     58 	.area HOME
                                     59 ;--------------------------------------------------------
                                     60 ; code
                                     61 ;--------------------------------------------------------
                                     62 	.area CODE
                                     63 ;	user/timerTick.c: 19: void TIMER_Init(void)
                                     64 ;	-----------------------------------------
                                     65 ;	 function TIMER_Init
                                     66 ;	-----------------------------------------
      0080A6                         67 _TIMER_Init:
                                     68 ;	user/timerTick.c: 21: CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER4 , ENABLE); 
      0080A6 4B 01            [ 1]   69 	push	#0x01
      0080A8 4B 04            [ 1]   70 	push	#0x04
      0080AA CD 82 23         [ 4]   71 	call	_CLK_PeripheralClockConfig
      0080AD 85               [ 2]   72 	popw	x
                                     73 ;	user/timerTick.c: 22: TIM4_DeInit(); 
      0080AE CD 85 83         [ 4]   74 	call	_TIM4_DeInit
                                     75 ;	user/timerTick.c: 24: TIM4_TimeBaseInit(TIM4_PRESCALER_16, CYCLE_US);
      0080B1 4B C8            [ 1]   76 	push	#0xc8
      0080B3 4B 04            [ 1]   77 	push	#0x04
      0080B5 CD 85 9C         [ 4]   78 	call	_TIM4_TimeBaseInit
      0080B8 85               [ 2]   79 	popw	x
                                     80 ;	user/timerTick.c: 25: TIM4_ClearFlag(TIM4_FLAG_UPDATE); 
      0080B9 4B 01            [ 1]   81 	push	#0x01
      0080BB CD 85 CC         [ 4]   82 	call	_TIM4_ClearFlag
      0080BE 84               [ 1]   83 	pop	a
                                     84 ;	user/timerTick.c: 26: TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
      0080BF 4B 01            [ 1]   85 	push	#0x01
      0080C1 4B 01            [ 1]   86 	push	#0x01
      0080C3 CD 85 AE         [ 4]   87 	call	_TIM4_ITConfig
      0080C6 85               [ 2]   88 	popw	x
                                     89 ;	user/timerTick.c: 27: TIM4_Cmd(ENABLE);    // Enable TIM4 
      0080C7 4B 01            [ 1]   90 	push	#0x01
      0080C9 CD 85 A9         [ 4]   91 	call	_TIM4_Cmd
      0080CC 84               [ 1]   92 	pop	a
                                     93 ;	user/timerTick.c: 28: timeTickMs = 0;
      0080CD 5F               [ 1]   94 	clrw	x
      0080CE CF 00 07         [ 2]   95 	ldw	_timeTickMs+2, x
      0080D1 CF 00 05         [ 2]   96 	ldw	_timeTickMs+0, x
                                     97 ;	user/timerTick.c: 29: timeTickUs = 0;
      0080D4 72 5F 00 09      [ 1]   98 	clr	_timeTickUs+0
      0080D8 81               [ 4]   99 	ret
                                    100 ;	user/timerTick.c: 32: void TIMER_Inc(void)
                                    101 ;	-----------------------------------------
                                    102 ;	 function TIMER_Inc
                                    103 ;	-----------------------------------------
      0080D9                        104 _TIMER_Inc:
                                    105 ;	user/timerTick.c: 34: timeTickUs++;
      0080D9 72 5C 00 09      [ 1]  106 	inc	_timeTickUs+0
                                    107 ;	user/timerTick.c: 35: if(timeTickUs%5 == 0){
      0080DD 5F               [ 1]  108 	clrw	x
      0080DE C6 00 09         [ 1]  109 	ld	a, _timeTickUs+0
      0080E1 97               [ 1]  110 	ld	xl, a
      0080E2 A6 05            [ 1]  111 	ld	a, #0x05
      0080E4 62               [ 2]  112 	div	x, a
      0080E5 4D               [ 1]  113 	tnz	a
      0080E6 27 01            [ 1]  114 	jreq	00109$
      0080E8 81               [ 4]  115 	ret
      0080E9                        116 00109$:
                                    117 ;	user/timerTick.c: 36: timeTickMs++;
      0080E9 CE 00 07         [ 2]  118 	ldw	x, _timeTickMs+2
      0080EC 1C 00 01         [ 2]  119 	addw	x, #0x0001
      0080EF C6 00 06         [ 1]  120 	ld	a, _timeTickMs+1
      0080F2 A9 00            [ 1]  121 	adc	a, #0x00
      0080F4 90 97            [ 1]  122 	ld	yl, a
      0080F6 C6 00 05         [ 1]  123 	ld	a, _timeTickMs+0
      0080F9 A9 00            [ 1]  124 	adc	a, #0x00
      0080FB 90 95            [ 1]  125 	ld	yh, a
      0080FD CF 00 07         [ 2]  126 	ldw	_timeTickMs+2, x
      008100 90 CF 00 05      [ 2]  127 	ldw	_timeTickMs+0, y
      008104 81               [ 4]  128 	ret
                                    129 ;	user/timerTick.c: 40: void TIMER_InitTime(TIME *pTime)
                                    130 ;	-----------------------------------------
                                    131 ;	 function TIMER_InitTime
                                    132 ;	-----------------------------------------
      008105                        133 _TIMER_InitTime:
                                    134 ;	user/timerTick.c: 42: pTime->timeMS = timeTickMs;
      008105 1E 03            [ 2]  135 	ldw	x, (0x03, sp)
      008107 5C               [ 2]  136 	incw	x
      008108 5C               [ 2]  137 	incw	x
      008109 90 CE 00 07      [ 2]  138 	ldw	y, _timeTickMs+2
      00810D EF 02            [ 2]  139 	ldw	(0x2, x), y
      00810F 90 CE 00 05      [ 2]  140 	ldw	y, _timeTickMs+0
      008113 FF               [ 2]  141 	ldw	(x), y
      008114 81               [ 4]  142 	ret
                                    143 ;	user/timerTick.c: 45: uint8_t TIMER_CheckTimeUS(TIME *pTime, uint16_t time)
                                    144 ;	-----------------------------------------
                                    145 ;	 function TIMER_CheckTimeUS
                                    146 ;	-----------------------------------------
      008115                        147 _TIMER_CheckTimeUS:
      008115 52 04            [ 2]  148 	sub	sp, #4
                                    149 ;	user/timerTick.c: 47: timeGet = TIM4_GetCounter();
      008117 CD 85 B9         [ 4]  150 	call	_TIM4_GetCounter
      00811A 5F               [ 1]  151 	clrw	x
      00811B 97               [ 1]  152 	ld	xl, a
      00811C CF 00 01         [ 2]  153 	ldw	_timeGet+0, x
                                    154 ;	user/timerTick.c: 48: if(((timeGet > pTime->timeUS)&&((timeGet - pTime->timeUS) >= time))||((timeGet < pTime->timeUS)&&(((CYCLE_US -  pTime->timeUS) + timeGet + 1) >= time))){
      00811F 16 07            [ 2]  155 	ldw	y, (0x07, sp)
      008121 17 01            [ 2]  156 	ldw	(0x01, sp), y
      008123 1E 01            [ 2]  157 	ldw	x, (0x01, sp)
      008125 FE               [ 2]  158 	ldw	x, (x)
      008126 1F 03            [ 2]  159 	ldw	(0x03, sp), x
      008128 1E 03            [ 2]  160 	ldw	x, (0x03, sp)
      00812A C3 00 01         [ 2]  161 	cpw	x, _timeGet+0
      00812D 24 0A            [ 1]  162 	jrnc	00105$
      00812F CE 00 01         [ 2]  163 	ldw	x, _timeGet+0
      008132 72 F0 03         [ 2]  164 	subw	x, (0x03, sp)
      008135 13 09            [ 2]  165 	cpw	x, (0x09, sp)
      008137 24 14            [ 1]  166 	jrnc	00101$
      008139                        167 00105$:
      008139 1E 03            [ 2]  168 	ldw	x, (0x03, sp)
      00813B C3 00 01         [ 2]  169 	cpw	x, _timeGet+0
      00813E 23 17            [ 2]  170 	jrule	00102$
      008140 CE 00 01         [ 2]  171 	ldw	x, _timeGet+0
      008143 1C 00 C9         [ 2]  172 	addw	x, #0x00c9
      008146 72 F0 03         [ 2]  173 	subw	x, (0x03, sp)
      008149 13 09            [ 2]  174 	cpw	x, (0x09, sp)
      00814B 25 0A            [ 1]  175 	jrc	00102$
      00814D                        176 00101$:
                                    177 ;	user/timerTick.c: 49: pTime->timeUS = timeGet;
      00814D 1E 01            [ 2]  178 	ldw	x, (0x01, sp)
      00814F 90 CE 00 01      [ 2]  179 	ldw	y, _timeGet+0
      008153 FF               [ 2]  180 	ldw	(x), y
                                    181 ;	user/timerTick.c: 50: return 0;
      008154 4F               [ 1]  182 	clr	a
      008155 20 02            [ 2]  183 	jra	00106$
      008157                        184 00102$:
                                    185 ;	user/timerTick.c: 52: return 1;
      008157 A6 01            [ 1]  186 	ld	a, #0x01
      008159                        187 00106$:
      008159 5B 04            [ 2]  188 	addw	sp, #4
      00815B 81               [ 4]  189 	ret
                                    190 ;	user/timerTick.c: 55: uint8_t TIMER_CheckTimeMS(TIME *pTime, uint32_t time)
                                    191 ;	-----------------------------------------
                                    192 ;	 function TIMER_CheckTimeMS
                                    193 ;	-----------------------------------------
      00815C                        194 _TIMER_CheckTimeMS:
      00815C 52 0B            [ 2]  195 	sub	sp, #11
                                    196 ;	user/timerTick.c: 57: if(((timeTickMs > pTime->timeMS)&&((timeTickMs - pTime->timeMS) >= time))||((timeTickMs < pTime->timeMS)&&(((CYCLE_MS -  pTime->timeMS) + timeTickMs + 1) >= time))){
      00815E 1E 0E            [ 2]  197 	ldw	x, (0x0e, sp)
      008160 5C               [ 2]  198 	incw	x
      008161 5C               [ 2]  199 	incw	x
      008162 1F 0A            [ 2]  200 	ldw	(0x0a, sp), x
      008164 1E 0A            [ 2]  201 	ldw	x, (0x0a, sp)
      008166 E6 03            [ 1]  202 	ld	a, (0x3, x)
      008168 6B 08            [ 1]  203 	ld	(0x08, sp), a
      00816A E6 02            [ 1]  204 	ld	a, (0x2, x)
      00816C 6B 07            [ 1]  205 	ld	(0x07, sp), a
      00816E FE               [ 2]  206 	ldw	x, (x)
      00816F 1F 05            [ 2]  207 	ldw	(0x05, sp), x
      008171 CE 00 07         [ 2]  208 	ldw	x, _timeTickMs+2
      008174 72 F0 07         [ 2]  209 	subw	x, (0x07, sp)
      008177 C6 00 06         [ 1]  210 	ld	a, _timeTickMs+1
      00817A 12 06            [ 1]  211 	sbc	a, (0x06, sp)
      00817C 88               [ 1]  212 	push	a
      00817D C6 00 05         [ 1]  213 	ld	a, _timeTickMs+0
      008180 12 06            [ 1]  214 	sbc	a, (0x06, sp)
      008182 6B 02            [ 1]  215 	ld	(0x02, sp), a
      008184 84               [ 1]  216 	pop	a
      008185 88               [ 1]  217 	push	a
      008186 13 13            [ 2]  218 	cpw	x, (0x13, sp)
      008188 84               [ 1]  219 	pop	a
      008189 12 11            [ 1]  220 	sbc	a, (0x11, sp)
      00818B 7B 01            [ 1]  221 	ld	a, (0x01, sp)
      00818D 12 10            [ 1]  222 	sbc	a, (0x10, sp)
      00818F 4F               [ 1]  223 	clr	a
      008190 49               [ 1]  224 	rlc	a
      008191 6B 09            [ 1]  225 	ld	(0x09, sp), a
      008193 1E 07            [ 2]  226 	ldw	x, (0x07, sp)
      008195 C3 00 07         [ 2]  227 	cpw	x, _timeTickMs+2
      008198 7B 06            [ 1]  228 	ld	a, (0x06, sp)
      00819A C2 00 06         [ 1]  229 	sbc	a, _timeTickMs+1
      00819D 7B 05            [ 1]  230 	ld	a, (0x05, sp)
      00819F C2 00 05         [ 1]  231 	sbc	a, _timeTickMs+0
      0081A2 24 04            [ 1]  232 	jrnc	00105$
      0081A4 0D 09            [ 1]  233 	tnz	(0x09, sp)
      0081A6 27 15            [ 1]  234 	jreq	00101$
      0081A8                        235 00105$:
      0081A8 CE 00 07         [ 2]  236 	ldw	x, _timeTickMs+2
      0081AB 13 07            [ 2]  237 	cpw	x, (0x07, sp)
      0081AD C6 00 06         [ 1]  238 	ld	a, _timeTickMs+1
      0081B0 12 06            [ 1]  239 	sbc	a, (0x06, sp)
      0081B2 C6 00 05         [ 1]  240 	ld	a, _timeTickMs+0
      0081B5 12 05            [ 1]  241 	sbc	a, (0x05, sp)
      0081B7 24 14            [ 1]  242 	jrnc	00102$
      0081B9 0D 09            [ 1]  243 	tnz	(0x09, sp)
      0081BB 26 10            [ 1]  244 	jrne	00102$
      0081BD                        245 00101$:
                                    246 ;	user/timerTick.c: 58: pTime->timeMS = timeTickMs;
      0081BD 1E 0A            [ 2]  247 	ldw	x, (0x0a, sp)
      0081BF 90 CE 00 07      [ 2]  248 	ldw	y, _timeTickMs+2
      0081C3 EF 02            [ 2]  249 	ldw	(0x2, x), y
      0081C5 90 CE 00 05      [ 2]  250 	ldw	y, _timeTickMs+0
      0081C9 FF               [ 2]  251 	ldw	(x), y
                                    252 ;	user/timerTick.c: 59: return 0;
      0081CA 4F               [ 1]  253 	clr	a
      0081CB 20 02            [ 2]  254 	jra	00106$
      0081CD                        255 00102$:
                                    256 ;	user/timerTick.c: 61: return 1;
      0081CD A6 01            [ 1]  257 	ld	a, #0x01
      0081CF                        258 00106$:
      0081CF 5B 0B            [ 2]  259 	addw	sp, #11
      0081D1 81               [ 4]  260 	ret
                                    261 	.area CODE
                                    262 	.area INITIALIZER
                                    263 	.area CABS (ABS)
