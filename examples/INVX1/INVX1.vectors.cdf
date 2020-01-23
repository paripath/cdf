cdf INVX1
	table INVX1
		inputs A;
		outputs Y;
		function
			Y = (!A)
		end_function
		incap 
			1 , 0 = r ;
		delay dpower 
			1 , 0 = r ;
		delay dpower 
			0 , 1 = f ;
		lpower 
			0 , 1 = - ;
	end_table
end_cdf
