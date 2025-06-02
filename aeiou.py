import pandas as pd
import numpy as np

# Paths to CSV files
file_path = r"C:\Users\Yash Jha\Downloads\multi_classification_train.csv"
file_path1 = r"C:\Users\Yash Jha\Downloads\multi_classification_test.csv"
save_path = r"C:\Users\Yash Jha\Downloads\decision_tree_predictions.csv"

# Load training data
data = pd.read_csv(file_path)
matrix = data.iloc[:, 1:].values

# Decision Tree Functions
def fit_decision_tree(X, y, max_depth=None):
    n_classes = len(np.unique(y))
    n_features = X.shape[1]
    tree = build_tree(X, y, max_depth, depth=0)
    return tree

def predict_decision_tree(X, tree):
    return np.array([predict(inputs, tree) for inputs in X])

def build_tree(X, y, max_depth, depth):
    n_samples, n_features = X.shape
    n_labels = len(np.unique(y))
    if depth == max_depth or n_labels == 1 or n_samples < 2:
        return {"value": majority_class(y)}
    feature, threshold = best_split(X, y)
    if feature is None:
        return {"value": majority_class(y)}
    left_idxs = X[:, feature] <= threshold
    right_idxs = X[:, feature] > threshold
    left_child = build_tree(X[left_idxs], y[left_idxs], max_depth, depth + 1)
    right_child = build_tree(X[right_idxs], y[right_idxs], max_depth, depth + 1)
    return {"feature": feature, "threshold": threshold, "left": left_child, "right": right_child}

def best_split(X, y):
    best_gain = -1
    best_feature, best_threshold = None, None
    for feature in range(X.shape[1]):
        sorted_indices = np.argsort(X[:, feature])
        sorted_X = X[sorted_indices, feature]
        sorted_y = y[sorted_indices]
        thresholds = np.unique(sorted_X)
        for threshold in thresholds:
            gain = information_gain(sorted_X, sorted_y, threshold)
            if gain > best_gain:
                best_gain, best_feature, best_threshold = gain, feature, threshold
    return best_feature, best_threshold

def information_gain(X_column, y, threshold):
    parent_entropy = entropy(y)
    left_idxs = X_column <= threshold
    right_idxs = X_column > threshold
    left_y = y[left_idxs]
    right_y = y[right_idxs]
    if len(left_y) == 0 or len(right_y) == 0:
        return 0
    left_entropy = entropy(left_y)
    right_entropy = entropy(right_y)
    child_entropy = (len(left_y) / len(y)) * left_entropy + (len(right_y) / len(y)) * right_entropy
    return parent_entropy - child_entropy

def entropy(y):
    y = y.astype(int)
    proportions = np.bincount(y) / len(y)
    return -np.sum([p * np.log2(p) for p in proportions if p > 0])

def majority_class(y):
    y = y.astype(int)
    return np.bincount(y).argmax()

def predict(inputs, tree):
    if "value" in tree:
        return tree["value"]
    feature, threshold = tree["feature"], tree["threshold"]
    if inputs[feature] <= threshold:
        return predict(inputs, tree["left"])
    else:
        return predict(inputs, tree["right"])

# Training the Decision Tree
X = np.array(matrix[:40000, :20])
y = np.array(matrix[:40000, 20])
tree = fit_decision_tree(X, y, max_depth=12)

# Validate predictions on training data
predictions_train = predict_decision_tree(X, tree)
accuracy_train = np.mean(predictions_train == y)
print("Training Accuracy:", accuracy_train)

# Load test data
data1 = pd.read_csv(file_path1)
matrix1 = data1.iloc[:, 1:].values

# Make predictions on test data
predictions_test = predict_decision_tree(np.array(matrix1[:, :20]), tree)

# Save predictions to CSV
np.savetxt(save_path, predictions_test, delimiter=",", fmt="%.6f", header="Predictions", comments="")
print(f"File saved to: {save_path}")
