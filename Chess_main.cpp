#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
void initialisation_plateau(int p[8][8]){
	int i,j;
	p[0][0]=1;
	p[0][1]=2;
	p[0][2]=3;
	p[0][3]=4;
	p[0][4]=5;
	p[0][5]=3;
	p[0][6]=2;
	p[0][7]=1;
	
	for(i=1;i<2;i++)
	{
		for(j=0;j<8;j++)
		{
			p[i][j]=6;
		}
	}
	for(i=2;i<6;i++)
	{
		for(j=0;j<8;j++)
		{
			p[i][j]=0;
		}
	}
	for(i=6;i<7;i++)
	{
		for(j=0;j<8;j++)
		{
			p[i][j]=66;
		}
	}
	p[7][0]=11;
	p[7][1]=22;
	p[7][2]=33;
	p[7][3]=44;
	p[7][4]=55;
	p[7][5]=33;
	p[7][6]=22;
	p[7][7]=11;

}
void afficher_plateau(int p[8][8]){
 int n=8;
int i;
    	int l=-1;
    cout<<"___________________________________________________________________\n"<<endl;
	
	for(int i=0;i<n;i++){
		HANDLE console;
		console = GetStdHandle(STD_OUTPUT_HANDLE);
		l++;
		SetConsoleTextAttribute(console,15);
		cout<<l;
		for(int j=0;j<n;j++)
		{
			if(j==7){
			
				cout<<" |  ";
			}
			else{
				cout<<" | ";
			}
			if(p[i][j]==1)
			
			{   SetConsoleTextAttribute(console,8);
				cout<<"  Tn ";
				
			}
				if(p[i][j]==2)
			{
				cout<<"  Cn ";
				
			}
				if(p[i][j]==3)
			{
				cout<<"  Fn ";
			}
				if(p[i][j]==4)
			{
				cout<<"  Dn ";
			}
				if(p[i][j]==5)
			{
				cout<<"  Rn ";
			}
				if(p[i][j]==6)
			{   SetConsoleTextAttribute(console,8);
				cout<< "  Pn ";
			}
				if(p[i][j]==0)
			{  
			    SetConsoleTextAttribute(console,7);
				cout<<" __  ";
			} 
				if(p[i][j]==11)
			{   
			    SetConsoleTextAttribute(console,15);
				cout<<" Tb  ";
			}
				if(p[i][j]==22)
			{
				cout<<" Cb  ";
			}
				if(p[i][j]==33)
			{
				cout<<" Fb  ";
			}
				if(p[i][j]==44)
			{
				cout<<" Db  ";
			}
				if(p[i][j]==55)
			{
				cout<<" Rb  ";
			}
				if(p[i][j]==66)
			{   
			    SetConsoleTextAttribute(console,15);
				cout<<" Pb  ";
			} 
			
		}
	    	
		cout<< "|"<<endl;
		cout<< " "<<endl;
		
		}  	
	    cout<<"____________________________________________________________________ \n";
		cout<<"     a       b       c       d       e       f        g        h     \n\n";

}
void Deplacer(int p[8][8],int i,int j,int i2,int j2){
	p[i2][j2]=p[i][j];
  	p[i][j]=0;	
}
int T[4];
void initT(int T[4]){
	for(int e=0;e<=4;e++){
		T[e]=0;
	}
}
void Pion_joueur1(int p[8][8],int i,int j, int T[4]){
	do{
		int i2,j2,choix;
		  	cout<<"Entrez Les coordonnees De la case d arrivee : " <<endl;
  			cout<<"La ligne = ";
  			cin>>i2;
  			cout<<"la colonne = ";
			cin>>j2;
  			if(p[i2][j2]==0){
				if(j==j2){
					if(i==1){	
					if((i2==i+1)||(i2==i+2)){
						 Deplacer(p,i,j,i2,j2);
						 if(i2==i+2){
						 	T[0]=3;
						 }
						}
						else{
						cout<<"Impossible"<<endl;
						}
					}
					else if(i>1){
					   if((i2==i+1) && (i!=6)){
					    Deplacer(p,i,j,i2,j2);
				    	 }
				    	else{
				    	cout<<"Impossible"<<endl;
				    	}	
		               //Echange
		             if(i==6) {

			         		cout<<"veuillez changer votre pion en :"<<endl<<"1-Tour"<<endl<<"2-Cavalier"<<endl<<"3-Fou"<<endl<<"4-Dame"<<endl;
			         		cin>>choix;
				             switch(choix)
                                 {
                                    case 1 :
                                    p[i][j]=1;
                                   	Deplacer(p,i,j,i2,j2);
                     	            break;
                                    case 2 :
                                	p[i][j]=2;
                                	Deplacer(p,i,j,i2,j2);
                                	break;	
                                    case 3 :
                                	p[i][j]=3;
                                	Deplacer(p,i,j,i2,j2);
                                	break;
                                    case 4 :
                                 	p[i][j]=4;
                                	Deplacer(p,i,j,i2,j2);
                                	break;	
                                    case 5:break;	
                                  }

		                        	}
					}	
				}
				//prise en passant
				else if((i==4) && (p[i][j+1]==66 || p[i][j-1]==66) && ( (i2==i+1 && j2==j+1) || (i2==i+1 && j2==j-1) ) ){
					if(T[0]==2){
						if(i2==i+1 && j2==j+1){
							Deplacer(p,i,j,i2,j2);
							p[i][j+1]=0;
						}
						else if(i2==i+1 && j2==j-1){
							Deplacer(p,i,j,i2,j2);
							p[i][j-1]=0;
						}
					}
				}
				else{
				cout<<"Impossible"<<endl;
				}
			}
			else if( ( (i2==i+1 && j2==j+1) || (i2==i+1 && j2==j-1) ) && ((p[i2][j2]==0)||(p[i2][j2]==66)||(p[i2][j2]==11)||(p[i2][j2]==22)||(p[i2][j2]==33)||(p[i2][j2]==44)||(p[i2][j2]==55)) ){
			//tester si une piece de l'autre joueur est a la position de tuer Pour le Pion
			Deplacer(p,i,j,i2,j2);
			}
			else{
			cout<<"Imposssible"<<endl;
		    }
				          	
  		   }while(p[i][j]!=0);
}
void Tour_joueur1(int p[8][8],int i,int j){
		int cpx=0,cpy=0,cpxn=0,cpyn=0,m,n;
	   	int i2,j2;
			cout<<"Entrez Les coordonnees De la case d arrivee : " <<endl;
  			cout<<"La ligne =";
  			cin>>i2;
  			cout<<"La colonne =";
			cin>>j2;					
						if((p[i2][j2]==0)||(p[i2][j2]==66)||(p[i2][j2]==11)||(p[i2][j2]==22)||(p[i2][j2]==33)||(p[i2][j2]==44)||(p[i2][j2]==55)){
							if(i2==i){
								int f=j;
								do{
									f++;
									cpy++;
								}while(p[i][f]==0);
								int h=j2;
								do{
									h--;
									cpyn++;
								}while(p[i][h]==0);
									
									if((j2<cpyn)||(j2<cpy))
									{
									 Deplacer(p,i,j,i2,j2);
									}else{
										cout<<"Impossible"<<endl;
										
									}
							}
							else if(j2==j){
							int k=i;
							do{
									k++;
									cpx++;
								}while(p[k][j]==0);
							int h=i2;		    		
							do{
									h--;
									cpxn++;
								}while(p[h][j]==0);

								if((i2<cpxn)||(i2<cpx))
								{
										 Deplacer(p,i,j,i2,j2);
									}else{
										cout<<"Impossible"<<endl;
										
									}
							}
							else{
							cout<<"Impossible"<<endl;
							
							}
						}
						else{
							cout<<"Impossible"<<endl;
						
						}		
}
void Cavalier(int p[8][8],int i,int j){
	int i2,j2;
        	cout<<"Entrez Les coordonnees De la case d arrivee : " <<endl;
  			cout<<"La ligne = ";
  			cin>>i2;
  			cout<<"la colonne = ";
			cin>>j2;
		    if(p[i2][j2]==0)
			{//tester si le mouvement de la tour va a une place vide ou pour tuer une piece de l'autre joueur
				if((i2==i+2 && j2==j+1) || (i2==i+2 && j2==j-1) || (i2==i-2 && j2==i+1) || (i2==i-2 && j2==j-1) || (i2==i+1 && j2==j+2) || (i2==i-1 && j2==j+2) || (i2==i+1 && j2==j-2) || (i2==i-1 && j2==j-2))
				{
		   		 Deplacer(p,i,j,i2,j2);				
				}
				else{
				cout<<"movement impossible "<< endl;
				}
		}
		else{
			cout<<"movement impossible "<< endl;
		}	  
}
void Fou_joueur1(int p[8][8],int i,int j){
	int cpxy=0,cpxyn=0,cpyx=0,cpyxn=0,i2,j2;
			cout<<"Entrez Les coordonnees De la case d arrivee : " <<endl;
  			cout<<"La ligne = ";
  			cin>>i2;
  			cout<<"la colonne = ";
			cin>>j2;
					int	t=i,c=j;
					do{
						cpxy++;//le compteur des cases vides en (i,j) choisi avant est droit
						t++;c++;//pour parcourir la matrice en avant est droit
					}while((t<i2 && c<j2)&&(p[t][c]==0));//tantque il y a une place vide est le parcour de la matrice n'est pas d?passer le delacement choisi 
					int e=i,r=j;	
					do{
						cpxyn++;//le compteur des cases vides en (i,j) choisi derri?re est gauche
						e--;r--;//pour parcourir la matrice en derriere est gauche
					}while((e>i2 && r>j2)&&(p[e][r]==0));//tantque il y a une place vide est le parcour de la matrice n'est pas d?passer le delacement choisi 
					int u=i,w=j;
			    	do{
						cpyx++;//le compteur des cases vides en (i,j) choisi derri?re est droite
						u--;w++;//pour parcourir la matrice en derriere est droite
					}while((u>i2 && w<j2)&&(p[u][w]==0));//tantque il y a une place vide est le parcour de la matrice n'est pas depasser le delacement choisi 
					int o=i,m=j;
					do{
						cpyxn++;//le compteur des cases vides en (i,j) choisi avant est gauche
						o++;m--;//pour parcourir la matrice en avant est gauche 
					}while((o<i2 && m>j2)&&(p[o][m]==0));//tantque il y a une place vide est le parcour de la matrice n'est pas depasser le delacement choisi 

						if(( (p[i2][j2]==0)||(p[i2][j2]==66)||(p[i2][j2]==11)||(p[i2][j2]==22)||(p[i2][j2]==33)||(p[i2][j2]==44)||(p[i2][j2]==55) )&&(cpxy!=0 || cpxyn!=0 || cpyx!=0 || cpyxn!=0)){
								if(((i+cpxy==i2)&&(j+cpxy==j2))){
									Deplacer(p,i,j,i2,j2);
						    	}
						    	if(((i-cpxyn==i2)&&(j-cpxyn==j2))){
									 Deplacer(p,i,j,i2,j2);
						    	}
						    	if(((i-cpyx==i2)&&(j+cpyx==j2))){
									 Deplacer(p,i,j,i2,j2);
						    	}
						    	if(((i+cpyxn==i2)&&(j-cpyxn==j2))){
									 Deplacer(p,i,j,i2,j2);
						    	}
								else{
									cout<<"impossible"<<endl;
								}
							}
							else{
								cout<<"impossible"<<endl;
							}		
}
						
						
void Roi(int p[8][8],int i,int j){
	int i2,j2;
	cout<<"Entrez Les coordonnees De la case d arrivee : " <<endl;
  	cout<<"La ligne =";
  	cin>>i2;
  	cout<<"La colonne =";
	cin>>j2;
	if(p[i2][j2]==0){
		
		 if((p[i][j]==5) && ((p[i2][j2]==66) || (p[i2][j2]==11) || (p[i2][j2]==22) || (p[i2][j2]==33) || (p[i2][j2]==44) || (p[i2][j2]==55) || (p[i2][j2]==0)) ){
		 	//test que le roi choisi est se le 1 joueur et le deplacement  est une place vide ou une piece adverser
		 	if((i2==i-1 && j2==j)||(i2==i+1 && j2==j)||(i2==i && j2==j-1)||(i2==i && j2==j+1)||(i2==i-1 && j2==j-1)||(i2==i-1 && j2==j+1)||(i2==i+1 && j2==j-1)||((i2==i+1 && j2==j+1))){ 
		 	//les deplacemnt de base pour le roi
		 	Deplacer(p,i,j,i2,j2);
			}
			else if(i==0 && j==4){//tester si le roi est son place initial
								if(T[1]!=5){
									if(j2==j-3 && i2==i){//si l'utilisateur choisi la grande roque
										Deplacer(p,i,j,i2,j2);
									    p[0][2]=1;//deplacer la Tour 
									    p[0][0]=0;//vider l'ancien  place de la tour
									    T[1]=5;
									}
									else if(j2==j+2 && i2==i){//si l'utilisateur choisi la petite roque
										Deplacer(p,i,j,i2,j2);
									    p[0][5]=1;
									    p[0][7]=0;
									    T[1]=5;
								    }
								}
			}
			else{
				cout<<"Impossible"<<endl;
			}
		 }
	     else if((p[i][j]==55) && ((p[i2][j2]==6) || (p[i2][j2]==1) || (p[i2][j2]==2) || (p[i2][j2]==3) || (p[i2][j2]==4) || (p[i2][j2]==5) || (p[i2][j2]==0))){
	     	if((i2==i-1 && j2==j)||(i2==i+1 && j2==j)||(i2==i && j2==j-1)||(i2==i && j2==j+1)||(i2==i-1 && j2==j-1)||(i2==i-1 && j2==j+1)||(i2==i+1 && j2==j-1)||((i2==i+1 && j2==j+1))){ 
		 	Deplacer(p,i,j,i2,j2);
			}
			else if(i==6 && j==4){//tester si le roi est son place initial
								if(T[1]!=5){
									if(j2==j-3 && i2==i){//si l'utilisateur choisit la grande roque
										Deplacer(p,i,j,i2,j2);
									    p[0][2]=11;//deplacer la Tour pour protejet le roi
									    p[0][0]=0;//vider l'ancien  place de la tour
									    T[1]=5;
									}
									else if(j2==j+2 && i2==i){//si l'utilisateur choisi la petite roque
										Deplacer(p,i,j,i2,j2);
									    p[0][5]=11;
									    p[0][7]=0;
									    T[1]=5;
								    }
								}
			}
			else{
				cout<<"Impossible"<<endl;
			}
		 }

	}
}

void Dame_joueur1(int p[8][8],int i,int j){
int cpxy=0,cpxyn=0,cpyx=0,cpyxn=0;
int i2,j2;
            cout<<"Entrez Les coordonnees De la case d arrivee : " <<endl;
  			cout<<"La ligne =";
  			cin>>i2;
  			cout<<"La colonne =";
			cin>>j2;
			int t=i,w=j;
					do{
						cpxy++;
						t++;w++;
					}while((t<i2 && t<j2)&&(p[t][w]==0));
					int e=i,r=j;	
					do{
						cpxyn++;
						e--;r--;
					}while((e>i2 && r>j2)&&(p[e][r]==0));
					int u=i,m=j;
			    	do{
						cpyx++;
						u--;m++;
					}while((u>i2 && m<j2)&&(p[u][m]==0)); 
					int o=i,n=j;
					do{
						cpyxn++;
						o++;n--;
					}while((o<i2 && n>j2)&&(p[o][n]==0)); 
					if(p[i2][j2]==0){
						int cpy=0,cpyn=0,cpx=0,cpxn=0;
							if(i2==i){
								for(int v=0;v<8;v++){
	    							if(p[i][v]==0){
	    							cpy++;
									}
								}
								for(int v=8;v>0;v--){
	    							if(p[i][v]==0){
	    							cpyn++;
									}
								}									
									if((j2<cpyn)||(j2<cpy))
									{
										 Deplacer(p,i,j,i2,j2);
									}else{
										cout<<"Impossible"<<endl;
									}
							}
							else if(j2==j){	    		
							for(int v=0;v<8;v++){
	    						if(p[v][j]==0){
	    						cpx++;
								}
							}
							for(int v=8;v>0;v--){
	    						if(p[v][j]==0){
	    							cpxn++;
								}
							}
								if((i2<cpxn)||(i2<cpx))
								{
										 Deplacer(p,i,j,i2,j2);
								}
								else{
										cout<<"Impossible"<<endl;
									}
							}
							else if(((p[i2][j2]==0) || (p[i2][j2]==66) || (p[i2][j2]==11) || (p[i2][j2]==22) || (p[i2][j2]==33) || (p[i2][j2]==44) || (p[i2][j2]==55))&&(cpxy!=0 || cpxyn!=0 || cpyx!=0 || cpyxn!=0)){

						    	if(((i+cpxy==i2)&&(j+cpxy==j2))){
								     Deplacer(p,i,j,i2,j2);
						    	}
						    	if(((i-cpxyn==i2)&&(j-cpxyn==j2))){
									 Deplacer(p,i,j,i2,j2);
						    	}
						    	if(((i-cpyx==i2)&&(j+cpyx==j2))){
								      Deplacer(p,i,j,i2,j2);
						    	}
						    	if(((i+cpyxn==i2)&&(j-cpyxn==j2))){
									 Deplacer(p,i,j,i2,j2);
						    	}
						    	else{
								cout<<"Impossible"<<endl;
								}
							}
							else{
							cout<<"Impossible"<<endl;
							}
					
				}
				else{
				cout<<"Impossible"<<endl;
				}
}
void joueur1(int p[8][8]){
  int i,j,i2,j2,n;
  cout<<"Entrez Les coordonnees De la case de depart : " <<endl;
  cout<<"la ligne = ";
  cin>>i;
  cout<<"la colonne = ";
  cin>>j;
  if(p[i][j]==0){//test si la case choisi vide
  	cout<<"Impossible"<<endl;
  	joueur1(p);
  }
  else{
  		
		if(p[i][j]==6){//P
	  	Pion_joueur1(p,i,j,T);
  		}	
        else if(p[i][j]==1){ //T
	    Tour_joueur1(p,i,j);	
		}		
		else if(p[i][j]==2){//C 
		Cavalier(p,i,j);
    	}
 	    else if(p[i][j]==3){//F				
		Fou_joueur1(p,i,j);				
		}
    	else if(p[i][j]==5){ //R
		Roi(p,i,j);
		}    
	    else if(p[i][j]==4){//D
		Dame_joueur1(p,i,j);
		}
		if(p[i][j]!=0){
	    joueur1(p);	
		}
    }
} 
void Pion_joueur2(int p[8][8],int i,int j,int T[4]){
		int i2,j2,choix;
		  	cout<<"Entrez Les coordonnees De la case d arrivee : " <<endl;
  			cout<<"la ligne = ";
  			cin>>i2;
  			cout<<"la colonne = ";
			cin>>j2;
  			if(p[i2][j2]==0){
				if(j==j2){
					if(i==6){	
					if((i2==i-1)||(i2==i-2)){
						 Deplacer(p,i,j,i2,j2);
						 if(i2==i-2){
						 	T[0]=2;
						 }
						}
						else{
						cout<<"Impossible"<<endl;
						}
					}
					else if(i<6){
					   if((i2==i-1) && (i2!=0)){
					    Deplacer(p,i,j,i2,j2);
				    	 }
						
				    	 //Echange
		             	else if(i2==0) {
			         	cout<<"veuillez changer votre pion en :"<<endl<<"1-Tour"<<endl<<"2-Cavalier"<<endl<<"3-Fou"<<endl<<"4-Dame"<<endl;
			         	cin>>choix;
				         switch(choix)
                        {
                         case 1 :
                        p[i][j]=11;
                        Deplacer(p,i,j,i2,j2);
                     	break;
                        case 2 :
                        p[i][j]=22;
                        Deplacer(p,i,j,i2,j2);
                        break;	
                        case 3 :
                        p[i][j]=33;
                        Deplacer(p,i,j,i2,j2);
                        break;
                        case 4 :
                        p[i][j]=44;
                        Deplacer(p,i,j,i2,j2);
                        break;	
                        case 5:break;	
                        }
		                }
						 else{
				    	cout<<"Impossible"<<endl;
				    	}
				    	
					}	
				}
				//prise en passant
				else if((i==3) && (p[i][j+1]==6 || p[i][j-1]==6) && ( (i2==i-1 && j2==j-1) || (i2==i-1 && j2==j+1) ) ){
					if(T[0]==3){
						if(i2==i-1 && j2==j-1){
							Deplacer(p,i,j,i2,j2);
							p[i][j-1]=0;
						}
						else if(i2==i-1 && j2==j+1){
							Deplacer(p,i,j,i2,j2);
							p[i][j+1]=0;
						}
					}
				}
				
				else{
				cout<<"Impossible"<<endl;
				}
			}
			else if( ( (i2==i-1 && j2==j+1) || (i2==i-1 && j2==j-1) ) && ( (p[i2][j2]==0) || (p[i2][j2]==6) ||(p[i2][j2]==1) ||(p[i2][j2]==2) || (p[i2][j2]==3) || (p[i2][j2]==4) || (p[i2][j2]==5) ) ){
				//tester si une piece de l'autre joueur est a la position de tuer Pour le Pion
				Deplacer(p,i,j,i2,j2);
			}
			else{
			cout<<"Imposssible"<<endl;
		    }	          	
}
void Tour_joueur2(int p[8][8],int i,int j){
			int cpx=0,cpy=0,cpxn=0,cpyn=0,m,n;
	   	int i2,j2;
			cout<<"Entrez Les coordonnees De la case d arrivee : " <<endl;
  			cout<<"La ligne =";
  			cin>>i2;
  			cout<<"La colonne =";
			cin>>j2;					
						if((p[i2][j2]==0)||(p[i2][j2]==6)||(p[i2][j2]==1)||(p[i2][j2]==2)||(p[i2][j2]==3)||(p[i2][j2]==4)||(p[i2][j2]==5)){
							if(i2==i){
								int f=j;
								do{
									f++;
									cpy++;
								}while(p[i][f]==0);
								int h=j2;
								do{
									h--;
									cpyn++;
								}while(p[i][h]==0);
									
									if((j2<cpyn)||(j2<cpy)){
										 Deplacer(p,i,j,i2,j2);
									}else{
										cout<<"Impossible"<<endl;
										
									}
							}
							else if(j2==j){
							int k=i;
							do{
									k++;
									cpx++;
								}while(p[k][j]==0);
							int h=i2;		    		
							do{
									h--;
									cpxn++;
								}while(p[h][j]==0);

								if((i2<cpxn)||(i2<cpx)){
										 Deplacer(p,i,j,i2,j2);
									}else{
										cout<<"Impossible"<<endl;
										
									}
							}
							else{
							cout<<"Impossible"<<endl;
							
							}
						}
						else{
							cout<<"Impossible"<<endl;
						
						}		
}
void Fou_joueur2(int p[8][8],int i,int j){
					int cpxy=0,cpxyn=0,cpyx=0,cpyxn=0,i2,j2;
			cout<<"Entrez Les coordonnees De la case d arrivee : " <<endl;
  		   	cout<<"La ligne =";
  			cin>>i2;
  			cout<<"La colonne =";
			cin>>j2;
					int	t=i,w=j;
					do{
						cpxy++;
						t++;w++;
					}while((t<i2 && t<j2)&&(p[t][w]==0));
					int e=i,r=j;	
					do{
						cpxyn++;
						e--;r--;
					}while((e>i2 && r>j2)&&(p[e][r]==0));
					int u=i,c=j;
			    	do{
						cpyx++;
						u--;c++;

					}while((u>i2 && c<j2)&&(p[u][c]==0)); 
					int o=i,n=j;
					do{
						cpyxn++;
						o++;n--;
					}while((o<i2 && n>j2)&&(p[o][n]==0));

						if(((p[i2][j2]==0)||(p[i2][j2]==6)||(p[i2][j2]==1)||(p[i2][j2]==2)||(p[i2][j2]==3)||(p[i2][j2]==4)||(p[i2][j2]==5))&&(cpxy!=0 || cpxyn!=0 || cpyx!=0 || cpyxn!=0)){
						    	if(((i+cpxy==i2)&&(j+cpxy==j2))){
									 Deplacer(p,i,j,i2,j2);
						    	}
						    	if(((i-cpxyn==i2)&&(j-cpxyn==j2))){
									  Deplacer(p,i,j,i2,j2);
						    	}
						    	if(((i-cpyx==i2)&&(j+cpyx==j2))){
									  Deplacer(p,i,j,i2,j2);
						    	}
						    	if(((i+cpyxn==i2)&&(j-cpyxn==j2))){
									  Deplacer(p,i,j,i2,j2);
						    	}
								else{
									cout<<"impossible"<<endl;
								}
							}
							else{
								cout<<"impossible"<<endl;
							}
}
void Dame_joueur2(int p[8][8],int i,int j){
			int cpxy=0,cpxyn=0,cpyx=0,cpyxn=0,i2,j2;
			cout<<"Entrez Les coordonnees De la case d arrivee : " <<endl;
  			cout<<"La ligne =";
  			cin>>i2;
  			cout<<"La colonne =";
			cin>>j2;
					int	t=i,w=j;
					do{
						cpxy++;
						t++;w++;
					}while((t<i2 && t<j2)&&(p[t][w]==0));
					int e=i,r=j;	
					do{
						cpxyn++;
						e--;r--;
					}while((e>i2 && r>j2)&&(p[e][r]==0));
					int u=i,c=j;
			    	do{
						cpyx++;
						u--;c++;

					}while((u>i2 && c<j2)&&(p[u][c]==0)); 
					int o=i,n=j;
					do{
						cpyxn++;
						o++;n--;
					}while((o<i2 && n>j2)&&(p[o][n]==0));
					if((p[i2][j2]==0)||(p[i2][j2]==6)||(p[i2][j2]==1)||(p[i2][j2]==2)||(p[i2][j2]==3)||(p[i2][j2]==4)||(p[i2][j2]==5)){
						int cpy=0,cpyn=0,cpx=0,cpxn=0;
							if(i2==i){
								for(int q=0;q<8;q++){
	    							if(p[i][q]==0){
	    							cpy++;
									}
								}
								for(int q=8;q>0;q--){
	    							if(p[i][q]==0){
	    							cpyn++;
									}
								}									
									if((j2>=cpyn)||(j2>=cpy)){
										  Deplacer(p,i,j,i2,j2);
									}else{
										cout<<"Impossible"<<endl;
									}
							}
							else if(j2==j){	    		
							for(int q=0;q<8;q++){
	    						if(p[q][j]==0){
	    						cpx++;
								}
							}
							for(int q=8;q>0;q--){
	    						if(p[q][j]==0){
	    							cpxn++;
								}
							}
								if((i2>=cpxn)||(i2>=cpx)){
										 Deplacer(p,i,j,i2,j2);
									}else{
										cout<<"Impossible"<<endl;
									}
							}
							if(((p[i2][j2]==0)||(p[i2][j2]==6)||(p[i2][j2]==1)||(p[i2][j2]==2)||(p[i2][j2]==3)||(p[i2][j2]==4)||(p[i2][j2]==5))&&(cpxy!=0 || cpxyn!=0 || cpyx!=0 || cpyxn!=0)){
						    	if(((i+cpxy==i2)&&(j+cpxy==j2))){
									  Deplacer(p,i,j,i2,j2);
						    	}
						    	if(((i-cpxyn==i2)&&(j-cpxyn==j2))){
									 Deplacer(p,i,j,i2,j2);
						    	}
						    	if(((i-cpyx==i2)&&(j+cpyx==j2))){
									 Deplacer(p,i,j,i2,j2);
						    	}
						    	if(((i+cpyxn==i2)&&(j-cpyxn==j2))){
									 Deplacer(p,i,j,i2,j2);
						    	}
								else{
									cout<<"impossible"<<endl;
								}
							}
							else{
								cout<<"impossible"<<endl;
							}
					
				}
				else{
				cout<<"Impossible"<<endl;
				}
}
void joueur2(int p[8][8]){
 int i,j,i2,j2,n;
  cout<<"Entrez Les coordonnees De la case de depart : " <<endl;
  cout<<"la ligne = ";
  cin>>i;
  cout<<"la colonne = ";
  cin>>j;
  if(p[i][j]==0){//test si la case choisi vide
  	cout<<"Impossible"<<endl;
  	joueur2(p);
  }
  else{
  		
		if(p[i][j]==66){//P
	  	Pion_joueur2(p,i,j,T);
  		}	
        else if(p[i][j]==11){ //T
	    Tour_joueur2(p,i,j);	
		}		
		else if(p[i][j]==22){//C 
		Cavalier(p,i,j);
    	}
 	    else if(p[i][j]==33){//F				
		Fou_joueur2(p,i,j);				
		}
    	else if(p[i][j]==55){ //R
		Roi(p,i,j);
		}    
	    else if(p[i][j]==44){//D
		Dame_joueur2(p,i,j);
		}
		if(p[i][j]!=0){
	    joueur2(p);	
		}
    }	
}
int Fin_jeu(int p[8][8]){
	for(int i=0;i<=7;i++){
		for(int j=0;j<=7;j++){
			if((p[i][j]==5)&&(p[i][j]==55)){
				return 1;
			}
			else{
				return 0;
			}
		}
	}
}


		

int main(){  
	cout<<"\n \t\t********************************BIENVENUE AU Jeu D'echec ************************************ \n\n "<<endl;
	int plateau[8][8];
	int tJ,J1,J2,i,j,n;
	initT(T);
    initialisation_plateau(plateau);
	afficher_plateau(plateau);
	do{
	cout<<"***********************************************Joueur1************************************************************"<<endl;	
	joueur1(plateau);
	afficher_plateau(plateau);
	cout<<"***********************************************Joueur2************************************************************"<<endl;	
	joueur2(plateau);
	afficher_plateau(plateau);
	}while(Fin_jeu(plateau)!=1);
	return 0;
}


