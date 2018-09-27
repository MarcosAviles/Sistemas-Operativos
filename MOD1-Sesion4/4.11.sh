#!/bin/bash

head /tmp/listacores >> /tmp/aux
rm /tmp/listacores
mv /tmp/aux /tmp/listacores
