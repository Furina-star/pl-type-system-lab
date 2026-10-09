"""Demonstrate different runtime type behaviors in Python. (Dynamic, Strong)"""

# Demonstrate different type behaviors
print("1. int + string")
try:
    print(5+"3")
except TypeError as e:
    print("   TypeError:", e)

# Demonstrate reassignment to a different type
print("2. reassign to a different type")
v = 10
print("  ", v, type(v).__name__)
v = "hello"
print("  ", v, type(v).__name__)

# Demonstrate function with wrong type
def add_one(n):
    return n + 1
print("3. function with wrong type")
print("  ", add_one(4))
try:
    print("  ", add_one("a"))
except TypeError as e:
    print("   TypeError:", e)

# Demonstrate int + float
print("4. int + float")
print("  ", 5 + 2.5)