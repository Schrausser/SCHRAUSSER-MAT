//----------------------------------------------------------------------------------------------------| calc_ funktionen, Tabellen, SCHRAUSSER 2010	//


double fn_tab_wp(double wert[100], int sw) // Tabelle zur Permutation zu m Klassen wP  // TBP m, min_n, max_n, min_k, max_k  //											                
{//noch zu implementieren
 	FILE *out;
	
	double  min_n, max_n, min_k, max_k, m_, dLauf[100], vektor[100];	       

	m_=   wert[1]; 
	min_n=wert[2];
	max_n=wert[3];
	min_k=wert[4];
	max_k=wert[5];

	out=fopen( "MAT_fn.txt", "w" );

	printf("\n\ncomputing wP ...");	
		
	// Permutationstabelle
	if(sw==1)
	if(m_==3) //gesamt Ck
	{
		for(dLauf[1]=min_n; dLauf[1]<= max_n; dLauf[1]++)//n
		{
			for(dLauf[2]=min_k; dLauf[2]<= max_k; dLauf[2]++)//k1
			{
				for(dLauf[3]=min_k; dLauf[3]<= max_k; dLauf[3]++)//k2
				{
					for(dLauf[4]=min_k; dLauf[4]<= max_k; dLauf[4]++)//k3
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
	}
	
	if(sw==2)
	if(m_==3) //k1+k2+k3=n wP
	{
		for(dLauf[1]=min_n; dLauf[1]<= max_n; dLauf[1]++)//n
		{
			for(dLauf[2]=1; dLauf[2]<= (max_n-1)/2; dLauf[2]++)//k1
			{
				for(dLauf[3]=1+dLauf[2]-1; dLauf[3]<= 2+dLauf[2]-1; dLauf[3]++)//k2
				{
					for(dLauf[4]=1; dLauf[4]<= max_n-1; dLauf[4]++)//k3
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
	}
	if(sw==2)
	if(m_==2) //k1+k2=n wP
	{
		for(dLauf[1]=min_n; dLauf[1]<= max_n; dLauf[1]++)//n
		{
			for(dLauf[2]=min_k; dLauf[2]<= max_k; dLauf[2]++)//k1
			{
				for(dLauf[3]=min_k; dLauf[3]<= max_k; dLauf[3]++)//k2
				{
					if(dLauf[2]+dLauf[3]==dLauf[1])//k1+k2=n
					if(dLauf[2]<=dLauf[3])fprintf(out,"(%.0f,%.0f) ", dLauf[2],dLauf[3]); //fprintf(out,"%.0f ", permutation_k(dLauf, 2+1))
				}
			}	
			fprintf(out,"\n");
		}
	}

	fclose(out);

	return 0;
};

double fn_tab_z(double wert[100], int sw) // z-Wert Tabelle // 
//                                                          // z zu z-Wert    (1) TBZ min_z,max_z,step //
//                                                          // p zu z-Wert    (2) TPZ min_z,max_z,step //
//                                                          // pa1 zu z-Wert  (3) T1Z min_z,max_z,step //
//                                                          // pa2 zu z-Wert  (4) T2Z min_z,max_z,step //
//                                                          // d zu z-Wert    (5) TDZ min_z,max_z,step //											                
{
 	FILE *out;
	
	double iLauf, jLauf, zlr=0;
	double  min_z, max_z, step, dfz=100000; // calculation über t-Verteilung, df=dfz

	out=fopen( "MAT_fn.txt", "w" );

	min_z =wert[1];
    max_z =wert[2];
	step = wert[3];

	if (min_z-floor(min_z)< 0.5) min_z=floor(min_z);
	if (min_z-floor(min_z)>=0.5) min_z=floor(min_z)+0.5;

	if (min_z<-6||max_z>6){printf("\n\ndesign.0 '-4<=z<=4'"); exit(0);} //-6<=z<=6
	if (min_z> max_z)     {printf("\n\ndesign.0 'min>max'");  exit(0);} //min>max
	if (step> 0.5)        {printf("\n\ndesign.0 'step>0.5'"); exit(0);} //step>0.5
	
	if (step>0)
	if (0.50/step>66000)  {printf("\n\nfile.0 'rows>66000'"); exit(0);} //zeilen max=66000

	// überschrift
	if(sw==1)fprintf(out,"z-Wert.\n");
	if(sw==2)fprintf(out,"Prozentrang p zu z-Wert.\n");
	if(sw==3)fprintf(out,"1-seitiges Signifikanzniveau pa1 zu z-Wert.\n");
	if(sw==4)fprintf(out,"2-seitiges Signifikanzniveau pa2 zu z-Wert.\n");
	if(sw==5)fprintf(out,"Dichte d zu z-Wert.\n");

	fprintf(out,"----------------");
	for(iLauf=min_z; iLauf<= max_z; iLauf+=0.5)fprintf(out,"--------");
	fprintf(out,"\n");
	
	fprintf(out,"        \tz\n");
	fprintf(out,"                ");
	for(iLauf=min_z; iLauf<= max_z; iLauf+=0.5)fprintf(out,"--------");
	fprintf(out,"\n");

	fprintf(out,"z+      \t", jLauf);
	for(iLauf=min_z; iLauf<= max_z; iLauf+=0.5)fprintf(out,"%.1f\t", iLauf);
	fprintf(out,"\n");
	fprintf(out,"----------------");
	for(iLauf=min_z; iLauf<= max_z; iLauf+=0.5)fprintf(out,"--------");
	fprintf(out,"\n");

	if(step==0)//eine zeile
	{
		fprintf(out,"0.00000 \t");
	
		for(iLauf=min_z; iLauf<= max_z; iLauf+=0.5)
		{
			if(sw==1)fprintf(out,"%.4f\t", iLauf                                   );//z-wert
			if(sw==2)fprintf(out,"%.5f\t", pt_funktion(iLauf,dfz)                  );//prozentrang p
			if(sw==3)if(iLauf<=0)fprintf(out,"%.4f\t", pt_funktion(iLauf,dfz)      );//signifikanzniveau pa1
			if(sw==3)if(iLauf> 0)fprintf(out,"%.4f\t", 1-pt_funktion(iLauf,dfz)    );
			if(sw==4)if(iLauf<=0)fprintf(out,"%.4f\t", 2*(pt_funktion(iLauf,dfz))  );//signifikanzniveau pa2
			if(sw==4)if(iLauf> 0)fprintf(out,"%.4f\t", 2*(1-pt_funktion(iLauf,dfz)));
			if(sw==5)fprintf(out,"%.4f\t", dz_funktion(iLauf)                      );//dichte d 
			
			zlr++;	
		}
		fprintf(out,"\n");
	}

	if(step>0)//mehrere zeilen
	for(jLauf=0; jLauf<= 0.5; jLauf+=step)
	{
		fprintf(out,"%.5f \t", jLauf);
	
		for(iLauf=min_z; iLauf<= max_z; iLauf+=0.5)
		{	
			if(iLauf+jLauf> max_z)  break;
			
			if(iLauf+jLauf< wert[1])fprintf(out,"      \t");
			
			if(iLauf+jLauf>= wert[1])
			{
				if(sw==1)fprintf(out,"%.4f\t", iLauf+jLauf                                         );//z-wert
				if(sw==2)fprintf(out,"%.5f\t", pt_funktion(iLauf+jLauf,dfz)                        );//prozentrang p 
				if(sw==3)if(iLauf+jLauf<=0)fprintf(out,"%.4f\t", pt_funktion(iLauf+jLauf,dfz)      );//signifikanzniveau pa1
				if(sw==3)if(iLauf+jLauf> 0)fprintf(out,"%.4f\t", 1-pt_funktion(iLauf+jLauf,dfz)    );
				if(sw==4)if(iLauf+jLauf<=0)fprintf(out,"%.4f\t", 2*(pt_funktion(iLauf+jLauf,dfz))  );//signifikanzniveau pa2
				if(sw==4)if(iLauf+jLauf> 0)fprintf(out,"%.4f\t", 2*(1-pt_funktion(iLauf+jLauf,dfz)));
				if(sw==5)fprintf(out,"%.4f\t", dz_funktion(iLauf+jLauf)                            );//dichte d 
				
				zlr++;
			}
		}
		fprintf(out,"\n");
	}

	fprintf(out,"----------------");
	for(iLauf=min_z; iLauf<= max_z; iLauf+=0.5)fprintf(out,"--------");
	fprintf(out,"\nSCHRAUSSER-MAT");//fusszeile

	fclose(out);

	fn_erg=zlr;

	return 0;
};

double fn_tab_t(double wert[100], int sw) // t-Wert Tabelle // 
//                                                          // t zu t-Wert          (1) TBT min_t,max_t,step     //
//                                                          // p zu t-Wert bei df   (2) TPT min_t,max_t,step, df //
//                                                          // pa1 zu t-Wert bei df (3) T1T min_t,max_t,step, df //
//                                                          // pa2 zu t-Wert bei df (4) T2T min_t,max_t,step, df //
//                                                          // d zu t-Wert bei df   (5) TDT min_t,max_t,step, df //											                
{
 	FILE *out;
	
	double iLauf, jLauf, zlr=0;
	double  min_t, max_t, step, df, twert[100];

	out=fopen( "MAT_fn.txt", "w" );

	min_t =wert[1];
    max_t =wert[2];
	step = wert[3];
	df   = wert[4];

	twert[2]=df;//bei dichte d

	if (min_t-floor(min_t)< 0.5) min_t=floor(min_t);
	if (min_t-floor(min_t)>=0.5) min_t=floor(min_t)+0.5;

	//if (min_t<-1000||max_t>1000){printf("\n\ndesign.0 '-1000<=t<=1000"); exit(0);} //-1000<=t<=1000
	if (min_t> max_t)     {printf("\n\ndesign.0 'min>max'");  exit(0);} //min>max
	if (step> 0.5)        {printf("\n\ndesign.0 'step>0.5'"); exit(0);} //step>0.5
	
	if (step>0)
	if (0.50/step>66000)  {printf("\n\nfile.0 'rows>66000'");; exit(0);} //zeilen max=66000

	// überschrift
	if(sw==1)fprintf(out,"t-Wert.\n");
	if(sw==2)fprintf(out,"Prozentrang p zu t-Wert bei df= %G.\n", df);
	if(sw==3)fprintf(out,"1-seitiges Signifikanzniveau pa1 zu t-Wert bei df= %G.\n", df);
	if(sw==4)fprintf(out,"2-seitiges Signifikanzniveau pa2 zu t-Wert bei df= %G.\n", df);
	if(sw==5)fprintf(out,"Dichte d zu t-Wert bei df= %G.\n", df);

	fprintf(out,"----------------");
	for(iLauf=min_t; iLauf<= max_t; iLauf+=0.5)fprintf(out,"--------");
	fprintf(out,"\n");
	
	fprintf(out,"        \tt\n");
	fprintf(out,"                ");
	for(iLauf=min_t; iLauf<= max_t; iLauf+=0.5)fprintf(out,"--------");
	fprintf(out,"\n");

	fprintf(out,"t+      \t", jLauf);
	for(iLauf=min_t; iLauf<= max_t; iLauf+=0.5)fprintf(out,"%.1f\t", iLauf);
	fprintf(out,"\n");
	fprintf(out,"----------------");
	for(iLauf=min_t; iLauf<= max_t; iLauf+=0.5)fprintf(out,"--------");
	fprintf(out,"\n");

	if(step==0)//eine zeile
	{
		fprintf(out,"0.00000 \t");
	
		for(iLauf=min_t; iLauf<= max_t; iLauf+=0.5)
		{
			if(sw==1)fprintf(out,"%.4f\t", iLauf                                  );//t-wert
			if(sw==2)fprintf(out,"%.4f\t", pt_funktion(iLauf,df)                  );//prozentrang p
			if(sw==3)if(iLauf<=0)fprintf(out,"%.4f\t", pt_funktion(iLauf,df)      );//signifikanzniveau pa1
			if(sw==3)if(iLauf> 0)fprintf(out,"%.4f\t", 1-pt_funktion(iLauf,df)    );
			if(sw==4)if(iLauf<=0)fprintf(out,"%.4f\t", 2*(pt_funktion(iLauf,df))  );//signifikanzniveau pa1
			if(sw==4)if(iLauf> 0)fprintf(out,"%.4f\t", 2*(1-pt_funktion(iLauf,df)));
			if(sw==5){twert[1]=iLauf; fprintf(out,"%.4f\t", dt_funktion(twert) );  }//dichte d 
			
			zlr++;	
		}
		fprintf(out,"\n");
	}

	if(step>0)//mehrere zeilen
	for(jLauf=0; jLauf<= 0.5; jLauf+=step)
	{
		fprintf(out,"%.5f \t", jLauf);
	
		for(iLauf=min_t; iLauf<= max_t; iLauf+=0.5)
		{	
			if(iLauf+jLauf> max_t)  break;
			
			if(iLauf+jLauf< wert[1])fprintf(out,"      \t");
			
			if(iLauf+jLauf>= wert[1])
			{
				if(sw==1)fprintf(out,"%.4f\t", iLauf+jLauf                                        );//t-wert
				if(sw==2)fprintf(out,"%.4f\t", pt_funktion(iLauf+jLauf,df)                        );//prozentrang p 
				if(sw==3)if(iLauf+jLauf<=0)fprintf(out,"%.4f\t", pt_funktion(iLauf+jLauf,df)      );//signifikanzniveau pa1
				if(sw==3)if(iLauf+jLauf> 0)fprintf(out,"%.4f\t", 1-pt_funktion(iLauf+jLauf,df)    );
				if(sw==4)if(iLauf+jLauf<=0)fprintf(out,"%.4f\t", 2*(pt_funktion(iLauf+jLauf,df))  );//signifikanzniveau pa2
				if(sw==4)if(iLauf+jLauf> 0)fprintf(out,"%.4f\t", 2*(1-pt_funktion(iLauf+jLauf,df)));
				if(sw==5){twert[1]=iLauf+jLauf;fprintf(out,"%.4f\t", dt_funktion(twert) );         }//dichte d 
				
				zlr++;
			}
		}
		fprintf(out,"\n");
	}

	fprintf(out,"----------------");
	for(iLauf=min_t; iLauf<= max_t; iLauf+=0.5)fprintf(out,"--------");
	fprintf(out,"\nSCHRAUSSER-MAT");//fusszeile

	fclose(out);

	fn_erg=zlr;

	return 0;
};

double fn_tab_x2(double wert[100], int sw) // x2-Wert Tabelle // 
//                                                          // x2 zu x2-Wert         (1) TBX min_x2,max_x2,step     //
//                                                          // p zu x2-Wert bei df   (2) TPX min_x2,max_x2,step, df //
//                                                          // pa1 zu x2-Wert bei df (3) T1X min_x2,max_x2,step, df //
//                                                          // pa2 zu x2-Wert bei df (4) T2X min_x2,max_x2,step, df //
//                                                          // d zu x2-Wert bei df   (5) TDX min_x2,max_x2,step, df //											                
{
 	FILE *out;
	
	double iLauf, jLauf, zlr=0;
	double  min_x2, max_x2, step, df, x2wert[100];

	out=fopen( "MAT_fn.txt", "w" );

	min_x2 =wert[1];
    max_x2 =wert[2];
	step = wert[3];
	df   = wert[4];

	x2wert[2]=df;//bei dichte d

	if (min_x2-floor(min_x2)< 0.5) min_x2=floor(min_x2);
	if (min_x2-floor(min_x2)>=0.5) min_x2=floor(min_x2)+0.5;

	if (sw!=1&&df<1)      {printf("\n\ndesign.0 'df<1'");     exit(0);} //df<1
	if (min_x2<0)         {printf("\n\ndesign.0 'min<0'");    exit(0);} //min<0
	if (min_x2> max_x2)   {printf("\n\ndesign.0 'min>max'");  exit(0);} //min>max
	if (step> 0.5)        {printf("\n\ndesign.0 'step>0.5'"); exit(0);} //step>0.5
	
	if (step>0)
	if (0.50/step>66000)  {printf("\n\nfile.0 'rows>66000"); exit(0);} //zeilen max=66000

	// überschrift
	if(sw==1)fprintf(out,"chi2-Wert.\n");
	if(sw==2)fprintf(out,"Prozentrang p zu chi\xb2-Wert bei df= %G.\n", df);
	if(sw==3)fprintf(out,"1-seitiges Signifikanzniveau pa1 zu chi\xb2-Wert bei df= %G.\n", df);
	if(sw==4)fprintf(out,"2-seitiges Signifikanzniveau pa2 zu chi\xb2-Wert bei df= %G.\n", df);
	if(sw==5)fprintf(out,"Dichte d zu chi\xb2-Wert bei df= %G.\n", df);

	fprintf(out,"----------------");
	for(iLauf=min_x2; iLauf<= max_x2; iLauf+=0.5)fprintf(out,"--------");
	fprintf(out,"\n");
	
	fprintf(out,"        \tchi2\n");
	fprintf(out,"                ");
	for(iLauf=min_x2; iLauf<= max_x2; iLauf+=0.5)fprintf(out,"--------");
	fprintf(out,"\n");

	fprintf(out,"chi2+   \t", jLauf);
	for(iLauf=min_x2; iLauf<= max_x2; iLauf+=0.5)fprintf(out,"%.1f\t", iLauf);
	fprintf(out,"\n");
	fprintf(out,"----------------");
	for(iLauf=min_x2; iLauf<= max_x2; iLauf+=0.5)fprintf(out,"--------");
	fprintf(out,"\n");

	if(step==0)//eine zeile
	{
		fprintf(out,"0.00000 \t");
	
		for(iLauf=min_x2; iLauf<= max_x2; iLauf+=0.5)
		{
			if(sw==1)fprintf(out,"%.4f\t", iLauf                                    );//x2-wert
			if(sw==2)fprintf(out,"%.4f\t", px_funktion(iLauf,df)                    );//prozentrang p
			if(df==1)
			if(sw==3)fprintf(out,"%.4f\t", (1-px_funktion(iLauf,df))/2              );//signifikanzniveau pa1 bei df=1 
			if(df!=1)
			if(sw==3)fprintf(out,"------\t"                                         );//signifikanzniveau pa1 bei df<>1   
			if(sw==4)fprintf(out,"%.4f\t", 1-px_funktion(iLauf,df)                  );//signifikanzniveau pa1
			if(sw==5){x2wert[1]=iLauf; fprintf(out,"%.4f\t", dx_funktion(x2wert) ); }//dichte d 
			
			zlr++;	
		}
		fprintf(out,"\n");
	}

	if(step>0)//mehrere zeilen
	for(jLauf=0; jLauf<= 0.5; jLauf+=step)
	{
		fprintf(out,"%.5f \t", jLauf);

		for(iLauf=min_x2; iLauf<= max_x2; iLauf+=0.5)
		{	
			if(iLauf+jLauf> max_x2)  break;
			
			if(iLauf+jLauf< wert[1])fprintf(out,"      \t");
			
			if(iLauf+jLauf>= wert[1])
			{
				if(sw==1)fprintf(out,"%.4f\t", iLauf+jLauf                                  );//x2-wert
				if(sw==2)fprintf(out,"%.4f\t", px_funktion(iLauf+jLauf,df)                  );//prozentrang p 
				if(df==1)
				if(sw==3)fprintf(out,"%.4f\t", (1-px_funktion(iLauf+jLauf,df))/2            );//signifikanzniveau pa1 bei df=1
				if(df!=1)
				if(sw==3)fprintf(out,"------\t"                                             );//signifikanzniveau pa1 bei df<>1 
				if(sw==4)fprintf(out,"%.4f\t", 1-px_funktion(iLauf+jLauf,df)                );//signifikanzniveau pa2
				if(sw==5){x2wert[1]=iLauf+jLauf;fprintf(out,"%.4f\t", dx_funktion(x2wert) );}//dichte d 
				
				zlr++;
			}
		}
		fprintf(out,"\n");
	}

	fprintf(out,"----------------");
	for(iLauf=min_x2; iLauf<= max_x2; iLauf+=0.5)fprintf(out,"--------");
	fprintf(out,"\nSCHRAUSSER-MAT");//fusszeile

	fclose(out);

	fn_erg=zlr;

	return 0;
};

double fn_tab_F(double wert[100], int sw) // F-Wert Tabelle // 
//                                                          // F zu F-Wert               (1) TBF min_F,max_F,step         //
//                                                          // p zu F-Wert bei df1,df2   (2) TPF min_F,max_F,step,df1,df2 //
//                                                          // pa1 zu F-Wert bei df1,df2 (3) T1F min_F,max_F,step,df1,df2 //
//                                                          // pa2 zu F-Wert bei df1,df2 (4) T2F min_F,max_F,step,df1,df2 //
//                                                          // d zu F-Wert bei df1,df2   (5) TDF min_F,max_F,step,df1,df2 //											                
{
 	FILE *out;
	
	double iLauf, jLauf, zlr=0;
	double  min_F, max_F, step, df1, df2,Fwert[100];

	out=fopen( "MAT_fn.txt", "w" );

	min_F =wert[1];
    max_F =wert[2];
	step = wert[3];
	df1  = wert[4];
	df2  = wert[5];

	if (df1-floor(df1)<  0.5) df1=floor(df1);//rundung
	if (df1-floor(df1)>= 0.5) df1= ceil(df1);

	if (df2-floor(df2)<  0.5) df2=floor(df2);
	if (df2-floor(df2)>= 0.5) df2= ceil(df2);

	Fwert[2]=df1;//bei dichte d
	Fwert[3]=df2;

	if (min_F-floor(min_F)< 0.5) min_F=floor(min_F);
	if (min_F-floor(min_F)>=0.5) min_F=floor(min_F)+0.5;

	//if (df1<1 || df2<1)  {printf("\n\ndesign.0 'df<1");     exit(0);} //df<1
	if (min_F<0)         {printf("\n\ndesign.0 'min<0'");;    exit(0);} //min<0
	if (min_F> max_F)    {printf("\n\ndesign.0 'min>max'");  exit(0);} //min>max
	if (step> 0.5)       {printf("\n\ndesign.0 'step>0.5'");; exit(0);} //step>0.5
	
	if (step>0)
	if (0.50/step>66000)  {printf("\n\nfile.0 'rows>66000'");; exit(0);} //zeilen max=66000

	// überschrift
	if(sw==1)fprintf(out,"F-Wert.\n");
	if(sw==2)fprintf(out,"Prozentrang p zu F-Wert bei df1= %G, df2= %G.\n", df1,df2);
	if(sw==3)fprintf(out,"1-seitiges Signifikanzniveau pa1 zu F-Wert bei df1= %G, df2= %G.\n", df1,df2);
	if(sw==4)fprintf(out,"2-seitiges Signifikanzniveau pa2 zu F-Wert bei df1= %G, df2= %G.\n", df1,df2);
	if(sw==5)fprintf(out,"Dichte d zu F-Wert bei df1= %G, df2= %G.\n", df1,df2);

	fprintf(out,"----------------");
	for(iLauf=min_F; iLauf<= max_F; iLauf+=0.5)fprintf(out,"--------");
	fprintf(out,"\n");
	
	fprintf(out,"        \tF\n");
	fprintf(out,"                ");
	for(iLauf=min_F; iLauf<= max_F; iLauf+=0.5)fprintf(out,"--------");
	fprintf(out,"\n");

	fprintf(out,"F+      \t", jLauf);
	for(iLauf=min_F; iLauf<= max_F; iLauf+=0.5)fprintf(out,"%.1f\t", iLauf);
	fprintf(out,"\n");
	fprintf(out,"----------------");
	for(iLauf=min_F; iLauf<= max_F; iLauf+=0.5)fprintf(out,"--------");
	fprintf(out,"\n");

	if(step==0)//eine zeile
	{
		fprintf(out,"0.00000 \t");
	
		for(iLauf=min_F; iLauf<= max_F; iLauf+=0.5)
		{
			if(sw==1)fprintf(out,"%.4f\t", iLauf                                  );//F-wert
			if(sw==2)fprintf(out,"%.4f\t", pf_funktion(iLauf,df1,df2 )            );//prozentrang p
			if(df1==1 && df2>=7000)
			if(sw==3)fprintf(out,"%.4f\t", (1-pf_funktion(iLauf,df1,df2))/2       );//signifikanzniveau pa1 bei df1=1, df2->oo 
			if(df1!=1)
			if(sw==3)fprintf(out,"------\t"                                       );//signifikanzniveau pa1 bei df1<>1   
			if(sw==4)fprintf(out,"%.4f\t", 1-pf_funktion(iLauf,df1,df2)           );//signifikanzniveau pa2
			if(sw==5){Fwert[1]=iLauf; fprintf(out,"%.4f\t", df_funktion(Fwert) ); }//dichte d 
			
			zlr++;	
		}
		fprintf(out,"\n");
	}

	if(step>0)//mehrere zeilen
	for(jLauf=0; jLauf<= 0.5; jLauf+=step)
	{
		fprintf(out,"%.5f \t", jLauf);

		for(iLauf=min_F; iLauf<= max_F; iLauf+=0.5)
		{	
			if(iLauf+jLauf> max_F)  break;
			
			if(iLauf+jLauf< wert[1])fprintf(out,"      \t");
			
			if(iLauf+jLauf>= wert[1])
			{
				if(sw==1)fprintf(out,"%.4f\t", iLauf+jLauf                                );//F-wert
				if(sw==2)fprintf(out,"%.4f\t", pf_funktion(iLauf+jLauf,df1,df2)           );//prozentrang p 
				if(df1==1 && df2>=7000)
				if(sw==3)fprintf(out,"%.4f\t", (1-pf_funktion(iLauf+jLauf,df1,df2))/2     );//signifikanzniveau pa1 bei df1=1, df2->oo
				if(df1!=1)
				if(sw==3)fprintf(out,"------\t"                                           );//signifikanzniveau pa1 bei df1<>1 
				if(sw==4)fprintf(out,"%.4f\t", 1-pf_funktion(iLauf+jLauf,df1,df2)         );//signifikanzniveau pa2
				if(sw==5){Fwert[1]=iLauf+jLauf;fprintf(out,"%.4f\t", df_funktion(Fwert) );}//dichte d 
				
				zlr++;
			}
		}
		fprintf(out,"\n");
	}

	fprintf(out,"----------------");
	for(iLauf=min_F; iLauf<= max_F; iLauf+=0.5)fprintf(out,"--------");
	fprintf(out,"\nSCHRAUSSER-MAT");//fusszeile

	fclose(out);

	fn_erg=zlr;

	return 0;
};

double fn_tab_binom(double wert[100], int sw) // Tabellen zur Binomialverteilung  // 
//                                                                                // P0      (1) TBB p, min_k,max_k, min_n,max_n   //
//                                                                                // p       (2) TWB p, min_k,max_k, min_n,max_n   //
//                                                                                // pexact1 (3) T1B p, min_k,max_k, min_n,max_n   //
//                                                                                // pexact2 (4) T2B p, min_k,max_k, min_n,max_n   //											                
{
 	FILE *out;
	
	double iLauf, jLauf, zlr=0;
	double p, min_n, max_n, min_k, max_k, pkn[100], ab[100];

	out=fopen( "MAT_fn.txt", "w" );

	p=     wert[1]; //N/K=p
	min_k= wert[2];
    max_k= wert[3];
	min_n= wert[4];
    max_n= wert[5];

	pkn[1]=p;

	if (min_k<0      || min_n<0)         {printf("\n\ndesign.0 'min<0'");    exit(0);} //min<0
	if (min_k> max_k || min_n> max_n)    {printf("\n\ndesign.0 'min>max'");  exit(0);} //min>max

	if (max_n-min_n>66000)  {printf("\n\nfile.0 'rows>66000"); exit(0);} //zeilen max=66000

	if(sw==1)printf("\n\ncomputing P0 ...");	
	if(sw==2)printf("\n\ncomputing p ...");	
	if(sw==3)printf("\n\ncomputing pexact1 ...");
	if(sw==4)printf("\n\ncomputing pexact2 ...");

	// überschrift
	if(sw==1)fprintf(out,"Binomiale Punkt-Wahrscheinlichkeit P0 bei K/N=p= %G.\n", p);
	if(sw==2)fprintf(out,"Binomiale Wahrscheinlichkeit p bei K/N=p= %G.\n", p);
	if(sw==3)fprintf(out,"Exakt binomiales 1-seitiges Signifikanzniveau pexact1 bei K/N=p= %G.\n", p);
	if(sw==4)fprintf(out,"Exakt binomiales 2-seitiges Signifikanzniveau pexact2 bei K/N=p= %G.\n", p);

	fprintf(out,"----------------");
	for(iLauf=min_k; iLauf<= max_k; iLauf++)fprintf(out,"--------");
	fprintf(out,"\n");
	
	fprintf(out,"        \tk(=a)\n");
	fprintf(out,"                ");
	for(iLauf=min_k; iLauf<= max_k; iLauf++)fprintf(out,"--------");
	fprintf(out,"\n");

	fprintf(out,"n(=a+b) \t", jLauf);
	for(iLauf=min_k; iLauf<= max_k; iLauf++)fprintf(out,"%.0f\t", iLauf);
	fprintf(out,"\n");
	fprintf(out,"----------------");
	for(iLauf=min_k; iLauf<= max_k; iLauf++)fprintf(out,"--------");
	fprintf(out,"\n");

	for(pkn[3]=min_n; pkn[3]<= max_n; pkn[3]++)
	{
		fprintf(out,"%7.0f \t", pkn[3]);

		for(pkn[2]=min_k; pkn[2]<= max_k; pkn[2]++)
		{	
			if(pkn[2]>pkn[3]) break;
		
			if(sw==1)fprintf(out,"%.5f\t",fn_binom(pkn, 2)                                     );//P0
			if(sw==2)fprintf(out,"%.4f\t",fn_binom(pkn, 1)                                     );//p 
			if(p==0.5)
			if(sw==3){ab[1]=pkn[2]; ab[2]=pkn[3]-pkn[2];fprintf(out,"%.4f\t",fn_binom_t(ab, 2));}//signifikanzniveau pexact1 bei N/K=p=0.5
			if(p==0.5)
			if(sw==4){ab[1]=pkn[2]; ab[2]=pkn[3]-pkn[2];fprintf(out,"%.4f\t",fn_binom_t(ab, 3));}//signifikanzniveau pexact2 bei N/K=p=0.5
			if(p!=0.5)if(sw>=3)fprintf(out,"------\t");    

			zlr++;
		}
		fprintf(out,"\n");
	}

	fprintf(out,"----------------");
	for(iLauf=min_k; iLauf<= max_k; iLauf++)fprintf(out,"--------");
	fprintf(out,"\nSCHRAUSSER-MAT");//fusszeile

	fclose(out);

	printf("\r                                               \r" );

	fn_erg=zlr;

	return 0;
};

double fn_tab_hygeo(double wert[100], int sw) // Tabellen zur 
//                                            // hypergeometrischen Verteilung  //             
//                                                                              // P0      (1) TBH K,N, min_k,max_k, min_n,max_n   //
//                                                                              // p       (2) TWH K,N, min_k,max_k, min_n,max_n   //
//                                                                              // pexact1 (3) T1H K,N, min_k,max_k, min_n,max_n   //
//                                                                              // pexact2 (4) T2H K,N, min_k,max_k, min_n,max_n   //											                
//                                                                              // 2x2C    (5) TCH K,N, min_k,max_k, min_n,max_n   //											                

{
 	FILE *out;
	
	double iLauf, jLauf, zlr=0;
	double K,N, min_n, max_n, min_k, max_k, pkn[100], ab[100];

	out=fopen( "MAT_fn.txt", "w" );

	K=     wert[1]; //N/K=p
	N=     wert[2];
	min_k= wert[3];
    max_k= wert[4];
	min_n= wert[5];
    max_n= wert[6];

	pkn[3]=N;
	pkn[4]=K;

	if (K>N)                             {printf("\n\ndesign.0 'K>N'");      exit(0);} //K>N
	if (min_k<0      || min_n<0)         {printf("\n\ndesign.0 'min<0'");    exit(0);} //min<0
	if (min_k> max_k || min_n> max_n)    {printf("\n\ndesign.0 'min>max'");  exit(0);} //min>max
	if (min_n>N)                         {printf("\n\ndesign.0 'n>N'");      exit(0);} //n>N
	if (min_k>N)                         {printf("\n\ndesign.0 'k>N'");      exit(0);} //k>N

	if (max_n-min_n>66000)  {printf("\n\nfile.0 'rows>66000"); exit(0);} //zeilen max=66000

	if(sw==1)printf("\n\ncomputing P0 ...");	
	if(sw==2)printf("\n\ncomputing p ...");	
	if(sw==3)printf("\n\ncomputing pexact1 ...");
	if(sw==4)printf("\n\ncomputing pexact2 ...");

	// überschrift
	if(sw==1)fprintf(out,"Hypergeometrische Punkt-Wahrscheinlichkeit P0 bei K(=a+b)= %.0f, N(=a+b+c+d)= %.0f.\n", K,N);
	if(sw==2)fprintf(out,"Hypergeometrische Wahrscheinlichkeit p bei K(=a+b)= %.0f, N(=a+b+c+d)= %.0f.\n", K,N);
	if(sw==3)fprintf(out,"Exakt hypergeometrisches 1-seitiges Signifikanzniveau pexact1 bei K(=a+b)= %.0f, N(=a+b+c+d)= %.0f.\n", K,N);
	if(sw==4)fprintf(out,"Exakt hypergeometrisches 2-seitiges Signifikanzniveau pexact2 bei K(=a+b)= %.0f, N(=a+b+c+d)= %.0f.\n", K,N);
	if(sw==5)fprintf(out,"Kombinationen C zu den 2x2 Felder Anordnungen bei K(=a+b)= %.0f, N(=a+b+c+d)= %.0f.\n", K,N);

	fprintf(out,"----------------");
	for(iLauf=min_k; iLauf<= max_k; iLauf++)fprintf(out,"--------");
	fprintf(out,"\n");
	
	fprintf(out,"        \tk(=a)\n");
	fprintf(out,"                ");
	for(iLauf=min_k; iLauf<= max_k; iLauf++)fprintf(out,"--------");
	fprintf(out,"\n");

	fprintf(out,"n(=a+c) \t", jLauf);
	for(iLauf=min_k; iLauf<= max_k; iLauf++)fprintf(out,"%.0f\t", iLauf);
	fprintf(out,"\n");
	fprintf(out,"----------------");
	for(iLauf=min_k; iLauf<= max_k; iLauf++)fprintf(out,"--------");
	fprintf(out,"\n");

	for(pkn[2]=min_n; pkn[2]<= max_n; pkn[2]++)
	{
		fprintf(out,"%7.0f \t", pkn[2]);

		for(pkn[1]=min_k; pkn[1]<= max_k; pkn[1]++)
		{	
			if(pkn[1]>pkn[2]) break;

			if(sw==1)fprintf(out,"%.5f\t",fn_hygeo(pkn, 2)     );//P0
			if(sw==2)fprintf(out,"%.4f\t",fn_hygeo(pkn, 1)     );//p 
			if(sw>=3)
			{
				ab[1]=pkn[1];        ab[2]=K-pkn[1];
				ab[3]=pkn[2]-pkn[1]; ab[4]=N-ab[1]-ab[2]-ab[3];
				
				if(sw==3)fprintf(out,"%.4f\t",fn_2kf2(ab, 4, 1));//signifikanzniveau pexact1 
				if(sw==4)fprintf(out,"%.4f\t",fn_2kf2(ab, 4, 0));//signifikanzniveau pexact2   
		        if(sw==5)fprintf(out,"%.0f\t",fn_2kfc(ab, 4   ));//kombinationen 2x2C  
			}
			zlr++;
		}
		fprintf(out,"\n");
	}

	fprintf(out,"----------------");
	for(iLauf=min_k; iLauf<= max_k; iLauf++)fprintf(out,"--------");
	fprintf(out,"\nSCHRAUSSER-MAT");//fusszeile

	fclose(out);

	printf("\r                                               \r" );

	fn_erg=zlr;

	return 0;
};

double fn_tab_rnd(double wert[100]) // Quasi-Zufallszahlen Tabelle // TBR sd,min,max,n  //                                                                            
{
 	FILE *out;
	
	double iLauf, jLauf, zlr=0;
	double sd,  min, max, n, sp, zln;

	out=fopen( "MAT_fn.txt", "w" );


	sd=  fabs(wert[1]); if (wert[1]==-0.1) sd=0;
	min= wert[2];
    max= wert[3];
	n=   wert[4];

	if(n>11000){printf("\n\nfile.0 'n>11000'"); exit(0);} //n max=11000

	if (n<=200)          {sp=ceil(n/10);  zln=10;}
	if (n>200 && n<=400) {sp=ceil(n/20);  zln=20;}
	if (n>400 && n<=600) {sp=ceil(n/40);  zln=40;}
	if (n>600 && n<=840) {sp=ceil(n/60);  zln=60;}
	if (n>840 )          {sp=ceil(n/100); zln=100;}

	if (min> max )    {printf("\n\ndesign.0 'min>max'");  exit(0);} //min>max

	// überschrift
	if(sd==-1)fprintf(out,"Quasizufallszahl n(%G,%G) bei Anfangswert sd= Zeitwert.\n", min,max);
	if(sd==0)fprintf(out,"Quasizufallszahl n(%G,%G) bei Anfangswert sd= Zeitwert.\n", min,max);
	if(sd>0)fprintf(out,"Quasizufallszahl n(%G,%G) bei Anfangswert sd= %G.\n", min,max,sd);

	fprintf(out,"----------------");
	for(iLauf=0; iLauf< sp; iLauf+=1)fprintf(out,"--------");
	fprintf(out,"\n");
	
	fprintf(out,"        \ti\n");
	fprintf(out,"                ");
	for(iLauf=0; iLauf< sp; iLauf+=1)fprintf(out,"--------");
	fprintf(out,"\n");

	fprintf(out,"i+      \t", jLauf);
	for(iLauf=0; iLauf< sp; iLauf+=1)fprintf(out,"%.0f\t", iLauf*zln);
	fprintf(out,"\n");
	fprintf(out,"----------------");
	for(iLauf=0; iLauf< sp; iLauf+=1)fprintf(out,"--------");
	fprintf(out,"\n");

	for(iLauf=1; iLauf<= zln; iLauf++)
	{
		if(n<11)if(iLauf>n) break;
		fprintf(out,"%7.0f \t", iLauf);

		for(jLauf=0; jLauf< sp; jLauf+=1)
		{	
			if(jLauf*zln+iLauf>n) break;
		
			                      sd=qzufall(sd, min, max);
			if( wert[1]!=floor(wert[1]))fprintf(out,"%.2f\t", sd       );//RND
			if( wert[1]==floor(wert[1]))fprintf(out,"%.0f\t", zahl_0(sd));//RND gerundet bei sd ganzzahlig
			sd=pow(sd,2);
			
			zlr++;
		}
		fprintf(out,"\n");
	}

	fprintf(out,"----------------");
	for(iLauf=0; iLauf< sp; iLauf+=1)fprintf(out,"--------");
	fprintf(out,"\nSCHRAUSSER-MAT");//fusszeile

	fclose(out);

	printf("\r                                               \r" );

	fn_erg=zlr;

	return 0;
};


double fn_tab_korr(double wert[100], int sw) //  Tabellen zur Korrelation // 
//                                                                        // p zu r bei n   (1) TPK min_r,max_r, min_n,max_n, step //
//                                                                        // pa1 zu r bei n (2) T1K min_r,max_r, min_n,max_n, step //
//                                                                        // pa2 zu r bei n (3) T2K min_r,max_r, min_n,max_n, step //										                
{
 	FILE *out;
	
	double iLauf, jLauf, zlr=0;
	double  min_r, max_r, min_n, max_n, step, p;

	out=fopen( "MAT_fn.txt", "w" );

	min_r =wert[1];
    max_r =wert[2];
	min_n =wert[3];
    max_n =wert[4];
	step = wert[5];

	//if(min_n/2 !=floor(min_n/2)) min_n+=1; //n geradzahlig
	
	if (min_r> max_r || min_n> max_n)   {printf("\n\ndesign.0 'min>max'");  exit(0);} //min>max
	
	if(max_r!=min_r)
	{
		if (step> max_r-min_r  )        {printf("\n\ndesign.0 '>step'");    exit(0);} //step>max_r-min_r
		if (max_r-min_r/step>66000)     {printf("\n\nfile.0 'rows>66000'"); exit(0);} //zeilen max=66000
	}

	// überschrift
	if(sw==1)fprintf(out,"Prozentrang p zum Korrelationskoeffizienten r bei n= n1= n2.\n");
	if(sw==2)fprintf(out,"1-seitiges Signifikanzniveau pa1 zum Korrelationskoeffizienten r bei n= n1= n2.\n");
	if(sw==3)fprintf(out,"2-seitiges Signifikanzniveau pa2 zum Korrelationskoeffizienten r bei n= n1= n2.\n");
	;

	fprintf(out,"----------------");
	for(iLauf=min_n; iLauf<= max_n; iLauf++)fprintf(out,"--------");
	fprintf(out,"\n");
	
	fprintf(out,"        \tn\n");
	fprintf(out,"                ");
	for(iLauf=min_n; iLauf<= max_n; iLauf++)fprintf(out,"--------");
	fprintf(out,"\n");

	fprintf(out,"r       \t", jLauf);
	for(iLauf=min_n; iLauf<= max_n; iLauf++)fprintf(out,"%.0f\t", iLauf);
	fprintf(out,"\n");
	fprintf(out,"----------------");
	for(iLauf=min_n; iLauf<= max_n; iLauf++)fprintf(out,"--------");
	fprintf(out,"\n");

	if(max_r==min_r)
	{
		fprintf(out,"%7.4f \t", max_r);
		
		for(iLauf=min_n; iLauf<= max_n; iLauf++)
		{
				p= pt_funktion(fn_trw(max_r,iLauf),iLauf-2);
				
				if(sw==1 )fprintf(out,"%.4f\t",p        );//prozentrang p 
				
				if(sw==2 || sw==3)
				{
					if(p>0.5)p=1-p;
				    if(sw==2 )fprintf(out,"%.4f\t",   p );//signifikanzniveau pa1
				    if(sw==3 )fprintf(out,"%.4f\t", 2*p );//signifikanzniveau pa2
				}

				zlr++;
		}
		fprintf(out,"\n");
	}

	if(max_r!=min_r)
	for(jLauf=min_r; jLauf<= max_r; jLauf+=step)
	{
		fprintf(out,"%7.4f \t", jLauf);
	
		for(iLauf=min_n; iLauf<= max_n; iLauf++)
		{
				p= pt_funktion(fn_trw(jLauf,iLauf),iLauf-2);
				
				if(sw==1)fprintf(out,"%.4f\t",p        );//prozentrang p 
				
				if(sw==2 || sw==3 )
				{
					if(p>0.5)p=1-p;
				    if(sw==2)fprintf(out,"%.4f\t",   p );//signifikanzniveau pa1
				    if(sw==3)fprintf(out,"%.4f\t", 2*p );//signifikanzniveau pa2
				}
				zlr++;
		}
		fprintf(out,"\n");
	}

	fprintf(out,"----------------");
	for(iLauf=min_n; iLauf<= max_n; iLauf++)fprintf(out,"--------");
	fprintf(out,"\nSCHRAUSSER-MAT");//fusszeile

	fclose(out);

	fn_erg=zlr;

	return 0;
};

double fn_tab_F_sig(double wert[100]) // F-Wert Tabelle zu Niveau pa2 // 
//                                                                    // F-Wert (1) TFS pa2,min_df1,max_df1,min_df2,max_df2 //
{
 	FILE *out;
	
	double iLauf, jLauf, zlr=0;
	double  min_df1, max_df1, min_df2, max_df2, pa2;

	out=fopen( "MAT_fn.txt", "w" );

	pa2 = wert[1];
	min_df1 =wert[2];
    max_df1 =wert[3];
	min_df2 =wert[4];
    max_df2 =wert[5];
	
	if (pa2<=0||pa2>=1){printf("\n\ndesign.0 '0<pa2<1'"); exit(0);} //0<pa2<1

	if (min_df1<1||max_df1>1000||min_df2<1||max_df2>1000){printf("\n\ndesign.0 '1<=df1,df2<=1000'"); exit(0);} //1<=df1,df2<=1000
	if (min_df1> max_df1||min_df2> max_df2)     {printf("\n\ndesign.0 'min_df>max_df'");  exit(0);} //min_df>max_df
	
	// überschrift
	if(pa2<=0.00999999999)fprintf(out,"Kritischer F-Wert zum 2-seitigen %.0f\x89 Niveau pa2=%.3f bei df1 und df2.\n",pa2*1000,pa2);
	if(pa2> 0.00999999999)fprintf(out,"Kritischer F-Wert zum 2-seitigen %.0f%% Niveau pa2=%.2f bei df1 und df2.\n",pa2*100,pa2);

	fprintf(out,"----------------");
	for(iLauf=min_df1; iLauf<= max_df1; iLauf++)fprintf(out,"--------");
	fprintf(out,"\n");
	
	fprintf(out,"        \tdf1\n");
	fprintf(out,"                ");
	for(iLauf=min_df1; iLauf<= max_df1; iLauf++)fprintf(out,"--------");
	fprintf(out,"\n");

	fprintf(out,"df2     \t", jLauf);
	for(iLauf=min_df1; iLauf<= max_df1; iLauf++)fprintf(out,"%.0f\t", iLauf);
	fprintf(out,"\n");
	fprintf(out,"----------------");
	for(iLauf=min_df1; iLauf<= max_df1; iLauf++)fprintf(out,"--------");
	fprintf(out,"\n");

	if(min_df2==max_df2)//eine zeile
	{
		fprintf(out,"%.0f \t\t", max_df2);
	
		for(iLauf=min_df1; iLauf<= max_df1; iLauf++)
		{
			if(max_df2<3) fprintf(out,"%G\t", fp_funktion(1-pa2,iLauf,max_df2) );//F-Werte zu pa2 bei df1, df2
			if(max_df2>=3)fprintf(out,"%.3f\t", fp_funktion(1-pa2,iLauf,max_df2) );//F-Werte zu pa2 bei df1, df2
			
			zlr++;	
		}
		fprintf(out,"\n");
	}

	if(min_df2 < max_df2)//mehrere zeilen
	for(jLauf=min_df2; jLauf<= max_df2; jLauf++)
	{
		fprintf(out,"%.0f \t\t", jLauf);
	
		for(iLauf=min_df1; iLauf<= max_df1; iLauf++)
		{	

			if(jLauf<3) fprintf(out,"%G\t", fp_funktion(1-pa2, iLauf, jLauf)  );//F-Werte zu pa2 bei df1, df2
			if(jLauf>=3)fprintf(out,"%.3f\t", fp_funktion(1-pa2, iLauf, jLauf)  );//F-Werte zu pa2 bei df1, df2
			
			zlr++;
			
		}
		fprintf(out,"\n");
	}

	fprintf(out,"----------------");
	for(iLauf=min_df1; iLauf<= max_df1; iLauf++)fprintf(out,"--------");
	fprintf(out,"\nSCHRAUSSER-MAT");//fusszeile

	fclose(out);

	fn_erg=zlr;

	return 0;
};

double fn_tab_sig(double wert[100],int sw) // Tabelle Theta zu Niveau pa2 // 
//                                                                          // t-Wert  (1) TTS min_pa2,max_pa2,st, min_df,max_df    //
//                                                                          // x2-Wert (2) TXS min_pa2,max_pa2,st, min_df,max_df    //
//                                                                          // r(t)    (3) TRS min_pa2,max_pa2,st, min_n, max_n     //
//                                                                          // r(Z)    (4) TZS min_pa2,max_pa2,st, min_n, max_n     //
//                                                                          // R       (5) TMS min_pa2,max_pa2,st, min_n, max_n,  k //
//                                                                          // rxy.B   (6) TPS min_pa2,max_pa2,st, min_n, max_n,  k //
{
 	FILE *out;
	
	double iLauf, jLauf, zlr=0;
	double  min_pa2, max_pa2, min_df, max_df, st, vektor[10];

	out=fopen( "MAT_fn.txt", "w" );

	min_pa2 =wert[1];
    max_pa2 =wert[2];
	st      =wert[3];
	min_df  =wert[4];
    max_df  =wert[5];
	vektor[3]=wert[6];

	if ((max_pa2-min_pa2)/st>100)  {printf("\n\nfile.0 'cols>100'"); exit(0);} //spalten max=100
	
	if(sw<=2)if (min_df<1||max_df>1000){printf("\n\ndesign.0 '1<=df<=1000'"); exit(0);} //1<=df<=1000
	if (min_df> max_df)       {printf("\n\ndesign.0 'min_df>max_df'");  exit(0);} //min_df>max_df
	if (min_pa2>max_pa2)      {printf("\n\ndesign.0 'min_pa2>max_pa2'");  exit(0);} //min_pa2>max_pa2

	if (min_pa2<=0||max_pa2>=1||min_pa2>=1||max_pa2<=0){printf("\n\ndesign.0 '0<pa2<1'");  exit(0);} //0<pa2<1
	
	// überschrift
	if(sw==1)fprintf(out,"Kritischer \xb1t-Wert zum 2-seitigen Niveau pa2 bei df.\n");
	if(sw==2)fprintf(out,"Kritischer chi\xb2-Wert zum 2-seitigen Niveau pa2 bei df.\n");
	if(sw==3)fprintf(out,"Kritischer Korrelationskoeffizient \xb1r zum 2-seitigen Niveau pa2 bei n (t-Verteilung).\n");
	if(sw==4)fprintf(out,"Kritischer Korrelationskoeffizient \xb1r zum 2-seitigen Niveau pa2 bei n (Z-Verteilung).\n");
	if(sw==5)fprintf(out,"Kritischer Multipler-Korrelationskoeffizient R zum 2-seitigen Niveau pa2 bei n und k=%.0f.\n", vektor[3]);
	if(sw==6)fprintf(out,"Kritischer Partial-Korrelationskoeffizient rxy.B zum 2-seitigen Niveau pa2 bei n und k=%.0f.\n", vektor[3]);

	fprintf(out,"----------------");
	for(iLauf=min_pa2; iLauf<= max_pa2; iLauf+=st)fprintf(out,"--------");
	fprintf(out,"\n");
	
	fprintf(out,"        \tpa2\n");
	fprintf(out,"                ");
	for(iLauf=min_pa2; iLauf<= max_pa2; iLauf+=st)fprintf(out,"--------");
	fprintf(out,"\n");

	if(sw<=2)fprintf(out,"df      \t", jLauf);
	if(sw>=3)fprintf(out,"n       \t", jLauf);
	for(iLauf=min_pa2; iLauf<= max_pa2; iLauf+=st)fprintf(out,"%.4f\t", iLauf);
	fprintf(out,"\n");
	fprintf(out,"----------------");
	for(iLauf=min_pa2; iLauf<= max_pa2; iLauf+=st)fprintf(out,"--------");
	fprintf(out,"\n");

	if(min_df==max_df)//eine zeile
	{
		fprintf(out,"%.0f \t\t", max_df);
	
		for(iLauf=min_pa2; iLauf<= max_pa2; iLauf+=st)
		{
			vektor[1]=iLauf;
			vektor[2]=max_df;
			
			if(sw==1)fprintf(out,"%.3f\t", tp_funktion(1-iLauf/2,max_df) );//t-Werte zu pa2 bei df
			if(sw==2)fprintf(out,"%.2f\t", xp_funktion(1-iLauf,  max_df)  );//x2-Werte zu pa2 bei df
			if(sw==3)fprintf(out,"%.4f\t", fn_frpt(vektor)                );//r zu pa2 bei n (t)
			if(sw==4)fprintf(out,"%.4f\t", fn_frpz(vektor, 1)             );//r zu pa2 bei n (Z)
			if(sw==5)fprintf(out,"%.4f\t", fn_fmkp(vektor)                );//R zu pa2 bei n, k 
			if(sw==6)fprintf(out,"%.4f\t", fn_frpz(vektor, 2)             );//rxy.B zu pa2 bei n, k (Z)
			
			zlr++;	
		}
		fprintf(out,"\n");
	}

	if(min_df < max_df)//mehrere zeilen
	for(jLauf=min_df; jLauf<= max_df; jLauf++)
	{
		fprintf(out,"%.0f \t\t", jLauf);
	
		for(iLauf=min_pa2; iLauf<= max_pa2; iLauf+=st)
		{	
			vektor[1]=iLauf;
			vektor[2]=jLauf;

			if(sw==1)fprintf(out,"%.3f\t", tp_funktion(1-iLauf/2, jLauf)  );//t-Werte zu pa2 bei df
			if(sw==2)fprintf(out,"%.2f\t", xp_funktion(1-iLauf,   jLauf)  );//x2-Werte zu pa2 bei df
			if(sw==3)fprintf(out,"%.4f\t", fn_frpt(vektor)                );//r zu pa2 bei n (t)
			if(sw==4)fprintf(out,"%.4f\t", fn_frpz(vektor, 1)             );//r zu pa2 bei n (Z)
			if(sw==5)fprintf(out,"%.4f\t", fn_fmkp(vektor)                );//R zu pa2 bei n, k 
			if(sw==6)fprintf(out,"%.4f\t", fn_frpz(vektor, 2)             );//rxy.B zu pa2 bei n, k (Z)
				                             
			zlr++;
			
		}
		fprintf(out,"\n");
	}

	fprintf(out,"----------------");
	for(iLauf=min_pa2; iLauf<= max_pa2; iLauf+=st)fprintf(out,"--------");
	fprintf(out,"\nSCHRAUSSER-MAT");//fusszeile

	fclose(out);

	fn_erg=zlr;

	return 0;
};

double fn_tab_epsilon(double wert[100],int sw) // Tabellen zur Effektgroesse epsilon // 
//                                                                                   // pa2opt  (1) TPE min_e,max_e,st, min_n,max_n      //
//                                                                                   // nopt    (2) TNE min_e,max_e,st, min_pa2,max_pa2, stp  //
//                                                                                   // eopt    (3) TEE min_pa2,max_pa2,st, min_n, max_n //
{
 	FILE *out;
	
	double iLauf, jLauf, zlr=0, st1=1;
	double  min_q1, max_q1, min_q2, max_q2, st, vektor[10];

	out=fopen( "MAT_fn.txt", "w" );

	min_q1  =wert[1];
    max_q1  =wert[2];
	st      =wert[3];
	min_q2  =wert[4];
    max_q2  =wert[5];

	if(sw==2) st1= wert[6];

	if ((max_q1-min_q1)/st>100)  {printf("\n\nfile.0 'cols>100'"); exit(0);} //spalten max=100
	
	if(sw==1)//pa2opt
	{
		if (min_q2<2||max_q2>1000)        {printf("\n\ndesign.0 '2<=n<=1000'"); exit(0);} //2<=n<=1000
		if (min_q2> max_q2)               {printf("\n\ndesign.0 'min_n>max_n'");exit(0);} //min_n>max_n
		if (min_q1>max_q1)                {printf("\n\ndesign.0 'min_e>max_e'");exit(0);} //min_e>max_e
		if (min_q1<=0.001||max_q1>=2   ||
			min_q1>=2    ||max_q1<=0.001) {printf("\n\ndesign.0 '0.001<e<2'");  exit(0);} //0.001<e<2
	}

	if(sw==2)//nopt
	{
		if (min_q2<=0||max_q2>=1||
			min_q2>=1||max_q2<=0 )       {printf("\n\ndesign.0 '0<pa2<1'");        exit(0);} //0<pa2<1
		if (min_q2> max_q2)              {printf("\n\ndesign.0 'min_pa2>max_pa2'");exit(0);} //min_pa2>max_pa2
		if (min_q1>max_q1)               {printf("\n\ndesign.0 'min_e>max_e'");    exit(0);} //min_e>max_e
		if (min_q1<=0.001||max_q1>=2  ||
			min_q1>=2   ||max_q1<=0.001) {printf("\n\ndesign.0 '0.001<e<2'");      exit(0);} //0.001<e<2
	}

	if(sw==3)//eopt
	{
		if (min_q2<2||max_q2>1000)  {printf("\n\ndesign.0 '2<=n<=1000'");     exit(0);} //2<=n<=1000
		if (min_q2> max_q2)         {printf("\n\ndesign.0 'min_n>max_n'");    exit(0);} //min_n>max_n
		if (min_q1<=0||max_q1>=1||
			min_q1>=1||max_q1<=0 )  {printf("\n\ndesign.0 '0<pa2<1'");        exit(0);} //0<pa2<1
		if (min_q1> max_q1)         {printf("\n\ndesign.0 'min_pa2>max_pa2'");exit(0);} //min_pa2>max_pa2
	}

	// überschrift
	if(sw==1)fprintf(out,"Optimales 2-seitiges Niveau pa2opt zu Stichprobenumfang n bei Effektgröße epsilon, df=n-1.\n");
	if(sw==2)fprintf(out,"Optimaler Stichprobenumfang nopt zu kritischem Niveau pa2crit bei Effektgröße epsilon, (z-Verteilung).\n");
	if(sw==3)fprintf(out,"Optimale Effektgröße eopt zu Niveau pa2crit bei gegebenem Stichprobenumfang n, df=n-1.\n");
	
	fprintf(out,"----------------");
	for(iLauf=min_q1; iLauf<= max_q1; iLauf+=st)fprintf(out,"--------");
	fprintf(out,"\n");
	
	if(sw!=3)fprintf(out,"        \tepsilon\n");
	if(sw==3)fprintf(out,"        \tpa2\n");
	fprintf(out,"                ");
	for(iLauf=min_q1; iLauf<= max_q1; iLauf+=st)fprintf(out,"--------");
	fprintf(out,"\n");

	if(sw!=2)fprintf(out,"n       \t", jLauf);
	if(sw==2)fprintf(out,"pa2     \t", jLauf);
	for(iLauf=min_q1; iLauf<= max_q1; iLauf+=st)fprintf(out,"%.3f\t", iLauf);
	fprintf(out,"\n");
	fprintf(out,"----------------");
	for(iLauf=min_q1; iLauf<= max_q1; iLauf+=st)fprintf(out,"--------");
	fprintf(out,"\n");

	if(min_q2==max_q2)//eine zeile
	{
		fprintf(out,"%.0f \t\t", max_q2);
	
		for(iLauf=min_q1; iLauf<= max_q1; iLauf+=st)
		{	
			if(sw==1){vektor[1]=iLauf;vektor[2]=max_q2;;vektor[3]=max_q2-1;    }//pa2 zu e
			if(sw==2){vektor[1]=1-max_q2/2;vektor[2]=iLauf;;vektor[3]=100000;  }//n zu e
			if(sw==3){vektor[1]=1-iLauf/2;vektor[2]=max_q2;;vektor[3]=max_q2-1;}//e zu pa2
			
			if(sw==1)fprintf(out,"%.3f\t", 2*(fn_epsilon(vektor, 9) ) );//pa2 zu e
			if(sw==2)fprintf(out,"%.0f\t", fn_epsilon(vektor, 7)      );//n zu e
			if(sw==3)fprintf(out,"%.3f\t", fn_epsilon(vektor, 8)      );//e zu pa2
			
			zlr++;	
		}
		fprintf(out,"\n");
	}

	if(min_q2 < max_q2)//mehrere zeilen
	for(jLauf=min_q2; jLauf<= max_q2; jLauf+=st1)
	{
		if(sw!=2)fprintf(out,"%.0f \t\t", jLauf);
		if(sw==2)fprintf(out,"%.4f \t\t", jLauf);
	
		for(iLauf=min_q1; iLauf<= max_q1; iLauf+=st)
		{	
			if(sw==1){vektor[1]=iLauf;vektor[2]=jLauf;;vektor[3]=jLauf-1;     }//pa2 zu e
			if(sw==2){vektor[1]=1-jLauf/2;vektor[2]=iLauf;;vektor[3]=100000;  }//n zu e
			if(sw==3){vektor[1]=1-iLauf/2;vektor[2]=jLauf;;vektor[3]=jLauf-1; }//e zu pa2

			if(sw==1)fprintf(out,"%.3f\t", 2*(fn_epsilon(vektor, 9))  );//pa2 zu e
			if(sw==2)fprintf(out,"%.0f\t", fn_epsilon(vektor, 7)      );//n zu e
			if(sw==3)fprintf(out,"%.3f\t", fn_epsilon(vektor, 8)      );//e zu pa2
	                             
			zlr++;
		}
		fprintf(out,"\n");
	}

	fprintf(out,"----------------");
	for(iLauf=min_q1; iLauf<= max_q1; iLauf+=st)fprintf(out,"--------");
	fprintf(out,"\nSCHRAUSSER-MAT");//fusszeile

	fclose(out);

	fn_erg=zlr;

	return 0;
};

