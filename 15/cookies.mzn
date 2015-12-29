int: n = 4;
array[1..n] of int: cap = [5, -1, 0, -1];
array[1..n] of int: dur = [-1, 3, -1, 0];
array[1..n] of int: fla = [0, 0, 4, 0];
array[1..n] of int: tex = [0, 0, 0, 2];
array[1..n] of int: cal = [5, 1, 6, 8];

array[1..n] of var int: amount;
var int: total_cap = max(0, sum (i in 1..n) (amount[i] * cap[i]));
var int: total_dur = max(0, sum (i in 1..n) (amount[i] * dur[i]));
var int: total_fla = max(0, sum (i in 1..n) (amount[i] * fla[i]));
var int: total_tex = max(0, sum (i in 1..n) (amount[i] * tex[i]));
var int: total_cal = sum (i in 1..n) (amount[i] * cal[i]);

var int: score = total_cap * total_dur * total_fla * total_tex;

constraint forall (i in 1..n) (amount[i] >= 0);
constraint forall (i in 1..n) (amount[i] <= 100);
constraint sum (i in 1..n) (amount[i]) == 100;
constraint total_cal == 500;

solve maximize score;

output [show(score)];
