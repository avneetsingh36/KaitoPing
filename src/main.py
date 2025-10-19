import subprocess

def run_cpp() -> list:
    out = []

    instructions = "You are a helpful assistant."
    message = "What is your name?"
    res = subprocess.run(["./api/main_executable", instructions, message], capture_output=True, text=True, check=True)
    for line in res.stdout.splitlines():
        out.append(line)

    return out

def main():

    content = run_cpp()
    for line in content:
        print(line)


if __name__ == "__main__":
    main()
