cdf TBUFX1
	table TBUFX1
		inputs A , OE;
		outputs Y;
		function
			Y = A
			Y Z = !OE
		end_function
		incap 
			01 , 11 = r ;
		delay dpower 
			01 , 11 = r ;
		delay dpower 
			11 , 01 = f ;
		tristate dpower 
			00 , 01 = z ;
		tristate dpower 
			10 , 11 = Z ;
		tristate 
			01 , 00 = T ;
		tristate 
			11 , 10 = t ;
		lpower 
			00 , 01 , 10 , 11 = - ;
	end_table
end_cdf
