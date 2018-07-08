dependencies=$(which jq)

if [ -z "${dependencies}" ]; then

fi
github_api=https://api.github.com

branches=$(curl --request GET ${github_api}/repos/python/cpython/branches)

branches_names=$(echo $branches | jq '.[].name')

for branch in ${branches_names}; do
    echo ${branch}
done
