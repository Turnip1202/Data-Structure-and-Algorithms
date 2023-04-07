const colors = ["red", "green", "blue"];
const newColors = ["black", "brown"];
const moreNewColors = {
  [Symbol.isConcatSpreadable]: true,
  length: 2,
  0: "turnip",
  1: "cyan",
};

newColors[Symbol.isConcatSpreadable] = false;
const colors2 = colors.concat("yellow", newColors);
const colors3 = colors.concat(moreNewColors);
console.log(colors)
console.log(colors2)
console.log(colors3)




