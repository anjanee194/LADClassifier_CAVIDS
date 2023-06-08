#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



void read_csv(int row, int col, char *filename, double **data){
	FILE *file;
	file = fopen(filename, "r");
	char** arbid =(char**) malloc(row*sizeof(char*));
	int ctl=0;
	char *arr=(char*)calloc(row, sizeof(char));
	int i = 0;
	int j = 0;
	clock_t start, end;
    	double cpu_time_used;

	int Arbitration_ID=0;
	int DLC=1;
	int D0=2;
	int D1=3;
	int D2=4;
	int D3=5;
	int D4=6;
	int D5=7;
	int D6=8;
	int D7=9;
	int Class=10;
	int Time_Interval=11;
	int TimePeriod=12;
	int P_CAN_ID_000=13;
	int P_CAN_ID_002=14;
	int P_CAN_ID_043=15;
	int P_CAN_ID_07F=16;
	int P_CAN_ID_130=17;
	int P_CAN_ID_140=18;
	int P_CAN_ID_153=19;
	int P_CAN_ID_164=20;
	int P_CAN_ID_220=21;
	int P_CAN_ID_251=22;
	int P_CAN_ID_260=23;
	int P_CAN_ID_2A0=24;
	int P_CAN_ID_2B0=25;
	int P_CAN_ID_329=26;
	int P_CAN_ID_340=27;
	int P_CAN_ID_350=28;
	int P_CAN_ID_356=29;
	int P_CAN_ID_366=30;
	int P_CAN_ID_367=31;
	int P_CAN_ID_368=32;
	int P_CAN_ID_370=33;
	int P_CAN_ID_381=34;
	int P_CAN_ID_386=35;
	int P_CAN_ID_387=36;
	int P_CAN_ID_389=37;
	int P_CAN_ID_38D=38;
	int P_CAN_ID_391=39;
	int P_CAN_ID_394=40;
	int P_CAN_ID_410=41;
	int P_CAN_ID_412=42;
	int P_CAN_ID_420=43;
	int P_CAN_ID_421=44;
	int P_CAN_ID_42D=45;
	int P_CAN_ID_430=46;
	int P_CAN_ID_436=47;
	int P_CAN_ID_44E=48;
	int P_CAN_ID_453=49;
	int P_CAN_ID_470=50;
	int P_CAN_ID_479=51;
	int P_CAN_ID_47F=52;
	int P_CAN_ID_483=53;
	int P_CAN_ID_484=54;
	int P_CAN_ID_485=55;
	int P_CAN_ID_48A=56;
	int P_CAN_ID_48C=57;
	int P_CAN_ID_490=58;
	int P_CAN_ID_492=59;
	int P_CAN_ID_495=60;
	int P_CAN_ID_49F=61;
	int P_CAN_ID_4A2=62;
	int P_CAN_ID_4A4=63;
	int P_CAN_ID_4A7=64;
	int P_CAN_ID_4A9=65;
	int P_CAN_ID_4C9=66;
	int P_CAN_ID_4CB=67;
	int P_CAN_ID_4F1=68;
	int P_CAN_ID_500=69;
	int P_CAN_ID_507=70;
	int P_CAN_ID_50A=71;
	int P_CAN_ID_50C=72;
	int P_CAN_ID_50E=73;
	int P_CAN_ID_520=74;
	int P_CAN_ID_52A=75;
	int P_CAN_ID_53B=76;
	int P_CAN_ID_53E=77;
	int P_CAN_ID_53F=78;
	int P_CAN_ID_541=79;
	int P_CAN_ID_544=80;
	int P_CAN_ID_553=81;
	int P_CAN_ID_559=82;
	int P_CAN_ID_563=83;
	int P_CAN_ID_568=84;
	int P_CAN_ID_572=85;
	int P_CAN_ID_57F=86;
	int P_CAN_ID_58B=87;
	int P_CAN_ID_593=88;
	int P_CAN_ID_5A0=89;
	int P_CAN_ID_5A2=90;
	int P_CAN_ID_5A6=91;
	int P_CAN_ID_5B0=92;
	int P_CAN_ID_5BE=93;
	int P_CAN_ID_5CD=94;
	int P_CAN_ID_7C4=95;
	int P_CAN_ID_7CC=96;
	int P_CAN_ID_7D0=97;
	int P_CAN_ID_7D4=98;
	int P_CAN_ID_7D8=99;
	int P_CAN_ID_7DC=100;
    char line[4098];

	start = clock();
	for(int k=0;k<row;k++)
	{
		arbid[k]=(char*) malloc(5*sizeof(char));
		arr[k]='a';
	}
	while (fgets(line, 4098, file) && (i < row))
    {
    	// double row[ssParams->nreal + 1];
        char* tmp = strdup(line);
		const char* tok;
        j=0;
	    for (tok = strtok(line, ","); tok && *tok; j++, tok = strtok(NULL, ","))
	    {
	    	if (j==0)
			{
				strcpy(arbid[i],tok);
		//printf("tok-%s\t",arbid[i]);

				data[i][j]=0;
			}
			else
			{
				data[i][j] = atof(tok);
				//printf("%f\t", data[i][j]);
			}
	    }
	    //printf("test1\n");

        free(tmp);
        i++;
    }

    for(i=0;i<row;i++)
	{
		//printf("arbid -%s\t",arbid[i]);
		//printf("%f",TimePeriod);

		//printf("data- %f\t",data[i][j]);


		if( data[i][TimePeriod] <= 0.008427977561950684)
       			 {arr[ctl++]='1';
			//printf("%f\t",data[i][TimePeriod]);
			}

        else if( (data[i][TimePeriod] <= 0.06636488437652588) && (data[i][TimePeriod] >= 0.05364358425140381) )
        		arr[ctl++]='1';

  		else if( data[i][D4] >= 50.5 && data[i][D0] >= 32.5 && data[i][Time_Interval] >= 0.00029909610748291016 )
        		arr[ctl++]='1';
        else if( data[i][D1] >= 66.5 && data[i][D3] >= 161.5 && data[i][Time_Interval] <= 0.00022113323211669922 )
        		arr[ctl++]='1';
        else if( data[i][D6] >= 111.5 && data[i][D3] >= 161.5 && data[i][Time_Interval] <= 0.00022113323211669922 )
        		arr[ctl++]='1';
        else if( data[i][D3] >= 161.5 && data[i][D7] >= 143.5 && data[i][Time_Interval] <= 0.00022113323211669922 )
        		arr[ctl++]='1';
        else if( data[i][Time_Interval] >= 0.0013914108276367188 && data[i][P_CAN_ID_2B0] >= 0.5 )
        		arr[ctl++]='1';
        else if( data[i][Time_Interval] >= 0.0003548860549926758 && data[i][D0] >= 16.5 && data[i][D4] >= 127.5 )
        		arr[ctl++]='1';

		else if (strcmp(arbid[i],"000\0")==0 && data[i][DLC] == 8)
			arr[ctl++]='1';

		else if (strcmp(arbid[i],"2B0\0")==0)
		{

			if (data[i][DLC] >= 7.0 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >=0.0002846717834472656 && data[i][P_CAN_ID_164] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_251] <=0.5&& data[i][Time_Interval] >= 0.0002846717834472656 && data[i][D5] <=33.5 )
				  arr[ctl++]='1';
			else if( data[i][D4] >=128.5&& data[i][Time_Interval] <= 0.00019538402557373047 && data[i][P_CAN_ID_164] >=0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <=0.00019538402557373047&& data[i][D1] <= 1.5 && data[i][P_CAN_ID_164] >=0.5 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_251] <=0.5 && data[i][Time_Interval] >= 0.0002846717834472656 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_251] <=0.5 && data[i][D1] <= 253.5 && data[i][Time_Interval] <=0.00019538402557373047 )
				  arr[ctl++]='1';
			else
				  arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"4A2\0")==0)
		{
			if (data[i][DLC] >= 5.0 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >=0.0002111195 && data[i][P_CAN_ID_38D] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_485] <=0.5 && data[i][Time_Interval] >= 0.0002111195 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >=0.0002111195 && data[i][Time_Interval] <= 0.0006757975 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <=0.000119448 && data[i][Time_Interval] >= 0.00011205650000000001 && data[i][P_CAN_ID_483] <= 0.5 )
				  arr[ctl++]='1';
			else
				  arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"4A4\0")==0)

		{

			if (data[i][D0] >= 15.5)
				  arr[ctl++]='1';
			else if( data[i][D0] <= 12.5)
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003000495)
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <=0.000235081 && data[i][Time_Interval] >= 0.000208497)
				  arr[ctl++]='1';
			else
				  arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"4A7\0")==0)
		{
			if (data[i][DLC] >= 5.0)
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0004811286926269531 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00036263465881347656 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >=0.00011539459228515625 && data[i][P_CAN_ID_251] <= 0.5 && data[i][Time_Interval] <= 0.00011694431304931642 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >=0.00011050701141357422 && data[i][Time_Interval] <= 0.00011241436004638672 && data[i][P_CAN_ID_470] <= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_42D] <=0.5 && data[i][P_CAN_ID_484] <= 0.5 && data[i][Time_Interval] >= 0.00019860267639160156 )
				  arr[ctl++]='1';
			else
				  arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"4A9\0")==0)
		{
			if (data[i][Time_Interval] >= 0.00029850006103515625)
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.0002186298370361328 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.0002149343490600586 && data[i][Time_Interval] >= 0.00021398067474365237)
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00021183490753173828 && data[i][Time_Interval] <= 0.00021278858184814453 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0002186298370361328 && data[i][Time_Interval] <= 0.00023448467254638675)
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_470] <=0.5 && data[i][Time_Interval] <= 0.00021588802337646484 && data[i][Time_Interval] >= 0.0002149343490600586 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_329] >=0.5 && data[i][Time_Interval] <= 0.00022304058074951172 && data[i][Time_Interval] >= 0.00020802021026611328 )
				  arr[ctl++]='1';
			else
				  arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"4C9\0")==0)
		{
			if (data[i][Time_Interval] <= 0.00021708011627197266)
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00029647350311279297)
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00029647350311279297 && data[i][P_CAN_ID_386] >= 0.5)
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00021708011627197266 && data[i][Time_Interval] <= 0.00022017955780029294)
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023472309112548828 && data[i][Time_Interval] >= 0.0002315044403076172)
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_368] <=0.5 && data[i][Time_Interval] <= 0.00022554397583007812 && data[i][Time_Interval] >= 0.00022017955780029294 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <=0.00024020671844482422 && data[i][Time_Interval] >= 0.00021040439605712888 && data[i][P_CAN_ID_485] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <=0.00021708011627197266 && data[i][Time_Interval] >= 0.00021040439605712888 && data[i][P_CAN_ID_140] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_329] >=0.5 && data[i][Time_Interval] >= 0.00020802021026611328 && data[i][Time_Interval] <= 0.00021326541900634766 )
				  arr[ctl++]='1';
			else
				  arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"4CB\0")==0)
		{
			if (data[i][D1] >= 10.5)
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0007909536361694336 && data[i][P_CAN_ID_485] <= 0.5)
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00024116039276123047 && data[i][P_CAN_ID_164] >= 0.5)
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00030350685119628906 && data[i][D0] >= 128.5)
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00036394596099853516 && data[i][Time_Interval] <= 0.0004825592041015625)
				  arr[ctl++]='1';
			else if( data[i][D0] <=2.0 && data[i][Time_Interval] >= 0.00022947788238525393 && data[i][Time_Interval] <= 0.0002371072769165039)
				  arr[ctl++]='1';
			else if( data[i][D0] <=2.0 && data[i][P_CAN_ID_329] <= 0.5 && data[i][Time_Interval] >= 0.0005388259887695312)
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_47F] <=0.5 && data[i][Time_Interval] <= 0.00022947788238525393 && data[i][D0] >= 128.5)
				  arr[ctl++]='1';
			else
				  arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"4F1\0")==0)
		{
			if (data[i][DLC] >= 6.0)
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00026297569274902344)
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >=0.00020360946655273438 && data[i][D1] <= 7.5 && data[i][P_CAN_ID_386] >= 0.5)
				  arr[ctl++]='1';
			else if( data[i][D1] <=7.5 && data[i][Time_Interval] >= 0.00015103816986083984 && data[i][Time_Interval] <= 0.00015366077423095703)
				  arr[ctl++]='1';
			else
				  arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"5A6\0")==0)
		{

			if (data[i][Time_Interval] >= 0.00030291080474853516 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_53B] <= 0.5 && data[i][Time_Interval] <= 0.00024306774139404294 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023257732391357422 && data[i][P_CAN_ID_541] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.001244187355041504 && data[i][P_CAN_ID_367] <= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0007932186126708984 && data[i][Time_Interval] <= 0.0011066198348999023 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_53B] <=0.5 && data[i][Time_Interval] <= 0.0002168416976928711 && data[i][Time_Interval] >= 0.0002149343490600586 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_53B] <=0.5 && data[i][Time_Interval] <= 0.00023257732391357422 && data[i][Time_Interval] >= 0.0002290010452270508 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_53B] <=0.5 && data[i][Time_Interval] <= 0.0002130270004272461 && data[i][Time_Interval] >= 0.00021088123321533203 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_53B] <=0.5 && data[i][Time_Interval] >= 0.000217437744140625 && data[i][Time_Interval] <= 0.00021898746490478518 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >=0.00034356117248535156 && data[i][P_CAN_ID_381] <= 0.5 && data[i][Time_Interval] <= 0.00040471553802490234 )
				  arr[ctl++]='1';
			else
				  arr[ctl++]='0';

		}
		else if (strcmp(arbid[i],"5B0\0")==0)
		{
			if (data[i][DLC] >= 6.0 )
				  arr[ctl++]='1';
			else if( data[i][D0] >= 157.5 && data[i][Time_Interval] <= 0.00015616416931152344 )
				  arr[ctl++]='1';
			else if( data[i][D0] >= 157.5 && data[i][Time_Interval] >= 0.00019943714141845703 )
				  arr[ctl++]='1';
			else
				  arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"5BE\0")==0)
		{
			if (data[i][D3] >= 3.5 )
				  arr[ctl++]='1';
			else if( data[i][D0] >= 4.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003523826599121094 && data[i][Time_Interval] <= 0.00037276744842529297 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003523826599121094 && data[i][P_CAN_ID_58B] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.0002351999282836914 && data[i][P_CAN_ID_48A] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_368] <= 0.5 && data[i][Time_Interval] >= 0.00043511390686035156 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.0002351999282836914 && data[i][P_CAN_ID_368] <= 0.5 && data[i][Time_Interval] >= 0.0002282857894897461 )
				  arr[ctl++]='1';
			else
				  arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"5CD\0")==0)
		{
			if (data[i][Time_Interval] >= 0.000301361083984375 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00022268295288085938 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00024056434631347656 && data[i][P_CAN_ID_568] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000301361083984375 && data[i][P_CAN_ID_58B] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000301361083984375 && data[i][P_CAN_ID_260] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000301361083984375 && data[i][P_CAN_ID_329] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000301361083984375 && data[i][P_CAN_ID_140] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000301361083984375 && data[i][P_CAN_ID_381] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000301361083984375 && data[i][P_CAN_ID_164] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00021660327911376953 && data[i][P_CAN_ID_386] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00021660327911376953 && data[i][P_CAN_ID_140] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00021660327911376953 && data[i][P_CAN_ID_164] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003260374069213867 && data[i][P_CAN_ID_387] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000301361083984375 && data[i][Time_Interval] <= 0.0007874965667724609 && data[i][P_CAN_ID_386] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000301361083984375 && data[i][Time_Interval] <= 0.002046346664428711 && data[i][P_CAN_ID_386] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00021660327911376953 && data[i][P_CAN_ID_329] >= 0.5 && data[i][Time_Interval] >= 0.00021278858184814453 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_52A] >= 0.5 && data[i][Time_Interval] >= 0.0003260374069213867 && data[i][Time_Interval] <= 0.0007874965667724609 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0002092123031616211 && data[i][P_CAN_ID_329] >= 0.5 && data[i][Time_Interval] <= 0.00021147727966308594 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_52A] <= 0.5 && data[i][Time_Interval] >= 0.00023114681243896482 && data[i][Time_Interval] <= 0.00023448467254638675 )
				  arr[ctl++]='1';
			else
				  arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"07F\0")==0)
		{
			if (data[i][Time_Interval] >= 0.0003885030746459961 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023615360260009766 && data[i][P_CAN_ID_381] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023615360260009766 && data[i][P_CAN_ID_329] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023615360260009766 && data[i][P_CAN_ID_541] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023615360260009766 && data[i][Time_Interval] >= 0.00021898746490478518 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003001689910888672 && data[i][P_CAN_ID_381] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003001689910888672 && data[i][P_CAN_ID_500] >= 0.5)
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003470182418823242 && data[i][P_CAN_ID_520] >= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003470182418823242 && data[i][Time_Interval] <= 0.0003701448440551758 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_520] <= 0.5 && data[i][Time_Interval] <= 0.0002143383026123047 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_520] <= 0.5 && data[i][Time_Interval] <= 0.0002187490463256836 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_381] >= 0.5 && data[i][Time_Interval] <= 0.00024902820587158203 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_329] <= 0.5 && data[i][Time_Interval] >= 0.00038802623748779297 )
				  arr[ctl++]='1';
			else if( data[i][P_CAN_ID_329] <= 0.5 && data[i][Time_Interval] >= 0.0003707408905029297 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00031197071075439453 && data[i][Time_Interval] <= 0.0003255605697631836 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0002143383026123047 && data[i][Time_Interval] <= 0.0002187490463256836 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00038802623748779297 && data[i][Time_Interval] >= 0.0003707408905029297 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023615360260009766 && data[i][P_CAN_ID_520] <= 0.5 && data[i][P_CAN_ID_386] <= 0.5 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003001689910888672 && data[i][P_CAN_ID_520] <= 0.5 && data[i][Time_Interval] <=0.0003019571304321289 )
				  arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003470182418823242 && data[i][P_CAN_ID_329] <= 0.5 && data[i][P_CAN_ID_541] <= 0.5 )
				  arr[ctl++]='1';
			else
				  arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"7C4\0")==0)
		{
			if (data[i][D2] >= 10.5 )
				  arr[ctl++]='1';
			else if( data[i][D1] >= 25.5 )
				  arr[ctl++]='1';
			else if( data[i][D0] >= 48.5 )
				  arr[ctl++]='1';
			else
				  arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"7CC\0")==0)
		{
			if (data[i][D0] >= 38.5 )
				  arr[ctl++]='1';
			else if( data[i][D0] >= 32.5 && data[i][D6] >= 169.5 )
				  arr[ctl++]='1';
			else if( data[i][D6] >= 169.5 && data[i][D7] <= 135.5 )
				  arr[ctl++]='1';
			else if( data[i][D6] >= 169.5 && data[i][D5] <= 134.5 )
				  arr[ctl++]='1';
			else if( data[i][D6] >= 169.5 && data[i][D4] <= 23.5 )
				  arr[ctl++]='1';
			else if( data[i][D7] >= 135.5 && data[i][D4] <= 23.5 )
				  arr[ctl++]='1';
			else if( data[i][D5] >= 134.5 && data[i][D4] <= 23.5 )
				  arr[ctl++]='1';
			else if( data[i][D3] >= 35.5 && data[i][D0] >= 32.5 && data[i][D5] >= 134.5 )
				  arr[ctl++]='1';
			else if( data[i][D3] >= 35.5 && data[i][D0] <= 32.5 && data[i][Time_Interval] <= 0.00022947788238525393 )
				  arr[ctl++]='1';
			else if( data[i][D3] >= 35.5 && data[i][D0] <= 32.5 && data[i][D6] <= 169.5 )
				  arr[ctl++]='1';
			else if( data[i][D3] >= 35.5 && data[i][D0] <= 32.5 && data[i][Time_Interval] >= 0.0003546476364135742 )
				  arr[ctl++]='1';
			else if( data[i][D3] >= 35.5 && data[i][Time_Interval] <=0.00022947788238525393 && data[i][D7] >= 135.5 )
				  arr[ctl++]='1';
			else if( data[i][D3] <= 35.5 && data[i][D0] >= 32.5 && data[i][D7] >= 135.5 )
				  arr[ctl++]='1';
			else if( data[i][D3] <= 35.5 && data[i][D6] <= 169.5 && data[i][D7] >= 135.5 )
				  arr[ctl++]='1';
			else if( data[i][D0] <= 32.5 && data[i][D6] <= 169.5 && data[i][D5] >= 134.5 )
				  arr[ctl++]='1';
			else if( data[i][D0] <= 32.5 && data[i][D6] <= 169.5 && data[i][D4] >= 23.5 )
				  arr[ctl++]='1';
			else
				  arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"7D0\0")==0)
		{
			if (data[i][D2] >= 10.5 )
				 arr[ctl++]='1';
			else if( data[i][D1] >= 25.5 )
				 arr[ctl++]='1';
			else if( data[i][D7] <= 169.0 )
				 arr[ctl++]='1';
			else if( data[i][D0] >= 48.5 )
				 arr[ctl++]='1';
			else
				 arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"7D4\0")==0)
		{
			if (data[i][D6] <= 169.5)
				arr[ctl++]='1';
			else if( data[i][D5] <= 169.5)
				arr[ctl++]='1';
			else if( data[i][D7] <= 169.5)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_260] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][D3] <= 11.5)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_436] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_52A] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_5BE] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0002524852752685547 && data[i][Time_Interval] <= 0.00044167041778564453 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.0002524852752685547 && data[i][D4] <= 169.5 )
				arr[ctl++]='1';
			else if( data[i][D4] <= 169.5 && data[i][D3] <= 169.5 )
				arr[ctl++]='1';
			else if( data[i][D4] <= 169.5 && data[i][D0] >= 47.5 )
				arr[ctl++]='1';
			else if( data[i][D3] <= 169.5 && data[i][D0] >= 47.5 )
				arr[ctl++]='1';
			else if( data[i][D1] >= 23.5 && data[i][D0] >= 47.5 )
				arr[ctl++]='1';
			else
				 arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"7D8\0")==0)
		{
			if (data[i][D0] >= 48.5 )
				arr[ctl++]='1';
			else if( data[i][D3] >= 41.5 && data[i][Time_Interval] <= 0.00022709369659423828)
				arr[ctl++]='1';
			else if( data[i][D0] <= 32.5 && data[i][D7] <= 128.5)
				arr[ctl++]='1';
			else if( data[i][D0] <= 32.5 && data[i][D0] >= 16.5)
				arr[ctl++]='1';
			else if( data[i][D3] >= 41.5 && data[i][D6] >= 56.5 && data[i][Time_Interval] >= 0.00029850006103515625)
				arr[ctl++]='1';
			else if( data[i][D3] >= 41.5 && data[i][D6] >= 56.5 && data[i][D2] >= 57.5)
				arr[ctl++]='1';
			else if( data[i][D3] >= 41.5 && data[i][D6] <= 56.5 && data[i][D0] <= 32.5)
				arr[ctl++]='1';
			else if( data[i][D3] >= 41.5 && data[i][Time_Interval] >= 0.00029850006103515625 && data[i][D2] >= 57.5)
				arr[ctl++]='1';
			else if( data[i][D3] >= 41.5 && data[i][Time_Interval] >= 0.00029850006103515625 && data[i][D7] >= 128.5)
				arr[ctl++]='1';
			else if( data[i][D6] >= 56.5 && data[i][D2] <= 57.5 && data[i][D0] >= 32.5)
				arr[ctl++]='1';
			else if( data[i][D6] >= 56.5 && data[i][D0] <= 32.5 && data[i][D6] <= 128.5)
				arr[ctl++]='1';
			else if( data[i][D6] >= 56.5 && data[i][D7] >= 128.5 && data[i][D6] <= 128.5)
				arr[ctl++]='1';
			else if( data[i][D6] <= 56.5 && data[i][Time_Interval] <= 0.00022709369659423828 && data[i][D2] <= 57.5)
				arr[ctl++]='1';
			else if( data[i][D6] <= 56.5 && data[i][Time_Interval] >= 0.00029850006103515625 && data[i][D2] >= 57.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00022709369659423828 && data[i][D0] >= 32.5 && data[i][D7] >= 128.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00022709369659423828 && data[i][D0] >= 32.5 && data[i][D6] >= 128.5)
				arr[ctl++]='1';
			else
				 arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"7DC\0")==0)
		{
			if (data[i][D0] >= 48.5 )
				arr[ctl++]='1';
			else if( data[i][D3] >= 18.5 && data[i][D2] >= 25.5 )
				arr[ctl++]='1';
			else if( data[i][D3] >= 18.5 && data[i][Time_Interval] <= 0.00022959709167480471 )
				arr[ctl++]='1';
			else if( data[i][D3] >= 18.5 && data[i][D5] <= 133.5)
				arr[ctl++]='1';
			else if( data[i][D3] <= 18.5 && data[i][D4] <= 133.5)
				arr[ctl++]='1';
			else if( data[i][D2] <= 25.5 && data[i][Time_Interval] <= 0.00022959709167480471)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00022959709167480471 && data[i][D5] <= 133.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00022959709167480471 && data[i][D0] >= 3.5)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"42D\0")==0)
		{
			if (data[i][Time_Interval] >= 0.0014973878860473633 )
				arr[ctl++]='1';
			else if( data[i][D4] >= 2.5 && data[i][Time_Interval] >= 0.0002999305725097656)
				arr[ctl++]='1';
			else if( data[i][D4] >= 2.5 && data[i][D7] >= 33.5)
				arr[ctl++]='1';
			else if( data[i][D4] <= 2.5 && data[i][D5] <= 145.5)
				arr[ctl++]='1';
			else if( data[i][D4] <= 2.5 && data[i][D6] >= 7.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0002999305725097656 && data[i][P_CAN_ID_387] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003370046615600586 && data[i][Time_Interval] <= 0.0004252195358276367)
				arr[ctl++]='1';
			else if( data[i][D4] >= 2.5 && data[i][Time_Interval] <= 0.0002366304397583008 && data[i][P_CAN_ID_140] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][D4] >= 2.5 && data[i][Time_Interval] <= 0.0002366304397583008 && data[i][P_CAN_ID_368] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][D4] >= 2.5 && data[i][Time_Interval] <= 0.0002366304397583008 && data[i][P_CAN_ID_329] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][D4] >= 2.5 && data[i][Time_Interval] <= 0.00022494792938232422 && data[i][P_CAN_ID_389] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00022494792938232422 && data[i][Time_Interval] <= 0.0002280473709106445 && data[i][P_CAN_ID_140] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00022494792938232422 && data[i][Time_Interval] <= 0.0002280473709106445 && data[i][P_CAN_ID_386] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00022494792938232422 && data[i][Time_Interval] <= 0.0002280473709106445 && data[i][P_CAN_ID_387] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00022494792938232422 && data[i][P_CAN_ID_391] >= 0.5 && data[i][Time_Interval] <= 0.00022637844085693362)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_389] <= 0.5 && data[i][Time_Interval] >= 0.00022709369659423828 && data[i][Time_Interval] <= 0.0002275705337524414)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_340] <= 0.5 && data[i][P_CAN_ID_421] <= 0.5 && data[i][Time_Interval] >= 0.0009629726409912109)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00022494792938232422 && data[i][Time_Interval] <= 0.00022637844085693362)
				arr[ctl++]='1';
			else if( data[i][D4] >= 2.5 && data[i][Time_Interval] <= 0.00022494792938232422 && data[i][P_CAN_ID_394] <= 0.5)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"43\0")==0)
		{
			if (data[i][D0] >= 4.5 )
				arr[ctl++]='1';
			else if( data[i][D1] >= 16.5 )
				arr[ctl++]='1';
			else if( data[i][D0] <= 3.5 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"44E\0")==0)
		{
			if (data[i][Time_Interval] <= 0.00023746490478515625 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00029790401458740234 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023746490478515625 && data[i][P_CAN_ID_387] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00029790401458740234 && data[i][P_CAN_ID_329] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00029790401458740234 && data[i][P_CAN_ID_386] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00021588802337646484 && data[i][P_CAN_ID_386] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00021588802337646484 && data[i][Time_Interval] >= 0.00020825862884521484 && data[i][P_CAN_ID_140] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00021135807037353518 && data[i][Time_Interval] <= 0.0002218484878540039 && data[i][P_CAN_ID_329] >= 0.5)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';

		}

		else if (strcmp(arbid[i],"48C\0")==0)
		{
			if (data[i][D2] >= 3.5 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_58B] <= 0.5 && data[i][Time_Interval] >= 0.0012749433517456055)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023305416107177732 && data[i][P_CAN_ID_386] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00024020671844482422 && data[i][Time_Interval] >= 0.00021827220916748047 && data[i][P_CAN_ID_2B0] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][D1] <= 32.5 && data[i][Time_Interval] >= 0.0002275705337524414 && data[i][Time_Interval] <= 0.00023305416107177732)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';

		}
		else if (strcmp(arbid[i],"49F\0")==0)
		{
			if (data[i][D1] <= 254.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0013284683227539062 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023806095123291016 && data[i][P_CAN_ID_453] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00034165382385253906 && data[i][Time_Interval] <= 0.0011444091796875)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.0002321004867553711 && data[i][Time_Interval] >= 0.00023114681243896482)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00034165382385253906 && data[i][Time_Interval] <= 0.001280069351196289)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023305416107177732 && data[i][Time_Interval] >= 0.00023245811462402344)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"50A\0")==0)
		{
			if (data[i][D0] >= 11.5 )
				arr[ctl++]='1';
			else if( data[i][D0] <= 8.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023090839385986328 && data[i][Time_Interval] >= 0.00022816658020019529)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"50C\0")==0)
		{
			if (data[i][D2] >= 3.5 )
				arr[ctl++]='1';
			else if( data[i][D6] >= 1.5 && data[i][D4] >= 5.5 && data[i][D0] <= 63.5)
				arr[ctl++]='1';
			else if( data[i][D6] >= 1.5 && data[i][D4] >= 5.5 && data[i][Time_Interval] >= 0.00027501583099365234)
				arr[ctl++]='1';
			else if( data[i][D6] >= 1.5 && data[i][D4] >= 5.5 && data[i][Time_Interval] <= 0.00022518634796142578)
				arr[ctl++]='1';
			else if( data[i][D4] >= 5.5 && data[i][D0] <= 63.5 && data[i][Time_Interval] >= 0.00027501583099365234)
				arr[ctl++]='1';
			else if( data[i][D4] >= 5.5 && data[i][D0] <= 63.5 && data[i][Time_Interval] <= 0.00022518634796142578)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"50E\0")==0)
		{
			if (data[i][D4] >= 10.5 )
				arr[ctl++]='1';
			else if( data[i][D3] >= 32.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00022423267364501953 && data[i][P_CAN_ID_470] <= 0.5 && data[i][Time_Interval] <= 0.00022685527801513672)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_507] <= 0.5 && data[i][P_CAN_ID_50C] <= 0.5 && data[i][Time_Interval] >= 0.0009480714797973633 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00022840499877929685 && data[i][Time_Interval] >= 0.00022709369659423828)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0004830360412597656 && data[i][P_CAN_ID_507] <= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00022423267364501953 && data[i][Time_Interval] <= 0.00022840499877929685 && data[i][P_CAN_ID_470] <= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003540515899658203 && data[i][P_CAN_ID_453] <= 0.5 && data[i][Time_Interval] <= 0.0003758668899536133)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"52A\0")==0)
		{
			if (data[i][D4] >= 2.5 )
				arr[ctl++]='1';
			else if( data[i][D7] >= 136.5 && data[i][Time_Interval] >= 0.00035750865936279297)
				arr[ctl++]='1';
			else if( data[i][D7] >= 136.5 && data[i][Time_Interval] <= 0.0002321004867553711)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"53B\0")==0)
		{
			if (data[i][Time_Interval] <= 0.00021898746490478518 && data[i][P_CAN_ID_329] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00021898746490478518 && data[i][P_CAN_ID_52A] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_4CB] <= 0.5 && data[i][Time_Interval] <= 0.00021898746490478518 && data[i][Time_Interval] >= 0.0002142190933227539)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_4CB] <= 0.5 && data[i][P_CAN_ID_260] <= 0.5 && data[i][Time_Interval] >= 0.0007170438766479492)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00024020671844482422 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00030219554901123047 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"53E\0")==0)
		{
			if (data[i][D4] <= 7.5 )
				arr[ctl++]='1';
			else if( data[i][D5] >= 208.0 )
				arr[ctl++]='1';
			else if( data[i][D4] >= 12.5 && data[i][Time_Interval] <= 0.000240325927734375)
				arr[ctl++]='1';
			else if( data[i][D4] >= 12.5 && data[i][Time_Interval] >= 0.00033855438232421875)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00033855438232421875 )
				arr[ctl++]='1';
			else if( data[i][D4] >= 12.5 && data[i][D5] <= 131.5)
				arr[ctl++]='1';
			else if( data[i][D4] >= 12.5 && data[i][D5] >= 131.5 && data[i][P_CAN_ID_4A7] <= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00022852420806884766 && data[i][D5] <= 133.5 && data[i][Time_Interval] <= 0.00023150444030761716)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}

		else if (strcmp(arbid[i],"53F\0")==0)
		{
			if (data[i][P_CAN_ID_329] <= 0.5 && data[i][Time_Interval] >= 0.0010530948638916016)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_4A9] <= 0.5 && data[i][Time_Interval] >= 0.00021088123321533203 && data[i][Time_Interval] <= 0.00021398067474365237 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_4A9] <= 0.5 && data[i][Time_Interval] >= 0.00035858154296875 && data[i][Time_Interval] <= 0.00070953369140625)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00021088123321533203 && data[i][P_CAN_ID_52A] >= 0.5 && data[i][Time_Interval] <= 0.00022304058074951172)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_2B0] <= 0.5 && data[i][Time_Interval] <= 0.0009695291519165039 && data[i][Time_Interval] >= 0.00070953369140625)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00022089481353759766 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00031447410583496094 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00022089481353759766 && data[i][Time_Interval] <= 0.00022304058074951172)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023341178894042966 && data[i][Time_Interval] >= 0.00023055076599121094)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"57F\0")==0)
		{
			if (data[i][D3] >= 1.5)
				arr[ctl++]='1';
			else if( data[i][D7] >= 2.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0009579658508300781)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00031244754791259766 && data[i][P_CAN_ID_568] <= 0.5 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"58B\0")==0)
		{
			if (data[i][D1] >= 3.5)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_48A] <= 0.5 && data[i][Time_Interval] <= 0.0002356767654418945 && data[i][Time_Interval] >= 0.0002321004867553711)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"140\0")==0)
		{
			if (data[i][D4] >= 32.5)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_130] <= 0.5 && data[i][Time_Interval] >= 0.0009586811065673828)
				arr[ctl++]='1';
			else if( data[i][D3] <= 107.5 && data[i][D1] >= 128.5)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_130] <= 0.5 && data[i][Time_Interval] >= 0.0003088712692260742 && data[i][P_CAN_ID_000] <= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0009586811065673828)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_130] <= 0.5 && data[i][Time_Interval] <= 0.00024688243865966797)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"220\0")==0)
		{
			if (data[i][D4] >= 1.5 && data[i][Time_Interval] >= 0.0017951726913452148)
				arr[ctl++]='1';
			else if( data[i][D4] >= 1.5 && data[i][D2] >= 130.5 && data[i][D6] <= 15.5)
				arr[ctl++]='1';
			else if( data[i][D4] >= 1.5 && data[i][D2] >= 130.5 && data[i][Time_Interval] >= 0.0005820989608764648)
				arr[ctl++]='1';
			else if( data[i][D4] >= 1.5 && data[i][D2] >= 130.5 && data[i][P_CAN_ID_329] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][D4] >= 1.5 && data[i][D5] <= 244.5 && data[i][P_CAN_ID_260] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][D4] >= 1.5 && data[i][Time_Interval] <= 0.00023996829986572266 && data[i][P_CAN_ID_329] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][D4] >= 1.5 && data[i][D6] <= 15.5 && data[i][Time_Interval] <= 0.00022852420806884766)
				arr[ctl++]='1';
			else if( data[i][D4] >= 1.5 && data[i][D0] >= 16.5 && data[i][P_CAN_ID_329] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][D4] >= 1.5 && data[i][Time_Interval] >= 0.0005820989608764648 && data[i][D0] >= 26.5)
				arr[ctl++]='1';
			else if( data[i][D4] >= 1.5 && data[i][D2] >= 130.5)
				arr[ctl++]='1';
			else if( data[i][D4] >= 1.5 && data[i][P_CAN_ID_153] <= 0.5)
				arr[ctl++]='1';
			else if( data[i][D4] >= 1.5 && data[i][P_CAN_ID_153] >= 0.5 && data[i][Time_Interval] >= 0.0003529787063598633)
				arr[ctl++]='1';
			else if( data[i][D2] >= 130.5 && data[i][P_CAN_ID_153] <= 0.5 && data[i][Time_Interval] <= 0.00022852420806884766)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_153] >= 0.5 && data[i][D5] <= 26.5 && data[i][Time_Interval] >= 0.0003529787063598633)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}

		else if (strcmp(arbid[i],"260\0")==0)
		{
			if (data[i][D3] >= 48.5 )
				arr[ctl++]='1';
			else if( data[i][D3] <= 47.5  )
				arr[ctl++]='1';
			else if( data[i][D5] >= 189.5 && data[i][D4] >= 254.5 && data[i][D0] <= 5.5 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"329\0")==0)
		{
			if (data[i][D7] >= 16.5)
				arr[ctl++]='1';
			else if( data[i][D4] >= 49.5 && data[i][Time_Interval] >= 0.0005239248275756836 && data[i][P_CAN_ID_2B0] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][D1] >= 198.5 && data[i][D0] >= 132.5 && data[i][D0] <= 213.5)
				arr[ctl++]='1';
			else if( data[i][D4] >= 49.5 && data[i][Time_Interval] <= 0.0002187490463256836 )
				arr[ctl++]='1';
			else if( data[i][D4] >= 49.5 && data[i][D1] >= 198.5 && data[i][D5] <= 44.5)
				arr[ctl++]='1';
			else if( data[i][D4] >= 49.5 && data[i][D1] >= 198.5 && data[i][Time_Interval] <= 0.00022518634796142578 )
				arr[ctl++]='1';
			else if( data[i][D1] >= 198.5 && data[i][D5] >= 44.5 && data[i][Time_Interval] <= 0.0002187490463256836 )
				arr[ctl++]='1';
			else
				 arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"366\0")==0)
		{
			if (data[i][DLC] >= 7.5 )
				arr[ctl++]='1';
			else if( data[i][D2] >= 31.5 && data[i][D5] <= 3.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003230571746826172 && data[i][D1] <= 14.5 && data[i][D3] >= 53.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003230571746826172 && data[i][D3] >= 54.5 && data[i][D5] <= 1.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003230571746826172 && data[i][P_CAN_ID_140] >= 0.5 && data[i][D5] <= 1.5)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_356] <= 0.5 && data[i][Time_Interval] >= 0.0003230571746826172 )
				arr[ctl++]='1';
			else if( data[i][D5] <= 3.5 && data[i][D4] <= 44.5 && data[i][Time_Interval] >= 0.0003230571746826172)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00020825862884521484 && data[i][D3] >= 53.5 && data[i][D5] <= 1.5)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}

		else if (strcmp(arbid[i],"367\0")==0)
		{
			if (data[i][P_CAN_ID_366] <= 0.5 && data[i][D4] >= 12.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023639202117919922 && data[i][D3] >= 63.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003033876419067383 && data[i][D3] >= 63.5 )
				arr[ctl++]='1';
			else if( data[i][D6] >= 217.5 && data[i][D6] <= 227.5 && data[i][Time_Interval] >= 0.0009442567825317383 )
				arr[ctl++]='1';
			else if( data[i][D6] >= 217.5 && data[i][D4] <= 3.5 && data[i][Time_Interval] >= 0.0009442567825317383 )
				arr[ctl++]='1';
			else if( data[i][D7] <= 2.5 && data[i][D6] >= 33.5 && data[i][Time_Interval] >= 0.0009442567825317383 )
				arr[ctl++]='1';
			else if( data[i][D6] >= 227.5 && data[i][D4] <= 3.5 && data[i][Time_Interval] >= 0.0004284381866455078 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_366] <= 0.5 && data[i][Time_Interval] >= 0.0004284381866455078  )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_366] >= 0.5 && data[i][D7] <= 7.5 && data[i][Time_Interval] >= 0.0009442567825317383 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_366] <= 0.5 && data[i][Time_Interval] >= 0.0003033876419067383 && data[i][D7] <= 7.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023639202117919922 && data[i][D7] <= 7.5 && data[i][P_CAN_ID_340] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023639202117919922 && data[i][D6] >= 217.5 && data[i][D4] <= 3.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003033876419067383 && data[i][D7] <= 10.5 && data[i][D6] >= 217.5 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}

		else if (strcmp(arbid[i],"368\0")==0)
		{
			if (data[i][P_CAN_ID_367] <= 0.5 && data[i][D4] >= 3.5 )
				arr[ctl++]='1';
			else if( data[i][D5] <= 118.5 && data[i][Time_Interval] >= 0.0016666650772094727 )
				arr[ctl++]='1';
			else if( data[i][D7] >= 64.5 && data[i][Time_Interval] >= 0.0016666650772094727 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.0002351999282836914 && data[i][P_CAN_ID_220] >= 0.5 && data[i][D1] <= 1.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003129243850708008 && data[i][D5] <= 38.5 && data[i][P_CAN_ID_2B0] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][D7] <= 64.5 && data[i][P_CAN_ID_2B0] >= 0.5 && data[i][Time_Interval] <= 0.00023901462554931638 )
				arr[ctl++]='1';
			else if( data[i][D5] >= 12.5 && data[i][Time_Interval] >= 0.0007234811782836914 && data[i][D5] <= 24.5 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_367] <= 0.5 && data[i][Time_Interval] >= 0.0007234811782836914 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_367] <= 0.5 && data[i][Time_Interval] <= 0.0002351999282836914 && data[i][D1] <= 3.5 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_367] <= 0.5 && data[i][Time_Interval] >= 0.0003129243850708008 && data[i][D1] <= 3.5 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}

		else if (strcmp(arbid[i],"389\0")==0)
		{
			if (data[i][Time_Interval] >= 0.00030171871185302734 && data[i][D4] >= 1.5 )
				arr[ctl++]='1';
			else if( data[i][D4] >= 1.5 && data[i][D3] <= 47.5)
				arr[ctl++]='1';
			else if( data[i][D4] >= 1.5 && data[i][P_CAN_ID_140] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][D4] >= 1.5 && data[i][P_CAN_ID_260] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023996829986572266 && data[i][D4] >= 1.5 && data[i][P_CAN_ID_329] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023996829986572266 && data[i][D4] >= 1.5 && data[i][D6] <= 29.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00030171871185302734 && data[i][D3] <= 47.5 && data[i][P_CAN_ID_340] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_421] <= 0.5 && data[i][D4] >= 1.5 && data[i][Time_Interval] <= 0.00022113323211669922 )
				arr[ctl++]='1';
			else if( data[i][D3] <= 47.5 && data[i][D6] <= 132.5 && data[i][Time_Interval] >= 0.0010281801223754883 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.0002321004867553711 && data[i][Time_Interval] >= 0.00023043155670166016 && data[i][P_CAN_ID_368] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0010281801223754883 )
				 arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00030171871185302734 && data[i][P_CAN_ID_386] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.0002321004867553711 && data[i][P_CAN_ID_368] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023996829986572266 && data[i][D3] <= 47.5 && data[i][P_CAN_ID_329] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00030171871185302734 && data[i][P_CAN_ID_421] <= 0.5 && data[i][P_CAN_ID_000] <= 0.5 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_421] <= 0.5 && data[i][Time_Interval] >= 0.00022852420806884766 && data[i][Time_Interval] <= 0.0002321004867553711 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}

		else if (strcmp(arbid[i],"394\0")==0)
		{
			if (data[i][D7] <= 247.5 && data[i][D0] >= 1.5)
				arr[ctl++]='1';
			else if( data[i][D7] <= 247.5 && data[i][D5] >= 84.5 && data[i][Time_Interval] <= 0.00023901462554931638)
				arr[ctl++]='1';
			else if( data[i][D7] <= 247.5 && data[i][Time_Interval] >= 0.00036585330963134766 && data[i][P_CAN_ID_387] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][D6] >= 62.5 && data[i][D5] >= 84.5 && data[i][Time_Interval] <= 0.00023615360260009766 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"410\0")==0)
		{
			if (data[i][D4] >= 1.5 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_436] <= 0.5 && data[i][P_CAN_ID_340] <= 0.5 && data[i][Time_Interval] >= 0.0004889965057373047)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003629922866821289)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0002290010452270508 && data[i][Time_Interval] <= 0.0002301931381225586 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_436] <= 0.5 && data[i][Time_Interval] <= 0.0002321004867553711 && data[i][Time_Interval] >= 0.0002301931381225586 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_436] <= 0.5 && data[i][Time_Interval] >= 0.00022709369659423828 && data[i][Time_Interval] <= 0.0002290010452270508 )
				arr[ctl++]='1';

			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"412\0")==0)
		{
			if (data[i][D3] >= 12.5 )
				arr[ctl++]='1';
			else if( data[i][D3] <= 11.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003401041030883789 && data[i][P_CAN_ID_260] <= 0.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023043155670166016 && data[i][Time_Interval] >= 0.00022780895233154294 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00022780895233154294 && data[i][Time_Interval] >= 0.00022614002227783203 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"420\0")==0)
		{
			if (data[i][Time_Interval] >= 0.00030171871185302734 && data[i][D4] <= 251.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00030171871185302734 && data[i][P_CAN_ID_386] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][D4] <= 251.5 && data[i][P_CAN_ID_368] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][D0] >= 208.5 && data[i][Time_Interval] >= 0.0006350278854370117  )
				arr[ctl++]='1';
			else if( data[i][D0] <= 112.5 && data[i][D0] >= 80.5 && data[i][Time_Interval] >= 0.0006350278854370117 )
				arr[ctl++]='1';
			else if( data[i][D4] <= 251.5 && data[i][Time_Interval] <= 0.00022089481353759766 && data[i][P_CAN_ID_164] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0006350278854370117 )
				arr[ctl++]='1';
			else if( data[i][D4] <= 251.5 && data[i][Time_Interval] <= 0.00022089481353759766 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_38D] <= 0.5 && data[i][Time_Interval] >= 0.00022089481353759766 && data[i][Time_Interval] <= 0.00022304058074951172  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00022518634796142578 && data[i][Time_Interval] >= 0.00021350383758544922 && data[i][P_CAN_ID_368] >= 0.5  )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"421\0")==0)
		{
			if (data[i][Time_Interval] >= 0.00029850006103515625 && data[i][D0] <= 253.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00029850006103515625 && data[i][P_CAN_ID_386] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][D0] <= 253.5 && data[i][P_CAN_ID_329] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][D0] <= 253.5 && data[i][P_CAN_ID_368] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][D7] <= 118.5 && data[i][D0] <= 253.5 && data[i][D7] >= 91.5 )
				arr[ctl++]='1';
			else if( data[i][D0] <= 253.5 && data[i][P_CAN_ID_260] >= 0.5 && data[i][D7] >= 14.5  )
				arr[ctl++]='1';
			else if( data[i][D0] <= 253.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0006260871887207031 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.0002275705337524414 && data[i][P_CAN_ID_368] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_420] <= 0.5 && data[i][Time_Interval] >= 0.00022542476654052732 && data[i][Time_Interval] <= 0.0002275705337524414)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"436\0")==0)
		{
			if (data[i][DLC] >= 6.0  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000746607780456543  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.0001556873321533203 && data[i][Time_Interval] >= 0.0001538991928100586 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.000746607780456543 && data[i][Time_Interval] >= 0.0003085136413574219 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"453\0")==0)
		{
			if (data[i][DLC] >= 6.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0002671480178833008 && data[i][P_CAN_ID_2B0] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][D2] >= 143.5 && data[i][D2] <= 144.5 && data[i][Time_Interval] >= 0.0002671480178833008  )
				arr[ctl++]='1';
			else if( data[i][D2] >= 143.5 && data[i][Time_Interval] <= 0.00016760826110839844 && data[i][P_CAN_ID_2B0] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00017511844635009766 && data[i][D2] >= 143.5 && data[i][P_CAN_ID_140] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][D2] >= 143.5 && data[i][D2] <= 144.5 && data[i][Time_Interval] <= 0.00016760826110839844  )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}

		else if (strcmp(arbid[i],"470\0")==0)
		{
			if (data[i][D3] >= 4.5 && data[i][Time_Interval] >= 0.0011584758758544922)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000607013702392578 && data[i][P_CAN_ID_140] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023138523101806638 && data[i][D3] >= 4.5 && data[i][P_CAN_ID_260] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023138523101806638 && data[i][D3] >= 4.5 && data[i][P_CAN_ID_2B0] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023138523101806638 && data[i][D3] >= 4.5 && data[i][P_CAN_ID_140] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000301361083984375 && data[i][D2] >= 4.5 && data[i][D1] <= 64.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000301361083984375 && data[i][D7] <= 104.5 && data[i][D5] >= 80.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000301361083984375 && data[i][D5] >= 80.5 && data[i][D3] >= 4.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000301361083984375 && data[i][D7] <= 80.5 && data[i][D3] >= 4.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000301361083984375 && data[i][D3] >= 4.5 && data[i][D7] >= 141.5  )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_453] <= 0.5 && data[i][D2] >= 4.5 && data[i][Time_Interval] >= 0.0011584758758544922  )
				arr[ctl++]='1';
			else if( data[i][D2] >= 4.5 && data[i][D1] <= 64.5 && data[i][Time_Interval] <= 0.00022375583648681638 )
				arr[ctl++]='1';
			else if( data[i][D5] >= 80.5 && data[i][Time_Interval] <= 0.00022375583648681638 && data[i][D7] <= 65.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00022375583648681638 && data[i][D7] <= 80.5 && data[i][D3] >= 4.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0011584758758544922 )
				 arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023138523101806638 && data[i][D3] >= 4.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000301361083984375 && data[i][P_CAN_ID_453] <= 0.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023138523101806638 && data[i][Time_Interval] >= 0.00021898746490478518 && data[i][P_CAN_ID_140] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_368] <= 0.5 && data[i][P_CAN_ID_453] <= 0.5 && data[i][Time_Interval] <= 0.00022375583648681638  )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"479\0")==0)
		{
			if (data[i][D0] >= 82.5)
				arr[ctl++]='1';
			else if( data[i][D0] <= 73.5)
				arr[ctl++]='1';
			else if( data[i][D0] <= 75.5 && data[i][Time_Interval] >= 0.0003428459167480469 )
				arr[ctl++]='1';
			else if( data[i][D0] <= 75.5 && data[i][P_CAN_ID_391] <= 0.5 && data[i][Time_Interval] <= 0.00022923946380615237)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_368] <= 0.5 && data[i][Time_Interval] >= 0.0003428459167480469 && data[i][D0] >= 76.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023627281188964844 && data[i][D0] <= 75.5 && data[i][Time_Interval] >= 0.0002199411392211914)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"483\0")==0)
		{
			if (data[i][D0] >= 23.5  )
				arr[ctl++]='1';
			else if( data[i][D0] <= 18.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0011943578720092773  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00023114681243896482 && data[i][Time_Interval] <= 0.00023329257965087888 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"484\0")==0)
		{
			if (data[i][D4] >= 3.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00034737586975097656  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0002290010452270508 && data[i][Time_Interval] <= 0.00022971630096435547 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023353099822998047 && data[i][D0] >= 47.5 && data[i][Time_Interval] >= 0.00023245811462402344  )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"485\0")==0)
		{
			if (data[i][DLC] >= 6.0  )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_387] <= 0.5 && data[i][P_CAN_ID_453] <= 0.5 && data[i][Time_Interval] >= 0.001543879508972168  )
				arr[ctl++]='1';
			else if( data[i][D0] <= 2.5 && data[i][Time_Interval] >= 0.0002605915069580078  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0001494884490966797 && data[i][Time_Interval] <= 0.00015294551849365234 )
				arr[ctl++]='1';
			else if( data[i][D0] <= 2.5 && data[i][Time_Interval] <= 0.00015795230865478516 && data[i][P_CAN_ID_453] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00015342235565185547 && data[i][P_CAN_ID_470] >= 0.5 && data[i][Time_Interval] >= 0.00015294551849365234  )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"490\0")==0)
		{
			if (data[i][D0] >= 1.5  )
				arr[ctl++]='1';
			else if( data[i][D2] >= 8.5 && data[i][Time_Interval] <= 0.0002294778823852539)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.0002294778823852539 && data[i][P_CAN_ID_340] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][D7] >= 146.5 && data[i][Time_Interval] <= 0.0002294778823852539 && data[i][P_CAN_ID_4F1] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][D5] >= 112.5 && data[i][Time_Interval] >= 0.0012420415878295898 && data[i][P_CAN_ID_386] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.0002294778823852539 && data[i][Time_Interval] >= 0.00022494792938232422 && data[i][P_CAN_ID_389] >= 0.5  )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"492\0")==0)
		{
			if (data[i][D1] <= 253.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00024020671844482422 && data[i][P_CAN_ID_220] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_387] >= 0.5 && data[i][Time_Interval] <= 0.00023365020751953125 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023365020751953125 && data[i][Time_Interval] >= 0.00022923946380615237  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0006629228591918945 && data[i][P_CAN_ID_2B0] >= 0.5 && data[i][Time_Interval] <= 0.000764012336730957  )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"495\0")==0)
		{
			if (data[i][D5] >= 2.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.0002204179763793945 && data[i][P_CAN_ID_386] <= 0.5 && data[i][Time_Interval] >= 0.0002199411392211914  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00034248828887939453 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00021922588348388672 && data[i][Time_Interval] <= 0.0002199411392211914 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00022339820861816404 && data[i][P_CAN_ID_389] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0002204179763793945 && data[i][P_CAN_ID_329] <= 0.5 && data[i][Time_Interval] <= 0.00022089481353759766 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"500\0")==0)
		{
			if (data[i][D0] >= 1.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0010155439376831055  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003679990768432617 && data[i][P_CAN_ID_140] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000545501708984375 && data[i][P_CAN_ID_386] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00023376941680908203 && data[i][Time_Interval] <= 0.00023651123046875003 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0006865262985229492 && data[i][P_CAN_ID_2B0] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_495] <= 0.5 && data[i][D4] >= 8.5 && data[i][Time_Interval] >= 0.0007345676422119141  )
				arr[ctl++]='1';
			else if( data[i][D4] >= 8.5 && data[i][Time_Interval] >= 0.00040400028228759766 && data[i][P_CAN_ID_2B0] >= 0.5  )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"507\0")==0)
		{
			if (data[i][DLC] >= 6.0  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0007494688034057617  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00016510486602783203 && data[i][P_CAN_ID_4F1] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00015556812286376953 && data[i][Time_Interval] <= 0.0001569986343383789  )
				arr[ctl++]='1';
			else if( data[i][D0] <= 7.5 && data[i][Time_Interval] >= 0.00026547908782958984 && data[i][Time_Interval] <= 0.0007494688034057617  )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"520\0")==0)
		{
			if (data[i][Time_Interval] <= 0.00023949146270751953 && data[i][P_CAN_ID_164] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023949146270751953 && data[i][P_CAN_ID_386] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00021851062774658203 && data[i][P_CAN_ID_329] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00021851062774658203 && data[i][P_CAN_ID_389] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00030553340911865234 )
				 arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023949146270751953 && data[i][P_CAN_ID_329] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023949146270751953 && data[i][P_CAN_ID_387] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023949146270751953 && data[i][P_CAN_ID_389] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023949146270751953 && data[i][P_CAN_ID_140] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00021851062774658203 && data[i][P_CAN_ID_368] <= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023949146270751953 && data[i][Time_Interval] >= 0.00022649765014648438 && data[i][P_CAN_ID_260] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00021851062774658203 && data[i][P_CAN_ID_368] <= 0.5 && data[i][Time_Interval] <= 0.0002213716506958008 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00022649765014648438 && data[i][P_CAN_ID_50C] >= 0.5 && data[i][Time_Interval] <= 0.00023305416107177732 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"541\0")==0)
		{
			if (data[i][D1] >= 4.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00026857852935791016 && data[i][P_CAN_ID_2B0] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.0002280473709106445 && data[i][Time_Interval] >= 0.00022399425506591797)
				arr[ctl++]='1';
			else if( data[i][D1] >= 3.5 && data[i][P_CAN_ID_260] <= 0.5 && data[i][Time_Interval] >= 0.0009649991989135742  )
				arr[ctl++]='1';
			else if( data[i][D1] >= 3.5 && data[i][Time_Interval] <= 0.0007129907608032227 && data[i][Time_Interval] >= 0.0004055500030517578  )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"544\0")==0)
		{
			if (data[i][D0] <= 254.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0002244710922241211 && data[i][P_CAN_ID_453] <= 0.5 && data[i][Time_Interval] <= 0.00022685527801513672 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"553\0")==0)
		{
			if (data[i][D2] <= 24.5  )
				arr[ctl++]='1';
			else if( data[i][D1] >= 1.5 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_544] <= 0.5 && data[i][Time_Interval] >= 0.0008126497268676758 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00022089481353759766 && data[i][Time_Interval] <= 0.00022459030151367188 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00035750865936279297 && data[i][Time_Interval] <= 0.0003980398178100586 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"559\0")==0)
		{
			if (data[i][Time_Interval] <= 0.000217437744140625 && data[i][P_CAN_ID_52A] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.000217437744140625 && data[i][P_CAN_ID_329] >= 0.5 && data[i][Time_Interval] >= 0.00020992755889892578  )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_453] <= 0.5 && data[i][Time_Interval] >= 0.00020992755889892578 && data[i][Time_Interval] <= 0.0002111196517944336  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00029349327087402344 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.000217437744140625  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.000217437744140625 && data[i][Time_Interval] <= 0.00021922588348388672  )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_453] <= 0.5 && data[i][Time_Interval] <= 0.00022494792938232422 && data[i][Time_Interval] >= 0.00021922588348388672 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"563\0")==0)
		{
			if (data[i][D6] >= 1.5 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"568\0")==0)
		{
			if (data[i][D4] >= 128.5  )
				arr[ctl++]='1';
			else if( data[i][D4] <= 127.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003466606140136719 && data[i][D3] >= 142.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00022995471954345703 && data[i][Time_Interval] <= 0.00023353099822998044  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0009143352508544923 && data[i][D3] <= 138.5  )
				arr[ctl++]='1';
			else if( data[i][D3] >= 139.5 && data[i][Time_Interval] <= 0.00022995471954345703 && data[i][Time_Interval] >= 0.00022649765014648438 )
				arr[ctl++]='1';
			else if( data[i][D3] >= 139.5 && data[i][D5] <= 64.5 && data[i][Time_Interval] >= 0.002015829086303711 )
				arr[ctl++]='1';
			else if( data[i][D3] >= 141.5 && data[i][D5] <= 64.5 && data[i][Time_Interval] >= 0.0009143352508544923  )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"593\0")==0)
		{
			if (data[i][DLC] >= 7.0  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00019514560699462888 && data[i][Time_Interval] >= 0.00019133090972900393 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"572\0")==0)
		{
			if (data[i][P_CAN_ID_520] <= 0.5 && data[i][Time_Interval] <= 0.0003933906555175781 && data[i][Time_Interval] >= 0.0003484487533569336 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00021183490753173828 && data[i][Time_Interval] <= 0.00022542476654052734 && data[i][P_CAN_ID_329] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00020802021026611328 && data[i][Time_Interval] <= 0.00022089481353759766 && data[i][P_CAN_ID_541] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00024056434631347656 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.0003933906555175781)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"47F\0")==0)
		{
			if (data[i][D2] <= 254.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.0002351999282836914 && data[i][P_CAN_ID_2B0] >= 0.5)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"48A\0")==0)
		{
			if (data[i][D5] >= 2.5 && data[i][P_CAN_ID_470] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][D5] >= 2.5 && data[i][P_CAN_ID_340] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][D5] >= 2.5 && data[i][Time_Interval] <= 0.0002351999282836914 && data[i][D6] >= 32.5 )
				arr[ctl++]='1';
			else if( data[i][D5] >= 2.5 && data[i][Time_Interval] >= 0.00046002864837646484 && data[i][D6] >= 32.5 )
				arr[ctl++]='1';
			else if( data[i][D5] >= 2.5 && data[i][D7] >= 126.5 && data[i][D6] >= 32.5 )
				arr[ctl++]='1';
			else if( data[i][D5] >= 2.5 && data[i][D7] >= 126.5 && data[i][Time_Interval] <= 0.00022554397583007812 )
				arr[ctl++]='1';
			else if( data[i][D5] >= 2.5 && data[i][D2] >= 128.5 && data[i][D6] >= 32.5)
				arr[ctl++]='1';
			else if( data[i][D5] >= 2.5 && data[i][D6] >= 32.5 && data[i][Time_Interval] >= 0.0003553628921508789)
				arr[ctl++]='1';
			else if( data[i][D5] >= 2.5 && data[i][P_CAN_ID_140] <= 0.5 && data[i][Time_Interval] <= 0.0002199411392211914 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.0002351999282836914 && data[i][D6] >= 32.5 && data[i][D6] <= 95.5 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}

		else if (strcmp(arbid[i],"153\0")==0)
		{
			if (data[i][D3] <= 254.5 && data[i][D1] <= 129.5 )
				arr[ctl++]='1';
			else if( data[i][D3] <= 254.5 && data[i][P_CAN_ID_260] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][D3] <= 254.5 && data[i][P_CAN_ID_340] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][D6] >= 145.5 && data[i][D7] >= 206.5  )
				arr[ctl++]='1';
			else if( data[i][D6] >= 145.5 && data[i][D7] <= 45.5  )
				arr[ctl++]='1';
			else if( data[i][D7] <= 97.5 && data[i][D6] >= 207.5 )
				arr[ctl++]='1';
			else if( data[i][D3] <= 254.5 && data[i][D7] <= 126.5 && data[i][D6] >= 175.5  )
				arr[ctl++]='1';
			else if( data[i][D3] <= 254.5 && data[i][D7] >= 206.5 && data[i][D6] >= 64.5  )
				arr[ctl++]='1';
			else if( data[i][D3] <= 254.5 && data[i][D7] <= 206.5 && data[i][D6] <= 17.5  )
				arr[ctl++]='1';
			else if( data[i][D3] <= 254.5 && data[i][D7] <= 97.5 && data[i][D6] >= 130.5  )
				arr[ctl++]='1';
			else if( data[i][D7] >= 126.5 && data[i][D6] <= 145.5 && data[i][D6] >= 97.5 )
				arr[ctl++]='1';
			else if( data[i][D7] <= 126.5 && data[i][D7] >= 45.5 && data[i][D6] <= 64.5  )
				arr[ctl++]='1';
			else if( data[i][D3] <= 254.5 && data[i][D7] >= 126.5 && data[i][D6] <= 145.5  )
				arr[ctl++]='1';
			else if( data[i][D3] <= 254.5 && data[i][D7] <= 177.5 && data[i][D6] >= 207.5  )
				arr[ctl++]='1';
			else if( data[i][D7] <= 126.5 && data[i][P_CAN_ID_47F] <= 0.5 && data[i][D6] <= 48.5  )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}

		else if (strcmp(arbid[i],"164\0")==0)
		{
			if (data[i][DLC] >= 6.0 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"251\0")==0)
		{
			if (data[i][D4] >= 0.5 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"340\0")==0)
		{
			if (data[i][Time_Interval] <= 0.00023305416107177732 && data[i][D4] <= 133.5 && data[i][D6] >= 181.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023305416107177732 && data[i][D6] <= 92.5 && data[i][D4] >= 214.5)
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023305416107177732 && data[i][D1] >= 3.5 && data[i][P_CAN_ID_220] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][D4] >= 133.5 && data[i][D6] <= 92.5 && data[i][D1] >= 3.5 )
				arr[ctl++]='1';
			else if( data[i][D4] <= 133.5 && data[i][D0] <= 251.5 && data[i][D6] >= 181.5 )
				arr[ctl++]='1';
			else if( data[i][D6] >= 181.5 && data[i][D1] >= 3.5 && data[i][D4] <= 165.5 )
				arr[ctl++]='1';
			else if( data[i][D6] <= 181.5 && data[i][D1] >= 3.5 && data[i][D4] >= 214.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023305416107177732 && data[i][D1] >= 3.5 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"381\0")==0)
		{
			if (data[i][D2] >= 64.5 && data[i][D7] >= 5.5 && data[i][Time_Interval] <= 0.00022709369659423828 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023496150970458984 && data[i][D7] >= 5.5 && data[i][D2] <= 60.5  )
				arr[ctl++]='1';
			else if( data[i][D5] >= 140.5 && data[i][D7] >= 5.5 && data[i][D2] <= 60.5  )
				arr[ctl++]='1';
			else if( data[i][D2] >= 68.5 && data[i][Time_Interval] <= 0.00022709369659423828 )
				arr[ctl++]='1';
			else if( data[i][D2] >= 64.5 && data[i][P_CAN_ID_2B0] >= 0.5 && data[i][Time_Interval] >= 0.0007737874984741211 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023496150970458984 && data[i][D2] <= 60.5 && data[i][D5] >= 214.5  )
				arr[ctl++]='1';
			else if( data[i][D5] >= 140.5 && data[i][D2] <= 60.5 && data[i][Time_Interval] <= 0.00022709369659423828  )
				arr[ctl++]='1';
			else if( data[i][D1] >= 143.5 && data[i][D7] >= 5.5 && data[i][D2] <= 60.5  )
				arr[ctl++]='1';
			else if( data[i][D7] >= 5.5 && data[i][D2] <= 60.5 && data[i][Time_Interval] >= 0.00035369396209716797  )
				arr[ctl++]='1';
			else if( data[i][D2] >= 66.5 && data[i][D1] >= 207.5 && data[i][Time_Interval] <= 0.00022709369659423828  )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_2B0] <= 0.5 && data[i][D2] >= 65.5 && data[i][Time_Interval] <= 0.00022709369659423828  )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}

		else if (strcmp(arbid[i],"386\0")==0)
		{
			if (data[i][D0] >= 50.5 && data[i][Time_Interval] <= 0.00022518634796142578 && data[i][P_CAN_ID_260] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_260] >= 0.5 && data[i][Time_Interval] <= 0.00022995471954345703 )
				arr[ctl++]='1';
			else if( data[i][D0] <= 50.5 && data[i][Time_Interval] <= 0.00022518634796142578 && data[i][D6] >= 130.5)
				arr[ctl++]='1';
			else if( data[i][D0] <= 50.5 && data[i][Time_Interval] <= 0.00022518634796142578 && data[i][D2] >= 121.5 )
				arr[ctl++]='1';
			else if( data[i][D0] <= 50.5 && data[i][Time_Interval] >= 0.0006536245346069336 && data[i][P_CAN_ID_2B0] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][D5] >= 65.5 && data[i][Time_Interval] >= 0.0002988576889038086 && data[i][P_CAN_ID_260] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00022518634796142578 && data[i][D7] <= 127.5 && data[i][P_CAN_ID_2B0] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00022518634796142578 && data[i][D6] >= 130.5 && data[i][D2] <= 121.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00022518634796142578 && data[i][D6] <= 130.5 && data[i][D2] >= 121.5 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"387\0")==0)
		{
			if (data[i][D6] >= 14.5 )
				arr[ctl++]='1';
			else
				 arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"391\0")==0)
		{
			if (data[i][D6] >= 15.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023949146270751953 && data[i][D6] <= 11.5 && data[i][P_CAN_ID_153] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023949146270751953 && data[i][D6] <= 9.5 && data[i][P_CAN_ID_492] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023949146270751953 && data[i][P_CAN_ID_387] >= 0.5 && data[i][Time_Interval] >= 0.00022876262664794922  )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"356\0")==0)
		{
			if (data[i][D0] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00024116039276123047 && data[i][D4] <= 39.5 && data[i][P_CAN_ID_386] >= 0.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023281574249267578 && data[i][P_CAN_ID_164] >= 0.5)
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"38D\0")==0)
		{
			if (data[i][D6] <= 253.5 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_260] >= 0.5 && data[i][Time_Interval] >= 0.0020750761032104492  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00023424625396728518 && data[i][D2] <= 73.5 && data[i][P_CAN_ID_220] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][D2] <= 73.5 && data[i][P_CAN_ID_387] >= 0.5 && data[i][Time_Interval] <= 0.00022852420806884766  )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"53B\0")==0)
		{
			if (data[i][Time_Interval] <= 0.00021898746490478518 && data[i][P_CAN_ID_329] >= 0.5  )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00021898746490478518 && data[i][P_CAN_ID_52A] >= 0.5)
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_4CB] <= 0.5 && data[i][Time_Interval] <= 0.00021898746490478518 && data[i][Time_Interval] >= 0.0002142190933227539 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_4CB] <= 0.5 && data[i][P_CAN_ID_260] <= 0.5 && data[i][Time_Interval] >= 0.0007170438766479492 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] <= 0.00024020671844482422 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00030219554901123047 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}
		else if (strcmp(arbid[i],"130\0")==0)
		{
			if (data[i][Time_Interval] <= 0.00023496150970458984 && data[i][D5] >= 7.5 )
				arr[ctl++]='1';
			else if( data[i][Time_Interval] >= 0.00035369396209716797 && data[i][D5] >= 7.5 )
				arr[ctl++]='1';
			else if( data[i][D5] >= 7.5 && data[i][D0] >= 16.5  )
				arr[ctl++]='1';
			else if( data[i][D6] >= 10.5 && data[i][D5] >= 7.5 )
				arr[ctl++]='1';
			else if( data[i][P_CAN_ID_2B0] >= 0.5 && data[i][Time_Interval] <= 0.00022637844085693362 && data[i][D0] <= 4.5 )
				arr[ctl++]='1';
			else
				arr[ctl++]='0';
		}

        else
         		arr[ctl++]='0';

	//printf("%c \n",arr[i]);
	}
	end = clock();
     	cpu_time_used = ((double) (end - start))*1000 / CLOCKS_PER_SEC;
	printf("cpu time -%f",cpu_time_used);
}

int main(int argc, char const *argv[])
{
	/* code */
	if (argc < 3){
		printf("Please specify the CSV file as an input.\n");
		exit(0);
	}

	int row     = atoi(argv[1]);
	int col     = atoi(argv[2]);
	char fname[256];	strcpy(fname, argv[3]);

	double **data;
	data = (double **)malloc(row * sizeof(double *));
	for (int i = 0; i < row; ++i){
		data[i] = (double *)malloc(col * sizeof(double));
	}

	read_csv(row, col, fname, data);

	return 0;
}




