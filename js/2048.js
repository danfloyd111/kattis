
let board = [];
for (let i=0; i<4; ++i) {
	let row = [];
	const line = readline();
	line.split(" ").forEach(val => row.push(parseInt(val)));
	board.push(row);
}
const direction = parseInt(readline());

const mergeLeft = line => {
	let temp = [];
	let temp_idx = 0;
	let merged = false;
	line.forEach(num => {
		if ((temp.length === 0 || merged) && num !== 0) {
			temp[temp_idx] = num;
			++temp_idx;
			merged = false;
		} else if (num === temp[temp_idx - 1]) {
			temp[temp_idx - 1] *= 2;
			merged = true;
		} else if (num !== 0) {
			temp[temp_idx] = num;
			++temp_idx;
		}
	});
	while (temp.length < line.length) temp.push(0);
	return temp;
};

const mergeRight = line => mergeLeft(line.reverse()).reverse();

switch (direction) {
	case 0: // left
		for (let i=0; i<board.length; ++i) board[i] = mergeLeft(board[i]);
		break;
	case 1: {// up 
		let col = [];
		for (let i=0; i<board.length; ++i) {
			for (let j=0; j<board[i].length; ++j) {
				col.push(board[j][i]);
			}
			col = mergeLeft(col);
			for (let j=0; j<board[i].length; ++j) {
				board[j][i] = col.shift();
			}
		}
		break;
	}
	case 2: // right
		for (let i=0; i<board.length; ++i) board[i] = mergeLeft(board[i].reverse()).reverse();
		break;
	case 3: {// down
		let col = [];
		for (let i=0; i<board.length; ++i) {
			for (let j=0; j<board[i].length; ++j) {
				col.push(board[j][i]);
			}
			col = mergeLeft(col.reverse()).reverse();
			for (let j=0; j<board[i].length; ++j) {
				board[j][i] = col.shift();
			}
		}
		break;
	}
	default: console.log("Invalid direction");
}

board.forEach(line => {
	let prompt = "";
	line.forEach(value => prompt += ("" + value + " "));
	print(prompt);
});
