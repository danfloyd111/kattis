let line = readline();
let hw = line.split(" ");
let height = parseInt(hw[0]);
let width = parseInt(hw[1]);
line = readline();
let bricks = line.split(" ");
let failure = false;
let h = 0;
while (!failure && h<height) {
    let w = 0;
    while (!failure && w<width) {
        if (!failure && bricks.length > 0) {
            let brick = parseInt(bricks.shift());
            w += brick;
        } else {
            failure = true;
        }
    }
    if (w!=width) {
        failure = true;
    }
    h ++;
}
if (height!=h) {
    failure = true;
}
print(failure ? "NO" : "YES");