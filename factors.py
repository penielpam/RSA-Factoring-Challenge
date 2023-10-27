import sys

def factorize_number(number):
    factors = []
    for i in range(2, number + 1):
        while number % i == 0:
            factors.append(i)
            number //= i
            if len(factors) == 2:
                break
    if len(factors) == 2:
        return f"{factors[0]}*{factors[1]}"
    else:
        return f"{number}={number}*1"

def main(file_path):
    try:
        with open(file_path, 'r') as file:
            lines = file.readlines()

        for line in lines:
            number = int(line.strip())
            factorization = factorize_number(number)
            print(factorization)

    except FileNotFoundError:
        print("File not found.")
    except ValueError:
        print("Invalid number in the file.")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        sys.exit(1)

    file_path = sys.argv[1]
    main(file_path)
