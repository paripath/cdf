cdf DFFX1
	table DFFX1
		inputs D;
		clocks CK;
		outputs Q , QN;
		function
			ff(IQ, IQN) {
				clocked_on : CK
				next_state : D
			}
			Q = IQ
			QN = IQN
		end_function
		delay dpower 
		simfeed v(ck)=0.0000000 v(dffx1:c)=-0.0000484 v(dffx1:cn)=1.1997150 v(dffx1:hnet14)=0.0000011 v(dffx1:hnet16)=1.4285070 v(dffx1:hnet22)=0.0001969 v(dffx1:hnet24)=0.3567618 v(dffx1:hnet30)=0.9733627 v(dffx1:hnet32)=1.2001050 v(dffx1:hnet38)=0.0000006 v(dffx1:hnet40)=1.3620590 v(dffx1:m)=1.1996580 v(dffx1:net43)=1.2002100 v(d)=1.2000000 v(dffx1:pm)=0.0003926 v(dffx1:s)=0.0000233 v(q)=0.0000005 v(qn)=1.1999990 v(vdd)=1.2000000 v(vss)=0.0000000
			model delay CK r Q r = 0.02800 0.00079  , 0.11805 , 0.01524; #jobs/DFFX1_power_delay_1.sp.result0 
			model delay CK r Q r = 0.02800 0.00205  , 0.13246 , 0.02590; #jobs/DFFX1_power_delay_1.sp.result1 
			model delay CK r Q r = 0.02800 0.00474  , 0.15994 , 0.04938; #jobs/DFFX1_power_delay_1.sp.result2 
			model delay CK r Q r = 0.02800 0.01011  , 0.21243 , 0.09690; #jobs/DFFX1_power_delay_1.sp.result3 
			model delay CK r Q r = 0.02800 0.02086  , 0.31553 , 0.19346; #jobs/DFFX1_power_delay_1.sp.result4 
			model delay CK r Q r = 0.04400 0.00079  , 0.12471 , 0.01523; #jobs/DFFX1_power_delay_2.sp.result0 
			model delay CK r Q r = 0.04400 0.00205  , 0.13912 , 0.02589; #jobs/DFFX1_power_delay_2.sp.result1 
			model delay CK r Q r = 0.04400 0.00474  , 0.16660 , 0.04939; #jobs/DFFX1_power_delay_2.sp.result2 
			model delay CK r Q r = 0.04400 0.01011  , 0.21909 , 0.09690; #jobs/DFFX1_power_delay_2.sp.result3 
			model delay CK r Q r = 0.04400 0.02086  , 0.32219 , 0.19346; #jobs/DFFX1_power_delay_2.sp.result4 
			model delay CK r Q r = 0.07600 0.00079  , 0.13414 , 0.01525; #jobs/DFFX1_power_delay_3.sp.result0 
			model delay CK r Q r = 0.07600 0.00205  , 0.14854 , 0.02590; #jobs/DFFX1_power_delay_3.sp.result1 
			model delay CK r Q r = 0.07600 0.00474  , 0.17604 , 0.04938; #jobs/DFFX1_power_delay_3.sp.result2 
			model delay CK r Q r = 0.07600 0.01011  , 0.22853 , 0.09690; #jobs/DFFX1_power_delay_3.sp.result3 
			model delay CK r Q r = 0.07600 0.02086  , 0.33161 , 0.19346; #jobs/DFFX1_power_delay_3.sp.result4 
			model delay CK r Q r = 0.13800 0.00079  , 0.14444 , 0.01527; #jobs/DFFX1_power_delay_4.sp.result0 
			model delay CK r Q r = 0.13800 0.00205  , 0.15886 , 0.02591; #jobs/DFFX1_power_delay_4.sp.result1 
			model delay CK r Q r = 0.13800 0.00474  , 0.18637 , 0.04938; #jobs/DFFX1_power_delay_4.sp.result2 
			model delay CK r Q r = 0.13800 0.01011  , 0.23885 , 0.09690; #jobs/DFFX1_power_delay_4.sp.result3 
			model delay CK r Q r = 0.13800 0.02086  , 0.34193 , 0.19346; #jobs/DFFX1_power_delay_4.sp.result4 
			model delay CK r Q r = 0.26400 0.00079  , 0.15347 , 0.01526; #jobs/DFFX1_power_delay_5.sp.result0 
			model delay CK r Q r = 0.26400 0.00205  , 0.16792 , 0.02591; #jobs/DFFX1_power_delay_5.sp.result1 
			model delay CK r Q r = 0.26400 0.00474  , 0.19545 , 0.04940; #jobs/DFFX1_power_delay_5.sp.result2 
			model delay CK r Q r = 0.26400 0.01011  , 0.24794 , 0.09690; #jobs/DFFX1_power_delay_5.sp.result3 
			model delay CK r Q r = 0.26400 0.02086  , 0.35100 , 0.19345; #jobs/DFFX1_power_delay_5.sp.result4 
			model delay CK r QN f = 0.02800 0.00079  , 0.15393 , 0.01138; #jobs/DFFX1_power_delay_1.sp.result0 
			model delay CK r QN f = 0.02800 0.00205  , 0.16447 , 0.01699; #jobs/DFFX1_power_delay_1.sp.result1 
			model delay CK r QN f = 0.02800 0.00474  , 0.18233 , 0.02859; #jobs/DFFX1_power_delay_1.sp.result2 
			model delay CK r QN f = 0.02800 0.01011  , 0.21399 , 0.05315; #jobs/DFFX1_power_delay_1.sp.result3 
			model delay CK r QN f = 0.02800 0.02086  , 0.27525 , 0.10468; #jobs/DFFX1_power_delay_1.sp.result4 
			model delay CK r QN f = 0.04400 0.00079  , 0.16060 , 0.01135; #jobs/DFFX1_power_delay_2.sp.result0 
			model delay CK r QN f = 0.04400 0.00205  , 0.17113 , 0.01703; #jobs/DFFX1_power_delay_2.sp.result1 
			model delay CK r QN f = 0.04400 0.00474  , 0.18899 , 0.02861; #jobs/DFFX1_power_delay_2.sp.result2 
			model delay CK r QN f = 0.04400 0.01011  , 0.22065 , 0.05316; #jobs/DFFX1_power_delay_2.sp.result3 
			model delay CK r QN f = 0.04400 0.02086  , 0.28191 , 0.10468; #jobs/DFFX1_power_delay_2.sp.result4 
			model delay CK r QN f = 0.07600 0.00079  , 0.17003 , 0.01138; #jobs/DFFX1_power_delay_3.sp.result0 
			model delay CK r QN f = 0.07600 0.00205  , 0.18057 , 0.01700; #jobs/DFFX1_power_delay_3.sp.result1 
			model delay CK r QN f = 0.07600 0.00474  , 0.19843 , 0.02860; #jobs/DFFX1_power_delay_3.sp.result2 
			model delay CK r QN f = 0.07600 0.01011  , 0.23009 , 0.05315; #jobs/DFFX1_power_delay_3.sp.result3 
			model delay CK r QN f = 0.07600 0.02086  , 0.29135 , 0.10468; #jobs/DFFX1_power_delay_3.sp.result4 
			model delay CK r QN f = 0.13800 0.00079  , 0.18036 , 0.01137; #jobs/DFFX1_power_delay_4.sp.result0 
			model delay CK r QN f = 0.13800 0.00205  , 0.19090 , 0.01699; #jobs/DFFX1_power_delay_4.sp.result1 
			model delay CK r QN f = 0.13800 0.00474  , 0.20875 , 0.02859; #jobs/DFFX1_power_delay_4.sp.result2 
			model delay CK r QN f = 0.13800 0.01011  , 0.24041 , 0.05316; #jobs/DFFX1_power_delay_4.sp.result3 
			model delay CK r QN f = 0.13800 0.02086  , 0.30167 , 0.10468; #jobs/DFFX1_power_delay_4.sp.result4 
			model delay CK r QN f = 0.26400 0.00079  , 0.18945 , 0.01136; #jobs/DFFX1_power_delay_5.sp.result0 
			model delay CK r QN f = 0.26400 0.00205  , 0.19998 , 0.01703; #jobs/DFFX1_power_delay_5.sp.result1 
			model delay CK r QN f = 0.26400 0.00474  , 0.21784 , 0.02861; #jobs/DFFX1_power_delay_5.sp.result2 
			model delay CK r QN f = 0.26400 0.01011  , 0.24950 , 0.05316; #jobs/DFFX1_power_delay_5.sp.result3 
			model delay CK r QN f = 0.26400 0.02086  , 0.31076 , 0.10468; #jobs/DFFX1_power_delay_5.sp.result4 
			model dpower CK r Q r = 0.02800 0.00079  , 8.72448; #jobs/DFFX1_power_delay_1.sp.result0 
			model dpower CK r Q r = 0.02800 0.00205  , 10.56321; #jobs/DFFX1_power_delay_1.sp.result1 
			model dpower CK r Q r = 0.02800 0.00474  , 14.48557; #jobs/DFFX1_power_delay_1.sp.result2 
			model dpower CK r Q r = 0.02800 0.01011  , 22.27322; #jobs/DFFX1_power_delay_1.sp.result3 
			model dpower CK r Q r = 0.02800 0.02086  , 36.84912; #jobs/DFFX1_power_delay_1.sp.result4 
			model dpower CK r Q r = 0.04400 0.00079  , 8.71810; #jobs/DFFX1_power_delay_2.sp.result0 
			model dpower CK r Q r = 0.04400 0.00205  , 10.56032; #jobs/DFFX1_power_delay_2.sp.result1 
			model dpower CK r Q r = 0.04400 0.00474  , 14.48294; #jobs/DFFX1_power_delay_2.sp.result2 
			model dpower CK r Q r = 0.04400 0.01011  , 22.26871; #jobs/DFFX1_power_delay_2.sp.result3 
			model dpower CK r Q r = 0.04400 0.02086  , 36.64353; #jobs/DFFX1_power_delay_2.sp.result4 
			model dpower CK r Q r = 0.07600 0.00079  , 8.79123; #jobs/DFFX1_power_delay_3.sp.result0 
			model dpower CK r Q r = 0.07600 0.00205  , 10.62515; #jobs/DFFX1_power_delay_3.sp.result1 
			model dpower CK r Q r = 0.07600 0.00474  , 14.54504; #jobs/DFFX1_power_delay_3.sp.result2 
			model dpower CK r Q r = 0.07600 0.01011  , 22.32483; #jobs/DFFX1_power_delay_3.sp.result3 
			model dpower CK r Q r = 0.07600 0.02086  , 36.21424; #jobs/DFFX1_power_delay_3.sp.result4 
			model dpower CK r Q r = 0.13800 0.00079  , 8.99231; #jobs/DFFX1_power_delay_4.sp.result0 
			model dpower CK r Q r = 0.13800 0.00205  , 10.83484; #jobs/DFFX1_power_delay_4.sp.result1 
			model dpower CK r Q r = 0.13800 0.00474  , 14.75884; #jobs/DFFX1_power_delay_4.sp.result2 
			model dpower CK r Q r = 0.13800 0.01011  , 22.50826; #jobs/DFFX1_power_delay_4.sp.result3 
			model dpower CK r Q r = 0.13800 0.02086  , 35.03856; #jobs/DFFX1_power_delay_4.sp.result4 
			model dpower CK r Q r = 0.26400 0.00079  , 9.58564; #jobs/DFFX1_power_delay_5.sp.result0 
			model dpower CK r Q r = 0.26400 0.00205  , 11.42617; #jobs/DFFX1_power_delay_5.sp.result1 
			model dpower CK r Q r = 0.26400 0.00474  , 15.34810; #jobs/DFFX1_power_delay_5.sp.result2 
			model dpower CK r Q r = 0.26400 0.01011  , 22.64805; #jobs/DFFX1_power_delay_5.sp.result3 
			model dpower CK r Q r = 0.26400 0.02086  , 30.04211; #jobs/DFFX1_power_delay_5.sp.result4 
			model dpower CK r QN f = 0.02800 0.00079  , 8.72448; #jobs/DFFX1_power_delay_1.sp.result0 
			model dpower CK r QN f = 0.02800 0.00205  , 10.56321; #jobs/DFFX1_power_delay_1.sp.result1 
			model dpower CK r QN f = 0.02800 0.00474  , 14.48557; #jobs/DFFX1_power_delay_1.sp.result2 
			model dpower CK r QN f = 0.02800 0.01011  , 22.27322; #jobs/DFFX1_power_delay_1.sp.result3 
			model dpower CK r QN f = 0.02800 0.02086  , 36.84912; #jobs/DFFX1_power_delay_1.sp.result4 
			model dpower CK r QN f = 0.04400 0.00079  , 8.71810; #jobs/DFFX1_power_delay_2.sp.result0 
			model dpower CK r QN f = 0.04400 0.00205  , 10.56032; #jobs/DFFX1_power_delay_2.sp.result1 
			model dpower CK r QN f = 0.04400 0.00474  , 14.48294; #jobs/DFFX1_power_delay_2.sp.result2 
			model dpower CK r QN f = 0.04400 0.01011  , 22.26871; #jobs/DFFX1_power_delay_2.sp.result3 
			model dpower CK r QN f = 0.04400 0.02086  , 36.64353; #jobs/DFFX1_power_delay_2.sp.result4 
			model dpower CK r QN f = 0.07600 0.00079  , 8.79123; #jobs/DFFX1_power_delay_3.sp.result0 
			model dpower CK r QN f = 0.07600 0.00205  , 10.62515; #jobs/DFFX1_power_delay_3.sp.result1 
			model dpower CK r QN f = 0.07600 0.00474  , 14.54504; #jobs/DFFX1_power_delay_3.sp.result2 
			model dpower CK r QN f = 0.07600 0.01011  , 22.32483; #jobs/DFFX1_power_delay_3.sp.result3 
			model dpower CK r QN f = 0.07600 0.02086  , 36.21424; #jobs/DFFX1_power_delay_3.sp.result4 
			model dpower CK r QN f = 0.13800 0.00079  , 8.99231; #jobs/DFFX1_power_delay_4.sp.result0 
			model dpower CK r QN f = 0.13800 0.00205  , 10.83484; #jobs/DFFX1_power_delay_4.sp.result1 
			model dpower CK r QN f = 0.13800 0.00474  , 14.75884; #jobs/DFFX1_power_delay_4.sp.result2 
			model dpower CK r QN f = 0.13800 0.01011  , 22.50826; #jobs/DFFX1_power_delay_4.sp.result3 
			model dpower CK r QN f = 0.13800 0.02086  , 35.03856; #jobs/DFFX1_power_delay_4.sp.result4 
			model dpower CK r QN f = 0.26400 0.00079  , 9.58564; #jobs/DFFX1_power_delay_5.sp.result0 
			model dpower CK r QN f = 0.26400 0.00205  , 11.42617; #jobs/DFFX1_power_delay_5.sp.result1 
			model dpower CK r QN f = 0.26400 0.00474  , 15.34810; #jobs/DFFX1_power_delay_5.sp.result2 
			model dpower CK r QN f = 0.26400 0.01011  , 22.64805; #jobs/DFFX1_power_delay_5.sp.result3 
			model dpower CK r QN f = 0.26400 0.02086  , 30.04211; #jobs/DFFX1_power_delay_5.sp.result4 
			00 , 01 , 10 , 11 = rf ;
		delay dpower 
		simfeed v(ck)=0.0000000 v(dffx1:c)=0.0000777 v(dffx1:cn)=1.2000650 v(dffx1:hnet14)=-0.1708871 v(dffx1:hnet16)=1.1999980 v(dffx1:hnet22)=0.9727797 v(dffx1:hnet24)=1.1997660 v(dffx1:hnet30)=-0.0000499 v(dffx1:hnet32)=0.1881151 v(dffx1:hnet38)=-0.1487851 v(dffx1:hnet40)=1.1999990 v(dffx1:m)=0.0000772 v(dffx1:net43)=-0.0000995 v(d)=0.0000000 v(dffx1:pm)=1.1995360 v(dffx1:s)=1.2000000 v(q)=1.2000000 v(qn)=0.0000006 v(vdd)=1.2000000 v(vss)=0.0000000
			model delay CK r Q f = 0.02800 0.00079  , 0.10322 , 0.01358; #jobs/DFFX1_power_delay_6.sp.result0 
			model delay CK r Q f = 0.02800 0.00205  , 0.11667 , 0.02045; #jobs/DFFX1_power_delay_6.sp.result1 
			model delay CK r Q f = 0.02800 0.00474  , 0.13840 , 0.03316; #jobs/DFFX1_power_delay_6.sp.result2 
			model delay CK r Q f = 0.02800 0.01011  , 0.17352 , 0.05658; #jobs/DFFX1_power_delay_6.sp.result3 
			model delay CK r Q f = 0.02800 0.02086  , 0.23623 , 0.10607; #jobs/DFFX1_power_delay_6.sp.result4 
			model delay CK r Q f = 0.04400 0.00079  , 0.10969 , 0.01358; #jobs/DFFX1_power_delay_7.sp.result0 
			model delay CK r Q f = 0.04400 0.00205  , 0.12310 , 0.02047; #jobs/DFFX1_power_delay_7.sp.result1 
			model delay CK r Q f = 0.04400 0.00474  , 0.14482 , 0.03317; #jobs/DFFX1_power_delay_7.sp.result2 
			model delay CK r Q f = 0.04400 0.01011  , 0.17994 , 0.05658; #jobs/DFFX1_power_delay_7.sp.result3 
			model delay CK r Q f = 0.04400 0.02086  , 0.24265 , 0.10607; #jobs/DFFX1_power_delay_7.sp.result4 
			model delay CK r Q f = 0.07600 0.00079  , 0.11940 , 0.01366; #jobs/DFFX1_power_delay_8.sp.result0 
			model delay CK r Q f = 0.07600 0.00205  , 0.13280 , 0.02051; #jobs/DFFX1_power_delay_8.sp.result1 
			model delay CK r Q f = 0.07600 0.00474  , 0.15453 , 0.03319; #jobs/DFFX1_power_delay_8.sp.result2 
			model delay CK r Q f = 0.07600 0.01011  , 0.18967 , 0.05659; #jobs/DFFX1_power_delay_8.sp.result3 
			model delay CK r Q f = 0.07600 0.02086  , 0.25238 , 0.10607; #jobs/DFFX1_power_delay_8.sp.result4 
			model delay CK r Q f = 0.13800 0.00079  , 0.13039 , 0.01390; #jobs/DFFX1_power_delay_9.sp.result0 
			model delay CK r Q f = 0.13800 0.00205  , 0.14385 , 0.02074; #jobs/DFFX1_power_delay_9.sp.result1 
			model delay CK r Q f = 0.13800 0.00474  , 0.16568 , 0.03339; #jobs/DFFX1_power_delay_9.sp.result2 
			model delay CK r Q f = 0.13800 0.01011  , 0.20094 , 0.05673; #jobs/DFFX1_power_delay_9.sp.result3 
			model delay CK r Q f = 0.13800 0.02086  , 0.26370 , 0.10611; #jobs/DFFX1_power_delay_9.sp.result4 
			model delay CK r Q f = 0.26400 0.00079  , 0.14056 , 0.01449; #jobs/DFFX1_power_delay_10.sp.result0 
			model delay CK r Q f = 0.26400 0.00205  , 0.15419 , 0.02130; #jobs/DFFX1_power_delay_10.sp.result1 
			model delay CK r Q f = 0.26400 0.00474  , 0.17628 , 0.03386; #jobs/DFFX1_power_delay_10.sp.result2 
			model delay CK r Q f = 0.26400 0.01011  , 0.21175 , 0.05697; #jobs/DFFX1_power_delay_10.sp.result3 
			model delay CK r Q f = 0.26400 0.02086  , 0.27461 , 0.10620; #jobs/DFFX1_power_delay_10.sp.result4 
			model delay CK r QN r = 0.02800 0.00079  , 0.14342 , 0.01393; #jobs/DFFX1_power_delay_6.sp.result0 
			model delay CK r QN r = 0.02800 0.00205  , 0.15511 , 0.02395; #jobs/DFFX1_power_delay_6.sp.result1 
			model delay CK r QN r = 0.02800 0.00474  , 0.18026 , 0.04714; #jobs/DFFX1_power_delay_6.sp.result2 
			model delay CK r QN r = 0.02800 0.01011  , 0.23146 , 0.09539; #jobs/DFFX1_power_delay_6.sp.result3 
			model delay CK r QN r = 0.02800 0.02086  , 0.33404 , 0.19238; #jobs/DFFX1_power_delay_6.sp.result4 
			model delay CK r QN r = 0.04400 0.00079  , 0.14985 , 0.01397; #jobs/DFFX1_power_delay_7.sp.result0 
			model delay CK r QN r = 0.04400 0.00205  , 0.16154 , 0.02396; #jobs/DFFX1_power_delay_7.sp.result1 
			model delay CK r QN r = 0.04400 0.00474  , 0.18669 , 0.04714; #jobs/DFFX1_power_delay_7.sp.result2 
			model delay CK r QN r = 0.04400 0.01011  , 0.23788 , 0.09540; #jobs/DFFX1_power_delay_7.sp.result3 
			model delay CK r QN r = 0.04400 0.02086  , 0.34046 , 0.19238; #jobs/DFFX1_power_delay_7.sp.result4 
			model delay CK r QN r = 0.07600 0.00079  , 0.15958 , 0.01395; #jobs/DFFX1_power_delay_8.sp.result0 
			model delay CK r QN r = 0.07600 0.00205  , 0.17127 , 0.02396; #jobs/DFFX1_power_delay_8.sp.result1 
			model delay CK r QN r = 0.07600 0.00474  , 0.19640 , 0.04714; #jobs/DFFX1_power_delay_8.sp.result2 
			model delay CK r QN r = 0.07600 0.01011  , 0.24757 , 0.09539; #jobs/DFFX1_power_delay_8.sp.result3 
			model delay CK r QN r = 0.07600 0.02086  , 0.35015 , 0.19238; #jobs/DFFX1_power_delay_8.sp.result4 
			model delay CK r QN r = 0.13800 0.00079  , 0.17078 , 0.01396; #jobs/DFFX1_power_delay_9.sp.result0 
			model delay CK r QN r = 0.13800 0.00205  , 0.18241 , 0.02397; #jobs/DFFX1_power_delay_9.sp.result1 
			model delay CK r QN r = 0.13800 0.00474  , 0.20748 , 0.04714; #jobs/DFFX1_power_delay_9.sp.result2 
			model delay CK r QN r = 0.13800 0.01011  , 0.25863 , 0.09540; #jobs/DFFX1_power_delay_9.sp.result3 
			model delay CK r QN r = 0.13800 0.02086  , 0.36120 , 0.19238; #jobs/DFFX1_power_delay_9.sp.result4 
			model delay CK r QN r = 0.26400 0.00079  , 0.18146 , 0.01407; #jobs/DFFX1_power_delay_10.sp.result0 
			model delay CK r QN r = 0.26400 0.00205  , 0.19298 , 0.02403; #jobs/DFFX1_power_delay_10.sp.result1 
			model delay CK r QN r = 0.26400 0.00474  , 0.21794 , 0.04716; #jobs/DFFX1_power_delay_10.sp.result2 
			model delay CK r QN r = 0.26400 0.01011  , 0.26902 , 0.09541; #jobs/DFFX1_power_delay_10.sp.result3 
			model dpower CK r Q f = 0.02800 0.00079  , 8.80507; #jobs/DFFX1_power_delay_6.sp.result0 
			model dpower CK r Q f = 0.02800 0.00205  , 10.64288; #jobs/DFFX1_power_delay_6.sp.result1 
			model dpower CK r Q f = 0.02800 0.00474  , 14.56360; #jobs/DFFX1_power_delay_6.sp.result2 
			model dpower CK r Q f = 0.02800 0.01011  , 22.35544; #jobs/DFFX1_power_delay_6.sp.result3 
			model dpower CK r Q f = 0.02800 0.02086  , 36.80862; #jobs/DFFX1_power_delay_6.sp.result4 
			model dpower CK r Q f = 0.04400 0.00079  , 8.79198; #jobs/DFFX1_power_delay_7.sp.result0 
			model dpower CK r Q f = 0.04400 0.00205  , 10.61821; #jobs/DFFX1_power_delay_7.sp.result1 
			model dpower CK r Q f = 0.04400 0.00474  , 14.54972; #jobs/DFFX1_power_delay_7.sp.result2 
			model dpower CK r Q f = 0.04400 0.01011  , 22.33717; #jobs/DFFX1_power_delay_7.sp.result3 
			model dpower CK r Q f = 0.04400 0.02086  , 36.56768; #jobs/DFFX1_power_delay_7.sp.result4 
			model dpower CK r Q f = 0.07600 0.00079  , 8.85066; #jobs/DFFX1_power_delay_8.sp.result0 
			model dpower CK r Q f = 0.07600 0.00205  , 10.67173; #jobs/DFFX1_power_delay_8.sp.result1 
			model dpower CK r Q f = 0.07600 0.00474  , 14.60242; #jobs/DFFX1_power_delay_8.sp.result2 
			model dpower CK r Q f = 0.07600 0.01011  , 22.38276; #jobs/DFFX1_power_delay_8.sp.result3 
			model dpower CK r Q f = 0.07600 0.02086  , 36.06885; #jobs/DFFX1_power_delay_8.sp.result4 
			model dpower CK r Q f = 0.13800 0.00079  , 9.08445; #jobs/DFFX1_power_delay_9.sp.result0 
			model dpower CK r Q f = 0.13800 0.00205  , 10.89966; #jobs/DFFX1_power_delay_9.sp.result1 
			model dpower CK r Q f = 0.13800 0.00474  , 14.82166; #jobs/DFFX1_power_delay_9.sp.result2 
			model dpower CK r Q f = 0.13800 0.01011  , 22.56743; #jobs/DFFX1_power_delay_9.sp.result3 
			model dpower CK r Q f = 0.13800 0.02086  , 34.72694; #jobs/DFFX1_power_delay_9.sp.result4 
			model dpower CK r Q f = 0.26400 0.00079  , 9.75980; #jobs/DFFX1_power_delay_10.sp.result0 
			model dpower CK r Q f = 0.26400 0.00205  , 11.55491; #jobs/DFFX1_power_delay_10.sp.result1 
			model dpower CK r Q f = 0.26400 0.00474  , 15.46261; #jobs/DFFX1_power_delay_10.sp.result2 
			model dpower CK r Q f = 0.26400 0.01011  , 22.61633; #jobs/DFFX1_power_delay_10.sp.result3 
			model dpower CK r Q f = 0.26400 0.02086  , 29.20656; #jobs/DFFX1_power_delay_10.sp.result4 
			model dpower CK r QN r = 0.02800 0.00079  , 8.80507; #jobs/DFFX1_power_delay_6.sp.result0 
			model dpower CK r QN r = 0.02800 0.00205  , 10.64288; #jobs/DFFX1_power_delay_6.sp.result1 
			model dpower CK r QN r = 0.02800 0.00474  , 14.56360; #jobs/DFFX1_power_delay_6.sp.result2 
			model dpower CK r QN r = 0.02800 0.01011  , 22.35544; #jobs/DFFX1_power_delay_6.sp.result3 
			model dpower CK r QN r = 0.02800 0.02086  , 36.80862; #jobs/DFFX1_power_delay_6.sp.result4 
			model dpower CK r QN r = 0.04400 0.00079  , 8.79198; #jobs/DFFX1_power_delay_7.sp.result0 
			model dpower CK r QN r = 0.04400 0.00205  , 10.61821; #jobs/DFFX1_power_delay_7.sp.result1 
			model dpower CK r QN r = 0.04400 0.00474  , 14.54972; #jobs/DFFX1_power_delay_7.sp.result2 
			model dpower CK r QN r = 0.04400 0.01011  , 22.33717; #jobs/DFFX1_power_delay_7.sp.result3 
			model dpower CK r QN r = 0.04400 0.02086  , 36.56768; #jobs/DFFX1_power_delay_7.sp.result4 
			model dpower CK r QN r = 0.07600 0.00079  , 8.85066; #jobs/DFFX1_power_delay_8.sp.result0 
			model dpower CK r QN r = 0.07600 0.00205  , 10.67173; #jobs/DFFX1_power_delay_8.sp.result1 
			model dpower CK r QN r = 0.07600 0.00474  , 14.60242; #jobs/DFFX1_power_delay_8.sp.result2 
			model dpower CK r QN r = 0.07600 0.01011  , 22.38276; #jobs/DFFX1_power_delay_8.sp.result3 
			model dpower CK r QN r = 0.07600 0.02086  , 36.06885; #jobs/DFFX1_power_delay_8.sp.result4 
			model dpower CK r QN r = 0.13800 0.00079  , 9.08445; #jobs/DFFX1_power_delay_9.sp.result0 
			model dpower CK r QN r = 0.13800 0.00205  , 10.89966; #jobs/DFFX1_power_delay_9.sp.result1 
			model dpower CK r QN r = 0.13800 0.00474  , 14.82166; #jobs/DFFX1_power_delay_9.sp.result2 
			model dpower CK r QN r = 0.13800 0.01011  , 22.56743; #jobs/DFFX1_power_delay_9.sp.result3 
			model dpower CK r QN r = 0.13800 0.02086  , 34.72694; #jobs/DFFX1_power_delay_9.sp.result4 
			model dpower CK r QN r = 0.26400 0.00079  , 9.75980; #jobs/DFFX1_power_delay_10.sp.result0 
			model dpower CK r QN r = 0.26400 0.00205  , 11.55491; #jobs/DFFX1_power_delay_10.sp.result1 
			model dpower CK r QN r = 0.26400 0.00474  , 15.46261; #jobs/DFFX1_power_delay_10.sp.result2 
			model dpower CK r QN r = 0.26400 0.01011  , 22.61633; #jobs/DFFX1_power_delay_10.sp.result3 
			model dpower CK r QN r = 0.26400 0.02086  , 29.20656; #jobs/DFFX1_power_delay_10.sp.result4 
			10 , 11 , 00 , 01 = fr ;
		ipower 
		simfeed v(ck)=0.0000000 v(dffx1:c)=0.0000025 v(dffx1:cn)=1.2000630 v(dffx1:hnet14)=0.4622942 v(dffx1:hnet16)=1.2000000 v(dffx1:hnet22)=1.1076530 v(dffx1:hnet24)=1.1999980 v(dffx1:hnet30)=0.9742206 v(dffx1:hnet32)=1.1997860 v(dffx1:hnet38)=0.3732018 v(dffx1:hnet40)=1.2000000 v(dffx1:m)=0.0000003 v(dffx1:net43)=1.1995760 v(d)=0.0000000 v(dffx1:pm)=1.1999970 v(dffx1:s)=0.0000251 v(q)=0.0000023 v(qn)=1.1999990 v(vdd)=1.2000000 v(vss)=0.0000000
			model ipower CK r = 0.02800  , 3.15118; #jobs/DFFX1_ipower_1.sp.result0 
			model ipower CK r = 0.04400  , 3.13483; #jobs/DFFX1_ipower_2.sp.result0 
			model ipower CK r = 0.07600  , 3.17932; #jobs/DFFX1_ipower_3.sp.result0 
			model ipower CK r = 0.13800  , 3.38289; #jobs/DFFX1_ipower_4.sp.result0 
			model ipower CK r = 0.26400  , 4.00962; #jobs/DFFX1_ipower_5.sp.result0 
			model ipower CK r = 0.51600  , 4.30517; #jobs/DFFX1_ipower_6.sp.result0 
			model ipower CK r = 1.02000  , 4.30517; #jobs/DFFX1_ipower_7.sp.result0 
			00 , 01 , 00 , 01 = -- ;
		ipower 
		simfeed v(ck)=1.2000000 v(dffx1:c)=1.2001520 v(dffx1:cn)=0.0000300 v(dffx1:hnet14)=0.9730170 v(dffx1:hnet16)=1.1998350 v(dffx1:hnet22)=0.4876870 v(dffx1:hnet24)=1.2000000 v(dffx1:hnet30)=-0.1424982 v(dffx1:hnet32)=1.1999990 v(dffx1:hnet38)=0.9796580 v(dffx1:hnet40)=1.1999040 v(dffx1:m)=0.0000607 v(dffx1:net43)=1.1996720 v(d)=0.0000000 v(dffx1:pm)=1.1998090 v(dffx1:s)=0.0000276 v(q)=0.0000015 v(qn)=1.1999990 v(vdd)=1.2000000 v(vss)=0.0000000
			model ipower CK f = 0.02800  , 3.15014; #jobs/DFFX1_ipower_8.sp.result0 
			model ipower CK f = 0.04400  , 3.17638; #jobs/DFFX1_ipower_9.sp.result0 
			model ipower CK f = 0.07600  , 3.30131; #jobs/DFFX1_ipower_10.sp.result0 
			model ipower CK f = 0.13800  , 3.59181; #jobs/DFFX1_ipower_11.sp.result0 
			model ipower CK f = 0.26400  , 4.28261; #jobs/DFFX1_ipower_12.sp.result0 
			model ipower CK f = 0.51600  , 4.60095; #jobs/DFFX1_ipower_13.sp.result0 
			model ipower CK f = 1.02000  , 4.60095; #jobs/DFFX1_ipower_14.sp.result0 
			00 , 01 , 00 = -- ;
		ipower 
			model ipower D r = 0.02800  , 2.75484; #jobs/DFFX1_ipower_15.sp.result0 
			model ipower D r = 0.04400  , 2.72296; #jobs/DFFX1_ipower_16.sp.result0 
			model ipower D r = 0.07600  , 2.72613; #jobs/DFFX1_ipower_17.sp.result0 
			model ipower D r = 0.13800  , 2.84521; #jobs/DFFX1_ipower_18.sp.result0 
			model ipower D r = 0.26400  , 3.26188; #jobs/DFFX1_ipower_19.sp.result0 
			model ipower D r = 0.51600  , 3.47787; #jobs/DFFX1_ipower_20.sp.result0 
			model ipower D r = 1.02000  , 3.47787; #jobs/DFFX1_ipower_21.sp.result0 
			00 , 10 = -- ;
		ipower 
			model ipower D f = 0.02800  , 3.97077; #jobs/DFFX1_ipower_22.sp.result0 
			model ipower D f = 0.04400  , 3.97255; #jobs/DFFX1_ipower_23.sp.result0 
			model ipower D f = 0.07600  , 4.00684; #jobs/DFFX1_ipower_24.sp.result0 
			model ipower D f = 0.13800  , 4.17207; #jobs/DFFX1_ipower_25.sp.result0 
			model ipower D f = 0.26400  , 4.64346; #jobs/DFFX1_ipower_26.sp.result0 
			model ipower D f = 0.51600  , 4.86495; #jobs/DFFX1_ipower_27.sp.result0 
			model ipower D f = 1.02000  , 4.86495; #jobs/DFFX1_ipower_28.sp.result0 
			10 , 00 = -- ;
		incap 
			model incap D r = 0.07600  , 0.01233; #jobs/DFFX1_incap_1.sp.result 
			model incap D f = 0.07600  , 0.01224; #jobs/DFFX1_incap_1.sp.result 
			model incap CK r = 0.07600  , 0.01281; #jobs/DFFX1_incap_1.sp.result 
			model incap CK f = 0.07600  , 0.01284; #jobs/DFFX1_incap_1.sp.result 
			00 , 10 = -- ;
		incap 
			00 , 01 = -- ;
		setup hold mpw 
		simfeed setup v(ck)=1.2000000 v(dffx1:c)=1.2001520 v(dffx1:cn)=0.0000300 v(dffx1:hnet14)=0.9730170 v(dffx1:hnet16)=1.1998350 v(dffx1:hnet22)=0.4876870 v(dffx1:hnet24)=1.2000000 v(dffx1:hnet30)=-0.1424982 v(dffx1:hnet32)=1.1999990 v(dffx1:hnet38)=0.9796580 v(dffx1:hnet40)=1.1999040 v(dffx1:m)=0.0000607 v(dffx1:net43)=1.1996720 v(d)=0.0000000 v(dffx1:pm)=1.1998090 v(dffx1:s)=0.0000276 v(q)=0.0000015 v(qn)=1.1999990 v(vdd)=1.2000000 v(vss)=0.0000000
		simfeed hold v(ck)=0.0000000 v(dffx1:c)=-0.0000484 v(dffx1:cn)=1.1997150 v(dffx1:hnet14)=0.0000011 v(dffx1:hnet16)=1.4285070 v(dffx1:hnet22)=0.0001969 v(dffx1:hnet24)=0.3567618 v(dffx1:hnet30)=0.9733627 v(dffx1:hnet32)=1.2001050 v(dffx1:hnet38)=0.0000006 v(dffx1:hnet40)=1.3620590 v(dffx1:m)=1.1996580 v(dffx1:net43)=1.2002100 v(d)=1.2000000 v(dffx1:pm)=0.0003926 v(dffx1:s)=0.0000233 v(q)=0.0000005 v(qn)=1.1999990 v(vdd)=1.2000000 v(vss)=0.0000000
			model setup D r CK r = 0.02800 0.02800  , 0.04705; #jobs/DFFX1_setup_1.sp.iteration jobs/DFFX1_setup_1.sp.iterations
			model setup D r CK r = 0.02800 0.02800  , 0.04705; #jobs/DFFX1_setup_1.sp.iteration jobs/DFFX1_setup_1.sp.iterations
			model setup D r CK r = 0.02800 0.26400  , 0.03738; #jobs/DFFX1_setup_2.sp.iteration jobs/DFFX1_setup_2.sp.iterations
			model setup D r CK r = 0.02800 0.26400  , 0.03738; #jobs/DFFX1_setup_2.sp.iteration jobs/DFFX1_setup_2.sp.iterations
			model setup D r CK r = 0.26400 0.02800  , 0.00085; #jobs/DFFX1_setup_3.sp.iteration jobs/DFFX1_setup_3.sp.iterations
			model setup D r CK r = 0.26400 0.02800  , 0.00085; #jobs/DFFX1_setup_3.sp.iteration jobs/DFFX1_setup_3.sp.iterations
			model setup D r CK r = 0.26400 0.26400  , 0.03773; #jobs/DFFX1_setup_4.sp.iteration jobs/DFFX1_setup_4.sp.iterations
			model setup D r CK r = 0.26400 0.26400  , 0.03773; #jobs/DFFX1_setup_4.sp.iteration jobs/DFFX1_setup_4.sp.iterations
			model hold D f CK r = 0.02800 0.02800  , -0.03279; #jobs/DFFX1_hold_1.sp.iteration jobs/DFFX1_hold_1.sp.iterations
			model hold D f CK r = 0.02800 0.02800  , -0.03279; #jobs/DFFX1_hold_1.sp.iteration jobs/DFFX1_hold_1.sp.iterations
			model hold D f CK r = 0.02800 0.26400  , 0; #jobs/DFFX1_hold_2.sp.iteration jobs/DFFX1_hold_2.sp.iterations
			model hold D f CK r = 0.02800 0.26400  , 0; #jobs/DFFX1_hold_2.sp.iteration jobs/DFFX1_hold_2.sp.iterations
			model hold D f CK r = 0.26400 0.02800  , 0; #jobs/DFFX1_hold_3.sp.iteration jobs/DFFX1_hold_3.sp.iterations
			model hold D f CK r = 0.26400 0.02800  , 0; #jobs/DFFX1_hold_3.sp.iteration jobs/DFFX1_hold_3.sp.iterations
			model hold D f CK r = 0.26400 0.26400  , -0.07930; #jobs/DFFX1_hold_4.sp.iteration jobs/DFFX1_hold_4.sp.iterations
			model hold D f CK r = 0.26400 0.26400  , -0.07930; #jobs/DFFX1_hold_4.sp.iteration jobs/DFFX1_hold_4.sp.iterations
			model mpw CK r = 0.26400  , 0.10555; # jobs/DFFX1_mpw_1.sp.result
			00 , 01 , 00 , 11 = rf ;
		setup hold mpw 
		simfeed setup v(ck)=1.2000000 v(dffx1:c)=1.1999970 v(dffx1:cn)=-0.0001167 v(dffx1:hnet14)=0.0000878 v(dffx1:hnet16)=0.3550378 v(dffx1:hnet22)=0.0000001 v(dffx1:hnet24)=0.8095952 v(dffx1:hnet30)=0.0000001 v(dffx1:hnet32)=0.7155777 v(dffx1:hnet38)=0.0000704 v(dffx1:hnet40)=0.3471633 v(dffx1:m)=1.1997800 v(dffx1:net43)=0.0001750 v(d)=1.2000000 v(dffx1:pm)=0.0001403 v(dffx1:s)=1.1999980 v(q)=1.1999980 v(qn)=0.0000006 v(vdd)=1.2000000 v(vss)=0.0000000
		simfeed hold v(ck)=0.0000000 v(dffx1:c)=0.0000777 v(dffx1:cn)=1.2000650 v(dffx1:hnet14)=-0.1708871 v(dffx1:hnet16)=1.1999980 v(dffx1:hnet22)=0.9727797 v(dffx1:hnet24)=1.1997660 v(dffx1:hnet30)=-0.0000499 v(dffx1:hnet32)=0.1881151 v(dffx1:hnet38)=-0.1487851 v(dffx1:hnet40)=1.1999990 v(dffx1:m)=0.0000772 v(dffx1:net43)=-0.0000995 v(d)=0.0000000 v(dffx1:pm)=1.1995360 v(dffx1:s)=1.2000000 v(q)=1.2000000 v(qn)=0.0000006 v(vdd)=1.2000000 v(vss)=0.0000000
			model setup D f CK r = 0.02800 0.02800  , 0.05418; #jobs/DFFX1_setup_5.sp.iteration jobs/DFFX1_setup_5.sp.iterations
			model setup D f CK r = 0.02800 0.02800  , 0.05418; #jobs/DFFX1_setup_5.sp.iteration jobs/DFFX1_setup_5.sp.iterations
			model setup D f CK r = 0.02800 0.26400  , 0.00085; #jobs/DFFX1_setup_6.sp.iteration jobs/DFFX1_setup_6.sp.iterations
			model setup D f CK r = 0.02800 0.26400  , 0.00085; #jobs/DFFX1_setup_6.sp.iteration jobs/DFFX1_setup_6.sp.iterations
			model setup D f CK r = 0.26400 0.02800  , 0.00085; #jobs/DFFX1_setup_7.sp.iteration jobs/DFFX1_setup_7.sp.iterations
			model setup D f CK r = 0.26400 0.02800  , 0.00085; #jobs/DFFX1_setup_7.sp.iteration jobs/DFFX1_setup_7.sp.iterations
			model setup D f CK r = 0.26400 0.26400  , 0.08367; #jobs/DFFX1_setup_8.sp.iteration jobs/DFFX1_setup_8.sp.iterations
			model setup D f CK r = 0.26400 0.26400  , 0.08367; #jobs/DFFX1_setup_8.sp.iteration jobs/DFFX1_setup_8.sp.iterations
			model hold D r CK r = 0.02800 0.02800  , -0.02638; #jobs/DFFX1_hold_5.sp.iteration jobs/DFFX1_hold_5.sp.iterations
			model hold D r CK r = 0.02800 0.02800  , -0.02638; #jobs/DFFX1_hold_5.sp.iteration jobs/DFFX1_hold_5.sp.iterations
			model hold D r CK r = 0.02800 0.26400  , -0.03144; #jobs/DFFX1_hold_6.sp.iteration jobs/DFFX1_hold_6.sp.iterations
			model hold D r CK r = 0.02800 0.26400  , -0.03144; #jobs/DFFX1_hold_6.sp.iteration jobs/DFFX1_hold_6.sp.iterations
			model hold D r CK r = 0.26400 0.02800  , 0; #jobs/DFFX1_hold_7.sp.iteration jobs/DFFX1_hold_7.sp.iterations
			model hold D r CK r = 0.26400 0.02800  , 0; #jobs/DFFX1_hold_7.sp.iteration jobs/DFFX1_hold_7.sp.iterations
			model hold D r CK r = 0.26400 0.26400  , -0.03227; #jobs/DFFX1_hold_8.sp.iteration jobs/DFFX1_hold_8.sp.iterations
			model hold D r CK r = 0.26400 0.26400  , -0.03227; #jobs/DFFX1_hold_8.sp.iteration jobs/DFFX1_hold_8.sp.iterations
			10 , 11 , 10 , 01 = fr ;
		lpower 
			model lpower 00 = 0  , 0.11013; #jobs/DFFX1_lpower_1.sp.result 
			model lpower 01 = 0  , 0.04999; #jobs/DFFX1_lpower_1.sp.result 
			model lpower 10 = 0  , 0.12728; #jobs/DFFX1_lpower_1.sp.result 
			model lpower 11 = 0  , 0.07936; #jobs/DFFX1_lpower_1.sp.result 
			00 , 01 , 10 , 11 = -- ;
	end_table
end_cdf
