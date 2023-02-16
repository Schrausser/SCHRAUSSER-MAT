//----------------------------------------------------------------------------------------------------| calc_ funktionen, k Kontingenzfelder, SCHRAUSSER 2010	//

double fn_kmtn0(double wert[100], int zn)// multinomiale Punkt-Wahrscheinlichkeit P0 zu k - Feldern  // MN0 z1, ... , zk //
{
	double z_[100], vektor[100], P0, n=0;
	int iLauf, k;

	k= zn;

	for(iLauf=1 ; iLauf <=k; iLauf++ ) z_[iLauf]= wert[iLauf];
	for(iLauf=1 ; iLauf <=k; iLauf++ ) n+= z_[iLauf];	
		
	for(iLauf=1 ; iLauf <= 2*k; iLauf+=2 ) 
	{                   
			            vektor[iLauf]= 1.0/k;
						vektor[iLauf+1]= z_[(iLauf+1)/2];
	}
						vektor[2*k+1]= n;//

		   P0= fn_mtnom(vektor,2*k+1);//	
	
	fn_erg = P0;

	return 0;
};

double fn_kmtn2(double wert[100], int zn)// multinomiale Wahrscheinlichkeit, 2-seitiges sig.-Niveau pexact2 zu k - Feldern  // MN2 z1, ... , zk //
{
	double C, z_[100], z1_[100],z2_[100], vektor[100], index[100], P[10], n=0, sum;
	int iLauf, k, zlr=0, sw=0, i_=1;

	P[6]=0;
	P[2]=0;

	k= zn;

	for(iLauf=1 ; iLauf <=k; iLauf++ ) z_[iLauf]= wert[iLauf];
	for(iLauf=1 ; iLauf <=k; iLauf++ ) n+= z_[iLauf];

	C= kombination_w(k, n);

	if(C>1E+009) {printf("\n\ndesign.0 'C > 1,000,000,000'\n");exit(0);}
	
	for(iLauf=1 ; iLauf <= 2*k; iLauf+=2 ) 
	{                   
			            vektor[iLauf]= 1.0/k;
						vektor[iLauf+1]= z_[(iLauf+1)/2];
	}
						vektor[2*k+1]= n;//

	     P[0]= fn_mtnom(vektor,2*k+1);//				

		printf("\n\n");
		printf("C=%.0f, computing Pi ...", C);	 		

		                                    z_[1]=n;
		for(iLauf=2 ; iLauf <=k; iLauf++ )  z_[iLauf]=0;
		
		for(iLauf=1 ; iLauf <=k; iLauf++ ) 
			                          vektor[2*iLauf]= z_[iLauf];

					   P[8]= fn_mtnom(vektor,2*k+1);
				 P[6]+=P[8];
					if(P[8]<= P[0])P[2]+=P[8];

	// Exakt multinomiale Wahrscheinlichkeits-Verteilung     
	// k=2 bis k=12 in geschwindigkeits-maximierender explizitcodierung -> schleifenminimierung //
	// ab k=13 lange rechenzeiten über allgemein algorithmus  
	//
	//------------------------------------------------------------------------------------------- 2 //
	if(k==2)
	{
		while(z_[1]>0) 
		{
			z_[1]--;
			z_[2]++;
								  vektor[2]= z_[1];
								  vektor[4]= z_[2];
				   P[8]= fn_mtnom(vektor,5);
			 P[6]+=P[8];
				if(P[8]<= P[0])P[2]+=P[8];
		}
	}

	//------------------------------------------------------------------------------------------- 3 //
	if(k==3)
	{	
		while(z_[1]>0) 
		{
			//z_[3]=0;
			z_[1]--;
			z_[2]++;
			z1_[2]=z_[2];
			z1_[3]=z_[3];
								  vektor[2]= z_[1];
								  vektor[4]= z1_[2];
							   	  vektor[6]= z1_[3];
				   P[8]= fn_mtnom(vektor,7);
			 P[6]+=P[8];
				if(P[8]<= P[0])P[2]+=P[8];


			while(z1_[2]>0)
			{
				z1_[2]--;
				z1_[3]++;
									  vektor[2]= z_[1];
									  vektor[4]= z1_[2];
							   		  vektor[6]= z1_[3];
					   P[8]= fn_mtnom(vektor,7);
				 P[6]+=P[8];
					if(P[8]<= P[0])P[2]+=P[8];	
			}
		}
	}
	//------------------------------------------------------------------------------------------- 4 //
	if(k==4)
	{
		while(z_[1]>0) //k=4
		{
			//z_[3]=0;
			z_[1]--;
			z_[2]++;
			z1_[2]=z_[2];
			z1_[3]=z_[3];
								  vektor[2]= z_[1];
								  vektor[4]= z1_[2];
							   	  vektor[6]= z1_[3];
								  vektor[8]= z_[4];
				   P[8]= fn_mtnom(vektor,9);
			 P[6]+=P[8];
				if(P[8]<= P[0])P[2]+=P[8];
					
			while(z1_[2]>0)
			{
		     	//z_[4]=0;
				z1_[2]--;
				z1_[3]++;
				z2_[3]=z1_[3];
				z1_[4]=z_[4];
									  vektor[2]= z_[1];
									  vektor[4]= z1_[2];
							   		  vektor[6]= z1_[3];
									  vektor[8]= z_[4];
					   P[8]= fn_mtnom(vektor,9);
				 P[6]+=P[8];
					if(P[8]<= P[0])P[2]+=P[8];	
	
				while(z2_[3]>0)
				{
					z2_[3]--;
					z1_[4]++;	
									  vektor[2]= z_[1];
									  vektor[4]= z1_[2];
							   		  vektor[6]= z2_[3];
									  vektor[8]= z1_[4];
					   P[8]= fn_mtnom(vektor,9);
				 P[6]+=P[8];
					if(P[8]<= P[0])P[2]+=P[8];	
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------- 5 //
	if(k==5)
	{
		while(z_[1]>0) //k=4
		{
			//z_[3]=0;
			z_[1]--;
			z_[2]++;
			z1_[2]=z_[2];
			z1_[3]=z_[3];
								  vektor[2]= z_[1];
								  vektor[4]= z1_[2];
							   	  vektor[6]= z1_[3];
								  vektor[8]= z_[4];
								  vektor[10]= z_[5];
				   P[8]= fn_mtnom(vektor,11);
			 P[6]+=P[8];
				if(P[8]<= P[0])P[2]+=P[8];
	
			while(z1_[2]>0)
			{
				//z_[4]=0;
				z1_[2]--;
				z1_[3]++;
				z2_[3]=z1_[3];
				z1_[4]=z_[4];
									  vektor[2]=  z_[1];
									  vektor[4]= z1_[2];
							   		  vektor[6]= z1_[3];
									  vektor[8]= z1_[4];
									  vektor[10]= z_[5];
					   P[8]= fn_mtnom(vektor,11);
				 P[6]+=P[8];
					if(P[8]<= P[0])P[2]+=P[8];	

				while(z2_[3]>0)
				{
					//z_[5]=0;
					z2_[3]--;
					z1_[4]++;

					z2_[4]=z1_[4];
				    z1_[5]=z_[5];
										  vektor[2]=  z_[1];
										  vektor[4]= z1_[2];
							   			  vektor[6]= z2_[3];
										  vektor[8]= z1_[4];
										  vektor[10]= z_[5];
						   P[8]= fn_mtnom(vektor,11);
					 P[6]+=P[8];
						if(P[8]<= P[0])P[2]+=P[8];
	
					while(z2_[4]>0)
					{
						z2_[4]--;
						z1_[5]++;
										  vektor[2]=  z_[1];
										  vektor[4]= z1_[2];
							   			  vektor[6]= z2_[3];
										  vektor[8]= z2_[4];
										  vektor[10]=z1_[5];
						   P[8]= fn_mtnom(vektor,11);
					 P[6]+=P[8];
						if(P[8]<= P[0])P[2]+=P[8];
					}
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------- 6 //
	if(k==6)
	{
		while(z_[1]>0) 
		{
			 //z_[3]=0;
			 z_[1]--;
		     z_[2]++;
			z1_[2]=z_[2];
			z1_[3]=z_[3];

								  vektor[2]=  z_[1];
								  vektor[4]= z1_[2];
							   	  vektor[6]= z1_[3];
								  vektor[8]=  z_[4];
								  vektor[10]= z_[5];
								  vektor[12]= z_[6];
				   P[8]= fn_mtnom(vektor,13);
			 P[6]+=P[8];
				if(P[8]<= P[0])P[2]+=P[8];

			while(z1_[2]>0)
			{
				 //z_[4]=0;
				z1_[2]--;
				z1_[3]++;
				z2_[3]=z1_[3];
				z1_[4]= z_[4];
									  vektor[2]=  z_[1];
									  vektor[4]= z1_[2];
							   		  vektor[6]= z1_[3];
									  vektor[8]= z1_[4];
									  vektor[10]= z_[5];
									  vektor[12]= z_[6];
					   P[8]= fn_mtnom(vektor,13);
				 P[6]+=P[8];
					if(P[8]<= P[0])P[2]+=P[8];	

				while(z2_[3]>0)
				{
					 //z_[5]=0;
					z2_[3]--;
					z1_[4]++;
					z2_[4]=z1_[4];
				    z1_[5]= z_[5];

										  vektor[2]=  z_[1];
										  vektor[4]= z1_[2];
							   			  vektor[6]= z2_[3];
										  vektor[8]= z1_[4];
										  vektor[10]= z_[5];
										  vektor[12]= z_[6];
						   P[8]= fn_mtnom(vektor,13);
					 P[6]+=P[8];
						if(P[8]<= P[0])P[2]+=P[8];

					while(z2_[4]>0)
					{
						// z_[6]=0;
						z2_[4]--;
						z1_[5]++;
						z2_[5]=z1_[5];
						z1_[6]=z_[6];

											  vektor[2]=   z_[1];
											  vektor[4]=  z1_[2];
							   				  vektor[6]=  z2_[3];
											  vektor[8]=  z2_[4];
											  vektor[10]= z1_[5];
											  vektor[12]=  z_[6];
							   P[8]= fn_mtnom(vektor,13);
						 P[6]+=P[8];
							if(P[8]<= P[0])P[2]+=P[8];
			
						while(z2_[5]>0)
						{
							z2_[5]--;
							z1_[6]++;

												  vektor[2]=   z_[1];
												  vektor[4]=  z1_[2];
							   					  vektor[6]=  z2_[3];
												  vektor[8]=  z2_[4];
												  vektor[10]= z2_[5];
												  vektor[12]= z1_[6];
								   P[8]= fn_mtnom(vektor,13);
							 P[6]+=P[8];
								if(P[8]<= P[0])P[2]+=P[8];
						}
					}
				}
			}
		}
	}
		
	//------------------------------------------------------------------------------------------- 7 //
	if(k==7)
	{
		while(z_[1]>0) 
		{
			 //z_[3]=0;
			 z_[1]--;
		     z_[2]++;
			z1_[2]=z_[2];
			z1_[3]=z_[3];
								  vektor[2]=  z_[1];
								  vektor[4]= z1_[2];
							   	  vektor[6]= z1_[3];
								  vektor[8]=  z_[4];
								  vektor[10]= z_[5];
								  vektor[12]= z_[6];
								  vektor[14]= z_[7];
				   P[8]= fn_mtnom(vektor,15);
			 P[6]+=P[8];
				if(P[8]<= P[0])P[2]+=P[8];
	
			while(z1_[2]>0)
			{
				 //z_[4]=0;
				z1_[2]--;
				z1_[3]++;
				z2_[3]=z1_[3];
				z1_[4]= z_[4];
									  vektor[2]=  z_[1];
									  vektor[4]= z1_[2];
							   		  vektor[6]= z1_[3];
									  vektor[8]= z1_[4];
									  vektor[10]= z_[5];
									  vektor[12]= z_[6];
									  vektor[14]= z_[7];
					   P[8]= fn_mtnom(vektor,15);
				 P[6]+=P[8];
					if(P[8]<= P[0])P[2]+=P[8];	

				while(z2_[3]>0)
				{
					// z_[5]=0;
					z2_[3]--;
					z1_[4]++;
					z2_[4]=z1_[4];
				    z1_[5]= z_[5];

										  vektor[2]=  z_[1];
										  vektor[4]= z1_[2];
							   			  vektor[6]= z2_[3];
										  vektor[8]= z1_[4];
										  vektor[10]= z_[5];
										  vektor[12]= z_[6];
										  vektor[14]= z_[7];
						   P[8]= fn_mtnom(vektor,15);
					 P[6]+=P[8];
						if(P[8]<= P[0])P[2]+=P[8];
			
					while(z2_[4]>0)
					{
						// z_[6]=0;
						z2_[4]--;
						z1_[5]++;
						z2_[5]=z1_[5];
						z1_[6]=z_[6];
											  vektor[2]=   z_[1];
											  vektor[4]=  z1_[2];
							   				  vektor[6]=  z2_[3];
											  vektor[8]=  z2_[4];
											  vektor[10]= z1_[5];
											  vektor[12]=  z_[6];
							                  vektor[14]=  z_[7];
							   P[8]= fn_mtnom(vektor,15);
						 P[6]+=P[8];
							if(P[8]<= P[0])P[2]+=P[8];
		
						while(z2_[5]>0)
						{
							//z_[7]=0;
							z2_[5]--;
							z1_[6]++;
							z2_[6]=z1_[6];
							z1_[7]=z_[7];

												  vektor[2]=   z_[1];
												  vektor[4]=  z1_[2];
							   					  vektor[6]=  z2_[3];
												  vektor[8]=  z2_[4];
												  vektor[10]= z2_[5];
												  vektor[12]= z1_[6];
												  vektor[14]=  z_[7];
								   P[8]= fn_mtnom(vektor,15);
							 P[6]+=P[8];
								if(P[8]<= P[0])P[2]+=P[8];
						
							while(z2_[6]>0)
							{
								z2_[6]--;
								z1_[7]++;
													  vektor[2]=   z_[1];
													  vektor[4]=  z1_[2];
							   						  vektor[6]=  z2_[3];
													  vektor[8]=  z2_[4];
													  vektor[10]= z2_[5];
													  vektor[12]= z2_[6];
									                  vektor[14]= z1_[7];
									   P[8]= fn_mtnom(vektor,15);
								 P[6]+=P[8];
									if(P[8]<= P[0])P[2]+=P[8];
							}
						}
					}
				}
			}
		}
	}
		
	//------------------------------------------------------------------------------------------- 8 //
	if(k==8)
	{
		while(z_[1]>0) 
		{
			 //z_[3]=0;
			 z_[1]--;
		     z_[2]++;
			z1_[2]=z_[2];
			z1_[3]=z_[3];
								  vektor[2]=  z_[1];
								  vektor[4]= z1_[2];
							   	  vektor[6]= z1_[3];
								  vektor[8]=  z_[4];
								  vektor[10]= z_[5];
								  vektor[12]= z_[6];
								  vektor[14]= z_[7];
								  vektor[16]= z_[8];
				   P[8]= fn_mtnom(vektor,17);
			 P[6]+=P[8];
				if(P[8]<= P[0])P[2]+=P[8];
					
			while(z1_[2]>0)
			{
				 //z_[4]=0;
				z1_[2]--;
				z1_[3]++;
				z2_[3]=z1_[3];
				z1_[4]= z_[4];
									  vektor[2]=  z_[1];
									  vektor[4]= z1_[2];
							   		  vektor[6]= z1_[3];
									  vektor[8]= z1_[4];
									  vektor[10]= z_[5];
									  vektor[12]= z_[6];
									  vektor[14]= z_[7];
									  vektor[16]= z_[8];
					   P[8]= fn_mtnom(vektor,17);
				 P[6]+=P[8];
					if(P[8]<= P[0])P[2]+=P[8];	

				while(z2_[3]>0)
				{
					 //z_[5]=0;
					z2_[3]--;
					z1_[4]++;

					z2_[4]=z1_[4];
				    z1_[5]= z_[5];
										  vektor[2]=  z_[1];
										  vektor[4]= z1_[2];
							   			  vektor[6]= z2_[3];
										  vektor[8]= z1_[4];
										  vektor[10]= z_[5];
										  vektor[12]= z_[6];
										  vektor[14]= z_[7];
										  vektor[16]= z_[8];
						   P[8]= fn_mtnom(vektor,17);
					 P[6]+=P[8];
						if(P[8]<= P[0])P[2]+=P[8];
					
					while(z2_[4]>0)
					{
						 //z_[6]=0;
						z2_[4]--;
						z1_[5]++;
						z2_[5]=z1_[5];
						z1_[6]=z_[6];
											  vektor[2]=   z_[1];
											  vektor[4]=  z1_[2];
							   				  vektor[6]=  z2_[3];
											  vektor[8]=  z2_[4];
											  vektor[10]= z1_[5];
											  vektor[12]=  z_[6];
							                  vektor[14]=  z_[7];
											  vektor[16]=  z_[8];
							   P[8]= fn_mtnom(vektor,17);
						 P[6]+=P[8];
							if(P[8]<= P[0])P[2]+=P[8];

						while(z2_[5]>0)
						{
							 //z_[7]=0;
							z2_[5]--;
							z1_[6]++;
							z2_[6]=z1_[6];
							z1_[7]=z_[7];
												  vektor[2]=   z_[1];
												  vektor[4]=  z1_[2];
							   					  vektor[6]=  z2_[3];
												  vektor[8]=  z2_[4];
												  vektor[10]= z2_[5];
												  vektor[12]= z1_[6];
												  vektor[14]=  z_[7];
												  vektor[16]=  z_[8];
								   P[8]= fn_mtnom(vektor,17);
							 P[6]+=P[8];
								if(P[8]<= P[0])P[2]+=P[8];
	
							while(z2_[6]>0)
							{
								 //z_[8]=0;
								z2_[6]--;
								z1_[7]++;
						        z2_[7]=z1_[7];
							    z1_[8]=z_[8];
													  vektor[2]=   z_[1];
													  vektor[4]=  z1_[2];
							   						  vektor[6]=  z2_[3];
													  vektor[8]=  z2_[4];
													  vektor[10]= z2_[5];
													  vektor[12]= z2_[6];
									                  vektor[14]= z1_[7];
													  vektor[16]=  z_[8];
									   P[8]= fn_mtnom(vektor,17);
								 P[6]+=P[8];
									if(P[8]<= P[0])P[2]+=P[8];

								while(z2_[7]>0)
								{
									z2_[7]--;
									z1_[8]++;
														  vektor[2]=   z_[1];
														  vektor[4]=  z1_[2];
							   							  vektor[6]=  z2_[3];
														  vektor[8]=  z2_[4];
														  vektor[10]= z2_[5];
														  vektor[12]= z2_[6];
														  vektor[14]= z2_[7];
														  vektor[16]= z1_[8];
										   P[8]= fn_mtnom(vektor,17);
									 P[6]+=P[8];
										if(P[8]<= P[0])P[2]+=P[8];
								}
							}
						}
					}
				}
			}
		}
	}
	//------------------------------------------------------------------------------------------- 9 //
	if(k==9)
	{
		while(z_[1]>0) 
		{
			 //z_[3]=0;
			 z_[1]--;
		     z_[2]++;
			z1_[2]=z_[2];
			z1_[3]=z_[3];
								  vektor[2]=  z_[1];
								  vektor[4]= z1_[2];
							   	  vektor[6]= z1_[3];
								  vektor[8]=  z_[4];
								  vektor[10]= z_[5];
								  vektor[12]= z_[6];
								  vektor[14]= z_[7];
								  vektor[16]= z_[8];
								  vektor[18]= z_[9];
				   P[8]= fn_mtnom(vektor,19);
			 P[6]+=P[8];
				if(P[8]<= P[0])P[2]+=P[8];

			while(z1_[2]>0)
			{
				 //z_[4]=0;
				z1_[2]--;
				z1_[3]++;
				z2_[3]=z1_[3];
				z1_[4]= z_[4];
									  vektor[2]=  z_[1];
									  vektor[4]= z1_[2];
							   		  vektor[6]= z1_[3];
									  vektor[8]= z1_[4];
									  vektor[10]= z_[5];
									  vektor[12]= z_[6];
									  vektor[14]= z_[7];
									  vektor[16]= z_[8];
									  vektor[18]= z_[9];
					   P[8]= fn_mtnom(vektor,19);
				 P[6]+=P[8];
					if(P[8]<= P[0])P[2]+=P[8];	

				while(z2_[3]>0)
				{
					 //z_[5]=0;
					z2_[3]--;
					z1_[4]++;

					z2_[4]=z1_[4];
				    z1_[5]= z_[5];
										  vektor[2]=  z_[1];
										  vektor[4]= z1_[2];
							   			  vektor[6]= z2_[3];
										  vektor[8]= z1_[4];
										  vektor[10]= z_[5];
										  vektor[12]= z_[6];
										  vektor[14]= z_[7];
										  vektor[16]= z_[8];
										  vektor[18]= z_[9];
						   P[8]= fn_mtnom(vektor,19);
					 P[6]+=P[8];
						if(P[8]<= P[0])P[2]+=P[8];
					
					while(z2_[4]>0)
					{
						 //z_[6]=0;
						z2_[4]--;
						z1_[5]++;

						z2_[5]=z1_[5];
						z1_[6]=z_[6];
											  vektor[2]=   z_[1];
											  vektor[4]=  z1_[2];
							   				  vektor[6]=  z2_[3];
											  vektor[8]=  z2_[4];
											  vektor[10]= z1_[5];
											  vektor[12]=  z_[6];
							                  vektor[14]=  z_[7];
											  vektor[16]=  z_[8];
											  vektor[18]=  z_[9];
							   P[8]= fn_mtnom(vektor,19);
						 P[6]+=P[8];
							if(P[8]<= P[0])P[2]+=P[8];
				
						while(z2_[5]>0)
						{
							 //z_[7]=0;
							z2_[5]--;
							z1_[6]++;
							z2_[6]=z1_[6];
							z1_[7]=z_[7];
												  vektor[2]=   z_[1];
												  vektor[4]=  z1_[2];
							   					  vektor[6]=  z2_[3];
												  vektor[8]=  z2_[4];
												  vektor[10]= z2_[5];
												  vektor[12]= z1_[6];
												  vektor[14]=  z_[7];
												  vektor[16]=  z_[8];
												  vektor[18]=  z_[9];
								   P[8]= fn_mtnom(vektor,19);
							 P[6]+=P[8];
								if(P[8]<= P[0])P[2]+=P[8];
				
							while(z2_[6]>0)
							{
								 //z_[8]=0;
								z2_[6]--;
								z1_[7]++;
						        z2_[7]=z1_[7];
							    z1_[8]=z_[8];
													  vektor[2]=   z_[1];
													  vektor[4]=  z1_[2];
							   						  vektor[6]=  z2_[3];
													  vektor[8]=  z2_[4];
													  vektor[10]= z2_[5];
													  vektor[12]= z2_[6];
									                  vektor[14]= z1_[7];
													  vektor[16]=  z_[8];
													  vektor[18]=  z_[9];
									   P[8]= fn_mtnom(vektor,19);
								 P[6]+=P[8];
									if(P[8]<= P[0])P[2]+=P[8];

								while(z2_[7]>0)
								{
									 //z_[9]=0;
									z2_[7]--;
									z1_[8]++;
									z2_[8]=z1_[8];
							        z1_[9]=z_[9];
														  vektor[2]=   z_[1];
														  vektor[4]=  z1_[2];
							   							  vektor[6]=  z2_[3];
														  vektor[8]=  z2_[4];
														  vektor[10]= z2_[5];
														  vektor[12]= z2_[6];
														  vektor[14]= z2_[7];
														  vektor[16]= z1_[8];
														  vektor[18]=  z_[9];
										   P[8]= fn_mtnom(vektor,19);
									 P[6]+=P[8];
										if(P[8]<= P[0])P[2]+=P[8];

									while(z2_[8]>0)
									{
							         	z2_[8]--;
										z1_[9]++;
															  vektor[2]=   z_[1];
															  vektor[4]=  z1_[2];
							   								  vektor[6]=  z2_[3];
															  vektor[8]=  z2_[4];
															  vektor[10]= z2_[5];
															  vektor[12]= z2_[6];
															  vektor[14]= z2_[7];
															  vektor[16]= z2_[8];
											                  vektor[18]= z1_[9];
											   P[8]= fn_mtnom(vektor,19);
										 P[6]+=P[8];
											if(P[8]<= P[0])P[2]+=P[8];
									}
								}
							}
						}
					}
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------- 10 //
	if(k==10)
	{
		while(z_[1]>0) 
		{
			 //z_[3]=0;
			 z_[1]--;
		     z_[2]++;
			z1_[2]=z_[2];
			z1_[3]=z_[3];
								  vektor[2]=  z_[1];
								  vektor[4]= z1_[2];
							   	  vektor[6]= z1_[3];
								  vektor[8]=  z_[4];
								  vektor[10]= z_[5];
								  vektor[12]= z_[6];
								  vektor[14]= z_[7];
								  vektor[16]= z_[8];
								  vektor[18]=  z_[9];
								  vektor[20]= z_[10];
				   P[8]= fn_mtnom(vektor,21);
			 P[6]+=P[8];
				if(P[8]<= P[0])P[2]+=P[8];

			while(z1_[2]>0)
			{
				 //z_[4]=0;
				z1_[2]--;
				z1_[3]++;
				z2_[3]=z1_[3];
				z1_[4]= z_[4];
									  vektor[2]=  z_[1];
									  vektor[4]= z1_[2];
							   		  vektor[6]= z1_[3];
									  vektor[8]= z1_[4];
									  vektor[10]= z_[5];
									  vektor[12]= z_[6];
									  vektor[14]= z_[7];
									  vektor[16]= z_[8];
									  vektor[18]=  z_[9];
									  vektor[20]= z_[10];
					   P[8]= fn_mtnom(vektor,21);
				 P[6]+=P[8];
					if(P[8]<= P[0])P[2]+=P[8];	

				while(z2_[3]>0)
				{
					//z_[5]=0;
					z2_[3]--;
					z1_[4]++;
					z2_[4]=z1_[4];
				    z1_[5]= z_[5];
										  vektor[2]=  z_[1];
										  vektor[4]= z1_[2];
							   			  vektor[6]= z2_[3];
										  vektor[8]= z1_[4];
										  vektor[10]= z_[5];
										  vektor[12]= z_[6];
										  vektor[14]= z_[7];
										  vektor[16]= z_[8];
										  vektor[18]=  z_[9];
										  vektor[20]= z_[10];
						   P[8]= fn_mtnom(vektor,21);
					 P[6]+=P[8];
						if(P[8]<= P[0])P[2]+=P[8];
				
					while(z2_[4]>0)
					{
						 //z_[6]=0;
						z2_[4]--;
						z1_[5]++;
						z2_[5]=z1_[5];
						z1_[6]=z_[6];
											  vektor[2]=   z_[1];
											  vektor[4]=  z1_[2];
							   				  vektor[6]=  z2_[3];
											  vektor[8]=  z2_[4];
											  vektor[10]= z1_[5];
											  vektor[12]=  z_[6];
							                  vektor[14]=  z_[7];
											  vektor[16]=  z_[8];
											  vektor[18]=  z_[9];
											  vektor[20]= z_[10];
							   P[8]= fn_mtnom(vektor,21);
						 P[6]+=P[8];
							if(P[8]<= P[0])P[2]+=P[8];

						while(z2_[5]>0)
						{
							 //z_[7]=0;
							z2_[5]--;
							z1_[6]++;
							z2_[6]=z1_[6];
							z1_[7]=z_[7];
												  vektor[2]=   z_[1];
												  vektor[4]=  z1_[2];
							   					  vektor[6]=  z2_[3];
												  vektor[8]=  z2_[4];
												  vektor[10]= z2_[5];
												  vektor[12]= z1_[6];
												  vektor[14]=  z_[7];
												  vektor[16]=  z_[8];
												  vektor[18]=  z_[9];
												  vektor[20]= z_[10];
								   P[8]= fn_mtnom(vektor,21);
							 P[6]+=P[8];
								if(P[8]<= P[0])P[2]+=P[8];

							while(z2_[6]>0)
							{
								 //z_[8]=0;
								z2_[6]--;
								z1_[7]++;
						        z2_[7]=z1_[7];
							    z1_[8]=z_[8];
													  vektor[2]=   z_[1];
													  vektor[4]=  z1_[2];
							   						  vektor[6]=  z2_[3];
													  vektor[8]=  z2_[4];
													  vektor[10]= z2_[5];
													  vektor[12]= z2_[6];
									                  vektor[14]= z1_[7];
													  vektor[16]=  z_[8];
													  vektor[18]=  z_[9];
													  vektor[20]= z_[10];
									   P[8]= fn_mtnom(vektor,21);
								 P[6]+=P[8];
									if(P[8]<= P[0])P[2]+=P[8];

								while(z2_[7]>0)
								{
									 //z_[9]=0;
									z2_[7]--;
									z1_[8]++;
									z2_[8]=z1_[8];
							        z1_[9]=z_[9];
														  vektor[2]=   z_[1];
														  vektor[4]=  z1_[2];
							   							  vektor[6]=  z2_[3];
														  vektor[8]=  z2_[4];
														  vektor[10]= z2_[5];
														  vektor[12]= z2_[6];
														  vektor[14]= z2_[7];
														  vektor[16]= z1_[8];
														  vektor[18]=  z_[9];
														  vektor[20]= z_[10];
										   P[8]= fn_mtnom(vektor,21);
									 P[6]+=P[8];
										if(P[8]<= P[0])P[2]+=P[8];

									while(z2_[8]>0)
									{
								         //z_[10]=0;
										z2_[8]--;
										z1_[9]++;
										z2_[9]=z1_[9];
							            z1_[10]=z_[10];
															  vektor[2]=   z_[1];
															  vektor[4]=  z1_[2];
							   								  vektor[6]=  z2_[3];
															  vektor[8]=  z2_[4];
															  vektor[10]= z2_[5];
															  vektor[12]= z2_[6];
															  vektor[14]= z2_[7];
															  vektor[16]= z2_[8];
											                  vektor[18]= z1_[9];
															  vektor[20]= z_[10];
											   P[8]= fn_mtnom(vektor,21);
										 P[6]+=P[8];
											if(P[8]<= P[0])P[2]+=P[8];

										while(z2_[9]>0)
										{
											z2_[9]--;
											z1_[10]++;
																  vektor[2]=   z_[1];
																  vektor[4]=  z1_[2];
							   									  vektor[6]=  z2_[3];
																  vektor[8]=  z2_[4];
																  vektor[10]= z2_[5];
																  vektor[12]= z2_[6];
																  vektor[14]= z2_[7];
																  vektor[16]= z2_[8];
																  vektor[18]= z2_[9];
																  vektor[20]= z1_[10];
												   
												   P[8]= fn_mtnom(vektor,21);
											 P[6]+=P[8];
												if(P[8]<= P[0])P[2]+=P[8];
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------- 11 //
	if(k==11)
	{
		while(z_[1]>0) 
		{
			 //z_[3]=0;
			 z_[1]--;
		     z_[2]++;
			z1_[2]=z_[2];
			z1_[3]=z_[3];
								  vektor[2]=  z_[1];
								  vektor[4]= z1_[2];
							   	  vektor[6]= z1_[3];
								  vektor[8]=  z_[4];
								  vektor[10]= z_[5];
								  vektor[12]= z_[6];
								  vektor[14]= z_[7];
								  vektor[16]= z_[8];
								  vektor[18]=  z_[9];
								  vektor[20]= z_[10];
								  vektor[22]= z_[11];
				   P[8]= fn_mtnom(vektor,23);
			 P[6]+=P[8];
				if(P[8]<= P[0])P[2]+=P[8];

			while(z1_[2]>0)
			{
				 //z_[4]=0;
				z1_[2]--;
				z1_[3]++;
				z2_[3]=z1_[3];
				z1_[4]= z_[4];
  				                      vektor[2]=  z_[1];
									  vektor[4]= z1_[2];
							   		  vektor[6]= z1_[3];
									  vektor[8]= z1_[4];
									  vektor[10]= z_[5];
									  vektor[12]= z_[6];
									  vektor[14]= z_[7];
									  vektor[16]= z_[8];
									  vektor[18]=  z_[9];
									  vektor[20]= z_[10];
									  vektor[22]= z_[11];
					   P[8]= fn_mtnom(vektor,23);
				 P[6]+=P[8];
					if(P[8]<= P[0])P[2]+=P[8];	

				while(z2_[3]>0)
				{
					 //z_[5]=0;
					z2_[3]--;
					z1_[4]++;
					z2_[4]=z1_[4];
				    z1_[5]= z_[5];
										  vektor[2]=  z_[1];
										  vektor[4]= z1_[2];
							   			  vektor[6]= z2_[3];
										  vektor[8]= z1_[4];
										  vektor[10]= z_[5];
										  vektor[12]= z_[6];
										  vektor[14]= z_[7];
										  vektor[16]= z_[8];
										  vektor[18]=  z_[9];
										  vektor[20]= z_[10];
										  vektor[22]= z_[11];
						   P[8]= fn_mtnom(vektor,23);
					 P[6]+=P[8];
						if(P[8]<= P[0])P[2]+=P[8];

					while(z2_[4]>0)
					{
						 //z_[6]=0;
						z2_[4]--;
						z1_[5]++;
						z2_[5]=z1_[5];
						z1_[6]=z_[6];
											  vektor[2]=   z_[1];
											  vektor[4]=  z1_[2];
							   				  vektor[6]=  z2_[3];
											  vektor[8]=  z2_[4];
											  vektor[10]= z1_[5];
											  vektor[12]=  z_[6];
							                  vektor[14]=  z_[7];
											  vektor[16]=  z_[8];
											  vektor[18]=  z_[9];
											  vektor[20]= z_[10];
											  vektor[22]= z_[11];
							   P[8]= fn_mtnom(vektor,23);
						 P[6]+=P[8];
							if(P[8]<= P[0])P[2]+=P[8];
				
						while(z2_[5]>0)
						{
							 //z_[7]=0;
							z2_[5]--;
							z1_[6]++;
							z2_[6]=z1_[6];
							z1_[7]=z_[7];
												  vektor[2]=   z_[1];
												  vektor[4]=  z1_[2];
							   					  vektor[6]=  z2_[3];
												  vektor[8]=  z2_[4];
												  vektor[10]= z2_[5];
												  vektor[12]= z1_[6];
												  vektor[14]=  z_[7];
												  vektor[16]=  z_[8];
												  vektor[18]=  z_[9];
												  vektor[20]= z_[10];
												  vektor[22]= z_[11];
								   P[8]= fn_mtnom(vektor,23);
							 P[6]+=P[8];
								if(P[8]<= P[0])P[2]+=P[8];
						
							while(z2_[6]>0)
							{
								 //z_[8]=0;
								z2_[6]--;
								z1_[7]++;
						        z2_[7]=z1_[7];
							    z1_[8]=z_[8];
													  vektor[2]=   z_[1];
													  vektor[4]=  z1_[2];
							   						  vektor[6]=  z2_[3];
													  vektor[8]=  z2_[4];
													  vektor[10]= z2_[5];
													  vektor[12]= z2_[6];
									                  vektor[14]= z1_[7];
													  vektor[16]=  z_[8];
													  vektor[18]=  z_[9];
													  vektor[20]= z_[10];
													  vektor[22]= z_[11];
									   P[8]= fn_mtnom(vektor,23);
								 P[6]+=P[8];
									if(P[8]<= P[0])P[2]+=P[8];
					
								while(z2_[7]>0)
								{
									 //z_[9]=0;
									z2_[7]--;
									z1_[8]++;
									z2_[8]=z1_[8];
							        z1_[9]=z_[9];
														  vektor[2]=   z_[1];
														  vektor[4]=  z1_[2];
							   							  vektor[6]=  z2_[3];
														  vektor[8]=  z2_[4];
														  vektor[10]= z2_[5];
														  vektor[12]= z2_[6];
														  vektor[14]= z2_[7];
														  vektor[16]= z1_[8];
														  vektor[18]=  z_[9];
														  vektor[20]= z_[10];
														  vektor[22]= z_[11];
										   P[8]= fn_mtnom(vektor,23);
									 P[6]+=P[8];
										if(P[8]<= P[0])P[2]+=P[8];

									while(z2_[8]>0)
									{
								         //z_[10]=0;
										z2_[8]--;
										z1_[9]++;
										z2_[9]=z1_[9];
							            z1_[10]=z_[10];
															  vektor[2]=   z_[1];
															  vektor[4]=  z1_[2];
							   								  vektor[6]=  z2_[3];
															  vektor[8]=  z2_[4];
															  vektor[10]= z2_[5];
															  vektor[12]= z2_[6];
															  vektor[14]= z2_[7];
															  vektor[16]= z2_[8];
											                  vektor[18]= z1_[9];
															  vektor[20]= z_[10];
															  vektor[22]= z_[11];
											   P[8]= fn_mtnom(vektor,23);
										 P[6]+=P[8];
											if(P[8]<= P[0])P[2]+=P[8];

										while(z2_[9]>0)
										{
											//z_[11]=0;
											z2_[9]--;
											z1_[10]++;
											z2_[10]=z1_[10];
							                z1_[11]=z_[11];
																  vektor[2]=   z_[1];
																  vektor[4]=  z1_[2];
							   									  vektor[6]=  z2_[3];
																  vektor[8]=  z2_[4];
																  vektor[10]= z2_[5];
																  vektor[12]= z2_[6];
																  vektor[14]= z2_[7];
																  vektor[16]= z2_[8];
																  vektor[18]= z2_[9];
																  vektor[20]= z1_[10];
																  vektor[22]= z_[11];
												   
												   P[8]= fn_mtnom(vektor,23);
											 P[6]+=P[8];
												if(P[8]<= P[0])P[2]+=P[8];

											while(z2_[10]>0)
											{
												z2_[10]--;
												z1_[11]++;
																	  vektor[2]=   z_[1];
																	  vektor[4]=  z1_[2];
							   										  vektor[6]=  z2_[3];
																	  vektor[8]=  z2_[4];
																	  vektor[10]= z2_[5];
																	  vektor[12]= z2_[6];
																	  vektor[14]= z2_[7];
																	  vektor[16]= z2_[8];
																	  vektor[18]= z2_[9];
																	  vektor[20]= z2_[10];
																	  vektor[22]= z1_[11];
													   
													   P[8]= fn_mtnom(vektor,23);
												 P[6]+=P[8];
													if(P[8]<= P[0])P[2]+=P[8];
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	//------------------------------------------------------------------------------------------- 12 //
	if(k==12)
	{
		while(z_[1]>0) 
		{
			 //z_[3]=0;
			 z_[1]--;
		     z_[2]++;
			z1_[2]=z_[2];
			z1_[3]=z_[3];
								  vektor[2]=  z_[1];
								  vektor[4]= z1_[2];
							   	  vektor[6]= z1_[3];
								  vektor[8]=  z_[4];
								  vektor[10]= z_[5];
								  vektor[12]= z_[6];
								  vektor[14]= z_[7];
								  vektor[16]= z_[8];
								  vektor[18]=  z_[9];
								  vektor[20]= z_[10];
								  vektor[22]= z_[11];
								  vektor[24]= z_[12];
				   P[8]= fn_mtnom(vektor,25);
			 P[6]+=P[8];
				if(P[8]<= P[0])P[2]+=P[8];

			while(z1_[2]>0)
			{
				 //z_[4]=0;
				z1_[2]--;
				z1_[3]++;
				z2_[3]=z1_[3];
				z1_[4]= z_[4];
									  vektor[2]=  z_[1];
									  vektor[4]= z1_[2];
							   		  vektor[6]= z1_[3];
									  vektor[8]= z1_[4];
									  vektor[10]= z_[5];
									  vektor[12]= z_[6];
									  vektor[14]= z_[7];
									  vektor[16]= z_[8];
									  vektor[18]=  z_[9];
									  vektor[20]= z_[10];
									  vektor[22]= z_[11];
									  vektor[24]= z_[12];
					   P[8]= fn_mtnom(vektor,25);
				 P[6]+=P[8];
					if(P[8]<= P[0])P[2]+=P[8];	

				while(z2_[3]>0)
				{
					 //z_[5]=0;
					z2_[3]--;
					z1_[4]++;
					z2_[4]=z1_[4];
				    z1_[5]= z_[5];
										  vektor[2]=  z_[1];
										  vektor[4]= z1_[2];
							   			  vektor[6]= z2_[3];
										  vektor[8]= z1_[4];
										  vektor[10]= z_[5];
										  vektor[12]= z_[6];
										  vektor[14]= z_[7];
										  vektor[16]= z_[8];
										  vektor[18]=  z_[9];
										  vektor[20]= z_[10];
										  vektor[22]= z_[11];
										  vektor[24]= z_[12];
						   P[8]= fn_mtnom(vektor,25);
					 P[6]+=P[8];
						if(P[8]<= P[0])P[2]+=P[8];
		
					while(z2_[4]>0)
					{
						 //z_[6]=0;
						z2_[4]--;
						z1_[5]++;
						z2_[5]=z1_[5];
						z1_[6]=z_[6];
											  vektor[2]=   z_[1];
											  vektor[4]=  z1_[2];
							   				  vektor[6]=  z2_[3];
											  vektor[8]=  z2_[4];
											  vektor[10]= z1_[5];
											  vektor[12]=  z_[6];
							                  vektor[14]=  z_[7];
											  vektor[16]=  z_[8];
											  vektor[18]=  z_[9];
											  vektor[20]= z_[10];
											  vektor[22]= z_[11];
											  vektor[24]= z_[12];
							   P[8]= fn_mtnom(vektor,25);
						 P[6]+=P[8];
							if(P[8]<= P[0])P[2]+=P[8];

						while(z2_[5]>0)
						{
							 //z_[7]=0;
							z2_[5]--;
							z1_[6]++;
							z2_[6]=z1_[6];
							z1_[7]=z_[7];
												  vektor[2]=   z_[1];
												  vektor[4]=  z1_[2];
							   					  vektor[6]=  z2_[3];
												  vektor[8]=  z2_[4];
												  vektor[10]= z2_[5];
												  vektor[12]= z1_[6];
												  vektor[14]=  z_[7];
												  vektor[16]=  z_[8];
												  vektor[18]=  z_[9];
												  vektor[20]= z_[10];
												  vektor[22]= z_[11];
												  vektor[24]= z_[12];
								   P[8]= fn_mtnom(vektor,25);
							 P[6]+=P[8];
								if(P[8]<= P[0])P[2]+=P[8];
	
							while(z2_[6]>0)
							{
								 //z_[8]=0;
								z2_[6]--;
								z1_[7]++;
						        z2_[7]=z1_[7];
							    z1_[8]=z_[8];
													  vektor[2]=   z_[1];
													  vektor[4]=  z1_[2];
							   						  vektor[6]=  z2_[3];
													  vektor[8]=  z2_[4];
													  vektor[10]= z2_[5];
													  vektor[12]= z2_[6];
									                  vektor[14]= z1_[7];
													  vektor[16]=  z_[8];
													  vektor[18]=  z_[9];
													  vektor[20]= z_[10];
													  vektor[22]= z_[11];
                                                      vektor[24]= z_[12];
									   P[8]= fn_mtnom(vektor,25);
								 P[6]+=P[8];
									if(P[8]<= P[0])P[2]+=P[8];

								while(z2_[7]>0)
								{
									 //z_[9]=0;
									z2_[7]--;
									z1_[8]++;
									z2_[8]=z1_[8];
							        z1_[9]=z_[9];
														  vektor[2]=   z_[1];
														  vektor[4]=  z1_[2];
							   							  vektor[6]=  z2_[3];
														  vektor[8]=  z2_[4];
														  vektor[10]= z2_[5];
														  vektor[12]= z2_[6];
														  vektor[14]= z2_[7];
														  vektor[16]= z1_[8];
														  vektor[18]=  z_[9];
														  vektor[20]= z_[10];
														  vektor[22]= z_[11];
														  vektor[24]= z_[12];
										   P[8]= fn_mtnom(vektor,25);
									 P[6]+=P[8];
										if(P[8]<= P[0])P[2]+=P[8];

									while(z2_[8]>0)
									{
								         //z_[10]=0;
										z2_[8]--;
										z1_[9]++;
										z2_[9]=z1_[9];
							            z1_[10]=z_[10];
															  vektor[2]=   z_[1];
															  vektor[4]=  z1_[2];
							   								  vektor[6]=  z2_[3];
															  vektor[8]=  z2_[4];
															  vektor[10]= z2_[5];
															  vektor[12]= z2_[6];
															  vektor[14]= z2_[7];
															  vektor[16]= z2_[8];
											                  vektor[18]= z1_[9];
															  vektor[20]= z_[10];
															  vektor[22]= z_[11];
															  vektor[24]= z_[12];
											   P[8]= fn_mtnom(vektor,25);
										 P[6]+=P[8];
											if(P[8]<= P[0])P[2]+=P[8];

										while(z2_[9]>0)
										{
											//z_[11]=0;
											z2_[9]--;
											z1_[10]++;
											z2_[10]=z1_[10];
							                z1_[11]=z_[11];
																  vektor[2]=   z_[1];
																  vektor[4]=  z1_[2];
							   									  vektor[6]=  z2_[3];
																  vektor[8]=  z2_[4];
																  vektor[10]= z2_[5];
																  vektor[12]= z2_[6];
																  vektor[14]= z2_[7];
																  vektor[16]= z2_[8];
																  vektor[18]= z2_[9];
																  vektor[20]= z1_[10];
																  vektor[22]= z_[11];
																  vektor[24]= z_[12];
												   
												   P[8]= fn_mtnom(vektor,25);
											 P[6]+=P[8];
												if(P[8]<= P[0])P[2]+=P[8];

											while(z2_[10]>0)
											{
													//z_[12]=0;
												z2_[10]--;
												z1_[11]++;
												z2_[11]=z1_[11];
							                    z1_[12]=z_[12];
																	  vektor[2]=   z_[1];
																	  vektor[4]=  z1_[2];
							   										  vektor[6]=  z2_[3];
																	  vektor[8]=  z2_[4];
																	  vektor[10]= z2_[5];
																	  vektor[12]= z2_[6];
																	  vektor[14]= z2_[7];
																	  vektor[16]= z2_[8];
																	  vektor[18]= z2_[9];
																	  vektor[20]= z2_[10];
																	  vektor[22]= z1_[11];
																	  vektor[24]= z_[12];
													   
													   P[8]= fn_mtnom(vektor,25);
												 P[6]+=P[8];
													if(P[8]<= P[0])P[2]+=P[8];

												while(z2_[11]>0)
												{
													z2_[11]--;
													z1_[12]++;
																		  vektor[2]=   z_[1];
																		  vektor[4]=  z1_[2];
							   											  vektor[6]=  z2_[3];
																		  vektor[8]=  z2_[4];
																		  vektor[10]= z2_[5];
																		  vektor[12]= z2_[6];
																		  vektor[14]= z2_[7];
																		  vektor[16]= z2_[8];
																		  vektor[18]= z2_[9];
																		  vektor[20]= z2_[10];
																		  vektor[22]= z2_[11];
																		  vektor[24]= z1_[12];
														   
														   P[8]= fn_mtnom(vektor,25);
													 P[6]+=P[8];
														if(P[8]<= P[0])P[2]+=P[8];
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------- k //
	if(k>12)
	{
		for (iLauf = 1; iLauf <=  zn; iLauf++)index[iLauf]=0;
		                                      index[1]=-1;
		
		for (iLauf = 1; iLauf <=  4; iLauf++)P[iLauf]=0;
		
		while(1)
		{
			for (iLauf = 1; iLauf <=  zn; iLauf++) // allgemeine index generierung 
			{				
				if(iLauf == 1)
				{ 
					index[1]++;
				}

				if(index[iLauf] > n) 
				{ 
					index[iLauf] = 0;
					index[iLauf+1] += 1;	
				}
			}
												   sum=0;
			for (iLauf = 1; iLauf <=  zn; iLauf++){sum+=index[iLauf]; if(sum >n){ sw=1;break;}}

			if(sw==0 && sum==n)
			{
				for (iLauf = 2; iLauf <=  zn*2; iLauf+=2)
				{
										  vektor[iLauf]= index[i_];i_++;				    
				}
				i_=1;		
						  P[1]= fn_mtnom(vektor,zn*2+1);
					P[3]+=P[1];
					   if(P[1]<= P[0])P[2]+=P[1];	
				 
				 printf("\r%.14f                    ", P[3] );
			}
			sw=0;
				
			if(index[zn] == n) break;
		}	
	}

	printf("\r                                               \r" );

	fn_erg= P[2];

	return 0;
};