const moment = require('moment')

const elNow = document.querySelector('.now-time')
const elAlarm = document.querySelector('.alarm-time')
//elAlarm.addEventListener('change', onAlarmTextChange)

let time = moment()

let nowTime
let alarmTime

/** Set Time */
const now = moment(time).format('HHmmss')
nowTime = now
elNow.innerText = now

const alarm = moment(time).add(5, 'seconds').format('HHmmss')
alarmTime = alarm
elAlarm.value = alarm


let stop

var i=0
timer()
/** Now Time */
function timer() {
    time = moment().format('HH mm ss')

    /** Set Now */
    nowTime = time
    elNow.innerText = time

    //check()
    const diff = moment(nowTime, 'HHmmss').diff(moment(alarmTime, 'HHmmss'))
    if (diff === 0) {
        alert('wake up!')
	clearTimeout(stop)
    }else{
     stop = setTimeout(() => {timer()}, 1000)
    }
}

/** Check Time */
//function check() {
    
 //   }
//}


/**
 * Save To Global Variable,
 * Can't Read Dom In Minimize Status.
 * @param {event} event
 */
//function onAlarmTextChange(event) {
//    alarmTime = event.target.value
//}
