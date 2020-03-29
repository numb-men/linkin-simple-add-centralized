var fs = require('fs');

let input, output;
const args = process.argv.slice(2);
for (let i = 0; i < args.length; i++) {
    if (args[i] === '-input') {
        input = args[++i];
    } else if (args[i] === '-output') {
        output = args[++i];
    }
}
console.log(input);
console.log(output);
const lines = fs.readFileSync(input).toString().split('\n');
let sums = '';
for (let line of lines) {
    if (line === '') {
        continue;
    }
    let sum = 0;
    let nums = line.split('+');
    for (let num of nums) {
        if (num !== '') {
            sum += Number(num);
        }
    }
    sums += sum + '\n';
}
fs.writeFileSync(output, sums);
