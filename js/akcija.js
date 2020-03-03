let nCases = parseInt(readline());
let v = [];
while (nCases--) {
    let num = parseInt(readline());
    v.push(num);
}
v.sort((a,b)=>b-a);
let groups = [];
while (v.length > 0) {
    let a = v.splice(0,3);
    groups.push(a);    
}
let cost = 0;
groups.forEach(group=>{
    if (group.length === 3) {
        group.pop();
    }
    cost += group.reduce((a,b)=>a+b);
});
print(cost);