void build(ll id,ll l,ll r)
{
    if(l==r)
    {
        Node[id]=a[l];
        return;
    }
    ll mid=(l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    Node[id]=Node[id*2]+Node[id*2+1];
}
ll get(ll id,ll l,ll r,ll u,ll v)
{
    if(l>v||r<u)
    {
        return 0;
    }
    if(l>=u&&r<=v)
    {
        return Node[id];
    }
    ll mid=(l+r)>>1;
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
void update(ll id,ll l,ll r,ll u,ll v,ll val)
{
    if(l>v||r<u)
    {
        return ;
    }
    if(l==r&&u==v)
    {
        Node[id]+=val;
        return;
    }
    ll mid=(l+r)>>1;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    Node[id]=Node[id*2]+Node[id*2+1];
}
