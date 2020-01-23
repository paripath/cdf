cdf AND2X1
	table AND2X1
		inputs A , B;
		outputs Y;
		function
			Y = (A B)
		end_function
		incap 
			00 , 10 = - ;
		incap 
			00 , 01 = - ;
		delay dpower 
			01 , 11 = r ;
		delay dpower 
			10 , 11 = r ;
		delay dpower 
			11 , 01 = f ;
		delay dpower 
			11 , 10 = f ;
		lpower 
			00 , 01 , 10 , 11 = - ;
	end_table
end_cdf
