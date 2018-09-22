void store_in_sender(char *sender,char *receiver,char *message)
{
    char name[10000]={};
    char direct[1000]={};
    char paabeje[1000]={};
    char Fsender[1000]={};
    char Frec[1000]={};
    strcat(Fsender,sender);
    strcat(Frec,receiver);
    strcat(name,sender);
    strcat(name,": " );
    strcat(name,message);
    strcat(name,"\n");
    encrypt(name);
    //SENDER ER PART TA START
    //strcat(direct,"/");//THIK EI JAYGAAY ROOT DIRECTORY BOSHAYE DIBI//
    strcat(direct,sender);
    strcat(direct,"/");
    strcat(receiver,".txt");
    strcat(direct,receiver);
    //puts(direct);
    FILE *fptr;
    fptr = fopen(direct, "a");
    if(fptr == NULL)
    {
      printf("Sender Error!");
      exit(1);
    }
   fprintf(fptr,"%s", name);
   fclose(fptr);
   //SENDER ER KAHINI SHESH ,RECIEVER SHURU
   FILE *f;
   //strcat(paabeje,"/");//THIK EI JAYGAAY ROOT DIRECTORY BOSHAYE DIBI//
    strcat(paabeje,Frec);
    strcat(paabeje,"/");
    strcat(Fsender,".txt");
    strcat(paabeje,Fsender);
    //puts(paabeje);


   f = fopen(paabeje, "a");
   if(f == NULL)
   {
      printf("Receiver Error!");
      exit(1);
   }
   fprintf(f,"%s", name);
   fclose(f);
   //RECIEVER OO SHESH

    return;
}
