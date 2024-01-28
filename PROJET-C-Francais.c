#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
/*structers*/
//struct for members
typedef struct {
	int id;
	int nmb_doc;
	char last_name[50];
	char first_name[50];
	int role;//3=teacher 2=students 1=visitor
	char adress[100];
	int late;
}member;
member members[1000]={
		{10000,1,"Boudokhane","Seif",2,"seifboudokhane@gmail.com",0},
		{10001,1,"Boudokhane","Ahmed",1,"seifboudokhane@gmail.com",0},
		{10002,1,"Boudokhane","Anis",3,"seifboudokhane@gmail.com",0}
	};int nmb_user=2;
//struct for books
typedef struct {
	char code[9];
	char add_date[20];
	int room;
	int line;
	char name_writer[100];
	char name_editor[100];
	int nmb_copies;
	int nmb_loans;
	char title[100];
}book;

book books[1000]={
		{"BK-0","4/7/2003",1,1,"Jhoan Doe","Jane Doe",3,1,"Advanced C"},
		{"BK-1","4/7/2003",1,2,"Jhoan Doe","Jane Doe",3,0,"The art of C programming"},
		{"BK-2","4/7/2003",1,3,"Jhoan Doe","Jane Doe",3,0,"Advanced C Techniques"}
	};int nmb_book=2;
//struct for magazines
typedef struct {
	char code[9];
	int room;
	int line;
	char title[100];
	int nmb_copies;
	int nmb_loans;
	char frq[20];
}magazine;

magazine magazines[1000]={
		{"MZ-0",2,1,"Nature",5,1,"monthly"},
		{"MZ-1",2,1,"Discover",2,0,"weekly"},
		{"MZ-2",2,1,"National Geography",6,0,"daily"}
	};int nmb_maga=2;
//struct for articles
typedef struct {
	char code[9];
	char add_date[20];
	int room;
	int line;
	char name_writer[100];
	int nmb_copies;
	int nmb_loans;
	char title[100];
}article;

article articles[1000]={
		{"ART-0","4/7/2003",1,1,"Thomas S. Kuhn",7,1,"The Structure of Scientific Revolutions"},
		{"ART-1","4/7/2003",1,2,"Stephen Hawking",5,0,"A Brief History of Time"},
		{"ART-2","4/7/2003",1,3,"The Selfish Gene",8,0,"The Selfish Gene"}
	};int nmb_arti=2;
//struct for loan slip
typedef struct{
	char doc_title[100];
	char code_doc[20];
	char name_borrower[100];
	int id_borrower;
	char borrow_date[20];
	char due_date[20];
}slip;

slip slips[3000]={
	{"Advanced C","BK-0","Seif Boudokhane",10000,"9/12/2022","30/12/2021"},
	{"Nature","MZ-0","Ahmed Boudokhane",10001,"4/7/2022","11/7/2023"},
	{"Thomas S. Kuhn","ART-0","Anis Boudokhane",10002,"9/12/2022","14/8/2021"}
};int nmb_slip=2;

//functions
//funtion that compares two strings
int compare(char name1[20], char name2[20]) {
	int i;
    if (strlen(name1) != strlen(name2)) {
        return 0;
    }

    for (i = 0; i < strlen(name1); i++) {
        if (tolower(name1[i]) != tolower(name2[i])) {
            return 0;
        }
    }

    return 1;
}
//functions that displays
void display_slip(int i){
	printf("le titre et le code du document emprunte:\t%s -- %s\n",slips[i].doc_title ,slips[i].code_doc);
	printf("le nom et l'identifiant de l'Emprunteur :\t%s -- %d\n",slips[i].name_borrower,slips[i].id_borrower);
	printf("la date a laquelle il a ete emprunte:\t%s\n",slips[i].borrow_date);
	printf("la date d'echeance:\t%s\n",slips[i].due_date);
	if(members[slips[i].id_borrower-10000].late==1){
		printf("<-DATE-D'ECHEANCE-PASSEE->\n\n");
		}
	printf("-----------------------------------------------------------------------------------\n");
}
void display_article(int i){
	printf("Titre: %s\n",articles[i].title);
	printf("Nom de l'auteur : %s\n",articles[i].name_writer);
	printf("Date d'edition: %s\n",articles[i].add_date);
	printf("Code: %s\n",articles[i].code);
	printf("Nombre de copies: %d\n",articles[i].nmb_copies);
	printf("Nombre de fois qu'il a ete prete: %d\n",articles[i].nmb_loans);
	printf("Emplacement dans la bibliotheque : Salle %d/Ligne %d\n",articles[i].room,articles[i].line);
	printf("-----------------------------------------------------------------------------------\n");
}
void display_magazine(int i){
	printf("Titre: %s\n",magazines[i].title);
	printf("code: %s\n",magazines[i].code);
	printf("Frequence de publication: %s\n",magazines[i].frq);
	printf("Nombre de copies: %d\n",magazines[i].nmb_copies);
	printf("Nombre de fois qu'il a ete prete : %d\n",magazines[i].nmb_loans);
	printf("Emplacement dans la bibliotheque : SALLE %d/Ligne %d\n",magazines[i].room,books[i].line);
	printf("-----------------------------------------------------------------------------------\n");
}
void display_book(int i){
	printf("Titre: %s\n",books[i].title);
	printf("Nom de l'ecrivain: %s\n",books[i].name_writer);
	printf("Nom de l'editeur: %s\n",books[i].name_editor);
	printf("Date d'edition: %s\n",books[i].add_date);
	printf("Code: %s\n",books[i].code);
	printf("Nombre de copies: %d\n",books[i].nmb_copies);
	printf("Nombre de fois qu'il a ete prete : %d\n",books[i].nmb_loans);
	printf("Emplacement dans la bibliotheque : SALLE %d/Ligne %d\n",books[i].room,books[i].line);
	printf("-----------------------------------------------------------------------------------\n");}
void display_member(int i){
	printf("Nom: %s %s\n",members[i].first_name,members[i].last_name);
	printf("Identifiant: %d\n",members[i].id);
		switch(members[i].role){
			case 1:printf("RÔLE : Un visiteur\n");break;
			case 2:printf("RÔLE : Un etudiant\n");break;
			case 3:printf("RÔLE : Un enseignant\n");break;
		}
	printf("nombre total de Documents pretes: %d\n",members[i].nmb_doc);
	if(members[i].late==1){
		printf("\t!!! RETARD POUR RENVOYER UN DOCUMENT\n");
	}
	
	printf("Adresse email: %s\n",members[i].adress);
	printf("-----------------------------------------------------------------------------------\n");
}
//function that get info
void info_member(int i){
	char ch [100];gets(ch);
	printf("-----INFORMATIONS-MEMBRE-----\n");
	printf("Prenom: ");gets(members[i].first_name);
	printf("Last name: ");gets(members[i].last_name);
	printf("Role:\n");
	printf("\t tapez 1 pour visiteur\n");
	printf("\t tapez 2 pour etudiant\n");
	printf("\t tapez 3 pour professeur\n");
	members[i].role=selection(4);
	printf("Adress: ");scanf("%s",members[i].adress);
	members[i].id=10000+i;
}
void info_book(int i){
	char ch[100];gets(ch);
	printf("-----INFORMATIONS-DU-LIVRE-----\n");
	printf("Titre: ");gets(books[i].title);
	printf("Nom de l'auteur : ");gets(books[i].name_writer);
	printf("Nom de l'editeur : ");gets(books[i].name_editor);
	printf("La date de publication dans ce format JJ/MM/AAAA : ");scanf("%s",&books[i].add_date);
	printf("Nombre d'exemplaires disponibles: ");books[i].nmb_copies=selection(99);
	printf("Emplacement dans la bibliotheque : \n");
	printf("\t Numero de chambre: ");books[i].room=selection(10);
	printf("\t Numero de ligne: ");books[i].line=selection(50);
}
void info_magazine(int i){
	char ch[100];
	printf("-----INFORMATIONS-DU-MAGAZINE-----\n");gets(ch);
	printf("Titre: ");gets(magazines[i].title);
	printf("Frequence de publication : ");scanf("%s",&magazines[i].frq);
	printf("Nombre d'exemplaires disponibles : ");magazines[i].nmb_copies=selection(99);
	printf("Emplacement dans la bibliotheque: \n");
	printf("\t Numero de salle: ");magazines[i].room=selection(10);
	printf("\t Numero de ligne: ");magazines[i].line=selection(50);
}
void info_article(int i){
	char ch[100];gets(ch);
	printf("type: ");gets(articles[i].title);
	printf("Nom de l'ecrivain : ");gets(articles[i].name_writer);
	printf("La date de publication dans ce format JJ/MM/AAAA: ");scanf("%s",&articles[i].add_date);
	printf("Nombre d'exemplaires disponibles : ");articles[i].nmb_copies=selection(99);
	printf("Emplacement dans la bibliotheque: \n");
	printf("\t Numero de chambre: ");articles[i].room=selection(10);
	printf("\t Numero de ligne: ");articles[i].line=selection(50);
}
//functions that deletes
void delete_slip(int code){
	int j;
	for (j=code;j<=nmb_slip;j++){
		slips[j]=slips[j+1];
	}
	nmb_slip=nmb_slip-1;
}
void delete_article(char code_ch[20]){
	int j;int inc;int code;int k;int h;
	int i=0;int id;
	do{
		if(compare(code_ch,slips[i].code_doc)){
			id=slips[i].id_borrower-10000;
			members[id].nmb_doc=members[id].nmb_doc-1;
			delete_slip(i);
			i=i-1;
		}
		i++;
	}while(i<=nmb_slip);
	sscanf(code_ch,"ART-%d",&code);
	
	for (j=code;j<=nmb_arti;j++){
		articles[j]=articles[j+1];
		sscanf(articles[j].code,"ART-%d",&inc);
		inc=inc-1;
		sprintf(articles[j].code,"ART-%d",inc);
	}
	nmb_arti=nmb_arti-1;
	for(k=0;k<=nmb_arti;k++){
		for(h=0;h<=nmb_slip;h++){  
			if(compare(slips[h].doc_title,articles[k].title)){
				strcpy(slips[h].code_doc,articles[k].code);
			}
		}
	}
}
void delete_book(char code_ch[20]){
	int j;int inc;int code;int k;int h;
	int i=0;int id;
	do{
		if(compare(code_ch,slips[i].code_doc)){
			id=slips[i].id_borrower-10000;
			members[id].nmb_doc=members[id].nmb_doc-1;
			delete_slip(i);
			i=i-1;
		}
		i++;
	}while(i<=nmb_slip);
	sscanf(code_ch,"BK-%d",&code);
	
	for (j=code;j<=nmb_book;j++){
		books[j]=books[j+1];
		sscanf(books[j].code,"BK-%d",&inc);
		inc=inc-1;
		sprintf(books[j].code,"BK-%d",inc);
	}
	nmb_book=nmb_book-1;
	for(k=0;k<=nmb_book;k++){
		for(h=0;h<=nmb_slip;h++){
			if(compare(slips[h].doc_title,books[k].title)){
				strcpy(slips[h].code_doc,books[k].code);
			}
		}
	}
}
void delete_magazine(char code_ch[20]){
	int j;int inc;int code;int k;int h;
	int i=0;int id;
	do{
		if(compare(code_ch,slips[i].code_doc)){
			id=slips[i].id_borrower-10000;
			members[id].nmb_doc=members[id].nmb_doc-1;
			delete_slip(i);
			i=i-1;
		}
		i++;
	}while(i<=nmb_slip);
	sscanf(code_ch,"MZ-%d",&code);
	for (j=code;j<=nmb_maga;j++){
		magazines[j]=magazines[j+1];
		sscanf(magazines[j].code,"MZ-%d",&inc);
		inc=inc-1;
		sprintf(magazines[j].code,"MZ-%d",inc);
	}
	nmb_maga=nmb_maga-1;
	for(k=0;k<=nmb_maga;k++){
		for(h=0;h<=nmb_slip;h++){
			if(compare(slips[h].doc_title,magazines[k].title)){
				strcpy(slips[h].code_doc,magazines[k].code);
			}
		}
	}
}
void delete_member(int id){
	int j;char nom[100];int k;int h;
	int i=0;
	do{
		if(id==slips[i].id_borrower){
			delete_slip(i);
			i=i-1;
		}
		i++;
	}while(i<=nmb_slip);
	id=id-10000;
	for (j=id;j<=nmb_user;j++){
		members[j]=members[j+1];
		members[j].id=members[j].id-1;
	}
	nmb_user=nmb_user-1;
	
	for(k=0;k<=nmb_user;k++){
		sprintf(nom,"%s %s",members[k].first_name,members[k].last_name);
		for(h=0;h<=nmb_slip;h++){
			if(compare(nom,slips[h].name_borrower)){
				slips[h].id_borrower=members[k].id;
			}
		}
	}
}
//function that turns a string into uppercase
void make_upper(char *arr) {
	int i;
	// Iterate through each character in the array
	for (i = 0; arr[i] != '\0'; i++) {
	// Convert the character to uppercase using the toupper() function
	// from the ctype.h library
	arr[i] = toupper(arr[i]);
	}
}
//function that checks if the input is a digit
int is_digit(const char* str){
	int i;
    if (str == NULL)
    {
    	return 0;
    }

    // Check if the string consists only of digits
    for ( i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }

    return 1;
}

//function that checks the type of document
//returns: 0=invalid/1=Book/2=Magazine/3=Article
int document_type(char code[20]){
	char ch_code[20];
	make_upper(code);
	if (code[0]=='B'&&code[1]=='K'&&code[2]=='-'){
		sscanf(code,"BK-%s",ch_code);
		if(is_digit(ch_code)){
			if(atoi(ch_code)<=nmb_book){
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			return 0;
		}
		
	}
	else{
		if(code[0]=='M'&&code[1]=='Z'&&code[2]=='-'){
			sscanf(code,"MZ-%s",ch_code);
			if(is_digit(ch_code)){
				if(atoi(ch_code)<=nmb_maga){
				return 2;
				}
				else{
					return 0;
				}
			}
			else{
				return 0;
			}
		}
		else{
			if(code[0]=='A'&&code[1]=='R'&&code[2]=='T'&&code[3]=='-'){
				sscanf(code,"ART-%s",ch_code);
				if(is_digit(ch_code)){
					if(atoi(ch_code)<=nmb_arti){
						return 3;
					}
					else{
						return 0;
					}
				}
				else{
					return 0;
				}		
			}
			else{
				return 0;
			}
		}
	}
}
//function that gets the selection
int selection(int i){
	char select[100];int select_d;
	while(1){
			scanf("%s",select);
			if(is_digit(select)){
				select_d=atoi(select);
				if(select_d>0 && select_d<i){
					break;
				}
				else{
				printf("Entree invalide\n");
				}
			}
			else{
				printf("Entree invalide\n");
			}
		}
	return select_d;
}
//main function
int main(){	
    int search_id;char search_code[20];char search_ans[20];char search_title[100];
    int ans_d1;int ans_d2;char ch[1000];
	int code;int id;
	int i;int j;
	// Get the current time
	time_t t = time(NULL);
	// Convert the time to a struct tm
	struct tm tm = *localtime(&t);
	struct tm tm2 = *localtime(&t);
	//date to compare
	int due_day;
	int due_month;
	int due_year;
	//set to fullscreen
	HWND hWnd = GetConsoleWindow();
  	ShowWindow(hWnd,SW_SHOWMAXIMIZED);
	// Enable ANSI escape codes
	setvbuf(stdout, NULL, _IOFBF, 0);
	// Set the text color to green
	system("mode con: cols=300 lines=300");
	printf("\x1b[32m");
	//main program
	//check if someone is late
	for(i=0;i<=nmb_slip;i++){
		sscanf(slips[i].due_date,"%d/%d/%d",&due_day,&due_month,&due_year);
		id=slips[i].id_borrower-10000;
		if(due_year<tm.tm_year + 1900){
			members[id].late=1;
		}
		else{
			if(due_year==tm.tm_year+1900&&due_month<tm.tm_mon+1){
				members[id].late=1;
			}
			else{
				if(due_year==tm.tm_year+1900&&due_month==tm.tm_mon+1&&due_day<tm.tm_mday){
					members[id].late=1;
				}
			}
		}
	}
	printf("\n\n<--BIENVENUE-A-LA-BIBLIOTHEQUE-D'ISSATSO--->\n\n");
	system("pause");
	//menus
	while(1){
		system("cls");
		printf("\n\ntapez 01 pour ajouter un membre\n");
		printf("tapez 02 pour ajouter un document\n");
		printf("tapez 03 pour supprimer un membre\n");
		printf("tapez 04 pour supprimer un document\n");
		printf("tapez 05 pour modifier un membre\n");
		printf("tapez 06 pour modifier un document\n");
		printf("tapez 07 pour emprunter un document\n");
		printf("tapez 08 pour retourner un document\n");
		printf("tapez 09 pour rechercher un membre\n");
		printf("tapez 10 pour rechercher un document\n");
		printf("tapez 11 pour afficher la liste des membres\n");
		printf("tapez 12 pour afficher la liste des documents\n");
		printf("tapez 13 pour afficher la liste des fiches d’emprunt\n");
		ans_d1=selection(14);
		system("cls");
		switch(ans_d1) {
			case 1://ADD A MEMBER--------------------------------------------------------------------------
				nmb_user++;
				info_member(nmb_user);
				members[nmb_user].nmb_doc=0;
				printf("-->MEMBRE AJOUTE AVEC SUCCES\n");
				system("pause");
				break;
			case 2://ADD A DOCUMENT--------------------------------------------------------------------------
				printf("\n\nQuel type de document souhaitez-vous ajouter ? \n\n");
				printf("tapez 1 pour les livres\n");
				printf("tapez 2 pour les revues scientifiques\n");
				printf("tapez 3 pour les articles scientifiques\n");
				ans_d2=selection(4);
				system("cls");
				switch(ans_d2){
					case 1:
						nmb_book++;
						info_book(nmb_book);
						//giving the book a code
						sprintf(books[nmb_book].code,"BK-%d",nmb_book);
						//initiating the number of loans of a book
						books[nmb_book].nmb_loans=0;
						printf("-->LIVRE AJOUTE AVEC SUCCES\n");
						break;
					case 2:
						nmb_maga++;
						info_magazine(nmb_maga);
						//giving the magazines a code
						sprintf(magazines[nmb_maga].code,"MZ-%d",nmb_maga);
						//initiating the number of loans of a magazines
						magazines[nmb_maga].nmb_loans=0;
						printf("-->MAGAZINE AJOUTE AVEC SUCCES \n");
						break;
					case 3:
						nmb_arti++;
						info_article(nmb_arti);
						//giving the magazines a code
						sprintf(articles[nmb_arti].code,"ART-%d",nmb_arti);
						//initiating the number of loans of an article
						articles[nmb_arti].nmb_loans=0;
						printf("-->ARTICLE AJOUTE AVEC SUCCES\n");
						break;
				}
				system("pause");
				break;
			case 3://DELETE A MEMBER--------------------------------------------------------------------------
				if(nmb_user>=0){
					printf("\n\nQuel est l'identifiant (xxxxx) du membre que vous souhaitez supprimer: \t");
					scanf("%d",&id);
					if(id<11000 && id>=10000 && (id-10000) <=nmb_user){
						delete_member(id);
						printf("-->MEMBRE SUPPRIME AVEC SUCCES\n");
					}
					else{
						printf("-->ENTREE INVALIDE\n");
					}
				}
				else{
					printf("-->Il n'y a pas de membres\n");
				}
				system("pause");
				break;
			case 4://DELETE A DOCUMENT--------------------------------------------------------------------------
				printf("\n\nINDICE DE CODE : LIVRE=(BK-xx) MAGAZINE=(MZ-xx) ARTICLE=(ART-xx)\n\n");
				printf("Le code du document que vous souhaitez supprimer: \t");scanf("%s",&search_ans);
				make_upper(search_ans);
				switch(document_type(search_ans)){
					case 0://invalid input
						printf("-->ENTREE INVALIDE\n");
						break;
					case 1://delete book
						delete_book(search_ans);
						printf("-->LIVRE SUPPRIME AVEC SUCCES\n");
						break;
					case 2://delete magazine
						delete_magazine(search_ans);
						printf("-->MAGAZINE SUPPRIME AVEC SUCCES\n");
						break;
					case 3://delete article
						delete_article(search_ans);
						printf("-->ARTICLE SUPPRIME AVEC SUCCES\n");
						break;
				}
				system("pause");
				break;
			case 5://EDIT A MEMBER--------------------------------------------------------------------------
				printf("\n\nQuel est l'identifiant (xxxxx) du membre que vous souhaitez modifier : \t");
				scanf("%d",&id);
				if(id<11000&&id>=10000&&(id-10000)<=nmb_user){
					//display info
					display_member(id-10000);
					//edit
					info_member(id-10000);
					printf("-->MEMBER EDITED SUCCESSFULLY\n");
				}
				else{
					printf("-->ENTREE INVALIDE\n");
				}
				system("pause");
				break;
			case 6://EDIT A documment--------------------------------------------------------------------------
				printf("\n\nINDICE DE CODE : LIVRE=(BK-xx) MAGAZINE=(MZ-xx) ARTICLE=(ART-xx)\n\n");
				printf("Le code du document que vous souhaitez modifier: \t");scanf("%s",&search_ans);
				make_upper(search_ans);
				switch(document_type(search_ans)){
					case 0://invalid input
						printf("-->ENTREE INVALIDE\n");
						break;
					case 1://edit book
						sscanf(search_ans,"BK-%d",&code);
						display_book(code);
						info_book(code);
						printf("-->LIVRE EDITE AVEC SUCCES\n");
						break;
					case 2://edit magazine
						sscanf(search_ans,"MZ-%d",&code);
						display_magazine(code);
						info_magazine(code);
						printf("-->MAGAZINE EDITE AVEC SUCCES\n");
						break;
					case 3://edit article
						sscanf(search_ans,"ART-%d",&code);
						display_article(code);
						info_article(code);
						printf("-->ARTICLE MODIFIE AVEC SUCCES\n");
						break;
				}
				system("pause");
				break;
			case 7://Borrow a document
				printf("\n\nINDICE DE CODE : LIVRE=(BK-xx) MAGAZINE=(MZ-xx) ARTICLE=(ART-xx)\n\n");
				printf("Le code du document que vous souhaitez emprunter: \t");
				scanf("%s",&search_ans);
				make_upper(search_ans);
				switch(document_type(search_ans)){
					case 1:
						sscanf(search_ans,"BK-%d",&code);
						display_book(code);
						printf("\n\nVous souhaitez emprunter ce livre ?\n\n");
						printf("taper 1 si OUI\n");
						printf("taper 2 si NON\n");
						ans_d2=selection(3);
						if(ans_d2==1){
							printf("\n\nQuel est l'ID (xxxxx) du Membre qui empruntera ce Document: \t");
							scanf("%d",&id);
							if(id<11000&&id>=10000&&(id-10000)<=nmb_user){
									if(members[id-10000].nmb_doc<members[id-10000].role){
									nmb_slip++;
									strcpy(slips[nmb_slip].doc_title,books[code].title);
									strcpy(slips[nmb_slip].code_doc,books[code].code);
									sprintf(slips[nmb_slip].name_borrower,"%s %s",members[id-10000].first_name,members[id-10000].last_name);
									slips[nmb_slip].id_borrower=id;
									sprintf(slips[nmb_slip].borrow_date,"%d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
									
									// Calculate the due date
									tm2.tm_mday = tm.tm_mday + (7*members[id-10000].role);		
									mktime(&tm2);
									sprintf(slips[nmb_slip].due_date,"%d/%d/%d", tm2.tm_mday, tm2.tm_mon + 1, tm2.tm_year + 1900);
									members[id-10000].nmb_doc=members[id-10000].nmb_doc+1;
									books[code].nmb_copies=books[code].nmb_copies-1;
									books[code].nmb_loans++;
									printf("-->DOCUMENT EMPRUNTE AVEC SUCCES\n");
								}
								else{
									printf("-->LE MEMBRE A ATTEINT LE NOMBRE MAXIMAL DE DOCUMENTS AUTORISES\n");
								}
							}
							else{
								printf("-->ENTREE INVALIDE\n");
							}
						}
						break;
					case 2:
						sscanf(search_ans,"MZ-%d",&code);
						display_magazine(code);
						printf("\n\nVoulez-vous emprunter ce magazine?\n\n");
						printf("taper 1 si OUI\n");
						printf("taper 2 si NON\n");
						ans_d2=selection(3);
						if(ans_d2==1){
							printf("\n\nQuel est l'ID (xxxxx) du Membre qui empruntera ce Document : \t");
							scanf("%d",&id);
							if(id<11000&&id>=10000&&(id-10000)<=nmb_user){
									if(members[id-10000].nmb_doc<members[id-10000].role){
									nmb_slip++;
									strcpy(slips[nmb_slip].doc_title,magazines[code].title);
									strcpy(slips[nmb_slip].code_doc,magazines[code].code);
									sprintf(slips[nmb_slip].name_borrower,"%s %s",members[id-10000].first_name,members[id-10000].last_name);
									slips[nmb_slip].id_borrower=id;
									sprintf(slips[nmb_slip].borrow_date,"%d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
									// Calculate the due date
									tm2.tm_mday = tm.tm_mday + (7*members[id-10000].role);		
									mktime(&tm2);
									sprintf(slips[nmb_slip].due_date,"%d/%d/%d", tm2.tm_mday, tm2.tm_mon + 1, tm2.tm_year + 1900);
									members[id-10000].nmb_doc=members[id-10000].nmb_doc+1;
									magazines[code].nmb_copies=magazines[code].nmb_copies-1;
									magazines[code].nmb_loans++;
									printf("-->DOCUMENT EMPRUNTE AVEC SUCCES\n");
								}
								else{
									printf("-->LE MEMBRE A ATTEINT LE NOMBRE MAXIMAL DE DOCUMENTS AUTORISES\n");
								}
							}
							else{
								printf("-->ENTREE INVALIDE\n");
							}
						}
						break;
					case 3:
						sscanf(search_ans,"ART-%d",&code);
						display_article(code);
						printf("\n\nVoulez-vous emprunter cet article ?\n");
						printf("taper 1 si OUI\n");
						printf("taper 2 si NON\n");
						ans_d2=selection(3);
						if(ans_d2==1){
							printf("\n\nQuel est l'identifiant (xxxxx) du membre qui empruntera ce document: \t");scanf("%d",&id);
							if(id<11000&&id>=10000&&(id-10000)<=nmb_user){
								if(members[id-10000].nmb_doc<members[id-10000].role){
									nmb_slip++;
									strcpy(slips[nmb_slip].doc_title,articles[code].title);
									strcpy(slips[nmb_slip].code_doc,articles[code].code);
									sprintf(slips[nmb_slip].name_borrower,"%s %s",members[id-10000].first_name,members[id-10000].last_name);
									slips[nmb_slip].id_borrower=id;
									sprintf(slips[nmb_slip].borrow_date,"%d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
									// Calculate the due date
									tm2.tm_mday = tm.tm_mday + (7*members[id-10000].role);		
									mktime(&tm2);
									sprintf(slips[nmb_slip].due_date,"%d/%d/%d", tm2.tm_mday, tm2.tm_mon + 1, tm2.tm_year + 1900);
									members[id-10000].nmb_doc=members[id-10000].nmb_doc+1;
									articles[code].nmb_copies=articles[code].nmb_copies-1;
									articles[code].nmb_loans++;
									printf("-->DOCUMENT EMPRUNTE AVEC SUCCES\n");
								}
								else{
									printf("-->LE MEMBRE A ATTEINT LE NOMBRE MAXIMAL DE DOCUMENTS AUTORISES\n");
								}
							}
							else{
								printf("-->ENTREE INVALIDE\n");
							}
						}
						break;
						}
				system("pause");
				break;
			case 8://Return a Document
				printf("\n\nINDICE DE CODE : LIVRE=(BK-xx) MAGAZINE=(MZ-xx) ARTICLE=(ART-xx)\n\n");
				printf("Le code du document que vous souhaitez emprunter : \t");scanf("%s",&search_code);
			    make_upper(search_code);
				switch(document_type(search_code)){
					case 1:
						printf("\n\nL'identifiant (xxxxx) de la personne renvoyant le Document : \t");scanf("%d",&id);
						if(id<11000&&id>=10000&&(id-10000)<=nmb_user){
							sscanf(search_code,"BK-%d",&code);
							for(i=0;i<=nmb_slip;i++){
								if(compare(search_code,slips[i].code_doc)&&slips[i].id_borrower==id){
									delete_slip(i);
									books[code].nmb_copies++;
									books[code].nmb_loans=books[code].nmb_loans-1;
									members[id-10000].nmb_doc=members[id-10000].nmb_doc-1;
									printf("-->LIVRE RETOURNE AVEC SUCCES\n");
									break;	
								}
							}
								if(i>nmb_slip){
									printf("-->ENTREE INVALIDE\n");
								}
						}
						else{
							printf("-->ENTREE INVALIDE\n");
						}
						break;
					case 2:
						printf("\n\nL'identifiant (xxxxx) de la personne renvoyant le Document: \t");scanf("%d",&id);
						if(id<11000&&id>=10000&&(id-10000)<=nmb_user){
							sscanf(search_code,"MZ-%d",&code);
							for(i=0;i<=nmb_slip;i++){
								if(compare(search_code,slips[i].code_doc)&&slips[i].id_borrower==id){
									delete_slip(i);
									magazines[code].nmb_copies++;
									magazines[code].nmb_loans=magazines[code].nmb_loans-1;
									members[id-10000].nmb_doc=members[id-10000].nmb_doc-1;
									printf("-->MAGAZINE RETOURNE AVEC SUCCES\n");
									break;	
								}
								if(i>nmb_slip){
									printf("-->ENTREE INVALIDE\n");
								}
							}
						}
						else{
							printf("-->ENTREE INVALIDE\n");
						}
						break;
					case 3:
						printf("\n\nL'identifiant (xxxxx) de la personne renvoyant le Document : \t");scanf("%d",&id);
						if(id<11000&&id>=10000&&(id-10000)<=nmb_user){
							sscanf(search_code,"ART-%d",&code);
							for(i=0;i<=nmb_slip;i++){
								if(compare(search_code,slips[i].code_doc)&&slips[i].id_borrower==id){
									delete_slip(i);
									articles[code].nmb_copies++;
									articles[code].nmb_loans=articles[code].nmb_loans-1;
									members[id-10000].nmb_doc=members[id-10000].nmb_doc-1;
									printf("->ARTICLE RETOURNE AVEC SUCCES\n");
									break;	
								}
								if(i>nmb_slip){
									printf("->ENTREE INVALIDE\n");
								}
							}
						}
						else{
							printf("->ENTREE INVALIDE\n");
						}
						break;
					default:
						printf("->ENTREE INVALIDE\n");
						break;
				}
				system("pause");
				break;
			case 9://SEARCH FOR MEMBER--------------------------------------------------------------------------
				printf("\n\nTapez 1 pour rechercher par ID\n");
				printf("Tapez 2 pour rechercher par prenom\n");
				printf("Tapez 3 pour rechercher par nom de famille\n");
				printf("tapez 4 pour rechercher par role\n");
				ans_d2=selection(5);
				system("cls");
				switch(ans_d2){
					case 1:
						printf("\n\nQuel est l'identifiant (xxxxx) du membre que vous souhaitez rechercher : \t");
						scanf("%d",&search_id);
						if(search_id<11000&&search_id>=10000&&(search_id-10000)<=nmb_user){
							display_member(search_id-10000);
						}
						else{
							printf("->ENTREE INVALIDE\n");
						}
						break;
					case 2:
						printf("\n\nQuel est le prenom de la personne que vous recherchez : ");
						scanf("%s",&search_ans);
						for (i=0;i<=nmb_user;i++){
							if(compare(search_ans,members[i].first_name)){
								display_member(i);
							}
						}
						break;
					case 3:
						printf("\n\nQuel est le nom de famille de la personne que vous recherchez : ");
						scanf("%s",&search_ans);
						for (i=0;i<=nmb_user;i++){
							if(compare(search_ans,members[i].last_name)){
								display_member(i);
							}
						}
						break;
					case 4:
						printf("\n\nTapez 1 pour rechercher des visiteurs\n");
						printf("Tapez 2 pour rechercher des etudiants\n");
						printf("Tapez 3 pour rechercher des professeurs\n");
						ans_d2=selection(4);
						system("cls");
						for (i=0;i<=nmb_user;i++){
							if(ans_d2==members[i].role){
								display_member(i);
							}
						}
				}
				printf("\n");
				system("pause");
				break;
			case 10://search for document
				printf("\n\nTapez 1 pour rechercher par code\n");
				printf("Tapez 2 pour rechercher par titre\n");
				printf("Tapez 3 pour effectuer une recherche par nom d'auteur\n");
				printf("Tapez 4 pour rechercher par nom d'editeur\n");
				printf("tapez 5 pour rechercher par date de publication\n");
				printf("tapez 6 pour rechercher par frequence de publication\n");
				ans_d2=selection(7);
				switch(ans_d2){
					case 1:
						printf("\n\nINDICE DE CODE : LIVRE=(BK-xx) MAGAZINE=(MZ-xx) ARTICLE=(ART-xx)\n\n");
						printf("Le code du document que vous souhaitez rechercher : \t");scanf("%s",&search_code);
			    		switch(document_type(search_code)){
			    			case 0:
			    				printf("-->Code invalide\n");
			    				break;
			    			case 1:
			    				sscanf(search_code,"BK-%d",&code);
			    				display_book(code);
			    				break;
			    			case 2:
			    				sscanf(search_code,"MZ-%d",&code);
			    				display_magazine(code);
			    				break;
			    			case 3:
			    				sscanf(search_code,"ART-%d",&code);
			    				display_article(code);
			    				break;
						}
						break;
					case 2:
						printf("\n\nLe titre du document que vous souhaitez rechercher :");gets(ch);gets(search_title);
						for(i=0;i<=nmb_book;i++){
							if(compare(search_title,books[i].title)){
								display_book(i);
							}
						}
						for(i=0;i<=nmb_maga;i++){
							if(compare(search_title,magazines[i].title)){
								display_magazine(i);
							}
						}
						for(i=0;i<=nmb_arti;i++){
							if(compare(search_title,articles[i].title)){
								display_article(i);
							}
						}
						break;
					case 3:
						printf("\n\nLe nom de l'auteur du document que vous souhaitez rechercher: ");gets(ch);gets(search_title);
						for(i=0;i<=nmb_book;i++){
							if(compare(search_title,books[i].name_writer)){
								display_book(i);
							}
						}
						for(i=0;i<=nmb_arti;i++){
							if(compare(search_title,articles[i].name_writer)){
								display_article(i);
							}
						}
						break;
					case 4:
						printf("\n\nLe nom de l'editeur du document que vous souhaitez rechercher : ");gets(ch);gets(search_title);
						for(i=0;i<=nmb_book;i++){
							if(compare(search_title,books[i].name_editor)){
								display_book(i);
							}
						}
						break;
					case 5:
						printf("\n\nLa date de publication du document que vous souhaitez rechercher JJ/MM/AAAA: ");scanf("%s",search_title);
						for(i=0;i<=nmb_book;i++){
							if(compare(search_title,books[i].add_date)){
								display_book(i);
							}
						}
						for(i=0;i<=nmb_arti;i++){
							if(compare(search_title,articles[i].add_date)){
								display_article(i);
							}
						}
						break;
					case 6:
						printf("\n\nLa frequence de publication du document que vous souhaitez rechercher:");scanf("%s",search_title);
						for(i=0;i<=nmb_maga;i++){
							if(compare(search_title,magazines[i].frq)){
								display_magazine(i);
							}
						}
						break;
				}
				printf("\n");
				system("pause");
				break;
			case 11://DISPLAY LIST OF MEMBERS--------------------------------------------------------------------------
				printf("\n\nTapez 1 pour afficher tous les membres\n");
				printf("Tapez 2 pour afficher les membres en retard\n");
				ans_d2=selection(3);
				system("cls");
				switch(ans_d2){
					case 1:
						printf("\n\n<----LA--LISTE--DES--MEMBRES---->\n\n");
						for (i=0;i<=nmb_user;i++){
								display_member(i);
							}
						break;
					case 2:
						printf("\n\n<----LA--LISTE--DES--DERNIERES-MEMBRES---->\n\n");
						for (i=0;i<=nmb_user;i++){
							if(members[i].late==1){
								display_member(i);
							}
						}
						break;
				}
				
				printf("\n");
				system("pause");
				break;
			case 12://DISPLAY LIST OF DOCUMENTS--------------------------------------------------------------------------
				printf("\n\nQuel type de documents voulez-vous afficher:\n");
				printf("tapez 1 pour les livres\n");
				printf("tapez 2 pour les revues scientifiques\n");
				printf("tapez 3 pour les articles scientifiques\n");
				printf("tapez 4 pour tous\n");
				ans_d2=selection(5);
				system("cls");
				switch(ans_d2){
					case 1:
						printf("\n\n<---------LIVRES--------->\n");
						for (i=0;i<=nmb_book;i++){
							display_book(i);
						}
						printf("\n");
						system("pause");
						break;
					case 2:
						printf("\n\n<---------LES-MAGAZINES--------->\n");
						for (i=0;i<=nmb_maga;i++){
							display_magazine(i);
						}
						printf("\n");
						system("pause");
						break;
					case 3:
						printf("\n\n<---------DES-ARTICLES--------->\n");
						for (i=0;i<=nmb_arti;i++){
							display_article(i);
						}
						printf("\n");
						system("pause");
						break;
					case 4:
						printf("\n\n<----------LIVRES---------->\n");
						for (i=0;i<=nmb_book;i++){
							display_book(i);
						}
						printf("\n\n<---------LES-MAGAZINES--------->\n");
						for (i=0;i<=nmb_maga;i++){
							display_magazine(i);
						}
						printf("\n\n<---------DES-ARTICLES--------->\n");
						for (i=0;i<=nmb_arti;i++){
							display_article(i);
						}
						printf("\n");
						system("pause");
						break;
					}
				break;
			case 13://display list of slips
				printf("\n\nTaper 1 pour afficher tous les feuillets\n");
				printf("Tapez 2 pour afficher la date d'echeance depassee\n");
				ans_d2=selection(3);
				system("cls");
				switch(ans_d2){
					case 1:
						printf("\n\n<----LISTE--DES--FEUILLETS---->\n\n");
						for (i=0;i<=nmb_slip;i++){
							display_slip(i);
						}
						break;
					case 2:
						printf("<----LISTE--DES--FICHES-AVEC-DATE-DATE-PASSEE--->\n\n");
						for (i=0;i<=nmb_slip;i++){
							if(members[slips[i].id_borrower-10000].late==1){
								display_slip(i);
							}	
						}
						break;
				}
				printf("\n");
				system("pause");
				break;
		}
	}
	return 0;
}
