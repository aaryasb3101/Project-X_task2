# CPU Scheduler and Cache Hierarchy Simulator

## Features

- Round Robin Scheduling (Quantum = 2)
- FIFO Cache Replacement
- Three-Level Cache Hierarchy (L1, L2, L3)
- RAM Access Tracking
- Input File Parsing

## Cache Configuration

L1: 32 slots, 4 cycles
L2: 128 slots, 12 cycles
L3: 512 slots, 40 cycles
RAM: Unlimited, 200 cycles

## Compilation

g++ main.cpp -o simulator

## Execution

.\simulator.exe