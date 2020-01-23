cdf DFFX1
	table DFFX1
		inputs D ;
		clocks CK ;
		outputs Q , QN ;
		function
			ff(IQ, IQN) {
				clocked_on : CK
				next_state : D
			}
			Q = IQ
			QN = IQN
		end_function
	end_table
end_cdf

