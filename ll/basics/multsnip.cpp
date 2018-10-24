node* node::mult(node*p,node*q)
{
 node*n,*m,*tot=NULL;

 for(n=p;n!=NULL;n=n->link)
 {node*prod=new node;
  node*h=prod;
  for(m=q;m!=NULL;m=m->link)
   {prod->link=new node;
    prod=prod->link;
    prod->exp=(n->exp)+(m->exp);
    prod->coeff=(n->coeff)*(m->coeff);
   }
  prod->link=NULL;
  tot=add(tot,h->link);
  delete h;
  delete prod;
 }
 return tot;
}
