
int calculate_circumference(int square_side) {
    int square_circumference = square_side * 4;
    return square_circumference;
}

int calculate_area(int square_side) {
    int square_area = square_side * square_side;
    return square_area;
}

int main(int, char**){
    int square_1_side, square_2_side;
    printf("Zadejte velikost strany prvniho a pote druheho ctverce\n");
    scanf("%d", &square_1_side); 
    scanf("%d", &square_2_side); 
    printf("          obvod  obsah\n");
    printf("ctverec1  ");
    printf("%d     ",calculate_circumference(square_1_side));
    printf("%d \n",calculate_area(square_1_side));
    printf("ctverec2  ");
    printf("%d     ",calculate_circumference(square_2_side));
    printf("%d",calculate_area(square_2_side));
}
