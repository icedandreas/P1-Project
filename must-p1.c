#include <stdio.h>
int findNutritionalState(double weight, double height, double weightloss, int acuteDisease);
double findBMI(double weight, double height);

int findNutritionalState(double weight, double height, double weightloss, int acuteDisease){
    double BMI = 0, weightlossPercentage = 0;
    int scoreFromBMI = 0, mustScore = 0;
    BMI = findBMI(weight, height);
    weightlossPercentage = (weightloss/weight)*100;

    if(BMI < 20 && BMI > 18.5){
        mustScore += 1;
    }
    else if(BMI <= 18.5){
        mustScore += 2;
    }

    if(weightlossPercentage >= 5 && weightlossPercentage <= 10){
        mustScore += 1;
    }
    else if(weightlossPercentage > 10){
        mustScore += 2;
    }

    if(acuteDisease){
        mustScore += 2;
    }

    return mustScore;

}
double findBMI(double weight, double height){
    double BMI = 0;
    height /= 100;

    BMI = weight/(height*height);
    return BMI;
}

int main(void){
    double weight = 0, height = 0, BMI = 0, mustScore = 0, weightloss = 0;
    int acuteDisease;
    char acuteDiseaseAnswer;

    printf("Enter your weight in kg and height in cm\n");
    scanf("%lf %lf", &weight, &height);
    printf("Now enter your weight loss over the last 3-6 months\n");
    scanf("%lf", &weightloss);
    printf("Do you have any acute diseases?(y/n)\n");
    do{  
        scanf("%c", &acuteDiseaseAnswer);
    }while(acuteDiseaseAnswer != 'y' && acuteDiseaseAnswer != 'n'); 
    
    if(acuteDiseaseAnswer == 'y'){
        acuteDisease = 1;
    }
    else{
        acuteDisease = 0;
    }

    mustScore = findNutritionalState(weight, height, weightloss, acuteDisease);

    printf("This is your MUST score: %f\n", mustScore);

}
