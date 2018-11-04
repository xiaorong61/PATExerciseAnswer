'use strict';
var rl = require("readline").createInterface(process.stdin, process.stdout);
var paper = [];
var map = new Map();
map.set("A", "MON");
map.set("B", "TUE");
map.set("C", "WED");
map.set("D", "THU");
map.set("E", "FRI");
map.set("F", "SAT");
map.set("G", "SUN");
rl.on("line", function (line) {
    paper.push(line.trim().split(""));
    if (paper.length == 4)
        rl.close();
}).on("close", function () {
    var day, hour;
    var i = 0;
    for (;; i++) {
        var current = paper[0][i];
        if (current == paper[1][i] && map.has(current)) {
            day = map.get(current);
            break;
        }
    }
    for (i++;; i++) {
        var current = paper[0][i];
        if (current == paper[1][i])
            if (/[A-N]/.test(current)) {
                hour = current.charCodeAt(0) - "A".charCodeAt(0) + 10;
                break;
            }
            else if (/[0-9]/.test(current)) {
                hour = Number.parseInt(current);
                break;
            }
    }
    var minute = paper[2]
        .map(function (item, i) { return /[a-zA-Z]/.test(item) && item == paper[3][i]; })
        .indexOf(true);
    console.log(day + " " + (hour < 10 ? "0" + hour : hour) + ":" + (minute < 10 ? "0" + minute : minute));
    process.exit(0);
});
