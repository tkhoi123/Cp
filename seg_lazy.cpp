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
void fix(ll id,ll l,ll r)
{
    if(Lazy[id]&&l!=r)
    {
        Lazy[id*2]+=Lazy[id];
        Lazy[id*2+1]+=Lazy[id];
        Node[id*2]+=Lazy[id];
        Node[id*2+1]+=Lazy[id];
        Lazy[id]=0;
    }
}
ll get(ll id,ll l,ll r,ll u,ll v)
{
    fix(id,l,r);
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
    if(l>=u&&r<=v)
    {
        Node[id]+=val;
        Lazy[id]+=val;
        return;
    }
    fix(id,l,r);
    ll mid=(l+r)>>1;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    Node[id]=Node[id*2]+Node[id*2+1];
}
