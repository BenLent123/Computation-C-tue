#include <stdio.h>
#include <math.h>
    int main(void)
    {
        char cmd;
        float curr_re = 0.0;
        float curr_im = 0.0;
        float new_re = 0.0;
        float new_im = 0.0;
        float p = 0.0;
        float inter = 0.0;
        float inter1 = 0.0;
        float inter2 = 0.0;
        int i;
        int re;
        int im;
     
       
        
      printf("** Complex Calculator **\n");
do {
         
    printf( "Operation [0+-*crpq]? ");
    
    scanf(" %c",&cmd);
    
    
      if (cmd=='-') {
        printf("Complex operand?");
        printf(" ");
        scanf("%f %f", &new_re, &new_im);
        curr_re=curr_re-new_re;
        curr_im=curr_im-new_im;
        
    }
     else if (cmd=='*') {
        printf("Complex operand?");
        printf(" ");
        scanf("%f %f", &new_re, &new_im);
        inter=0+curr_re;
        curr_re=curr_re*new_re-new_im*curr_im;
        curr_im=curr_im*new_re+inter*new_im;    
   
    }
    else if (cmd=='+') {
        printf("Complex operand?");
        printf(" ");
        scanf("%f %f", &new_re, &new_im);
        curr_re=curr_re+new_re;
        curr_im=curr_im+new_im;
    
    }
    
    else if (cmd=='r') {
        printf("Natural operand?");
        printf(" ");
        scanf("%f", &p);
        // do this r times --------------------------
    new_im=0;
    new_re=1;
    for (i=0;i<p;i++) 
    {
    
    inter1 = curr_re * new_re - curr_im * new_im;
    inter2 = curr_re * new_im  + curr_im* new_re;
    new_re = inter1;
    new_im = inter2;
    }
    curr_re=new_re;
    curr_im=new_im;
    
    // ---------------------------------------------------
    
    }
    else if (cmd=='c') {
        curr_re=curr_re;
        curr_im=-curr_im;
    
        
        
    }
    else if (cmd=='0') {
        
        curr_re=curr_re-curr_re;
        curr_im=curr_im-curr_im;
        
    }
    
    else if (cmd=='p') {
     //prints this array of dots --> seen in task sheet
     re=curr_re;
     im=-curr_im;
    for (int outer=-10;outer <= 10; outer++){
    for (int inner=-10;inner <= 10; inner++){
        
     if (outer==0&&inner==0&&im!=0&&re!=0) {printf("+");}
    else if (outer==0&&inner!=0) {printf("-");}
    else if (inner==0&&outer!=0) {printf("|");} 
    else if (outer==im&&inner==re){printf("*");}
    else {
    printf(".");
    }
    }
    printf("\n");
    }     
        
    }
    
    
    else if (cmd!='q'&&cmd!='+'&&cmd!='-'&&cmd!='*'&&cmd!='0'&&cmd!='p') {
        printf("Invalid command '%s'\n", &cmd);
        
    }
    
    if (curr_im < 0) 
    {
     printf("Current value is %f%fi\n", curr_re, curr_im);
    } else {
    
      printf("Current value is %f+%fi\n", curr_re, curr_im);   
     }
     
    
        
     if (cmd=='q') {
       
    printf("Bye!\n");
        
    }
   
    } while (cmd!='q');
      }
    
    
        