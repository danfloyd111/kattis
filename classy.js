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

function swap(map, i, j) {
    let temp = map[i];
    map[i] = map[j];
    map[j] = temp;
}

let map = [];

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
    // output
    map.forEach(entry => {
        print(entry.name);
    });
    print(Array(31).join("="));
}

