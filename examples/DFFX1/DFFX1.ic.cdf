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
			00 , 01 , 10 , 11 = rf ;
		delay dpower 
		simfeed v(ck)=0.0000000 v(dffx1:c)=0.0000777 v(dffx1:cn)=1.2000650 v(dffx1:hnet14)=-0.1708871 v(dffx1:hnet16)=1.1999980 v(dffx1:hnet22)=0.9727797 v(dffx1:hnet24)=1.1997660 v(dffx1:hnet30)=-0.0000499 v(dffx1:hnet32)=0.1881151 v(dffx1:hnet38)=-0.1487851 v(dffx1:hnet40)=1.1999990 v(dffx1:m)=0.0000772 v(dffx1:net43)=-0.0000995 v(d)=0.0000000 v(dffx1:pm)=1.1995360 v(dffx1:s)=1.2000000 v(q)=1.2000000 v(qn)=0.0000006 v(vdd)=1.2000000 v(vss)=0.0000000
			10 , 11 , 00 , 01 = fr ;
		ipower 
		simfeed v(ck)=0.0000000 v(dffx1:c)=0.0000025 v(dffx1:cn)=1.2000630 v(dffx1:hnet14)=0.4622942 v(dffx1:hnet16)=1.2000000 v(dffx1:hnet22)=1.1076530 v(dffx1:hnet24)=1.1999980 v(dffx1:hnet30)=0.9742206 v(dffx1:hnet32)=1.1997860 v(dffx1:hnet38)=0.3732018 v(dffx1:hnet40)=1.2000000 v(dffx1:m)=0.0000003 v(dffx1:net43)=1.1995760 v(d)=0.0000000 v(dffx1:pm)=1.1999970 v(dffx1:s)=0.0000251 v(q)=0.0000023 v(qn)=1.1999990 v(vdd)=1.2000000 v(vss)=0.0000000
			00 , 01 , 00 , 01 = -- ;
		ipower 
		simfeed v(ck)=1.2000000 v(dffx1:c)=1.2001520 v(dffx1:cn)=0.0000300 v(dffx1:hnet14)=0.9730170 v(dffx1:hnet16)=1.1998350 v(dffx1:hnet22)=0.4876870 v(dffx1:hnet24)=1.2000000 v(dffx1:hnet30)=-0.1424982 v(dffx1:hnet32)=1.1999990 v(dffx1:hnet38)=0.9796580 v(dffx1:hnet40)=1.1999040 v(dffx1:m)=0.0000607 v(dffx1:net43)=1.1996720 v(d)=0.0000000 v(dffx1:pm)=1.1998090 v(dffx1:s)=0.0000276 v(q)=0.0000015 v(qn)=1.1999990 v(vdd)=1.2000000 v(vss)=0.0000000
			00 , 01 , 00 = -- ;
		ipower 
			00 , 10 = -- ;
		ipower 
			10 , 00 = -- ;
		incap 
			00 , 10 = -- ;
		incap 
			00 , 01 = -- ;
		setup hold mpw 
		simfeed setup v(ck)=1.2000000 v(dffx1:c)=1.2001520 v(dffx1:cn)=0.0000300 v(dffx1:hnet14)=0.9730170 v(dffx1:hnet16)=1.1998350 v(dffx1:hnet22)=0.4876870 v(dffx1:hnet24)=1.2000000 v(dffx1:hnet30)=-0.1424982 v(dffx1:hnet32)=1.1999990 v(dffx1:hnet38)=0.9796580 v(dffx1:hnet40)=1.1999040 v(dffx1:m)=0.0000607 v(dffx1:net43)=1.1996720 v(d)=0.0000000 v(dffx1:pm)=1.1998090 v(dffx1:s)=0.0000276 v(q)=0.0000015 v(qn)=1.1999990 v(vdd)=1.2000000 v(vss)=0.0000000
		simfeed hold v(ck)=0.0000000 v(dffx1:c)=-0.0000484 v(dffx1:cn)=1.1997150 v(dffx1:hnet14)=0.0000011 v(dffx1:hnet16)=1.4285070 v(dffx1:hnet22)=0.0001969 v(dffx1:hnet24)=0.3567618 v(dffx1:hnet30)=0.9733627 v(dffx1:hnet32)=1.2001050 v(dffx1:hnet38)=0.0000006 v(dffx1:hnet40)=1.3620590 v(dffx1:m)=1.1996580 v(dffx1:net43)=1.2002100 v(d)=1.2000000 v(dffx1:pm)=0.0003926 v(dffx1:s)=0.0000233 v(q)=0.0000005 v(qn)=1.1999990 v(vdd)=1.2000000 v(vss)=0.0000000
			00 , 01 , 00 , 11 = rf ;
		setup hold mpw 
		simfeed setup v(ck)=1.2000000 v(dffx1:c)=1.1999970 v(dffx1:cn)=-0.0001167 v(dffx1:hnet14)=0.0000878 v(dffx1:hnet16)=0.3550378 v(dffx1:hnet22)=0.0000001 v(dffx1:hnet24)=0.8095952 v(dffx1:hnet30)=0.0000001 v(dffx1:hnet32)=0.7155777 v(dffx1:hnet38)=0.0000704 v(dffx1:hnet40)=0.3471633 v(dffx1:m)=1.1997800 v(dffx1:net43)=0.0001750 v(d)=1.2000000 v(dffx1:pm)=0.0001403 v(dffx1:s)=1.1999980 v(q)=1.1999980 v(qn)=0.0000006 v(vdd)=1.2000000 v(vss)=0.0000000
		simfeed hold v(ck)=0.0000000 v(dffx1:c)=0.0000777 v(dffx1:cn)=1.2000650 v(dffx1:hnet14)=-0.1708871 v(dffx1:hnet16)=1.1999980 v(dffx1:hnet22)=0.9727797 v(dffx1:hnet24)=1.1997660 v(dffx1:hnet30)=-0.0000499 v(dffx1:hnet32)=0.1881151 v(dffx1:hnet38)=-0.1487851 v(dffx1:hnet40)=1.1999990 v(dffx1:m)=0.0000772 v(dffx1:net43)=-0.0000995 v(d)=0.0000000 v(dffx1:pm)=1.1995360 v(dffx1:s)=1.2000000 v(q)=1.2000000 v(qn)=0.0000006 v(vdd)=1.2000000 v(vss)=0.0000000
			10 , 11 , 10 , 01 = fr ;
		lpower 
			00 , 01 , 10 , 11 = -- ;
	end_table
end_cdf
