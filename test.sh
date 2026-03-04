#!/usr/bin/env bash
# check_stderr.sh — run a command and detect whether it wrote anything to stderr

set -u -o pipefail

if [[ $# -lt 1 ]]; then
  echo "Usage: $0 <command> [args...]" >&2
  exit 2
fi

stderr_file="$(mktemp)"
trap 'rm -f "$stderr_file"' EXIT

# Run the command, showing stderr normally *and* saving a copy for detection
"$@" 2> >(tee "$stderr_file" >&2)
status=$?

if [[ -s "$stderr_file" ]]; then
  echo "⚠️  Detected output on stderr from: $*" >&2
  # Return a distinct code to signal "stderr was used"
  exit 3
else
  echo "✅ No stderr output from: $*" >&2
  # Preserve the original program exit status
  exit "$status"
fi
