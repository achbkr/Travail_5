#include <stdio.h>

struct Date {
    int JJ, MM, AA;
};

// pour sairir les dates
void saisir_date(struct Date *date);
// pour trier les dates 
void sort_dates(struct Date *dates, int n);
// calculer la difference ente deux dates
void time_diffrence(struct Date *date_1,struct Date *date_2);

int main() {
    int n;
    printf("Donnez le nombre de dates vous voulez saisir : \n");
    scanf("%d", &n);

    struct Date tab_dates[n];
    for (int i = 0; i < n; i++) {
        printf("Date numero %d :\n", i + 1);
        saisir_date(&tab_dates[i]);
    }

    sort_dates(tab_dates, n);

    printf("Les dates triees sont:\n");
    for (int i = 0; i < n; i++) {
        printf("%d/%d/%d\n", tab_dates[i].JJ, tab_dates[i].MM, tab_dates[i].AA);
    }
    time_diffrence(&tab_dates[0],&tab_dates[1]);

    return 0;
}

void saisir_date(struct Date *date) {
    printf("JJ :\n");
    scanf("%d", &date->JJ);
    printf("MM :\n");
    scanf("%d", &date->MM);
    printf("AA :\n");
    scanf("%d", &date->AA);
    printf("La date que vous avez saisie est : %d/%d/%d\n", date->JJ, date->MM, date->AA);
}

void sort_dates(struct Date *dates, int n) {
    struct Date tmp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dates[i].AA > dates[j].AA || 
                (dates[i].AA == dates[j].AA && dates[i].MM > dates[j].MM) || 
                (dates[i].AA == dates[j].AA && dates[i].MM == dates[j].MM && dates[i].JJ > dates[j].JJ)) {
                tmp = dates[i];
                dates[i] = dates[j];
                dates[j] = tmp;
            }
        }
    }
}


void time_diffrence(struct Date *date_1,struct Date *date_2){
    struct Date difference;
    int N_Jours;
    difference.AA = date_1->AA - date_2->AA;
    difference.MM = date_1->MM - date_2->MM;
    difference.JJ = date_1->JJ - date_2->JJ;
    if(difference.AA < 0){
      difference.AA = -difference.AA;
    }
    if(difference.MM < 0){
        difference.MM = difference.MM +12;
    }
    if(difference.JJ < 0){
        difference.JJ = difference.JJ + 30 ;
    }
    N_Jours = difference.AA * 365 + difference.MM * 30 + difference.JJ ;
    printf("La difference entre les deux dates est : %d",N_Jours);


}