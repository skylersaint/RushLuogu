#!/usr/bin/env bash

set -euo pipefail

if [[ $# -ne 1 ]]; then
    echo "Usage: $0 <problem_id>"
    echo "Example: $0 P1002"
    exit 1
fi

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
project_root="$(cd "${script_dir}/.." && pwd)"
template_file="${project_root}/templates/problem.cpp"
target_file="${project_root}/problems/$1.cpp"

if [[ -f "${target_file}" ]]; then
    echo "File already exists: ${target_file}"
    exit 1
fi

cp "${template_file}" "${target_file}"
echo "Created ${target_file}"
