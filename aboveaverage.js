let nCases = parseInt(readline());
while (nCases--) {
    let line = readline();
    let values = line.split(" ");
    values.shift();
    let avg = values.reduce((acc,cur)=>parseInt(acc)+parseInt(cur)) / values.length;
    let aboveAvg = 0;
    values.forEach(element => {
        if (parseInt(element)>avg) {
            ++aboveAvg;
        }
    });
    let perc = (aboveAvg/values.length*100).toFixed(3);
    print(perc + "%");
}