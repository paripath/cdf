cdf INVXL
	table INVXL
		inputs A;
		outputs Y;
		function
			Y = (!A)
		end_function
		incap 
			model incap A f = 0.07600  , 0.01887; #jobs/INVXL_incap_1.sp.result 
			model incap A r = 0.07600  , 0.01887; #jobs/INVXL_incap_1.sp.result 
			1 , 0 = r ;
		delay dpower 
			model delay A f Y r = 0.02800 0.00040  , 0.02359 , 0.01188; #jobs/INVXL_power_delay_1.sp.result0 
			model delay A f Y r = 0.02800 0.00103  , 0.03164 , 0.01581; #jobs/INVXL_power_delay_1.sp.result1 
			model delay A f Y r = 0.02800 0.00237  , 0.04477 , 0.02551; #jobs/INVXL_power_delay_1.sp.result2 
			model delay A f Y r = 0.02800 0.00506  , 0.07057 , 0.04963; #jobs/INVXL_power_delay_1.sp.result3 
			model delay A f Y r = 0.02800 0.01043  , 0.12215 , 0.09815; #jobs/INVXL_power_delay_1.sp.result4 
			model delay A f Y r = 0.04400 0.00040  , 0.02856 , 0.01429; #jobs/INVXL_power_delay_2.sp.result0 
			model delay A f Y r = 0.04400 0.00103  , 0.03806 , 0.01978; #jobs/INVXL_power_delay_2.sp.result1 
			model delay A f Y r = 0.04400 0.00237  , 0.05360 , 0.02814; #jobs/INVXL_power_delay_2.sp.result2 
			model delay A f Y r = 0.04400 0.00506  , 0.07900 , 0.04963; #jobs/INVXL_power_delay_2.sp.result3 
			model delay A f Y r = 0.04400 0.01043  , 0.13028 , 0.09815; #jobs/INVXL_power_delay_2.sp.result4 
			model delay A f Y r = 0.07600 0.00040  , 0.03720 , 0.01849; #jobs/INVXL_power_delay_3.sp.result0 
			model delay A f Y r = 0.07600 0.00103  , 0.04859 , 0.02512; #jobs/INVXL_power_delay_3.sp.result1 
			model delay A f Y r = 0.07600 0.00237  , 0.06776 , 0.03596; #jobs/INVXL_power_delay_3.sp.result2 
			model delay A f Y r = 0.07600 0.00506  , 0.09677 , 0.05317; #jobs/INVXL_power_delay_3.sp.result3 
			model delay A f Y r = 0.07600 0.01043  , 0.14724 , 0.09815; #jobs/INVXL_power_delay_3.sp.result4 
			model delay A f Y r = 0.13800 0.00040  , 0.05169 , 0.02573; #jobs/INVXL_power_delay_4.sp.result0 
			model delay A f Y r = 0.13800 0.00103  , 0.06574 , 0.03355; #jobs/INVXL_power_delay_4.sp.result1 
			model delay A f Y r = 0.13800 0.00237  , 0.08927 , 0.04712; #jobs/INVXL_power_delay_4.sp.result2 
			model delay A f Y r = 0.13800 0.00506  , 0.12610 , 0.06779; #jobs/INVXL_power_delay_4.sp.result3 
			model delay A f Y r = 0.13800 0.01043  , 0.18171 , 0.10313; #jobs/INVXL_power_delay_4.sp.result4 
			model delay A f Y r = 0.26400 0.00040  , 0.07716 , 0.03876; #jobs/INVXL_power_delay_5.sp.result0 
			model delay A f Y r = 0.26400 0.00103  , 0.09521 , 0.04842; #jobs/INVXL_power_delay_5.sp.result1 
			model delay A f Y r = 0.26400 0.00237  , 0.12491 , 0.06483; #jobs/INVXL_power_delay_5.sp.result2 
			model delay A f Y r = 0.26400 0.00506  , 0.17115 , 0.09142; #jobs/INVXL_power_delay_5.sp.result3 
			model delay A f Y r = 0.26400 0.01043  , 0.24340 , 0.13176; #jobs/INVXL_power_delay_5.sp.result4 
			model dpower A f Y r = 0.02800 0.00040  , 1.94948; #jobs/INVXL_power_delay_1.sp.result0 
			model dpower A f Y r = 0.02800 0.00103  , 2.85871; #jobs/INVXL_power_delay_1.sp.result1 
			model dpower A f Y r = 0.02800 0.00237  , 4.78756; #jobs/INVXL_power_delay_1.sp.result2 
			model dpower A f Y r = 0.02800 0.00506  , 8.67866; #jobs/INVXL_power_delay_1.sp.result3 
			model dpower A f Y r = 0.02800 0.01043  , 16.44615; #jobs/INVXL_power_delay_1.sp.result4 
			model dpower A f Y r = 0.04400 0.00040  , 2.04686; #jobs/INVXL_power_delay_2.sp.result0 
			model dpower A f Y r = 0.04400 0.00103  , 2.93040; #jobs/INVXL_power_delay_2.sp.result1 
			model dpower A f Y r = 0.04400 0.00237  , 4.84031; #jobs/INVXL_power_delay_2.sp.result2 
			model dpower A f Y r = 0.04400 0.00506  , 8.69861; #jobs/INVXL_power_delay_2.sp.result3 
			model dpower A f Y r = 0.04400 0.01043  , 16.44801; #jobs/INVXL_power_delay_2.sp.result4 
			model dpower A f Y r = 0.07600 0.00040  , 2.28081; #jobs/INVXL_power_delay_3.sp.result0 
			model dpower A f Y r = 0.07600 0.00103  , 3.13513; #jobs/INVXL_power_delay_3.sp.result1 
			model dpower A f Y r = 0.07600 0.00237  , 5.00098; #jobs/INVXL_power_delay_3.sp.result2 
			model dpower A f Y r = 0.07600 0.00506  , 8.80681; #jobs/INVXL_power_delay_3.sp.result3 
			model dpower A f Y r = 0.07600 0.01043  , 16.50372; #jobs/INVXL_power_delay_3.sp.result4 
			model dpower A f Y r = 0.13800 0.00040  , 2.77797; #jobs/INVXL_power_delay_4.sp.result0 
			model dpower A f Y r = 0.13800 0.00103  , 3.59557; #jobs/INVXL_power_delay_4.sp.result1 
			model dpower A f Y r = 0.13800 0.00237  , 5.40344; #jobs/INVXL_power_delay_4.sp.result2 
			model dpower A f Y r = 0.13800 0.00506  , 9.12772; #jobs/INVXL_power_delay_4.sp.result3 
			model dpower A f Y r = 0.13800 0.01043  , 16.72580; #jobs/INVXL_power_delay_4.sp.result4 
			model dpower A f Y r = 0.26400 0.00040  , 3.84575; #jobs/INVXL_power_delay_5.sp.result0 
			model dpower A f Y r = 0.26400 0.00103  , 4.61657; #jobs/INVXL_power_delay_5.sp.result1 
			model dpower A f Y r = 0.26400 0.00237  , 6.34412; #jobs/INVXL_power_delay_5.sp.result2 
			model dpower A f Y r = 0.26400 0.00506  , 9.95259; #jobs/INVXL_power_delay_5.sp.result3 
			model dpower A f Y r = 0.26400 0.01043  , 17.39055; #jobs/INVXL_power_delay_5.sp.result4 
			1 , 0 = r ;
		delay dpower 
			model delay A r Y f = 0.02800 0.00040  , 0.01486 , 0.00818; #jobs/INVXL_power_delay_6.sp.result0 
			model delay A r Y f = 0.02800 0.00103  , 0.02164 , 0.01113; #jobs/INVXL_power_delay_6.sp.result1 
			model delay A r Y f = 0.02800 0.00237  , 0.03203 , 0.01560; #jobs/INVXL_power_delay_6.sp.result2 
			model delay A r Y f = 0.02800 0.00506  , 0.04771 , 0.02657; #jobs/INVXL_power_delay_6.sp.result3 
			model delay A r Y f = 0.02800 0.01043  , 0.07836 , 0.05267; #jobs/INVXL_power_delay_6.sp.result4 
			model delay A r Y f = 0.04400 0.00040  , 0.01543 , 0.01068; #jobs/INVXL_power_delay_7.sp.result0 
			model delay A r Y f = 0.04400 0.00103  , 0.02375 , 0.01428; #jobs/INVXL_power_delay_7.sp.result1 
			model delay A r Y f = 0.04400 0.00237  , 0.03683 , 0.01987; #jobs/INVXL_power_delay_7.sp.result2 
			model delay A r Y f = 0.04400 0.00506  , 0.05533 , 0.02863; #jobs/INVXL_power_delay_7.sp.result3 
			model delay A r Y f = 0.04400 0.01043  , 0.08591 , 0.05267; #jobs/INVXL_power_delay_7.sp.result4 
			model delay A r Y f = 0.07600 0.00040  , 0.01477 , 0.01521; #jobs/INVXL_power_delay_8.sp.result0 
			model delay A r Y f = 0.07600 0.00103  , 0.02536 , 0.01965; #jobs/INVXL_power_delay_8.sp.result1 
			model delay A r Y f = 0.07600 0.00237  , 0.04223 , 0.02672; #jobs/INVXL_power_delay_8.sp.result2 
			model delay A r Y f = 0.07600 0.00506  , 0.06671 , 0.03705; #jobs/INVXL_power_delay_8.sp.result3 
			model delay A r Y f = 0.07600 0.01043  , 0.10127 , 0.05511; #jobs/INVXL_power_delay_8.sp.result4 
			model delay A r Y f = 0.13800 0.00040  , 0.01069 , 0.02287; #jobs/INVXL_power_delay_9.sp.result0 
			model delay A r Y f = 0.13800 0.00103  , 0.02439 , 0.02859; #jobs/INVXL_power_delay_9.sp.result1 
			model delay A r Y f = 0.13800 0.00237  , 0.04634 , 0.03760; #jobs/INVXL_power_delay_9.sp.result2 
			model delay A r Y f = 0.13800 0.00506  , 0.07874 , 0.05109; #jobs/INVXL_power_delay_9.sp.result3 
			model delay A r Y f = 0.13800 0.01043  , 0.12552 , 0.07076; #jobs/INVXL_power_delay_9.sp.result4 
			model delay A r Y f = 0.26400 0.00040  , -0.00191 , 0.03652; #jobs/INVXL_power_delay_10.sp.result0 
			model delay A r Y f = 0.26400 0.00103  , 0.01608 , 0.04420; #jobs/INVXL_power_delay_10.sp.result1 
			model delay A r Y f = 0.26400 0.00237  , 0.04513 , 0.05618; #jobs/INVXL_power_delay_10.sp.result2 
			model delay A r Y f = 0.26400 0.00506  , 0.08833 , 0.07378; #jobs/INVXL_power_delay_10.sp.result3 
			model delay A r Y f = 0.26400 0.01043  , 0.15188 , 0.10018; #jobs/INVXL_power_delay_10.sp.result4 
			model dpower A r Y f = 0.02800 0.00040  , 0.46421; #jobs/INVXL_power_delay_6.sp.result0 
			model dpower A r Y f = 0.02800 0.00103  , 0.46226; #jobs/INVXL_power_delay_6.sp.result1 
			model dpower A r Y f = 0.02800 0.00237  , 0.49017; #jobs/INVXL_power_delay_6.sp.result2 
			model dpower A r Y f = 0.02800 0.00506  , 0.51025; #jobs/INVXL_power_delay_6.sp.result3 
			model dpower A r Y f = 0.02800 0.01043  , 0.51539; #jobs/INVXL_power_delay_6.sp.result4 
			model dpower A r Y f = 0.04400 0.00040  , 0.46193; #jobs/INVXL_power_delay_7.sp.result0 
			model dpower A r Y f = 0.04400 0.00103  , 0.42162; #jobs/INVXL_power_delay_7.sp.result1 
			model dpower A r Y f = 0.04400 0.00237  , 0.43283; #jobs/INVXL_power_delay_7.sp.result2 
			model dpower A r Y f = 0.04400 0.00506  , 0.47454; #jobs/INVXL_power_delay_7.sp.result3 
			model dpower A r Y f = 0.04400 0.01043  , 0.49818; #jobs/INVXL_power_delay_7.sp.result4 
			model dpower A r Y f = 0.07600 0.00040  , 0.61442; #jobs/INVXL_power_delay_8.sp.result0 
			model dpower A r Y f = 0.07600 0.00103  , 0.51104; #jobs/INVXL_power_delay_8.sp.result1 
			model dpower A r Y f = 0.07600 0.00237  , 0.40546; #jobs/INVXL_power_delay_8.sp.result2 
			model dpower A r Y f = 0.07600 0.00506  , 0.38674; #jobs/INVXL_power_delay_8.sp.result3 
			model dpower A r Y f = 0.07600 0.01043  , 0.44268; #jobs/INVXL_power_delay_8.sp.result4 
			model dpower A r Y f = 0.13800 0.00040  , 0.98118; #jobs/INVXL_power_delay_9.sp.result0 
			model dpower A r Y f = 0.13800 0.00103  , 0.84421; #jobs/INVXL_power_delay_9.sp.result1 
			model dpower A r Y f = 0.13800 0.00237  , 0.66003; #jobs/INVXL_power_delay_9.sp.result2 
			model dpower A r Y f = 0.13800 0.00506  , 0.47071; #jobs/INVXL_power_delay_9.sp.result3 
			model dpower A r Y f = 0.13800 0.01043  , 0.39110; #jobs/INVXL_power_delay_9.sp.result4 
			model dpower A r Y f = 0.26400 0.00040  , 1.91615; #jobs/INVXL_power_delay_10.sp.result0 
			model dpower A r Y f = 0.26400 0.00103  , 1.69647; #jobs/INVXL_power_delay_10.sp.result1 
			model dpower A r Y f = 0.26400 0.00237  , 1.38683; #jobs/INVXL_power_delay_10.sp.result2 
			model dpower A r Y f = 0.26400 0.00506  , 1.04136; #jobs/INVXL_power_delay_10.sp.result3 
			model dpower A r Y f = 0.26400 0.01043  , 0.70726; #jobs/INVXL_power_delay_10.sp.result4 
			0 , 1 = f ;
		lpower 
			model lpower 0 = 0  , 0.00044; #jobs/INVXL_lpower_1.sp.result 
			model lpower 1 = 0  , 0.00120; #jobs/INVXL_lpower_1.sp.result 
			0 , 1 = - ;
	end_table
end_cdf
