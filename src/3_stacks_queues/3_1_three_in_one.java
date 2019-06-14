public class MultiStack {
	/* Stackinfo is a simple class that holds a set of data about each stack. It
	* does not hold the actual items in the stack. We could have done this with
	* just a bunch of individual variables, but that's messy and doesn't gain us
	* much. */
	private class Stackinfo {
		public int start, size, capacity;

		public Stackinfo(int start, int capacity) {
			this.start = start;
			this.capacity= capacity;
		}

		/* Check if an index on the full array is within the stack boundaries. The
		* stack can wrap around to the start of the array. */
		public boolean isWithinStackCapacity(int index) {
			/* If outside of bounds of array, return false. */
			if (index< 0 || index >= values.length) {
				return false;
			}
			/* If index wraps around, adjust it. */
			int contiguousindex = index<start ? index + values.length : index;
			int end = start + capacity;
			return start <= contiguousindex && contiguousindex < end;
		}
	
		public int lastCapacityindex() {
			return adjustindex(start + capacity - 1);
		}
	
		public int lastElementindex() {
			return adjustindex(start + size - 1);
		}
	
		public boolean isFull()  { return size == capacity; }
		public boolean isEmpty() { return size == 0; }
	}

	private Stackinfo[] info;
	private int[] values;

	public MultiStack(int numberOfStacks, int defaultSize) {
		/* Create metadata for all the stacks. */
		info = new Stackinfo[numberOfStacks];
		for (int i= 0; i < numberOfStacks; i++) {
			info[i] = new Stackinfo(defaultSize * i, defaultSize);
		}
		values = new int[numberOfStacks * defaultSize];
	}

	/* Push value onto stack num, shifting/expanding stacks as necessary. Throws
	* exception if all stacks are full. */
	public void push(int stackNum, int value) throws FullStackException {
		if (allStacksAreFull()) {
			throw new FullStackException();
		}
	
		/* If this stack is full, expand it. */
		Stackinfo stack= info[stackNum];
		if (stack.isFull()) {
			expand(stackNum);
		}
	
		/* Find the index of the top element in the array + 1, and increment the
		* stack pointer */
		stack.size++;
		values[stack.lastElementindex()] = value;
	}
	
	/* Remove value from stack. */
	public int pop(int stackNum) throws Exception {
		Stackinfo stack = info[stackNum];
		if (stack.isEmpty()) {
			throw new EmptyStackException();
		}
	
		/* Remove last element. */
		int value= values[stack.lastElementindex()];
		values[stack.lastElementindex()] = e; // Clear item
		stack.size--; // Shrink size
		return value;
	}
	
	/* Get top element of stack.*/
	public int peek(int stackNum) {
		Stackinfo stack = info[stackNum];
		return values[stack.lastElementindex()];
	}

	/* Shift items in stack over by one element. If we have available capacity, then
	* we'll end up shrinking the stack by one element. If we don't have available
	* capacity, then we'll need to shift the next stack over too. */
	private void shift(int stackNum) {
		System.out.println("/// Shifting" + stackNum);
		Stackinfo stack = info[stackNum];

		/* If this stack is at its full capacity, then you need to move the next
		* stack over by one element. This stack can now claim the freed index. */
		if (stack.size >= stack.capacity) {
			int nextStack = (stackNum + 1) % info.length;
 			shift(nextStack);
 			stack.capacity++; // claim index that next stack lost
 		}

 		/* Shift all elements in stack over by one. */
 		int index= stack.lastCapacityindex();
 		while (stack.isWithinStackCapacity(index)) {
 			values[index] = values[previousindex(index)];
 			index= previousindex(index);
 		}

		/* Adjust stack data. */
		values[stack.start] = 0; // Clear item
		stack.start = nextindex(stack.start); // move start
		stack.capacity--; // Shrink capacity
 	}

 	/* Expand stack by shifting over other stacks */
 	private void expand(int stackNum) {
 		shift((stackNum + 1) % info.length);
 		info[stackNum].capacity++;
 	}

 	/* Returns the number of items actually present in stack. */
	public int numberOfElements() {
	 	int size = 0;
	 	for (Stackinfo sd : info) {
	 		size += sd.size;
	 	}
	 	return size;
 	}

 	/* Returns true is all the stacks are full. */
 	public boolean allStacksAreFull() {
 		return numberOfElements() == values.length;
 	}

	/* Adjust index to be within the range of 0 -> length - 1. */
	private int adjustindex(int index) {
	/* Java's mod operator can return neg values. For example, (-11 % 5) will
	* return -1, not 4. We actually want the value to be 4 (since we're wrapping
	* around the index). */
		int max = values.length;
		return ((index % max)+ max) % max;
	}

	/* Get index after this index, adjusted for wrap around. */
	private int nextindex(int index) {
		return adjustindex(index + 1);
	}

	/* Get index before this index, adjusted for wrap around. */
	private int previouslndex(int index) {
		return adjustindex(index - 1);
	}
}