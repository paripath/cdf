cdf TLATX1
	table TLATX1
		inputs D ;
		clocks G ;
		outputs Q , QN ;
		function
			latch(IQ, IQN) {
				enable : G
				data_in : D
			}
			Q = IQ
			QN = IQN
		end_function
	end_table
end_cdf

