cdf XOR2X1
	table XOR2X1
		inputs A , B;
		outputs Y;
		function
			Y = (A ^ B)
		end_function
		incap 
			00 , 11 = - ;
		delay dpower 
			state 0-
			00 , 01 = r ;
		delay dpower 
			state -0
			00 , 10 = r ;
		delay dpower 
			state -1
			11 , 01 = r ;
		delay dpower 
			state 1-
			11 , 10 = r ;
		delay dpower 
			state 0-
			01 , 00 = f ;
		delay dpower 
			state -1
			01 , 11 = f ;
		delay dpower 
			state -0
			10 , 00 = f ;
		delay dpower 
			state 1-
			10 , 11 = f ;
		lpower 
			00 , 01 , 10 , 11 = - ;
	end_table
end_cdf
