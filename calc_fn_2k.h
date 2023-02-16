//----------------------------------------------------------------------------------------------------| calc_ funktionen, 2^k Kontingenzfelder, SCHRAUSSER 2010	 //

double fn_2khg(double wert[100], int zn);

double fn_2khg(double wert[100], int zn)// hypergeometrische Punkt-Wahrscheinlichkeit P0 zu 2^k - Feldern // HG0 z11,...,z2hk
{
	int iLauf, jLauf, kLauf, nr=1, index[10], felder = 1;
	long double fLauf, S_[20], Z_[20], N_[100], N1_, Z1_, n_=0,k_,x_, fact, P0_=1;
	double pos[10]; 

	k_= (1/log(2))*log(zn); //ordnung k  (max zn=64, max k=6)
	
	if (k_ < 2 || k_ != floor(k_)) {printf("\n\ndesign.0 '2^k= %i, k= %.2f'",  zn, k_); exit(0);}// k >1, ganzzahlig

	for(jLauf=1; jLauf<= zn; jLauf++)  n_+=wert[jLauf];// n
	for(iLauf=1; iLauf<= 2*k_; iLauf++) S_[iLauf]=0;//S_ =0

	//summen S
	for(iLauf = 1; iLauf <= k_; iLauf++) index[iLauf] = 1;
	
	while (felder <= zn) // durchlauf über 2^k zellen (zn)
	{
		for(iLauf = 1; iLauf <= k_; iLauf++)
		{
			                 pos[iLauf] = index[iLauf]+2*iLauf-2; // feldpositions index 
		
	                                 for(kLauf= 1; kLauf <= 2*k_; kLauf++) 
			if(index[iLauf]+2*iLauf-2 == kLauf )
			{
				S_[kLauf]+=wert[nr]; // summierung
			}
		}
		nr++; //wertzähler
		
		for (jLauf = 1; jLauf <= k_; jLauf++) // index generierung
		{				
			if(jLauf == 1)
			{ 
				index[1]++;
			}
		
			if(index[jLauf] == 3) 
			{ 
				index[jLauf] = 1;
				index[jLauf+1] += 1;	
			}
		}
		//printf (" %i\n", felder);
		felder++;
	}	

	//bildschirmausgabe	
	//printf("\n");
	//for(kLauf= 1; kLauf <= 2*k_; kLauf++) printf("S%i= %.0f \n",kLauf, S_[kLauf]);//


	// Punktwahrscheinlichkeit P0 
/**/
						   fact = n_;
	for(jLauf = 0; jLauf < fact; jLauf++) //n - faktoriellzerlegung
	{
		for(iLauf=1; iLauf<= 2*k_; iLauf++) Z_[iLauf]=1; //auf 1
		for(iLauf=1; iLauf<= zn; iLauf++) N_[iLauf]=1; //auf 1
		Z1_=N1_=1;
				                                                   for(kLauf = 1; kLauf <= 2*k_; kLauf++) //randsummen
		for(fLauf =   S_[kLauf]-jLauf; fLauf >= 2; fLauf -= fact)	Z_[kLauf] *= fLauf;
		
		for(fLauf =   n_-jLauf; fLauf >= 2; fLauf -= fact)	N1_ *= fLauf; //n

		                                                           for(kLauf = 1; kLauf <=zn; kLauf++) //zellen
		for(fLauf =   wert[kLauf]-jLauf; fLauf >= 2; fLauf -= fact)	N_[kLauf] *= fLauf;

					  for(kLauf = 1; kLauf <= 2*k_; kLauf++)Z1_*= Z_[kLauf];

							                                    N1_=pow(N1_,k_-1);
							for(kLauf = 1; kLauf <= zn; kLauf++)N1_*= N_[kLauf];

							                            x_= Z1_/N1_;
		                                    P0_ = P0_ * x_;
	}

	fn_erg=P0_;

	return fn_erg;
}

double fn_kfa(double wert[100], int zn) // x2-wert zu 2^k - Feldern // KFA z11,...,z2hk
{
	int iLauf,jLauf,kLauf,i1=1,i2=0, nr=1;
	double  S_[20], fe_[100], chi[100], n=0, k_;
	double pos[10];
	int index[10], felder = 1; 

	fn_erg=0;

	k_= (1/log(2))*log(zn); //ordnung k (max zn=64, max k=6)
	if (k_ < 2 || k_ != floor(k_)) {printf("\n\ndesign.0 '2^k= %i, k= %.2f'",  zn, k_); exit(0);}// k >1, ganzzahlig
	
	for(iLauf=1; iLauf<= zn; iLauf++) n+= wert[iLauf]; // n
	for(iLauf=1; iLauf<= 2*k_; iLauf++) S_[iLauf]=0;//S_ =0
	for(kLauf= 1; kLauf <= pow(2,k_); kLauf++) fe_[kLauf] = 1; //fe =1
	
	//printf("\n\n");

	//summen
	for(iLauf = 1; iLauf <= k_; iLauf++){index[iLauf] = 1;}
	
	while (felder <= zn) // durchlauf über 2 hoch k zellen zn
	{
		for(iLauf = 1; iLauf <= k_; iLauf++)
		{
			                 pos[iLauf] = index[iLauf]+2*iLauf-2; // feldpositions index 
			//printf ("%.0f ", pos[iLauf]); 
		
	                                 for(kLauf= 1; kLauf <= 2*k_; kLauf++) 
			if(index[iLauf]+2*iLauf-2 == kLauf )
			{
				S_[kLauf]+=wert[nr]; // summierung
			}
		}
		nr++; //wertzähler
		
		for (jLauf = 1; jLauf <= k_; jLauf++) // index generierung
		{				
			if(jLauf == 1)
			{ 
				index[1]++;
			}
		
			if(index[jLauf] == 3) 
			{ 
				index[jLauf] = 1;
				index[jLauf+1] += 1;	
			}
		}
	//	printf (" %i\n", felder);
		felder++;
	}
	
	//bildschirmausgabe//
	//for(kLauf= 1; kLauf <= 2*k_; kLauf++) printf("S%i= %.0f \n",kLauf, S_[kLauf]);

	// fe summen

	felder = 1; nr=1;
	
	for(iLauf = 1; iLauf <= k_; iLauf++){index[iLauf] = 1;}
	
	while (felder <= zn) // durchlauf über 2 hoch k zellen (zn)
	{
		for(iLauf = 1; iLauf <= k_; iLauf++)
		{
			                 pos[iLauf] = index[iLauf]+2*iLauf-2; // feldpositions index 
			//printf ("%.0f ", pos[iLauf]); 
		
	                                 for(kLauf= 1; kLauf <= 2*k_; kLauf++) 
			if(index[iLauf]+2*iLauf-2 == kLauf )
			{
				fe_[nr]*=S_[kLauf];// fe summierung
			}
		}
		nr++; //wertzähler
		
		for (jLauf = 1; jLauf <= k_; jLauf++) // index generierung
		{				
			if(jLauf == 1)
			{ 
				index[1]++;
			}
		
			if(index[jLauf] == 3) 
			{ 
				index[jLauf] = 1;
				index[jLauf+1] += 1;	
			}
		}
	//	printf (" %i\n", felder);
		felder++;
	}

	for(kLauf= 1; kLauf <= pow(2,k_); kLauf++) {fe_[kLauf] = fe_[kLauf]/pow(n,k_-1);}
	for(kLauf= 1; kLauf <= pow(2,k_); kLauf++) {chi[kLauf] = pow(wert[kLauf]-fe_[kLauf],2)/fe_[kLauf]; fn_erg+= chi[kLauf];}
	
	//bildschirmausgabe
	//printf("\n");
	//for(kLauf= 1; kLauf <= pow(2,k_); kLauf++) { printf("fe%i= %f \n",kLauf, fe_[kLauf]);}//
	//printf("\n");	//
	//for(kLauf= 1; kLauf <= pow(2,k_); kLauf++)  printf("chi%i= %f \n",kLauf, chi[kLauf]);	//
	
	return 0;
}

long double fn_2kp2(double wert[100], int zn, int sw_) // hypergeometrische Wahrscheinlichkeit, 2-seitiges sig.- Niveau pexact2 zu 2^k - Feldern // (1) HG2 z11,...,z2hk  //   
//                                                     // Kombinationen C zu 2^k - Feldern                                                       // (2) CHG z11,...,z2hk  //
{
	int           Lauf[25], nr=1, index[10],  felder = 1, zlr[25];
	long double  dLauf[100], P[2], p[2], z_[100], S_[20],n_=0, k_, pos[10],max[10],sum[20],vektor[5],sw=0;//
		
	k_= (1/log(2))*log(zn); //ordnung k  (max zn=64, max k=6)
	
	if (k_<2 || k_!=floor(k_)) { printf("\n\ndesign.0 '2^k= %i, k= %.2f'", zn, k_); exit(0); } // k >1, ganzzahlig

	p[0]=0;
	p[2]=0;
	
	for(Lauf[1]=1; Lauf[1]<= zn;   Lauf[1]++)  n_+=wert[Lauf[1]];    // n
	for(Lauf[1]=1; Lauf[1]<= 2*k_; Lauf[1]++)        S_[Lauf[1]]= 0; // S_ =0
	for(Lauf[1]=0; Lauf[1]<  25;   Lauf[1]++)       zlr[Lauf[1]]= 0; // zlr =0
	for(Lauf[1]=0; Lauf[1]<  20;   Lauf[1]++)       sum[Lauf[1]]= 0; // sum =0
	for(Lauf[1]=1; Lauf[1]<= k_;   Lauf[1]++)     index[Lauf[1]]= 1; // Randsummen S
	for(Lauf[1]=1; Lauf[1]<= 100;  Lauf[1]++)     dLauf[Lauf[1]]= 0; // 
	
	while (felder <= zn) // durchlauf über 2^k zellen (zn)
	{
		for(Lauf[1]=1; Lauf[1]<=k_; Lauf[1]++)
		{
			                    pos[Lauf[1]]= index[Lauf[1]]+2*Lauf[1]-2; // feldpositions index 
		
	                                     for(Lauf[3]= 1; Lauf[3]<=2*k_; Lauf[3]++) 
			if(index[Lauf[1]]+2*Lauf[1]-2 == Lauf[3] )
			{
				S_[Lauf[3]]+=wert[nr]; // summierung
			}
		}
		nr++; //wertzähler
		
		for (Lauf[1]=1; Lauf[1]<=k_; Lauf[1]++) // index generierung
		{				
			if(Lauf[1]==1)
			{ 
				index[1]++;
			}
		
			if(index[Lauf[1]]==3) 
			{ 
				index[Lauf[1]]=1;
				index[Lauf[1]+1]+=1;	
			}
		}
		felder++;
	}	

	//bildschirmausgabe//
	//for(Lauf[1]= 1;Lauf[1] <= 2*k_; Lauf[1]++) printf("S%i= %.0f \n",Lauf[1], S_[Lauf[1]]);

	P[0]= fn_2khg(wert, zn); //P0

	printf("\n\n");
	if(sw_==1)printf("computing Pi ...");
	if(sw_==2)printf("computing C ...");

	Lauf[1]=0; Lauf[2]=0;

	max[0]= fn_sort(S_,2*k_,2);

	max[1]= S_[5]; 
	max[2]= S_[6];

	// Exakt hypergeometrische Wahrscheinlichkeits-Verteilung bei Randsummen S Fixierung    
	// 2^2, 2^3, 2^4 in geschwindigkeits-maximierender explizitcodierung -> schleifenminimierung //
	// 2^5, 2^6 lange rechenzeiten über allgemein algorithmus (max 2^oo) 
	// 2^7 ... begrenzt durch felddimensionierung 
	// ---------------------------------------------------------------------------------------------------------------- 2^2 //
	if(k_==2) // (Fisher Exact Test)
	{
		               vektor[1]=wert[1];
				       vektor[2]=wert[4];
		max[0]=fn_sort(vektor,2,1); // minimalfrequenz

		z_[1] = wert[1]-max[0];
		z_[2] = S_[3]-z_[1];
		z_[3] = S_[1]-z_[1];
		z_[4] = n_-z_[1]-z_[2]-z_[3];

		while(1)
		{
			if(sw_==1)
			{
					  P[1]= fn_2khg(z_, zn);  // Pi
				  if( P[1]<=P[0]) p[2]+=P[1]; // p2= Pi <= P0
				p[0]+=P[1];
				
				//printf("\r%.14f",p[0]);
			}

			if(sw_==2){ zlr[0]++;  }//printf("\r%i                   ",zlr[0]);

			z_[1]++;
			z_[2] = S_[3]-z_[1];
			z_[3] = S_[1]-z_[1];
			z_[4] = n_-z_[1]-z_[2]-z_[3];
			
			if(z_[2]<0 || z_[3]<0 || z_[4]<0) break;
		}
	}
	// ---------------------------------------------------------------------------------------------------------------- 2^3 //
	if(k_==3)
	{
		//2x2 hauptlauf a,b,c,d
		while(Lauf[1]<= max[1])
		{
			while(Lauf[2]<= max[1]+1-zlr[1])
			{
				for(dLauf[1]=max[1]-zlr[2]; dLauf[1]>= 0; dLauf[1]--)
				{	
					z_[1]=Lauf[1];
					z_[2]=Lauf[2];
					z_[3]=dLauf[1];
					z_[4]=max[1]-zlr[2]-dLauf[1];

					//2x2 nebenlauf e,f,g,h
					while(dLauf[2]<= max[2]+1)
					{
						while(dLauf[3]<= max[2]+1-zlr[3])
						{
							for(dLauf[4]=max[2]-zlr[4]; dLauf[4]>= 0; dLauf[4]--)
							{														
								z_[5]=dLauf[2];
								z_[6]=dLauf[3];
								z_[7]=dLauf[4];
								z_[8]=max[2]-zlr[4]-dLauf[4];z_[Lauf[5]];

								if(z_[1]+z_[2]+z_[5]+z_[6] > S_[1])break;//
								if(z_[3]+z_[4]+z_[7]+z_[8] > S_[2])break;
								if(z_[2]+z_[4]+z_[6]+z_[8] > S_[4])break;//
								
								if(z_[1]+z_[3]+z_[5]+z_[7] == S_[3])  
								{
									if(sw_==1)
									{
											//P[1]= fn_2khg(z_, zn); // allgemein
											P[1]= fn_hg_( z_, 1); // 2x2x2
										if( P[1]<=P[0]) p[2]+=P[1];         // p2= Pi <= P0
									  p[0]+=P[1];

									  //printf("\rP(%i)= %.14f, p= %.14f p.exact[2]= %.8f",zlr[0], P[1], p[0],p[2]);	//

										//printf("\r%.14f",p[0]);
									}
								
									if(sw_==2){zlr[0]++; }//printf("\r%i                   ",zlr[0]);
								}
							}
							dLauf[3]++;zlr[4]++;	
						}
						dLauf[2]++; 
						dLauf[3]=0;           zlr[3]++;
									   zlr[4]=zlr[3];	
					}
					dLauf[2]=0;
					  zlr[4]=0; 
					  zlr[3]=0; max[2]= S_[6];
				
					//2x2 nebenlauf e,f,g,h
				}
				Lauf[2]++;zlr[2]++;
			}
			Lauf[1]++; 
			Lauf[2]=0;           zlr[1]++;
						  zlr[2]=zlr[1];   
		}
		Lauf[1]=0;
	}
	/**/
	//
	// --------------------------------------------------------------------------------------------------------------- 2^4 //
	if(k_==4)
	{
		for(Lauf[1]=1; Lauf[1]<= 20; Lauf[1]++)  dLauf[Lauf[1]]=0;  // dLauf =0

		while(dLauf[1]<=max[0])
		{
			      dLauf[2]=0;
			while(dLauf[2]<=max[0])
			{
				      dLauf[3]=0;
				while(dLauf[3]<=max[0])
				{
					      dLauf[4]=0;
					while(dLauf[4]<=max[0])
					{
						      dLauf[5]=0;
						while(dLauf[5]<=max[0])
						{
							      dLauf[6]=0;
							while(dLauf[6]<=max[0])
							{
								      dLauf[7]=0;
								while(dLauf[7]<=max[0] )
								{	
								          dLauf[8]=0;
									while(dLauf[8]<=max[0] )
									{
										      dLauf[9]=0;
										while(dLauf[9]<=max[0] )
										{
											      dLauf[10]=0;
											while(dLauf[10]<=max[0] )
											{
												      dLauf[11]=0;
												while(dLauf[11]<=max[0] )
												{
													      dLauf[12]=0;
													while(dLauf[12]<=max[0] )
													{
													          dLauf[13]=0;
														while(dLauf[13]<=max[0] )
														{
															      dLauf[14]=0;
															while(dLauf[14]<=max[0] )
															{
																      dLauf[15]=0;
																while(dLauf[15]<=max[0])
																{
																	      dLauf[16]=0;
																	while(dLauf[16]<=max[0] )
																	{			
																		if(dLauf[1] +dLauf[2] +dLauf[3] +dLauf[4] +dLauf[5] +dLauf[6] +dLauf[7] +dLauf[8] +dLauf[9] +dLauf[10] +dLauf[11] +dLauf[12] +dLauf[13] +dLauf[14] +dLauf[15] +dLauf[16] > n_) break;
																		
																		if(dLauf[1]+dLauf[3] +dLauf[9]  +dLauf[11]+dLauf[5] +dLauf[7] +dLauf[13]+dLauf[15] > S_[1]) break;
																		if(dLauf[2]+dLauf[4] +dLauf[10] +dLauf[12]+dLauf[6] +dLauf[8] +dLauf[14]+dLauf[16] > S_[2]) break;
																		if(dLauf[1]+dLauf[2] +dLauf[5]  +dLauf[6] +dLauf[9] +dLauf[10]+dLauf[13]+dLauf[14] > S_[3]) break;
																		if(dLauf[3]+dLauf[4] +dLauf[7]  +dLauf[8] +dLauf[11]+dLauf[12]+dLauf[15]+dLauf[16] > S_[4]) break;
																		if(dLauf[1]+dLauf[2] +dLauf[3]  +dLauf[4] +dLauf[9] +dLauf[10]+dLauf[11]+dLauf[12] > S_[5]) break;
																		if(dLauf[5]+dLauf[6] +dLauf[7]  +dLauf[8] +dLauf[13]+dLauf[14]+dLauf[15]+dLauf[16] > S_[6]) break;
																		if(dLauf[1]+dLauf[2] +dLauf[3]  +dLauf[4] +dLauf[5] +dLauf[6] +dLauf[7] +dLauf[8]  > S_[7]) break;
																		if(dLauf[9]+dLauf[10]+dLauf[11] +dLauf[12]+dLauf[13]+dLauf[14]+dLauf[15]+dLauf[16] > S_[8]) break;

																		if( dLauf[1]+dLauf[3] +dLauf[9] +dLauf[11]+dLauf[5] +dLauf[7] +dLauf[13]+dLauf[15] == S_[1] &&
																			dLauf[2]+dLauf[4] +dLauf[10]+dLauf[12]+dLauf[6] +dLauf[8] +dLauf[14]+dLauf[16] == S_[2] &&
																			dLauf[1]+dLauf[2] +dLauf[5] +dLauf[6] +dLauf[9] +dLauf[10]+dLauf[13]+dLauf[14] == S_[3] &&
																			dLauf[3]+dLauf[4] +dLauf[7] +dLauf[8] +dLauf[11]+dLauf[12]+dLauf[15]+dLauf[16] == S_[4] &&
																			dLauf[1]+dLauf[2] +dLauf[3] +dLauf[4] +dLauf[9] +dLauf[10]+dLauf[11]+dLauf[12] == S_[5] &&
																			dLauf[5]+dLauf[6] +dLauf[7] +dLauf[8] +dLauf[13]+dLauf[14]+dLauf[15]+dLauf[16] == S_[6] &&
																			dLauf[1]+dLauf[2] +dLauf[3] +dLauf[4] +dLauf[5] +dLauf[6] +dLauf[7] +dLauf[8]  == S_[7] && 
																			dLauf[9]+dLauf[10]+dLauf[11]+dLauf[12]+dLauf[13]+dLauf[14]+dLauf[15]+dLauf[16] == S_[8]
																			)
																		{
																			//printf("%.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f ",dLauf[1],dLauf[2],dLauf[3],dLauf[4],dLauf[5],dLauf[6],dLauf[7],dLauf[8],dLauf[9],dLauf[10],dLauf[11],dLauf[12],dLauf[13],dLauf[14],dLauf[15],dLauf[16]);
																			//printf("\n");
																			if(sw_==1)
																			{
																						P[1]= fn_2khg(dLauf, 16); // Pi
																					if( P[1]<=P[0]) p[2]+=P[1];   // p2= Pi <= P0
																				  p[0]+=P[1];


																				//printf("\r%.14f",p[0]);
																				//printf("\rP(%i)= %.14f, p= %.14f p.exact[2]= %.8f",zlr[0], P[1], p[0],p[2]);	//
																			}
																			
																			if(sw_==2){zlr[0]++; }//printf("\r%i                   ",zlr[0]);
																		}

																	   dLauf[16]++;
																	}//dLauf16
		                                                            if(dLauf[1]+dLauf[2]+dLauf[3]+dLauf[4]+dLauf[5]+dLauf[6]+dLauf[7]+dLauf[8]+dLauf[9]+dLauf[10]+dLauf[11]+dLauf[12]+dLauf[13]+dLauf[14]+dLauf[15]>n_) break;
			                                                        if(dLauf[1]+dLauf[3]+dLauf[9]+dLauf[11]+dLauf[5]+dLauf[7]+dLauf[13]+dLauf[15]>S_[1]) break;
																
																   dLauf[15]++;
																}//dLauf15
	                                                            if(dLauf[1]+dLauf[2]+dLauf[3]+dLauf[4]+dLauf[5]+dLauf[6]+dLauf[7]+dLauf[8]+dLauf[9]+dLauf[10]+dLauf[11]+dLauf[12]+dLauf[13]+dLauf[14]>n_) break;
	                                                            if(dLauf[1]+dLauf[2]+dLauf[5]+dLauf[6]+dLauf[9]+dLauf[10]+dLauf[13]+dLauf[14]>S_[3])break;
															
															   dLauf[14]++;
															}//dLauf14
	                                                        if(dLauf[1]+dLauf[2]+dLauf[3]+dLauf[4]+dLauf[5]+dLauf[6]+dLauf[7]+dLauf[8]+dLauf[9]+dLauf[10]+dLauf[11]+dLauf[12]+dLauf[13]>n_) break;
														
														   dLauf[13]++;
														}//dLauf13
	                                                    if(dLauf[1]+dLauf[2]+dLauf[3]+dLauf[4]+dLauf[5]+dLauf[6]+dLauf[7]+dLauf[8]+dLauf[9]+dLauf[10]+dLauf[11]+dLauf[12]>n_) break;
		                                                if(dLauf[1]+dLauf[2]+dLauf[3]+dLauf[4]+dLauf[9]+dLauf[10]+dLauf[11]+dLauf[12]>S_[5]) break;
													
													   dLauf[12]++;
													}//dLauf12
	                                                if(dLauf[1]+dLauf[2]+dLauf[3]+dLauf[4]+dLauf[5]+dLauf[6]+dLauf[7]+dLauf[8]+dLauf[9]+dLauf[10]+dLauf[11]>n_) break;
												
												   dLauf[11]++;
												}//dLauf11
	                                            if(dLauf[1]+dLauf[2]+dLauf[3]+dLauf[4]+dLauf[5]+dLauf[6]+dLauf[7]+dLauf[8]+dLauf[9]+dLauf[10]>n_) break;
											
											   dLauf[10]++;
                                            }//dLauf10
	                                        if(dLauf[1]+dLauf[2]+dLauf[3]+dLauf[4]+dLauf[5]+dLauf[6]+dLauf[7]+dLauf[8]+dLauf[9]>n_) break;
										
										   dLauf[9]++;
                                        }//dLauf9
	                                    if(dLauf[1]+dLauf[2]+dLauf[3]+dLauf[4]+dLauf[5]+dLauf[6]+dLauf[7]+dLauf[8]>S_[7]) break;
									 
										dLauf[8]++;
                                      }//dLauf8
	                                  if(dLauf[1]+dLauf[2]+dLauf[3]+dLauf[4]+dLauf[5]+dLauf[6]+dLauf[7]>n_) break;
								 
									 dLauf[7]++;
                                  }//dLauf7
	                              if(dLauf[1]+dLauf[2]+dLauf[3]+dLauf[4]+dLauf[5]+dLauf[6]>n_) break;
							  
								 dLauf[6]++; 
                              }//dLauf6
	                          if(dLauf[1]+dLauf[2]+dLauf[3]+dLauf[4]+dLauf[5]>n_) break;
	
							 dLauf[5]++; 
						  }//dLauf5
	                      if(dLauf[1]+dLauf[2]+dLauf[3]+dLauf[4]>n_) break;
						
						  dLauf[4]++; 
					   }//dLauf4
	                   if(dLauf[1]+dLauf[2]+dLauf[3]>n_) break;
						
					   dLauf[3]++; 
                    }//dLauf3
	                if(dLauf[1]+dLauf[2]>n_) break;
					
				   dLauf[2]++; 
                }//dLauf2
			
				dLauf[1]++;
		   }//dLauf1
	}
	/**/
	//
	// --------------------------------------------------------------------------------------------------------------- 2^k //
	if(k_ > 4) 
	{
		for(Lauf[1]=1; Lauf[1]<= zn; Lauf[1]++) dLauf[Lauf[1]]= 0; // 
		
		dLauf[1]=-1;
		
		while(1)
		{
			for(Lauf[1] = 1; Lauf[1] <=  zn; Lauf[1]++) // allgemeine index generierung 1 - zn
			{				
				if(Lauf[1] == 1)
				{ 
					dLauf[1]++;
				}
				if(dLauf[zn]> max[0])break;
				
				if(dLauf[Lauf[1]] > max[0]) 
				{ 
					dLauf[Lauf[1]] = 0;
					dLauf[Lauf[1]+1] += 1;	
				}			
			}

			if(dLauf[zn] > max[0] || p[0]>= 0.9999999999 ) break;
		
			while(1)
			{  
				// rekursiv fächer, \/sum: sum > n prüfung
				                                             sum[0]=0;
				for(Lauf[1] = 1; Lauf[1] <=  zn; Lauf[1]++) {sum[0]+=dLauf[Lauf[1]]; if(sum[0] > n_) {sw=1;break;}} ;
														                                           if(sw==1) 
																								   {  sw=0; break;}										      
				for(Lauf[1]=1; Lauf[1]<= k_; Lauf[1]++) index[Lauf[1]]= 1; // 
				for(Lauf[1]=0; Lauf[1]<  20;   Lauf[1]++)       sum[Lauf[1]]=0;  // sum =0
														
				nr=1;
					   felder=1;
				while (felder <= zn) // durchlauf über 2^k zellen (zn)
				{
					for(Lauf[1]=1; Lauf[1]<=k_; Lauf[1]++)
					{
													  for(Lauf[3]= 1; Lauf[3]<=2*k_; Lauf[3]++) 
						if(index[Lauf[1]]+2*Lauf[1]-2 == Lauf[3] )
						{
							sum[Lauf[3]]+=dLauf[nr]; // summierung
						}
					}
					nr++; //wertzähler
					
					for (Lauf[1]=1; Lauf[1]<=k_; Lauf[1]++) // index generierung
					{				
						if(Lauf[1]==1)
						{ 
							index[1]++;
						}
					
						if(index[Lauf[1]]==3) 
						{ 
							index[Lauf[1]]=1;
							index[Lauf[1]+1]+=1;	
						}
					}
					felder++;
				}	
				
				for(Lauf[1] = 1; Lauf[1] <=  2*k_; Lauf[1]++) if(sum[Lauf[1]] > S_[Lauf[1]]) {sw=1;break;} //	 \/sum: sum > S prüfung
																						   if(sw==1) 
																						   {  sw=0; break;}

				sw=0;
				for(Lauf[1] = 1; Lauf[1] <=  2*k_; Lauf[1]++) if(sum[Lauf[1]] == S_[Lauf[1]]) sw+=1;  // /\sum: sum = S prüfung
				
				if(sw==2*k_) // bei /\sum: sum = S
				{
					//printf("%.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f ",dLauf[1],dLauf[2],dLauf[3],dLauf[4],dLauf[5],dLauf[6],dLauf[7],dLauf[8],dLauf[9],dLauf[10],dLauf[11],dLauf[12],dLauf[13],dLauf[14],dLauf[15],dLauf[16]);
					//printf("\n");

						  P[1]= fn_2khg(dLauf, zn); // Pi
					  if( P[1]<=P[0]) p[2]+=P[1];   // p2= Pi <= P0
					p[0]+=P[1];

					//if(sw_==1)printf("\r%.14f",p[0]);
					//printf("\rP(%i)= %.14f, p= %.14f p.exact[2]= %.8f",zlr[0], P[1], p[0],p[2]);	//

					if(sw_==2){zlr[0]++; }//printf("\r%i                   ",zlr[0]);
				}

				if(1) break;
			}
		}
	}
	
	printf("\r                                                                           \r ");
	if(sw_==1) fn_erg=p[2]; 
	if(sw_==2) fn_erg=zlr[0];

	return 0;
};

//--------------------------------------------------------------------------------------------------------- vorversionen- //
double fn_hg_(double wert[100], int sw)// hypergeometrischer 2x2x2 Test //
//																	       // P0 zu a   (1) HG0 a,b,c,d,e,f,g,h 
//																	       // p1 asymp  (2) HG1 a,b,c,d,e,f,g,h
//                                                                         // z-wert    (3) ZHG a,b,c,d,e,f,g,h
{
	double a_,b_,c_,d_,e_,f_,g_,h_, n_, p, p1, z_, p1_, P0_=1;
	double iLauf, jLauf, fact, Z1_=1, Z2_=1, Z3_=1,Z4_=1, Z5_=1,Z6_=1 ;//, Z_
	double N1_=1, N2_=1, N3_=1, N4_=1, N5_=1, N6_=1 , N7_=1, N8_=1,N9_=1;

	double ZS1, ZS2, TS1, TS2, SS1, SS2, pk=0;

	int sw_1=0, zlr=1;

	long double x_;

	a_=wert[1];     b_=wert[2]; 	e_=wert[5];      f_=wert[6];       ZS1=a_+b_+e_+f_;
	c_=wert[3];     d_=wert[4];     g_=wert[7];      h_=wert[8];       ZS2=c_+d_+g_+h_;
                                
	                                SS1=a_+c_+e_+g_; SS2=b_+d_+f_+h_;
	                                                                    
				               TS1=a_+b_+c_+d_;                        TS2=e_+f_+g_+h_;					
									                                  
							                                           n_=a_+b_+c_+d_+e_+f_+g_+h_;

	// Punktwahrscheinlichkeit P0  zu a 
						   fact = n_;
	for(jLauf = 0; jLauf < fact; jLauf++) //n - faktoriellzerlegung
	{
		for(iLauf =   (a_+b_+c_+d_)-jLauf; iLauf >= 2; iLauf -= fact)	Z1_ *= iLauf;
		for(iLauf =   (e_+f_+g_+h_)-jLauf; iLauf >= 2; iLauf -= fact)	Z2_ *= iLauf;
		for(iLauf =   (a_+b_+e_+f_)-jLauf; iLauf >= 2; iLauf -= fact)	Z3_ *= iLauf;
		for(iLauf =   (c_+d_+g_+h_)-jLauf; iLauf >= 2; iLauf -= fact)	Z4_ *= iLauf;
		for(iLauf =   (a_+c_+e_+g_)-jLauf; iLauf >= 2; iLauf -= fact)	Z5_ *= iLauf;
		for(iLauf =   (b_+d_+f_+h_)-jLauf; iLauf >= 2; iLauf -= fact)	Z6_ *= iLauf;
		
		for(iLauf =   (n_)-jLauf; iLauf >= 2; iLauf -= fact)	N1_ *= iLauf;
		for(iLauf =   (a_)-jLauf; iLauf >= 2; iLauf -= fact)	N2_ *= iLauf;
		for(iLauf =   (b_)-jLauf; iLauf >= 2; iLauf -= fact)	N3_ *= iLauf;
		for(iLauf =   (c_)-jLauf; iLauf >= 2; iLauf -= fact)	N4_ *= iLauf;
		for(iLauf =   (d_)-jLauf; iLauf >= 2; iLauf -= fact)	N5_ *= iLauf;
		for(iLauf =   (e_)-jLauf; iLauf >= 2; iLauf -= fact)	N6_ *= iLauf;
		for(iLauf =   (f_)-jLauf; iLauf >= 2; iLauf -= fact)	N7_ *= iLauf;
		for(iLauf =   (g_)-jLauf; iLauf >= 2; iLauf -= fact)	N8_ *= iLauf;
		for(iLauf =   (h_)-jLauf; iLauf >= 2; iLauf -= fact)	N9_ *= iLauf;
/* zerlegt 
							Z_= Z1_*Z2_*Z3_;
						x_= Z_/(N1_*N2_*N3_*N4_*N5_*N6_*N7_*N8_*N9_);
					x_= x_* Z4_*Z5_*Z6_;
					x_= x_ / N1_;
			   //if(x_==1) break; 
*/

					x_= (Z1_*Z2_*Z3_*Z4_*Z5_*Z6_)/(N1_*N1_*N2_*N3_*N4_*N5_*N6_*N7_*N8_*N9_);
		P0_ = P0_ * x_;
		
		Z1_= Z2_= Z3_= Z4_= Z5_= Z6_ = 1;
		N1_= N2_= N3_= N4_= N5_= N6_ = N7_= N8_= N9_= 1;	
	}

	if(sw==1) fn_erg =P0_;

	if(sw==2 || sw==3) // z-approximiertes einseitiges Signifikanzniveau p1 //
	{
			   p=(( e_+f_+g_+h_)*(c_+d_+g_+h_)*(b_+d_+f_+h_))/pow(n_,3);
														p1=(( e_+f_+g_+h_-1)*(c_+d_+g_+h_-1)*(b_+d_+f_+h_-1))/pow((n_-1),3);
		z_=(h_-n_*p-0.5)/sqrt(n_*p*(1-p)-n_*(n_-1)*p*(p-p1));

		            p1_=pz_funktion(z_);
					p1_=p1_/2;// halbes 2-seitiges sig niveau
				 if(p1_>0.5) p1_=1-p1_;
		fn_erg= P0_+p1_;
	
		if(sw==3) fn_erg= z_;
	}
	
	return fn_erg;
}

long double fn_hgx(double wert[100])// hypergeometrischer 2x2x2 Test, pexact2 zu a // HG2 a,b,c,d,e,f,g,h      
{
	long double iLauf=0, jLauf=0, kLauf, lLauf=0, mLauf=0, nLauf, zlr=0, j_zlr=0, k_zlr=0, n_zlr=0, m_zlr=0, p_zlr=0;
	long double a,b,c,d,e,f,g,h, Z1,Z2,S1,S2;
    long double  Rmax, Rmax1,P0, P_, p=0, p_=0, vektor[100];

				vektor[1]=wert[1];  // P0
				vektor[2]=wert[2];
				vektor[3]=wert[3];
				vektor[4]=wert[4];
				vektor[5]=wert[5];
				vektor[6]=wert[6];
				vektor[7]=wert[7];
				vektor[8]=wert[8];
	 P0= fn_hg_(vektor, 1);

	printf("\n\n");

	Z1 = wert[1]+wert[2]+wert[5]+wert[6]; // zeilenfrequenzen
	Z2 = wert[3]+wert[4]+wert[7]+wert[8]; 
	S1 = wert[1]+wert[3]+wert[5]+wert[7]; // spaltenfrequenzen
	S2 = wert[2]+wert[4]+wert[6]+wert[8];
		
	Rmax= wert[1]+wert[2]+wert[3]+wert[4]; // tafelfrequenzen
	Rmax1=wert[5]+wert[6]+wert[7]+wert[8];

	//2x2 hauptlauf a,b,c,d
	while(iLauf<= Rmax+1)
	{
		while(jLauf<= Rmax+1-j_zlr)
		{
			for(kLauf=Rmax-k_zlr; kLauf>= 0; kLauf--)
			{	
				a=iLauf;
				b=jLauf;
				c=kLauf;
				d=Rmax-k_zlr-kLauf;

				//2x2 nebenlauf e,f,g,h
				while(lLauf<= Rmax1+1)
				{
					while(mLauf<= Rmax1+1-m_zlr)
					{
						for(nLauf=Rmax1-n_zlr; nLauf>= 0; nLauf--)
						{														
							e=lLauf;
							f=mLauf;
							g=nLauf;
							h=Rmax1-n_zlr-nLauf;

							if(a+b+e+f > Z1)break;////
							if(c+d+g+h > Z2)break;
							//if(a+c+e+g > S1)break;
							if(b+d+f+h > S2)break;//
							
							if( /*a+b+e+f == Z1 &&
							    c+d+g+h == Z2 &&*/
								a+c+e+g == S1 //&&
								/*b+d+f+h == S2*/ )
							{
								//zlr++;
												vektor[1]= a; // Pi
												vektor[2]= b;
												vektor[3]= c;
												vektor[4]= d;
												vektor[5]= e;
												vektor[6]= f;
												vektor[7]= g;
												vektor[8]= h;

									P_= fn_hg_( vektor, 1);
								if( P_<=P0) p_+=P_;         // p= Pi <= P0
								p+=P_;

								printf("%.14f\r",p);
							}
						}
						 mLauf++;

						n_zlr++;
					}
					lLauf++; mLauf=0;
						  m_zlr++;
					n_zlr=m_zlr;
				}
				lLauf=0;
				n_zlr=m_zlr=0;Rmax1= wert[5]+wert[6]+wert[7]+wert[8];
			}
			jLauf++;
			 
			k_zlr++;
		}
		iLauf++; jLauf=0;
		      j_zlr++;
        k_zlr=j_zlr;
	}
	iLauf=0;
	printf("                                         \r");
	fn_erg=p_; 

	return 0;
};