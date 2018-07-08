import requests

github_api = "https://api.github.com"
python_repo = "{}/repos/python/cpython/branches".format(github_api)
branches = requests.get(python_repo).json()
print(branches)
