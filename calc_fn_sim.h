//----------------------------------------------------------------------------------------------------| calc_ funktionen, randomisation und 
//                                                                                                    | datensimulationsmodelle, SCHRAUSSER 2010	//

double fn_rnd_var(double wert[100]);
long double fn_lto_1(double wert[100]);

double fn_rnd_var(double wert[100])// zufallsvektor (n) nach verteilung // 
//                                                                      //  z-verteilt          /  RNN 0, M, a, x, s        //
//                                                                      //  t-verteilt          /  RNN 1, M, a, x, s, df    //
//                                                                      //  x2-verteilt         /  RNN 2, M, a,       df    //
//                                                                      //  F-verteilt          /  RNN 3, M, a, df1, df2    //
//                                                                      //  Laplace-verteilt    /  RNN 4, M, a, a, b        //
//                                                                      //  rho-verteilt        /  RNN 5, M, a, min, max, v //
//                                                                      //  Logistisch verteilt /  RNN 6, M, a, a, b        //
//                                                                      //  Cauchy verteilt     /  RNN 7, M, a, eta, theta  //
//                                                                      //  Gleich-verteilt     /  RNN 8, M, a, min, max    //
//                                                                      //  Gleich-verteilt     /  RNN 9, M, a, x, s        //

//                                                                      //                         RNN 0, 30000, 0, 100, 15      //
//                                                                      //                         RNN 5, 30000, 0, 43, 157, 5   //
{
	FILE *out;

	int iLauf;
	double x_, df_, df_2, am_, s_,M_,sd,sw1, M_zlr=0, vektor[5],v_;//, sw_sim=0

	sw1= wert[1]; //outputschalter

	   sd=wert[3];
	if(sd==0) sd=(time(0)-1234567890); //seed

	M_=wert[2];am_=wert[4];s_=wert[5];df_=wert[6];

	if(sw1==2) {am_=0; s_=1;df_=wert[4];}
	if(sw1==3) {am_=0; s_=1;df_=wert[4];df_2=wert[5];}

	if(sw1==5) v_=wert[6];

	vektor[2]=wert[4];
	vektor[3]=wert[5];

	//if(sw1==0||sw1==9) sw_sim=wert[6];
	
	out=fopen( "MAT_fn.txt", "w" );//if(sw_sim!=1)

	for(iLauf=1;iLauf<=1000;iLauf++)sd=sqrt(qzufall(sd,0,100))*1234;//"zufallswarmlauf"//if(sw_sim!=1)

	while(M_zlr<M_)// über simulationszyklen M
	{
		if(sw1==0)x_=zp_funktion(qzufall(sd,0,1));                                   
		if(sw1==1)x_=tp_funktion(qzufall(sd,0,1), df_);
		if(sw1==2)x_=xp_funktion(qzufall(sd,0,1), df_);
		if(sw1==3)x_=fp_funktion(qzufall(sd,0,1), df_,df_2);
		if(sw1==4)//Laplace
		{
						   vektor[1]=qzufall(sd,0,1);							  
			x_=Lp_funktion(vektor);
		}
		if(sw1==5)//rho
		{
			x_=0;
			for(iLauf=1;iLauf<=v_;iLauf++){x_+=qzufall(sd,wert[4],wert[5]);sd=sqrt(qzufall(sd,0,100))*1234;}							  
			x_/=v_;
		}
		if(sw1==6)//Logistisch
		{
						   vektor[1]=qzufall(sd,0,1);							  
			x_=Ap_funktion(vektor);
		}
		if(sw1==7)//Cauchy
		{
						   vektor[1]=qzufall(sd,0,1);							  
			x_=Cp_funktion(vektor);
		}
		if(sw1==9)//Gleich
		{
			x_=qzufall(sd,am_-(s_+s_*( (1/(pz_funktion(1)-0.5))*(0.5-(pz_funktion(1)-0.5)))),
						  am_+(s_+s_*( (1/(pz_funktion(1)-0.5))*(0.5-(pz_funktion(1)-0.5)))));

		}
		if(sw1==8)x_=qzufall(sd,wert[4],wert[5]);	//Gleich (min,max)

		
		sd=sqrt(qzufall(sd,0,100))*1234;

				 if(sw1!=4&&sw1!=6&&sw1!=7&&sw1!=5&&sw1!=8&&sw1!=9)x_=am_+x_*s_;
		if(M_zlr<=66000)fprintf(out,"%f\n",x_);//if(sw_sim!=1)

		M_zlr++;
	}

	fclose(out);//if(sw_sim!=1)
	
	fn_erg=x_;
	
	return fn_erg;
};

double fn_rnd_bivar(double wert[100])// zufallsmatrix (N) nach bivariater verteilung //                    RNB sw1,sw2, M, a, x1, s1,      x2, s2,      r //
//                                                                                   //  z-verteilt     // RNB   0,sw2, M, a, x1, s1,      x2, s2,      r //      
//                                                                                   //  t-verteilt     // RNB   1,sw2, M, a, x1, s1, df1, x2, s2, df2, r //
//                                                                                   //  //x2-verteilt  // RNB   2,sw2, M, a,         df1,         df2, r //
//                                                                                   //  L-verteilt     // RNB   3,sw2, M, a, ax, bx,      ay, by,      r //
//                                                                                   //  A-verteilt     // RNB   4,sw2, M, a, ax, bx,      ay, by,      r //
//                                                                                   //  gleichverteilt // RNB   8,sw2, M, a, -x, +x,      -y, +y,      r //
//                                                                                   //  q=r(M)         // RNB sw1,  0, M, a, x1, s1,      x2, s2,      r //
//                                                                                   //  q=x(M)         // RNB sw1,  1, M, a, x1, s1,      x2, s2,      r //
//                                                                                   //  q=y(M)         // RNB sw1,  2, M, a, x1, s1,      x2, s2,      r //
//                                                                                   //  q=d(M)         // RNB sw1,  3, M, a, x1, s1,      x2, s2,      r //
{
	FILE *out, *tmp;

	double x_, y_,  M_, am_1, s_1,am_2, s_2,sd, sw1, sw2, M_zlr=0, r_, xy_=0,x2=0,y2=0,sum_x=0,sum_y=0,df_1, df_2, 
		   vektor1[5],vektor2[5], min_x=0,max_x=0, min_y=0,max_y=0;
	char in_x[10], in_y[10], in_d[10];
	
	sw1= wert[1]; //outputschalter
	sw2= wert[2]; //outputschalter

	M_=wert[3];
	   sd=wert[4];
	if(sd==0) sd=(time(0)-1234567890); //seed
	
	if(sw1==0)
	{
		am_1=wert[5];s_1=wert[6];
		am_2=wert[7];s_2=wert[8];
		r_=  wert[9];
	}

	if(sw1==1)
	{
		am_1=wert[5];s_1=wert[6];df_1=wert[7];
		am_2=wert[8];s_2=wert[9];df_2=wert[10];
		r_=  wert[11];
	}
/*
	if(sw1==2)
	{
		df_1=wert[5];am_1=0;s_1=1;
		df_2=wert[6];am_2=0;s_2=1;
		r_=  wert[7];
	}
*/
	if(sw1==3||sw1==4)
	{
		am_1=wert[5];s_1=wert[6];vektor1[2]=0;vektor1[3]=1;
		am_2=wert[7];s_2=wert[8];vektor2[2]=0;vektor2[3]=1;
		r_=  wert[9];
	}

	if(sw1==8)
	{
		am_1=(wert[5]+wert[6])/2;s_1=1;
		am_2=(wert[7]+wert[8])/2;s_2=1;
		r_=  wert[9];
	}

	out=fopen( "MAT_fn.txt", "w" );

	while(M_zlr<M_)// über simulationszyklen M
	{
		if(sw1==0)x_=zp_funktion(qzufall(sd,0,1)); 
		if(sw1==1)x_=tp_funktion(qzufall(sd,0,1), df_1);
		//if(sw1==2)x_=xp_funktion(qzufall(sd,0,1), df_1);
		if(sw1==3)
		{
			               vektor1[1]=qzufall(sd,0,1);	
			x_=Lp_funktion(vektor1);
		}
		if(sw1==4)
		{
			               vektor1[1]=qzufall(sd,0,1);	
			x_=Ap_funktion(vektor1);
		}

		if(sw1==8)x_=qzufall(sd,0,1);//

		sd=sqrt(qzufall(sd,0,100))*1234; 
		
		if(sw1==0)y_=r_*x_+sqrt(1-fabs(r_))*(zp_funktion(qzufall(sd,0,1))*(1+((fn_const(2)/8)*fabs(r_))));
		if(sw1==1)y_=r_*x_+sqrt(1-fabs(r_))*(tp_funktion(qzufall(sd,0,1), df_2)*(1+((fn_const(2)/8)*fabs(r_))));
		//if(sw1==2)y_=r_*x_+sqrt(1-fabs(r_))*(xp_funktion(qzufall(sd,0,1), df_2)*(1+((fn_const(2)/8)*fabs(r_))));
		if(sw1==3)
		{                                          vektor2[1]=qzufall(sd,0,1);
			y_=r_*x_+sqrt(1-fabs(r_))*(Lp_funktion(vektor2)*(1+((fn_const(2)/8)*fabs(r_))));
		}
		if(sw1==4)
		{                                          vektor2[1]=qzufall(sd,0,1);
			y_=r_*x_+sqrt(1-fabs(r_))*(Ap_funktion(vektor2)*(1+((fn_const(2)/8)*fabs(r_))));
		}
		if(sw1==8)
		{
			y_=r_*x_+sqrt(1-fabs(r_))*( qzufall(sd,0,1)*(1+((fn_const(2)/8)*fabs(r_))));//		
		}
		
		sd=sqrt(qzufall(sd,0,100))*1234; 
		
		x_=am_1+x_*s_1;
		y_=am_2+y_*s_2;

		if(sw1==8)//bei gleichverteilung y min max
		{
			if(M_zlr==0){min_x=x_;max_x=x_;min_y=y_;max_y=y_;}
			else{if(min_x>x_)min_x=x_;	if(max_x<x_)max_x=x_;if(min_y>y_)min_y=y_;	if(max_y<y_)max_y=y_;}
		}

		//summierungen
		xy_+=    x_*            y_;
		x2+=pow(x_,2);y2+=pow(y_,2);
		sum_x+=  x_;   sum_y+=  y_;
		
		if(M_<=66000)fprintf(out,"%f\t%f\t%f\n",x_, y_, x_-y_);
	
		M_zlr++;
	}

	if(M_<=66000)
	if(sw1==8)//bei gleichverteilung y transformation
	{
		M_zlr=0;
		fclose(out);
		tmp=fopen( "MAT_fn.txt", "r" );
		out=fopen( "~simtmp", "w" );
		while(M_zlr<M_)// über simulationszyklen M
		{
			fscanf(tmp,"%s%s%s",in_x, in_y, in_d);

			fprintf(out,"%f\t%f\t%f\n",wert[5]+(wert[6]-wert[5])*((atof(in_x)-min_x)/(max_x-min_x)), 
				                       wert[7]+(wert[8]-wert[7])*((atof(in_y)-min_y)/(max_y-min_y)), 
									   (wert[5]+(wert[6]-wert[5])*((atof(in_x)-min_x)/(max_x-min_x)))-(wert[7]+(wert[8]-wert[7])*((atof(in_y)-min_y)/(max_y-min_y))));
			M_zlr++;
		}
		M_zlr=0;
		fclose(out);
		fclose(tmp);
		
		out=fopen( "MAT_fn.txt", "w" );
		tmp=fopen( "~simtmp", "r" );
		while(M_zlr<M_)// über simulationszyklen M
		{
			fscanf(tmp,"%s%s%s",in_x, in_y, in_d);

			fprintf(out,"%f\t%f\t%f\n",atof(in_x), atof(in_y), atof(in_d));
			M_zlr++;
		}
		fclose(tmp);
		
		system("del ~simtmp");
	}

	fclose(out);

	//kennwertberechnung
	xy_/=M_;
	sum_x/=M_; sum_y/=M_;
	x2/=M_; y2/=M_;

	xy_=xy_-(sum_x*sum_y);

	x2=sqrt(x2-pow(sum_x,2));
	y2=sqrt(y2-pow(sum_y,2));
	
	if(sw2==0)fn_erg=xy_/(x2*y2);
	if(sw2==1)fn_erg=x_;
	if(sw2==2)fn_erg=y_;
	if(sw2==3)fn_erg=x_-y_;

	return fn_erg;
};

double fn_2uv_sim(double wert[100]) // Simulation: Parameterdifferenz  // UVS sw1,sw2,sw3,sw4, M, a, n1, n2, am1, s1, am2, s2,x //
//                                     bei 2 unverbundenen Gruppen     //      
//                                                                     //  z-verteilt       // UVS 0,sw2,sw3,sw4, M, a, n1, n2, am1, s1, am2, s2,x //
//                                                                     //  gleichverteilt m // UVS 1,sw2,sw3,sw4, M, a, n1, n2, mn1, mx1,mn2,mx2,x //
//                                                                     //  Laplaceverteilt  // UVS 2,sw2,sw3,sw4, M, a, n1, n2, am1, s1, am2, s2,x //
//                                                                     //  rho-verteilt     // UVS 3,sw2,sw3,sw4, M, a, n1, n2, mn1, mx1,v1,mn2,mx2,v2,x //
//                                                                     //  gleichverteilt x // UVS 9,sw2,sw3,sw4, M, a, n1, n2, am1, s1, am2, s2,x //
//                |                                                    //  q= sum diff      // UVS sw1,0,sw3,sw4, M, a, n1, n2, am1, s1, am2, s2,x //
//                |                                                    //  q= RNG diff      // UVS sw1,1,sw3,sw4, M, a, n1, n2, am1, s1, am2, s2,x //
//          \          /                                               //  q= AM diff       // UVS sw1,2,sw3,sw4, M, a, n1, n2, am1, s1, am2, s2,x //
//           \    +   /                                                //  q= MD diff       // UVS sw1,3,sw3,sw4, M, a, n1, n2, am1, s1, am2, s2,x //
//            +      +                                                 //  q= GM diff       // UVS sw1,4,sw3,sw4, M, a, n1, n2, am1, s1, am2, s2,x //
//      ___  +  o   o  + ___                                           //  q= HM diff       // UVS sw1,5,sw3,sw4, M, a, n1, n2, am1, s1, am2, s2,x //
//           +         +                                               //  q= SD diff       // UVS sw1,6,sw3,sw4, M, a, n1, n2, am1, s1, am2, s2,x //
//             +  V  +                                                 //  q= V diff        // UVS sw1,7,sw3,sw4, M, a, n1, n2, am1, s1, am2, s2,x //
//           /    +   \                                                //  q= D diff        // UVS sw1,8,sw3,sw4, M, a, n1, n2, am1, s1, am2, s2,x //
//          /          \                                               //  q= t-wert        // UVS sw1,9,sw3,sw4, M, a, n1, n2, am1, s1, am2, s2,x //
//                |                                                    //  q= U-wert        // UVS sw1,10,sw3,sw4,M, a, n1, n2, am1, s1, am2, s2,x //
//                |                                                    //  q= r             // UVS sw1,11,sw3,sw4,M, a, n , n , am1, s1, am2, s2,x //
//                                                                     //  qq= p(x=q)       // UVS sw1,sw2,0,sw4, M, a, n1, n2, am1, s1, am2, s2,x //
//                                                                     //  qq= pa2(x=q)     // UVS sw1,sw2,1,sw4, M, a, n1, n2, am1, s1, am2, s2,x //
//                                                                     //  qq= q(x=p)       // UVS sw1,sw2,2,sw4, M, a, n1, n2, am1, s1, am2, s2,x //
//                                                                     //  qG= sum          // UVS sw1,sw2,sw3,0, M, a, n1, n2, am1, s1, am2, s2,x //
//                                                                     //  qG= RNG          // UVS sw1,sw2,sw3,1, M, a, n1, n2, am1, s1, am2, s2,x //
//                                                                     //  qG= AM           // UVS sw1,sw2,sw3,2, M, a, n1, n2, am1, s1, am2, s2,x //
//                                                                     //  qG= MD           // UVS sw1,sw2,sw3,3, M, a, n1, n2, am1, s1, am2, s2,x //
//                                                                     //  qG= GM           // UVS sw1,sw2,sw3,4, M, a, n1, n2, am1, s1, am2, s2,x //
//                                                                     //  qG= HM           // UVS sw1,sw2,sw3,5, M, a, n1, n2, am1, s1, am2, s2,x //
//                                                                     //  qG= SD           // UVS sw1,sw2,sw3,6, M, a, n1, n2, am1, s1, am2, s2,x //
//                                                                     //  qG= V            // UVS sw1,sw2,sw3,7, M, a, n1, n2, am1, s1, am2, s2,x //
//                                                                     //  qG= D            // UVS sw1,sw2,sw3,8, M, a, n1, n2, am1, s1, am2, s2,x //

//                                                                     //                   // UVS 0,0,0,0, 1000, 0, 15,10, 0, 1, 0, 1, 0.95
//                                                                     //                   // UVS 0,3,0,0, 1000, 0, 20,32, 100, 15, 100, 15, 3.4
{
	FILE *out;

	int  jLauf,kLauf,i1, i2=1, i3, i4,i5,hub= 0;
	double iLauf,M_, N_, min,sw2,sw3,sw4, p_zlr=0,sd, zlr_[100], vektor[5], X_[1000], X_1[1000],X_2[100],D_[30001],D_sort[30001], 
		                                                                    //^^^SIC    //^^^SIC
		q_1[30001],  q_2[30001],  q_, R_[100], n_1, n_2, n_, sum1=0, sum2=0, x_;

	if (wert[5]>30000 && wert[3]==2)  {printf("\n\ndesign.0 'M<=30000; qq=q'");  exit(0);}

	sd=wert[6];
	if(sd==0) sd=(time(0)-1234567890); //seed

	sw2=wert[2];
	sw3=wert[3];
	sw4=wert[4];

	n_1=wert[7];
	n_2=wert[8];

	vektor[2]=wert[9];//AM1
	vektor[3]=wert[10];//s1

	N_=n_1+n_2;

	M_= wert[5];

	x_=wert[13];

	if(wert[1]==3)x_=wert[15];


	n_=(n_1+n_2)*2;

	for(jLauf=0;jLauf<=100;jLauf++)X_[jLauf]=0;
	
	zlr_[2]=1;

	printf("\r                                                                         \r");
	
	while(zlr_[2]<=M_)// über Simulationszyklen M_
	{	
		i1=i3=1;sum1=sum2=0;
		for(iLauf=1;iLauf<=n_1;iLauf++) // x1
		{ 
			if(wert[1]==0) //z-verteilt
			{
				X_[i1]= zp_funktion(qzufall(sd,0,1)); sd=sqrt(qzufall(sd,0,100))*1234;
				X_[i1]= wert[9]+wert[10]*X_[i1];
			}

			if(wert[1]==1) //gleichverteilt (min,max)
			{
				X_[i1]=qzufall(sd,wert[9],wert[10]);
				sd=sqrt(qzufall(sd,0,100))*1234;
			}

			if(wert[1]==2) //Laplaceverteilt
			{
				                   vektor[1]=qzufall(sd,0,1);
				X_[i1]=Lp_funktion(vektor);
				sd=sqrt(qzufall(sd,0,100))*1234;
			}
			if(wert[1]==3)//rho-verteilt
			{
				X_[i1]=0;
				for(jLauf=1;jLauf<=wert[11];jLauf++){X_[i1]+=qzufall(sd,wert[9],wert[10]);sd=sqrt(qzufall(sd,0,100))*1234;}							  
				X_[i1]/=wert[11];
			}

			if(wert[1]==9) //gleichverteilt (am,s)
			{
				X_[i1]=qzufall(sd,wert[9]-(wert[10]+wert[10]*( (1/(pz_funktion(1)-0.5))*(0.5-(pz_funktion(1)-0.5)))),
							      wert[9]+(wert[10]+wert[10]*( (1/(pz_funktion(1)-0.5))*(0.5-(pz_funktion(1)-0.5)))));
				sd=sqrt(qzufall(sd,0,100))*1234;
			}

			sum1+=X_[i1];//if(sw2==0) 
			X_1[i3] =X_[i1];i3++;
			i1++;
			X_[i1]= 1;i1++;	
		}

		if(M_<=30000)//matrixausgabe bei M<=30000
		{
			if(sw4==0)q_1[i2]=sum1;                    //q1=sum
			if(sw4==1)q_1[i2]=fn_sort(X_1, n_1, 3);    //q1=RNG
			if(sw4==2)q_1[i2]=stat_theta(X_1, n_1, 1); //q1=AM	
			if(sw4==3)q_1[i2]=fn_sort(X_1, n_1, 6);    //q1=MD
			if(sw4==4)q_1[i2]=stat_theta(X_1, n_1, 6); //q1=GM
			if(sw4==5)q_1[i2]=stat_theta(X_1, n_1, 0); //q1=HM
			if(sw4==6)q_1[i2]=stat_theta(X_1, n_1, 3); //q1=SD
			if(sw4==7)q_1[i2]=stat_theta(X_1, n_1, 15);//q1=V
			if(sw4==8)q_1[i2]=stat_theta(X_1, n_1, 7); //q1=D	
		}

		i3=1;

		vektor[2]=wert[11]; //AM2
		vektor[3]=wert[12]; //s2
		
		for(iLauf=n_1+1;iLauf<=N_;iLauf++) // x2
		{	
			if(wert[1]==0)//z-verteilt
			{
				X_[i1]= zp_funktion(qzufall(sd,0,1)); sd=sqrt(qzufall(sd,0,100))*1234;
				X_[i1]= wert[11]+wert[12]*X_[i1];	
			}

			if(wert[1]==1) //gleichverteilt (min,max)
			{
				X_[i1]=qzufall(sd,wert[11],wert[12]);
				sd=sqrt(qzufall(sd,0,100))*1234;
			}

			if(wert[1]==2) //Laplaceverteilt
			{
				                   vektor[1]=qzufall(sd,0,1);
				X_[i1]=Lp_funktion(vektor);
				sd=sqrt(qzufall(sd,0,100))*1234;
			}

			if(wert[1]==3)//rho-verteilt
			{
				X_[i1]=0;
				for(jLauf=1;jLauf<=wert[14];jLauf++){X_[i1]+=qzufall(sd,wert[12],wert[13]);sd=sqrt(qzufall(sd,0,100))*1234;}							  
				X_[i1]/=wert[14];
			}

			if(wert[1]==9) //gleichverteilt
			{
				X_[i1]=qzufall(sd,wert[11]-(wert[12]+wert[12]*( (1/(pz_funktion(1)-0.5))*(0.5-(pz_funktion(1)-0.5)))),
							      wert[11]+(wert[12]+wert[12]*( (1/(pz_funktion(1)-0.5))*(0.5-(pz_funktion(1)-0.5)))));
				sd=sqrt(qzufall(sd,0,100))*1234;
			}

			sum2+=X_[i1];//if(sw2==0)
			X_2[i3]=X_[i1];i3++;
			i1++;
			X_[i1]= 2;i1++;	
		}

		if(M_<=30000)//matrixausgabe bei M<=30000
		{
			if(sw4==0)q_2[i2]=sum2;                    //q2=sum
			if(sw4==1)q_2[i2]=fn_sort(X_2, n_2, 3);    //q2=RNG
			if(sw4==2)q_2[i2]=stat_theta(X_2, n_2, 1); //q2=AM	
			if(sw4==3)q_2[i2]=fn_sort(X_2, n_2, 6);    //q2=MD
			if(sw4==4)q_2[i2]=stat_theta(X_2, n_2, 6); //q2=GM
			if(sw4==5)q_2[i2]=stat_theta(X_2, n_2, 0); //q2=HM
			if(sw4==6)q_2[i2]=stat_theta(X_2, n_2, 3); //q2=SD
			if(sw4==7)q_2[i2]=stat_theta(X_2, n_2, 15);//q2=V
			if(sw4==8)q_2[i2]=stat_theta(X_2, n_2, 7); //q2=D
		}
		
		//Theta q
		if(sw2==0) q_=sum1-sum2;                                         //q=summen differenz
		if(sw2==1) q_=fn_sort(X_1, n_1, 3)-fn_sort(X_2, n_2, 3);         //q=RNG differenz
		if(sw2==2) q_=stat_theta(X_1, n_1, 1)-stat_theta(X_2, n_2, 1);   //q=AM differenz
		if(sw2==3) q_=fn_sort(X_1, n_1, 6)-fn_sort(X_2, n_2, 6);         //q=MD differenz
		if(sw2==4) q_=stat_theta(X_1, n_1, 6)-stat_theta(X_2, n_2, 6);   //q=GM differenz
		if(sw2==5) q_=stat_theta(X_1, n_1, 0)-stat_theta(X_2, n_2, 0);   //q=HM differenz
		if(sw2==6) q_=stat_theta(X_1, n_1, 3)-stat_theta(X_2, n_2, 3);   //q=SD differenz
		if(sw2==7) q_=stat_theta(X_1, n_1, 15)-stat_theta(X_2, n_2, 15); //q=V differenz
		if(sw2==8) q_=stat_theta(X_1, n_1, 7)-stat_theta(X_2, n_2, 7);   //q=D differenz
		if(sw2==9) q_=fn_t_uv(X_,n_, 1);                                 //q=t-wert
		if(sw2==10)q_=fn_U_test(X_,n_, 1);                               //q=U-wert
		if(sw2==11)                                                      //q=r
		{	
			i4=i5=1;
			for(jLauf=1;jLauf<=n_1+n_2;jLauf+=2)
			{
				R_[jLauf  ]=X_1[i4];i4++;
				R_[jLauf+1]=X_2[i5];i5++;
			}
			q_=fn_lin_reg(R_, n_1+n_2, 1);  
		}
		
		
		if(M_<=30000) D_[i2]=q_;//matrixausgabe bei M<=30000

		if(q_<=x_)p_zlr++; //p

		if(zlr_[2]==1)min=q_;
		if(zlr_[2]>1)if(q_<min)min=q_;

		printf("M= %.0f\r",zlr_[2]);
	
		sum1=0;sum2=0;
		zlr_[2]++;i2++;
	}

	out=fopen( "MAT_fn.txt", "w" );
	
	if(M_<=30000)//matrixausgabe bei M<=30000
	{
		D_sort[1] = min;//anfangswert=minimalwert

		for (kLauf = 1; kLauf <= M_; kLauf++)//sortierung
		{
			for (jLauf = 0; jLauf < kLauf; jLauf++)
			{
				if (D_[kLauf] < D_sort[kLauf-jLauf])
				{
					D_sort[(kLauf-jLauf)+1] = D_sort[kLauf-jLauf]; hub++;	
				}	
			}
			D_sort[(kLauf+1)-hub] =D_[kLauf]; hub=0;

			printf("p(approx.)= %i\r",kLauf);
		}

		for (kLauf = 2; kLauf <= M_+1; kLauf++)D_sort[kLauf-1]=D_sort[kLauf];//laufindexkorrektur
		D_sort[kLauf-1]=0;

		for(jLauf=1;jLauf<=M_;jLauf++)//ThetaTheta qq
		{
			if(sw3==0||sw3==2)fprintf(out,"%.6f\t%.6f\t%.6f\t%.6f\n",q_1[jLauf], q_2[jLauf],D_sort[jLauf], jLauf/M_);//qq=p
			if(sw3==1)                                                                                       //qq=pa2
			{
				if(jLauf/M_>=0.5)fprintf(out,"%.6f\t%.6f\t%.6f\t%.6f\n",q_1[jLauf], q_2[jLauf],D_sort[jLauf], (1-jLauf/M_)*2);
				if(jLauf/M_< 0.5)fprintf(out,"%.6f\t%.6f\t%.6f\t%.6f\n",q_1[jLauf], q_2[jLauf],D_sort[jLauf], (  jLauf/M_)*2);
			}
			
			if(sw3==2)if(jLauf/M_<=x_&&(jLauf+1)/M_>x_)fn_erg=D_sort[jLauf]; //qq=q
		}
	}

	fclose(out);

	printf("\r                                                              \r");
	
	//ThetaTheta bildschirmausgabe
	if(sw3==0)fn_erg=p_zlr/M_;       //qq=p
	if(sw3==1)                       //qq=pa2
	{
		if(p_zlr/M_>=0.5)fn_erg=(1-p_zlr/M_)*2;
		if(p_zlr/M_< 0.5)fn_erg=(  p_zlr/M_)*2;
	} 

	//bei sw3=2, M_<=30000 qq=q
	
	return fn_erg;
};

double fn_approx(double wert[100]) // Kurvenanpassung //
//                                                    // Laplace approximation b           // APX0,0, pcrit
//                                                    // Laplace approximation a           // APX0,1, pcrit
//                                                    // Laplace approximation mindiff     // APX0,2, pcrit
//                                                    // Logistische approximation b       // APX1,0, pcrit
//                                                    // Logistische approximation a       // APX1,1, pcrit
//                                                    // Logistische approximation mindiff // APX1,2, pcrit
//                                                    // Extremwert approximation b        // APX2,0, pcrit
//                                                    // Extremwert approximation a        // APX2,1, pcrit
//                                                    // Extremwert approximation mindiff  // APX2,2, pcrit
//                                                    // t-Wert approximation df           // APX3,0, pcrit
//                                                    // t-Wert approximation mindiff      // APX3,2, pcrit
//                                                    // Cauchy approximation theta        // APX4,0, pcrit
//                                                    // Cauchy approximation eta          // APX4,1, pcrit
//                                                    // Cauchy approximation mindiff      // APX4,2, pcrit
//                                                    // Weibull approximation c           // APX5,0, pcrit 
//                                                    // Weibull approximation b           // APX5,1, pcrit 
//                                                    // Weibull approximation mindiff     // APX5,2, pcrit 
//                                                    // Weibull approximation a           // APX5,3, pcrit 
{
	FILE *in, *out;

	int iLauf, i_=0, i_2=0;
	double  jLauf=0, in_X[3][30001],p_crit,vektor[5],vektor_w[5],diff_=0,sum_=0,sum_2=0,mind=100000000,stp, stp1, 
		    b_, min_diff=100000000, stp_am=0, min_a=100000000, sw, min_w=0, sw1;
	char nil[10], in_q[10],in_qq[10];

	sw=    wert[2];
	p_crit=wert[3]; // pcrit < 0.5
	
	if(wert[1]!=3)stp=0.0001; // b incrementor
	if(wert[1]==3)stp=0.001; // df incrementor
	if(wert[1]==3)jLauf=1;
	stp1=0.001; // a incrementor

	in =fopen( "MAT_X.txt", "r" );
	out=fopen( "MAT_fn.txt", "w" );
		
	printf("\r                                                                         \r");

	while (feof (in) == 0)
	{
		fscanf(in,"%s%s%s%s",nil, nil, in_q, in_qq);

		if(wert[1]==5&&sw1==0){min_w=atof(in_q);sw1=1;}// weibull a 

		sum_+=atof(in_q);//SUM
		sum_2+=pow(atof(in_q),2);//SUM2
		i_2++;
			
		if(atof(in_qq)>=p_crit)//bei p>= pcrit
		{   
			i_++;
			in_X[1][i_]=atof(in_q); in_X[2][i_]=atof(in_qq); // approximations matrix
		}	
	}

	sum_-=atof(in_q);
	sum_2-=pow(atof(in_q),2);

	vektor[2]=sum_/i_2;//AM

	while(1)//a
	{
		while(1)//b
		{
			jLauf+=stp;
			vektor[3]=jLauf;//b

				  iLauf=0;
			while(iLauf<i_-1)
			{
				  iLauf++;
								                 vektor[1]=in_X[1][iLauf];//x
				if(wert[1]==0)diff_+=pL_funktion(vektor) - in_X[2][iLauf];                      //Laplace
				if(wert[1]==1)diff_+=pA_funktion(vektor) - in_X[2][iLauf];                      //Logistisch
				if(wert[1]==2)diff_+=pV_funktion(vektor) - in_X[2][iLauf];                      //Extremwert
				if(wert[1]==3)diff_+=pt_funktion(vektor[1]-vektor[2],vektor[3])-in_X[2][iLauf]; //t-wert
				if(wert[1]==4)diff_+=pC_funktion(vektor) - in_X[2][iLauf];                      //Cauchy
				if(wert[1]==5)                                                                  //Weibull 
				{
					                             vektor_w[1]=vektor[1]-min_w;//
				                                 vektor_w[2]=vektor[2]-min_w;//
				                                 vektor_w[3]=vektor[3];      //
				              diff_+=pW_funktion(vektor_w) - in_X[2][iLauf];                   
				}
				
				//if(jLauf==stp)fprintf(out,"%f\t%f\n",in_X[1][iLauf],in_X[2][iLauf]);
			}
		
			diff_/=(i_-1);
			diff_=fabs(diff_);

			if(mind>diff_)mind=diff_;
			if(mind<diff_)break;

			if(wert[1]<=2)printf("a= %.4f b= %.4f",vektor[2], jLauf);
			if(wert[1]==3)printf("df= %.4f p-diff= %.10f\r",jLauf, diff_);
			if(wert[1]==4)printf("eta= %.4f theta= %.4f",vektor[2], jLauf);
			if(wert[1]==5)printf("b= %.4f c= %.4f",vektor_w[2], jLauf);
			if(wert[1]!=3)if(min_diff!=100000000)printf(" p-diff= %.10f\r",min_diff);
			else printf("\r");

			diff_=0;
		}
		
		if(wert[1]==3) //t
		{
			b_=jLauf-stp;
			min_diff=mind;
			min_a=0;break;
		}

		if(min_diff>mind)
		{
			min_diff=mind;
			if(vektor[2]<=sum_/i_2)stp_am=-stp1;
			if(vektor[2]> sum_/i_2)stp_am= stp1; 
		}
		
		if(min_diff<mind)
		{
			if(vektor[2]> sum_/i_2)break; 
			if(vektor[2]< sum_/i_2)vektor[2]=sum_/i_2+2*stp1;
		}

		if(min_a>vektor[2])min_a=vektor[2];

		vektor[2]=vektor[2]+stp_am;
		
		b_=jLauf-stp;jLauf=0;
		mind=100000000;

	}
	printf("\r                                                                         \r");

	//printf("a=%.14f  b=%f  diff=%.10f %i\n",min_a,b_,min_diff , i_);

	if(wert[1]==0)fprintf(out,"Kurvenanpassung, Laplace-Funktion L\n");
	if(wert[1]==1)fprintf(out,"Kurvenanpassung, Logistische-Funktion A\n");
	if(wert[1]==2)fprintf(out,"Kurvenanpassung, Extremwert-Funktion V\n");
	if(wert[1]==3)fprintf(out,"Kurvenanpassung, t-Wert Funktion t\n");
	if(wert[1]==4)fprintf(out,"Kurvenanpassung, Cauchy-Funktion C\n");
	if(wert[1]==5)fprintf(out,"Kurvenanpassung, Weibull-Funktion W\n");
	fprintf(out,"----------------------------------------\n");
	fprintf(out,"\tAM\ts\tn\tpcrit\n");
	fprintf(out,"----------------------------------------\n");
	fprintf(out,"q\t%.3f\t%.3f\t%i\t%.3f\n",sum_/i_2,sqrt(sum_2/i_2-pow(sum_/i_2,2)),i_,p_crit);
	fprintf(out,"----------------------------------------\n");
	if(wert[1]<=2)fprintf(out,"\ta\tb\tp-diff\n");
	if(wert[1]==3)fprintf(out,"\t \tdf\tp-diff\n");
	if(wert[1]==4)fprintf(out,"\teta\ttheta\tp-diff\n");
	if(wert[1]==5)fprintf(out,"\tb\tc\tp-diff\n");
	fprintf(out,"----------------------------------------\n");
	if(wert[1]==0)fprintf(out,"L\t");
	if(wert[1]==1)fprintf(out,"A\t");
	if(wert[1]==2)fprintf(out,"V\t");
	if(wert[1]==3)fprintf(out,"t\t");
	if(wert[1]==4)fprintf(out,"C\t");
	if(wert[1]==5)fprintf(out,"W\t");
	if(wert[1]!=3)fprintf(out,"%.3f\t%.3f",min_a-min_w,b_);
	if(wert[1]==3)fprintf(out," \t%.3f",b_);
	fprintf(out,"\t%.10f\n",min_diff);
	fprintf(out,"----------------------------------------\n");
	if(wert[1]==5&&min_w<0)fprintf(out,"*)W=x+%.3f\n\n",-min_w);
	if(wert[1]==5&&min_w>=0)fprintf(out,"*)W=x%.3f\n\n",-min_w);
	fprintf(out,"SCHRAUSSER-MAT");
	
	fclose(in);
	fclose(out);
	
	if(sw==0)fn_erg=b_;
	if(sw==1)fn_erg=min_a-min_w;
	if(sw==2)fn_erg=min_diff;
	if(sw==3&&wert[1]==5)fn_erg=-min_w;

	return 0;
};

double fn_bn_sim(double wert[100])// binomialsimulation //          // BSMsw, M, a, p, k, n  
//                                                      //  mk                                // BSM 0, 
//                                                      //  am_k=am_bn                        // BSM 1,
//                                                      //  P(nk/M)                           // BSM 2,
//                                                      //  p(nk/M)                           // BSM 3,
//                                                      //  pdiff                             // BSM 4,
//                                                      //  binomialverteilter zufallsvektor  // BSM 5,
//                                                      //  BSM5, 1000, 0,  0.5, 5, 10 
{
	FILE *out;

	int iLauf, jLauf, kLauf;
	long double zlr=0, k_, n_n, n_a, n_[1000], n_a_zlr=0, n_a_tot=0, n_b_tot=0, sd, M_, p_=0, n_c=0, zzlr=0, PZ, seed, sw, 
		        vektor[5],diff,diff_sum=0, P_,PB=0, PM=0;//n_b,

	PZ=		wert[4]*100; //p(a)= PZ/100  
	k_=		wert[5];     //k
	n_n=	wert[6];     //n 
	M_=		wert[2];     //Simulationszyklen M 
	     sd=wert[3];     //seed
	if(  sd==0) 
	     sd=(time(0)-1234567890);
	seed=sd;
	sw=		wert[1];    //ausgabe schalter

	vektor[1]= wert[4]; //Binomialfunktions-argumentvektor
	vektor[2]= k_;
	vektor[3]= n_n;

	out=fopen( "MAT_fn.txt", "w" );
	
	for(iLauf=0;iLauf<=n_n;iLauf++) n_[iLauf]=0;//mk vektor auf 0-vektor

	printf("\r                                                   ");
	printf("\rM< 100,000");

	for(jLauf=1;jLauf<=M_;jLauf++) //über  Simulationszyklen M
	{
		for(kLauf=1;kLauf<=n_n;kLauf++) //über Design n
		{
			                             n_a= qzufall(sd,0,100);sd=sqrt(n_a)*1234; //gleichverteilte zufallsvariable
			                   //n_b=n_n-n_a;
			                          if(n_a<=PZ)n_a_zlr++; //bei p=PZ/100
		}

		if(sw==5 && jLauf<=66000)fprintf(out,"%.0f\n",n_a_zlr);
	
		for(iLauf=0;iLauf<=n_n;iLauf++) {if(zlr==n_a_zlr ) n_[iLauf]++;zlr++;} //wie oft n_a bei durchgang über n
		                                                              zlr=0;
	                                    n_a_tot+=n_a_zlr;
		                            n_b_tot+=n_n-n_a_zlr;
								                 n_a_zlr=0;
								 
		if(zzlr==100000) //M zähler
		{
			printf("\rM> %i00,000", jLauf/100000);zzlr=0;
		}

		zzlr++;
	}

	printf("\r                              \r");
	
	if(sw<5) //ergebnistabelle
	{	
		fprintf(out,"Binomialsimulation, M= %.0f, seed= %.0f\n", M_, sd);	
		fprintf(out,"---------------------------------------------------------------------------\n");
		fprintf(out,"\t\tk=a\t\tb\t\tn\n");
		fprintf(out,"---------------------------------------------------------------------------\n");
		fprintf(out,"pz\t\t%.3f\t\t%.3f\t\t1.000\n", wert[4],1-wert[4]);
		fprintf(out,"f\t\t%.0f\t\t%.0f\t\t%.0f\n", k_,n_n-k_, n_n);
		fprintf(out,"pf\t\t%.3f\t\t%.3f\t\t%.3f\n", k_/n_n,(n_n-k_)/n_n, n_n/n_n);
		fprintf(out,"fe\t\t%.0f\t\t%.0f\t\t%.0f\n", n_n*wert[4],n_n-n_n*wert[4], n_n);
		fprintf(out,"pfe\t\t%.3f\t\t%.3f\t\t%.3f\n", (n_n*wert[4])/n_n,(n_n-n_n*wert[4])/n_n, n_n/n_n);
		fprintf(out,"m\t\t%10.0f\t%10.0f\t%10.0f\n", n_a_tot,n_b_tot,n_a_tot+n_b_tot);
		fprintf(out,"f(m/M)\t\t%.3f\t\t%.3f\t\t%.3f\n", n_a_tot/M_,n_b_tot/M_, (n_a_tot+n_b_tot)/M_);
		fprintf(out,"p(m/n/M)\t%.8f\t%.8f\t%.8f\n", n_a_tot/M_/n_n,n_b_tot/M_/n_n,(n_a_tot+n_b_tot)/(M_*n_n));
		fprintf(out,"---------------------------------------------------------------------------\n");
		fprintf(out,"k\t\tPk\t\tmk\t\tP(mk/M)\t\tP(diff)\n");
		fprintf(out,"---------------------------------------------------------------------------\n");
		for(iLauf=0;iLauf<=n_n;iLauf++) 
		{
			if(n_[iLauf]/M_>0)
			{
				fprintf(out,"%i\t\t",iLauf);
				if(n_n<=500) 
				{
												     vektor[2]=n_c;
									     P_=fn_binom(vektor, 2);
					fprintf(out,"%.8f\t",P_);
								     PB+=P_;
				}
				if(n_n>500)fprintf(out,"---\t");
				
				fprintf(out,"%10.0f\t",n_[iLauf]);
				fprintf(out,"%.8f\t",n_[iLauf]/M_);
								 PM+=n_[iLauf]/M_;
				if(n_n<=500)
				{
													 diff=n_[iLauf]/M_-P_;
					if(diff<0) fprintf(out,"%.8f\t", diff);
					if(diff>=0)fprintf(out,"+%.8f\t",diff);
										   diff_sum+=diff;
				}
				if(n_n>500)fprintf(out,"---\t");

				fprintf(out,"\n");
			}
			n_c++;
		}

		fprintf(out,"\t\t----------\t----------\t----------\t-----------\n");
		fprintf(out,"sum\t\t%.8f\t%10.0f\t%.8f\t", PB, M_, PM);
		if(diff_sum<0.00000000)fprintf(out,"%.8f\n", diff_sum);
		if(diff_sum>0.00000001){fprintf(out,"+%.8f\n", diff_sum);}
		else {fprintf(out,"\xb1%.8f\n", diff_sum);}
		fprintf(out,"---------------------------------------------------------------------------\n");
		fprintf(out,"SCHRAUSSER-MAT");
	}
	
	fclose(out);
	
	fn_erg=0;

	if(sw==0){for(iLauf=0;iLauf<k_;iLauf++); fn_erg=n_[iLauf];	                         } //mk
	if(sw==1) fn_erg=n_a_tot/M_;	                                                               //am_k = am_bn
	if(sw==2){for(iLauf=0;iLauf<k_;iLauf++); fn_erg=n_[iLauf]/M_;                        } //P(mk/M)
	if(sw==3){for(iLauf=0;iLauf<=k_;iLauf++) fn_erg+=n_[iLauf]/M_;                       } //p(mk/M)
	if(sw==4&&n_n<=500)                                                                    //Pdiff
	{	                                                               vektor[2]=k_;
		for(iLauf=0;iLauf<k_;iLauf++); fn_erg=(n_[iLauf]/M_)- fn_binom(vektor, 2);
	} 
	if(sw==5) fn_erg=M_; 

	return 0;
};

double fn_hg_sim(double wert[100])//hypergeometrische simulation (2x2) // HSM sw, M, a, pk, pn, pK, k, n, K, N    
//                                                                     // am_a = am_hg                               // HSM 1,
//                                                                     // hypergeometrisch verteilter zufallsvektor  // HSM 4,            
//                                                                     // HSM4, 1000, 0, 0.25, 0.50, 0.50, 1, 2, 2, 4
//                                                                     //
//                                                                     // anm. P werte und k skala nicht passend, 
//                                                                     // kurvenform entspricht nach einpassung
{
	FILE *out;

	int  iLauf, M_zlr=0, sw2=0 ;
	double jLauf, ind=0, n_[1000], M_, k_, K_,N_,n__, a_=0,b_=0,c_=0,d_=0,n_a,n_b,n_c,n_d,n_a_zlr=0,n_b_zlr=0,n_b_zlr1=0,n_c_zlr=0,n_c_zlr1=0,
			n_d_zlr=0,n_d_zlr1=0,sd,sw=1, sw1, xzlr=0,zlr=0,
		    amin,a_m_a_x, bmin,bmax,cmin,cmax,dmin,dmax, vektor[10], max, p_=0, am_a=0, am_b=0,am_c=0,am_d=0,
			PZa,PZb,PZc,PZd,fea,feb,fec,fed, Pi, pi=0;//z1_,

	out=fopen( "MAT_fn.txt", "w" );

	sw1= wert[1]; //outputschalter

	   sd=wert[3];
	if(sd==0) sd=(time(0)-1234567890); //seed
	
	//häufigkeiten
	k_=wert[7]; //k=a
	n__=wert[8];  //n
	K_ =wert[9];  //K
	N_ =wert[10];  //N

	M_ =wert[2];  //simulationszyklen M

	//feldwahrscheinlichkeiten pz
	PZa=100*wert[4];             PZb=100*(wert[6]-wert[4]);
	PZc=100*(wert[5]-wert[4]);   PZd=100*(1-wert[4]-(wert[6]-wert[4])-(wert[5]-wert[4]));

	//erwartete frequenzen
	fea=( n__    *    K_)/N_;
	feb=((N_-n__)*    K_)/N_;
	fec=( n__    *(N_-K_))/N_;
	fed=((N_-n__)*(N_-K_))/N_;


				  vektor[1]=K_;
				  vektor[2]=n__;
	max= fn_sort(vektor,2,2);

	// minimalrandfrequezen als maximalhäufigkeit
	if(K_>=n__)a_m_a_x=n__;else a_m_a_x=K_;

				  vektor[1]=K_;
				  vektor[2]=N_-n__;
	bmax= fn_sort(vektor,2,1);

				  vektor[1]=n__;
				  vektor[2]=N_-K_;
	cmax= fn_sort(vektor,2,1);

				  vektor[1]=N_-n__;
				  vektor[2]=N_-K_;
	dmax= fn_sort(vektor,2,1);

	//minimalhäufigkeiten

	amin=a_m_a_x;
	for(jLauf=a_m_a_x;jLauf>=0;jLauf--)
	{
		if(K_-jLauf<0||
		   n__-jLauf<0||
		  (N_)-((K_)-jLauf)-((n__)-jLauf)-jLauf<0
			)
		{amin++;break;}
		
		amin--;	
	}

	bmin=bmax;
	for(jLauf=bmax;jLauf>=0;jLauf--)
	{
		if(K_-jLauf<0||
		   N_-n__-jLauf<0||
		  (N_)-((K_)-jLauf)-((N_-n__)-jLauf)-jLauf<0
			)
		{bmin++;break;}
		
		bmin--;	
	}

	cmin=cmax;
	for(jLauf=cmax;jLauf>=0;jLauf--)
	{
		if(n__-jLauf<0||
		   N_-K_-jLauf<0||
		  (N_)-((n__)-jLauf)-((N_-K_)-jLauf)-jLauf<0
			)
		{cmin++;break;}
		
		cmin--;	
	}

	dmin=dmax;
	for(jLauf=dmax;jLauf>=0;jLauf--)
	{
		if(N_-n__-jLauf<0||
		   N_-K_-jLauf<0||
		  (N_)-((N_-n__)-jLauf)-((N_-K_)-jLauf)-jLauf<0
			)
		{dmin++;break;}
		
		dmin--;	
	}

	for(iLauf=0;iLauf<=1000;iLauf++) n_[iLauf]=0;//mk vektor auf 0-vektor

	printf("\r                                                                    \r");

	while(M_zlr<M_)// über simulationszyklen M
	{
		for(iLauf=1;iLauf<=a_m_a_x;iLauf++)     //a von a
		{	
			n_a= qzufall(sd,0,100);sd=sqrt(n_a)*1234;
			if(n_a<=(fea/N_)*100)n_a_zlr++;     //pfea // auswahlfilter, alternativ über zellen pz denkbar //
		}
			
		n_a=n_a_zlr;                            //a zlr
			     n_b=K_-n_a;	                //b zlr
		n_b_zlr1=n_b;	
				 n_c=n__-n_a;	                //c zlr
		n_c_zlr1=n_c;
				n_d=N_-n_a-(K_-n_a)-(n__-n_a);	//d zlr
		n_d_zlr1=n_d;
		
		if(n_a_zlr<amin)sw=0;                   //a < amin schalter

		if(sw==1)
		{
			for(iLauf=1;iLauf<=bmax;iLauf++)    //a von b
			{
				n_b= qzufall(sd,0,100);sd=sqrt(n_b)*1234;
				if(n_b<=(feb/N_)*100)n_b_zlr++; //pfeb // auswahlfilter, alternativ über zellen pz denkbar //
			}
			if(n_b_zlr<bmin)sw=0;               //b < bmin schalter
			
			n_a_zlr+=(K_)-(n_b_zlr);            //a zlr
			n_b_zlr1+=n_b_zlr;	                //b zlr
					  n_c=n__-(K_-(n_b_zlr));   //c zlr
			n_c_zlr1+=n_c;
					  n_d=N_-((K_)-(n_b_zlr))-n_b_zlr-(n__-(K_-(n_b_zlr))); //d zlr
			n_d_zlr1+=n_d;
		}

		if(sw==1)
		{
			for(iLauf=1;iLauf<=cmax;iLauf++)   //a von c
			{
				n_c= qzufall(sd,0,100);sd=sqrt(n_c)*1234;
				if(n_c<=(fec/N_)*100)n_c_zlr++;//pfec // auswahlfilter, alternativ über zellen pz denkbar //
			}
			if(n_c_zlr<cmin)sw=0;              //c < cmin schalter
			n_a_zlr+=(n__)-n_c_zlr;            //a zlr
			          n_b=K_-((n__)-n_c_zlr);  //b zlr
			n_b_zlr1+=n_b;
			n_c_zlr1+=n_c_zlr;	               //c zlr
					  n_d=N_-((n__)-n_c_zlr)-(K_-((n__)-n_c_zlr))-(n_c_zlr); //d zlr
			n_d_zlr1+=n_d;
		}
	
		if(sw==1)
		{
			for(iLauf=1;iLauf<=dmax;iLauf++)  //a von d
			{
				n_d= qzufall(sd,0,100);sd=sqrt(n_d)*1234;
				if(n_d<=(fed/N_)*100)n_d_zlr++;//pfed // auswahlfilter, alternativ über zellen pz denkbar //
			}
			if(n_d_zlr<dmin)sw=0;             //d < dmin schalter

			n_a_zlr+=(K_)-((N_-n__)-n_d_zlr); //a zlr
                      n_b=K_-((K_)-((N_-n__)-n_d_zlr));	//b zlr
			n_b_zlr1+=n_b;
					  n_c=n__-((K_)-((N_-n__)-n_d_zlr));//c zlr
			n_c_zlr1+=n_c;
			n_d_zlr1+=n_d_zlr;	              //d zlr
		}
		
		if(sw==1)
		{
			printf("\rM=%i",M_zlr);

			if(sw1==4&&M_zlr<=66000)fprintf(out,"%.2f\n",n_a_zlr/4.0);//zufalls-vektor ausgabe
			
			for(iLauf=0;iLauf<=max*4+10;iLauf++) {if(zlr==n_a_zlr ) n_[iLauf]++;zlr++;} //wie oft n_a bei durchgang über n
																			    zlr=0;
			am_a+=n_a_zlr;  //na summierung
			am_b+=n_b_zlr1; //nb summierung
			am_c+=n_c_zlr1; //nc summierung
			am_d+=n_d_zlr1; //nd summierung
											
			M_zlr++; //simulationszykleninkrementor
		}
		sw=1;
			
		n_a_zlr=n_b_zlr=n_b_zlr1=n_c_zlr=n_c_zlr1=n_d_zlr=n_d_zlr1=0;//zähler auf null
	}
	printf("\r                                             \r");

	if(sw1!=4) //ergebnistabelle
	{
		fprintf(out,"Hypergeometrische Simulation, M= %.0f, seed= %.0f\n", M_, sd);	
		fprintf(out,"--------------------------------------------------------------------------------------------------------------------------\n");
		fprintf(out,"\t\tk=a\t\tb\t\tK=a+b\t\tc\t\tn=a+c\t\td\t\tN=a+b+c+d\n");
		fprintf(out,"--------------------------------------------------------------------------------------------------------------------------\n");
		fprintf(out,"pz\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t1.000\n", wert[4],wert[6]-wert[4],wert[6],wert[5]-wert[4],wert[5],1-wert[4]-(wert[6]-wert[4])-(wert[5]-wert[4]), wert[7] );
		fprintf(out,"f\t\t%.0f\t\t%.0f\t\t%.0f\t\t%.0f\t\t%.0f\t\t%.0f\t\t%.0f\n", k_,K_-k_,K_,n__-k_,n__, N_-k_-(K_-k_)-(n__-k_),N_);
		fprintf(out,"pf\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", k_/N_,(K_-k_)/N_,K_/N_,(n__-k_)/N_,n__/N_, (N_-k_-(K_-k_)-(n__-k_))/N_,N_/N_);
		fprintf(out,"fe\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", fea,feb,K_,fec,n__,fed,N_);
		fprintf(out,"pfe\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", fea/N_,feb/N_,K_/N_,fec/N_,n__/N_,fed/N_,N_/N_);
		fprintf(out,"m\t\t%10.0f\t%10.0f\t%10.0f\t%10.0f\t%10.0f\t%10.0f\t%10.0f\n", am_a,am_b,am_a+am_b,am_c,am_a+am_c,am_d,am_a+am_b+am_c+am_d);
		fprintf(out,"f(m/4/M)\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n",am_a/4/M_,am_b/4/M_,(am_a+am_b)/4/M_,am_c/4/M_,(am_a+am_c)/4/M_,am_d/4/M_,(am_a+am_b+am_c+am_d)/4/M_);
		fprintf(out,"p(m/4/M/N)\t%.8f\t%.8f\t%.8f\t%.8f\t%.8f\t%.8f\t%.8f\n",am_a/4/N_/M_,am_b/4/N_/M_,(am_a+am_b)/4/N_/M_,am_c/4/N_/M_,(am_a+am_c)/4/N_/M_,am_d/4/N_/M_,M_/M_);
		fprintf(out,"--------------------------------------------------------------------------------------------------------------------------\n");
		fprintf(out,"k\t\tPk\t\tpk\t\tmk\t\tP(mk/M)\t\tp(mk/M)\n");
		fprintf(out,"--------------------------------------------------------------------------------------------------------------------------\n");
		
		for(iLauf=0;iLauf<=1000;iLauf++) 
		{
			vektor[1]=ind;			vektor[2]=K_-ind;
			vektor[3]=n__-ind;		vektor[4]=N_-ind-(K_-ind)-(n__-ind);
			
			                   Pi=0;
			if(ind==floor(ind))Pi=fn_2khg(vektor, 4);
			               pi+=Pi;
			
			p_+=(n_[iLauf])/(M_);
			
			if(n_[iLauf]>0)fprintf (out,"%.2f\t\t%f\t%f\t%10.0f\t%f\t%f\n",
				ind,
				Pi,
				pi,
				n_[iLauf],
				(n_[iLauf])/(M_),
				p_);
			
			ind+=1/4.;
		}
		fprintf(out,"--------------------------------------------------------------------------------------------------------------------------\n");
		fprintf(out,"SCHRAUSSER-MAT");
	}

	fclose(out);

	fn_erg=am_a/M_/4.0; //am_hg 

	return 0;
};

double fn_lto(double wert[100], double zn)// Lotto Simulation // LTO k,N, z1,z2,z3,z4,z5,z6
{
	int  iLauf, jLauf,  hub=0, sw=0, x=0, sd_zlr=0 ;
	double  srt0[100], srt[100], rnd_[100], z_[10], sd, zlr[10], N, min, i_=1, z_wert[100], k;
	
	if(wert[1]>6)fn_erg=fn_lto_1(wert);

	if(wert[1]<=6)
	{
		k=wert[1];
		N=wert[2];//max

		if (k<0 || k>6)  {printf("\n\ndesign.0 '0<=k<=6'");  exit(0);}
		if (zn != 8)     {printf("\n\ndesign.0 'n'");        exit(0);}
		if (N<45 || N>49){printf("\n\ndesign.0 '45<=N<=49'");exit(0);}

		for(iLauf=1; iLauf<=6; iLauf++) wert[iLauf+2]=floor(wert[iLauf+2]); // ggf auf ganze zahl abrunden

		if( wert[1+2]==wert[2+2] ||
			wert[1+2]==wert[3+2] ||
			wert[1+2]==wert[4+2] ||
			wert[1+2]==wert[5+2] ||
			wert[1+2]==wert[6+2] ||
			wert[2+2]==wert[3+2] ||
			wert[2+2]==wert[4+2] ||
			wert[2+2]==wert[5+2] ||
			wert[2+2]==wert[6+2] ||
			wert[3+2]==wert[4+2] ||
			wert[3+2]==wert[5+2] ||
			wert[3+2]==wert[6+2] ||
			wert[4+2]==wert[5+2] ||
			wert[4+2]==wert[6+2] ||
			wert[5+2]==wert[6+2] 
			)
		{ printf("\n\ndesign.0 'z=z'");exit(0); } //zahlen nicht verschieden

		for(iLauf=1; iLauf<=6; iLauf++) if(wert[iLauf+2]>N) {sw=1; break;}  
														  if(sw==1){printf("\n\ndesign.0 'z>%.0f'", N);exit(0);}//zahl > max

		for(iLauf=1; iLauf<=6; iLauf++) if(wert[iLauf+2]<=0) {sw=1; break;}  
														   if(sw==1){printf("\n\ndesign.0 'z<1'");exit(0);}//zahl < 1

		for(iLauf=1; iLauf<=N;iLauf++){z_wert[iLauf]=i_; i_++;} //z_wert= 1-6
		for(iLauf=1; iLauf<=N;iLauf++) zlr[iLauf]=0; //zlr= 0
			
		sd=(time(0)-1234567890); 

		printf("\n\n");
		
		while(1)
		{
			// randomisierte permutation
			for(iLauf=1; iLauf<=N;iLauf++){srt0[iLauf]=qzufall(sd,0,1);sd=srt0[iLauf];}

			min=srt0[1]; 
			for (iLauf = 1; iLauf <= N; iLauf++)if(srt0[iLauf]<min)min=srt0[iLauf];
					
			srt[1] = min;//anfangswert=minimalwert

			for (iLauf = 1; iLauf <= N; iLauf++)//sortierung
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
				rnd_[(iLauf+1)-hub] = z_wert[iLauf];hub=0;
			}

			for (iLauf = 2; iLauf <= N+1; iLauf++)rnd_[iLauf-1]=rnd_[iLauf];//laufindexkorrektur
			rnd_[iLauf-1]=0;
				
			sd= qzufall(sd,0,1);//sd

			// anfangswert neusetzung nach n= 1500000 wegen zyklizität (zu ca. n= 7,000,000)
			if (sd_zlr>=1500000){sd=(time(0)-1234567890); sd_zlr=0;} 
				
			// bildschirmausgabe
			printf("\r%2.0f %2.0f %2.0f %2.0f %2.0f %2.0f", rnd_[1],rnd_[2],rnd_[3],rnd_[4],rnd_[5],rnd_[6]);

			// vergleich auf x<=6 der n=6 zu m=k kombinationen Cnm der ersten n=6 werte des randomisierten permutationsvektors p 

			// 0|6|6|N 
			if(k==0)
			if(!(rnd_[1]<=6 || rnd_[2]<=6 || rnd_[3]<=6 || rnd_[4]<=6 || rnd_[5]<=6 || rnd_[6]<=6)) x=1;
				
			// 1|6|6|N 
			if(k==1)
			if(rnd_[1]<=6 || rnd_[2]<=6 || rnd_[3]<=6 || rnd_[4]<=6 || rnd_[5]<=6 || rnd_[6]<=6) x=1;
				
			// 2|6|6|N
			if(k==2)
			if( rnd_[1]<=6 && rnd_[2]<=6 ||
				rnd_[1]<=6 && rnd_[3]<=6 ||
				rnd_[1]<=6 && rnd_[4]<=6 ||
				rnd_[1]<=6 && rnd_[5]<=6 ||
				rnd_[1]<=6 && rnd_[6]<=6 ||
				rnd_[2]<=6 && rnd_[3]<=6 ||
				rnd_[2]<=6 && rnd_[4]<=6 ||
				rnd_[2]<=6 && rnd_[5]<=6 ||
				rnd_[2]<=6 && rnd_[6]<=6 ||
				rnd_[3]<=6 && rnd_[4]<=6 ||
				rnd_[3]<=6 && rnd_[5]<=6 ||
				rnd_[3]<=6 && rnd_[6]<=6 ||
				rnd_[4]<=6 && rnd_[5]<=6 ||
				rnd_[4]<=6 && rnd_[6]<=6 ||
				rnd_[5]<=6 && rnd_[6]<=6  ) x=1;
				
			// 3|6|6|N
			if(k==3)
			if(
				rnd_[1]<=6 && rnd_[2]<=6 && rnd_[3]<=6  ||
				rnd_[1]<=6 && rnd_[2]<=6 && rnd_[4]<=6  ||
				rnd_[1]<=6 && rnd_[2]<=6 && rnd_[5]<=6  ||
				rnd_[1]<=6 && rnd_[2]<=6 && rnd_[6]<=6  ||
				rnd_[1]<=6 && rnd_[3]<=6 && rnd_[4]<=6  ||
				rnd_[1]<=6 && rnd_[3]<=6 && rnd_[5]<=6  ||
				rnd_[1]<=6 && rnd_[3]<=6 && rnd_[6]<=6  ||
				rnd_[1]<=6 && rnd_[4]<=6 && rnd_[5]<=6  ||
				rnd_[1]<=6 && rnd_[4]<=6 && rnd_[6]<=6  ||
				rnd_[1]<=6 && rnd_[5]<=6 && rnd_[6]<=6  ||
				rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6  ||
				rnd_[2]<=6 && rnd_[3]<=6 && rnd_[5]<=6  ||  
				rnd_[2]<=6 && rnd_[3]<=6 && rnd_[6]<=6  ||
				rnd_[2]<=6 && rnd_[4]<=6 && rnd_[5]<=6  ||
				rnd_[2]<=6 && rnd_[4]<=6 && rnd_[6]<=6  ||
				rnd_[2]<=6 && rnd_[5]<=6 && rnd_[6]<=6  ||
				rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6  ||
				rnd_[3]<=6 && rnd_[4]<=6 && rnd_[6]<=6  ||
				rnd_[3]<=6 && rnd_[5]<=6 && rnd_[6]<=6  ||
				rnd_[4]<=6 && rnd_[5]<=6 && rnd_[6]<=6   ) x=1;
				
			// 4|6|6|N
			if(k==4)
			if(
				rnd_[1]<=6 && rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6 ||
				rnd_[1]<=6 && rnd_[2]<=6 && rnd_[3]<=6 && rnd_[5]<=6 ||
				rnd_[1]<=6 && rnd_[2]<=6 && rnd_[3]<=6 && rnd_[6]<=6 ||
				rnd_[1]<=6 && rnd_[2]<=6 && rnd_[4]<=6 && rnd_[5]<=6 ||
				rnd_[1]<=6 && rnd_[2]<=6 && rnd_[4]<=6 && rnd_[6]<=6 ||
				rnd_[1]<=6 && rnd_[2]<=6 && rnd_[5]<=6 && rnd_[6]<=6 ||
				rnd_[1]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6 ||
				rnd_[1]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[6]<=6 ||
				rnd_[1]<=6 && rnd_[3]<=6 && rnd_[5]<=6 && rnd_[6]<=6 ||
				rnd_[1]<=6 && rnd_[4]<=6 && rnd_[5]<=6 && rnd_[6]<=6 ||
				rnd_[1]<=6 && rnd_[2]<=6 && rnd_[4]<=6 && rnd_[6]<=6 ||
				rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6 ||  
				rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6 ||
				rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[6]<=6 ||
				rnd_[2]<=6 && rnd_[3]<=6 && rnd_[5]<=6 && rnd_[6]<=6 ||
				rnd_[2]<=6 && rnd_[4]<=6 && rnd_[5]<=6 && rnd_[6]<=6 ||
				rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6 && rnd_[6]<=6  ) x=1;

			// 5|6|6|N
			if(k==5)
			if(
				rnd_[1]<=6 && rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6  ||
				rnd_[1]<=6 && rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[6]<=6  ||
				rnd_[1]<=6 && rnd_[2]<=6 && rnd_[3]<=6 && rnd_[5]<=6 && rnd_[6]<=6  ||
				rnd_[1]<=6 && rnd_[2]<=6 && rnd_[4]<=6 && rnd_[5]<=6 && rnd_[6]<=6  ||
				rnd_[1]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6 && rnd_[6]<=6  ||
				rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6 && rnd_[6]<=6   )x=1;

			// 6|6|6|N
			if(k==6)
			if(rnd_[1]<=6 && rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6 && rnd_[6]<=6) x=1; 
			
			zlr[9]++; sd_zlr++;
			
			if(x==1) break;
		}

		// zahlenzuordnung	
		for(iLauf=1;iLauf<=6; iLauf++)	z_[iLauf]=rnd_[iLauf];

		for(iLauf=1;iLauf<=6; iLauf++) if(rnd_[iLauf]==wert[1+2])z_[iLauf]=1;
		for(iLauf=1;iLauf<=6; iLauf++) if(rnd_[iLauf]==wert[2+2])z_[iLauf]=2;
		for(iLauf=1;iLauf<=6; iLauf++) if(rnd_[iLauf]==wert[3+2])z_[iLauf]=3;
		for(iLauf=1;iLauf<=6; iLauf++) if(rnd_[iLauf]==wert[4+2])z_[iLauf]=4;
		for(iLauf=1;iLauf<=6; iLauf++) if(rnd_[iLauf]==wert[5+2])z_[iLauf]=5;
		for(iLauf=1;iLauf<=6; iLauf++) if(rnd_[iLauf]==wert[6+2])z_[iLauf]=6;
		
		for(iLauf=1;iLauf<=6; iLauf++)
		for(jLauf=1;jLauf<=6; jLauf++) if(rnd_[iLauf]==jLauf) z_[iLauf]=wert[jLauf+2];

		
		// bildschirmausgabe
		printf("\r%2.0f %2.0f %2.0f %2.0f %2.0f %2.0f ", z_[1],z_[2],z_[3],z_[4],z_[5],z_[6]);

		fn_erg= zlr[9];
	}
	
	return 0;
};


long double fn_lto_1(double wert[100])//  Lotto Simulation 2  //  LTO 45,3000000, 1,2,3,4,5,6  
//                                        unter Mitwirkung von
// 	                                      (verrücktem) Lottoprofessor PProf. Sebastian S. Ecksehr und
//                                        (ewigem) Assistenten Emil Quintniktz												                                     
{
	FILE *out;
	int  iLauf, jLauf,  hub=0, sw=1, x0=0, x1=0, x2=0, x3=0, x4=0,x5=0,x6=0, sd_zlr=0 ;
	double  hgw[10], vektor[10], srt0[100], srt[100], rnd_[100], z_[10], sd,  p=0,zlr[50], x_zlr8=0, x_zlr82=0, addp=0,
			addp2=0,M,N,  min, i_=1, z_wert[100], Ef=0, sf=0,pdiff;//flauf[10]

	N=wert[1];//max
	M=wert[2];

	if (N<10 || N>90){printf("\n\ndesign.0 '10<=N<=90'\n");exit(0);}

	for(iLauf=1; iLauf<=6; iLauf++) wert[iLauf+2]=floor(wert[iLauf+2]); // ggf auf ganze zahl abrunden

	if( wert[1+2]==wert[2+2] ||
		wert[1+2]==wert[3+2] ||
		wert[1+2]==wert[4+2] ||
		wert[1+2]==wert[5+2] ||
		wert[1+2]==wert[6+2] ||
		wert[2+2]==wert[3+2] ||
		wert[2+2]==wert[4+2] ||
		wert[2+2]==wert[5+2] ||
		wert[2+2]==wert[6+2] ||
		wert[3+2]==wert[4+2] ||
		wert[3+2]==wert[5+2] ||
		wert[3+2]==wert[6+2] ||
		wert[4+2]==wert[5+2] ||
		wert[4+2]==wert[6+2] ||
		wert[5+2]==wert[6+2] 
		)
		{printf("\n\ndesign.0 'z=z'\n");exit(0);} //zahlen nicht verschieden

	if( wert[1+2]>N ||
		wert[2+2]>N ||
		wert[3+2]>N ||
		wert[4+2]>N ||
		wert[5+2]>N ||
		wert[6+2]>N
		)
		{printf("\n\ndesign.0 'z>%.0f'\n", N);exit(0);} //zahl > max

	if( wert[1+2]<=0 ||
		wert[2+2]<=0 ||
		wert[3+2]<=0 ||
		wert[4+2]<=0 ||
		wert[5+2]<=0 ||
		wert[6+2]<=0 
		)
		{printf("\n\ndesign.0 'z<1'\n");exit(0);} //zahl < 1

	for(iLauf=1; iLauf<=N;iLauf++){z_wert[iLauf]=i_; i_++;}
	for(iLauf=0; iLauf<=50;iLauf++)zlr[iLauf]=0;
		
	sd=(time(0)-1234567890); 

	out=fopen( "MAT_fn.txt", "w" );
	
	fprintf(out,"Lotto Simulation, n=K=6, N=%.0f, M=%.0f, seed=%.0f\n",N,M,sd);
	fprintf(out,"--------------------------------------------------------------------------\n");
	fprintf(out,"\t\t\t\t%2.0f\t%2.0f\t%2.0f\t%2.0f\t%2.0f\t%2.0f\n",wert[3],wert[4],wert[5],wert[6],wert[7],wert[8]);
	fprintf(out,"--------------------------------------------------------------------------\n");

	printf("\r                                                  \r");

	//for(iLauf=1; iLauf<=8;iLauf++) srt0[iLauf]=wert[iLauf];
	
	while(zlr[9]<= M)// Randomisierte Permutation
	{
		for(iLauf=1; iLauf<=N;iLauf++){srt0[iLauf]=qzufall(sd,0,1);sd=srt0[iLauf];}

		min=srt0[1]; 
		for (iLauf = 1; iLauf <= N; iLauf++)if(srt0[iLauf]<min)min=srt0[iLauf];
				
		srt[1] = min;//anfangswert=minimalwert

		for (iLauf = 1; iLauf <= N; iLauf++)//sortierung
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
			rnd_[(iLauf+1)-hub] = z_wert[iLauf];hub=0;
		}

		for (iLauf = 2; iLauf <= N+1; iLauf++)rnd_[iLauf-1]=rnd_[iLauf];//laufindexkorrektur
		rnd_[iLauf-1]=0;
			
		sd= qzufall(sd,0,1);
		//sd=sqrt(qzufall(sd,0,100))*1234;

		// anfangswert neusetzung nach n= 1500000 wegen zyklizität (zu ca. n= 7,000,000)
		if (sd_zlr>=1500000){sd=(time(0)-1234567890); sd_zlr=0;} 
				
		//for(iLauf=1; iLauf<=8;iLauf++) printf("%.f\t", rnd_[iLauf]);printf("\n");
	
		printf("\r%2.0f %2.0f %2.0f %2.0f %2.0f %2.0f", rnd_[1],rnd_[2],rnd_[3],rnd_[4],rnd_[5],rnd_[6]);

		printf(" %.0f  ", M-zlr[9]);//  \r
		// 0|6|6|45 
		if(!(rnd_[1]<=6 || rnd_[2]<=6 || rnd_[3]<=6 || rnd_[4]<=6 || rnd_[5]<=6 || rnd_[6]<=6))
			x0=1;

		// 1|6|6|45 (1- p(0|6|6|45))
		if(rnd_[1]<=6 || rnd_[2]<=6 || rnd_[3]<=6 || rnd_[4]<=6 || rnd_[5]<=6 || rnd_[6]<=6)
			x1=1;

		// 2|6|6|45
		if( rnd_[1]<=6 && rnd_[2]<=6 ||
			rnd_[1]<=6 && rnd_[3]<=6 ||
			rnd_[1]<=6 && rnd_[4]<=6 ||
			rnd_[1]<=6 && rnd_[5]<=6 ||
			rnd_[1]<=6 && rnd_[6]<=6 ||
			rnd_[2]<=6 && rnd_[3]<=6 ||
			rnd_[2]<=6 && rnd_[4]<=6 ||
			rnd_[2]<=6 && rnd_[5]<=6 ||
			rnd_[2]<=6 && rnd_[6]<=6 ||
			rnd_[3]<=6 && rnd_[4]<=6 ||
			rnd_[3]<=6 && rnd_[5]<=6 ||
			rnd_[3]<=6 && rnd_[6]<=6 ||
			rnd_[4]<=6 && rnd_[5]<=6 ||
			rnd_[4]<=6 && rnd_[6]<=6 ||
			rnd_[5]<=6 && rnd_[6]<=6
			) x2=1;

		// 3|6|6|45
		if(
			rnd_[1]<=6 && rnd_[2]<=6 && rnd_[3]<=6  ||
			rnd_[1]<=6 && rnd_[2]<=6 && rnd_[4]<=6  ||
			rnd_[1]<=6 && rnd_[2]<=6 && rnd_[5]<=6  ||
			rnd_[1]<=6 && rnd_[2]<=6 && rnd_[6]<=6  ||
			rnd_[1]<=6 && rnd_[3]<=6 && rnd_[4]<=6  ||
			rnd_[1]<=6 && rnd_[3]<=6 && rnd_[5]<=6  ||
			rnd_[1]<=6 && rnd_[3]<=6 && rnd_[6]<=6  ||
			rnd_[1]<=6 && rnd_[4]<=6 && rnd_[5]<=6  ||
			rnd_[1]<=6 && rnd_[4]<=6 && rnd_[6]<=6  ||
			rnd_[1]<=6 && rnd_[5]<=6 && rnd_[6]<=6  ||
			rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6  ||
			rnd_[2]<=6 && rnd_[3]<=6 && rnd_[5]<=6  ||  
			rnd_[2]<=6 && rnd_[3]<=6 && rnd_[6]<=6  ||
			rnd_[2]<=6 && rnd_[4]<=6 && rnd_[5]<=6  ||
			rnd_[2]<=6 && rnd_[4]<=6 && rnd_[6]<=6  ||
			rnd_[2]<=6 && rnd_[5]<=6 && rnd_[6]<=6  ||
			rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6  ||
			rnd_[3]<=6 && rnd_[4]<=6 && rnd_[6]<=6  ||
			rnd_[3]<=6 && rnd_[5]<=6 && rnd_[6]<=6  ||
			rnd_[4]<=6 && rnd_[5]<=6 && rnd_[6]<=6  
			)
		{
			x3=1;
		}

		// 4|6|6|45
		if(
			rnd_[1]<=6 && rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6 ||
			rnd_[1]<=6 && rnd_[2]<=6 && rnd_[3]<=6 && rnd_[5]<=6 ||
			rnd_[1]<=6 && rnd_[2]<=6 && rnd_[3]<=6 && rnd_[6]<=6 ||
			rnd_[1]<=6 && rnd_[2]<=6 && rnd_[4]<=6 && rnd_[5]<=6 ||
			rnd_[1]<=6 && rnd_[2]<=6 && rnd_[4]<=6 && rnd_[6]<=6 ||
			rnd_[1]<=6 && rnd_[2]<=6 && rnd_[5]<=6 && rnd_[6]<=6 ||
			rnd_[1]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6 ||
			rnd_[1]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[6]<=6 ||
			rnd_[1]<=6 && rnd_[3]<=6 && rnd_[5]<=6 && rnd_[6]<=6 ||
			rnd_[1]<=6 && rnd_[4]<=6 && rnd_[5]<=6 && rnd_[6]<=6 ||
			rnd_[1]<=6 && rnd_[2]<=6 && rnd_[4]<=6 && rnd_[6]<=6 ||
			rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6 ||  
			rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6 ||
			rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[6]<=6 ||
			rnd_[2]<=6 && rnd_[3]<=6 && rnd_[5]<=6 && rnd_[6]<=6 ||
			rnd_[2]<=6 && rnd_[4]<=6 && rnd_[5]<=6 && rnd_[6]<=6 ||
			rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6 && rnd_[6]<=6 
			)
		{
			x4=1;
		}

		// 5|6|6|45
		if(
			rnd_[1]<=6 && rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6  ||
			rnd_[1]<=6 && rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[6]<=6  ||
			rnd_[1]<=6 && rnd_[2]<=6 && rnd_[3]<=6 && rnd_[5]<=6 && rnd_[6]<=6  ||
			rnd_[1]<=6 && rnd_[2]<=6 && rnd_[4]<=6 && rnd_[5]<=6 && rnd_[6]<=6  ||
			rnd_[1]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6 && rnd_[6]<=6  ||
			rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6 && rnd_[6]<=6  
			)
		{
			x5=1; 

			// zahlenzuordnung	
			/*for(iLauf=1;iLauf<=6; iLauf++)	z_[iLauf]=rnd_[iLauf];
			
			for(iLauf=1;iLauf<=6; iLauf++) if(rnd_[iLauf]==wert[1+2])z_[iLauf]=1;
			for(iLauf=1;iLauf<=6; iLauf++) if(rnd_[iLauf]==wert[2+2])z_[iLauf]=2;
			for(iLauf=1;iLauf<=6; iLauf++) if(rnd_[iLauf]==wert[3+2])z_[iLauf]=3;
			for(iLauf=1;iLauf<=6; iLauf++) if(rnd_[iLauf]==wert[4+2])z_[iLauf]=4;
			for(iLauf=1;iLauf<=6; iLauf++) if(rnd_[iLauf]==wert[5+2])z_[iLauf]=5;
			for(iLauf=1;iLauf<=6; iLauf++) if(rnd_[iLauf]==wert[6+2])z_[iLauf]=6;

			for(iLauf=1;iLauf<=6; iLauf++)
			for(jLauf=1;jLauf<=6; jLauf++) if(rnd_[iLauf]==jLauf) z_[iLauf]=wert[jLauf+2];
			
			printf("\r%2.0f %2.0f %2.0f %2.0f %2.0f %2.0f\n", z_[1],z_[2],z_[3],z_[4],z_[5],z_[6]);	*/
		}

		// 6|6|6|45
		if(rnd_[1]<=6 && rnd_[2]<=6 && rnd_[3]<=6 && rnd_[4]<=6 && rnd_[5]<=6 && rnd_[6]<=6)
		{
			x6=1; 
			
			// zahlenzuordnung	
			for(iLauf=1;iLauf<=6; iLauf++)	z_[iLauf]=rnd_[iLauf];
			
			for(iLauf=1;iLauf<=6; iLauf++)
			for(jLauf=1;jLauf<=6; jLauf++) if(rnd_[iLauf]==jLauf) z_[iLauf]=wert[jLauf+2];

			fprintf(out,"(6|6|6|N)@m=%10.0f\t", zlr[9]);
			fprintf(out,"\t%2.0f\t%2.0f\t%2.0f\t%2.0f\t%2.0f\t%2.0f\n", z_[1],z_[2],z_[3],z_[4],z_[5],z_[6]);
			
			
			sd=(time(0)-1234567890); sd_zlr=0; // anfangswert neusetzung 
		}	

		// p(z), Ep(z)= 6/N
		zlr[8]++;
		if(rnd_[1]==1 ||rnd_[2]==1 ||rnd_[3]==1 ||rnd_[4]==1 ||rnd_[5]==1 ||rnd_[6]==1 )
		{
			addp+=1-pow(1- 6/N,zlr[8] ); // additive p
			addp2+=pow(1-pow(1- 6/N,zlr[8] ),2);
			
			x_zlr8+=zlr[8]; x_zlr82+=pow(zlr[8],2); zlr[8]=0; //mittlere wartezeit t
			
			zlr[7]++;// n für beliebige zahl
		}
		
		if(x0==1) zlr[0]++;	
		if(x1==1) zlr[1]++;
		if(x2==1) zlr[2]++;
		if(x3==1) zlr[3]++;
		if(x4==1) zlr[4]++;
		if(x5==1) zlr[5]++;
		if(x6==1) zlr[6]++;
		x0=0;
		x1=0;
		x2=0;
		x3=0;
		x4=0;
		x5=0;
		x6=0;
		//fprintf(out,"%.0f %.0f %.0f %.0f %.0f\n", rnd_[1],rnd_[2],rnd_[3],rnd_[4],rnd_[5],rnd_[6] );

		zlr[9]++; sd_zlr++;
	}

	// hypergeometrische wahrscheinlichkeiten
	
                     vektor[1]=	0;
	                 vektor[2]= 6;
					 vektor[3]= N;
					 vektor[4]= 6;
	hgw[0]= fn_hygeo(vektor, 1);

	                   vektor[1]=	1-1;
	hgw[1]= 1-fn_hygeo(vektor, 1);

		               vektor[1]=	2-1;
	hgw[2]= 1-fn_hygeo(vektor, 1);

	                   vektor[1]=	3-1;
	hgw[3]= 1-fn_hygeo(vektor, 1);

		               vektor[1]=	4-1;
	hgw[4]= 1-fn_hygeo(vektor, 1);

			           vektor[1]=	5-1;
	hgw[5]= 1-fn_hygeo(vektor, 1);

			           vektor[1]=	6-1;
	hgw[6]= 1-fn_hygeo(vektor, 1);

	// mittlere Frequenz AM(f)
	for(iLauf=1;iLauf<=6; iLauf++)Ef+= zlr[iLauf];
	                              Ef/=zlr[9];
								  
	if(zlr[6]==0)fprintf(out,"(6|6|6|N)@m={}\n");

	fprintf(out,"--------------------------------------------------------------------------\n");
	fprintf(out,"Bei M=%.0f Simulationszyklen galt H(6):\"6 von 6 bei 6 in N\" " , M);
	if(zlr[6]==0)fprintf(out,"nicht.\n");
	if(zlr[6]!=0)fprintf(out,"%.0f mal.\n", zlr[6]);
	fprintf(out,"Die mittlere Anzahl f(m/M) richtiger Zahlen ist f(m/M)=%.4f (%.1f|6|6|N)\n",Ef,Ef );
	fprintf(out,"bei erwarteter Anzahl fe=%.4f (%.1f|6|6|N).\n",36/N,36/N );
	fprintf(out,"Die mittlere Wartezeit AM(t) bis zum Auftreten einer beliebigen Zahl z ist\n");
	fprintf(out,"AM(t)=%.4f (%.1f\xB1%.1f Ziehungen).\n",x_zlr8/zlr[7],x_zlr8/zlr[7],sqrt((x_zlr82/zlr[7])- pow(x_zlr8/zlr[7],2)) );
	fprintf(out,"Die mittlere Additiv-Wahrscheinlichkeit padd bis zum Auftreten einer \n");
	fprintf(out,"beliebigen Zahl z ist padd=%.4f (%.1f\xB1%.1f Prozent).\n",addp/zlr[7],100*addp/zlr[7],100*(sqrt((addp2/zlr[7])- pow(addp/zlr[7],2))) );
	fprintf(out,"--------------------------------------------------------------------------\n");
	fprintf(out,"\tz\tAM\ts\n");
	fprintf(out,"--------------------------------------------------------------------------\n");
	fprintf(out,"fe\t\t%.4f\t%.4f\n",36/N,sqrt(((N-6)/(N-1))*6*(6/N)*(1-(6/N))));
	fprintf(out,"f(m/M)\t\t%.4f\n",Ef);
	fprintf(out,"pe\t%.4f\n",6/N);
	fprintf(out,"m\t%.0f\n",zlr[7]);
	fprintf(out,"p(m/M)\t%.4f\n",zlr[7]/M);
	fprintf(out,"t\t\t%.4f\t%.4f\n",x_zlr8/zlr[7],sqrt((x_zlr82/zlr[7])- pow(x_zlr8/zlr[7],2)));
	fprintf(out,"padd\t\t%.4f\t%.4f\n",addp/zlr[7],sqrt((addp2/zlr[7])- pow(addp/zlr[7],2)));
	fprintf(out,"--------------------------------------------------------------------------\n");
	fprintf(out,"k\tp(k|6|6|N)e\t\tmk\tp(k|6|6|N)M\tpdiff\n");
	fprintf(out,"--------------------------------------------------------------------------\n");
	for(iLauf=0;iLauf<=6;iLauf++)
	{
		pdiff=hgw[iLauf]-zlr[iLauf]/zlr[9];
		fprintf(out,"%i\t%.8f\t%10.0f\t%.8f\t",iLauf, hgw[iLauf], zlr[iLauf], zlr[iLauf]/zlr[9]);
		if(pdiff< 0)fprintf(out,"%.8f\n",pdiff);
		if(pdiff>=0)fprintf(out,"+%.8f\n",pdiff);
	}
	fprintf(out,"--------------------------------------------------------------------------\n");
	fprintf(out,"mk: Anzahl von k|6|6|N\n");
	fprintf(out,"p(k|6|6|N)e: Hypergeometrische Erwartungswahrscheinlichkeit zu k\n");
	fprintf(out,"p(k|6|6|N)M: Simulierte Wahrscheinlichkeit zu k\n");	
	fprintf(out,"--------------------------------------------------------------------------\n");
	fprintf(out,"SCHRAUSSER-MAT");
	
	fclose(out);

	printf("\r                                                  \r");
	
	fn_erg= zlr[6]; //m(6|6|6|45)

	return fn_erg;
};


double fn_rlt_sim(double wert[100])//  Roulette Simulation   // RLT sw, M, S, a, paddsel                     //
//                                                           // g(18/37)         // RLT 1,  M, S, a          //
//                                                           // g(12/37)         // RLT 2,  M, S, a          //
//                                                           // g(6/37)          // RLT 3,  M, S, a          //
//                                                           // g(4/37)          // RLT 2,  M, S, a          //
//                                                           // g(3/37)          // RLT 5,  M, S, a          //
//                                                           // g(2/37)          // RLT 6,  M, S, a          //
//                                                           // g(1/37)          // RLT 7,  M, S, a          //
//                                                           // g(18/37|paddsel) // RLT 8,  M, S, a, paddsel //
//                                                           // g(12/37|paddsel) // RLT 9,  M, S, a, paddsel //
//                                                           // g(6/37 |paddsel) // RLT 10, M, S, a, paddsel //
//                                                           // g(4/37 |paddsel) // RLT 11, M, S, a, paddsel //
//                                                           // g(3/37 |paddsel) // RLT 12, M, S, a, paddsel //
//                                                           // g(2/37 |paddsel) // RLT 13, M, S, a, paddsel //
//                                                           // g(1/37 |paddsel) // RLT 14, M, S, a, paddsel //
//                                                           // g(18/37|paddselz)// RLT 15, M, S, a, paddsel //
//                                                           // g(12/37|paddselz)// RLT 16, M, S, a, paddsel //
//                                                           // g(6/37 |paddselz)// RLT 17, M, S, a, paddsel //
//                                                           // g(4/37 |paddselz)// RLT 18, M, S, a, paddsel //
//                                                           // g(3/37 |paddselz)// RLT 19, M, S, a, paddsel //
//                                                           // g(2/37 |paddselz)// RLT 20, M, S, a, paddsel //
//                                                           // Matrix G         // RLT 22, M, 1, a, paddsel //
//                                                           // Matrix G S AM    // RLT 23, M, S, a, paddsel // Mmax=1000
//                                                           // Matrix G      z  // RLT 24, M, 1, a, paddsel //
//                                                           // Matrix G S AM z  // RLT 25, M, S, a, paddsel // Mmax=1000
//                                                           // RLT 7,  (10h6), 1, 0, 0.5      //
//                                                           // RLT 14, 200, 1000, 123, 0.70 //
//                                                           // RLT 22, 100, 1, 0, 0.55      //
//                                                           // RLT 23, 100, 1000, 0, 0.55      //
{
	FILE *out;

	int iLauf,jLauf, i2=0, i3=0;
	double  sw,i1=0, sd,sd1, Z_, M_, S_,  zlr1[100],zlr2[200],zlr3[200],padd[200],padd1[200],padd2[200],padd_am[200],t_am[200],t_2[200],
		   gw_1=1,gw_2=1,gw_3=1,gw_4=1,gw_5=1,gw_6=1,gw_7=1,pdiff,
		   gw_1s=1,gw_2s=1,gw_3s=1,gw_4s=1,gw_5s=1,gw_6s=1,gw_7s=1,
		   sum_zlr2=0,sum_pdiff=0,sum_padd=0,sum_pads=0,sum_t=0, sum_ts=0,padd_sel,
		   sum_[100][200], S_zlr_=0,max[100],min[100], G_[50][1000],vektor[10],szmax,gmax,szmax0,szmax1,mn=0,mn1=0,mn2=0;
		   
	sw=wert[1];	//  
	M_=wert[2]; //Simulationszyklen M
	S_=wert[3]; //Simulations-Metazyklen S
	sd=wert[4]; //Seed
	if(sd==0)sd=(time(0)-1234567890);
	sd1=sd;
	padd_sel=wert[5];//Selektions Additiv Wahrscheinlichkeit

	if (M_<1){printf("\n\ndesign.0 'M>0'\n");exit(0);}
	if (S_<1){printf("\n\ndesign.0 'S>0'\n");exit(0);}
	if (padd_sel>=1||padd_sel<=0){printf("\n\ndesign.0 '0<padd<1'\n");exit(0);}

	for(iLauf=0;iLauf<=100;iLauf++)
	for(jLauf=0;jLauf<=200;jLauf++)sum_[iLauf][jLauf]=0;//Summen-Matrix -> 0-Matrix
	for(iLauf=0;iLauf<=50;iLauf++)
	for(jLauf=0;jLauf<=1000;jLauf++)G_[iLauf][jLauf]=0;//G-Matrix -> 0-Matrix
	for(iLauf=0;iLauf<=100;iLauf++){max[iLauf]=0;min[iLauf]=0;}

	for(iLauf=1;iLauf<=1000;iLauf++)sd=sqrt(qzufall(sd,0,100))*1234;//"zufallswarmlauf"
	
	out=fopen( "MAT_fn.txt", "w" );

	printf("\r                                                  \r");
	
	while(S_zlr_<S_) //über simulations-metazyklen S
	{
		gw_1=1;gw_2=1;gw_3=1;gw_4=1;gw_5=1;gw_6=1;gw_7=1;
		gw_1s=1;gw_2s=1;gw_3s=1;gw_4s=1;gw_5s=1;gw_6s=1;gw_7s=1;
		
		for(iLauf=0;iLauf<=200;iLauf++)//zählervektoren -> 0-vektoren
		{
			zlr1[iLauf]=0;
			zlr2[iLauf]=0;
			zlr3[iLauf]=1;
			padd_am[iLauf]=0;
			                         padd[0    ]=0.027027; // S I C !!!!!!!!!!!!!!
			if(iLauf<=36            )padd[iLauf]=0.027027; // !!!!!!!!!!!!!!!!!!!!
			if(iLauf>=40&&iLauf<=41 )padd[iLauf]=0.486486;
			if(iLauf>=42&&iLauf<=44 )padd[iLauf]=0.324324;
			if(iLauf>=45&&iLauf<=55 )padd[iLauf]=0.162162;
			if(iLauf>=56&&iLauf<=79 )padd[iLauf]=0.108108;
			if(iLauf>=80&&iLauf<=91 )padd[iLauf]=0.081081;
			if(iLauf>=92&&iLauf<=148)padd[iLauf]=0.054054;
			padd2[iLauf]=0;
			t_2[iLauf]=0;
			t_am[iLauf]=0;

			padd1[iLauf]=padd[iLauf];
		}
		
		while(zlr1[0]<M_)//über simulationszyklen M
		{
			Z_=floor(qzufall(sd,0,37));sd=sqrt(qzufall(sd,0,100))*1234; // Zufallszahl int(n(0;37))
				
			while(i1<=36)
			{
				if (Z_==i1) 
				{ 	
					  padd_am[i2]+=padd[i2]; 
					padd2[i2]+=pow(padd[i2],2);
			
					     padd1[i2]=padd[i2];
					               padd[i2]=0.027027027;
								   
								   zlr2[i2]++;

					   t_am[i2]+=zlr3[i2];
					t_2[i2]+=pow(zlr3[i2],2); 
					             zlr3[i2]=1;
				}
				
				if (Z_!=i1) //additiv p, wartezeiten t
				{
					          padd[i2]=1-(pow(1-0.027027027,zlr3[i2]+1)); 
					                                        zlr3[i2]++;
					padd1[i2]=padd[i2];
				} 
				i2++; i1++;
			}
			i1=0;i2=0;

			//gerade Zahl
			if(Z_/2==floor(Z_/2)&&Z_!=0)
			{
				  padd_am[40]+=padd[40];
				padd2[40]+=pow(padd[40],2);
				     padd1[40]=padd[40];
				               padd[40]=0.486486;
				
				             zlr2[40]++; 

				   t_am[40]+=zlr3[40]; 
				t_2[40]+=pow(zlr3[40],2);
				             zlr3[40]=1;
			}
			if(Z_/2!=floor(Z_/2)||Z_==0)
			{
				          padd[40]=1-(pow(1-0.486486,zlr3[40]+1));
				                                     zlr3[40]++;
				padd1[40]=padd[40];
			}
			
			//ungerade Zahl
			if(Z_!=0)
			if(Z_/2!=floor(Z_/2))
			{
				  padd_am[41]+=padd[41];
				padd2[41]+=pow(padd[41],2);
				     padd1[41]=padd[41];
				               padd[41]=0.486486;
				
				             zlr2[41]++; 

				   t_am[41]+=zlr3[41]; 
				t_2[41]+=pow(zlr3[41],2);
				             zlr3[41]=1;
			}
			
			if(Z_/2==floor(Z_/2)||Z_==0)
			{
				          padd[41]=1-(pow(1-0.486486,zlr3[41]+1));
				                                     zlr3[41]++;
				padd1[41]=padd[41];
			}

			//1. Drittel (Feld)
			if(Z_<=12&&Z_!=0)
			{
				  padd_am[42]+=padd[42];
				padd2[42]+=pow(padd[42],2);
				     padd1[42]=padd[42];
				               padd[42]=0.324324;
						  
						     zlr2[42]++;
				
				   t_am[42]+=zlr3[42]; 
				t_2[42]+=pow(zlr3[42],2);
				             zlr3[42]=1;
			}
			if(Z_>12||Z_==0)
			{
				          padd[42]=1-(pow(1-0.324324,zlr3[42]+1));
				                                     zlr3[42]++;
				padd1[42]=padd[42];
			}
			
			//2. Drittel (Feld)
			if(Z_>=13&&Z_<=24)
			{
				  padd_am[43]+=padd[43];
				padd2[43]+=pow(padd[43],2);
				     padd1[43]=padd[43]; 
					           padd[43]=0.324324;
							   
							 zlr2[43]++;
				
				   t_am[43]+=zlr3[43]; 
				t_2[43]+=pow(zlr3[43],2);
				             zlr3[43]=1;
			}
			if(Z_<13||Z_>24)
			{
				          padd[43]=1-(pow(1-0.324324,zlr3[43]+1));
				                                     zlr3[43]++;
				padd1[43]=padd[43];
			}
			
			//3. Drittel (Feld)
			if(Z_>=25)
			{
				  padd_am[44]+=padd[44];
				padd2[44]+=pow(padd[44],2); 
				     padd1[44]=padd[44];
					           padd[44]=0.324324;
							   
							 zlr2[44]++;
				
				   t_am[44]+=zlr3[44]; 
				t_2[44]+=pow(zlr3[44],2);
				             zlr3[44]=1;
			}
			
			if(Z_<25)
			{
				          padd[44]=1-(pow(1-0.324324,zlr3[44]+1));
				                                     zlr3[44]++;
				padd1[44]=padd[44];

			}

			//1. Sechstel
			if(Z_<=6&&Z_!=0){padd_am[45]+=padd[45];padd2[45]+=pow(padd[45],2);zlr2[45]++; padd1[45]=padd[45];padd[45]=0.162162;t_am[45]+=zlr3[45]; t_2[45]+=pow(zlr3[45],2);zlr3[45]=1;}
			if(Z_>6||Z_==0) {padd[45]=1-(pow(1-0.162162,zlr3[45]+1));zlr3[45]++;}					
			//2. Sechstel
			if(Z_>=4&&Z_<=9){padd_am[46]+=padd[46];padd2[46]+=pow(padd[46],2);zlr2[46]++; padd1[46]=padd[46];padd[46]=0.162162;t_am[46]+=zlr3[46]; t_2[46]+=pow(zlr3[46],2);zlr3[46]=1;}
			if(Z_<4||Z_>9) {padd[46]=1-(pow(1-0.162162,zlr3[46]+1));zlr3[46]++;}
			//3. Sechstel
			if(Z_>=7&&Z_<=12){padd_am[47]+=padd[47];padd2[47]+=pow(padd[47],2);zlr2[47]++; padd1[47]=padd[47];padd[47]=0.162162;t_am[47]+=zlr3[47]; t_2[47]+=pow(zlr3[47],2);zlr3[47]=1;}
			if(Z_<7||Z_>12) {padd[47]=1-(pow(1-0.162162,zlr3[47]+1));zlr3[47]++;}
			//4. Sechstel
			if(Z_>=10&&Z_<=15){padd_am[48]+=padd[48];padd2[48]+=pow(padd[48],2);zlr2[48]++; padd1[48]=padd[48];padd[48]=0.162162;t_am[48]+=zlr3[48]; t_2[48]+=pow(zlr3[48],2);zlr3[48]=1;}
			if(Z_<10||Z_>15) {padd[48]=1-(pow(1-0.162162,zlr3[48]+1));zlr3[48]++;}
			//5. Sechstel
			if(Z_>=13&&Z_<=18){padd_am[49]+=padd[49];padd2[49]+=pow(padd[49],2);zlr2[49]++; padd1[49]=padd[49];padd[49]=0.162162;t_am[49]+=zlr3[49]; t_2[49]+=pow(zlr3[49],2);zlr3[49]=1;}
			if(Z_<13||Z_>18) {padd[49]=1-(pow(1-0.162162,zlr3[49]+1));zlr3[49]++;}
			//6. Sechstel
			if(Z_>=16&&Z_<=21){padd_am[50]+=padd[50];padd2[50]+=pow(padd[50],2);zlr2[50]++; padd1[50]=padd[50];padd[50]=0.162162;t_am[50]+=zlr3[50]; t_2[50]+=pow(zlr3[50],2);zlr3[50]=1;}
			if(Z_<16||Z_>21) {padd[50]=1-(pow(1-0.162162,zlr3[50]+1));zlr3[50]++;}
			//7. Sechstel
			if(Z_>=19&&Z_<=24){padd_am[51]+=padd[51];padd2[51]+=pow(padd[51],2);zlr2[51]++;padd1[51]=padd[51];padd[51]=0.162162; t_am[51]+=zlr3[51]; t_2[51]+=pow(zlr3[51],2);zlr3[51]=1;}
			if(Z_<19||Z_>24) {padd[51]=1-(pow(1-0.162162,zlr3[51]+1));zlr3[51]++;}
			//8. Sechstel
			if(Z_>=22&&Z_<=27){padd_am[52]+=padd[52];padd2[52]+=pow(padd[52],2);zlr2[52]++;padd1[52]=padd[52];padd[52]=0.162162;t_am[52]+=zlr3[52]; t_2[52]+=pow(zlr3[52],2);zlr3[52]=1;}
			if(Z_<22||Z_>27) {padd[52]=1-(pow(1-0.162162,zlr3[52]+1));zlr3[52]++;}
			//9. Sechstel
			if(Z_>=25&&Z_<=30){padd_am[53]+=padd[53];padd2[53]+=pow(padd[53],2);zlr2[53]++; padd1[53]=padd[53];padd[53]=0.162162;t_am[53]+=zlr3[53]; t_2[53]+=pow(zlr3[53],2);zlr3[53]=1;}
			if(Z_<25||Z_>30) {padd[53]=1-(pow(1-0.162162,zlr3[53]+1));zlr3[53]++;}
			//10. Sechstel
			if(Z_>=28&&Z_<=33){padd_am[54]+=padd[54];padd2[54]+=pow(padd[54],2);zlr2[54]++; padd1[54]=padd[54];padd[54]=0.162162;t_am[54]+=zlr3[54]; t_2[54]+=pow(zlr3[54],2);zlr3[54]=1;}
			if(Z_<28||Z_>33) {padd[54]=1-(pow(1-0.162162,zlr3[54]+1));zlr3[54]++;}
			//11. Sechstel
			if(Z_>=31){padd_am[55]+=padd[55];padd2[55]+=pow(padd[55],2);zlr2[55]++; padd1[55]=padd[55];padd[55]=0.162162;t_am[55]+=zlr3[55]; t_2[55]+=pow(zlr3[55],2);zlr3[55]=1;}
			if(Z_<31) {padd[55]=1-(pow(1-0.162162,zlr3[55]+1));zlr3[55]++;padd1[55]=padd[55];}

			//1. Viertel
			if(Z_==1||Z_==2||Z_==4||Z_==5){padd_am[56]+=padd[56];padd2[56]+=pow(padd[56],2);zlr2[56]++; padd1[56]=padd[56];padd[56]=0.108108;t_am[56]+=zlr3[56]; t_2[56]+=pow(zlr3[56],2);zlr3[56]=1;}
			else {padd[56]=1-(pow(1-0.108108,zlr3[56]+1));zlr3[56]++;}
			//2. Viertel
			if(Z_==2||Z_==3||Z_==5||Z_==6){padd_am[57]+=padd[57];padd2[57]+=pow(padd[57],2);zlr2[57]++; padd1[57]=padd[57];padd[57]=0.108108;t_am[57]+=zlr3[57]; t_2[57]+=pow(zlr3[57],2);zlr3[57]=1;}
			else {padd[57]=1-(pow(1-0.108108,zlr3[57]+1));zlr3[57]++;}
			//3. Viertel
			if(Z_==4||Z_==5||Z_==7||Z_==8){padd_am[58]+=padd[58];padd2[58]+=pow(padd[58],2);zlr2[58]++; padd1[58]=padd[58];padd[58]=0.108108;t_am[58]+=zlr3[58]; t_2[58]+=pow(zlr3[58],2);zlr3[58]=1;}
			else {padd[58]=1-(pow(1-0.108108,zlr3[58]+1));zlr3[58]++;}
			//4. Viertel
			if(Z_==5||Z_==6||Z_==8||Z_==9){padd_am[59]+=padd[59];padd2[59]+=pow(padd[59],2);zlr2[59]++; padd1[59]=padd[59];padd[59]=0.108108;t_am[59]+=zlr3[59]; t_2[59]+=pow(zlr3[59],2);zlr3[59]=1;}
			else {padd[59]=1-(pow(1-0.108108,zlr3[59]+1));zlr3[59]++;}
			//5. Viertel
			if(Z_==7||Z_==8||Z_==10||Z_==11){padd_am[60]+=padd[60];padd2[60]+=pow(padd[60],2);zlr2[60]++; padd1[60]=padd[60];padd[60]=0.108108;t_am[60]+=zlr3[60]; t_2[60]+=pow(zlr3[60],2);zlr3[60]=1;}
			else {padd[60]=1-(pow(1-0.108108,zlr3[60]+1));zlr3[60]++;}
			//6. Viertel
			if(Z_==8||Z_==9||Z_==11||Z_==12){padd_am[61]+=padd[61];padd2[61]+=pow(padd[61],2);zlr2[61]++; padd1[61]=padd[61];padd[61]=0.108108;t_am[61]+=zlr3[61]; t_2[61]+=pow(zlr3[61],2);zlr3[61]=1;}
			else {padd[61]=1-(pow(1-0.108108,zlr3[61]+1));zlr3[61]++;}
			//7. Viertel
			if(Z_==10||Z_==11||Z_==13||Z_==14){padd_am[62]+=padd[62];padd2[62]+=pow(padd[62],2);zlr2[62]++; padd1[62]=padd[62];padd[62]=0.108108;t_am[62]+=zlr3[62]; t_2[62]+=pow(zlr3[62],2);zlr3[62]=1;}
			else {padd[62]=1-(pow(1-0.108108,zlr3[62]+1));zlr3[62]++;}
			//8. Viertel
			if(Z_==11||Z_==12||Z_==14||Z_==15){padd_am[63]+=padd[63];padd2[63]+=pow(padd[63],2);zlr2[63]++; padd1[63]=padd[63];padd[63]=0.108108;t_am[63]+=zlr3[63]; t_2[63]+=pow(zlr3[63],2);zlr3[63]=1;}
			else {padd[63]=1-(pow(1-0.108108,zlr3[63]+1));zlr3[63]++;}
			//9. Viertel
			if(Z_==13||Z_==14||Z_==16||Z_==17){padd_am[64]+=padd[64];padd2[64]+=pow(padd[64],2);zlr2[64]++; padd1[64]=padd[64];padd[64]=0.108108;t_am[64]+=zlr3[64]; t_2[64]+=pow(zlr3[64],2);zlr3[64]=1;}
			else {padd[64]=1-(pow(1-0.108108,zlr3[64]+1));zlr3[64]++;}
			//10. Viertel
			if(Z_==14||Z_==15||Z_==17||Z_==18){padd_am[65]+=padd[65];padd2[65]+=pow(padd[65],2);zlr2[65]++; padd1[65]=padd[65];padd[65]=0.108108;t_am[65]+=zlr3[65]; t_2[65]+=pow(zlr3[65],2);zlr3[65]=1;}
			else {padd[65]=1-(pow(1-0.108108,zlr3[65]+1));zlr3[65]++;}
			//11. Viertel
			if(Z_==14||Z_==15||Z_==17||Z_==18){padd_am[66]+=padd[66];padd2[66]+=pow(padd[66],2);zlr2[66]++; padd1[66]=padd[66];padd[66]=0.108108;t_am[66]+=zlr3[66]; t_2[66]+=pow(zlr3[66],2);zlr3[66]=1;}
			else {padd[66]=1-(pow(1-0.108108,zlr3[66]+1));zlr3[66]++;}
			//12. Viertel
			if(Z_==16||Z_==17||Z_==19||Z_==20){padd_am[67]+=padd[67];padd2[67]+=pow(padd[67],2);zlr2[67]++; padd1[67]=padd[67];padd[67]=0.108108;t_am[67]+=zlr3[67]; t_2[67]+=pow(zlr3[67],2);zlr3[67]=1;}
			else {padd[67]=1-(pow(1-0.108108,zlr3[67]+1));zlr3[67]++;}
			//13. Viertel
			if(Z_==17||Z_==18||Z_==20||Z_==21){padd_am[68]+=padd[68];padd2[68]+=pow(padd[68],2);zlr2[68]++; padd1[68]=padd[68];padd[68]=0.108108;t_am[68]+=zlr3[68]; t_2[68]+=pow(zlr3[68],2);zlr3[68]=1;}
			else {padd[68]=1-(pow(1-0.108108,zlr3[68]+1));zlr3[68]++;}
			//14. Viertel
			if(Z_==19||Z_==20||Z_==22||Z_==23){padd_am[69]+=padd[69];padd2[69]+=pow(padd[69],2);zlr2[69]++; padd1[69]=padd[69];padd[69]=0.108108;t_am[69]+=zlr3[69]; t_2[69]+=pow(zlr3[69],2);zlr3[69]=1;}
			else {padd[69]=1-(pow(1-0.108108,zlr3[69]+1));zlr3[69]++;}
			//15. Viertel
			if(Z_==20||Z_==21||Z_==23||Z_==24){padd_am[70]+=padd[70];padd2[70]+=pow(padd[70],2);zlr2[70]++; padd1[70]=padd[70];padd[70]=0.108108;t_am[70]+=zlr3[70]; t_2[70]+=pow(zlr3[70],2);zlr3[70]=1;}
			else {padd[70]=1-(pow(1-0.108108,zlr3[70]+1));zlr3[70]++;}
			//16. Viertel
			if(Z_==22||Z_==23||Z_==25||Z_==26){padd_am[71]+=padd[71];padd2[71]+=pow(padd[71],2);zlr2[71]++; padd1[71]=padd[71];padd[71]=0.108108;t_am[71]+=zlr3[71]; t_2[71]+=pow(zlr3[71],2);zlr3[71]=1;}
			else {padd[71]=1-(pow(1-0.108108,zlr3[71]+1));zlr3[71]++;}
			//17. Viertel
			if(Z_==23||Z_==24||Z_==26||Z_==27){padd_am[72]+=padd[72];padd2[72]+=pow(padd[72],2);zlr2[72]++; padd1[72]=padd[72];padd[72]=0.108108;t_am[72]+=zlr3[72]; t_2[72]+=pow(zlr3[72],2);zlr3[72]=1;}
			else {padd[72]=1-(pow(1-0.108108,zlr3[72]+1));zlr3[72]++;}
			//18. Viertel
			if(Z_==25||Z_==26||Z_==28||Z_==29){padd_am[73]+=padd[73];padd2[73]+=pow(padd[73],2);zlr2[73]++; padd1[73]=padd[73];padd[73]=0.108108;t_am[73]+=zlr3[73]; t_2[73]+=pow(zlr3[73],2);zlr3[73]=1;}
			else {padd[73]=1-(pow(1-0.108108,zlr3[73]+1));zlr3[73]++;}
			//19. Viertel
			if(Z_==26||Z_==27||Z_==29||Z_==30){padd_am[74]+=padd[74];padd2[74]+=pow(padd[74],2);zlr2[74]++; padd1[74]=padd[74];padd[74]=0.108108;t_am[74]+=zlr3[74]; t_2[74]+=pow(zlr3[74],2);zlr3[74]=1;}
			else {padd[74]=1-(pow(1-0.108108,zlr3[74]+1));zlr3[74]++;}
			//20. Viertel
			if(Z_==26||Z_==27||Z_==29||Z_==30){padd_am[75]+=padd[75];padd2[75]+=pow(padd[75],2);zlr2[75]++; padd1[75]=padd[75];padd[75]=0.108108;t_am[75]+=zlr3[75]; t_2[75]+=pow(zlr3[75],2);zlr3[75]=1;}
			else {padd[75]=1-(pow(1-0.108108,zlr3[75]+1));zlr3[75]++;}
			//21. Viertel
			if(Z_==28||Z_==29||Z_==31||Z_==32){padd_am[76]+=padd[76];padd2[76]+=pow(padd[76],2);zlr2[76]++; padd1[76]=padd[76];padd[76]=0.108108;t_am[76]+=zlr3[76]; t_2[76]+=pow(zlr3[76],2);zlr3[76]=1;}
			else {padd[76]=1-(pow(1-0.108108,zlr3[76]+1));zlr3[76]++;}
			//22. Viertel
			if(Z_==29||Z_==30||Z_==32||Z_==33){padd_am[77]+=padd[77];padd2[77]+=pow(padd[77],2);zlr2[77]++; padd1[77]=padd[77];padd[77]=0.108108;t_am[77]+=zlr3[77]; t_2[77]+=pow(zlr3[77],2);zlr3[77]=1;}
			else {padd[77]=1-(pow(1-0.108108,zlr3[77]+1));zlr3[77]++;}
			//23. Viertel
			if(Z_==31||Z_==32||Z_==34||Z_==35){padd_am[78]+=padd[78];padd2[78]+=pow(padd[78],2);zlr2[78]++; padd1[78]=padd[78];padd[78]=0.108108;t_am[78]+=zlr3[78]; t_2[78]+=pow(zlr3[78],2);zlr3[78]=1;}
			else {padd[78]=1-(pow(1-0.108108,zlr3[78]+1));zlr3[78]++;}
			//24. Viertel
			if(Z_==32||Z_==33||Z_==35||Z_==36){padd_am[79]+=padd[79];padd2[79]+=pow(padd[79],2);zlr2[79]++; padd1[79]=padd[79];padd[79]=0.108108;t_am[79]+=zlr3[79]; t_2[79]+=pow(zlr3[79],2);zlr3[79]=1;}
			else {padd[79]=1-(pow(1-0.108108,zlr3[79]+1));zlr3[79]++;padd1[79]=padd[79];}

			//1. Zwölftel
			if(Z_==1||Z_==2||Z_==3){padd_am[80]+=padd[80];padd2[80]+=pow(padd[80],2);zlr2[80]++; padd1[80]=padd[80];padd[80]=0.081081;t_am[80]+=zlr3[80]; t_2[80]+=pow(zlr3[80],2);zlr3[80]=1;}
			else                      {padd[80]=1-(pow(1-0.081081,zlr3[80]+1));zlr3[80]++;}
			//2. Zwölftel
			if(Z_==4||Z_==5||Z_==6){padd_am[81]+=padd[81];padd2[81]+=pow(padd[81],2);zlr2[81]++; padd1[81]=padd[81];padd[81]=0.081081;t_am[81]+=zlr3[81]; t_2[81]+=pow(zlr3[81],2);zlr3[81]=1;}
			else                      {padd[81]=1-(pow(1-0.081081,zlr3[81]+1));zlr3[81]++;}
			//3. Zwölftel
			if(Z_==7||Z_==8||Z_==9){padd_am[82]+=padd[82];padd2[82]+=pow(padd[82],2);zlr2[82]++; padd1[82]=padd[82];padd[82]=0.081081;t_am[82]+=zlr3[82]; t_2[82]+=pow(zlr3[82],2);zlr3[82]=1;}
			else                      {padd[82]=1-(pow(1-0.081081,zlr3[82]+1));zlr3[82]++;}
			//4. Zwölftel
			if(Z_==10||Z_==11||Z_==12){padd_am[83]+=padd[83];padd2[83]+=pow(padd[83],2);zlr2[83]++; padd1[83]=padd[83];padd[83]=0.081081;t_am[83]+=zlr3[83]; t_2[83]+=pow(zlr3[83],2);zlr3[83]=1;}
			else                      {padd[83]=1-(pow(1-0.081081,zlr3[83]+1));zlr3[83]++;}
			//5. Zwölftel
			if(Z_==13||Z_==14||Z_==15){padd_am[84]+=padd[84];padd2[84]+=pow(padd[84],2);zlr2[84]++; padd1[84]=padd[84];padd[84]=0.081081;t_am[84]+=zlr3[84]; t_2[84]+=pow(zlr3[84],2);zlr3[84]=1;}
			else                      {padd[84]=1-(pow(1-0.081081,zlr3[84]+1));zlr3[84]++;}
			//6. Zwölftel
			if(Z_==16||Z_==17||Z_==18){padd_am[85]+=padd[85];padd2[85]+=pow(padd[85],2);zlr2[85]++; padd1[85]=padd[85];padd[85]=0.081081;t_am[85]+=zlr3[85]; t_2[85]+=pow(zlr3[85],2);zlr3[85]=1;}
			else                      {padd[85]=1-(pow(1-0.081081,zlr3[85]+1));zlr3[85]++;}
			//7. Zwölftel
			if(Z_==19||Z_==20||Z_==21){padd_am[86]+=padd[86];padd2[86]+=pow(padd[86],2);zlr2[86]++; padd1[86]=padd[86];padd[86]=0.081081;t_am[86]+=zlr3[86]; t_2[86]+=pow(zlr3[86],2);zlr3[86]=1;}
			else                      {padd[86]=1-(pow(1-0.081081,zlr3[86]+1));zlr3[86]++;}
			//8. Zwölftel
			if(Z_==22||Z_==23||Z_==24){padd_am[87]+=padd[87];padd2[87]+=pow(padd[87],2);zlr2[87]++; padd1[87]=padd[87];padd[87]=0.081081;t_am[87]+=zlr3[87]; t_2[87]+=pow(zlr3[87],2);zlr3[87]=1;}
			else                      {padd[87]=1-(pow(1-0.081081,zlr3[87]+1));zlr3[87]++;}
			//9. Zwölftel
			if(Z_==25||Z_==26||Z_==27){padd_am[88]+=padd[88];padd2[88]+=pow(padd[88],2);zlr2[88]++; padd1[88]=padd[88];padd[88]=0.081081;t_am[88]+=zlr3[88]; t_2[88]+=pow(zlr3[88],2);zlr3[88]=1;}
			else                      {padd[88]=1-(pow(1-0.081081,zlr3[88]+1));zlr3[88]++;}
			//10. Zwölftel
			if(Z_==28||Z_==29||Z_==30){padd_am[89]+=padd[89];padd2[89]+=pow(padd[89],2);zlr2[89]++; padd1[89]=padd[89];padd[89]=0.081081;t_am[89]+=zlr3[89]; t_2[89]+=pow(zlr3[89],2);zlr3[89]=1;}
			else                      {padd[89]=1-(pow(1-0.081081,zlr3[89]+1));zlr3[89]++;}
			//11. Zwölftel
			if(Z_==31||Z_==32||Z_==33){padd_am[90]+=padd[90];padd2[90]+=pow(padd[90],2);zlr2[90]++; padd1[90]=padd[90];padd[90]=0.081081;t_am[90]+=zlr3[90]; t_2[90]+=pow(zlr3[90],2);zlr3[90]=1;}
			else                      {padd[90]=1-(pow(1-0.081081,zlr3[90]+1));zlr3[90]++;}
			//12. Zwölftel
			if(Z_==34||Z_==35||Z_==36){padd_am[91]+=padd[91];padd2[91]+=pow(padd[91],2);zlr2[91]++; padd1[91]=padd[91];padd[91]=0.081081;t_am[91]+=zlr3[91]; t_2[91]+=pow(zlr3[91],2);zlr3[91]=1;}
			else                      {padd[91]=1-(pow(1-0.081081,zlr3[91]+1));zlr3[91]++;padd1[91]=padd[91];}

			//1. Paar
			if(Z_==1||Z_==2){padd_am[92]+=padd[92];padd2[92]+=pow(padd[92],2);zlr2[92]++; padd1[92]=padd[92];padd[92]=0.054054;t_am[92]+=zlr3[92]; t_2[92]+=pow(zlr3[92],2);zlr3[92]=1;}
			else            {padd[92]=1-(pow(1-0.054054,zlr3[92]+1));zlr3[92]++;}
			//2. Paar
			if(Z_==2||Z_==3){padd_am[93]+=padd[93];padd2[93]+=pow(padd[93],2);zlr2[93]++; padd1[93]=padd[93];padd[93]=0.054054;t_am[93]+=zlr3[93]; t_2[93]+=pow(zlr3[93],2);zlr3[93]=1;}
			else            {padd[93]=1-(pow(1-0.054054,zlr3[93]+1));zlr3[93]++;}
			//3. Paar
			if(Z_==4||Z_==5){padd_am[94]+=padd[94];padd2[94]+=pow(padd[94],2);zlr2[94]++; padd1[94]=padd[94];padd[94]=0.054054;t_am[94]+=zlr3[94]; t_2[94]+=pow(zlr3[94],2);zlr3[94]=1;}
			else            {padd[94]=1-(pow(1-0.054054,zlr3[94]+1));zlr3[94]++;}
			//4. Paar
			if(Z_==5||Z_==6){padd_am[95]+=padd[95];padd2[95]+=pow(padd[95],2);zlr2[95]++; padd1[95]=padd[95];padd[95]=0.054054;t_am[95]+=zlr3[95]; t_2[95]+=pow(zlr3[95],2);zlr3[95]=1;}
			else            {padd[95]=1-(pow(1-0.054054,zlr3[95]+1));zlr3[95]++;}
			//5. Paar
			if(Z_==7||Z_==8){padd_am[96]+=padd[96];padd2[96]+=pow(padd[96],2);zlr2[96]++; padd1[96]=padd[96];padd[96]=0.054054;t_am[96]+=zlr3[96]; t_2[96]+=pow(zlr3[96],2);zlr3[96]=1;}
			else            {padd[96]=1-(pow(1-0.054054,zlr3[96]+1));zlr3[96]++;}
			//6. Paar
			if(Z_==8||Z_==9){padd_am[97]+=padd[97];padd2[97]+=pow(padd[97],2);zlr2[97]++; padd1[97]=padd[97];padd[97]=0.054054;t_am[97]+=zlr3[97]; t_2[97]+=pow(zlr3[97],2);zlr3[97]=1;}
			else            {padd[97]=1-(pow(1-0.054054,zlr3[97]+1));zlr3[97]++;}
			//7. Paar
			if(Z_==10||Z_==11){padd_am[98]+=padd[98];padd2[98]+=pow(padd[98],2);zlr2[98]++; padd1[98]=padd[98];padd[98]=0.054054;t_am[98]+=zlr3[98]; t_2[98]+=pow(zlr3[98],2);zlr3[98]=1;}
			else            {padd[98]=1-(pow(1-0.054054,zlr3[98]+1));zlr3[98]++;}
			//8. Paar
			if(Z_==11||Z_==12){padd_am[99]+=padd[99];padd2[99]+=pow(padd[99],2);zlr2[99]++; padd1[99]=padd[99];padd[99]=0.054054;t_am[99]+=zlr3[99]; t_2[99]+=pow(zlr3[99],2);zlr3[99]=1;}
			else            {padd[99]=1-(pow(1-0.054054,zlr3[99]+1));zlr3[99]++;}
			//9. Paar
			if(Z_==13||Z_==14){padd_am[100]+=padd[100];padd2[100]+=pow(padd[100],2);zlr2[100]++; padd1[100]=padd[100];padd[100]=0.054054;t_am[100]+=zlr3[100]; t_2[100]+=pow(zlr3[100],2);zlr3[100]=1;}
			else            {padd[100]=1-(pow(1-0.054054,zlr3[100]+1));zlr3[100]++;}
			//10. Paar
			if(Z_==14||Z_==15){padd_am[101]+=padd[101];padd2[101]+=pow(padd[101],2);zlr2[101]++; padd1[101]=padd[101];padd[101]=0.054054;t_am[101]+=zlr3[101]; t_2[101]+=pow(zlr3[101],2);zlr3[101]=1;}
			else            {padd[101]=1-(pow(1-0.054054,zlr3[101]+1));zlr3[101]++;}
			//11. Paar
			if(Z_==16||Z_==17){padd_am[102]+=padd[102];padd2[102]+=pow(padd[102],2);zlr2[102]++; padd1[102]=padd[102];padd[102]=0.054054;t_am[102]+=zlr3[102]; t_2[102]+=pow(zlr3[102],2);zlr3[102]=1;}
			else            {padd[102]=1-(pow(1-0.054054,zlr3[102]+1));zlr3[102]++;}
			//12. Paar
			if(Z_==17||Z_==18){padd_am[103]+=padd[103];padd2[103]+=pow(padd[103],2);zlr2[103]++; padd1[103]=padd[103];padd[103]=0.054054;t_am[103]+=zlr3[103]; t_2[103]+=pow(zlr3[103],2);zlr3[103]=1;}
			else            {padd[103]=1-(pow(1-0.054054,zlr3[103]+1));zlr3[103]++;}
			//13. Paar
			if(Z_==19||Z_==20){padd_am[104]+=padd[104];padd2[104]+=pow(padd[104],2);zlr2[104]++; padd1[104]=padd[104];padd[104]=0.054054;t_am[104]+=zlr3[104]; t_2[104]+=pow(zlr3[104],2);zlr3[104]=1;}
			else            {padd[104]=1-(pow(1-0.054054,zlr3[104]+1));zlr3[104]++;}
			//14. Paar
			if(Z_==20||Z_==21){padd_am[105]+=padd[105];padd2[105]+=pow(padd[105],2);zlr2[105]++; padd1[105]=padd[105];padd[105]=0.054054;t_am[105]+=zlr3[105]; t_2[105]+=pow(zlr3[105],2);zlr3[105]=1;}
			else            {padd[105]=1-(pow(1-0.054054,zlr3[105]+1));zlr3[105]++;}
			//15. Paar
			if(Z_==22||Z_==23){padd_am[106]+=padd[106];padd2[106]+=pow(padd[106],2);zlr2[106]++; padd1[106]=padd[106];padd[106]=0.054054;t_am[106]+=zlr3[106]; t_2[106]+=pow(zlr3[106],2);zlr3[106]=1;}
			else            {padd[106]=1-(pow(1-0.054054,zlr3[106]+1));zlr3[106]++;}
			//16. Paar
			if(Z_==23||Z_==24){padd_am[107]+=padd[107];padd2[107]+=pow(padd[107],2);zlr2[107]++; padd1[107]=padd[107];padd[107]=0.054054;t_am[107]+=zlr3[107]; t_2[107]+=pow(zlr3[107],2);zlr3[107]=1;}
			else            {padd[107]=1-(pow(1-0.054054,zlr3[107]+1));zlr3[107]++;}
			//17. Paar
			if(Z_==25||Z_==26){padd_am[108]+=padd[108];padd2[108]+=pow(padd[108],2);zlr2[108]++; padd1[108]=padd[108];padd[108]=0.054054;t_am[108]+=zlr3[108]; t_2[108]+=pow(zlr3[108],2);zlr3[108]=1;}
			else            {padd[108]=1-(pow(1-0.054054,zlr3[108]+1));zlr3[108]++;}
			//18. Paar
			if(Z_==26||Z_==27){padd_am[109]+=padd[109];padd2[109]+=pow(padd[109],2);zlr2[109]++; padd1[109]=padd[109];padd[109]=0.054054;t_am[109]+=zlr3[109]; t_2[109]+=pow(zlr3[109],2);zlr3[109]=1;}
			else            {padd[109]=1-(pow(1-0.054054,zlr3[109]+1));zlr3[109]++;}
			//19. Paar
			if(Z_==28||Z_==29){padd_am[110]+=padd[110];padd2[110]+=pow(padd[110],2);zlr2[110]++; padd1[110]=padd[110];padd[110]=0.054054;t_am[110]+=zlr3[110]; t_2[110]+=pow(zlr3[110],2);zlr3[110]=1;}
			else            {padd[110]=1-(pow(1-0.054054,zlr3[110]+1));zlr3[110]++;}
			//20. Paar
			if(Z_==29||Z_==30){padd_am[111]+=padd[111];padd2[111]+=pow(padd[111],2);zlr2[111]++; padd1[111]=padd[111];padd[111]=0.054054;t_am[111]+=zlr3[111]; t_2[111]+=pow(zlr3[111],2);zlr3[111]=1;}
			else            {padd[111]=1-(pow(1-0.054054,zlr3[111]+1));zlr3[111]++;}
			//21. Paar
			if(Z_==31||Z_==32){padd_am[112]+=padd[112];padd2[112]+=pow(padd[112],2);zlr2[112]++; padd1[112]=padd[112];padd[112]=0.054054;t_am[112]+=zlr3[112]; t_2[112]+=pow(zlr3[112],2);zlr3[112]=1;}
			else            {padd[112]=1-(pow(1-0.054054,zlr3[112]+1));zlr3[112]++;}
			//22. Paar
			if(Z_==32||Z_==33){padd_am[113]+=padd[113];padd2[113]+=pow(padd[113],2);zlr2[113]++; padd1[113]=padd[113];padd[113]=0.054054;t_am[113]+=zlr3[113]; t_2[113]+=pow(zlr3[113],2);zlr3[113]=1;}
			else            {padd[113]=1-(pow(1-0.054054,zlr3[113]+1));zlr3[113]++;}
			//23. Paar
			if(Z_==34||Z_==35){padd_am[114]+=padd[114];padd2[114]+=pow(padd[114],2);zlr2[114]++; padd1[114]=padd[114];padd[114]=0.054054;t_am[114]+=zlr3[114]; t_2[114]+=pow(zlr3[114],2);zlr3[114]=1;}
			else            {padd[114]=1-(pow(1-0.054054,zlr3[114]+1));zlr3[114]++;}
			//24. Paar
			if(Z_==35||Z_==36){padd_am[115]+=padd[115];padd2[115]+=pow(padd[115],2);zlr2[115]++; padd1[115]=padd[115];padd[115]=0.054054;t_am[115]+=zlr3[115]; t_2[115]+=pow(zlr3[115],2);zlr3[115]=1;}
			else            {padd[115]=1-(pow(1-0.054054,zlr3[115]+1));zlr3[115]++;padd1[115]=padd[115];}
			//25. Paar
			if(Z_==1||Z_==4){padd_am[116]+=padd[116];padd2[116]+=pow(padd[116],2);zlr2[116]++; padd1[116]=padd[116];padd[116]=0.054054;t_am[116]+=zlr3[116]; t_2[116]+=pow(zlr3[116],2);zlr3[116]=1;}
			else            {padd[116]=1-(pow(1-0.054054,zlr3[116]+1));zlr3[116]++;}
			//26. Paar
			if(Z_==2||Z_==5){padd_am[117]+=padd[117];padd2[117]+=pow(padd[117],2);zlr2[117]++; padd1[117]=padd[117];padd[117]=0.054054;t_am[117]+=zlr3[117]; t_2[117]+=pow(zlr3[117],2);zlr3[117]=1;}
			else            {padd[117]=1-(pow(1-0.054054,zlr3[117]+1));zlr3[117]++;}
			//27. Paar
			if(Z_==3||Z_==6){padd_am[118]+=padd[118];padd2[118]+=pow(padd[118],2);zlr2[118]++; padd1[118]=padd[118];padd[118]=0.054054;t_am[118]+=zlr3[118]; t_2[118]+=pow(zlr3[118],2);zlr3[118]=1;}
			else            {padd[118]=1-(pow(1-0.054054,zlr3[118]+1));zlr3[118]++;}
			//28. Paar
			if(Z_==4||Z_==7){padd_am[119]+=padd[119];padd2[119]+=pow(padd[119],2);zlr2[119]++; padd1[119]=padd[119];padd[119]=0.054054;t_am[119]+=zlr3[119]; t_2[119]+=pow(zlr3[119],2);zlr3[119]=1;}
			else            {padd[119]=1-(pow(1-0.054054,zlr3[119]+1));zlr3[119]++;}
			//29. Paar
			if(Z_==5||Z_==8){padd_am[120]+=padd[120];padd2[120]+=pow(padd[120],2);zlr2[120]++; padd1[120]=padd[120];padd[120]=0.054054;t_am[120]+=zlr3[120]; t_2[120]+=pow(zlr3[120],2);zlr3[120]=1;}
			else            {padd[120]=1-(pow(1-0.054054,zlr3[120]+1));zlr3[120]++;}
			//30. Paar
			if(Z_==6||Z_==9){padd_am[121]+=padd[121];padd2[121]+=pow(padd[121],2);zlr2[121]++; padd1[121]=padd[121];padd[121]=0.054054;t_am[121]+=zlr3[121]; t_2[121]+=pow(zlr3[121],2);zlr3[121]=1;}
			else            {padd[121]=1-(pow(1-0.054054,zlr3[121]+1));zlr3[121]++;}
			//31. Paar
			if(Z_==7||Z_==10){padd_am[122]+=padd[122];padd2[122]+=pow(padd[122],2);zlr2[122]++; padd1[122]=padd[122];padd[122]=0.054054;t_am[122]+=zlr3[122]; t_2[122]+=pow(zlr3[122],2);zlr3[122]=1;}
			else            {padd[122]=1-(pow(1-0.054054,zlr3[122]+1));zlr3[122]++;}
			//32. Paar
			if(Z_==8||Z_==11){padd_am[123]+=padd[123];padd2[123]+=pow(padd[123],2);zlr2[123]++; padd1[123]=padd[123];padd[123]=0.054054;t_am[123]+=zlr3[123]; t_2[123]+=pow(zlr3[123],2);zlr3[123]=1;}
			else            {padd[123]=1-(pow(1-0.054054,zlr3[123]+1));zlr3[123]++;}
			//33. Paar
			if(Z_==9||Z_==12){padd_am[124]+=padd[124];padd2[124]+=pow(padd[124],2);zlr2[124]++; padd1[124]=padd[124];padd[124]=0.054054;t_am[124]+=zlr3[124]; t_2[124]+=pow(zlr3[124],2);zlr3[124]=1;}
			else            {padd[124]=1-(pow(1-0.054054,zlr3[124]+1));zlr3[124]++;}
			//34. Paar
			if(Z_==10||Z_==13){padd_am[125]+=padd[125];padd2[125]+=pow(padd[125],2);zlr2[125]++; padd1[125]=padd[125];padd[125]=0.054054;t_am[125]+=zlr3[125]; t_2[125]+=pow(zlr3[125],2);zlr3[125]=1;}
			else            {padd[125]=1-(pow(1-0.054054,zlr3[125]+1));zlr3[125]++;}
			//35. Paar
			if(Z_==11||Z_==14){padd_am[126]+=padd[126];padd2[126]+=pow(padd[126],2);zlr2[126]++; padd1[126]=padd[126];padd[126]=0.054054;t_am[126]+=zlr3[126]; t_2[126]+=pow(zlr3[126],2);zlr3[126]=1;}
			else            {padd[126]=1-(pow(1-0.054054,zlr3[126]+1));zlr3[126]++;}
			//36. Paar
			if(Z_==12||Z_==15){padd_am[127]+=padd[127];padd2[127]+=pow(padd[127],2);zlr2[127]++; padd1[127]=padd[127];padd[127]=0.054054;t_am[127]+=zlr3[127]; t_2[127]+=pow(zlr3[127],2);zlr3[127]=1;}
			else            {padd[127]=1-(pow(1-0.054054,zlr3[127]+1));zlr3[127]++;}
			//37. Paar
			if(Z_==13||Z_==16){padd_am[128]+=padd[128];padd2[128]+=pow(padd[128],2);zlr2[128]++; padd1[128]=padd[128];padd[128]=0.054054;t_am[128]+=zlr3[128]; t_2[128]+=pow(zlr3[128],2);zlr3[128]=1;}
			else            {padd[128]=1-(pow(1-0.054054,zlr3[128]+1));zlr3[128]++;}
			//38. Paar
			if(Z_==14||Z_==17){padd_am[129]+=padd[129];padd2[129]+=pow(padd[129],2);zlr2[129]++; padd1[129]=padd[129];padd[129]=0.054054;t_am[129]+=zlr3[129]; t_2[129]+=pow(zlr3[129],2);zlr3[129]=1;}
			else            {padd[129]=1-(pow(1-0.054054,zlr3[129]+1));zlr3[129]++;}
			//39. Paar
			if(Z_==15||Z_==18){padd_am[130]+=padd[130];padd2[130]+=pow(padd[130],2);zlr2[130]++; padd1[130]=padd[130];padd[130]=0.054054;t_am[130]+=zlr3[130]; t_2[130]+=pow(zlr3[130],2);zlr3[130]=1;}
			else            {padd[130]=1-(pow(1-0.054054,zlr3[130]+1));zlr3[130]++;}
			//40. Paar
			if(Z_==16||Z_==19){padd_am[131]+=padd[131];padd2[131]+=pow(padd[131],2);zlr2[131]++; padd1[131]=padd[131];padd[131]=0.054054;t_am[131]+=zlr3[131]; t_2[131]+=pow(zlr3[131],2);zlr3[131]=1;}
			else            {padd[131]=1-(pow(1-0.054054,zlr3[131]+1));zlr3[131]++;}
			//41. Paar
			if(Z_==17||Z_==20){padd_am[132]+=padd[132];padd2[132]+=pow(padd[132],2);zlr2[132]++; padd1[132]=padd[132];padd[132]=0.054054;t_am[132]+=zlr3[132]; t_2[132]+=pow(zlr3[132],2);zlr3[132]=1;}
			else            {padd[132]=1-(pow(1-0.054054,zlr3[132]+1));zlr3[132]++;}
			//42. Paar
			if(Z_==18||Z_==21){padd_am[133]+=padd[133];padd2[133]+=pow(padd[133],2);zlr2[133]++; padd1[133]=padd[133];padd[133]=0.054054;t_am[133]+=zlr3[133]; t_2[133]+=pow(zlr3[133],2);zlr3[133]=1;}
			else            {padd[133]=1-(pow(1-0.054054,zlr3[133]+1));zlr3[133]++;}
			//43. Paar
			if(Z_==19||Z_==22){padd_am[134]+=padd[134];padd2[134]+=pow(padd[134],2);zlr2[134]++; padd1[134]=padd[134];padd[134]=0.054054;t_am[134]+=zlr3[134]; t_2[134]+=pow(zlr3[134],2);zlr3[134]=1;}
			else            {padd[134]=1-(pow(1-0.054054,zlr3[134]+1));zlr3[134]++;}
			//44. Paar
			if(Z_==20||Z_==23){padd_am[135]+=padd[135];padd2[135]+=pow(padd[135],2);zlr2[135]++; padd1[135]=padd[135];padd[135]=0.054054;t_am[135]+=zlr3[135]; t_2[135]+=pow(zlr3[135],2);zlr3[135]=1;}
			else            {padd[135]=1-(pow(1-0.054054,zlr3[135]+1));zlr3[135]++;}
			//45. Paar
			if(Z_==21||Z_==24){padd_am[136]+=padd[136];padd2[136]+=pow(padd[136],2);zlr2[136]++; padd1[136]=padd[136];padd[136]=0.054054;t_am[136]+=zlr3[136]; t_2[136]+=pow(zlr3[136],2);zlr3[136]=1;}
			else            {padd[136]=1-(pow(1-0.054054,zlr3[136]+1));zlr3[136]++;}
			//46. Paar
			if(Z_==22||Z_==25){padd_am[137]+=padd[137];padd2[137]+=pow(padd[137],2);zlr2[137]++; padd1[137]=padd[137];padd[137]=0.054054;t_am[137]+=zlr3[137]; t_2[137]+=pow(zlr3[137],2);zlr3[137]=1;}
			else            {padd[137]=1-(pow(1-0.054054,zlr3[137]+1));zlr3[137]++;}
			//47. Paar
			if(Z_==23||Z_==26){padd_am[138]+=padd[138];padd2[138]+=pow(padd[138],2);zlr2[138]++; padd1[138]=padd[138];padd[138]=0.054054;t_am[138]+=zlr3[138]; t_2[138]+=pow(zlr3[138],2);zlr3[138]=1;}
			else            {padd[138]=1-(pow(1-0.054054,zlr3[138]+1));zlr3[138]++;}
			//48. Paar
			if(Z_==24||Z_==27){padd_am[139]+=padd[139];padd2[139]+=pow(padd[139],2);zlr2[139]++; padd1[139]=padd[139];padd[139]=0.054054;t_am[139]+=zlr3[139]; t_2[139]+=pow(zlr3[139],2);zlr3[139]=1;}
			else            {padd[139]=1-(pow(1-0.054054,zlr3[139]+1));zlr3[139]++;}
			//49. Paar
			if(Z_==25||Z_==28){padd_am[140]+=padd[140];padd2[140]+=pow(padd[140],2);zlr2[140]++; padd1[140]=padd[140];padd[140]=0.054054;t_am[140]+=zlr3[140]; t_2[140]+=pow(zlr3[140],2);zlr3[140]=1;}
			else            {padd[140]=1-(pow(1-0.054054,zlr3[140]+1));zlr3[140]++;}
			//50. Paar
			if(Z_==26||Z_==29){padd_am[141]+=padd[141];padd2[141]+=pow(padd[141],2);zlr2[141]++; padd1[141]=padd[141];padd[141]=0.054054;t_am[141]+=zlr3[141]; t_2[141]+=pow(zlr3[141],2);zlr3[141]=1;}
			else            {padd[141]=1-(pow(1-0.054054,zlr3[141]+1));zlr3[141]++;}
			//51. Paar
			if(Z_==27||Z_==30){padd_am[142]+=padd[142];padd2[142]+=pow(padd[142],2);zlr2[142]++; padd1[142]=padd[142];padd[142]=0.054054;t_am[142]+=zlr3[142]; t_2[142]+=pow(zlr3[142],2);zlr3[142]=1;}
			else            {padd[142]=1-(pow(1-0.054054,zlr3[142]+1));zlr3[142]++;}
			//52. Paar
			if(Z_==28||Z_==31){padd_am[143]+=padd[143];padd2[143]+=pow(padd[143],2);zlr2[143]++; padd1[143]=padd[143];padd[143]=0.054054;t_am[143]+=zlr3[143]; t_2[143]+=pow(zlr3[143],2);zlr3[143]=1;}
			else            {padd[143]=1-(pow(1-0.054054,zlr3[143]+1));zlr3[143]++;}
			//53. Paar
			if(Z_==29||Z_==32){padd_am[144]+=padd[144];padd2[144]+=pow(padd[144],2);zlr2[144]++; padd1[144]=padd[144];padd[144]=0.054054;t_am[144]+=zlr3[144]; t_2[144]+=pow(zlr3[144],2);zlr3[144]=1;}
			else            {padd[144]=1-(pow(1-0.054054,zlr3[144]+1));zlr3[144]++;}
			//54. Paar
			if(Z_==30||Z_==33){padd_am[145]+=padd[145];padd2[145]+=pow(padd[145],2);zlr2[145]++; padd1[145]=padd[145];padd[145]=0.054054;t_am[145]+=zlr3[145]; t_2[145]+=pow(zlr3[145],2);zlr3[145]=1;}
			else            {padd[145]=1-(pow(1-0.054054,zlr3[145]+1));zlr3[145]++;}
			//55. Paar
			if(Z_==31||Z_==34){padd_am[146]+=padd[146];padd2[146]+=pow(padd[146],2);zlr2[146]++; padd1[146]=padd[146];padd[146]=0.054054;t_am[146]+=zlr3[146]; t_2[146]+=pow(zlr3[146],2);zlr3[146]=1;}
			else            {padd[146]=1-(pow(1-0.054054,zlr3[146]+1));zlr3[146]++;}
			//56. Paar
			if(Z_==32||Z_==35){padd_am[147]+=padd[147];padd2[147]+=pow(padd[147],2);zlr2[147]++; padd1[147]=padd[147];padd[147]=0.054054;t_am[147]+=zlr3[147]; t_2[147]+=pow(zlr3[147],2);zlr3[147]=1;}
			else            {padd[147]=1-(pow(1-0.054054,zlr3[147]+1));zlr3[147]++;}
			//57. Paar
			if(Z_==33||Z_==36){padd_am[148]+=padd[148];padd2[148]+=pow(padd[148],2);zlr2[148]++; padd1[148]=padd[148];padd[148]=0.054054;t_am[148]+=zlr3[148]; t_2[148]+=pow(zlr3[148],2);zlr3[148]=1;}
			else            {padd[148]=1-(pow(1-0.054054,zlr3[148]+1));zlr3[148]++;}
		
			// RND setzung ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if(Z_>=25) gw_1 +=2;                  //gewinnzähler bei rnd einsatz 1 zu 12/37 (3. drittel)
			if(Z_<25)  gw_1 -=1;

			if(Z_!=0&&Z_/2==floor(Z_/2)) gw_2 +=1;//gewinnzähler bei rnd einsatz 1 zu 18/37 (gerade zahl)
			if(       Z_/2!=floor(Z_/2)) gw_2 -=1;
			if(Z_==0)		             gw_2 -=1;

			if(Z_>=31) gw_3 +=5;                  //gewinnzähler bei rnd einsatz 1 zu 6/37 (letzten sechs (z)=(31 32 33 34 35 36))
			if(Z_<31)  gw_3 -=1;

			if(Z_>=32&&Z_!=34) gw_4 +=8;          //gewinnzähler bei rnd einsatz 1 zu 4/37 (letzten vier (z)=(32 33 35 36))
			if(Z_<32||Z_==34)  gw_4 -=1;

			if(Z_>=34) gw_5 +=11;                 //gewinnzähler bei rnd einsatz 1 zu 3/37 (letzten drei (z)=(34 35 36))
			if(Z_< 34)  gw_5 -=1;

			if(Z_>=35) gw_6 +=17;                 //gewinnzähler bei rnd einsatz 1 zu 2/37 (letzten zwei (z)=(35 36))
			if(Z_<35)  gw_6 -=1;
			
			if(Z_==36) gw_7 +=36;                 //gewinnzähler bei rnd einsatz 1 zu 1/37 (z=36)
			if(Z_!=36) gw_7 -=1;
			
			// sel p.add setzung //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
			// Ereignis p.add 
			if(sw>=8&&sw<=14||sw==22||sw==23)
			{
				if(padd1[40]>=padd_sel)
				{
					if(Z_!=0&&Z_/2==floor(Z_/2)) gw_2s +=1;//gewinnzähler bei p.add einsatz 1 zu 18/37 (gerade zahl)
					if(       Z_/2!=floor(Z_/2)) gw_2s -=1;
					if(Z_==0)		             gw_2s -=1;
				}

				if(padd1[44]>=padd_sel)
				{
					if(Z_>=25) gw_1s +=2;                 
					if(Z_<25)  gw_1s -=1;				  //gewinnzähler bei p.add einsatz 1 zu 12/37 (3. drittel)
				}
				
				if(padd1[55]>=padd_sel)
				{
					if(Z_>=31) gw_3s +=5;                 //gewinnzähler bei p.add einsatz 1 zu 6/37 (letzten sechs (z)=(31 32 33 34 35 36))
					if(Z_<31)  gw_3s -=1;
				}

				if(padd1[79]>=padd_sel)
				{
					if(Z_>=32&&Z_!=34) gw_4s +=8;         //gewinnzähler bei p.add einsatz 1 zu 4/37 (letzten vier (z)=(32 33 35 36))
					if(Z_<32||Z_==34)  gw_4s -=1;
				}

				if(padd1[91]>=padd_sel)
				{
					if(Z_>=34) gw_5s +=11;                //gewinnzähler bei p.add einsatz 1 zu 3/37 (letzten drei (z)=(34 35 36))
					if(Z_< 34) gw_5s -=1;
				}

				if(padd1[115]>=padd_sel)
				{	
					if(Z_>=35) gw_6s +=17;                //gewinnzähler bei p.add einsatz 1 zu 2/37 (letzten zwei (z)=(35 36))
					if(Z_<35)  gw_6s -=1;
				}
			
				if(padd1[36]>=padd_sel)
				{
					if(Z_==36) gw_7s +=36;               //gewinnzähler bei p.add einsatz 1 zu 1/37 (z=36)
					if(Z_!=36) gw_7s -=1;
				}
			}
			
			// Mittlere p.add über einzelereigniss p.add z
			if(sw>=15&&sw<=21||sw==24||sw==25)
			{
				if((padd1[2]+padd1[4]+padd1[6]+padd1[8]+padd1[10]+padd1[12]+padd1[14]+padd1[16]+padd1[18]+padd1[20]+padd1[22]+padd1[24]
					+padd1[26]+padd1[28]+padd1[30]+padd1[32]+padd1[34]+padd1[36])/18>=padd_sel)
				{
					if(Z_!=0&&Z_/2==floor(Z_/2)) gw_2s +=1;//gewinnzähler bei p.add z einsatz 1 zu 18/37 (gerade zahl)
					if(Z_/2!=floor(Z_/2)) gw_2s -=1;
					if(Z_==0)		  gw_2s -=1;
				}	

				if((padd1[25]+padd1[26]+padd1[27]+padd1[28]+padd1[29]+padd1[30]+padd1[31]+padd1[32]+padd1[33]+padd1[34]+padd1[35]+padd1[36])/12>=padd_sel)
				{
					if(Z_>=25) gw_1s +=2;                  //gewinnzähler bei p.add z einsatz 1 zu 12/37 (3. drittel)
					if(Z_<25)  gw_1s -=1;
				}
				
				if((padd1[31]+padd1[32]+padd1[33]+padd1[34]+padd1[35]+padd1[36])/6>=padd_sel)
				{
					if(Z_>=31) gw_3s +=5;                  //gewinnzähler bei p.add z einsatz 1 zu 6/37 (letzten sechs (z)=(31 32 33 34 35 36))
					if(Z_<31)  gw_3s -=1;
				}

				if((padd1[32]+padd1[33]+padd1[35]+padd1[36])/4>=padd_sel)
				{
					if(Z_>=32&&Z_!=34) gw_4s +=8;          //gewinnzähler bei p.add z einsatz 1 zu 4/37 (letzten vier (z)=(32 33 35 36))
					if(Z_<32||Z_==34)  gw_4s -=1;
				}

				if((padd1[34]+padd1[35]+padd1[36])/3>=padd_sel)
				{
					if(Z_>=34) gw_5s +=11;                 //gewinnzähler bei p.add z einsatz 1 zu 3/37 (letzten drei (z)=(34 35 36))
					if(Z_< 34)  gw_5s -=1;
				}

				if((padd1[35]+padd1[36])/2>=padd_sel)
				{	
					if(Z_>=35) gw_6s +=17;                 //gewinnzähler bei p.add z einsatz 1 zu 2/37 (letzten zwei (z)=(35 36))
					if(Z_<35)  gw_6s -=1;
				}
			
				if(padd1[36]>=padd_sel)
				{
					if(Z_==36) gw_7s +=36;                 //gewinnzähler bei p.add z einsatz 1 zu 1/37 (z=36)
					if(Z_!=36)  gw_7s -=1;
				}
			}

			//Bildschirmzähler
			if(sw==2)printf("M= %7.0f, e(12|rnd)= %5.0f\r",S_zlr_*M_+zlr1[0],gw_1); //gewinnzähler bei  einsatz 1 zu 12/37
			if(sw==1)printf("M= %7.0f, e(18|rnd)= %5.0f\r",S_zlr_*M_+zlr1[0], gw_2);//gewinnzähler bei  einsatz 1 zu 18/37
			if(sw==3)printf("M= %7.0f, e(6|rnd)= %5.0f\r",S_zlr_*M_+zlr1[0], gw_3); //gewinnzähler bei  einsatz 1 zu 6/37
			if(sw==4)printf("M= %7.0f, eg(4|rnd)= %5.0f\r",S_zlr_*M_+zlr1[0], gw_4);//gewinnzähler bei  einsatz 1 zu 4/37
			if(sw==5)printf("M= %7.0f, e(3|rnd)= %5.0f\r",S_zlr_*M_+zlr1[0], gw_5); //gewinnzähler bei  einsatz 1 zu 3/37
			if(sw==6)printf("M= %7.0f, e(2|rnd)= %5.0f\r",S_zlr_*M_+zlr1[0], gw_6); //gewinnzähler bei  einsatz 1 zu 2/37
			if(sw==7)printf("M= %7.0f, e(1|rnd)= %5.0f\r",S_zlr_*M_+zlr1[0], gw_7); //gewinnzähler bei  einsatz 1 zu 1/37
			if(sw==9||sw==16)printf("M= %7.0f, e(12|%.3f)= %5.0f\r",S_zlr_*M_+zlr1[0],padd_sel, gw_1s);//gewinnzähler bei paddsel einsatz 1 zu 12/37
			if(sw==8||sw==15)printf("M= %7.0f, e(18|%.3f)= %5.0f\r",S_zlr_*M_+zlr1[0],padd_sel, gw_2s);//gewinnzähler bei paddsel einsatz 1 zu 18/37
			if(sw==10||sw==17)printf("M= %7.0f, e(6|%.3f)= %5.0f\r",S_zlr_*M_+zlr1[0],padd_sel, gw_3s);//gewinnzähler bei paddsel einsatz 1 zu 6/37
			if(sw==11||sw==18)printf("M= %7.0f, e(4|%.3f)= %5.0f\r",S_zlr_*M_+zlr1[0],padd_sel, gw_4s);//gewinnzähler bei paddsel einsatz 1 zu 4/37
			if(sw==12||sw==19)printf("M= %7.0f, e(3|%.3f)= %5.0f\r",S_zlr_*M_+zlr1[0],padd_sel, gw_5s);//gewinnzähler bei paddsel einsatz 1 zu 3/37
			if(sw==13||sw==20)printf("M= %7.0f, e(2|%.3f)= %5.0f\r",S_zlr_*M_+zlr1[0],padd_sel, gw_6s);//gewinnzähler bei paddsel einsatz 1 zu 2/37
			if(sw==14||sw==21)printf("M= %7.0f, e(1|%.3f)= %5.0f\r",S_zlr_*M_+zlr1[0],padd_sel, gw_7s);//gewinnzähler bei paddsel einsatz 1 zu 1/37
			if(sw>=22)printf("M= %.0f\r",S_zlr_*M_+zlr1[0]);//zähler bei Matrix G
	
			//G-Matrix 
			if(sw==23||sw==25)
			{
				if(S_zlr_==0&&zlr1[0]==0) //maximal und minimal vektoren initialisierung
				{
					G_[14][i3]=gw_2; G_[15][i3]=gw_2;
					G_[16][i3]=gw_1; G_[17][i3]=gw_1;
					G_[18][i3]=gw_3; G_[19][i3]=gw_3;
					G_[20][i3]=gw_4; G_[21][i3]=gw_4;
					G_[22][i3]=gw_5; G_[23][i3]=gw_5;
					G_[24][i3]=gw_6; G_[25][i3]=gw_6;
					G_[26][i3]=gw_7; G_[27][i3]=gw_7;
					G_[28][i3]=gw_2s;G_[29][i3]=gw_2s;
					G_[30][i3]=gw_1s;G_[31][i3]=gw_1s;
					G_[32][i3]=gw_3s;G_[33][i3]=gw_3s;
					G_[34][i3]=gw_4s;G_[35][i3]=gw_4s;
					G_[36][i3]=gw_5s;G_[37][i3]=gw_5s;
					G_[38][i3]=gw_6s;G_[39][i3]=gw_6s;
					G_[40][i3]=gw_7s;G_[41][i3]=gw_7s;
				}
				//                 maximale minimal und maximalwerte
				
				G_[0][i3]+=gw_2;   if(G_[14][i3]>gw_2 )G_[14][i3]=gw_2; if(G_[15][i3]<gw_2 )G_[15][i3]=gw_2;
				G_[1][i3]+=gw_1;   if(G_[16][i3]>gw_1 )G_[16][i3]=gw_1; if(G_[17][i3]<gw_1 )G_[17][i3]=gw_1;
				G_[2][i3]+=gw_3;   if(G_[18][i3]>gw_3 )G_[18][i3]=gw_3; if(G_[19][i3]<gw_3 )G_[19][i3]=gw_3;
				G_[3][i3]+=gw_4;   if(G_[20][i3]>gw_4 )G_[20][i3]=gw_4; if(G_[21][i3]<gw_4 )G_[21][i3]=gw_4;
				G_[4][i3]+=gw_5;   if(G_[22][i3]>gw_5 )G_[22][i3]=gw_5; if(G_[23][i3]<gw_5 )G_[23][i3]=gw_5;
				G_[5][i3]+=gw_6;   if(G_[24][i3]>gw_6 )G_[24][i3]=gw_6; if(G_[25][i3]<gw_6 )G_[25][i3]=gw_6;
				G_[6][i3]+=gw_7;   if(G_[26][i3]>gw_7 )G_[26][i3]=gw_7; if(G_[27][i3]<gw_7 )G_[27][i3]=gw_7;
				G_[7][i3]+=gw_2s;  if(G_[28][i3]>gw_2s)G_[28][i3]=gw_2s;if(G_[29][i3]<gw_2s)G_[29][i3]=gw_2s;
				G_[8][i3]+=gw_1s;  if(G_[30][i3]>gw_1s)G_[30][i3]=gw_1s;if(G_[31][i3]<gw_1s)G_[31][i3]=gw_1s;
				G_[9][i3]+=gw_3s;  if(G_[32][i3]>gw_3s)G_[32][i3]=gw_3s;if(G_[33][i3]<gw_3s)G_[33][i3]=gw_3s;
				G_[10][i3]+=gw_4s; if(G_[34][i3]>gw_4s)G_[34][i3]=gw_4s;if(G_[35][i3]<gw_4s)G_[35][i3]=gw_4s;
				G_[11][i3]+=gw_5s; if(G_[36][i3]>gw_5s)G_[36][i3]=gw_5s;if(G_[37][i3]<gw_5s)G_[37][i3]=gw_5s;
				G_[12][i3]+=gw_6s; if(G_[38][i3]>gw_6s)G_[38][i3]=gw_6s;if(G_[39][i3]<gw_6s)G_[39][i3]=gw_6s;
				G_[13][i3]+=gw_7s; if(G_[40][i3]>gw_7s)G_[40][i3]=gw_7s;if(G_[41][i3]<gw_7s)G_[41][i3]=gw_7s;
			}
			
			if((sw==22||sw==24)&&S_==1&&zlr1[0]<=66000)
			 fprintf(out,"%.0f\t%.0f\t%.0f\t%.0f\t%.0f\t%.0f\t%.0f\t%.0f\t%.0f\t%.0f\t%.0f\t%.0f\t%.0f\t%.0f\n",
				gw_2, gw_1, gw_3, gw_4, gw_5,gw_6,gw_7,gw_2s, gw_1s, gw_3s, gw_4s, gw_5s,gw_6s,gw_7s ); //Matrix G ausgabe bei S==1
	
			//maximalwerte
			if(gw_1>max[1]) max[1]= gw_1;
			if(gw_2>max[2]) max[2]= gw_2;
			if(gw_3>max[3]) max[3]= gw_3;
			if(gw_4>max[4]) max[4]= gw_4;
			if(gw_5>max[5]) max[5]= gw_5;
			if(gw_6>max[6]) max[6]= gw_6;
			if(gw_7>max[7]) max[7]= gw_7;

			if(gw_1s>max[8])  max[8]= gw_1s;
			if(gw_2s>max[9])  max[9]= gw_2s;
			if(gw_3s>max[10]) max[10]= gw_3s;
			if(gw_4s>max[11]) max[11]= gw_4s;
			if(gw_5s>max[12]) max[12]= gw_5s;
			if(gw_6s>max[13]) max[13]= gw_6s;
			if(gw_7s>max[14]) max[14]= gw_7s;

			//minimalwerte
			if(gw_1<min[1]) min[1]= gw_1;
			if(gw_2<min[2]) min[2]= gw_2;
			if(gw_3<min[3]) min[3]= gw_3;
			if(gw_4<min[4]) min[4]= gw_4;
			if(gw_5<min[5]) min[5]= gw_5;
			if(gw_6<min[6]) min[6]= gw_6;
			if(gw_7<min[7]) min[7]= gw_7;

			if(gw_1s<min[8])  min[8]= gw_1s;
			if(gw_2s<min[9])  min[9]= gw_2s;
			if(gw_3s<min[10]) min[10]= gw_3s;
			if(gw_4s<min[11]) min[11]= gw_4s;
			if(gw_5s<min[12]) min[12]= gw_5s;
			if(gw_6s<min[13]) min[13]= gw_6s;
			if(gw_7s<min[14]) min[14]= gw_7s;	
			
			zlr1[0]++;i3++;
		}

		sum_[1][1]+=gw_1; sum_[2][1]+=gw_1s;
		sum_[1][2]+=gw_2; sum_[2][2]+=gw_2s;
		sum_[1][3]+=gw_3; sum_[2][3]+=gw_3s;
		sum_[1][4]+=gw_4; sum_[2][4]+=gw_4s;
		sum_[1][5]+=gw_5; sum_[2][5]+=gw_5s;
		sum_[1][6]+=gw_6; sum_[2][6]+=gw_6s;
		sum_[1][7]+=gw_7; sum_[2][7]+=gw_7s;

	
		for(iLauf=0;iLauf<=148;iLauf++) 
		{
			sum_[3][iLauf]+=zlr2[iLauf];
			sum_[4][iLauf]+=padd_am[iLauf];
			sum_[5][iLauf]+=t_am[iLauf];
			sum_[6][iLauf]+=padd2[iLauf];
			sum_[7][iLauf]+=t_2[iLauf];
		}

		S_zlr_++;i3=0;
	}

	for(iLauf=0;iLauf<=148;iLauf++) 
	{
		zlr2[iLauf]=   sum_[3][iLauf]/S_;
		padd_am[iLauf]=sum_[4][iLauf]/S_;
		t_am[iLauf]=   sum_[5][iLauf]/S_;
		padd2[iLauf]=  sum_[6][iLauf]/S_;
		t_2[iLauf]=    sum_[7][iLauf]/S_;
	}

	//G Matrix Mittelung
	if(sw==23||sw==25)
	{
		for(iLauf=0;iLauf<=13;iLauf++)
		for(jLauf=0;jLauf<=M_;jLauf++)G_[iLauf][jLauf]/=S_;
	}

	if(sw==23||sw==25)
	{	
		for(jLauf=0;jLauf<=M_-1;jLauf++)
		{
			for(iLauf=0;iLauf<=41;iLauf++)fprintf(out,"%.3f\t",G_[iLauf][jLauf]);// Matrix G ausgabe bei S>1
			fprintf(out,"\n");
		}
	}

	// Ergebnistabelle
	if(sw!=22&&sw!=23&&sw!=24&&sw!=25)
	{
		fprintf(out,"Roulette Simulation, M=%.0f, S=%.0f, seed=%.0f\n",M_,S_,sd1);
		fprintf(out,"------------------------------------------------------------------------------------------------\n");
		fprintf(out,"\t\t\t\t\t\t\t\tp.add\t\tt\n");
		fprintf(out,"\t\t\t\t\t\t\t\t-------------\t----------------\n");
		fprintf(out,"z\tp(e)\t\tm\tp(m/M)\t\tdiff(p)\t\tAM\ts\tAM\ts\n");
		fprintf(out,"------------------------------------------------------------------------------------------------\n");
		
		// 1/37 /////////////////////////////////////////////////////////////////////////////////////////////////////////// 
		for(iLauf=0;iLauf<=36;iLauf++)
		{
			pdiff=1.0/37-zlr2[iLauf]/M_;
			   sum_zlr2+=zlr2[iLauf];
			
			if(zlr2[iLauf]==0) { sum_pads+=0; sum_pdiff+=0;     sum_padd+=0;                            mn++;}
			if(zlr2[iLauf]> 0) 
			{                    sum_pdiff+=pdiff; sum_padd+=padd_am[iLauf]/(zlr2[iLauf]);
			                     sum_pads+=sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)));
			}

			if(S_==1) // Bei einem Simulationszyklus M, S=1
			{
				if(zlr2[iLauf]==1)  mn1++;
				if(zlr2[iLauf]> 1)  sum_ts+=sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2));
				if(t_am[iLauf]>=1){ sum_t+=t_am[iLauf]/(zlr2[iLauf]);    }
				if(t_am[iLauf]< 1){ sum_t+=0; if(zlr2[iLauf]==0)sum_t+=0;}
			}
			
			if(S_>1) // Bei Metazyklen S>1
			{
				if(zlr2[iLauf]*S_==1) mn1++;
				if(zlr2[iLauf]*S_> 1) sum_ts+=sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2));
				if(zlr2[iLauf]>0    ) sum_t+=t_am[iLauf]/(zlr2[iLauf]);
			}

			// Bei keinem Ereignis zi
			if(zlr2[iLauf]==0)          fprintf(out,"%i\t%0.6f\t%6.0f\t{}      \t{}      \t{}   \t{}   \t{}   \t{}   \n", 
				                                                               iLauf,  1.0/37, zlr2[iLauf]); 
			// Bei ein- oder mehrmaligem Ereignis zi
			if(zlr2[iLauf]> 0) 
			{
				if(S_==1)               fprintf(out,"%i\t%0.6f\t%6.0f\t%.6f",  iLauf,  1.0/37, zlr2[iLauf], zlr2[iLauf]/M_); // p(e), m, p(m/M)
				if(S_> 1)               fprintf(out,"%i\t%0.6f\t%6.1f\t%.6f",  iLauf,  1.0/37, zlr2[iLauf], zlr2[iLauf]/M_); //
										
				if(pdiff< 0)            fprintf(out,"\t%.6f",                  pdiff); // Wahrscheinlichkeits p(e)-p(m/M) Differenz
				if(pdiff>=0)            fprintf(out,"\t+%.6f",                 pdiff); //
		
				if(M_==1)               fprintf(out,"\t{}   \t{}   \t{}   \t{}   \n");

				if(M_>1&&S_==1) // Bei einem Simulationszyklus M, S=1 // Mittlere Additiv Wahrscheinlichkeiten p.add und Wartezeiten t //
				{
				if(zlr2[iLauf]!=1)      fprintf(out,"\t%.3f\t%.3f\t%.3f",      padd_am[iLauf]/(zlr2[iLauf]),sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)) ),
													                           t_am[iLauf]/(zlr2[iLauf]));
		
				if(zlr2[iLauf]==1)      fprintf(out,"\t%.3f\t{}   \t%.3f",     padd_am[iLauf]/(zlr2[iLauf]),
													                           t_am[iLauf]/(zlr2[iLauf]) );
				}

				if(M_>1&&S_> 1) // Bei Metazyklen S>1 // Mittlere Additiv Wahrscheinlichkeiten p.add und Wartezeiten t //
				{
				if(zlr2[iLauf]*S_> 1)   fprintf(out,"\t%.3f\t%.3f\t%.3f",      padd_am[iLauf]/(zlr2[iLauf]),
					                                                           sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)) ),
													                           t_am[iLauf]/(zlr2[iLauf]));
		
				if(zlr2[iLauf]*S_==1)   fprintf(out,"\t%.3f\t{}   \t%.3f",     padd_am[iLauf]/(zlr2[iLauf]),
													                           t_am[iLauf]/(zlr2[iLauf]) );
				}
			}

			if(M_>1&&S_==1) // Bei einem Simulationszyklus M, S=1 // Standardabweichungen s der Wartezeiten t //
			{
				if(zlr2[iLauf]==1){     fprintf(out,"\t{}   \n");mn2++; }
				if(zlr2[iLauf]> 1)      fprintf(out,"\t%.3f\n",                sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2)) );
			}

			if(M_>1&&S_>1&&zlr2[iLauf]> 0) // Bei Metazyklen S>1 // Standardabweichungen s der Wartezeiten t //
			{
				if(zlr2[iLauf]*S_==1){  fprintf(out,"\t{}   \n");mn2++; }
				if(zlr2[iLauf]*S_> 1)   fprintf(out,"\t%.3f\n",                sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2)) );
			}
		}
		// Mittelwerte der gemittelten Kennwerte 
		fprintf(out,"\t--------\t------\t--------\t---------\t-----\t-----\t------\t------\n");
		if(S_==1)                       fprintf(out,"AM\t%0.6f\t%6.0f\t%0.6f", 1.0/37, sum_zlr2/37,sum_zlr2/(37-mn)/M_);// p(e), m, p(m/M)
		if(S_> 1)                       fprintf(out,"AM\t%0.6f\t%6.1f\t%0.6f", 1.0/37, sum_zlr2/37,sum_zlr2/(37-mn)/M_);//
		if(sum_pdiff/37>  0.0000001  )  fprintf(out,"\t+%0.6f",                sum_pdiff/(37-mn) );// Wahrscheinlichkeits p(e)-p(m/M) Differenz
		if(sum_pdiff/37< -0.0000001  )  fprintf(out,"\t%0.6f",                 sum_pdiff/(37-mn) );//    
		if(sum_pdiff/37>=-0.0000001&&
		   sum_pdiff/37<= 0.0000001  )  fprintf(out,"\t\xb1%0.6f",             fabs(sum_pdiff/(37-mn)) );// 
		
		//Bei einem Simulationszyklus M>1
		if(M_> 1) 
		{
			                            fprintf(out,"\t%0.3f",                 sum_padd/(37-mn));    //AM(p.add)
			if(mn+mn1<37)               fprintf(out,"\t%0.3f",                 sum_pads/(37-mn-mn1));//s(p.add)
			if(mn+mn1==37)              fprintf(out,"\t{}   ");//Bei keinen Streuungen s(p.add)

			                            fprintf(out,"\t%0.3f",                 sum_t/(37-mn) );      //AM(t)
			if(mn+mn2<37)               fprintf(out,"\t%0.3f\n\n",             sum_ts/(37-mn-mn2) ); //s(t)
			if(S_==1&&mn+mn2==37)       fprintf(out,"\t{}   \n\n"); //Bei einem Simulationszyklus M, S=1 und keinen Streuungen s(t)
			if(S_> 1&&mn+mn2==37)       fprintf(out,"\t{}   \n\n"); //Bei Metazyklen S>1, und keinen Streuungen s(t)
		}
		
		//bei genau einem Simulations Ereignis M=1 
		if(M_==1)                     fprintf(out,"\t{}   \t{}   \t{}   \t{}   \n\n");
	
		mn=0;mn1=0;mn2=0;

		// 18/37 ///////////////////////////////////////////////////////////////////////////////////////////////////////////
		fprintf(out,"18/37\n");
		sum_zlr2=sum_pdiff=sum_padd=sum_pads=sum_t=sum_ts=0;
		
		for(iLauf=40;iLauf<=41;iLauf++)
		{
			pdiff=18.0/37-zlr2[iLauf]/M_;
			   sum_zlr2+=zlr2[iLauf];
			
			if(zlr2[iLauf]==0) { sum_pads+=0; sum_pdiff+=0;     sum_padd+=0;                            mn++;}
			if(zlr2[iLauf]> 0) 
			{                    sum_pdiff+=pdiff; sum_padd+=padd_am[iLauf]/(zlr2[iLauf]);
			                     sum_pads+=sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)));
			}

			if(S_==1) // Bei einem Simulationszyklus M, S=1
			{
				if(zlr2[iLauf]==1)  mn1++;
				if(zlr2[iLauf]> 1)  sum_ts+=sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2));
				if(t_am[iLauf]>=1){ sum_t+=t_am[iLauf]/(zlr2[iLauf]);    }
				if(t_am[iLauf]< 1){ sum_t+=0; if(zlr2[iLauf]==0)sum_t+=0;}
			}
			
			if(S_>1) // Bei Metazyklen S>1
			{
				if(zlr2[iLauf]*S_==1) mn1++;
				if(zlr2[iLauf]*S_> 1) sum_ts+=sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2));
				if(zlr2[iLauf]>0    ) sum_t+=t_am[iLauf]/(zlr2[iLauf]);
			}

			// Bei keinem Ereignis zi
			if(zlr2[iLauf]==0)          fprintf(out,"%i\t%0.6f\t%6.0f\t{}      \t{}      \t{}   \t{}   \t{}   \t{}   \n", 
				                                                               iLauf-39,  18.0/37, zlr2[iLauf]); 
			// Bei ein- oder mehrmaligem Ereignis zi
			if(zlr2[iLauf]> 0) 
			{
				if(S_==1)               fprintf(out,"%i\t%0.6f\t%6.0f\t%.6f",  iLauf-39,  18.0/37, zlr2[iLauf], zlr2[iLauf]/M_); // p(e), m, p(m/M)
				if(S_> 1)               fprintf(out,"%i\t%0.6f\t%6.1f\t%.6f",  iLauf-39,  18.0/37, zlr2[iLauf], zlr2[iLauf]/M_); //
										
				if(pdiff< 0)            fprintf(out,"\t%.6f",                  pdiff); // Wahrscheinlichkeits p(e)-p(m/M) Differenz
				if(pdiff>=0)            fprintf(out,"\t+%.6f",                 pdiff); //
		
				if(M_==1)               fprintf(out,"\t{}   \t{}   \t{}   \t{}   \n");

				if(M_>1&&S_==1) // Bei einem Simulationszyklus M, S=1 // Mittlere Additiv Wahrscheinlichkeiten p.add und Wartezeiten t //
				{
				if(zlr2[iLauf]!=1)      fprintf(out,"\t%.3f\t%.3f\t%.3f",      padd_am[iLauf]/(zlr2[iLauf]),sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)) ),
													                           t_am[iLauf]/(zlr2[iLauf]));
		
				if(zlr2[iLauf]==1)      fprintf(out,"\t%.3f\t{}   \t%.3f",     padd_am[iLauf]/(zlr2[iLauf]),
													                           t_am[iLauf]/(zlr2[iLauf]) );
				}

				if(M_>1&&S_> 1) // Bei Metazyklen S>1 // Mittlere Additiv Wahrscheinlichkeiten p.add und Wartezeiten t //
				{
				if(zlr2[iLauf]*S_> 1)   fprintf(out,"\t%.3f\t%.3f\t%.3f",      padd_am[iLauf]/(zlr2[iLauf]),
					                                                           sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)) ),
													                           t_am[iLauf]/(zlr2[iLauf]));
		
				if(zlr2[iLauf]*S_==1)   fprintf(out,"\t%.3f\t{}   \t%.3f",     padd_am[iLauf]/(zlr2[iLauf]),
													                           t_am[iLauf]/(zlr2[iLauf]) );
				}
			}

			if(M_>1&&S_==1) // Bei einem Simulationszyklus M, S=1 // Standardabweichungen s der Wartezeiten t //
			{
				if(zlr2[iLauf]==1){     fprintf(out,"\t{}   \n");mn2++; }
				if(zlr2[iLauf]> 1)      fprintf(out,"\t%.3f\n",                sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2)) );
			}

			if(M_>1&&S_>1&&zlr2[iLauf]> 0) // Bei Metazyklen S>1 // Standardabweichungen s der Wartezeiten t //
			{
				if(zlr2[iLauf]*S_==1){  fprintf(out,"\t{}   \n");mn2++; }
				if(zlr2[iLauf]*S_> 1)   fprintf(out,"\t%.3f\n",                sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2)) );
			}
		}
		// Mittelwerte der gemittelten Kennwerte 
		fprintf(out,"\t--------\t------\t--------\t---------\t-----\t-----\t------\t------\n");
		if(S_==1)                       fprintf(out,"AM\t%0.6f\t%6.0f\t%0.6f", 18.0/37, sum_zlr2/2,sum_zlr2/(2-mn)/M_);// p(e), m, p(m/M)
		if(S_> 1)                       fprintf(out,"AM\t%0.6f\t%6.1f\t%0.6f", 18.0/37, sum_zlr2/2,sum_zlr2/(2-mn)/M_);//
		if(sum_pdiff/2 >  0.0000001  )  fprintf(out,"\t+%0.6f",                sum_pdiff/(2-mn) );// Wahrscheinlichkeits p(e)-p(m/M) Differenz
		if(sum_pdiff/2 < -0.0000001  )  fprintf(out,"\t%0.6f",                 sum_pdiff/(2-mn) );//    
		if(sum_pdiff/2 >=-0.0000001&&
		   sum_pdiff/2 <= 0.0000001  )  fprintf(out,"\t\xb1%0.6f",             fabs(sum_pdiff/(2-mn)) );// 
		
		//Bei einem Simulationszyklus M>1
		if(M_> 1) 
		{
			                           fprintf(out,"\t%0.3f",                 sum_padd/(2-mn));    //AM(p.add)
			if(mn+mn1<2 )              fprintf(out,"\t%0.3f",                 sum_pads/(2-mn-mn1));//s(p.add)
			if(mn+mn1==2)              fprintf(out,"\t{}   ");//Bei keinen Streuungen s(p.add)
			                           fprintf(out,"\t%0.3f",                 sum_t/(2-mn) );      //AM(t)
			if(mn+mn2<2)               fprintf(out,"\t%0.3f\n\n",             sum_ts/(2-mn-mn2) ); //s(t)
			if(S_==1&&mn+mn2==2)       fprintf(out,"\t{}   \n\n"); //Bei einem Simulationszyklus M, S=1 und keinen Streuungen s(t)
			if(S_> 1&&mn+mn2==2)       fprintf(out,"\t{}   \n\n"); //Bei Metazyklen S>1, und keinen Streuungen s(t)
		}
		
		//bei genau einem Simulations Ereignis M=1 
		if(M_==1)                     fprintf(out,"\t{}   \t{}   \t{}   \t{}   \n\n");
	
		mn=0;mn1=0;mn2=0;
	

		// 12/37 ///////////////////////////////////////////////////////////////////////////////////////////////////////////
		fprintf(out,"12/37\n");
		sum_zlr2=sum_pdiff=sum_padd=sum_pads=sum_t=sum_ts=0;
		for(iLauf=42;iLauf<=44;iLauf++)
		{
				pdiff=12.0/37-zlr2[iLauf]/M_;
			   sum_zlr2+=zlr2[iLauf];
			
			if(zlr2[iLauf]==0) { sum_pads+=0; sum_pdiff+=0;     sum_padd+=0;                            mn++;}
			if(zlr2[iLauf]> 0) 
			{                    sum_pdiff+=pdiff; sum_padd+=padd_am[iLauf]/(zlr2[iLauf]);
			                     sum_pads+=sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)));
			}

			if(S_==1) // Bei einem Simulationszyklus M, S=1
			{
				if(zlr2[iLauf]==1)  mn1++;
				if(zlr2[iLauf]> 1)  sum_ts+=sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2));
				if(t_am[iLauf]>=1){ sum_t+=t_am[iLauf]/(zlr2[iLauf]);    }
				if(t_am[iLauf]< 1){ sum_t+=0; if(zlr2[iLauf]==0)sum_t+=0;}
			}
			
			if(S_>1) // Bei Metazyklen S>1
			{
				if(zlr2[iLauf]*S_==1) mn1++;
				if(zlr2[iLauf]*S_> 1) sum_ts+=sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2));
				if(zlr2[iLauf]>0    ) sum_t+=t_am[iLauf]/(zlr2[iLauf]);
			}

			// Bei keinem Ereignis zi
			if(zlr2[iLauf]==0)          fprintf(out,"%i\t%0.6f\t%6.0f\t{}      \t{}      \t{}   \t{}   \t{}   \t{}   \n", 
				                                                               iLauf-41,  12.0/37, zlr2[iLauf]); 
			// Bei ein- oder mehrmaligem Ereignis zi
			if(zlr2[iLauf]> 0) 
			{
				if(S_==1)               fprintf(out,"%i\t%0.6f\t%6.0f\t%.6f",  iLauf-41,  12.0/37, zlr2[iLauf], zlr2[iLauf]/M_); // p(e), m, p(m/M)
				if(S_> 1)               fprintf(out,"%i\t%0.6f\t%6.1f\t%.6f",  iLauf-41,  12.0/37, zlr2[iLauf], zlr2[iLauf]/M_); //
										
				if(pdiff< 0)            fprintf(out,"\t%.6f",                  pdiff); // Wahrscheinlichkeits p(e)-p(m/M) Differenz
				if(pdiff>=0)            fprintf(out,"\t+%.6f",                 pdiff); //
		
				if(M_==1)               fprintf(out,"\t{}   \t{}   \t{}   \t{}   \n");

				if(M_>1&&S_==1) // Bei einem Simulationszyklus M, S=1 // Mittlere Additiv Wahrscheinlichkeiten p.add und Wartezeiten t //
				{
				if(zlr2[iLauf]!=1)      fprintf(out,"\t%.3f\t%.3f\t%.3f",      padd_am[iLauf]/(zlr2[iLauf]),sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)) ),
													                           t_am[iLauf]/(zlr2[iLauf]));
		
				if(zlr2[iLauf]==1)      fprintf(out,"\t%.3f\t{}   \t%.3f",     padd_am[iLauf]/(zlr2[iLauf]),
													                           t_am[iLauf]/(zlr2[iLauf]) );
				}

				if(M_>1&&S_> 1) // Bei Metazyklen S>1 // Mittlere Additiv Wahrscheinlichkeiten p.add und Wartezeiten t //
				{
				if(zlr2[iLauf]*S_> 1)   fprintf(out,"\t%.3f\t%.3f\t%.3f",      padd_am[iLauf]/(zlr2[iLauf]),
					                                                           sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)) ),
													                           t_am[iLauf]/(zlr2[iLauf]));
		
				if(zlr2[iLauf]*S_==1)   fprintf(out,"\t%.3f\t{}   \t%.3f",     padd_am[iLauf]/(zlr2[iLauf]),
													                           t_am[iLauf]/(zlr2[iLauf]) );
				}
			}

			if(M_>1&&S_==1) // Bei einem Simulationszyklus M, S=1 // Standardabweichungen s der Wartezeiten t //
			{
				if(zlr2[iLauf]==1){     fprintf(out,"\t{}   \n");mn2++; }
				if(zlr2[iLauf]> 1)      fprintf(out,"\t%.3f\n",                sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2)) );
			}

			if(M_>1&&S_>1&&zlr2[iLauf]> 0) // Bei Metazyklen S>1 // Standardabweichungen s der Wartezeiten t //
			{
				if(zlr2[iLauf]*S_==1){  fprintf(out,"\t{}   \n");mn2++; }
				if(zlr2[iLauf]*S_> 1)   fprintf(out,"\t%.3f\n",                sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2)) );
			}
		}
		// Mittelwerte der gemittelten Kennwerte 
		fprintf(out,"\t--------\t------\t--------\t---------\t-----\t-----\t------\t------\n");
		if(S_==1)                       fprintf(out,"AM\t%0.6f\t%6.0f\t%0.6f", 12.0/37, sum_zlr2/3,sum_zlr2/(3-mn)/M_);// p(e), m, p(m/M)
		if(S_> 1)                       fprintf(out,"AM\t%0.6f\t%6.1f\t%0.6f", 12.0/37, sum_zlr2/3,sum_zlr2/(3-mn)/M_);//
		if(sum_pdiff/3 >  0.0000001  )  fprintf(out,"\t+%0.6f",                sum_pdiff/(3-mn) );// Wahrscheinlichkeits p(e)-p(m/M) Differenz
		if(sum_pdiff/3 < -0.0000001  )  fprintf(out,"\t%0.6f",                 sum_pdiff/(3-mn) );//    
		if(sum_pdiff/3 >=-0.0000001&&
		   sum_pdiff/3 <= 0.0000001  )  fprintf(out,"\t\xb1%0.6f",             fabs(sum_pdiff/(3-mn)) );// 
		
		//Bei einem Simulationszyklus M>1
		if(M_> 1) 
		{
			                           fprintf(out,"\t%0.3f",                 sum_padd/(3-mn));    //AM(p.add)
			if(mn+mn1<3 )              fprintf(out,"\t%0.3f",                 sum_pads/(3-mn-mn1));//s(p.add)
			if(mn+mn1==3)              fprintf(out,"\t{}   ");//Bei keinen Streuungen s(p.add)
			                           fprintf(out,"\t%0.3f",                 sum_t/(3-mn) );      //AM(t)
			if(mn+mn2<3 )              fprintf(out,"\t%0.3f\n\n",             sum_ts/(3-mn-mn2) ); //s(t)
			if(S_==1&&mn+mn2==3)       fprintf(out,"\t{}   \n\n"); //Bei einem Simulationszyklus M, S=1 und keinen Streuungen s(t)
			if(S_> 1&&mn+mn2==3)       fprintf(out,"\t{}   \n\n"); //Bei Metazyklen S>1, und keinen Streuungen s(t)
		}
		
		//bei genau einem Simulations Ereignis M=1 
		if(M_==1)                     fprintf(out,"\t{}   \t{}   \t{}   \t{}   \n\n");
	
		mn=0;mn1=0;mn2=0;

		// 6/37 ///////////////////////////////////////////////////////////////////////////////////////////////////////////
		fprintf(out,"6/37\n");
		sum_zlr2=sum_pdiff=sum_padd=sum_pads=sum_t=sum_ts=0;
		for(iLauf=45;iLauf<=55;iLauf++)
		{
			pdiff=6.0/37-zlr2[iLauf]/M_;
			   sum_zlr2+=zlr2[iLauf];
			
			if(zlr2[iLauf]==0) { sum_pads+=0; sum_pdiff+=0;     sum_padd+=0;                            mn++;}
			if(zlr2[iLauf]> 0) 
			{                    sum_pdiff+=pdiff; sum_padd+=padd_am[iLauf]/(zlr2[iLauf]);
			                     sum_pads+=sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)));
			}

			if(S_==1) // Bei einem Simulationszyklus M, S=1
			{
				if(zlr2[iLauf]==1)  mn1++;
				if(zlr2[iLauf]> 1)  sum_ts+=sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2));
				if(t_am[iLauf]>=1){ sum_t+=t_am[iLauf]/(zlr2[iLauf]);    }
				if(t_am[iLauf]< 1){ sum_t+=0; if(zlr2[iLauf]==0)sum_t+=0;}
			}
			
			if(S_>1) // Bei Metazyklen S>1
			{
				if(zlr2[iLauf]*S_==1) mn1++;
				if(zlr2[iLauf]*S_> 1) sum_ts+=sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2));
				if(zlr2[iLauf]>0    ) sum_t+=t_am[iLauf]/(zlr2[iLauf]);
			}

			// Bei keinem Ereignis zi
			if(zlr2[iLauf]==0)          fprintf(out,"%i\t%0.6f\t%6.0f\t{}      \t{}      \t{}   \t{}   \t{}   \t{}   \n", 
				                                                               iLauf-44,  6.0/37, zlr2[iLauf]); 
			// Bei ein- oder mehrmaligem Ereignis zi
			if(zlr2[iLauf]> 0) 
			{
				if(S_==1)               fprintf(out,"%i\t%0.6f\t%6.0f\t%.6f",  iLauf-44,  6.0/37, zlr2[iLauf], zlr2[iLauf]/M_); // p(e), m, p(m/M)
				if(S_> 1)               fprintf(out,"%i\t%0.6f\t%6.1f\t%.6f",  iLauf-44,  6.0/37, zlr2[iLauf], zlr2[iLauf]/M_); //
										
				if(pdiff< 0)            fprintf(out,"\t%.6f",                  pdiff); // Wahrscheinlichkeits p(e)-p(m/M) Differenz
				if(pdiff>=0)            fprintf(out,"\t+%.6f",                 pdiff); //
		
				if(M_==1)               fprintf(out,"\t{}   \t{}   \t{}   \t{}   \n");

				if(M_>1&&S_==1) // Bei einem Simulationszyklus M, S=1 // Mittlere Additiv Wahrscheinlichkeiten p.add und Wartezeiten t //
				{
				if(zlr2[iLauf]!=1)      fprintf(out,"\t%.3f\t%.3f\t%.3f",      padd_am[iLauf]/(zlr2[iLauf]),sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)) ),
													                           t_am[iLauf]/(zlr2[iLauf]));
		
				if(zlr2[iLauf]==1)      fprintf(out,"\t%.3f\t{}   \t%.3f",     padd_am[iLauf]/(zlr2[iLauf]),
													                           t_am[iLauf]/(zlr2[iLauf]) );
				}

				if(M_>1&&S_> 1) // Bei Metazyklen S>1 // Mittlere Additiv Wahrscheinlichkeiten p.add und Wartezeiten t //
				{
				if(zlr2[iLauf]*S_> 1)   fprintf(out,"\t%.3f\t%.3f\t%.3f",      padd_am[iLauf]/(zlr2[iLauf]),
					                                                           sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)) ),
													                           t_am[iLauf]/(zlr2[iLauf]));
		
				if(zlr2[iLauf]*S_==1)   fprintf(out,"\t%.3f\t{}   \t%.3f",     padd_am[iLauf]/(zlr2[iLauf]),
													                           t_am[iLauf]/(zlr2[iLauf]) );
				}
			}

			if(M_>1&&S_==1) // Bei einem Simulationszyklus M, S=1 // Standardabweichungen s der Wartezeiten t //
			{
				if(zlr2[iLauf]==1){     fprintf(out,"\t{}   \n");mn2++; }
				if(zlr2[iLauf]> 1)      fprintf(out,"\t%.3f\n",                sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2)) );
			}

			if(M_>1&&S_>1&&zlr2[iLauf]> 0) // Bei Metazyklen S>1 // Standardabweichungen s der Wartezeiten t //
			{
				if(zlr2[iLauf]*S_==1){  fprintf(out,"\t{}   \n");mn2++; }
				if(zlr2[iLauf]*S_> 1)   fprintf(out,"\t%.3f\n",                sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2)) );
			}
		}
		// Mittelwerte der gemittelten Kennwerte 
		fprintf(out,"\t--------\t------\t--------\t---------\t-----\t-----\t------\t------\n");
		if(S_==1)                       fprintf(out,"AM\t%0.6f\t%6.0f\t%0.6f", 6.0/37, sum_zlr2/11,sum_zlr2/(11-mn)/M_);// p(e), m, p(m/M)
		if(S_> 1)                       fprintf(out,"AM\t%0.6f\t%6.1f\t%0.6f", 6.0/37, sum_zlr2/11,sum_zlr2/(11-mn)/M_);//
		if(sum_pdiff/11>  0.0000001  )  fprintf(out,"\t+%0.6f",                sum_pdiff/(11-mn) );// Wahrscheinlichkeits p(e)-p(m/M) Differenz
		if(sum_pdiff/11< -0.0000001  )  fprintf(out,"\t%0.6f",                 sum_pdiff/(11-mn) );//    
		if(sum_pdiff/11>=-0.0000001&&
		   sum_pdiff/11<= 0.0000001  )  fprintf(out,"\t\xb1%0.6f",             fabs(sum_pdiff/(11-mn)) );// 
		
		//Bei einem Simulationszyklus M>1
		if(M_> 1) 
		{
			                            fprintf(out,"\t%0.3f",                 sum_padd/(11-mn));    //AM(p.add)
			if(mn+mn1<11)               fprintf(out,"\t%0.3f",                 sum_pads/(11-mn-mn1));//s(p.add)
			if(mn+mn1==11)              fprintf(out,"\t{}   ");//Bei keinen Streuungen s(p.add)

			                            fprintf(out,"\t%0.3f",                 sum_t/(11-mn) );      //AM(t)
			if(mn+mn2<11)               fprintf(out,"\t%0.3f\n\n",             sum_ts/(11-mn-mn2) ); //s(t)
			if(S_==1&&mn+mn2==11)       fprintf(out,"\t{}   \n\n"); //Bei einem Simulationszyklus M, S=1 und keinen Streuungen s(t)
			if(S_> 1&&mn+mn2==11)       fprintf(out,"\t{}   \n\n"); //Bei Metazyklen S>1, und keinen Streuungen s(t)
		}
		
		//bei genau einem Simulations Ereignis M=1 
		if(M_==1)                     fprintf(out,"\t{}   \t{}   \t{}   \t{}   \n\n");
	
		mn=0;mn1=0;mn2=0;
		
		// 4/37 ///////////////////////////////////////////////////////////////////////////////////////////////////////////
		fprintf(out,"4/37\n");
		sum_zlr2=sum_pdiff=sum_padd=sum_pads=sum_t=sum_ts=0;
		for(iLauf=56;iLauf<=79;iLauf++)
		{
			pdiff=4.0/37-zlr2[iLauf]/M_;
			   sum_zlr2+=zlr2[iLauf];
			
			if(zlr2[iLauf]==0) { sum_pads+=0; sum_pdiff+=0;     sum_padd+=0;                            mn++;}
			if(zlr2[iLauf]> 0) 
			{                    sum_pdiff+=pdiff; sum_padd+=padd_am[iLauf]/(zlr2[iLauf]);
			                     sum_pads+=sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)));
			}

			if(S_==1) // Bei einem Simulationszyklus M, S=1
			{
				if(zlr2[iLauf]==1)  mn1++;
				if(zlr2[iLauf]> 1)  sum_ts+=sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2));
				if(t_am[iLauf]>=1){ sum_t+=t_am[iLauf]/(zlr2[iLauf]);    }
				if(t_am[iLauf]< 1){ sum_t+=0; if(zlr2[iLauf]==0)sum_t+=0;}
			}
			
			if(S_>1) // Bei Metazyklen S>1
			{
				if(zlr2[iLauf]*S_==1) mn1++;
				if(zlr2[iLauf]*S_> 1) sum_ts+=sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2));
				if(zlr2[iLauf]>0    ) sum_t+=t_am[iLauf]/(zlr2[iLauf]);
			}

			// Bei keinem Ereignis zi
			if(zlr2[iLauf]==0)          fprintf(out,"%i\t%0.6f\t%6.0f\t{}      \t{}      \t{}   \t{}   \t{}   \t{}   \n", 
				                                                               iLauf-55,  4.0/37, zlr2[iLauf]); 
			// Bei ein- oder mehrmaligem Ereignis zi
			if(zlr2[iLauf]> 0) 
			{
				if(S_==1)               fprintf(out,"%i\t%0.6f\t%6.0f\t%.6f",  iLauf-55,  4.0/37, zlr2[iLauf], zlr2[iLauf]/M_); // p(e), m, p(m/M)
				if(S_> 1)               fprintf(out,"%i\t%0.6f\t%6.1f\t%.6f",  iLauf-55,  4.0/37, zlr2[iLauf], zlr2[iLauf]/M_); //
										
				if(pdiff< 0)            fprintf(out,"\t%.6f",                  pdiff); // Wahrscheinlichkeits p(e)-p(m/M) Differenz
				if(pdiff>=0)            fprintf(out,"\t+%.6f",                 pdiff); //
		
				if(M_==1)               fprintf(out,"\t{}   \t{}   \t{}   \t{}   \n");

				if(M_>1&&S_==1) // Bei einem Simulationszyklus M, S=1 // Mittlere Additiv Wahrscheinlichkeiten p.add und Wartezeiten t //
				{
				if(zlr2[iLauf]!=1)      fprintf(out,"\t%.3f\t%.3f\t%.3f",      padd_am[iLauf]/(zlr2[iLauf]),sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)) ),
													                           t_am[iLauf]/(zlr2[iLauf]));
		
				if(zlr2[iLauf]==1)      fprintf(out,"\t%.3f\t{}   \t%.3f",     padd_am[iLauf]/(zlr2[iLauf]),
													                           t_am[iLauf]/(zlr2[iLauf]) );
				}

				if(M_>1&&S_> 1) // Bei Metazyklen S>1 // Mittlere Additiv Wahrscheinlichkeiten p.add und Wartezeiten t //
				{
				if(zlr2[iLauf]*S_> 1)   fprintf(out,"\t%.3f\t%.3f\t%.3f",      padd_am[iLauf]/(zlr2[iLauf]),
					                                                           sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)) ),
													                           t_am[iLauf]/(zlr2[iLauf]));
		
				if(zlr2[iLauf]*S_==1)   fprintf(out,"\t%.3f\t{}   \t%.3f",     padd_am[iLauf]/(zlr2[iLauf]),
													                           t_am[iLauf]/(zlr2[iLauf]) );
				}
			}

			if(M_>1&&S_==1) // Bei einem Simulationszyklus M, S=1 // Standardabweichungen s der Wartezeiten t //
			{
				if(zlr2[iLauf]==1){     fprintf(out,"\t{}   \n");mn2++; }
				if(zlr2[iLauf]> 1)      fprintf(out,"\t%.3f\n",                sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2)) );
			}

			if(M_>1&&S_>1&&zlr2[iLauf]> 0) // Bei Metazyklen S>1 // Standardabweichungen s der Wartezeiten t //
			{
				if(zlr2[iLauf]*S_==1){  fprintf(out,"\t{}   \n");mn2++; }
				if(zlr2[iLauf]*S_> 1)   fprintf(out,"\t%.3f\n",                sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2)) );
			}
		}
		// Mittelwerte der gemittelten Kennwerte 
		fprintf(out,"\t--------\t------\t--------\t---------\t-----\t-----\t------\t------\n");
		if(S_==1)                       fprintf(out,"AM\t%0.6f\t%6.0f\t%0.6f", 4.0/37, sum_zlr2/24,sum_zlr2/(24-mn)/M_);// p(e), m, p(m/M)
		if(S_> 1)                       fprintf(out,"AM\t%0.6f\t%6.1f\t%0.6f", 4.0/37, sum_zlr2/24,sum_zlr2/(24-mn)/M_);//
		if(sum_pdiff/24>  0.0000001  )  fprintf(out,"\t+%0.6f",                sum_pdiff/(24-mn) );// Wahrscheinlichkeits p(e)-p(m/M) Differenz
		if(sum_pdiff/24< -0.0000001  )  fprintf(out,"\t%0.6f",                 sum_pdiff/(24-mn) );//    
		if(sum_pdiff/24>=-0.0000001&&
		   sum_pdiff/24<= 0.0000001  )  fprintf(out,"\t\xb1%0.6f",             fabs(sum_pdiff/(24-mn)) );// 
		
		//Bei einem Simulationszyklus M>1
		if(M_> 1) 
		{
			                            fprintf(out,"\t%0.3f",                 sum_padd/(24-mn));    //AM(p.add)
			if(mn+mn1<24 )              fprintf(out,"\t%0.3f",                 sum_pads/(24-mn-mn1));//s(p.add)
			if(mn+mn1==24)              fprintf(out,"\t{}   ");//Bei keinen Streuungen s(p.add)

			                            fprintf(out,"\t%0.3f",                 sum_t/(24-mn) );      //AM(t)
			if(mn+mn2<24 )              fprintf(out,"\t%0.3f\n\n",             sum_ts/(24-mn-mn2) ); //s(t)
			if(S_==1&&mn+mn2==24)       fprintf(out,"\t{}   \n\n"); //Bei einem Simulationszyklus M, S=1 und keinen Streuungen s(t)
			if(S_> 1&&mn+mn2==24)       fprintf(out,"\t{}   \n\n"); //Bei Metazyklen S>1, und keinen Streuungen s(t)
		}
		
		//bei genau einem Simulations Ereignis M=1 
		if(M_==1)                     fprintf(out,"\t{}   \t{}   \t{}   \t{}   \n\n");
	
		mn=0;mn1=0;mn2=0;		

		// 3/37 ///////////////////////////////////////////////////////////////////////////////////////////////////////////
		fprintf(out,"3/37\n");
		sum_zlr2=sum_pdiff=sum_padd=sum_pads=sum_t=sum_ts=0;
		for(iLauf=80;iLauf<=91;iLauf++)
		{
				pdiff=3.0/37-zlr2[iLauf]/M_;
			   sum_zlr2+=zlr2[iLauf];
			
			if(zlr2[iLauf]==0) { sum_pads+=0; sum_pdiff+=0;     sum_padd+=0;                            mn++;}
			if(zlr2[iLauf]> 0) 
			{                    sum_pdiff+=pdiff; sum_padd+=padd_am[iLauf]/(zlr2[iLauf]);
			                     sum_pads+=sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)));
			}

			if(S_==1) // Bei einem Simulationszyklus M, S=1
			{
				if(zlr2[iLauf]==1)  mn1++;
				if(zlr2[iLauf]> 1)  sum_ts+=sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2));
				if(t_am[iLauf]>=1){ sum_t+=t_am[iLauf]/(zlr2[iLauf]);    }
				if(t_am[iLauf]< 1){ sum_t+=0; if(zlr2[iLauf]==0)sum_t+=0;}
			}
			
			if(S_>1) // Bei Metazyklen S>1
			{
				if(zlr2[iLauf]*S_==1) mn1++;
				if(zlr2[iLauf]*S_> 1) sum_ts+=sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2));
				if(zlr2[iLauf]>0    ) sum_t+=t_am[iLauf]/(zlr2[iLauf]);
			}

			// Bei keinem Ereignis zi
			if(zlr2[iLauf]==0)          fprintf(out,"%i\t%0.6f\t%6.0f\t{}      \t{}      \t{}   \t{}   \t{}   \t{}   \n", 
				                                                               iLauf-79,  3.0/37, zlr2[iLauf]); 
			// Bei ein- oder mehrmaligem Ereignis zi
			if(zlr2[iLauf]> 0) 
			{
				if(S_==1)               fprintf(out,"%i\t%0.6f\t%6.0f\t%.6f",  iLauf-79,  3.0/37, zlr2[iLauf], zlr2[iLauf]/M_); // p(e), m, p(m/M)
				if(S_> 1)               fprintf(out,"%i\t%0.6f\t%6.1f\t%.6f",  iLauf-79,  3.0/37, zlr2[iLauf], zlr2[iLauf]/M_); //
										
				if(pdiff< 0)            fprintf(out,"\t%.6f",                  pdiff); // Wahrscheinlichkeits p(e)-p(m/M) Differenz
				if(pdiff>=0)            fprintf(out,"\t+%.6f",                 pdiff); //
		
				if(M_==1)               fprintf(out,"\t{}   \t{}   \t{}   \t{}   \n");

				if(M_>1&&S_==1) // Bei einem Simulationszyklus M, S=1 // Mittlere Additiv Wahrscheinlichkeiten p.add und Wartezeiten t //
				{
				if(zlr2[iLauf]!=1)      fprintf(out,"\t%.3f\t%.3f\t%.3f",      padd_am[iLauf]/(zlr2[iLauf]),sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)) ),
													                           t_am[iLauf]/(zlr2[iLauf]));
		
				if(zlr2[iLauf]==1)      fprintf(out,"\t%.3f\t{}   \t%.3f",     padd_am[iLauf]/(zlr2[iLauf]),
													                           t_am[iLauf]/(zlr2[iLauf]) );
				}

				if(M_>1&&S_> 1) // Bei Metazyklen S>1 // Mittlere Additiv Wahrscheinlichkeiten p.add und Wartezeiten t //
				{
				if(zlr2[iLauf]*S_> 1)   fprintf(out,"\t%.3f\t%.3f\t%.3f",      padd_am[iLauf]/(zlr2[iLauf]),
					                                                           sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)) ),
													                           t_am[iLauf]/(zlr2[iLauf]));
		
				if(zlr2[iLauf]*S_==1)   fprintf(out,"\t%.3f\t{}   \t%.3f",     padd_am[iLauf]/(zlr2[iLauf]),
													                           t_am[iLauf]/(zlr2[iLauf]) );
				}
			}

			if(M_>1&&S_==1) // Bei einem Simulationszyklus M, S=1 // Standardabweichungen s der Wartezeiten t //
			{
				if(zlr2[iLauf]==1){     fprintf(out,"\t{}   \n");mn2++; }
				if(zlr2[iLauf]> 1)      fprintf(out,"\t%.3f\n",                sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2)) );
			}

			if(M_>1&&S_>1&&zlr2[iLauf]> 0) // Bei Metazyklen S>1 // Standardabweichungen s der Wartezeiten t //
			{
				if(zlr2[iLauf]*S_==1){  fprintf(out,"\t{}   \n");mn2++; }
				if(zlr2[iLauf]*S_> 1)   fprintf(out,"\t%.3f\n",                sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2)) );
			}
		}
		// Mittelwerte der gemittelten Kennwerte 
		fprintf(out,"\t--------\t------\t--------\t---------\t-----\t-----\t------\t------\n");
		if(S_==1)                       fprintf(out,"AM\t%0.6f\t%6.0f\t%0.6f", 3.0/37, sum_zlr2/12,sum_zlr2/(12-mn)/M_);// p(e), m, p(m/M)
		if(S_> 1)                       fprintf(out,"AM\t%0.6f\t%6.1f\t%0.6f", 3.0/37, sum_zlr2/12,sum_zlr2/(12-mn)/M_);//
		if(sum_pdiff/12>  0.0000001  )  fprintf(out,"\t+%0.6f",                sum_pdiff/(12-mn) );// Wahrscheinlichkeits p(e)-p(m/M) Differenz
		if(sum_pdiff/12< -0.0000001  )  fprintf(out,"\t%0.6f",                 sum_pdiff/(12-mn) );//    
		if(sum_pdiff/12>=-0.0000001&&
		   sum_pdiff/12<= 0.0000001  )  fprintf(out,"\t\xb1%0.6f",             fabs(sum_pdiff/(12-mn)) );// 
		
		//Bei einem Simulationszyklus M>1
		if(M_> 1) 
		{
			                            fprintf(out,"\t%0.3f",                 sum_padd/(12-mn));    //AM(p.add)
			if(mn+mn1<12)               fprintf(out,"\t%0.3f",                 sum_pads/(12-mn-mn1));//s(p.add)
			if(mn+mn1==12)              fprintf(out,"\t{}   ");//Bei keinen Streuungen s(p.add)

			                            fprintf(out,"\t%0.3f",                 sum_t/(12-mn) );      //AM(t)
			if(mn+mn2<12)               fprintf(out,"\t%0.3f\n\n",             sum_ts/(12-mn-mn2) ); //s(t)
			if(S_==1&&mn+mn2==12)       fprintf(out,"\t{}   \n\n"); //Bei einem Simulationszyklus M, S=1 und keinen Streuungen s(t)
			if(S_> 1&&mn+mn2==12)       fprintf(out,"\t{}   \n\n"); //Bei Metazyklen S>1, und keinen Streuungen s(t)
		}
		
		//bei genau einem Simulations Ereignis M=1 
		if(M_==1)                     fprintf(out,"\t{}   \t{}   \t{}   \t{}   \n\n");
	
		mn=0;mn1=0;mn2=0;
		

		// 2/37 ///////////////////////////////////////////////////////////////////////////////////////////////////////////
		fprintf(out,"2/37\n");
		sum_zlr2=sum_pdiff=sum_padd=sum_pads=sum_t=sum_ts=0;
		for(iLauf=92;iLauf<=148;iLauf++)
		{
					pdiff=2.0/37-zlr2[iLauf]/M_;
			   sum_zlr2+=zlr2[iLauf];
			
			if(zlr2[iLauf]==0) { sum_pads+=0; sum_pdiff+=0;     sum_padd+=0;                            mn++;}
			if(zlr2[iLauf]> 0) 
			{                    sum_pdiff+=pdiff; sum_padd+=padd_am[iLauf]/(zlr2[iLauf]);
			                     sum_pads+=sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)));
			}

			if(S_==1) // Bei einem Simulationszyklus M, S=1
			{
				if(zlr2[iLauf]==1)  mn1++;
				if(zlr2[iLauf]> 1)  sum_ts+=sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2));
				if(t_am[iLauf]>=1){ sum_t+=t_am[iLauf]/(zlr2[iLauf]);    }
				if(t_am[iLauf]< 1){ sum_t+=0; if(zlr2[iLauf]==0)sum_t+=0;}
			}
			
			if(S_>1) // Bei Metazyklen S>1
			{
				if(zlr2[iLauf]*S_==1) mn1++;
				if(zlr2[iLauf]*S_> 1) sum_ts+=sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2));
				if(zlr2[iLauf]>0    ) sum_t+=t_am[iLauf]/(zlr2[iLauf]);
			}

			// Bei keinem Ereignis zi
			if(zlr2[iLauf]==0)          fprintf(out,"%i\t%0.6f\t%6.0f\t{}      \t{}      \t{}   \t{}   \t{}   \t{}   \n", 
				                                                               iLauf-91,  2.0/37, zlr2[iLauf]); 
			// Bei ein- oder mehrmaligem Ereignis zi
			if(zlr2[iLauf]> 0) 
			{
				if(S_==1)               fprintf(out,"%i\t%0.6f\t%6.0f\t%.6f",  iLauf-91,  2.0/37, zlr2[iLauf], zlr2[iLauf]/M_); // p(e), m, p(m/M)
				if(S_> 1)               fprintf(out,"%i\t%0.6f\t%6.1f\t%.6f",  iLauf-91,  2.0/37, zlr2[iLauf], zlr2[iLauf]/M_); //
										
				if(pdiff< 0)            fprintf(out,"\t%.6f",                  pdiff); // Wahrscheinlichkeits p(e)-p(m/M) Differenz
				if(pdiff>=0)            fprintf(out,"\t+%.6f",                 pdiff); //
		
				if(M_==1)               fprintf(out,"\t{}   \t{}   \t{}   \t{}   \n");

				if(M_>1&&S_==1) // Bei einem Simulationszyklus M, S=1 // Mittlere Additiv Wahrscheinlichkeiten p.add und Wartezeiten t //
				{
				if(zlr2[iLauf]!=1)      fprintf(out,"\t%.3f\t%.3f\t%.3f",      padd_am[iLauf]/(zlr2[iLauf]),sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)) ),
													                           t_am[iLauf]/(zlr2[iLauf]));
		
				if(zlr2[iLauf]==1)      fprintf(out,"\t%.3f\t{}   \t%.3f",     padd_am[iLauf]/(zlr2[iLauf]),
													                           t_am[iLauf]/(zlr2[iLauf]) );
				}

				if(M_>1&&S_> 1) // Bei Metazyklen S>1 // Mittlere Additiv Wahrscheinlichkeiten p.add und Wartezeiten t //
				{
				if(zlr2[iLauf]*S_> 1)   fprintf(out,"\t%.3f\t%.3f\t%.3f",      padd_am[iLauf]/(zlr2[iLauf]),
					                                                           sqrt(fabs( (padd2[iLauf]/(zlr2[iLauf])) - pow(padd_am[iLauf]/(zlr2[iLauf]),2)) ),
													                           t_am[iLauf]/(zlr2[iLauf]));
		
				if(zlr2[iLauf]*S_==1)   fprintf(out,"\t%.3f\t{}   \t%.3f",     padd_am[iLauf]/(zlr2[iLauf]),
													                           t_am[iLauf]/(zlr2[iLauf]) );
				}
			}

			if(M_>1&&S_==1) // Bei einem Simulationszyklus M, S=1 // Standardabweichungen s der Wartezeiten t //
			{
				if(zlr2[iLauf]==1){     fprintf(out,"\t{}   \n");mn2++; }
				if(zlr2[iLauf]> 1)      fprintf(out,"\t%.3f\n",                sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2)) );
			}

			if(M_>1&&S_>1&&zlr2[iLauf]> 0) // Bei Metazyklen S>1 // Standardabweichungen s der Wartezeiten t //
			{
				if(zlr2[iLauf]*S_==1){  fprintf(out,"\t{}   \n");mn2++; }
				if(zlr2[iLauf]*S_> 1)   fprintf(out,"\t%.3f\n",                sqrt((t_2[iLauf]/(zlr2[iLauf]))- pow(t_am[iLauf]/(zlr2[iLauf]),2)) );
			}
		}
		// Mittelwerte der gemittelten Kennwerte 
		fprintf(out,"\t--------\t------\t--------\t---------\t-----\t-----\t------\t------\n");
		if(S_==1)                       fprintf(out,"AM\t%0.6f\t%6.0f\t%0.6f", 2.0/37, sum_zlr2/57,sum_zlr2/(57-mn)/M_);// p(e), m, p(m/M)
		if(S_> 1)                       fprintf(out,"AM\t%0.6f\t%6.1f\t%0.6f", 2.0/37, sum_zlr2/57,sum_zlr2/(57-mn)/M_);//
		if(sum_pdiff/57>  0.0000001  )  fprintf(out,"\t+%0.6f",                sum_pdiff/(57-mn) );// Wahrscheinlichkeits p(e)-p(m/M) Differenz
		if(sum_pdiff/57< -0.0000001  )  fprintf(out,"\t%0.6f",                 sum_pdiff/(57-mn) );//    
		if(sum_pdiff/57>=-0.0000001&&
		   sum_pdiff/57<= 0.0000001  )  fprintf(out,"\t\xb1%0.6f",             fabs(sum_pdiff/(57-mn)) );// 
		
		//Bei einem Simulationszyklus M>1
		if(M_> 1) 
		{
			                            fprintf(out,"\t%0.3f",                 sum_padd/(57-mn));    //AM(p.add)
			if(mn+mn1<57)               fprintf(out,"\t%0.3f",                 sum_pads/(57-mn-mn1));//s(p.add)
			if(mn+mn1==57)              fprintf(out,"\t{}   ");//Bei keinen Streuungen s(p.add)

			                            fprintf(out,"\t%0.3f",                 sum_t/(57-mn) );      //AM(t)
			if(mn+mn2<57)               fprintf(out,"\t%0.3f\n\n",             sum_ts/(57-mn-mn2) ); //s(t)
			if(S_==1&&mn+mn2==57)       fprintf(out,"\t{}   \n\n"); //Bei einem Simulationszyklus M, S=1 und keinen Streuungen s(t)
			if(S_> 1&&mn+mn2==57)       fprintf(out,"\t{}   \n\n"); //Bei Metazyklen S>1, und keinen Streuungen s(t)
		}
		
		//bei genau einem Simulations Ereignis M=1 
		if(M_==1)                     fprintf(out,"\t{}   \t{}   \t{}   \t{}   \n\n");
	
		
		fprintf(out,"------------------------------------------------------------------------------------------------\n");
		
		if(S_==1)
		{
			fprintf(out,"Nach M=%.0f Simulationszyklen und randomisierter Sukzessivsetzung einer Einheit e=1 zeigte\n",M_ );
			
			vektor[1]=sum_[1][2]/S_;
			vektor[2]=sum_[1][1]/S_;
			vektor[3]=sum_[1][3]/S_;
			vektor[4]=sum_[1][4]/S_;
			vektor[5]=sum_[1][5]/S_;
			vektor[6]=sum_[1][6]/S_;
			vektor[7]=sum_[1][7]/S_;

			gmax=fn_sort(vektor, 7, 2);

			szmax=18;
			if(vektor[2]==gmax)szmax=12;
			if(vektor[3]==gmax)szmax=6;
			if(vektor[4]==gmax)szmax=4;
			if(vektor[5]==gmax)szmax=3;
			if(vektor[6]==gmax)szmax=2;
			if(vektor[7]==gmax)szmax=1;

			szmax0=szmax;

			fprintf(out,"Szenario k=%.0f bei M=%.0f die maximale Kumulation von e(%.0f|rnd)[M]=%.0f\n",szmax,M_,szmax,gmax);
			
			if(sw>=8)
			{
			
			vektor[1]=sum_[2][2]/S_;
			vektor[2]=sum_[2][1]/S_;
			vektor[3]=sum_[2][3]/S_;
			vektor[4]=sum_[2][4]/S_;
			vektor[5]=sum_[2][5]/S_;
			vektor[6]=sum_[2][6]/S_;
			vektor[7]=sum_[2][7]/S_;

			gmax=fn_sort(vektor, 7, 2);
			szmax=18;
			if(vektor[2]==gmax)szmax=12;
			if(vektor[3]==gmax)szmax=6;
			if(vektor[4]==gmax)szmax=4;
			if(vektor[5]==gmax)szmax=3;
			if(vektor[6]==gmax)szmax=2;
			if(vektor[7]==gmax)szmax=1;

			szmax1=szmax;
			
				fprintf(out,"Unter p.add>=%.3f bedingter Sukzessivsetzung einer Einheit e=1 zeigte Szenario k=%.0f  \n",padd_sel,szmax);
				fprintf(out,"bei M=%.0f die maximale Kumulation von e(%.0f|%.3f)[M]=%.0f.\n",M_,szmax,padd_sel,gmax);
				fprintf(out,"Die maximale Kummulationsdifferenz zwischen randomisierter und bedingter Setzung von e=1\n");
				
				vektor[1]=sum_[2][2]/S_-sum_[1][2]/S_;
				vektor[2]=sum_[2][1]/S_-sum_[1][1]/S_;
				vektor[3]=sum_[2][3]/S_-sum_[1][3]/S_;
				vektor[4]=sum_[2][4]/S_-sum_[1][4]/S_;
				vektor[5]=sum_[2][5]/S_-sum_[1][5]/S_;
				vektor[6]=sum_[2][6]/S_-sum_[1][6]/S_;
				vektor[7]=sum_[2][7]/S_-sum_[1][7]/S_;

				gmax=fn_sort(vektor, 7, 2);
				szmax=18;
				if(vektor[2]==gmax)szmax=12;
				if(vektor[3]==gmax)szmax=6;
				if(vektor[4]==gmax)szmax=4;
				if(vektor[5]==gmax)szmax=3;
				if(vektor[6]==gmax)szmax=2;
				if(vektor[7]==gmax)szmax=1;
							
				fprintf(out,"bei M=%.0f zeigte Szenario k=%.0f, diff(e)[M]=%.0f.\n", M_,szmax,gmax);
			}
		}

		if(S_>1)
		{
			fprintf(out,"Nach S=%.0f Metazyklen zu M=%.0f Simulationszyklen (SM=%.0f) und randomisierter\n",S_, M_, M_*S_);
			
			vektor[1]=sum_[1][2]/S_;
			vektor[2]=sum_[1][1]/S_;
			vektor[3]=sum_[1][3]/S_;
			vektor[4]=sum_[1][4]/S_;
			vektor[5]=sum_[1][5]/S_;
			vektor[6]=sum_[1][6]/S_;
			vektor[7]=sum_[1][7]/S_;

			gmax=fn_sort(vektor, 7, 2);

			szmax=18;
			if(vektor[2]==gmax)szmax=12;
			if(vektor[3]==gmax)szmax=6;
			if(vektor[4]==gmax)szmax=4;
			if(vektor[5]==gmax)szmax=3;
			if(vektor[6]==gmax)szmax=2;
			if(vektor[7]==gmax)szmax=1;

			szmax0=szmax;
						
			fprintf(out,"Sukzessivsetzung einer Einheit e=1 zeigte Szenario k=%.0f bei M=%.0f die maximale mittlere \n",szmax, M_);
			fprintf(out,"Kumulation von e(%.0f|rnd)[M]=%.1f.\n",szmax,gmax);
			
			if(sw>=8)
			{
				fprintf(out,"Unter p.add>=%.3f bedingter Sukzessivsetzung einer Einheit e=1 zeigte ",padd_sel);
				
				vektor[1]=sum_[2][2]/S_;
				vektor[2]=sum_[2][1]/S_;
				vektor[3]=sum_[2][3]/S_;
				vektor[4]=sum_[2][4]/S_;
				vektor[5]=sum_[2][5]/S_;
				vektor[6]=sum_[2][6]/S_;
				vektor[7]=sum_[2][7]/S_;

				gmax=fn_sort(vektor, 7, 2);
				szmax=18;
				if(vektor[2]==gmax)szmax=12;
				if(vektor[3]==gmax)szmax=6;
				if(vektor[4]==gmax)szmax=4;
				if(vektor[5]==gmax)szmax=3;
				if(vektor[6]==gmax)szmax=2;
				if(vektor[7]==gmax)szmax=1;

				szmax1=szmax;
				
				fprintf(out,"Szenario k=%.0f bei\nM=%.0f die maximale mittlere Kumulation von e(%.0f|%.3f)[M]=%.1f.\n",szmax,M_,szmax,padd_sel,gmax);
				fprintf(out,"Die maximale mittlere Kummulationsdifferenz zwischen randomisierter und bedingter Setzung von\ne=1 ");
				
				vektor[1]=sum_[2][2]/S_-sum_[1][2]/S_;
				vektor[2]=sum_[2][1]/S_-sum_[1][1]/S_;
				vektor[3]=sum_[2][3]/S_-sum_[1][3]/S_;
				vektor[4]=sum_[2][4]/S_-sum_[1][4]/S_;
				vektor[5]=sum_[2][5]/S_-sum_[1][5]/S_;
				vektor[6]=sum_[2][6]/S_-sum_[1][6]/S_;
				vektor[7]=sum_[2][7]/S_-sum_[1][7]/S_;

				gmax=fn_sort(vektor, 7, 2);
				szmax=18;
				if(vektor[2]==gmax)szmax=12;
				if(vektor[3]==gmax)szmax=6;
				if(vektor[4]==gmax)szmax=4;
				if(vektor[5]==gmax)szmax=3;
				if(vektor[6]==gmax)szmax=2;
				if(vektor[7]==gmax)szmax=1;
							
				fprintf(out,"bei M=%.0f zeigte Szenario k=%.0f, diff(e)[M]=%.1f.\n", M_,szmax,gmax);
			}
		}
		
		fprintf(out,"------------------------------------------------------------------------------------------------\n");
		if(sw>=8)fprintf(out,"\te(k|rnd)\t\t\te(k|p.add>=%.3f)\t\tdiff(e)\n", padd_sel);
		if(sw< 8)fprintf(out,"\te(k|rnd)\t\t\te(k|p.add)\t\t\tdiff(e)\n");	
		fprintf(out,"\t------------------------\t------------------------\t------------------------\n");
		fprintf(out,"k/37\tmin\tmax\tM\t\tmin\tmax\tM\t\tmin\tmax\tM\n");
		fprintf(out,"------------------------------------------------------------------------------------------------\n");
		
		if(S_==1)
		{
			fprintf(out,"18");if(szmax0==18)fprintf(out,"'");if(sw>=8)if(szmax1==18)fprintf(out,"\"");fprintf(out,"\t");
			if(sw>=8)fprintf(out,"%6.0f\t%6.0f\t%6.0f\t\t%6.0f\t%6.0f\t%6.0f\t\t%6.0f\t%6.0f\t%6.0f\n", min[2],max[2],sum_[1][2]/S_, min[9],max[9],sum_[2][2]/S_, min[9]-min[2], max[9]-max[2], sum_[2][2]/S_-sum_[1][2]/S_);
			if(sw< 8)fprintf(out,"%6.0f\t%6.0f\t%6.0f\t\t{}   \t%{}   \t{}   \t\t{}   \t%{}   \t%{}   \n", min[2],max[2],sum_[1][2]/S_);
			
			fprintf(out,"12");if(szmax0==12)fprintf(out,"'");if(sw>=8)if(szmax1==12)fprintf(out,"\"");fprintf(out,"\t");
			if(sw>=8)fprintf(out,"%6.0f\t%6.0f\t%6.0f\t\t%6.0f\t%6.0f\t%6.0f\t\t%6.0f\t%6.0f\t%6.0f\n", min[1],max[1],sum_[1][1]/S_, min[8],max[8],sum_[2][1]/S_, min[8]-min[1], max[8]-max[1],sum_[2][1]/S_-sum_[1][1]/S_);
			if(sw< 8)fprintf(out,"%6.0f\t%6.0f\t%6.0f\t\t{}   \t%{}   \t{}   \t\t{}   \t%{}   \t%{}   \n", min[1],max[1],sum_[1][1]/S_);
			fprintf(out,"6");if(szmax0==6)fprintf(out,"'");if(sw>=8)if(szmax1==6)fprintf(out,"\"");fprintf(out,"\t");
			if(sw>=8)fprintf(out,"%6.0f\t%6.0f\t%6.0f\t\t%6.0f\t%6.0f\t%6.0f\t\t%6.0f\t%6.0f\t%6.0f\n", min[3],max[3],sum_[1][3]/S_, min[10],max[10],sum_[2][3]/S_, min[10]-min[3], max[10]-max[3],sum_[2][3]/S_-sum_[1][3]/S_);
			if(sw< 8)fprintf(out,"%6.0f\t%6.0f\t%6.0f\t\t{}   \t%{}   \t{}   \t\t{}   \t%{}   \t%{}   \n", min[3],max[3],sum_[1][3]/S_);
			fprintf(out,"4");if(szmax0==4)fprintf(out,"'");if(sw>=8)if(sw>=8)if(szmax1==4)fprintf(out,"\"");fprintf(out,"\t");
			if(sw>=8)fprintf(out,"%6.0f\t%6.0f\t%6.0f\t\t%6.0f\t%6.0f\t%6.0f\t\t%6.0f\t%6.0f\t%6.0f\n", min[4],max[4],sum_[1][4]/S_, min[11],max[11],sum_[2][4]/S_, min[11]-min[4], max[11]-max[4],sum_[2][4]/S_-sum_[1][4]/S_);
			if(sw< 8)fprintf(out,"%6.0f\t%6.0f\t%6.0f\t\t{}   \t%{}   \t{}   \t\t{}   \t%{}   \t%{}   \n", min[4],max[4],sum_[1][4]/S_);
			fprintf(out,"3");if(szmax0==3)fprintf(out,"'");if(sw>=8)if(szmax1==3)fprintf(out,"\"");fprintf(out,"\t");
			if(sw>=8)fprintf(out,"%6.0f\t%6.0f\t%6.0f\t\t%6.0f\t%6.0f\t%6.0f\t\t%6.0f\t%6.0f\t%6.0f\n", min[5],max[5],sum_[1][5]/S_, min[12],max[12],sum_[2][5]/S_, min[12]-min[5], max[12]-max[5],sum_[2][5]/S_-sum_[1][5]/S_);
			if(sw< 8)fprintf(out,"%6.0f\t%6.0f\t%6.0f\t\t{}   \t%{}   \t{}   \t\t{}   \t%{}   \t%{}   \n", min[5],max[5],sum_[1][5]/S_);
			fprintf(out,"2");if(szmax0==2)fprintf(out,"'");if(sw>=8)if(szmax1==2)fprintf(out,"\"");fprintf(out,"\t");
			if(sw>=8)fprintf(out,"%6.0f\t%6.0f\t%6.0f\t\t%6.0f\t%6.0f\t%6.0f\t\t%6.0f\t%6.0f\t%6.0f\n", min[6],max[6],sum_[1][6]/S_, min[13],max[13],sum_[2][6]/S_, min[13]-min[6], max[13]-max[6],sum_[2][6]/S_-sum_[1][6]/S_);
			if(sw< 8)fprintf(out,"%6.0f\t%6.0f\t%6.0f\t\t{}   \t%{}   \t{}   \t\t{}   \t%{}   \t%{}   \n", min[6],max[6],sum_[1][6]/S_);
			fprintf(out,"1");if(szmax0==1)fprintf(out,"'");if(sw>=8)if(szmax1==1)fprintf(out,"\"");fprintf(out,"\t");
			if(sw>=8)fprintf(out,"%6.0f\t%6.0f\t%6.0f\t\t%6.0f\t%6.0f\t%6.0f\t\t%6.0f\t%6.0f\t%6.0f\n", min[7],max[7],sum_[1][7]/S_, min[14],max[14],sum_[2][7]/S_, min[14]-min[7], max[14]-max[7],sum_[2][7]/S_-sum_[1][7]/S_);
			if(sw< 8)fprintf(out,"%6.0f\t%6.0f\t%6.0f\t\t{}   \t%{}   \t{}   \t\t{}   \t%{}   \t%{}   \n", min[7],max[7],sum_[1][7]/S_);
		}
		
		if(S_>1)
		{
			fprintf(out,"18");if(szmax0==18)fprintf(out,"'");if(sw>=8)if(szmax1==18)fprintf(out,"\"");fprintf(out,"\t");
			if(sw>=8)fprintf(out,"%6.0f\t%6.0f\t%6.1f\t\t%6.0f\t%6.0f\t%6.1f\t\t%6.0f\t%6.0f\t%6.1f\n", min[2],max[2],sum_[1][2]/S_, min[9],max[9],sum_[2][2]/S_, min[9]-min[2], max[9]-max[2], sum_[2][2]/S_-sum_[1][2]/S_);
			if(sw< 8)fprintf(out,"%6.0f\t%6.0f\t%6.1f\t\t{}   \t%{}   \t{}   \t\t{}   \t%{}   \t%{}   \n", min[2],max[2],sum_[1][2]/S_);
			fprintf(out,"12");if(szmax0==12)fprintf(out,"'");if(sw>=8)if(szmax1==12)fprintf(out,"\"");fprintf(out,"\t");
			if(sw>=8)fprintf(out,"%6.0f\t%6.0f\t%6.1f\t\t%6.0f\t%6.0f\t%6.1f\t\t%6.0f\t%6.0f\t%6.1f\n", min[1],max[1],sum_[1][1]/S_, min[8],max[8],sum_[2][1]/S_, min[8]-min[1], max[8]-max[1],sum_[2][1]/S_-sum_[1][1]/S_);
			if(sw< 8)fprintf(out,"%6.0f\t%6.0f\t%6.1f\t\t{}   \t%{}   \t{}   \t\t{}   \t%{}   \t%{}   \n", min[1],max[1],sum_[1][1]/S_);
			fprintf(out,"6");if(szmax0==6)fprintf(out,"'");if(sw>=8)if(szmax1==6)fprintf(out,"\"");fprintf(out,"\t");
			if(sw>=8)fprintf(out,"%6.0f\t%6.0f\t%6.1f\t\t%6.0f\t%6.0f\t%6.1f\t\t%6.0f\t%6.0f\t%6.1f\n", min[3],max[3],sum_[1][3]/S_, min[10],max[10],sum_[2][3]/S_, min[10]-min[3], max[10]-max[3],sum_[2][3]/S_-sum_[1][3]/S_);
			if(sw< 8)fprintf(out,"%6.0f\t%6.0f\t%6.1f\t\t{}   \t%{}   \t{}   \t\t{}   \t%{}   \t%{}   \n", min[3],max[3],sum_[1][3]/S_);
			fprintf(out,"4");if(szmax0==4)fprintf(out,"'");if(sw>=8)if(szmax1==4)fprintf(out,"\"");fprintf(out,"\t");
			if(sw>=8)fprintf(out,"%6.0f\t%6.0f\t%6.1f\t\t%6.0f\t%6.0f\t%6.1f\t\t%6.0f\t%6.0f\t%6.1f\n", min[4],max[4],sum_[1][4]/S_, min[11],max[11],sum_[2][4]/S_, min[11]-min[4], max[11]-max[4],sum_[2][4]/S_-sum_[1][4]/S_);
			if(sw< 8)fprintf(out,"%6.0f\t%6.0f\t%6.1f\t\t{}   \t%{}   \t{}   \t\t{}   \t%{}   \t%{}   \n", min[4],max[4],sum_[1][4]/S_);
			fprintf(out,"3");if(szmax0==3)fprintf(out,"'");if(sw>=8)if(szmax1==3)fprintf(out,"\"");fprintf(out,"\t");
			if(sw>=8)fprintf(out,"%6.0f\t%6.0f\t%6.1f\t\t%6.0f\t%6.0f\t%6.1f\t\t%6.0f\t%6.0f\t%6.1f\n", min[5],max[5],sum_[1][5]/S_, min[12],max[12],sum_[2][5]/S_, min[12]-min[5], max[12]-max[5],sum_[2][5]/S_-sum_[1][5]/S_);
			if(sw< 8)fprintf(out,"%6.0f\t%6.0f\t%6.1f\t\t{}   \t%{}   \t{}   \t\t{}   \t%{}   \t%{}   \n", min[5],max[5],sum_[1][5]/S_);
			fprintf(out,"2");if(szmax0==2)fprintf(out,"'");if(sw>=8)if(szmax1==2)fprintf(out,"\"");fprintf(out,"\t");
			if(sw>=8)fprintf(out,"%6.0f\t%6.0f\t%6.1f\t\t%6.0f\t%6.0f\t%6.1f\t\t%6.0f\t%6.0f\t%6.1f\n", min[6],max[6],sum_[1][6]/S_, min[13],max[13],sum_[2][6]/S_, min[13]-min[6], max[13]-max[6],sum_[2][6]/S_-sum_[1][6]/S_);
			if(sw< 8)fprintf(out,"%6.0f\t%6.0f\t%6.1f\t\t{}   \t%{}   \t{}   \t\t{}   \t%{}   \t%{}   \n", min[6],max[6],sum_[1][6]/S_);
			fprintf(out,"1");if(szmax0==1)fprintf(out,"'");if(sw>=8)if(szmax1==1)fprintf(out,"\"");fprintf(out,"\t");
			if(sw>=8)fprintf(out,"%6.0f\t%6.0f\t%6.1f\t\t%6.0f\t%6.0f\t%6.1f\t\t%6.0f\t%6.0f\t%6.1f\n", min[7],max[7],sum_[1][7]/S_, min[14],max[14],sum_[2][7]/S_, min[14]-min[7], max[14]-max[7],sum_[2][7]/S_-sum_[1][7]/S_);
			if(sw< 8)fprintf(out,"%6.0f\t%6.0f\t%6.1f\t\t{}   \t%{}   \t{}   \t\t{}   \t%{}   \t%{}   \n", min[7],max[7],sum_[1][7]/S_);
		}
		
		fprintf(out,"------------------------------------------------------------------------------------------------\n");
		if(sw>=15&&sw<=21||sw==24||sw==25)fprintf(out,"*)p.add=AM(p.add)[z]\n\n");
		
		fprintf(out,"SCHRAUSSER-MAT");
	}

	printf("\r                                                  \r");
	fclose(out);

	if(sw==1)         fn_erg=sum_[1][2]/S_;
	if(sw==2)         fn_erg=sum_[1][1]/S_;
	if(sw==3)         fn_erg=sum_[1][3]/S_;
	if(sw==4)         fn_erg=sum_[1][4]/S_;
	if(sw==5)         fn_erg=sum_[1][5]/S_;
	if(sw==6)         fn_erg=sum_[1][6]/S_;
	if(sw==7)         fn_erg=sum_[1][7]/S_;
	if(sw==8 ||sw==15)fn_erg=sum_[2][2]/S_;
	if(sw==9 ||sw==16)fn_erg=sum_[2][1]/S_;
	if(sw==10||sw==17)fn_erg=sum_[2][3]/S_;
	if(sw==11||sw==18)fn_erg=sum_[2][4]/S_;
	if(sw==12||sw==19)fn_erg=sum_[2][5]/S_;
	if(sw==13||sw==20)fn_erg=sum_[2][6]/S_;
	if(sw==14||sw==21)fn_erg=sum_[2][7]/S_;
	if(sw>=22)        fn_erg=M_;

	return 0;
};

