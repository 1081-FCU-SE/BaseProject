var sqlite = require('sqlite3').verbose();

var moment = require('moment');

var db = new sqlite.Datebase('TimeTraveler.db');

var AlarmTime = [];
var AlarmIndex = 0;

var stop;

function StartAlarm(){
	var time = moment().format('HHmm');
	var diff = moment(time,'HHmm').diff(moment(AlarmTime[AlarmIndex],'HHmm'));
	if(diff > 0) {
		AlarmIndex++;
	}
	if(diff === 0){
		alert(wake up!);
		AlarmIndex++;
	}
}

setinterval(() => {StartAlarm()},60000);

function refreashalarmtime(date){
	update_day;
	AlarmTime = [];
	AlarmIndex = 0;
	db.serialize(function(){
		db.each("SELECT * FROM Calendar WHERE Date =\'"+date+"\'",function(){
			AlarmTime.push(row.StartTime);
		});
	});
	AlarmTime.sort(function(a,b) {return a-b;});
}

setinterval(() => {refreashalarmtime(now_day)},12*60*60*1000);
