#include<reg51.h>
#define msec 100
#define lcd_data_str_pin P2
#include<stdio.h>


sbit  gcA=P1^0;		// interrupt for A (green corridor)
sbit  gcB=P1^1;        	// interrupt for B (green corridor)
sbit  gcC=P1^2;      	// interrupt for C (green corridor)
sbit  gcD=P1^3;     	// interrupt for D (green corridor)

sbit  SenA=P0^7;     // sensor in line A
sbit  SenB=P0^2;     // sensor in line B
sbit  SenC=P0^1;     // sensor in line C
sbit  SenD=P0^5;     // sensor in line D

void normal(); 

void main (void)
{
		while(1)
		{ 
			normal();
		}	
} 

void delay(unsigned int m_sec)  //Time delay function
{
		int i,j ;
		for(i=0;i<m_sec;i++)
 	    for(j=0;j<500;j++);
}         
 

void normal()
{
 		      P2=0x28;P3=0x11;  // A Green
				delay(5000);
				if(SenA == 0)
				{delay(10000);}
				
				while(gcA==1)
		        {
		        	P2=0x28;P3=0x11;  // A Green
				   delay(5000);
		        }
				
				P2=0x41;P3=0x11;  // A yellow
			   delay(2000);
			   P2=0x82;P3=0x11;   // B Green
			   delay(5000);
			   if(SenB == 0)
				{delay(10000);}
				
				while(gcB==1)
				{
					P2=0x82;P3=0x11;   // B Green
			   	delay(5000);
			   }
				
			   P2=0x81;P3=0x11;   // B yellow
			   delay(2000);
			   P2=0x88;P3=0x14;    // C Green
			   delay(5000);
			   if(SenC == 0)
				{delay(10000);}
				
				while(gcC==1)
				{
					P2=0x88;P3=0x14;    // C Green
			   	delay(5000);
				}
				
			  
			   P2=0x88;P3=0x12;   // C yellow
			   delay(2000);
			   P2=0x88;P3=0x41;    // D Green
			   delay(5000);
			   if(SenD == 0)
				{delay(10000);}
				
				while(gcD == 1)
				{ 	
					P2=0x88;P3=0x41;    // D Green
			   	delay(5000);
				}
			      
			   P2=0x88;P3=0x21;     // D yellow
			   delay(2000);
			   
}