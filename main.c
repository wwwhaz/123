#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define Num 1001 

 //設定資料型態 
void inorder(int BinaryTree[], char data[], int i);
void dright(int BinaryTree[], char data[], int i, int j);
void dleft(int BinaryTree[], char data[], int i, int j);

int main() 
{
    int n, i,j, layer = 1,k;
    char key;
    int BinaryTree[Num]; //宣告一個陣列儲存輸入到樹的值 
	char data[Num]; //宣告一個陣列判佔存輸入的值和判斷該值是否為空值 
	
	for(i = 0; i < Num; i++) //將陣列tree 1~1000的值設為-1 
		BinaryTree[i] = -1;
	
	for(i = 1; i < Num; i++) //將陣列type 1~1000的值設為f
		data[i] = 'f';
	
	BinaryTree[0] = n;
	data[0] = 't';
while(1)
 {  //菜單顯示 
    printf("Function list:\n");
    printf("(i or I) Insert new node\n");
    printf("(t or T) Show inoder tree\n");
    printf("(d or D) Delete node based on key\n");
    printf("(s or S) Search node based on key\n");
    printf("(q or Q) End\n");
	printf("請輸入指示");
    scanf(" %c",&key);
    switch (key)
	{
	//輸入一個值 ，存入到樹裡 
	case 'i':
	case 'I':
    	printf("請輸入*1*個節點(1~1000)： \n", n);
       	scanf("%d", &n);
       	i=0;
       	do{
				if(n < BinaryTree[i]){ //尋找key的位置 ， 
					if((i + 1) * 2 - 1 >= pow(2, layer)-1)//值較v小往左子樹走
						layer++;
					i = (i + 1) * 2 - 1;//左子樹節點索引
				}else if(n >BinaryTree[i]){
					if((i + 1) * 2 - 1 >= pow(2, layer)-1)//值較大往右子樹走
						layer++;
					i = (i + 1) * 2;//右子樹節點索引
				}else{
					printf("你所輸入的值已存在\n"); //若key已存在，則輸出已存在 
					break;
				}
			}while(data[i] != 'f');
			
			if(n !=BinaryTree[i]){ //都不存在於樹中，則插入新的key 
				BinaryTree[i] = n;
				data[i] = 't';
			}	
    break;
    //iorder顯現樹 
    case 't':
	case 'T':
		 //呼叫建立二元樹之副程式
    	printf("Inorder: ");
		inorder(BinaryTree, data, 0); //呼叫inorder函數 
		printf("\n");
    break;
    //刪除值 
   case 'd':
   case 'D':
        printf("請輸入要刪除的值: ");
			scanf("%d", &n);
			i = 0;
			do{
				if(data[i] == 'f' || i >= pow(2, layer)-1)
				{ //如果沒有搜尋到需要刪除的值，則輸出錯誤訊息 
					printf("你所想刪除的值不在其中\n", n);
					break;
				}else if(n < BinaryTree[i])
				{ //搜尋需要刪除的值 
					i = (i + 1) * 2 - 1; 
				}else if(n > BinaryTree[i])
				{
					i = (i + 1) * 2;
				}else if(n == BinaryTree[i])
				{ //刪除搜尋到的值 
					if(data[(i+1)*2-1] == 'f' && data[(i+1)*2] == 'f')
					{ //degree為0時 
						data[i] = -1;
						data[i] = 'f';
					}else if(data[(i+1)*2-1] == 'f')
					{ //當degree為1時 
						dright(BinaryTree,data, i, (i+1)*2); //呼叫 dright函數 ，刪除右子樹值 
					}else if(data[(i+1)*2] == 'f')
					{ //當degree為1時 
						dleft(BinaryTree,data, i, (i+1)*2-1); //呼叫 dleft函數，刪除左子樹值 
					}else{ //degree為2時
						j = i;
						i = (i+1)*2-1;
						while(data[(i+1)*2] == 't')
						{
							i = (i+1)*2;
						}
						data[j] = BinaryTree[i];
						data[i] = 'f';
						if(data[(i+1)*2-1] == 't')//左子樹 
							dleft(BinaryTree, data, i, (i+1)*2-1); //呼叫 dleft函數，刪除左子樹值 
					}
					break;
				}
			}while(1); 
			break;
	//搜尋 
   case's':
   case 'S':
   	    printf("請輸入想搜尋的值: ");
			scanf("%d", &n);
			i = 0;
			do{
				if(data[i] == 'f' || i >= pow(2, layer)-1)
				{ //如果沒有搜尋到需要刪除的值，則輸出錯誤訊息  
					printf("你所想搜尋的值不在其中\n", n);
					break;
				}else if(n < BinaryTree[i])//拜訪左子樹 
				{
					i = (i + 1) * 2 - 1;
				}else if(n > BinaryTree[i])//拜訪右子樹 
				{
					i = (i + 1) * 2;
				}else if(n == BinaryTree[i])//值相同，輸出值 
				{
					printf("%d's index value = %d\n", n, i);
					break;
				}
			}while(1);
			break;
	//結束程式 
   case 'q':
   case 'Q':
		printf("End\n");
		return 0;
		break;
		}
}				
	} 
void inorder(int BinaryTree[], char data[], int i)
{
	if(data[(i+1)*2-1] == 't') //左子樹
		inorder(BinaryTree, data, (i+1)*2-1);
		
	printf("%d ", BinaryTree[i]); //拜訪，輸出值	
	if(data[(i+1)*2] == 't') //右子樹 
		inorder(BinaryTree, data, (i+1)*2);
}

void dright(int BinaryTree[], char data[], int i, int j){ //右邊的樹往左移 
	BinaryTree[i] = BinaryTree[j];
	data[i] = 't';
	data[j] = 'f';
	//移動樹直到所有值都移完為止 
	if(data[(j + 1) * 2 - 1] == 't')
	{ //左下往左上移 
		i = j - 1;
		j = (j + 1) * 2 - 1;
		dright(BinaryTree, data, i, j);
	}
	if(data[(i + 1) * 2] == 't')
	{ //右下往左上移 
		i = j;
		j = (j + 1) * 2;
		dright(BinaryTree, data, i, j);
	}
}

void dleft(int BinaryTree[], char data[], int i, int j){ //左邊的樹往右移 
	BinaryTree[i] = BinaryTree[j];
	data[i] = 't';
	BinaryTree[j] = -1;
	data[j] = 'f';
	
	//移動樹直到所有值都移完為止
	if(BinaryTree[(j + 1) * 2 - 1] == 't')
	{ //左下往右上移 
		i = j;
		j = (j + 1) * 2 - 1;
		dleft(BinaryTree, data, i, j);
	}
	
	if(data[(i + 1) * 2] == 't')
	{ //右下往右上移 
		i = j + 1;
		j = (j + 1) * 2;
		dleft(BinaryTree, data, i, j);
	}
}




