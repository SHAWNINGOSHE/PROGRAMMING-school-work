enrollment = pd.read_csv("enrollment_data.csv")
academics = pd.read_csv("academic_records.csv")
demographics = pd.read_csv("demographic_data.csv")

df = enrollment.merge(academics, on="student_id") \
               .merge(demographics, on="student_id")

df.head()

df = df.dropna()
df = df.drop_duplicates()

target_enroll = "will_enroll"

target_support = "needs_support"

X = df.drop([target_enroll, target_support], axis=1)
y_enroll = df[target_enroll]
y_support = df[target_support]

X = pd.get_dummies(X, drop_first=True)

X_train, X_test, y_train_enroll, y_test_enroll = train_test_split(
    X, y_enroll, test_size=0.2, random_state=42
)

X_train2, X_test2, y_train_support, y_test_support = train_test_split(
    X, y_support, test_size=0.2, random_state=42
)

scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

X_train2_scaled = scaler.fit_transform(X_train2)
X_test2_scaled = scaler.transform(X_test2)

model_enroll = RandomForestClassifier()
model_enroll.fit(X_train_scaled, y_train_enroll)

pred_enroll = model_enroll.predict(X_test_scaled)
print("Enrollment Prediction Accuracy:", accuracy_score(y_test_enroll, pred_enroll))
print(classification_report(y_test_enroll, pred_enroll))

model_support = RandomForestClassifier()
model_support.fit(X_train2_scaled, y_train_support)

pred_support = model_support.predict(X_test2_scaled)
print("Support Prediction Accuracy:", accuracy_score(y_test_support, pred_support))
print(classification_report(y_test_support, pred_support))

new_students = pd.read_csv("new_students.csv")
new_students_processed = pd.get_dummies(new_students, drop_first=True)


new_students_processed = new_students_processed.reindex(columns=X.columns, fill_value=0)

new_scaled = scaler.transform(new_students_processed)

new_pred_enroll = model_enroll.predict(new_scaled)
new_pred_support = model_support.predict(new_scaled)

new_students["will_enroll"] = new_pred_enroll
new_students["needs_support"] = new_pred_support

new_students.head()
