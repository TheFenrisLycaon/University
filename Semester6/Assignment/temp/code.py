import pandas as pd
import numpy as np
import matplotlib
import matplotlib.pyplot as plt
import seaborn as sns
import missingno

df = pd.read_csv("train.csv")
df.info()
df.head()
w