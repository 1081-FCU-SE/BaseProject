var leap_year=[31,29,31,30,31,30,31,31,30,31,30,31];
var average_year=[31,28,31,30,31,30,31,31,30,31,30,31];
var week_day=["SUN","MON","TUE","WED","THU","FRI","SAT"];
var month_name=["January","February","March","April","May","June","July","August","September","October","November","December"];

var now_date = new Date();
var now_year;
var now_month;
var now_day;

function update_day(){
	now_year = now_date.getFullYear();
	now_month = now_date.getMonth();
	now_day = now_year + '/' + (now_month+1) + '/' +now_date.getDate();
}

update_day();

function Startday(y,m){
	var tempdate = new Date(y,m,1);
	return (tempdate.getDay());
}

function Isleapyear(y,m){
	if(y%400 == 0 || (y%4==0 && y%100!=0)){
		return leap_year[m];
	}
	else{
		return average_year[m];
	}
}

function createelement(){
	var weekday = document.getElementById('weekday');
	for(var i = 0;i < 7;i++){
		var temp = document.createElement('span');
		temp.innerHTML = week_day[i];
		weekday.appendChild(temp);
	}
	var day = document.getElementById('day');
	for(var i = 0;i < 42;i++){
		var temp = document.createElement('span');
		temp.innerHTML = "";
		day.appendChild(temp);
	}
}

function update(){
	var day = document.getElementById('day');
	var startday = Startday(now_year,now_month);
	var totleday = Isleapyear(now_year,now_month);
	for(var i = 1 ; i <= startday ; i++){
		day.childNodes[i].innerHTML = "";
		day.childNodes[i].id = "";
		day.childNodes[i].onclick = 0;
	}
	for(var i = 1 ; i <= totleday ; i++){
		day.childNodes[i+startday].innerHTML = i.toString();
		day.childNodes[i+startday].id = now_year +'/'+ (now_month+1) +'/'+ i;
		day.childNodes[i+startday].onclick = function(){Eventupdate(this.id)};
	}
	for(var i = totleday+startday ; i<42 ; i++){
		day.childNodes[i+1].innerHTML = "";
		day.childNodes[i+1].id = "";
		day.childNodes[i+1].onclick = 0;
	}
	document.getElementById('month').innerHTML = month_name[now_month];
	document.getElementById('year').innerHTML = now_year;
}



//function Eventupdate(date){
//	alert(date);
//}

document.getElementById('pev').onclick = function(e){
	e.preventDefault();
	now_month--;
	if(now_month < 0){
		now_year--;
		now_month = 11;
	}
	update();
}

document.getElementById('next').onclick = function(e){
	e.preventDefault();
	now_month++;
	if(now_month > 11){
		now_year++;
		now_month = 0;
	}
	update();
}


document.getElementById('AddEvent').onsubmit = function(e){
	e.preventDefault();
	alert(this.StartTime.value + '~' +this.FinishTime.value + ' | ' + this.EventName.value);
	this.reset();
}


createelement();
update();
