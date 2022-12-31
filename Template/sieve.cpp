for(ll i=4; i<=n; i+=2)check[i]=true;
    for(ll i=3; i*i<=n; i+=2)
    {
        if(check[i]==false)
        {
            for(ll j=i*i; j<n; j+=2*i)
            {
                check[j]=true;
            }
        }
    }
