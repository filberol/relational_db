import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("lab_bench_res/benchmark_results.csv")

columns = list(df.columns[1:])
for column in columns:
    plt.figure()
    plt.xlabel("Rows")
    plt.ylabel(column)
    plt.plot(df["Rows"], df[column])
    # plt.show()
    name = column.lower().split(" ")[0] + ".png"
    plt.savefig("lab_bench_res/" + name)