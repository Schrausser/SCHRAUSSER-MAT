//----------------------------------------------------------------------------------------------------| calc_ funktionsgerüst, SCHRAUSSER 2009 - 2011	//

long double fn_grs_1(double wert[100])//  Autocode   //  // (0) FN1 0,0  // 											                                     
{

/*	
	FILE *out;

	int iLauf,ind=1,ind2=1;
	
	out=fopen( "MAT_fn.txt", "w" );

	for(iLauf=92;iLauf<=115;iLauf++)
	{
		fprintf(out,"//%i. Paar\n",iLauf-91);
		fprintf(out,"if(Z_==%i||Z_==%i){padd_am[%i]+=padd[%i];padd2[%i]+=pow(padd[%i],2);zlr2[%i]++; t_am[%i]+=zlr3[%i]; t_2[%i]+=pow(zlr3[%i],2);zlr3[%i]=1;}\n",ind,ind+1,iLauf,iLauf,iLauf,iLauf,iLauf,iLauf,iLauf,iLauf,iLauf,iLauf);
		fprintf(out,"else            {padd[%i]=1-(pow(1-0.054054,zlr3[%i]));zlr3[%i]++;}\n",iLauf,iLauf,iLauf);
		ind+=1;

		ind2++;if(ind2==3){ind2=1;ind+=1;}
	}

	fclose(out);


	double ilauf, x_1=1000, x_2,vektor[3];//gamma wendepunkt
	                                                   
	                                                   vektor[2]=10000000;
	for(ilauf=1.46155999;ilauf<1.47;ilauf+=0.000000001)
	{
		                                               vektor[1]=ilauf;
                                            x_2=igamma(vektor);
		printf("Gamma(%.10f)=%.16f\n",ilauf,x_2);
	                                     if(x_2>x_1)break;
		                                        x_1=x_2;
	}

	fn_erg = ilauf;
	
	
	
	//p-kurve zur theta-verteilung
	
	FILE *in, *out,*out2,*out3;
	
	double x_, M=0,n=0, inc,i_,d,scala, scala1,scala2,p_,p1,nd=1,iLauf,pin=0,x1=0,y_=0;//
	char tmp[1000000]; 

	in=fopen( "tmp_in.txt", "r" );
	out=fopen( "tmp_out.txt", "w" );
	out2=fopen( "tmp_out2.txt", "w" );
	out3=fopen( "tmp_out3.txt", "w" );
	
	do { if(fgetc(in)=='\n') M++;} while (feof (in) == 0);   fclose( in  );
	
	    d=(10.2983310000000050/10);//range
	inc=d/(M/10);
	i_=inc;


	scala=94.714314+inc;//minimalwert
	scala2=94.714314;
	scala1=94.714314;

	in=fopen( "tmp_in.txt", "r" );
	
	while (n<M)
	{ 
		fscanf ( in, "%s", tmp);  n++;
		           x_=atof(tmp);
		                       p_=n/M;
		
		if(n>1)//p-kurve linearinterpoliert
		{
			fprintf( out3, "%f\t%0.32f\n",scala1+i_,p1);i_+=inc/10;
			
			for(iLauf=1;iLauf<nd-1;iLauf++)
			{		
				                                       pin+=(p_-p1)/(nd-2);
				fprintf( out3, "%f\t%0.32f\n",scala1+i_,p1+pin);
				                                     i_+=inc/10;
			}

			pin=0;
		}
							   
		nd=1;					   					   
							   
		while(scala2<=x_)//p-kurve
		{		
			
			fprintf( out2, "%f\t%f\t%f\n",scala2,  x_-scala2,p_);
			                              scala2+=inc/10;

										  nd++;
		}
		p1=p_;

		
		fprintf( out, "%s\t%f\t%f\t%f\n", tmp, p_,scala, (1/M)/nd); 
		                                          scala+=inc;
											                   
	} 

	//p-kurve linearinterpoliert
		
	fprintf( out3, "%0.32f\n",p1);
	
	for(iLauf=1;iLauf<nd-1;iLauf++)
	{		
				                     pin+=(p_-p1)/(nd-2);
		fprintf( out3, "%0.32f\n",p1+pin);												  
	}

	fclose(in);
	fclose(out);
	fclose(out2);
	fclose(out3);

	in=fopen( "tmp_out3.txt", "r" );
	out=fopen( "tmp_out4.txt", "w" );

	//P dichtekurve aus interpolierter p-kurve (interpoliert)
	while (feof (in) == 0)
	{
		              fscanf ( in, "%s", tmp); 
		                         x_=atof(tmp);
					  
					for(iLauf=1;iLauf<300;iLauf++)//interpolierung ist hier sinnvoll 
					{
						 fscanf ( in, "%s", tmp); 
									y_=atof(tmp);

									 x_=(x_+y_)/2;
					}
					                          
			fprintf( out, "%0.32f\n",x_-x1 );
		                                x1=x_;
	}  

	fclose(in);
	fclose(out);
	*/

	// romberg integration // FN1 a,b,  // 
	
	double A_, B_, H_, N_=1, X_, I_[17], E_=1e-17, F_, F1_, S_, Q_,  Ia, vektor[3];
	int  j_,k_;

	A_=wert[1]; //integrations min
	B_=wert[2]; //integrations max

	vektor[2]=23; //df

	H_=B_-A_;
	                       X_=A_;
	                //F_=log(X_)/X_; // funktion f(x)
					//F_=pow(X_,2); // funktion f(x)
					//F_=2*X_; // funktion f(x)
					//F_=dz_funktion(X_); // z // (7-stellige genauigkeit)
					//F_=pow(X_,1.4-1)*pow(fn_const(1),-X_); //gamma bei a=0.0001 b=10000 mit x>=1, weniger gut geeignet
					vektor[1]=X_;F_=dt_funktion(vektor); // t genau bei höherem df 
	            F1_=F_;

	                       X_=B_;
	                //F_=log(X_)/X_; // funktion f(x)
					//F_=pow(X_,2); // funktion f(x)
					//F_=2*X_; // funktion f(x)
					//F_=dz_funktion(X_);// z
					//F_=pow(X_,1.4-1)*pow(fn_const(1),-X_); //gamma
					vektor[1]=X_;F_=dt_funktion(vektor); // t
	I_[0]=  H_*(F1_+F_)/2;

	for(k_=1;k_<=17;k_++)
	{
		S_=0;H_/=2;N_*=2;Q_=1;
		
		for(j_=1;j_<=N_-1;j_+=2)
		{
			           X_=A_+j_*H_;
			    //F_=log(X_)/X_; // funktion f(x)
				//F_=pow(X_,2); // funktion f(x)
				//F_=2*X_; // funktion f(x)
				//F_=dz_funktion(X_); // z
				//F_=pow(X_,1.4-1)*pow(fn_const(1),-X_); //gamma
				vektor[1]=X_;F_=dt_funktion(vektor); // t
			S_+=F_;
		}
		
		I_[k_]=I_[k_-1]/2+S_*H_;

		for(j_=k_-1;j_>=0;j_--)
		{
			                                   Q_*=4;
			I_[j_]=I_[j_+1]+(I_[j_+1]-I_[j_])/(Q_-1);
		}

		printf("\nI_[0]= %.16f",I_[0]);

		                        Ia=fabs(I_[0]);
		                     if(Ia<1)Ia=1;
		if(fabs(I_[1]-I_[0])<E_*Ia)break;
	}

	printf("\nI_[0]= %.16f\n",I_[0]);

	fn_erg=I_[0];

	return fn_erg;
}




long double fn_grs_2(double wert[100])// hypergeometrisch exakt 2x2x2           
//                                       bei maximaler randfrequenz fmax >=15  
//                                       -> zeitlich aufwendige kalkulation 
//													                            // (0) FN2 a,b,c,d,e,f,g,h   //     
{
    FILE *out;
	
	double a,b,c,d,e,f,g,h, n, zlr=0;
	double vektor[100], P0, P0_, p_=0, S1,S2,Z1,Z2, T1, T2;
	double max_a, max_b, max_c, max_d, max_e, max_f, max_g, max_h, x1, x2,x3 ;//,zh

	out=fopen( "fx.txt", "w" );

	Z1=wert[1]+wert[2]+wert[5]+wert[6];  
	Z2=wert[3]+wert[4]+wert[7]+wert[8];
	S1=wert[1]+wert[3]+wert[5]+wert[7];
	S2=wert[2]+wert[4]+wert[6]+wert[8];
	T1=wert[1]+wert[2]+wert[3]+wert[4];
	T2=wert[5]+wert[6]+wert[7]+wert[8];

	n=T1+T2;

	if(Z1>=S1) max_a=Z1; if(S1>Z1) max_a=S1;max_e=max_a;
	if(Z1>=S2) max_b=Z1; if(S2>Z1) max_b=S2;max_f=max_b;
	if(Z2>=S1) max_c=Z2; if(S1>Z2) max_c=S1;max_g=max_c;
	if(Z2>=S2) max_d=Z2; if(S2>Z2) max_d=S2;max_h=max_d;

	if (max_a > n/2+1)max_a=ceil(n/2+1);
	if (max_b > n/2+1)max_b=ceil(n/2+1);
	if (max_c > n/2+1)max_c=ceil(n/2+1);
	if (max_d > n/2+1)max_d=ceil(n/2+1);

	vektor[1]=wert[1];
	vektor[2]=wert[2];
	vektor[3]=wert[3];
	vektor[4]=wert[4];
	vektor[5]=wert[5];
	vektor[6]=wert[6];
	vektor[7]=wert[7];
	vektor[8]=wert[8];
										
	P0= fn_hg_(vektor, 1);//

		printf("\n\n");

    //max randsumme +1 (wegen null)
	
	for(e=max_e+1; e>=0;e-=1)//ggf step 2..
	{
		for(f=max_f -e +1; f>=0;f-=1)//ggf step 2..
		{
			for(g=max_g -e +1; g>=0;g-=1)//ggf step 2..
			{
			               if(f>=g)x1=f;
				            if(g>f)x1=g;
				for(h=0; h<=max_h -x1 +1;h+=1)
				{
					for(d=0; d<=max_d-g-h+1;d+=1)
					{
						for(c=0; c<=max_c-d-g-h+1;c+=1)
						{
							             if(e+f>=d)x2=e+f;
				                         if(d>e+f)x2=d;
							for(b=0; b<=max_b    -x2+1;b+=1)
							{				
								         if(b+e+f>=c)x3=b+e+f;
				                         if(c>b+e+f)x3=c;
								for(a=0; a<=max_a  -x3+1;a+=1)
								{
									if(a+b+c+d > T1) break;
									
									if(  
										a+b+e+f == Z1 && //Z1
										c+d+g+h == Z2 && //Z2
										a+c+e+g == S1 && //S1
										b+d+f+h == S2 && //S2
										a+b+c+d == T1 && //T1
										e+f+g+h == T2 //&&   //T1
										//((a == 4 || a== 0) &&
										//(b == 4 || b== 0) &&
										//(c == 4 || c== 0) &&
										//(d == 4 || d== 0) &&
										//(e == 4 || e== 0) &&
										//(f == 4 || f== 0) &&
										//(g == 4 || g== 0) &&
										//(((h == 4 || h== 0)) 
	     								)
									{
									//	printf("HG0 %.0f,%.0f,%.0f,%.0f,%.0f,%.0f,%.0f,%.0f\n",a,b,c,d,e,f,g,h);zlr++;
								        printf("%.0f\r",zlr);zlr++;//
										//printf("%.0f  %.0f  %.0f  %.0f\n\n",a,b, e,f);//
										//printf("%.0f  %.0f  %.0f  %.0f\n\n", c,d ,g,h);//
										///*	
										vektor[1]=a;
										vektor[2]=b;
										vektor[3]=c;
										vektor[4]=d;
										vektor[5]=e;
										vektor[6]=f;
										vektor[7]=g;
										vektor[8]=h;
										
										
										P0_= fn_hg_(vektor, 1);//
										//zh = fn_hg_(vektor, 3);//

										//printf("\nz= %.5f P0= %.5f\n\n",zh,P0_); //
										
										if(P0_<=P0)p_=p_+P0_;if(p_>=0.9998) {exit(1); fclose(out);} // p_=1 Begrenzung//

										//printf ("%.32f\t%.4f\n", P0_, p_);
										//fprintf (out,"%.32f\t%.4f\n", P0_, p_);
										 // fprintf (out,"%.16f\n", zh);
                                        //*/
									}
									//printf("%.0f, %.0f, %.0f, %.0f, %.0f, %.0f, %.0f, %.0f  \r",a,b,c,d,e,f,g,h);
								
								
								}
							
							}
						
						}
					
					}
				
				}
			}

		}

	}
	
	fclose(out);

	fn_erg=p_;
	
	return 0;
}


double fn_grs_3(double wert[100], int k) // vollständige Permutationsmatrix wP von n zu m Klassen  //  FN3 n,k1,k2, ...km (geschwindigkeitsmaximierend bei k1>k2>...>kn) //											                
{
 	FILE *out;
	
	int iLauf[10], Lauf[100], pLauf[100],  sw=0, k_[100],i_=0;
	double n_,zlr=0 , dLauf[100], vektor[100];
	int stellen, vorz, maxlng=1; //ecvt indizes: double -> string -> int	       

	n_=wert[1]; 
	if(wert[1]!=99)if(n_>12) {printf("\n\ndesign.0 'n>12'\n");exit(0);} //begrenzt auf n=12

	k=k-1;
	
	for(Lauf[1]=1; Lauf[1]<= k;  Lauf[1]++)    k_[Lauf[1]]= atoi(ecvt(wert[Lauf[1]+1],maxlng,&stellen,&vorz));
	for(Lauf[1]=1; Lauf[1]<= n_; Lauf[1]++) pLauf[Lauf[1]]= 1; 

	// dateilänge begrenzt auf zln<66000
	                                             dLauf[1]=n_;
	for(Lauf[1]=2; Lauf[1]<= k+1;  Lauf[1]++)    dLauf[Lauf[1]]= wert[Lauf[1]];
	if(wert[1]!=99)if(permutation_k(dLauf, k)>66000) {printf("\n\nfile.0 'wP>66000'");  exit(0);}   
	
	pLauf[1]=0;

	out=fopen( "fx.txt", "w" );

	if(n_>=7)printf("\n\ncomputing pi(xj) ...");	
	
	//  wP explizit
	if( (wert[1]>=8 && wert[1]<=12) || wert[1]==99)
	{
		//------------------------------------------------------------------------------------------------- wP n=8 //
		if(n_==8)
		{
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){if(k_[1]>=2)if(Lauf[1]>Lauf[2]) break;// k1>k2> ... >kn vorausgesetzt
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){if(k_[1]>=3)if(Lauf[2]>Lauf[3]) break;//if(k_[2]>=3)if(Lauf[2]>Lauf[3]) break;
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){if(k_[1]>=4)if(Lauf[3]>Lauf[4]) break;//if(k_[2]>=4)if(Lauf[3]>Lauf[4]) break;
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){if(k_[1]>=5)if(Lauf[4]>Lauf[5]) break;//if(k_[2]>=5)if(Lauf[4]>Lauf[5]) break;
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){//if(k_[1]>=6)if(Lauf[5]>Lauf[6]) break;//if(k_[2]>=6)if(Lauf[5]>Lauf[6]) break;
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){//if(k_[1]>=7)if(Lauf[6]>Lauf[7]) break;//if(k_[2]>=7)if(Lauf[6]>Lauf[7]) break;
			
			    sw=0;
				// elementwiederholungsfilter explizit
				if( Lauf[1]==Lauf[2]  || 
					Lauf[1]==Lauf[3]  || 
					Lauf[1]==Lauf[4]  || 
					Lauf[1]==Lauf[5]  || 
					Lauf[1]==Lauf[6]  || 
					Lauf[1]==Lauf[7]  ||
					Lauf[1]==Lauf[8]  ||
					Lauf[2]==Lauf[3]  ||
					Lauf[2]==Lauf[4]  ||
					Lauf[2]==Lauf[5]  ||
					Lauf[2]==Lauf[6]  ||
					Lauf[2]==Lauf[7]  ||
					Lauf[2]==Lauf[8]  ||
					Lauf[3]==Lauf[4]  || 
					Lauf[3]==Lauf[5]  || 
					Lauf[3]==Lauf[6]  || 
					Lauf[3]==Lauf[7]  || 
					Lauf[3]==Lauf[8]  ||
					Lauf[4]==Lauf[5]  || 
					Lauf[4]==Lauf[6]  ||
					Lauf[4]==Lauf[7]  ||
					Lauf[4]==Lauf[8]  ||
					Lauf[5]==Lauf[6]  || 
				    Lauf[5]==Lauf[7]  || 
					Lauf[5]==Lauf[8]  ||
					Lauf[6]==Lauf[7]  ||
					Lauf[6]==Lauf[8]  ||
					Lauf[7]==Lauf[8]  
					
				  )sw=1;
						
				// anordnungswiederholungsfilter 
				if(sw==0)
				for(iLauf[3]=1; iLauf[3]<=k; iLauf[3]++)
				{
					     if(sw==0)
			             for(iLauf[1]=1; iLauf[1]<= k_[iLauf[3]]; iLauf[1]++)
										   for(iLauf[2]=iLauf[1]+1; iLauf[2]<=k_[iLauf[3]]; iLauf[2]++) 
				  if( ( Lauf[iLauf[1]+i_]>Lauf[iLauf[2]+i_] ) ) {sw=1;break;}
				  i_+=k_[iLauf[3]];
				}
				i_=0;
				
				// dateiausgabe des permutationsvektors
				if(sw==0)
				{
					for(iLauf[3]=1; iLauf[3]<= k; iLauf[3]++)
					{
						for(iLauf[1]=1; iLauf[1]<= k_[iLauf[3]]; iLauf[1]++) fprintf(out,"%i ", Lauf[iLauf[1]+i_]); 
						fprintf(out,"   ");//
						i_+=k_[iLauf[3]];
					}
					fprintf(out,"\n");
					i_=0;
						zlr++;
				}

			}//8
			}//7
			}//6
			}//5
			}//4
			}//3
			}//2
			}//1
		}

		//------------------------------------------------------------------------------------------------- wP n=9 //
		if(n_==9)
		{
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){ 
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){ if(k_[1]>=2)if(Lauf[1]>Lauf[2]) break;
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){ if(k_[1]>=3)if(Lauf[2]>Lauf[3]) break;
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){ if(k_[1]>=4)if(Lauf[3]>Lauf[4]) break;
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){ if(k_[1]>=5)if(Lauf[4]>Lauf[5]) break;
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){ if(k_[1]>=6)if(Lauf[5]>Lauf[6]) break;
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){ //if(k_[1]>=7)if(Lauf[6]>Lauf[7]) break;
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){ //if(k_[1]>=8)if(Lauf[7]>Lauf[8]) break;
			
			    sw=0;
				// elementwiederholungsfilter explizit
				if( Lauf[1]==Lauf[2]  || 
					Lauf[1]==Lauf[3]  || 
					Lauf[1]==Lauf[4]  || 
					Lauf[1]==Lauf[5]  || 
					Lauf[1]==Lauf[6]  || 
					Lauf[1]==Lauf[7]  ||
					Lauf[1]==Lauf[8]  ||
					Lauf[1]==Lauf[9]  ||
					Lauf[2]==Lauf[3]  ||
					Lauf[2]==Lauf[4]  ||
					Lauf[2]==Lauf[5]  ||
					Lauf[2]==Lauf[6]  ||
					Lauf[2]==Lauf[7]  ||
					Lauf[2]==Lauf[8]  ||
					Lauf[2]==Lauf[9]  ||
					Lauf[3]==Lauf[4]  || 
					Lauf[3]==Lauf[5]  || 
					Lauf[3]==Lauf[6]  || 
					Lauf[3]==Lauf[7]  || 
					Lauf[3]==Lauf[8]  ||
					Lauf[3]==Lauf[9]  ||
					Lauf[4]==Lauf[5]  || 
					Lauf[4]==Lauf[6]  ||
					Lauf[4]==Lauf[7]  ||
					Lauf[4]==Lauf[8]  ||
					Lauf[4]==Lauf[9]  ||
					Lauf[5]==Lauf[6]  || 
				    Lauf[5]==Lauf[7]  || 
					Lauf[5]==Lauf[8]  ||
					Lauf[5]==Lauf[9]  ||
					Lauf[6]==Lauf[7]  ||
					Lauf[6]==Lauf[8]  ||
					Lauf[6]==Lauf[9]  ||
					Lauf[7]==Lauf[8]  ||
					Lauf[7]==Lauf[9]  ||
					Lauf[8]==Lauf[9]  
					
				  )sw=1;
						
				// anordnungswiederholungsfilter 
				if(sw==0)
				for(iLauf[3]=1; iLauf[3]<=k; iLauf[3]++)
				{
					     if(sw==0)
			             for(iLauf[1]=1; iLauf[1]<= k_[iLauf[3]]; iLauf[1]++)
										   for(iLauf[2]=iLauf[1]+1; iLauf[2]<=k_[iLauf[3]]; iLauf[2]++) 
				  if( ( Lauf[iLauf[1]+i_]>Lauf[iLauf[2]+i_] ) ) {sw=1;break;}
				  i_+=k_[iLauf[3]];
				}
				i_=0;
				
				// dateiausgabe des permutationsvektors
				if(sw==0)
				{
					for(iLauf[3]=1; iLauf[3]<= k; iLauf[3]++)
					{
						for(iLauf[1]=1; iLauf[1]<= k_[iLauf[3]]; iLauf[1]++) fprintf(out,"%i ", Lauf[iLauf[1]+i_]); 
						fprintf(out,"   ");//
						i_+=k_[iLauf[3]];
					}
					fprintf(out,"\n");
					i_=0;
						zlr++;
				}
			
			}//9
			}//8
			}//7
			}//6
			}//5
			}//4
			}//3
			}//2
			}//1
		}

		//------------------------------------------------------------------------------------------------- wP n=10 //
		if(n_==10)
		{
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){ 
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){ if(k_[1]>=2)if(Lauf[1]>Lauf[2]) break;
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){ if(k_[1]>=3)if(Lauf[2]>Lauf[3]) break;//if(k_[2]>=3)if(Lauf[2]>Lauf[3]) break;
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){ if(k_[1]>=4)if(Lauf[3]>Lauf[4]) break;//if(k_[2]>=4)if(Lauf[3]>Lauf[4]) break;
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){ if(k_[1]>=5)if(Lauf[4]>Lauf[5]) break;//if(k_[2]>=5)if(Lauf[4]>Lauf[5]) break;
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){ if(k_[1]>=6)if(Lauf[5]>Lauf[6]) break;//if(k_[2]>=6)if(Lauf[5]>Lauf[6]) break;
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){ if(k_[1]>=7)if(Lauf[6]>Lauf[7]) break;//if(k_[2]>=7)if(Lauf[6]>Lauf[7]) break;
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){ //if(k_[1]>=8)if(Lauf[7]>Lauf[8]) break;//if(k_[2]>=8)if(Lauf[7]>Lauf[8]) break;
			for (Lauf[10]=1; Lauf[10]<=n_; Lauf[10]++){ //if(k_[1]>=9)if(Lauf[8]>Lauf[9]) break;//if(k_[2]>=9)if(Lauf[8]>Lauf[9]) break;

			
			    sw=0;
				// elementwiederholungsfilter explizit
				if( Lauf[1]==Lauf[2]  || 
					Lauf[1]==Lauf[3]  || 
					Lauf[1]==Lauf[4]  || 
					Lauf[1]==Lauf[5]  || 
					Lauf[1]==Lauf[6]  || 
					Lauf[1]==Lauf[7]  ||
					Lauf[1]==Lauf[8]  ||
					Lauf[1]==Lauf[9]  ||
					Lauf[1]==Lauf[10] ||
					Lauf[2]==Lauf[3]  ||
					Lauf[2]==Lauf[4]  ||
					Lauf[2]==Lauf[5]  ||
					Lauf[2]==Lauf[6]  ||
					Lauf[2]==Lauf[7]  ||
					Lauf[2]==Lauf[8]  ||
					Lauf[2]==Lauf[9]  ||
					Lauf[2]==Lauf[10] ||
					Lauf[3]==Lauf[4]  || 
					Lauf[3]==Lauf[5]  || 
					Lauf[3]==Lauf[6]  || 
					Lauf[3]==Lauf[7]  || 
					Lauf[3]==Lauf[8]  ||
					Lauf[3]==Lauf[9]  ||
					Lauf[3]==Lauf[10] ||
					Lauf[4]==Lauf[5]  || 
					Lauf[4]==Lauf[6]  ||
					Lauf[4]==Lauf[7]  ||
					Lauf[4]==Lauf[8]  ||
					Lauf[4]==Lauf[9]  ||
					Lauf[4]==Lauf[10] ||
					Lauf[5]==Lauf[6]  || 
				    Lauf[5]==Lauf[7]  || 
					Lauf[5]==Lauf[8]  ||
					Lauf[5]==Lauf[9]  ||
					Lauf[5]==Lauf[10] ||
					Lauf[6]==Lauf[7]  ||
					Lauf[6]==Lauf[8]  ||
					Lauf[6]==Lauf[9]  ||
					Lauf[6]==Lauf[10] ||
					Lauf[7]==Lauf[8]  ||
					Lauf[7]==Lauf[9]  ||
					Lauf[7]==Lauf[10] ||
					Lauf[8]==Lauf[9]  ||
					Lauf[8]==Lauf[10] ||
					Lauf[9]==Lauf[10]  
					
				  )sw=1;
						
				// anordnungswiederholungsfilter 
				if(sw==0)
				for(iLauf[3]=1; iLauf[3]<=k; iLauf[3]++)
				{
					     if(sw==0)
			             for(iLauf[1]=1; iLauf[1]<= k_[iLauf[3]]; iLauf[1]++)
										   for(iLauf[2]=iLauf[1]+1; iLauf[2]<=k_[iLauf[3]]; iLauf[2]++) 
				  if( ( Lauf[iLauf[1]+i_]>Lauf[iLauf[2]+i_] ) ) {sw=1;break;}
				  i_+=k_[iLauf[3]];
				}
				i_=0;
				
				// dateiausgabe des permutationsvektors
				if(sw==0)
				{
					for(iLauf[3]=1; iLauf[3]<= k; iLauf[3]++)
					{
						for(iLauf[1]=1; iLauf[1]<= k_[iLauf[3]]; iLauf[1]++) fprintf(out,"%i ", Lauf[iLauf[1]+i_]); 
						fprintf(out,"   ");//
						i_+=k_[iLauf[3]];
					}
					fprintf(out,"\n");
					i_=0;
						zlr++;
				}
			
			}//10
			}//9
			}//8
			}//7
			}//6
			}//5
			}//4
			}//3
			}//2
			}//1
		}

		//------------------------------------------------------------------------------------------------- wP n=11 //
		if(n_==11)
		{
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){ 
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){ if(k_[1]>=2)if(Lauf[1]>Lauf[2]) break;
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){ if(k_[1]>=3)if(Lauf[2]>Lauf[3]) break;//if(k_[2]>=3)if(Lauf[2]>Lauf[3]) break;
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){ if(k_[1]>=4)if(Lauf[3]>Lauf[4]) break;//if(k_[2]>=4)if(Lauf[3]>Lauf[4]) break;
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){ if(k_[1]>=5)if(Lauf[4]>Lauf[5]) break;//if(k_[2]>=5)if(Lauf[4]>Lauf[5]) break;
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){ if(k_[1]>=6)if(Lauf[5]>Lauf[6]) break;//if(k_[2]>=6)if(Lauf[5]>Lauf[6]) break;
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){ if(k_[1]>=7)if(Lauf[6]>Lauf[7]) break;//if(k_[2]>=7)if(Lauf[6]>Lauf[7]) break;
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){ if(k_[1]>=8)if(Lauf[7]>Lauf[8]) break;//if(k_[2]>=8)if(Lauf[7]>Lauf[8]) break;
			for (Lauf[10]=1; Lauf[10]<=n_; Lauf[10]++){ //if(k_[1]>=9)if(Lauf[8]>Lauf[9]) break;//if(k_[2]>=9)if(Lauf[8]>Lauf[9]) break;
			for (Lauf[11]=1; Lauf[11]<=n_; Lauf[11]++){ //if(k_[1]>=10)if(Lauf[9]>Lauf[10]) break;if(k_[2]>=10)if(Lauf[9]>Lauf[10]) break;

			    sw=0;
				// elementwiederholungsfilter explizit
				if( Lauf[1]==Lauf[2]  || 
					Lauf[1]==Lauf[3]  || 
					Lauf[1]==Lauf[4]  || 
					Lauf[1]==Lauf[5]  || 
					Lauf[1]==Lauf[6]  || 
					Lauf[1]==Lauf[7]  ||
					Lauf[1]==Lauf[8]  ||
					Lauf[1]==Lauf[9]  ||
					Lauf[1]==Lauf[10] ||
					Lauf[1]==Lauf[11] ||
					Lauf[2]==Lauf[3]  ||
					Lauf[2]==Lauf[4]  ||
					Lauf[2]==Lauf[5]  ||
					Lauf[2]==Lauf[6]  ||
					Lauf[2]==Lauf[7]  ||
					Lauf[2]==Lauf[8]  ||
					Lauf[2]==Lauf[9]  ||
					Lauf[2]==Lauf[10] ||
					Lauf[2]==Lauf[11] ||
					Lauf[3]==Lauf[4]  || 
					Lauf[3]==Lauf[5]  || 
					Lauf[3]==Lauf[6]  || 
					Lauf[3]==Lauf[7]  || 
					Lauf[3]==Lauf[8]  ||
					Lauf[3]==Lauf[9]  ||
					Lauf[3]==Lauf[10] ||
					Lauf[3]==Lauf[11] ||
					Lauf[4]==Lauf[5]  || 
					Lauf[4]==Lauf[6]  ||
					Lauf[4]==Lauf[7]  ||
					Lauf[4]==Lauf[8]  ||
					Lauf[4]==Lauf[9]  ||
					Lauf[4]==Lauf[10] ||
					Lauf[4]==Lauf[11] ||
					Lauf[5]==Lauf[6]  || 
				    Lauf[5]==Lauf[7]  || 
					Lauf[5]==Lauf[8]  ||
					Lauf[5]==Lauf[9]  ||
					Lauf[5]==Lauf[10] ||
					Lauf[5]==Lauf[11] ||
					Lauf[6]==Lauf[7]  ||
					Lauf[6]==Lauf[8]  ||
					Lauf[6]==Lauf[9]  ||
					Lauf[6]==Lauf[10] ||
					Lauf[6]==Lauf[11] ||
					Lauf[7]==Lauf[8]  ||
					Lauf[7]==Lauf[9]  ||
					Lauf[7]==Lauf[10] ||
					Lauf[7]==Lauf[11] ||
					Lauf[8]==Lauf[9]  ||
					Lauf[8]==Lauf[10] ||
					Lauf[8]==Lauf[11] ||
					Lauf[9]==Lauf[10] ||
					Lauf[9]==Lauf[11] ||
					Lauf[10]==Lauf[11]
					
				  )sw=1;
						
				// anordnungswiederholungsfilter 
				if(sw==0)
				for(iLauf[3]=1; iLauf[3]<=k; iLauf[3]++)
				{
					     if(sw==0)
			             for(iLauf[1]=1; iLauf[1]<= k_[iLauf[3]]; iLauf[1]++)
										   for(iLauf[2]=iLauf[1]+1; iLauf[2]<=k_[iLauf[3]]; iLauf[2]++) 
				  if( ( Lauf[iLauf[1]+i_]>Lauf[iLauf[2]+i_] ) ) {sw=1;break;}
				  i_+=k_[iLauf[3]];
				}
				i_=0;
				
				// dateiausgabe des permutationsvektors
				if(sw==0)
				{
					for(iLauf[3]=1; iLauf[3]<= k; iLauf[3]++)
					{
						for(iLauf[1]=1; iLauf[1]<= k_[iLauf[3]]; iLauf[1]++) fprintf(out,"%i ", Lauf[iLauf[1]+i_]); 
						fprintf(out,"   ");//
						i_+=k_[iLauf[3]];
					}
					fprintf(out,"\n");
					i_=0;
						zlr++;
				}
			
			}//11
			}//10
			}//9
			}//8
			}//7
			}//6
			}//5
			}//4
			}//3
			}//2
			}//1
		}

		//------------------------------------------------------------------------------------------------- wP n=12 //
		if(n_==12)
		{
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){ 
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){ if(k_[1]>=2)if(Lauf[1]>Lauf[2]) break;
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){ if(k_[1]>=3)if(Lauf[2]>Lauf[3]) break;if(k_[2]>=3)if(Lauf[2]>Lauf[3]) break;
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){ if(k_[1]>=4)if(Lauf[3]>Lauf[4]) break;if(k_[2]>=4)if(Lauf[3]>Lauf[4]) break;
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){ if(k_[1]>=5)if(Lauf[4]>Lauf[5]) break;if(k_[2]>=5)if(Lauf[4]>Lauf[5]) break;
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){ if(k_[1]>=6)if(Lauf[5]>Lauf[6]) break;if(k_[2]>=6)if(Lauf[5]>Lauf[6]) break;
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){ if(k_[1]>=7)if(Lauf[6]>Lauf[7]) break;if(k_[2]>=7)if(Lauf[6]>Lauf[7]) break;
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){ if(k_[1]>=8)if(Lauf[7]>Lauf[8]) break;if(k_[2]>=8)if(Lauf[7]>Lauf[8]) break;
			for (Lauf[10]=1; Lauf[10]<=n_; Lauf[10]++){ if(k_[1]>=9)if(Lauf[8]>Lauf[9]) break;if(k_[2]>=9)if(Lauf[8]>Lauf[9]) break;
			for (Lauf[11]=1; Lauf[11]<=n_; Lauf[11]++){ //if(k_[1]>=10)if(Lauf[9]>Lauf[10]) break;//if(k_[2]>=10)if(Lauf[9]>Lauf[10]) break;
			for (Lauf[12]=1; Lauf[12]<=n_; Lauf[12]++){ //if(k_[1]>=11)if(Lauf[10]>Lauf[11]) break;//if(k_[2]>=10)if(Lauf[9]>Lauf[10]) break;
			
			
			    sw=0;
				// elementwiederholungsfilter explizit
				if( Lauf[1]==Lauf[2]  || 
					Lauf[1]==Lauf[3]  || 
					Lauf[1]==Lauf[4]  || 
					Lauf[1]==Lauf[5]  || 
					Lauf[1]==Lauf[6]  || 
					Lauf[1]==Lauf[7]  ||
					Lauf[1]==Lauf[8]  ||
					Lauf[1]==Lauf[9]  ||
					Lauf[1]==Lauf[10] ||
					Lauf[1]==Lauf[11] ||
					Lauf[1]==Lauf[12] ||
					Lauf[2]==Lauf[3]  ||
					Lauf[2]==Lauf[4]  ||
					Lauf[2]==Lauf[5]  ||
					Lauf[2]==Lauf[6]  ||
					Lauf[2]==Lauf[7]  ||
					Lauf[2]==Lauf[8]  ||
					Lauf[2]==Lauf[9]  ||
					Lauf[2]==Lauf[10] ||
					Lauf[2]==Lauf[11] ||
					Lauf[2]==Lauf[12] ||
					Lauf[3]==Lauf[4]  || 
					Lauf[3]==Lauf[5]  || 
					Lauf[3]==Lauf[6]  || 
					Lauf[3]==Lauf[7]  || 
					Lauf[3]==Lauf[8]  ||
					Lauf[3]==Lauf[9]  ||
					Lauf[3]==Lauf[10] ||
					Lauf[3]==Lauf[11] ||
					Lauf[3]==Lauf[12] ||
					Lauf[3]==Lauf[12] ||
					Lauf[4]==Lauf[5]  || 
					Lauf[4]==Lauf[6]  ||
					Lauf[4]==Lauf[7]  ||
					Lauf[4]==Lauf[8]  ||
					Lauf[4]==Lauf[9]  ||
					Lauf[4]==Lauf[10] ||
					Lauf[4]==Lauf[11] ||
					Lauf[4]==Lauf[12] ||
					Lauf[4]==Lauf[12] ||
					Lauf[5]==Lauf[6]  || 
				    Lauf[5]==Lauf[7]  || 
					Lauf[5]==Lauf[8]  ||
					Lauf[5]==Lauf[9]  ||
					Lauf[5]==Lauf[10] ||
					Lauf[5]==Lauf[11] ||
					Lauf[5]==Lauf[12] ||
					Lauf[6]==Lauf[7]  ||
					Lauf[6]==Lauf[8]  ||
					Lauf[6]==Lauf[9]  ||
					Lauf[6]==Lauf[10] ||
					Lauf[6]==Lauf[11] ||
					Lauf[6]==Lauf[12] ||
					Lauf[7]==Lauf[8]  ||
					Lauf[7]==Lauf[9]  ||
					Lauf[7]==Lauf[10] ||
					Lauf[7]==Lauf[11] ||
					Lauf[7]==Lauf[12] ||
					Lauf[8]==Lauf[9]  ||
					Lauf[8]==Lauf[10] ||
					Lauf[8]==Lauf[11] ||
					Lauf[8]==Lauf[12] ||
					Lauf[9]==Lauf[10] ||
					Lauf[9]==Lauf[11] ||
					Lauf[9]==Lauf[12] ||
					Lauf[10]==Lauf[11] ||
					Lauf[10]==Lauf[12] ||
					Lauf[11]==Lauf[12] 
					
				  )sw=1;
						
				// anordnungswiederholungsfilter 
				if(sw==0)
				for(iLauf[3]=1; iLauf[3]<=k; iLauf[3]++)
				{
					     if(sw==0)
			             for(iLauf[1]=1; iLauf[1]<= k_[iLauf[3]]; iLauf[1]++)
										   for(iLauf[2]=iLauf[1]+1; iLauf[2]<=k_[iLauf[3]]; iLauf[2]++) 
				  if( ( Lauf[iLauf[1]+i_]>Lauf[iLauf[2]+i_] ) ) {sw=1;break;}
				  i_+=k_[iLauf[3]];
				}
				i_=0;
				
				// dateiausgabe des permutationsvektors
				if(sw==0)
				{
					for(iLauf[3]=1; iLauf[3]<= k; iLauf[3]++)
					{
						for(iLauf[1]=1; iLauf[1]<= k_[iLauf[3]]; iLauf[1]++) fprintf(out,"%i ", Lauf[iLauf[1]+i_]); 
						fprintf(out,"   ");//
						i_+=k_[iLauf[3]];
					}
					fprintf(out,"\n");
					printf("\r%.0f  " ,zlr);
					i_=0;
					zlr++;
				}
			
			}//12
			}//11
			}//10
			}//9
			}//8
			}//7
			}//6
			}//5
			}//4
			}//3
			}//2
			}//1
		}
		
		// Permutationstabelle
		if(wert[1]==99)
		{
			//m=3 gesamt
			for(dLauf[1]=1; dLauf[1]<= 30; dLauf[1]++)//n
			{
				for(dLauf[2]=1; dLauf[2]<= 10; dLauf[2]++)//k1
				{
					for(dLauf[3]=1; dLauf[3]<= 10; dLauf[3]++)//k2
					{
						for(dLauf[4]=1; dLauf[4]<= 10; dLauf[4]++)//k3
						{	
							if(dLauf[2]<=dLauf[3])
								if(dLauf[3]<=dLauf[4])
								{
																						vektor[1]=dLauf[1];
																						vektor[2]=dLauf[2];
																						vektor[3]=dLauf[3];
																						vektor[4]=dLauf[4];
								if(dLauf[2]<=dLauf[3]) fprintf(out,"%.0f\t", permutation_k(vektor, 3+1)); //fprintf(out,"(%.0f,%.0f,%.0f) ", dLauf[2],dLauf[3],dLauf[1]-dLauf[4])
								}
						}
					}
				}	
				fprintf(out,"\n");
			}
			
			//m=3
			/*for(dLauf[1]=3; dLauf[1]<= 70; dLauf[1]++)//n
			{
				for(dLauf[2]=1; dLauf[2]<= (70-1)/2; dLauf[2]++)//k1
				{
					for(dLauf[3]=1+dLauf[2]-1; dLauf[3]<= 2+dLauf[2]-1; dLauf[3]++)//k2
					{
						for(dLauf[4]=1; dLauf[4]<= 70-1; dLauf[4]++)//k3
						{	
							if(dLauf[1]-dLauf[4]>0)
							if(dLauf[2]+dLauf[3]+(dLauf[1]-dLauf[4])==dLauf[1])//k1+k2+k3=n
							{
																						vektor[1]=dLauf[1];
																						vektor[2]=dLauf[2];
																						vektor[3]=dLauf[3];
																						vektor[4]=dLauf[1]-dLauf[4];
								if(dLauf[2]<=dLauf[3])fprintf(out,"(%.0f,%.0f,%.0f) ", dLauf[2],dLauf[3],dLauf[1]-dLauf[4]); //fprintf(out,"%.0f ", permutation_k(vektor, 3+1))
							}
						}
					}
				}	
				fprintf(out,"\n");
			}
		
			// m=2
			for(dLauf[1]=1; dLauf[1]<= 70; dLauf[1]++)//n
			{
				for(dLauf[2]=1; dLauf[2]<= 69; dLauf[2]++)//k1
				{
					for(dLauf[3]=1; dLauf[3]<= 69; dLauf[3]++)//k2
					{
						if(dLauf[2]+dLauf[3]==dLauf[1])//k1+k2=n
						if(dLauf[2]<=dLauf[3])fprintf(out,"(%.0f,%.0f) ", dLauf[2],dLauf[3]); //fprintf(out,"%.0f ", permutation_k(dLauf, 2+1))
					}
				}	
				fprintf(out,"\n");
			}*/
		}
	}
	
	// wP allgemein
	if(wert[1]!=99)
	if(wert[1]<8 || wert[1] >12 )
	while(1)
	{
		for(Lauf[1]=1; Lauf[1]<= n_; Lauf[1]++) // allgemeine index generierung 1 - n_
		{				
			if(Lauf[1]==1)
			 
				pLauf[1]++;
		
			if(Lauf[1]==n_ && pLauf[Lauf[1]] > n_ ) break;
			
			if( pLauf[Lauf[1]]> n_) 
			{ 
				pLauf[Lauf[1]] = 1;
				pLauf[Lauf[1]+1] += 1;	
			}			
		}
		
		// endkriterium
		if(Lauf[1]==n_ && pLauf[Lauf[1]] > n_ ) break;
		
		// elementwiederholungsprüfung
		        if( sw==0 )	    
		        for(Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++)
			                    for(Lauf[2]=Lauf[1]+1; Lauf[2]<=n_; Lauf[2]++) 
		if( ( pLauf[Lauf[1]]==pLauf[Lauf[2]] ) ) {sw=1; break;}  

		// anordnungswiederholungsprüfung innerhalb der klassen
		if( sw==0 )
		{
			for(Lauf[3]=1; Lauf[3]<=k; Lauf[3]++)
			{
					  if( sw==0 )
			          for(Lauf[1]=1; Lauf[1]<= k_[Lauf[3]]; Lauf[1]++)
										for(Lauf[2]=Lauf[1]+1; Lauf[2]<=k_[Lauf[3]]; Lauf[2]++) 
			  if( ( pLauf[Lauf[1]+i_]>pLauf[Lauf[2]+i_] ) ) {sw=1;break;}
			  i_+=k_[Lauf[3]];
			}
			i_=0;
		}

		if( sw==0 ) // dateiausgabe des Permutationsvektors  
		{
			for(Lauf[3]=1; Lauf[3]<= k; Lauf[3]++)
			{
				for(Lauf[1]=1; Lauf[1]<= k_[Lauf[3]]; Lauf[1]++) fprintf(out,"%i ", pLauf[Lauf[1]+i_]); 
				fprintf(out,"   ");//
				i_+=k_[Lauf[3]];
			}
			fprintf(out,"\n");
			i_=0;
			
			zlr++;
		}
		sw=0;
	}	 

	if(n_>=7)printf("\r                                                                           \r ");

	fn_erg=zlr;

	fclose(out);

	return 0;
};
 
double fn_grs_4(double wert[100] ) // vollständige Kombinationsmatrizen //  
//                                                                      // Kombination  C ohne Wh von n zu m (1) FN4 1, 3,2  
//                                                                      // Kombination wC  mit Wh von n zu m (2) FN4 2, 3,2
//                                                                      // Variation    V ohne Wh von n zu m (3) FN4 3, 3,2
//                                                                      // Variation   wV  mit Wh von n zu m (4) FN4 4, 3,2
//                                                                      // Permutation  P zu 1 Kl n          (5) FN4 5, 3,0
//                                                                      // Permutation wP zu 2 Kl k1+k2=n    (6) FN4 6, 3,1,2 
{
	FILE *out;
	
	int iLauf, Lauf[100], vLauf[100], sw=0;	       
	double  n_, m_, zlr=0, wp[100], cmb;

	n_=wert[2];
	m_=wert[3];

	if(wert[1]==1 && n_<m_){printf("\n\ndesign.0 'n<m'"); exit(0);} //C n<m
	if(wert[1]<=2 && m_>16){printf("\n\nfile.0 'm>16'");  exit(0);} //C, wC begrenzt auf m<=16
	if(wert[1]==3 && n_<m_){printf("\n\ndesign.0 'n<m'"); exit(0);} //V n<m
	if(wert[1]==3 && m_>8) {printf("\n\nfile.0 'm>8'");   exit(0);} //V  begrenzt auf m<=8
	if(wert[1]==4 && m_>16){printf("\n\nfile.0 'm>16'");  exit(0);} //wV begrenzt auf m<=16
	
	// dateilänge begrenzt auf zln<66000
	if(wert[1]==1){cmb=kombination_(n_,m_);if(cmb>66000) {printf("\n\nfile.0 'C=%.0f>66000'", cmb);  exit(0);} } //C 
	if(wert[1]==2){cmb=kombination_w(n_,m_);if(cmb>66000){printf("\n\nfile.0 'wC=%.0f>66000'", cmb); exit(0);} } //wC 
	if(wert[1]==3){cmb=variation_(n_,m_);if(cmb>66000)   {printf("\n\nfile.0 'V=%.0f>66000'", cmb);  exit(0);} } //V 
	if(wert[1]==4){cmb=pow(n_,m_);if(cmb>66000)          {printf("\n\nfile.0 'wV=%.0f>66000'", cmb); exit(0);} } //wV 

	//Permutation P als Variation V von n zu n
	if(wert[1]==5) m_=n_; 
	if(wert[1]==5 && n_>8) {printf("\n\nfile.0 'n>8'"); exit(0);} //P begrenzt auf n<=8
	
	//Permutation wP(2) als Kombination C von k1+k2=n zu k1
	if(wert[1]==6) if(m_>wert[4]) m_=wert[4]; //m= kmin
	                                
	                                  wp[1]=n_;
	                                  wp[2]=m_;
	                                  wp[3]=n_-m_;								 
	if(wert[1]==6){ cmb=permutation_k(wp,2+1);if(cmb>66000)  {printf("\n\nfile.0 'wP=%.0f>66000'", cmb);  exit(0);} } //wP 

	
	for(Lauf[1]=1; Lauf[1]<=100; Lauf[1]++) vLauf[Lauf[1]]= 1; // 
	
	vLauf[1]=0;

	out=fopen( "fx.txt", "w" );

	if(wert[1]<=2 )               printf("\n\ncomputing ci(xj) ..."); //C, wC
	if(wert[1]==3 || wert[1]==4 ) printf("\n\ncomputing vi(xj) ..."); //V, wV
	if(wert[1]==5 && wert[2]==8)  printf("\n\ncomputing pi(xj) ..."); //P
	if(wert[1]==6  )              printf("\n\ncomputing pi(xj) ..."); //wP

	// Kombination C, wC, explizit
	if( wert[1]<=2 && wert[3] >=5 ||
		wert[1]==6 &&      m_ >=5  )
		
	{
		//------------------------------------------------------------------------------------------- C,wC,wP m=5 //
		if(m_==5)
		{
			// C, wC
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			
				// C, wP
				// elementwiederholungsfilter explizit
				if(wert[1]==1 || wert[1]==6)
				{
					if (Lauf[1]==Lauf[2]) break;
					if (Lauf[1]==Lauf[3]) break;
					if (Lauf[1]==Lauf[4]) break;
					if (Lauf[1]==Lauf[5]) break;
					if (Lauf[2]==Lauf[3]) break;
					if (Lauf[2]==Lauf[4]) break;
					if (Lauf[2]==Lauf[5]) break;
					if (Lauf[3]==Lauf[4]) break;
					if (Lauf[3]==Lauf[5]) break;
					if (Lauf[4]==Lauf[5]) break;
				}
				
				// C, wC
				if(wert[1]!=6){for(iLauf=1; iLauf<= 5; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");}
				
				// wP
				if(wert[1]==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%i ", Lauf[vLauf[1]]);fprintf(out," ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%i ", vLauf[1]);//k2
						    sw=0;
					}
					fprintf(out,"\n");
				}
			
				zlr++;

			// anordnungswiederholungsfilter explizit
			 
			 if(Lauf[5]==Lauf[4]) break;
			}if(Lauf[4]==Lauf[3]) break;//5
			}if(Lauf[3]==Lauf[2]) break;//4
			}if(Lauf[2]==Lauf[1]) break;//3
			}//2
			}//1
		}

		//---------------------------------------------------------------------------------------------- C,wC m=6 //
		if(m_==6)
		{
			// C, wC
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			
				// C, wP
				// elementwiederholungsfilter explizit
				if(wert[1]==1 || wert[1]==6)
				{
					if (Lauf[1]==Lauf[2]) break;
					if (Lauf[1]==Lauf[3]) break;
					if (Lauf[1]==Lauf[4]) break;
					if (Lauf[1]==Lauf[5]) break;
					if (Lauf[1]==Lauf[6]) break;
					if (Lauf[2]==Lauf[3]) break;
					if (Lauf[2]==Lauf[4]) break;
					if (Lauf[2]==Lauf[5]) break;
					if (Lauf[2]==Lauf[6]) break;
					if (Lauf[3]==Lauf[4]) break;
					if (Lauf[3]==Lauf[5]) break;
					if (Lauf[3]==Lauf[6]) break;
					if (Lauf[4]==Lauf[5]) break;
					if (Lauf[4]==Lauf[6]) break;
					if (Lauf[5]==Lauf[6]) break;
				}
				
				// C, wC
				if(wert[1]!=6){for(iLauf=1; iLauf<= 6; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");}

				// wP
				if(wert[1]==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%i ", Lauf[vLauf[1]]);fprintf(out," ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%i ", vLauf[1]);//k2
						    sw=0;
					}
					fprintf(out,"\n");
				}
				
				zlr++;

			// anordnungswiederholungsfilter explizit
			 
			 if(Lauf[6]==Lauf[5]) break;
			}if(Lauf[5]==Lauf[4]) break;//6
			}if(Lauf[4]==Lauf[3]) break;//5
			}if(Lauf[3]==Lauf[2]) break;//4
			}if(Lauf[2]==Lauf[1]) break;//3
			}//2
			}//1
		}
		
		//---------------------------------------------------------------------------------------------- C,wC m=7 //
		if(m_==7)
		{
			// C, wC
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			
				// C, wP
				// elementwiederholungsfilter explizit
				if(wert[1]==1 || wert[1]==6)
				{
					if (Lauf[1]==Lauf[2]) break;
					if (Lauf[1]==Lauf[3]) break;
					if (Lauf[1]==Lauf[4]) break;
					if (Lauf[1]==Lauf[5]) break;
					if (Lauf[1]==Lauf[6]) break;
					if (Lauf[1]==Lauf[7]) break;
					if (Lauf[2]==Lauf[3]) break;
					if (Lauf[2]==Lauf[4]) break;
					if (Lauf[2]==Lauf[5]) break;
					if (Lauf[2]==Lauf[6]) break;
					if (Lauf[2]==Lauf[7]) break;
					if (Lauf[3]==Lauf[4]) break;
					if (Lauf[3]==Lauf[5]) break;
					if (Lauf[3]==Lauf[6]) break;
					if (Lauf[3]==Lauf[7]) break;
					if (Lauf[4]==Lauf[5]) break;
					if (Lauf[4]==Lauf[6]) break;
					if (Lauf[4]==Lauf[7]) break;
					if (Lauf[5]==Lauf[6]) break;
					if (Lauf[5]==Lauf[7]) break;
					if (Lauf[6]==Lauf[7]) break;
				}
				
				// C, wC
				if(wert[1]!=6){for(iLauf=1; iLauf<= 7; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");}
				
				// wP
				if(wert[1]==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%i ", Lauf[vLauf[1]]);fprintf(out," ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%i ", vLauf[1]);//k2
						    sw=0;
					}
					fprintf(out,"\n");
				}

				zlr++;

			// anordnungswiederholungsfilter explizit
			 
		     if(Lauf[7]==Lauf[6]) break;
			}if(Lauf[6]==Lauf[5]) break;//7
			}if(Lauf[5]==Lauf[4]) break;//6
			}if(Lauf[4]==Lauf[3]) break;//5
			}if(Lauf[3]==Lauf[2]) break;//4
			}if(Lauf[2]==Lauf[1]) break;//3
			}//2
			}//1
		}

		//---------------------------------------------------------------------------------------------- C,wC m=8 //
		if(m_==8)
		{
			// C, wC
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			
				// C, wP
				// elementwiederholungsfilter explizit
				if(wert[1]==1 || wert[1]==6)
				{
					if (Lauf[1]==Lauf[2]) break;
					if (Lauf[1]==Lauf[3]) break;
					if (Lauf[1]==Lauf[4]) break;
					if (Lauf[1]==Lauf[5]) break;
					if (Lauf[1]==Lauf[6]) break;
					if (Lauf[1]==Lauf[7]) break;
					if (Lauf[1]==Lauf[8]) break;
					if (Lauf[2]==Lauf[3]) break;
					if (Lauf[2]==Lauf[4]) break;
					if (Lauf[2]==Lauf[5]) break;
					if (Lauf[2]==Lauf[6]) break;
					if (Lauf[2]==Lauf[7]) break;
					if (Lauf[2]==Lauf[8]) break;
					if (Lauf[3]==Lauf[4]) break;
					if (Lauf[3]==Lauf[5]) break;
					if (Lauf[3]==Lauf[6]) break;
					if (Lauf[3]==Lauf[7]) break;
					if (Lauf[3]==Lauf[8]) break;
					if (Lauf[4]==Lauf[5]) break;
					if (Lauf[4]==Lauf[6]) break;
					if (Lauf[4]==Lauf[7]) break;
					if (Lauf[4]==Lauf[8]) break;
					if (Lauf[5]==Lauf[6]) break;
					if (Lauf[5]==Lauf[7]) break;
					if (Lauf[5]==Lauf[8]) break;
					if (Lauf[6]==Lauf[7]) break;
					if (Lauf[6]==Lauf[8]) break;
					if (Lauf[7]==Lauf[8]) break;

				}
				
				// C, wC
				if(wert[1]!=6){for(iLauf=1; iLauf<= 8; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");}

				// wP
				if(wert[1]==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%i ", Lauf[vLauf[1]]);fprintf(out," ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%i ", vLauf[1]);//k2
						    sw=0;
					}
					fprintf(out,"\n");
				}
				
				zlr++;

			// anordnungswiederholungsfilter explizit
			 
			 if(Lauf[8]==Lauf[7]) break;
			}if(Lauf[7]==Lauf[6]) break;//8
			}if(Lauf[6]==Lauf[5]) break;//7
			}if(Lauf[5]==Lauf[4]) break;//6
			}if(Lauf[4]==Lauf[3]) break;//5
			}if(Lauf[3]==Lauf[2]) break;//4
			}if(Lauf[2]==Lauf[1]) break;//3
			}//2
			}//1
		}

		//---------------------------------------------------------------------------------------------- C,wC m=9 //
		if(m_==9)
		{
			// C, wC
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){
			
				// C, wP
				// elementwiederholungsfilter explizit
				if(wert[1]==1 || wert[1]==6)
				{
					if (Lauf[1]==Lauf[2]) break;
					if (Lauf[1]==Lauf[3]) break;
					if (Lauf[1]==Lauf[4]) break;
					if (Lauf[1]==Lauf[5]) break;
					if (Lauf[1]==Lauf[6]) break;
					if (Lauf[1]==Lauf[7]) break;
					if (Lauf[1]==Lauf[8]) break;
					if (Lauf[1]==Lauf[9]) break;
					if (Lauf[2]==Lauf[3]) break;
					if (Lauf[2]==Lauf[4]) break;
					if (Lauf[2]==Lauf[5]) break;
					if (Lauf[2]==Lauf[6]) break;
					if (Lauf[2]==Lauf[7]) break;
					if (Lauf[2]==Lauf[8]) break;
					if (Lauf[2]==Lauf[9]) break;
					if (Lauf[3]==Lauf[4]) break;
					if (Lauf[3]==Lauf[5]) break;
					if (Lauf[3]==Lauf[6]) break;
					if (Lauf[3]==Lauf[7]) break;
					if (Lauf[3]==Lauf[8]) break;
					if (Lauf[3]==Lauf[9]) break;
					if (Lauf[4]==Lauf[5]) break;
					if (Lauf[4]==Lauf[6]) break;
					if (Lauf[4]==Lauf[7]) break;
					if (Lauf[4]==Lauf[8]) break;
					if (Lauf[4]==Lauf[9]) break;
					if (Lauf[5]==Lauf[6]) break;
					if (Lauf[5]==Lauf[7]) break;
					if (Lauf[5]==Lauf[8]) break;
					if (Lauf[5]==Lauf[9]) break;
					if (Lauf[6]==Lauf[7]) break;
					if (Lauf[6]==Lauf[8]) break;
					if (Lauf[6]==Lauf[9]) break;
					if (Lauf[7]==Lauf[8]) break;
					if (Lauf[7]==Lauf[9]) break;
					if (Lauf[8]==Lauf[9]) break;
				}
				
				// C, wC
				if(wert[1]!=6){for(iLauf=1; iLauf<= 9; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");}

				// wP
				if(wert[1]==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%i ", Lauf[vLauf[1]]);fprintf(out," ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%i ", vLauf[1]);//k2
						    sw=0;
					}
					fprintf(out,"\n");
				}
					
				zlr++;

			// anordnungswiederholungsfilter explizit
			 if(Lauf[9]==Lauf[8]) break;
			}if(Lauf[8]==Lauf[7]) break;//9
			}if(Lauf[7]==Lauf[6]) break;//8
			}if(Lauf[6]==Lauf[5]) break;//7
			}if(Lauf[5]==Lauf[4]) break;//6
			}if(Lauf[4]==Lauf[3]) break;//5
			}if(Lauf[3]==Lauf[2]) break;//4
			}if(Lauf[2]==Lauf[1]) break;//3
			}//2
			}//1
		}

		//---------------------------------------------------------------------------------------------- C,wC m=10 //
		if(m_==10)
		{
			// C, wC
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){
			for (Lauf[10]=1; Lauf[10]<=n_; Lauf[10]++){
			
				// C, wP
				// elementwiederholungsfilter explizit
				if(wert[1]==1 || wert[1]==6)
				{
					if (Lauf[1]==Lauf[2]) break;
					if (Lauf[1]==Lauf[3]) break;
					if (Lauf[1]==Lauf[4]) break;
					if (Lauf[1]==Lauf[5]) break;
					if (Lauf[1]==Lauf[6]) break;
					if (Lauf[1]==Lauf[7]) break;
					if (Lauf[1]==Lauf[8]) break;
					if (Lauf[1]==Lauf[9]) break;
					if (Lauf[1]==Lauf[10]) break;
					if (Lauf[2]==Lauf[3]) break;
					if (Lauf[2]==Lauf[4]) break;
					if (Lauf[2]==Lauf[5]) break;
					if (Lauf[2]==Lauf[6]) break;
					if (Lauf[2]==Lauf[7]) break;
					if (Lauf[2]==Lauf[8]) break;
					if (Lauf[2]==Lauf[9]) break;
					if (Lauf[2]==Lauf[10]) break;
					if (Lauf[3]==Lauf[4]) break;
					if (Lauf[3]==Lauf[5]) break;
					if (Lauf[3]==Lauf[6]) break;
					if (Lauf[3]==Lauf[7]) break;
					if (Lauf[3]==Lauf[8]) break;
					if (Lauf[3]==Lauf[9]) break;
					if (Lauf[3]==Lauf[10]) break;
					if (Lauf[4]==Lauf[5]) break;
					if (Lauf[4]==Lauf[6]) break;
					if (Lauf[4]==Lauf[7]) break;
					if (Lauf[4]==Lauf[8]) break;
					if (Lauf[4]==Lauf[9]) break;
					if (Lauf[4]==Lauf[10]) break;
					if (Lauf[5]==Lauf[6]) break;
					if (Lauf[5]==Lauf[7]) break;
					if (Lauf[5]==Lauf[8]) break;
					if (Lauf[5]==Lauf[9]) break;
					if (Lauf[5]==Lauf[10]) break;
					if (Lauf[6]==Lauf[7]) break;
					if (Lauf[6]==Lauf[8]) break;
					if (Lauf[6]==Lauf[9]) break;
					if (Lauf[6]==Lauf[10]) break;
					if (Lauf[7]==Lauf[8]) break;
					if (Lauf[7]==Lauf[9]) break;
					if (Lauf[7]==Lauf[10]) break;
					if (Lauf[8]==Lauf[9]) break;
					if (Lauf[8]==Lauf[10]) break;
					if (Lauf[9]==Lauf[10]) break;
				}
				
				// C, wC
				if(wert[1]!=6){for(iLauf=1; iLauf<= 10; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");}

				// wP
				if(wert[1]==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%i ", Lauf[vLauf[1]]);fprintf(out," ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%i ", vLauf[1]);//k2
						    sw=0;
					}
					fprintf(out,"\n");
				}
				
				zlr++;

			// anordnungswiederholungsfilter explizit
			 if(Lauf[10]==Lauf[9]) break;
			}if(Lauf[9]==Lauf[8]) break;//10
			}if(Lauf[8]==Lauf[7]) break;//9
			}if(Lauf[7]==Lauf[6]) break;//8
			}if(Lauf[6]==Lauf[5]) break;//7
			}if(Lauf[5]==Lauf[4]) break;//6
			}if(Lauf[4]==Lauf[3]) break;//5
			}if(Lauf[3]==Lauf[2]) break;//4
			}if(Lauf[2]==Lauf[1]) break;//3
			}//2
			}//1
		}

		//---------------------------------------------------------------------------------------------- C,wC m=11 //
		if(m_==11)
		{
			// C, wC
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){
			for (Lauf[10]=1; Lauf[10]<=n_; Lauf[10]++){
			for (Lauf[11]=1; Lauf[11]<=n_; Lauf[11]++){
			
				// C, wP
				// elementwiederholungsfilter explizit
				if(wert[1]==1 || wert[1]==6)
				{
					if (Lauf[1]==Lauf[2]) break;
					if (Lauf[1]==Lauf[3]) break;
					if (Lauf[1]==Lauf[4]) break;
					if (Lauf[1]==Lauf[5]) break;
					if (Lauf[1]==Lauf[6]) break;
					if (Lauf[1]==Lauf[7]) break;
					if (Lauf[1]==Lauf[8]) break;
					if (Lauf[1]==Lauf[9]) break;
					if (Lauf[1]==Lauf[10]) break;
					if (Lauf[1]==Lauf[11]) break;
					if (Lauf[2]==Lauf[3]) break;
					if (Lauf[2]==Lauf[4]) break;
					if (Lauf[2]==Lauf[5]) break;
					if (Lauf[2]==Lauf[6]) break;
					if (Lauf[2]==Lauf[7]) break;
					if (Lauf[2]==Lauf[8]) break;
					if (Lauf[2]==Lauf[9]) break;
					if (Lauf[2]==Lauf[10]) break;
					if (Lauf[2]==Lauf[11]) break;
					if (Lauf[3]==Lauf[4]) break;
					if (Lauf[3]==Lauf[5]) break;
					if (Lauf[3]==Lauf[6]) break;
					if (Lauf[3]==Lauf[7]) break;
					if (Lauf[3]==Lauf[8]) break;
					if (Lauf[3]==Lauf[9]) break;
					if (Lauf[3]==Lauf[10]) break;
					if (Lauf[3]==Lauf[11]) break;
					if (Lauf[4]==Lauf[5]) break;
					if (Lauf[4]==Lauf[6]) break;
					if (Lauf[4]==Lauf[7]) break;
					if (Lauf[4]==Lauf[8]) break;
					if (Lauf[4]==Lauf[9]) break;
					if (Lauf[4]==Lauf[10]) break;
					if (Lauf[4]==Lauf[11]) break;
					if (Lauf[5]==Lauf[6]) break;
					if (Lauf[5]==Lauf[7]) break;
					if (Lauf[5]==Lauf[8]) break;
					if (Lauf[5]==Lauf[9]) break;
					if (Lauf[5]==Lauf[10]) break;
					if (Lauf[5]==Lauf[11]) break;
					if (Lauf[6]==Lauf[7]) break;
					if (Lauf[6]==Lauf[8]) break;
					if (Lauf[6]==Lauf[9]) break;
					if (Lauf[6]==Lauf[10]) break;
					if (Lauf[6]==Lauf[11]) break;
					if (Lauf[7]==Lauf[8]) break;
					if (Lauf[7]==Lauf[9]) break;
					if (Lauf[7]==Lauf[10]) break;
					if (Lauf[7]==Lauf[11]) break;
					if (Lauf[8]==Lauf[9]) break;
					if (Lauf[8]==Lauf[10]) break;
					if (Lauf[8]==Lauf[11]) break;
					if (Lauf[9]==Lauf[10]) break;
					if (Lauf[9]==Lauf[11]) break;
					if (Lauf[10]==Lauf[11]) break;
				}
				
				// C, wC
				if(wert[1]!=6){for(iLauf=1; iLauf<= 11; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");}

				// wP
				if(wert[1]==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%i ", Lauf[vLauf[1]]);fprintf(out," ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%i ", vLauf[1]);//k2
						    sw=0;
					}
					fprintf(out,"\n");
				}
				
				zlr++;

			// anordnungswiederholungsfilter explizit
			 if(Lauf[11]==Lauf[10]) break;
			}if(Lauf[10]==Lauf[9]) break;//11
			}if(Lauf[9]==Lauf[8]) break;//10
			}if(Lauf[8]==Lauf[7]) break;//9
			}if(Lauf[7]==Lauf[6]) break;//8
			}if(Lauf[6]==Lauf[5]) break;//7
			}if(Lauf[5]==Lauf[4]) break;//6
			}if(Lauf[4]==Lauf[3]) break;//5
			}if(Lauf[3]==Lauf[2]) break;//4
			}if(Lauf[2]==Lauf[1]) break;//3
			}//2
			}//1
		}

		//---------------------------------------------------------------------------------------------- C,wC m=12 //
		if(m_==12)
		{
			// C, wC
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){
			for (Lauf[10]=1; Lauf[10]<=n_; Lauf[10]++){
			for (Lauf[11]=1; Lauf[11]<=n_; Lauf[11]++){
			for (Lauf[12]=1; Lauf[12]<=n_; Lauf[12]++){
			
				// C, wP
				// elementwiederholungsfilter explizit
				if(wert[1]==1 || wert[1]==6)
				{
					if (Lauf[1]==Lauf[2]) break;
					if (Lauf[1]==Lauf[3]) break;
					if (Lauf[1]==Lauf[4]) break;
					if (Lauf[1]==Lauf[5]) break;
					if (Lauf[1]==Lauf[6]) break;
					if (Lauf[1]==Lauf[7]) break;
					if (Lauf[1]==Lauf[8]) break;
					if (Lauf[1]==Lauf[9]) break;
					if (Lauf[1]==Lauf[10]) break;
					if (Lauf[1]==Lauf[11]) break;
					if (Lauf[1]==Lauf[12]) break;
					if (Lauf[2]==Lauf[3]) break;
					if (Lauf[2]==Lauf[4]) break;
					if (Lauf[2]==Lauf[5]) break;
					if (Lauf[2]==Lauf[6]) break;
					if (Lauf[2]==Lauf[7]) break;
					if (Lauf[2]==Lauf[8]) break;
					if (Lauf[2]==Lauf[9]) break;
					if (Lauf[2]==Lauf[10]) break;
					if (Lauf[2]==Lauf[11]) break;
					if (Lauf[2]==Lauf[12]) break;
					if (Lauf[3]==Lauf[4]) break;
					if (Lauf[3]==Lauf[5]) break;
					if (Lauf[3]==Lauf[6]) break;
					if (Lauf[3]==Lauf[7]) break;
					if (Lauf[3]==Lauf[8]) break;
					if (Lauf[3]==Lauf[9]) break;
					if (Lauf[3]==Lauf[10]) break;
					if (Lauf[3]==Lauf[11]) break;
					if (Lauf[3]==Lauf[12]) break;
					if (Lauf[4]==Lauf[5]) break;
					if (Lauf[4]==Lauf[6]) break;
					if (Lauf[4]==Lauf[7]) break;
					if (Lauf[4]==Lauf[8]) break;
					if (Lauf[4]==Lauf[9]) break;
					if (Lauf[4]==Lauf[10]) break;
					if (Lauf[4]==Lauf[11]) break;
					if (Lauf[4]==Lauf[12]) break;
					if (Lauf[5]==Lauf[6]) break;
					if (Lauf[5]==Lauf[7]) break;
					if (Lauf[5]==Lauf[8]) break;
					if (Lauf[5]==Lauf[9]) break;
					if (Lauf[5]==Lauf[10]) break;
					if (Lauf[5]==Lauf[11]) break;
					if (Lauf[5]==Lauf[12]) break;
					if (Lauf[6]==Lauf[7]) break;
					if (Lauf[6]==Lauf[8]) break;
					if (Lauf[6]==Lauf[9]) break;
					if (Lauf[6]==Lauf[10]) break;
					if (Lauf[6]==Lauf[11]) break;
					if (Lauf[6]==Lauf[12]) break;
					if (Lauf[7]==Lauf[8]) break;
					if (Lauf[7]==Lauf[9]) break;
					if (Lauf[7]==Lauf[10]) break;
					if (Lauf[7]==Lauf[11]) break;
					if (Lauf[7]==Lauf[12]) break;
					if (Lauf[8]==Lauf[9]) break;
					if (Lauf[8]==Lauf[10]) break;
					if (Lauf[8]==Lauf[11]) break;
					if (Lauf[8]==Lauf[12]) break;
					if (Lauf[9]==Lauf[10]) break;
					if (Lauf[9]==Lauf[11]) break;
					if (Lauf[9]==Lauf[12]) break;
					if (Lauf[10]==Lauf[11]) break;
					if (Lauf[10]==Lauf[12]) break;
					if (Lauf[11]==Lauf[12]) break;
				}
				
				// C, wC
				if(wert[1]!=6){for(iLauf=1; iLauf<= 12; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");}

				// wP
				if(wert[1]==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%i ", Lauf[vLauf[1]]);fprintf(out," ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%i ", vLauf[1]);//k2
						    sw=0;
					}
					fprintf(out,"\n");
				}
					
				zlr++;

			// anordnungswiederholungsfilter explizit
			 if(Lauf[12]==Lauf[11]) break;
			}if(Lauf[11]==Lauf[10]) break;//12
			}if(Lauf[10]==Lauf[9]) break;//11
			}if(Lauf[9]==Lauf[8]) break;//10
			}if(Lauf[8]==Lauf[7]) break;//9
			}if(Lauf[7]==Lauf[6]) break;//8
			}if(Lauf[6]==Lauf[5]) break;//7
			}if(Lauf[5]==Lauf[4]) break;//6
			}if(Lauf[4]==Lauf[3]) break;//5
			}if(Lauf[3]==Lauf[2]) break;//4
			}if(Lauf[2]==Lauf[1]) break;//3
			}//2
			}//1
		}
	
		//---------------------------------------------------------------------------------------------- C,wC m=13 //
		if(m_==13)
		{
			// C, wC
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){
			for (Lauf[10]=1; Lauf[10]<=n_; Lauf[10]++){
			for (Lauf[11]=1; Lauf[11]<=n_; Lauf[11]++){
			for (Lauf[12]=1; Lauf[12]<=n_; Lauf[12]++){
			for (Lauf[13]=1; Lauf[13]<=n_; Lauf[13]++){
			
				// C, wP
				// elementwiederholungsfilter explizit
				if(wert[1]==1 || wert[1]==6)
				{
					if (Lauf[1]==Lauf[2]) break;
					if (Lauf[1]==Lauf[3]) break;
					if (Lauf[1]==Lauf[4]) break;
					if (Lauf[1]==Lauf[5]) break;
					if (Lauf[1]==Lauf[6]) break;
					if (Lauf[1]==Lauf[7]) break;
					if (Lauf[1]==Lauf[8]) break;
					if (Lauf[1]==Lauf[9]) break;
					if (Lauf[1]==Lauf[10]) break;
					if (Lauf[1]==Lauf[11]) break;
					if (Lauf[1]==Lauf[12]) break;
					if (Lauf[1]==Lauf[13]) break;
					if (Lauf[2]==Lauf[3]) break;
					if (Lauf[2]==Lauf[4]) break;
					if (Lauf[2]==Lauf[5]) break;
					if (Lauf[2]==Lauf[6]) break;
					if (Lauf[2]==Lauf[7]) break;
					if (Lauf[2]==Lauf[8]) break;
					if (Lauf[2]==Lauf[9]) break;
					if (Lauf[2]==Lauf[10]) break;
					if (Lauf[2]==Lauf[11]) break;
					if (Lauf[2]==Lauf[12]) break;
					if (Lauf[2]==Lauf[13]) break;
					if (Lauf[3]==Lauf[4]) break;
					if (Lauf[3]==Lauf[5]) break;
					if (Lauf[3]==Lauf[6]) break;
					if (Lauf[3]==Lauf[7]) break;
					if (Lauf[3]==Lauf[8]) break;
					if (Lauf[3]==Lauf[9]) break;
					if (Lauf[3]==Lauf[10]) break;
					if (Lauf[3]==Lauf[11]) break;
					if (Lauf[3]==Lauf[12]) break;
					if (Lauf[3]==Lauf[13]) break;
					if (Lauf[4]==Lauf[5]) break;
					if (Lauf[4]==Lauf[6]) break;
					if (Lauf[4]==Lauf[7]) break;
					if (Lauf[4]==Lauf[8]) break;
					if (Lauf[4]==Lauf[9]) break;
					if (Lauf[4]==Lauf[10]) break;
					if (Lauf[4]==Lauf[11]) break;
					if (Lauf[4]==Lauf[12]) break;
					if (Lauf[4]==Lauf[13]) break;
					if (Lauf[5]==Lauf[6]) break;
					if (Lauf[5]==Lauf[7]) break;
					if (Lauf[5]==Lauf[8]) break;
					if (Lauf[5]==Lauf[9]) break;
					if (Lauf[5]==Lauf[10]) break;
					if (Lauf[5]==Lauf[11]) break;
					if (Lauf[5]==Lauf[12]) break;
					if (Lauf[5]==Lauf[13]) break;
					if (Lauf[6]==Lauf[7]) break;
					if (Lauf[6]==Lauf[8]) break;
					if (Lauf[6]==Lauf[9]) break;
					if (Lauf[6]==Lauf[10]) break;
					if (Lauf[6]==Lauf[11]) break;
					if (Lauf[6]==Lauf[12]) break;
					if (Lauf[6]==Lauf[13]) break;
					if (Lauf[7]==Lauf[8]) break;
					if (Lauf[7]==Lauf[9]) break;
					if (Lauf[7]==Lauf[10]) break;
					if (Lauf[7]==Lauf[11]) break;
					if (Lauf[7]==Lauf[12]) break;
					if (Lauf[7]==Lauf[13]) break;
					if (Lauf[8]==Lauf[9]) break;
					if (Lauf[8]==Lauf[10]) break;
					if (Lauf[8]==Lauf[11]) break;
					if (Lauf[8]==Lauf[12]) break;
					if (Lauf[8]==Lauf[13]) break;
					if (Lauf[9]==Lauf[10]) break;
					if (Lauf[9]==Lauf[11]) break;
					if (Lauf[9]==Lauf[12]) break;
					if (Lauf[9]==Lauf[13]) break;
					if (Lauf[10]==Lauf[11]) break;
					if (Lauf[10]==Lauf[12]) break;
					if (Lauf[10]==Lauf[13]) break;
					if (Lauf[11]==Lauf[12]) break;
					if (Lauf[11]==Lauf[13]) break;
					if (Lauf[12]==Lauf[13]) break;
				}
				
				// C, wC
				if(wert[1]!=6){for(iLauf=1; iLauf<= 13; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");}

				// wP
				if(wert[1]==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%i ", Lauf[vLauf[1]]);fprintf(out," ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%i ", vLauf[1]);//k2
						    sw=0;
					}
					fprintf(out,"\n");
				}
					
				zlr++;

			// anordnungswiederholungsfilter explizit
			 if(Lauf[13]==Lauf[12]) break;
			}if(Lauf[12]==Lauf[11]) break;//13
			}if(Lauf[11]==Lauf[10]) break;//12
			}if(Lauf[10]==Lauf[9]) break;//11
			}if(Lauf[9]==Lauf[8]) break;//10
			}if(Lauf[8]==Lauf[7]) break;//9
			}if(Lauf[7]==Lauf[6]) break;//8
			}if(Lauf[6]==Lauf[5]) break;//7
			}if(Lauf[5]==Lauf[4]) break;//6
			}if(Lauf[4]==Lauf[3]) break;//5
			}if(Lauf[3]==Lauf[2]) break;//4
			}if(Lauf[2]==Lauf[1]) break;//3
			}//2
			}//1
		}
		//---------------------------------------------------------------------------------------------- C,wC m=14 //
		if(m_==14)
		{
			// C, wC
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){
			for (Lauf[10]=1; Lauf[10]<=n_; Lauf[10]++){
			for (Lauf[11]=1; Lauf[11]<=n_; Lauf[11]++){
			for (Lauf[12]=1; Lauf[12]<=n_; Lauf[12]++){
			for (Lauf[13]=1; Lauf[13]<=n_; Lauf[13]++){
			for (Lauf[14]=1; Lauf[14]<=n_; Lauf[14]++){
			
				// C, wP
				// elementwiederholungsfilter explizit
				if(wert[1]==1 || wert[1]==6)
				{
					if (Lauf[1]==Lauf[2]) break;
					if (Lauf[1]==Lauf[3]) break;
					if (Lauf[1]==Lauf[4]) break;
					if (Lauf[1]==Lauf[5]) break;
					if (Lauf[1]==Lauf[6]) break;
					if (Lauf[1]==Lauf[7]) break;
					if (Lauf[1]==Lauf[8]) break;
					if (Lauf[1]==Lauf[9]) break;
					if (Lauf[1]==Lauf[10]) break;
					if (Lauf[1]==Lauf[11]) break;
					if (Lauf[1]==Lauf[12]) break;
					if (Lauf[1]==Lauf[13]) break;
					if (Lauf[1]==Lauf[14]) break;
					if (Lauf[2]==Lauf[3]) break;
					if (Lauf[2]==Lauf[4]) break;
					if (Lauf[2]==Lauf[5]) break;
					if (Lauf[2]==Lauf[6]) break;
					if (Lauf[2]==Lauf[7]) break;
					if (Lauf[2]==Lauf[8]) break;
					if (Lauf[2]==Lauf[9]) break;
					if (Lauf[2]==Lauf[10]) break;
					if (Lauf[2]==Lauf[11]) break;
					if (Lauf[2]==Lauf[12]) break;
					if (Lauf[2]==Lauf[13]) break;
					if (Lauf[2]==Lauf[14]) break;
					if (Lauf[3]==Lauf[4]) break;
					if (Lauf[3]==Lauf[5]) break;
					if (Lauf[3]==Lauf[6]) break;
					if (Lauf[3]==Lauf[7]) break;
					if (Lauf[3]==Lauf[8]) break;
					if (Lauf[3]==Lauf[9]) break;
					if (Lauf[3]==Lauf[10]) break;
					if (Lauf[3]==Lauf[11]) break;
					if (Lauf[3]==Lauf[12]) break;
					if (Lauf[3]==Lauf[13]) break;
					if (Lauf[3]==Lauf[14]) break;
					if (Lauf[4]==Lauf[5]) break;
					if (Lauf[4]==Lauf[6]) break;
					if (Lauf[4]==Lauf[7]) break;
					if (Lauf[4]==Lauf[8]) break;
					if (Lauf[4]==Lauf[9]) break;
					if (Lauf[4]==Lauf[10]) break;
					if (Lauf[4]==Lauf[11]) break;
					if (Lauf[4]==Lauf[12]) break;
					if (Lauf[4]==Lauf[13]) break;
					if (Lauf[4]==Lauf[14]) break;
					if (Lauf[5]==Lauf[6]) break;
					if (Lauf[5]==Lauf[7]) break;
					if (Lauf[5]==Lauf[8]) break;
					if (Lauf[5]==Lauf[9]) break;
					if (Lauf[5]==Lauf[10]) break;
					if (Lauf[5]==Lauf[11]) break;
					if (Lauf[5]==Lauf[12]) break;
					if (Lauf[5]==Lauf[13]) break;
					if (Lauf[5]==Lauf[14]) break;
					if (Lauf[6]==Lauf[7]) break;
					if (Lauf[6]==Lauf[8]) break;
					if (Lauf[6]==Lauf[9]) break;
					if (Lauf[6]==Lauf[10]) break;
					if (Lauf[6]==Lauf[11]) break;
					if (Lauf[6]==Lauf[12]) break;
					if (Lauf[6]==Lauf[13]) break;
					if (Lauf[6]==Lauf[14]) break;
					if (Lauf[7]==Lauf[8]) break;
					if (Lauf[7]==Lauf[9]) break;
					if (Lauf[7]==Lauf[10]) break;
					if (Lauf[7]==Lauf[11]) break;
					if (Lauf[7]==Lauf[12]) break;
					if (Lauf[7]==Lauf[13]) break;
					if (Lauf[7]==Lauf[14]) break;
					if (Lauf[8]==Lauf[9]) break;
					if (Lauf[8]==Lauf[10]) break;
					if (Lauf[8]==Lauf[11]) break;
					if (Lauf[8]==Lauf[12]) break;
					if (Lauf[8]==Lauf[13]) break;
					if (Lauf[8]==Lauf[14]) break;
					if (Lauf[9]==Lauf[10]) break;
					if (Lauf[9]==Lauf[11]) break;
					if (Lauf[9]==Lauf[12]) break;
					if (Lauf[9]==Lauf[13]) break;
					if (Lauf[9]==Lauf[14]) break;
					if (Lauf[10]==Lauf[11]) break;
					if (Lauf[10]==Lauf[12]) break;
					if (Lauf[10]==Lauf[13]) break;
					if (Lauf[10]==Lauf[14]) break;
					if (Lauf[11]==Lauf[12]) break;
					if (Lauf[11]==Lauf[13]) break;
					if (Lauf[11]==Lauf[14]) break;
					if (Lauf[12]==Lauf[13]) break;
					if (Lauf[12]==Lauf[14]) break;
					if (Lauf[13]==Lauf[14]) break;
				}
				
				// C, wC
				if(wert[1]!=6){for(iLauf=1; iLauf<= 14; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");}

				// wP
				if(wert[1]==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%i ", Lauf[vLauf[1]]);fprintf(out," ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%i ", vLauf[1]);//k2
						    sw=0;
					}
					fprintf(out,"\n");
				}
				
				//printf("\r%.0f ",zlr);	
				zlr++;

			// anordnungswiederholungsfilter explizit
			 if(Lauf[14]==Lauf[13]) break;
			}if(Lauf[13]==Lauf[12]) break;//14
			}if(Lauf[12]==Lauf[11]) break;//13
			}if(Lauf[11]==Lauf[10]) break;//12
			}if(Lauf[10]==Lauf[9]) break;//11
			}if(Lauf[9]==Lauf[8]) break;//10
			}if(Lauf[8]==Lauf[7]) break;//9
			}if(Lauf[7]==Lauf[6]) break;//8
			}if(Lauf[6]==Lauf[5]) break;//7
			}if(Lauf[5]==Lauf[4]) break;//6
			}if(Lauf[4]==Lauf[3]) break;//5
			}if(Lauf[3]==Lauf[2]) break;//4
			}if(Lauf[2]==Lauf[1]) break;//3
			}//2
			}//1
		}

		//---------------------------------------------------------------------------------------------- C,wC m=15 //
		if(m_==15)
		{
			// C, wC
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){
			for (Lauf[10]=1; Lauf[10]<=n_; Lauf[10]++){
			for (Lauf[11]=1; Lauf[11]<=n_; Lauf[11]++){
			for (Lauf[12]=1; Lauf[12]<=n_; Lauf[12]++){
			for (Lauf[13]=1; Lauf[13]<=n_; Lauf[13]++){
			for (Lauf[14]=1; Lauf[14]<=n_; Lauf[14]++){
			for (Lauf[15]=1; Lauf[15]<=n_; Lauf[15]++){
			
				// C, wP
				// elementwiederholungsfilter explizit
				if(wert[1]==1 || wert[1]==6)
				{
					if (Lauf[1]==Lauf[2]) break;
					if (Lauf[1]==Lauf[3]) break;
					if (Lauf[1]==Lauf[4]) break;
					if (Lauf[1]==Lauf[5]) break;
					if (Lauf[1]==Lauf[6]) break;
					if (Lauf[1]==Lauf[7]) break;
					if (Lauf[1]==Lauf[8]) break;
					if (Lauf[1]==Lauf[9]) break;
					if (Lauf[1]==Lauf[10]) break;
					if (Lauf[1]==Lauf[11]) break;
					if (Lauf[1]==Lauf[12]) break;
					if (Lauf[1]==Lauf[13]) break;
					if (Lauf[1]==Lauf[14]) break;
					if (Lauf[1]==Lauf[15]) break;
					if (Lauf[2]==Lauf[3]) break;
					if (Lauf[2]==Lauf[4]) break;
					if (Lauf[2]==Lauf[5]) break;
					if (Lauf[2]==Lauf[6]) break;
					if (Lauf[2]==Lauf[7]) break;
					if (Lauf[2]==Lauf[8]) break;
					if (Lauf[2]==Lauf[9]) break;
					if (Lauf[2]==Lauf[10]) break;
					if (Lauf[2]==Lauf[11]) break;
					if (Lauf[2]==Lauf[12]) break;
					if (Lauf[2]==Lauf[13]) break;
					if (Lauf[2]==Lauf[14]) break;
					if (Lauf[2]==Lauf[15]) break;
					if (Lauf[3]==Lauf[4]) break;
					if (Lauf[3]==Lauf[5]) break;
					if (Lauf[3]==Lauf[6]) break;
					if (Lauf[3]==Lauf[7]) break;
					if (Lauf[3]==Lauf[8]) break;
					if (Lauf[3]==Lauf[9]) break;
					if (Lauf[3]==Lauf[10]) break;
					if (Lauf[3]==Lauf[11]) break;
					if (Lauf[3]==Lauf[12]) break;
					if (Lauf[3]==Lauf[13]) break;
					if (Lauf[3]==Lauf[14]) break;
					if (Lauf[3]==Lauf[15]) break;
					if (Lauf[4]==Lauf[5]) break;
					if (Lauf[4]==Lauf[6]) break;
					if (Lauf[4]==Lauf[7]) break;
					if (Lauf[4]==Lauf[8]) break;
					if (Lauf[4]==Lauf[9]) break;
					if (Lauf[4]==Lauf[10]) break;
					if (Lauf[4]==Lauf[11]) break;
					if (Lauf[4]==Lauf[12]) break;
					if (Lauf[4]==Lauf[13]) break;
					if (Lauf[4]==Lauf[14]) break;
					if (Lauf[4]==Lauf[15]) break;
					if (Lauf[5]==Lauf[6]) break;
					if (Lauf[5]==Lauf[7]) break;
					if (Lauf[5]==Lauf[8]) break;
					if (Lauf[5]==Lauf[9]) break;
					if (Lauf[5]==Lauf[10]) break;
					if (Lauf[5]==Lauf[11]) break;
					if (Lauf[5]==Lauf[12]) break;
					if (Lauf[5]==Lauf[13]) break;
					if (Lauf[5]==Lauf[14]) break;
					if (Lauf[5]==Lauf[15]) break;
					if (Lauf[6]==Lauf[7]) break;
					if (Lauf[6]==Lauf[8]) break;
					if (Lauf[6]==Lauf[9]) break;
					if (Lauf[6]==Lauf[10]) break;
					if (Lauf[6]==Lauf[11]) break;
					if (Lauf[6]==Lauf[12]) break;
					if (Lauf[6]==Lauf[13]) break;
					if (Lauf[6]==Lauf[14]) break;
					if (Lauf[6]==Lauf[15]) break;
					if (Lauf[7]==Lauf[8]) break;
					if (Lauf[7]==Lauf[9]) break;
					if (Lauf[7]==Lauf[10]) break;
					if (Lauf[7]==Lauf[11]) break;
					if (Lauf[7]==Lauf[12]) break;
					if (Lauf[7]==Lauf[13]) break;
					if (Lauf[7]==Lauf[14]) break;
					if (Lauf[7]==Lauf[15]) break;
					if (Lauf[8]==Lauf[9]) break;
					if (Lauf[8]==Lauf[10]) break;
					if (Lauf[8]==Lauf[11]) break;
					if (Lauf[8]==Lauf[12]) break;
					if (Lauf[8]==Lauf[13]) break;
					if (Lauf[8]==Lauf[14]) break;
					if (Lauf[8]==Lauf[15]) break;
					if (Lauf[9]==Lauf[10]) break;
					if (Lauf[9]==Lauf[11]) break;
					if (Lauf[9]==Lauf[12]) break;
					if (Lauf[9]==Lauf[13]) break;
					if (Lauf[9]==Lauf[14]) break;
					if (Lauf[9]==Lauf[15]) break;
					if (Lauf[10]==Lauf[11]) break;
					if (Lauf[10]==Lauf[12]) break;
					if (Lauf[10]==Lauf[13]) break;
					if (Lauf[10]==Lauf[14]) break;
					if (Lauf[10]==Lauf[15]) break;
					if (Lauf[11]==Lauf[12]) break;
					if (Lauf[11]==Lauf[13]) break;
					if (Lauf[11]==Lauf[14]) break;
					if (Lauf[11]==Lauf[15]) break;
					if (Lauf[12]==Lauf[13]) break;
					if (Lauf[12]==Lauf[14]) break;
					if (Lauf[12]==Lauf[15]) break;
					if (Lauf[13]==Lauf[14]) break;
					if (Lauf[13]==Lauf[15]) break;
					if (Lauf[14]==Lauf[15]) break;
				}
				
				// C, wC
				if(wert[1]!=6){for(iLauf=1; iLauf<= 15; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");}

				// wP
				if(wert[1]==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%i ", Lauf[vLauf[1]]);fprintf(out," ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%i ", vLauf[1]);//k2
						    sw=0;
					}
					fprintf(out,"\n");
				}

				//printf("\r%.0f ",zlr);	
				zlr++;

			// anordnungswiederholungsfilter explizit
			 if(Lauf[15]==Lauf[14]) break;
			}if(Lauf[14]==Lauf[13]) break;//15
			}if(Lauf[13]==Lauf[12]) break;//14
			}if(Lauf[12]==Lauf[11]) break;//13
			}if(Lauf[11]==Lauf[10]) break;//12
			}if(Lauf[10]==Lauf[9]) break;//11
			}if(Lauf[9]==Lauf[8]) break;//10
			}if(Lauf[8]==Lauf[7]) break;//9
			}if(Lauf[7]==Lauf[6]) break;//8
			}if(Lauf[6]==Lauf[5]) break;//7
			}if(Lauf[5]==Lauf[4]) break;//6
			}if(Lauf[4]==Lauf[3]) break;//5
			}if(Lauf[3]==Lauf[2]) break;//4
			}if(Lauf[2]==Lauf[1]) break;//3
			}//2
			}//1
		}

		//---------------------------------------------------------------------------------------------- C,wC m=16 //
		if(m_==16)
		{
			// C, wC
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){
			for (Lauf[10]=1; Lauf[10]<=n_; Lauf[10]++){
			for (Lauf[11]=1; Lauf[11]<=n_; Lauf[11]++){
			for (Lauf[12]=1; Lauf[12]<=n_; Lauf[12]++){
			for (Lauf[13]=1; Lauf[13]<=n_; Lauf[13]++){
			for (Lauf[14]=1; Lauf[14]<=n_; Lauf[14]++){
			for (Lauf[15]=1; Lauf[15]<=n_; Lauf[15]++){
			for (Lauf[16]=1; Lauf[16]<=n_; Lauf[16]++){
			
				// C, wP
				// elementwiederholungsfilter explizit
				if(wert[1]==1 || wert[1]==6)
				{
					if (Lauf[1]==Lauf[2]) break;
					if (Lauf[1]==Lauf[3]) break;
					if (Lauf[1]==Lauf[4]) break;
					if (Lauf[1]==Lauf[5]) break;
					if (Lauf[1]==Lauf[6]) break;
					if (Lauf[1]==Lauf[7]) break;
					if (Lauf[1]==Lauf[8]) break;
					if (Lauf[1]==Lauf[9]) break;
					if (Lauf[1]==Lauf[10]) break;
					if (Lauf[1]==Lauf[11]) break;
					if (Lauf[1]==Lauf[12]) break;
					if (Lauf[1]==Lauf[13]) break;
					if (Lauf[1]==Lauf[14]) break;
					if (Lauf[1]==Lauf[15]) break;
					if (Lauf[1]==Lauf[16]) break;
					if (Lauf[2]==Lauf[3]) break;
					if (Lauf[2]==Lauf[4]) break;
					if (Lauf[2]==Lauf[5]) break;
					if (Lauf[2]==Lauf[6]) break;
					if (Lauf[2]==Lauf[7]) break;
					if (Lauf[2]==Lauf[8]) break;
					if (Lauf[2]==Lauf[9]) break;
					if (Lauf[2]==Lauf[10]) break;
					if (Lauf[2]==Lauf[11]) break;
					if (Lauf[2]==Lauf[12]) break;
					if (Lauf[2]==Lauf[13]) break;
					if (Lauf[2]==Lauf[14]) break;
					if (Lauf[2]==Lauf[15]) break;
					if (Lauf[2]==Lauf[16]) break;
					if (Lauf[3]==Lauf[4]) break;
					if (Lauf[3]==Lauf[5]) break;
					if (Lauf[3]==Lauf[6]) break;
					if (Lauf[3]==Lauf[7]) break;
					if (Lauf[3]==Lauf[8]) break;
					if (Lauf[3]==Lauf[9]) break;
					if (Lauf[3]==Lauf[10]) break;
					if (Lauf[3]==Lauf[11]) break;
					if (Lauf[3]==Lauf[12]) break;
					if (Lauf[3]==Lauf[13]) break;
					if (Lauf[3]==Lauf[14]) break;
					if (Lauf[3]==Lauf[15]) break;
					if (Lauf[3]==Lauf[16]) break;
					if (Lauf[4]==Lauf[5]) break;
					if (Lauf[4]==Lauf[6]) break;
					if (Lauf[4]==Lauf[7]) break;
					if (Lauf[4]==Lauf[8]) break;
					if (Lauf[4]==Lauf[9]) break;
					if (Lauf[4]==Lauf[10]) break;
					if (Lauf[4]==Lauf[11]) break;
					if (Lauf[4]==Lauf[12]) break;
					if (Lauf[4]==Lauf[13]) break;
					if (Lauf[4]==Lauf[14]) break;
					if (Lauf[4]==Lauf[15]) break;
					if (Lauf[4]==Lauf[16]) break;
					if (Lauf[5]==Lauf[6]) break;
					if (Lauf[5]==Lauf[7]) break;
					if (Lauf[5]==Lauf[8]) break;
					if (Lauf[5]==Lauf[9]) break;
					if (Lauf[5]==Lauf[10]) break;
					if (Lauf[5]==Lauf[11]) break;
					if (Lauf[5]==Lauf[12]) break;
					if (Lauf[5]==Lauf[13]) break;
					if (Lauf[5]==Lauf[14]) break;
					if (Lauf[5]==Lauf[15]) break;
					if (Lauf[5]==Lauf[16]) break;
					if (Lauf[6]==Lauf[7]) break;
					if (Lauf[6]==Lauf[8]) break;
					if (Lauf[6]==Lauf[9]) break;
					if (Lauf[6]==Lauf[10]) break;
					if (Lauf[6]==Lauf[11]) break;
					if (Lauf[6]==Lauf[12]) break;
					if (Lauf[6]==Lauf[13]) break;
					if (Lauf[6]==Lauf[14]) break;
					if (Lauf[6]==Lauf[15]) break;
					if (Lauf[6]==Lauf[16]) break;
					if (Lauf[7]==Lauf[8]) break;
					if (Lauf[7]==Lauf[9]) break;
					if (Lauf[7]==Lauf[10]) break;
					if (Lauf[7]==Lauf[11]) break;
					if (Lauf[7]==Lauf[12]) break;
					if (Lauf[7]==Lauf[13]) break;
					if (Lauf[7]==Lauf[14]) break;
					if (Lauf[7]==Lauf[15]) break;
					if (Lauf[7]==Lauf[16]) break;
					if (Lauf[8]==Lauf[9]) break;
					if (Lauf[8]==Lauf[10]) break;
					if (Lauf[8]==Lauf[11]) break;
					if (Lauf[8]==Lauf[12]) break;
					if (Lauf[8]==Lauf[13]) break;
					if (Lauf[8]==Lauf[14]) break;
					if (Lauf[8]==Lauf[15]) break;
					if (Lauf[9]==Lauf[10]) break;
					if (Lauf[9]==Lauf[11]) break;
					if (Lauf[9]==Lauf[12]) break;
					if (Lauf[9]==Lauf[13]) break;
					if (Lauf[9]==Lauf[14]) break;
					if (Lauf[9]==Lauf[15]) break;
					if (Lauf[9]==Lauf[16]) break;
					if (Lauf[10]==Lauf[11]) break;
					if (Lauf[10]==Lauf[12]) break;
					if (Lauf[10]==Lauf[13]) break;
					if (Lauf[10]==Lauf[14]) break;
					if (Lauf[10]==Lauf[15]) break;
					if (Lauf[10]==Lauf[16]) break;
					if (Lauf[11]==Lauf[12]) break;
					if (Lauf[11]==Lauf[13]) break;
					if (Lauf[11]==Lauf[14]) break;
					if (Lauf[11]==Lauf[15]) break;
					if (Lauf[11]==Lauf[16]) break;
					if (Lauf[12]==Lauf[13]) break;
					if (Lauf[12]==Lauf[14]) break;
					if (Lauf[12]==Lauf[15]) break;
					if (Lauf[12]==Lauf[16]) break;
					if (Lauf[13]==Lauf[14]) break;
					if (Lauf[13]==Lauf[15]) break;
					if (Lauf[13]==Lauf[16]) break;
					if (Lauf[14]==Lauf[15]) break;
					if (Lauf[14]==Lauf[16]) break;
					if (Lauf[15]==Lauf[16]) break;
				}
				
				// C, wC
				if(wert[1]!=6){for(iLauf=1; iLauf<= 16; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");}

				// wP
				if(wert[1]==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%i ", Lauf[vLauf[1]]);fprintf(out," ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%i ", vLauf[1]);//k2
						    sw=0;
					}
					fprintf(out,"\n");
				}
				
				//printf("\r%.0f                     ",zlr);	
				zlr++;

			// anordnungswiederholungsfilter explizit
			 if(Lauf[16]==Lauf[15]) break;
			}if(Lauf[15]==Lauf[14]) break;//16
			}if(Lauf[14]==Lauf[13]) break;//15
			}if(Lauf[13]==Lauf[12]) break;//14
			}if(Lauf[12]==Lauf[11]) break;//13
			}if(Lauf[11]==Lauf[10]) break;//12
			}if(Lauf[10]==Lauf[9]) break;//11
			}if(Lauf[9]==Lauf[8]) break;//10
			}if(Lauf[8]==Lauf[7]) break;//9
			}if(Lauf[7]==Lauf[6]) break;//8
			}if(Lauf[6]==Lauf[5]) break;//7
			}if(Lauf[5]==Lauf[4]) break;//6
			}if(Lauf[4]==Lauf[3]) break;//5
			}if(Lauf[3]==Lauf[2]) break;//4
			}if(Lauf[2]==Lauf[1]) break;//3
			}//2
			}//1
		}	
	}

	// Variation V, wV, explizit
	if(  ((wert[1]==3 || wert[1]==4) && wert[3] >=7) ||
	     ( wert[1]==5                && wert[2] >=7)  )
	{
		//---------------------------------------------------------------------------------------------- V,wV  m=7 //
		if(m_==7)
		{
			// V, wV
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			
				// V, P
				// elementwiederholungsfilter explizit
				if(wert[1]==3 || wert[1]==5)
				{
					if( Lauf[1]!=Lauf[2]  && 
					    Lauf[1]!=Lauf[3]  && 
					    Lauf[1]!=Lauf[4]  && 
					    Lauf[1]!=Lauf[5]  && 
					    Lauf[1]!=Lauf[6]  && 
					    Lauf[1]!=Lauf[7]  && 
					    Lauf[2]!=Lauf[3]  &&
					    Lauf[2]!=Lauf[4]  &&
					    Lauf[2]!=Lauf[5]  &&
					    Lauf[2]!=Lauf[6]  &&
					    Lauf[2]!=Lauf[7]  && 
					    Lauf[3]!=Lauf[4]  && 
					    Lauf[3]!=Lauf[5]  && 
					    Lauf[3]!=Lauf[6]  && 
					    Lauf[3]!=Lauf[7]  && 
					    Lauf[4]!=Lauf[5]  && 
					    Lauf[4]!=Lauf[6]  &&
					    Lauf[4]!=Lauf[7]  &&
					    Lauf[5]!=Lauf[6]  && 
				        Lauf[5]!=Lauf[7]  && 
					    Lauf[6]!=Lauf[7]  )
					{
						for(iLauf=1; iLauf<= 7; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");
						zlr++;
					}
				}

				// wV
				if(wert[1]==4)
				{
						for(iLauf=1; iLauf<= 7; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");
						zlr++;
				}
			 
			}//7
			}//6
			}//5
			}//4
			}//3
			}//2
			}//1
		}

		//------------------------------------------------------------------------------------------- V,wV  m=8 //
		if(m_==8)
		{
			// V, wV
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			
		
				// V, P
				// elementwiederholungsfilter explizit
				if(wert[1]==3 || wert[1]==5)
				{
					if( Lauf[1]!=Lauf[2]  && 
					    Lauf[1]!=Lauf[3]  && 
					    Lauf[1]!=Lauf[4]  && 
					    Lauf[1]!=Lauf[5]  && 
					    Lauf[1]!=Lauf[6]  && 
					    Lauf[1]!=Lauf[7]  &&
						Lauf[1]!=Lauf[8]  &&
					    Lauf[2]!=Lauf[3]  &&
					    Lauf[2]!=Lauf[4]  &&
					    Lauf[2]!=Lauf[5]  &&
					    Lauf[2]!=Lauf[6]  &&
					    Lauf[2]!=Lauf[7]  &&
						Lauf[2]!=Lauf[8]  &&
					    Lauf[3]!=Lauf[4]  && 
					    Lauf[3]!=Lauf[5]  && 
					    Lauf[3]!=Lauf[6]  && 
					    Lauf[3]!=Lauf[7]  && 
						Lauf[3]!=Lauf[8]  &&
					    Lauf[4]!=Lauf[5]  && 
					    Lauf[4]!=Lauf[6]  &&
					    Lauf[4]!=Lauf[7]  &&
						Lauf[4]!=Lauf[8]  &&
					    Lauf[5]!=Lauf[6]  && 
				        Lauf[5]!=Lauf[7]  && 
						Lauf[5]!=Lauf[8]  &&
					    Lauf[6]!=Lauf[7]  &&
						Lauf[6]!=Lauf[8]  &&
						Lauf[7]!=Lauf[8] )
						
					{
						for(iLauf=1; iLauf<= 8; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");
						zlr++;
					}
				}

				// wV
				if(wert[1]==4)
				{
						for(iLauf=1; iLauf<= 8; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");
						zlr++;
				}
			 
			}//8
			}//7
			}//6
			}//5
			}//4
			}//3
			}//2
			}//1
		}

		//----------------------------------------------------------------------------------------------- wV  m=9 //
		if(m_==9)
		{
			// wV
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){
			
			for(iLauf=1; iLauf<= 9; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");
			zlr++;
		 
			}//9
			}//8
			}//7
			}//6
			}//5
			}//4
			}//3
			}//2
			}//1
		}

		//----------------------------------------------------------------------------------------------- wV  m=10 //
		if(m_==10)
		{
			// wV
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){
			for (Lauf[10]=1; Lauf[10]<=n_; Lauf[10]++){
			
			for(iLauf=1; iLauf<= 10; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");
			zlr++;
		 
			}//10
			}//9
			}//8
			}//7
			}//6
			}//5
			}//4
			}//3
			}//2
			}//1
		}

		//----------------------------------------------------------------------------------------------- wV  m=11 //
		if(m_==11)
		{
			// wV
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){
			for (Lauf[10]=1; Lauf[10]<=n_; Lauf[10]++){
			for (Lauf[11]=1; Lauf[11]<=n_; Lauf[11]++){
			
			for(iLauf=1; iLauf<= 11; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");
			zlr++;
		 
			}//11
			}//10
			}//9
			}//8
			}//7
			}//6
			}//5
			}//4
			}//3
			}//2
			}//1
		}
		//----------------------------------------------------------------------------------------------- wV  m=12 //
		if(m_==12)
		{
			// wV
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){
			for (Lauf[10]=1; Lauf[10]<=n_; Lauf[10]++){
			for (Lauf[11]=1; Lauf[11]<=n_; Lauf[11]++){
			for (Lauf[12]=1; Lauf[12]<=n_; Lauf[12]++){
			
			for(iLauf=1; iLauf<= 12; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");
			zlr++;
		 
			}//12
			}//11
			}//10
			}//9
			}//8
			}//7
			}//6
			}//5
			}//4
			}//3
			}//2
			}//1
		}
		//----------------------------------------------------------------------------------------------- wV  m=13 //
		if(m_==13)
		{
			// wV
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){
			for (Lauf[10]=1; Lauf[10]<=n_; Lauf[10]++){
			for (Lauf[11]=1; Lauf[11]<=n_; Lauf[11]++){
			for (Lauf[12]=1; Lauf[12]<=n_; Lauf[12]++){
			for (Lauf[13]=1; Lauf[13]<=n_; Lauf[13]++){
			
			for(iLauf=1; iLauf<= 13; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");
			zlr++;
		 
			}//13
			}//12
			}//11
			}//10
			}//9
			}//8
			}//7
			}//6
			}//5
			}//4
			}//3
			}//2
			}//1
		}

		//----------------------------------------------------------------------------------------------- wV  m=14 //
		if(m_==14)
		{
			// wV
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){
			for (Lauf[10]=1; Lauf[10]<=n_; Lauf[10]++){
			for (Lauf[11]=1; Lauf[11]<=n_; Lauf[11]++){
			for (Lauf[12]=1; Lauf[12]<=n_; Lauf[12]++){
			for (Lauf[13]=1; Lauf[13]<=n_; Lauf[13]++){
			for (Lauf[14]=1; Lauf[14]<=n_; Lauf[14]++){
			
			for(iLauf=1; iLauf<= 14; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");
			zlr++;
		 
			}//14
			}//13
			}//12
			}//11
			}//10
			}//9
			}//8
			}//7
			}//6
			}//5
			}//4
			}//3
			}//2
			}//1
		}

		//----------------------------------------------------------------------------------------------- wV  m=15 //
		if(m_==15)
		{
			// wV
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){
			for (Lauf[10]=1; Lauf[10]<=n_; Lauf[10]++){
			for (Lauf[11]=1; Lauf[11]<=n_; Lauf[11]++){
			for (Lauf[12]=1; Lauf[12]<=n_; Lauf[12]++){
			for (Lauf[13]=1; Lauf[13]<=n_; Lauf[13]++){
			for (Lauf[14]=1; Lauf[14]<=n_; Lauf[14]++){
			for (Lauf[15]=1; Lauf[15]<=n_; Lauf[15]++){
			
			for(iLauf=1; iLauf<= 15; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");
			zlr++;
		 
			}//15
			}//14
			}//13
			}//12
			}//11
			}//10
			}//9
			}//8
			}//7
			}//6
			}//5
			}//4
			}//3
			}//2
			}//1
		}

		//----------------------------------------------------------------------------------------------- wV  m=16 //
		if(m_==16)
		{
			// wV
			for (Lauf[1]=1; Lauf[1]<=n_; Lauf[1]++){
			for (Lauf[2]=1; Lauf[2]<=n_; Lauf[2]++){
			for (Lauf[3]=1; Lauf[3]<=n_; Lauf[3]++){
			for (Lauf[4]=1; Lauf[4]<=n_; Lauf[4]++){
			for (Lauf[5]=1; Lauf[5]<=n_; Lauf[5]++){
			for (Lauf[6]=1; Lauf[6]<=n_; Lauf[6]++){
			for (Lauf[7]=1; Lauf[7]<=n_; Lauf[7]++){
			for (Lauf[8]=1; Lauf[8]<=n_; Lauf[8]++){
			for (Lauf[9]=1; Lauf[9]<=n_; Lauf[9]++){
			for (Lauf[10]=1; Lauf[10]<=n_; Lauf[10]++){
			for (Lauf[11]=1; Lauf[11]<=n_; Lauf[11]++){
			for (Lauf[12]=1; Lauf[12]<=n_; Lauf[12]++){
			for (Lauf[13]=1; Lauf[13]<=n_; Lauf[13]++){
			for (Lauf[14]=1; Lauf[14]<=n_; Lauf[14]++){
			for (Lauf[15]=1; Lauf[15]<=n_; Lauf[15]++){
			for (Lauf[16]=1; Lauf[16]<=n_; Lauf[16]++){
			
			for(iLauf=1; iLauf<= 16; iLauf++)fprintf(out,"%i ", Lauf[iLauf]);fprintf(out,"\n");
			zlr++;
		 
			}//16
			}//15
			}//14
			}//13
			}//12
			}//11
			}//10
			}//9
			}//8
			}//7
			}//6
			}//5
			}//4
			}//3
			}//2
			}//1
		}
	}

	// allgemeinalgorithmus

	if( ( wert[1]<=2                && wert[3] <5) || 
		((wert[1]==3 || wert[1]==4) && wert[3] <7) || 
		( wert[1]==5                && wert[2] <7) ||
		( wert[1]==6                && m_ <5     )  )
		
	{	
		while(1)
		{
			// allgemeine index generierung 
			for (Lauf[1]=1; Lauf[1]<= m_; Lauf[1]++) 
			{				
				if(Lauf[1]==1) 
					
					vLauf[1]++;

				if(Lauf[1]==m_ && vLauf[Lauf[1]] > n_) break;
				
				if( vLauf[Lauf[1]] > n_) 
				{ 
					vLauf[Lauf[1]  ]  = 1;
					vLauf[Lauf[1]+1] += 1;	
				}
			}
			// endkriterium
			if(Lauf[1]==m_ && vLauf[Lauf[1]] > n_) break;

			// elementwiederholungsprüfung bei C, V, P, wP
			if(wert[1]==1 || wert[1]==3 || wert[1]==5 || wert[1]==6)
			{
					   for(Lauf[1]=1; Lauf[1]<= m_; Lauf[1]++)
										for(Lauf[2]=Lauf[1]+1; Lauf[2]<=m_; Lauf[2]++) 
				if( ( vLauf[Lauf[1]]==vLauf[Lauf[2]] ) ) sw=1;
			}

			// anordnungswiederholungsprüfung bei C, wC, wP
			if(sw==0 && (wert[1]==1 || wert[1]==2 || wert[1]==6) )
			{
					   for(Lauf[1]=1; Lauf[1]<= m_; Lauf[1]++)
										for(Lauf[2]=Lauf[1]+1; Lauf[2]<=m_; Lauf[2]++) 
				if( ( vLauf[Lauf[1]]>vLauf[Lauf[2]] ) ) sw=1;
			}

			// zeilenvektor ausgabe in datei
			if(sw==0)
			{
				// C, wC, V, wV, P
				if(wert[1]<6){for(Lauf[1]=1; Lauf[1]<= m_; Lauf[1]++)fprintf(out,"%i ", vLauf[Lauf[1]]);fprintf(out,"\n");}
				
				// wP
				if(wert[1]==6)
				{
					for(Lauf[1]=1; Lauf[1]<= m_; Lauf[1]++)fprintf(out,"%i ", vLauf[Lauf[1]]);fprintf(out," "); // k1
					
					for(Lauf[1]=1; Lauf[1]<= n_; Lauf[1]++)//3
					{
						for(Lauf[2]=1; Lauf[2]<= m_; Lauf[2]++) if(vLauf[Lauf[2]]==Lauf[1])sw=1; // k1 k2 element vergleich
						
						if (sw==0) fprintf(out,"%i ", Lauf[1]); //k2
						    sw=0;
					}
					fprintf(out,"\n");
				}
				
				zlr++;
			}
			sw=0;
		}
	}
	printf("\r                                               \r" );

	fn_erg= zlr;

	return 0;
};
  
long double fn_grs_5(double wert[100])// exakt 2x2x2 kombination mit wh (2x2X2x2), 2x2x2 palindrome kombination bei Z=S // FN5 8,26,6,25,29,31,25,8          //
{
	FILE *out;
	
	double iLauf, jLauf, kLauf, lLauf, mLauf, nLauf, zlr=0, j_zlr=0, k_zlr=0, n_zlr=0, m_zlr=0, p_zlr=0.0001;
	double a,b,c,d,e,f,g,h, Z1,Z2,S1,S2;
    double  Rmax, Rmax1,P0, P_, p_=0, vektor[100], z_;
	//double a_, b_, c_, d_, n1_, Z11, Z12, S11, S12, min_1, min_2, min_;
	//double e_, f_, g_, h_, n2_, Z21, Z22, S21, S22;
	
	out=fopen( "fx.txt", "w" );

	//double n_;
/*
	a_= 1;      b_= 1;    Z11=a_+b_;
    c_= 1;      d_= 1;	  Z12=c_+d_;

	S11= a_+c_; S12= b_+d_;       n1_= a_+b_+c_+d_;

	e_= 1;      f_= 1;    Z21=e_+f_;
    g_= 1;      h_= 1;	  Z22=g_+h_;

	S21= e_+g_; S22= f_+h_;       n2_= e_+f_+g_+h_; n_=n1_+n2_;

	//minimalwert
	if(a_<=b_) min_1=a_;if(a_>b_) min_1=b_;
	if(c_<=d_) min_2=d_;if(c_>d_) min_2=d_;
	if(min_1<= min_2)min_=min_1;if(min_1> min_2)min_=min_2;

	a_=a_-min_;
	b_ = Z11-a_;
	c_ = S11-a_;
	d_ =n1_-a_-b_-c_;
	
	if(e_<=f_) min_1=e_;if(e_>f_) min_1=f_;
	if(g_<=h_) min_2=g_;if(g_>h_) min_2=h_;
	if(min_1<= min_2)min_=min_1;if(min_1> min_2)min_=min_2;

	e_=e_-min_;
	f_ = Z21-e_;
	g_ = S21-e_;
	h_ =n2_-e_-f_-g_;
*/
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

	Z1 = wert[1]+wert[2]+wert[5]+wert[6];
	Z2 = wert[3]+wert[4]+wert[7]+wert[8]; 
	S1 = wert[1]+wert[3]+wert[5]+wert[7];
	S2 = wert[2]+wert[4]+wert[6]+wert[8];
		
	Rmax= wert[1]+wert[2]+wert[3]+wert[4]; // tafelfrequenzen
	Rmax1=wert[5]+wert[6]+wert[7]+wert[8];

	//2x2x2 Palindrome Variation

	//2x2 hauptlauf
	for(iLauf=0; iLauf<= Rmax+1; iLauf++)
	{
		for(jLauf=0; jLauf<= Rmax+1-j_zlr; jLauf++)
		{
			for(kLauf=Rmax-k_zlr; kLauf>= 0; kLauf--)
			{	
				
				a=iLauf;
				b=jLauf;
				c=kLauf;
				d=Rmax-k_zlr-kLauf;

				//e=d; f=c; g=b; h=a;//revers

				// Zellenfrequenzen
				//printf("%.0f %.0f %.0f %.0f  %.0f %.0f %.0f %.0f \n",a, b, c, d, e, f, g, h);// 2x2x2
				//printf("1:\n");
				//printf("%.0f %.0f|%.0f\n%.0f %.0f|%.0f\n---+-\n%.0f %.0f|%.0f\n",a, b,a+b, c, d, c+d, a+c,b+d,a+b+c+d);//2x2	

				//zlr++;
/*
				printf("%.0f = ", a+b+e+f );//Z1
				printf("%.0f = ", c+d+g+h ); //Z2
				printf("%.0f = ", a+c+e+g ); //S1
				printf("%.0f = ", b+d+f+h ); //S2
				printf("%.0f = ", a+b+c+d ); //T1
				printf("%.0f \n", e+f+g+h );   //T1
				
				vektor[1]= iLauf;
				vektor[2]= jLauf;
				vektor[3]= kLauf;
				vektor[4]= Rmax-k_zlr-kLauf;
				vektor[5]= Rmax-k_zlr-kLauf;
				vektor[6]= kLauf;
				vektor[7]= jLauf;
				vektor[8]= iLauf;
		
				P_= fn_hg_(vektor, 1);

				p_+=P_;
*/
				//printf("P= %.16f \n",P_);

				//2x2 nebenlauf
				for(lLauf=0; lLauf<= Rmax1+1; lLauf++)
				{
					for(mLauf=0; mLauf<= Rmax1+1-m_zlr; mLauf++)
					{
						for(nLauf=Rmax1-n_zlr; nLauf>= 0; nLauf--)
						{														
							e=lLauf;
							f=mLauf;
							g=nLauf;
							h=Rmax1-n_zlr-nLauf;

							// Zellenfrequenzen
							//printf("%.0f %.0f %.0f %.0f  %.0f %.0f %.0f %.0f \n",a, b, c, d, e, f, g, h);// 2x2x2
						//	printf("2:\n");
						//	printf("%.0f %.0f|%.0f\n%.0f %.0f|%.0f\n---+-\n%.0f %.0f|%.0f\n\n",e, f,e+f, g, h, g+h, e+g,f+h,e+f+g+h);//2x2	

							if( a+b+e+f == Z1 &&
							    c+d+g+h == Z2 &&
								a+c+e+g == S1 &&
								b+d+f+h == S2 )
							{
							
								   zlr++;
													 vektor[1]= a;
													 vektor[2]= b;
													 vektor[3]= c;
													 vektor[4]= d;
													 vektor[5]= e;
													 vektor[6]= f;
													 vektor[7]= g;
													 vektor[8]= h;
							
										  z_= fn_hg_(vektor, 3);
										  P_= fn_hg_(vektor, 1);
									if(P_<=P0) p_=p_+P_;  //p

								printf("%.0f\r",zlr);
								if(p_zlr-p_<=0) // ausgabe in % schritten 
								{	
								fprintf (out,"%.16f\n", P_);
								//	fprintf (out,"%f\n", z_);
									p_zlr+=0.0001; //(p_zlr+0.1 = 10 werte, +0.01 = 100 werte...)
								}
							}
						}

						n_zlr++;
					}
						  m_zlr++;
					n_zlr=m_zlr;
				}
				n_zlr=m_zlr=0;Rmax1= wert[5]+wert[6]+wert[7]+wert[8];
			}
			k_zlr++;
		}
		      j_zlr++;
        k_zlr=j_zlr;
	}

	fclose(out);

	//printf("M= %.0f, p= %.16f\n", zlr, p_);

	fn_erg=P0; 

	return 0;
}

long double fn_grs_6(double wert[100])// exakt hypergeometrisch 4-Felder  // FN6 1,0,0,0           //
{
	FILE *out;

	double a,b,c,d, n, zlr=0, P0, P_, pw=0, p=0;

	n=wert[1]+wert[2]+wert[3]+wert[4];

	P0=faktoriell(wert[1]+wert[2]) * faktoriell(wert[3]+wert[4]) * faktoriell(wert[1]+wert[3]) * faktoriell(wert[2]+wert[4]) ;
					P0=P0/( faktoriell(n) * faktoriell(wert[1]) * faktoriell(wert[2]) * faktoriell(wert[3]) * faktoriell(wert[4])*(n*(n+2)+1) );
					
					printf("\n\n");	
	out=fopen( "fx.txt", "w" );
	for(a=0;a<=n;a++)
	{
		for(b=0;b<=n;b++)
		{
			for(c=0;c<=n;c++)
			{
				for(d=0;d<=n;d++)
				{
				//if(a+b+c+d!=n) break;
				  if(a+b+c+d==n){/*printf("%.0f: \n%.0f %.0f|%.0f\n%.0f %.0f|%.0f\n-----\n%.0f %.0f|%.0f\n\n",
					zlr, a,b,a+b,c,d,c+d, a+c,b+d, a+b+c+d);*/zlr++;
				
				
					P_=faktoriell(a+b) * faktoriell(c+d) * faktoriell(a+c) * faktoriell(b+d) ;
					P_=P_/( faktoriell(n) * faktoriell(a) * faktoriell(b) * faktoriell(c) * faktoriell(d)*(n*(n+2)+1) );
					
					if(P_<=P0)p+=P_;

					pw+= P_;

					printf("%.14f\r",   pw );
					//fprintf(out, "%f\n",P_);	//

					//fprintf(out, "%.0f %.0f %.0f %.0f P= %f\n",a,b,c,d,P_);	//
				
				
				}
				
				
				}
			}
		}
	}

	fn_erg = p;

	fclose(out);

	return 0;
}
/*
double fn_grs_7(double wert[100])//, 2x2x2 kombinationen  //  FN7 maxf,0         //
{
	double aLauf, bLauf,cLauf,dLauf,eLauf,fLauf,gLauf,hLauf;
	double a,b,c,d,e,f,g,h, n,Z1, Z2, T1, T2,S1,S2, zlr=0, vektor[100], P0, P_, p1=0;

	for(aLauf=0;aLauf<=wert[1];aLauf++)
	{
		for(bLauf=0;bLauf<=wert[1];bLauf++)
		{
			for(cLauf=0;cLauf<=wert[1];cLauf++)
			{
				for(dLauf=0;dLauf<=wert[1];dLauf++)
				{
					for(eLauf=0;eLauf<=wert[1];eLauf++)
					{
						for(fLauf=0;fLauf<=wert[1];fLauf++)
						{
							for(gLauf=0;gLauf<=wert[1];gLauf++)
							{
								for(hLauf=0;hLauf<=wert[1];hLauf++)
								{
									n=aLauf+bLauf+cLauf+dLauf+eLauf+fLauf+gLauf+hLauf;

									T1=aLauf+bLauf+cLauf+dLauf;
									T2=eLauf+fLauf+gLauf+hLauf;
									Z1=aLauf+bLauf+eLauf+fLauf;
									Z2=cLauf+dLauf+gLauf+hLauf;
									S1=aLauf+cLauf+eLauf+gLauf;
									S2=bLauf+dLauf+fLauf+hLauf;

										     vektor[1]= aLauf;
											 vektor[2]= bLauf;
											 vektor[3]= cLauf;
											 vektor[4]= dLauf;
											 vektor[5]= eLauf;
											 vektor[6]= fLauf;
											 vektor[7]= gLauf;
											 vektor[8]= hLauf;
							
									P0= fn_hg_(vektor, 1);

									for(a=0;a<=n;a++)
									{
										for(b=0;b<=n;b++)
										{
											for(c=0;c<=n;c++)
											{
												for(d=0;d<=n;d++)
												{
													for(e=0;e<=n;e++)
													{
														for(f=0;f<=n;f++)
														{
															for(g=0;g<=n;g++)
															{
																for(h=0;h<=n;h++)
																{
																	//if(a+b+c+d!=n) break;
																	if( a+b+c+d==T1 &&
																		e+f+g+h==T2 &&
																		a+b+e+f==Z1 &&
																		c+d+g+h==Z2 &&
																		a+c+e+g==S1 &&
																		b+d+f+h==S2)
																	{   
																		//printf("%.0f: \n%.0f %.0f|%.0f\n%.0f %.0f|%.0f\n-----\n%.0f %.0f|%.0f\n\n",
																		//zlr, a,b,a+b,c,d,c+d, a+c,b+d, a+b+c+d)
																		//printf("\n%.0f %.0f|%.0f\n%.0f %.0f|%.0f\n-----\n%.0f %.0f|%.0f\n\n",
																		//e,f,e+f,g,h,g+h, e+g,f+h, e+f+g+h);
															
																		vektor[1]= a;
																		vektor[2]= b;
																		vektor[3]= c;
																		vektor[4]= d;
																		vektor[5]= e;
																		vektor[6]= f;
																		vektor[7]= g;
																		vektor[8]= h;
											
																		P_= fn_hg_(vektor, 1);
																		if(P_<=P0) p1=p1+P_;
															  
																		zlr++;
																	}
																}
															}
														}
													}
												}	
											}
										}
									}
									//printf("%.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f v= %.0f\n",aLauf,bLauf,cLauf,dLauf,eLauf,fLauf,gLauf,hLauf,zlr);zlr=0;
									//printf("%.0f ",zlr);zlr=0;
									printf("%.5f ",P0);zlr=0;p1=0;
								}
							}
						}
						printf(" ");//
					}
				}
				printf("\n");	
			}
		}
	}
		
	fn_erg = zlr;	
	return 0;
}
*//*
long double fn_grs_7(double wert[100], int zn)// exakt multinomial k-Felder  // FN7 3,4,5        //
{

								

	// allgemeinvariante in entwicklung -------------------------------------------------------- k //
	if(0)
	{
		for(iLauf=1 ; iLauf <=k; iLauf++ ) z_[iLauf]= wert[iLauf];
		for(iLauf=1 ; iLauf <=k; iLauf++ ) n+= z_[iLauf];
		
		for(iLauf=1 ; iLauf <= 2*k; iLauf+=2 ) 
		{                   
			                vektor[iLauf]= 1.0/k;
							vektor[iLauf+1]= z_[(iLauf+1)/2];
							//printf("%f %.0f\n", vektor[iLauf], vektor[iLauf+1]);
		}
							vektor[2*k+1]= n;//


				 P[0]= fn_mtnom(vektor,2*k+1);//

				
			 		//printf("%.14f\n",    P[0] );//

		                                    z_[1]=n;
		for(iLauf=2 ; iLauf <=k; iLauf++ )  z_[iLauf]=0;

		printf("%.0f %.0f %.0f %.0f %.0f %.0f %.0f -a\n",z_[1],z_[2],z_[3],z_[4],z_[5],z_[6],z_[7]);//
									  
		for(iLauf=1 ; iLauf <=k; iLauf++ ) 
			                          vektor[2*iLauf]= z_[iLauf];

					   P[8]= fn_mtnom(vektor,2*k+1);
				 P[6]+=P[8];
					if(P[8]<= P[0])P[2]+=P[8];
					
					//printf("%.14f\r",   P[6] )

		while(z_[1]>0) 
		{
			 z_[3]=0;
			 z_[1]--;
		     z_[2]++;
			z1_[2]=z_[2];
			z1_[3]=z_[3];
	printf("%.0f %.0f %.0f %.0f %.0f %.0f %.0f -b\n",z_[1],z1_[2],z1_[3],z_[4],z_[5],z_[6],z_[7]);	//	

				
									  vektor[2]=  z_[1];
									  vektor[4]= z1_[2];
							   		  vektor[6]= z1_[3];

				      for(iLauf=4 ; iLauf <=k; iLauf++ ) 
			                          vektor[2*iLauf]= z_[iLauf];

					   P[8]= fn_mtnom(vektor,2*k+1);zlr++;
				 P[6]+=P[8];
					if(P[8]<= P[0])P[2]+=P[8];
					
					//printf("%.14f\r",   P[6] );
					
					//fprintf(out,"%.14f\n",    P[8] );

			while(z1_[2]>0)
			{
				 z_[4]=0;
				z1_[2]--;
				z1_[3]++;
				z2_[3]=z1_[3];
				z1_[4]= z_[4];
				printf("%.0f %.0f %.0f %.0f %.0f %.0f %.0f -c\n",z_[1],z1_[2],z1_[3],z1_[4],z_[5],z_[6],z_[7]);//
				
										  vektor[2]=  z_[1];
										  vektor[4]= z1_[2];
							   			  vektor[6]= z1_[3];
										  vektor[8]= z1_[4];

						  for(iLauf=5 ; iLauf <=k; iLauf++ ) 
			                              vektor[2*iLauf]= z_[iLauf];
						
						   P[8]= fn_mtnom(vektor,2*k+1);zlr++;
					 P[6]+=P[8];
						if(P[8]<= P[0])P[2]+=P[8];	

						//printf("%.14f\r",   P[6] );

						//fprintf(out, "%.14f\n",   P[8] );
					
						
				for(iLauf=0 ; iLauf <=k-5; iLauf++ )
				{
					while(z2_[3+iLauf]>0)
					{
						  z_[5+iLauf]=0;
						 z2_[3+iLauf]--;
						 z1_[4+iLauf]++;

						 z2_[4+iLauf]=z1_[4+iLauf];
						 z1_[5+iLauf]= z_[5+iLauf];
						printf("%.0f %.0f %.0f %.0f %.0f %.0f %.0f -d\n",z_[1],z1_[2],z2_[3],z2_[4],z2_[5],z_[6], z_[7]);//
						
											  vektor[2]=  z_[1];
											  vektor[4]= z1_[2];
								                                     for(jLauf=0; jLauf <=iLauf; jLauf++ ) 
									          vektor[2*(3+jLauf)]= z2_[3+jLauf];
											 
											  vektor[2*(3+iLauf+1)]= z1_[3+iLauf+1];
								
							                                  for(jLauf=3+iLauf+2; jLauf <=k; jLauf++ )
									          vektor[2*jLauf]= z_[jLauf];//
									
							   P[8]= fn_mtnom(vektor,2*k+1);zlr++;
						 P[6]+=P[8];
							if(P[8]<= P[0])P[2]+=P[8];
							
							//printf("%.14f\r",   P[6] );
							//fprintf(out,"%.14f\n",   P[8] );
					}
				}
				
				while(z2_[k-1]>0)
				{

					z2_[k-1]--;
					z1_[k]++;

				printf("%.0f %.0f %.0f %.0f %.0f %.0f %.0f -f\n",z_[1],z1_[2],z2_[3],z2_[4],z2_[5],z2_[6], z1_[7]);	//
							
										  vektor[2]=   z_[1];
										  vektor[4]=  z1_[2];
							   			  vektor[6]=  z2_[3];
										  vektor[8]=  z2_[4];
							 
					    for(iLauf=5 ; iLauf <=k-1; iLauf++ ) 
			                              vektor[2*iLauf]= z2_[iLauf];
										 
										
										  vektor[2*k]= z1_[k];//
						   P[8]= fn_mtnom(vektor,2*k+1);zlr++;
					 P[6]+=P[8];
						if(P[8]<= P[0])P[2]+=P[8];
					
						//printf("%.14f\r",   P[6] );
						//fprintf(out,"%.14f\n",   P[8] );
				
				}
			}
		}
	}
	
	
	

	return 0;
}*/	

double fn_grs_7(double wert[100], double n) //  vollständige Kombinationsmatrizen (2) //
//                                                                      // Kombination  C ohne Wh von (x) zu m (1) FN7 1, 2,  1,2,3   
//                                                                      // Kombination wC  mit Wh von (x) zu m (2) FN7 2, 2,  1,2,3 
//                                                                      // Variation    V ohne Wh von (x) zu m (3) FN7 3, 2,  1,2,3 
//                                                                      // Variation   wV  mit Wh von (x) zu m (4) FN7 4, 2,  1,2,3 
//                                                                      // Permutation  P zu 1 Kl (x)          (5) FN7 5,     1,2,3
{
	FILE *out;
	
	int Lauf[100], vLauf[100], sw=0, i_=2;
	double  n_, m_, zlr=0;

	n_=n - 2;
	m_=wert[2];

	if(wert[1]==5) {n_=n - 1;m_=n_;i_=1;} //Permutation P als Variation V von n zu n
	
	for(Lauf[1]=1; Lauf[1]<=100; Lauf[1]++) vLauf[Lauf[1]]= 1; // 
	
	vLauf[1]=0;

	out=fopen( "fx.txt", "w" );

	if(wert[1]<=2 )               printf("\n\ncomputing ci(xj) ..."); //C, wC
	if(wert[1]==3 || wert[1]==4 ) printf("\n\ncomputing vi(xj) ..."); //V, wV
	if(wert[1]==5 && wert[2]==8)  printf("\n\ncomputing pi(xj) ..."); //P
		
	while(1)
	{
		// allgemeine index generierung 
		for (Lauf[1]=1; Lauf[1]<= m_; Lauf[1]++) 
		{				
			if(Lauf[1]==1) 
				
				vLauf[1]++;

			if(Lauf[1]==m_ && vLauf[Lauf[1]] > n_) break;
			
			if( vLauf[Lauf[1]] > n_) 
			{ 
				vLauf[Lauf[1]  ]  = 1;
				vLauf[Lauf[1]+1] += 1;	
			}
		}
		// endkriterium
		if(Lauf[1]==m_ && vLauf[Lauf[1]] > n_) break;

		// elementwiederholungsprüfung bei C, V, P
		if(wert[1]==1 || wert[1]==3 || wert[1]==5)
		{
				   for(Lauf[1]=1; Lauf[1]<= m_; Lauf[1]++)
									for(Lauf[2]=Lauf[1]+1; Lauf[2]<=m_; Lauf[2]++) 
			if( ( vLauf[Lauf[1]]==vLauf[Lauf[2]] ) ) sw=1;
		}

		// anordnungswiederholungsprüfung bei C, wC
		if(sw==0 && (wert[1]==1 || wert[1]==2) )
		{
				   for(Lauf[1]=1; Lauf[1]<= m_; Lauf[1]++)
									for(Lauf[2]=Lauf[1]+1; Lauf[2]<=m_; Lauf[2]++) 
			if( ( vLauf[Lauf[1]]>vLauf[Lauf[2]] ) ) sw=1;
		}

		// zeilenvektor ausgabe in datei
		if(sw==0)
		{
			for(Lauf[1]=1; Lauf[1]<= m_; Lauf[1]++)fprintf(out,"%.0f ", wert[vLauf[Lauf[1]]+i_]);fprintf(out,"\n");
			zlr++;
		}
		sw=0;
	}	
	printf("\r                                               \r" );

	fn_erg= zlr;

	return 0;
}


long double fn_grs_8(double wert[100])// 2x2x2 randomisierte Permutation // FN8 8,26,6,25,29,31,25,8         //
{
	FILE *out;
	int  iLauf, jLauf,  hub=0, sw=1 ;
	double  vektor[100], srt0[9], srt[9], rnd_[8], sd, P0, P, n, p=0,zlr=0, M=300000;
	double  Z1,Z2, T1, T2,  min;
	double  S1,S2, g_;

				vektor[1]=wert[1];  // P0
				vektor[2]=wert[2];
				vektor[3]=wert[3];
				vektor[4]=wert[4];
				vektor[5]=wert[5];
				vektor[6]=wert[6];
				vektor[7]=wert[7];
				vektor[8]=wert[8];
	 P0= fn_hg_(vektor, 1);

	T1=wert[1]+wert[2]+wert[3]+wert[4];
	T2=wert[5]+wert[6]+wert[7]+wert[8];
	Z1=wert[1]+wert[2]+wert[5]+wert[6];
	Z2=wert[3]+wert[4]+wert[7]+wert[8];
	S1=wert[1]+wert[3]+wert[5]+wert[7];
	S2=wert[2]+wert[4]+wert[6]+wert[8];

	n=T1+T2;

	g_=0;
	 
	rnd_[1]=0;
	rnd_[2]=0;
	rnd_[3]=0;
	rnd_[4]=0;
	rnd_[5]=0;
	rnd_[6]=0;
	rnd_[7]=0;
	rnd_[8]=0;
		
	sd=(time(0)-1234567890); sd= qzufall(sd,0,10);

	out=fopen( "fx.txt", "w" );

	 //printf("\n\n%.0f %.0f %.0f %.0f %.0f %.0f", T1,T2,Z1,Z2,S1,S2);

	printf("\n\n");

	//for(iLauf=1; iLauf<=8;iLauf++) srt0[iLauf]=wert[iLauf];
	
	while(zlr<= M)// Randomisierte Permutation
	{
		for(iLauf=1; iLauf<=8;iLauf++){srt0[iLauf]=qzufall(sd,0,1);sd=srt0[iLauf];}

		min=srt0[1]; 
		for (iLauf = 1; iLauf <= 8; iLauf++)if(srt0[iLauf]<min)min=srt0[iLauf];
				
		srt[1] = min;//anfangswert=minimalwert

		for (iLauf = 1; iLauf <= 8; iLauf++)//sortierung
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
			rnd_[(iLauf+1)-hub] = wert[iLauf];hub=0;
		}

		for (iLauf = 2; iLauf <= 8+1; iLauf++)rnd_[iLauf-1]=rnd_[iLauf];//laufindexkorrektur
		rnd_[iLauf-1]=0;
			
		sd= qzufall(sd,0,1);
				
		//for(iLauf=1; iLauf<=8;iLauf++) printf("%.f\t", rnd_[iLauf]);printf("\n");
		//for(iLauf=1; iLauf<=8;iLauf++) fprintf(out,"%.0f\t", srt[iLauf]);fprintf(out,"\n");//
		//fprintf(out,"%.0f\t%.0f\t%.0f\t%.0f",Z11,Z12,S11,S12);fprintf(out,"\n");

		printf("%.0f  \r", M-zlr);
				//if(rnd_[1] <= n/16 )p++; // a >= zellen f mittel -> p

					vektor[1]=rnd_[1];  // P0
					vektor[2]=rnd_[2];
					vektor[3]=rnd_[3];
					vektor[4]=rnd_[4];
					vektor[5]=rnd_[5];
					vektor[6]=rnd_[6];
					vektor[7]=rnd_[7];
					vektor[8]=rnd_[8];
		 P= fn_hg_( vektor, 1);
				
		if(P <= P0 ) p++; // a >= rnd a -> p

		zlr++;
	}

	fclose(out);

	fn_erg= p/zlr;

	return 0;
}

/*
long double fn_grs_9(double wert[100])// 2x2x2 randomisierte variation (3) nur bei T // FN9 8,26,6,25,29,31,25,8           //
{
	int  iLauf, jLauf, index=1, hub=0, sw=1, sw1=1 ;//,
	double vektor[100], rnd_[15],  srt0[15][3], srt[15], srt1[15], sd, P0, n, p=0,zlr=0, M=100000;
	double Z11,Z12,Z21,Z22, Z1,Z2, T1, T2, TZ, TS, r_min;
	double S11,S12,S21,S22, S1,S2;
	double a,b,c,d,e,f,g,h;
	
				vektor[1]=wert[1];  // P0
				vektor[2]=wert[2];
				vektor[3]=wert[3];
				vektor[4]=wert[4];
				vektor[5]=wert[5];
				vektor[6]=wert[6];
				vektor[7]=wert[7];
				vektor[8]=wert[8];
	 P0= fn_hg_(vektor, 1);

	T1=wert[1]+wert[2]+wert[3]+wert[4];
	T2=wert[5]+wert[6]+wert[7]+wert[8];
	Z1=wert[1]+wert[2]+wert[5]+wert[6];
	Z2=wert[3]+wert[4]+wert[7]+wert[8];
	S1=wert[1]+wert[3]+wert[5]+wert[7];
	S2=wert[2]+wert[4]+wert[6]+wert[8];

	n=T1+T2;

	//minimalwert
	if(T1<=Z1)TZ= T1; if(T1>Z1)TZ= Z1; 
	if(T1<=S1)TS= T1; if(T1>S1)TS= S1;
		
	sd=(time(0)-1234567890); 

	 //printf("\n\n%.0f %.0f %.0f %.0f %.0f %.0f", T1,T2,Z1,Z2,S1,S2);

	printf("\n\n");
	
	while(zlr<= M)// Randomisierte variation, Felder T1 T2 bedingt (Z, S beliebig)
	{
				
										              Z11=qzufall(sd,0,T1);        // 2x2 Rand Frequenzen  
								              Z12= T1-Z11;
								   Z12= floor(Z12);

		                                          sd= qzufall(sd,0,10);
								                      Z11=floor(Z11);

			                          S11=qzufall(sd,0,T1-Z11);                    //
			                   S12=T1-S11;
				     S12=floor(S12);
			
					              sd= qzufall(sd,0,10);
							S11=floor(S11);
							
		if(sw==1)// 2x2 T1 Zellen Frequenzen a,b,c,d
		{					          

									  if(Z11<=S11) r_min= Z11;                           
									   if(Z11>S11) r_min= S11; 

						      rnd_[1]=qzufall(sd,0,r_min);
			      rnd_[2]=Z11-rnd_[1];
			      rnd_[2]=floor(rnd_[2]);
			  
			      rnd_[3]=S11-rnd_[1];
			      rnd_[3]=floor(rnd_[3]);
				  
																 sd= qzufall(sd,0,10); 
						      rnd_[1]=floor(rnd_[1]);
			       rnd_[4]=T1-rnd_[1]-rnd_[2]-rnd_[3];
		
	   
		}
	   
	
		if(sw==-1) // 2x2 T1 Zellen Frequenzen d,c,b,a
		{
										if(Z12<=S12) r_min= Z12;                         
									     if(Z12>S12) r_min= S12;
			   
							    rnd_[4]=qzufall(sd,0,r_min);
			        rnd_[3]=Z12-rnd_[4];
			        rnd_[3]=floor(rnd_[3]);
			  
			        rnd_[2]=S12-rnd_[4];
			        rnd_[2]=floor(rnd_[2]);
				  
																 sd= qzufall(sd,0,10); 
						        rnd_[4]=floor(rnd_[4]);
			         rnd_[1]=T1-rnd_[4]-rnd_[3]-rnd_[2];

	   
		}			
	   
		sw*=-1;                     
						
						                             Z21=qzufall(sd,0,T2-Z11);        // 2x2 Rand Frequenzen  
								             Z22= T2-Z21;
								             Z22= floor(Z22);

		                                         sd= qzufall(sd,0,10);
								                     Z21=floor(Z21);

			                         S21=qzufall(sd,S11,T2-Z21);                      //
			                  S22=T2-S21;
				              S22=floor(S21);
			
					              sd= qzufall(sd,0,10);
							         S21=floor(S21);


			                if(Z22<=S22) r_min= Z22;                                  // 2x2 T2 Zellen Frequenzen
			                 if(Z22>S22) r_min= S22; 

			        rnd_[8]=qzufall(sd,0,r_min);
        rnd_[7]=Z22-rnd_[8];
	    rnd_[7]=floor(rnd_[7]);
	  
	    rnd_[6]=S22-rnd_[8];
	    rnd_[6]=floor(rnd_[6]);
		  		
	                rnd_[8]=floor(rnd_[8]);
	     rnd_[5]=T2-rnd_[8]-rnd_[7]-rnd_[6];
 
                  sd= qzufall(sd,0,10);
		if( 
			//rnd_[1]+rnd_[2] +rnd_[5]+rnd_[6]== Z1 &&
			//rnd_[3]+rnd_[4] +rnd_[7]+rnd_[8]== Z2 &&
			//rnd_[1]+rnd_[3] +rnd_[5]+rnd_[7]== S1 &&
			//rnd_[2]+rnd_[4] +rnd_[6]+rnd_[8]== S2 &&
			//rnd_[1]+rnd_[2] +rnd_[3]+rnd_[4]== T1 &&
			//rnd_[5]+rnd_[6] +rnd_[7]+rnd_[8]== T2 &&		
			//rnd_[4] >=-1000000000000 
			rnd_[5] >=0&&
			rnd_[1] >=0
		   )
		{	       
			for(iLauf=1; iLauf<=8;iLauf++) srt0[iLauf-1][1]=rnd_[iLauf];
			for(iLauf=1; iLauf<=8;iLauf++){srt0[iLauf-1][2]=qzufall(sd,0,1);sd=srt0[iLauf-1][2];}
			
			srt[1] = -0;//anfangswert=minimalwert1

			for (iLauf = 0; iLauf <= 8; iLauf++)//sortierung
			{
				for (jLauf = 0; jLauf < iLauf; jLauf++)
				{
					if (srt0[iLauf][2] < srt[iLauf-jLauf])
					{
						srt[(iLauf-jLauf)+1] = srt[iLauf-jLauf]; 
						srt1[(iLauf-jLauf)+1] = srt1[iLauf-jLauf];
						hub++;	
					}	
				}
				srt[(iLauf+1)-hub] = srt0[iLauf][1]; 
				srt1[(iLauf+1)-hub] = index;
				hub=0;index++;
			}
			index=1;

			for (iLauf = 2; iLauf <= 8+1; iLauf++) srt[iLauf-1]=srt[iLauf];  //laufindexkorrektur
			srt[iLauf-1]=0;
			
			if(sw1==1)
			{
				a= srt[1];
				b= srt[2];
				c= srt[3];
				d= srt[4];
				e= srt[5];
				f= srt[6];
				g= srt[7];
				h= srt[8];		 
			}

			if(sw1==-1)
			{
				d= srt[8];
				b= srt[7];
				c= srt[6];
				a= srt[5];
				e= srt[4];
				f= srt[3];
				g= srt[2];
				h= srt[1];						 
			}
		   
			sw1*=-1;

			//printf("Z11= %.0f ", rnd_[1]+rnd_[2]);
			//printf("Z12= %.0f ", rnd_[3]+rnd_[4]);
			//printf("S11= %.0f ", rnd_[1]+rnd_[3]);
			//printf("S12= %.0f ", rnd_[2]+rnd_[4]);
			//printf("\n" );

			//printf("Z21= %.0f ", rnd_[5]+rnd_[6]);
			//printf("Z22= %.0f ", rnd_[7]+rnd_[8]);
			//printf("S21= %.0f ", rnd_[5]+rnd_[7]);
			//printf("S22= %.0f ", rnd_[6]+rnd_[8]);

			//printf("\n\n" );

			//printf("%.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f\n ",a,b,c,d,e,f,g,h);
			//for(iLauf=1; iLauf<=8;iLauf++) printf("%.0f ", rnd_[iLauf]);printf("\n");//

			printf("%.0f  \r", M-zlr);
			if(a <= n/16 )p++; // a <= zellen f mittel -> p

			zlr++;
		
		}
	}

	fn_erg= p/zlr;

	return 0;
}
*/
/**/
long double fn_grs_9(double wert[100])// 2x2x2 randomisierte variation (2) bei S,Z,T // FN9 8,26,6,25,29,31,25,8           //
{
	FILE *out;

	int   sw=1, zlr_1=0;//iLauf,
	double vektor[100], rnd_[9],  sd, P0, P_, Px, n, p=0,zlr=0, M=10000, sw1, crit;
	double Z11,Z12, Z1,Z2, T1, T2, TZ, TS;
	double S11,S12, S1,S2;
	
				vektor[1]=wert[1];  // P0
				vektor[2]=wert[2];
				vektor[3]=wert[3];
				vektor[4]=wert[4];
				vektor[5]=wert[5];
				vektor[6]=wert[6];
				vektor[7]=wert[7];
				vektor[8]=wert[8];
	 P0= fn_hg_(vektor, 1);

	T1=wert[1]+wert[2]+wert[3]+wert[4];
	T2=wert[5]+wert[6]+wert[7]+wert[8];
	Z1=wert[1]+wert[2]+wert[5]+wert[6];
	Z2=wert[3]+wert[4]+wert[7]+wert[8];
	S1=wert[1]+wert[3]+wert[5]+wert[7];
	S2=wert[2]+wert[4]+wert[6]+wert[8];

	n=T1+T2;

			vektor[1]=n/8;  // Px zur wahrscheinlichkeitsfilterung
				vektor[2]=n/8;
				vektor[3]=n/8;
				vektor[4]=n/8;
				vektor[5]=n/8;
				vektor[6]=n/8;
				vektor[7]=n/8;
				vektor[8]=n/8;
	Px= fn_hg_( vektor, 1);

	sd=(time(0)-1234567890); sd= qzufall(sd,0,10);

	out=fopen( "fx.txt", "w" );

	printf("\n\n");

	rnd_[8]=0;
	
	while(zlr<= M)// Randomisierte Variation
	{
					   
		   sw1=qzufall(sd,-1,1);
					   sd= qzufall(sd,0,10);
						   
		if(sw1<-0.5)   //  Zellenfrequenz a  //                                  
		{	 		   
																	  if(T1<=Z1)TZ= T1; 
																	  if(T1>Z1) TZ= Z1;
																	  if(S1<TZ) TZ= S1;
													
														   rnd_[1]=qzufall(sd,0,TZ+1);        
														   rnd_[1]=floor(rnd_[1]);

														sd= qzufall(sd,0,10);
										  
														 if(T1<=Z1)TZ= T1; 
														 if(T1>Z1) TZ= Z1;

											Z11=qzufall(sd,rnd_[1],TZ+1); 
											Z11=floor(Z11);
									rnd_[2]=Z11-rnd_[1];
					 			
								sd= qzufall(sd,0,10);

								 if(T1<=S2)TZ= T1; 
								 if(T1>S2) TZ= S2;
							 
					S12=qzufall(sd,rnd_[2],TZ+1); 
					S12=floor(S12);
			rnd_[4]=S12-rnd_[2];
			
			rnd_[3]=T1-rnd_[1]-rnd_[2]-rnd_[4];

			while(rnd_[3]<0)
			{	
					sd= qzufall(sd,0,10);
					if(T1<=Z1)TZ= T1; 
																		  if(T1>Z1) TZ= Z1;
																		  if(S1<TZ) TZ= S1;
														
															   rnd_[1]=qzufall(sd,0,TZ+1);        
															   rnd_[1]=floor(rnd_[1]);

															sd= qzufall(sd,0,10);
											  
															 if(T1<=Z1)TZ= T1; 
															 if(T1>Z1) TZ= Z1;

												Z11=qzufall(sd,rnd_[1],TZ+1); 
												Z11=floor(Z11);
										rnd_[2]=Z11-rnd_[1];
					 				
									sd= qzufall(sd,0,10);

									 if(T1<=S2)TZ= T1; 
									 if(T1>S2) TZ= S2;
								 
						S12=qzufall(sd,rnd_[2],TZ+1); 
						S12=floor(S12);
				rnd_[4]=S12-rnd_[2];
				
				rnd_[3]=T1-rnd_[1]-rnd_[2]-rnd_[4];
			}
		}
		if(sw1>=-0.5 && sw1<0)   //  Zellenfrequenz b //             
		{
			                                                          if(T1<=Z1)TZ= T1; 
																	  if(T1>Z1) TZ= Z1;
																	  if(S2<TZ) TZ= S2;
													
														   rnd_[2]=qzufall(sd,0,TZ+1);        
														   rnd_[2]=floor(rnd_[2]);

														sd= qzufall(sd,0,10);
										  
														 if(T1<=Z1)TZ= T1; 
														 if(T1>Z1) TZ= Z1;

											Z11=qzufall(sd,rnd_[2],TZ+1); 
											Z11=floor(Z11);
									rnd_[1]=Z11-rnd_[2];
					 			
								sd= qzufall(sd,0,10);

								 if(T1<=S1)TZ= T1; 
								 if(T1>S1) TZ= S1;
							 
					S11=qzufall(sd,rnd_[1],TZ+1); 
					S11=floor(S11);
			rnd_[3]=S11-rnd_[1];
			
			rnd_[4]=T1-rnd_[1]-rnd_[2]-rnd_[3];

			while(rnd_[4]<0)
			{
				     if(T1<=Z1)TZ= T1; 
																	  if(T1>Z1) TZ= Z1;
																	  if(S2<TZ) TZ= S2;
													
														   rnd_[2]=qzufall(sd,0,TZ+1);        
														   rnd_[2]=floor(rnd_[2]);

														sd= qzufall(sd,0,10);
										  
														 if(T1<=Z1)TZ= T1; 
														 if(T1>Z1) TZ= Z1;

											Z11=qzufall(sd,rnd_[2],TZ+1); 
											Z11=floor(Z11);
									rnd_[1]=Z11-rnd_[2];
					 			
								sd= qzufall(sd,0,10);

								 if(T1<=S1)TZ= T1; 
								 if(T1>S1) TZ= S1;
							 
					S11=qzufall(sd,rnd_[1],TZ+1); 
					S11=floor(S11);
			rnd_[3]=S11-rnd_[1];
			
			rnd_[4]=T1-rnd_[1]-rnd_[2]-rnd_[3];
			}
		}
		
		if(sw1>=0 && sw1<0.5)  //  Zellenfrequenz c //              
		{
																	  if(T1<=Z2)TZ= T1; 
																	  if(T1>Z2) TZ= Z2;
																	  if(S1<TZ) TZ= S1;
													
														   rnd_[3]=qzufall(sd,0,TZ+1);        
														   rnd_[3]=floor(rnd_[3]);

														sd= qzufall(sd,0,10);
										  
														 if(T1<=Z2)TZ= T1; 
														 if(T1>Z2) TZ= Z2;

											Z12=qzufall(sd,rnd_[3],TZ+1); 
											Z12=floor(Z12);
									rnd_[4]=Z12-rnd_[3];
					 			
								sd= qzufall(sd,0,10);

								 if(T1<=S2)TZ= T1; 
								 if(T1>S2) TZ= S2;
							 
					S12=qzufall(sd,rnd_[4],TZ+1); 
					S12=floor(S12);
			rnd_[2]=S12-rnd_[4];
			
			rnd_[1]=T1-rnd_[3]-rnd_[2]-rnd_[4];
			
			while(rnd_[1]<0)
			{
																		if(T1<=Z2)TZ= T1; 
																	  if(T1>Z2) TZ= Z2;
																	  if(S1<TZ) TZ= S1;
													
														   rnd_[3]=qzufall(sd,0,TZ+1);        
														   rnd_[3]=floor(rnd_[3]);

														sd= qzufall(sd,0,10);
										  
														 if(T1<=Z2)TZ= T1; 
														 if(T1>Z2) TZ= Z2;

											Z12=qzufall(sd,rnd_[3],TZ+1); 
											Z12=floor(Z12);
									rnd_[4]=Z12-rnd_[3];
					 			
								sd= qzufall(sd,0,10);

								 if(T1<=S2)TZ= T1; 
								 if(T1>S2) TZ= S2;
							 
					S12=qzufall(sd,rnd_[4],TZ+1); 
					S12=floor(S12);
			rnd_[2]=S12-rnd_[4];
			
			rnd_[1]=T1-rnd_[3]-rnd_[2]-rnd_[4];
			}
		}

		if(sw1>=0.5)  //  Zellenfrequenz d //                     
		{
																		if(T1<=Z2)TZ= T1; 
																	  if(T1>Z2) TZ= Z2;
																	  if(S2<TZ) TZ= S2;
													
														   rnd_[4]=qzufall(sd,0,TZ+1);        
														   rnd_[4]=floor(rnd_[4]);

														sd= qzufall(sd,0,10);
										  
														 if(T1<=Z2)TZ= T1; 
														 if(T1>Z2) TZ= Z2;

											Z12=qzufall(sd,rnd_[4],TZ+1); 
											Z12=floor(Z12);
									rnd_[3]=Z12-rnd_[4];
					 			
								sd= qzufall(sd,0,10);

								 if(T1<=S1)TZ= T1; 
								 if(T1>S1) TZ= S1;
							 
					S11=qzufall(sd,rnd_[3],TZ+1); 
					S11=floor(S11);
			rnd_[1]=S11-rnd_[3];
			
			rnd_[2]=T1-rnd_[3]-rnd_[1]-rnd_[4];

			while(rnd_[2]<0)
			{

														if(T1<=Z2)TZ= T1; 
																	  if(T1>Z2) TZ= Z2;
																	  if(S2<TZ) TZ= S2;
													
														   rnd_[4]=qzufall(sd,0,TZ+1);        
														   rnd_[4]=floor(rnd_[4]);

														sd= qzufall(sd,0,10);
										  
														 if(T1<=Z2)TZ= T1; 
														 if(T1>Z2) TZ= Z2;

											Z12=qzufall(sd,rnd_[4],TZ+1); 
											Z12=floor(Z12);
									rnd_[3]=Z12-rnd_[4];
					 			
								sd= qzufall(sd,0,10);

								 if(T1<=S1)TZ= T1; 
								 if(T1>S1) TZ= S1;
							 
					S11=qzufall(sd,rnd_[3],TZ+1); 
					S11=floor(S11);
			rnd_[1]=S11-rnd_[3];
			
			rnd_[2]=T1-rnd_[3]-rnd_[1]-rnd_[4];
			}
		}

		Z11= rnd_[1]+rnd_[2];
		S11= rnd_[1]+rnd_[3];
	   
	   //  Zellenfrequenzen e f,g,h  //
		
					   sd= qzufall(sd,0,10);
			  if(T2<=Z1-Z11)TZ= T2; 
			  if(T2>Z1-Z11) TZ= Z1-Z11;
			  if(S1-S11<TZ) TZ= S1-S11;

		  if(TZ<=Z2-Z12)TS= TZ; 
		  if(TZ>Z2-Z12) TS= Z2-Z12;
		  if(S2-S12<TS) TS= S2-S12;

	   rnd_[5]=qzufall(sd,TS,TZ+1);        
	   rnd_[5]=floor(rnd_[5]);
	   rnd_[6]=Z1-Z11-rnd_[5];
	   rnd_[7]=S1-S11-rnd_[5];
	   rnd_[8]=T2-rnd_[5]-rnd_[6]-rnd_[7];

	   zlr_1=0;		 			
					vektor[1]=rnd_[1];  // P_
					vektor[2]=rnd_[2];
					vektor[3]=rnd_[3];
					vektor[4]=rnd_[4];
					vektor[5]=rnd_[5];
					vektor[6]=rnd_[6];
					vektor[7]=rnd_[7];
					vektor[8]=rnd_[8];
		P_= fn_hg_( vektor, 1);
			
		                                     sd= qzufall(sd,0,1);	
		                        crit=qzufall(sd,0,Px/30000); //wahrscheinlichkeitsfilter in gleichverteilung
		if( P_ >= crit)
		{	
			//for(iLauf=1; iLauf<=8;iLauf++) fprintf(out,"%.0f\t", rnd_[iLauf]);fprintf(out,"\n");//
			fprintf(out,"%.16f\t", P_);fprintf(out,"\n");

			printf("%.0f  \r", M-zlr); //zähler
			
			if(rnd_[2] <= wert[2] )p++; // a <= rnd a -> p

			

			zlr++;
		}

		sd= qzufall(sd,50,100);
	}
	
	fclose(out);

	if (p/zlr > 0.5) p=1-p/zlr;

	fn_erg= p/2;

	return 0;
}

long double fn_grs_0(double wert[100])// FN0 // FN0 0,0         //
{
	//redundanzniveau sim
	int iLauf,kLauf,jLauf,S_;
	long double   sd, n_, M_,  R_, p_, niv[10], p_niv=0, p_add[20], p_add_=0,p_1=0,p_2=0,p_3=0,p_4=0,
		         p12=0,p13=0 ,p23=0, p14=0,p24=0 ,p34=0,p123=0,p124=0,p134=0,p234=0,p1234=0,
				 
				 n_01=0,n_02=0,n_03=0,n_04=0,n_05=0,n_06=0,n_07=0,n_08=0,n_09=0,n_10=0;

	n_= 100;
	
	M_= 5000;
	S_= 3;

	R_= 5000;

	niv[1]=0.05;
	niv[2]=0.01;
	niv[3]=0.02;
	niv[4]=0.21;

	fn_erg=0;
	

	sd=(time(0)-1234567890);

	for(iLauf=1;iLauf<= S_;iLauf++) p_add[iLauf]=0;

	printf("\r");

	for(kLauf=1;kLauf<= R_;kLauf++)
	{

		for(jLauf=1;jLauf<= M_;jLauf++)
		{
			for(iLauf=1;iLauf<= S_;iLauf++)
			{
				p_= qzufall(sd,0,n_)/n_;
				if(M_*S_==1000*1000)sd=(time(0)-1234567890);

				//if(p_<=niv)p_niv++;

				sd=p_*1234;

				if(iLauf<=0)
				{
					if(p_<= 0.1         ) n_01++;
					if(p_> 0.1&&p_<= 0.2) n_02++;
					if(p_> 0.2&&p_<= 0.3) n_03++;
					if(p_> 0.3&&p_<= 0.4) n_04++;
					if(p_> 0.4&&p_<= 0.5) n_05++;
					if(p_> 0.5&&p_<= 0.6) n_06++;
					if(p_> 0.6&&p_<= 0.7) n_07++;
					if(p_> 0.7&&p_<= 0.8) n_08++;
					if(p_> 0.8&&p_<= 0.9) n_09++;
					if(p_> 0.9&&p_<= 1.0) n_10++;
				
				}

				p_add[iLauf]=p_;

				p_niv=0;

			
				}
			
			if(S_==2)
			{
				if(p_add[1]<=niv[1])p_1++;
				if(p_add[2]<=niv[2])p_2++;
				if(p_add[1]<=niv[1] &&p_add[2]<=niv[2] ) p12++;
			}

			if(S_==3)
			{
				if(p_add[1]<=niv[1])p_1++;
				if(p_add[2]<=niv[2])p_2++;
				if(p_add[3]<=niv[3])p_3++;
				if(p_add[1]<=niv[1] &&p_add[2]<=niv[2] ) p12++;
				if(p_add[1]<=niv[1] &&p_add[3]<=niv[3] ) p13++;
				if(p_add[2]<=niv[2] &&p_add[3]<=niv[3] ) p23++;
				if(p_add[1]<=niv[1] &&p_add[2]<=niv[2] &&p_add[3]<=niv[3] ) p123++;
			
			}

			if(S_==4)
			{
				if(p_add[1]<=niv[1])p_1++;
				if(p_add[2]<=niv[2])p_2++;
				if(p_add[3]<=niv[3])p_3++;
				if(p_add[3]<=niv[3])p_4++;

				if(p_add[1]<=niv[1] &&p_add[2]<=niv[2] ) p12++;
				if(p_add[1]<=niv[1] &&p_add[3]<=niv[3] ) p13++;
				if(p_add[2]<=niv[2] &&p_add[3]<=niv[3] ) p23++;
				if(p_add[1]<=niv[1] &&p_add[4]<=niv[4] ) p14++;
				if(p_add[2]<=niv[2] &&p_add[4]<=niv[4] ) p24++;
				if(p_add[3]<=niv[3] &&p_add[4]<=niv[4] ) p34++;

				if(p_add[1]<=niv[1] &&p_add[2]<=niv[2]&&p_add[3]<=niv[3]  ) p123++;
				if(p_add[1]<=niv[1] &&p_add[2]<=niv[2]&&p_add[4]<=niv[4]  ) p124++;
				if(p_add[1]<=niv[1] &&p_add[3]<=niv[3]&&p_add[4]<=niv[4]  ) p134++;
				if(p_add[2]<=niv[2] &&p_add[3]<=niv[3]&&p_add[4]<=niv[4]  ) p234++;

				if(p_add[1]<=niv[1] &&p_add[2]<=niv[2] &&p_add[3]<=niv[3] &&p_add[4]<=niv[4]) p1234++;
			
			}
		}
	
		printf("R_M_=%i\r",kLauf*jLauf );

	}
	//printf("p(<=%.3f)= %.6f\n",niv,p_niv/M_ );

	for(iLauf=1;iLauf<= S_;iLauf++) p_add_+=p_add[iLauf];

	//fn_erg=fn_erg/S_;

	//fn_erg=p_add_/(S_*M_);
	if(S_==2)
	{
		printf("add1p(<=niv)= %.6f\n",(p_1+p_2-p12)  /(R_*M_) );//a oder b oder beide
		printf("add2p(<=niv)= %.6f\n",(p_1+p_2-2*p12)/(R_*M_) );//entweder a oder b 
		printf("multp(<=niv)= %.6f\n", p12           /(R_*M_) );//a und b
	}

	if(S_==3)
	{
		printf("add1p(<=niv)= %.6f\n",(p_1+p_2+p_3-p12-p13-p23+1*p123)  /(R_*M_) );//a oder b oder c oder mehrere
		printf("add2p(<=niv)= %.6f\n",(p_1+p_2+p_3-p12-p13-p23-2*p123)/(R_*M_)   );//entweder a oder b oder c
		printf("multp(<=niv)= %.6f\n", p123           /(R_*M_)                   );//a und b und c
		printf("addmin2p(<=niv)= %.6f\n",(p12+p13+p23-2*p123)  /(R_*M_)          );//mindestens2
	}

	if(S_==4)
	{
		printf("multp(<=niv)= %.6f\n", p1234 /(R_*M_)                            );//a und b und c und d
		printf("addmin3p(<=niv)= %.6f\n",(p123+p124+p134+p234-3*p1234)  /(R_*M_) );//mindestens3
	}
	//fn_erg= (p_1+p_2)/(R_*M_);

	//printf("%.3f\n%.3f\n%.3f\n%.3f\n%.3f\n%.3f\n%.3f\n%.3f\n%.3f\n%.3f\n",n_01/(R_*M_),n_02/(R_*M_),n_03/(R_*M_),n_04/(R_*M_),n_05/(R_*M_),n_06/(R_*M_),n_07/(R_*M_),n_08/(R_*M_),n_09/(R_*M_),n_10/(R_*M_));

	fn_erg=R_*M_;

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*
	//n zu variation V bei m

	//F(m,V) = n

	double iLauf, m_, V_;

	m_=6;
	V_=60480;

	for(iLauf=m_; iLauf<=170; iLauf++) if(variation_(iLauf,m_)==V_)printf("\nn=%.0f\n",iLauf);

	fn_erg=V_;
	

*/

	return 0;
};

