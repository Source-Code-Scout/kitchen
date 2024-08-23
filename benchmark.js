/**
 * passByValue isnt actually possible in JS, so this is a load of BS. ignore this for now
 * in future - we may be able to distinguish properly, until then lets skip doing this in JS.
 *
 *
 * inside a code block in JS, let & consts are used as copies. whereas var is attached directly to parent.
 * maybe try to experiment and show something around this.
 */

const { performance } = require("perf_hooks");

function passByValue(arr) {
  let newArr = [...arr];
  // for (let i = 0; i < newArr.length; i++) {
  //   newArr[i] *= 2;
  // }
  return newArr;
}

function passByReference(arr) {
  for (let i = 0; i < arr.length; i++) {
    arr[i] *= 2;
  }
  return arr;
}

function benchmark(func, arr, iterations) {
  const start = performance.now();

  for (let i = 0; i < iterations; i++) {
    func([...arr]);
  }

  const end = performance.now();
  return end - start;
}

const testArray = Array(1000000).fill(1);
const iterations = 1000;

console.log("running PBV");
const valueTime = benchmark(passByValue, testArray, iterations);
console.log("running PBR");
const referenceTime = benchmark(passByReference, testArray, iterations);

// Print results
console.log(`Pass by value time: ${valueTime.toFixed(2)} ms`);
console.log(`Pass by reference time: ${referenceTime.toFixed(2)} ms`);
console.log(
  `Pass by reference is ${(valueTime / referenceTime).toFixed(2)}x faster`
);
