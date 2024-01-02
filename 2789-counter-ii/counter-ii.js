/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let presentVal = init;
    return {
        increment: () => presentVal = presentVal+1,
        decrement: () => presentVal = presentVal-1,
        reset: () => presentVal = init
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */