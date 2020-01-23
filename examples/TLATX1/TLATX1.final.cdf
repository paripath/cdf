cdf TLATX1
	table TLATX1
		inputs D;
		clocks G;
		outputs Q , QN;
		function
			latch(IQ, IQN) {
				enable : G
				data_in : D
			}
			Q = IQ
			QN = IQN
		end_function
		delay dpower 
		simfeed v(d)=1.2000000 v(g)=0.0000000 v(q)=0.0000005 v(qn)=1.1999990 v(tlatx1:cn)=1.1999570 v(tlatx1:c)=0.0000005 v(tlatx1:hnet12)=0.0000004 v(tlatx1:hnet14)=1.3826370 v(tlatx1:hnet20)=1.0093900 v(tlatx1:hnet22)=1.2000390 v(tlatx1:m)=0.0000068 v(tlatx1:pm)=1.2000780 v(vdd)=1.2000000 v(vss)=0.0000000
			model delay G r Q r = 0.02800 0.00079  , 0.10495 , 0.01167; #jobs/TLATX1_delay_1.sp.result0 
			model delay G r Q r = 0.02800 0.00205  , 0.11358 , 0.01745; #jobs/TLATX1_delay_1.sp.result1 
			model delay G r Q r = 0.02800 0.00474  , 0.12923 , 0.02944; #jobs/TLATX1_delay_1.sp.result2 
			model delay G r Q r = 0.02800 0.01011  , 0.15787 , 0.05443; #jobs/TLATX1_delay_1.sp.result3 
			model delay G r Q r = 0.02800 0.02086  , 0.21346 , 0.10541; #jobs/TLATX1_delay_1.sp.result4 
			model delay G r Q r = 0.04400 0.00079  , 0.11008 , 0.01168; #jobs/TLATX1_delay_2.sp.result0 
			model delay G r Q r = 0.04400 0.00205  , 0.11871 , 0.01746; #jobs/TLATX1_delay_2.sp.result1 
			model delay G r Q r = 0.04400 0.00474  , 0.13436 , 0.02945; #jobs/TLATX1_delay_2.sp.result2 
			model delay G r Q r = 0.04400 0.01011  , 0.16300 , 0.05442; #jobs/TLATX1_delay_2.sp.result3 
			model delay G r Q r = 0.04400 0.02086  , 0.21859 , 0.10541; #jobs/TLATX1_delay_2.sp.result4 
			model delay G r Q r = 0.07600 0.00079  , 0.11650 , 0.01162; #jobs/TLATX1_delay_3.sp.result0 
			model delay G r Q r = 0.07600 0.00205  , 0.12515 , 0.01747; #jobs/TLATX1_delay_3.sp.result1 
			model delay G r Q r = 0.07600 0.00474  , 0.14080 , 0.02943; #jobs/TLATX1_delay_3.sp.result2 
			model delay G r Q r = 0.07600 0.01011  , 0.16945 , 0.05443; #jobs/TLATX1_delay_3.sp.result3 
			model delay G r Q r = 0.07600 0.02086  , 0.22503 , 0.10541; #jobs/TLATX1_delay_3.sp.result4 
			model delay G r Q r = 0.13800 0.00079  , 0.12301 , 0.01167; #jobs/TLATX1_delay_4.sp.result0 
			model delay G r Q r = 0.13800 0.00205  , 0.13166 , 0.01746; #jobs/TLATX1_delay_4.sp.result1 
			model delay G r Q r = 0.13800 0.00474  , 0.14732 , 0.02945; #jobs/TLATX1_delay_4.sp.result2 
			model delay G r Q r = 0.13800 0.01011  , 0.17598 , 0.05442; #jobs/TLATX1_delay_4.sp.result3 
			model delay G r Q r = 0.13800 0.02086  , 0.23156 , 0.10541; #jobs/TLATX1_delay_4.sp.result4 
			model delay G r Q r = 0.26400 0.00079  , 0.12682 , 0.01172; #jobs/TLATX1_delay_5.sp.result0 
			model delay G r Q r = 0.26400 0.00205  , 0.13546 , 0.01750; #jobs/TLATX1_delay_5.sp.result1 
			model delay G r Q r = 0.26400 0.00474  , 0.15115 , 0.02947; #jobs/TLATX1_delay_5.sp.result2 
			model delay G r Q r = 0.26400 0.01011  , 0.17983 , 0.05442; #jobs/TLATX1_delay_5.sp.result3 
			model delay G r Q r = 0.26400 0.02086  , 0.23541 , 0.10541; #jobs/TLATX1_delay_5.sp.result4 
			model delay G r QN f = 0.02800 0.00079  , 0.16191 , 0.01305; #jobs/TLATX1_delay_1.sp.result0 
			model delay G r QN f = 0.02800 0.00205  , 0.16984 , 0.01699; #jobs/TLATX1_delay_1.sp.result1 
			model delay G r QN f = 0.02800 0.00474  , 0.18274 , 0.02399; #jobs/TLATX1_delay_1.sp.result2 
			model delay G r QN f = 0.02800 0.01011  , 0.20365 , 0.03726; #jobs/TLATX1_delay_1.sp.result3 
			model delay G r QN f = 0.02800 0.02086  , 0.24074 , 0.06525; #jobs/TLATX1_delay_1.sp.result4 
			model delay G r QN f = 0.04400 0.00079  , 0.16704 , 0.01306; #jobs/TLATX1_delay_2.sp.result0 
			model delay G r QN f = 0.04400 0.00205  , 0.17497 , 0.01699; #jobs/TLATX1_delay_2.sp.result1 
			model delay G r QN f = 0.04400 0.00474  , 0.18787 , 0.02399; #jobs/TLATX1_delay_2.sp.result2 
			model delay G r QN f = 0.04400 0.01011  , 0.20878 , 0.03726; #jobs/TLATX1_delay_2.sp.result3 
			model delay G r QN f = 0.04400 0.02086  , 0.24587 , 0.06525; #jobs/TLATX1_delay_2.sp.result4 
			model delay G r QN f = 0.07600 0.00079  , 0.17349 , 0.01301; #jobs/TLATX1_delay_3.sp.result0 
			model delay G r QN f = 0.07600 0.00205  , 0.18142 , 0.01701; #jobs/TLATX1_delay_3.sp.result1 
			model delay G r QN f = 0.07600 0.00474  , 0.19432 , 0.02397; #jobs/TLATX1_delay_3.sp.result2 
			model delay G r QN f = 0.07600 0.01011  , 0.21524 , 0.03724; #jobs/TLATX1_delay_3.sp.result3 
			model delay G r QN f = 0.07600 0.02086  , 0.25232 , 0.06524; #jobs/TLATX1_delay_3.sp.result4 
			model delay G r QN f = 0.13800 0.00079  , 0.18004 , 0.01304; #jobs/TLATX1_delay_4.sp.result0 
			model delay G r QN f = 0.13800 0.00205  , 0.18795 , 0.01701; #jobs/TLATX1_delay_4.sp.result1 
			model delay G r QN f = 0.13800 0.00474  , 0.20085 , 0.02397; #jobs/TLATX1_delay_4.sp.result2 
			model delay G r QN f = 0.13800 0.01011  , 0.22176 , 0.03724; #jobs/TLATX1_delay_4.sp.result3 
			model delay G r QN f = 0.13800 0.02086  , 0.25885 , 0.06524; #jobs/TLATX1_delay_4.sp.result4 
			model delay G r QN f = 0.26400 0.00079  , 0.18389 , 0.01306; #jobs/TLATX1_delay_5.sp.result0 
			model delay G r QN f = 0.26400 0.00205  , 0.19181 , 0.01700; #jobs/TLATX1_delay_5.sp.result1 
			model delay G r QN f = 0.26400 0.00474  , 0.20471 , 0.02395; #jobs/TLATX1_delay_5.sp.result2 
			model delay G r QN f = 0.26400 0.01011  , 0.22562 , 0.03726; #jobs/TLATX1_delay_5.sp.result3 
			model delay G r QN f = 0.26400 0.02086  , 0.26270 , 0.06524; #jobs/TLATX1_delay_5.sp.result4 
			model dpower G r Q r QN f = 0.02800 0.00079 0.00079  , 11.16803; #jobs/TLATX1_power_1.sp.result0 
			model dpower G r Q r QN f = 0.02800 0.00079 0.01011  , 11.09754; #jobs/TLATX1_power_1.sp.result1 
			model dpower G r Q r QN f = 0.02800 0.01011 0.00079  , 24.61088; #jobs/TLATX1_power_1.sp.result2 
			model dpower G r Q r QN f = 0.02800 0.01011 0.01011  , 24.57500; #jobs/TLATX1_power_1.sp.result3 
			model dpower G r Q r QN f = 0.04400 0.00079 0.00079  , 11.14262; #jobs/TLATX1_power_2.sp.result0 
			model dpower G r Q r QN f = 0.04400 0.00079 0.01011  , 11.10541; #jobs/TLATX1_power_2.sp.result1 
			model dpower G r Q r QN f = 0.04400 0.01011 0.00079  , 24.60763; #jobs/TLATX1_power_2.sp.result2 
			model dpower G r Q r QN f = 0.04400 0.01011 0.01011  , 24.59024; #jobs/TLATX1_power_2.sp.result3 
			model dpower G r Q r QN f = 0.07600 0.00079 0.00079  , 11.23574; #jobs/TLATX1_power_3.sp.result0 
			model dpower G r Q r QN f = 0.07600 0.00079 0.01011  , 11.19243; #jobs/TLATX1_power_3.sp.result1 
			model dpower G r Q r QN f = 0.07600 0.01011 0.00079  , 24.70347; #jobs/TLATX1_power_3.sp.result2 
			model dpower G r Q r QN f = 0.07600 0.01011 0.01011  , 24.65870; #jobs/TLATX1_power_3.sp.result3 
			model dpower G r Q r QN f = 0.13800 0.00079 0.00079  , 11.56039; #jobs/TLATX1_power_4.sp.result0 
			model dpower G r Q r QN f = 0.13800 0.00079 0.01011  , 11.51204; #jobs/TLATX1_power_4.sp.result1 
			model dpower G r Q r QN f = 0.13800 0.01011 0.00079  , 25.02999; #jobs/TLATX1_power_4.sp.result2 
			model dpower G r Q r QN f = 0.13800 0.01011 0.01011  , 24.98494; #jobs/TLATX1_power_4.sp.result3 
			model dpower G r Q r QN f = 0.26400 0.00079 0.00079  , 12.43408; #jobs/TLATX1_power_5.sp.result0 
			model dpower G r Q r QN f = 0.26400 0.00079 0.01011  , 12.38196; #jobs/TLATX1_power_5.sp.result1 
			model dpower G r Q r QN f = 0.26400 0.01011 0.00079  , 25.89808; #jobs/TLATX1_power_5.sp.result2 
			model dpower G r Q r QN f = 0.26400 0.01011 0.01011  , 25.85227; #jobs/TLATX1_power_5.sp.result3 
			00 , 01 , 00 , 10 , 11 = rf ;
		delay dpower 
		simfeed v(d)=0.0000000 v(g)=0.0000000 v(q)=1.1999990 v(qn)=0.0000007 v(tlatx1:cn)=1.1999990 v(tlatx1:c)=0.0000045 v(tlatx1:hnet12)=-0.1298808 v(tlatx1:hnet14)=1.1999990 v(tlatx1:hnet20)=0.0000072 v(tlatx1:hnet22)=0.3147303 v(tlatx1:m)=1.1999740 v(tlatx1:pm)=0.0000145 v(vdd)=1.2000000 v(vss)=0.0000000
			model delay G r Q f = 0.02800 0.00079  , 0.08694 , 0.01104; #jobs/TLATX1_delay_6.sp.result0 
			model delay G r Q f = 0.02800 0.00205  , 0.09554 , 0.01514; #jobs/TLATX1_delay_6.sp.result1 
			model delay G r Q f = 0.02800 0.00474  , 0.10950 , 0.02235; #jobs/TLATX1_delay_6.sp.result2 
			model delay G r Q f = 0.02800 0.01011  , 0.13099 , 0.03523; #jobs/TLATX1_delay_6.sp.result3 
			model delay G r Q f = 0.02800 0.02086  , 0.16706 , 0.06043; #jobs/TLATX1_delay_6.sp.result4 
			model delay G r Q f = 0.04400 0.00079  , 0.09213 , 0.01104; #jobs/TLATX1_delay_7.sp.result0 
			model delay G r Q f = 0.04400 0.00205  , 0.10071 , 0.01514; #jobs/TLATX1_delay_7.sp.result1 
			model delay G r Q f = 0.04400 0.00474  , 0.11465 , 0.02235; #jobs/TLATX1_delay_7.sp.result2 
			model delay G r Q f = 0.04400 0.01011  , 0.13614 , 0.03521; #jobs/TLATX1_delay_7.sp.result3 
			model delay G r Q f = 0.04400 0.02086  , 0.17221 , 0.06043; #jobs/TLATX1_delay_7.sp.result4 
			model delay G r Q f = 0.07600 0.00079  , 0.09888 , 0.01114; #jobs/TLATX1_delay_8.sp.result0 
			model delay G r Q f = 0.07600 0.00205  , 0.10745 , 0.01526; #jobs/TLATX1_delay_8.sp.result1 
			model delay G r Q f = 0.07600 0.00474  , 0.12141 , 0.02242; #jobs/TLATX1_delay_8.sp.result2 
			model delay G r Q f = 0.07600 0.01011  , 0.14292 , 0.03526; #jobs/TLATX1_delay_8.sp.result3 
			model delay G r Q f = 0.07600 0.02086  , 0.17901 , 0.06044; #jobs/TLATX1_delay_8.sp.result4 
			model delay G r Q f = 0.13800 0.00079  , 0.10569 , 0.01130; #jobs/TLATX1_delay_9.sp.result0 
			model delay G r Q f = 0.13800 0.00205  , 0.11426 , 0.01542; #jobs/TLATX1_delay_9.sp.result1 
			model delay G r Q f = 0.13800 0.00474  , 0.12824 , 0.02257; #jobs/TLATX1_delay_9.sp.result2 
			model delay G r Q f = 0.13800 0.01011  , 0.14982 , 0.03539; #jobs/TLATX1_delay_9.sp.result3 
			model delay G r Q f = 0.13800 0.02086  , 0.18599 , 0.06055; #jobs/TLATX1_delay_9.sp.result4 
			model delay G r Q f = 0.26400 0.00079  , 0.10991 , 0.01183; #jobs/TLATX1_delay_10.sp.result0 
			model delay G r Q f = 0.26400 0.00205  , 0.11857 , 0.01596; #jobs/TLATX1_delay_10.sp.result1 
			model delay G r Q f = 0.26400 0.00474  , 0.13270 , 0.02305; #jobs/TLATX1_delay_10.sp.result2 
			model delay G r Q f = 0.26400 0.01011  , 0.15449 , 0.03577; #jobs/TLATX1_delay_10.sp.result3 
			model delay G r Q f = 0.26400 0.02086  , 0.19084 , 0.06076; #jobs/TLATX1_delay_10.sp.result4 
			model delay G r QN r = 0.02800 0.00079  , 0.14439 , 0.01324; #jobs/TLATX1_delay_6.sp.result0 
			model delay G r QN r = 0.02800 0.00205  , 0.15171 , 0.01875; #jobs/TLATX1_delay_6.sp.result1 
			model delay G r QN r = 0.02800 0.00474  , 0.16482 , 0.03011; #jobs/TLATX1_delay_6.sp.result2 
			model delay G r QN r = 0.02800 0.01011  , 0.19099 , 0.05443; #jobs/TLATX1_delay_6.sp.result3 
			model delay G r QN r = 0.02800 0.02086  , 0.24487 , 0.10551; #jobs/TLATX1_delay_6.sp.result4 
			model delay G r QN r = 0.04400 0.00079  , 0.14953 , 0.01325; #jobs/TLATX1_delay_7.sp.result0 
			model delay G r QN r = 0.04400 0.00205  , 0.15686 , 0.01872; #jobs/TLATX1_delay_7.sp.result1 
			model delay G r QN r = 0.04400 0.00474  , 0.16997 , 0.03011; #jobs/TLATX1_delay_7.sp.result2 
			model delay G r QN r = 0.04400 0.01011  , 0.19613 , 0.05443; #jobs/TLATX1_delay_7.sp.result3 
			model delay G r QN r = 0.04400 0.02086  , 0.25000 , 0.10551; #jobs/TLATX1_delay_7.sp.result4 
			model delay G r QN r = 0.07600 0.00079  , 0.15636 , 0.01325; #jobs/TLATX1_delay_8.sp.result0 
			model delay G r QN r = 0.07600 0.00205  , 0.16367 , 0.01876; #jobs/TLATX1_delay_8.sp.result1 
			model delay G r QN r = 0.07600 0.00474  , 0.17676 , 0.03011; #jobs/TLATX1_delay_8.sp.result2 
			model delay G r QN r = 0.07600 0.01011  , 0.20290 , 0.05443; #jobs/TLATX1_delay_8.sp.result3 
			model delay G r QN r = 0.07600 0.02086  , 0.25676 , 0.10552; #jobs/TLATX1_delay_8.sp.result4 
			model delay G r QN r = 0.13800 0.00079  , 0.16333 , 0.01324; #jobs/TLATX1_delay_9.sp.result0 
			model delay G r QN r = 0.13800 0.00205  , 0.17064 , 0.01877; #jobs/TLATX1_delay_9.sp.result1 
			model delay G r QN r = 0.13800 0.00474  , 0.18368 , 0.03014; #jobs/TLATX1_delay_9.sp.result2 
			model delay G r QN r = 0.13800 0.01011  , 0.20978 , 0.05444; #jobs/TLATX1_delay_9.sp.result3 
			model delay G r QN r = 0.13800 0.02086  , 0.26362 , 0.10551; #jobs/TLATX1_delay_9.sp.result4 
			model delay G r QN r = 0.26400 0.00079  , 0.16821 , 0.01332; #jobs/TLATX1_delay_10.sp.result0 
			model delay G r QN r = 0.26400 0.00205  , 0.17546 , 0.01883; #jobs/TLATX1_delay_10.sp.result1 
			model delay G r QN r = 0.26400 0.00474  , 0.18841 , 0.03017; #jobs/TLATX1_delay_10.sp.result2 
			model delay G r QN r = 0.26400 0.01011  , 0.21441 , 0.05446; #jobs/TLATX1_delay_10.sp.result3 
			model delay G r QN r = 0.26400 0.02086  , 0.26818 , 0.10552; #jobs/TLATX1_delay_10.sp.result4 
			model dpower G r Q f QN r = 0.02800 0.00079 0.00079  , 11.75535; #jobs/TLATX1_power_6.sp.result0 
			model dpower G r Q f QN r = 0.02800 0.00079 0.01011  , 25.15519; #jobs/TLATX1_power_6.sp.result1 
			model dpower G r Q f QN r = 0.02800 0.01011 0.00079  , 11.71828; #jobs/TLATX1_power_6.sp.result2 
			model dpower G r Q f QN r = 0.02800 0.01011 0.01011  , 25.15582; #jobs/TLATX1_power_6.sp.result3 
			model dpower G r Q f QN r = 0.04400 0.00079 0.00079  , 11.73320; #jobs/TLATX1_power_7.sp.result0 
			model dpower G r Q f QN r = 0.04400 0.00079 0.01011  , 25.13017; #jobs/TLATX1_power_7.sp.result1 
			model dpower G r Q f QN r = 0.04400 0.01011 0.00079  , 11.66781; #jobs/TLATX1_power_7.sp.result2 
			model dpower G r Q f QN r = 0.04400 0.01011 0.01011  , 25.11776; #jobs/TLATX1_power_7.sp.result3 
			model dpower G r Q f QN r = 0.07600 0.00079 0.00079  , 11.73095; #jobs/TLATX1_power_8.sp.result0 
			model dpower G r Q f QN r = 0.07600 0.00079 0.01011  , 25.15893; #jobs/TLATX1_power_8.sp.result1 
			model dpower G r Q f QN r = 0.07600 0.01011 0.00079  , 11.72747; #jobs/TLATX1_power_8.sp.result2 
			model dpower G r Q f QN r = 0.07600 0.01011 0.01011  , 25.17585; #jobs/TLATX1_power_8.sp.result3 
			model dpower G r Q f QN r = 0.13800 0.00079 0.00079  , 12.04710; #jobs/TLATX1_power_9.sp.result0 
			model dpower G r Q f QN r = 0.13800 0.00079 0.01011  , 25.47208; #jobs/TLATX1_power_9.sp.result1 
			model dpower G r Q f QN r = 0.13800 0.01011 0.00079  , 12.01914; #jobs/TLATX1_power_9.sp.result2 
			model dpower G r Q f QN r = 0.13800 0.01011 0.01011  , 25.46448; #jobs/TLATX1_power_9.sp.result3 
			model dpower G r Q f QN r = 0.26400 0.00079 0.00079  , 12.98990; #jobs/TLATX1_power_10.sp.result0 
			model dpower G r Q f QN r = 0.26400 0.00079 0.01011  , 26.36936; #jobs/TLATX1_power_10.sp.result1 
			model dpower G r Q f QN r = 0.26400 0.01011 0.00079  , 12.89368; #jobs/TLATX1_power_10.sp.result2 
			model dpower G r Q f QN r = 0.26400 0.01011 0.01011  , 26.30687; #jobs/TLATX1_power_10.sp.result3 
			10 , 11 , 10 , 00 , 01 = fr ;
		delay dpower 
		simfeed v(d)=0.0000000 v(g)=1.2000000 v(q)=0.0000006 v(qn)=1.1999990 v(tlatx1:cn)=0.0000006 v(tlatx1:c)=1.1999990 v(tlatx1:hnet12)=1.1090110 v(tlatx1:hnet14)=1.1999990 v(tlatx1:hnet20)=0.0439852 v(tlatx1:hnet22)=1.2000000 v(tlatx1:m)=0.0000006 v(tlatx1:pm)=1.1999980 v(vdd)=1.2000000 v(vss)=0.0000000
			model delay D r Q r = 0.02800 0.00079  , 0.06023 , 0.01157; #jobs/TLATX1_delay_11.sp.result0 
			model delay D r Q r = 0.02800 0.00205  , 0.06889 , 0.01736; #jobs/TLATX1_delay_11.sp.result1 
			model delay D r Q r = 0.02800 0.00474  , 0.08463 , 0.02939; #jobs/TLATX1_delay_11.sp.result2 
			model delay D r Q r = 0.02800 0.01011  , 0.11344 , 0.05440; #jobs/TLATX1_delay_11.sp.result3 
			model delay D r Q r = 0.02800 0.02086  , 0.16911 , 0.10539; #jobs/TLATX1_delay_11.sp.result4 
			model delay D r Q r = 0.04400 0.00079  , 0.06295 , 0.01179; #jobs/TLATX1_delay_12.sp.result0 
			model delay D r Q r = 0.04400 0.00205  , 0.07162 , 0.01752; #jobs/TLATX1_delay_12.sp.result1 
			model delay D r Q r = 0.04400 0.00474  , 0.08735 , 0.02949; #jobs/TLATX1_delay_12.sp.result2 
			model delay D r Q r = 0.04400 0.01011  , 0.11612 , 0.05444; #jobs/TLATX1_delay_12.sp.result3 
			model delay D r Q r = 0.04400 0.02086  , 0.17178 , 0.10541; #jobs/TLATX1_delay_12.sp.result4 
			model delay D r Q r = 0.07600 0.00079  , 0.06726 , 0.01247; #jobs/TLATX1_delay_13.sp.result0 
			model delay D r Q r = 0.07600 0.00205  , 0.07618 , 0.01827; #jobs/TLATX1_delay_13.sp.result1 
			model delay D r Q r = 0.07600 0.00474  , 0.09214 , 0.03013; #jobs/TLATX1_delay_13.sp.result2 
			model delay D r Q r = 0.07600 0.01011  , 0.12103 , 0.05475; #jobs/TLATX1_delay_13.sp.result3 
			model delay D r Q r = 0.07600 0.02086  , 0.17668 , 0.10549; #jobs/TLATX1_delay_13.sp.result4 
			model delay D r Q r = 0.13800 0.00079  , 0.07211 , 0.01356; #jobs/TLATX1_delay_14.sp.result0 
			model delay D r Q r = 0.13800 0.00205  , 0.08134 , 0.01947; #jobs/TLATX1_delay_14.sp.result1 
			model delay D r Q r = 0.13800 0.00474  , 0.09762 , 0.03111; #jobs/TLATX1_delay_14.sp.result2 
			model delay D r Q r = 0.13800 0.01011  , 0.12665 , 0.05549; #jobs/TLATX1_delay_14.sp.result3 
			model delay D r Q r = 0.13800 0.02086  , 0.18250 , 0.10599; #jobs/TLATX1_delay_14.sp.result4 
			model delay D r Q r = 0.26400 0.00079  , 0.07366 , 0.01571; #jobs/TLATX1_delay_15.sp.result0 
			model delay D r Q r = 0.26400 0.00205  , 0.08347 , 0.02178; #jobs/TLATX1_delay_15.sp.result1 
			model delay D r Q r = 0.26400 0.00474  , 0.10052 , 0.03333; #jobs/TLATX1_delay_15.sp.result2 
			model delay D r Q r = 0.26400 0.01011  , 0.13009 , 0.05704; #jobs/TLATX1_delay_15.sp.result3 
			model delay D r Q r = 0.26400 0.02086  , 0.18601 , 0.10684; #jobs/TLATX1_delay_15.sp.result4 
			model delay D r QN f = 0.02800 0.00079  , 0.11671 , 0.01295; #jobs/TLATX1_delay_11.sp.result0 
			model delay D r QN f = 0.02800 0.00205  , 0.12464 , 0.01692; #jobs/TLATX1_delay_11.sp.result1 
			model delay D r QN f = 0.02800 0.00474  , 0.13755 , 0.02394; #jobs/TLATX1_delay_11.sp.result2 
			model delay D r QN f = 0.02800 0.01011  , 0.15847 , 0.03723; #jobs/TLATX1_delay_11.sp.result3 
			model delay D r QN f = 0.02800 0.02086  , 0.19557 , 0.06524; #jobs/TLATX1_delay_11.sp.result4 
			model delay D r QN f = 0.04400 0.00079  , 0.11944 , 0.01294; #jobs/TLATX1_delay_12.sp.result0 
			model delay D r QN f = 0.04400 0.00205  , 0.12736 , 0.01697; #jobs/TLATX1_delay_12.sp.result1 
			model delay D r QN f = 0.04400 0.00474  , 0.14026 , 0.02394; #jobs/TLATX1_delay_12.sp.result2 
			model delay D r QN f = 0.04400 0.01011  , 0.16118 , 0.03723; #jobs/TLATX1_delay_12.sp.result3 
			model delay D r QN f = 0.04400 0.02086  , 0.19827 , 0.06524; #jobs/TLATX1_delay_12.sp.result4 
			model delay D r QN f = 0.07600 0.00079  , 0.12463 , 0.01303; #jobs/TLATX1_delay_13.sp.result0 
			model delay D r QN f = 0.07600 0.00205  , 0.13243 , 0.01704; #jobs/TLATX1_delay_13.sp.result1 
			model delay D r QN f = 0.07600 0.00474  , 0.14525 , 0.02399; #jobs/TLATX1_delay_13.sp.result2 
			model delay D r QN f = 0.07600 0.01011  , 0.16612 , 0.03727; #jobs/TLATX1_delay_13.sp.result3 
			model delay D r QN f = 0.07600 0.02086  , 0.20319 , 0.06525; #jobs/TLATX1_delay_13.sp.result4 
			model delay D r QN f = 0.13800 0.00079  , 0.13086 , 0.01319; #jobs/TLATX1_delay_14.sp.result0 
			model delay D r QN f = 0.13800 0.00205  , 0.13848 , 0.01721; #jobs/TLATX1_delay_14.sp.result1 
			model delay D r QN f = 0.13800 0.00474  , 0.15112 , 0.02417; #jobs/TLATX1_delay_14.sp.result2 
			model delay D r QN f = 0.13800 0.01011  , 0.17186 , 0.03737; #jobs/TLATX1_delay_14.sp.result3 
			model delay D r QN f = 0.13800 0.02086  , 0.20886 , 0.06530; #jobs/TLATX1_delay_14.sp.result4 
			model delay D r QN f = 0.26400 0.00079  , 0.13537 , 0.01358; #jobs/TLATX1_delay_15.sp.result0 
			model delay D r QN f = 0.26400 0.00205  , 0.14263 , 0.01755; #jobs/TLATX1_delay_15.sp.result1 
			model delay D r QN f = 0.26400 0.00474  , 0.15493 , 0.02447; #jobs/TLATX1_delay_15.sp.result2 
			model delay D r QN f = 0.26400 0.01011  , 0.17545 , 0.03756; #jobs/TLATX1_delay_15.sp.result3 
			model delay D r QN f = 0.26400 0.02086  , 0.21228 , 0.06538; #jobs/TLATX1_delay_15.sp.result4 
			model dpower D r Q r QN f = 0.02800 0.00079 0.00079  , 9.22731; #jobs/TLATX1_power_11.sp.result0 
			model dpower D r Q r QN f = 0.02800 0.00079 0.01011  , 9.18412; #jobs/TLATX1_power_11.sp.result1 
			model dpower D r Q r QN f = 0.02800 0.01011 0.00079  , 22.75204; #jobs/TLATX1_power_11.sp.result2 
			model dpower D r Q r QN f = 0.02800 0.01011 0.01011  , 22.71003; #jobs/TLATX1_power_11.sp.result3 
			model dpower D r Q r QN f = 0.04400 0.00079 0.00079  , 9.16215; #jobs/TLATX1_power_12.sp.result0 
			model dpower D r Q r QN f = 0.04400 0.00079 0.01011  , 9.09644; #jobs/TLATX1_power_12.sp.result1 
			model dpower D r Q r QN f = 0.04400 0.01011 0.00079  , 22.64363; #jobs/TLATX1_power_12.sp.result2 
			model dpower D r Q r QN f = 0.04400 0.01011 0.01011  , 22.59327; #jobs/TLATX1_power_12.sp.result3 
			model dpower D r Q r QN f = 0.07600 0.00079 0.00079  , 9.18062; #jobs/TLATX1_power_13.sp.result0 
			model dpower D r Q r QN f = 0.07600 0.00079 0.01011  , 9.13249; #jobs/TLATX1_power_13.sp.result1 
			model dpower D r Q r QN f = 0.07600 0.01011 0.00079  , 22.60810; #jobs/TLATX1_power_13.sp.result2 
			model dpower D r Q r QN f = 0.07600 0.01011 0.01011  , 22.56155; #jobs/TLATX1_power_13.sp.result3 
			model dpower D r Q r QN f = 0.13800 0.00079 0.00079  , 9.61382; #jobs/TLATX1_power_14.sp.result0 
			model dpower D r Q r QN f = 0.13800 0.00079 0.01011  , 9.54688; #jobs/TLATX1_power_14.sp.result1 
			model dpower D r Q r QN f = 0.13800 0.01011 0.00079  , 22.92812; #jobs/TLATX1_power_14.sp.result2 
			model dpower D r Q r QN f = 0.13800 0.01011 0.01011  , 22.86704; #jobs/TLATX1_power_14.sp.result3 
			model dpower D r Q r QN f = 0.26400 0.00079 0.00079  , 11.12973; #jobs/TLATX1_power_15.sp.result0 
			model dpower D r Q r QN f = 0.26400 0.00079 0.01011  , 10.96041; #jobs/TLATX1_power_15.sp.result1 
			model dpower D r Q r QN f = 0.26400 0.01011 0.00079  , 24.15008; #jobs/TLATX1_power_15.sp.result2 
			model dpower D r Q r QN f = 0.26400 0.01011 0.01011  , 24.05847; #jobs/TLATX1_power_15.sp.result3 
			01 , 01 , 11 = rf ;
		delay dpower 
		simfeed v(d)=1.2000000 v(g)=1.2000000 v(q)=1.1999990 v(qn)=0.0000006 v(tlatx1:cn)=0.0000006 v(tlatx1:c)=1.1999990 v(tlatx1:hnet12)=0.0000004 v(tlatx1:hnet14)=0.1869549 v(tlatx1:hnet20)=0.0000000 v(tlatx1:hnet22)=1.1111800 v(tlatx1:m)=1.1999990 v(tlatx1:pm)=0.0000008 v(vdd)=1.2000000 v(vss)=0.0000000
			model delay D f Q f = 0.02800 0.00079  , 0.08418 , 0.01195; #jobs/TLATX1_delay_16.sp.result0 
			model delay D f Q f = 0.02800 0.00205  , 0.09301 , 0.01599; #jobs/TLATX1_delay_16.sp.result1 
			model delay D f Q f = 0.02800 0.00474  , 0.10731 , 0.02309; #jobs/TLATX1_delay_16.sp.result2 
			model delay D f Q f = 0.02800 0.01011  , 0.12914 , 0.03566; #jobs/TLATX1_delay_16.sp.result3 
			model delay D f Q f = 0.02800 0.02086  , 0.16536 , 0.06056; #jobs/TLATX1_delay_16.sp.result4 
			model delay D f Q f = 0.04400 0.00079  , 0.09019 , 0.01197; #jobs/TLATX1_delay_17.sp.result0 
			model delay D f Q f = 0.04400 0.00205  , 0.09899 , 0.01602; #jobs/TLATX1_delay_17.sp.result1 
			model delay D f Q f = 0.04400 0.00474  , 0.11327 , 0.02311; #jobs/TLATX1_delay_17.sp.result2 
			model delay D f Q f = 0.04400 0.01011  , 0.13510 , 0.03567; #jobs/TLATX1_delay_17.sp.result3 
			model delay D f Q f = 0.04400 0.02086  , 0.17133 , 0.06056; #jobs/TLATX1_delay_17.sp.result4 
			model delay D f Q f = 0.07600 0.00079  , 0.10212 , 0.01264; #jobs/TLATX1_delay_18.sp.result0 
			model delay D f Q f = 0.07600 0.00205  , 0.11096 , 0.01651; #jobs/TLATX1_delay_18.sp.result1 
			model delay D f Q f = 0.07600 0.00474  , 0.12529 , 0.02344; #jobs/TLATX1_delay_18.sp.result2 
			model delay D f Q f = 0.07600 0.01011  , 0.14719 , 0.03585; #jobs/TLATX1_delay_18.sp.result3 
			model delay D f Q f = 0.07600 0.02086  , 0.18346 , 0.06064; #jobs/TLATX1_delay_18.sp.result4 
			model delay D f Q f = 0.13800 0.00079  , 0.12213 , 0.01425; #jobs/TLATX1_delay_19.sp.result0 
			model delay D f Q f = 0.13800 0.00205  , 0.13153 , 0.01831; #jobs/TLATX1_delay_19.sp.result1 
			model delay D f Q f = 0.13800 0.00474  , 0.14677 , 0.02533; #jobs/TLATX1_delay_19.sp.result2 
			model delay D f Q f = 0.13800 0.01011  , 0.16970 , 0.03744; #jobs/TLATX1_delay_19.sp.result3 
			model delay D f Q f = 0.13800 0.02086  , 0.20662 , 0.06137; #jobs/TLATX1_delay_19.sp.result4 
			model delay D f Q f = 0.26400 0.00079  , 0.16037 , 0.01665; #jobs/TLATX1_delay_20.sp.result0 
			model delay D f Q f = 0.26400 0.00205  , 0.17046 , 0.02085; #jobs/TLATX1_delay_20.sp.result1 
			model delay D f Q f = 0.26400 0.00474  , 0.18682 , 0.02807; #jobs/TLATX1_delay_20.sp.result2 
			model delay D f Q f = 0.26400 0.01011  , 0.21125 , 0.04011; #jobs/TLATX1_delay_20.sp.result3 
			model delay D f Q f = 0.26400 0.02086  , 0.24963 , 0.06352; #jobs/TLATX1_delay_20.sp.result4 
			model delay D f QN r = 0.02800 0.00079  , 0.14177 , 0.01324; #jobs/TLATX1_delay_16.sp.result0 
			model delay D f QN r = 0.02800 0.00205  , 0.14903 , 0.01878; #jobs/TLATX1_delay_16.sp.result1 
			model delay D f QN r = 0.02800 0.00474  , 0.16205 , 0.03016; #jobs/TLATX1_delay_16.sp.result2 
			model delay D f QN r = 0.02800 0.01011  , 0.18816 , 0.05445; #jobs/TLATX1_delay_16.sp.result3 
			model delay D f QN r = 0.02800 0.02086  , 0.24201 , 0.10551; #jobs/TLATX1_delay_16.sp.result4 
			model delay D f QN r = 0.04400 0.00079  , 0.14774 , 0.01330; #jobs/TLATX1_delay_17.sp.result0 
			model delay D f QN r = 0.04400 0.00205  , 0.15500 , 0.01878; #jobs/TLATX1_delay_17.sp.result1 
			model delay D f QN r = 0.04400 0.00474  , 0.16803 , 0.03016; #jobs/TLATX1_delay_17.sp.result2 
			model delay D f QN r = 0.04400 0.01011  , 0.19412 , 0.05445; #jobs/TLATX1_delay_17.sp.result3 
			model delay D f QN r = 0.04400 0.02086  , 0.24797 , 0.10551; #jobs/TLATX1_delay_17.sp.result4 
			model delay D f QN r = 0.07600 0.00079  , 0.15996 , 0.01328; #jobs/TLATX1_delay_18.sp.result0 
			model delay D f QN r = 0.07600 0.00205  , 0.16719 , 0.01882; #jobs/TLATX1_delay_18.sp.result1 
			model delay D f QN r = 0.07600 0.00474  , 0.18017 , 0.03018; #jobs/TLATX1_delay_18.sp.result2 
			model delay D f QN r = 0.07600 0.01011  , 0.20622 , 0.05445; #jobs/TLATX1_delay_18.sp.result3 
			model delay D f QN r = 0.07600 0.02086  , 0.26003 , 0.10551; #jobs/TLATX1_delay_18.sp.result4 
			model delay D f QN r = 0.13800 0.00079  , 0.18304 , 0.01356; #jobs/TLATX1_delay_19.sp.result0 
			model delay D f QN r = 0.13800 0.00205  , 0.19010 , 0.01908; #jobs/TLATX1_delay_19.sp.result1 
			model delay D f QN r = 0.13800 0.00474  , 0.20280 , 0.03035; #jobs/TLATX1_delay_19.sp.result2 
			model delay D f QN r = 0.13800 0.01011  , 0.22856 , 0.05451; #jobs/TLATX1_delay_19.sp.result3 
			model delay D f QN r = 0.13800 0.02086  , 0.28217 , 0.10553; #jobs/TLATX1_delay_19.sp.result4 
			model delay D f QN r = 0.26400 0.00079  , 0.22560 , 0.01396; #jobs/TLATX1_delay_20.sp.result0 
			model delay D f QN r = 0.26400 0.00205  , 0.23242 , 0.01950; #jobs/TLATX1_delay_20.sp.result1 
			model delay D f QN r = 0.26400 0.00474  , 0.24469 , 0.03068; #jobs/TLATX1_delay_20.sp.result2 
			model delay D f QN r = 0.26400 0.01011  , 0.26998 , 0.05464; #jobs/TLATX1_delay_20.sp.result3 
			model delay D f QN r = 0.26400 0.02086  , 0.32328 , 0.10557; #jobs/TLATX1_delay_20.sp.result4 
			model dpower D f Q f QN r = 0.02800 0.00079 0.00079  , 11.99830; #jobs/TLATX1_power_16.sp.result0 
			model dpower D f Q f QN r = 0.02800 0.00079 0.01011  , 25.40409; #jobs/TLATX1_power_16.sp.result1 
			model dpower D f Q f QN r = 0.02800 0.01011 0.00079  , 11.90916; #jobs/TLATX1_power_16.sp.result2 
			model dpower D f Q f QN r = 0.02800 0.01011 0.01011  , 25.35092; #jobs/TLATX1_power_16.sp.result3 
			model dpower D f Q f QN r = 0.04400 0.00079 0.00079  , 11.97253; #jobs/TLATX1_power_17.sp.result0 
			model dpower D f Q f QN r = 0.04400 0.00079 0.01011  , 25.38967; #jobs/TLATX1_power_17.sp.result1 
			model dpower D f Q f QN r = 0.04400 0.01011 0.00079  , 11.90355; #jobs/TLATX1_power_17.sp.result2 
			model dpower D f Q f QN r = 0.04400 0.01011 0.01011  , 25.32833; #jobs/TLATX1_power_17.sp.result3 
			model dpower D f Q f QN r = 0.07600 0.00079 0.00079  , 12.12274; #jobs/TLATX1_power_18.sp.result0 
			model dpower D f Q f QN r = 0.07600 0.00079 0.01011  , 25.53336; #jobs/TLATX1_power_18.sp.result1 
			model dpower D f Q f QN r = 0.07600 0.01011 0.00079  , 11.98058; #jobs/TLATX1_power_18.sp.result2 
			model dpower D f Q f QN r = 0.07600 0.01011 0.01011  , 25.41120; #jobs/TLATX1_power_18.sp.result3 
			model dpower D f Q f QN r = 0.13800 0.00079 0.00079  , 12.71758; #jobs/TLATX1_power_19.sp.result0 
			model dpower D f Q f QN r = 0.13800 0.00079 0.01011  , 26.10159; #jobs/TLATX1_power_19.sp.result1 
			model dpower D f Q f QN r = 0.13800 0.01011 0.00079  , 12.44291; #jobs/TLATX1_power_19.sp.result2 
			model dpower D f Q f QN r = 0.13800 0.01011 0.01011  , 25.84654; #jobs/TLATX1_power_19.sp.result3 
			model dpower D f Q f QN r = 0.26400 0.00079 0.00079  , 14.29688; #jobs/TLATX1_power_20.sp.result0 
			model dpower D f Q f QN r = 0.26400 0.00079 0.01011  , 27.55363; #jobs/TLATX1_power_20.sp.result1 
			model dpower D f Q f QN r = 0.26400 0.01011 0.00079  , 13.81529; #jobs/TLATX1_power_20.sp.result2 
			model dpower D f Q f QN r = 0.26400 0.01011 0.01011  , 27.10883; #jobs/TLATX1_power_20.sp.result3 
			11 , 11 , 01 = fr ;
		ipower 
		simfeed v(d)=0.0000000 v(g)=0.0000000 v(q)=0.0000015 v(qn)=1.1999990 v(tlatx1:cn)=1.2000420 v(tlatx1:c)=0.0000022 v(tlatx1:hnet12)=0.4630701 v(tlatx1:hnet14)=1.2000000 v(tlatx1:hnet20)=0.9761847 v(tlatx1:hnet22)=1.1998720 v(tlatx1:m)=0.0000217 v(tlatx1:pm)=1.1997470 v(vdd)=1.2000000 v(vss)=0.0000000
			model ipower G r = 0.02800  , 3.15051; #jobs/TLATX1_ipower_1.sp.result0 
			model ipower G r = 0.04400  , 3.13064; #jobs/TLATX1_ipower_2.sp.result0 
			model ipower G r = 0.07600  , 3.20177; #jobs/TLATX1_ipower_3.sp.result0 
			model ipower G r = 0.13800  , 3.54315; #jobs/TLATX1_ipower_4.sp.result0 
			model ipower G r = 0.26400  , 4.41605; #jobs/TLATX1_ipower_5.sp.result0 
			00 , 01 , 00 , 01 = -- ;
		ipower 
		simfeed v(d)=0.0000000 v(g)=1.2000000 v(q)=0.0000012 v(qn)=1.1999990 v(tlatx1:cn)=0.0000203 v(tlatx1:c)=1.2001420 v(tlatx1:hnet12)=0.9750561 v(tlatx1:hnet14)=1.1998630 v(tlatx1:hnet20)=-0.1409034 v(tlatx1:hnet22)=1.1999990 v(tlatx1:m)=0.0000248 v(tlatx1:pm)=1.1997270 v(vdd)=1.2000000 v(vss)=0.0000000
			model ipower G f = 0.02800  , 3.11512; #jobs/TLATX1_ipower_6.sp.result0 
			model ipower G f = 0.04400  , 3.13348; #jobs/TLATX1_ipower_7.sp.result0 
			model ipower G f = 0.07600  , 3.30740; #jobs/TLATX1_ipower_8.sp.result0 
			model ipower G f = 0.13800  , 3.72198; #jobs/TLATX1_ipower_9.sp.result0 
			model ipower G f = 0.26400  , 4.66894; #jobs/TLATX1_ipower_10.sp.result0 
			00 , 01 , 00 = -- ;
		ipower 
			model ipower D r = 0.02800  , 1.58926; #jobs/TLATX1_ipower_11.sp.result0 
			model ipower D r = 0.04400  , 1.59055; #jobs/TLATX1_ipower_12.sp.result0 
			model ipower D r = 0.07600  , 1.59097; #jobs/TLATX1_ipower_13.sp.result0 
			model ipower D r = 0.13800  , 1.58940; #jobs/TLATX1_ipower_14.sp.result0 
			model ipower D r = 0.26400  , 1.58294; #jobs/TLATX1_ipower_15.sp.result0 
			00 , 10 = -- ;
		ipower 
			model ipower D f = 0.02800  , 1.70571; #jobs/TLATX1_ipower_16.sp.result0 
			model ipower D f = 0.04400  , 1.69080; #jobs/TLATX1_ipower_17.sp.result0 
			model ipower D f = 0.07600  , 1.67869; #jobs/TLATX1_ipower_18.sp.result0 
			model ipower D f = 0.13800  , 1.66961; #jobs/TLATX1_ipower_19.sp.result0 
			model ipower D f = 0.26400  , 1.66147; #jobs/TLATX1_ipower_20.sp.result0 
			10 , 00 = -- ;
		incap 
			model incap D r = 0.07600  , 0.02965; #jobs/TLATX1_incap_1.sp.result 
			model incap D f = 0.07600  , 0.02929; #jobs/TLATX1_incap_1.sp.result 
			model incap G r = 0.07600  , 0.01763; #jobs/TLATX1_incap_1.sp.result 
			model incap G f = 0.07600  , 0.01758; #jobs/TLATX1_incap_1.sp.result 
			00 , 10 = -- ;
		incap 
			00 , 01 = -- ;
		setup hold 
		simfeed setup v(d)=0.0000000 v(g)=0.0000000 v(q)=0.0000015 v(qn)=1.1999990 v(tlatx1:cn)=1.2000420 v(tlatx1:c)=0.0000021 v(tlatx1:hnet12)=0.5822921 v(tlatx1:hnet14)=1.2000000 v(tlatx1:hnet20)=0.9762297 v(tlatx1:hnet22)=1.1998730 v(tlatx1:m)=0.0000216 v(tlatx1:pm)=1.1997490 v(vdd)=1.2000000 v(vss)=0.0000000
		simfeed hold v(d)=1.2000000 v(g)=1.2000000 v(q)=1.1999970 v(qn)=0.0000011 v(tlatx1:cn)=-0.0001016 v(tlatx1:c)=1.1998680 v(tlatx1:hnet12)=0.0001404 v(tlatx1:hnet14)=0.3610118 v(tlatx1:hnet20)=0.0000003 v(tlatx1:hnet22)=1.3601650 v(tlatx1:m)=1.1998740 v(tlatx1:pm)=0.0002801 v(vdd)=1.2000000 v(vss)=0.0000000
			model setup D r G f = 0.02800 0.02800  , 0.00998; #jobs/TLATX1_setup_1.sp.iteration jobs/TLATX1_setup_1.sp.iterations
			model setup D r G f = 0.02800 0.02800  , 0.00998; #jobs/TLATX1_setup_1.sp.iteration jobs/TLATX1_setup_1.sp.iterations
			model setup D r G f = 0.02800 0.26400  , 0.00085; #jobs/TLATX1_setup_2.sp.iteration jobs/TLATX1_setup_2.sp.iterations
			model setup D r G f = 0.02800 0.26400  , 0.00085; #jobs/TLATX1_setup_2.sp.iteration jobs/TLATX1_setup_2.sp.iterations
			model setup D r G f = 0.26400 0.02800  , 0.00085; #jobs/TLATX1_setup_3.sp.iteration jobs/TLATX1_setup_3.sp.iterations
			model setup D r G f = 0.26400 0.02800  , 0.00085; #jobs/TLATX1_setup_3.sp.iteration jobs/TLATX1_setup_3.sp.iterations
			model setup D r G f = 0.26400 0.26400  , -0.08258; #jobs/TLATX1_setup_4.sp.iteration jobs/TLATX1_setup_4.sp.iterations
			model setup D r G f = 0.26400 0.26400  , -0.08258; #jobs/TLATX1_setup_4.sp.iteration jobs/TLATX1_setup_4.sp.iterations
			model hold D f G f = 0.02800 0.02800  , -0.04349; #jobs/TLATX1_hold_1.sp.iteration jobs/TLATX1_hold_1.sp.iterations
			model hold D f G f = 0.02800 0.02800  , -0.04349; #jobs/TLATX1_hold_1.sp.iteration jobs/TLATX1_hold_1.sp.iterations
			model hold D f G f = 0.02800 0.26400  , -0.01614; #jobs/TLATX1_hold_2.sp.iteration jobs/TLATX1_hold_2.sp.iterations
			model hold D f G f = 0.02800 0.26400  , -0.01614; #jobs/TLATX1_hold_2.sp.iteration jobs/TLATX1_hold_2.sp.iterations
			model hold D f G f = 0.26400 0.02800  , 0; #jobs/TLATX1_hold_3.sp.iteration jobs/TLATX1_hold_3.sp.iterations
			model hold D f G f = 0.26400 0.02800  , 0; #jobs/TLATX1_hold_3.sp.iteration jobs/TLATX1_hold_3.sp.iterations
			model hold D f G f = 0.26400 0.26400  , -0.07547; #jobs/TLATX1_hold_4.sp.iteration jobs/TLATX1_hold_4.sp.iterations
			model hold D f G f = 0.26400 0.26400  , -0.07547; #jobs/TLATX1_hold_4.sp.iteration jobs/TLATX1_hold_4.sp.iterations
			01 , 00 , 01 , 10 = rf ;
		setup hold 
		simfeed setup v(d)=1.2000000 v(g)=0.0000000 v(q)=1.1999980 v(qn)=0.0000008 v(tlatx1:cn)=1.1999980 v(tlatx1:c)=-0.0000388 v(tlatx1:hnet12)=0.0000000 v(tlatx1:hnet14)=0.7145731 v(tlatx1:hnet20)=0.0000776 v(tlatx1:hnet22)=0.3492335 v(tlatx1:m)=1.1999270 v(tlatx1:pm)=0.0001549 v(vdd)=1.2000000 v(vss)=0.0000000
		simfeed hold v(d)=0.0000000 v(g)=1.2000000 v(q)=0.0000014 v(qn)=1.1999990 v(tlatx1:cn)=0.0000219 v(tlatx1:c)=1.2001620 v(tlatx1:hnet12)=0.9712000 v(tlatx1:hnet14)=1.1998450 v(tlatx1:hnet20)=-0.1430034 v(tlatx1:hnet22)=1.1999990 v(tlatx1:m)=0.0000266 v(tlatx1:pm)=1.1996910 v(vdd)=1.2000000 v(vss)=0.0000000
			model setup D f G f = 0.02800 0.02800  , 0.05917; #jobs/TLATX1_setup_5.sp.iteration jobs/TLATX1_setup_5.sp.iterations
			model setup D f G f = 0.02800 0.02800  , 0.05917; #jobs/TLATX1_setup_5.sp.iteration jobs/TLATX1_setup_5.sp.iterations
			model setup D f G f = 0.02800 0.26400  , 0.03313; #jobs/TLATX1_setup_6.sp.iteration jobs/TLATX1_setup_6.sp.iterations
			model setup D f G f = 0.02800 0.26400  , 0.03313; #jobs/TLATX1_setup_6.sp.iteration jobs/TLATX1_setup_6.sp.iterations
			model setup D f G f = 0.26400 0.02800  , 0.00085; #jobs/TLATX1_setup_7.sp.iteration jobs/TLATX1_setup_7.sp.iterations
			model setup D f G f = 0.26400 0.02800  , 0.00085; #jobs/TLATX1_setup_7.sp.iteration jobs/TLATX1_setup_7.sp.iterations
			model setup D f G f = 0.26400 0.26400  , 0.09898; #jobs/TLATX1_setup_8.sp.iteration jobs/TLATX1_setup_8.sp.iterations
			model setup D f G f = 0.26400 0.26400  , 0.09898; #jobs/TLATX1_setup_8.sp.iteration jobs/TLATX1_setup_8.sp.iterations
			model hold D r G f = 0.02800 0.02800  , 0.01426; #jobs/TLATX1_hold_5.sp.iteration jobs/TLATX1_hold_5.sp.iterations
			model hold D r G f = 0.02800 0.02800  , 0.01426; #jobs/TLATX1_hold_5.sp.iteration jobs/TLATX1_hold_5.sp.iterations
			model hold D r G f = 0.02800 0.26400  , 0; #jobs/TLATX1_hold_6.sp.iteration jobs/TLATX1_hold_6.sp.iterations
			model hold D r G f = 0.02800 0.26400  , 0; #jobs/TLATX1_hold_6.sp.iteration jobs/TLATX1_hold_6.sp.iterations
			model hold D r G f = 0.26400 0.02800  , 0.00170; #jobs/TLATX1_hold_7.sp.iteration jobs/TLATX1_hold_7.sp.iterations
			model hold D r G f = 0.26400 0.02800  , 0.00170; #jobs/TLATX1_hold_7.sp.iteration jobs/TLATX1_hold_7.sp.iterations
			model hold D r G f = 0.26400 0.26400  , 0.10008; #jobs/TLATX1_hold_8.sp.iteration jobs/TLATX1_hold_8.sp.iterations
			model hold D r G f = 0.26400 0.26400  , 0.10008; #jobs/TLATX1_hold_8.sp.iteration jobs/TLATX1_hold_8.sp.iterations
			11 , 10 , 11 , 00 = fr ;
		mpw 
		simfeed v(d)=0.0000000 v(g)=0.0000000 v(q)=0.0000015 v(qn)=1.1999990 v(tlatx1:cn)=1.2000420 v(tlatx1:c)=0.0000022 v(tlatx1:hnet12)=0.4630701 v(tlatx1:hnet14)=1.2000000 v(tlatx1:hnet20)=0.9761847 v(tlatx1:hnet22)=1.1998720 v(tlatx1:m)=0.0000217 v(tlatx1:pm)=1.1997470 v(vdd)=1.2000000 v(vss)=0.0000000
			model mpw G r = 0.26400  , 0.05141; # jobs/TLATX1_mpw_1.sp.result
			00 , 01 , 00 , 11 = rf ;
		mpw 
		simfeed v(d)=1.2000000 v(g)=0.0000000 v(q)=1.1999980 v(qn)=0.0000009 v(tlatx1:cn)=1.1999980 v(tlatx1:c)=-0.0000427 v(tlatx1:hnet12)=0.0000000 v(tlatx1:hnet14)=0.8715662 v(tlatx1:hnet20)=0.0000857 v(tlatx1:hnet22)=0.3523619 v(tlatx1:m)=1.1999190 v(tlatx1:pm)=0.0001709 v(vdd)=1.2000000 v(vss)=0.0000000
			10 , 11 , 10 , 01 = fr ;
		lpower 
			model lpower 00 = 0  , 0.03476; #jobs/TLATX1_lpower_1.sp.result 
			model lpower 01 = 0  , 0.02907; #jobs/TLATX1_lpower_1.sp.result 
			model lpower 10 = 0  , 0.02194; #jobs/TLATX1_lpower_1.sp.result 
			model lpower 11 = 0  , 0.10890; #jobs/TLATX1_lpower_1.sp.result 
			00 , 01 , 10 , 11 = -- ;
	end_table
end_cdf
