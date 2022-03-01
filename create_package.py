from pathlib import Path
from sys import argv

if __name__ == "__main__":
    package = argv[1]
    (Path("src") / package).mkdir(parents=True, exist_ok=True)
    include = Path("include")
    include.mkdir(parents=True, exist_ok=True)
    text = Path("template.txt").read_text().format(package=package.upper())
    (include / package).with_suffix(".h").write_text(text)
