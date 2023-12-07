try:
    number = int(input("Please choose a number to divide: "))
except ValueError:
    print("We only accept integers.")
    exit(0)

if number == 0:
    print("All non-zero integers are divisors of 0")
    exit(0)

# Accept both negative and positive number
# Disivors can be negative or postive as well
divisors = []
for i in range(1, abs(number) + 1):
    if number % i == 0:
        divisors.extend([i,-1 * i])

print(divisors)