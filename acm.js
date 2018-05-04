let DEBUG = false; // Toggle this when testing on local Node.js instance 

let attempts = {};
let score = { 
    points: 0,
    solved: 0
};

function evalLine(line, attempts, score) {
    let tokens = line.split(" ");
    // tokens[0] : timestamp
    // tokens[1] : problemId
    // tokens[2] : outcome
    if (tokens[2] === "wrong") {
        attempts[tokens[1]] = attempts[tokens[1]] ? attempts[tokens[1]] + 20 : 20; 
    } else {
        let timestamp = parseInt(tokens[0]);
        let penalty = attempts[tokens[1]] ? attempts[tokens[1]] : 0;
        score.points += timestamp + penalty;
        score.solved ++;
    }
}

if (!DEBUG) {
    // Kattis I/O
    let stop = false;
    while (!stop) {
        let line = readline();
        stop = parseInt(line) === -1;
        if (!stop) {
            evalLine(line,attempts,score);
        }
    }

    print(score.solved, score.points);
} else {
    // Node.js local test
    let inputTest1 = [
        "3 E right",
        "10 A wrong",
        "30 C wrong",
        "50 B wrong",
        "100 A wrong",
        "200 A right",
        "250 C wrong",
        "300 D right"
    ];

    let inputTest2 = [
        "7 H right",
        "15 B wrong",
        "30 E wrong",
        "35 E right",
        "80 B wrong",
        "80 B right",
        "100 D wrong",
        "100 C wrong",
        "300 C right",
        "300 D wrong"
    ];


    inputTest1.forEach(line => evalLine(line,attempts,score));
    console.log(score.solved, score.points);
    score.points = 0;
    score.solved = 0;
    attempts = {};
    inputTest2.forEach(line => evalLine(line,attempts,score));
    console.log(score.solved, score.points);
}
