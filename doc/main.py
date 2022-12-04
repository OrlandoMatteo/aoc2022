from glob import glob

import markdown

files = glob("../day*/*.cpp")
files = sorted(files)

days = []
for f in files:
    day = f.split('/')[1]
    days.append(day)
days = sorted(list(set(days)))

out = "# AOC2022\n"

for d in days:
    out += f"## {d}\n"
    for i in [1, 2]:
        out += f"### problem {i} \n"
        fp = open(f"../{d}/problem{i}.cpp")
        f = fp.read()
        out += "```cpp\n"
        out += f
        out += "```\n"
fp = open('../README.md', 'w')
fp.write(out)
