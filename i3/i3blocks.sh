#!/usr/bin/env bash

icon_battery=""
icon_batteries="    "
icon_charging=""
icon_clock=""
icon_calendar=""
icon_disk=""
icon_home=""
icon_linux=""
icon_mail=""
icon_cpu=""
icon_mem=""
icon_music=""
icon_prog=""
icon_shell=""
icon_vol=""
icon_mute=""
icon_wlan=""
icon_eth=""

base00="#1d1f21"
base01="#282a2e"
base02="#373b41"
base03="#969896"
base04="#b4b7b4"
base05="#c5c8c6"
base06="#e0e0e0"
base07="#ffffff"
base08="#cc6666"
base09="#de935f"
base0A="#f0c674"
base0B="#b5bd68"
base0C="#8abeb7"
base0D="#81a2be"
base0E="#b294bb"
base0F="#a3685a"

separator="[separator]
color=$base00"

cat <<GLOBAL
# i3blocks config file
#
# Please see man i3blocks for a complete reference!
# The man page is also hosted at http://vivien.github.io/i3blocks
#
# List of valid properties:
#
# align
# color
# command
# full_text
# instance
# interval
# label
# min_width
# name
# separator
# separator_block_width
# short_text
# signal
# urgent



# Global properties
#
# The top properties below are applied to every block, but can be overridden.
# Each block command defaults to the script name to avoid boilerplate.
command=~/dotfiles/i3/scripts/i3blocks/\$BLOCK_NAME
full_text=■
color=$base05
markup=none
separator=false
separator_block_width=5

# Application title
[title]
command=xtitle -st 65
interval=persist
color=$base0C


$separator
$separator

GLOBAL


cat <<NETWORK
# Network interface monitoring
#
# If the instance is not specified, use the interface used for default route.
# The address can be forced to IPv4 or IPv6 with -4 or -6 switches.
[label network]
full_text=$icon_eth
color=$base0D

[iface]
#instance=wlan0
color=$base0B
interval=10
separator=false

#[bandwidth]
#instance=eth0
#interval=5

$separator

NETWORK


cat <<CPU
# CPU usage
#
# The script may be called with -w and -c switches to specify thresholds,
# see the script for details.
[label cpu]
full_text=$icon_cpu
color=$base0D

[cpu_usage]
interval=5
min_width=99.99%
align=right

#[load_average]
#interval=10

$separator

CPU


cat <<MEMORY
# Memory usage
#
# The type defaults to "mem" if the instance is not specified.
[label mem]
full_text=$icon_mem
color=$base0D

[memory]
interval=5

# [memory]
# label=SWAP
# instance=swap
# separator=false
# interval=30

$separator

MEMORY


~/dotfiles/bin/is_laptop && cat <<BATTERY
# Battery
#
# The type defaults to "mem" if the instance is not specified.
[label battery]
full_text=$icon_battery
color=$base0D

[battery]
interval=15

$separator

BATTERY


cat <<DISK
# Disk usage
#
# The directory defaults to \$HOME if the instance is not specified.
# The script may be called with a optional argument to set the alert
# (defaults to 10 for 10%).
[label disk]
full_text=$icon_disk$icon_linux
color=$base0D

[disk]
instance=/
interval=10

$separator

DISK


lsblk | grep -q /home && cat <<DISKHOME
[label disk home]
full_text=$icon_disk$icon_home
color=$base0D

[disk]
instance=/home
interval=10

$separator

DISKHOME


cat <<VOLUME
# Volume indicator
#
# The first parameter sets the step (and units to display)
# The second parameter overrides the mixer selection
# See the script for details.
[label volume]
full_text=$icon_vol
color=$base0D

[volume 1%]
instance=Master
#instance=PCM
interval=once
signal=10
min_width=99%

$separator

VOLUME

cat <<DATETIME
# Date Time
#
[label date]
full_text=
color=$base0D

[date]
interval=60

$separator

[label time]
full_text=
color=$base0D

[time]
command=date '+%H:%M'
interval=5

DATETIME


cat <<OTHER
# Generic media player support
#
# This displays "ARTIST - SONG" if a music is playing.
# Supported players are: spotify, vlc, audacious, xmms2, mplayer, and others.
#[mediaplayer]
#instance=spotify
#interval=5
#signal=10

# OpenVPN support
#
# Support multiple VPN, with colors.
#[openvpn]
#interval=20

# Temperature
#
# Support multiple chips, though lm-sensors.
# The script may be called with -w and -c switches to specify thresholds,
# see the script for details.
#[temperature]
#label=TEMP
#interval=10

# Key indicators
#
# Add the following bindings to i3 config file:
#
# bindsym --release Caps_Lock exec pkill -SIGRTMIN+11 i3blocks
# bindsym --release Num_Lock  exec pkill -SIGRTMIN+11 i3blocks
#[keyindicator]
#instance=CAPS
#interval=once
#signal=11

#[keyindicator]
#instance=NUM
#interval=once
#signal=11

$separator

OTHER

