#!/bin/sh

# Set any error as fatal
set -e

if [[ $USER != "ansible" ]]; then
    echo "This script must be run as ansible.  Exiting."
    exit 1
fi

ansible-playbook -v -i hosts_localhost triton-application.yml
