//----------------------------------------------------------------------------------------------------| calc_1 berechnungsprozedur, SCHRAUSSER 2009	//

#include "calc.h"
#include "calc_2.h"

main(int arg0c, char *arg0v[])
{
	FILE *tmpStream, *inStream, *ergStream, *outStream;

	fn[1]=0;//funktionsvektorinitialisierung
	operat[0]=0;

	ini_();//----------------------------------------------------------------------------------------> voreinstellungen
	
	strcpy(formel0, arg0v[1]);
    for (iLauf=2; iLauf < arg0c; iLauf++)
	{
	  strcat(formel0,arg0v[iLauf]);//----------------------------------------------------------------> formel0zeichensatzzusammenbau aus vektorzeiger arg0v
	}
	
	laenge = strlen(formel0);//----------------------------------------------------------------------> bestimmug der formel0 zeichensatzlänge
	//printf("\nformel0zeichensatz: %s\n\nformel0vektorlaenge= %i\n", formel0, laenge);//------------> bildschirmausgabe	
	
	//outStream = fopen( "MAT_log.txt", "a" );
	//fprintf(outStream,"\n%s= ", formel0);//--------------------------------------------------------> dateiausgabe der formel0	
	//fclose(outStream);

	tmpStream = fopen( "~tmp", "w" );
	fprintf(tmpStream,"%s",formel0);//---------------------------------------------------------------> formel0zeichensatzausgabe in tmp stream
	fclose(tmpStream);

	tmpStream = fopen( "~tmp", "r" );
	for(iLauf=1;iLauf<=laenge;iLauf++)
	{
		arg0 = fgetc (tmpStream );
		arg0_[iLauf]=arg0;//-------------------------------------------------------------------------> formel0vektorzusammenbau
	}
	fclose(tmpStream);

	//printf("\nformel0vektor: ");//-----------------------------------------------------------------> bildschirmausgabe
	//for(iLauf=1;iLauf<=laenge;iLauf++) printf("%c ",arg0_[iLauf]);
	//printf("\n");
	
	while(index0 <= laenge)//------------------------------------------------------------------------> Vektorenerstellung (Funktion, Wert, Operator)
	{
		tmpStream = fopen( "~tmp", "w" );
		
		while( arg0_[index0] != '=' && //------------------------------------------------------------> arg0umentarterkennungsschleife
			   arg0_[index0] != '+' &&  
			   sw_1 != 1          && 
			   sw_fn!= 1          && //--------------------------------------------------------------> wenn nicht funktion
			   arg0_[index0] != '*' && 
			   arg0_[index0] != '/' &&
			   arg0_[index0] != '%' &&
			   arg0_[index0] != 'h' &&
			   arg0_[index0] != 'v' &&
			   arg0_[index0] != ',' &&
			   index0 <= laenge ) 
		{
			//---------------------------------------------------------------------------------------> funktionsschalterzuweisung
			funktions_decl_1(arg0_, index0);


			if(sw_fn==0)//---------------------------------------------------------------------------> keine funktion
			{
				if(index0 > 1 && arg0_[index0] == '-' )//--------------------------------------------> x < 0 schaltung
					 if( arg0_[index0-1] != '=') 
					  if( arg0_[index0-1] != '+')
					   if( arg0_[index0-1] != '-')
						if( arg0_[index0-1] != '*')
						 if( arg0_[index0-1] != '/')
						  if( arg0_[index0-1] != '%')
						   if( arg0_[index0-1] != 'h')
						    if( arg0_[index0-1] != 'v')
							  if( arg0_[index0-1] != ',') sw_1 = 1;
				
				if(index0 > 1 && arg0_[index0] == '-' )//--------------------------------------------> x < 0 nach funktion schaltung 
				    if(sw_fn_1 == 1) sw_1 = 0;
						   
				sw_fn_1=0;//-------------------------------------------------------------------------> funktionsschalter 2 rückstellung
				
				if(sw_1==0){fprintf(tmpStream,"%c",arg0_[index0]);index0++;} //----------------------> wertzusammenbau und ausgabe in tmpstream
			}
		}// argumentarterkennungsschleife end
		
		sw_1 = 0;//----------------------------------------------------------------------------------> x < 0 schalterrückstellung
			   
		fclose(tmpStream);

		tmpStream = fopen( "~tmp", "r" );
		
		if(arg0_[index0] == '=') {fgets (erg0_,8,tmpStream ); erg0_var=1;}//-------------------------> ergbnisvariablenamen einlesen, ergebnisvariablenschalter	
		
		//-------------------------------------------------------------------------------------------> funktionsvektor zusammenbau (index0 erhöhung um anzahl funktionsbezeichner zeichenlänge -1)
		if(sw_fn==0) {fn[index1+1]=0;}
		
		if(sw_fn==1) index0=funktions_decl_2(arg0_, index0, index1);
	
		//-------------------------------------------------------------------------------------------> wertvektor zusammenbau
		if(arg0_[index0] != '=' && sw_fn==0) 
		{	
			fscanf (tmpStream, "%s", wert_var_ );//--------------------------------------------------> variablendateinamen einlesen
			fclose(tmpStream);
			tmpStream = fopen( "~tmp", "r" );
			fscanf (tmpStream, "%lf", &wert[index1] );//---------------------------------------------> wertvektor zusammenbau (direkteingabe)

			if(( atof(wert_var_) == 0.000000 &&  strncmp(wert_var_, "0.",2)  != 0
				                             &&  stricmp(wert_var_, "0"   )  != 0))//--------------> variable einlesen (bei variableneingabe)
			//if(atof(wert_var_) != wert[index1])//vorversion
			{
				if (fopen (wert_var_, "r") == NULL  ) {printf(" bad Formula 'variable.0'\n"); exit(0);}
				else 
				{
					inStream = fopen( wert_var_, "r" );
					fscanf (inStream, "%s", inpt_ );//-----------------------------------------------> variablendateinamen einlesen
					fclose(inStream);
					inStream = fopen( wert_var_, "r" );
					fscanf (inStream, "%lf", &wert[index1] );//--------------------------------------> wertvektor zusammenbau (variableneingabe)
					fclose(inStream);
					if (atof(inpt_) != wert[index1]) {printf("bad Variable '%s'\n", wert_var_); exit(0);}
				}
			}
		}

		fclose(tmpStream);
		//-------------------------------------------------------------------------------------------> operatorvektor zusammenbau
		if(arg0_[index0] == '+') {operat[index1] = 1;index1++;}
		if(arg0_[index0] == '-') {operat[index1] = 2;index1++;}
		if(arg0_[index0] == '*') {operat[index1] = 3;index1++;}
		if(arg0_[index0] == '/') {operat[index1] = 4;index1++;}
		if(arg0_[index0] == '%') {operat[index1] = 5;index1++;}
		if(arg0_[index0] == 'h') {operat[index1] = 6;index1++;}
		if(arg0_[index0] == 'v') {operat[index1] = 7;index1++;}
		if(arg0_[index0] == ',') {operat[index1] = 8;index1++;}

		sw_fn=0;//-----------------------------------------------------------------------------------> funktionsschalter 1 rückstellung
		index0++;	
	}
	//printf("\nOperatorvektor: ");//----------------------------------------------------------------> bildschirmausgabe
	//for(iLauf=1;iLauf<index1+1;iLauf++) printf("%i ",operat[iLauf]);
	//printf("\nFunktionsvektor: ");//---------------------------------------------------------------> bildschirmausgabe
	//for(iLauf=1;iLauf<=index1;iLauf++) printf("%i ",fn[iLauf]);
	//printf("\n\n");

	//-----------------------------------------------------------------------------------------------| Arithmetische Funktionen
	funktions_decl_3(index1, wert);

	//printf("Wertvektor': ");//---------------------------------------------------------------------> bildschirmausgabe
	//for(iLauf=1;iLauf<=index1;iLauf++) printf("%.0f ",wert[iLauf]);
	//printf("\n\n");
	//printf("\n");
	
	//-----------------------------------------------------------------------------------------------| Arihmetische Operationen
	//-----------------------------------------------------------------------------------------------> potenzierung und wurzelziehung
	for(iLauf=1;iLauf<=index1;iLauf++)//-------------------------------------------------------------> index1 = anzahl der arg0umente (werte) 
	{				//index1-1 prüfen	
		if(operat[iLauf] == 6)//---------------------------------------------------------------------> operatorschalter potenz
		{ 
			if( wert[iLauf+1]<1 && wert[iLauf]<0)//--------------------------------------------------> potenz
			{
				wert[iLauf+1] = pow(-wert[iLauf],wert[iLauf+1]);//bei x<0, n<1
				wert[iLauf+1] = -wert[iLauf+1];
			}
			else
			{
				wert[iLauf+1] = pow(wert[iLauf],wert[iLauf+1]);
			}
			
			if(iLauf==1){operat[iLauf]=1;wert[iLauf]=0;}//-------------------------------------------> operatormodifikation
			else
			{
				if(operat[iLauf-1]<=2) wert[iLauf]=0;
				if(operat[iLauf-1] >2) wert[iLauf]=1;//---------------------------------------------->  wertmodifikation
				
				if(iLauf == 1) operat[iLauf]=1;//----------------------------------------------------> operatormodifikation
				if(iLauf > 1) operat[iLauf]=operat[iLauf-1];	
			}
		}

		if(operat[iLauf] == 7)//---------------------------------------------------------------------> operatorschalter wurzel
		{ 
			if( wert[iLauf]/2!=floor(wert[iLauf]/2) && wert[iLauf+1]<0)//----------------------------> wurzel
			{
				wert[iLauf+1] = pow(-wert[iLauf+1],1.0/wert[iLauf]);//bei x<0, n ungerade 
				wert[iLauf+1] = -wert[iLauf+1];
			}
			else
			{
				wert[iLauf+1] = pow(wert[iLauf+1],1.0/wert[iLauf]);
			}
			
			if(iLauf==1){operat[iLauf]=1;wert[iLauf]=0;}//-------------------------------------------> operatormodifikation
			else
			{
				if(operat[iLauf-1]<=2) wert[iLauf]=0;
				if(operat[iLauf-1] >2) wert[iLauf]=1;//---------------------------------------------->  wertmodifikation
				
				if(iLauf == 1) operat[iLauf]=1;//----------------------------------------------------> operatormodifikation
				if(iLauf > 1) operat[iLauf]=operat[iLauf-1];	
			}
		}
	}

	//-----------------------------------------------------------------------------------------------> punktrechnung
	for(iLauf=1;iLauf<=index1-1;iLauf++)//-----------------------------------------------------------> index1 = anzahl der arg0umente (werte)
	{                  //index0 prüfen
		if(operat[iLauf] > 2 && operat[iLauf] < 6)
		{
			if(operat[iLauf] == 3) wert[iLauf+1] *= wert[iLauf]; //----------------------------------> multiplikation
			if(operat[iLauf] == 4) 
			{
				if(wert[iLauf+1] != 0) wert[iLauf+1] = (wert[iLauf]/wert[iLauf+1]); //---------------> division
				if(wert[iLauf+1] == 0) {printf("%s Division by 0\n", wert_var_); exit(0);} 
			}
			
			if(operat[iLauf] == 5) //----------------------------------------------------------------> modulo division
			{
				sprintf(tmp,"%f", wert[iLauf]);   mod_Z = atoi(tmp); 
				sprintf(tmp,"%f", wert[iLauf+1]); mod_N = atoi(tmp); 
				wert[iLauf+1] = (mod_Z % mod_N); 
			}
				
			if(operat[iLauf-1]<=2) wert[iLauf]=0;//--------------------------------------------------> wertmodifikation
			if(operat[iLauf-1] >2) wert[iLauf]=1;
		
			if(iLauf == 1) operat[iLauf]=1;//--------------------------------------------------------> operatormodifikation
			if(iLauf > 1) operat[iLauf]=operat[iLauf-1];	
		}	
	}

	//printf("Wertvektor': ");//---------------------------------------------------------------------> bildschirmausgabe
	//for(iLauf=1;iLauf<=index1;iLauf++) printf("%.3f ",wert[iLauf]);
	//printf("\n\n");
	//printf("\n");
	
	//-----------------------------------------------------------------------------------------------> plusminusrechnung
	erg= wert[1];
	for(iLauf=1;iLauf<=index1-1;iLauf++)//-----------------------------------------------------------> index1 = anzahl der arg0umente (werte)
	{
		/*printf("%.3f",wert[iLauf]);
		if(iLauf != index1) 
		{	
			if(operat[iLauf] == 1) printf(" + ");
			if(operat[iLauf] == 2) printf(" - ");
		}*/	
			
		if(operat[iLauf] == 1) erg += wert[iLauf+1];//-----------------------------------------------> addition
	
		if(operat[iLauf] == 2) erg -= wert[iLauf+1];//-----------------------------------------------> subtraktion 		   
	}
	
	//-----------------------------------------------------------------------------------------------> bildschirmausgabe ergebnis 
	printf(erg_format_1,erg);

	//printf("\n");

	if (erg0_var == 1) //----------------------------------------------------------------------------> bei ergbnisvariablen definition 
	{
		ergStream = fopen( erg0_, "w" );
		
		fprintf (ergStream,erg_format_2, erg);//-----------------------------------------------------> ergebnisausgabe in variablenfile
		
		//printf ("\nergebisvariablendateiname: %s\n", erg0_);	
		fclose(ergStream);
	}

	outStream = fopen( "MAT_log.txt", "a" );	
	
	//-----------------------------------------------------------------------------------------------> dateiausgabe des ergebnisses
	fprintf(outStream,erg_format_2, erg);

	fclose(outStream);
	
	//system ("start notepad MAT_log.txt");
	//system ("cls");
	//system ("type MAT_log.txt");

	system("del ~tmp");//----------------------------------------------------------------------------> tmp stream löschung
	
	return 0;	
}

