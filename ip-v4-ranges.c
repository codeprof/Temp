#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <syslog.h>


#define MAX_LINE_SIZE 1024
#define MAX_PARTS 64

#define MAX_IPV4_RANGES 8000


int parts = 0;
char** parts[MAX_PARTS] = {}


int currentRange = -1;
unsigned long rangesStart[MAX_IPV4_RANGES];
unsigned long rangesEnd[MAX_IPV4_RANGES];


void logErr(char *msg)
{
	setlogmask(LOG_UPTO (LOG_NOTICE));
	openlog("iptable-block", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
	syslog(LOG_ERROR, msg);
	closelog();	
}


void readLine(void)
{
	char *line = NULL;
	parts[0] = NULL;
	if (fges(fd, MAX_LINE_SIZE, line) != NULL)
	{
		parts = 0;
		while ((i >= MAX_PARTS-1) && (parts[i++] = strtok(line, ",") != NULL))
		{
			line = NULL;
		}
		parts[i] = NULL;
	}
}

void addIPv4Range(unsigned long rangeStart, unsigned long rangeEnd)
{
	
	if ((currentRange >= 0) && (rangesEnd[currentRange]+1 == rangeStart))
	{
		rangesEnd[currentRange] = rangeEnd;
	} 
	else
	{
		if (currentRange < MAX_IPV4_RANGES)
		{
			currentRange++;
			rangesStart[currentRange] = rangeStart;			
			rangesEnd[currentRange] = rangeEnd;
		}
		else
		{
			logErr("out of free ranges.");
		}
	}
}


char* getRangeIPAndMask()
{
	
}



unsigned long getULong(int i)
{
	if (i < 0) i = 0;
	if (i >= MAX_PARTS) i = MAX_PARTS - 1;
	char *ptr = parts[i];
	if (ptr[0] == '"') ptr++;
	return (unsigned long)atoll(ptr);
}

char * getIP(unsigned long startIP, unsigned long endIP)
{
	sprintf(tmp, "%i.%i.%i.%i/")
}



char* nextIP()
{
	
	if (line[0] != '#')
	{
	char *str = strtok(line, ",")
	if (str != NULL)
	{
		
		long tmp = (unsigned long)atoll(strtok(line, ","));
	}
	}
}



 

int main()
{
  if (system("wget software77.net/geo-ip/?DL=2 -O /tmp/IpToCountry.csv.zip") == 0)
  {
	  if (system("unzip /tmp/IpToCountry.csv.zip -d /tmp") == 0)
	  {	  		  
		  FILE *myfile = fopen ( "/tmp/IpToCountry.csv", "r" );
		  while(feof(fd) == 0)
		  {
			  readLine();	         
		  } 
		  fclose (pFile);	 
	  }
  }
}
