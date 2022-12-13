from typing import List, Tuple
import itertools

RAW_INPUT = """addx 15
addx -11
addx 6
addx -3
addx 5
addx -1
addx -8
addx 13
addx 4
noop
addx -1
addx 5
addx -1
addx 5
addx -1
addx 5
addx -1
addx 5
addx -1
addx -35
addx 1
addx 24
addx -19
addx 1
addx 16
addx -11
noop
noop
addx 21
addx -15
noop
noop
addx -3
addx 9
addx 1
addx -3
addx 8
addx 1
addx 5
noop
noop
noop
noop
noop
addx -36
noop
addx 1
addx 7
noop
noop
noop
addx 2
addx 6
noop
noop
noop
noop
noop
addx 1
noop
noop
addx 7
addx 1
noop
addx -13
addx 13
addx 7
noop
addx 1
addx -33
noop
noop
noop
addx 2
noop
noop
noop
addx 8
noop
addx -1
addx 2
addx 1
noop
addx 17
addx -9
addx 1
addx 1
addx -3
addx 11
noop
noop
addx 1
noop
addx 1
noop
noop
addx -13
addx -19
addx 1
addx 3
addx 26
addx -30
addx 12
addx -1
addx 3
addx 1
noop
noop
noop
addx -9
addx 18
addx 1
addx 2
noop
noop
addx 9
noop
noop
noop
addx -1
addx 2
addx -37
addx 1
addx 3
noop
addx 15
addx -21
addx 22
addx -6
addx 1
noop
addx 2
addx 1
noop
addx -10
noop
noop
addx 20
addx 1
addx 2
addx 2
addx -6
addx -11
noop
noop
noop
"""

ROWS = 6
COLS = 40

Instruction = List[Tuple[int, int]]
def parse_input(plain_text: str) -> Instruction:

    output = [] 
    for line in plain_text.strip().splitlines():
        output.append(0)
        if not line.strip() == 'noop':
            _, value = line.strip().split(' ')
            output.append(int(value))
    return output


def compute_register_state(
    instructions: Instruction,
    ) -> int:
    register = list(itertools.accumulate(instructions, initial=1))
    return register



def compute_signal_strength(instructions) -> int:
    register = compute_register_state(instructions)
    strength = [register[i] * (i + 1) for i in range(19, 220, 40)]
    return sum(strength)


def display_crt(instructions):
    register = compute_register_state(instructions)
    display = [
        [0 for _ in range(COLS)]
        for _ in range(ROWS)]

    for cycle in range(240):
        is_on = int(abs(register[cycle] - cycle % COLS) <= 1)
        display[cycle // COLS][cycle % COLS] = is_on 

    str_display = '\n'.join([
        ''.join([('.', '#')[i] for i in row])
        for row in display])
    print(str_display)



if __name__ == '__main__':
    with open('day10/test') as f:
        test_plain_text = f.read()
    test_case = parse_input(test_plain_text)
    print('test case display')
    print(compute_signal_strength(test_case))
    display_crt(test_case)

    with open('day10/input') as f:
        plain_text = f.read()
    instructions = parse_input(plain_text)

    signal_strength = compute_signal_strength(instructions)
    print(f'answer1: {signal_strength}')

    print('part 2')
    display_crt(instructions)





