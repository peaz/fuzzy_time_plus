#include "english_time.h"
#include "string.h"

static const char* const ONETEENS[] = {
  "zero",
  "one",
  "two",
  "three",
  "four",
  "five",
  "six",
  "seven",
  "eight",
  "nine",
  "ten",
  "eleven",
  "twelve",
  "thirteen",
  "fourteen",
  "fifteen",
  "sixteen",
  "seventeen",
  "eighteen",
  "nineteen"
};

static const char* const TWENS[] = {
  "twenty",
  "thirty",
  "forty",
  "fifty",
};

static const char* STR_TEEN = "teen";
static const char* STR_OH_CLOCK = "o'clock";
static const char* STR_OH = "o'";
static const char* STR_NOON = "noon";
static const char* STR_MIDNIGHT = "midnight";
static const char* STR_QUARTER = "quarter";
static const char* STR_TO = "to";
static const char* STR_PAST = "past";
static const char* STR_HALF = "half";
static const char* STR_ITS = "it's";
static const char* STR_ALMOST = "almost";
static const char* STR_JUST = "just";

void english_time_2lines(int hours, int minutes, char* str_hour, char* str_minute) {
    
  strcpy(str_hour, "");
  strcpy(str_minute, "");

  if(hours == 0) {
    strcat(str_hour,"twelve");
  }
  else {
    if (hours > 12) {
      hours = hours - 12;
    }
    strcat(str_hour, ONETEENS[hours]);
  }

  if(minutes == 0){
    strcat(str_minute,STR_OH_CLOCK);
  }
  else {
    if(minutes < 20) {
      if(minutes < 10) {
        strcat(str_minute, STR_OH);  
      }
      strcat(str_minute, ONETEENS[minutes]);
      if((minutes == 14) || (minutes > 15)) {
        strcpy(str_minute, ONETEENS[minutes-10]);
        strcat(str_minute, "\n");
        strcat(str_minute, STR_TEEN);
      }
    }
    else {
      strcat(str_minute, TWENS[((minutes/10)%10)-2]);
      if((minutes%10)>0) {
        strcat(str_minute, "\n");
        strcat(str_minute, ONETEENS[minutes%10]); 
      } 
    }
  }
}

void english_time_3lines(int hours, int minutes, char* str_hour, char* str_minute1, char* str_minute2) {
  
  strcpy(str_hour, "");
  strcpy(str_minute1, "");
  strcpy(str_minute2, "");

  if(hours == 0) {
    strcat(str_hour,"twelve");
  }
  else {
    if (hours > 12) {
      hours = hours - 12;
    }
    strcat(str_hour, ONETEENS[hours]);
  }

  if(minutes == 0){
    strcat(str_minute1,STR_OH_CLOCK);
  }
  else {
    if(minutes < 20) {
      if(minutes < 10) {
        strcat(str_minute1, STR_OH);  
      }
      strcat(str_minute1, ONETEENS[minutes]);
      if((minutes == 14) || (minutes > 15)) {
        strcpy(str_minute1, ONETEENS[minutes-10]);
        strcpy(str_minute2, STR_TEEN);
      }
    }
    else {
      strcat(str_minute1, TWENS[((minutes/10)%10)-2]);
      if((minutes%10)>0) {
        strcat(str_minute2, ONETEENS[minutes%10]); 
      } 
    }
  }
}

void fuzzy_time(int hours, int minutes, char* line1, char* line2, char* line3) {

  strcpy(line1, "");
  strcpy(line2, "");
  strcpy(line3, "");

  if (minutes > 0 && minutes < 5) {
    strcat(line1,STR_JUST);
  }
  else if ((minutes >= 5 && minutes < 10) || (minutes >= 55 && minutes < 58)) {
    strcat(line1,ONETEENS[5]);
  }
  else if ((minutes >= 10 && minutes < 15) || (minutes >= 50 && minutes < 55)) {
    strcat(line1,ONETEENS[10]);
  }
  else if ((minutes >= 15 && minutes < 20) || (minutes >= 45 && minutes < 50)) {
    strcat(line1,STR_QUARTER);
  }
  else if ((minutes >= 20 && minutes < 25) || (minutes >= 40 && minutes < 45)) {
    strcat(line1,TWENS[0]);
  }
  else if ((minutes >= 25 && minutes < 30) || (minutes >= 35 && minutes < 40)) {
    strcat(line1,TWENS[0]);
    strcat(line2,ONETEENS[5]);
    strcat(line2," ");
  }
  else if (minutes >= 30 && minutes < 35) {
    strcat(line1,STR_HALF);
  }
  else if (minutes >=58 && minutes < 60) {
    strcat(line1,STR_ALMOST);
  }

  if(minutes == 0){
    strcat(line1,STR_ITS);
    if(hours == 0) {
      strcat(line2,STR_MIDNIGHT);
    }
    else if (hours == 12) {
      strcat(line2, STR_NOON);
    }
    else {
      if (hours > 12) hours -= 12;
      strcat(line2, ONETEENS[hours]);
      strcat(line3, STR_OH_CLOCK);
    }
  } 
  else {
    if(minutes < 35) {
      if (hours > 12) hours -= 12;
      strcat(line2,STR_PAST);
    }
    else {
      hours += 1;
      if (hours == 24) hours = 0;
      if (hours > 12) hours -= 12;
      strcat(line2,STR_TO);
    }

    if(hours == 0) {
      strcat(line3,STR_MIDNIGHT);
    }
    else if (hours == 12) {
      strcat(line3, STR_NOON);
    }
    else {
      strcat(line3, ONETEENS[hours]);
    }

  }
  
}