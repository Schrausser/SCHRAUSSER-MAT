//----------------------------------------------------------------------------------------------------| calc_ funktionen, 2^k Kontingenzfelder (2x2 Fixierung), SCHRAUSSER 2010	 //
double fn_2kf0(double wert[100], int zn);
double fn_2kfc(double wert[100], int zn);
long double fn_2kf2(double wert[100], int zn, int sw);

double fn_2kf0(double wert[100], int zn) // hypergeometrische Punkt-Wahrscheinlichkeit P0 zu 2^k - Feldern bei 2x2 Fixierung // HF0 z11,...,z2hk //
//                                       // hypergeometrische Punkt-Wahrscheinlichkeit P0 zu 2x2-Feldern (Fisher Exact Test) // FX1 a,b,c,d //                                      
{
	int iLauf,  kLauf;
	long double fLauf, jLauf, S_[100], N_[100], n_=0,k_, x_, P0_=1,fact;
	double Z1_=1,Z2_=1,Z3_=1,Z4_=1,N1_=1,N2_=1,N3_=1,N4_=1,N5_=1, Z_;

	fn_erg=1;

	k_= (1/log(2))*log(zn); //ordnung k  (max zn=64, max k=6)
	
	if (k_ < 2 || k_ != floor(k_)) {printf("\n\ndesign.0 '2^k= %i, k= %.2f'",  zn, k_); exit(0);}// k >1, ganzzahlig

	//for(jLauf=1; jLauf<= zn; jLauf++)  n_+=wert[jLauf];// n
	for(iLauf=1; iLauf<= 2*k_; iLauf++) S_[iLauf]=0;//S_ =0

	for(iLauf=1; iLauf<= zn; iLauf+=4) // 2x2 Randsummen, ni
	{
		S_[iLauf]=   wert[iLauf]  +wert[iLauf+1]; //Zi1
		S_[iLauf+1]= wert[iLauf]  +wert[iLauf+2]; //Si1
		S_[iLauf+2]= wert[iLauf+2]+wert[iLauf+3]; //Zi2
		S_[iLauf+3]= wert[iLauf+1]+wert[iLauf+3]; //Si2
		N_[iLauf-1]=   S_[iLauf]+    S_[iLauf+2];  //ni
	}
	
	// Punktwahrscheinlichkeit P0 

	for(kLauf=0; kLauf< zn; kLauf+=4)
	{
						       fact = N_[kLauf];
		for(jLauf = 0; jLauf < fact; jLauf++) //ni - faktoriellzerlegung
		{
			for(fLauf =   (S_[1+kLauf])-jLauf; fLauf >= 2; fLauf -= fact)	Z1_ *= fLauf;
			for(fLauf =   (S_[2+kLauf])-jLauf; fLauf >= 2; fLauf -= fact)	Z2_ *= fLauf;
			for(fLauf =   (S_[3+kLauf])-jLauf; fLauf >= 2; fLauf -= fact)	Z3_ *= fLauf;
			for(fLauf =   (S_[4+kLauf])-jLauf; fLauf >= 2; fLauf -= fact)	Z4_ *= fLauf;
			
			for(fLauf =   (N_[kLauf])    -jLauf; fLauf >= 2; fLauf -= fact)	N1_ *= fLauf;
			for(fLauf =   (wert[1+kLauf])-jLauf; fLauf >= 2; fLauf -= fact)	N2_ *= fLauf;
			for(fLauf =   (wert[3+kLauf])-jLauf; fLauf >= 2; fLauf -= fact)	N3_ *= fLauf;
			for(fLauf =   (wert[2+kLauf])-jLauf; fLauf >= 2; fLauf -= fact)	N4_ *= fLauf;
			for(fLauf =   (wert[4+kLauf])-jLauf; fLauf >= 2; fLauf -= fact)	N5_ *= fLauf;

					   Z_= Z1_/(N1_*N2_);
					   Z_=Z_*Z2_/N3_;
					   Z_=Z_*Z3_/N4_;
					   Z_=Z_*Z4_/N5_;		  
				   x_= Z_;
			P0_ *= x_;
			
			Z1_= Z2_= Z3_= Z4_ = 1;
			N1_= N2_= N3_= N4_= N5_= 1;
		}
	
		fn_erg*=P0_;
		        P0_=1;
	}

	return fn_erg;
};

double fn_2kfx(double wert[100], int zn) // x2-wert zu 2^k- Feldern bei 2x2 Fixierung  // XHF z11,...,z2hk //
{
	int iLauf, jLauf;
	long double S_[100], N_[100], n_=0,k_, x_, x2_=0;

	k_= (1/log(2))*log(zn); //ordnung k  (max zn=64, max k=6)
	
	if (k_ < 2 || k_ != floor(k_)) {printf("\n\ndesign.0 '2^k= %i, k= %.2f'",  zn, k_); exit(0);}// k >1, ganzzahlig

	for(jLauf=1; jLauf<= zn; jLauf++)  n_+=wert[jLauf];// n
	for(iLauf=1; iLauf<= 2*k_; iLauf++) S_[iLauf]=0;//S_ =0

	for(iLauf=1; iLauf<= zn; iLauf+=4) // 2x2 Randsummen
	{
		S_[iLauf]=   wert[iLauf]  +wert[iLauf+1]; //Zi1
		S_[iLauf+1]= wert[iLauf]  +wert[iLauf+2]; //Si1
		S_[iLauf+2]= wert[iLauf+2]+wert[iLauf+3]; //Zi2
		S_[iLauf+3]= wert[iLauf+1]+wert[iLauf+3]; //Si2
		N_[iLauf-1]=     S_[iLauf]+    S_[iLauf+2];  //ni
	}

	//printf("\n\n");
	//for(iLauf=0; iLauf< zn; iLauf+=4)printf("N%i= %.0f\n", iLauf, N_[iLauf]);

	for(iLauf=0; iLauf< zn; iLauf+=4) // x2-wert
	{
			 x_= (wert[1+iLauf]+wert[2+iLauf]+wert[3+iLauf]+wert[4+iLauf]) * pow(wert[1+iLauf]*wert[4+iLauf] - wert[2+iLauf]*wert[3+iLauf],2);
			 x_= x_ /(S_[1+iLauf]*S_[2+iLauf]*S_[3+iLauf]*S_[4+iLauf]);
		x2_+=x_;
	}

	fn_erg=x2_;

	return 0;
};

double fn_2kfc(double wert[100], int zn) // Kombinationen C zu 2^k - Feldern bei 2x2 Fixierung  // CHF z11,...,z2hk //												                                      
{
	int iLauf, i_=1;
	double  S_[100], k_, vektor[100], minf, C=1;

	k_= (1/log(2))*log(zn); //ordnung k  (max zn=64, max k=6)
	
	if (k_ < 2 || k_ != floor(k_)) {printf("\n\ndesign.0 '2^k= %i, k= %.2f'",  zn, k_); exit(0);}// k >1, ganzzahlig

	for(iLauf=1; iLauf<= 2*k_; iLauf++) S_[iLauf]=0;//S_ =0
	
	for(iLauf=1; iLauf<= zn; iLauf+=4) // 2x2 Randsummen
	{
		S_[iLauf]=   wert[iLauf]  +wert[iLauf+1]; //Zi1
		S_[iLauf+1]= wert[iLauf]  +wert[iLauf+2]; //Si1
		S_[iLauf+2]= wert[iLauf+2]+wert[iLauf+3]; //Zi2
		S_[iLauf+3]= wert[iLauf+1]+wert[iLauf+3]; //Si2
	}
	
	for(iLauf=1; iLauf<= zn; iLauf+=4) // kombinationen C
	{
					  vektor[1]=wert[iLauf];
					  vektor[2]=wert[iLauf+3];
		minf= fn_sort(vektor,2,1);	

		if(wert[iLauf+1] <= wert[iLauf+2])  C*= (S_[iLauf] -   (wert[iLauf] -minf))+1 ; //b=<c
		if(wert[iLauf+1] >  wert[iLauf+2])  C*= (S_[iLauf+1] - (wert[iLauf] -minf))+1 ; //b >c
	}

	fn_erg=C;	
	
	return fn_erg;
};

long double fn_2kf2(double wert[100], int zn, int sw) // hypergeometrische Wahrscheinlichkeit, 2-seitiges sig.- Niveau pexact2 zu 2^k - Feldern bei 2x2 Fixierung  // (0) HF2 z11,...,z2hk //												                                      
//                                                    // hypergeometrische Wahrscheinlichkeit, 1-seitiges sig.- Niveau pexact1 zu 2x2-Feldern (Fisher Exact Test)  // (1) FX1 a,b,c,d //
//                                                    // hypergeometrische Wahrscheinlichkeit, 2-seitiges sig.- Niveau pexact2 zu 2x2-Feldern (Fisher Exact Test)  // (0) FX2 a,b,c,d //
{
	//FILE *out;
	
	int iLauf, jLauf, zlr=0, i_=1;
	double  z_[100], N_[50], S_[100], n_=0,k_, min[50], vektor[100], C=1;
	double  P0, P_1,  p=0, pw=0, p11=0, p12=0, PP=0, p1;

	k_= (1/log(2))*log(zn); //ordnung k  (max zn=64, max k=6)
	
	if (k_ < 2 || k_ != floor(k_)) {printf("\n\ndesign.0 '2^k= %i, k= %.2f'",  zn, k_); exit(0);}// k >1, ganzzahlig
	if (zn > 64) {printf("\n\nbad design 'zmax = 64'",  zn, k_); exit(0);}// max 2^6


	for(jLauf=1; jLauf<= zn; jLauf++)  z_[jLauf]=wert[jLauf];// z_
	for(jLauf=1; jLauf<= zn; jLauf++)  n_+=wert[jLauf];// n
	for(iLauf=1; iLauf<= 2*k_; iLauf++) S_[iLauf]=0;//S_ =0
	
	for(iLauf=1; iLauf<= zn; iLauf+=4) // 2x2 Randsummen
	{
		S_[iLauf]=   wert[iLauf]  +wert[iLauf+1]; //Zi1
		S_[iLauf+1]= wert[iLauf]  +wert[iLauf+2]; //Si1
		S_[iLauf+2]= wert[iLauf+2]+wert[iLauf+3]; //Zi2
		S_[iLauf+3]= wert[iLauf+1]+wert[iLauf+3]; //Si2
		N_[i_]=     S_[iLauf]+    S_[iLauf+2];  //ni
		i_++;
	}
	
	C= fn_2kfc(wert,zn);

	if(C>1E+009) {printf("\n\ndesign.0 'C > 1,000,000,000'\n");exit(0);}
	
			
	P0=fn_2kf0( z_, zn); // P0

	i_=1;
	for(iLauf=0; iLauf< zn; iLauf+=4) 	// minimalwert
	{
						 vektor[1]=z_[1+iLauf];
						 vektor[2]=z_[4+iLauf];
		min[i_]= fn_sort(vektor,2,1);
		    i_++;
	}

	i_=1;
	for(iLauf=0; iLauf< zn; iLauf+=4) 	// zellenfreqeunz
	{
		z_[1+iLauf] = z_[1+iLauf]-min[i_];
		z_[2+iLauf] = S_[1+iLauf]-z_[1+iLauf];
		z_[3+iLauf] = S_[2+iLauf]-z_[1+iLauf];
		z_[4+iLauf] = N_[i_]-z_[1+iLauf]-z_[2+iLauf]-z_[3+iLauf];
	
		i_++;
	}	

	if(k_>2) printf("\n\n");
	if(k_>2) printf("C=%.0f, computing Pi ...", C);	 	

	//out=fopen( "fx.txt", "w" );

	// Exakt hypergeometrische Wahrscheinlichkeits-Verteilung bei 2x2 Randsummen Fixierung    
	// 2^2 bis 2^6 in geschwindigkeits-maximierender explizitcodierung -> schleifenminimierung //
	// 2^7 ... begrenzt durch felddimensionierung 

	//-------------------------------------------------------------------------------------------- Fisher Exact Test - 2^2 //
	if(k_==2) 
	{
		while( 1 )
		{
				P_1=fn_2kf0(z_, zn); // Pi
			//pw+=P_1;
			zlr++;//
			
			// pexact 2
			if (P_1 <= P0) p+=P_1; 
			
			// pexact 1
			if (P_1 == P0) PP=1;
			            if(PP==0 && P_1<= P0) p11+=P_1;  
			            if(PP==1 && P_1<= P0) p12+=P_1;

			z_[1]++;
			z_[2] = S_[1]-z_[1];
			z_[3] = S_[2]-z_[1];
			z_[4] = N_[1]-z_[1]-z_[2]-z_[3];
			
			if(z_[2]<0 || z_[3]<0 || z_[4]<0) break;
		}
		             p1=p11+P0;
		   if(p12<p1)p1=p12;
		if (sw==1) p=p1;
	}

	//---------------------------------------------------------------------------------------------------------------- 2^3 //
	if(k_==3)
	{
		while( 1 )
		{
			while( 1 )
			{
				//printf("%.0f %.0f  %.0f %.0f\n",  z_[1], z_[2], z_[5],z_[6]);
				//printf("%.0f %.0f  %.0f %.0f\n", z_[3], z_[4], z_[7], z_[8]);
		
					P_1=fn_2kf0(z_, zn); // Pi
				pw+=P_1;
				
				if (P_1 <= P0) p+=P_1;

				//printf("%f %f %f %f\n",P_1, P_2, P_1*P_2, p1_);
				
				//printf("\r%.14f",pw );//zlr++;
				//fprintf(out, "%.16f\n",P_1*P_2);

			//	fprintf(out, "ZHG %.0f, %.0f, %.0f, %.0f,%.0f, %.0f, %.0f, %.0f\n",z_[1], z_[2], z_[3], z_[4],z_[5],z_[6],  z_[7], z_[8]);

				z_[5]++;
				z_[6] = S_[5]-z_[5];
				z_[7] = S_[6]-z_[5];
				z_[8] = N_[2]-z_[5]-z_[6]-z_[7];
				
				if(z_[6]<0 || z_[7]<0 || z_[8]<0) break;
			}
			
			z_[1]++;
			z_[2] = S_[1]-z_[1];
			z_[3] = S_[2]-z_[1];
			z_[4] = N_[1]-z_[1]-z_[2]-z_[3];

			if(z_[2]<0 || z_[3]<0 || z_[4]<0) break;

			z_[5]= wert[5];z_[6]= wert[6];    
			z_[7]= wert[7];z_[8]= wert[8];

			z_[5]=  z_[5]-min[2];
			z_[6] = S_[5]-z_[5];
			z_[7] = S_[6]-z_[5];
			z_[8] = N_[2]-z_[5]-z_[6]-z_[7];
		}
	}

	//---------------------------------------------------------------------------------------------------------------- 2^4 //
	if(k_==4)
	{
		while( 1 )
		{
			while( 1 )
			{
				while( 1 )
				{
					while( 1 )
					{
					
						    P_1=fn_2kf0(z_, zn); // Pi
					  //pw+=P_1;
						if (P_1 <= P0) p+=P_1;

						//printf("\r%.14f",pw );//zlr++;
						//fprintf(out, "%.16f\n",P_1);

						z_[13]++;
						z_[14] = S_[13]-z_[13];
						z_[15] = S_[14]-z_[13];
						z_[16] = N_[4]-z_[13]-z_[14]-z_[15];
						
						if(z_[14]<0 || z_[15]<0 || z_[16]<0) break;
					}
				
					z_[9]++;
					z_[10] = S_[9]-z_[9];
					z_[11] = S_[10]-z_[9];
					z_[12] = N_[3]-z_[9]-z_[10]-z_[11];

					if(z_[10]<0 || z_[11]<0 || z_[12]<0) break;

					z_[13]= wert[13];z_[14]= wert[14];    
					z_[15]= wert[15];z_[16]= wert[16];

					z_[13]=  z_[13]-min[4];
					z_[14] = S_[13]-z_[13];
					z_[15] = S_[14]-z_[13];
					z_[16] = N_[4]-z_[13]-z_[14]-z_[15];
						
				}
			
				z_[5]++;
				z_[6] = S_[5]-z_[5];
				z_[7] = S_[6]-z_[5];
				z_[8] = N_[2]-z_[5]-z_[6]-z_[7];

				if(z_[6]<0 || z_[7]<0 || z_[8]<0) break;

				z_[9]= wert[9];z_[10]= wert[10];    
				z_[11]= wert[11];z_[12]= wert[12];
				z_[13]= wert[13];z_[14]= wert[14];    
				z_[15]= wert[15];z_[16]= wert[16];

				z_[9]=  z_[9]-min[3];
				z_[10] = S_[9]-z_[9];
				z_[11] = S_[10]-z_[9];
				z_[12] = N_[3]-z_[9]-z_[10]-z_[11];

				z_[13]=  z_[13]-min[4];
				z_[14] = S_[13]-z_[13];
				z_[15] = S_[14]-z_[13];
				z_[16] = N_[4]-z_[13]-z_[14]-z_[15];

			}
			
			z_[1]++;
			z_[2] = S_[1]-z_[1];
			z_[3] = S_[2]-z_[1];
			z_[4] = N_[1]-z_[1]-z_[2]-z_[3];

			if(z_[2]<0 || z_[3]<0 || z_[4]<0) break;

			z_[5]= wert[5];z_[6]= wert[6];    
			z_[7]= wert[7];z_[8]= wert[8];
			z_[9]= wert[9];z_[10]= wert[10];    
			z_[11]= wert[11];z_[12]= wert[12];
			z_[13]= wert[13];z_[14]= wert[14];    
			z_[15]= wert[15];z_[16]= wert[16];

			z_[5]=  z_[5]-min[2];
			z_[6] = S_[5]-z_[5];
			z_[7] = S_[6]-z_[5];
			z_[8] = N_[2]-z_[5]-z_[6]-z_[7];

			z_[9]=  z_[9]-min[3];
			z_[10] = S_[9]-z_[9];
			z_[11] = S_[10]-z_[9];
			z_[12] = N_[3]-z_[9]-z_[10]-z_[11];

			z_[13]=  z_[13]-min[4];
			z_[14] = S_[13]-z_[13];
			z_[15] = S_[14]-z_[13];
			z_[16] = N_[4]-z_[13]-z_[14]-z_[15];
		}
	}

	//---------------------------------------------------------------------------------------------------------------- 2^5 //
	if(k_==5)
	{
		while( 1 )
		{
			while( 1 )
			{
				while( 1 )
				{
					while( 1 )
					{
						while( 1 )
						{
							while( 1 )
							{
								while( 1 )
								{
									while( 1 )
									{
									
										    P_1=fn_2kf0(z_, zn); // Pi
									  //pw+=P_1;//
										if (P_1 <= P0) p+=P_1;

										//printf("\r%.14f",pw );//zlr++;
										//fprintf(out, "%.16f\n",P_1);

										z_[29]++;
										z_[30] = S_[29]-z_[29];
										z_[31] = S_[30]-z_[29];
										z_[32] = N_[8]-z_[29]-z_[30]-z_[31];
										
										if(z_[30]<0 || z_[31]<0 || z_[32]<0) break;
									}
										

									z_[25]++;
									z_[26] = S_[25]-z_[25];
									z_[27] = S_[26]-z_[25];
									z_[28] = N_[7]-z_[25]-z_[26]-z_[27];

									if(z_[26]<0 || z_[27]<0 || z_[28]<0) break;

									z_[29]= wert[29];z_[30]= wert[30];    
									z_[31]= wert[31];z_[32]= wert[32];

									z_[29]=  z_[29]-min[8];
									z_[30] = S_[29]-z_[29];
									z_[31] = S_[30]-z_[29];
									z_[32] = N_[8]-z_[29]-z_[30]-z_[31];
										
								}


								z_[21]++;
								z_[22] = S_[21]-z_[21];
								z_[23] = S_[22]-z_[21];
								z_[24] = N_[6]-z_[21]-z_[22]-z_[23];

								if(z_[22]<0 || z_[23]<0 || z_[24]<0) break;

								
								z_[25]= wert[25];z_[26]= wert[26];    
								z_[27]= wert[27];z_[28]= wert[28];
								z_[29]= wert[29];z_[30]= wert[30];    
								z_[31]= wert[31];z_[32]= wert[32];

								z_[25]=  z_[25]-min[7];
								z_[26] = S_[25]-z_[25];
								z_[27] = S_[26]-z_[25];
								z_[28] = N_[7]-z_[25]-z_[26]-z_[27];

								z_[29]=  z_[29]-min[8];
								z_[30] = S_[29]-z_[29];
								z_[31] = S_[30]-z_[29];
								z_[32] = N_[8]-z_[29]-z_[30]-z_[31];
									
							}

							z_[17]++;
							z_[18] = S_[17]-z_[17];
							z_[19] = S_[18]-z_[17];
							z_[20] = N_[5]-z_[17]-z_[18]-z_[19];

							if(z_[18]<0 || z_[19]<0 || z_[20]<0) break;

							
							z_[21]= wert[21];z_[22]= wert[22];    
							z_[23]= wert[23];z_[24]= wert[24];
							z_[25]= wert[25];z_[26]= wert[26];    
							z_[27]= wert[27];z_[28]= wert[28];
							z_[29]= wert[29];z_[30]= wert[30];    
							z_[31]= wert[31];z_[32]= wert[32];

							z_[21]=  z_[21]-min[6];
							z_[22] = S_[21]-z_[21];
							z_[23] = S_[22]-z_[21];
							z_[24] = N_[6]-z_[21]-z_[22]-z_[23];

							z_[25]=  z_[25]-min[7];
							z_[26] = S_[25]-z_[25];
							z_[27] = S_[26]-z_[25];
							z_[28] = N_[7]-z_[25]-z_[26]-z_[27];

							z_[29]=  z_[29]-min[8];
							z_[30] = S_[29]-z_[29];
							z_[31] = S_[30]-z_[29];
							z_[32] = N_[8]-z_[29]-z_[30]-z_[31];
								
						}

						z_[13]++;
						z_[14] = S_[13]-z_[13];
						z_[15] = S_[14]-z_[13];
						z_[16] = N_[4]-z_[13]-z_[14]-z_[15];

						if(z_[14]<0 || z_[15]<0 || z_[16]<0) break;

						z_[17]= wert[17];z_[18]= wert[18];   
						z_[19]= wert[19];z_[20]= wert[20];
						z_[21]= wert[21];z_[22]= wert[22];    
						z_[23]= wert[23];z_[24]= wert[24];
						z_[25]= wert[25];z_[26]= wert[26];    
						z_[27]= wert[27];z_[28]= wert[28];
						z_[29]= wert[29];z_[30]= wert[30];    
						z_[31]= wert[31];z_[32]= wert[32];

						z_[17]=  z_[17]-min[5];
						z_[18] = S_[17]-z_[17];
						z_[19] = S_[18]-z_[17];
						z_[20] = N_[5]-z_[17]-z_[18]-z_[19];

						z_[21]=  z_[21]-min[6];
						z_[22] = S_[21]-z_[21];
						z_[23] = S_[22]-z_[21];
						z_[24] = N_[6]-z_[21]-z_[22]-z_[23];

						z_[25]=  z_[25]-min[7];
						z_[26] = S_[25]-z_[25];
						z_[27] = S_[26]-z_[25];
						z_[28] = N_[7]-z_[25]-z_[26]-z_[27];

						z_[29]=  z_[29]-min[8];
						z_[30] = S_[29]-z_[29];
						z_[31] = S_[30]-z_[29];
						z_[32] = N_[8]-z_[29]-z_[30]-z_[31];
							
					}

					z_[9]++;
					z_[10] = S_[9]-z_[9];
					z_[11] = S_[10]-z_[9];
					z_[12] = N_[3]-z_[9]-z_[10]-z_[11];

					if(z_[10]<0 || z_[11]<0 || z_[12]<0) break;

					z_[13]= wert[13];z_[14]= wert[14];    
					z_[15]= wert[15];z_[16]= wert[16];
					z_[17]= wert[17];z_[18]= wert[18];   
					z_[19]= wert[19];z_[20]= wert[20];
					z_[21]= wert[21];z_[22]= wert[22];    
					z_[23]= wert[23];z_[24]= wert[24];
					z_[25]= wert[25];z_[26]= wert[26];    
					z_[27]= wert[27];z_[28]= wert[28];
					z_[29]= wert[29];z_[30]= wert[30];    
					z_[31]= wert[31];z_[32]= wert[32];

					z_[13]=  z_[13]-min[4];
					z_[14] = S_[13]-z_[13];
					z_[15] = S_[14]-z_[13];
					z_[16] = N_[4]-z_[13]-z_[14]-z_[15];

					z_[17]=  z_[17]-min[5];
					z_[18] = S_[17]-z_[17];
					z_[19] = S_[18]-z_[17];
					z_[20] = N_[5]-z_[17]-z_[18]-z_[19];

					z_[21]=  z_[21]-min[6];
					z_[22] = S_[21]-z_[21];
					z_[23] = S_[22]-z_[21];
					z_[24] = N_[6]-z_[21]-z_[22]-z_[23];

					z_[25]=  z_[25]-min[7];
					z_[26] = S_[25]-z_[25];
					z_[27] = S_[26]-z_[25];
					z_[28] = N_[7]-z_[25]-z_[26]-z_[27];

					z_[29]=  z_[29]-min[8];
					z_[30] = S_[29]-z_[29];
					z_[31] = S_[30]-z_[29];
					z_[32] = N_[8]-z_[29]-z_[30]-z_[31];
						
				}
			
				z_[5]++;
				z_[6] = S_[5]-z_[5];
				z_[7] = S_[6]-z_[5];
				z_[8] = N_[2]-z_[5]-z_[6]-z_[7];

				if(z_[6]<0 || z_[7]<0 || z_[8]<0) break;

				z_[9]= wert[9];z_[10]= wert[10];    
				z_[11]= wert[11];z_[12]= wert[12];
				z_[13]= wert[13];z_[14]= wert[14];    
				z_[15]= wert[15];z_[16]= wert[16];
				z_[17]= wert[17];z_[18]= wert[18];    
				z_[19]= wert[19];z_[20]= wert[20];
				z_[21]= wert[21];z_[22]= wert[22];    
				z_[23]= wert[23];z_[24]= wert[24];
				z_[25]= wert[25];z_[26]= wert[26];    
				z_[27]= wert[27];z_[28]= wert[28];
				z_[29]= wert[29];z_[30]= wert[30];    
				z_[31]= wert[31];z_[32]= wert[32];

				z_[9]=  z_[9]-min[3];
				z_[10] = S_[9]-z_[9];
				z_[11] = S_[10]-z_[9];
				z_[12] = N_[3]-z_[9]-z_[10]-z_[11];

				z_[13]=  z_[13]-min[4];
				z_[14] = S_[13]-z_[13];
				z_[15] = S_[14]-z_[13];
				z_[16] = N_[4]-z_[13]-z_[14]-z_[15];
				
				z_[17]=  z_[17]-min[5];
				z_[18] = S_[17]-z_[17];
				z_[19] = S_[18]-z_[17];
				z_[20] = N_[5]-z_[17]-z_[18]-z_[19];

				z_[21]=  z_[21]-min[6];
				z_[22] = S_[21]-z_[21];
				z_[23] = S_[22]-z_[21];
				z_[24] = N_[6]-z_[21]-z_[22]-z_[23];

				z_[25]=  z_[25]-min[7];
				z_[26] = S_[25]-z_[25];
				z_[27] = S_[26]-z_[25];
				z_[28] = N_[7]-z_[25]-z_[26]-z_[27];

				z_[29]=  z_[29]-min[8];
				z_[30] = S_[29]-z_[29];
				z_[31] = S_[30]-z_[29];
				z_[32] = N_[8]-z_[29]-z_[30]-z_[31];
			}
			
			z_[1]++;
			z_[2] = S_[1]-z_[1];
			z_[3] = S_[2]-z_[1];
			z_[4] = N_[1]-z_[1]-z_[2]-z_[3];

			if(z_[2]<0 || z_[3]<0 || z_[4]<0) break;

			z_[5]= wert[5];z_[6]= wert[6];    
			z_[7]= wert[7];z_[8]= wert[8];
			z_[9]= wert[9];z_[10]= wert[10];    
			z_[11]= wert[11];z_[12]= wert[12];
			z_[13]= wert[13];z_[14]= wert[14];    
			z_[15]= wert[15];z_[16]= wert[16];
			
			z_[17]= wert[17];z_[18]= wert[18];    
			z_[19]= wert[19];z_[20]= wert[20];
			z_[21]= wert[21];z_[22]= wert[22];    
			z_[23]= wert[23];z_[24]= wert[24];
			z_[25]= wert[25];z_[26]= wert[26];    
			z_[27]= wert[27];z_[28]= wert[28];
			z_[29]= wert[29];z_[30]= wert[30];    
			z_[31]= wert[31];z_[32]= wert[32];

			z_[5]=  z_[5]-min[2];
			z_[6] = S_[5]-z_[5];
			z_[7] = S_[6]-z_[5];
			z_[8] = N_[2]-z_[5]-z_[6]-z_[7];

			z_[9]=  z_[9]-min[3];
			z_[10] = S_[9]-z_[9];
			z_[11] = S_[10]-z_[9];
			z_[12] = N_[3]-z_[9]-z_[10]-z_[11];

			z_[13]=  z_[13]-min[4];
			z_[14] = S_[13]-z_[13];
			z_[15] = S_[14]-z_[13];
			z_[16] = N_[4]-z_[13]-z_[14]-z_[15];

			z_[17]=  z_[17]-min[5];
			z_[18] = S_[17]-z_[17];
			z_[19] = S_[18]-z_[17];
			z_[20] = N_[5]-z_[17]-z_[18]-z_[19];

			z_[21]=  z_[21]-min[6];
			z_[22] = S_[21]-z_[21];
			z_[23] = S_[22]-z_[21];
			z_[24] = N_[6]-z_[21]-z_[22]-z_[23];

			z_[25]=  z_[25]-min[7];
			z_[26] = S_[25]-z_[25];
			z_[27] = S_[26]-z_[25];
			z_[28] = N_[7]-z_[25]-z_[26]-z_[27];

			z_[29]=  z_[29]-min[8];
			z_[30] = S_[29]-z_[29];
			z_[31] = S_[30]-z_[29];
			z_[32] = N_[8]-z_[29]-z_[30]-z_[31];

		}
	}

	//---------------------------------------------------------------------------------------------------------------- 2^6 //
	if(k_==6)
	{
		while( 1 )
		{
			while( 1 )
			{
				while( 1 )
				{
					while( 1 )
					{
						while( 1 )
						{
							while( 1 )
							{
								while( 1 )
								{
									while( 1 )
									{
										while( 1 )
										{
											while( 1 )
											{
												while( 1 )
												{
													while( 1 )
													{
														while( 1 )
														{
															while( 1 )
															{
																while( 1 )
																{
																	while( 1 )
																	{
																	
																		P_1=fn_2kf0(z_, zn); // Pi
																	  pw+=P_1;//
																		if (P_1 <= P0) p+=P_1;

																		//printf("\r%.14f",pw );//zlr++;

																		z_[61]++;
																		z_[62] = S_[61]-z_[61];
																		z_[63] = S_[62]-z_[61];
																		z_[64] = N_[16]-z_[61]-z_[62]-z_[63];
																		
																		if(z_[62]<0 || z_[63]<0 || z_[64]<0) break;
																	}

																	z_[57]++;
																	z_[58] = S_[57]-z_[57];
																	z_[59] = S_[58]-z_[57];
																	z_[60] = N_[15]-z_[57]-z_[58]-z_[59];

																	if(z_[58]<0 || z_[59]<0 || z_[60]<0) break;
    
																	z_[61]= wert[61];z_[62]= wert[62];
																	z_[63]= wert[63];z_[64]= wert[64];

																	z_[61]=  z_[61]-min[16];
																	z_[62] = S_[61]-z_[61];
																	z_[63] = S_[62]-z_[61];
																	z_[64] = N_[16]-z_[61]-z_[62]-z_[63];
																		
																}
																z_[53]++;
																z_[54] = S_[53]-z_[53];
																z_[55] = S_[54]-z_[53];
																z_[56] = N_[14]-z_[53]-z_[54]-z_[55];

																if(z_[54]<0 || z_[55]<0 || z_[56]<0) break;
    
																z_[57]= wert[57];z_[58]= wert[58];
																z_[59]= wert[59];z_[60]= wert[60];    
																z_[61]= wert[61];z_[62]= wert[62];
																z_[63]= wert[63];z_[64]= wert[64];

																z_[57]=  z_[57]-min[15];
																z_[58] = S_[57]-z_[57];
																z_[59] = S_[58]-z_[57];
																z_[60] = N_[15]-z_[57]-z_[58]-z_[59];

																z_[61]=  z_[61]-min[16];
																z_[62] = S_[61]-z_[61];
																z_[63] = S_[62]-z_[61];
																z_[64] = N_[16]-z_[61]-z_[62]-z_[63];
																	
															}

															z_[49]++;
															z_[50] = S_[49]-z_[49];
															z_[51] = S_[50]-z_[49];
															z_[52] = N_[13]-z_[49]-z_[50]-z_[51];

															if(z_[50]<0 || z_[51]<0 || z_[52]<0) break;

															z_[53]= wert[53];z_[54]= wert[54];
															z_[55]= wert[55];z_[56]= wert[56];    
															z_[57]= wert[57];z_[58]= wert[58];
															z_[59]= wert[59];z_[60]= wert[60];    
															z_[61]= wert[61];z_[62]= wert[62];
															z_[63]= wert[63];z_[64]= wert[64];

															z_[53]=  z_[53]-min[14];
															z_[54] = S_[53]-z_[53];
															z_[55] = S_[54]-z_[53];
															z_[56] = N_[14]-z_[53]-z_[54]-z_[55];

															z_[57]=  z_[57]-min[15];
															z_[58] = S_[57]-z_[57];
															z_[59] = S_[58]-z_[57];
															z_[60] = N_[15]-z_[57]-z_[58]-z_[59];

															z_[61]=  z_[61]-min[16];
															z_[62] = S_[61]-z_[61];
															z_[63] = S_[62]-z_[61];
															z_[64] = N_[16]-z_[61]-z_[62]-z_[63];
																
														}

														z_[45]++;
														z_[46] = S_[45]-z_[45];
														z_[47] = S_[46]-z_[45];
														z_[48] = N_[12]-z_[45]-z_[46]-z_[47];

														if(z_[46]<0 || z_[47]<0 || z_[48]<0) break;

														z_[49]= wert[49];z_[50]= wert[50];
														z_[51]= wert[51];z_[52]= wert[52];    
														z_[53]= wert[53];z_[54]= wert[54];
														z_[55]= wert[55];z_[56]= wert[56];    
														z_[57]= wert[57];z_[58]= wert[58];
														z_[59]= wert[59];z_[60]= wert[60];    
														z_[61]= wert[61];z_[62]= wert[62];
														z_[63]= wert[63];z_[64]= wert[64]; 

														z_[49]=  z_[49]-min[13];
														z_[50] = S_[49]-z_[49];
														z_[51] = S_[50]-z_[49];
														z_[52] = N_[13]-z_[49]-z_[50]-z_[51];

														z_[53]=  z_[53]-min[14];
														z_[54] = S_[53]-z_[53];
														z_[55] = S_[54]-z_[53];
														z_[56] = N_[14]-z_[53]-z_[54]-z_[55];

														z_[57]=  z_[57]-min[15];
														z_[58] = S_[57]-z_[57];
														z_[59] = S_[58]-z_[57];
														z_[60] = N_[15]-z_[57]-z_[58]-z_[59];

														z_[61]=  z_[61]-min[16];
														z_[62] = S_[61]-z_[61];
														z_[63] = S_[62]-z_[61];
														z_[64] = N_[16]-z_[61]-z_[62]-z_[63];
															
													}

													z_[41]++;
													z_[42] = S_[41]-z_[41];
													z_[43] = S_[42]-z_[41];
													z_[44] = N_[11]-z_[41]-z_[42]-z_[43];

													if(z_[42]<0 || z_[43]<0 || z_[44]<0) break;

													z_[45]= wert[45];z_[46]= wert[46];
													z_[47]= wert[47];z_[48]= wert[48];    
													z_[49]= wert[49];z_[50]= wert[50];
													z_[51]= wert[51];z_[52]= wert[52];    
													z_[53]= wert[53];z_[54]= wert[54];
													z_[55]= wert[55];z_[56]= wert[56];    
													z_[57]= wert[57];z_[58]= wert[58];
													z_[59]= wert[59];z_[60]= wert[60];    
													z_[61]= wert[61];z_[62]= wert[62];
													z_[63]= wert[63];z_[64]= wert[64]; 


													z_[45]=  z_[45]-min[12];
													z_[46] = S_[45]-z_[45];
													z_[47] = S_[46]-z_[45];
													z_[48] = N_[12]-z_[45]-z_[46]-z_[47];

													z_[49]=  z_[49]-min[13];
													z_[50] = S_[49]-z_[49];
													z_[51] = S_[50]-z_[49];
													z_[52] = N_[13]-z_[49]-z_[50]-z_[51];

													z_[53]=  z_[53]-min[14];
													z_[54] = S_[53]-z_[53];
													z_[55] = S_[54]-z_[53];
													z_[56] = N_[14]-z_[53]-z_[54]-z_[55];

													z_[57]=  z_[57]-min[15];
													z_[58] = S_[57]-z_[57];
													z_[59] = S_[58]-z_[57];
													z_[60] = N_[15]-z_[57]-z_[58]-z_[59];

													z_[61]=  z_[61]-min[16];
													z_[62] = S_[61]-z_[61];
													z_[63] = S_[62]-z_[61];
													z_[64] = N_[16]-z_[61]-z_[62]-z_[63];
														
												}

												z_[37]++;
												z_[38] = S_[37]-z_[37];
												z_[39] = S_[38]-z_[37];
												z_[40] = N_[10]-z_[37]-z_[38]-z_[39];

												if(z_[38]<0 || z_[39]<0 || z_[40]<0) break;

												 
												z_[41]= wert[41];z_[42]= wert[42];
												z_[43]= wert[43];z_[44]= wert[44];    
												z_[45]= wert[45];z_[46]= wert[46];
												z_[47]= wert[47];z_[48]= wert[48];    
												z_[49]= wert[49];z_[50]= wert[50];
												z_[51]= wert[51];z_[52]= wert[52];    
												z_[53]= wert[53];z_[54]= wert[54];
												z_[55]= wert[55];z_[56]= wert[56];    
												z_[57]= wert[57];z_[58]= wert[58];
												z_[59]= wert[59];z_[60]= wert[60];    
												z_[61]= wert[61];z_[62]= wert[62];
												z_[63]= wert[63];z_[64]= wert[64]; 

												
												z_[41]=  z_[41]-min[11];
												z_[42] = S_[41]-z_[41];
												z_[43] = S_[42]-z_[41];
												z_[44] = N_[11]-z_[41]-z_[42]-z_[43];

												z_[45]=  z_[45]-min[12];
												z_[46] = S_[45]-z_[45];
												z_[47] = S_[46]-z_[45];
												z_[48] = N_[12]-z_[45]-z_[46]-z_[47];

												z_[49]=  z_[49]-min[13];
												z_[50] = S_[49]-z_[49];
												z_[51] = S_[50]-z_[49];
												z_[52] = N_[13]-z_[49]-z_[50]-z_[51];

												z_[53]=  z_[53]-min[14];
												z_[54] = S_[53]-z_[53];
												z_[55] = S_[54]-z_[53];
												z_[56] = N_[14]-z_[53]-z_[54]-z_[55];

												z_[57]=  z_[57]-min[15];
												z_[58] = S_[57]-z_[57];
												z_[59] = S_[58]-z_[57];
												z_[60] = N_[15]-z_[57]-z_[58]-z_[59];

												z_[61]=  z_[61]-min[16];
												z_[62] = S_[61]-z_[61];
												z_[63] = S_[62]-z_[61];
												z_[64] = N_[16]-z_[61]-z_[62]-z_[63];
													
											}
											z_[33]++;
											z_[34] = S_[33]-z_[33];
											z_[35] = S_[34]-z_[33];
											z_[36] = N_[9]-z_[33]-z_[34]-z_[35];

											if(z_[34]<0 || z_[35]<0 || z_[36]<0) break;

											 
											z_[37]= wert[37];z_[38]= wert[38];
											z_[39]= wert[39];z_[40]= wert[40];    
											z_[41]= wert[41];z_[42]= wert[42];
											z_[43]= wert[43];z_[44]= wert[44];    
											z_[45]= wert[45];z_[46]= wert[46];
											z_[47]= wert[47];z_[48]= wert[48];    
											z_[49]= wert[49];z_[50]= wert[50];
											z_[51]= wert[51];z_[52]= wert[52];    
											z_[53]= wert[53];z_[54]= wert[54];
											z_[55]= wert[55];z_[56]= wert[56];    
											z_[57]= wert[57];z_[58]= wert[58];
											z_[59]= wert[59];z_[60]= wert[60];    
											z_[61]= wert[61];z_[62]= wert[62];
											z_[63]= wert[63];z_[64]= wert[64]; 

											
											z_[37]=  z_[37]-min[10];
											z_[38] = S_[37]-z_[37];
											z_[39] = S_[38]-z_[37];
											z_[40] = N_[10]-z_[37]-z_[38]-z_[39];

											z_[41]=  z_[41]-min[11];
											z_[42] = S_[41]-z_[41];
											z_[43] = S_[42]-z_[41];
											z_[44] = N_[11]-z_[41]-z_[42]-z_[43];

											z_[45]=  z_[45]-min[12];
											z_[46] = S_[45]-z_[45];
											z_[47] = S_[46]-z_[45];
											z_[48] = N_[12]-z_[45]-z_[46]-z_[47];

											z_[49]=  z_[49]-min[13];
											z_[50] = S_[49]-z_[49];
											z_[51] = S_[50]-z_[49];
											z_[52] = N_[13]-z_[49]-z_[50]-z_[51];

											z_[53]=  z_[53]-min[14];
											z_[54] = S_[53]-z_[53];
											z_[55] = S_[54]-z_[53];
											z_[56] = N_[14]-z_[53]-z_[54]-z_[55];

											z_[57]=  z_[57]-min[15];
											z_[58] = S_[57]-z_[57];
											z_[59] = S_[58]-z_[57];
											z_[60] = N_[15]-z_[57]-z_[58]-z_[59];

											z_[61]=  z_[61]-min[16];
											z_[62] = S_[61]-z_[61];
											z_[63] = S_[62]-z_[61];
											z_[64] = N_[16]-z_[61]-z_[62]-z_[63];
												
										}

										z_[29]++;
										z_[30] = S_[29]-z_[29];
										z_[31] = S_[30]-z_[29];
										z_[32] = N_[8]-z_[29]-z_[30]-z_[31];

										if(z_[30]<0 || z_[31]<0 || z_[32]<0) break;

										
										z_[33]= wert[33];z_[34]= wert[34];
										z_[35]= wert[35];z_[36]= wert[36];    
										z_[37]= wert[37];z_[38]= wert[38];
										z_[39]= wert[39];z_[40]= wert[40];    
										z_[41]= wert[41];z_[42]= wert[42];
										z_[43]= wert[43];z_[44]= wert[44];    
										z_[45]= wert[45];z_[46]= wert[46];
										z_[47]= wert[47];z_[48]= wert[48];    
										z_[49]= wert[49];z_[50]= wert[50];
										z_[51]= wert[51];z_[52]= wert[52];    
										z_[53]= wert[53];z_[54]= wert[54];
										z_[55]= wert[55];z_[56]= wert[56];    
										z_[57]= wert[57];z_[58]= wert[58];
										z_[59]= wert[59];z_[60]= wert[60];    
										z_[61]= wert[61];z_[62]= wert[62];
										z_[63]= wert[63];z_[64]= wert[64]; 

										
										z_[33]=  z_[33]-min[9];
										z_[34] = S_[33]-z_[33];
										z_[35] = S_[34]-z_[33];
										z_[36] = N_[9]-z_[33]-z_[34]-z_[35];

										z_[37]=  z_[37]-min[10];
										z_[38] = S_[37]-z_[37];
										z_[39] = S_[38]-z_[37];
										z_[40] = N_[10]-z_[37]-z_[38]-z_[39];

										z_[41]=  z_[41]-min[11];
										z_[42] = S_[41]-z_[41];
										z_[43] = S_[42]-z_[41];
										z_[44] = N_[11]-z_[41]-z_[42]-z_[43];

										z_[45]=  z_[45]-min[12];
										z_[46] = S_[45]-z_[45];
										z_[47] = S_[46]-z_[45];
										z_[48] = N_[12]-z_[45]-z_[46]-z_[47];

										z_[49]=  z_[49]-min[13];
										z_[50] = S_[49]-z_[49];
										z_[51] = S_[50]-z_[49];
										z_[52] = N_[13]-z_[49]-z_[50]-z_[51];

										z_[53]=  z_[53]-min[14];
										z_[54] = S_[53]-z_[53];
										z_[55] = S_[54]-z_[53];
										z_[56] = N_[14]-z_[53]-z_[54]-z_[55];

										z_[57]=  z_[57]-min[15];
										z_[58] = S_[57]-z_[57];
										z_[59] = S_[58]-z_[57];
										z_[60] = N_[15]-z_[57]-z_[58]-z_[59];

										z_[61]=  z_[61]-min[16];
										z_[62] = S_[61]-z_[61];
										z_[63] = S_[62]-z_[61];
										z_[64] = N_[16]-z_[61]-z_[62]-z_[63];
											
									}


									z_[25]++;
									z_[26] = S_[25]-z_[25];
									z_[27] = S_[26]-z_[25];
									z_[28] = N_[7]-z_[25]-z_[26]-z_[27];

									if(z_[26]<0 || z_[27]<0 || z_[28]<0) break;

									z_[29]= wert[29];z_[30]= wert[30];    
									z_[31]= wert[31];z_[32]= wert[32];
									z_[33]= wert[33];z_[34]= wert[34];
									z_[35]= wert[35];z_[36]= wert[36];    
									z_[37]= wert[37];z_[38]= wert[38];
									z_[39]= wert[39];z_[40]= wert[40];    
									z_[41]= wert[41];z_[42]= wert[42];
									z_[43]= wert[43];z_[44]= wert[44];    
									z_[45]= wert[45];z_[46]= wert[46];
									z_[47]= wert[47];z_[48]= wert[48];    
									z_[49]= wert[49];z_[50]= wert[50];
									z_[51]= wert[51];z_[52]= wert[52];    
									z_[53]= wert[53];z_[54]= wert[54];
									z_[55]= wert[55];z_[56]= wert[56];    
									z_[57]= wert[57];z_[58]= wert[58];
									z_[59]= wert[59];z_[60]= wert[60];    
									z_[61]= wert[61];z_[62]= wert[62];
									z_[63]= wert[63];z_[64]= wert[64]; 

									z_[29]=  z_[29]-min[8];
									z_[30] = S_[29]-z_[29];
									z_[31] = S_[30]-z_[29];
									z_[32] = N_[8]-z_[29]-z_[30]-z_[31];

									z_[33]=  z_[33]-min[9];
									z_[34] = S_[33]-z_[33];
									z_[35] = S_[34]-z_[33];
									z_[36] = N_[9]-z_[33]-z_[34]-z_[35];

									z_[37]=  z_[37]-min[10];
									z_[38] = S_[37]-z_[37];
									z_[39] = S_[38]-z_[37];
									z_[40] = N_[10]-z_[37]-z_[38]-z_[39];

									z_[41]=  z_[41]-min[11];
									z_[42] = S_[41]-z_[41];
									z_[43] = S_[42]-z_[41];
									z_[44] = N_[11]-z_[41]-z_[42]-z_[43];

									z_[45]=  z_[45]-min[12];
									z_[46] = S_[45]-z_[45];
									z_[47] = S_[46]-z_[45];
									z_[48] = N_[12]-z_[45]-z_[46]-z_[47];

									z_[49]=  z_[49]-min[13];
									z_[50] = S_[49]-z_[49];
									z_[51] = S_[50]-z_[49];
									z_[52] = N_[13]-z_[49]-z_[50]-z_[51];

									z_[53]=  z_[53]-min[14];
									z_[54] = S_[53]-z_[53];
									z_[55] = S_[54]-z_[53];
									z_[56] = N_[14]-z_[53]-z_[54]-z_[55];

									z_[57]=  z_[57]-min[15];
									z_[58] = S_[57]-z_[57];
									z_[59] = S_[58]-z_[57];
									z_[60] = N_[15]-z_[57]-z_[58]-z_[59];

									z_[61]=  z_[61]-min[16];
									z_[62] = S_[61]-z_[61];
									z_[63] = S_[62]-z_[61];
									z_[64] = N_[16]-z_[61]-z_[62]-z_[63];
										
								}


								z_[21]++;
								z_[22] = S_[21]-z_[21];
								z_[23] = S_[22]-z_[21];
								z_[24] = N_[6]-z_[21]-z_[22]-z_[23];

								if(z_[22]<0 || z_[23]<0 || z_[24]<0) break;

								
								z_[25]= wert[25];z_[26]= wert[26];    
								z_[27]= wert[27];z_[28]= wert[28];
								z_[29]= wert[29];z_[30]= wert[30];    
								z_[31]= wert[31];z_[32]= wert[32];
								z_[33]= wert[33];z_[34]= wert[34];
								z_[35]= wert[35];z_[36]= wert[36];    
								z_[37]= wert[37];z_[38]= wert[38];
								z_[39]= wert[39];z_[40]= wert[40];    
								z_[41]= wert[41];z_[42]= wert[42];
								z_[43]= wert[43];z_[44]= wert[44];    
								z_[45]= wert[45];z_[46]= wert[46];
								z_[47]= wert[47];z_[48]= wert[48];    
								z_[49]= wert[49];z_[50]= wert[50];
								z_[51]= wert[51];z_[52]= wert[52];    
								z_[53]= wert[53];z_[54]= wert[54];
								z_[55]= wert[55];z_[56]= wert[56];    
								z_[57]= wert[57];z_[58]= wert[58];
								z_[59]= wert[59];z_[60]= wert[60];    
								z_[61]= wert[61];z_[62]= wert[62];
								z_[63]= wert[63];z_[64]= wert[64]; 

								z_[25]=  z_[25]-min[7];
								z_[26] = S_[25]-z_[25];
								z_[27] = S_[26]-z_[25];
								z_[28] = N_[7]-z_[25]-z_[26]-z_[27];

								z_[29]=  z_[29]-min[8];
								z_[30] = S_[29]-z_[29];
								z_[31] = S_[30]-z_[29];
								z_[32] = N_[8]-z_[29]-z_[30]-z_[31];

								z_[33]=  z_[33]-min[9];
								z_[34] = S_[33]-z_[33];
								z_[35] = S_[34]-z_[33];
								z_[36] = N_[9]-z_[33]-z_[34]-z_[35];

								z_[37]=  z_[37]-min[10];
								z_[38] = S_[37]-z_[37];
								z_[39] = S_[38]-z_[37];
								z_[40] = N_[10]-z_[37]-z_[38]-z_[39];

								z_[41]=  z_[41]-min[11];
								z_[42] = S_[41]-z_[41];
								z_[43] = S_[42]-z_[41];
								z_[44] = N_[11]-z_[41]-z_[42]-z_[43];

								z_[45]=  z_[45]-min[12];
								z_[46] = S_[45]-z_[45];
								z_[47] = S_[46]-z_[45];
								z_[48] = N_[12]-z_[45]-z_[46]-z_[47];

								z_[49]=  z_[49]-min[13];
								z_[50] = S_[49]-z_[49];
								z_[51] = S_[50]-z_[49];
								z_[52] = N_[13]-z_[49]-z_[50]-z_[51];

								z_[53]=  z_[53]-min[14];
								z_[54] = S_[53]-z_[53];
								z_[55] = S_[54]-z_[53];
								z_[56] = N_[14]-z_[53]-z_[54]-z_[55];

								z_[57]=  z_[57]-min[15];
								z_[58] = S_[57]-z_[57];
								z_[59] = S_[58]-z_[57];
								z_[60] = N_[15]-z_[57]-z_[58]-z_[59];

								z_[61]=  z_[61]-min[16];
								z_[62] = S_[61]-z_[61];
								z_[63] = S_[62]-z_[61];
								z_[64] = N_[16]-z_[61]-z_[62]-z_[63];
									
							}

							z_[17]++;
							z_[18] = S_[17]-z_[17];
							z_[19] = S_[18]-z_[17];
							z_[20] = N_[5]-z_[17]-z_[18]-z_[19];

							if(z_[18]<0 || z_[19]<0 || z_[20]<0) break;

							
							z_[21]= wert[21];z_[22]= wert[22];    
							z_[23]= wert[23];z_[24]= wert[24];
							z_[25]= wert[25];z_[26]= wert[26];    
							z_[27]= wert[27];z_[28]= wert[28];
							z_[29]= wert[29];z_[30]= wert[30];    
							z_[31]= wert[31];z_[32]= wert[32];
							z_[33]= wert[33];z_[34]= wert[34];
							z_[35]= wert[35];z_[36]= wert[36];    
							z_[37]= wert[37];z_[38]= wert[38];
							z_[39]= wert[39];z_[40]= wert[40];    
							z_[41]= wert[41];z_[42]= wert[42];
							z_[43]= wert[43];z_[44]= wert[44];    
							z_[45]= wert[45];z_[46]= wert[46];
							z_[47]= wert[47];z_[48]= wert[48];    
							z_[49]= wert[49];z_[50]= wert[50];
							z_[51]= wert[51];z_[52]= wert[52];    
							z_[53]= wert[53];z_[54]= wert[54];
							z_[55]= wert[55];z_[56]= wert[56];    
							z_[57]= wert[57];z_[58]= wert[58];
							z_[59]= wert[59];z_[60]= wert[60];    
							z_[61]= wert[61];z_[62]= wert[62];
							z_[63]= wert[63];z_[64]= wert[64]; 

							z_[21]=  z_[21]-min[6];
							z_[22] = S_[21]-z_[21];
							z_[23] = S_[22]-z_[21];
							z_[24] = N_[6]-z_[21]-z_[22]-z_[23];

							z_[25]=  z_[25]-min[7];
							z_[26] = S_[25]-z_[25];
							z_[27] = S_[26]-z_[25];
							z_[28] = N_[7]-z_[25]-z_[26]-z_[27];

							z_[29]=  z_[29]-min[8];
							z_[30] = S_[29]-z_[29];
							z_[31] = S_[30]-z_[29];
							z_[32] = N_[8]-z_[29]-z_[30]-z_[31];

							z_[33]=  z_[33]-min[9];
							z_[34] = S_[33]-z_[33];
							z_[35] = S_[34]-z_[33];
							z_[36] = N_[9]-z_[33]-z_[34]-z_[35];

							z_[37]=  z_[37]-min[10];
							z_[38] = S_[37]-z_[37];
							z_[39] = S_[38]-z_[37];
							z_[40] = N_[10]-z_[37]-z_[38]-z_[39];

							z_[41]=  z_[41]-min[11];
							z_[42] = S_[41]-z_[41];
							z_[43] = S_[42]-z_[41];
							z_[44] = N_[11]-z_[41]-z_[42]-z_[43];

							z_[45]=  z_[45]-min[12];
							z_[46] = S_[45]-z_[45];
							z_[47] = S_[46]-z_[45];
							z_[48] = N_[12]-z_[45]-z_[46]-z_[47];

							z_[49]=  z_[49]-min[13];
							z_[50] = S_[49]-z_[49];
							z_[51] = S_[50]-z_[49];
							z_[52] = N_[13]-z_[49]-z_[50]-z_[51];

							z_[53]=  z_[53]-min[14];
							z_[54] = S_[53]-z_[53];
							z_[55] = S_[54]-z_[53];
							z_[56] = N_[14]-z_[53]-z_[54]-z_[55];

							z_[57]=  z_[57]-min[15];
							z_[58] = S_[57]-z_[57];
							z_[59] = S_[58]-z_[57];
							z_[60] = N_[15]-z_[57]-z_[58]-z_[59];

							z_[61]=  z_[61]-min[16];
							z_[62] = S_[61]-z_[61];
							z_[63] = S_[62]-z_[61];
							z_[64] = N_[16]-z_[61]-z_[62]-z_[63];
								
						}

						z_[13]++;
						z_[14] = S_[13]-z_[13];
						z_[15] = S_[14]-z_[13];
						z_[16] = N_[4]-z_[13]-z_[14]-z_[15];

						if(z_[14]<0 || z_[15]<0 || z_[16]<0) break;

						z_[17]= wert[17];z_[18]= wert[18];   
						z_[19]= wert[19];z_[20]= wert[20];
						z_[21]= wert[21];z_[22]= wert[22];    
						z_[23]= wert[23];z_[24]= wert[24];
						z_[25]= wert[25];z_[26]= wert[26];    
						z_[27]= wert[27];z_[28]= wert[28];
						z_[29]= wert[29];z_[30]= wert[30];    
						z_[31]= wert[31];z_[32]= wert[32];
						z_[33]= wert[33];z_[34]= wert[34];
						z_[35]= wert[35];z_[36]= wert[36];    
						z_[37]= wert[37];z_[38]= wert[38];
						z_[39]= wert[39];z_[40]= wert[40];    
						z_[41]= wert[41];z_[42]= wert[42];
						z_[43]= wert[43];z_[44]= wert[44];    
						z_[45]= wert[45];z_[46]= wert[46];
						z_[47]= wert[47];z_[48]= wert[48];    
						z_[49]= wert[49];z_[50]= wert[50];
						z_[51]= wert[51];z_[52]= wert[52];    
						z_[53]= wert[53];z_[54]= wert[54];
						z_[55]= wert[55];z_[56]= wert[56];    
						z_[57]= wert[57];z_[58]= wert[58];
						z_[59]= wert[59];z_[60]= wert[60];    
						z_[61]= wert[61];z_[62]= wert[62];
						z_[63]= wert[63];z_[64]= wert[64]; 

						z_[17]=  z_[17]-min[5];
						z_[18] = S_[17]-z_[17];
						z_[19] = S_[18]-z_[17];
						z_[20] = N_[5]-z_[17]-z_[18]-z_[19];

						z_[21]=  z_[21]-min[6];
						z_[22] = S_[21]-z_[21];
						z_[23] = S_[22]-z_[21];
						z_[24] = N_[6]-z_[21]-z_[22]-z_[23];

						z_[25]=  z_[25]-min[7];
						z_[26] = S_[25]-z_[25];
						z_[27] = S_[26]-z_[25];
						z_[28] = N_[7]-z_[25]-z_[26]-z_[27];

						z_[29]=  z_[29]-min[8];
						z_[30] = S_[29]-z_[29];
						z_[31] = S_[30]-z_[29];
						z_[32] = N_[8]-z_[29]-z_[30]-z_[31];

						z_[33]=  z_[33]-min[9];
						z_[34] = S_[33]-z_[33];
						z_[35] = S_[34]-z_[33];
						z_[36] = N_[9]-z_[33]-z_[34]-z_[35];

						z_[37]=  z_[37]-min[10];
						z_[38] = S_[37]-z_[37];
						z_[39] = S_[38]-z_[37];
						z_[40] = N_[10]-z_[37]-z_[38]-z_[39];

						z_[41]=  z_[41]-min[11];
						z_[42] = S_[41]-z_[41];
						z_[43] = S_[42]-z_[41];
						z_[44] = N_[11]-z_[41]-z_[42]-z_[43];

						z_[45]=  z_[45]-min[12];
						z_[46] = S_[45]-z_[45];
						z_[47] = S_[46]-z_[45];
						z_[48] = N_[12]-z_[45]-z_[46]-z_[47];

						z_[49]=  z_[49]-min[13];
						z_[50] = S_[49]-z_[49];
						z_[51] = S_[50]-z_[49];
						z_[52] = N_[13]-z_[49]-z_[50]-z_[51];

						z_[53]=  z_[53]-min[14];
						z_[54] = S_[53]-z_[53];
						z_[55] = S_[54]-z_[53];
						z_[56] = N_[14]-z_[53]-z_[54]-z_[55];

						z_[57]=  z_[57]-min[15];
						z_[58] = S_[57]-z_[57];
						z_[59] = S_[58]-z_[57];
						z_[60] = N_[15]-z_[57]-z_[58]-z_[59];

						z_[61]=  z_[61]-min[16];
						z_[62] = S_[61]-z_[61];
						z_[63] = S_[62]-z_[61];
						z_[64] = N_[16]-z_[61]-z_[62]-z_[63];
							
					}

					z_[9]++;
					z_[10] = S_[9]-z_[9];
					z_[11] = S_[10]-z_[9];
					z_[12] = N_[3]-z_[9]-z_[10]-z_[11];

					if(z_[10]<0 || z_[11]<0 || z_[12]<0) break;

					z_[13]= wert[13];z_[14]= wert[14];    
					z_[15]= wert[15];z_[16]= wert[16];
					z_[17]= wert[17];z_[18]= wert[18];   
					z_[19]= wert[19];z_[20]= wert[20];
					z_[21]= wert[21];z_[22]= wert[22];    
					z_[23]= wert[23];z_[24]= wert[24];
					z_[25]= wert[25];z_[26]= wert[26];    
					z_[27]= wert[27];z_[28]= wert[28];
					z_[29]= wert[29];z_[30]= wert[30];    
					z_[31]= wert[31];z_[32]= wert[32];

					z_[33]= wert[33];z_[34]= wert[34];
					z_[35]= wert[35];z_[36]= wert[36];    
					z_[37]= wert[37];z_[38]= wert[38];
					z_[39]= wert[39];z_[40]= wert[40];    
					z_[41]= wert[41];z_[42]= wert[42];
					z_[43]= wert[43];z_[44]= wert[44];    
					z_[45]= wert[45];z_[46]= wert[46];
					z_[47]= wert[47];z_[48]= wert[48];    
					z_[49]= wert[49];z_[50]= wert[50];
					z_[51]= wert[51];z_[52]= wert[52];    
					z_[53]= wert[53];z_[54]= wert[54];
					z_[55]= wert[55];z_[56]= wert[56];    
					z_[57]= wert[57];z_[58]= wert[58];
					z_[59]= wert[59];z_[60]= wert[60];    
					z_[61]= wert[61];z_[62]= wert[62];
					z_[63]= wert[63];z_[64]= wert[64]; 

					z_[13]=  z_[13]-min[4];
					z_[14] = S_[13]-z_[13];
					z_[15] = S_[14]-z_[13];
					z_[16] = N_[4]-z_[13]-z_[14]-z_[15];

					z_[17]=  z_[17]-min[5];
					z_[18] = S_[17]-z_[17];
					z_[19] = S_[18]-z_[17];
					z_[20] = N_[5]-z_[17]-z_[18]-z_[19];

					z_[21]=  z_[21]-min[6];
					z_[22] = S_[21]-z_[21];
					z_[23] = S_[22]-z_[21];
					z_[24] = N_[6]-z_[21]-z_[22]-z_[23];

					z_[25]=  z_[25]-min[7];
					z_[26] = S_[25]-z_[25];
					z_[27] = S_[26]-z_[25];
					z_[28] = N_[7]-z_[25]-z_[26]-z_[27];

					z_[29]=  z_[29]-min[8];
					z_[30] = S_[29]-z_[29];
					z_[31] = S_[30]-z_[29];
					z_[32] = N_[8]-z_[29]-z_[30]-z_[31];

					z_[33]=  z_[33]-min[9];
					z_[34] = S_[33]-z_[33];
					z_[35] = S_[34]-z_[33];
					z_[36] = N_[9]-z_[33]-z_[34]-z_[35];

					z_[37]=  z_[37]-min[10];
					z_[38] = S_[37]-z_[37];
					z_[39] = S_[38]-z_[37];
					z_[40] = N_[10]-z_[37]-z_[38]-z_[39];

					z_[41]=  z_[41]-min[11];
					z_[42] = S_[41]-z_[41];
					z_[43] = S_[42]-z_[41];
					z_[44] = N_[11]-z_[41]-z_[42]-z_[43];

					z_[45]=  z_[45]-min[12];
					z_[46] = S_[45]-z_[45];
					z_[47] = S_[46]-z_[45];
					z_[48] = N_[12]-z_[45]-z_[46]-z_[47];

					z_[49]=  z_[49]-min[13];
					z_[50] = S_[49]-z_[49];
					z_[51] = S_[50]-z_[49];
					z_[52] = N_[13]-z_[49]-z_[50]-z_[51];

					z_[53]=  z_[53]-min[14];
					z_[54] = S_[53]-z_[53];
					z_[55] = S_[54]-z_[53];
					z_[56] = N_[14]-z_[53]-z_[54]-z_[55];

					z_[57]=  z_[57]-min[15];
					z_[58] = S_[57]-z_[57];
					z_[59] = S_[58]-z_[57];
					z_[60] = N_[15]-z_[57]-z_[58]-z_[59];

					z_[61]=  z_[61]-min[16];
					z_[62] = S_[61]-z_[61];
					z_[63] = S_[62]-z_[61];
					z_[64] = N_[16]-z_[61]-z_[62]-z_[63];
						
				}
			
				z_[5]++;
				z_[6] = S_[5]-z_[5];
				z_[7] = S_[6]-z_[5];
				z_[8] = N_[2]-z_[5]-z_[6]-z_[7];

				if(z_[6]<0 || z_[7]<0 || z_[8]<0) break;

				z_[9]= wert[9];z_[10]= wert[10];    
				z_[11]= wert[11];z_[12]= wert[12];
				z_[13]= wert[13];z_[14]= wert[14];    
				z_[15]= wert[15];z_[16]= wert[16];
				z_[17]= wert[17];z_[18]= wert[18];    
				z_[19]= wert[19];z_[20]= wert[20];
				z_[21]= wert[21];z_[22]= wert[22];    
				z_[23]= wert[23];z_[24]= wert[24];
				z_[25]= wert[25];z_[26]= wert[26];    
				z_[27]= wert[27];z_[28]= wert[28];
				z_[29]= wert[29];z_[30]= wert[30];    
				z_[31]= wert[31];z_[32]= wert[32];

				z_[33]= wert[33];z_[34]= wert[34];
				z_[35]= wert[35];z_[36]= wert[36];    
				z_[37]= wert[37];z_[38]= wert[38];
				z_[39]= wert[39];z_[40]= wert[40];    
				z_[41]= wert[41];z_[42]= wert[42];
				z_[43]= wert[43];z_[44]= wert[44];    
				z_[45]= wert[45];z_[46]= wert[46];
				z_[47]= wert[47];z_[48]= wert[48];    
				z_[49]= wert[49];z_[50]= wert[50];
				z_[51]= wert[51];z_[52]= wert[52];    
				z_[53]= wert[53];z_[54]= wert[54];
				z_[55]= wert[55];z_[56]= wert[56];    
				z_[57]= wert[57];z_[58]= wert[58];
				z_[59]= wert[59];z_[60]= wert[60];    
				z_[61]= wert[61];z_[62]= wert[62];
				z_[63]= wert[63];z_[64]= wert[64]; 

				z_[9]=  z_[9]-min[3];
				z_[10] = S_[9]-z_[9];
				z_[11] = S_[10]-z_[9];
				z_[12] = N_[3]-z_[9]-z_[10]-z_[11];

				z_[13]=  z_[13]-min[4];
				z_[14] = S_[13]-z_[13];
				z_[15] = S_[14]-z_[13];
				z_[16] = N_[4]-z_[13]-z_[14]-z_[15];
				
				z_[17]=  z_[17]-min[5];
				z_[18] = S_[17]-z_[17];
				z_[19] = S_[18]-z_[17];
				z_[20] = N_[5]-z_[17]-z_[18]-z_[19];

				z_[21]=  z_[21]-min[6];
				z_[22] = S_[21]-z_[21];
				z_[23] = S_[22]-z_[21];
				z_[24] = N_[6]-z_[21]-z_[22]-z_[23];

				z_[25]=  z_[25]-min[7];
				z_[26] = S_[25]-z_[25];
				z_[27] = S_[26]-z_[25];
				z_[28] = N_[7]-z_[25]-z_[26]-z_[27];

				z_[29]=  z_[29]-min[8];
				z_[30] = S_[29]-z_[29];
				z_[31] = S_[30]-z_[29];
				z_[32] = N_[8]-z_[29]-z_[30]-z_[31];

				z_[33]=  z_[33]-min[9];
				z_[34] = S_[33]-z_[33];
				z_[35] = S_[34]-z_[33];
				z_[36] = N_[9]-z_[33]-z_[34]-z_[35];

				z_[37]=  z_[37]-min[10];
				z_[38] = S_[37]-z_[37];
				z_[39] = S_[38]-z_[37];
				z_[40] = N_[10]-z_[37]-z_[38]-z_[39];

				z_[41]=  z_[41]-min[11];
				z_[42] = S_[41]-z_[41];
				z_[43] = S_[42]-z_[41];
				z_[44] = N_[11]-z_[41]-z_[42]-z_[43];

				z_[45]=  z_[45]-min[12];
				z_[46] = S_[45]-z_[45];
				z_[47] = S_[46]-z_[45];
				z_[48] = N_[12]-z_[45]-z_[46]-z_[47];

				z_[49]=  z_[49]-min[13];
				z_[50] = S_[49]-z_[49];
				z_[51] = S_[50]-z_[49];
				z_[52] = N_[13]-z_[49]-z_[50]-z_[51];

				z_[53]=  z_[53]-min[14];
				z_[54] = S_[53]-z_[53];
				z_[55] = S_[54]-z_[53];
				z_[56] = N_[14]-z_[53]-z_[54]-z_[55];

				z_[57]=  z_[57]-min[15];
				z_[58] = S_[57]-z_[57];
				z_[59] = S_[58]-z_[57];
				z_[60] = N_[15]-z_[57]-z_[58]-z_[59];

				z_[61]=  z_[61]-min[16];
				z_[62] = S_[61]-z_[61];
				z_[63] = S_[62]-z_[61];
				z_[64] = N_[16]-z_[61]-z_[62]-z_[63];
			}
			
			z_[1]++;
			z_[2] = S_[1]-z_[1];
			z_[3] = S_[2]-z_[1];
			z_[4] = N_[1]-z_[1]-z_[2]-z_[3];

			if(z_[2]<0 || z_[3]<0 || z_[4]<0) break;

			z_[5]= wert[5];z_[6]= wert[6];    
			z_[7]= wert[7];z_[8]= wert[8];
			z_[9]= wert[9];z_[10]= wert[10];    
			z_[11]= wert[11];z_[12]= wert[12];
			z_[13]= wert[13];z_[14]= wert[14];    
			z_[15]= wert[15];z_[16]= wert[16];
			z_[17]= wert[17];z_[18]= wert[18];    
			z_[19]= wert[19];z_[20]= wert[20];
			z_[21]= wert[21];z_[22]= wert[22];    
			z_[23]= wert[23];z_[24]= wert[24];
			z_[25]= wert[25];z_[26]= wert[26];    
			z_[27]= wert[27];z_[28]= wert[28];
			z_[29]= wert[29];z_[30]= wert[30];    
			z_[31]= wert[31];z_[32]= wert[32];
			z_[33]= wert[33];z_[34]= wert[34];
			z_[35]= wert[35];z_[36]= wert[36];    
			z_[37]= wert[37];z_[38]= wert[38];
			z_[39]= wert[39];z_[40]= wert[40];    
			z_[41]= wert[41];z_[42]= wert[42];
			z_[43]= wert[43];z_[44]= wert[44];    
			z_[45]= wert[45];z_[46]= wert[46];
			z_[47]= wert[47];z_[48]= wert[48];    
			z_[49]= wert[49];z_[50]= wert[50];
			z_[51]= wert[51];z_[52]= wert[52];    
			z_[53]= wert[53];z_[54]= wert[54];
			z_[55]= wert[55];z_[56]= wert[56];    
			z_[57]= wert[57];z_[58]= wert[58];
			z_[59]= wert[59];z_[60]= wert[60];    
			z_[61]= wert[61];z_[62]= wert[62];
			z_[63]= wert[63];z_[64]= wert[64];    
		
			z_[5]=  z_[5]-min[2];
			z_[6] = S_[5]-z_[5];
			z_[7] = S_[6]-z_[5];
			z_[8] = N_[2]-z_[5]-z_[6]-z_[7];

			z_[9]=  z_[9]-min[3];
			z_[10] = S_[9]-z_[9];
			z_[11] = S_[10]-z_[9];
			z_[12] = N_[3]-z_[9]-z_[10]-z_[11];

			z_[13]=  z_[13]-min[4];
			z_[14] = S_[13]-z_[13];
			z_[15] = S_[14]-z_[13];
			z_[16] = N_[4]-z_[13]-z_[14]-z_[15];

			z_[17]=  z_[17]-min[5];
			z_[18] = S_[17]-z_[17];
			z_[19] = S_[18]-z_[17];
			z_[20] = N_[5]-z_[17]-z_[18]-z_[19];

			z_[21]=  z_[21]-min[6];
			z_[22] = S_[21]-z_[21];
			z_[23] = S_[22]-z_[21];
			z_[24] = N_[6]-z_[21]-z_[22]-z_[23];

			z_[25]=  z_[25]-min[7];
			z_[26] = S_[25]-z_[25];
			z_[27] = S_[26]-z_[25];
			z_[28] = N_[7]-z_[25]-z_[26]-z_[27];

			z_[29]=  z_[29]-min[8];
			z_[30] = S_[29]-z_[29];
			z_[31] = S_[30]-z_[29];
			z_[32] = N_[8]-z_[29]-z_[30]-z_[31];

			z_[33]=  z_[33]-min[9];
			z_[34] = S_[33]-z_[33];
			z_[35] = S_[34]-z_[33];
			z_[36] = N_[9]-z_[33]-z_[34]-z_[35];

			z_[37]=  z_[37]-min[10];
			z_[38] = S_[37]-z_[37];
			z_[39] = S_[38]-z_[37];
			z_[40] = N_[10]-z_[37]-z_[38]-z_[39];

			z_[41]=  z_[41]-min[11];
			z_[42] = S_[41]-z_[41];
			z_[43] = S_[42]-z_[41];
			z_[44] = N_[11]-z_[41]-z_[42]-z_[43];

			z_[45]=  z_[45]-min[12];
			z_[46] = S_[45]-z_[45];
			z_[47] = S_[46]-z_[45];
			z_[48] = N_[12]-z_[45]-z_[46]-z_[47];

			z_[49]=  z_[49]-min[13];
			z_[50] = S_[49]-z_[49];
			z_[51] = S_[50]-z_[49];
			z_[52] = N_[13]-z_[49]-z_[50]-z_[51];

			z_[53]=  z_[53]-min[14];
			z_[54] = S_[53]-z_[53];
			z_[55] = S_[54]-z_[53];
			z_[56] = N_[14]-z_[53]-z_[54]-z_[55];

			z_[57]=  z_[57]-min[15];
			z_[58] = S_[57]-z_[57];
			z_[59] = S_[58]-z_[57];
			z_[60] = N_[15]-z_[57]-z_[58]-z_[59];

			z_[61]=  z_[61]-min[16];
			z_[62] = S_[61]-z_[61];
			z_[63] = S_[62]-z_[61];
			z_[64] = N_[16]-z_[61]-z_[62]-z_[63];

		}
	}

	//fclose(out);
	if(k_>2)printf("\r                                                                           \r ");
	
	fn_erg=p;//zlr

	return fn_erg;
};

