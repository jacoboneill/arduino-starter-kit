import argparse

p = argparse.ArgumentParser(description="Ohm's Law Calculator")
p.add_argument("-v", "-V", "--voltage", type=float, help="voltage")
p.add_argument("-i", "-A", "--current", type=float, help="current")
p.add_argument("-r", "-R", "--resistance", type=float, help="resistance")

args = p.parse_args()
group = ["voltage", "current", "resistance"]
target = [name for name in group if getattr(args, name) is None]

if len(target) != 1:
    flags = ", ".join("--" + n for n in group)
    if not target:
        p.error(f"exactly 2 of {flags} must be given, but all 3 were")
    p.error(f"exactly 2 of {flags} must be given, but {len(target)-1} is missing")

target = target[0]

print(
    f"Voltage   : {args.current * args.resistance if target == 'voltage' else args.voltage}V"
)
print(
    f"Current   : {args.voltage / args.resistance if target == 'current' else args.current}A"
)
print(
    f"Resistance: {args.voltage / args.current if target == 'resistance' else args.resistance}Ω"
)
