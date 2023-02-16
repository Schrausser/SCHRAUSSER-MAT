//----------------------------------------------------------------------------------------------------| calc_ funktionen, kxl Kontingenzfelder, SCHRAUSSER 2010	//
double fn_klhg(double wert[100]);
double fn_klx(double wert[100]);

double fn_klhg(double wert[100])// hypergeometrische Punkt-Wahrscheinlichkeit P0 zu kxl - Feldern  // KL0 Z,S,z11,...,z1S,...,zZ1,...,zZS
{
	int jLauf, iLauf, kLauf, nS, nZ;
	double P0_=1,zp=1, n_=0, z_[100], Z[50],S[50], fLauf, Z_[50], S_[50], N1_=1, N_[50], Z1_=1, x_, fact;
	
	// ecvt indizes: double -> string -> int
	int stellen, vorz, maxlng=1;	       

	nZ=atoi(ecvt(wert[1],maxlng,&stellen,&vorz));
	nS=atoi(ecvt(wert[2],maxlng,&stellen,&vorz));
	
	//allgemeine n, Zeilen Z, Spalten S Berechnung
	for(jLauf=1; jLauf<= nZ*nS; jLauf++) {z_[jLauf]=wert[jLauf+2]; n_+=z_[jLauf];}// zellen, n
	
	for(jLauf=1; jLauf<= nZ; jLauf++) Z[jLauf]=0; //zeilen auf 0
	for(jLauf=1; jLauf<= nS; jLauf++) S[jLauf]=0; //Spalten auf 0

	                                                   for(jLauf=1; jLauf<= nZ; jLauf++) 
	for(iLauf=1+nS*(jLauf-1); iLauf<= nS*jLauf; iLauf++) Z[jLauf]+=wert[iLauf+2];          //Zeilen Z

	                                                     for(jLauf=1; jLauf<= nS; jLauf++) 
    for(iLauf=jLauf; iLauf<= nS*nZ-(nS-jLauf); iLauf+= nS) S[jLauf]+=wert[iLauf+2];       //Spalten S

	// Punktwahrscheinlichkeit P0  
	
	for(jLauf=1; jLauf<= nZ; jLauf++) Z_[jLauf]=1; //auf 1
	for(jLauf=1; jLauf<= nS; jLauf++) S_[jLauf]=1; //auf 1
	for(jLauf=1; jLauf<= nZ*nS; jLauf++) N_[jLauf]=1; //auf 1

						   fact = n_;
	for(jLauf = 0; jLauf < fact; jLauf++) //n - faktoriellzerlegung
	{
		                                                           for(kLauf = 1; kLauf <= nZ; kLauf++)
		for(fLauf =   Z[kLauf]-jLauf; fLauf >= 2; fLauf -= fact)	Z_[kLauf] *= fLauf;

			                                                       for(kLauf = 1; kLauf <= nS; kLauf++)
		for(fLauf =   S[kLauf]-jLauf; fLauf >= 2; fLauf -= fact)	S_[kLauf] *= fLauf;
			
		for(fLauf =   n_-jLauf; fLauf >= 2; fLauf -= fact)	N1_ *= fLauf;
		
                                                                   for(kLauf = 1; kLauf <= nZ*nS; kLauf++)
		for(fLauf =   z_[kLauf]-jLauf; fLauf >= 2; fLauf -= fact)	N_[kLauf] *= fLauf;
	

							for(kLauf = 1; kLauf <= nZ; kLauf++)Z1_*= Z_[kLauf];
							for(kLauf = 1; kLauf <= nS; kLauf++)Z1_*= S_[kLauf];
							for(kLauf = 1; kLauf <= nZ*nS; kLauf++)N1_*= N_[kLauf];
						x_= Z1_/N1_;
					//x_= x_* Z4_*Z5_*Z6_;
					
					//x_= x_ / N1_;
			   //if(x_==1) break; 
		P0_ = P0_ * x_;
		
		for(iLauf=1; iLauf<= nZ; iLauf++) Z_[iLauf]=1; //auf 1
		for(iLauf=1; iLauf<= nS; iLauf++) S_[iLauf]=1; //auf 1
		for(iLauf=1; iLauf<= nZ*nS; iLauf++) N_[iLauf]=1; //auf 1

		Z1_=N1_=1;
	}

	fn_erg=P0_;

	return fn_erg;
}

double fn_klx(double wert[100])// x2-wert zu kxl - Feldern bei Zeilen Z = k und Spalten S = l  // KLX Z,S,z11,...,z1S,...,zZ1,...,zZS
{
	int iLauf,jLauf,nS, nZ, i_=3;
	double z_[50][50], fe[50][50], n=0, Z[50], S[50], zlr=0;//

	// ecvt indizes: double -> string -> int
	int stellen, vorz, maxlng=1;	       

	nZ=atoi(ecvt(wert[1],maxlng,&stellen,&vorz));
	nS=atoi(ecvt(wert[2],maxlng,&stellen,&vorz));

	fn_erg=0;
	
	for(iLauf=1; iLauf<= nZ; iLauf++)
	for(jLauf=1; jLauf<= nS; jLauf++) { z_[iLauf][jLauf]=wert[i_]; i_++; }

	//allgemeine n, Zeilen Z, Spalten S Berechnung
	for(jLauf=1; jLauf<= nZ*nS; jLauf++) n+=wert[jLauf+2]; // n
	for(jLauf=1; jLauf<= nZ; jLauf++) Z[jLauf]=0; //zeilen auf 0
	for(jLauf=1; jLauf<= nS; jLauf++) S[jLauf]=0; //Spalten auf 0

	                                                   for(jLauf=1; jLauf<= nZ; jLauf++) 
	for(iLauf=1+nS*(jLauf-1); iLauf<= nS*jLauf; iLauf++) Z[jLauf]+=wert[iLauf+2];          //Zeilen Z

	                                                     for(jLauf=1; jLauf<= nS; jLauf++) 
    for(iLauf=jLauf; iLauf<= nS*nZ-(nS-jLauf); iLauf+= nS) S[jLauf]+=wert[iLauf+2];       //Spalten S
/*
	//bildschirmausgabe fb
	printf("\n\n");
	for(iLauf=1; iLauf<= nZ; iLauf++) 
	{
		for(jLauf=1; jLauf<= nS; jLauf++) printf("%.0f ",z_[iLauf][jLauf]);
	    
		printf("\n");
	}
	
	//bildschirmausgabe Z,S
	printf("\n");
	for(iLauf=1; iLauf<= nZ; iLauf++)printf("Z[%i]= %.0f ",iLauf, Z[iLauf]);
	printf("\n");
	for(iLauf=1; iLauf<= nS; iLauf++)printf("S[%i]= %.0f ",iLauf, S[iLauf]);	
	printf("\n");
*/
	// erwartete frequenzen fe ij 
	for(iLauf=1; iLauf<= nZ; iLauf++)
	for(jLauf=1; jLauf<= nS; jLauf++) { fe[iLauf][jLauf]=(Z[iLauf]*S[jLauf]/n); }
/*
	//bildschirmausgabe fe
	for(iLauf=1; iLauf<= nZ; iLauf++) 
	{
		for(jLauf=1; jLauf<= nS; jLauf++) printf("%f ",fe[iLauf][jLauf]);
	    
		printf("\n");
	}
*/
	//x2-wert
	for(iLauf=1; iLauf<= nZ; iLauf++)
	for(jLauf=1; jLauf<= nS; jLauf++) fn_erg+= pow(z_[iLauf][jLauf] - fe[iLauf][jLauf],2)/fe[iLauf][jLauf]; 

	return fn_erg;
}

long double fn_klp2(double wert[100], int sw_) //  hypergeometrische Wahrscheinlichkeit, 2-seitiges sig.-Niveau pexact2 zu kxl - Feldern  //  (1) KL2 3,3, 5,2,5,0,5,5,2,5,3   //
//                                             //  Kombinationen C zu kxl - Feldern                                                       //  (2) CKL 3,3, 5,2,5,0,5,5,2,5,3   //
{
	//FILE *out;
	int jLauf, iLauf=0, nS, nZ;
    int index[50], sw=0;
	double Lauf[50],zlr[5], sum=0, crit=0.9999999999 ;
	long double z_[100], Z[30], S[30],  Z1[30], S1[30], P0, P_, p=0, p2=0;
    long double  n_=0 , R_, zp=1, vektor[100];
	
	// ecvt indizes: double -> string -> int
	int stellen, vorz, maxlng=1;	       

	nZ=atoi(ecvt(wert[1],maxlng,&stellen,&vorz));
	nS=atoi(ecvt(wert[2],maxlng,&stellen,&vorz));

	fn_erg=0;

	zlr[0]=0;
		
	//out=fopen( "fx.txt", "w" );

	//allgemeine n, Zeilen Z, Spalten S Berechnung
	for(jLauf=1; jLauf<= nZ*nS; jLauf++) {z_[jLauf]=wert[jLauf+2]; n_+=z_[jLauf];}// zellen, n
	
	for(jLauf=1; jLauf<= nZ; jLauf++) Z[jLauf]=0; //zeilen auf 0
	for(jLauf=1; jLauf<= nS; jLauf++) S[jLauf]=0; //Spalten auf 0

	                                                   for(jLauf=1; jLauf<= nZ; jLauf++) 
	for(iLauf=1+nS*(jLauf-1); iLauf<= nS*jLauf; iLauf++) Z[jLauf]+=wert[iLauf+2];          //Zeilen Z

	                                                     for(jLauf=1; jLauf<= nS; jLauf++) 
    for(iLauf=jLauf; iLauf<= nS*nZ-(nS-jLauf); iLauf+= nS) S[jLauf]+=wert[iLauf+2];       //Spalten S
	
	zlr[0]=zlr[1]=zlr[2]=0;

	for(iLauf=1; iLauf<=50;iLauf++)index[iLauf]=0;
	
	for(iLauf=1; iLauf<=50;iLauf++) Lauf[iLauf]=0;

	R_=Z[1];
	for(jLauf=2; jLauf<= nZ; jLauf++) if(Z[jLauf]>=R_) R_=Z[jLauf]; //maximale Randsumme 
	for(jLauf=1; jLauf<= nS; jLauf++) if(S[jLauf]>=R_) R_=S[jLauf];  
	
	for(jLauf=1; jLauf<= nZ*nS+2; jLauf++)vektor[jLauf]=wert[jLauf];

	P0= fn_klhg(vektor);

	printf("\n\n");
	if(sw_==1)printf("computing Pi ...");
	if(sw_==2)printf("computing C ...");
	
	if(1)//if(0)//
	{
	// Exakt hypergeometrische Wahrscheinlichkeits-Verteilung bei Zeilen Z und Spalten S Fixierung    
	// 2x2 - 5x5 in geschwindigkeits-maximierender explizitcodierung -> schleifenminimierung //
	// (kxl.txt A3000 rechenzeiten im vergleich: explizit t= 22s, allgemein t= 9m49s)
	//
	// --------------------------------------------------------------------------------------------------------------- 2x2 //
	if(wert[1]==2 && wert[2]==2) 
	{
		while(Lauf[1]<= R_)
		{
			while(Lauf[2]<= n_-zlr[1])
			{
				while(Lauf[3]<= n_-zlr[2])
				{											
					Lauf[4] =n_-Lauf[1]-Lauf[2]-Lauf[3];

					if (Lauf[4]<0) break;
					
					if(Lauf[1]+Lauf[2]> Z[1]) break;//
					if(Lauf[3]+Lauf[4]> Z[2]) break;//

					if(Lauf[1]+Lauf[3]> S[1]) break;

					if(Lauf[2]+Lauf[4]==S[2])
					{
						if(sw_==1)
						{
							vektor[3]=Lauf[1];
							vektor[4]=Lauf[2];
							vektor[5]=Lauf[3];
							vektor[6]=Lauf[4];
						
							P_= fn_klhg(vektor);

							if(P_<=P0)p2+=P_;
							p+=P_;
							
							printf("\r%.14f",p);
						}

						if(sw_==2)
						{
							zlr[0]++;
							//printf("\r%.0f                ",zlr[0]);
						}
					}
					Lauf[3]++;
					if(Lauf[1]+Lauf[2]+Lauf[3]>n_) break;
					if(Lauf[1]+Lauf[3]> S[1]) break;
				}
				Lauf[3]=0;Lauf[2]++;
				if(Lauf[1]+Lauf[2]> Z[1]) break;//
			}
			Lauf[2]=0;Lauf[1]++;
			zlr[1]++;
			zlr[2]=zlr[1];if(p>= crit)break;//
		}
	}

	//
	// --------------------------------------------------------------------------------------------------------------- 2x3 //
	if(wert[1]==2 && wert[2]==3) 
	{
		while(Lauf[1]<= R_)
		{
			while(Lauf[2]<= R_)
			{
				while(Lauf[3]<= R_)
				{
					while(Lauf[4]<= n_-zlr[1])//
					{
						while(Lauf[5]<= n_-zlr[2])//
						{								
							Lauf[6] =n_-Lauf[1]-Lauf[2]-Lauf[3]-Lauf[4]-Lauf[5];

							if (Lauf[6]<0) break;
							
							if(Lauf[1]+Lauf[2]+Lauf[3]> Z[1]) break;//
							if(Lauf[4]+Lauf[5]+Lauf[6]> Z[2]) break;//

							if(Lauf[1]+Lauf[4]> S[1]) break;
							if(Lauf[2]+Lauf[5]> S[2]) break;
						
							if(Lauf[3]+Lauf[6]==S[3])
							{
								if(sw_==1)
								{
												vektor[3]=Lauf[1];
												vektor[4]=Lauf[2];
												vektor[5]=Lauf[3];
												vektor[6]=Lauf[4];
												vektor[7]=Lauf[5];
												vektor[8]=Lauf[6];
									P_= fn_klhg(vektor);
							
									if(P_<=P0)p2+=P_;
									p+=P_;
								
									printf("\r%.14f",p);
								    //fprintf(out, "%.32f\n",P_);
								}

								if(sw_==2)
								{
									zlr[0]++;
									//printf("\r%.0f                ",zlr[0]);
								}
							}
							Lauf[5]++;
							if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]>n_) break;
							if(Lauf[2]+Lauf[5]> S[2]) break;
						}
						Lauf[5]=0;Lauf[4]++;
						if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]>n_) break;
						if(Lauf[1]+Lauf[4]> S[1]) break;
					}
					Lauf[4]=0;Lauf[3]++;
					zlr[1]++;//
					zlr[2]=zlr[1];//
					if(Lauf[1]+Lauf[2]+Lauf[3]>Z[1]) break;
				}
				Lauf[3]=0;Lauf[2]++;if(p>= crit)break;//
				zlr[1]=0;zlr[2]=0;//
			}
			Lauf[2]=0; Lauf[1]++;if(p>= crit)break;//
		}
	}

	//
	// --------------------------------------------------------------------------------------------------------------- 3x2 //
	if(wert[1]==3 && wert[2]==2) 
	{
		while(Lauf[1]<= R_)
		{
			while(Lauf[2]<= R_)
			{
				while(Lauf[3]<= R_)
				{
					while(Lauf[4]<= n_-zlr[1])
					{
						while(Lauf[5]<= n_-zlr[2])
						{								
							Lauf[6] =n_-Lauf[1]-Lauf[2]-Lauf[3]-Lauf[4]-Lauf[5];

							if (Lauf[6]<0) break;
							
							if(Lauf[1]+Lauf[2]> Z[1]) break;//
							if(Lauf[3]+Lauf[4]> Z[2]) break;//
							if(Lauf[5]+Lauf[6]> Z[3]) break;//

							if(Lauf[1]+Lauf[3]+Lauf[5]> S[1]) break;
						
							if(Lauf[2]+Lauf[4]+Lauf[6]==S[2])
							{
								if(sw_==1)
								{
												vektor[3]=Lauf[1];
												vektor[4]=Lauf[2];
												vektor[5]=Lauf[3];
												vektor[6]=Lauf[4];
												vektor[7]=Lauf[5];
												vektor[8]=Lauf[6];
									P_= fn_klhg(vektor);
							
									if(P_<=P0)p2+=P_;
									p+=P_;
								
									printf("\r%.14f",p);
								}

								if(sw_==2)
								{
									zlr[0]++;
									//printf("\r%.0f                ",zlr[0]);
								}
							}
							Lauf[5]++;
							if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]>n_) break;
							if(Lauf[1]+Lauf[3]+Lauf[5]> S[1]) break;
						}
						Lauf[5]=0;Lauf[4]++;
						if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]>n_) break;
						if(Lauf[3]+Lauf[4]> Z[2]) break;//
					}
					Lauf[4]=0;Lauf[3]++;//if(p>= crit)break;
					zlr[1]++;
					zlr[2]=zlr[1];
					if(Lauf[1]+Lauf[2]+Lauf[3]>n_) break;
				
				}
				Lauf[3]=0;Lauf[2]++;if(p>= crit)break;
				zlr[1]=0;zlr[2]=0;
				if(Lauf[1]+Lauf[2]> Z[1]) break;//
			}
			Lauf[2]=0; Lauf[1]++;if(p>= crit)break;//
		}
	}
				
	//
	// --------------------------------------------------------------------------------------------------------------- 3x3 //
	if(wert[1]==3 && wert[2]==3) 
	{
		while(Lauf[1]<= R_)
		{
			while(Lauf[2]<= R_)
			{
				while(Lauf[3]<= R_)
				{
					while(Lauf[4]<= R_)
					{
						while(Lauf[5]<= R_)
						{
							while(Lauf[6]<= R_)
							{
								while(Lauf[7]<= n_-zlr[1])//
								{
									while(Lauf[8]<= n_-zlr[2])//
									{										
										Lauf[9] =n_-Lauf[1]-Lauf[2]-Lauf[3]-Lauf[4]-Lauf[5]-Lauf[6]-Lauf[7]-Lauf[8];

										if (Lauf[9]<0) break;
										
										if(Lauf[1]+Lauf[2]+Lauf[3]> Z[1]) break;//
										if(Lauf[4]+Lauf[5]+Lauf[6]> Z[2]) break;//
										if(Lauf[7]+Lauf[8]+Lauf[9]> Z[3]) break;//
										if(Lauf[1]+Lauf[4]+Lauf[7]> S[1]) break;
										if(Lauf[2]+Lauf[5]+Lauf[8]> S[2]) break;
								
										if(Lauf[3]+Lauf[6]+Lauf[9]==S[3])
										{
											if(sw_==1)
											{
															vektor[3]=Lauf[1];
															vektor[4]=Lauf[2];
															vektor[5]=Lauf[3];
															vektor[6]=Lauf[4];
															vektor[7]=Lauf[5];
															vektor[8]=Lauf[6];
															vektor[9]=Lauf[7];
															vektor[10]=Lauf[8];
															vektor[11]=Lauf[9];
												P_= fn_klhg(vektor);
										
												if(P_<=P0)p2+=P_;
												p+=P_;
												
												printf("\r%.14f",p);
												//printf("%.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f\n",a,b,c,d,e,f,g,h,i);//
											}

											if(sw_==2)
											{
												zlr[0]++;
												//printf("\r%.0f                ",zlr[0]);
											}

										}
										Lauf[8]++;//if(p>= crit)break;
										if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]>n_) break;
										if(Lauf[2]+Lauf[5]+Lauf[8]> S[2]) break;
									}
									Lauf[8]=0;Lauf[7]++;//if(p>= crit)break;
									if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]>n_) break;
									if(Lauf[1]+Lauf[4]+Lauf[7]> S[1]) break;
								}
								Lauf[7]=0;Lauf[6]++;//if(p>= crit)break;
								zlr[1]++;//
							   zlr[2]=zlr[1];//
							   if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]>n_) break;
							   if(Lauf[4]+Lauf[5]+Lauf[6]> Z[2]) break;//
							}
							Lauf[6]=0;Lauf[5]++;//if(p>= crit)break;
							zlr[1]=0;zlr[2]=0;//
							if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]>n_) break;
						}
						Lauf[5]=0; Lauf[4]++;//if(p>= crit)break;
						if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]>n_) break;
					}//
					Lauf[4]=0;Lauf[3]++;if(p>= crit)break;
					if(Lauf[1]+Lauf[2]+Lauf[3]> Z[1]) break;//

				}//
				Lauf[3]=0; Lauf[2]++;if(p>= crit)break;
			}//
			Lauf[2]=0;Lauf[1]++;//
			if(p>= crit)break;
	
		}
	}
	
	//
	// --------------------------------------------------------------------------------------------------------------- 2x4 //
	if(wert[1]==2 && wert[2]==4   ) 
	{
		while(Lauf[1]<= R_)
		{
			while(Lauf[2]<= R_)
			{
				while(Lauf[3]<= R_)
				{
						while(Lauf[4]<= R_)
						{
							while(Lauf[5]<= R_)
							{
								while(Lauf[6]<= n_-zlr[1])
								{
									while(Lauf[7]<= n_-zlr[2])
									{									
										Lauf[8] =n_-Lauf[1]-Lauf[2]-Lauf[3]-Lauf[4]-Lauf[5]-Lauf[6]-Lauf[7];

										if (Lauf[8]<0) break;
										
										if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]> Z[1]) break;//
										if(Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]> Z[2]) break;//
									
										if(Lauf[1]+Lauf[5]> S[1]) break;
										if(Lauf[2]+Lauf[6]> S[2]) break;
										if(Lauf[3]+Lauf[7]> S[3]) break;
									
										if(Lauf[4]+Lauf[8]==S[4] ) 
										{
										    if(sw_==1)
											{
															vektor[3]=Lauf[1];
															vektor[4]=Lauf[2];
															vektor[5]=Lauf[3];
															vektor[6]=Lauf[4];
															vektor[7]=Lauf[5];
															vektor[8]=Lauf[6];
															vektor[9]=Lauf[7];
															vektor[10]=Lauf[8];
												P_= fn_klhg(vektor);
												
												if(P_<=P0)p2+=P_;
												p+=P_;
												
												printf("\r%.14f",p);//
												//printf("%.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f\n",a,b,c,d,e,f,g,h,i);//
											}

											if(sw_==2)
											{
												zlr[0]++;
												//printf("\r%.0f                ",zlr[0]);
											}
										}
										Lauf[7]++;
										if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]>n_) break;
										if(Lauf[3]+Lauf[7]> S[3]) break;
									}
									Lauf[7]=0;Lauf[6]++;
									if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]>n_) break;
									if(Lauf[2]+Lauf[6]> S[2]) break;
								}
								Lauf[6]=0;Lauf[5]++;
								zlr[1]++;
								zlr[2]=zlr[1];
								if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]>n_) break;
								if(Lauf[1]+Lauf[5]> S[1]) break;
							}
							Lauf[5]=0;Lauf[4]++;
							zlr[1]=0;zlr[2]=0;
							if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]> Z[1]) break;//
					}
					Lauf[4]=0;Lauf[3]++;if(p>= crit)break;
				}
				Lauf[3]=0; Lauf[2]++;if(p>= crit)break;
			}
			Lauf[2]=0;Lauf[1]++;
			if(p>= crit)break;	
		}	
	}

	//
	// --------------------------------------------------------------------------------------------------------------- 4x2 //
	if(  wert[1]==4 && wert[2]==2) 
	{
		while(Lauf[1]<= R_)
		{
			while(Lauf[2]<= R_)
			{
				while(Lauf[3]<= R_)
				{
						while(Lauf[4]<= R_)
						{
							while(Lauf[5]<= R_)
							{
								while(Lauf[6]<= n_-zlr[1])
								{
									while(Lauf[7]<= n_-zlr[2])
									{									
										Lauf[8] =n_-Lauf[1]-Lauf[2]-Lauf[3]-Lauf[4]-Lauf[5]-Lauf[6]-Lauf[7];

										if (Lauf[8]<0) break;
										
										if(Lauf[1]+Lauf[2] > Z[1]) break;//
										if(Lauf[3]+Lauf[4] > Z[2]) break;//
										if(Lauf[5]+Lauf[6] > Z[3]) break;//
										if(Lauf[7]+Lauf[8] > Z[4]) break;//
									
										if(Lauf[1]+Lauf[3]+Lauf[5]+Lauf[7]> S[1]) break;
									
										if(Lauf[2]+Lauf[4]+Lauf[6]+Lauf[8]==S[2] ) 
										{
										  	if(sw_==1)
											{
															vektor[3]=Lauf[1];
															vektor[4]=Lauf[2];
															vektor[5]=Lauf[3];
															vektor[6]=Lauf[4];
															vektor[7]=Lauf[5];
															vektor[8]=Lauf[6];
															vektor[9]=Lauf[7];
															vektor[10]=Lauf[8];
												P_= fn_klhg(vektor);
												
												if(P_<=P0)p2+=P_;
												p+=P_;
												
												printf("\r%.14f",p);
											}

											if(sw_==2)
											{
												zlr[0]++;
												//printf("\r%.0f                ",zlr[0]);
											}

										}
										Lauf[7]++;
										if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]>n_) break;
										if(Lauf[1]+Lauf[3]+Lauf[5]+Lauf[7]> S[1]) break;
									}
									Lauf[7]=0;Lauf[6]++;
									if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]>n_) break;
									if(Lauf[5]+Lauf[6] > Z[3]) break;//
								}
								Lauf[6]=0;Lauf[5]++;
								zlr[1]++;
								zlr[2]=zlr[1];
								if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]>n_) break;
							}
							Lauf[5]=0;Lauf[4]++;
							zlr[1]=0;zlr[2]=0;
							if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]>n_) break;
							if(Lauf[3]+Lauf[4] > Z[2]) break;//
					}
					Lauf[4]=0;Lauf[3]++;if(p>= crit)break;
				}
				Lauf[3]=0; Lauf[2]++;if(p>= crit)break;
				if(Lauf[1]+Lauf[2] > Z[1]) break;//
			}
			Lauf[2]=0;Lauf[1]++;
			if(p>= crit)break;	
		}	
	}

	//
	// --------------------------------------------------------------------------------------------------------------- 3x4 //
	if(wert[1]==3 && wert[2]==4) 
	{
		while(Lauf[1]<= R_)
		{
			while(Lauf[2]<= R_)
			{
				while(Lauf[3]<= R_)
				{
					while(Lauf[4]<= R_)
					{
						while(Lauf[5]<= R_)
						{
							while(Lauf[6]<= R_)
							{
								while(Lauf[7]<= R_)
								{
									while(Lauf[8]<= R_)
									{
										while(Lauf[9]<= R_)
										{
											while(Lauf[10]<= n_-zlr[1])
											{
												while(Lauf[11]<= n_-zlr[2])
												{																		 
													Lauf[12] =n_-Lauf[1]-Lauf[2]-Lauf[3]-Lauf[4]-Lauf[5]-Lauf[6]-Lauf[7]-Lauf[8]-Lauf[9]-Lauf[10]-Lauf[11];

													if (Lauf[12]<0) break;
													
													if(Lauf[1]+ Lauf[2]+ Lauf[3]+ Lauf[4]>  Z[1]) break;//
													if(Lauf[5]+ Lauf[6]+ Lauf[7]+ Lauf[8]>  Z[2]) break;//
													if(Lauf[9]+ Lauf[10]+Lauf[11]+Lauf[12]> Z[3]) break;//
												
													if(Lauf[1]+ Lauf[5]+ Lauf[9] > S[1]) break;
													if(Lauf[2]+ Lauf[6]+ Lauf[10]> S[2]) break;
													if(Lauf[3]+ Lauf[7]+ Lauf[11]> S[3]) break;
												
													if(Lauf[4]+ Lauf[8]+ Lauf[12]==S[4])
													{
														if(sw_==1)
														{		
																		vektor[3]=Lauf[1];
																		vektor[4]=Lauf[2];
																		vektor[5]=Lauf[3];
																		vektor[6]=Lauf[4];
																		vektor[7]=Lauf[5];
																		vektor[8]=Lauf[6];
																		vektor[9]=Lauf[7];
																		vektor[10]=Lauf[8];
																		vektor[11]=Lauf[9];
																		vektor[12]=Lauf[10];
																		vektor[13]=Lauf[11];
																		vektor[14]=Lauf[12];
															P_= fn_klhg(vektor);
													
															if(P_<=P0)p2+=P_;
															p+=P_;
															
															printf("\r%.14f",p);
														}

														if(sw_==2)
														{
															zlr[0]++;
															//printf("\r%.0f                ",zlr[0]);
														}

													}
													Lauf[11]++;
													if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]>n_) break;
													if(Lauf[3]+ Lauf[7]+ Lauf[11]> S[3]) break;
												}
												Lauf[11]=0;Lauf[10]++;
												if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]>n_) break;
												if(Lauf[2]+ Lauf[6]+ Lauf[10]> S[2]) break;
											}
											Lauf[10]=0;Lauf[9]++;
											zlr[1]++;
											zlr[2]=zlr[1];
											if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]>n_) break;
											if(Lauf[1]+ Lauf[5]+ Lauf[9] > S[1]) break;
										}
										Lauf[9]=0;Lauf[8]++;
										zlr[1]=0;zlr[2]=0;
										if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]>n_) break;
										if(Lauf[5]+ Lauf[6]+ Lauf[7]+ Lauf[8]>  Z[2]) break;//
									}
									Lauf[8]=0; Lauf[7]++;
									if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]>n_) break;
								
								}
								Lauf[7]=0;Lauf[6]++;
								if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]>n_) break;
							}
							Lauf[6]=0; Lauf[5]++;
							if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]>n_) break;
						}
						Lauf[5]=0; Lauf[4]++;
						if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]>Z[1]) break;
					}
					Lauf[4]=0; Lauf[3]++;if(p>= crit)break;
				}
				Lauf[3]=0; Lauf[2]++;if(p>= crit)break;						
			}
			Lauf[2]=0;Lauf[1]++;
			if(p>= crit)break;
		}
	}

	//
	// --------------------------------------------------------------------------------------------------------------- 4x3 //
	if(wert[1]==4 && wert[2]==3) 
	{
		while(Lauf[1]<= R_)
		{
			while(Lauf[2]<= R_)
			{
				while(Lauf[3]<= R_)
				{
					while(Lauf[4]<= R_)
					{
						while(Lauf[5]<= R_)
						{
							while(Lauf[6]<= R_)
							{
								while(Lauf[7]<= R_)
								{
									while(Lauf[8]<= R_)
									{
										while(Lauf[9]<= R_)
										{
											while(Lauf[10]<= n_-zlr[1])
											{
												while(Lauf[11]<= n_-zlr[2])
												{													 
													Lauf[12] =n_-Lauf[1]-Lauf[2]-Lauf[3]-Lauf[4]-Lauf[5]-Lauf[6]-Lauf[7]-Lauf[8]-Lauf[9]-Lauf[10]-Lauf[11];

													if (Lauf[12]<0) break;
													
													if(Lauf[1]+  Lauf[2]+ Lauf[3]>  Z[1]) break;//
													if(Lauf[4]+  Lauf[5]+ Lauf[6]>  Z[2]) break;//
													if(Lauf[7]+  Lauf[8]+ Lauf[9]>  Z[3]) break;//
													if(Lauf[10]+ Lauf[11]+Lauf[12]> Z[4]) break;//

													if(Lauf[1]+ Lauf[4]+ Lauf[7] + Lauf[10]> S[1]) break;
													if(Lauf[2]+ Lauf[5]+ Lauf[8] + Lauf[11]> S[2]) break;
													
													if(Lauf[3]+ Lauf[6]+ Lauf[9] + Lauf[12]==S[3])
													{
														if(sw_==1)
														{
																		vektor[3]=Lauf[1];
																		vektor[4]=Lauf[2];
																		vektor[5]=Lauf[3];
																		vektor[6]=Lauf[4];
																		vektor[7]=Lauf[5];
																		vektor[8]=Lauf[6];
																		vektor[9]=Lauf[7];
																		vektor[10]=Lauf[8];
																		vektor[11]=Lauf[9];
																		vektor[12]=Lauf[10];
																		vektor[13]=Lauf[11];
																		vektor[14]=Lauf[12];
															P_= fn_klhg(vektor);
													
															if(P_<=P0)p2+=P_;
															p+=P_;
															
															printf("\r%.14f",p);
														}

														if(sw_==2)
														{
															zlr[0]++;
															//printf("\r%.0f                ",zlr[0]);
														}

													}
													Lauf[11]++;
													if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]>n_) break;
													if(Lauf[2]+ Lauf[5]+ Lauf[8] + Lauf[11]> S[2]) break;
												}
												Lauf[11]=0;Lauf[10]++;
												if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]>n_) break;
												if(Lauf[1]+ Lauf[4]+ Lauf[7] + Lauf[10]> S[1]) break;
											}
											Lauf[10]=0;Lauf[9]++;
											zlr[1]++;
											zlr[2]=zlr[1];
											if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]>n_) break;
											if(Lauf[7]+  Lauf[8]+ Lauf[9]>  Z[3]) break;//
										}
										Lauf[9]=0;Lauf[8]++;
										zlr[1]=0;zlr[2]=0;
										if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]>n_) break;
									}
									Lauf[8]=0; Lauf[7]++;
									if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]>n_) break;
								}
								Lauf[7]=0;Lauf[6]++;
								if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]>n_) break;
								if(Lauf[4]+  Lauf[5]+ Lauf[6]>  Z[2]) break;//
							}
							Lauf[6]=0; Lauf[5]++;
							if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]>n_) break;
						}
						Lauf[5]=0; Lauf[4]++;
						if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]>n_) break;
					}
					Lauf[4]=0; Lauf[3]++;if(p>= crit)break;
					if(Lauf[1]+  Lauf[2]+ Lauf[3]>  Z[1]) break;//
				}
				Lauf[3]=0; Lauf[2]++;if(p>= crit)break;						
			}
			Lauf[2]=0;Lauf[1]++;
			if(p>= crit)break;
		}
	}

	//
	// --------------------------------------------------------------------------------------------------------------- 4x4 //
	if(wert[1]==4 && wert[2]==4) 
	{
		while(Lauf[1]<= R_)
		{
			while(Lauf[2]<= R_)
			{
				while(Lauf[3]<= R_)
				{
					while(Lauf[4]<= R_)
					{
						while(Lauf[5]<= R_)
						{
							while(Lauf[6]<= R_)
							{
								while(Lauf[7]<= R_)
								{
									while(Lauf[8]<= R_)
									{
										while(Lauf[9]<= R_)
										{
											while(Lauf[10]<= R_)
											{
												while(Lauf[11]<= R_)
												{
													while(Lauf[12]<= R_)
													{
														while(Lauf[13]<= R_)
														{
															while(Lauf[14]<= n_-zlr[1])
															{
																while(Lauf[15]<= n_-zlr[2])
																{	
																	Lauf[16] =n_-Lauf[1]-Lauf[2]-Lauf[3]-Lauf[4]-Lauf[5]-Lauf[6]-Lauf[7]-Lauf[8]-Lauf[9]-Lauf[10]-Lauf[11]-Lauf[12]-Lauf[13]-Lauf[14]-Lauf[15];

																	if (Lauf[16]<0) break;
																	
																	if(Lauf[1]+ Lauf[2]+ Lauf[3]+ Lauf[4]>  Z[1]) break;//
																	if(Lauf[5]+ Lauf[6]+ Lauf[7]+ Lauf[8]>  Z[2]) break;//
																	if(Lauf[9]+ Lauf[10]+Lauf[11]+Lauf[12]> Z[3]) break;//
																	if(Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]> Z[4]) break;//

																	if(Lauf[1]+ Lauf[5]+ Lauf[9]+  Lauf[13]> S[1]) break;
																	if(Lauf[2]+ Lauf[6]+ Lauf[10]+ Lauf[14]> S[2]) break;
																	if(Lauf[3]+ Lauf[7]+ Lauf[11]+ Lauf[15]> S[3]) break;
																
																	if(Lauf[4]+ Lauf[8]+ Lauf[12]+ Lauf[16]==S[4])
																	{
																		if(sw_==1)
																		{
																						vektor[3]=Lauf[1];
																						vektor[4]=Lauf[2];
																						vektor[5]=Lauf[3];
																						vektor[6]=Lauf[4];
																						vektor[7]=Lauf[5];
																						vektor[8]=Lauf[6];
																						vektor[9]=Lauf[7];
																						vektor[10]=Lauf[8];
																						vektor[11]=Lauf[9];
																						vektor[12]=Lauf[10];
																						vektor[13]=Lauf[11];
																						vektor[14]=Lauf[12];
																						vektor[15]=Lauf[13];
																						vektor[16]=Lauf[14];
																						vektor[17]=Lauf[15];
																						vektor[18]=Lauf[16];
																			P_= fn_klhg(vektor);
																	
																			if(P_<=P0)p2+=P_;
																			p+=P_;
																			
																			printf("\r%.14f",p);
																		}

																		if(sw_==2)
																		{
																			zlr[0]++;
																			//printf("\r%.0f                ",zlr[0]);
																		}
																	
																	}
																	Lauf[15]++;//if(p>= crit)break;
																	if(Lauf[3]+ Lauf[7]+ Lauf[11]+ Lauf[15]> S[3]) break;

																}
																Lauf[15]=0;Lauf[14]++;//if(p>= crit)break;

																if(Lauf[2]+ Lauf[6]+ Lauf[10]+ Lauf[14]> S[2]) break;
															}
															Lauf[14]=0;Lauf[13]++;//if(p>= crit)break;
															zlr[1]++;
															zlr[2]=zlr[1];
														
														if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]>n_) break;
															if(Lauf[1]+ Lauf[5]+ Lauf[9]+  Lauf[13]> S[1]) break;

														}
														Lauf[13]=0;Lauf[12]++;//if(p>= crit)break;
														zlr[1]=0;zlr[2]=0;

														if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]>n_) break;
														if(Lauf[9]+ Lauf[10]+Lauf[11]+Lauf[12]> Z[3]) break;//
													}
													Lauf[12]=0; Lauf[11]++;//if(p>= crit)break;
													if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]>n_) break;
												}
												Lauf[11]=0;Lauf[10]++;//if(p>= crit)break;
												if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]>n_) break;
											}
											Lauf[10]=0; Lauf[9]++;//if(p>= crit)break;
											if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]>n_) break;
										}
										Lauf[9]=0; Lauf[8]++;//if(p>= crit)break;
										if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]>n_) break;
										if(Lauf[5]+ Lauf[6]+ Lauf[7]+ Lauf[8]>  Z[2]) break;//
									}
									Lauf[8]=0; Lauf[7]++;//if(p>= crit)break;
									if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]>n_) break;
								}
								Lauf[7]=0; Lauf[6]++;//if(p>= crit)break;
								if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]>n_) break;
							}
							Lauf[6]=0; Lauf[5]++;//if(p>= crit)break;
							if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]>n_) break;
						}
						Lauf[5]=0; Lauf[4]++;//if(p>= crit)break;
						if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]>n_) break;
						if(Lauf[1]+ Lauf[2]+ Lauf[3]+ Lauf[4]>  Z[1]) break;
					}
					Lauf[4]=0; Lauf[3]++;if(p>= crit)break;
					//if(Lauf[1]+Lauf[2]+Lauf[3]>n_) break;
				}
				Lauf[3]=0; Lauf[2]++;if(p>= crit)break;
				//if(Lauf[1]+Lauf[2]>n_) break;
				
			}
			Lauf[2]=0;Lauf[1]++;if(p>= crit)break;
		}
	}

	//
	// --------------------------------------------------------------------------------------------------------------- 2x5 //
	if(wert[1]==2 && wert[2]==5) 
	{
		while(Lauf[1]<= R_)
		{
			while(Lauf[2]<= R_)
			{
				while(Lauf[3]<= R_)
				{
					while(Lauf[4]<= R_)
					{
						while(Lauf[5]<= R_)
						{
							while(Lauf[6]<= R_)
							{
								while(Lauf[7]<= R_)
								{
									while(Lauf[8]<= n_-zlr[1])
									{
										while(Lauf[9]<= n_-zlr[2])
										{	
											Lauf[10] =n_-Lauf[1]-Lauf[2]-Lauf[3]-Lauf[4]-Lauf[5]-Lauf[6]-Lauf[7]-Lauf[8]-Lauf[9];

											if (Lauf[10]<0) break;
											
											if(Lauf[1]+ Lauf[2]+ Lauf[3]+ Lauf[4]+ Lauf[5]>  Z[1]) break;//
											if(Lauf[6]+ Lauf[7]+ Lauf[8]+ Lauf[9]+ Lauf[10]> Z[2]) break;//
										
											if(Lauf[1]+ Lauf[6]> S[1]) break;
											if(Lauf[2]+ Lauf[7]> S[2]) break;
											if(Lauf[3]+ Lauf[8]> S[3]) break;
											if(Lauf[4]+ Lauf[9]> S[4]) break;
										
											if(Lauf[5]+ Lauf[10]==S[5])
											{
												if(sw_==1)
												{
																vektor[3]=Lauf[1];
																vektor[4]=Lauf[2];
																vektor[5]=Lauf[3];
																vektor[6]=Lauf[4];
																vektor[7]=Lauf[5];
																vektor[8]=Lauf[6];
																vektor[9]=Lauf[7];
																vektor[10]=Lauf[8];
																vektor[11]=Lauf[9];
																vektor[12]=Lauf[10];
													P_= fn_klhg(vektor);
											
													if(P_<=P0)p2+=P_;
													p+=P_;
												
													printf("\r%.14f",p);
												}

												if(sw_==2)
												{
													zlr[0]++;
													//printf("\r%.0f                ",zlr[0]);
												}
											}
											Lauf[9]++;
											if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]>n_) break;
											if(Lauf[4]+ Lauf[9]> S[4]) break;
										}
										Lauf[9]=0;Lauf[8]++;
										if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]>n_) break;
										if(Lauf[3]+ Lauf[8]> S[3]) break;
									}
									Lauf[8]=0;Lauf[7]++;
									zlr[1]++;
									zlr[2]=zlr[1];
									if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]>n_) break;
									if(Lauf[2]+ Lauf[7]> S[2]) break;
									
								}
								Lauf[7]=0;Lauf[6]++;
								zlr[1]=0;zlr[2]=0;
								if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]>n_) break;
								if(Lauf[1]+ Lauf[6]> S[1]) break;
							}
							Lauf[6]=0; Lauf[5]++;
							if(Lauf[1]+ Lauf[2]+ Lauf[3]+ Lauf[4]+ Lauf[5]>  Z[1]) break;
							}
						Lauf[5]=0; Lauf[4]++;
						if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]>n_) break;
					}
					Lauf[4]=0; Lauf[3]++;if(p>= crit)break;
				}
				Lauf[3]=0; Lauf[2]++;if(p>= crit)break;						
			}
			Lauf[2]=0;Lauf[1]++;
			if(p>= crit)break;
		}
	}

	//
	// --------------------------------------------------------------------------------------------------------------- 5x2 //
	if(wert[1]==5 && wert[2]==2) 
	{
		while(Lauf[1]<= R_)
		{
			while(Lauf[2]<= R_)
			{
				while(Lauf[3]<= R_)
				{
					while(Lauf[4]<= R_)
					{
						while(Lauf[5]<= R_)
						{
							while(Lauf[6]<= R_)
							{
								while(Lauf[7]<= R_)
								{
									while(Lauf[8]<= n_-zlr[1])
									{
										while(Lauf[9]<= n_-zlr[2])
										{	
											Lauf[10] =n_-Lauf[1]-Lauf[2]-Lauf[3]-Lauf[4]-Lauf[5]-Lauf[6]-Lauf[7]-Lauf[8]-Lauf[9];

											if (Lauf[10]<0) break;
											
											if(Lauf[1]+ Lauf[2]> Z[1]) break;//
											if(Lauf[3]+ Lauf[4]> Z[2]) break;//
											if(Lauf[5]+ Lauf[6]> Z[3]) break;//
											if(Lauf[7]+ Lauf[8]> Z[4]) break;//
											if(Lauf[9]+ Lauf[10]> Z[5]) break;//
										
											if(Lauf[1]+ Lauf[3]+ Lauf[5]+ Lauf[7]+ Lauf[9]> S[1]) break;
																					
											if(Lauf[2]+ Lauf[4]+ Lauf[6]+ Lauf[8]+ Lauf[10]==S[2])
											{
												if(sw_==1)
												{
																vektor[3]=Lauf[1];
																vektor[4]=Lauf[2];
																vektor[5]=Lauf[3];
																vektor[6]=Lauf[4];
																vektor[7]=Lauf[5];
																vektor[8]=Lauf[6];
																vektor[9]=Lauf[7];
																vektor[10]=Lauf[8];
																vektor[11]=Lauf[9];
																vektor[12]=Lauf[10];
													P_= fn_klhg(vektor);
											
													if(P_<=P0)p2+=P_;
													p+=P_;
												
													printf("\r%.14f",p);
												}

												if(sw_==2)
												{
													zlr[0]++;
													//printf("\r%.0f                ",zlr[0]);
												}
											}
											Lauf[9]++;
											if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]>n_) break;
											if(Lauf[1]+ Lauf[3]+ Lauf[5]+ Lauf[7]+ Lauf[9]> S[1]) break;
										}
										Lauf[9]=0;Lauf[8]++;
										if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]>n_) break;
										if(Lauf[7]+ Lauf[8]> Z[4]) break;//
									}
									Lauf[8]=0;Lauf[7]++;
									zlr[1]++;
									zlr[2]=zlr[1];
									if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]>n_) break;
								}
								Lauf[7]=0;Lauf[6]++;
								zlr[1]=0;zlr[2]=0;
								if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]>n_) break;
								if(Lauf[5]+ Lauf[6]> Z[3]) break;//
							}
							Lauf[6]=0; Lauf[5]++;
							if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]>n_) break;
							}
						Lauf[5]=0; Lauf[4]++;
						if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]>n_) break;
						if(Lauf[3]+ Lauf[4]> Z[2]) break;//
					}
					Lauf[4]=0; Lauf[3]++;if(p>= crit)break;
				}
				Lauf[3]=0; Lauf[2]++;if(p>= crit)break;
				if(Lauf[1]+ Lauf[2]> Z[1]) break;//
			}
			Lauf[2]=0;Lauf[1]++;
			if(p>= crit)break;
		}
	}

	//
	// --------------------------------------------------------------------------------------------------------------- 3x5 //
	if(wert[1]==3 && wert[2]==5) 
	{
		while(Lauf[1]<= R_)
		{
			while(Lauf[2]<= R_)
			{
				while(Lauf[3]<= R_)
				{
					while(Lauf[4]<= R_)
					{
						while(Lauf[5]<= R_)
						{
							while(Lauf[6]<= R_)
							{
								while(Lauf[7]<= R_)
								{
									while(Lauf[8]<= R_)
									{
										while(Lauf[9]<= R_)
										{
											while(Lauf[10]<= R_)
											{
												while(Lauf[11]<= R_)
												{
													while(Lauf[12]<= R_)
													{
														while(Lauf[13]<= n_-zlr[1])
														{
															while(Lauf[14]<= n_-zlr[2])
															{	
														 
																Lauf[15] =n_-Lauf[1]-Lauf[2]-Lauf[3]-Lauf[4]-Lauf[5]-Lauf[6]-Lauf[7]-Lauf[8]-Lauf[9]-Lauf[10]-Lauf[11]-Lauf[12]-Lauf[13]-Lauf[14];

																if (Lauf[15]<0) break;
																
																if(Lauf[1]+  Lauf[2]+  Lauf[3]+  Lauf[4]+  Lauf[5]>  Z[1]) break;//
																if(Lauf[6]+  Lauf[7]+  Lauf[8]+  Lauf[9]+  Lauf[10]> Z[2]) break;//
																if(Lauf[11]+ Lauf[12]+ Lauf[13]+ Lauf[14]+ Lauf[15]> Z[3]) break;//
																

																if(Lauf[1]+ Lauf[6]+ Lauf[11]> S[1]) break;
																if(Lauf[2]+ Lauf[7]+ Lauf[12]> S[2]) break;
																if(Lauf[3]+ Lauf[8]+ Lauf[13]> S[3]) break;
																if(Lauf[4]+ Lauf[9]+ Lauf[14]> S[4]) break;
															
																if(Lauf[5]+ Lauf[10]+ Lauf[15]==S[5])
																{
																	if(sw_==1)
																	{
																					vektor[3]=Lauf[1];
																					vektor[4]=Lauf[2];
																					vektor[5]=Lauf[3];
																					vektor[6]=Lauf[4];
																					vektor[7]=Lauf[5];
																					vektor[8]=Lauf[6];
																					vektor[9]=Lauf[7];
																					vektor[10]=Lauf[8];
																					vektor[11]=Lauf[9];
																					vektor[12]=Lauf[10];
																					vektor[13]=Lauf[11];
																					vektor[14]=Lauf[12];
																					vektor[15]=Lauf[13];
																					vektor[16]=Lauf[14];
																					vektor[17]=Lauf[15];
																		P_= fn_klhg(vektor);
																
																		if(P_<=P0)p2+=P_;
																		p+=P_;
																	
																		printf("\r%.14f",p);
																	}

																	if(sw_==2)
																	{
																		zlr[0]++;
																		//printf("\r%.0f                ",zlr[0]);
																	}
																}
																Lauf[14]++;//if(p>= crit)break;
																if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]>n_) break;
																if(Lauf[4]+ Lauf[9]+ Lauf[14]> S[4]) break;
															}
															Lauf[14]=0;Lauf[13]++;//if(p>= crit)break;
															if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]>n_) break;
															if(Lauf[3]+ Lauf[8]+ Lauf[13]> S[3]) break;
														}
														Lauf[13]=0;Lauf[12]++;//if(p>= crit)break;	
														zlr[1]++;
														zlr[2]=zlr[1];
														if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]>n_) break;
														if(Lauf[2]+ Lauf[7]+ Lauf[12]> S[2]) break;
													}
													Lauf[12]=0;Lauf[11]++;//if(p>= crit)break;	
													zlr[1]=0;zlr[2]=0;
													if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]>n_) break;
													if(Lauf[1]+ Lauf[6]+ Lauf[11]> S[1]) break;
												}
												Lauf[11]=0;Lauf[10]++;//if(p>= crit)break;
												if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]>n_) break;
												if(Lauf[6]+  Lauf[7]+ Lauf[8]+ Lauf[9]+  Lauf[10]> Z[2]) break;//
											}
											Lauf[10]=0; Lauf[9]++;//if(p>= crit)break;
											if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]>n_) break;
										}
										Lauf[9]=0;Lauf[8]++;//if(p>= crit)break;
										if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]>n_) break;
									}
									Lauf[8]=0; Lauf[7]++;//if(p>= crit)break;
									if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]>n_) break;
								}
								Lauf[7]=0; Lauf[6]++;//if(p>= crit)break;
								if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]>n_) break;
							}
							Lauf[6]=0; Lauf[5]++;//if(p>= crit)break;
							if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]>Z[1]) break;
						}
						Lauf[5]=0; Lauf[4]++;//if(p>= crit)break;
						if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]>n_) break;
					}
					Lauf[4]=0; Lauf[3]++;if(p>= crit)break;
				}
				Lauf[3]=0; Lauf[2]++;if(p>= crit)break;
			}
			Lauf[2]=0;Lauf[1]++;if(p>= crit)break;
		}
	}

	//
	// --------------------------------------------------------------------------------------------------------------- 5x3 //
	if(wert[1]==5 && wert[2]==3) 
	{
		while(Lauf[1]<= R_)
		{
			while(Lauf[2]<= R_)
			{
				while(Lauf[3]<= R_)
				{
					while(Lauf[4]<= R_)
					{
						while(Lauf[5]<= R_)
						{
							while(Lauf[6]<= R_)
							{
								while(Lauf[7]<= R_)
								{
									while(Lauf[8]<= R_)
									{
										while(Lauf[9]<= R_)
										{
											while(Lauf[10]<= R_)
											{
												while(Lauf[11]<= R_)
												{
													while(Lauf[12]<= R_)
													{
														while(Lauf[13]<= n_-zlr[1])
														{
															while(Lauf[14]<= n_-zlr[2])
															{																 
																Lauf[15] =n_-Lauf[1]-Lauf[2]-Lauf[3]-Lauf[4]-Lauf[5]-Lauf[6]-Lauf[7]-Lauf[8]-Lauf[9]-Lauf[10]-Lauf[11]-Lauf[12]-Lauf[13]-Lauf[14];

																if (Lauf[15]<0) break;
																
																if(Lauf[1]+  Lauf[2]+  Lauf[3]>  Z[1]) break;//
																if(Lauf[4]+  Lauf[5]+  Lauf[6]>  Z[2]) break;//
																if(Lauf[7]+  Lauf[8]+  Lauf[9]>  Z[3]) break;//
																if(Lauf[10]+ Lauf[11]+ Lauf[12]> Z[4]) break;//
																if(Lauf[13]+ Lauf[14]+ Lauf[15]> Z[5]) break;//
																
																if(Lauf[1]+  Lauf[4]+  Lauf[7]+  Lauf[10]+  Lauf[13]> S[1]) break;
																if(Lauf[2]+  Lauf[5]+  Lauf[8]+  Lauf[11]+  Lauf[14]> S[2]) break;
															
																if(Lauf[3]+  Lauf[6]+  Lauf[9]+  Lauf[12]+  Lauf[15]==S[3])
																{
																	if(sw_==1)
																	{
																					vektor[3]=Lauf[1];
																					vektor[4]=Lauf[2];
																					vektor[5]=Lauf[3];
																					vektor[6]=Lauf[4];
																					vektor[7]=Lauf[5];
																					vektor[8]=Lauf[6];
																					vektor[9]=Lauf[7];
																					vektor[10]=Lauf[8];
																					vektor[11]=Lauf[9];
																					vektor[12]=Lauf[10];
																					vektor[13]=Lauf[11];
																					vektor[14]=Lauf[12];
																					vektor[15]=Lauf[13];
																					vektor[16]=Lauf[14];
																					vektor[17]=Lauf[15];
																		P_= fn_klhg(vektor);
																
																		if(P_<=P0)p2+=P_;
																		p+=P_;
																	
																		printf("\r%.14f",p);
																	}

																	if(sw_==2)
																	{
																		zlr[0]++;
																		//printf("\r%.0f                ",zlr[0]);
																	}
																}
																Lauf[14]++;//if(p>= crit)break;
																if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]>n_) break;
																if(Lauf[2]+  Lauf[5]+  Lauf[8]+  Lauf[11]+  Lauf[14]> S[2]) break;
															}
															Lauf[14]=0;Lauf[13]++;//if(p>= crit)break;
															if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]>n_) break;
															if(Lauf[1]+  Lauf[4]+  Lauf[7]+  Lauf[10]+  Lauf[13]> S[1]) break;
														}
														Lauf[13]=0;Lauf[12]++;//if(p>= crit)break;
														if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]>n_) break;
														zlr[1]++;
														zlr[2]=zlr[1];
														if(Lauf[10]+ Lauf[11]+ Lauf[12]> Z[4]) break;//
													}
													Lauf[12]=0;Lauf[11]++;//if(p>= crit)break;
													if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]>n_) break;
													zlr[1]=0;zlr[2]=0;
												}
												Lauf[11]=0;Lauf[10]++;//if(p>= crit)break;
												if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]>n_) break;
											}
											Lauf[10]=0; Lauf[9]++;//if(p>= crit)break;
											if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]>n_) break;
											if(Lauf[7]+  Lauf[8]+  Lauf[9]>  Z[3]) break;//
										}
										Lauf[9]=0;Lauf[8]++;//if(p>= crit)break;
										if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]>n_) break;
										
									}
									Lauf[8]=0; Lauf[7]++;//if(p>= crit)break;
									if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]>n_) break;
								}
								Lauf[7]=0; Lauf[6]++;//if(p>= crit)break;
								if(Lauf[4]+  Lauf[5]+  Lauf[6]>  Z[2]) break;//
								if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]>n_) break;
							}
							Lauf[6]=0; Lauf[5]++;//if(p>= crit)break;
							if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]>n_) break;
						}
						Lauf[5]=0; Lauf[4]++;//if(p>= crit)break;
						if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]>n_) break;
					}
					Lauf[4]=0; Lauf[3]++;if(p>= crit)break;
					if(Lauf[1]+  Lauf[2]+  Lauf[3]>  Z[1]) break;//
				}
				Lauf[3]=0; Lauf[2]++;if(p>= crit)break;
			}
			Lauf[2]=0;Lauf[1]++;if(p>= crit)break;
		}
	}

	
	//
	// --------------------------------------------------------------------------------------------------------------- 5x5 //
	if(wert[1]==5 && wert[2]==5) 
	{
		while(Lauf[1]<= R_)
		{
			while(Lauf[2]<= R_)
			{
				while(Lauf[3]<= R_)
				{
					while(Lauf[4]<= R_)
					{
						while(Lauf[5]<= R_)
						{
							while(Lauf[6]<= R_)
							{
								while(Lauf[7]<= R_)
								{
									while(Lauf[8]<= R_)
									{
										while(Lauf[9]<= R_)
										{
											while(Lauf[10]<= R_)
											{
												while(Lauf[11]<= R_)
												{
													while(Lauf[12]<= R_)
													{
														while(Lauf[13]<= R_)
														{
															while(Lauf[14]<= R_)
															{
																while(Lauf[15]<= R_)
																{
																	while(Lauf[16]<= R_)
																	{
																		while(Lauf[17]<= R_)
																		{
																			while(Lauf[18]<= R_)
																			{
																				while(Lauf[19]<= R_)
																				{
																					while(Lauf[20]<= R_)
																					{
																						while(Lauf[21]<= R_)
																						{
																							while(Lauf[22]<= R_)
																							{
																								while(Lauf[23]<= n_-zlr[1])
																								{
																									while(Lauf[24]<= n_-zlr[2])
																									{													 
																										Lauf[25] =n_-Lauf[1]-Lauf[2]-Lauf[3]-Lauf[4]-Lauf[5]-Lauf[6]-Lauf[7]-Lauf[8]-Lauf[9]-Lauf[10]-Lauf[11]-Lauf[12]-Lauf[13]-Lauf[14]-Lauf[15]-Lauf[16]-Lauf[17]-Lauf[18]-Lauf[19]-Lauf[20]-Lauf[21]-Lauf[22]-Lauf[23]-Lauf[24];

																										if (Lauf[25]<0) break;
																										
																										if(Lauf[1]+  Lauf[2]+  Lauf[3]+  Lauf[4]+  Lauf[5]>  Z[1]) break;//
																										if(Lauf[6]+  Lauf[7]+  Lauf[8]+  Lauf[9]+  Lauf[10]> Z[2]) break;//
																										if(Lauf[11]+ Lauf[12]+ Lauf[13]+ Lauf[14]+ Lauf[15]> Z[3]) break;//
																										if(Lauf[16]+ Lauf[17]+ Lauf[18]+ Lauf[19]+ Lauf[20]> Z[4]) break;//
																										if(Lauf[21]+ Lauf[22]+ Lauf[23]+ Lauf[24]+ Lauf[25]> Z[5]) break;//

																										if(Lauf[1]+ Lauf[6]+ Lauf[11]+ Lauf[16]+ Lauf[21]> S[1]) break;
																										if(Lauf[2]+ Lauf[7]+ Lauf[12]+ Lauf[17]+ Lauf[22]> S[2]) break;
																										if(Lauf[3]+ Lauf[8]+ Lauf[13]+ Lauf[18]+ Lauf[23]> S[3]) break;
																										if(Lauf[4]+ Lauf[9]+ Lauf[14]+ Lauf[19]+ Lauf[24]> S[4]) break;
																									
																										if(Lauf[5]+ Lauf[10]+ Lauf[15]+ Lauf[20]+ Lauf[25]==S[5])
																										{
																											if(sw_==1)
																											{
																															vektor[3]=Lauf[1];
																															vektor[4]=Lauf[2];
																															vektor[5]=Lauf[3];
																															vektor[6]=Lauf[4];
																															vektor[7]=Lauf[5];
																															vektor[8]=Lauf[6];
																															vektor[9]=Lauf[7];
																															vektor[10]=Lauf[8];
																															vektor[11]=Lauf[9];
																															vektor[12]=Lauf[10];
																															vektor[13]=Lauf[11];
																															vektor[14]=Lauf[12];
																															vektor[15]=Lauf[13];
																															vektor[16]=Lauf[14];
																															vektor[17]=Lauf[15];
																															vektor[18]=Lauf[16];
																															vektor[19]=Lauf[17];
																															vektor[20]=Lauf[18];
																															vektor[21]=Lauf[19];
																															vektor[22]=Lauf[20];
																															vektor[23]=Lauf[21];
																															vektor[24]=Lauf[22];
																															vektor[25]=Lauf[23];
																															vektor[26]=Lauf[24];
																															vektor[27]=Lauf[25];
																												P_= fn_klhg(vektor);
																										
																												if(P_<=P0)p2+=P_;
																												p+=P_;
																											
																												printf("\r%.14f",p);
																											}

																											if(sw_==2)
																											{
																												zlr[0]++;
																												//printf("\r%.0f                ",zlr[0]);
																											}
																										}
																										Lauf[24]++;//if(p>= crit)break;
																										if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]+Lauf[17]+Lauf[18]+Lauf[19]+Lauf[20]+Lauf[21]+Lauf[22]+Lauf[23]+Lauf[24]>n_) break;
																										if(Lauf[4]+ Lauf[9]+ Lauf[14]+ Lauf[19]+ Lauf[24]> S[4]) break;
																									}
																									Lauf[24]=0;Lauf[23]++;//if(p>= crit)break;
																									if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]+Lauf[17]+Lauf[18]+Lauf[19]+Lauf[20]+Lauf[21]+Lauf[22]+Lauf[23]>n_) break;
																									if(Lauf[3]+ Lauf[8]+ Lauf[13]+ Lauf[18]+ Lauf[23]> S[3]) break;
																								}
																								Lauf[23]=0;Lauf[22]++;//if(p>= crit)break;
																								zlr[1]++;
																								zlr[2]=zlr[1];
																								if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]+Lauf[17]+Lauf[18]+Lauf[19]+Lauf[20]+Lauf[21]+Lauf[22]>n_) break;
																								if(Lauf[2]+ Lauf[7]+ Lauf[12]+ Lauf[17]+ Lauf[22]> S[2]) break;
																							}
																							Lauf[22]=0;Lauf[21]++;//if(p>= crit)break;
																							zlr[1]=0;zlr[2]=0;
																							if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]+Lauf[17]+Lauf[18]+Lauf[19]+Lauf[20]+Lauf[21]>n_) break;
																							if(Lauf[1]+ Lauf[6]+ Lauf[11]+ Lauf[16]+ Lauf[21]> S[1]) break;
																						}
																						Lauf[21]=0; Lauf[20]++;//if(p>= crit)break;
																						if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]+Lauf[17]+Lauf[18]+Lauf[19]+Lauf[20]>n_) break;
																						if(Lauf[16]+ Lauf[17]+ Lauf[18]+ Lauf[19]+ Lauf[20]> Z[4]) break;//
																					}
																					Lauf[20]=0;Lauf[19]++;//if(p>= crit)break;
																					if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]+Lauf[17]+Lauf[18]+Lauf[19]>n_) break;
																				}
																				Lauf[19]=0; Lauf[18]++;//if(p>= crit)break;
																				if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]+Lauf[17]+Lauf[18]>n_) break;
																			}
																			Lauf[18]=0; Lauf[17]++;//if(p>= crit)break;
																				if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]+Lauf[17]>n_) break;
																		}
																		Lauf[17]=0; Lauf[16]++;//if(p>= crit)break;
																		if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]>n_) break;
																	}
																	Lauf[16]=0; Lauf[15]++;//if(p>= crit)break;
																	if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]>n_) break;
																	if(Lauf[11]+ Lauf[12]+ Lauf[13]+ Lauf[14]+ Lauf[15]> Z[3]) break;//
																}
																Lauf[15]=0; Lauf[14]++;//if(p>= crit)break;
																if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]>n_) break;
															}
															Lauf[14]=0; Lauf[13]++;//if(p>= crit)break;
															if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]>n_) break;
														}
														Lauf[13]=0; Lauf[12]++;//if(p>= crit)break;
														if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]>n_) break;
													}
													Lauf[12]=0; Lauf[11]++;//if(p>= crit)break;
													if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]>n_) break;
												}
												Lauf[11]=0;Lauf[10]++;//if(p>= crit)break;
												if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]>n_) break;
												if(Lauf[6]+  Lauf[7]+  Lauf[8]+  Lauf[9]+  Lauf[10]> Z[2]) break;//
											}
											Lauf[10]=0; Lauf[9]++;//if(p>= crit)break;
											if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]>n_) break;
										}
										Lauf[9]=0;Lauf[8]++;//if(p>= crit)break;
										if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]>n_) break;
									}
									Lauf[8]=0; Lauf[7]++;//if(p>= crit)break;
									if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]>n_) break;
								}
								Lauf[7]=0; Lauf[6]++;//if(p>= crit)break;
								if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]>n_) break;
							}
							Lauf[6]=0; Lauf[5]++;//if(p>= crit)break;
							if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]>Z[1]) break;
						}
						Lauf[5]=0; Lauf[4]++;//if(p>= crit)break;
						if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]>n_) break;
					}
					Lauf[4]=0; Lauf[3]++;if(p>= crit)break;
				}
				Lauf[3]=0; Lauf[2]++;if(p>= crit)break;
			}
			Lauf[2]=0;Lauf[1]++;if(p>= crit)break;
		}
	}
	//
	// --------------------------------------------------------------------------------------------------------------- 4x5 //
	if(wert[1]==4 && wert[2]==5) 
	{
		while(Lauf[1]<= R_)
		{
			while(Lauf[2]<= R_)
			{
				while(Lauf[3]<= R_)
				{
					while(Lauf[4]<= R_)
					{
						while(Lauf[5]<= R_)
						{
							while(Lauf[6]<= R_)
							{
								while(Lauf[7]<= R_)
								{
									while(Lauf[8]<= R_)
									{
										while(Lauf[9]<= R_)
										{
											while(Lauf[10]<= R_)
											{
												while(Lauf[11]<= R_)
												{
													while(Lauf[12]<= R_)
													{
														while(Lauf[13]<= R_)
														{
															while(Lauf[14]<= R_)
															{
																while(Lauf[15]<= R_)
																{
																	while(Lauf[16]<= R_)
																	{
																		while(Lauf[17]<= R_)
																		{
																			while(Lauf[18]<= n_-zlr[1])
																			{
																				while(Lauf[19]<= n_-zlr[2])
																				{														 
																					Lauf[20] =n_-Lauf[1]-Lauf[2]-Lauf[3]-Lauf[4]-Lauf[5]-Lauf[6]-Lauf[7]-Lauf[8]-Lauf[9]-Lauf[10]-Lauf[11]-Lauf[12]-Lauf[13]-Lauf[14]-Lauf[15]-Lauf[16]-Lauf[17]-Lauf[18]-Lauf[19];

																					if (Lauf[20]<0) break;
																					
																					if(Lauf[1]+  Lauf[2]+  Lauf[3]+  Lauf[4]+  Lauf[5]>  Z[1]) break;//
																					if(Lauf[6]+  Lauf[7]+  Lauf[8]+  Lauf[9]+  Lauf[10]> Z[2]) break;//
																					if(Lauf[11]+ Lauf[12]+ Lauf[13]+ Lauf[14]+ Lauf[15]> Z[3]) break;//
																					if(Lauf[16]+ Lauf[17]+ Lauf[18]+ Lauf[19]+ Lauf[20]> Z[4]) break;//

																					if(Lauf[1]+ Lauf[6]+ Lauf[11]+ Lauf[16]> S[1]) break;
																					if(Lauf[2]+ Lauf[7]+ Lauf[12]+ Lauf[17]> S[2]) break;
																					if(Lauf[3]+ Lauf[8]+ Lauf[13]+ Lauf[18]> S[3]) break;
																					if(Lauf[4]+ Lauf[9]+ Lauf[14]+ Lauf[19]> S[4]) break;
																				
																					if(Lauf[5]+ Lauf[10]+ Lauf[15]+ Lauf[20]==S[5])
																					{
																						if(sw_==1)
																						{
																										vektor[3]=Lauf[1];
																										vektor[4]=Lauf[2];
																										vektor[5]=Lauf[3];
																										vektor[6]=Lauf[4];
																										vektor[7]=Lauf[5];
																										vektor[8]=Lauf[6];
																										vektor[9]=Lauf[7];
																										vektor[10]=Lauf[8];
																										vektor[11]=Lauf[9];
																										vektor[12]=Lauf[10];
																										vektor[13]=Lauf[11];
																										vektor[14]=Lauf[12];
																										vektor[15]=Lauf[13];
																										vektor[16]=Lauf[14];
																										vektor[17]=Lauf[15];
																										vektor[18]=Lauf[16];
																										vektor[19]=Lauf[17];
																										vektor[20]=Lauf[18];
																										vektor[21]=Lauf[19];
																										vektor[22]=Lauf[20];
																							P_= fn_klhg(vektor);
																					
																							if(P_<=P0)p2+=P_;
																							p+=P_;
																						
																							printf("\r%.14f",p);
																						}

																						if(sw_==2)
																						{
																							zlr[0]++;
																							//printf("\r%.0f                ",zlr[0]);
																						}
																					}
																					Lauf[19]++;//if(p>= crit)break;
																					if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]+Lauf[17]+Lauf[18]+Lauf[19]>n_) break;
																					if(Lauf[4]+ Lauf[9]+ Lauf[14]+ Lauf[19]> S[4]) break;
																				}
																				Lauf[19]=0;Lauf[18]++;//if(p>= crit)break;
																				if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]+Lauf[17]+Lauf[18]>n_) break;
																				if(Lauf[3]+ Lauf[8]+ Lauf[13]+ Lauf[18]> S[3]) break;
																			}
																			Lauf[18]=0;Lauf[17]++;//if(p>= crit)break;	
																			zlr[1]++;
																			zlr[2]=zlr[1];
																			if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]+Lauf[17]>n_) break;
																			if(Lauf[2]+ Lauf[7]+ Lauf[12]+ Lauf[17]> S[2]) break;
																		}
																		Lauf[17]=0;Lauf[16]++;//if(p>= crit)break;
																		zlr[1]=0;zlr[2]=0;
																		if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]>n_) break;
																		if(Lauf[1]+ Lauf[6]+ Lauf[11]+ Lauf[16]> S[1]) break;
																	}
																	Lauf[16]=0; Lauf[15]++;//if(p>= crit)break;
																	if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]>n_) break;
																
																}
																Lauf[15]=0;Lauf[14]++;//if(p>= crit)break;
																if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]>n_) break;
																if(Lauf[11]+ Lauf[12]+ Lauf[13]+ Lauf[14]+ Lauf[15]> Z[3]) break;//
															}
															Lauf[14]=0; Lauf[13]++;//if(p>= crit)break;
															if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]>n_) break;
														}
														Lauf[13]=0; Lauf[12]++;//if(p>= crit)break;
														if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]>n_) break;
													}
													Lauf[12]=0; Lauf[11]++;//if(p>= crit)break;
													if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]>n_) break;
												}
												Lauf[11]=0; Lauf[10]++;//if(p>= crit)break;
												if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]>n_) break;
												if(Lauf[6]+  Lauf[7]+  Lauf[8]+  Lauf[9]+  Lauf[10]> Z[2]) break;//
											}
											Lauf[10]=0; Lauf[9]++;//if(p>= crit)break;
											if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]>n_) break;
										}
										Lauf[9]=0; Lauf[8]++;//if(p>= crit)break;
										if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]>n_) break;
									}
									Lauf[8]=0; Lauf[7]++;//if(p>= crit)break;
									if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]>n_) break;
								}
								Lauf[7]=0; Lauf[6]++;//if(p>= crit)break;
								if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]>n_) break;
							}
							Lauf[6]=0;Lauf[5]++;//if(p>= crit)break;
							if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]>n_) break;
							if(Lauf[1]+  Lauf[2]+  Lauf[3]+  Lauf[4]+  Lauf[5]>  Z[1]) break;//
						}
						Lauf[5]=0; Lauf[4]++;//if(p>= crit)break;
						if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]>n_) break;
					}
					Lauf[4]=0;Lauf[3]++;if(p>= crit)break;
					if(Lauf[1]+Lauf[2]+Lauf[3]>n_) break;
				}
				Lauf[3]=0; Lauf[2]++;if(p>= crit)break;
			}
			Lauf[2]=0;Lauf[1]++;if(p>= crit)break;
		}
	}

	//
	// --------------------------------------------------------------------------------------------------------------- 5x4 //
	if(wert[1]==5 && wert[2]==4) 
	{
		while(Lauf[1]<= R_)
		{
			while(Lauf[2]<= R_)
			{
				while(Lauf[3]<= R_)
				{
					while(Lauf[4]<= R_)
					{
						while(Lauf[5]<= R_)
						{
							while(Lauf[6]<= R_)
							{
								while(Lauf[7]<= R_)
								{
									while(Lauf[8]<= R_)
									{
										while(Lauf[9]<= R_)
										{
											while(Lauf[10]<= R_)
											{
												while(Lauf[11]<= R_)
												{
													while(Lauf[12]<= R_)
													{
														while(Lauf[13]<= R_)
														{
															while(Lauf[14]<= R_)
															{
																while(Lauf[15]<= R_)
																{
																	while(Lauf[16]<= R_)
																	{
																		while(Lauf[17]<= R_)
																		{
																			while(Lauf[18]<= n_-zlr[1])
																			{
																				while(Lauf[19]<= n_-zlr[2])
																				{																 
																					Lauf[20] =n_-Lauf[1]-Lauf[2]-Lauf[3]-Lauf[4]-Lauf[5]-Lauf[6]-Lauf[7]-Lauf[8]-Lauf[9]-Lauf[10]-Lauf[11]-Lauf[12]-Lauf[13]-Lauf[14]-Lauf[15]-Lauf[16]-Lauf[17]-Lauf[18]-Lauf[19];

																					if (Lauf[20]<0) break;
																					
																					if(Lauf[1]+  Lauf[2]+  Lauf[3]+  Lauf[4]>  Z[1]) break;//
																					if(Lauf[5]+  Lauf[6]+  Lauf[7]+  Lauf[8]>  Z[2]) break;//
																					if(Lauf[9]+  Lauf[10]+ Lauf[11]+ Lauf[12]> Z[3]) break;//
																					if(Lauf[13]+ Lauf[14]+ Lauf[15]+ Lauf[16]> Z[4]) break;//
																					if(Lauf[17]+ Lauf[18]+ Lauf[19]+ Lauf[20]> Z[5]) break;//

																					if(Lauf[1]+ Lauf[5]+ Lauf[9]+  Lauf[13]+ Lauf[17]> S[1]) break;
																					if(Lauf[2]+ Lauf[6]+ Lauf[10]+ Lauf[14]+ Lauf[18]> S[2]) break;
																					if(Lauf[3]+ Lauf[7]+ Lauf[11]+ Lauf[15]+ Lauf[19]> S[3]) break;
																				
																					if(Lauf[4]+ Lauf[8]+ Lauf[12]+ Lauf[16]+ Lauf[20]==S[4])
																					{
																						if(sw_==1)
																						{
																										vektor[3]=Lauf[1];
																										vektor[4]=Lauf[2];
																										vektor[5]=Lauf[3];
																										vektor[6]=Lauf[4];
																										vektor[7]=Lauf[5];
																										vektor[8]=Lauf[6];
																										vektor[9]=Lauf[7];
																										vektor[10]=Lauf[8];
																										vektor[11]=Lauf[9];
																										vektor[12]=Lauf[10];
																										vektor[13]=Lauf[11];
																										vektor[14]=Lauf[12];
																										vektor[15]=Lauf[13];
																										vektor[16]=Lauf[14];
																										vektor[17]=Lauf[15];
																										vektor[18]=Lauf[16];
																										vektor[19]=Lauf[17];
																										vektor[20]=Lauf[18];
																										vektor[21]=Lauf[19];
																										vektor[22]=Lauf[20];
																							P_= fn_klhg(vektor);
																					
																							if(P_<=P0)p2+=P_;
																							p+=P_;
																						
																							printf("\r%.14f",p);
																						}

																						if(sw_==2)
																						{
																							zlr[0]++;
																							//printf("\r%.0f                ",zlr[0]);
																						}
																					}
																					Lauf[19]++;//if(p>= crit)break;
																					if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]+Lauf[17]+Lauf[18]+Lauf[19]>n_) break;
																					if(Lauf[3]+ Lauf[7]+ Lauf[11]+ Lauf[15]+ Lauf[19]> S[3]) break;
																				}
																				Lauf[19]=0;Lauf[18]++;//if(p>= crit)break;
																				if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]+Lauf[17]+Lauf[18]>n_) break;
																				if(Lauf[2]+ Lauf[6]+ Lauf[10]+ Lauf[14]+ Lauf[18]> S[2]) break;
																			}
																			Lauf[18]=0;Lauf[17]++;//if(p>= crit)break;
																			zlr[1]++;
																			zlr[2]=zlr[1];
																			if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]+Lauf[17]>n_) break;
																			if(Lauf[1]+ Lauf[5]+ Lauf[9]+  Lauf[13]+ Lauf[17]> S[1]) break;
																		}
																		Lauf[17]=0;Lauf[16]++;//if(p>= crit)break;
																		zlr[1]=0;zlr[2]=0;
																		if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]+Lauf[16]>n_) break;
																		if(Lauf[13]+ Lauf[14]+ Lauf[15]+ Lauf[16]> Z[4]) break;//
																	}
																	Lauf[16]=0; Lauf[15]++;//if(p>= crit)break;
																	if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]+Lauf[15]>n_) break;
																}
																Lauf[15]=0;Lauf[14]++;//if(p>= crit)break;
																if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]+Lauf[14]>n_) break;
															}
															Lauf[14]=0; Lauf[13]++;//if(p>= crit)break;
															if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]+Lauf[13]>n_) break;
														}
														Lauf[13]=0; Lauf[12]++;//if(p>= crit)break;
															if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]+Lauf[12]>n_) break;
														if(Lauf[9]+  Lauf[10]+ Lauf[11]+ Lauf[12]> Z[3]) break;//
													}
													Lauf[12]=0; Lauf[11]++;//if(p>= crit)break;
														if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]+Lauf[11]>n_) break;
												}
												Lauf[11]=0; Lauf[10]++;//if(p>= crit)break;
													if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]+Lauf[10]>n_) break;
											}
											Lauf[10]=0; Lauf[9]++;//if(p>= crit)break;
												if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]+Lauf[9]>n_) break;
										}
										Lauf[9]=0; Lauf[8]++;//if(p>= crit)break;
											if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]+Lauf[8]>n_) break;
										if(Lauf[5]+  Lauf[6]+  Lauf[7]+  Lauf[8]>  Z[2]) break;//
									}
									Lauf[8]=0; Lauf[7]++;//if(p>= crit)break;
										if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]+Lauf[7]>n_) break;	
								}
								Lauf[7]=0; Lauf[6]++;//if(p>= crit)break;
									if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]+Lauf[6]>n_) break;
							}
							Lauf[6]=0;Lauf[5]++;//if(p>= crit)break;
								if(Lauf[1]+Lauf[2]+Lauf[3]+Lauf[4]+Lauf[5]>n_) break;
						}
						Lauf[5]=0; Lauf[4]++;//if(p>= crit)break;
						if(Lauf[1]+  Lauf[2]+  Lauf[3]+  Lauf[4]>  Z[1]) break;//
					}
					Lauf[4]=0;Lauf[3]++;if(p>= crit)break;
					//if(Lauf[1]+Lauf[2]+Lauf[3]>n_) break;
					
				}
				Lauf[3]=0; Lauf[2]++;if(p>= crit)break;
			}
			Lauf[2]=0;Lauf[1]++;if(p>= crit)break;
		}
	}
	}//if(1) schalter
	//
	// --------------------------------------------------------------------------------------------------------------- kxl //
	/**/
	if(wert[1]>5 || wert[2]>5)//if(1)//
	{
		index[4]=-1;
		
		while(1)
		{
			for (iLauf = 4; iLauf <=  nZ*nS; iLauf++) // allgemeine index generierung 1 - kl-3
			{				
				if(iLauf == 4)
				{ 
					index[4]++;
				}
				//if(index[nZ*nS] > R_)break;
				
				if(index[iLauf] > R_) 
				{ 
					index[iLauf] = 0;
					index[iLauf+1] += 1;	
				}
			
				Lauf[nZ*nS+4-iLauf]=index[iLauf]; //index inversion, beginnend mit kl
			}
			//if(Lauf[4] == 0){ zlr[1]=0;zlr[2]=0; } schneller ohne zlr

			if(index[nZ*nS]> R_ || p>= crit)break; // abbruch nach gesamtdurchlauf oder p >= p crit
					
			while(Lauf[3]<= n_) // index kl-2 generierung //-zlr[1]
			{
				while(Lauf[2]<= n_) // index kl-1 generierung //-zlr[2]
				{	
					iLauf=1;
					while(iLauf<= nZ*nS) 
					{
						z_[iLauf]=Lauf[nZ*nS+1-iLauf];iLauf++;//index als zellenfrequenz  
					}		 
					                                          z_[nZ*nS] =n_ ;
					for (iLauf = 1; iLauf <= nZ*nS-1; iLauf++)z_[nZ*nS]-=z_[iLauf];
					                                      if (z_[nZ*nS]<0) break;    //abbruch bei zkl < 0	

					//Zeilen Z, Spalten S Berechnung
					for(jLauf=1; jLauf<= nZ; jLauf++) Z1[jLauf]=0; //Zeilen auf 0
					for(jLauf=1; jLauf<= nS; jLauf++) S1[jLauf]=0; //Spalten auf 0

																	    for(jLauf=1; jLauf<= nZ; jLauf++) 
					for(iLauf=1+nS*(jLauf-1); iLauf<= nS*jLauf; iLauf++) Z1[jLauf]+=z_[iLauf];          //Zeilen Z

																		  for(jLauf=1; jLauf<= nS; jLauf++) 
					for(iLauf=jLauf; iLauf<= nS*nZ-(nS-jLauf); iLauf+= nS) S1[jLauf]+=z_[iLauf];       //Spalten S
				
					//abbruch bei Z, S > 0	
					                                                            sw=0;
					for(jLauf=1; jLauf<= nZ; jLauf++)   if(Z1[jLauf]> Z[jLauf]) sw=1;
					for(jLauf=1; jLauf<= nS-1; jLauf++) if(S1[jLauf]> S[jLauf]) sw=1;
                                                                             if(sw==1) break; 	

					if(S1[nS]==S[nS]) // Pi <= P0
					{	
		             												  for (iLauf = 1; iLauf <= nZ*nS; iLauf++) 
														vektor[iLauf+2]=z_[iLauf];
											P_= fn_klhg(vektor);
							  if(P_<=P0)p2+=P_;
										 p+=P_;
						printf("\r%.14f",p);   //p bildschirmausgbe

						if(sw_==2)zlr[0]++;
						//printf("\r%.0f                ",zlr[0]);
						
					}
					Lauf[2]++; // index kl-1 
				}
				Lauf[2]=0;Lauf[3]++; // index kl-2
			}
			Lauf[3]=0;
			//zlr[1]++;//
			//zlr[2]=zlr[1];//
		}
	}
	
	//
	// --------------------------------------------------------------------------------------------------------------- --- //

	//fclose(out);
	printf("\r                                         \r");
	if(sw_==1) fn_erg=p2;// 
	if(sw_==2) fn_erg=zlr[0];//  

	return 0;
}