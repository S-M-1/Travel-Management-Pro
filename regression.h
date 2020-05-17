
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<cstdlib>
#include<ctype.h>

namespace reg{
void gn(long int line[100]){
    int i;

    const char * commandsForGnuplot[] = {"set title \"Probability Graph\"", "plot     'data.temp' with lines"};
    long int xvals[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    
    FILE * temp = fopen("data.temp", "w");
   
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    
    for (i=0; i < 12; i++)
    {
    fprintf(temp, "%d %d \n", xvals[i], line[i]); 
    }

    for (i=0; i < 2; i++)
    {
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); 
    }

}

void Mumbai(){
		long int line[12];
		long int i,x_b[12],y_b[12],x_b_2[12],y_b_2[12],mean_x=0,mean_y=0;
		long int x_y[12],s_x_y=0,s_x_b_2=0;
		long int b0,b1;
		long int x[12]={1,2,3,4,5,6,7,8,9,10,11,12};
		long int y[12] = {16481,134673,37498,36486,97636,54647,53637,98631,23322,78738,9993,23234};
        
		
		for(i=0;i<12;i++){
			mean_x+=x[i];
			mean_y+=y[i];
		}
		
		mean_x = mean_x/12;
		mean_y = mean_y/12;
		
		 for(i=0;i<12;i++){
	     	x_b[i] = x[i]-mean_x;
	     	y_b[i] = y[i]-mean_y;
		 }
		 
		 for(i=0;i<12;i++){
	     	x_b_2[i] = pow(x_b[i],2);
	     	y_b_2[i] = pow(y_b[i],2);
		 }
		 
		 for(i=0;i<12;i++){
		 	x_y[i] =x_b[i]*y_b[i];
		 	s_x_y += x_y[i]; 
		 }
		 
		 for(i=0;i<12;i++){
		 	s_x_b_2+= x_b_2[i];
		 }
		 
		b1 = s_x_b_2/12;
		
		// Intercept
		
		b0 = mean_y-(b1*mean_x);

        // Now make line and plot


        for(i=0;i<12;i++){
            line[i]=b0+(b1*y[i]);
        }


    gn(line);
        

}
	

	void Pondicherry(){
		long int line[12];
		int i,x_b[12],y_b[12],x_b_2[12],y_b_2[12],mean_x=0,mean_y=0;
		int x_y[12],s_x_y=0,s_x_b_2=0;
		int b0,b1;
		int x[12]={1,2,3,4,5,6,7,8,9,10,11,12};
		int y[12] = {41264,23212,34341,45632,45521,45667,11111,23232,9992,2124,34345,23231};
		

		for(i=0;i<12;i++){
			mean_x+=x[i];
			mean_y+=y[i];
		}
		
		mean_x = mean_x/12;
		mean_y = mean_y/12;
		
		 for(i=0;i<12;i++){
	     	x_b[i] = x[i]-mean_x;
	     	y_b[i] = y[i]-mean_y;
		 }
		 
		 for(i=0;i<12;i++){
	     	x_b_2[i] = pow(x_b[i],2);
	     	y_b_2[i] = pow(y_b[i],2);
		 }
		 
		 for(i=0;i<12;i++){
		 	x_y[i] =x_b[i]*y_b[i];
		 	s_x_y += x_y[i]; 
		 }
		 
		 for(i=0;i<12;i++){
		 	s_x_b_2+= x_b_2[i];
		 }
		 
		b1 = s_x_b_2/12;
		
		// Intercept
		
		b0 = mean_y-(b1*mean_x);
		
		
        // Now make line and plot


        for(i=0;i<12;i++){
            line[i]=b0+(b1*y[i]);
        }


        gn(line);
	}
	
	void Kolkata(){
		long int line[12];
		int i,x_b[12],y_b[12],x_b_2[12],y_b_2[12],mean_x=0,mean_y=0;
		int x_y[12],s_x_y=0,s_x_b_2=0;
		int b0,b1;
		int x[12]={1,2,3,4,5,6,7,8,9,10,11,12};
		int y[12] = {4567,9876,71253,34309,87233,21313,34459,92731,83470,28397,12304,23047};
		

		for(i=0;i<12;i++){
			mean_x+=x[i];
			mean_y+=y[i];
		}
		
		mean_x = mean_x/12;
		mean_y = mean_y/12;
		
		 for(i=0;i<12;i++){
	     	x_b[i] = x[i]-mean_x;
	     	y_b[i] = y[i]-mean_y;
		 }
		 
		 for(i=0;i<12;i++){
	     	x_b_2[i] = pow(x_b[i],2);
	     	y_b_2[i] = pow(y_b[i],2);
		 }
		 
		 for(i=0;i<12;i++){
		 	x_y[i] =x_b[i]*y_b[i];
		 	s_x_y += x_y[i]; 
		 }
		 
		 for(i=0;i<12;i++){
		 	s_x_b_2+= x_b_2[i];
		 }
		 
		b1 = s_x_b_2/12;
		
		// Intercept
		
		b0 = mean_y-(b1*mean_x);


        // Now make line and plot


        for(i=0;i<12;i++){
            line[i]=b0+(b1*y[i]);
        }

        gn(line);
	}
	
	void Goa(){
		long int line[12];
		int i,x_b[12],y_b[12],x_b_2[12],y_b_2[12],mean_x=0,mean_y=0;
		int x_y[12],s_x_y=0,s_x_b_2=0;
		int b0,b1;
		int x[12]={1,2,3,4,5,6,7,8,9,10,11,12};
		int y[12] = {4570,1234,2141,43431,67123,45788,23490,21568,21234,45612,46567,43122};
		

		for(i=0;i<12;i++){
			mean_x+=x[i];
			mean_y+=y[i];
		}
		
		mean_x = mean_x/12;
		mean_y = mean_y/12;
		
		 for(i=0;i<12;i++){
	     	x_b[i] = x[i]-mean_x;
	     	y_b[i] = y[i]-mean_y;
		 }
		 
		 for(i=0;i<12;i++){
	     	x_b_2[i] = pow(x_b[i],2);
	     	y_b_2[i] = pow(y_b[i],2);
		 }
		 
		 for(i=0;i<12;i++){
		 	x_y[i] =x_b[i]*y_b[i];
		 	s_x_y += x_y[i]; 
		 }
		 
		 for(i=0;i<12;i++){
		 	s_x_b_2+= x_b_2[i];
		 }
		 
		b1 = s_x_b_2/12;
		
		// Intercept
		
		b0 = mean_y-(b1*mean_x);


        // Now make line and plot


        for(i=0;i<12;i++){
            line[i]=b0+(b1*y[i]);
        }

        gn(line);
	}
	
	void Chennai(){
		long int line[12];
		int i,x_b[12],y_b[12],x_b_2[12],y_b_2[12],mean_x=0,mean_y=0;
		int x_y[12],s_x_y=0,s_x_b_2=0;
		int b0,b1;
		int x[12]={1,2,3,4,5,6,7,8,9,10,11,12};
		int y[12] = {98632,7490,2364,23789,20123,34371,23882,24882,21344,23823,21344,21344};
	

		for(i=0;i<12;i++){
			mean_x+=x[i];
			mean_y+=y[i];
		}
		
		mean_x = mean_x/12;
		mean_y = mean_y/12;
		
		 for(i=0;i<12;i++){
	     	x_b[i] = x[i]-mean_x;
	     	y_b[i] = y[i]-mean_y;
		 }
		 
		 for(i=0;i<12;i++){
	     	x_b_2[i] = pow(x_b[i],2);
	     	y_b_2[i] = pow(y_b[i],2);
		 }
		 
		 for(i=0;i<12;i++){
		 	x_y[i] =x_b[i]*y_b[i];
		 	s_x_y += x_y[i]; 
		 }
		 
		 for(i=0;i<12;i++){
		 	s_x_b_2+= x_b_2[i];
		 }
		 
		b1 = s_x_b_2/12;
		
		// Intercept
		
		b0 = mean_y-(b1*mean_x);

        // Now make line and plot


        for(i=0;i<12;i++){
            line[i]=b0+(b1*y[i]);
        }
        gn(line);
	}

}