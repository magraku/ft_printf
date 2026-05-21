
atoi()
{

}

ft_lst_new()
{
    

}

ft_lst_add_back()
{

}

int is_alpha(char c)
{

    
}

int ft_verify_digit(char *str)
{
    int i;
    
    i = 0;
    while(str[i])
    {
        if(!(is_alpha(str[i])))
            return(0);
        i++;
    }
    return(1);
}
