#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Max number of candidates
#define MAX 9

//candidates have name and vote count
typedef struct
{
   char *name; 
  
   int votes;

} 
candidate;

// Array of candidates
candidate candidates[MAX];

//number of candidates
int candidate_count;

//function prototypes
bool vote(string name);
void print_winner(void);  


int main(int argc, string argv[])
{
   //check for invalid usage
   //arg[0] is the function arg[1] 1st cand, arg[2] 2nd candidate
   if (argc <2)
   {
      printf("Usage: plurality [candidate ...]\n");
      return 1;
   }

//populate array of candidates
candidate_count = argc - 1;
if (candidate_count > MAX) 
{
   printf("Too many candidates, must be less than %i\n", MAX);
   return 2;
}

for (int i=0; i<candidate_count; i++) 
{
   candidates[i].name = argv[i+1];
   candidates[i].votes=0; //initializes the amount of votes for each candidate
}

int voter_count;
printf("Number of voters: ");
scanf("%d",&voter_count);
printf("\n%d voters\n\n",voter_count);

printf("Vote options are: \n");
   
for (int i=0; i<candidate_count; i++) {
printf("(%d): %s\n",i+1,candidates[i].name);
}

//loop over all voters
for (int i=0; i < voter_count; i++) 
{
   char name2[10];

   printf("Voter %d, Please type the name of your candidate: ",i+1);
   
   scanf("%s",*&name2);
 

   //check for valid vote
   
   if (!vote(name2)) //Is this the correct input here?
   {
      printf("invalid vote\n");
   }
}

print_winner();

}

bool vote(char *name)   //Is this the correct input here?
{
   printf("\n%s is being inputted into vote function\n\n",name);
   for (int i=0; i<candidate_count; i++)
   {
      if (strcmp(name,candidates[i].name) == 0)            
      {
         candidates[i].votes++;
         return true;
      }
   }
   return false;
}

void print_winner(void) {
   printf("winner is: ");

   int mostVote=0;

   for (int i2=0; i2<candidate_count; i2++) {
      
      if (mostVote<candidates[i2].votes) {
         mostVote=candidates[i2].votes;
      }


   }
   

   for (int i3=0; i3<candidate_count; i3++) {
      if (mostVote==candidates[i3].votes) {
         printf("%s",candidates[i3].name);
      }


   }
}