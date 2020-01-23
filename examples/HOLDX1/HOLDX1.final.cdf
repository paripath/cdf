cdf HOLDX1
	table HOLDX1
		inputs Y;
		outputs Y;
		function
		end_function
		incap 
			model incap Y f = 0.07600  , 0.04486; #jobs/HOLDX1_incap_1.sp.result 
			model incap Y r = 0.07600  , 0.05829; #jobs/HOLDX1_incap_1.sp.result 
			1 , 0 = r ;
		lpower 
			model lpower 0 = 0  , 0.00149; #jobs/HOLDX1_lpower_1.sp.result 
			model lpower 1 = 0  , 0.00578; #jobs/HOLDX1_lpower_1.sp.result 
			0 , 1 = - ;
	end_table
end_cdf
