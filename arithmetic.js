let input = readline(); // Kattis input
//let input = "7654321001234567"; // test input for Node.js

let binaryString = "";

/*
    octal to binary: converting each digit into 3 bits binary
    number (7 is 111), in this way we can manage very big numbers
    because we are treating them as strings.
    ex: 77 become 111111
*/

for (let i=0; i<input.length; ++i) {
    let chunk = parseInt(input.charAt(i),8).toString(2);
    if (chunk.length < 3 && i != 0)
        while (chunk.length < 3)
            chunk = "0" + chunk;
    binaryString += chunk;
}

/*
    zero-left-padding the binary string in order to be able to
    divide the strings in chunks of 4 bits.
*/

while (binaryString.length % 4 != 0)
    binaryString = "0" + binaryString;
let chunks = binaryString.match(/.{4}/g);

/*
    binary to hex: converting each chunk of 4 bits in a hex digit
    and joining them all.
*/

let hexString = "";
chunks.forEach(chunk => {
    hexString += parseInt(chunk,2).toString(16);
});

//console.log(hexString.toUpperCase()); // local test for Node.js
print(hexString.toUpperCase()); // Kattis output