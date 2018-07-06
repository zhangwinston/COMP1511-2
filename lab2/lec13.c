int daysToNextThursday (int year, int month, int day){
	int doomsday = yearToDoomsday (year);
	int leapYear = isLeapYear(year);
	int weekDay = dayOfWeek(doomsday,leapYear,month,day);
	
	int daysToThursday;
	
	return daysToThursday;
	
}
