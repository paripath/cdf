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
			00 , 01 , 00 , 10 , 11 = rf ;
		delay dpower 
			10 , 11 , 10 , 00 , 01 = fr ;
		delay dpower 
			01 , 01 , 11 = rf ;
		delay dpower 
			11 , 11 , 01 = fr ;
		ipower 
			00 , 01 , 00 , 01 = -- ;
		ipower 
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
			01 , 00 , 01 , 10 = rf ;
		setup hold 
			11 , 10 , 11 , 00 = fr ;
		mpw 
			00 , 01 , 00 , 11 = rf ;
		mpw 
			10 , 11 , 10 , 01 = fr ;
		lpower 
			00 , 01 , 10 , 11 = -- ;
	end_table
end_cdf
