// printf("!----- CONNECTION ESTABLISHED -----!\n");
// printf("COPYRIGHT MEGA CORPORATION - STRICTLY CONFIDENTIAL - FOR INTERNAL USE ONLY\n");
// printf("Welcome, ########.\n");
// printf("There are 7 areas in this dojo that you must traverse to be the very best.\n");
// printf("I'm expecting the best from you!\n");
// printf("!----- DOJO TRAINING STARTING -----!\n");

// ビギニング

void Beginning(char* in) {
    if(strings_not_equal("Right, I am the clown that you wished for, do with me however you like", in))
        illegal_move();
    printf("Congratulations, you passed the first area. Feeling satisfied?\n");
}