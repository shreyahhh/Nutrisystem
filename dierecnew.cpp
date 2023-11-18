#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>

using namespace std;


struct FoodItem {
    double calories;
    double protein;
};

class Nutrisystem {
public:
    string name;
    double bodyweight;
    double height;
    double targetWeight;
    double dailyCalorieIntake;
    double dailyCaloriesBurned;
    double netCalorieIntake;
    string bmiCategory; 
    vector<string> dietPlan;
    vector<string> workoutPlan;
    bool workedOut;

    //map implementation
    map<string, FoodItem> foodDatabase;

    Nutrisystem() : name(""), bodyweight(0.0), height(0.0), targetWeight(0.0),
        dailyCalorieIntake(0.0), dailyCaloriesBurned(0.0), netCalorieIntake(0.0), bmiCategory(""), workedOut(false) {}

    void welcomeMessage() {
        cout << "Welcome to Nutrisystem!" << endl;
        cout << "Embark on a journey to better health and well-being." << endl;
        cout << "Let's get started on your personalized health and fitness plan." << endl;
        cout << "Please enter your name: ";
        getline(cin, name);
    }

    void initializeFoodDatabase() {
        
        //initialize food ddata base

        foodDatabase["Scrambled eggs with avocado"] = {250.0, 15.0};
        foodDatabase["Quinoa salad with chickpeas"] = {350.0, 10.0};
        foodDatabase["Almonds and a banana"] = {200.0, 8.0};
        foodDatabase["Grilled salmon with steamed broccoli"] = {400.0, 20.0};
        foodDatabase["Greek yogurt with berries"] = {180.0, 10.0};
        foodDatabase["Scrambled tofu with sautéed vegetables (bell peppers, spinach, onions, and tomatoes)"] = {300.0, 18.0};
        foodDatabase["Oatmeal with almond or coconut milk, berries"] = {300.0, 18.0};
        foodDatabase["A handful of cherry tomatoes"] = {300.0, 18.0};
        foodDatabase["Grilled fish or skinless poultry with quinoa"] = {300.0, 18.0};
        foodDatabase["Scrambled eggs"] = {300.0, 18.0};
        foodDatabase["Steamed broccoli and cauliflower"] = {300.0, 18.0};
        foodDatabase["Mixed greens salad with vinaigrette dressing"] = {300.0, 18.0};
        foodDatabase["Whole-grain toast"] = {300.0, 18.0};
        foodDatabase["Roasted sweet potatoes"] = {300.0, 18.0};
        foodDatabase["Lentil and vegetable soup"] = {300.0, 18.0};
        foodDatabase["A glass of dairy-free fortified orange juice"] = {300.0, 18.0};
    
    }

    void collectHealthData() {
        cout << "Hello, " << name << "!" << endl;
        cout << "Let's begin by gathering some health-related information." << endl;

        do {
            cout << "Enter your current bodyweight (in kilograms): ";
            cin >> bodyweight;
            if (bodyweight <= 0) {
                cout << "Invalid input. Please enter a positive number: ";
            }
        } while (bodyweight <= 0);

        do {
            cout << "Enter your height (in meters): ";
            cin >> height;
            if (height <= 0) {
                cout << "Invalid input. Please enter a positive number: ";
            }
        } while (height <= 0);

        do {
            cout << "Enter your target weight (in kilograms): ";
            cin >> targetWeight;
            if (targetWeight <= 0) {
                cout << "Invalid input. Please enter a positive number: ";
            }
        } while (targetWeight <= 0);

        do {
            cout << "Did you work out today? (1 for Yes, 0 for No): ";
            cin >> workedOut;
            if (workedOut != 0 && workedOut != 1) {
                cout << "Invalid input. Please enter 1 for Yes or 0 for No: ";
            }
        } while (workedOut != 0 && workedOut != 1);

        if (workedOut) {
            do {
                cout << "Enter the number of calories you burned during your workout: ";
                cin >> dailyCaloriesBurned;
                if (dailyCaloriesBurned < 0) {
                    cout << "Invalid input. Please enter a non-negative number: ";
                }
            } while (dailyCaloriesBurned < 0);
        } else {
            dailyCaloriesBurned = 0; 
        }

        do {
            cout << "Enter your estimated daily calorie intake (calories): ";
            cin >> dailyCalorieIntake;
            if (dailyCalorieIntake <= 0) {
                cout << "Invalid input. Please enter a positive number: ";
            }
        } while (dailyCalorieIntake <= 0);

        calculateBMI();
        calculateNetCalorieIntake();
        generateDietPlan();
        generateWorkoutPlan();
        calculateWaterIntake();
    }

    void calculateBMI() {
        double bmi = bodyweight / (height * height);

        if (bmi < 18.5) {
            bmiCategory = "Underweight";
        } else if (bmi < 24.9) {
            bmiCategory = "Healthy Weight";
        } else if (bmi < 29.9) {
            bmiCategory = "Overweight";
        } else {
            bmiCategory = "Obese";
        }
    }

    void calculateNetCalorieIntake() {
        netCalorieIntake = dailyCalorieIntake - dailyCaloriesBurned;
    }

    void calculateWaterIntake() {
        double suggestedWaterIntake = (bodyweight * 30.0);
        if (bmiCategory == "Obese") {
            suggestedWaterIntake *= 1.1;
        }

        cout << "\nWater Intake Recommendation for " << name << ":\n";
        cout << "Based on your body weight and BMI, it is recommended that you consume at least " << suggestedWaterIntake << " milliliters of water per day.\n";
    }
    void generateDietPlan() {
    dietPlan.clear();

    // Ask the user about allergies 
    cout << "Do you have any food allergies? Select an option:" << endl;
    cout << "1. No allergies" << endl;
    cout << "2. Dairy allergy" << endl;
    cout << "3. Nut allergy" << endl;

    int allergyChoice;
    while (true) {
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> allergyChoice;
        if (allergyChoice == 1 || allergyChoice == 2 || allergyChoice == 3) {
            break;
        }
        cout << "Invalid input. Please enter 1, 2, or 3." << endl;
    }

    if (allergyChoice == 1) {
        // No allergies
        if (bmiCategory == "Underweight") {
            dietPlan.push_back("Breakfast: " + recommendFood("Scrambled tofu with sautéed vegetables (bell peppers, spinach, onions, and tomatoes"));
            dietPlan.push_back("Lunch: " + recommendFood("Quinoa salad with chickpeas"));
            dietPlan.push_back("Snack: " + recommendFood("Almonds and a banana"));
            dietPlan.push_back("Dinner: " + recommendFood("Grilled salmon with steamed broccoli"));
        } else if (bmiCategory == "Healthy Weight") {
            dietPlan.push_back("Breakfast: " + recommendFood("Oatmeal with almond or coconut milk, berries"));
            dietPlan.push_back("Lunch: " + recommendFood("Grilled chicken with mixed vegetables"));
            dietPlan.push_back("Snack: " + recommendFood("Almonds and a banana"));
            dietPlan.push_back("Dinner: " + recommendFood("Quinoa salad with chickpeas"));
        } else if (bmiCategory == "Overweight") {
            dietPlan.push_back("Breakfast: " + recommendFood("Greek yogurt with berries"));
            dietPlan.push_back("Lunch: " + recommendFood("Grilled fish or skinless poultry with quinoa"));
            dietPlan.push_back("Snack: " + recommendFood("A handful of cherry tomatoes"));
            dietPlan.push_back("Dinner: " + recommendFood("Quinoa salad with chickpeas"));
        } else if (bmiCategory == "Obese") {
            dietPlan.push_back("Breakfast: " + recommendFood("Scrambled eggs"));
            dietPlan.push_back("Lunch: " + recommendFood("Grilled chicken with mixed vegetables"));
            dietPlan.push_back("Snack: " + recommendFood("Almonds and a banana"));
            dietPlan.push_back("Dinner: " + recommendFood("Steamed broccoli and cauliflower"));
        }
    } else if (allergyChoice == 2) {
        
        dietPlan.push_back("We have created a custom diet plan based on your dairy allergy:");
        
        if (bmiCategory == "Underweight") {
            dietPlan.push_back("Breakfast: " + recommendFood("Scrambled tofu with sautéed vegetables (bell peppers, spinach, onions, and tomatoes"));
            dietPlan.push_back("Lunch: " + recommendFood("Quinoa salad with chickpeas"));
            dietPlan.push_back("Snack: " + recommendFood("Almonds and a banana"));
            dietPlan.push_back("Dinner: " + recommendFood("Grilled salmon with steamed broccoli"));
        } else if (bmiCategory == "Healthy Weight") {
            dietPlan.push_back("Breakfast: " + recommendFood("Oatmeal with almond or coconut milk, berries"));
            dietPlan.push_back("Lunch: " + recommendFood("Grilled chicken with mixed vegetables"));
            dietPlan.push_back("Snack: " + recommendFood("Almonds and a banana"));
            dietPlan.push_back("Dinner: " + recommendFood("Quinoa salad with chickpeas"));
        } else if (bmiCategory == "Overweight") {
            dietPlan.push_back("Breakfast: " + recommendFood("Greek yogurt with berries"));
            dietPlan.push_back("Lunch: " + recommendFood("Grilled fish or skinless poultry with quinoa"));
            dietPlan.push_back("Snack: " + recommendFood("A handful of cherry tomatoes"));
            dietPlan.push_back("Dinner: " + recommendFood("Quinoa salad with chickpeas"));
        } else if (bmiCategory == "Obese") {
            dietPlan.push_back("Breakfast: " + recommendFood("Scrambled eggs"));
            dietPlan.push_back("Lunch: " + recommendFood("Grilled chicken with mixed vegetables"));
            dietPlan.push_back("Snack: " + recommendFood("Almonds and a banana"));
            dietPlan.push_back("Dinner: " + recommendFood(" Steamed broccoli and cauliflower"));
        }




    } else {
        // nut allergy
        dietPlan.push_back("We have created a custom diet plan based on your nut allergy:");
        

        if (bmiCategory == "Underweight") {
            dietPlan.push_back("Breakfast: " + recommendFood("A glass of dairy-free fortified orange juice"));
            dietPlan.push_back("Lunch: " + recommendFood("Grilled chicken with mixed vegetables"));
            dietPlan.push_back("Dinner: " + recommendFood("Baked fish with steamed asparagus"));
        } else if (bmiCategory == "Healthy Weight") {
            dietPlan.push_back("Breakfast: " + recommendFood("Yogurt parfait with non-dairy yogurt and berries"));
            dietPlan.push_back("Lunch: " + recommendFood("Quinoa salad with roasted vegetables"));
            dietPlan.push_back("Dinner: " + recommendFood("Stir-fried tofu with brown rice"));
        } else if (bmiCategory == "Overweight") {
            dietPlan.push_back("Breakfast: " + recommendFood("Yogurt parfait with non-dairy yogurt and berries"));
            dietPlan.push_back("Lunch: " + recommendFood("Lentil and vegetable soup"));
            dietPlan.push_back("Dinner: " + recommendFood("Roasted sweet potatoes"));
        } else if (bmiCategory == "Obese") {
            dietPlan.push_back("Breakfast: " + recommendFood("Whole-grain toast"));
            dietPlan.push_back("Lunch: " + recommendFood("Mixed greens salad with vinaigrette dressing"));
            dietPlan.push_back("Dinner: " + recommendFood("Stir-fried tofu with brown rice"));
        }

    }
}



    string recommendFood(const string& foodName) {
       
        if (foodDatabase.find(foodName) != foodDatabase.end()) {
            double calories = foodDatabase[foodName].calories;
            double protein = foodDatabase[foodName].protein;
            return foodName + " (" + to_string(calories) + " calories, " + to_string(protein) + "g protein)";
        } else {
            return foodName;
        }
    }

    void generateWorkoutPlan() {
        workoutPlan.clear();

        cout << "Great! Let's plan your gym workout routine." << endl;
        cout << "Here's a gym workout plan focusing on different muscle groups:" << endl;

        workoutPlan.push_back("Monday: Chest and Triceps");
        workoutPlan.push_back("- Bench Press: 4 sets x 8-10 reps");
        workoutPlan.push_back("- Tricep Dips: 3 sets x 10-12 reps");
        workoutPlan.push_back("Tuesday: Back and Biceps");
        workoutPlan.push_back("- Pull-Ups or Lat Pulldowns: 4 sets x 8-10 reps");
        workoutPlan.push_back("- Bicep Curls: 3 sets x 10-12 reps");
        workoutPlan.push_back("Wednesday: Legs and Abs");
        workoutPlan.push_back("- Squats: 4 sets x 8-10 reps");
        workoutPlan.push_back("- Leg Raises: 3 sets x 10-12 reps");
        workoutPlan.push_back("Thursday: Shoulders and Cardio");
        workoutPlan.push_back("- Overhead Press: 4 sets x 8-10 reps");
        workoutPlan.push_back("- Cardio: 30 minutes of running or cycling");
        workoutPlan.push_back("Friday: Rest day (relax and recover)");
        workoutPlan.push_back("Saturday: Full Body Workout");
        workoutPlan.push_back("- Deadlifts: 4 sets x 6-8 reps");
        workoutPlan.push_back("- Push-Ups: 3 sets x 10-12 reps");
        workoutPlan.push_back("Sunday: Rest day (relax and recover)");
    }

    void displayUserData() {
        cout << "\nUser Data:\n";
        cout << "Name: " << name << endl;
        cout << "Bodyweight: " << bodyweight << " kg\n";
        cout << "Height: " << height << " meters\n";
        cout << "Target Weight: " << targetWeight << " kg\n";
        cout << "BMI Category: " << bmiCategory << "\n";
    }

    void displayCaloriesInfo() {
        cout << "\nCalories Information:\n";
        cout << "Daily Calorie Intake: " << dailyCalorieIntake << " calories\n";
        cout << "Daily Calories Burned: " << dailyCaloriesBurned << " calories\n";
        cout << "Net Calorie Intake (Intake vs. Burnt): " << netCalorieIntake << " calories\n";
    }

    void displayDietPlan() {
        cout << "\nDiet Plan for " << name << " (BMI Category: " << bmiCategory << "):\n";
        for (const auto& plan : dietPlan) {
            cout << "- " << plan << endl;
        }
    }

    void displayWorkoutPlan() {
        cout << "\nWorkout Plan for " << name << " (BMI Category: " << bmiCategory << "):\n";
        for (const auto& plan : workoutPlan) {
            cout << "- " << plan << endl;
        }
    }
};

int main() {
    Nutrisystem nutrisystem;
    nutrisystem.initializeFoodDatabase(); 
    nutrisystem.welcomeMessage();
    nutrisystem.collectHealthData();
    nutrisystem.displayUserData();
    nutrisystem.displayCaloriesInfo();
    nutrisystem.displayDietPlan();
    nutrisystem.displayWorkoutPlan();

    return 0;
}