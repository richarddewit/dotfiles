#!/usr/bin/env bash

caption="♬ Spotify"
metadata=""
tries=0
while [ -z "$metadata" ]; do
  metadata="$(playerctl -p spotifyd metadata)"
  ((tries+=1))
  echo "Tries: $tries"
  sleep 1

  if [ $tries -ge 10 ]; then
    notify-send "$caption" "Unable to get song metadata!"
    exit 1
  fi
done

artist="$(echo "$metadata" | grep artist | awk -F '[[:space:]][[:space:]]+' '{print $2;}' | awk 'ORS=", "' | head -c -2)"
title="$(echo "$metadata" | grep title | awk -F '[[:space:]][[:space:]]+' '{print $2;}')"

notify-send "$caption - Now Playing" "$artist - $title"
