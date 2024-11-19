# Philosophers


**Philosophers** is a multithreading and synchronization project from the 42 curriculum. The goal is to simulate the famous **Dining Philosophers Problem**, a classic concurrency problem that introduces concepts such as deadlock, starvation, and resource management.

## Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [How It Works](#how-it-works)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Simulation Rules](#simulation-rules)

## About the Project

The **Philosophers** project challenges you to implement a concurrent simulation of philosophers sitting around a table, eating, thinking, and competing for forks (resources). The project emphasizes the use of multithreading and synchronization mechanisms to avoid common concurrency issues.

## Features

- Simulates the dining philosophers problem using threads.
- Implements proper synchronization to avoid race conditions.
- Handles edge cases such as deadlock and starvation.
- Configurable simulation parameters.

## How It Works

1. **The Problem**:
   - A group of philosophers sits around a circular table.
   - Each philosopher alternates between thinking, eating, and sleeping.
   - To eat, a philosopher must pick up two forks (one on each side).

2. **Challenges**:
   - Forks are shared between neighbors, creating competition for resources.
   - Proper synchronization is required to prevent deadlock and starvation.

3. **Solution**:
   - Uses mutexes to manage access to forks.
   - Implements mechanisms to ensure all philosophers get a chance to eat.

## Getting Started

### Prerequisites

- A C compiler (GCC or Clang).
- GNU Make.

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/armhakob/Philosophers.git
   cd Philosophers
2. Compile the program:
   ```bash
   make
   ```
This will create the `philo` executable.

### Usage

Run the program with the following syntax:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: Number of philosophers and forks.
- `time_to_die`: Time (in milliseconds) before a philosopher dies if they don’t start eating.
- `time_to_eat`: Time (in milliseconds) a philosopher takes to eat.
- `time_to_sleep`: Time (in milliseconds) a philosopher takes to sleep.
- `number_of_times_each_philosopher_must_eat` (optional): The simulation ends when each philosopher has eaten at least this many times.

### Example
Run a simulation with 5 philosophers:
```bash
./philo 5 800 200 200
```
Run a smulation with 5 philosophers, where each must eat 7 times:
```bash
./philo 5 800 200 200 7
```
### Simulation Rules
1. Philosophers can only pick up one fork at a time.
2. A philosopher dies if they don’t start eating within `time_to_die` milliseconds.
3. The simulation ends if:
   - A philosopher dies.
   - The optional `number_of_times_each_philosopher_must_eat` condition is met.
