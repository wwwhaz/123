#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define Num 1001 

 //�]�w��ƫ��A 
void inorder(int BinaryTree[], char data[], int i);
void dright(int BinaryTree[], char data[], int i, int j);
void dleft(int BinaryTree[], char data[], int i, int j);

int main() 
{
    int n, i,j, layer = 1,k;
    char key;
    int BinaryTree[Num]; //�ŧi�@�Ӱ}�C�x�s��J��𪺭� 
	char data[Num]; //�ŧi�@�Ӱ}�C�P���s��J���ȩM�P�_�ӭȬO�_���ŭ� 
	
	for(i = 0; i < Num; i++) //�N�}�Ctree 1~1000���ȳ]��-1 
		BinaryTree[i] = -1;
	
	for(i = 1; i < Num; i++) //�N�}�Ctype 1~1000���ȳ]��f
		data[i] = 'f';
	
	BinaryTree[0] = n;
	data[0] = 't';
while(1)
 {  //������ 
    printf("Function list:\n");
    printf("(i or I) Insert new node\n");
    printf("(t or T) Show inoder tree\n");
    printf("(d or D) Delete node based on key\n");
    printf("(s or S) Search node based on key\n");
    printf("(q or Q) End\n");
	printf("�п�J����");
    scanf(" %c",&key);
    switch (key)
	{
	//��J�@�ӭ� �A�s�J���� 
	case 'i':
	case 'I':
    	printf("�п�J*1*�Ӹ`�I(1~1000)�G \n", n);
       	scanf("%d", &n);
       	i=0;
       	do{
				if(n < BinaryTree[i]){ //�M��key����m �A 
					if((i + 1) * 2 - 1 >= pow(2, layer)-1)//�ȸ�v�p�����l��
						layer++;
					i = (i + 1) * 2 - 1;//���l��`�I����
				}else if(n >BinaryTree[i]){
					if((i + 1) * 2 - 1 >= pow(2, layer)-1)//�ȸ��j���k�l��
						layer++;
					i = (i + 1) * 2;//�k�l��`�I����
				}else{
					printf("�A�ҿ�J���Ȥw�s�b\n"); //�Ykey�w�s�b�A�h��X�w�s�b 
					break;
				}
			}while(data[i] != 'f');
			
			if(n !=BinaryTree[i]){ //�����s�b��𤤡A�h���J�s��key 
				BinaryTree[i] = n;
				data[i] = 't';
			}	
    break;
    //iorder��{�� 
    case 't':
	case 'T':
		 //�I�s�إߤG���𤧰Ƶ{��
    	printf("Inorder: ");
		inorder(BinaryTree, data, 0); //�I�sinorder��� 
		printf("\n");
    break;
    //�R���� 
   case 'd':
   case 'D':
        printf("�п�J�n�R������: ");
			scanf("%d", &n);
			i = 0;
			do{
				if(data[i] == 'f' || i >= pow(2, layer)-1)
				{ //�p�G�S���j�M��ݭn�R�����ȡA�h��X���~�T�� 
					printf("�A�ҷQ�R�����Ȥ��b�䤤\n", n);
					break;
				}else if(n < BinaryTree[i])
				{ //�j�M�ݭn�R������ 
					i = (i + 1) * 2 - 1; 
				}else if(n > BinaryTree[i])
				{
					i = (i + 1) * 2;
				}else if(n == BinaryTree[i])
				{ //�R���j�M�쪺�� 
					if(data[(i+1)*2-1] == 'f' && data[(i+1)*2] == 'f')
					{ //degree��0�� 
						data[i] = -1;
						data[i] = 'f';
					}else if(data[(i+1)*2-1] == 'f')
					{ //��degree��1�� 
						dright(BinaryTree,data, i, (i+1)*2); //�I�s dright��� �A�R���k�l��� 
					}else if(data[(i+1)*2] == 'f')
					{ //��degree��1�� 
						dleft(BinaryTree,data, i, (i+1)*2-1); //�I�s dleft��ơA�R�����l��� 
					}else{ //degree��2��
						j = i;
						i = (i+1)*2-1;
						while(data[(i+1)*2] == 't')
						{
							i = (i+1)*2;
						}
						data[j] = BinaryTree[i];
						data[i] = 'f';
						if(data[(i+1)*2-1] == 't')//���l�� 
							dleft(BinaryTree, data, i, (i+1)*2-1); //�I�s dleft��ơA�R�����l��� 
					}
					break;
				}
			}while(1); 
			break;
	//�j�M 
   case's':
   case 'S':
   	    printf("�п�J�Q�j�M����: ");
			scanf("%d", &n);
			i = 0;
			do{
				if(data[i] == 'f' || i >= pow(2, layer)-1)
				{ //�p�G�S���j�M��ݭn�R�����ȡA�h��X���~�T��  
					printf("�A�ҷQ�j�M���Ȥ��b�䤤\n", n);
					break;
				}else if(n < BinaryTree[i])//���X���l�� 
				{
					i = (i + 1) * 2 - 1;
				}else if(n > BinaryTree[i])//���X�k�l�� 
				{
					i = (i + 1) * 2;
				}else if(n == BinaryTree[i])//�ȬۦP�A��X�� 
				{
					printf("%d's index value = %d\n", n, i);
					break;
				}
			}while(1);
			break;
	//�����{�� 
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
	if(data[(i+1)*2-1] == 't') //���l��
		inorder(BinaryTree, data, (i+1)*2-1);
		
	printf("%d ", BinaryTree[i]); //���X�A��X��	
	if(data[(i+1)*2] == 't') //�k�l�� 
		inorder(BinaryTree, data, (i+1)*2);
}

void dright(int BinaryTree[], char data[], int i, int j){ //�k�䪺�𩹥��� 
	BinaryTree[i] = BinaryTree[j];
	data[i] = 't';
	data[j] = 'f';
	//���ʾ𪽨�Ҧ��ȳ��������� 
	if(data[(j + 1) * 2 - 1] == 't')
	{ //���U�����W�� 
		i = j - 1;
		j = (j + 1) * 2 - 1;
		dright(BinaryTree, data, i, j);
	}
	if(data[(i + 1) * 2] == 't')
	{ //�k�U�����W�� 
		i = j;
		j = (j + 1) * 2;
		dright(BinaryTree, data, i, j);
	}
}

void dleft(int BinaryTree[], char data[], int i, int j){ //���䪺�𩹥k�� 
	BinaryTree[i] = BinaryTree[j];
	data[i] = 't';
	BinaryTree[j] = -1;
	data[j] = 'f';
	
	//���ʾ𪽨�Ҧ��ȳ���������
	if(BinaryTree[(j + 1) * 2 - 1] == 't')
	{ //���U���k�W�� 
		i = j;
		j = (j + 1) * 2 - 1;
		dleft(BinaryTree, data, i, j);
	}
	
	if(data[(i + 1) * 2] == 't')
	{ //�k�U���k�W�� 
		i = j + 1;
		j = (j + 1) * 2;
		dleft(BinaryTree, data, i, j);
	}
}




