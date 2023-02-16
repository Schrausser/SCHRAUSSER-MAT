//----------------------------------------------------------------------------------------------------| calc_ funktionen, Kombinatorik, SCHRAUSSER 2010	//
double fn_komb_m(double wert[100], double vn, int theta );

double fn_komb_m(double wert[100], double vn, int theta ) // Vollständige Kombinationsmatrizen  //
//                                                        // von Vektor x mit n zu m            //  
//                                                                                              // Kombination  C ohne Wh von n zu m (1) K_M m,x1,...,xn  
//                                                                                              // Kombination wC  mit Wh von n zu m (2) KWM m,x1,...,xn
//                                                                                              // Variation    V ohne Wh von n zu m (3) V_M m,x1,...,xn
//                                                                                              // Variation   wV  mit Wh von n zu m (4) VWM m,x1,...,xn
//                                                                                              // Permutation  P zu 1 Kl n          (5) P_M x1,...,xn
//                                                                                              // Permutation wP zu 2 Kl k1+k2=n    (6) P2M k1,k2,x1,...,xn  
{
	FILE *out;
	
	int iLauf, Lauf[100], vLauf[100], i_, sw=0;	       
	double  n_, m_, zlr=0, wp[100], c_wert[100], cmb;

	m_=wert[1];
	
	if(theta< 5) i_=1;
	if(theta==5) i_=0;
	if(theta==6) i_=2;
                        n_=vn-i_;
	for(iLauf=1; iLauf<=n_; iLauf++) c_wert[iLauf]= wert[iLauf+i_];
	
	if(theta==1 && n_<m_){printf("\n\ndesign.0 'n<m'"); exit(0);} //C n<m
	if(theta<=2 && m_>16){printf("\n\nt.0 'm>16'");  exit(0);} //C, wC begrenzt auf m<=16
	if(theta==3 && n_<m_){printf("\n\ndesign.0 'n<m'"); exit(0);} //V n<m
	if(theta==3 && m_>8) {printf("\n\nt.0 'm>8'");   exit(0);} //V  begrenzt auf m<=8
	if(theta==4 && m_>16){printf("\n\nt.0 'm>16'");  exit(0);} //wV begrenzt auf m<=16
	
	// dateilänge begrenzt auf zln<66000
	if(theta==1){cmb=kombination_(n_,m_);if(cmb>66000) {printf("\n\nfile.0 'C=%.0f>66000'", cmb);  exit(0);} } //C 
	if(theta==2){cmb=kombination_w(n_,m_);if(cmb>66000){printf("\n\nfile.0 'wC=%.0f>66000'", cmb); exit(0);} } //wC 
	if(theta==3){cmb=variation_(n_,m_);if(cmb>66000)   {printf("\n\nfile.0 'V=%.0f>66000'", cmb);  exit(0);} } //V 
	if(theta==4){cmb=pow(n_,m_);if(cmb>66000)          {printf("\n\nfile.0 'wV=%.0f>66000'", cmb); exit(0);} } //wV 

	//Permutation P als Variation V von n zu n
	if(theta==5) m_=n_; 
	if(theta==5 && n_>8) {printf("\n\nfile.0 'n>8'"); exit(0);} //P begrenzt auf n<=8
	
	//Permutation wP(2) als Kombination C von k1+k2=n zu k1
	if(theta==6) if(m_>wert[2]) m_=wert[2]; //m= kmin
	if(theta==6) if(wert[1]+wert[2]!=n_){printf("\n\ndesign.0 'k1+k2<>n'");  exit(0);} //k1+k2<>n
	                                
	                                  wp[1]=n_;
	                                  wp[2]=m_;
	                                  wp[3]=n_-m_;								 
	if(theta==6){ cmb=permutation_k(wp,2+1);if(cmb>66000)  {printf("\n\nfile.0 'wP=%.0f>66000'", cmb);  exit(0);} } //wP 

	
	for(Lauf[1]=1; Lauf[1]<=100; Lauf[1]++) vLauf[Lauf[1]]= 1; // 
	
	vLauf[1]=0;

	out=fopen( "MAT_fn.txt", "w" );

	if(theta<=2 )               printf("\n\ncomputing ci(xj) ..."); //C, wC
	if(theta==3 || theta==4 ) printf("\n\ncomputing vi(xj) ..."); //V, wV
	if(theta==5 && vn==8)  printf("\n\ncomputing pi(xj) ..."); //P
	if(theta==6  )              printf("\n\ncomputing pi(xj) ..."); //wP

	// Kombination C, wC, explizit
	if( theta<=2 && wert[1] >=5 ||
		theta==6 &&      m_ >=5  )
		
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
				if(theta==1 || theta==6)
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
				if(theta!=6){for(iLauf=1; iLauf<= 5; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");}
				
				// wP
				if(theta==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%.0f ", c_wert[Lauf[vLauf[1]]]);fprintf(out,"  ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%.0f ", c_wert[vLauf[1]]);//k2
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
				if(theta==1 || theta==6)
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
				if(theta!=6){for(iLauf=1; iLauf<= 6; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");}

				// wP
				if(theta==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%.0f ", c_wert[Lauf[vLauf[1]]]);fprintf(out,"  ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%.0f ", c_wert[vLauf[1]]);//k2
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
				if(theta==1 || theta==6)
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
				if(theta!=6){for(iLauf=1; iLauf<= 7; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");}
				
				// wP
				if(theta==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%.0f ", c_wert[Lauf[vLauf[1]]]);fprintf(out,"  ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%.0f ", c_wert[vLauf[1]]);//k2
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
				if(theta==1 || theta==6)
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
				if(theta!=6){for(iLauf=1; iLauf<= 8; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");}

				// wP
				if(theta==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%.0f ", c_wert[Lauf[vLauf[1]]]);fprintf(out,"  ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%.0f ", c_wert[vLauf[1]]);//k2
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
				if(theta==1 || theta==6)
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
				if(theta!=6){for(iLauf=1; iLauf<= 9; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");}

				// wP
				if(theta==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%.0f ", c_wert[Lauf[vLauf[1]]]);fprintf(out,"  ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%.0f ", c_wert[vLauf[1]]);//k2
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
				if(theta==1 || theta==6)
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
				if(theta!=6){for(iLauf=1; iLauf<= 10; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");}

				// wP
				if(theta==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%.0f ", c_wert[Lauf[vLauf[1]]]);fprintf(out,"  ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%.0f ", c_wert[vLauf[1]]);//k2
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
				if(theta==1 || theta==6)
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
				if(theta!=6){for(iLauf=1; iLauf<= 11; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");}

				// wP
				if(theta==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%.0f ", c_wert[Lauf[vLauf[1]]]);fprintf(out,"  ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%.0f ", c_wert[vLauf[1]]);//k2
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
				if(theta==1 || theta==6)
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
				if(theta!=6){for(iLauf=1; iLauf<= 12; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");}

				// wP
				if(theta==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%.0f ", c_wert[Lauf[vLauf[1]]]);fprintf(out,"  ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%.0f ", c_wert[vLauf[1]]);//k2
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
				if(theta==1 || theta==6)
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
				if(theta!=6){for(iLauf=1; iLauf<= 13; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");}

				// wP
				if(theta==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%.0f ", c_wert[Lauf[vLauf[1]]]);fprintf(out,"  ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%.0f ", c_wert[vLauf[1]]);//k2
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
				if(theta==1 || theta==6)
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
				if(theta!=6){for(iLauf=1; iLauf<= 14; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");}

				// wP
				if(theta==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%.0f ", c_wert[Lauf[vLauf[1]]]);fprintf(out,"  ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%.0f ", c_wert[vLauf[1]]);//k2
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
				if(theta==1 || theta==6)
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
				if(theta!=6){for(iLauf=1; iLauf<= 15; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");}

				// wP
				if(theta==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%.0f ", c_wert[Lauf[vLauf[1]]]);fprintf(out,"  ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%.0f ", c_wert[vLauf[1]]);//k2
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
				if(theta==1 || theta==6)
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
				if(theta!=6){for(iLauf=1; iLauf<= 16; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");}

				// wP
				if(theta==6) 
				{
					for(vLauf[1]=1; vLauf[1]<= m_; vLauf[1]++)fprintf(out,"%.0f ", c_wert[Lauf[vLauf[1]]]);fprintf(out,"  ");//k1
					
					for(vLauf[1]=1; vLauf[1]<= n_; vLauf[1]++)
					{
						    for(vLauf[2]=1; vLauf[2]<= m_; vLauf[2]++) // k1 k2 vergleich
						if(Lauf[vLauf[2]]==vLauf[1])
							sw=1; 
						if (sw==0) fprintf(out,"%.0f ", c_wert[vLauf[1]]);//k2
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
	if(  ((theta==3 || theta==4) && wert[1] >=7) ||
	     ( theta==5                && vn >=7)  )
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
				if(theta==3 || theta==5)
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
						for(iLauf=1; iLauf<= 7; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");
						zlr++;
					}
				}

				// wV
				if(theta==4)
				{
						for(iLauf=1; iLauf<= 7; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");
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
				if(theta==3 || theta==5)
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
						for(iLauf=1; iLauf<= 8; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");
						zlr++;
					}
				}

				// wV
				if(theta==4)
				{
						for(iLauf=1; iLauf<= 8; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");
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
			
			for(iLauf=1; iLauf<= 9; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");
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
			
			for(iLauf=1; iLauf<= 10; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");
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
			
			for(iLauf=1; iLauf<= 11; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");
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
			
			for(iLauf=1; iLauf<= 12; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");
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
			
			for(iLauf=1; iLauf<= 13; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");
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
			
			for(iLauf=1; iLauf<= 14; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");
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
			
			for(iLauf=1; iLauf<= 15; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");
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
			
			for(iLauf=1; iLauf<= 16; iLauf++)fprintf(out,"%.0f ", c_wert[Lauf[iLauf]]);fprintf(out,"\n");
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

	if( ( theta<=2              && wert[1] <5) || 
		((theta==3 || theta==4) && wert[1] <7) || 
		( theta==5              && vn      <7) ||
		( theta==6              && m_      <5   ) )
		
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
			if(theta==1 || theta==3 || theta==5 || theta==6)
			{
					   for(Lauf[1]=1; Lauf[1]<= m_; Lauf[1]++)
										for(Lauf[2]=Lauf[1]+1; Lauf[2]<=m_; Lauf[2]++) 
				if( ( vLauf[Lauf[1]]==vLauf[Lauf[2]] ) ) sw=1;
			}

			// anordnungswiederholungsprüfung bei C, wC, wP
			if(sw==0 && (theta==1 || theta==2 || theta==6) )
			{
					   for(Lauf[1]=1; Lauf[1]<= m_; Lauf[1]++)
										for(Lauf[2]=Lauf[1]+1; Lauf[2]<=m_; Lauf[2]++) 
				if( ( vLauf[Lauf[1]]>vLauf[Lauf[2]] ) ) sw=1;
			}

			// zeilenvektor ausgabe in datei
			if(sw==0)
			{
				// C, wC, V, wV, P
				if(theta<6){for(Lauf[1]=1; Lauf[1]<= m_; Lauf[1]++)fprintf(out,"%.0f ", c_wert[vLauf[Lauf[1]]]);fprintf(out,"\n");}
				                                                             //^^^^^^
				                                                            //Formatierung ggf auch für kommazahlen
				// wP
				if(theta==6)
				{
					for(Lauf[1]=1; Lauf[1]<= m_; Lauf[1]++)fprintf(out,"%.0f ", c_wert[vLauf[Lauf[1]]]);fprintf(out,"  "); // k1
					
					for(Lauf[1]=1; Lauf[1]<= n_; Lauf[1]++)
					{
						for(Lauf[2]=1; Lauf[2]<= m_; Lauf[2]++) if(vLauf[Lauf[2]]==Lauf[1])sw=1; // k1 k2 element vergleich
						
						if (sw==0) fprintf(out,"%.0f ", c_wert[Lauf[1]]); //k2
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

	return zlr;
};

double fn_komb_wp(double wert[100], int vn) // Vollständige Permutationsmatrix wP von Vektor x zu m Klassen  //   
//                                             (geschwindigkeitsmaximierend bei k1>k2>...>kn)                //  PMM m,k1,...km, x1,..,xn                                       											                
{
 	FILE *out;
	
	int iLauf[10], Lauf[100], pLauf[100],  sw=0, k_[100],i_=0,m_;
	double  n_, zlr=0 ,dLauf[100],  c_wert[100], vektor[100], wpm;
	int stellen, vorz, maxlng=1; //ecvt indizes: double -> string -> int	       
	
	m_= atoi(ecvt(wert[1],maxlng,&stellen,&vorz));
	n_=vn-(m_+1); 
	
	if(m_>9)  {printf("\n\ndesign.0 'm>9'\n");exit(0); }//begrenzt auf m<10
	if(m_>2)if(n_>12) {printf("\n\ndesign.0 'n>12'\n");exit(0);}//begrenzt auf n<12

	if(m_>2)for(Lauf[1]=2; Lauf[1]<= m_+1; Lauf[1]++){ if(wert[Lauf[1]]>=10) {printf("\n\ndesign.0 'ki>9'\n");exit(0);}}//begrenzt auf k<10
		
	for(Lauf[1]=1; Lauf[1]<= m_; Lauf[1]++)     k_[Lauf[1]]= atoi(ecvt(wert[Lauf[1]+1],maxlng,&stellen,&vorz));//k zuweisung
	for(Lauf[1]=1; Lauf[1]<= n_; Lauf[1]++) c_wert[Lauf[1]]= wert[Lauf[1]+1+m_];//wertvektor an c_wert
	for(Lauf[1]=1; Lauf[1]<= n_; Lauf[1]++)  pLauf[Lauf[1]]= 1;//pLauf zu 1

	if(m_==2)// bei m=2 über C
	{
		                                        vektor[1]=wert[2];
		                                        vektor[2]=wert[3];
		for(Lauf[1]=1; Lauf[1]<= n_; Lauf[1]++) vektor[Lauf[1]+2]= c_wert[Lauf[1]];
		
		                       fn_erg=fn_komb_m(vektor,n_+2,6);
		//exit(0);
	}

	// dateilänge begrenzt auf zln<66000
	                                          dLauf[1]=n_;
	for(Lauf[1]=2; Lauf[1]<= m_+1; Lauf[1]++) dLauf[Lauf[1]]= wert[Lauf[1]];
	if(  m_>2) { wpm=permutation_k(dLauf, m_+1); if(wpm>66000) {printf("\n\nfile.0 'wP>66000'");  exit(0);} }   
	
	pLauf[1]=0;

	out=fopen( "MAT_fn.txt", "w" );

	if(  m_>2) if(n_>=7)printf("\n\ncomputing pi(xj) ...");	
	
	//wP explizit
	if(  m_>2)
	if( (n_>=8 && n_<=12))
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
				for(iLauf[3]=1; iLauf[3]<=m_; iLauf[3]++)
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
					for(iLauf[3]=1; iLauf[3]<= m_; iLauf[3]++)
					{
						for(iLauf[1]=1; iLauf[1]<= k_[iLauf[3]]; iLauf[1]++) fprintf(out,"%.0f ", c_wert[Lauf[iLauf[1]+i_]]); 
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
				for(iLauf[3]=1; iLauf[3]<=m_; iLauf[3]++)
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
					for(iLauf[3]=1; iLauf[3]<= m_; iLauf[3]++)
					{
						for(iLauf[1]=1; iLauf[1]<= k_[iLauf[3]]; iLauf[1]++) fprintf(out,"%.0f ", c_wert[Lauf[iLauf[1]+i_]]); 
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
				for(iLauf[3]=1; iLauf[3]<=m_; iLauf[3]++)
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
					for(iLauf[3]=1; iLauf[3]<= m_; iLauf[3]++)
					{
						for(iLauf[1]=1; iLauf[1]<= k_[iLauf[3]]; iLauf[1]++) fprintf(out,"%.0f ", c_wert[Lauf[iLauf[1]+i_]]); 
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
				for(iLauf[3]=1; iLauf[3]<=m_; iLauf[3]++)
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
					for(iLauf[3]=1; iLauf[3]<= m_; iLauf[3]++)
					{
						for(iLauf[1]=1; iLauf[1]<= k_[iLauf[3]]; iLauf[1]++) fprintf(out,"%.0f ", c_wert[Lauf[iLauf[1]+i_]]); 
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
				for(iLauf[3]=1; iLauf[3]<=m_; iLauf[3]++)
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
					for(iLauf[3]=1; iLauf[3]<= m_; iLauf[3]++)
					{
						for(iLauf[1]=1; iLauf[1]<= k_[iLauf[3]]; iLauf[1]++) fprintf(out,"%.0f ", c_wert[Lauf[iLauf[1]+i_]]); 
						fprintf(out,"   ");//
						i_+=k_[iLauf[3]];
					}
					fprintf(out,"\n");
					printf("\rcomputing pi(xj) %.0f  ",wpm-zlr);
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
	}
	
	// wP allgemein
	if(m_>2)
	if(n_<8 || n_ >12 )
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
			for(Lauf[3]=1; Lauf[3]<=m_; Lauf[3]++)
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
			for(Lauf[3]=1; Lauf[3]<= m_; Lauf[3]++)
			{
				for(Lauf[1]=1; Lauf[1]<= k_[Lauf[3]]; Lauf[1]++) fprintf(out,"%.0f ", c_wert[pLauf[Lauf[1]+i_]]); 
				fprintf(out,"   ");//
				i_+=k_[Lauf[3]];
			}
			fprintf(out,"\n");
			i_=0;
			
			zlr++;
		}
		sw=0;
	}	 
	if(m_>2)
	if(n_>=7)printf("\r                                                                           \r ");

	if(m_>2)fn_erg=zlr;

	fclose(out);

	return 0;
};