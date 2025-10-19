import subprocess

def run_cpp() -> list:
    out = []
    res = subprocess.run(["./main_executable"], capture_output=True, text=True, check=True)
    for line in res.stdout.splitlines():
        out.append(line)

    return out

def main():

    content = run_cpp()
    for line in content:
        print(line)


if __name__ == "__main__":
    main()
