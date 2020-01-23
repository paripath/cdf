cdf INVX1
	table INVX1
		inputs A;
		outputs Y;
		function
			Y = (!A)
		end_function
		incap 
			model incap A f = 0.07600  , 0.03573; #jobs/INVX1_incap_1.sp.result 
			model incap A r = 0.07600  , 0.03572; #jobs/INVX1_incap_1.sp.result 
			1 , 0 = r ;
		delay dpower 
			model delay A f Y r = 0.02800 0.00079  , 0.02402 , 0.01213; #jobs/INVX1_power_delay_1.sp.result0 
			model delay A f Y r = 0.02800 0.00205  , 0.03241 , 0.01620; #jobs/INVX1_power_delay_1.sp.result1 
			model delay A f Y r = 0.02800 0.00474  , 0.04624 , 0.02678; #jobs/INVX1_power_delay_1.sp.result2 
			model delay A f Y r = 0.02800 0.01011  , 0.07365 , 0.05249; #jobs/INVX1_power_delay_1.sp.result3 
			model delay A f Y r = 0.02800 0.02086  , 0.12845 , 0.10406; #jobs/INVX1_power_delay_1.sp.result4 
			model delay A f Y r = 0.04400 0.00079  , 0.02906 , 0.01452; #jobs/INVX1_power_delay_2.sp.result0 
			model delay A f Y r = 0.04400 0.00205  , 0.03898 , 0.02026; #jobs/INVX1_power_delay_2.sp.result1 
			model delay A f Y r = 0.04400 0.00474  , 0.05512 , 0.02915; #jobs/INVX1_power_delay_2.sp.result2 
			model delay A f Y r = 0.04400 0.01011  , 0.08205 , 0.05250; #jobs/INVX1_power_delay_2.sp.result3 
			model delay A f Y r = 0.04400 0.02086  , 0.13656 , 0.10405; #jobs/INVX1_power_delay_2.sp.result4 
			model delay A f Y r = 0.07600 0.00079  , 0.03785 , 0.01877; #jobs/INVX1_power_delay_3.sp.result0 
			model delay A f Y r = 0.07600 0.00205  , 0.04975 , 0.02569; #jobs/INVX1_power_delay_3.sp.result1 
			model delay A f Y r = 0.07600 0.00474  , 0.06971 , 0.03698; #jobs/INVX1_power_delay_3.sp.result2 
			model delay A f Y r = 0.07600 0.01011  , 0.09977 , 0.05547; #jobs/INVX1_power_delay_3.sp.result3 
			model delay A f Y r = 0.07600 0.02086  , 0.15348 , 0.10406; #jobs/INVX1_power_delay_3.sp.result4 
			model delay A f Y r = 0.13800 0.00079  , 0.05258 , 0.02602; #jobs/INVX1_power_delay_4.sp.result0 
			model delay A f Y r = 0.13800 0.00205  , 0.06724 , 0.03423; #jobs/INVX1_power_delay_4.sp.result1 
			model delay A f Y r = 0.13800 0.00474  , 0.09175 , 0.04843; #jobs/INVX1_power_delay_4.sp.result2 
			model delay A f Y r = 0.13800 0.01011  , 0.13001 , 0.06980; #jobs/INVX1_power_delay_4.sp.result3 
			model delay A f Y r = 0.13800 0.02086  , 0.18784 , 0.10807; #jobs/INVX1_power_delay_4.sp.result4 
			model delay A f Y r = 0.26400 0.00079  , 0.07850 , 0.03912; #jobs/INVX1_power_delay_5.sp.result0 
			model delay A f Y r = 0.26400 0.00205  , 0.09731 , 0.04921; #jobs/INVX1_power_delay_5.sp.result1 
			model delay A f Y r = 0.26400 0.00474  , 0.12818 , 0.06636; #jobs/INVX1_power_delay_5.sp.result2 
			model delay A f Y r = 0.26400 0.01011  , 0.17627 , 0.09410; #jobs/INVX1_power_delay_5.sp.result3 
			model delay A f Y r = 0.26400 0.02086  , 0.25127 , 0.13581; #jobs/INVX1_power_delay_5.sp.result4 
			model dpower A f Y r = 0.02800 0.00079  , 3.74549; #jobs/INVX1_power_delay_1.sp.result0 
			model dpower A f Y r = 0.02800 0.00205  , 5.56299; #jobs/INVX1_power_delay_1.sp.result1 
			model dpower A f Y r = 0.02800 0.00474  , 9.42454; #jobs/INVX1_power_delay_1.sp.result2 
			model dpower A f Y r = 0.02800 0.01011  , 17.20663; #jobs/INVX1_power_delay_1.sp.result3 
			model dpower A f Y r = 0.02800 0.02086  , 32.73879; #jobs/INVX1_power_delay_1.sp.result4 
			model dpower A f Y r = 0.04400 0.00079  , 3.92769; #jobs/INVX1_power_delay_2.sp.result0 
			model dpower A f Y r = 0.04400 0.00205  , 5.69761; #jobs/INVX1_power_delay_2.sp.result1 
			model dpower A f Y r = 0.04400 0.00474  , 9.51934; #jobs/INVX1_power_delay_2.sp.result2 
			model dpower A f Y r = 0.04400 0.01011  , 17.24088; #jobs/INVX1_power_delay_2.sp.result3 
			model dpower A f Y r = 0.04400 0.02086  , 32.74057; #jobs/INVX1_power_delay_2.sp.result4 
			model dpower A f Y r = 0.07600 0.00079  , 4.36864; #jobs/INVX1_power_delay_3.sp.result0 
			model dpower A f Y r = 0.07600 0.00205  , 6.08055; #jobs/INVX1_power_delay_3.sp.result1 
			model dpower A f Y r = 0.07600 0.00474  , 9.81821; #jobs/INVX1_power_delay_3.sp.result2 
			model dpower A f Y r = 0.07600 0.01011  , 17.43653; #jobs/INVX1_power_delay_3.sp.result3 
			model dpower A f Y r = 0.07600 0.02086  , 32.84001; #jobs/INVX1_power_delay_3.sp.result4 
			model dpower A f Y r = 0.13800 0.00079  , 5.30732; #jobs/INVX1_power_delay_4.sp.result0 
			model dpower A f Y r = 0.13800 0.00205  , 6.94709; #jobs/INVX1_power_delay_4.sp.result1 
			model dpower A f Y r = 0.13800 0.00474  , 10.57161; #jobs/INVX1_power_delay_4.sp.result2 
			model dpower A f Y r = 0.13800 0.01011  , 18.03335; #jobs/INVX1_power_delay_4.sp.result3 
			model dpower A f Y r = 0.13800 0.02086  , 33.24678; #jobs/INVX1_power_delay_4.sp.result4 
			model dpower A f Y r = 0.26400 0.00079  , 7.32621; #jobs/INVX1_power_delay_5.sp.result0 
			model dpower A f Y r = 0.26400 0.00205  , 8.87301; #jobs/INVX1_power_delay_5.sp.result1 
			model dpower A f Y r = 0.26400 0.00474  , 12.34039; #jobs/INVX1_power_delay_5.sp.result2 
			model dpower A f Y r = 0.26400 0.01011  , 19.57702; #jobs/INVX1_power_delay_5.sp.result3 
			model dpower A f Y r = 0.26400 0.02086  , 34.48071; #jobs/INVX1_power_delay_5.sp.result4 
			1 , 0 = r ;
		delay dpower 
			model delay A r Y f = 0.02800 0.00079  , 0.01502 , 0.00830; #jobs/INVX1_power_delay_6.sp.result0 
			model delay A r Y f = 0.02800 0.00205  , 0.02203 , 0.01130; #jobs/INVX1_power_delay_6.sp.result1 
			model delay A r Y f = 0.02800 0.00474  , 0.03272 , 0.01595; #jobs/INVX1_power_delay_6.sp.result2 
			model delay A r Y f = 0.02800 0.01011  , 0.04904 , 0.02772; #jobs/INVX1_power_delay_6.sp.result3 
			model delay A r Y f = 0.02800 0.02086  , 0.08113 , 0.05506; #jobs/INVX1_power_delay_6.sp.result4 
			model delay A r Y f = 0.04400 0.00079  , 0.01560 , 0.01083; #jobs/INVX1_power_delay_7.sp.result0 
			model delay A r Y f = 0.04400 0.00205  , 0.02423 , 0.01452; #jobs/INVX1_power_delay_7.sp.result1 
			model delay A r Y f = 0.04400 0.00474  , 0.03771 , 0.02026; #jobs/INVX1_power_delay_7.sp.result2 
			model delay A r Y f = 0.04400 0.01011  , 0.05665 , 0.02952; #jobs/INVX1_power_delay_7.sp.result3 
			model delay A r Y f = 0.04400 0.02086  , 0.08869 , 0.05506; #jobs/INVX1_power_delay_7.sp.result4 
			model delay A r Y f = 0.07600 0.00079  , 0.01497 , 0.01537; #jobs/INVX1_power_delay_8.sp.result0 
			model delay A r Y f = 0.07600 0.00205  , 0.02595 , 0.01996; #jobs/INVX1_power_delay_8.sp.result1 
			model delay A r Y f = 0.07600 0.00474  , 0.04337 , 0.02724; #jobs/INVX1_power_delay_8.sp.result2 
			model delay A r Y f = 0.07600 0.01011  , 0.06850 , 0.03785; #jobs/INVX1_power_delay_8.sp.result3 
			model delay A r Y f = 0.07600 0.02086  , 0.10403 , 0.05709; #jobs/INVX1_power_delay_8.sp.result4 
			model delay A r Y f = 0.13800 0.00079  , 0.01089 , 0.02307; #jobs/INVX1_power_delay_9.sp.result0 
			model delay A r Y f = 0.13800 0.00205  , 0.02510 , 0.02898; #jobs/INVX1_power_delay_9.sp.result1 
			model delay A r Y f = 0.13800 0.00474  , 0.04777 , 0.03828; #jobs/INVX1_power_delay_9.sp.result2 
			model delay A r Y f = 0.13800 0.01011  , 0.08112 , 0.05216; #jobs/INVX1_power_delay_9.sp.result3 
			model delay A r Y f = 0.13800 0.02086  , 0.12910 , 0.07232; #jobs/INVX1_power_delay_9.sp.result4 
			model delay A r Y f = 0.26400 0.00079  , -0.00185 , 0.03679; #jobs/INVX1_power_delay_10.sp.result0 
			model delay A r Y f = 0.26400 0.00205  , 0.01684 , 0.04476; #jobs/INVX1_power_delay_10.sp.result1 
			model delay A r Y f = 0.26400 0.00474  , 0.04689 , 0.05709; #jobs/INVX1_power_delay_10.sp.result2 
			model delay A r Y f = 0.26400 0.01011  , 0.09141 , 0.07520; #jobs/INVX1_power_delay_10.sp.result3 
			model delay A r Y f = 0.26400 0.02086  , 0.15675 , 0.10232; #jobs/INVX1_power_delay_10.sp.result4 
			model dpower A r Y f = 0.02800 0.00079  , 0.87231; #jobs/INVX1_power_delay_6.sp.result0 
			model dpower A r Y f = 0.02800 0.00205  , 0.86967; #jobs/INVX1_power_delay_6.sp.result1 
			model dpower A r Y f = 0.02800 0.00474  , 0.92428; #jobs/INVX1_power_delay_6.sp.result2 
			model dpower A r Y f = 0.02800 0.01011  , 0.96023; #jobs/INVX1_power_delay_6.sp.result3 
			model dpower A r Y f = 0.02800 0.02086  , 0.96940; #jobs/INVX1_power_delay_6.sp.result4 
			model dpower A r Y f = 0.04400 0.00079  , 0.86457; #jobs/INVX1_power_delay_7.sp.result0 
			model dpower A r Y f = 0.04400 0.00205  , 0.79134; #jobs/INVX1_power_delay_7.sp.result1 
			model dpower A r Y f = 0.04400 0.00474  , 0.81681; #jobs/INVX1_power_delay_7.sp.result2 
			model dpower A r Y f = 0.04400 0.01011  , 0.89572; #jobs/INVX1_power_delay_7.sp.result3 
			model dpower A r Y f = 0.04400 0.02086  , 0.93824; #jobs/INVX1_power_delay_7.sp.result4 
			model dpower A r Y f = 0.07600 0.00079  , 1.15338; #jobs/INVX1_power_delay_8.sp.result0 
			model dpower A r Y f = 0.07600 0.00205  , 0.95160; #jobs/INVX1_power_delay_8.sp.result1 
			model dpower A r Y f = 0.07600 0.00474  , 0.75660; #jobs/INVX1_power_delay_8.sp.result2 
			model dpower A r Y f = 0.07600 0.01011  , 0.73019; #jobs/INVX1_power_delay_8.sp.result3 
			model dpower A r Y f = 0.07600 0.02086  , 0.83757; #jobs/INVX1_power_delay_8.sp.result4 
			model dpower A r Y f = 0.13800 0.00079  , 1.84601; #jobs/INVX1_power_delay_9.sp.result0 
			model dpower A r Y f = 0.13800 0.00205  , 1.57870; #jobs/INVX1_power_delay_9.sp.result1 
			model dpower A r Y f = 0.13800 0.00474  , 1.22310; #jobs/INVX1_power_delay_9.sp.result2 
			model dpower A r Y f = 0.13800 0.01011  , 0.87043; #jobs/INVX1_power_delay_9.sp.result3 
			model dpower A r Y f = 0.13800 0.02086  , 0.73281; #jobs/INVX1_power_delay_9.sp.result4 
			model dpower A r Y f = 0.26400 0.00079  , 3.61256; #jobs/INVX1_power_delay_10.sp.result0 
			model dpower A r Y f = 0.26400 0.00205  , 3.18199; #jobs/INVX1_power_delay_10.sp.result1 
			model dpower A r Y f = 0.26400 0.00474  , 2.58300; #jobs/INVX1_power_delay_10.sp.result2 
			model dpower A r Y f = 0.26400 0.01011  , 1.92375; #jobs/INVX1_power_delay_10.sp.result3 
			model dpower A r Y f = 0.26400 0.02086  , 1.29809; #jobs/INVX1_power_delay_10.sp.result4 
			0 , 1 = f ;
		lpower 
			model lpower 0 = 0  , 0.00083; #jobs/INVX1_lpower_1.sp.result 
			model lpower 1 = 0  , 0.00230; #jobs/INVX1_lpower_1.sp.result 
			0 , 1 = - ;
	end_table
end_cdf
