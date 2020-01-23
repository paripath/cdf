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
			00 , 01 , 10 , 11 = rf ;
		delay dpower 
			10 , 11 , 00 , 01 = fr ;
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
		setup hold mpw 
			00 , 01 , 00 , 11 = rf ;
		setup hold mpw 
			10 , 11 , 10 , 01 = fr ;
		lpower 
			00 , 01 , 10 , 11 = -- ;
	end_table
end_cdf
