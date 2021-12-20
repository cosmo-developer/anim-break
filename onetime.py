import os
os.system("cmake .")
os.system("cmake --build .")
os.system('"unit-test/Debug/unit-test"')
input("Press enter to clear everything")
os.system("git clean -fdx")