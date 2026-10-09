/* Demonstrate different runtime type behaviors in JavaScript. (Dynamic, Weak) */


// Demonstrate type coercion in JavaScript
console.log("1. int + string");
console.log("  ", 5 + "3", typeof (5 + "3"));
console.log("  ", 5 - "3", typeof (5 - "3"));

// Demonstrate dynamic typing in JavaScript
console.log("2. reassign to a different type");
let v = 10;
console.log("  ", v, typeof v);
v = "hello";
console.log("  ", v, typeof v);

// Demonstrate function with wrong type
function addOne(n) {
  return n + 1;
}
console.log("3. function with wrong type");
console.log("  ", addOne(4));
console.log("  ", addOne("a"));

// Demonstrate int + float
console.log("4. int + float");
console.log("  ", 5 + 2.5);