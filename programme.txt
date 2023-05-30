import numpy as np
import matplotlib.pyplot as plt

# Load the image as a numpy array
img = np.array([[255, 100, 50], [200, 150, 75], [100, 50, 25]])

# Invert the image (negative to positive)
img = 255 - img

# Display the image with the 'viridis' colormap
plt.imshow(img, cmap="viridis")
plt.show()

