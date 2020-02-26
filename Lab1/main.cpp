#include<clocale>
#include<stdio.h>
#include<malloc.h>





//��� ���� ����� ��������� � i-���� �������� �� J-��� ������ ���������� *(matrix+j*size+i)=....

struct Matrix
{
    void* matrix;
    int size;
    int element_size;
};


struct Matrix *create(int e_size,int size); //������� ������� � �������� ��������
struct Matrix *create_ed(int e_size,int size);//������� ��������� ������� � ������� ��������
struct Matrix *create_test(int e_size, int size);


void test_mlt(void);


void fill_mat(struct Matrix* m1);//������� ���������� ������� � ����������
void print_mat(struct Matrix* m1);//������� ������ �������
void multiplication(struct Matrix* m1, struct Matrix* m2, Matrix *res); // ��������� ���� ������
void addition(struct Matrix* m1, struct Matrix* m2, Matrix *res);//�������� ���� ������
void scalar_multiplication(struct Matrix* m1, float scalar, Matrix *res);//��������� ������� �� ������
void transpose(struct Matrix* m1, Matrix *res);//���������������� �������
void lines_addition(struct Matrix* m1, int num_i, int num_p, float kof, Matrix *res );//����������� ������ � ������ ������













int main()
{
    struct Matrix *mat1,*mat2;
    struct Matrix* res;
    setlocale(LC_CTYPE,"rus");
    int pref=0;
    int size;
    int el_size;
    float scalar;
    int num_i, num_p;
    float koef;
    int flag_rep=1;
    int flag_ans=1;
    int flag_ans_r=1;
    int flag_size=1;


    while(flag_rep)
    {
        flag_rep=0;
        printf("��� �� ������ �������?\n�������� ��� �������- 1\n������� ��� �������-2\n�������� �� ������-3\n���������������-4\n��������� � ������ �������� ���������� ������ �����-5\n");
        scanf("%d",&pref);
        printf("������� ������� ������� nxn: ");
        scanf("%d",&size);
        while(flag_size)
        {
            printf("������� ������ ��������(int-4,float-32): ");
            scanf("%d",&el_size);
            if(el_size!=4&&el_size!=32)
            {
                printf("������ ������������ ������");
                flag_size=1;
            }
            else
                flag_size=0;
        }

        mat1=create(el_size,size);


        switch (pref) {
        case 1:
            res = create(mat1->element_size, mat1->size);
            printf("������� �������� ������ ������� �� ������\n");
            fill_mat(mat1);
            mat2=create(el_size,size);
            printf("������� �������� ������ ������� �� ������\n");
            fill_mat(mat2);
            multiplication(mat1,mat2,res);
            free(res);
            free(mat2);
            break;
        case 2:
            res = create(mat1->element_size, mat1->size);
            printf("������� �������� ������ ������� �� ������\n");
            fill_mat(mat1);
            mat2=create_ed(el_size,size);
            printf("������� �������� ������ ������� �� ������\n");
            fill_mat(mat2);
            addition(mat1,mat2,res);
            free(res);
            free(mat2);
            break;
        case 3:
            res = create(mat1->element_size, mat1->size);
            printf("������� �������� ������� �� ������\n");
            fill_mat(mat1);
            printf("������� ������\n");
            scanf("%f",&scalar);
            scalar_multiplication(mat1,scalar,res);
            free(res);
            break;
        case 4:
            res = create(mat1->element_size, mat1->size);
            printf("������� �������� ������� �� ������\n");
            fill_mat(mat1);
            transpose(mat1,res);
            free(res);
            break;
        case 5:


            printf("������� �������� ������� �� ������\n");
            fill_mat(mat1);
            printf("�������� �������:\n");
            print_mat(mat1);
            while(flag_ans_r)
            {
                flag_ans=1;
                while(flag_ans)
                {
                    printf("������� ����� ������, � ������� ����� ���������, ����� ������,������� ����� ���������, � �����������: ");
                    scanf("%d %d %f",&num_i,&num_p,&koef);
                    if(mat1->size<num_i||mat1->size<num_p)
                    {
                        printf("������ ����� c�����, ��������� �� ������� �������");
                        flag_ans=1;
                    }
                    else
                    {
                        flag_ans=0;
                        lines_addition(mat1,num_i,num_p,koef,res);
                    }
                }
                flag_ans=1;


                while(flag_ans)
                {
                    printf("������ ��������� ��� ���� ������?(��-1, ���-0): ");
                    scanf("%d",&flag_ans);
                    if(flag_ans!=0&&flag_ans!=1)
                    {
                        printf("������ �������������� �����");
                        flag_ans=1;
                    }
                    else
                    {
                        flag_ans_r=flag_ans;
                        flag_ans=0;

                    }
                }
            }
            free(res);

            break;
        case 6:
            test_mlt();


        default:
            printf("������ �������������� �����");
            flag_rep=1;
            break;
        }

    };


    free(mat1);
    free(mat2);


    return 0;
}






//***************************************//
struct Matrix *create(int e_size,int size)
{
    struct Matrix *mtrx = (struct Matrix*)malloc(sizeof(struct Matrix));
    mtrx->element_size=e_size;
    mtrx->size=size;
    mtrx->matrix=malloc(size*size*e_size);
    for(int i=0;i<size*size*e_size;i++)
        *(char*)((char*)mtrx->matrix + i)=0;
    return mtrx;
}

struct Matrix *create_ed(int e_size,int size)
{
    struct Matrix *mtrx = create(e_size,size);
        for(int i=0; i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(e_size==4)
            {
                if(i==j)
                    *((int*)mtrx->matrix+i+size*j)=1;
                else
                    *((int*)mtrx->matrix+i+size*j)=0;
            }
            else if(e_size==32)
            {
                if(i==j)
                    *((float*)mtrx->matrix+i+size*j)=1;
                else
                    *((float*)mtrx->matrix+i+size*j)=0;
            }
            else
                printf("�� ������ ������ ������");
        }
    }
    return mtrx;
}

void fill_mat(struct Matrix* m1)
{
    if(m1->element_size==4)
    {
        for(int i=0; i<m1->size*m1->size; i++)
        {
            scanf("%d",((int*)m1->matrix+i));
        }
    }
    else
    {
        for(int i=0; i<m1->size*m1->size; i++)
        {
            scanf("%f",((float*)m1->matrix+i));
        }
    }

}


void print_mat(struct Matrix* m1)
{
    if(m1->element_size==4)
    {
        for(int i=0; i<m1->size*m1->size; i++)
        {
            printf("%d ",*((int*)m1->matrix + i) );
            if((i+1)%m1->size==0)
                printf("\n");
        }
    }
    else
    {
        for(int i=0; i<m1->size*m1->size; i++)
        {
            printf("%f ",*((float*)m1->matrix + i) );
            if((i+1)%m1->size==0)
                printf("\n");
        }
    }
}


void multiplication(struct Matrix* m1, struct Matrix* m2,struct Matrix *res)
{

    if (m1->element_size==4)
    {
            for(int j=0;j<m1->size;j++)
            {
                for(int l=0;l<m1->size;l++)
                {
                    int el=0;
                    for(int i=0; i<m1->size;i++)
                        el+=*((int*)m1->matrix +j*m1->size+i)*(*((int*)m2->matrix +i*m2->size+l));
                    *((int*)res->matrix+j*m1->size+l)=el;

                }
            }
     }
    else
    {
        for(int j=0;j<m1->size;j++)
        {
            for(int l=0;l<m1->size;l++)
            {
                float el=0;
                for(int i=0; i<m1->size;i++)
                    el+=*((float*)m1->matrix +j*m1->size+i)*(*((float*)m2->matrix +i*m2->size+l));
                *((float*)res->matrix+j*m1->size+l)=el;

            }

        }
    }
    print_mat(res);

}

void addition(struct Matrix* m1, struct Matrix* m2,struct Matrix *res)
{

     if (m1->element_size==4)
     {
         for(int k=0;k<res->size*res->size;k++)
             *((int*)res->matrix+k)=*((int*)m1->matrix+k)+(*((int*)m2->matrix+k));
     }
     else
     {
         for(int k=0;k<res->size*res->size;k++)
             *((float*)res->matrix+k)=*((float*)m1->matrix+k)+(*((float*)m2->matrix+k));
     }

     print_mat(res);

}

void scalar_multiplication(struct Matrix* m1, float scalar,struct Matrix *res)
{

     if (m1->element_size==4)
     {
         for(int k=0;k<res->size*res->size;k++)
             *((int*)res->matrix+k)=(int)(((float)*((int*)m1->matrix+k))*scalar);
     }
     else
     {
         for(int k=0;k<res->size*res->size;k++)
             *((float*)res->matrix+k)=*((float*)m1->matrix+k)*scalar;
     }

     print_mat(res);

}
void transpose(struct Matrix* m1,struct Matrix *res)
{


        if (m1->element_size==4)
        {
            for(int j=0; j<m1->size;j++)
            {
               for(int i=0; i<m1->size;i++)
               {
                   *((int*)res->matrix+i*res->size+j)=*((int*)m1->matrix+j*m1->size+i);
               }

            }
        }
        else
        {
            for(int j=0; j<m1->size;j++)
            {
               for(int i=0; i<m1->size;i++)
               {
                   *((float*)res->matrix+i*res->size+j)=*((float*)m1->matrix+j*m1->size+i);
               }

            }
        }
    print_mat(res);
}

void lines_addition(struct Matrix* m1, int num_i, int num_p, float kof,struct Matrix *res )
{
     struct Matrix* el_mat=create_ed(m1->element_size,m1->size);

     if(el_mat->element_size==4)
     {
         *((int*)el_mat->matrix+(num_p-1)+el_mat->size*(num_i-1))+=(int)kof;
     }
     else
     {
         *((float*)el_mat->matrix+(num_p-1)+el_mat->size*(num_i-1))=kof;
     }

     multiplication(el_mat,m1,res);




}


struct Matrix *create_test(int e_size, int size)
{
    struct Matrix *test;

    test=create(e_size,size);
    if(e_size==4)
    {
        for(int i=0;i<size*size;i++)
        {
            *((int*)test->matrix+i)=i;
        }
    }
    else if(e_size==32)
    {
        for(int i=0;i<size*size;i++)
        {
            *((float*)test->matrix+i)=i;
        }
    }

    return test;

}

void test_mlt(void)
{
    struct Matrix *m1,*m2,*res;
    int flag=0;
    int res_2[4]={2,3,6,11};
    int res_3[9]={15,18,21,42,54,66,69,90,111};
    // test int
    m1=create_test(4,3);
    print_mat(m1);
    printf("\n");
    m2=create_test(4,3);
    print_mat(m2);
    printf("\n");
    res=create(4,3);
    multiplication(m1,m2,res);
    for(int i=0;i<res->size*res->size;i++)
    {
        if(*((int*)res->matrix+i)!=res_3[i])
            flag++;
    }
    if (flag>0)
        printf("false\n");
    else {
        printf("true\n");
    }
    free(m1);
    free(m2);
    free(res);

    m1=create_test(4,2);
    print_mat(m1);
    printf("\n");
    m2=create_test(4,2);
    print_mat(m2);
    printf("\n");
    res=create(4,2);
    multiplication(m1,m2,res);
    for(int i=0;i<res->size*res->size;i++)
    {
        if(*((int*)res->matrix+i)!=res_2[i])
            flag++;
    }
    if (flag>0)
        printf("false\n");
    else {
        printf("true\n");
    }
    free(m1);
    free(m2);
    free(res);

    //���� ��� float
    m1=create_test(32,3);
    print_mat(m1);
    printf("\n");
    m2=create_test(32,3);
    print_mat(m2);
    printf("\n");
    res=create(32,3);
    multiplication(m1,m2,res);
    for(int i=0;i<res->size*res->size;i++)
    {
        if(*((float*)res->matrix+i)!=(float)res_3[i])
            flag++;
    }
    if (flag>0)
        printf("false\n");
    else {
        printf("true\n");
    }
    free(m1);
    free(m2);
    free(res);

    m1=create_test(32,2);
    print_mat(m1);
    printf("\n");
    m2=create_test(32,2);
    print_mat(m2);
    printf("\n");
    res=create(32,2);
    multiplication(m1,m2,res);
    for(int i=0;i<res->size*res->size;i++)
    {
        if(*((float*)res->matrix+i)!=(float)res_2[i])
            flag++;
    }
    if (flag>0)
        printf("false\n");
    else {
        printf("true\n");
    }
    free(m1);
    free(m2);
    free(res);







}



