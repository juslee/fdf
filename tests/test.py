import matplotlib.pyplot as plt

# List of 2D screen coordinates (x, y)
points = [(400, 300), (457, 300), (514, 300),
          (400, 385), (457, 385), (514, 385),
          (400, 470), (457, 470), (514, 470)]

# Separate the coordinates into X and Y lists
x_coords, y_coords = zip(*points)

# Plot the points and connect them with lines
plt.plot(x_coords[:3], y_coords[:3], marker='o')  # Connect the first row (top)
plt.plot(x_coords[3:6], y_coords[3:6], marker='o')  # Connect the second row (middle)
plt.plot(x_coords[6:], y_coords[6:], marker='o')  # Connect the third row (bottom)

# Connect the columns between rows (vertical lines)
for i in range(3):
    plt.plot([x_coords[i], x_coords[i+3], x_coords[i+6]], [y_coords[i], y_coords[i+3], y_coords[i+6]], marker='o')

# Invert the y-axis to match screen coordinates
plt.gca().invert_yaxis()

# Set labels and title
plt.xlabel("X coordinates")
plt.ylabel("Y coordinates")
plt.title("2D Screen Coordinates with Connected Lines")

# Set limits for better visibility
plt.xlim(350, 550)
plt.ylim(250, 500)

# Show the plot
plt.show()
