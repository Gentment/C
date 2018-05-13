#include <stdio.h>


class Book
{
char Book Name[20];
char ISBN[20];
char Writer[20];
char Publisher[20];
char BriefIntroduction[100];
int i_o;
Book *next;
};


class BookList{
public:
	Book* node,*head_ptr;

	BookList()
	{

		node = new Book[sizeof(Book)] ;
		head_ptr = NULL;
		node->next = NULL;
	}
void save_file();  

void load_file();

void AddNewBook();

void Add_list(Book *p);
};


void BookList::save_file()  
{  
	std::ofstream outfile;  
	outfile.open("book.txt"); //创建、打开文件  

	for(unsigned int x = 0; x < N; x++)  
	{  
		for(unsigned int y = 0; y < M; y++)  
		{  
			outfile<<book[x * N + y]<<" "; //写入数据  
		}  
		outfile<<std::endl;  
	}  
	outfile.close(); //关闭文件  

}  



void BookList::load_file()
{  
	fstream in;  
	in.open("book.txt"); //打开文件  
	//逐字符读取  
	char c;  
	while(!in.eof())  
	{  
		in>>c;//读取字符  

		//其他操作  
	}  

	//逐行读取  
	string str;  
	while(getline(in,str))  
	{  
		//其他操作  
	}  

	in.close();//关闭文件  
}  

void BookList::AddNewBook()
{


}


void BookList::Add_list(Book *p){
	if(head_point==NULL){
		p=new Book;
		p=head_ptr;
		p->next=NULL;
	}
	else{
		node=head_ptr;
		while(node->next!=NULL)
			node=node->next;
		p=node->next;
		p=node;

	}	
}

