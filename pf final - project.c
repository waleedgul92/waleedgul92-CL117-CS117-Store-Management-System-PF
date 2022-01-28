#include<stdio.h>
#include<string.h>
#include<math.h>
int tot_fr,tot_veg,tot_k,tot_d,tot_b,tot_bath,tot_bev,tot_tot;
int kitchen(FILE *fptr,FILE *ptr,FILE* fptr1);
char list(FILE *fptr,FILE *ptr,FILE *fptr1);
int fruits(FILE *fptr,FILE *ptr,FILE* fptr1);
int vegetables(FILE *fptr,FILE *ptr,FILE* fptr1);
char product(char products[],FILE *fptr,FILE *ptr,FILE *fptr1);
int dairy(FILE * fptr,FILE * ptr,FILE* fptr1);
int bath(FILE * fptr, FILE *ptr,FILE* fptr1);
int bev(FILE* fptr,FILE*ptr,FILE* fptr1);
int owner(FILE *ptr,FILE* fptr1);
int bill(void);
int  main()
{
	char status[20];
	FILE *fptr,*ptr,*fptr1;
	int local[50];
     //status of user of program
     int n, f[23];
     char ch[100];
     char ch1[100]={"owner123"};

     printf("if you are client, enter 1\n");
     printf("if you are owner, enter 2\n");  
     scanf("%d",&n);
     switch (n)
     
	{
     	case 1:
     		{
     			printf("so you are client !  ");
     			fptr= fopen("names.txt","w");
	           ptr=fopen("owner.txt","r+");
	           fptr1=fopen("rates.txt","w");
	            if(fptr==NULL)
	    		{
	        	printf("error in fptr!");
		        exit(1);
     			}
   	 		    if(ptr==NULL)
				{
	  			printf("error in ptr!");
				exit(1);
     			}
   		     	if(fptr1==NULL)
				{
	       		printf("error in fptr1!");
				exit(1);
     			}
 
     			list(fptr,ptr,fptr1);
     			fprintf(fptr1,"%d ",tot_d);
     			fprintf(fptr1,"%d ",tot_b);
     			fprintf(fptr1,"%d ",tot_bath);
     			fprintf(fptr1,"%d ",tot_bev);	
     	        fclose(fptr);
     			fclose(ptr); 
     			fclose(fptr1);	
     			char *str = (char*)malloc(5000);
				ptr = fopen("names.txt", "r");
				fscanf(ptr, "%[^\0]", str);
				fclose(ptr);
				ptr = fopen("owner.txt","w");
				fprintf(ptr,"%s", str);
				fclose(ptr);
     	        fclose(fptr);
     			fclose(ptr); 
     			fclose(fptr1);	
     			break;
			 }
	    	case 2:
	        printf("enter password to validate:");
			int y=0;
			scanf("%s",&ch);
     		if(strcmp(ch1,ch)==0)
     		{
     			printf("so you are owner or a manager!\n");
     			printf("so you are client !  ");
     			fptr= fopen("names.txt","r");
	            ptr=fopen("owner.txt","r");
	            fptr1=fopen("rates.txt","r");
	            if(fptr==NULL)
	    		{
	        	printf("error in fptr!");
		        exit(1);
     			}
   	 		    if(ptr==NULL)
				{
	  			printf("error in ptr!");
				exit(1);
     			}
   		     	if(fptr1==NULL)
				{
	       		printf("error in fptr1!");
				exit(1);
     			}
     			owner(ptr,fptr1);		
     		    fclose(fptr);
     			fclose(ptr); 
     			fclose(fptr1);
     			break;
			}
				
		else
			    printf("you are an intruder");
	            fclose(fptr);
     			fclose(ptr); 
     			fclose(fptr1);
     			break;	
	    default:
     		{
     			printf("you are an intruder");
     	        fclose(fptr);
     			fclose(ptr); 
     			fclose(fptr1);	  
     			break;
			}
}

}
                     // listing all the categories/
 					// all products available//
char list(FILE *fptr,FILE *ptr,FILE *fptr1)
{
	char choose[20];
	printf("\n\t\there a list of items availbles:");
	printf("\n(1)fruits\n(2)vegetables\n(3)beverages\n(4)kitchen products\n(5)dairy products\n(6)bathroom products\n(7)bakery products");
	printf("\nenter a product category:");
	scanf("%s",&choose);
	product(choose,fptr,ptr,fptr1);
}
char product(char products[],FILE *fptr,FILE *ptr,FILE *fptr1)
{
	char* list[20]={"fruits","vegetables","dairy","beverages","kitchen","bakery","bathroom"};
	
	
		if(strcmp(list[0],products)==0)
		{
		   fruits(fptr,ptr,fptr1);
	    }
	   	if(strcmp(list[1],products)==0)
		{
			vegetables(fptr,ptr,fptr1);
	    }
	    if(strcmp(list[4],products)==0)
	    {
	    	kitchen(fptr,ptr,fptr1);
		}
		if(strcmp(list[2],products)==0)
		{
			dairy(fptr,ptr,fptr1);
		}
		if(strcmp(list[5],products)==0)
		{	    
		bakery(fptr,ptr,fptr1);
		}
		if(strcmp(list[6],products)==0)
		{
		    bath(fptr,ptr,fptr1);
		}
		if(strcmp(list[3],products)==0)
		{

			bev(fptr,ptr,fptr1);
		}	
}
						//fruits counters
int fruits(FILE *fptr,FILE *ptr,FILE* fptr1)
{
	int i=0,f[22];
	int z[6];
   	for(i=0;i<7;i++)
	{
		fscanf(ptr,"%d", &f[i]);
	//	printf("%d   ",f[i]);
	}
	int a,b,c,d,sum,sum_m,m,apr,ga,gr,pin,app,ban;
	int sum_b,sum_apr,sum_app,sum_ga,sum_gr,sum_pin;
	int prices[20]={90,30,50,70,150,60};
	printf("\n\t\t------------------------------");
	printf("\n\t\there list of available fruits:");
	printf("\n\t\t------------------------------");
	printf("\n  (1)mangoes\t(2)appricot\t(3)banana\t(4)gauva\t(5)grapes\t(6)pineapple\t(7)apple\n\n");
	printf("enter number of mangoes in kgs : ");
	scanf("%d",&m);
	if(f[0]<m)
	printf("sorry not available at moment\n:");
    else
	z[0]=f[0]-m;
	fprintf(fptr,"%d ",z[0]);
	sum_m=m*prices[0];
	printf("price of mangoes =%d\n",sum_m);
	printf("enter number of bnanas in dozens : ");
	scanf("%d",&b);
	if(f[1]<b)
	printf("sorry not available at moment\n:");
    else
	z[1]=f[1]-b;
	fprintf(fptr,"%d ",z[1]);
	sum_b=b*prices[1];
	printf("price of bananas =%d",sum_b);
	printf("\nenter number of apricot in kgs : ");
	scanf("%d",&apr);
	if(f[2]<apr)
	printf("sorry not available at moment\n:");
    else
	z[2]=f[2]-apr;
	fprintf(fptr," %d ",z[2]);
	sum_apr=apr*prices[2];
	printf("price of apricot =%d\n",sum_apr);
	printf("enter number of gauva in kgs : ");
	scanf("%d",&ga);
	if(f[3]<ga)
	printf("sorry not available at moment\n:");
    else
	z[3]=f[3]-ga;
	fprintf(fptr,"%d ",z[3]);
	sum_ga=ga*prices[5];
	printf("price of gauva =%d\n",sum_ga);
	printf("enter number of grapes in kgs : ");
	scanf("%d",&gr);
	if(f[4]<gr)
	printf("sorry not available at moment\n:");
    else
	z[4]=f[4]-gr;
	fprintf(fptr,"%d ",z[4]);
	sum_gr=gr*prices[3];
	printf("price of grapes =%d\n",sum_gr);
	printf("enter number of pineapple in kgs : ");
	scanf("%d",&pin);
	if(f[5]<pin)
	printf("sorry not available at moment\n:");
    else
    z[5]=f[5]-pin;
	fprintf(fptr,"%d ",z[5]);
	sum_pin=pin*prices[4];
	printf("enter number of apple in kgs : ");
	scanf("%d",&app);
	if(f[6]<app)
	printf("sorry not available at moment\n:");
    else
	z[6]=f[6]-app;
	fprintf(fptr,"%d ",z[6]);
	sum_app=app*prices[5];
	printf("price of apple =%d\n",sum_app);
	int total=sum_b+sum_apr+sum_app+sum_ga+sum_gr+sum_m+sum_pin;
	printf("the total amount of fruits be =%d\n",total);
    tot_fr=total;
    fprintf(fptr1,"%d ",tot_fr);
   	printf("\n\t\t------------------------");
	printf("\n\tpress 1 to continue or 0 to go to bill counter");
	printf("\n\t\t------------------------");
	int n;
	scanf("%d",&n);
	if(1==n)
	vegetables(fptr,ptr,fptr1);
	else
	bill();	
}
							//vegetable counter
int vegetables(FILE *fptr,FILE *ptr,FILE* fptr1)
{
	int f[21],i;
    	for(i=7;i<12;i++){
 		fscanf(ptr,"%d",&f[i]);
	//	printf("%d  ",f[i]);
		}
	printf("\n\t\t-----------------------------------");
	printf("\n\t\there is list of vegetable available:");
	printf("\n\t\t-----------------------------------");
	printf("\n  (1)tomatoes\t(2)corn\t(3)pumpkin\t(4)onion\t(5)potatoe\n\n");
	typedef int fr;
	fr t,c,p,o,po;
	fr prices1[20]={50,60,100,40,30};
	fr sum_t,sum_c,sum_p,sum_o,sum_po;
 	printf("enter number of tomatoes in kgs :");
	scanf("%d",&t);
	if(f[7]<t)
	printf("sorry not available at moment\n:");
    else
	f[7]=f[7]-t;
	fprintf(fptr,"%d ",f[7]);
	sum_t=t*prices1[0];
	printf("price of tomatoes =%d\n",sum_t);
	printf("enter number of onions in kilograms :");
	scanf("%d",&o);
	if(f[9]<o)
	printf("sorry not available at moment\n:");
    else
	f[9]=f[9]-o;
	fprintf(fptr,"%d ",f[9]);
	sum_o=o*prices1[1];
	printf("price of onions =%d\n",sum_o);
	printf("enter number of pumpklin in kgs :");
	scanf("%d",&p);
	if(f[8]<p)
	printf("sorry not available at moment\n:");
    else
	f[8]=f[8]-p;
	fprintf(fptr,"%d ",f[8]);
	sum_p=p*prices1[2];
	printf("enter number of potatoes in kgs :");
	scanf("%d",&po);
	if(f[11]<po)
	printf("sorry not available at moment\n:");
    else
	f[11]=f[11]-po;
	fprintf(fptr,"%d ",f[11]);
	sum_po=po*prices1[3];
	printf("price of potatoes =%d\n",sum_po);
	printf("enter number of corn in kgs :");
	scanf("%d",&c);
	if(f[10]<c)
	printf("sorry not available at moment\n:");
    else
	f[10]=f[10]-c;
	fprintf(fptr,"%d ",f[10]);
	sum_c=c*prices1[4];
	printf("price of corn =%d\n",sum_c);
	int total1=sum_t+sum_c+sum_p+sum_o+sum_po;
	printf("the total amount of vegetables be=%d\n",total1);
	tot_veg =total1;
	fprintf(fptr1,"%d ",tot_veg);
	printf("\n\t\t------------------------");
	printf("\n\tpress 1 to continue or 0 to go to bill counter");
	printf("\n\t\t------------------------");
	int n;
	scanf("%d",&n);
	if(1==n)
	kitchen(fptr,ptr,fptr1);
	else
	bill();
}							// kitchen counter
int kitchen(FILE *fptr,FILE *ptr,FILE* fptr1)
{
	int f[21],i;
	// taking valuesfrom text file//
   	for(i=12;i<17;i++){
	fscanf(ptr,"%d",&f[i]);
	//printf("%d  ",f[i]);
    }
	int c,k,f_p,s,p;
	int sum_c,sum_k,sum_f_p,sum_s,sum_p,t_k;
	printf("\n\t\t-----------------------------------------");
	printf("\n\t\there a list of available kitchem products");
	printf("\n\t\t------------------------------------------");
	printf("\n  (1)cooker\t(2)knife\t(3)frying pan\t(4)spoons\t(5)plates\n");
	// prices of things respectively//
	int price[]={400,50,300,150,700};
	// taking values and checking with record if it is less than record then samechanges remaing  thingsin another file//
	printf("\nenter number of cookers");
	scanf("%d",&c);
	if(f[12]<c)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f[12]=f[12]-c;
		fprintf(fptr,"%d ",f[12]);
		sum_c=c*price[0];
		printf("total of cookers is:%d",sum_c);
	}
	// taking values and checking with record if it is less than record then same remaing thingsin another file//
	printf("\nenter number of knives");
	scanf("%d",&k);
	if(f[13]<k)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f[13]=f[13]-k;
		fprintf(fptr,"%d ",f[13]);
		sum_k=k*price[1];
		printf("total of knives is:%d",sum_k);
	}
	// taking values and checking with record if it is less than record then same remaing thingsin another file//
	printf("\nenter number of fry pans");
	scanf("%d",&f_p);
	if(f[15]<f_p)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f[14]=f[14]-f_p;
		fprintf(fptr,"%d ",f[14]);
		sum_f_p=f_p*price[2];
		printf("total of fry pans is:%d",sum_f_p);
	}
	// taking values and checking with record if it is less than record then same remaing thingsin another file//
	printf("\nenter number of spoons");
	scanf("%d",&s);
	if(f[16]<s)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f[15]=f[15]-s;
		fprintf(fptr,"%d ",f[15]);
		sum_s=s*price[3];
		printf("total of fry pans is:%d",sum_s);
	}
	// taking values and checking with record if it is less than record then same remaing thingsin another file//
	printf("\nenter number plates  pans");
	scanf("%d",&p);
	if(f[16]<p)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f[16]=f[16]-p;
		fprintf(fptr,"%d ",f[16]);
		sum_p=p*price[4];
		printf("total of plates is:%d",sum_p);
	}
	// total of all produvts//
	t_k=sum_c+sum_k+sum_f_p+sum_s+sum_p;
	printf("\ntotal of kitchen products is :%d",t_k);
	// total in gloal variable to display in bill//
	tot_k=t_k;
	fprintf(fptr1,"%d ",tot_k);
	int n;
	printf("\n\t\t------------------------");
	printf("\n\tpress 1 to continue or 0 to go to bill counter");
	printf("\n\t\t------------------------");
	scanf("%d",&n);
	if(1==n)
	dairy(fptr,ptr,fptr1);
	else
	bill();
	

}
						//dairy counter//
int dairy(FILE * fptr,FILE * ptr,FILE* fptr1)
{
	printf("\n\t\t----------------------------------------");
	printf("\n\t\there is list of available dairy products:");
	printf("\n\t\t-----------------------------------------");
	printf("\n  (1)milk\t(2)yogurt\t(3)cheese\t(4)butter\n");
	int m,b,y,c;
	int sum_m,sum_b,sum_y,sum_c,t_d;
	int price[]={100,60,250,450};
	int f[23],i;
   	for(i=17;i<21;i++){
	fscanf(ptr,"%d",&f[i]);
	//printf("\n%d  ",f[i]);
    }
	printf("enter milk in litres : ");
	scanf("%d",&m); 
    if(f[17]<m)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f[17]=f[17]-m;
		fprintf(fptr,"%d ",f[17]);
		sum_m=m*price[0];
		printf("total of milk is:%d",sum_m);
	}
	printf("\nenter yogurt : ");
	scanf("%d",&y);
    if(f[18]<y)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f[18]=f[18]-y;
		fprintf(fptr,"%d ",f[18]);
		sum_y=y*price[1];
		printf("total of yogurts is:%d",sum_y);
	}
	printf("\nenter chees: ");
	scanf("%d",&c);
    if(f[19]<c)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f[19]=f[19]-c;
		fprintf(fptr,"%d ",f[19]);
		sum_c=c*price[2];
		printf("\ntotal of  chees is:%d",sum_c);
	}
	printf("\nenter butters: ");
	scanf("%d",& b);
    if(f[20]<b)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f[20]=f[20]-b;
		fprintf(fptr,"%d ",f[20]);
		sum_b=b*price[3];
		printf("\ntotal of butter is:%d",sum_b);
	}
	t_d=sum_m+sum_y+sum_c+sum_b;
	tot_d=t_d;
	printf("\n\t\t------------------------");
	printf("\n\tpress 1 to continue or 0 to go to bill counter");
	printf("\n\t\t------------------------");
	int n;;
	scanf("%d",&n);
	if(1==n)
	bakery(fptr,ptr);
	else
	bill();
}   
						//bakery counter//
int bakery(FILE * fptr, FILE *ptr,FILE* fptr1)
{
	printf("\n\t\t--------------------------------------");
	printf("\n\t\there list of available bakery products");
	printf("\n\t\t--------------------------------------");
	printf("\n  (1)bread\t(2)cakes\t(3)pastery\t(4)donuts\n");
	int b,c,p,d;
	int price[]={50,250,60,70};
	int sum_b,sum_c,sum_p,sum_d,t_b;
	int f[25],i;
   	for(i=21;i<25;i++){
	fscanf(ptr,"%d",&f[i]);
	//printf("\n%d  ",f[i]);
    }
	printf("\nenter bread: ");
	scanf("%d",&b);
    if(f[21]<b)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f[21]=f[21]-b;
		fprintf(fptr,"%d ",f[21]);
		sum_b=b*price[0];
		printf("\ntotal of bread is:%d",sum_b);
	}
	printf("\nenter cake: ");
	scanf("%d",&c);
    if(f[22]<c)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f[22]=f[22]-c;
		fprintf(fptr,"%d ",f[22]);
		sum_c=c*price[1];
		printf("\ntotal of cake is:%d",sum_c);
	}
	printf("\nenter pasteries: ");
	scanf("%d",&p);
    if(f[23]<p)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f[23]=f[23]-p;
		fprintf(fptr,"%d ",f[23]);
		sum_p=p*price[2];
		printf("\ntotal of pastery is:%d",sum_p);
	}
	printf("\nenter donut: ");
	scanf("%d",&d);
    if(f[24]<d)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f[24]=f[24]-d;
		fprintf(fptr,"%d ",f[24]);
		sum_d=d*price[3];
		printf("\ntotal of donuts is:%d",sum_d);
	}
	t_b=sum_b+sum_p+sum_c+sum_d;
	tot_b=t_b;
	bath(fptr,ptr,fptr1);
}
						//bathroom counter//
int bath(FILE* fptr, FILE* ptr,FILE* fptr1)
{
	printf("\n\t\t------------------------------------------");
	printf("\n\t\there a list of available bathroom products");
	printf("\n\t\t------------------------------------------");
	printf("\n  (1)soap\t(2)toothpaste\t(3)shampoo\t(4)mouthwash");
	int s,t,sh,m;
	int sum_s,sum_t,sum_sh,sum_m,t_bath;
	int price[]={30,20,60,80};
	int f[29],i;
   	for(i=25;i<29;i++)
	   {
	fscanf(ptr,"%d",&f[i]);
	//printf("\n%d  ",f[i]);
    }
    printf("\nenter number of soaps: ");
	scanf("%d",&s);
    if(f[25]<s)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f[25]=f[25]-s;
		fprintf(fptr,"%d ",f[25]);
	
		sum_s=s*price[0];
		printf("\ntotal of soap is:%d",sum_s);
	}
	printf("\nenter number of toothpaste: ");
	scanf("%d",&t);
    if(f[24]<t)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f[26]=f[26]-t;
		fprintf(fptr,"%d ",f[26]);
		sum_t=t*price[1];
		printf("\ntotal of toothpaste is:%d",sum_t);	
	}
	printf("\nenter number of shamppos: ");
	scanf("%d",&sh);
    if(f[27]<sh)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f[27]=f[27]-sh;
		fprintf(fptr,"%d ",f[27]);
		sum_sh=sh*price[2];
		printf("\ntotal of shampoos is:%d",sum_sh);
	}
	printf("\nenter number of mouth wash: ");
	scanf("%d",&m);
    if(f[28]<m)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f[28]=f[28]-m;
		fprintf(fptr,"%d ",f[28]);
		sum_m=m*price[3];
		printf("\ntotal of moth wash is:%d",sum_m);
	}
    t_bath=sum_s+sum_t+sum_m+sum_sh;
	tot_bath=t_bath;
	printf("\n\t\t------------------------");
	printf("\n\tpress 1 to continue or 0 to go to bill counter");
	printf("\n\t\t------------------------");
	int n;
	scanf("%d",&n);
	if(1==n)
	bev(fptr,ptr,fptr1);
	else
	bill();
}
int bev(FILE* fptr,FILE*ptr,FILE* fptr1)
{
	printf("\n\t\t-------------------------------------------");
	printf("\n\t\there is list of available beverage products");
	printf("\n\t\t--------------------------------------------");
	printf("\n  (1)pepsi\t(2)7up\t(3)coke\t(4)fanta\n");
	int price1[]={50};
	int price[]={90};
	int p,s,c,f;
	int f1[33];
	int i;
	for(i=29;i<33;i++)
	{
	fscanf(ptr,"%d",&f1[i]);
	//printf("\n%d  ",f1[i]);
    }
    
	int sum_p,sum_s,sum_c,sum_f,sum_b,n;
	printf("\nenter in 1 or 2 litres");
	scanf("%d",&n);
	if(n==1)
	{
	printf("\nenter number of pepsi: ");
	scanf("%d",&p);    
    if(f1[29]<p)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f1[29]=f1[29]-p;
		fprintf(fptr,"%d ",f1[29]);
		sum_p=p*price1[0];
		printf("\ntotal of pepsi is:%d",sum_p);		
	}
	printf("\nenter number of 7up: ");
	scanf("%d",&s);  	
	if(f1[30]<s)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f1[30]=f1[30]-s;
		fprintf(fptr,"%d ",f1[30]);
		sum_s=s*price1[0];
		printf("\ntotal of 7up is:%d",sum_s);		
	}	
	printf("\nenter number of coke: ");
	scanf("%d",&c);  	
	if(f1[31]<c)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f1[31]=f1[31]-c;
		fprintf(fptr,"%d ",f1[31]);
		sum_c=c*price1[0];
		printf("\ntotal of coke is:%d",sum_c);	
	}
	printf("\nenter number of 7up: ");
	scanf("%d",&f);  	
	if(f1[32]<f)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f1[32]=f1[32]-f;
		fprintf(fptr,"%d ",f1[32]);
		sum_f=f*price1[0];
		printf("\ntotal of 7up is:%d",sum_f);		
	}		
	}
	if(n==2)
	{
	printf("\nenter number of pepsi: ");
	scanf("%d",&p);    
    if(f1[29]<p)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f1[29]=f1[29]-p;
		fprintf(fptr,"%d ",f1[29]);
		sum_p=p*price[0];
		printf("\ntotal of pepsi is:%d",sum_p);	
		
	}
	printf("\nenter number of 7up: ");
	scanf("%d",&s);  	
	if(f1[30]<s)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f1[30]=f1[30]-s;
		fprintf(fptr,"%d ",f1[30]);
		sum_s=s*price[0];
		printf("\ntotal of 7up is:%d",sum_s);		
	}	
	printf("\nenter number of coke: ");
	scanf("%d",&c);  	
	if(f1[31]<c)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f1[31]=f1[31]-c;
		fprintf(fptr,"%d ",f1[31]);
		sum_c=c*price[0];
		printf("\ntotal of coke is:%d",sum_c);	
	}
	printf("\nenter number of fants: ");
	scanf("%d",&f);  	
	if(f1[32]<f)
	{
		printf("sorry not available at moment");
	}
	else
	{
		f1[32]=f1[32]-f;
		fprintf(fptr,"%d ",f1[32]);
		sum_f=f*price[0];
		printf("\ntotal of fantas is:%d",sum_f);			
	}		
	}
	sum_b=sum_p+sum_s+sum_c+sum_f;
	tot_bev=sum_b;
	tot_tot=tot_bath+tot_d+tot_b+tot_fr+tot_veg+tot_k+tot_bev;
	bill();
}
int bill(void)
{

	printf("\n--------------------------------------------------------------------");
	printf("\n\ttotal of bathroom products is:%d",tot_bath);
	printf("\n\ttotal of dairy products is:%d",tot_d);
	printf("\n\ttotal of bakery products is:%d",tot_b);
	printf("\n\ttotal of fruits products is:%d",tot_fr);
	printf("\n\ttotal of vegetable products is:%d",tot_veg);
	printf("\n\ttotal of kitchen products is:%d",tot_k);
	printf("\n\ttotal of beverages products is:%d",tot_bev);
	printf("\n--------------------------------------------------------------------");
	printf("\n\ttotal of all products is:%d",tot_tot);
	printf("\n--------------------------------------------------------------------");
	printf("\n   thanks for shopping\t   Come back later");
	printf("\n--------------------------------------------------------------------");	
}

						// owner counter//
			// it takes values from files and print it//
int owner(FILE *ptr,FILE* fptr1)
{
	int f[33];
	int i=0,j;
	char *ch[7]={"mangoes","banana","apricot","gauva","grapes","pineapple","apple"};
	char *ch1[5]={"tomatoes","pumpkin","onion","corn","potato"};
	char *ch2[5]={"cooker","knife","frying pan","spoons","plates"};
	char *ch3[4]={"milk","yogurt","chees","butter"};
	char *ch4[5]={"bread","cake","pastery","donut"};
	char *ch5[4]={"soap","toothpaste","shampoo","mouthwash"};
	char *ch6[4]={"pepsi","7up","coke","fanta"};
	char *ch7[]={"fruits","vegetables","kitchen","dairy","bakery","bathroom","beverages"};
	for(i=0;i<7;i++){
		fscanf(ptr,"%d", &f[i]);
		if(0==i)
		{
			printf("\n\t\t----------------------");
			printf("\n\t\tremaing fruits are:");
			printf("\n\t\t-----------------------");
		}
		printf("\nremaining %s are :%d\n",ch[i],f[i]);
	}
	for(i=7;i<12;i++){
		fscanf(ptr,"%d", &f[i]);
		if(7==i)
		{
			printf("\n\t\t-------------------------");
			printf("\n\t\tremaing vegetables are:");
			printf("\n\t\t-------------------------");
		}	
		printf("\nremaining %s are :%d",ch1[i-7],f[i]);
    }
    for(i=12;i<17;i++)
    {
    	fscanf(ptr,"%d", &f[i]);
    	if(12==i)
    	{
    		printf("\n\t\t-----------------------------");
    		printf("\n\t\tremaing kitchen products are:");
    		printf("\n\t\t-----------------------------");
		}
    	
    	printf("\nremaing %s are:%d",ch2[i-12],f[i]);
	}
     for(i=17;i<21;i++)
    {
    	fscanf(ptr,"%d", &f[i]);
    	if(17==i)
    	{
    		printf("\n\t\t-----------------------------");
    		printf("\n\t\tremaing dairy products are:");
    		printf("\n\t\t-----------------------------");
		}
    	printf("\nremaing %s are:%d",ch3[i-17],f[i]);
    	
	}
	for(i=21;i<25;i++)
	{
		fscanf(ptr,"%d", &f[i]);
		if(21==i)
		{
			printf("\n\t\t-----------------------------");
			printf("\n\t\there list of bakery products");
			printf("\n\t\t-----------------------------");
		}
		
		printf("\nremaing %s are: %d",ch4[i-21],f[i]);
	}
	for(i=25;i<29;i++)
	{
		fscanf(ptr,"%d", &f[i]);
		if(25==i)
		{
			printf("\n\t\t-----------------------------");
			printf("\n\t\there list of bathroom products");
			printf("\n\t\t-----------------------------");
		}
		
		printf("\nremaing %s are: %d",ch5[i-25],f[i]);
	}
	for(i=29;i<33;i++)
	{
		fscanf(ptr,"%d", &f[i]);
		if(29==i)
		{
			printf("\n\t\t-------------------------------");
			printf("\n\t\there list of beverages products");
			printf("\n\t\t-------------------------------");
		}
		;
		printf("\nremaing %s are: %d",ch6[i-29],f[i]);
	}
	printf("\n\t--------------------------------------------------");
	printf("\n\t\ttotal sale amount is");
	printf("\n\t--------------------------------------------------");
	int f1[8];
	for(i=0;i<8;i++)
	{
		fscanf(fptr1,"%d",&f1[i]);
		printf("\nsales of %s is :%d",ch7[i],f1[i]);
}
}



