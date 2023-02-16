//----------------------------------------------------------------------------------------------------| MAT2 von Dietmar Schrausser 2009    
//                                                                                                      calc_1 berechnungsprozedur integriert als funktion fn_calc_1 
#include "MAT2.h"
#include "MAT3.h"
#include "calc_2.h"
#include <process.h>

void fn_calc_1 ();

main(int argc, char *argv[])
{
	FILE *tmpStream, *calcStream, *outStream;

	system("color 78");//----------------------------------------------------------------------------> farbprofil

	if (argc == 1 ) _profil();//---------------------------------------------------------------------> profil
	
	ini_();//----------------------------------------------------------------------------------------> voreinstellungen

	if (strcmp(argv[1], "//") == 0 ) exit(0);//------------------------------------------------------> Kommentar
	if (strcmp(argv[1], "FN") == 0 ) _funktionsindex();//--------------------------------------------> funktionsindex
	if (strcmp(argv[1], "FNg") == 0 ) _funktionsindex_g();//-----------------------------------------> funktionsindex
	if (strcmp(argv[1], "MAT") == 0 ) //-------------------------------------------------------------> funktionsindex PDF
	{
		_spawnlp( _P_NOWAIT, "acrobat.exe", "acrobat.exe", "MAT_Funktionsindex.pdf", NULL );exit(0);
	}
	
	if (strcmp(argv[1], "DAT") == 0 ) //-------------------------------------------------------------> datenoutput
	{
		_spawnlp( _P_NOWAIT, "notepad.exe", "notepad.exe", "MAT_fn.txt", NULL );exit(0);
	}
	if (strcmp(argv[1], "DATR") == 0 ) //-------------------------------------------------------------> Reportfile
	{
		_spawnlp( _P_NOWAIT, "notepad.exe", "notepad.exe", "MAT_rep.txt", NULL );exit(0);
	}
	if (strcmp(argv[1], "DATX") == 0 ) //-------------------------------------------------------------> Rohdatenmatrix
	{
		_spawnlp( _P_NOWAIT, "notepad.exe", "notepad.exe", "MAT_X.txt", NULL );exit(0);
	}

	if (strcmp(argv[1], "REP") == 0 )//--------------------------------------------------------------> datenoutput->Reportfile
	{
		tmpStream = fopen( "MAT_fn.txt", "r" );
		outStream = fopen( "MAT_rep.txt","a" );
		 
		_strdate( dbuffer );_strtime( tbuffer );
		fprintf(outStream,"MAT-Report / %s @ %s\n\n", dbuffer , tbuffer);
	
		do{
			                          c_1 = fgetc(tmpStream);
			if (ind > 1) fputc (c_2, outStream); 
			                    c_2 = c_1;
			    ind++;

		}while (feof (tmpStream) == 0); 

		fprintf(outStream,"\n\n\n");

		fclose( tmpStream  );
		fclose( outStream );

		exit(0);
	}

	if (strcmp(argv[1], "R//") == 0 )//--------------------------------------------------------------> kommentaroutput->Reportfile
	{
		
		outStream = fopen( "MAT_rep.txt","a" );
		 
		_strdate( dbuffer );_strtime( tbuffer );
		fprintf(outStream,"MAT-Report / %s @ %s // ", dbuffer , tbuffer);
	
		for(iLauf=2;iLauf<argc;iLauf++)fprintf(outStream,"%s ", argv[iLauf]);
			                        
		fprintf(outStream,"//\n\n");

	
		fclose( outStream );

		exit(0);
	}

	if (strcmp(argv[1], "(X)") == 0 )//--------------------------------------------------------------> datenoutput->Rohdatenmatrix
	{
		tmpStream = fopen( "MAT_fn.txt", "r" );
		outStream = fopen( "MAT_X.txt","w" );
		 
	
		do{
			                          c_1 = fgetc(tmpStream);
			if (ind > 1) fputc (c_2, outStream); 
			                    c_2 = c_1;
			    ind++;

		}while (feof (tmpStream) == 0); 

		fclose( tmpStream  );
		fclose( outStream );

		exit(0);
	}


	calcStream = fopen( "clc_", "w" );fprintf(calcStream," ");fclose(calcStream);//------------------> initialisierung
	
	strcpy(formel, argv[1]);
    for (iLauf=2; iLauf < argc; iLauf++) strcat(formel,argv[iLauf]);//-------------------------------> formelzeichensatzzusammenbau aus vektorzeiger argv

	laenge = strlen(formel);//-----------------------------------------------------------------------> bestimmug der formel zeichensatzlänge
	if(laenge>600){printf("\nformula n%i>600 .0\n",laenge); exit(0);}//------------------------------> formel zu lang

	printf("\n");
	//printf("Formelzeichensatz: %s\n", formel);//---------------------------------------------------> bildschirmausgabe	
	strcpy(formel_, formel);//-----------------------------------------------------------------------> formel zeichensatzspiegelung zur ergebnisausgabe

	outStream = fopen( "MAT_log.txt", "a" );
	_strdate( dbuffer );_strtime( tbuffer );
	fprintf(outStream,"MAT (c) SCHRAUSSER 2009; %s %s;\n\n", dbuffer , tbuffer);
	fprintf(outStream,"%s:\n", formel);//------------------------------------------------------------> dateiausgabe der formel	
	fclose(outStream);

	tmpStream = fopen( "~tmp1", "w" );
	fprintf(tmpStream,"%s",formel);//----------------------------------------------------------------> formelzeichensatzausgabe in tmp stream
	fclose(tmpStream);

	tmpStream = fopen( "~tmp1", "r" );
	for(iLauf=1;iLauf<=laenge;iLauf++)
	{
		arg = fgetc (tmpStream );
		arg_[iLauf]=arg;//---------------------------------------------------------------------------> formelvektorzusammenbau
	}
	fclose(tmpStream);
	
	for(iLauf=1;iLauf<=laenge;iLauf++) if (arg_[iLauf] == '=') ist_zlr++;//--------------------------> = zähler

	if (ist_zlr > 1) {printf("bad formula '='\n"); exit(0);}//-----------------------------------------> istprüfung

	if (ist_zlr == 1)//------------------------------------------------------------------------------> ergebnisvariablentrennung
	{
		tmpStream = fopen( "~tmp1", "r" );arg = ' '; 
		for(iLauf=1;iLauf<=laenge;iLauf++)
		{
			arg = fgetc (tmpStream );
			if(arg=='=') {frml = 1; erg_ln=iLauf;}//-------------------------------------------------> bei erreichung von =, 
			if(frml==0) erg_[iLauf-1]=arg;//---------------------------------------------------------> ergebnisvariablennamenvektor (zu beachten:  erg_[0],erg_[1]... -> erg_[iLauf-1])
			if(frml==2) arg_[iLauf-erg_ln]=arg;//----------------------------------------------------> formelvektorneuzusammenbau
			if(frml==1) frml=2;//--------------------------------------------------------------------> zwischenschaltung zur = zeichen überspringung		
		}
		fclose(tmpStream);
		laenge = laenge - erg_ln;//------------------------------------------------------------------> formellängen anpassung (länge - länge ergebnisvariablenteil)
	
		tmpStream = fopen( "~tmp1", "w" );
		for(iLauf=1;iLauf<=laenge;iLauf++) fprintf(tmpStream,"%c",arg_[iLauf]);//--------------------> formelzeichensatzausgabe in tmp stream bei berechnung ohne klammerebenen
		fclose(tmpStream);
	}

	for(iLauf=1;iLauf<=laenge;iLauf++)//-------------------------------------------------------------> argumentbewertung 
	{	
		if (arg_[iLauf] == '(') klm_auf_zlr++;//-----------------------------------------------------> klammerzähler
		if (arg_[iLauf] == ')') klm_zu_zlr++;
		
		//-------------------------------------------------------------------------------------------> klammersetzungsprüfung	
		klammer_();

	}//argumentbewertung end	
	
	if (klm_auf_zlr ==1 && klm_zu_zlr == 1)
	if (arg_[1] == '(' && arg_[laenge] == ')') {printf("bad formula '(x)'\n"); exit(0);}//-------------> klammerprüfung auf sinn
	
	if (klm_auf_zlr > klm_zu_zlr) {printf("bad formula '(()'"); exit(0);}//--------------------------> klammerprüfung
	if (klm_auf_zlr < klm_zu_zlr) {printf("bad formula '())'"); exit(0);}//--------------------------> klammerprüfung
	

	if (klm_auf_zlr > 0 ) while( dg_zlr <= klm_auf_zlr)//---------------------------------------------| Klammerebenenschleife	
	{ 	
		if (dg_zlr > 0) //---------------------------------------------------------------------------> formelneuzusammenbau ~tmp1 + calc_ergebnis + ~tmp2
		{
			strcpy(tmp_1 ," ");//--------------------------------------------------------------------> ZEICHENSATZ SÄUBERUNG!
			tmpStream = fopen( "~tmp1", "r" );//-----------------------------------------------------> öffnen von ~tmp1
			fscanf (tmpStream,"%s",tmp_1);//---------------------------------------------------------> einlesn des formelbeginnteils
			fclose(tmpStream);
			
			strcpy(tmp_clc ," ");//------------------------------------------------------------------> ZEICHENSATZ SÄUBERUNG!
			tmpStream = fopen( "clc_", "r" );//------------------------------------------------------> öffnen der berechnungsergebnisdatei
			fscanf (tmpStream,"%s",tmp_clc);//-------------------------------------------------------> einlesen des subformelergebnisses
			fclose(tmpStream);

			strcpy(tmp_2 ," ");//--------------------------------------------------------------------> ZEICHENSATZ SÄUBERUNG!
			tmpStream = fopen( "~tmp2", "r" );//-----------------------------------------------------> öffnen von ~tmp2
			fscanf (tmpStream,"%s",tmp_2);//---------------------------------------------------------> einlesen des formelendteils
			fclose(tmpStream);

			tmpStream = fopen( "~tmp1", "w" );//-----------------------------------------------------> öffnen von ~tmp1
			fprintf (tmpStream, "%s%s%s",tmp_1,tmp_clc, tmp_2);//------------------------------------> formelzusammenbau 
			
			fclose(tmpStream);
		
			tmpStream = fopen( "~tmp1", "r" );//-----------------------------------------------------> öffnen von ~tmp1
			fscanf (tmpStream,"%s",formel);//--------------------------------------------------------> einlesen des formelendteils
			fclose(tmpStream);

			laenge = strlen(formel);//---------------------------------------------------------------> bestimmung der neuen formellänge 
			//printf("\nFormelzeichensatz': %s\n", formel);//----------------------------------------> bildschirmausgabe
			printf("\n");
			
			tmpStream = fopen( "~tmp1", "w" );
			fprintf(tmpStream,"%s",formel);//--------------------------------------------------------> formelzeichensatzausgabe in tmp stream
			fclose(tmpStream);

			tmpStream = fopen( "~tmp1", "r" );
			for(iLauf=1;iLauf<=laenge;iLauf++)
			{
				arg = fgetc (tmpStream );
				arg_[iLauf]=arg;//-------------------------------------------------------------------> formelvektorneuzusammenbau
			}
			fclose(tmpStream);

			index=1;klm_zlr=0;
		}
		if(dg_zlr == klm_auf_zlr) dg_zlr++;//--------------------------------------------------------> letzter durchgang ohne klammerlösungen
		if(dg_zlr < klm_auf_zlr) tmpStream = fopen( "~tmp1", "w" );//--------------------------------> öffnen der beginn formel datei ~tmp1
		if(dg_zlr < klm_auf_zlr) while(index <= laenge)//--------------------------------------------> klammerlösungsschleife
		{
			while( arg_[index] != '(' && index <= laenge)//------------------------------------------> bis auf_klammer 
			{
					fprintf(tmpStream,"%c",arg_[index]);index++;//-----------------------------------> wertausgabe in tmpstream
			}
			
			if(arg_[index] == '(')//-----------------------------------------------------------------> bei auf_klammer  
			{
				klm_zlr++;//-------------------------------------------------------------------------> klammerzähler
				
				if( klm_zlr == klm_auf_zlr-dg_zlr)//-------------------------------------------------> bei erreichen der letzten auf_klammer 
				{
					calcStream = fopen( "~calc", "w" );
					
					while( arg_[index] != ')' )//----------------------------------------------------> bis zu_klammer 
					{   
						if(arg_[index] != '(') fprintf(calcStream,"%c",arg_[index]);//---------------> subformel ausgabe in calc stream  
						   /*&& arg_[index] != ')'*/
						index++; 
					}
					fclose(calcStream);
					calcStream = fopen( "~calc", "r" );
	
					fgets (tmp_clc,600,calcStream );//-----------------------------------------------> einlesen der subformelargumente
					//printf("calc_1 clc_= %s\n", tmp_clc);//----------------------------------------> bildschirmausgabe (berechnung via calc_1 nach clc_)
					printf("(%s)", tmp_clc);//-------------------------------------------------------> bildschirmausgabe der subformel
					
					outStream = fopen( "MAT_log.txt", "a" );
					fprintf(outStream,"\n(%s)= ", tmp_clc);//----------------------------------------> dateiausgabe der subformel	
					fclose(outStream);

					strcpy(cmd_ ," ");//-------------------------------------------------------------> befehlszusammenbau für calc_1
					strcat(cmd_, "calc_1 clc_=");strcat(cmd_, tmp_clc);
					//printf("cmd_: %s\n", cmd_);

					//////////////////////////////////////////////////////////////////////////////////////////////////
					
				//	system(cmd_);//------------------------------------------------------------------> Befehlsübergabe an calc_1.exe
					fn_calc_1(); //--tmp_clc---------------------------------------------------------> Subformelübergabe fn_calc_1
					
					//////////////////////////////////////////////////////////////////////////////////////////////////
					
					fclose(calcStream);

					dg_zlr++;//----------------------------------------------------------------------> durchgangszähler
	
					fclose(tmpStream);
					tmpStream = fopen( "~tmp2", "w" );//---------------------------------------------> öffnen der end formel datei ~tmp2

				}
				if(arg_[index] != ')' ) fprintf(tmpStream,"%c",arg_[index]);
				index++;
			}	
		}
		fclose(tmpStream);	
	
	}//Klammerebenenschleife end

	calcStream = fopen( "~tmp1", "r" );
					
	fgets (tmp_clc,600,calcStream );//---------------------------------------------------------------> einlesen der letztenformelargumente
	//printf("calc_1 clc_= %s\n", tmp_clc);//--------------------------------------------------------> bildschirmausgabe (endberechnung via calc_1 nach clc_)			
	printf("%s", tmp_clc);//-------------------------------------------------------------------------> bildschirmausgabe der subformel
	fclose(calcStream);
	
	outStream = fopen( "MAT_log.txt", "a" );
	fprintf(outStream,"\n(%s)= ", tmp_clc);//--------------------------------------------------------> dateiausgabe der subformel	
	fclose(outStream);



	strcpy(cmd_ ," ");//-----------------------------------------------------------------------------> befehlszusammenbau für calc_1
	strcat(cmd_, "calc_1 clc_=");strcat(cmd_, tmp_clc);
	//printf("cmd_: %s\n", cmd_);
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	
//	system(cmd_);//----------------------------------------------------------------------------------> Befehlsübergabe an calc_1.exe
	fn_calc_1(); //---tmp_clc------------------------------------------------------------------------> Subformelübergabe fn_calc_1
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	tmpStream = fopen( "clc_", "r" );//--------------------------------------------------------------> öffnen der berechnungsergebnisdatei 
	fgets (tmp_clc,600,tmpStream );//----------------------------------------------------------------> einlesen des endergebnisses
	fclose(tmpStream);

	if(klm_auf_zlr > 0) printf(erg_format_1, formel_, atof(tmp_clc));
	/*{
		if(atof(tmp_clc) < pow(10,stn))
		{
			if(floor(atof(tmp_clc)) == atof(tmp_clc))printf("\n\n%s= %.0f", formel_, atof(tmp_clc));//---> bildschirmausgabe des ergebnisses
			if(floor(atof(tmp_clc)) != atof(tmp_clc))printf("\n\n%s= %f", formel_, atof(tmp_clc));//-----> bildschirmausgabe des ergebnisses f
	
		}
		
		if(atof(tmp_clc) >= pow(10,stn))
		{
			if(floor(atof(tmp_clc)) == atof(tmp_clc))printf("\n\n%s= %.0e", formel_, atof(tmp_clc));//---> bildschirmausgabe des ergebnisses e
			if(floor(atof(tmp_clc)) != atof(tmp_clc))printf("\n\n%s= %e", formel_, atof(tmp_clc));//-----> bildschirmausgabe des ergebnisses fe
		}
	}*/	
	printf("\n");
	
	outStream = fopen( "MAT_log.txt", "a" );
	//-----------------------------------------------------------------------------------------------> dateiausgabe des ergebnisses
	if(klm_auf_zlr > 0) fprintf(outStream,erg_format_1, formel_, atof(tmp_clc));
	/*{
		if(atof(tmp_clc) < pow(10,stn))
		{
			if(floor(atof(tmp_clc)) == atof(tmp_clc))fprintf(outStream,"\n\n%s= %.0f", formel_, atof(tmp_clc));	
			if(floor(atof(tmp_clc)) != atof(tmp_clc))fprintf(outStream,"\n\n%s= %f", formel_, atof(tmp_clc));
		}
		
		if(atof(tmp_clc) >= pow(10,stn))
		{
			if(floor(atof(tmp_clc)) == atof(tmp_clc))fprintf(outStream,"\n\n%s= %.0e", formel_, atof(tmp_clc));	
			if(floor(atof(tmp_clc)) != atof(tmp_clc))fprintf(outStream,"\n\n%s= %e", formel_, atof(tmp_clc));
		}	
	}*/
	fprintf(outStream,"\n\n\n");

	fclose(outStream);

	if(frml==2)//------------------------------------------------------------------------------------> bei ergbnisvariablen definition 
	{
		outStream = fopen( erg_, "w" );
		//-------------------------------------------------------------------------------------------> ergebnisausgabe in variablenfile
		fprintf (outStream,erg_format_2, atof(tmp_clc));
		//if(floor(atof(tmp_clc)) == atof(tmp_clc))fprintf (outStream,"%.0f\n", atof(tmp_clc));
		//if(floor(atof(tmp_clc)) != atof(tmp_clc))fprintf (outStream,"%f\n", atof(tmp_clc));
		//printf ("\nergebisvariablendateiname: %s\n", erg_);
		fclose(outStream);
	}
	
	//_spawnlp( _P_NOWAIT, "acrobat.exe",  "acrobat.exe", "MAT_log.txt", NULL );
	if(klm_auf_zlr>0)//------------------------------------------------------------------------------> wenn klammern vorhanen
	{
		system("del ~tmp2");//-----------------------------------------------------------------------> tmp stream löschung
		system("del ~calc");//-----------------------------------------------------------------------> tmp stream löschung
	}
	system("del ~tmp1");//---------------------------------------------------------------------------> tmp stream löschung
	system("del clc_");//----------------------------------------------------------------------------> tmp stream löschung
	
	return 0;	
}


void fn_calc_1 ()
{
	FILE *tmpStream, *inStream, *ergStream, *outStream;

	int index0=1,index1=1, 
		zlr=0, sw_1=0, 	
		 laenge, iwert=0,  erg0_var=0,
		mod_Z, mod_N;

	double wert[100],//---------------------------------------------------------------------------------> wertvektor 
		   erg=0;

	char formel0[600], //--------------------------------------------------------------------------------> formel0zeichensatzvektor, formel0vektor
		arg0, arg0_[600], 
		inpt_[500],tmp[500],
		wert_var_[500],
		erg0_[500];
	
	fn[1]=0;//---------------------------------------------------------------------------------------> funktionsvektorinitialisierung
	operat[0]=0;

	for(iLauf=1;iLauf<=100;iLauf++)wert[iLauf]=0;//-------------------------------------------------->  WERTVEKTORREINIGUNG , sonst fehler ab 4. klammerebene

	strcpy(formel0, "clc_=");strcat(formel0, tmp_clc);//-----------------------------------------------> formel0zeichensatzzusammenbau 
	
	laenge = strlen(formel0);//-----------------------------------------------------------------------> bestimmug der formel0 zeichensatzlänge
	//printf("\nformel0zeichensatz: %s\n\nformel0vektorlaenge= %i\n", formel0, laenge);//---------------> bildschirmausgabe	
	
	//outStream = fopen( "MAT_log.txt", "a" );
	//fprintf(outStream,"\n(%s)= ", tmp_clc);//------------------------------------------------------> dateiausgabe der formel0	
	//fclose(outStream);

	tmpStream = fopen( "~tmp", "w" );
	fprintf(tmpStream,"%s",formel0);//----------------------------------------------------------------> formel0zeichensatzausgabe in tmp stream
	fclose(tmpStream);

	tmpStream = fopen( "~tmp", "r" );
	for(iLauf=1;iLauf<=laenge;iLauf++)
	{
		arg0 = fgetc (tmpStream );
		arg0_[iLauf]=arg0;//----------------------------------------------------------------------------> formel0vektorzusammenbau
	}
	fclose(tmpStream);

	//printf("\nformel0vektor: ");//------------------------------------------------------------------> bildschirmausgabe
	//for(iLauf=1;iLauf<=laenge;iLauf++) printf("%c ",arg0_[iLauf]);
	//printf("\n");
	
	while(index0 <= laenge)//-------------------------------------------------------------------------> Vektorenerstellung (Funktion, Wert, Operator)
	{
		tmpStream = fopen( "~tmp", "w" );
		
		while( arg0_[index0] != '=' && //--------------------------------------------------------------> argumentarterkennungsschleife
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
				if(index0 > 1 && arg0_[index0] == '-' )//-----------------------------------------------> x < 0 schaltung
					 if( arg0_[index0-1] != '=') 
					  if( arg0_[index0-1] != '+')
					   if( arg0_[index0-1] != '-')
						if( arg0_[index0-1] != '*')
						 if( arg0_[index0-1] != '/')
						  if( arg0_[index0-1] != '%')
						   if( arg0_[index0-1] != 'h')
						    if( arg0_[index0-1] != 'v')
							  if( arg0_[index0-1] != ',') sw_1 = 1;
				
				if(index0 > 1 && arg0_[index0] == '-' )//-----------------------------------------------> x < 0 nach funktion schaltung 
				    if(sw_fn_1 == 1) sw_1 = 0;
						   
				sw_fn_1=0;//-------------------------------------------------------------------------> funktionsschalter 2 rückstellung
				
				if(sw_1==0){fprintf(tmpStream,"%c",arg0_[index0]);index0++;} //-------------------------> wertzusammenbau und ausgabe in tmpstream
			}
		}// argumentarterkennungsschleife end
		
		sw_1 = 0;//----------------------------------------------------------------------------------> x < 0 schalterrückstellung
			   
		fclose(tmpStream);

		tmpStream = fopen( "~tmp", "r" );
		
		if(arg0_[index0] == '=') {fgets (erg0_,8,tmpStream ); erg0_var=1;}//-----------------------------> ergbnisvariablenamen einlesen, ergebnisvariablenschalter	
		
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
	//for(iLauf=1;iLauf<index1;iLauf++) printf("%i ",operat[iLauf]);
	//printf("\nFunktionsvektor: ");//---------------------------------------------------------------> bildschirmausgabe
	//for(iLauf=1;iLauf<=index1;iLauf++) printf("%i ",fn[iLauf]);
	//printf("\n\n");

	//------------------------------------------------------------------------------------------------| Arithmetische Funktionen
	funktions_decl_3(index1, wert);

	//------------------------------------------------------------------------------------------------| Arihmetische Operationen
	//-----------------------------------------------------------------------------------------------> potenzierung und wurzelziehung
	for(iLauf=1;iLauf<=index1;iLauf++)//-------------------------------------------------------------> index1 = anzahl der argumente (werte) 
	{	
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
	for(iLauf=1;iLauf<=index1-1;iLauf++)//-----------------------------------------------------------> index1 = anzahl der argumente (werte)
	{
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
				
				if(operat[iLauf-1]<=2) wert[iLauf]=0;//----------------------------------------------> wertmodifikation
				if(operat[iLauf-1] >2) wert[iLauf]=1;
				
				if(iLauf == 1) operat[iLauf]=1;//----------------------------------------------------> operatormodifikation
				if(iLauf > 1) operat[iLauf]=operat[iLauf-1];	
		}	
	}

	//printf(" Wertvektor': ");//--------------------------------------------------------------------> bildschirmausgabe
	//for(iLauf=1;iLauf<=index1+1;iLauf++) printf("%.2f ",wert[iLauf]);
	//printf("\n\n");
	//printf("\n");
	
	//-----------------------------------------------------------------------------------------------> plusminusrechnung
	erg= wert[1];
	for(iLauf=1;iLauf<=index1-1;iLauf++)//-------------------------------------------------------------> index1 = anzahl der argumente (werte)
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
	printf(erg_format_3,erg);
	
							 /*if(erg < pow(10,stn))
	{
		if(floor(erg) == erg) printf("= %.0f ",erg);//---------------------------------------------------> bildschirmausgabe ergebnis
		if(floor(erg) != erg) printf("= %f ",erg);//--------------------------------------------------> bildschirmausgabe ergebnis f
	}
	
	if(erg >= pow(10,stn))
	{
		if(floor(erg) == erg) printf("= %.0e ",erg);//---------------------------------------------------> bildschirmausgabe ergebnis e
		if(floor(erg) != erg) printf("= %e ",erg);//--------------------------------------------------> bildschirmausgabe ergebnis fe
	
	}*/
	
	//printf("\n");

	if (erg0_var == 1) //-----------------------------------------------------------------------------> bei ergbnisvariablen definition 
	{
		ergStream = fopen( erg0_, "w" );

		fprintf (ergStream,erg_format_2, erg);//-----------------------------------------------------> ergebnisausgabe in variablenfile
		
		//if(floor(erg) == erg) fprintf (ergStream,"%.0f\n", erg);//-----------------------------------> ergebnisausgabe in variablenfile
		//if(floor(erg) != erg) fprintf (ergStream,"%f\n", erg);
		
		//printf ("\nergebisvariablendateiname: %s\n", erg0_);
		fclose(ergStream);
	}

	outStream = fopen( "MAT_log.txt", "a" );
	
	fprintf(outStream,erg_format_2, erg);
	/*if(erg < pow(10,stn))
	{
		if(floor(erg) == erg) fprintf(outStream,"%.0f", erg);//-----------------------------------------> dateiausgabe des ergebnisses
		if(floor(erg) != erg) fprintf(outStream,"%f", erg);//----------------------------------------> dateiausgabe des ergebnisses f
	}
	if(erg >= pow(10,stn))
	{
		if(floor(erg) == erg) fprintf(outStream,"%.0e", erg);//-----------------------------------------> dateiausgabe des ergebnisses e
		if(floor(erg) != erg) fprintf(outStream,"%e", erg);//----------------------------------------> dateiausgabe des ergebnisses fe
	}*/
	fclose(outStream);
	
	//system ("start notepad MAT_log.txt");
	//system ("cls");
	//system ("type MAT_log.txt");

	system("del ~tmp");//----------------------------------------------------------------------------> tmp stream löschung
	
}
