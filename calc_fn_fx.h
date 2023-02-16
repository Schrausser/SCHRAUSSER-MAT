//---------------------------------------------------------------------------------------------------------| Fisher_Exact by Dietmar Schrausser, (c) SCHRAUSSER 2009, 2010
//                                                                                                         | Exakt hypergeometrischer 4-Felder Test nach R.A.Fisher,
//   --- deaktiviert, berechnung über HF funktion (calc_fn_2kx.h) ---                                      | Fisher Exact Test. 

long double fakt(double wert, double F);

long double fn_fx(double wert[100], int p)// Fisher EXACT Test;  PO, p.exact 1-seitig, p.exact 2-seitig // 
//													                                                    // FX0 (0) a,b,c,d
//													                                                    // FX1 (1) a,b,c,d
//													                                                    // FX2 (2) a,b,c,d
{
	int  index=1,i=0, sw=0;
	double iLauf,a,b,c,d,z1,z2,s1,s2,n,zlr=0,min, min_ad;
	long double P0,P01,P10,P11,Pi, P_=0, P_1, P1=0, P_vtl[200], F;

    //4-Felder Schema
	a=wert[1]; b=wert[2];   z1=a+b;
	c=wert[3]; d=wert[4];   z2=c+d;
	 
	s1=a+c;	   s2=b+d;	    n=a+b+c+d;

	F=pow(10,30);
	if(n>120)F=pow(10,50);
	if(n>170)F=pow(10,70);
	if(n>220)F=pow(10,90);
	if(n>240)F=pow(10,120);
	//if(n>270)F=pow(10,125);//Faktorielle in t=3 Teile

	if(n>270) printf ("\n[a][b][c][d] n>270 .0\n");

	//Theta0 = Hypergeometrische Wahrscheinlichkeit P0 der Initialanordnung 
	
	//Faktoriell Zerlegung zur Zahlengrössenminderung; ungemindert max n=114	
	P0=fakt(z1,F);		
	P0=P0*fakt(z2,F);	
	P0=P0*fakt(s1,F);	
	P0=P0*fakt(s2,F);	

	P01=fakt(n,F);		
	P01=P01*(fakt(a,F));
	P01=P01*(fakt(b,F));
	P01=P01*(fakt(c,F));
	P01=P01*(fakt(d,F));

	P0=P0/(P01*pow(F,2));//Nennermultiplikation wegen n-Faktoriellzerlegungen Nenner=5=nZ+1

	//p.exact einseitig 

	min= d; if(c<min)min=c; if(b<min)min=b; if(a<min)min=a;

	//if(!( min==b && b==d && a==c ) )
	if(( min==a && a!=b &&(a+d<=b+c))|| //a-d -, b-c +
	   ( min==d && d!=c)             ||
	   ((min==a && a==b) && (d<c))   ||
	   ((min==c && d==c) && (a<b))   ||
	   ((min==a && a==c) && (b>d))   ||
	   ( min==b && (b+c)>(a+d)   )   ||
	   ( min==c && (a+d)<(b+c)   )  /*||
       ((min==b && b==d) && (a>c))*/    )
	{ 
		for (iLauf=1; iLauf<=min; iLauf++)
		{
			P10=fakt(z1,F);
			P10=P10*fakt(z2,F);
			P10=P10*fakt(s1,F);
			P10=P10*fakt(s2,F);

			P11=fakt(n,F);
			P11=P11*(fakt(a-iLauf ,F));
			P11=P11*(fakt(b+iLauf ,F));
			P11=P11*(fakt(c+iLauf ,F));
			P11=P11*(fakt(d-iLauf ,F));

			P1+=P10/(P11*pow(F,2));
	   }
	}
	/*if(!( min==b && (b+c)>(a+d)))
	if(!( min==c && (a+d)<(b+c))) 
	if(!( min==a && b==d && a==c ) )
	if(( min==b && a!=b    )  	    || 
	   ( min==c && d!=c)			||
	   ((min==a && a==b) && (d>=c))	||
	   ((min==c && d==c) && (a>=b)) ||
	   ((min==a && a==c) && (b<d))	||
	   ( min==a && (a+d)>(b+c)   )  ||
	   ((min==b && b==d) && (a<c))    ) */
	else								//a-d +, b-c -
	{	
	   for (iLauf=1; iLauf<=min; iLauf++)
	   {
			P10=fakt(z1,F);
			P10=P10*fakt(z2,F);
			P10=P10*fakt(s1,F);
			P10=P10*fakt(s2,F);

			P11=fakt(n,F);
			P11=P11*(fakt(a+iLauf ,F));
			P11=P11*(fakt(b-iLauf ,F));
			P11=P11*(fakt(c-iLauf ,F));
			P11=P11*(fakt(d+iLauf ,F));

			P1+=P10/(P11*pow(F,2));
	   }
	}
	
	if((a==b) && (b==c) && (c==d)) 
	{
		P1=0;
		for (iLauf=1; iLauf<=a; iLauf++)
		{
			P10=fakt(z1,F);
			P10=P10*fakt(z2,F);
			P10=P10*fakt(s1,F);
			P10=P10*fakt(s2,F);

			P11=fakt(n,F);
			P11=P11*(fakt(a+iLauf ,F));
			P11=P11*(fakt(b-iLauf ,F));
			P11=P11*(fakt(c-iLauf ,F));
			P11=P11*(fakt(d+iLauf ,F));

			P1+=P10/(P11*pow(F,2));
	   }
	}
	
	P_1=P0+P1;

	//p.exact zweiseitig 

	min_ad=d;if(a<d)min_ad=a;
	for (iLauf=min_ad; iLauf>=0; iLauf--)//a-d -, b-c +
	{
		//Theta i =  Hypergeometrische Wahrscheinlichkeit Pi für jede mögliche Anordnung mit gleichen Randhäufigkeiten
		
		P10=fakt(z1,F);
		P10=P10*fakt(z2,F);
		P10=P10*fakt(s1,F);
		P10=P10*fakt(s2,F);

		P11=fakt(n,F);
		P11=P11*(fakt(a-iLauf ,F));
		P11=P11*(fakt(b+iLauf ,F));
		P11=P11*(fakt(c+iLauf ,F));
		P11=P11*(fakt(d-iLauf ,F));

		Pi=P10/(P11*pow(F,2));

		P_vtl[index]=Pi;index++;
	
		if (Pi <= P0 + 0.000000001 ) { P_+=Pi;zlr++;} //P0 bedingte Summierung von Pi zu P_
		i++;          /*Korrektur zur Fliesskommainkonsistenz*/
	}
	
	min_ad=c;if(b<c)min_ad=b;
	for (iLauf=1; iLauf<=min_ad; iLauf++)//a-d +, b-c -
	{
		//Theta i =  Hypergeometrische Wahrscheinlichkeit Pi für jede mögliche Anordnung mit gleichen Randhäufigkeiten
		
		P10=fakt(z1,F);
		P10=P10*fakt(z2,F);
		P10=P10*fakt(s1,F);
		P10=P10*fakt(s2,F);

		P11=fakt(n,F);
		P11=P11*(fakt(a+iLauf ,F));
		P11=P11*(fakt(b-iLauf ,F));
		P11=P11*(fakt(c-iLauf ,F));
		P11=P11*(fakt(d+iLauf ,F));

		Pi=P10/(P11*pow(F,2));

		P_vtl[index]=Pi;index++;
		
		if (Pi <= P0 + 0.000000001 ) { P_+=Pi;zlr++;} //P0 bedingte Summierung von Pi zu P_
		i++;          /*Korrektur zur Fliesskommainkonsistenz*/
	}

	if (p==0) fn_erg= P0;  //P0
	if (p==1) fn_erg= P_1; //p.exact[1]
	if (p==2) fn_erg= P_;  //p.exact[2]

	return 0;
}

long double fakt(double wert, double F)// Faktoriell in t=2 Teilen zur Exponentialdeflation// 
{
	int iLauf;
	long double fn_erg_1=1;  
	fn_erg=1;

	for(iLauf = 1; iLauf <= floor(wert/2); iLauf++) fn_erg_1 *= iLauf;	//Teil t=1
	fn_erg_1= fn_erg_1/F;
	
	for(iLauf = iLauf; iLauf <= wert; iLauf++) fn_erg *= iLauf;			//Teil t=2
	fn_erg = fn_erg/F;

																		//Teil t=3 ...
	
	fn_erg=fn_erg*fn_erg_1; //!wert = fn_erg * F^t

	return fn_erg;
};




