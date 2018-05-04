// Node.js local instructions for debugging are commented out, in case of testing diable all
// Kattis relative code

//let inputTest = [6, 65, 650]; 

function isPerfect(n) {
    let properDivs = [1];
    let s = Math.floor(Math.sqrt(n));
    for (let i = 2; i<=s; ++i) {
        if (n%i === 0) {
            let q = n / i;
            if (q != i) {
                properDivs.push(q);
            }
            properDivs.push(i);
        }
    }
    let sum = properDivs.reduce((accumulator,current)=>accumulator+current);
    if (sum === n) {
//        console.log(n + " perfect");
        print(n + " perfect"); // Kattis output
    } else if (sum <= n+2 && sum >= n-2) {
//        console.log(n + " almost perfect");
        print(n + " almost perfect"); // Kattis output
    } else {
//        console.log(n + " not perfect");
        print(n + " not perfect"); // Kattis output
    }
}

//inputTest.forEach(n=>isPerfect(n));

// Kattis input
let stop = false;
while(!stop) {
    let num = 0;
    if (num = parseInt(readline())) {
        isPerfect(num);        
    } else {
        stop = true;
    }
}
// -----------

// 1 2 3