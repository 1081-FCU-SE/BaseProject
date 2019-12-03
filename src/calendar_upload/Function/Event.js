var sqlite = require('sqlite3').verbose();

var db = new sqlite.Database('TimeTraveler.db');

var eventlist = document.getElementById('EventList');

function CreateTable(){
	db.serialize(function(){
		db.run('CREATE TABLE Calendar (Date text,StartTime text,FinishTime text,EventName text,WorkDone text DEFAULT \'O\')');
	})
}

function Eventupdate(date){
	var i = 0 ;
	var addevent = document.getElementById('AddEvenet');
	now_day = date;
	db.serialize(function(){
		db.each("SELECT * ,rowid AS id FROM Calendar WHERE Date =\'" + date + "\'",
			function(err,row){
				console.log(row);
				if(row){
					console.log(i);
					var text = row.StartTime + '~' + row.FinishTime + ' | ' + row.EventName;
					console.log(text);
					var button = document.createElement('button');
					button.id = row.id+31;
					button.onclick = function(){Workdone(this.id)};
					button.innerHTML = row.WorkDone;
					if(eventlist.childNodes[i].id == "AddEvent"){
					console.log("create");
					var temp = document.createElement('span');
					temp.innerHTML = text + '<br>';
					eventlist.insertBefore(temp,eventlist.childNodes[0]);
					//eventlist.appendChild(temp);
					}else{
					eventlist.childNodes[i].innerHTML = text;
					}
					eventlist.insertBefore(button,eventlist.childNodes[0]);
					i+=2;
				}
		});
	});
	while(eventlist.childNodes[i].id != "AddEvent"){
		console.log("del");
		eventlist.removeChild(eventlist.childNodes[i]);
		}
}

document.getElementById('AddEvent').onsubmit = function(e){
	e.preventDefault();
	var ST = this.StartTime.value;
	var FT = this.FinishTime.value;
	var EN = this.EventName.value;
	if(ST=="" || FT=="" || EN=="") {
		alert("input no null");
		return;
	}
	db.serialize(function(){
		var stmt = db.prepare("INSERT INTO Calendar VALUES (?,?,?,?,'o')");   //int set to 0
		stmt.run(now_day,ST,FT,EN);
		stmt.finalize();
	});
	Eventupdate(now_day);
	this.reset();
}


document.getElementById('DelEvent').onsubmit = function(e){
	e.preventDefault();
	var EN = this.EventName.value;
	if(EN=="") {
		alert("input no null");
		return;
	}
	db.serialize(function(){
		var stmt = db.prepare("DELETE FROM Calendar WHERE Date = ? and EventName = ? ");   //int set to 0
		stmt.run(now_day,EN);
		stmt.finalize();
	});
	Eventupdate(now_day);
	this.reset();
}

function Workdone(id){
	db.serialize(function(){
		//console.log(id);
		db.run("UPDATE Calendar SET WorkDone='v' WHERE rowid=?",id-31);
	});
	document.getElementById(id).innerHTML = 'v';
}

Eventupdate(now_day);
//db.close();
//CreateTable();
