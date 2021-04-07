
LNode *find_com(LNode *AW, LNode *BW){
    int i=0 , j=0, k;
    LNode *p = AW, c;
    while(p->next){
        i++;
        p = p->next;
    }
    p = BW;
    while(p->next){
        j++;
        p = p->next;
    }
    if(i-j > 0){
        k = i - j;
        while(k>0){
            AW = AW->next;
            k--;
        }
    }
    else{
        k = j - i;
        while(k>0){
            BW = BW->next;
            k--;
        }
    }
    while(AW){
        if(AW == BW){
            return AW;
        }
        else{
            AW = AW->next;
            BW = BW->next;
        }
    }

}

