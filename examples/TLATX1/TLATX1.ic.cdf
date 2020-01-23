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
			00 , 01 , 00 , 10 , 11 = rf ;
		delay dpower 
		simfeed v(d)=0.0000000 v(g)=0.0000000 v(q)=1.1999990 v(qn)=0.0000007 v(tlatx1:cn)=1.1999990 v(tlatx1:c)=0.0000045 v(tlatx1:hnet12)=-0.1298808 v(tlatx1:hnet14)=1.1999990 v(tlatx1:hnet20)=0.0000072 v(tlatx1:hnet22)=0.3147303 v(tlatx1:m)=1.1999740 v(tlatx1:pm)=0.0000145 v(vdd)=1.2000000 v(vss)=0.0000000
			10 , 11 , 10 , 00 , 01 = fr ;
		delay dpower 
		simfeed v(d)=0.0000000 v(g)=1.2000000 v(q)=0.0000006 v(qn)=1.1999990 v(tlatx1:cn)=0.0000006 v(tlatx1:c)=1.1999990 v(tlatx1:hnet12)=1.1090110 v(tlatx1:hnet14)=1.1999990 v(tlatx1:hnet20)=0.0439852 v(tlatx1:hnet22)=1.2000000 v(tlatx1:m)=0.0000006 v(tlatx1:pm)=1.1999980 v(vdd)=1.2000000 v(vss)=0.0000000
			01 , 01 , 11 = rf ;
		delay dpower 
		simfeed v(d)=1.2000000 v(g)=1.2000000 v(q)=1.1999990 v(qn)=0.0000006 v(tlatx1:cn)=0.0000006 v(tlatx1:c)=1.1999990 v(tlatx1:hnet12)=0.0000004 v(tlatx1:hnet14)=0.1869549 v(tlatx1:hnet20)=0.0000000 v(tlatx1:hnet22)=1.1111800 v(tlatx1:m)=1.1999990 v(tlatx1:pm)=0.0000008 v(vdd)=1.2000000 v(vss)=0.0000000
			11 , 11 , 01 = fr ;
		ipower 
		simfeed v(d)=0.0000000 v(g)=0.0000000 v(q)=0.0000015 v(qn)=1.1999990 v(tlatx1:cn)=1.2000420 v(tlatx1:c)=0.0000022 v(tlatx1:hnet12)=0.4630701 v(tlatx1:hnet14)=1.2000000 v(tlatx1:hnet20)=0.9761847 v(tlatx1:hnet22)=1.1998720 v(tlatx1:m)=0.0000217 v(tlatx1:pm)=1.1997470 v(vdd)=1.2000000 v(vss)=0.0000000
			00 , 01 , 00 , 01 = -- ;
		ipower 
		simfeed v(d)=0.0000000 v(g)=1.2000000 v(q)=0.0000012 v(qn)=1.1999990 v(tlatx1:cn)=0.0000203 v(tlatx1:c)=1.2001420 v(tlatx1:hnet12)=0.9750561 v(tlatx1:hnet14)=1.1998630 v(tlatx1:hnet20)=-0.1409034 v(tlatx1:hnet22)=1.1999990 v(tlatx1:m)=0.0000248 v(tlatx1:pm)=1.1997270 v(vdd)=1.2000000 v(vss)=0.0000000
			00 , 01 , 00 = -- ;
		ipower 
			00 , 10 = -- ;
		ipower 
			10 , 00 = -- ;
		incap 
			00 , 10 = -- ;
		incap 
			00 , 01 = -- ;
		setup hold 
		simfeed setup v(d)=0.0000000 v(g)=0.0000000 v(q)=0.0000015 v(qn)=1.1999990 v(tlatx1:cn)=1.2000420 v(tlatx1:c)=0.0000021 v(tlatx1:hnet12)=0.5822921 v(tlatx1:hnet14)=1.2000000 v(tlatx1:hnet20)=0.9762297 v(tlatx1:hnet22)=1.1998730 v(tlatx1:m)=0.0000216 v(tlatx1:pm)=1.1997490 v(vdd)=1.2000000 v(vss)=0.0000000
		simfeed hold v(d)=1.2000000 v(g)=1.2000000 v(q)=1.1999970 v(qn)=0.0000011 v(tlatx1:cn)=-0.0001016 v(tlatx1:c)=1.1998680 v(tlatx1:hnet12)=0.0001404 v(tlatx1:hnet14)=0.3610118 v(tlatx1:hnet20)=0.0000003 v(tlatx1:hnet22)=1.3601650 v(tlatx1:m)=1.1998740 v(tlatx1:pm)=0.0002801 v(vdd)=1.2000000 v(vss)=0.0000000
			01 , 00 , 01 , 10 = rf ;
		setup hold 
		simfeed setup v(d)=1.2000000 v(g)=0.0000000 v(q)=1.1999980 v(qn)=0.0000008 v(tlatx1:cn)=1.1999980 v(tlatx1:c)=-0.0000388 v(tlatx1:hnet12)=0.0000000 v(tlatx1:hnet14)=0.7145731 v(tlatx1:hnet20)=0.0000776 v(tlatx1:hnet22)=0.3492335 v(tlatx1:m)=1.1999270 v(tlatx1:pm)=0.0001549 v(vdd)=1.2000000 v(vss)=0.0000000
		simfeed hold v(d)=0.0000000 v(g)=1.2000000 v(q)=0.0000014 v(qn)=1.1999990 v(tlatx1:cn)=0.0000219 v(tlatx1:c)=1.2001620 v(tlatx1:hnet12)=0.9712000 v(tlatx1:hnet14)=1.1998450 v(tlatx1:hnet20)=-0.1430034 v(tlatx1:hnet22)=1.1999990 v(tlatx1:m)=0.0000266 v(tlatx1:pm)=1.1996910 v(vdd)=1.2000000 v(vss)=0.0000000
			11 , 10 , 11 , 00 = fr ;
		mpw 
		simfeed v(d)=0.0000000 v(g)=0.0000000 v(q)=0.0000015 v(qn)=1.1999990 v(tlatx1:cn)=1.2000420 v(tlatx1:c)=0.0000022 v(tlatx1:hnet12)=0.4630701 v(tlatx1:hnet14)=1.2000000 v(tlatx1:hnet20)=0.9761847 v(tlatx1:hnet22)=1.1998720 v(tlatx1:m)=0.0000217 v(tlatx1:pm)=1.1997470 v(vdd)=1.2000000 v(vss)=0.0000000
			00 , 01 , 00 , 11 = rf ;
		mpw 
		simfeed v(d)=1.2000000 v(g)=0.0000000 v(q)=1.1999980 v(qn)=0.0000009 v(tlatx1:cn)=1.1999980 v(tlatx1:c)=-0.0000427 v(tlatx1:hnet12)=0.0000000 v(tlatx1:hnet14)=0.8715662 v(tlatx1:hnet20)=0.0000857 v(tlatx1:hnet22)=0.3523619 v(tlatx1:m)=1.1999190 v(tlatx1:pm)=0.0001709 v(vdd)=1.2000000 v(vss)=0.0000000
			10 , 11 , 10 , 01 = fr ;
		lpower 
			00 , 01 , 10 , 11 = -- ;
	end_table
end_cdf
