#!/usr/bin/env bash
dnf update
dnf install check-devel -y
yum groupinstall "Development Tools" "Development Libraries" -y