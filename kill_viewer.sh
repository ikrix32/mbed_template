#!/bin/bash

echo killing JLinkExe
kill -9 $(ps aux | grep 'JLinkExe' | awk '{print $2}')

echo killing JLinkRTTClient
kill -9 $(ps aux | grep 'JLinkRTTClient' | awk '{print $2}')