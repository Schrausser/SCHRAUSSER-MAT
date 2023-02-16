//----------------------------------------------------------------------------------------------------| calc_ funktionen, SCHRAUSSER 2009 - 2011	//

double fn_wert[100];
long double fn_erg;
long double SIGMA = 34.0/45;
long double pi_zahl(){return 2*(1+pow(SIGMA,2));} 

double fn_const(int sw);
double fn_sort(double wert[100], double n, int theta);
double stat_theta(double wert[100], double n, int theta);
double fn_lin_reg(double wert[100], double n, int koef);
double zahl_0(double wert);
double vzeichen(double wert);
double faktoriell(double wert);
double fn_nk(double n, double k);
double dz_funktion(double wert);
double dt_funktion(double wert[100]);
double dx_funktion(double wert[100]);
double df_funktion(double wert[100]);
double zp_funktion(double wert);
double pz_funktion(double wert);
double pL_funktion(double wert[100]);
double Lp_funktion(double wert[100]);
double dL_funktion(double wert[100]);
double pA_funktion(double wert[100]);
double Ap_funktion(double wert[100]);
double pV_funktion(double wert[100]);
double Vp_funktion(double wert[100]);
double pC_funktion(double wert[100]);
double Cp_funktion(double wert[100]);
double pW_funktion(double wert[100]);
double Wp_funktion(double wert[100]);
double pd_funktion(double wert[100]);
double ptd_funktion(double wert[100]);
double tp_funktion(long double p_wert, double n_);
double pt_funktion(long double t_wert, double n_);
double fn_epsilon(double wert[100], int sw);
double fn_frpt(double wert[100]);
double px_funktion(long double x2_wert, double n_);
double xp_funktion(long double p_wert, double n_);
double pxd_funktion(double wert[100]);
double pf_funktion(long double f_wert, double n_1, double n_2);
double fp_funktion(long double f_wert, double n_1, double n_2);
double pfd_funktion(double wert[100]);
double fn_fmkp(double wert[100]);
double gamma(double wert);
double igamma(double wert[100]);
double inv_gamma(double wert, int theta);
double fn_trw(double wert,double n);
double fn_frpz(double wert[100], int sw);
double fn_binom(double wert[100], int theta);
double fn_binom_t(double wert[100], int theta);
double fn_mtnom(double wert[100], int n_);
double fn_hygeo(double wert[100], int theta);
double fn_hg_(double wert[100], int sw);
double kombination_(double n, double k);
double kombination_w(double n, double k);
double variation_(double n,double k);
double permutation_k(double wert[100], int nk);
double fn_t_uv(double wert[100],double n, int theta);
double fn_U_test(double wert[100], double n, int theta);


double fn_format(double wert[100]) // Zahlenausgabeformat // FORM vk,nk,f; f(1=f,2=g,3=G)
{
	int iLauf;
	char zfm, prm[20][50], zeile[20][50];

	FILE *iniStream; 
	
	if(wert[3]==1)zfm='f'; if(wert[3]==2)zfm='g'; if(wert[3]==3)zfm='G';

	iniStream = fopen ("MAT.ini", "r");
	for(iLauf=1; iLauf<= 9; iLauf++)fscanf(iniStream,"%s%s",prm[iLauf], zeile[iLauf]); 
	fclose( iniStream );

	iniStream = fopen ("MAT.ini", "w");

	fprintf( iniStream,"%.0f\t\t//vorkommastellen\n", wert[1]); 
	fprintf( iniStream,"%.0f\t\t//nachkommastellen\n", wert[2]); 
	fprintf( iniStream,"%c\t\t//zahlenformat\n", zfm); 

	for(iLauf=4; iLauf<= 9; iLauf++) fprintf(iniStream,"%s\t\t%s\n",prm[iLauf], zeile[iLauf]); 
	fclose( iniStream ); 

	fn_erg=1;
	return fn_erg;

	exit(1);
};

double fn_const(int sw)// Konstante Parameter // 
//                                            // (1) Eulersche Zahl, EUL
//                                            // (2) Pi Zahl, PI_
{
	if(sw==1)fn_erg= 2.7182818284590452353602874713527;
	if(sw==2)fn_erg= 3.1415926535897932384626433832795;
	
	return fn_erg;
};


double fn_e(double n)// Eulersche Zahl e (grenzwertformulierung) // EXP n
{
	if(n==0)n=pow(10,11); fn_erg= pow(1+1/n,n);
	
	return fn_erg;
};


double qzufall(double seed, double min, double max)// Quasizufallszahl // RND seed,min,max
{
	if(seed == 0.0) seed=(time(0)-1234567890); 
	
	fn_erg =		   10*( pow(seed,SIGMA) - floor( pow(seed,SIGMA) ) ) 
		      - floor( 10*( pow(seed,SIGMA) - floor( pow(seed,SIGMA) ) ) );
	
	fn_erg= min + (max-min)*fn_erg;
	
	return fn_erg;
};

double qzfx(double wert[100], int n)// Quasizufallselement px1 von Vektor x  // RNV seed, x1,x2 .. xn
{
	int iLauf, jLauf, hub=0;
	double srt0[100], srt[100], rnd_[100], min, sd;
	                                                   sd= wert[1];
	                                if(wert[1] == 0.0) sd=(time(0)-1234567890);                      
	                    n=n-1;           
	for(iLauf=1; iLauf<=n;iLauf++){srt0[iLauf]=qzufall(sd,0,1);sd=srt0[iLauf];}//zufallsvektor

	min=srt0[1]; 
	for (iLauf = 1; iLauf <= n; iLauf++)if(srt0[iLauf]<min)min=srt0[iLauf];//min
			
	srt[1] = min;//anfangswert=minimalwert

	for (iLauf = 1; iLauf <= n; iLauf++)//sortierung nach zufallszahl
	{
		for (jLauf = 0; jLauf < iLauf; jLauf++)
		{
			if (srt0[iLauf] < srt[iLauf-jLauf])
			{
				srt[(iLauf-jLauf)+1] = srt[iLauf-jLauf]; 	
			   rnd_[(iLauf-jLauf)+1] = rnd_[iLauf-jLauf];hub++;
			}	
		}
		srt[(iLauf+1)-hub] = srt0[iLauf]; 
		rnd_[(iLauf+1)-hub] = wert[iLauf+1];hub=0; // zuordnung von vektorelement
	}

	for (iLauf = 2; iLauf <= n+1; iLauf++)rnd_[iLauf-1]=rnd_[iLauf];//laufindexkorrektur
	rnd_[iLauf-1]=0;
		
	fn_erg = rnd_[1]; // px1
		
	return 0;
}

double faktoriell(double wert)// faktoriell // ! FACT
{	
	int iLauf;
	double fc_, vektor[3];
	fn_erg=1;

	//bei berechnung über gammaintegrale
	vektor[1]=wert+1;
	vektor[2]=1000;
	
	if(          wert-floor(wert)==0)for(iLauf = 1; iLauf <= wert; iLauf++) fn_erg *= iLauf;
	if(wert<=70&&wert-floor(wert)!=0){fc_=gamma(wert+1);fn_erg=fc_;} //gamma polynom
	if(wert> 70&&wert<=108&&wert-floor(wert)!=0){fc_=igamma(vektor);fn_erg=fc_;} //gamma integrale
	
	return fn_erg;
};

double faktoriell_2(double wert)// doppelfaktoriell // !!
{
	double iLauf;
	fn_erg=1;
	
	for(iLauf = wert; iLauf >= 2; iLauf -=2) fn_erg *= iLauf;
	
	return 0;
};

double faktoriell_4(double wert)// tripelfaktoriell // !.!
{
	double iLauf;
	fn_erg=1;
	
	for(iLauf = wert; iLauf >= 2; iLauf -=3) fn_erg *= iLauf;

	//fn_erg=3;
	
	return 0;
};

/*
double faktoriell_8(double wert)// 8faktoriell // B!  
{
	double iLauf;
	fn_erg=1;
	
	for(iLauf = wert; iLauf >= 2; iLauf -=8) fn_erg *= iLauf;
	
	return 0;
};
*/

double faktoriell_V(double wert)// gegen-faktoriell // V_ n  
{
	double iLauf;//, f_
	fn_erg=wert;
	
	for(iLauf = 1; iLauf <= wert; iLauf ++)
	{
		fn_erg /= iLauf;
		if(fn_erg<=1.0) break;
	}
	/*
	if(fn_erg!=1.0) 
	{
		f_=iLauf-1;
		if(fabs(faktoriell(iLauf)-wert)<fabs(faktoriell(iLauf-1)-wert))f_=iLauf;
		printf(" 'nV={}, %.0f! -> %.0f'",f_,wert); exit(0);
	}
	*/
	if(fn_erg!=1.0)//via beta Gamma (gamma inverse)
	{
		iLauf=inv_gamma(wert, 2)-1;
	}

	fn_erg=iLauf;
	
	return 0;
};


double fn_nk(double n, double k)// binomialkoeffizient n über k // N_K n,k
{
	double  iLauf, jLauf,n_=1, k_=1,  nk=1 , fact, erg_=1;
	long double x_=1;
	fn_erg = 1;
	                       fact = n;
	for(jLauf = 0; jLauf < fact; jLauf++) //n - faktoriellzerlegung
	{
		for(iLauf =   n-jLauf; iLauf >= 2; iLauf -= fact)	n_ *= iLauf;
		for(iLauf =   k-jLauf; iLauf >= 2; iLauf -= fact)   k_ *= iLauf;
		for(iLauf = n-k-jLauf; iLauf >= 2; iLauf -= fact)   nk *= iLauf;

		                    x_=(n_/(k_*nk));
		  	 //if(k/n!=0.5)if(x_==1 ) { break;}//printf("break\n");
		 fn_erg =  fn_erg * x_;
		
		n_=1, k_=1,  nk=1;
	}

	return fn_erg;
};

double fn_wkt(double wert[100], int n, int theta) // Wahrscheinlichkeiten // 
//                                                                 // Multiplikative Wkt          (1) MPW pA1, ... , pAn / MPW pA1, pA2|A1, ... , pAn|A1...An 
//                                                                 // Additive Wkt (ausschl abh)  (2) AAA pA1, ... , pAn
//                                                                 // Additive Wkt (einschl unabh)(3) AEU pA1, ... , pAn
//                                                                 // Additive Wkt (unabh)        (4) AWN pA, n
//                                                                 // Additive Wkt (einschl  abh) (5) AEA pA, pB, pAB
//                                                                 // Bedingte Wkt                (6) BWA pA, pAB  
//                                                                 // Totale Wkt                  (7) TWA pA1, pB|A1, ... , pAn, pB|An 
//                                                                 // Bayes Formulierung          (8) BYS pA1, pB|A1, ... , pAn, pB|An
{
	int iLauf;
	
	if(theta == 1) {fn_erg=1; for (iLauf=1; iLauf<= n; iLauf++)fn_erg*= wert[iLauf];}//(1)
	if(theta == 2) {fn_erg=0; for (iLauf=1; iLauf<= n; iLauf++)fn_erg+= wert[iLauf];}//(2)
	if(theta == 3) {fn_erg=1; for (iLauf=1; iLauf<= n; iLauf++)fn_erg*= 1-wert[iLauf];fn_erg=1-fn_erg;}//(3)                                                                  
	if(theta == 4)  fn_erg=1-pow(1-wert[1],wert[2]); //(4)  
	if(theta == 5)  fn_erg=wert[1]+wert[2]-wert[3];//(5)
	if(theta == 6)  fn_erg=wert[2]/wert[1];//(6)
	if(theta == 7) {fn_erg=0; for (iLauf=1; iLauf<= n; iLauf+=2)fn_erg+= wert[iLauf]*wert[iLauf+1];}//(7) 	                                 
	if(theta == 8) {fn_erg=0; for (iLauf=1; iLauf<= n; iLauf+=2)fn_erg+= wert[iLauf]*wert[iLauf+1];fn_erg=(wert[1]*wert[2])/fn_erg;}//(8) 	
	
	return 0;
};

double fn_binom(double wert[100], int theta)// binomialwahrscheinlichkeit  //
//																	  //BNW (1)p,k,n
//																	  //BNP (2)p,k,n
{
	double iLauf;
	double n, k, p, q, BW=0;

	p=wert[1]; k=wert[2]; n=wert[3]; q=1-p;

	//Binomialwahrscheinlichkeit (pA höchstens (<=) k mal von n)
	if(theta==1) for(iLauf = 0; iLauf <= k; iLauf++)BW+=fn_nk(n,iLauf)*pow(p,iLauf)*pow(q,n-iLauf);
		
	//Binomialpunktwahrscheinlichkeit (pA genau (=) k mal von n)
	if(theta==2) BW=fn_nk(n,k)*pow(p,k)*pow(q,n-k);

	fn_erg= BW;
	
	return fn_erg;
}

double fn_binom_t(double wert[100], int theta)// exakt binomialer 2-felder test  //
//														                         //BN0 (1)b,c
//														                         //BN1 (2)b,c
//														                         //BN2 (3)b,c
//                                                                               //ZBN (4)b,c 
{
	double iLauf;
	double n, k, p, q, BW=0;

	p=0.5; k=wert[1]; n=wert[1]+wert[2]; q=1-p;

	//Binomialpunktwahrscheinlichkeit P0
	if(theta==1) BW=fn_nk(n,k)*pow(p,k)*pow(q,n-k);

	//Signifikanzniveaus pexact
	if(theta==2 || theta==3) 
	{
		for(iLauf = 0; iLauf <= k; iLauf++)BW+=fn_nk(n,iLauf)*pow(p,iLauf)*pow(q,n-iLauf);
		if (BW > 0.5) BW = (1-BW)+ fn_nk(n,k)*pow(p,k)*pow(q,n-k);
	
		if (theta==2)if(k/n == 0.5)  BW=BW-(fn_nk(n,k)*pow(p,k)*pow(q,n-k))/2; // bei P(i)=0.5 p1-P0/2
		
		if (theta==3) 
		{
			BW=BW*2;
			if(k/n == 0.5) BW=BW- fn_nk(n,k)*pow(p,k)*pow(q,n-k); // bei P(i)=0.5 p2-2*P0/2

		}	
	}
	
	fn_erg= BW; if(fn_erg>1)fn_erg=1;

	// z-wert zur 2-Felder anordnung p=q=0.5
	if(theta==4) fn_erg=(k-(n /2))/sqrt( n/4)    ;
	
	return fn_erg;
}

double fn_poisson(double wert[100], int theta)// poissonwahrscheinlichkeit  //
//                                               = binomialwkt. bei n->oo, p->0, p*n= konstant
//												 wobei lambda=my=s2= p*n
//																	        //PNW (1)p,k,n
//																	        //PNP (2)p,k,n
{
	double iLauf;
	double n, k, p, PW=0;

	p=wert[1]; k=wert[2]; n=wert[3]; 

	//Poissonwahrscheinlichkeit (pA höchstens (<=) k mal von n)
	if(theta==1) for(iLauf = 0; iLauf <= k; iLauf++) PW+=pow(p*n,iLauf)/(faktoriell(iLauf)*pow(fn_const(1),p*n));

	//Poissonpunktwahrscheinlichkeit (pA genau (=) k mal von n)
	if(theta==2) PW=pow(p*n,k)/(faktoriell(k)*pow(fn_const(1),p*n));

	fn_erg= PW;
	
	return 0;
};

double fn_nbinom(double wert[100], int theta)// negative binomialwahrscheinlichkeit  // 
//                                              mit k=1 =geometrische Wahrscheinlichkeit 
//																	      //NBW (1)p,k,r+k
//																	      //NBP (2)p,k,r+k
{
	double iLauf;
	double r, k, p, q, NB=0;

	p=wert[1]; k=wert[2]; r=wert[3]-k; q=1-p;

	//Negative Binomialwahrscheinlichkeit (pA höchstens (<=) das k te mal bei r+k)
	if(theta==1)for(iLauf = 0; iLauf <= k; iLauf++) NB+=fn_nk(k+r-1,r+(k-iLauf))*pow(p,iLauf)*pow(q,r+(k-iLauf)); //<??über k
	//if(theta==1)for(iLauf = 0; iLauf <= r; iLauf++) NB+=fn_nk(k+iLauf-1,iLauf)*pow(p,k)*pow(q,iLauf); //über r
	//if(theta==1)for(iLauf = 0; iLauf <= k; iLauf++) NB+=fn_nk(iLauf+r-1,r)*pow(p,iLauf)*pow(q,r); //über k
	
	//Negative Binomialpunktwahrscheinlichkeit (pA das k te mal bei r+k)
	if(theta==2)NB=fn_nk(k+r-1,r)*pow(p,k)*pow(q,r);
	
	fn_erg= NB;

	return 0;
};

double fn_geom(double wert[100], int theta)// geometrische wahrscheinlichkeit  // 
//																	      //GMW (1)p,r+1
//																	      //GMP (2)p,r+1
{
	double iLauf;
	double r, p, q, GW=0;

	if(theta==1)if(wert[2]>1000000)printf("\n\ncomputing Pi ...");

	p=wert[1]; r=wert[2]-1; q=1-p;

	//Geometrische Wahrscheinlichkeit (pA das 1 te mal bis (<=) r+1)
	if(theta==1)for(iLauf = 0; iLauf <= r; iLauf++) GW+=p*pow(q,iLauf);
		
	//Geometrische Punktwahrscheinlichkeit (pA das 1 te mal bei r+1)
	if(theta==2)GW=p*pow(q,r);

	if(theta==1)if(wert[2]>1000000)printf("\r                  \r");
	
	fn_erg= GW; 

	return 0;
};

double fn_mtnom(double wert[100], int n_)// multi(poly)nomialwahrscheinlichkeit  // MNP p1,k1,...,ps,ks,n
{
	int iLauf;
	double ft_n, ft_k=1, f_p=1, sum_p=0, sum_k=0;

	for(iLauf = 1; iLauf <= n_-1; iLauf+=2)
	{
		sum_p+=wert[iLauf]; sum_k+=wert[iLauf+1];
	}

	if (sum_p < 0.999999 )	{printf("\n\nvalue.0 'sum(p)< 1'\n");exit(0);}
	if (sum_p > 1.000001 )	{printf("\n\nvalue.0 'sum(p)> 1'\n");exit(0);}
	if (sum_k != wert[n_])	{printf("\n\nvalue.0 'sum(k)<>n'\n");exit(0);}

	fn_erg= 1;

	ft_n=faktoriell(wert[n_]);
	
	//Multinomialpunktwahrscheinlichkeit (genau (=) k1,k2, ... ,ks von n, wobei sum(k1..ks)= n)
	if(n_>3)
	{
		for(iLauf = 1; iLauf <= n_-1; iLauf+=2)
		{
			ft_k*=faktoriell(wert[iLauf+1]); f_p*=pow(wert[iLauf],wert[iLauf+1]);
		}	
		fn_erg= (ft_n/ft_k)*f_p;
	}
	if(n_==3) fn_erg= fn_nk(wert[3],wert[2])*pow(wert[1],wert[2])*pow(1-wert[1],wert[3]-wert[2]);
	
	return fn_erg;
};

double fn_hygeo(double wert[100], int theta)// hypergeometrische wahrscheinlichkeit  //
//																	      //HGW (1)k,n,N,K
//																	      //HGP (2)k,n,N,K
{
	double iLauf;
	double k, n, N, K, HG=0;

	k=wert[1]; n=wert[2]; N=wert[3]; K=wert[4]; 
	
	//Hypergeometrische Wahrscheinlichkeit (höchstens (<=) kA von n von N mit KA)
	if(theta==1) for(iLauf = 0; iLauf <= k; iLauf++) HG+= (fn_nk(K,iLauf)*fn_nk(N-K,n-iLauf))/fn_nk(N,n);

	//Hypergeometrische Punktwahrscheinlichkeit (genau (=) kA von n von N mit KA)
	if(theta==2) HG= (fn_nk(K,k)*fn_nk(N-K,n-k))/fn_nk(N,n);

	fn_erg= HG;

	return fn_erg;
};

double fn_zhg(double wert[100])// z-wert zum hypergeometrischen 4-Felder Test  // ZFX a,b,c,d
{
	double a_, b_, c_, d_, n_, p, p1;

	a_=wert[1]; b_=wert[2]; 
	c_=wert[3]; d_=wert[4]; 

	n_=a_+b_+c_+d_;
				   p=(( d_+b_)*(c_+d_))/pow(n_,2);
													   p1=(( d_+b_-1)*(c_+d_-1))/pow(n_-1,2);
	fn_erg =(d_-n_*p-0)/sqrt(n_*p*(1-p)-n_*(n_-1)*p*(p-p1));

	return 0;
};

double fn_wkt_x(double wert[100], int sw) // Mittelwert und Streuung zu 
//                                        // binomial und hypergeometrischer Verteilung  // 
//                                                                             // binomial µx         (1) BNM p,n
//                                                                             // binomial sx         (2) BNS p,n
//                                                                             // hypergeometrisch µx (3) HGM n,N,K
//                                                                             // hypergeometrisch sx (4) HGS n,N,K
{
	if(sw==1) fn_erg= wert[1]*wert[2];
	if(sw==2) fn_erg= sqrt(wert[1]*wert[2]*(1-wert[1]));
	if(sw==3) fn_erg= wert[1]*(wert[3]/wert[2]);
	if(sw==4) fn_erg= sqrt((wert[2]-wert[1])/(wert[2]-1)*wert[1]*(wert[3]/wert[2])*(1-(wert[3]/wert[2])));

	return 0;
};






double fn_dgrad(double wert, int sw)// Bogenmasstransformation //
//                                                             // grad -> rad (1) RAD a
//                                                             // rad -> grad (2) DEG x
//                                                             // grad -> neugrad (3) GRAD x
//                                                             // neugrad -> grad (4) DGR x
{	
	long double pi_=pi_zahl();

	if(sw ==1) fn_erg= wert * pi_/180; // grad -> rad
	if(sw ==2) fn_erg= wert * 180/pi_; // rad -> grad
	if(sw ==3) fn_erg= wert * 100/90; // grad -> neugrad
	if(sw ==4) fn_erg= wert * 90/100; // neugrad -> grad
	
	return fn_erg;
};

double fn_wfkt(double wert, int sw)	// winkelfunktionen // 
//                                                      // Cotangens (1) COT x
//                                                      // Secans    (2) SEC x
//                                                      // Cosecans  (3) CSE x 
//													    // Hyperbolischer Cotangens (4) HCT x 
//                                                      // Hyperbolischer Secans    (5) HSE x 
//                                                      // Hyperbolischer Cosecans  (6) HCE x
//                                                      // Arcus Cotangens  (7) ACT x
//                                                      // Arcus Secans  (8) ASE x
//                                                      // Arcus Cosecans  (9) ACE x
//                                                      // Hyperbolischer Arcus Sinus  (10) AHS x
//                                                      // Hyperbolischer Arcus Cosinus  (11) AHC x
//                                                      // Hyperbolischer Arcus Tangens  (12) AHT x
//                                                      // Hyperbolischer Arcus Cotangens  (13) AHG x
//                                                      // Hyperbolischer Arcus Secans  (14) AHN x
//                                                      // Hyperbolischer Arcus Cosecans  (15) AHO x
//                                                      // Arcus Cotangens (Iteratives Näherungsverfahren) (16) IACT x
//                                                      // Arcus Secans (Iteratives Näherungsverfahren) (17) IASE x
//                                                      // Arcus Cosecans (Iteratives Näherungsverfahren) (18) IACE x
//                                                      // Hyperbolischer Arcus Sinus (Iteratives Näherungsverfahren) (19) IAHS x
//                                                      // Hyperbolischer Arcus Cosinus (Iteratives Näherungsverfahren) (20) IAHC x
//                                                      // Hyperbolischer Arcus Tangens (Iteratives Näherungsverfahren) (21) IAHT x
//                                                      // Hyperbolischer Arcus Cotangens (Iteratives Näherungsverfahren) (22) IAHG x
//                                                      // Hyperbolischer Arcus Secans (Iteratives Näherungsverfahren) (23) IAHN x
//                                                      // Hyperbolischer Arcus Cosecans (Iteratives Näherungsverfahren) (24) IAHO x

{
	double erg=99999, i_=0, i=1, zlr=0, krit=10000, krit2=10000000000;
	//long double pi_=pi_zahl();

	fn_erg=0;
	
	if(sw ==1) fn_erg= 1/tan(wert);
	if(sw ==2) fn_erg= 1/cos(wert);
	if(sw ==3) fn_erg= 1/sin(wert);
	//if(sw ==4) fn_erg= 1/tanh(wert);
	//if(sw ==5) fn_erg= 1/cosh(wert);
	//if(sw ==6) fn_erg= 1/sinh(wert);

	// Funktionsverfahren
	if(sw ==4)   fn_erg= 1+2*(pow(fn_const(1),-wert)/(pow(fn_const(1),wert)-pow(fn_const(1),-wert)));
	if(sw ==5)   fn_erg= 2/(pow(fn_const(1),wert)+pow(fn_const(1),-wert));
	if(sw ==6)   fn_erg= 2/(pow(fn_const(1),wert)-pow(fn_const(1),-wert));
	if(sw ==7)   fn_erg= -atan(wert)+1.5708;
	if(sw ==8) {    erg= atan(   ( sqrt(wert*wert-1) )) +( (vzeichen(wert)-1)*+1.5708 ); fn_erg=erg; }
	if(sw ==9) {    erg= atan( 1/( sqrt(wert*wert-1) )) +( (vzeichen(wert)-1)*+1.5708 ); fn_erg=erg; }
	if(sw ==10)  fn_erg= log( wert+ sqrt(wert*wert+1) );
	if(sw ==11)  fn_erg= log( wert+ sqrt(wert*wert-1) );
	if(sw ==12)  fn_erg= log( (1+wert)/(1-wert) )/2;
	if(sw ==13)  fn_erg= log( (1+wert)/(wert-1) )/2;
	if(sw ==14)  fn_erg= log( ( sqrt(-wert*wert+1)+1 )/wert  );
	if(sw ==15){    erg= log( ( vzeichen(wert)*sqrt(wert*wert+1)+1 )/wert  ); fn_erg=erg; }

	if(sw >=16 ) //näherungsverfahren
	{
		while(floor(erg*krit2)!=floor(wert*krit2) && zlr < krit)
		{	
			while(erg < wert )
			{
				if(sw ==16)erg=1/tan(i_); 
				if(sw ==17)erg=1/cos(i_); 
				if(sw ==18)erg=1/sin(i_); 
				if(sw ==19)erg=sinh(i_); 
				if(sw ==20)erg=cosh(i_); 
				if(sw ==21)erg=tanh(i_); 
				if(sw ==22)erg=1/tanh(i_); 
				if(sw ==23)erg=1/cosh(i_); 
				if(sw ==24)erg=1/sinh(i_); 
				if(floor(erg*krit2)==floor(wert*krit2) || zlr > krit) break; 
				if(sw <19 || sw > 21)i_-=i;
				if(sw >=19 && sw <= 21)i_+=i; 
				
				zlr++;
			} 
			i/=100;
			
			while(erg > wert )
			{
				if(sw ==16)erg=1/tan(i_); 
				if(sw ==17)erg=1/cos(i_);
				if(sw ==18)erg=1/sin(i_);
			    if(sw ==19)erg=sinh(i_);
				if(sw ==20)erg=cosh(i_);
				if(sw ==21)erg=tanh(i_);
				if(sw ==22)erg=1/tanh(i_);
				if(sw ==23)erg=1/cosh(i_);
				if(sw ==24)erg=1/sinh(i_);
				if(floor(erg*krit2)==floor(wert*krit2) || zlr > krit) break; 
				if(sw <19 || sw > 21)i_+=i; 
				if(sw >=19 && sw <= 21)i_-=i;
					
				zlr++;
			} 
			i/=10;
		}	
		fn_erg=i_;if(sw ==17)fn_erg=-fn_erg;
	}

/* näherungsverfahren vorversion

	if(sw >  15)//if(wert > 0.000001 || wert < -0.000001)
	{
		if( wert >= 0)
		{
			fn_erg= 0.000001;printf(" calculating...");
			if(sw ==7)while(1/tan(fn_erg) > wert) {fn_erg += 0.000001; if (fn_erg > 999) break;}
			if(sw ==8)while(floor(1000000*(1/sin(fn_erg))) != floor(1000000*wert)) {fn_erg += 0.000001; if (fn_erg > 999) break;}
			if(sw ==9)while(floor(1000000*(1/cos(fn_erg))) != floor(1000000*wert)) {fn_erg += 0.000001; if (fn_erg > 999) break;}
			if(sw==10)while(sinh(fn_erg) < wert) {fn_erg += 0.000001; if (fn_erg > 999) break;}
			if(sw==11)while(cosh(fn_erg) < wert) {fn_erg += 0.000001; if (fn_erg > 999) break;}
			if(sw==12)while(tanh(fn_erg) < wert) {fn_erg += 0.000001; if (fn_erg > 999) break;}
			if(sw==13)while(1/tanh(fn_erg) > wert) {fn_erg += 0.000001; if (fn_erg > 999) break;}
			if(sw==14)while(floor(1000000*(1/sinh(fn_erg))) != floor(1000000*wert)) {fn_erg += 0.000001; if (fn_erg > 999) break;}
			if(sw==15)while(floor(1000000*(1/cosh(fn_erg))) != floor(1000000*wert)) {fn_erg += 0.000001; if (fn_erg > 999) break;}
		}
		
		if( wert < 0) 
		{
			fn_erg=-0.000001;printf(" calculating...");
			if(sw ==7)while(1/tan(fn_erg) < wert) {fn_erg -= 0.000001; if (fn_erg < -999) break;}
			if(sw ==8)while(floor(1000000*(1/sin(fn_erg))) != floor(1000000*wert)) {fn_erg -= 0.000001; if (fn_erg < -999) break;}
			if(sw ==9)while(floor(1000000*(1/cos(fn_erg))) != floor(1000000*wert)) {fn_erg -= 0.000001; if (fn_erg < -999) break;}
			if(sw==10)while(sinh(fn_erg) > wert) {fn_erg -= 0.000001; if (fn_erg < -999) break;}
			if(sw==11)while(cosh(fn_erg) < fabs(wert)) {fn_erg += 0.000001; if (fn_erg > 999) break;}
			if(sw==12)while(tanh(fn_erg) > wert) {fn_erg -= 0.000001; if (fn_erg < -999) break;}
			if(sw==13)while(1/tanh(fn_erg) < wert) {fn_erg -= 0.000001; if (fn_erg < -999) break;}
			if(sw==14)while(floor(1000000*(1/sinh(fn_erg))) != floor(1000000*wert)) {fn_erg -= 0.000001; if (fn_erg < -999) break;}
			if(sw==15)while(floor(1000000*(1/cosh(fn_erg))) != floor(1000000*fabs(wert))) {fn_erg += 0.000001; if (fn_erg > 999) break;}
		}
		printf("\r                                                           ");
		if(sw ==7)printf("\rACT%.3f", wert);
		if(sw ==8)printf("\rASE%.3f", wert);
		if(sw ==9)printf("\rACE%.3f", wert);
		if(sw==10)printf("\rAHS%.3f", wert);
		if(sw==11)printf("\rAHC%.3f", wert);
		if(sw==12)printf("\rAHT%.3f", wert);
		if(sw==13)printf("\rAHG%.3f", wert);
		if(sw==14)printf("\rAHN%.3f", wert);
		if(sw==15)printf("\rAHO%.3f", wert);
	}
*/
		
	return fn_erg;
};

double zahl_0(double wert)	// ganze zahl gerundet // INTR 
{
	if(wert-floor(wert)<0.5 )  fn_erg = floor(wert);
	if(wert-floor(wert)>=0.5 ) fn_erg =  ceil(wert);

	return fn_erg;
};

double zahl_r(double wert)	// REST 
{
	if(wert<0) fn_erg = wert-ceil(wert);
	if(wert>0) fn_erg = wert-floor(wert);

	return 0;
};

double fn_red_x(double wert, int theta) // Reduktion, Querdifferenz von x
//																			// (1)RDN x 
//																			// (2)RDA x 
{
	int iLauf,stellen,vorz, maxlng=16;//
	char *zahl_, nr[2];
	double Q1=0,Q2=0;
	fn_erg=0;

	zahl_=ecvt(wert,maxlng,&stellen,&vorz);
	
	if (stellen  > 16) {printf("\n\nvalue.0 'n>16'"); exit(0);}
	
	//Reduktion,Quersumme
	if (theta==1) for(iLauf=1;iLauf<=stellen;iLauf++) {sprintf(nr,"%c",zahl_[iLauf-1]);fn_erg+=atof(nr);}
	
	//Querdifferenz,alternierende Quersumme
	if (theta==2)
	{
		for(iLauf=1;iLauf<=stellen;iLauf+=2) 
		{
			sprintf(nr,"%c",zahl_[iLauf-1]);Q1+=atof(nr);//printf("\n%.0f Q1=%.0f",atof(nr),Q1);
			sprintf(nr,"%c",zahl_[iLauf]);Q2+=atof(nr);//printf("\n%.0f Q2=%.0f",atof(nr),Q2);
		}
		fn_erg= fabs(Q1-Q2);
	}
	
	return fn_erg;
};


double variation_w(double n,double k)	// variation mit wh // VRW n,k
{	
	fn_erg= pow(n ,k);

	return 0;
};

double variation_(double n,double k)	// variation ohne wh (basic: als permutation beschrieben) // NPR n,k oder VR_ n,k
{
	long double n_=1, k_=1, iLauf;

	if (n<k) { printf("\n\ndesign.0 'n<m'");exit(0); } //n<m
	
	for(iLauf = 1; iLauf <= n; iLauf++) n_ *= iLauf;
	for(iLauf = 1; iLauf <= n-k; iLauf++) k_ *= iLauf;
	
	fn_erg= n_ / k_;

	return fn_erg;
};

double permutation_(double n)	// permutation zu 1 Klasse n // PM_ n
{
	int iLauf;
	fn_erg=1;
	
	for(iLauf = 1; iLauf <= n; iLauf++) fn_erg *= iLauf;

	return 0;
};

double permutation_k(double wert[100], int nk)	// permutation von n zu m klassen k1,k2,...,km // PMW n,k1,k2...km
{
	int iLauf, jLauf;
	double  pm_[100];

	for(jLauf = 1; jLauf <=nk; jLauf++)
	{	
		pm_[jLauf]=1;for(iLauf = 1; iLauf <= wert[jLauf]; iLauf++) pm_[jLauf] *= iLauf;
	}

	pm_[nk+1] = 1;for(iLauf = 2; iLauf <= nk; iLauf++) pm_[nk+1] *= pm_[iLauf];
	
	fn_erg = pm_[1]/pm_[nk+1];
	
	return fn_erg;
};

double kombination_(double n,double k)	// kombination ohne wh (permutation zu 2 klassen) // NCR n,k oder KM_ n,k
{
	long double n_=1, n_k=1, k_=1, iLauf;

	if (n<k) { printf("\n\ndesign.0 'n<m'");exit(0); } //n<m
	
	for(iLauf = 1; iLauf <= n; iLauf++) n_ *= iLauf;
	for(iLauf = 1; iLauf <= k; iLauf++) k_ *= iLauf;
	for(iLauf = 1; iLauf <= n-k; iLauf++) n_k *= iLauf;
	
	fn_erg= n_ / (k_ * n_k);

	return fn_erg;
};

double kombination_w(double n, double k)	// kombination mit wh  // KMW n,k
{
	long double n_1=1, n_k1=1, k_=1, iLauf;
	
	for(iLauf = 1; iLauf <= (n+k-1); iLauf++) n_k1 *= iLauf;
	for(iLauf = 1; iLauf <= k; iLauf++) k_ *= iLauf;
	for(iLauf = 1; iLauf <= n-1; iLauf++) n_1 *= iLauf;
	
	fn_erg= n_k1 / (k_ * n_1);
	
	//rundung (fliesskommainkonsistenz bei extrem hohen zahlenwerten)
	if(fn_erg-floor(fn_erg)>=0.5) fn_erg = ceil(fn_erg);
	if(fn_erg-floor(fn_erg)<0.5) fn_erg = floor(fn_erg);

	return fn_erg;
};

double vzeichen(double wert)	// vorzeichen des arguments // SGN 
{
	if(wert  > 0) fn_erg=  1;
	if(wert  < 0) fn_erg= -1;
	if(wert == 0) fn_erg=  0;
	
	return fn_erg;
};

double log_x(double basis_x,double wert)	// logarithmus zur basis x // LGX x,y
{
	/*//näherungsverfahren
	fn_erg=1;
	if(basis_x <= wert) while(pow(basis_x, fn_erg) < wert-0.0001) fn_erg += 0.0001;
	if(basis_x >  wert) while(pow(basis_x, fn_erg) > wert) fn_erg -= 0.0001;
	*/

	fn_erg= (1/log(basis_x))*log(wert);
	
	return 0;
};

double fisher_z(double wert,int mode)	// Fisher Z // FZR r / RFZ z
{
	if(mode == 1 &&  (wert >= 1 || wert <= -1) ){printf ("\n\nvalue.0 '-1<r<1'\n"); exit(0);}
	
	if (mode == 1) fn_erg = 0.5 * log( (1 + wert) / (1 - wert));
	if (mode == 2) {wert  = 2*wert; fn_erg = (pow(fn_const(1),wert ) - 1) / (pow(fn_const(1),wert ) + 1);}	
	
	return fn_erg;
};

double fn_sfz(double n)	// SD zu Fishers Z //SFZ n
{	
	fn_erg= sqrt(1/(n-3));
	return 0;
};

double fn_gfz(double  wert[100], int n) // Gemitteltes Fisher Z (bei unterschiedlichem nr), GFZ Z1,nr1, ... ,Zk,nrk
{
	int iLauf;
	double Z_1=0, Z_2=0;
	
	for(iLauf=1; iLauf<n; iLauf+=2) 
	{
		 Z_1+= wert[iLauf]*(wert[iLauf+1]-3); Z_2+= wert[iLauf+1]-3;
	}	
		
	fn_erg= Z_1/Z_2;		

	return 0;
};

double fn_frpz(double wert[100], int sw) // Korrelationskoeffizienten r, rxy.B zu Niveau pa2 //
//                                                                                           // RPZ pa2, n
//                                                                                           // KRP pa2, n, k
{
	double z_; 
	                          z_=zp_funktion(1-wert[1]/2);
	if(sw==1) fn_erg=fisher_z(z_*sqrt(1/(wert[2]-3)),2);
	if(sw==2) fn_erg=fisher_z(z_*sqrt(1/(wert[2]-3-(wert[3]-2))),2);
	
	return fn_erg;
};


double fn_amg(double  wert[100], int n) // Gewichtetes Arithmetisches Mittel, AMG x1,n1, ... ,xk,nk
{
	int iLauf;
	double n_=0;
	fn_erg=0;
	
	for(iLauf=1; iLauf<n; iLauf+=2) //summierung
	{
		fn_erg+= wert[iLauf]*wert[iLauf+1]; n_+= wert[iLauf+1];		
	}

	fn_erg = fn_erg/n_;//AMG mittelung

	return 0;
};

double stat_theta(double wert[100], double n, int theta)	// Harmonisches Mittel(0), HM_ x1,x2, ... ,xn
														// Arithmetisches Mittel(1), AM_ x1,x2, ... ,xn
														// Summe(2)  SUM  x1,x2, ... ,xn
														// Standardabweichung(3) SD  x1,x2, ... ,xn
														// Varianz(4)  VA_  x1,x2, ... ,xn
														// Produktsumme(5)  PSUM  x1,x2, ... ,xn
														// Geometrisches Mittel(6)  GM_  x1,x2, ... ,xn
													    // Schrausser's d(7)  D__  x1,x2, ... ,xn
														// DvarO(8) DVARO  x1,x2, ... ,xn
														// Populations-Standardabweichungs-Schätzung(9) SDG  x1,x2, ... ,xn
														// Populations-Varianz-Schätzung(10)  VAG  x1,x2, ... ,xn
														// Geschätzter Standardfehler des Mittelwertes(11)  SMG  x1,x2, ... ,xn
														// Summe der Quadrate (12) QSUM x1, x2, ... , xn
														// Summe der Produkte xy (13)  XSUM x1,y1 x2, y2 ... , xn, yn
														// Arithmetisches Mittel von xy (14)  AMX x1,y1 x2, y2 ... , xn, yn
														// Variationskoeffizient v (15) SDV x1, x2, ... , xn
{
	int iLauf, ind1=1, ind2=2; 
	double sd, sd_sum=0, pw, n1=0, x_;
	
	if(theta<5 || theta >6) 
	{
		fn_erg=0;
		
		for(iLauf=1; iLauf<=n; iLauf++) //summierung
		{
			if(theta == 0)          fn_erg += 1/wert[iLauf];
			if(theta >= 1  && 
			   theta <  12 || 
			   theta == 15  )       fn_erg += wert[iLauf];
			
			if(theta == 12)         fn_erg += pow(wert[iLauf],2);
		
			if(theta == 13 || 
			   theta == 14  )     { fn_erg += wert[ind1]*wert[ind2]; ind1+=2; ind2+=2;}
			

		
		}
		
		if(theta==0) fn_erg = n/fn_erg;//HM mittelung
		
		if(theta==1) fn_erg = fn_erg/n;//AM mittelung
		
		if(theta==15) x_ = fn_erg/n;//AM zu v

		if(theta==14) fn_erg = fn_erg/(n/2);//AM xy mittelung

		if(theta!=12
		&& theta!=13
		&& theta!=14)
		if(theta==3 ||  theta== 4 || theta>=7)//sd / pop var schätzer
		{
			fn_erg = fn_erg/n;
			for(iLauf=1; iLauf<=n; iLauf++) 
			{
				if(theta==3 || theta==9  ||
				  theta== 4 || theta==10 || theta==11 || theta==15) {sd=fn_erg - wert[iLauf]; sd_sum += pow(sd,2);}
				
				if(theta==7 ||
				   theta==8) {sd=fn_erg - wert[iLauf]; sd_sum += fabs(sd); if(sd != 0) n1++;}
			}

			if(theta==3 || theta==9 || theta==15) fn_erg = pow(sd_sum/n,0.5);
			if(theta==9) fn_erg = sqrt( pow(fn_erg,2) *(1.0*n/(n-1)));

			if(theta==4 || theta==10 || theta==11) fn_erg = sd_sum/n;
			if(theta==10|| theta==11) fn_erg = fn_erg *(1.0*n/(n-1));
			if(theta==11) fn_erg = sqrt(fn_erg /n);
			
			if(theta==7 ||
			   theta==8) fn_erg = sd_sum/n1;
			
			if(theta==8) {fn_erg=fn_erg/0.7955556; fn_erg = pow(fn_erg,0.5);}
		}
	}

	if(theta==5 || theta==6) 
	{
		fn_erg=1;for(iLauf=1; iLauf<=n; iLauf++) fn_erg *= wert[iLauf];//produktsumme

		if(theta==6) {pw=1.0/n;fn_erg = pow(fn_erg,pw);}//gm
	}

	if(theta==15) fn_erg /= x_; //v

	return fn_erg;
};

double stat_thetax(double wert[100], int theta)	// Varianz(1), VAX x,x2
                                                // Geschätzter Standardfehler des Mittelwertes (2), SMX s,n
												// Kovarianz (3), COX x,y, xy
												// Korrelation(4), KOX x,y,x2,y2,xy
												// Geschätzte Populationsstandardabweichnung(5), SDX s,n
												// SD von geschätzter Populations-SD(6), GSD sg,n
												// SD von geschätzter Populations-VA(7), GVA s2g,n
												// SD vom geschätzten Standardfehler des Mittelwertes (8), GSM smg,n
{
	double n_, s1_, s2_;

    n_= wert[2];
	
	if (theta==1) fn_erg= wert[2]-pow(wert[1],2);
	if (theta==2) fn_erg= sqrt( (pow(wert[1],2)*(n_/(n_-1)))/n_  );
	if (theta==3) fn_erg= wert[3]-(wert[1]*wert[2]);
	if (theta==4) 
	{ 
		s1_=wert[3]-pow(wert[1],2); 
		s2_=wert[4]-pow(wert[2],2);  
		fn_erg= ( wert[5] - (wert[1]*wert[2]) ) / ( sqrt(s1_)*sqrt(s2_) );
	}
	if (theta==5) fn_erg= sqrt( pow(wert[1],2) * (n_/(n_-1)) );
	if (theta==6) fn_erg= sqrt( pow(wert[1],2) / (n_/(n_-1)) );
	if (theta==7) fn_erg= sqrt( wert[1] / (n_/(n_-1)) );
	if (theta==8) fn_erg= sqrt( (pow(wert[1],2)*n_) / (n_/(n_-1)) );

	return 0;
};

double stat_thetaz(double wert[100], double n, int sw)	// z-wert Berechnungen // 
//                                                                         // z-Wert von a zu x             (1) Z_W a, x1, x2, ... , xn
//                                                                         // z-Wert von a bei x und s      (2) Z__ a, x, s
//                                                                         // schiefe zu x                  (3) SCH x1, x2, ... , xn
//                                                                         // breite zu x                   (4) EXZ x1, x2, ... , xn
//                                                                         // z zur schiefe                 (5) ZSH x1, x2, ... , xn
//                                                                         // z zur breite                  (6) ZEX x1, x2, ... , xn
//                                                                         // Populations z-Wert von a zu x (7) Z_W a, x1, x2, ... , xn
//                                                                         // Populations schiefe zu x      (8) SHP x1, x2, ... , xn
//                                                                         // Populations breite zu x       (9) EZP x1, x2, ... , xn
{
	int iLauf;
	double vektor[100], am_, s_, sum_=0, sum2_=0;

	if(sw==1 || sw==7)//Z_W, Z_P
	{
		for(iLauf=1;iLauf<=n-1;iLauf++) vektor[iLauf]=wert[iLauf+1];
	
		am_= stat_theta(vektor,n-1,1);
		if(sw==1 ) s_ = stat_theta(vektor,n-1,3);
		if( sw==7) s_ = stat_theta(vektor,n-1,9);

		fn_erg=(wert[1]-am_)/s_;
	}

	if(sw==2)fn_erg=(wert[1]-wert[2])/wert[3];//Z__

	if(sw==3 || sw==4 || sw==5 || sw==6) //SCH, EXZ
	{
		am_= stat_theta(wert,n,1);
		s_ = stat_theta(wert,n,3);
		
		if(sw==3 || sw==5) for(iLauf=1;iLauf<=n;iLauf++) sum_+=pow((wert[iLauf]-am_)/s_,3);
		if(sw==4 || sw==6) for(iLauf=1;iLauf<=n;iLauf++) sum_+=pow((wert[iLauf]-am_)/s_,4);
		
                                   fn_erg=  sum_/n;
		if(sw==4 || sw==6) fn_erg= fn_erg -3;
	}
	
	if(sw==5 || sw==6) //ZSH, ZEX
	{
		fn_erg=fn_erg/((sw-4)*sqrt(6/(1.0*n)));
	}

	if(sw==8) //SHP
	{
		am_= stat_theta(wert,n,1);
		s_ = stat_theta(wert,n,9);
		for(iLauf=1;iLauf<=n; iLauf++) sum_+=pow(wert[iLauf]-am_,3);
		
		fn_erg= (n * sum_) / ((n-1)*(n-2)*pow(s_,3));
	}

	if(sw==9) //EZP
	{
		am_= stat_theta(wert,n,1);
		s_ = stat_theta(wert,n,9);
		for(iLauf=1;iLauf<=n; iLauf++){sum_+=pow(wert[iLauf]-am_,4);sum2_+=pow(wert[iLauf]-am_,2);}

		fn_erg= (n *(n+1)* sum_-3*sum2_*sum2_*(n-1)) / ((n-1)*(n-2)*(n-3)*pow(s_,4));
	}

	return 0;
};

double stat_thetaz1(double wert, int sw)	// Normtransformationen, s zu Schiefe und Breite//
//                                                                     // s zur schiefe            (1) SSH n
//                                                                     // s zur breite             (2) SEX n
//                                                                     // Standardnorm u z-wert    (3) SW_ z
//                                                                     // IQ-Norm zu z-wert        (4) IQ_ z
//                                                                     // IQ-Norm f. Kinder zu z   (5) IQK z
//                                                                     // C-Norm zu z-wert         (6) CW_ z
//                                                                     // Sten-Norm zu z-wert      (7) STN z
//                                                                     // Standardnotenwert zu z   (8) SN_ z
//                                                                     // Flächentransf zu z       (9) T__ z
//                                                                     // Stanine-Norm zu z       (10) S__ z
//                                                                     // Wertpunkt zu z          (11) WP_ z
//                                                                     // Prozentrang PR zu z     (12) PR_ z
{
	if(sw==1 || sw==2) fn_erg = sw*sqrt(6/wert);  //SSH, SEX#

	if(sw==3)  fn_erg= 100+wert*10;  //SW_
	if(sw==4)  fn_erg= 100+wert*15;  //IQ_
	if(sw==5)  fn_erg= 100+wert*17;  //IQK
	if(sw==6)  fn_erg=   5+wert*2;   //CW_
	if(sw==7)  fn_erg= 5.5+wert*2;   //STN
	if(sw==8)  fn_erg=   3-wert;     //SN_
	if(sw==9)  fn_erg=  50+wert*10;  //T__
	if(sw==10) fn_erg=   5+wert*1.96;//S__
	if(sw==11) fn_erg=  10+wert*3;   //WP_
	if(sw==12) fn_erg= (pz_funktion(wert))*100; //PR_

	return 0;
};


//Lineare Regressionsfunktion (f(x=y)=bx+a, b=B1y_, a=B0y_; f(y=x)=by+a, b=B1x_, a=B0x_;) 
double fn_lin_reg(double wert[100]/*Regressionsmatrix R(x,y)*/, double n/*nR*/, int koef)
																						// Korrelation(1), KOR x11,x12, ... ,xn1,xn2
																						// Kovarianz(2), COV x11,x12, ... ,xn1,xn2
																						// Determinationskoeffizient(3), DET x11,x12, ... ,xn1,xn2
																						// Redundanz(4), RED x11,x12, ... ,xn1,xn2
																						// Regressionskoeffizent ayx (5), AYX x11,x12, ... ,xn1,xn2
																						// Regressionskoeffizent byx (6), BYX x11,x12, ... ,xn1,xn2
																						// Regressionskoeffizent axy (7), AXY x11,x12, ... ,xn1,xn2
																						// Regressionskoeffizent bxy (8), BXY x11,x12, ... ,xn1,xn2
                                                                                        // Regressionskoeffizent ryx (9), BXY x11,x12, ... ,xn1,xn2
{
	int iLauf; 
	double sum_x=0 ,sum_y=0, sum_y2=0, sum_x2=0, sum_xy=0, am_x, am_y, s2_x=0, s2_y=0, s_x, s_y, r_=0;
	double B1x_, B1y_, B0x_, B0y_;  
	
	for (iLauf = 1; iLauf <= n; iLauf+=2)// summierng x, y, y2, xy über n
	{
		sum_x  +=     wert[iLauf]; 
		sum_y  +=     wert[iLauf+1]; 
		sum_x2 += pow(wert[iLauf],2);
		sum_y2 += pow(wert[iLauf+1],2); 
		sum_xy +=     wert[iLauf]*wert[iLauf+1];
	}
	
	//mittelung
	am_x = sum_x / (n/2);
	am_y = sum_y / (n/2);

	for (iLauf = 1; iLauf <= n; iLauf+=2)//standardabweichungsberechnung (nb s unkorrigiert nach df)
	{
		s2_x  +=    pow(wert[iLauf]-am_x,2);
		s2_y  +=    pow(wert[iLauf+1]-am_y,2); 
	}

	s_x = sqrt(s2_x/(n/2));
	s_y = sqrt(s2_y/(n/2));

	//beta gewichte
	B1y_ = (((n/2) * sum_xy) - (sum_x * sum_y)) / (((n/2) * sum_x2) - pow(sum_x,2)); // byx
	B1x_ = (((n/2) * sum_xy) - (sum_x * sum_y)) / (((n/2) * sum_y2) - pow(sum_y,2)); // bxy
	
	if(koef==6) fn_erg = B1y_;//BYX / b / b1 / byx / x -> y / f(x) / y = bx
	if(koef==8) fn_erg = B1x_;//BXY / b / b1 / bxy / y -> x / f(y) / x = by
	
	B0y_ = am_y - (B1y_ * am_x);// ayx
	B0x_ = am_x - (B1x_ * am_y);// axy
	
	if(koef==5) fn_erg = B0y_;//AYX / a / b0 / ayx / x -> y / f(x) / y = x + a
	if(koef==7) fn_erg = B0x_;//AXY / a / b0 / axy / y -> x / f(y) / x = y + a
	
	if(koef==1 || koef==3 || koef==4 || koef==9)
	for (iLauf = 1; iLauf <= n; iLauf+=2)//korrelationskoeffizient
	{
		r_ += ((wert[iLauf]-am_x) /s_x) * ((wert[iLauf+1]-am_y) /s_y);	
	}

	if(koef==2)for (iLauf = 1; iLauf <= n; iLauf+=2)//kovarianz
	{
		r_ += (wert[iLauf]-am_x) * (wert[iLauf+1]-am_y);	
	}

	if(koef==1 || koef==2 || koef==3 || koef==4 || koef==9) fn_erg = r_ /(n/2);

	if(koef==3) fn_erg = pow(fn_erg,2); //determinationkoeffizient
	if(koef==4) fn_erg = 100*(pow(fn_erg,2)); //redundanz von y
	if(koef==9) fn_erg = 1/fn_erg; //ryx

	return fn_erg;
};

double fn_pkr(double wert[100], int sw)// Partial-Korrelation  // 
//                                                             // Partial-Korrelation (1) PKR rxy,rxz,ryz
//                                                             // Semipartial-Korrelation(2) PKS rxy,rxz,ryz
//                                                             // Partial-, Multiple Partial-Korrelation (3) PKRB RxyB,RxB / PKRB RyAB,RyB
//                                                             // Semipartial-, Multiple Semipartial-Korrelation(4) PKSB RxyB,RxB /PKSB Ryx,B,RyB
{
	double R1_, R2_;

	if(sw>=3){ R1_= pow(wert[1],2);	R2_= pow(wert[2],2);}
	
	if(sw==1) {fn_erg= (wert[1] - wert[2]*wert[3]) / ( sqrt(1-pow(wert[2],2)) * sqrt(1-pow(wert[3] ,2)) );}
	if(sw==2) {fn_erg= (wert[1] - wert[2]*wert[3]) / ( sqrt(1-pow(wert[2],2)) );}
	
	if(sw==3) fn_erg= sqrt((R1_-R2_)/(1-R2_));
	if(sw==4) fn_erg= sqrt(R1_-R2_);
	
	return 0;
};


double fn_zkr(double wert[100])// z-wert zur Partial-Korrelation // ZKR rxy.B, n, k
{
	double Z_, n_, k_;

	Z_= 0.5 * log( (1 + wert[1]) / (1 - wert[1]));
	n_=wert[2];
	k_=wert[3];
	
	fn_erg = Z_ * sqrt(n_-3-(k_-2));	
	
	return 0;
};

double fn_fmpk(double wert[100])// F-wert zur Multiplen Partial und Semipartial-Korrelation // FMP Ry,(AB), RyB, n, k, p 
{
	double R1_, R2_, n_, k_, p_;

	R1_= pow(wert[1],2);
	R2_= pow(wert[2],2);
	n_=wert[3];
	k_=wert[4];
	p_=wert[5];

	fn_erg = ((R1_-R2_)/k_) / ( (1-R1_)/(n_-k_-p_-1) );	
	
	return 0;
};

double fn_trw(double wert,double n)// t zu Korrelation r bei n // TRW r,n
{
	fn_erg = (wert*sqrt(n-2))/sqrt(1-pow(wert,2));	
	
	return fn_erg;
};

double fn_zrr(double wert1,double wert2,double n1,double n2)// Korrelationsdifferenz z-Wert r1-r2 bei n1, n2 // ZRR r1,r2,n1,n2
{
	double Z1, Z2, s12;	
	
	Z1= 0.5 * log( (1 + wert1) / (1 - wert1)); Z2= 0.5 * log( (1 + wert2) / (1 - wert2));
	
	s12= sqrt((1/(n1-3))+(1/(n2-3)));

	fn_erg= (Z1-Z2)/s12;

	return 0;
};

double fn_tkv(double wert[100], double n_)// t-Wert zur Varianzdifferenz korrelierter vektoren // TKV x11, x12, ... , xn1, xn2
{
	int iLauf, n1=0;
	double vektor_1[55], vektor_2[55], r2_, s2_1, s2_2;

	for (iLauf = 1; iLauf <= n_; iLauf+=2)
	{
		         n1++; 
		vektor_1[n1]=wert[iLauf]; 
		vektor_2[n1]=wert[iLauf+1];
	}

	s2_1= stat_theta(vektor_1, n1, 4);
	s2_2= stat_theta(vektor_2, n1, 4);
	r2_=  fn_lin_reg(wert, 2*n1, 3);

	fn_erg= ((s2_1-s2_2)*sqrt(n1-2)) / (2* sqrt((s2_1*s2_2)*(1-r2_)));

	return 0;
};

double fn_Rc12(double wert[100])// Multipler-Korrelationskoeffizient Rc,12 // MKR r1c, r2c, r12
{
	double r1c_, r2c_, r12_;

	r1c_ = wert[1];
	r2c_ = wert[2];
	r12_ = wert[3];	

	fn_erg= sqrt( ( pow(r1c_,2) + pow(r2c_,2) - 2*r12_* r1c_* r2c_ ) / ( 1-pow(r12_,2) )  );

	return 0;
};

double fn_Rc12k(double wert[100], int n)// Multipler-Korrelationskoeffizient Rc,12...k  // MKRN b1,b2,...bk,r1c,r2c,...,rkc
{
	int iLauf;
	fn_erg=0;
	
	for (iLauf=1; iLauf<=n/2; iLauf++) fn_erg+= wert[iLauf]*wert[iLauf+n/2] ;

	fn_erg=sqrt(fn_erg);
	
	return 0;
};

double fn_bci(double wert[100])// Rohwertgewicht bci  // MBC sc, bi, si
{
	fn_erg= wert[2]*(wert[1]/wert[3]);
	return 0;
};

double fn_ac12k(double wert[100], int n)// Multipler-Regressionskoeffizient ac,12...k  // MAC xc,sc,b1,x1,s1,...,bk,xk,sk
{
	int iLauf;
	double xc_, sc_;
	fn_erg=0;

	xc_=wert[1];
	sc_=wert[2];
	
	for (iLauf=3; iLauf<=n; iLauf+=3) fn_erg+= (wert[iLauf]*(sc_/wert[iLauf+2]))*wert[iLauf+1];

	fn_erg=xc_-fn_erg;
		
	return 0;
};

double fn_skm(double wert[100])// Schrumpfungskorrektur zu R // SKM R, n
{
	double R_, n_, k_; 
	
	//int n_, k_; 

	R_=wert[1];
	n_=wert[2];
	k_=wert[3];

	fn_erg= 1-((n_-3)/(n_-k_-2)) *( (1-pow(R_,2))+2/(n_-k_)*pow((1-pow(R_,2)),2)  )  ;

	 // fn_erg= (1-((n_-3)/(n_-k_-2))) *( (1-pow(R_,2))+2/(n_-k_)*pow((1-pow(R_,2)),2)  )  ;

	return 0;
};

double fn_fmkr(double wert[100])// F-wert zum Multiplen-Korrelationskoeffizienten // FMK R, n, k
{
	double R_, n_, k_; 

	R_=wert[1];
	n_=wert[2];
	k_=wert[3];
	
	fn_erg=  (pow(R_,2)*(n_-k_-1)) / ((1-pow(R_,2))*k_)  ;
	
	return 0;
};



double fn_tbmr(double wert[100])// t-wert zum Beta-Gewicht bi // TBM bi, rii, R, n, k
{
	double bi_, rii_, R_, n_, k_; 

	bi_ =wert[1];
	rii_=wert[2];
	R_  =wert[3];
	n_  =wert[4];
	k_  =wert[5];
	
	fn_erg=  bi_ / sqrt( (rii_*(1-pow(R_,2)) / (n_-k_-1)) );
	
	return 0;
};

double fn_rs_(double wert[100],double n)// Rangkorrelation rs // KRS x11,x12, ... ,xn1,xn2
{
	int iLauf, jLauf, index=1, wert_sort1_i[100], wert_sort2_i[100], n_=0, hub=0, vb, vbnr1=0, vbnr2=0;
	double d2=0, wert_1[100], wert_sort1[100], min1, 
				 wert_2[100], wert_sort2[100], min2,
		 rang=1, rang_1[100], vb_rang1[100], vb_rang1_n[100], vbi1=0,
	             rang_2[100], vb_rang2[100], vb_rang2_n[100], vbi2=0,
		 vbrn=0, T=0, U=0;
	
	for (iLauf = 1; iLauf <= n; iLauf+=2) {n_++;wert_1[n_]=wert[iLauf];wert_2[n_]=wert[iLauf+1];}//vektoraufteilung

	//printf("\n");for (iLauf = 1; iLauf <= n_; iLauf++) printf("%f %f\n",wert_1[iLauf], wert_2[iLauf]);

	min1=wert_1[1]; min2=wert_2[1];
	
	for (iLauf = 1; iLauf <= n_; iLauf++)//minima
	{
		if(wert_1[iLauf]<min1)min1=wert_1[iLauf];
		if(wert_2[iLauf]<min2)min2=wert_2[iLauf];
	}
	
	wert_sort1[1] = min1;//anfangswert=minimalwert1

	for (iLauf = 1; iLauf <= n_; iLauf++)//sortierung1
	{
		for (jLauf = 0; jLauf < iLauf; jLauf++)
		{
			if (wert_1[iLauf] < wert_sort1[iLauf-jLauf])
			{
				wert_sort1[(iLauf-jLauf)+1] = wert_sort1[iLauf-jLauf]; 
				wert_sort1_i[(iLauf-jLauf)+1] = wert_sort1_i[iLauf-jLauf];
				hub++;	
			
			}	
		}
		wert_sort1[(iLauf+1)-hub] = wert_1[iLauf]; 
		wert_sort1_i[(iLauf+1)-hub] = index;
		hub=0;index++;
	}

	index=1;

	for (iLauf = 2; iLauf <= n_+1; iLauf++) wert_sort1[iLauf-1]=wert_sort1[iLauf];  //laufindexkorrektur1
	wert_sort1[iLauf-1]=0;

	wert_sort2[1] = min2;//anfangswert=minimalwert2

	for (iLauf = 1; iLauf <= n_; iLauf++)//sortierung2
	{
		for (jLauf = 0; jLauf < iLauf; jLauf++)
		{
			if (wert_2[iLauf] < wert_sort2[iLauf-jLauf])
			{
				wert_sort2[(iLauf-jLauf)+1] = wert_sort2[iLauf-jLauf]; 
				wert_sort2_i[(iLauf-jLauf)+1] = wert_sort2_i[iLauf-jLauf];
				hub++;	
			}	
		}
		wert_sort2[(iLauf+1)-hub] = wert_2[iLauf];
		wert_sort2_i[(iLauf+1)-hub] = index;
		hub=0;index++;
	}

	for (iLauf = 2; iLauf <= n_+1; iLauf++) { wert_sort2[iLauf-1]=wert_sort2[iLauf];wert_sort2_i[iLauf-1]=wert_sort2_i[iLauf];}//laufindexkorrektur2
	wert_sort2[iLauf-1]=0;wert_sort2_i[iLauf-1]=0;

	for (iLauf = 1; iLauf <= 100; iLauf++) {vb_rang1[iLauf]=0; vb_rang1_n[iLauf]=1;}//vektoreninitialisierung1
	
	rang_1[1]=1;vb=0;
	for (iLauf = 1; iLauf <= n_; iLauf++) //rangermittlung1
	{	
		if (wert_sort1[iLauf+1] == wert_sort1[iLauf]) //bei wertgleichheit verbundränge1
		{
			if(vb==0) {vbnr1++; vbi1--; vb_rang1[vbnr1]+=rang;}
			rang_1[iLauf]=vbi1; rang_1[iLauf+1]=vbi1;
			vb_rang1[vbnr1]+=rang+1; vb_rang1_n[vbnr1]++;
			vb=1;
		}
		rang++;
		
		if (wert_sort1[iLauf+1] != wert_sort1[iLauf]) //bei wertunterschied rangzuweisung1
		{
			rang_1[iLauf+1]=rang;
			vb=0;
		}
	}
	
	for (iLauf = 1; iLauf <= vbnr1; iLauf++) //verbundrangwertberechnung1
	{
		for (jLauf = 1; jLauf <= n_; jLauf++) 
		{
			if (rang_1[jLauf]<0)if(fabs(rang_1[jLauf])==iLauf) rang_1[jLauf]= vb_rang1[iLauf]/vb_rang1_n[iLauf];
		}
	}

	//printf("\n");for (iLauf = 1; iLauf <= n_; iLauf++) printf("%f %f %i\n",rang_1[iLauf], wert_sort1[iLauf], wert_sort1_i[iLauf+1]);
	
	rang=1;

	for (iLauf = 1; iLauf <= 100; iLauf++) {vb_rang2[iLauf]=0; vb_rang2_n[iLauf]=1;}//vektoreninitialisierung2
	
	rang_2[1]=1;vb=0;
	for (iLauf = 1; iLauf <= n_; iLauf++) //rangermittlung2
	{	
		if (wert_sort2[iLauf+1] == wert_sort2[iLauf]) //bei wertgleichheit verbundränge2
		{
			if(vb==0) {vbnr2++; vbi2--; vb_rang2[vbnr2]+=rang;}
			rang_2[iLauf]=vbi2; rang_2[iLauf+1]=vbi2;
			vb_rang2[vbnr2]+=rang+1; vb_rang2_n[vbnr2]++;
			vb=1;
		}
		rang++;
		
		if (wert_sort2[iLauf+1] != wert_sort2[iLauf]) //bei wertunterschied rangzuweisung2
		{
			rang_2[iLauf+1]=rang;
			vb=0;
		}
	}
	
	for (iLauf = 1; iLauf <= vbnr2; iLauf++) //verbundrangwertberechnung2
	{
		for (jLauf = 1; jLauf <= n_; jLauf++) 
		{
			if (rang_2[jLauf]<0)if(fabs(rang_2[jLauf])==iLauf) rang_2[jLauf]= vb_rang2[iLauf]/vb_rang2_n[iLauf];
		}
	}

	//printf("\n");for (iLauf = 1; iLauf <= n_; iLauf++) printf("%f %f %i\n",rang_2[iLauf], wert_sort2[iLauf], wert_sort2_i[iLauf]);
	
	for (iLauf = 1; iLauf <= vbnr1; iLauf++) vbrn+=vb_rang1_n[iLauf];//verbundranganzahlberechnung
	for (iLauf = 1; iLauf <= vbnr2; iLauf++) vbrn+=vb_rang2_n[iLauf];
	
	//printf("\nn=%.0f Verbundraenge %.1f%%\n",vbrn, 100.0*(vbrn/n));printf("\n");
	
	for (iLauf = 1; iLauf <= n_; iLauf++)
	{
		for (jLauf = 1; jLauf <= n_; jLauf++)
		{
			if(wert_sort1_i[iLauf+1]==wert_sort2_i[jLauf])
			{
				d2+=pow((rang_1[iLauf]-rang_2[jLauf]),2);
				//printf("i%ir1=%f i%ir2=%f d2=%f\n",wert_sort1_i[iLauf+1],rang_1[iLauf], 
				//								   wert_sort2_i[jLauf], rang_2[jLauf], pow((rang_1[iLauf]-rang_2[jLauf]),2));
			}
		}
	}
	
	if(vbrn/n < 0.2)//verbundranganteil < 20%
	{
		fn_erg= 1-((6*d2)/((n/2)*(pow((n/2),2)-1)));
	}
	
	if(vbrn/n >= 0.2)//verbundranganteil >= 20%
	{
		for(iLauf= 1; iLauf <= vbnr1; iLauf++) T+=(pow(vb_rang1_n[iLauf],3)-vb_rang1_n[iLauf])/12;
		for(iLauf= 1; iLauf <= vbnr2; iLauf++) U+=(pow(vb_rang2_n[iLauf],3)-vb_rang2_n[iLauf])/12;
		//printf("\nT=%f U=%f n=%f d2=%f\n",T,U,n,d2);
		fn_erg= (2*((pow((n/2),3)-(n/2))/12) - T - U - d2 ) /
				(2* sqrt( (((pow((n/2),3)-(n/2))/12)-T) *  (((pow((n/2),3)-(n/2))/12)-U) ));
	}

	return 0;
};

double fn_t_uv(double wert[100],double n, int theta)// t-wert  // 
//															   // unverbundene stpr(1), TU_ x1,g1,x2,g2,... ,xn,gn; g(1,2)
//															   //   verbundene stpr(3), TV_ x11,x12,... ,xn1,xn2																
{
	int iLauf;
	double sum_x1=0, sum_x2=0, n1=0, n2=0, am_x1=0, am_x2=0, s12;//,s1, s2, c, dfcor 
	double d=0, sd=0; 
	
	for (iLauf = 1; iLauf <= n; iLauf+=2)// 
	{
		if(theta<3 )if(wert[iLauf+1]==1) {sum_x1+= wert[iLauf];n1++;}
		if(theta<3 )if(wert[iLauf+1]==2) {sum_x2+= wert[iLauf];n2++;}
		
		if(theta==3 )d+=wert[iLauf]-wert[iLauf+1];
	}	
	if(theta<3 ){am_x1= sum_x1/n1; am_x2= sum_x2/n2; sum_x1=sum_x2=0;}

	if(theta==3 )d=d/(n/2);

	for (iLauf = 1; iLauf <= n; iLauf+=2)// 
	{
		if(theta<3 )if(wert[iLauf+1]==1) sum_x1+= pow(wert[iLauf]-am_x1, 2);
		if(theta<3 )if(wert[iLauf+1]==2) sum_x2+= pow(wert[iLauf]-am_x2, 2);
		
		if(theta==3 )sd+=pow(wert[iLauf]-wert[iLauf+1]-d,2);
	}
	
	/*
	if(theta==2)
	{
		s1=sum_x1/(n1*(n1-1)); s2=sum_x2/(n2*(n2-1)); 	
		c= s1/(s1+s2);
		dfcor= 1/( (pow(c,2)/(n1-1))+((pow(1-c,2))/(n2-1))  );
	}
	*/

	if(theta<3 ) s12= sqrt((sum_x1+sum_x2)/((n1-1)+(n2-1)))*sqrt((1/n1)+(1/n2));

	if(theta==3 ) sd= sqrt(sd/((n/2)-1)); sd= sd/sqrt(n/2);
	
	if(theta==1 ) fn_erg= (am_x1-am_x2)/s12;
	//if(theta==2) fn_erg= dfcor;
	
	if(theta==3 ) fn_erg= d/sd;

	return fn_erg;
};

double fn_t_ux(double wert[100], int sw)// t-wert aus mittelwerten  // 
//												   // unverbundene stpr(1), TUX x1,s1,n1,x2,s2,n2
//												   // 1 stpr (2),  TT_ x,s,n,y												
{
	double s12_, n1_, n2_, s1_, s2_;
	n1_= wert[3];
	n2_= wert[6];
	s1_=pow(wert[2],2)*n1_;
	s2_=pow(wert[5],2)*n2_;

	s12_= sqrt( (s1_+s2_) / ((n1_-1)+(n2_-1)) ) * sqrt(1/n1_+1/n2_);

	//if(sw==1) fn_erg= (wert[1]-wert[4]) /  sqrt( pow(wert[2],2)/(wert[3]-1) + pow(wert[5],2)/(wert[6]-1) ); //siehe spss 2.t-wert
	if(sw==1) fn_erg= (wert[1]-wert[4]) / s12_ ;

	if(sw==2) fn_erg= (wert[1]-wert[4])/sqrt( pow(wert[2],2)/(wert[3]-1) );

	return 0;
}


double fn_sig(double wert)// 2 seitiges Signifikanzniveau von p zu z-, t-wert// SIG p											
{
	if(wert>0.5) fn_erg = 2*(1-wert);
	if(wert<=0.5) fn_erg = 2*wert;

	return 0;
}


double fn_korr_pbis(double wert[100],double n, int theta)// biserale korrelation  // 
//															   // punktbiserale korrelation rpb(1), KPB y1,x1,y2,x2,... ,yn,xn; x(1,2)														
//															   // biserale korrelation rbis(3), KBS y1,x1,y2,x2,... ,yn,xn; x(1,2)
//															   // s zur biseralen korrelation rbis(4), SBS y1,x1,y2,x2,... ,yn,xn; x(1,2)
//															   // z-wert biseralen korrelation rbis(5), ZBS y1,x1,y2,x2,... ,yn,xn; x(1,2)	
//															   // rpb/r -> rbis (6), BSK r,n1,n2
{
	int iLauf;
	double sum_x1=0, sum_x2=0, n1=0, n2=0, am_x1=0, am_x2=0, s_=0, s_2=0, rpb, x_rpb, n_;
	
	if(theta < 6)
	{
		for (iLauf = 1; iLauf <= n; iLauf+=2)// 
		{
			if(wert[iLauf+1]==1) {sum_x1+= wert[iLauf];n1++;}
			if(wert[iLauf+1]==2) {sum_x2+= wert[iLauf];n2++;}
			s_+=wert[iLauf];	
			s_2+=pow(wert[iLauf],2);
		}
		am_x1= sum_x1/n1; am_x2= sum_x2/n2; s_= sqrt(  ( s_2-(pow(s_,2))/(n/2) )/(n/2)  );

		if (theta<=2) n_= sqrt((n1*n2)/(pow(n/2,2)));
		if (theta>=3) n_= n1*n2/( pow(n/2,2)*(dz_funktion(zp_funktion( n1/(n/2)))) );
		
		rpb= ((am_x2 - am_x1)/s_) * n_;

		if (theta==4 || theta==5) x_rpb= sqrt(n1*n2)/( (dz_funktion(zp_funktion( n1/(n/2))))*(n/2)*sqrt(n/2));

		if (theta==1 || theta==3) fn_erg= rpb;
		if (theta==4) fn_erg= x_rpb;
		if (theta==5) fn_erg= rpb/x_rpb;
	}
	
	if (theta==6) fn_erg= wert[1]*sqrt(wert[2]*wert[3])/((wert[2]+wert[3])* (dz_funktion(zp_funktion( wert[2]/(wert[2]+wert[3]) ))) );
	
	return 0;
};

double fn_chi2(double wert[100],double n)// eindimensionales chi2  // EDX h1,h2,... ,hn
{
	int iLauf;
	double he=0; fn_erg= 0;
	
	for (iLauf = 1; iLauf <= n; iLauf++) he+= wert[iLauf]; he= he/n;
	for (iLauf = 1; iLauf <= n; iLauf++) fn_erg+= pow(wert[iLauf]-he,2); fn_erg = fn_erg/he;  

	return 0;
};

double fn_Q_test(double wert[100],double i)// Cochran Q Test  // CQT nT,T1,...,Tm, L1,...Ln
{
	int iLauf, m1=2;
	double T=0, T2=0, L=0,  L2=0 , m=wert[1]; 
	
	fn_erg= 0;
		 
	for (iLauf = 2; iLauf <= m+1; iLauf++) {T+= wert[iLauf];  m1++;} T= pow(T,2);
	for (iLauf = 2; iLauf <= m+1; iLauf++) T2+= pow(wert[iLauf],2);

	for (iLauf = m1; iLauf <= i; iLauf++) L+= wert[iLauf];
	for (iLauf = m1; iLauf <= i; iLauf++) L2+= pow(wert[iLauf],2);

	fn_erg=((m-1)*(m*T2-T))/(m*L-L2);

	return 0;
};

double fn_4chi2(double wert[100], int theta)// 4-Felder chi2 Verfahren // 
//                                                   // 4-Felder chi2(1) VFX a,b,c,d
//                                                   // 4-Felder chi2(2) VFYX a,b,c,d (kontinuitätskorrigiert)
//                                                   // McNemar  chi2(3) MNX b,c
//                                                   // McNemar  chi2(4) MNYX b,c (kontinuitätskorrigiert)
//                                                   // Phi-Korrelation(5) KPH a,b,c,d
//                                                   // Phi-Korrelation Max(6) KPM a,b,c,d
//                                                   // Chi2 zur Phi-Korrelation(7) XKP r,n
//                                                   // Tetrachorische-Korrelation(8) KTET a,b,c,d
//                                                   // s zur Tetrachorischen-Korrelation(9) STET a,b,c,d
//                                                   // z-Wert zur Tetrachorischen-Korrelation(10) ZTET a,b,c,d
{
	double Y=0,a,b,c,d,n,rtet,stet;

	if(theta==1 || theta==2 || theta>=5 ) 
	{
		a=wert[1]; b=wert[2]; c=wert[3]; d=wert[4];
		n=a+b+c+d; 
		
		if( ((a+b)*(a+c))/n >5 && 
			((a+b)*(b+d))/n >5 &&
			((c+d)*(a+c))/n >5 &&
			((c+d)*(b+d))/n >5    )
		{
			if(theta==1)fn_erg=(n*pow(a*d-b*c,2))/((a+b)*(c+d)*(a+c)*(b+d));
			if(theta==2)fn_erg=(n*pow(fabs(a*d-b*c)-n/2,2))/((a+b)*(c+d)*(a+c)*(b+d));//kontinuitätskorrigiert
			if(theta==5)fn_erg=(a*d-b*c)/sqrt((a+c)*(b+d)*(a+b)*(c+d));
			if(theta==6)fn_erg=sqrt( (((a+b)/n)/((c+d)/n)) * (((b+d)/n)/((a+c)/n)) );
			if(theta==8 || theta==10)
			{
				fn_erg=cos ( fn_dgrad( (180/(1+sqrt(b*c/(a*d)))), 1) );
				rtet= fn_erg;
			}

			if(theta==9 || theta==10)
			{
				fn_erg= sqrt((((a+b)/n)*((a+c)/n)*((c+d)/n)*((b+d)/n))/n) * 1/(  (dz_funktion(zp_funktion( (c+d)/n) ))  
																		       * (dz_funktion(zp_funktion( (b+d)/n) )) );
				stet= fn_erg;
			}
																					   
			if(theta==10) fn_erg= rtet/stet;

		}
		else { if(theta!=7 && theta!=2){printf("\n\ndesign.0 'fe<5'"); exit(0);}}

		if(theta==7)fn_erg=wert[2]*pow(wert[1],2);
	}

	if(theta==3 || theta==4)
	{
		b=wert[1]; c=wert[2];
		
		if (b+c>20)
		{
			if(theta==4) Y=0.5; // yates korrektur faktor
			fn_erg= (pow(fabs(b-c)-Y,2))/(b+c);
		}
		else { printf("\n\ndesign.0 'fe<10'"); exit(0);}
	}

	return 0;
};

double fn_sort(double wert[100], double n, int theta)// sortierung // 
//                                                                 // MIN(1) x1,x2,...,xn 
//                                                                 // MAX(2) x1,x2,...,xn 
//                                                                 // RNG(3) x1,x2,...,xn 
//                                                                 // RSUM(4) x1,x2,...,xn
//                                                                 // MR_(5) x1,x2,...,xn
//                                                                 // MD_(6) x1,x2,...,xn
{
	int iLauf, jLauf, hub= 0, vb, vbnr=0;
	double wert_sort[100], min, max, rang_[100], rang=1, vb_rang[100], vb_rang_n[100], vbi=0, md_;

	fn_erg=0;
	
	min=wert[1]; for (iLauf = 1; iLauf <= n; iLauf++)if(wert[iLauf]<min)min=wert[iLauf];//minimum
	max=wert[1]; for (iLauf = 1; iLauf <= n; iLauf++)if(wert[iLauf]>max)max=wert[iLauf];//maximum
	
	wert_sort[1] = min;//anfangswert=minimalwert

	for (iLauf = 1; iLauf <= n; iLauf++)//sortierung
	{
		for (jLauf = 0; jLauf < iLauf; jLauf++)
		{
			if (wert[iLauf] < wert_sort[iLauf-jLauf])
			{
				wert_sort[(iLauf-jLauf)+1] = wert_sort[iLauf-jLauf]; hub++;	
			}	
		}
		wert_sort[(iLauf+1)-hub] = wert[iLauf]; hub=0;
	}

	for (iLauf = 2; iLauf <= n+1; iLauf++)wert_sort[iLauf-1]=wert_sort[iLauf];//laufindexkorrektur
	wert_sort[iLauf-1]=0;

	//median 
	if (floor(n/2) == n/2)//n geradzahlig
	{
		for (iLauf = 1; iLauf <= n/2; iLauf++)
		{
			md_ = ( wert_sort[iLauf]+wert_sort[iLauf+1] ) /2;
		}
	}
	else
	{
		for (iLauf = 1; iLauf <= (floor((n-1)/2))+1; iLauf++)
		{
			md_ = wert_sort[iLauf];
		}
	}
	
	for (iLauf = 1; iLauf <= 100; iLauf++) {vb_rang[iLauf]=0; vb_rang_n[iLauf]=1;}//vektoreninitialisierung
	
	rang_[1]=1;vb=0;
	for (iLauf = 1; iLauf <= n; iLauf++) //rangermittlung
	{	
		if (wert_sort[iLauf+1] == wert_sort[iLauf]) //bei wertgleichheit verbundränge
		{
			if(vb==0) {vbnr++; vbi--; vb_rang[vbnr]+=rang;}
			rang_[iLauf]=vbi; rang_[iLauf+1]=vbi;
			vb_rang[vbnr]+=rang+1; vb_rang_n[vbnr]++;
			vb=1;
		}
		rang++;
		
		if (wert_sort[iLauf+1] != wert_sort[iLauf]) //bei wertunterschied rangzuweisung
		{
			rang_[iLauf+1]=rang;
			vb=0;
		}
	}
	
	for (iLauf = 1; iLauf <= vbnr; iLauf++) //verbundrangwertberechnung
	{
		for (jLauf = 1; jLauf <= n; jLauf++) 
		{
			if (rang_[jLauf]<0)if(fabs(rang_[jLauf])==iLauf) rang_[jLauf]= vb_rang[iLauf]/vb_rang_n[iLauf];
		}
	}
	
	if (theta==1) fn_erg= min;
	if (theta==2) fn_erg= max;
	if (theta==3) fn_erg= max-min;

	if (theta>=4) for(iLauf = 1; iLauf <= n; iLauf++) fn_erg+= rang_[iLauf];
	if (theta==5) fn_erg=fn_erg/n;

	if (theta==6) fn_erg=md_;

	return fn_erg;
};

double fn_U_test(double wert[100], double n, int theta)// U-Test, Biserale Rangkorrelation rbisR // 
//                                                                 // UTS_(1) x1,g1,x2,g2,... ,xn,gn; g(1,2) 
//                                                                 // SUTS(2) x1,g1,x2,g2,... ,xn,gn; g(1,2) 
//                                                                 // MUTS(3) x1,g1,x2,g2,... ,xn,gn; g(1,2) 
//                                                                 // ZUTS(4) x1,g1,x2,g2,... ,xn,gn; g(1,2)
//                                                                 // KBR(5) x1,g1,x2,g2,... ,xn,gn; g(1,2)
//                                                                 // ZBR(6) x1,g1,x2,g2,... ,xn,gn; g(1,2)
{
	int iLauf, jLauf,  n_=0, n1=0, n2=0, hub=0, vb, vbnr=0;
	double min, wert_sort[100], wert_[100], grp_sort[100], grp_[100],T1=0, T2=0, 
			rang_[100], rang=1, vb_rang[100], vb_rang_n[100], vbi=0, U, mU, sU, sUvb=0;

	for (iLauf = 1; iLauf <= n; iLauf+=2)//vektoraufteilung
	{
		n_++;wert_[n_]= wert[iLauf]; grp_[n_]= wert[iLauf+1]; 
	}
	
	min=wert[1]; for (iLauf = 1; iLauf <= n; iLauf++)if(wert[iLauf]<min)min=wert[iLauf];//minimum
	
	wert_sort[1] = min;//anfangswert=minimalwert
	for (iLauf = 1; iLauf <= n_; iLauf++)//sortierung
	{
		for (jLauf = 0; jLauf < iLauf; jLauf++)
		{
			if (wert_[iLauf] < wert_sort[iLauf-jLauf])
			{
				wert_sort[(iLauf-jLauf)+1] = wert_sort[iLauf-jLauf];
				grp_sort[(iLauf-jLauf)+1] = grp_sort[iLauf-jLauf];
				hub++;	
			}	
		}
		wert_sort[(iLauf+1)-hub] = wert_[iLauf]; 
		grp_sort[(iLauf+1)-hub]  = grp_[iLauf];
		hub=0;
	}
	
	//laufindexkorrektur
	for (iLauf = 2; iLauf <= n_+1; iLauf++) {wert_sort[iLauf-1]=wert_sort[iLauf];grp_sort[iLauf-1]=grp_sort[iLauf];} 
	wert_sort[n_+1]=0;
	
	//printf("\n");for (iLauf = 1; iLauf <= n_; iLauf++) printf("%f %f\n",wert_sort[iLauf], grp_sort[iLauf]);

	for (iLauf = 1; iLauf <= 100; iLauf++) {vb_rang[iLauf]=0; vb_rang_n[iLauf]=1;}//vektoreninitialisierung
	
	rang_[1]=1;vb=0;
	for (iLauf = 1; iLauf <= n_; iLauf++) //rangermittlung
	{	
		if (wert_sort[iLauf+1] == wert_sort[iLauf]) //bei wertgleichheit verbundränge
		{
			if(vb==0) {vbnr++; vbi--; vb_rang[vbnr]+=rang;}
			rang_[iLauf]=vbi; rang_[iLauf+1]=vbi;
			vb_rang[vbnr]+=rang+1; vb_rang_n[vbnr]++;
			vb=1;
		}
		rang++;
		
		if (wert_sort[iLauf+1] != wert_sort[iLauf]) //bei wertunterschied rangzuweisung
		{
			rang_[iLauf+1]=rang;
			vb=0;
		}
	}
	
	for (iLauf = 1; iLauf <= vbnr; iLauf++) //verbundrangwertberechnung
	{
		for (jLauf = 1; jLauf <= n_; jLauf++) 
		{
			if (rang_[jLauf]<0)if(fabs(rang_[jLauf])==iLauf) rang_[jLauf]= vb_rang[iLauf]/vb_rang_n[iLauf];
		}
	}

	//printf("\n");for (iLauf = 1; iLauf <= n_; iLauf++) printf("%f %f\n",rang_[iLauf], grp_sort[iLauf]);

	for (iLauf = 1; iLauf <= n_; iLauf++) // T berechnung
	{
		if(grp_sort[iLauf]==1) {T1+=rang_[iLauf]; n1++;}
		if(grp_sort[iLauf]==2) {T2+=rang_[iLauf]; n2++;}
	}

	if(T1<=T2) U= n1*n2+((n1*(n1+1))/2)-T1; 
	if(T1>T2)  U= n1*n2+((n2*(n2+1))/2)-T2;
		
	if (theta==1) fn_erg= U; 
	
	if(vbnr==0) sU= sqrt((n1*n2*(n1+n2+1))/12);

	if(vbnr>0) // bei verbundrängen sU korrektur
	{	
		for(iLauf = 1; iLauf <= vbnr; iLauf++) sUvb+=(pow(vb_rang_n[iLauf],3)-vb_rang_n[iLauf])/12;
		sU=sqrt( 1.0*(n1*n2)/(n_*(n_-1)) )*sqrt( ((pow(n_,3)-n_)/12)-sUvb );
	}	
	
									if (theta==2) fn_erg= sU; 
	
	mU= (n1*n2)/2;                  if (theta==3) fn_erg= mU;
	
	if (theta==4 || theta==6) fn_erg= (U-mU)/sU;

	//if (theta == 5) fn_erg= (2.0/(n1+n2))*(T2/n2-T1/n1);//alternativformel für rbisR
	if (theta == 5) fn_erg= (U-(n1*n2-U))/(1.0*n1*n2);

	return fn_erg;
};

double fn_T_test(double wert[100], double n, int theta)// Wilcoxon T-Test // 
//                                                                        // WTS_(1) x11,x12,... ,xn1,xn2
//                                                                        // SWTS(2) x11,x12,... ,xn1,xn2 
//                                                                        // MWTS(3) x11,x12,... ,xn1,xn2
//                                                                        // ZWTS(4) x11,x12,... ,xn1,xn2
{
	int iLauf, jLauf, n_=0, dn=0, dp=0, hub=0, vb, vbnr=0;
	double min, d[100], da[100], d_sort[100], da_sort[100], rang_[100], rang=1, vb_rang[100], vb_rang_n[100], vbi=0,
			T=0, T_=0, n__, sT, mT, sTvb=0, tmp;

	for (iLauf = 1; iLauf <= n; iLauf+=2) //differenz, abolutdifferenz
	{ 
		if(wert[iLauf]-wert[iLauf+1]!=0)
		{
			n_++; 
			d[n_]= wert[iLauf]-wert[iLauf+1]; da[n_]= fabs(wert[iLauf]-wert[iLauf+1]);
		}
	} 
	 
	min=da[1]; for (iLauf = 1; iLauf <= n_; iLauf++)if(da[iLauf]<min)min=da[iLauf];//minimum absolutdifferenz
	
	da_sort[1] = min;//anfangswert=minimalwert
	for (iLauf = 1; iLauf <= n_; iLauf++)//sortierung
	{
		for (jLauf = 0; jLauf < iLauf; jLauf++)
		{
			if (da[iLauf] < da_sort[iLauf-jLauf])
			{
				da_sort[(iLauf-jLauf)+1] = da_sort[iLauf-jLauf]; 
				d_sort[(iLauf-jLauf)+1]  =  d_sort[iLauf-jLauf];hub++;		
			}	
		}
		da_sort[(iLauf+1)-hub] = da[iLauf];
		d_sort[(iLauf+1)-hub]  =  d[iLauf]; hub=0;	
	}
	for (iLauf = 2; iLauf <= n_+1; iLauf++) {da_sort[iLauf-1]=da_sort[iLauf]; d_sort[iLauf-1]=d_sort[iLauf];}//laufindexkorrektur
	
	da_sort[n_+1]=0; d_sort[n_+1]=0; 

	//printf("\n");for (iLauf = 1; iLauf <= n_; iLauf++) printf("%f %f\n",d_sort[iLauf], d[iLauf]);

	for (iLauf = 1; iLauf <= 100; iLauf++) {vb_rang[iLauf]=0; vb_rang_n[iLauf]=1;}//vektoreninitialisierung

	rang_[1]=1;vb=0;
	for (iLauf = 1; iLauf <= n_; iLauf++) //rangermittlung
	{	
		if (da_sort[iLauf+1] == da_sort[iLauf]) //bei absolutdifferenzgleichheit verbundränge
		{
			if(vb==0) {vbnr++; vbi--; vb_rang[vbnr]+=rang;}
			rang_[iLauf]=vbi; rang_[iLauf+1]=vbi;
			vb_rang[vbnr]+=rang+1; vb_rang_n[vbnr]++;
			vb=1;
		}
		rang++;
		
		if (da_sort[iLauf+1] != da_sort[iLauf]) //bei absolutdifferenzunterschied rangzuweisung
		{
			rang_[iLauf+1]=rang;
			vb=0;
		}
	}
	
	for (iLauf = 1; iLauf <= vbnr; iLauf++) //verbundrangwertberechnung
	{
		for (jLauf = 1; jLauf <= n_; jLauf++) 
		{
			if (rang_[jLauf]<0)if(fabs(rang_[jLauf])==iLauf) rang_[jLauf]= vb_rang[iLauf]/vb_rang_n[iLauf];
		}
	}
	
	//printf("\n");for (iLauf = 1; iLauf <= n_; iLauf++) printf("%f %f %f\n",rang_[iLauf], da_sort[iLauf], d_sort[iLauf]);

	for (iLauf = 1; iLauf <= n_; iLauf++) // T berechnung
	{
		if(d_sort[iLauf]<0)   {T +=rang_[iLauf]; dn++;}//negativ differenz
		if(d_sort[iLauf]>0)   {T_+=rang_[iLauf]; dp++;}//positiv diferenz
	}

	if(dn>dp){ tmp= T; T= T_; T_= tmp;}//selteneres vorzeichen zu T

	n__= dn+dp; 
	
	mT= ((n__)*(n__+1))/4;
	
	for(iLauf= 1; iLauf <= vbnr; iLauf++) sTvb+=(pow(vb_rang_n[iLauf],3)-vb_rang_n[iLauf])/2;
	sT= sqrt(((n__*(n__+1))*(2*n__+1)-sTvb)/24);

	if (theta==1) fn_erg= T;
	if (theta==2) fn_erg= sT;
	if (theta==3) fn_erg= mT;
	if (theta==4) fn_erg= (T-mT)/sT;

	return 0;
};

double igamma(double wert[100]) // gamma integral funktion // IGM x,dt
{
	FILE *out;

	double iLauf,y_,x_=0,zlr=0,d_;
	d_=1/wert[2];

	printf("\rcomputing GAMMA ...");

	out=fopen( "MAT_fn.txt", "w" );

	for (iLauf = d_; iLauf <= 10/d_; iLauf+=d_)
	{
		    y_=pow(iLauf,wert[1]-1)*pow(fn_const(1),-iLauf);
	     if(y_<0.00001&&x_>1)break;
		x_+=y_;
		  
		   zlr+=1;
		if(zlr<66000)fprintf(out,"%.14f\n",y_);//dateiausgabe des dichtevektors (Jt) bei nmax=66000 
	}

	printf("\r                                  \r");

	fn_erg=x_*d_;

	fclose(out);
	
	return fn_erg;
};


double iigamma(double wert[100]) // Gamma Volumsintegral // IIG xa,xb,dt,dx
{
	double iLauf,jLauf,y_,x_=0,xy_=0,a_,b_,d_x, d_t;

	a_=wert[1];
	b_=wert[2];
	d_t=1/wert[3];
	d_x=1/wert[4];

	printf("\rcomputing GAMMA Volume ...");

	for (jLauf = a_; jLauf <= b_; jLauf+=d_x) //über dx bestimmt (xa - xb) 
	{
		for (iLauf = d_t; iLauf <= 10/d_t; iLauf+=d_t) //über dt unbestimmt (0 - oo)
		{
				y_=pow(iLauf,jLauf-1)*pow(fn_const(1),-iLauf);
			 if(y_<0.00001&&x_>1)break;
			x_+=y_;
		}
		xy_+=x_*d_t;
		     x_=0;
	}

	printf("\r                                  \r");

	fn_erg=xy_*d_x; // /((b_-a_)/d_x)
	
	return fn_erg;
};

double dgamma(double wert[100]) // gamma dichte funktion // DGM x,t
{
	fn_erg=pow(wert[2],wert[1]-1)*pow(fn_const(1),-wert[2]);

	return fn_erg;
};


double gamma(double wert) // gamma polynomial-approximation // GAMMA x
{
	double P1[10], QX=0, QY=0, QXQ=0, QYQ=0, QFQ=0, QWQ=0, QZQ=0, R2=1;
	int iLauf, QILauf;

	if (wert < 0 || wert > 70) {printf("\n\nvalue.0 '0<=x<=70'"); exit(0);}// wert bereich
	
	P1[0] =	1;
	P1[1] =	-0.577191652;
	P1[2] =	0.988205891;
	P1[3] =	-0.897056937;
	P1[4] =	0.918206857;
	P1[5] =	-0.756704078;
	P1[6] =	0.482199394;
	P1[7] =	-0.193527818;
	P1[8] =	0.035868343;

	QX = wert;

	if (QX != floor(QX))
		{
			if (QX < 1)				
			{ 
				QY=QX; R2=P1[8]; for (QILauf=7; QILauf >=0  ;QILauf--) R2 = R2 * QY + P1[QILauf];
				R2 = R2/QY; 
			}
			
			if (QX >= 1 && QX <= 2) 
			{ 
				QY=QX-1; R2=P1[8]; for (QILauf=7; QILauf >=0  ;QILauf--) R2 = R2 * QY + P1[QILauf];
			}
			
			if (QX > 2)
			{
				QY=QX-floor(QX); R2=P1[8]; for (QILauf=7; QILauf >=0  ;QILauf--) R2 = R2 * QY + P1[QILauf];
			    for(iLauf=1; iLauf <= QX-1;iLauf++) R2 = R2 * (QY+iLauf);
			}
		}
		if (QX == floor(QX)) for(iLauf=1; iLauf < QX; iLauf++) R2 *= iLauf; 

		QXQ=R2; QYQ=-7;	
		
		if(QXQ !=0 )
		{
			QFQ = log10(sqrt(pow(QXQ,2)));
			QYQ=QFQ+QYQ; 
			if (QFQ >= 0) QFQ= floor(QFQ);		
			if (QFQ < 0)  QFQ= -1*(floor(sqrt(pow(QFQ,2))));
			QZQ=QFQ; QFQ=QYQ; 
			if (QFQ >= 0) QFQ= floor(QFQ);	
			if (QFQ < 0)  QFQ= -1*(floor(sqrt(pow(QFQ,2))));	
			QYQ=QZQ-QFQ-1;
			if (QYQ < 19 ) 
			{
				if (QYQ < 0 ) QXQ=0; 
				if (QYQ >=0 )
				{
					if (QZQ >= 90){ QXQ *= 0.00000000000000000001; QFQ=QZQ; QZQ -= 20;}
					QWQ = sqrt(pow(QXQ*pow(10,(-1*QZQ)),2)); QWQ=floor(QWQ*pow(10,QYQ)+0.5);
					QWQ *= pow(10,QZQ)*pow(10,(-1*QYQ));
					if (QFQ >= 90) QWQ *= pow(10000000000,2);
					if (QXQ >= 0) QXQ = QWQ; 
					if (QXQ < 0) QXQ = -1*QWQ;
				}
			}
		}
		
	R2=QXQ;	fn_erg = R2; 

	return fn_erg;
};

double inv_gamma(double wert, int theta) // gamma approx. invers funktionen // 
//																        	// (1)AGAM g
//                                                                          // (2)BGAM g 
{
	double  erg=0, i_, i=1;

	if (wert < 0.885626 ) {printf("\rvalue.0 'GAMMA<0.885626'");exit(0);}
	//wendepunkt gültig für die gamma polynomial-approximation

	fn_erg=0;
	i_=theta;

	if(theta==1)//AGAM
	while(1)
	{
		while(erg>=wert&& i_<=1.46156) 
		{ 
			  erg=gamma(i_);
			            i_+=i;	
		}  
			    if(wert<1 ) i/=10;
		        if(wert>=1) i/=10000;
		
		while(erg<=wert)
		{     
			  erg=gamma(i_);
			            i_-=i; 
		}        
		         if(wert<1) i/=10;   
		         if(wert>=1)i/=1000;	

		if(i<0.000001)break;
	}

	if(theta==2)//BGAM
	while(1)
	{
		while(erg<=wert) 
		{ 
			  erg=gamma(i_);
			            i_+=i;
		}  
		                    i/=1000;
		
		while(erg>=wert && i_>=1.46156)
		{     
			  erg=gamma(i_);
			            i_-=i; 
		}   
		                    i/=100;	

		if(i<0.000001)break;
	}

	fn_erg=i_;
	if(theta==2)fn_erg=i_+0.000001;

	return fn_erg;
};

double dgam_funktion(double wert[100], int n)// gamma verteilungsdichtefunktion // DGAM x, c
{
	long double G_;
	
	G_= gamma(wert[2]); G_ = 1/G_;
	
	fn_erg=  G_ * pow(wert[1],wert[2]-1) * pow(fn_const(1),-wert[1]);

	return fn_erg;
};

double dt_funktion(double wert[100])// ordinatenwert d der t verteilungsdichtefunktion f(x=t) t -> d // DTW t, n
{
	long double pi_, G1_, G2_ ;
	
	pi_ = fn_const(2);
	G1_ = gamma((wert[2]+1)/2);
	G2_ = gamma(wert[2]/2);
	
	fn_erg= (G1_/G2_)* pow(wert[2] * pi_,-0.5) * pow( 1 +( pow(wert[1],2)/wert[2] ), -1*((wert[2]+1)/2) );
	
	return fn_erg;
};

double ptd_funktion(double wert[100])// prozentrang p (integral -oo ... t) der t verteilungsdichtefunktion f(x=t) bei df, t -> p //  PTD t, df
{
	double iLauf, t_, p_t=0, vektor[3], d_;
	long double pi_, G1_, G2_;
	
	t_=wert[1];
	
	vektor[2]=20;// igamma d
	d_=1/wert[3];
	if(wert[3]==0)d_=0.0001;
	
	if(t_<-20) t_=-20;
	if(t_> 20) t_= 20;
		
	pi_ = fn_const(2);
	
	if((wert[2]+1)/2<=70) //über Gamma-polynom
	{
		G1_ = gamma((wert[2]+1)/2);
		G2_ = gamma(wert[2]/2);
	}
	
	if((wert[2]+1)/2>70) //über Gamma-integrale
	{
					 vektor[1]=(wert[2]+1)/2;
		G1_ = igamma(vektor);
		             vektor[1]=wert[2]/2;
		G2_ = igamma(vektor);
	}

	for(iLauf=0; iLauf<=fabs(t_); iLauf+=d_) p_t+=(G1_/G2_)* pow(wert[2] * pi_,-0.5) * pow( 1 +( pow(iLauf,2)/wert[2] ), -1*((wert[2]+1)/2) );

	           p_t= (2*p_t)*d_;	
	fn_erg= (1-p_t)/2; 
	
	if(t_>0)fn_erg= 1-fn_erg;

	if(fn_erg>1) fn_erg=1;
	
	if(t_==-20) fn_erg=0;
	if(t_==  0) fn_erg=0.5;

	return fn_erg;
};

double dx_funktion(double wert[100])// ordinatenwert d der x2 verteilungsdichtefunktion f(x=x2) x2 -> d // DXW x, n
{
	long double G_;
	
	G_ = gamma(wert[2]/2); G_ = G_ * pow(2,wert[2]/2); G_= 1/G_;
	
	fn_erg= G_* pow(wert[1],(wert[2]/2)-1) * pow(fn_const(1),-wert[1]/2) ;

	return fn_erg;
};

double df_funktion(double wert[100])// ordinatenwert d der F verteilungsdichtefunktion f(x=F) F -> d // DFW x, n1, n2
{
	long double G_1, G_2, G_3, n1_, n2_, F_;

	F_=wert[1]; n1_=wert[2]; n2_=wert[3]; 
	
	G_1= gamma((n1_+n2_)/2); G_2= gamma(n1_/2); G_3= gamma(n2_/2); G_1= G_1/(G_2*G_3);
	
	fn_erg=  G_1 * pow(n1_/n2_,n1_/2) * pow(F_,(n1_/2)-1) * pow( 1+(n1_/n2_)*F_ , -((n1_+n2_)/2) );

	return fn_erg;
};

double pL_funktion(double wert[100])// Laplace Verteilungsfunktion F(x=L) L -> p  //  PLW L, a,b
{
	if(wert[1]< wert[2]) fn_erg=    0.5*pow(fn_const(1),-((wert[2]-wert[1])/wert[3]));
	if(wert[1]>=wert[2]) fn_erg= 1-(0.5*pow(fn_const(1),-((wert[1]-wert[2])/wert[3])));

	return fn_erg;
};

double Lp_funktion(double wert[100])// Laplace Verteilungsfunktion F(y=p) p -> L  //  LPW p, a,b
{
	   fn_erg=                 wert[2]-log(pow(  2*wert[1],-wert[3]));
	if(fn_erg>=wert[2])fn_erg= wert[2]+log(pow(2-2*wert[1],-wert[3]));

	return fn_erg;
};

double dL_funktion(double wert[100])// ordinatenwert d der Laplace Verteilungsdichtefunktion f(x=L) L -> d // DLW L, a,b
{
	fn_erg=   (1/(2*wert[3])) *pow(fn_const(1),-(fabs(wert[1]-wert[2])/wert[3]));
	
	return fn_erg;
};

double pA_funktion(double wert[100])// Logistische Verteilungsfunktion F(x=A) A -> p  //  PAW A, a,b
{
	fn_erg= 1/( 1+ pow(fn_const(1),-((wert[1]-wert[2])/wert[3])) );
	
	return fn_erg;
};

double Ap_funktion(double wert[100])// Logistische Verteilungsfunktion F(y=p) p -> A  //  APW p, a,b
{
	fn_erg= log( pow(((1/((1/wert[1])-1)) ),wert[3]) )+wert[2];
	
	return fn_erg;
};

double dA_funktion(double wert[100])// ordinatenwert d der Logistischen Verteilungsdichtefunktion f(x=A) A -> d // DAW A, a,b
{
	fn_erg= ((1/wert[3])*pow(fn_const(1),-((wert[1]-wert[2])/wert[3])))*pow(( 1+pow(fn_const(1),-((wert[1]-wert[2])/wert[3])) ),-2);
	
	return fn_erg;
};

double pV_funktion(double wert[100])// Extremwert Verteilungsfunktion F(x=V) V -> p  //  PVW V, a,b
{
	fn_erg= pow(fn_const(1),-(pow(fn_const(1),-((wert[1]-wert[2])/wert[3]))));
	
	return fn_erg;
};

double Vp_funktion(double wert[100])// Extremwert Verteilungsfunktion F(y=p) p -> V  //  VPW p, a,b
{
	fn_erg= (log(pow((log(1/wert[1])),-wert[3])))+wert[2];
	
	return fn_erg;
};

double dV_funktion(double wert[100])// ordinatenwert d der Extremwert Verteilungsdichtefunktion f(x=V) V -> d // DVW V, a,b
{
	fn_erg= (1/wert[3])*(pow(fn_const(1),-((wert[1]-wert[2])/wert[3])))*pow(fn_const(1),-(pow(fn_const(1),-((wert[1]-wert[2])/wert[3]))));
	
	return fn_erg;
};

double pC_funktion(double wert[100])// Cauchy Verteilungsfunktion F(x=C) C -> p  //  PCW C, a,b
{
	fn_erg= (1/2.0)+((1/fn_const(2))*(atan((wert[1]-wert[2])/wert[3])));
	
	return fn_erg;
};

double Cp_funktion(double wert[100])// Cauchy Verteilungsfunktion F(y=p) p -> C  //  CPW p, a,b
{
	fn_erg= wert[3]*tan((wert[1]-0.5)*fn_const(2))+wert[2];
	
	return fn_erg;
};

double dC_funktion(double wert[100])// ordinatenwert d der Cauchy Verteilungsdichtefunktion f(x=C) C -> d // DCW C, a,b
{
	fn_erg= 1/(wert[3]*fn_const(2)*(1+pow(((wert[1]-wert[2])/wert[3]),2)));
	
	return fn_erg;
};

double pW_funktion(double wert[100])// Weibull Verteilungsfunktion F(x=W) W -> p  //  PWW W, a,b
{
	fn_erg= 1-pow(fn_const(1),-(pow(((wert[1])/(wert[2])),wert[3])));
	
	return fn_erg;
};

double Wp_funktion(double wert[100])// Weibull Verteilungsfunktion F(y=p) p -> W  //  WPW p, a,b
{	
	fn_erg= (pow(  fabs(log(1.0-wert[1])) ,(1.0/wert[3]) ))*wert[2];

	return fn_erg;
};

double dW_funktion(double wert[100])// ordinatenwert d der Weibull Verteilungsdichtefunktion f(x=W) W -> d // DWW W, a,b
{
	fn_erg= (wert[3]/wert[2])*( pow( (wert[1]/wert[2]),(wert[3]-1)))*(pow(fn_const(1),-(pow((wert[1]/wert[2]),wert[3]))));
	
	return fn_erg;
};


double dz_funktion(double wert)// ordinatenwert d der z verteilungsdichtefunktion f(x=z) z -> d // DZW z
{
	//long double pi_zahl=2*(1+pow(SIGMA,2));
	
	fn_erg=(1/sqrt(2*   fn_const(2)  ))*pow(fn_const(1),(-(pow(wert,2)/2)));
	
	return fn_erg;
};

double zd_funktion(double wert)// z-wert vom ordinatenwert d der z verteilungsdichtefunktion f'(x)= f(y=d) d -> z // ZDW d
{
    /*
    // iteratives Näherungsverfahren
	double erg, i_=0, i=1, zlr=0, krit=1000000, krit2=1000000000000000;
	
	if (wert<=0 || fabs(wert) > 0.3972885) {printf("\n\nvalue.0 '0<zd<=0.397'\n");exit(0);}

	while(floor(erg*krit2)!=floor(wert*krit2) && zlr < krit)
	{	
		while(erg > wert )
		{
			erg=dz_funktion(i_); 
			if(floor(erg*krit2)==floor(wert*krit2) || zlr > krit) break; 
			i_+=i;  zlr++;//printf("d=%f z=%f\n",erg, i_);
		} 
		i/=10;
		
		while(erg < wert )
		{
			erg=dz_funktion(i_); 
			if(floor(erg*krit2)==floor(wert*krit2) || zlr > krit) break; 
			i_-=i;  zlr++;//printf("d=%f z=%f\n",erg, i_);
		} 
		i/=10;
	}
	
	fn_erg = i_;
	*/

	fn_erg= sqrt(log (1/pow( wert/sqrt(1/(2*(    fn_const(2)    )) )  ,2)) ); //Invers-Formulierung 

	return fn_erg;	
};

double pd_funktion(double wert[100])// prozentrang p (integral -oo ... z) der z verteilungsdichtefunktion f(x=z) z -> p //  PZD z
{
	long double iLauf, p_z=0, d_;

		d_=1/wert[2];
	if(wert[2]==0)d_=0.0001;
	
	if(wert[1]<-20) wert[1]=-20;
	if(wert[1]> 20) wert[1]= 20;

	for(iLauf=0; iLauf<=fabs(wert[1]); iLauf+=d_) p_z+= dz_funktion(iLauf);
	
       	       p_z=(p_z*2)*d_;
	fn_erg= (1-p_z)/2; 
	
	if(wert>0)fn_erg= 1-fn_erg;

	if(fn_erg>1) fn_erg=1;
	if(wert[1]==-20) fn_erg=0;

	if (wert==0) fn_erg=0.5;

	return fn_erg;
};

double zp_funktion(double wert) // z verteilungsfunktion F(y=p) p -> z  //  ZPW p
{
	long double  p_wert, z_wert, OO[10], RD[10];
	z_wert=RD[0]=RD[2]=RD[3]=RD[4]=0; OO[1]=OO[2]=RD[1]=RD[5]=1;
	
	fn_erg=0;
	
	if (wert>=1 || wert<0 ) {printf("\n\nvalue.0 '0<=p<=1'");exit(0);}
   		
	//F(x=p)
		
	p_wert = wert;//p-wert eingabe	
	
	//z-Wert Berechnung
	if(p_wert!=0.5)
	{
		if(p_wert>0.5) {OO[1]=1-p_wert;} else {OO[1]=p_wert;}
		OO[1]=-1*log(4*OO[1]*(1-OO[1]));
		OO[2]=(-3.231081277e-09*OO[1]+8.360937017e-08)*OO[1]-1.04527497e-06;
		OO[2]=(OO[2]*OO[1]+5.824238515e-06)*OO[1]+6.841218299e-06;
		OO[2]=((OO[2]*OO[1]-2.250947176e-04)*OO[1]-8.36435359e-04)*OO[1]+3.706987906e-02;
		z_wert=OO[2]*OO[1]+1.570796288;
		z_wert=sqrt(OO[1]*z_wert);
		if(p_wert<0.5) z_wert = z_wert * -1;
	}
	
	if(RD[0]==0)
	{
		RD[1]=z_wert; RD[2]=-5;

		//Kurvenglättung
		
		if(RD[1] !=0 )
		{	
			RD[3] = log10(fabs(RD[1]));
			RD[2]=RD[3]+RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);		
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));
			RD[4]=RD[3]; RD[3]=RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);	
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));	
			RD[2]=RD[4]-RD[3]-1;
			if (RD[2] < 19 ) 
			{
				if (RD[2] < 0 ) RD[1]=0; 
				if (RD[2] >=0 )
				{
					if (RD[4] >= 90){ RD[1] = RD[1] * 1e-20; RD[3]=RD[4]; RD[4] -= 20;}
					RD[5] = sqrt(pow(RD[1]*pow(10,(-1*RD[4])),2)); RD[5]=floor(RD[5]*pow(10,RD[2])+0.5);
					RD[5] *= pow(10,RD[4])*pow(10,(-1*RD[2]));
					if (RD[3] >= 90) RD[5] = RD[5] * 1e+20;
					if (RD[1] >= 0) RD[1] = RD[5]; 
					if (RD[1] < 0) RD[1] = -1*RD[5];
				}
			}
		}
		z_wert=RD[1]; fn_erg = z_wert;
	}
	
	return fn_erg;
};

double pz_funktion(double wert) // z verteilungsfunktion F(x=z) z -> p  //  PZW z
{
	long double   z_wert, p_wert, OO[10], RD[10];
	z_wert=RD[0]=RD[2]=RD[3]=RD[4]=0; OO[1]=OO[2]=RD[1]=RD[5]=1;

	fn_erg=0;

	//F(y=z)
	
	z_wert = wert;//z-wert eingabe

	//p-Wert Berechnung
	OO[1] = fabs(z_wert);
	if(OO[1]>7) p_wert=0; 
	if(OO[1]<=7)
	{
		p_wert=OO[1]*(3.80036e-05+OO[1]*(4.88906e-05+OO[1]*0.000005383));
		p_wert=1+OO[1]*(0.049867347+OO[1]*(2.11410061e-02+OO[1]*(3.2776263e-03+p_wert)));
		p_wert=0.5*pow(p_wert,-16);
	}
	if (z_wert>0) p_wert=1-p_wert;
	
	if(RD[0]==0)
	{
		RD[1]=p_wert; RD[2]=-5;

		//Kurvenglättung
		
		if(RD[1] !=0 )
		{
			RD[3] = log10(fabs(RD[1]));
			RD[2]=RD[3]+RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);		
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));
			RD[4]=RD[3]; RD[3]=RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);	
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));	
			RD[2]=RD[4]-RD[3]-1;
			if (RD[2] < 19 ) 
			{
				if (RD[2] < 0 ) RD[1]=0; 
				if (RD[2] >=0 )
				{
					if (RD[4] >= 90){ RD[1] = RD[1] * 1e-20; RD[3]=RD[4]; RD[4] -= 20;}
					RD[5] = sqrt(pow(RD[1]*pow(10,(-1*RD[4])),2)); RD[5]=floor(RD[5]*pow(10,RD[2])+0.5);
					RD[5] *= pow(10,RD[4])*pow(10,(-1*RD[2]));
					if (RD[3] >= 90) RD[5] = RD[5] * 1e+20;
					if (RD[1] >= 0) RD[1] = RD[5]; 
					if (RD[1] < 0) RD[1] = -1*RD[5];
				}
			}
		}
		p_wert=RD[1]; fn_erg = p_wert;
	}

	return fn_erg;
};

double tp_funktion(long double p_wert, double n_) // t verteilungsfunktion F(y=p) p -> t  //  TPW p,n
{
	long double  t_wert, OO[10], RD[10];
   
	t_wert=RD[0]=RD[2]=RD[3]=RD[4]=0; OO[1]=OO[2]=OO[3]=OO[4]=OO[5]=OO[6]=OO[7]=RD[1]=RD[5]=1;

	if (p_wert>=1 || p_wert<=0 ) {printf("value.0 '0<=p<=1'");exit(0);}
	
	//t-Wert Berechnung
	if(p_wert!=0.5)
	{
		if(p_wert>0.5) {OO[1]=1-p_wert;} else {OO[1]=p_wert;}

		OO[1]=-1*log(4*OO[1]*(1-OO[1]));
		OO[2]=(-3.231081277e-09*OO[1]+8.360937017e-08)*OO[1]-1.04527497e-06;
		OO[2]=(OO[2]*OO[1]+5.824238515e-06)*OO[1]+6.841218299e-06;
		OO[2]=((OO[2]*OO[1]-2.250947176e-04)*OO[1]-8.36435359e-04)*OO[1]+3.706987906e-02;
		t_wert=OO[2]*OO[1]+1.570796288;
		t_wert=sqrt(OO[1]*t_wert);
		if(p_wert>0.5) t_wert=t_wert*-1;
	}

	if(p_wert==0.5) t_wert=0; 

	if(RD[0] ==0)
	{
		OO[3]=pow(t_wert,2);
		OO[1]=t_wert+(1+OO[3])*t_wert/(4*n_)+((5*OO[3]+16)*OO[3]+3)*t_wert/(96*pow(n_,2));
		OO[1]=OO[1]+(((3*OO[3]+19)*OO[3]+17)*OO[3]-15)*t_wert/(384*pow(n_,3));
		OO[1]=OO[1]+((((79*OO[3]+776)*OO[3]+1482)*OO[3]-1920)*OO[3]-945)*t_wert/(92160*pow(n_,4));
		t_wert=OO[1]+(((((27*OO[3]+339)*OO[3]+930)*OO[3]-1782)*OO[3]-765)*OO[3]+17955)*t_wert/(368640*pow(n_,5));
	}

	if(RD[0]==0)
	{
		RD[1]=t_wert; RD[2]=-5;

		//Kurvenglättung
		if(RD[1] !=0 )
		{	
			RD[3] = log10(fabs(RD[1]));
			RD[2]=RD[3]+RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);		
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));
			RD[4]=RD[3]; RD[3]=RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);	
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));	
			RD[2]=RD[4]-RD[3]-1;
			if (RD[2] < 19 ) 
			{
				if (RD[2] < 0 ) RD[1]=0; 
				if (RD[2] >=0 )
				{
					if (RD[4] >= 90){ RD[1] = RD[1] * 1e-20; RD[3]=RD[4]; RD[4] -= 20;}
					RD[5] = sqrt(pow(RD[1]*pow(10,(-1*RD[4])),2)); RD[5]=floor(RD[5]*pow(10,RD[2])+0.5);
					RD[5] *= pow(10,RD[4])*pow(10,(-1*RD[2]));
					if (RD[3] >= 90) RD[5] = RD[5] * 1e+20;
					if (RD[1] >= 0) RD[1] = RD[5]; 
					if (RD[1] < 0) RD[1] = -1*RD[5];
				}
			}
		}
		t_wert=RD[1]; fn_erg=-t_wert;
	}
	return fn_erg;
}


double pt_funktion(long double t_wert, double n_) // t verteilungsfunktion F(x=t) t -> p  //  PTW t,n
{
	int sw=0;
	long double  p_wert/*P6*/, n_O/*p5*/, OO[10], RD[10], iLauf, iLauf_1, n_Z, n_N;

	RD[0]=RD[2]=RD[3]=RD[4]=iLauf_1=0; OO[1]=OO[2]=OO[3]=OO[4]=OO[5]=OO[6]=OO[7]=RD[1]=RD[5]=1;

	if (t_wert<0){t_wert=-t_wert;sw=1;} //berechnung über positive t-werte,  z bei df=100000

	//Prozentrangberechnung
	if(n_ != floor(n_))
	{
		OO[6]=n_; n_=floor(OO[6]); n_O = n_; n_=1; OO[5]=t_wert; t_wert=pow(t_wert,2);

		OO[1]=n_O/(n_O+n_*t_wert); OO[3]=sqrt(1-OO[1]);	n_Z=2*floor(n_/2)-n_+2;	n_N=2*floor(n_O/2)-n_O+2;

		if(n_Z*2-n_N == 1 )	{ p_wert=1-2/3.1417*atan(OO[3]/sqrt(OO[1])); OO[4]=OO[3]*sqrt(OO[1])/3.1417; } 
		if(n_Z*2-n_N == 2 )	{ p_wert=OO[1]; OO[4]=(1-OO[1])*p_wert;}
		if(n_Z*2-n_N == 3 ) { p_wert=sqrt(OO[1]); OO[4]=(1-OO[1])*p_wert/2; }
		if(n_Z*2-n_N != 1 && n_Z*2-n_N != 2 && n_Z*2-n_N != 3 )	{ p_wert=1-OO[3]; OO[4]=OO[1]*OO[3]/2;	}

		for(iLauf=n_N; iLauf <= n_O-2; iLauf +=2) 
		{
			if(n_O > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
			{ 			
				iLauf_1=iLauf; p_wert=p_wert-2/iLauf*OO[4];
				OO[4]=OO[4]*OO[1]*(n_Z/iLauf+1);
			}
		}
		if(iLauf_1!=iLauf) iLauf_1=iLauf_1+2;
	
		for(iLauf=n_Z; iLauf <= n_-2; iLauf +=2) 
		{
			if(n_ > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
			{ 
				p_wert=p_wert+2/iLauf*OO[4];
				OO[4]=OO[4]*(1-OO[1])*(iLauf_1/iLauf+1);
			}
		}
	
		if(RD[0] == 0)
		{
			p_wert=p_wert/2; n_=n_O;t_wert=OO[5];
			if(t_wert < 0) p_wert=1-p_wert;
	
			OO[7]=p_wert;
			n_=floor(OO[6])+1;
			n_O = n_; n_=1; OO[5]=t_wert; t_wert=pow(t_wert,2);
	
			OO[1]=n_O/(n_O+n_*t_wert); OO[3]=sqrt(1-OO[1]);
			n_Z=2*floor(n_/2)-n_+2;	n_N=2*floor(n_O/2)-n_O+2;

			if(n_Z*2-n_N == 1 )	{ p_wert=1-2/3.1417*atan(OO[3]/sqrt(OO[1])); OO[4]=OO[3]*sqrt(OO[1])/3.1417; } 
			if(n_Z*2-n_N == 2 )	{ p_wert=OO[1]; OO[4]=(1-OO[1])*p_wert;}
			if(n_Z*2-n_N == 3 ) { p_wert=sqrt(OO[1]); OO[4]=(1-OO[1])*p_wert/2; }
			if(n_Z*2-n_N != 1 && n_Z*2-n_N != 2 && n_Z*2-n_N != 3 )	{ p_wert=1-OO[3]; OO[4]=OO[1]*OO[3]/2;	}

		
			for(iLauf=n_N; iLauf <= n_O-2; iLauf +=2) 
			{
				if(n_O > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
				{ 			
					iLauf_1=iLauf; p_wert=p_wert-2/iLauf*OO[4];
					OO[4]=OO[4]*OO[1]*(n_Z/iLauf+1);
				}
			}
			if(iLauf_1!=iLauf) iLauf_1=iLauf_1+2;
	
			for(iLauf=n_Z; iLauf <= n_-2; iLauf +=2) 
			{
				if(n_ > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
				{ 
					p_wert=p_wert+2/iLauf*OO[4];
					OO[4]=OO[4]*(1-OO[1])*(iLauf_1/iLauf+1);
				}
			}

			if(RD[0] == 0)
			{
				p_wert=p_wert/2; n_=n_O; t_wert=OO[5];
				if(t_wert < 0) p_wert=1-p_wert;
			
				if(RD[0] == 0) 
				{
					p_wert=(p_wert-OO[7])*(OO[6]-floor(OO[6]))+OO[7]; n_=OO[6];
				}
			}
		}
	}

	if(n_ == floor(n_))
	{
		n_O = n_; n_=1; OO[5]=t_wert; t_wert=pow(t_wert,2);
		
		OO[1]=n_O/(n_O+n_*t_wert); OO[3]=sqrt(1-OO[1]);
		n_Z=2*floor(n_/2)-n_+2;	n_N=2*floor(n_O/2)-n_O+2;

		if(n_Z*2-n_N == 1 )	{ p_wert=1-2/3.1417*atan(OO[3]/sqrt(OO[1])); OO[4]=OO[3]*sqrt(OO[1])/3.1417; } //n=1
		if(n_Z*2-n_N == 2 )	{ p_wert=OO[1]; OO[4]=(1-OO[1])*p_wert;}//n={}
		if(n_Z*2-n_N == 3 ) { p_wert=sqrt(OO[1]); OO[4]=(1-OO[1])*p_wert/2; }//n={}
		if(n_Z*2-n_N != 1 && n_Z*2-n_N != 2 && n_Z*2-n_N != 3 )	{ p_wert=1-OO[3]; OO[4]=OO[1]*OO[3]/2;	}//n>1

	
		for(iLauf=n_N; iLauf <= n_O-2; iLauf +=2) 
		{
			if(n_O > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
			{ 			
				iLauf_1=iLauf; p_wert=p_wert-2/iLauf*OO[4];
				OO[4]=OO[4]*OO[1]*(n_Z/iLauf+1);
			}
		}
		if(iLauf_1!=iLauf) iLauf_1=iLauf_1+2;
	
		for(iLauf=n_Z; iLauf <= n_-2; iLauf +=2) 
		{
			if(n_ > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
			{ 
				p_wert=p_wert+2/iLauf*OO[4];
				OO[4]=OO[4]*(1-OO[1])*(iLauf_1/iLauf+1);
			}
		}

		if(RD[0] == 0)
		{
			p_wert=p_wert/2; n_=n_O; t_wert=OO[5];
			if(t_wert < 0) p_wert=1-p_wert;
		}
	}

	if(RD[0]==0)
	{
		RD[1]=p_wert; RD[2]=-5;

		//Kurvenglättung
		if(RD[1] !=0 )
		{
			RD[3] = log10(fabs(RD[1]));
			RD[2]=RD[3]+RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);		
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));
			RD[4]=RD[3]; RD[3]=RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);	
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));	
			RD[2]=RD[4]-RD[3]-1;
			if (RD[2] < 19 ) 
			{
				if (RD[2] < 0 ) RD[1]=0; 
				if (RD[2] >=0 )
				{
					if (RD[4] >= 90){ RD[1] = RD[1] * 1e-20; RD[3]=RD[4]; RD[4] -= 20;}
					RD[5] = sqrt(pow(RD[1]*pow(10,(-1*RD[4])),2)); RD[5]=floor(RD[5]*pow(10,RD[2])+0.5);
					RD[5] *= pow(10,RD[4])*pow(10,(-1*RD[2]));
					if (RD[3] >= 90) RD[5] = RD[5] * 1e+20;
					if (RD[1] >= 0) RD[1] = RD[5]; 
					if (RD[1] < 0) RD[1] = -1*RD[5];
				}
			}
		}
		p_wert=RD[1]; fn_erg=1-p_wert;
	}
	
	if(sw==1) fn_erg=1-fn_erg;
	return fn_erg;

};

double fn_ci_(double wert[100])// Vertrauensbereich // CI_ P, sem, df											
{
	        fn_erg= tp_funktion( 1-( (1-wert[1]) / 2 ) , wert[3]);
	fn_erg= fn_erg*wert[2];

	return 0;
}

double fn_epsilon(double wert[100], int sw)// Effektgrösse // 
//                                                         // Effektgrösse (1) EFG m0, m1, sg
//                                                         // x alpha crit (2) XCA p, m0, m1, sm, df
//                                                         // x beta crit  (3) XCB p, m0, m1, sm, df
//                                                         // alpha niveau (4) ANI x, m0, sm, df
//                                                         // alpha niveau (5) BNI x, m1, sm, df
//                                                         // Teststärke   (6) IMB x, m1, sm, df
//                                                         // Optimal n    (7) OPN p, e, df
//                                                         // Effektstärke (8) EFS p, n, df
//                                                         // Optimal alpha(9) OPP e, n, df
//                                                         // schwellenwert(10)SWX m0, m1, sg, n
//                                                         // Optimal n(z) (11)ONZ p, e
{
	if (sw==1|| sw==10) fn_erg= (wert[2]-wert[1])/wert[3];
	
	if (sw==2 || sw==3) 
	{
		fn_erg= tp_funktion(wert[1], wert[5]);
		
		if (sw==2)if(wert[2] > wert[3]) fn_erg=-fn_erg; // m0 > m1 -> -t  x alpha crit
		if (sw==3)if(wert[2] < wert[3]) fn_erg=-fn_erg; // m0 < m1 -> -t  x beta crit
			
		if (sw==2) fn_erg= wert[2]+fn_erg*wert[4];
		if (sw==3) fn_erg= wert[3]+fn_erg*wert[4];
	}
	
	if (sw==4 || sw==5 || sw==6) 
	{
	
		fn_erg= pt_funktion((wert[1]-wert[2])/wert[3], wert[4]);
		
		if(wert[2] < wert[1]) fn_erg=1-fn_erg; // m < x -> 1-p  

		if (sw==6) fn_erg=1-fn_erg;
	}

	if (sw==7 || sw==8 || sw==11)
	{
		if(sw!=11)fn_erg= tp_funktion(wert[1], wert[3]);
		if(sw==11)fn_erg= tp_funktion(wert[1], 100000);
		
		if (sw==7||sw==11) fn_erg= (pow(2* fn_erg, 2))/pow(wert[2],2); //OPN, ONZ
		if (sw==8 ) fn_erg= sqrt((pow(2* fn_erg, 2))/wert[2]);//EFS
	}

	if (sw==9 )
	{
		fn_erg= pt_funktion( sqrt(pow(wert[1],2)*wert[2])/2 , wert[3]);
		fn_erg= 1-fn_erg;
	}
	
	if (sw==10 )
	{
		fn_erg=  (sqrt(pow(fn_erg,2)*wert[4])/2)*(sqrt(pow(wert[3],2)/wert[4]));
		
		if(wert[1] < wert[2]) fn_erg = wert[1]+ fn_erg;
		if(wert[1] > wert[2]) fn_erg = wert[1]- fn_erg;
	}

	return fn_erg;
};

double fn_frpt(double wert[100])// Korrelationskoeffizient zum Niveau pa2 // RPT pa2, n
{
	double t_, n_; 

	n_=wert[2];
	                              t_= tp_funktion(1-(wert[1])/2,n_-2);
	                       t_=pow(t_,2);
	fn_erg=  pow(((n_-2) /(t_))+1,-0.5) ;
	
	return fn_erg;
};

double xp_funktion(long double p_wert, double n_) // chi2 verteilungsfunktion F(y=p) p -> x2  //  XPW p,n
{
	long double   x2_wert, x2[10], OO[10], RD[10], QIOS, QF, iLauf, hoch;
   
	x2_wert=RD[0]=RD[2]=RD[3]=RD[4]=0; OO[1]=OO[2]=OO[3]=OO[4]=RD[1]=RD[5]=QF=1;

	p_wert = 1-p_wert;
			//^^^^^^^^
           // Initial p Inversion

	if (p_wert>=1 || p_wert<=0 ){printf("value.0 '0<=p<=1'\n");exit(0);} 
	
	if(n_==1)
	{
		OO[3]=p_wert; p_wert=p_wert/2;

		//if(p_wert!=0.5)
		//{
			if(p_wert>0.5) {OO[1]=1-p_wert;} else {OO[1]=p_wert;}
			OO[1]=-1*log(4*OO[1]*(1-OO[1]));
			OO[2]=(-3.231081277e-09*OO[1]+8.360937017e-08)*OO[1]-1.04527497e-06;
			OO[2]=(OO[2]*OO[1]+5.824238515e-06)*OO[1]+6.841218299e-06;
			OO[2]=((OO[2]*OO[1]-2.250947176e-04)*OO[1]-8.36435359e-04)*OO[1]+3.706987906e-02;
			x2_wert=OO[2]*OO[1]+1.570796288;
			x2_wert=sqrt(OO[1]*x2_wert);
			if(p_wert>0.5) x2_wert = x2_wert * -1;
		//}

		if(RD[0]==0)
		{
			x2_wert=pow(x2_wert,2);
			p_wert=OO[3];
		}
	}

	if(n_==2) x2_wert=-2*log (p_wert);

	if(n_!=1 && n_!=2)
	{
		x2[1]=0; x2[2]=1; x2[3]=0.5; x2[4]=p_wert;
		M2410:
		x2_wert=1/x2[3]-1; 
		
		OO[3]=x2_wert;
		if(x2_wert==0) p_wert=1;
		if(n_>40 && x2_wert!=0)
		{
			OO[4]=2/(9*n_); x2_wert=(pow(x2_wert/n_,0.333)-1+OO[4])/sqrt(OO[4]);
		
			OO[1] = fabs(x2_wert);
			if(OO[1]>7) p_wert=0; 
			if(OO[1]<=7)
			{
				p_wert=OO[1]*(3.80036e-05+OO[1]*(4.88906e-05+OO[1]*0.000005383));
				p_wert=1+OO[1]*(0.049867347+OO[1]*(2.11410061e-02+OO[1]*(3.2776263e-03+p_wert)));
				p_wert=0.5*pow(p_wert,-16);
			}
			if (x2_wert<0) p_wert=1-p_wert;

			if(RD[0]==0) x2_wert=OO[3];
		}
	
		if(n_<=40 && x2_wert!=0)
		{
			QIOS=2-floor(n_)+2*floor(floor(n_/2));
			OO[4]=sqrt(x2_wert);
	
			if (QIOS!=1)
			{
				hoch=((-1*x2_wert)/2); p_wert=pow(2.718281828,hoch);
	
				QF=p_wert/2;
				if(QIOS>n_-1) x2_wert=OO[3];
			
				if(QIOS<=n_-1)
				{
					for(iLauf=QIOS; iLauf <= (n_-1); iLauf +=2)
					{
						QF=QF*OO[3]/iLauf; p_wert=p_wert+2*QF;
					}
				}
			}
	
			if(QIOS==1)
			{
				x2_wert=OO[4];
		
				OO[1] = fabs(x2_wert);
				if(OO[1]>7) p_wert=0; 
				if(OO[1]<=7)
				{
					p_wert=OO[1]*(3.80036e-05+OO[1]*(4.88906e-05+OO[1]*0.000005383));
					p_wert=1+OO[1]*(0.049867347+OO[1]*(2.11410061e-02+OO[1]*(3.2776263e-03+p_wert)));
					p_wert=0.5*pow(p_wert,-16);
				}
				if (x2_wert<0) p_wert=1-p_wert;

				if(RD[0]==0)
				{
					p_wert=2*p_wert;
					hoch=(-1*OO[3]/2);QF=0.3989422804*pow(2.718281828,hoch)/OO[4];
				}
				if(QIOS<=n_-1)
				{
					for(iLauf=QIOS; iLauf <= (n_-1); iLauf +=2)
					{
						QF=QF*OO[3]/iLauf; p_wert=p_wert+2*QF;
					}
				}
			}
			x2_wert=OO[3];
		}
	
		if(RD[0]==0)
		{
			if(p_wert<=x2[4]) {x2[1]=x2[3];} else {x2[2]=x2[3];}
			x2[0]=x2[3]; x2[3]=(x2[1]+x2[2])/2; 
			if(fabs(x2[3]-x2[0])>0.00001*x2[3]) goto M2410;							
			x2_wert=1/x2[3]-1; p_wert=x2[4];
		}
	}

	if(RD[0]==0)
	{
		RD[1]=x2_wert; RD[2]=-4;

		//Kurvenglättung
		if(RD[1] !=0 )
		{	
			RD[3] = log10(fabs(RD[1]));
			RD[2]=RD[3]+RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);		
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));
			RD[4]=RD[3]; RD[3]=RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);	
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));	
			RD[2]=RD[4]-RD[3]-1;
			if (RD[2] < 19 ) 
			{
				if (RD[2] < 0 ) RD[1]=0; 
				if (RD[2] >=0 )
				{
					if (RD[4] >= 90){ RD[1] = RD[1] * 1e-20; RD[3]=RD[4]; RD[4] -= 20;}
					RD[5] = sqrt(pow(RD[1]*pow(10,(-1*RD[4])),2)); RD[5]=floor(RD[5]*pow(10,RD[2])+0.5);
					RD[5] *= pow(10,RD[4])*pow(10,(-1*RD[2]));
					if (RD[3] >= 90) RD[5] = RD[5] * 1e+20;
					if (RD[1] >= 0) RD[1] = RD[5]; 
					if (RD[1] < 0) RD[1] = -1*RD[5];
				}
			}
		}
		x2_wert=RD[1]; fn_erg=x2_wert;
	}
	return fn_erg;
}


double px_funktion(long double x2_wert, double n_) // chi2 verteilungsfunktion F(x=x2) x2 -> p  //  PXW x2,n
{
	long double   p_wert,  OO[10], RD[10], QIOS, QF, iLauf, hoch;

    RD[0]=RD[2]=RD[3]=RD[4]=0; OO[1]=OO[2]=OO[3]=OO[4]=RD[1]=RD[5]=QF=1;

	//Prozentrangberechnung
	OO[3]=x2_wert;
	if(x2_wert==0) p_wert=1;
	if(n_>40 && x2_wert!=0)
	{
		OO[4]=2/(9*n_); x2_wert=(pow(x2_wert/n_,0.333)-1+OO[4])/sqrt(OO[4]);
		
		OO[1] = fabs(x2_wert);
		if(OO[1]>7) p_wert=0; 
		if(OO[1]<=7)
		{
			p_wert=OO[1]*(3.80036e-05+OO[1]*(4.88906e-05+OO[1]*0.000005383));
			p_wert=1+OO[1]*(0.049867347+OO[1]*(2.11410061e-02+OO[1]*(3.2776263e-03+p_wert)));
			p_wert=0.5*pow(p_wert,-16);
		}
		if (x2_wert<0) p_wert=1-p_wert;

		if(RD[0]==0) x2_wert=OO[3];
	}
	
	if(n_<=40 && x2_wert!=0)
	{
		QIOS=2-floor(n_)+2*floor(floor(n_/2));
		OO[4]=sqrt(x2_wert);
	
		if (QIOS!=1)
		{
			hoch=((-1*x2_wert)/2); p_wert=pow(2.718281828,hoch);
	
			QF=p_wert/2;
			if(QIOS>n_-1) x2_wert=OO[3];
			
			if(QIOS<=n_-1)
			{
				for(iLauf=QIOS; iLauf <= (n_-1); iLauf +=2)
				{
					QF=QF*OO[3]/iLauf; p_wert=p_wert+2*QF;
				}
			}
		}
	
		if(QIOS==1)
		{
			x2_wert=OO[4];
		
			OO[1] = fabs(x2_wert);
			if(OO[1]>7) p_wert=0; 
			if(OO[1]<=7)
			{
				p_wert=OO[1]*(3.80036e-05+OO[1]*(4.88906e-05+OO[1]*0.000005383));
				p_wert=1+OO[1]*(0.049867347+OO[1]*(2.11410061e-02+OO[1]*(3.2776263e-03+p_wert)));
				p_wert=0.5*pow(p_wert,-16);
			}
			if (x2_wert<0) p_wert=1-p_wert;
		
			if(RD[0]==0)
			{
				p_wert=2*p_wert;
				hoch=(-1*OO[3]/2);QF=0.3989422804*pow(2.718281828,hoch)/OO[4];
			}
			if(QIOS<=n_-1)
			{
				for(iLauf=QIOS; iLauf <= (n_-1); iLauf +=2)
				{
					QF=QF*OO[3]/iLauf; p_wert=p_wert+2*QF;
				}
			}
		}
		x2_wert=OO[3];
	}

	if(RD[0]==0)
	{
		RD[1]=p_wert; RD[2]=-5;

		//Kurvenglättung
		if(RD[1] !=0 )
		{
			RD[3] = log10(fabs(RD[1])); 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);		
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));
			RD[4]=RD[3]; RD[3]=RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);	
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));	
			RD[2]=RD[4]-RD[3]-1;
			if (RD[2] < 19 ) 
			{
				if (RD[2] < 0 ) RD[1]=0; 
				if (RD[2] >=0 )
				{
					if (RD[4] >= 90){ RD[1] = RD[1] * 1e-20; RD[3]=RD[4]; RD[4] -= 20;}
					RD[5] = sqrt(pow(RD[1]*pow(10,(-1*RD[4])),2)); RD[5]=floor(RD[5]*pow(10,RD[2])+0.5);
					RD[5] *= pow(10,RD[4])*pow(10,(-1*RD[2]));
					if (RD[3] >= 90) RD[5] = RD[5] * 1e+20;
					if (RD[1] >= 0) RD[1] = RD[5]; 
					if (RD[1] < 0) RD[1] = -1*RD[5];
				}
			}
		}
		p_wert=RD[1]; fn_erg=1-p_wert;
	}
	return fn_erg;
};


double pxd_funktion(double wert[100])// prozentrang p (integral 0 ... x2) der x2 verteilungsdichtefunktion f(x=x2) bei df, x2 -> p //  PXD x, df
{
	double iLauf, x2_, p_x2=0, vektor[3], min, d_,G_, e_;

	x2_=wert[1];
	vektor[2]=wert[2];//df
	d_=1/wert[3];
	if(wert[3]==0)d_=0.0001;

	e_ = fn_const(1);

	if (wert[2]==1)// bei df=1 über z-Integrale
	{
		                           vektor[1]=pow(x2_,0.5);
								   vektor[2]=1/d_;
		fn_erg=1-(2*(1-pd_funktion(vektor)));
	} 
	
	if (wert[2]>=2)//
	{
		min=xp_funktion(0.0000001, wert[2]);

		if(wert[2]/2<=70) G_ = gamma(wert[2]/2); //über Gamma polynom 
		if(wert[2]/2> 70)                        //über Gamma integrale 
		{
			            vektor[1]=wert[2]/2;
			            vektor[2]=20;
			G_ = igamma(vektor); 
		}
	
		G_ = G_ * pow(2,wert[2]/2); G_= 1/G_;

		for(iLauf=min; iLauf<=fabs(x2_); iLauf+=d_) p_x2+= G_* pow(iLauf,(wert[2]/2)-1) * pow(e_,-iLauf/2) ;
		
		fn_erg= p_x2*d_;	
	}
	
	if(fn_erg>1) fn_erg=1;

	if (x2_==0) fn_erg=0;

	return fn_erg;
};

double fp_funktion(long double p_wert, double n_1, double n_2) // F verteilungsfunktion F(y=p) p -> F  //  FPW p,n1.n2
{	
	long double  QX, QX1, QND, QMD, QQ, QP, QW1, QW2, QX2, Q5, P5, P6, R5=0; 
	long double  QX44, QW3=1, QIF, QJFU, QX0, QXQ, QYQ, QFQ, QZQ, QWQ; 

	QX=QYQ=QFQ=QWQ=QZQ=0; QXQ=QWQ=1;

	P6= 1-p_wert; Q5= n_1; P5= n_2;
	  //^^^^^^^^
     // Initial p Inversion

	if (Q5 > 30 && P5 > 30)
	{
		if(P6!=0.5)
		{
			if(P6>0.5) {QW1=1-P6;} else {QW1=P6;}

			QW1=-1*log(4*QW1*(1-QW1));
			QX44=(-3.231081277e-09*QW1+8.360937017e-08)*QW1-1.04527497e-06;
			QX44=(QX44*QW1+5.824238515e-06)*QW1+6.841218299e-06;
			QX44=((QX44*QW1-2.250947176e-04)*QW1-8.36435359e-04)*QW1+3.706987906e-02;
			QX=QX44*QW1+1.570796288;
			QX=sqrt(QW1*QX);
			if(P6>0.5) QX=QX*-1;
		}

		if(P6==0.5) QX=0; 
		
		if(R5==0)
		{
			QW1=2/9/Q5;
			QW2=2/9/P5;
			
			QW3=(1-QW1)*(1-QW2)+QX*sqrt(pow(1-QW1,2))*QW2+pow(1-QW2,2)*QW1-QW1*QW2*pow(QX,2);
			QX=pow(QW3/pow(1-QW2,2)-QW2*pow(QX,2),3);
		}
	}
	
	if (Q5 <= 30 || P5 <= 30)
	{
		QX1=0; QX2=1; QQ=0.5; QP=P6;
		
		M2950:
		QX=(1/QQ-1)*P5/Q5;

		QW1=P5/(P5+Q5*QX); QW2=sqrt(1-QW1);
		QMD=2*floor(Q5/2)-Q5+2;
		QND=2*floor(P5/2)-P5+2;

		if(QMD*2-QND == 1 )	{ P6=1-2/3.1417*atan(QW2/sqrt(QW1)); QW3=QW2*sqrt(QW1)/3.1417; } 
		if(QMD*2-QND == 2 )	{ P6=QW1; QW3=(1-QW1)*P6;}
		if(QMD*2-QND == 3 ) { P6=sqrt(QW1); QW3=(1-QW1)*P6/2; }			
		if(QMD*2-QND != 1 && QMD*2-QND != 2 && QMD*2-QND != 3 )	{ P6=1-QW2; QW3=QW1*QW2/2;	}

		for(QIF=QND; QIF <= P5-2; QIF +=2) 
		{
			if(P5 > QIF || fabs(2/QIF*QW3) >= 0.00001*P6 )
			{ 			
				QJFU=QIF;
		
				P6=P6-2/QIF*QW3;
				QW3=QW3*QW1*(QMD/QIF+1);
			}
		}
		if(QJFU!=QIF) QJFU=QJFU+2;

		for(QIF=QMD; QIF <= Q5-2; QIF +=2) 
		{
			if(Q5 > QIF || fabs(2/QIF*QW3) >= (0.00001*P6) )
			{ 
				P6=P6+2/QIF*QW3;
				QW3=QW3*(1-QW1)*(QJFU/QIF+1);
			}
		}

		if(R5 == 0) 
		{
			if(P6<=QP) {QX1=QQ;} else {QX2=QQ;}
			QX0=QQ;QQ=(QX1+QX2)/2;
			if(fabs(QQ-QX0)>0.00001*QQ ) goto M2950;
			QX=(1/QQ-1)*P5/Q5; P6=QP;
		}
	}
		
	if(R5 == 0) 
	{
		QXQ=QX; QYQ=-5;
	
		if(QXQ !=0 )
		{
			QFQ = log10(sqrt(pow(QXQ,2)));
			QYQ=QFQ+QYQ; 
			if (QFQ >= 0) QFQ= floor(QFQ);		
			if (QFQ < 0)  QFQ= -1*(floor(sqrt(pow(QFQ,2))));
			QZQ=QFQ; QFQ=QYQ; 
			if (QFQ >= 0) QFQ= floor(QFQ);	
			if (QFQ < 0)  QFQ= -1*(floor(sqrt(pow(QFQ,2))));	
			QYQ=QZQ-QFQ-1;
			if (QYQ < 19 ) 
			{
				if (QYQ < 0 ) QXQ=0; 
				if (QYQ >=0 )
				{
					if (QZQ >= 90){ QXQ = QXQ * 1e-20; QFQ=QZQ; QZQ -= 20;}
					QWQ = sqrt(pow(QXQ*pow(10,(-1*QZQ)),2)); QWQ=floor(QWQ*pow(10,QYQ)+0.5);
					QWQ *= pow(10,QZQ)*pow(10,(-1*QYQ));
					if (QFQ >= 90) QWQ = QWQ * 1e+20;
					if (QXQ >= 0) QXQ = QWQ; 
					if (QXQ < 0) QXQ = -1*QWQ;
				}
			}
		}
		QX=QXQ;	fn_erg=QX;
	}
	return fn_erg;
}


double pf_funktion(long double f_wert, double n_1, double n_2) // F verteilungsfunktion F(x=F) F -> p  //  PFW F,n1,n2
{
	long double  QX, QND, QMD, QW1, QW2, Q5, P5, P6, R5=0;
	long double  QW3=1, QIF, QJFU, QXQ, QYQ, QFQ, QZQ, QWQ; 

	QX=QYQ=QFQ=QWQ=QZQ=0; QXQ=QWQ=1;

	Q5 = n_1; P5 = n_2;	P6 = f_wert; QX=f_wert;

	QW1=P5/(P5+Q5*QX); QW2=sqrt(1-QW1);
	QMD=2*floor(Q5/2)-Q5+2;
	QND=2*floor(P5/2)-P5+2;

	if(QMD*2-QND == 1 )	{ P6=1-2/3.1417*atan(QW2/sqrt(QW1)); QW3=QW2*sqrt(QW1)/3.1417; } 
	if(QMD*2-QND == 2 )	{ P6=QW1; QW3=(1-QW1)*P6;}
	if(QMD*2-QND == 3 ) { P6=sqrt(QW1); QW3=(1-QW1)*P6/2; }			
	if(QMD*2-QND != 1 && QMD*2-QND != 2 && QMD*2-QND != 3 )	{ P6=1-QW2; QW3=QW1*QW2/2;	}

	for(QIF=QND; QIF <= P5-2; QIF +=2) 
	{
		if(P5 > QIF || fabs(2/QIF*QW3) >= (0.00001*P6) )
		{ 			
			QJFU=QIF;
		
			P6=P6-2/QIF*QW3;
			QW3=QW3*QW1*(QMD/QIF+1);
		}
	}
	if(QJFU!=QIF) QJFU=QJFU+2;
	

	for(QIF=QMD; QIF <= Q5-2; QIF +=2)
	{
		if(Q5 > QIF || fabs(2/QIF*QW3) >= (0.00001*P6) )
		{ 
			P6=P6+2/QIF*QW3;
			QW3=QW3*(1-QW1)*(QJFU/QIF+1);
		}
	}

	if(R5 == 0) 
	{
		QXQ= P6; QYQ=-5;

		if(QXQ !=0 )
		{
			QFQ = log10(fabs(QXQ));
			QYQ=QFQ+QYQ; 
			if (QFQ >= 0) QFQ= floor(QFQ);		
			if (QFQ < 0)  QFQ= -1*(floor(fabs(QFQ)));
			QZQ=QFQ; QFQ=QYQ; 
			if (QFQ >= 0) QFQ= floor(QFQ);	
			if (QFQ < 0)  QFQ= -1*(floor(fabs(QFQ)));	
			QYQ=QZQ-QFQ-1;
			if (QYQ < 19 ) 
			{
				if (QYQ < 0 ) QXQ=0; 
				if (QYQ >=0 )
				{
					if (QZQ >= 90){ QXQ = QXQ * 1e-20; QFQ=QZQ; QZQ -= 20;}
					QWQ = sqrt(pow(QXQ*pow(10,(-1*QZQ)),2)); QWQ=floor(QWQ*pow(10,QYQ)+0.5);
					QWQ *= pow(10,QZQ)*pow(10,(-1*QYQ));
					if (QFQ >= 90) QWQ = QWQ * 1e+20;
					if (QXQ >= 0) QXQ = QWQ; 
					if (QXQ < 0) QXQ = -1*QWQ;
				}
			}
		}
		P6=QXQ; fn_erg=1-P6; 
	}
	return fn_erg;
};

double fn_fmkp(double wert[100])// Multipler-Korrelationskoeffizient zum Niveau pa2 // MKP pa2, n, k
{
	double f_, n_, k_; 

	n_=wert[2];
	k_=wert[3];

	f_= fp_funktion(1-wert[1],k_,n_-k_-1);
	
	fn_erg=  pow(((n_-k_-1) /(k_*f_))+1,-0.5) ;
	
	return fn_erg;
};

double pfd_funktion(double wert[100])// prozentrang p (integral 0 ... F) der F verteilungsdichtefunktion f(x=F) bei df1, df2, F -> p //  PFD F, df1, df2
{
	double iLauf, p_F=0, vektor[5], min, d_;
	long double G_1, G_2, G_3, n1_, n2_, F_;

	if(wert[2]<=1){printf("\n\ndesign.0 '1<df1'"); exit(0);} //df1>1
	if(wert[3]<=2){printf("\n\ndesign.0 '2<df2'"); exit(0);} //df2>2

	F_=wert[1];
	vektor[2]=20;
	//vektor[2]=wert[2];	
	n1_=wert[2];
	//vektor[3]=wert[3];  
	n2_=wert[3];
		d_=1/wert[4];
	if(wert[4]==0)d_=0.0001;

	min=fp_funktion(0.0000001, wert[2], wert[3]);

	if((n1_+n2_)/2<=70) //über Gamma polynom
	{
		G_1= gamma((n1_+n2_)/2); 
		G_2= gamma(n1_/2); 
		G_3= gamma(n2_/2);
	}

	if((n1_+n2_)/2/2>70) //über Gamma integrale
	{
		            vektor[1]=(n1_+n2_)/2;
		G_1= igamma(vektor); 
		            vektor[1]=n1_/2;
		G_2= igamma(vektor); 
		            vektor[1]=n2_/2;
		G_3= igamma(vektor); 
	}
	
	G_1= G_1/(G_2*G_3);
	
	for(iLauf=min; iLauf<=F_;  iLauf+=d_) p_F+=  G_1 * pow(n1_/n2_,n1_/2) * pow(iLauf,(n1_/2)-1) * pow( 1+(n1_/n2_)*iLauf , -((n1_+n2_)/2) );
	
	fn_erg= p_F*d_;
	
	if(fn_erg>1) fn_erg=1;

	if (F_==0) fn_erg=0;

	return fn_erg;
};


double fn_di(double wert[100], int sw)// Funktions Differential und Integral // 
//																         	  // Differential F'n(x) (1) FD_n, w
//																	          // Integral    I'nf(x) (2) IF_n, c
//																         	  // Differential F'n(x) (3) FD0n, w
//																	          // Integral    I'nf(x) (4) IF0n, c
//                                                                            //
//                                                                            // bsp:
//                                                                            // ZFV1, -6,6,0.01
//                                                                            // (X)
//                                                                            // FD_6,0
{
	FILE *in, *out;

	double iLauf,jLauf,x_1=0, x_,x_2,x_3=0,c_,N=0,i=0,xx, min, max, rng, d_;//
	char  tmp[1000000];
	
	c_=wert[2];

	printf("\n\n");
	
	for(iLauf=1;iLauf<=wert[1];iLauf++)
	{
		if(sw==1||sw==3){printf("computing F");               for(jLauf=1;jLauf<=iLauf;  jLauf++)printf("'");  printf("(x) ..."); }
		if(sw==2||sw==4){printf("computing \xb3");if(iLauf>1){for(jLauf=1;jLauf<=iLauf-1;jLauf++)printf("'");};printf("f(x) ...");}
	
		if(iLauf>1) system("MAT (X)");
	
		in=fopen( "MAT_X.txt", "r" );
		
		do { if(fgetc(in)=='\n') N++;} while (feof (in) == 0);   fclose( in  );
	
		in=fopen( "MAT_X.txt", "r" );
		while (i<N)//min max
		{
			fscanf ( in, "%s", tmp); xx=atof(tmp);	
			fscanf ( in, "%s", tmp);

			if(i==0)min=xx;
		
			i++;
		}
		max=xx;
		rng=max-min;  //wertebereich
		d_=rng/(N-1); //delta d
		
		i=0;

		//printf("\n %f %f %f %f %f\n",min, max, rng, N, d_);

		fclose( in  );
		
		in=fopen( "MAT_X.txt", "r" );
		out=fopen( "MAT_fn.txt", "w" );

		while (i<N)
		{ 
			if(i==0)
			{
				fscanf ( in, "%s", tmp); xx=atof(tmp);
				fscanf ( in, "%s", tmp);  i++;
						  x_1=atof(tmp);
			}
			
			fscanf (     in, "%s", tmp); xx=atof(tmp);
			fscanf (     in, "%s", tmp);  i++;
						  x_2=atof(tmp);

            if(sw==1){fprintf( out, "%f\t%0.32f\n",xx-d_/2,       (x_2-x_1)/d_);     x_1 =x_2;      }  //differential
			if(sw==3){fprintf( out, "%f\t%0.32f\n",xx,     (1-d_)+(x_2-x_1)/d_);     x_1 =x_2;      }  //differential0
			
			if(sw==2){fprintf( out, "%f\t%0.32f\n",xx+d_/2,       (x_2+x_1)*d_+c_);  x_1+=x_2; c_=0;}  //integral
			
			if(sw==4)                                                                                  //integral0
			{
				if(i==2)
				{
					                                          x_=((x_2+x_1)-(1-d_))*d_+c_;
					  fprintf( out, "%f\t%0.32f\n",xx-d_,     x_);
				}
				
				if(i>2)
				{                                  
					                                          x_=((x_3-(1-d_))*d_)+x_ ;                                
					  fprintf( out, "%f\t%0.32f\n",xx-d_,     x_); 
				}
				                                                   x_3=x_2;
			}  		
		}
		
		if(iLauf<wert[1])N=0;i=0;

		printf("\r                                               \r" );

		fclose(in);
		fclose(out);
	}

	fn_erg=N;

	return 0;
};

double fn_vektor(double wert[100], int sw)// Funktionskurven Vektoren // 
//																      // Gamma Funktion aprx.(0) GFV1,min,max,d
//																      // z-Dichte Funktion   (1) ZFV1,min,max,d
//															          // z-Stamm Funktion    (2) ZFV2,min,max,d
//																      // t-Dichte Funktion   (3) TFV1,min,max,d, df
//																      // x2-Dichte Funktion  (5) XFV1,min,max,d, df
//																      // F-Dichte Funktion   (7) FFV1,min,max,d, df1,df2
//																      // b-Dichte Funktion   (9) BFV1,min,max,d, df1,df2
//																      // logz-Dichte Funktion(11)LZV1,min,max,d

{
	FILE *out;

	double  i_,min, max, d_,N_=0,vektor[4];

	min=wert[2];
	max=wert[3];
	d_= wert[4];

	out=fopen( "MAT_fn.txt", "w" );

	for(i_=min;i_<=max;i_+=d_)
	{
		if(sw==0){fprintf( out, "%f\t%0.32f\n",i_, gamma(i_)); }  //Gamma
		
		if(sw==1&&wert[1]==1){fprintf( out, "%f\t%0.32f\n",i_, dz_funktion(i_)); }  //z-Dichte
		if(sw==1&&wert[1]==2){fprintf( out, "%f\t%0.32f\n",i_, pz_funktion(i_)); }  //z-Stamm

		if(sw==3)                                                       //t-Dichte
		{
			                                             vektor[1]=i_;
                                                         vektor[2]=wert[5];//df
			fprintf( out, "%f\t%0.32f\n",i_, dt_funktion(vektor)); 
		
		}  

		if(sw==5)                                                       //x2-Dichte
		{
			                                             vektor[1]=i_;
                                                         vektor[2]=wert[5];//df
			fprintf( out, "%f\t%0.32f\n",i_, dx_funktion(vektor)); 
		
		}

		if(sw==7)                                                       //F-Dichte
		{
			                                             vektor[1]=i_;
                                                         vektor[2]=wert[5];//df1
														 vektor[3]=wert[6];//df2
			fprintf( out, "%f\t%0.32f\n",i_, df_funktion(vektor)); 
		
		}

		if(sw==9)                                                    //beta-Dichte
		{

			fprintf( out, "%f\t%0.32f\n",i_, ( (gamma(wert[5]+wert[6])/(gamma(wert[5])*gamma(wert[6]))) * pow(i_,wert[5]-1) * pow(1-i_,wert[6]-1) ) ); 
		
		}  
		
		if(sw==11){fprintf( out, "%f\t%0.32f\n",i_, 1/( i_*(sqrt(2*   fn_const(2)  )) )*pow(fn_const(1),(-(pow(log(i_),2)/2)))  ); }  //log z-Dichte


		N_++;
	}

	fclose(out);

	fn_erg=N_;

	return 0;
};

double fn_kgl(double wert) // Kurvenglättung // KGL i //										      
{
	FILE *in, *outx, *outy;

	double iLauf, N=0,i=0,y_1, y_2, x_, d_;
	char  tmp[1000000];

	in=fopen( "MAT_X.txt", "r" );
	do { if(fgetc(in)=='\n') N++;} while (feof (in) == 0);   fclose( in  );
	
	for(iLauf=1;iLauf<=wert;iLauf++) //Iterationen
	{
		if(iLauf>1)system("MAT (X)");
		
		printf("\rcomputing (y)', i=%.0f ...", iLauf-1);
		
		in=fopen( "MAT_X.txt", "r" );
		outx=fopen( "~tmp_fnx.txt", "w" ); //d

		fscanf ( in, "%s", tmp);
				   x_=atof(tmp); 
		      fscanf ( in, "%s", tmp);
		      fscanf ( in, "%s", tmp);
	       d_=fabs(x_)-fabs(atof(tmp));

		fclose(outx);
		fclose(in);

		in=fopen( "MAT_X.txt", "r" );
		outx=fopen( "~tmp_fnx.txt", "w" );
		
		while (i<N) //x vektor
		{
					   fscanf ( in, "%s", tmp);
								  x_=atof(tmp);
			fprintf( outx, "%f\n",x_-d_); 
			
			fscanf ( in, "%s", tmp);
			
			i++;
		}
		i=0;

		fclose(outx);
		fclose(in);

		in=fopen( "MAT_X.txt", "r" );
		outy=fopen( "~tmp_fny.txt", "w" );
		
		while (i<N-1) //y1 vektor
		{	
			if(i==0)
			{
				fscanf ( in, "%s", tmp);
				 fscanf ( in, "%s", tmp);y_1=atof(tmp);
				fprintf( outy, "%0.32f\n",y_1); 
			}
			
			fscanf ( in, "%s", tmp);
			fscanf ( in, "%s", tmp);y_2=atof(tmp);

			fprintf( outy, "%0.32f\n",(y_1+y_2)/2);
			
			y_1=y_2;
		
			i++;
		}
		i=0;

		fclose(outy);
		fclose(in);


		in=fopen( "~tmp_fny.txt", "r" );
		outy=fopen( "~tmp_fny2.txt", "w" );

		while (i<N) //y2 vektor
		{
			if(i==0)
			{
				 fscanf ( in, "%s", tmp);y_1=atof(tmp);
				fprintf( outy, "%0.32f\n",y_1); 
			}

			fscanf ( in, "%s", tmp);y_2=atof(tmp);

			fprintf( outy, "%0.32f\n",(y_1+y_2)/2);
			
			y_1=y_2;

			i++;
		}
		i=0;

		fclose(outy);
		fclose(in);

		outx=fopen( "~tmp_fnx.txt", "r" );
		outy=fopen( "~tmp_fny2.txt", "r" );
		in=  fopen( "MAT_fn.txt", "w" );
		
		while (i<N) //
		{
			fscanf ( outx, "%s", tmp);x_ =atof(tmp);
			fscanf ( outy, "%s", tmp);y_2=atof(tmp);

			fprintf( in, "%f\t%0.32f\n",x_, y_2);

			i++;
		}
			i=0;

		fclose(outx);
		fclose(outy);
		fclose(in);		
	}

	printf("\r                                               \r" );
	
	system("del ~tmp_fnx.txt");
	system("del ~tmp_fny.txt");
	system("del ~tmp_fny2.txt");

	fn_erg=N;
	
	return 0;
};


int fn_grp2(double wert[100]) // GRP2 Graphikdialog  // GRP m, axj, ayj  										      
{
	char cmd[255], c_[10], *c1, c2[40], ax[10000][40], ay[10000][40]; 

	int j=0, sw=1, n1=0, n2=0,  i1=0, i2;
	double i,modus;
	
	FILE *f1, *f2;

	f1=fopen ("MAT_fn.txt", "r");do{ if(fgetc(f1)=='\n') n1++;}while(feof (f1) == 0);fclose(f1);
	f1=fopen ("MAT_fn.txt", "r");do{fscanf(f1,"%s", &c2);n2++;}while(feof (f1) == 0);fclose(f1);

	j=n2/n1*1.0; //spaltenanzahl

	f1=fopen ("MAT_fn.txt", "r");
	do
	{
		for(i=1;i<wert[2];i++)    fscanf(f1,"%s", &c2);
                                  fscanf(f1,"%s", &ax[i1]);
							                          i1++;
		for(i=wert[2]+1;i<=j;i++) fscanf(f1,"%s", &c2);
		
	}while(feof (f1) == 0);fclose(f1);

	i1=0;

	f1=fopen ("MAT_fn.txt", "r");
	do
	{
		for(i=1;i<wert[3];i++)   fscanf(f1,"%s", &c2);
                                 fscanf(f1,"%s", &ay[i1]);
							                         i1++;
       for(i=wert[3]+1;i<=j;i++) fscanf(f1,"%s", &c2);
		
	}while(feof (f1) == 0);fclose(f1);

	f2=fopen ("MAT_F.asc","w");for(i2=1;i2<=n1;i2++)fprintf(f2,"%s\t%s\n",ax[i2-1],ay[i2-1]); fclose(f2);

	if (wert[1]==1) modus=1;  //funktionsmodus m
	if (wert[1]==2) modus=5;
	if (wert[1]==3) modus=2;
	if (wert[1]==4) modus=3;
	if (wert[1]==5) modus=4;

	strcpy(cmd,"MAT_F.asc ");
	
	     ftoa(modus,c_,0); 
	             c1=c_[0];
	strcat(cmd, &c1);

	_spawnlp( _P_NOWAIT, "D:\\_EIGENEDATEIEN_\\1_LAUFENDES\\1_SYSTEM\\3_C_PROGRAMME\\_GRP2_\\_GRP2_01\\Debug\\GRP2.exe ", 
		                 "D:\\_EIGENEDATEIEN_\\1_LAUFENDES\\1_SYSTEM\\3_C_PROGRAMME\\_GRP2_\\_GRP2_01\\Debug\\GRP2.exe ", 
						  cmd, NULL );exit(0);

	fn_erg=n1; //n
	
	return 0;
}










