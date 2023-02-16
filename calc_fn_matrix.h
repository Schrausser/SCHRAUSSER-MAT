//----------------------------------------------------------------------------------------------------| calc_ funktionen Matrizenrechnung, SCHRAUSSER 2010	//
double fn_matrix_a(double wert[100], int N, int sw);

double fn_matrix_a(double wert[100], int N, int sw)// Matrizenrechnung // 
//                                                                     // Addition       (1) MXA i,j,n,a11,...,a1k,...,ank,b11,...,b1k,...,bnk 
//                                                                     // Subtraktion    (2) MXS i,j,n,a11,...,a1k,...,ank,b11,...,b1k,...,bnk
//                                                                     // Transponierung (3) MXT i,j,n,a11,...,a1k,...,ank
//                                                                     // Spur           (4) MSP n,a11,...,a1k,...,ank
//                                                                     // Inversion      (5) MXI i,j,n,a11,...,a1k,...,ank
//                                                                     // Determinante   (6) MDT n,a11,...,a1k,...,ank
//                                                                     // Verkettung     (7) MXV i,j,n,a11,...,a1k,...,ank
//                                                                     // Multiplikation (8) MXM i,j,n1,k1,a11,...,a1k,...,ank,b11,...,b1k,...,bnk 
//                                                                     // Quadrierung    (9) MXQ i,j,n,k,a11,...,a1k,...,ank 
{
	int i_, j_, n_, n_k, k_, n_1, n_2, n_k_1, n_k_2, k_1, k_2, iLauf, jLauf, kLauf, ind=4;
	long double MX_[20][20], M_[20][20], V_[20][20] , E_[20][20]; // n=k=20 ggf. modifizieren
	long double x_=0, cb=0, sp=1;

	// ecvt indizes: double -> string -> int
	int stellen, vorz, maxlng=1;	       

	i_=atoi(ecvt(wert[1],maxlng,&stellen,&vorz));
	j_=atoi(ecvt(wert[2],maxlng,&stellen,&vorz));		
	n_=atoi(ecvt(wert[3],maxlng,&stellen,&vorz));
	if(sw==8 || sw==9)n_1=atoi(ecvt(wert[3],maxlng,&stellen,&vorz));
	if(sw==8 || sw==9)k_1=atoi(ecvt(wert[4],maxlng,&stellen,&vorz));
	//

	fn_erg=0;
	
	if(sw<=2) {n_k=(N-3)/2; k_= n_k / n_;}
	if(sw==3) {n_k=(N-3); k_= n_k / n_;}
	if(sw==4 || sw==6) {n_=i_; n_k=(N-1); k_= n_k / n_;}
	if(sw==5 || sw==7) {n_k=(N-3); k_= n_k / n_;}
	if(sw==8) {n_k=(N-4); n_k_1=n_1*k_1; n_k_2=n_k-n_k_1; n_2=k_1; k_2= n_k_2 / n_2;}
	if(sw==9) {n_k=(N-4); n_k_1=n_k; n_k_2=n_k; n_2=n_1; k_2= k_1 ;}
	if(sw<=4)
	{
		for(iLauf=1; iLauf<= n_; iLauf++)
		{
			for(jLauf=1; jLauf<= k_; jLauf++)
			{
				if(sw==1) MX_[iLauf][jLauf] = wert[ind]+wert[ind+n_k];
				if(sw==2) MX_[iLauf][jLauf] = wert[ind]-wert[ind+n_k];
				if(sw==3) MX_[jLauf][iLauf] = wert[ind];
				
				if(sw==4 && iLauf==jLauf) fn_erg += wert[ind];

				ind++;
			}	
		}
	}
	
	if(sw>=5 && sw <8)
    {
		//Einlesen von Matrix A in Feld M_	
		if(sw==6) ind=2;
		for(iLauf=1;iLauf<=n_;iLauf++)
		{
			for(jLauf=1;jLauf<=k_;jLauf++)
			{
				 M_[iLauf][jLauf]= wert[ind];
				 
				 ind++;
			}
		}

		if(sw==5 && n_==2)//Inversion bei n=2
		{
			x_= M_[1][1]*M_[2][2] - M_[1][2]*M_[2][1];// determinante

			MX_[1][1] =  (1/x_)*  M_[2][2]; MX_[1][2] =  (1/x_)* -M_[1][2];
			MX_[2][1] =  (1/x_)* -M_[2][1]; MX_[2][2] =  (1/x_)*  M_[1][1];
		}

		if(sw==5 && n_==3)//Inversion bei n=3
		{
			x_=  M_[1][1]*(M_[2][2]*M_[3][3] - M_[3][2]*M_[2][3]);   // determinante
			x_-= M_[2][1]*(M_[1][2]*M_[3][3] - M_[3][2]*M_[1][3]);
			x_+= M_[3][1]*(M_[1][2]*M_[2][3] - M_[2][2]*M_[1][3]);

			// Adjunkte A(adj)

			E_[1][1]=  M_[2][2]*M_[3][3]-M_[3][2]*M_[2][3];  E_[1][2]=-(M_[2][1]*M_[3][3]-M_[3][1]*M_[2][3]); E_[1][3]=  M_[2][1]*M_[3][2]-M_[3][1]*M_[2][2];    
		    E_[2][1]=-(M_[1][2]*M_[3][3]-M_[1][3]*M_[3][2]); E_[2][2]=  M_[1][1]*M_[3][3]-M_[3][1]*M_[1][3];  E_[2][3]=-(M_[1][1]*M_[3][2]-M_[3][1]*M_[1][2]);
		    E_[3][1]=  M_[1][2]*M_[2][3]-M_[2][2]*M_[1][3];  E_[3][2]=-(M_[1][1]*M_[2][3]-M_[2][1]*M_[1][3]); E_[3][3]=  M_[1][1]*M_[2][2]-M_[2][1]*M_[1][2];
		
			MX_[1][1]= (1/x_)* E_[1][1];  MX_[2][1]= (1/x_)* E_[1][2];  MX_[3][1]= (1/x_)* E_[1][3];
			MX_[1][2]= (1/x_)* E_[2][1];  MX_[2][2]= (1/x_)* E_[2][2];  MX_[3][2]= (1/x_)* E_[2][3];
			MX_[1][3]= (1/x_)* E_[3][1];  MX_[2][3]= (1/x_)* E_[3][2];  MX_[3][3]= (1/x_)* E_[3][3];
		}

		if(sw==5 && n_>3 || sw== 6 || sw==7) //Inversion bei n>3 via Verkettung nach Gauss
		{

			for(jLauf=1;jLauf<=k_;jLauf++) V_[1][jLauf]= M_[1][jLauf];           //Übergabe der ersten Zeile von M_ an V_
			for(iLauf=2;iLauf<=n_;iLauf++) V_[iLauf][1]= M_[iLauf][1]/-V_[1][1]; //Berechnung der ersten Spalte von  V_

			for(kLauf=2;kLauf<=k_;kLauf++)
			{
				for(iLauf=2;iLauf<=n_;iLauf++)
				{
					if(iLauf <= kLauf) // bis zum diagonalelement berechnung der oberen dreiecksmatrizenelemente b
					{
							for(jLauf=1;jLauf<=iLauf-1;jLauf++)cb += V_[jLauf][kLauf]*V_[iLauf][jLauf];
						
						V_[iLauf][kLauf] = 	M_[iLauf][kLauf] + cb;
															   cb=0;
					}
					
					if(iLauf > kLauf) // unter dem diagonalelement berechnung der unteren dreiecksmatrizenelemente c
					{
						
							 for(jLauf=1;jLauf<=kLauf-1;jLauf++)cb += V_[jLauf][kLauf]*V_[iLauf][jLauf];
			
						V_[iLauf][kLauf] = 	(M_[iLauf][kLauf] + cb) / -V_[kLauf][kLauf];
																cb=0;
					}
				}
			}

			//Berechnung der Determinante von A
			if(sw==6) for(iLauf=1;iLauf<=n_;iLauf++) sp*=V_[iLauf][iLauf]; //HauptdiagonalenPRODUKT von B

			for(kLauf=1;kLauf<=k_;kLauf++) //Erzeugung der Einheitsmatrix E_
			{
				for(iLauf=1;iLauf<=n_;iLauf++)
				{
					E_[iLauf][kLauf]=0; if(iLauf==kLauf)E_[iLauf][kLauf]=1;
				}
			}

			for(kLauf=1;kLauf<=k_;kLauf++) M_[1][kLauf]= E_[1][kLauf];//Berechnung der Matrix T_

			for(kLauf=1;kLauf<=k_;kLauf++)
			{
				for(iLauf=2;iLauf<=n_;iLauf++)
				{
							for(jLauf=1;jLauf<=iLauf-1;jLauf++)cb += E_[jLauf][kLauf]*V_[iLauf][jLauf];
						
						M_[iLauf][kLauf] = 	E_[iLauf][kLauf] + cb;
															   cb=0;
				}
			}

			for(iLauf=n_;iLauf>=1;iLauf--) //Berechnung der Matrix A_ (Transponierte inverse von M_)
			{
				for(kLauf=k_;kLauf>=1;kLauf--)
				{
					  for(jLauf=k_+1;jLauf>kLauf+1;jLauf--)cb += E_[iLauf][jLauf-1]*V_[kLauf][jLauf-1];
					E_[iLauf][kLauf]= (-M_[kLauf][iLauf] + cb) / -V_[kLauf][kLauf];
														   cb=0;
				}
			}

			//Transponierte Ausgabe von Matrix A_
			for(iLauf=1;iLauf<=n_;iLauf++)
			{
				for(jLauf=1;jLauf<=k_;jLauf++)
				{
					 MX_[iLauf][jLauf] = E_[jLauf][iLauf];

				}
			}
		}
	}
	
	if(sw==8 || sw==9)
    {
		//Einlesen von Matrix A in Feld M_	
		ind=5;
		for(iLauf=1;iLauf<=n_1;iLauf++)
		{
			for(jLauf=1;jLauf<=k_1;jLauf++)
			{
				 M_[iLauf][jLauf]= wert[ind];
				 
				 ind++;
			}
		}
		//Transponiertes Einlesen von Matrix B in Feld V_	
		ind=5+n_k_1;
		for(iLauf=1;iLauf<=n_2;iLauf++)
		{
			for(jLauf=1;jLauf<=k_2;jLauf++)
			{
				 if(sw==8)V_[jLauf][iLauf]= wert[ind];
				 if(sw==9)V_[jLauf][iLauf]= M_[iLauf][jLauf];
				 
				 ind++;
			}
		}

	    //matrizenmultiplikation
		for(kLauf=1;kLauf<=n_1;kLauf++)
		{
			for(iLauf=1;iLauf<=k_2;iLauf++)
			{
				for(jLauf=1;jLauf<=k_1;jLauf++)
				{
		 
					 x_+= M_[kLauf][jLauf]*V_[iLauf][jLauf]; 
				}
				MX_[kLauf][iLauf] =x_;
				x_=0;
			}
		}
	}
	
	if(sw!=4 && sw!=6 && sw!=7) fn_erg = MX_[i_][j_];
	if(sw==6) fn_erg = sp;
	if(sw==7) fn_erg = V_[i_][j_];


	return fn_erg;
}

double fn_betaR(double wert[100], int N)// Beta Gewicht bi zum Multiplen-Korrelationskoeffizienten R  // BMK i,k,r1c,r2c,...,rkc,r12,...,r1k,...,rik
{
	double R_[100], r_[10], X_[20][20], R_1[100], Rr_[110], b_[10];
	int i_, k_, iLauf, jLauf, ind=1, zlr1=1, zlr2=0, indx=1;
	// ecvt indizes: double -> string -> int
	int stellen, vorz, maxlng=1;	       

	i_=atoi(ecvt(wert[1],maxlng,&stellen,&vorz));
	k_=atoi(ecvt(wert[2],maxlng,&stellen,&vorz));

	for(iLauf=1;iLauf<=k_;iLauf++) r_[iLauf]=wert[iLauf+2]; 

	for(iLauf=1;iLauf<=k_;iLauf++) //einlesen der oberen prädiktor interkorrelations 3-ecks matrix 
	{
		for(jLauf=indx;jLauf<=k_;jLauf++)
		{
			if(iLauf!=jLauf) {X_[iLauf][jLauf]=wert[ind+2+k_];ind++;}
			if(iLauf==jLauf) X_[iLauf][jLauf]=1;
		}
		indx++;
	}
	
	ind=1; indx=1;
	for(iLauf=1;iLauf<=k_;iLauf++)//transponiertes einlesen der oberen prädiktor interkorrelations 3-ecks matrix 
	{
		for(jLauf=indx;jLauf<=k_;jLauf++)
		{
			if(iLauf!=jLauf) {X_[jLauf][iLauf]=wert[ind+2+k_];ind++;}
			if(iLauf==jLauf) X_[jLauf][iLauf]=1;
		}
		indx++;
	}

	/*
	for(iLauf=1;iLauf<=k_;iLauf++)
	{
		for(jLauf=1;jLauf<=k_;jLauf++)
		{	
			printf("\n%f",X_[iLauf][jLauf]);
		}
	}
	*/
	ind=4;
	for(iLauf=1;iLauf<=k_;iLauf++)
	{
		for(jLauf=1;jLauf<=k_;jLauf++)
		{	
			R_[ind]=X_[iLauf][jLauf]; //Matrix X_ an Vektor R_
			ind++;
		}
	}
	
	//for(iLauf=4;iLauf<=k_*k_+3;iLauf++)printf("\n%f",R_[iLauf]);
	
	ind=1;
	for(iLauf=1;iLauf<=k_;iLauf++)
	{
		for(jLauf=1;jLauf<=k_;jLauf++)
		{
			R_[1]=iLauf;
			R_[2]=jLauf;
			R_[3]=k_;
			
			R_1[ind]= fn_matrix_a( R_, k_*k_+3, 5); //inverse von Rx
			
			ind++;
		}
	}
	//for(iLauf=1;iLauf<=k_*k_;iLauf++)printf("\n%f",R_1[iLauf]);
	
	for(iLauf=1;iLauf<=k_*k_;iLauf++)    Rr_[iLauf+4]=R_1[iLauf]; 
	for(iLauf=1;iLauf<=k_;iLauf++)	Rr_[iLauf+4+k_*k_]=r_[iLauf]; 
	
	for(iLauf=1;iLauf<=k_;iLauf++)
	{
		Rr_[1]=iLauf;
		Rr_[2]=1;
		Rr_[3]=k_;
		Rr_[4]=k_;
		
		b_[iLauf]= fn_matrix_a( Rr_, k_*k_+k_+4, 8); // Rx * rxc
	}
	//for(iLauf=1;iLauf<=k_*k_+k_+4;iLauf++)printf("\n%f",Rr_[iLauf]);
	//for(iLauf=1;iLauf<=k_;iLauf++)printf("\n%f",b_[iLauf]);

	fn_erg= b_[i_];

	return 0;
};


double fn_invR(double wert[100], int N)// Element rii zur inversen Korrelationsmatrix R  // MRI i,k, r12,...,r1k,...,rik
{
	double R_[100],  X_[20][20], R_1[20][20];
	int i_, k_, iLauf, jLauf, ind=1, zlr1=1, zlr2=0, indx=1;
	// ecvt indizes: double -> string -> int
	int stellen, vorz, maxlng=1;	       

	i_=atoi(ecvt(wert[1],maxlng,&stellen,&vorz));
	k_=atoi(ecvt(wert[2],maxlng,&stellen,&vorz));

	for(iLauf=1;iLauf<=k_;iLauf++) //einlesen der oberen interkorrelations 3-ecks matrix 
	{
		for(jLauf=indx;jLauf<=k_;jLauf++)
		{
			if(iLauf!=jLauf) {X_[iLauf][jLauf]=wert[ind+2];ind++;}
			if(iLauf==jLauf) X_[iLauf][jLauf]=1;
		}
		indx++;
	}
	
	ind=1; indx=1;
	for(iLauf=1;iLauf<=k_;iLauf++)//transponiertes einlesen der oberen interkorrelations 3-ecks matrix 
	{
		for(jLauf=indx;jLauf<=k_;jLauf++)
		{
			if(iLauf!=jLauf) {X_[jLauf][iLauf]=wert[ind+2];ind++;}
			if(iLauf==jLauf) X_[jLauf][iLauf]=1;
		}
		indx++;
	}

	/*
	for(iLauf=1;iLauf<=k_;iLauf++)
	{
		for(jLauf=1;jLauf<=k_;jLauf++)
		{	
			printf("\n%f",X_[iLauf][jLauf]);
		}
	}
	*/
	ind=4;
	for(iLauf=1;iLauf<=k_;iLauf++)
	{
		for(jLauf=1;jLauf<=k_;jLauf++)
		{	
			R_[ind]=X_[iLauf][jLauf]; //Matrix X_ an Vektor R_
			ind++;
		}
	}
	
	//for(iLauf=4;iLauf<=k_*k_+3;iLauf++)printf("\n%f",R_[iLauf]);
	
	ind=1;
	for(iLauf=1;iLauf<=k_;iLauf++)
	{
		for(jLauf=1;jLauf<=k_;jLauf++)
		{
			R_[1]=iLauf;
			R_[2]=jLauf;
			R_[3]=k_;
			
			R_1[iLauf][jLauf]= fn_matrix_a( R_, k_*k_+3, 5); //inverse von Rx
			
			ind++;
		}
	}
	//for(iLauf=1;iLauf<=k_*k_;iLauf++)printf("\n%f",R_1[iLauf]);
	

	//for(iLauf=1;iLauf<=k_*k_+k_+4;iLauf++)printf("\n%f",Rr_[iLauf]);
	//for(iLauf=1;iLauf<=k_;iLauf++)printf("\n%f",b_[iLauf]);

	fn_erg= R_1[i_][i_];

	return 0;
};
















	
	