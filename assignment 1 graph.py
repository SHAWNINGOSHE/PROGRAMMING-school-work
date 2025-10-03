import matplotlib.pyplot as plt
import numpy as np

# Data
months = ["07/2019", "08/2019", "09/2019", "10/2019", "11/2019"]
searches = [50, 53, 59, 56, 62]
direct = [39, 47, 42, 51, 51]
social = [70, 80, 90, 87, 92]

# X positions
x = np.arange(len(months))
width = 0.25

# Create figure
plt.figure(figsize=(8,6))

# Bars
plt.bar(x - width, searches, width, label="Searches", color="#3399FF")  # blue
plt.bar(x, direct, width, label="Direct", color="#CC6699")              # pink
plt.bar(x + width, social, width, label="Social Media", color="#FFCC33") # yellow

# Labels and title
plt.ylabel("visitors\nin thousands")
plt.xlabel("months")
plt.title("Visitors by web traffic sources")
plt.xticks(x, months)

# Y-axis limit for better spacing
plt.ylim(0, 110)

# Show legend
plt.legend()

# Display chart
plt.show()
