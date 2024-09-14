const { performance } = require("perf_hooks");

// Create a large number of global variables
for (let i = 0; i < 1000000; i++) {
  global[`var${i}`] = i;
}

// Nest testArray deeply
const testArray = Array(10000000).fill(1);

function passButLocal() {
  function one() {
    function two() {
      function three() {
        function four() {
          const _arr = testArray;
          for (let i = 0; i < _arr.length; i++) {
            _arr[i] *= Math.floor(Math.random() * (10 - 1 + 1) + 1);
          }
        }
        four();
      }
      three();
    }
    two();
  }
  one();
}

function pass() {
  function one() {
    function two() {
      function three() {
        function four() {
          for (let i = 0; i < testArray.length; i++) {
            testArray[i] *= Math.floor(Math.random() * (10 - 1 + 1) + 1);
          }
        }
        four();
      }
      three();
    }
    two();
  }
  one();
}

function benchmark(func, iterations) {
  const start = performance.now();

  for (let i = 0; i < iterations; i++) {
    func();
  }

  const end = performance.now();
  return end - start;
}

const iterations = 1000;

console.log("Running passButLocal");
const local = benchmark(passButLocal, iterations);
console.log("Running pass");
const passDirect = benchmark(pass, iterations);

console.log(`PassButLocal time: ${local.toFixed(2)} ms`);
console.log(`Pass time: ${passDirect.toFixed(2)} ms`);
console.log(`PassButLocal is ${(passDirect / local).toFixed(2)}x faster`);
