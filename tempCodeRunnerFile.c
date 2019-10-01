rintf("1. 7*7\n2. 9*9\n");
    scanf("%d",&Size);
    while (Size != 1 || Size != 2)
    {
        printf("Please nput Size\n");
        printf("1. 7*7\n2. 9*9\n");
        scanf("%d",&Size);
    }
    
    if(Size == 1){
        Size = 7;
    }
    else
    {
        Size = 9;
    }