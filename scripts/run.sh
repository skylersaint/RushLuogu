#!/usr/bin/env bash

set -euo pipefail

choose_compiler() {
    if [[ -n "${CXX:-}" ]]; then
        printf '%s\n' "${CXX}"
        return
    fi

    if [[ -x /opt/homebrew/bin/g++-15 ]]; then
        printf '%s\n' "/opt/homebrew/bin/g++-15"
        return
    fi

    if command -v g++ >/dev/null 2>&1; then
        command -v g++
        return
    fi

    if command -v c++ >/dev/null 2>&1; then
        command -v c++
        return
    fi

    echo "No C++ compiler found. Please install g++ or clang++." >&2
    exit 1
}

if [[ $# -lt 1 ]]; then
    echo "Usage: $0 <problem_id> [args...]"
    echo "Example: $0 P1001"
    exit 1
fi

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
project_root="$(cd "${script_dir}/.." && pwd)"
problem_id="$1"
shift

compiler="$(choose_compiler)"
if [[ ! -x "${compiler}" ]]; then
    resolved_compiler="$(command -v "${compiler}" || true)"
    if [[ -z "${resolved_compiler}" ]]; then
        echo "Compiler not found: ${compiler}" >&2
        exit 1
    fi
    compiler="${resolved_compiler}"
fi

compiler_name="$(basename "${compiler}")"
build_dir="${project_root}/build/${compiler_name}"
binary="${build_dir}/bin/${problem_id}"

if [[ ! -x "${binary}" ]]; then
    "${script_dir}/build.sh"
fi

exec "${binary}" "$@"
