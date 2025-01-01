#!/bin/bash

# Keywords to skip
SKIP_KEYWORDS=("mtk","misc","a32","A32","MTK","samsung","Samsung","mt6768", "MT6768")

# Loop over all conflicted files
for file in $(git diff --name-only --diff-filter=U); do
    skip_file=false
    # Check if file contains any of the keywords
    for kw in "${SKIP_KEYWORDS[@]}"; do
        if grep -q "$kw" "$file"; then
            echo "Skipping $file (contains keyword $kw)"
            skip_file=true
            break
        fi
    done

    # If no keyword matched, keep incoming changes
    if [ "$skip_file" = false ]; then
        git checkout --theirs "$file"
        git add "$file"
        echo "Automatically kept incoming changes for $file"
    fi
done
