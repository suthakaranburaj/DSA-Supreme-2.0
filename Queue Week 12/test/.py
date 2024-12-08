import random

def generate_examples(num_examples):
    examples = []
    for _ in range(num_examples):
        size = random.randint(1, 15)  # Random size between 1 and 15
        array = [random.randint(1, 20) for _ in range(size)]  # Array elements between 1 and 20
        examples.append((size, array))
    return examples

def print_examples(examples):
    for size, array in examples:
        print(size)
        print(" ".join(map(str, array)))

# Generate and print 70 examples
examples = generate_examples(70)
print_examples(examples)
