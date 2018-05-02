let priority = {
    lower: 0,
    middle: 1,
    upper: 2
}

function compareClasses(c1, c2) {
    if (priority[c1] > priority[c2])
        return 1;
    if (priority[c1] < priority[c2])
        return -1;
    return 0;
}

function compareChains(c1, c2) {
    let t1 = c1.split("-").reverse();
    let t2 = c2.split("-").reverse();
    let i = 0, res = 0;
    while (i < t1.length && i < t2.length) {
        if ((res = compareClasses(t1[i],t2[i])))
            return res;
        ++i;
    }
    return 0;
}

function compareEntries(e1, e2) {
    let res = compareChains(e1.chain, e2.chain);
    if (res === 0) {
        if (e1.name < e2.name)
            return 1;
        if (e1.name > e2.name)
            return -1;
        return 0
    }
    return res;
}

function swap(map, i, j) {
    let temp = map[i];
    map[i] = map[j];
    map[j] = temp;
}

let map = [];
/*
let nCases = readline();
while (nCases--) {
    // input
    let nLines = readline();
    while (nLines--) {
        let line = readline();
        let tokens = line.split(" ");
        map.push({
            name: tokens[0].slice(0,tokens[0].length-1),
            chain: tokens[1], 
        });
    }
    /*
    // sorting [TODO: it works but is slow, try first with sorted insertion then with quicksort]
    for(let i=0; i<map.length; ++i) {
        for(let j=0; j<map.length; ++j) {
            let res = compareChains(map[j].chain,map[i].chain);
            switch (res) {
                case -1:
                    swap(map, i, j);
                    break;
                case 0:
                    if (map[j].name > map[i].name) {
                        swap(map, i, j);
                    }
                    break;
                // default case: continue
            }
        }
    }
    
    map.sort(compareEntries);
    // output
    map.forEach(entry => {
        print(entry.name);
    });
    print(Array(31).join("="));
}
*/
// Node test
let lines = [
    "mom: upper-upper-lower-middle class",
    "dad: middle-middle-middle-lower-middle class",
    "queenelizabeth: upper-upper-upper class",
    "chair: lower-lower class",
    "unclebob: middle-middle-lower-middle class"
];

lines.forEach(line => {
    let tokens = line.split(" ");
    map.push({
        name: tokens[0].slice(0,tokens[0].length-1),
        chain: tokens[1], 
    });
})
map.sort(compareEntries).reverse();
// output
map.forEach(entry => {
    console.log(entry.name);
});
console.log(Array(31).join("="));