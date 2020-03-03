let priority = { A:0, B:1, C:2 };
let prompt = "";
let values = readline().split(" ").sort((a,b)=>parseInt(a)-parseInt(b));
let tokens = readline().split("");
tokens.forEach(tok=> prompt += values[priority[tok]] + " ");
print(prompt);