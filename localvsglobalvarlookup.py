import time
import statistics

def mainLookup():
    for j in range(20):
        for i in range(1000000):
            str(i)

def mainCache():
    for j in range(20):
        s = str
        for i in range(1000000):
            s(i)

def benchmark(func, iterations):
    times = []
    for _ in range(iterations):
        start = time.perf_counter()
        func()
        end = time.perf_counter()
        times.append(end - start)
    return times

# Number of times to run each benchmark
iterations = 10

print("Running mainLookup")
lookup_times = benchmark(mainLookup, iterations)
print("Running mainCache")
cache_times = benchmark(mainCache, iterations)

# Calculate statistics
avg_lookup = statistics.mean(lookup_times)
avg_cache = statistics.mean(cache_times)
median_lookup = statistics.median(lookup_times)
median_cache = statistics.median(cache_times)

# Print results
print(f"\nResults over {iterations} iterations:")
print(f"mainLookup average time: {avg_lookup:.4f} seconds")
print(f"mainCache average time: {avg_cache:.4f} seconds")
print(f"mainLookup median time: {median_lookup:.4f} seconds")
print(f"mainCache median time: {median_cache:.4f} seconds")
print(f"mainCache is {avg_lookup/avg_cache:.2f}x faster on average")
print(f"mainCache is {median_lookup/median_cache:.2f}x faster (median)")

# Optional: print all times for each run
print("\nAll times for mainLookup:", [f"{t:.4f}" for t in lookup_times])
print("All times for mainCache:", [f"{t:.4f}" for t in cache_times])