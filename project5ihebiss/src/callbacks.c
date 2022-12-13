#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "bureaudevote.h"


#include "callbacks.h"
#include "interface.h"
#include "support.h"

int x=0;
int y=0;
int valid_confirm=0;
bureaudevote e;

void
on_buttongestinbvajouter_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *bureau;
bureau=lookup_widget(button,"window1gestionbv");
gtk_widget_destroy(bureau);
GtkWidget *ajouter ;
ajouter = create_window2ajouterbv ();
  gtk_widget_show (ajouter);
}


void
on_buttongestinbvmodifier_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *gestionbv;
gestionbv=lookup_widget(button,"window1gestionbv");
gtk_widget_destroy(gestionbv);
GtkWidget *modifier;
modifier = create_window3modifier__bv ();
  gtk_widget_show (modifier);


GtkWidget* msgId=lookup_widget(modifier,"label28");
gtk_label_set_text(GTK_LABEL(msgId),e.id);
                gtk_widget_show(msgId);

gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"entry3")),e.numerodebureau);

if (strcmp(e.capacite,"40")==0){
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (lookup_widget(modifier,"radiobutton_modif1")),TRUE);
}
else if (strcmp(e.capacite,"20")==0){
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (lookup_widget(modifier,"radiobutton_modif2")),TRUE);
}
else if (strcmp(e.capacite,"10")==0){
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (lookup_widget(modifier,"radiobutton_modif3")),TRUE);
}


gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(modifier,"spinbutton4")),e.d.jour);

gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(modifier,"spinbutton5")),e.d.annee);





}


void
on_buttongestionbvsupprimer_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

char z[30];


strcpy(z,e.id);
	supprimer_bv(z);

GtkWidget *treeview1_bv;
GtkWidget *afficher_bv;
afficher_bv=lookup_widget(button,"window1gestionbv");
treeview1_bv=lookup_widget(afficher_bv,"treeview1");
afficher_bureau(treeview1_bv);
}


void
on_buttonretourgestionbv_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobuttonajouter10_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobuttonajouter20_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobuttonajouter40_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonajouterok_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
bureaudevote bv;
int o=0,b=1;
GtkWidget *entrybureau, *entryId , *entryCapacite, *entryJour, *entryMois ,*entryAnnee ;

GtkWidget *e_id_bv;
GtkWidget *label33_id;
GtkWidget *label32_numbureau;

e_id_bv=lookup_widget(button,"e_id_bv");
label33_id=lookup_widget(button,"label33_id");
label32_numbureau=lookup_widget(button,"label32_numbureau");


entrybureau=lookup_widget(button,"entry1");
entryId=lookup_widget(button,"entry2");

entryJour=lookup_widget(button,"spinbutton1");
entryMois=lookup_widget(button,"comboboxentry1");
entryAnnee=lookup_widget(button,"spinbutton3");


strcpy(bv.numerodebureau,gtk_entry_get_text(GTK_ENTRY(entrybureau) ) );
strcpy(bv.id,gtk_entry_get_text(GTK_ENTRY(entryId) ) );
 if (x==1){
strcpy(bv.capacite,"40");}
else 
if (x==2){
strcpy(bv.capacite,"20");}
else
if (x==3){
strcpy(bv.capacite,"10");}


bv.d.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryJour));
strcpy(bv.d.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryMois)));
bv.d.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryAnnee));




if (veridId_bv(bv.id)==1)
{o=1;
gtk_widget_show(e_id_bv);
}
else 
{o=0;
gtk_widget_hide(e_id_bv);
}
if(strcmp(bv.id,"")==0){
		  gtk_widget_show (label33_id);
b=0;
}
else {
		  gtk_widget_hide(label33_id);
}
if(strcmp(bv.numerodebureau,"")==0){
		  gtk_widget_show (label32_numbureau);
b=0;
}
else {
		  gtk_widget_hide(label32_numbureau);
}


if(b==1){

if(o==0){
 

	ajout_bureau(bv);


GtkWidget *ajouter1;
ajouter1=lookup_widget(button,"window2ajouterbv");
gtk_widget_destroy(ajouter1);
GtkWidget *bureaudevote;
bureaudevote = create_window1gestionbv();
  gtk_widget_show (bureaudevote);

}
}
}

void
on_buttonrechercheajouterbv_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonannuler_modifier_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier_bv;
modifier_bv=lookup_widget(button,"window3modifier__bv");
gtk_widget_destroy(modifier_bv);
GtkWidget *afficher_bv;
afficher_bv = create_window1gestionbv ();
  gtk_widget_show (afficher_bv);
}


void
on_buttonok_modifier_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

bureaudevote b;

GtkWidget *entrybureau, *entryId , *entryCapacite, *entryJour, *entryMois ,*entryAnnee ;




entrybureau=lookup_widget(button,"entry3");


entryJour=lookup_widget(button,"spinbutton4");
entryMois=lookup_widget(button,"comboboxentry2");
entryAnnee=lookup_widget(button,"spinbutton5");


strcpy(b.numerodebureau,gtk_entry_get_text(GTK_ENTRY(entrybureau) ) );
strcpy(b.id,e.id);
 if (y==1){
strcpy(b.capacite,"40");}
else 
if (y==2){
strcpy(b.capacite,"20");}
else
if (y==3){
strcpy(b.capacite,"10");}


b.d.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryJour));
strcpy(b.d.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryMois)));
b.d.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryAnnee));
if(valid_confirm==1)
{
modifier_bv(b);
GtkWidget *modifier;
modifier=lookup_widget(button,"window3modifier__bv");
gtk_widget_destroy(modifier);

GtkWidget *gestionbv;
gestionbv = create_window1gestionbv ();
gtk_widget_show (gestionbv);
}

}


void
on_afficher1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview1_bv;
GtkWidget *afficher_bv;
afficher_bv=lookup_widget(button,"window1gestionbv");
treeview1_bv=lookup_widget(afficher_bv,"treeview1");
afficher_bureau(treeview1_bv);
}


void
on_radiobuttonajouter40_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}


void
on_radiobuttonajouter20_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}


void
on_radiobuttonajouter10_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=3;}
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

	gchar* numBV;
        gchar* id;
	gchar* capacite;
	gchar* jour;
	gchar* mois;
	gchar* annee;
	
	
	bureaudevote bv;
      
       GtkTreeIter iter;
	
	

	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0 ,  &numBV, 1, &id,2,&capacite,3,&jour,4,&mois,5,&annee,-1);
	strcpy(e.id,id);
	strcpy(e.numerodebureau,numBV);
	strcpy(e.capacite,capacite);
	e.d.jour=jour;
	e.d.annee=annee;
	
	
	 

	
	}
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active( (togglebutton)))
{valid_confirm=1;}
}


void
on_radiobutton_modif1_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=1;}
}


void
on_radiobutton_modif2_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=2;}
}


void
on_radiobutton_modif3_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=3;}
}


void
on_checkbutton_modif1_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
{valid_confirm=1;}
else
{valid_confirm=0;}
}


void
on_button_recherche_bv_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cherch;
char ch[20];
GtkWidget *treeview1_b;
GtkWidget *afficher_b;
afficher_b=lookup_widget(button,"window1gestionbv");

treeview1_b=lookup_widget(afficher_b,"treeview1");
cherch = lookup_widget (button ,"entry_recherche_bv");
strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherch)));
 rechercher_bureau(treeview1_b,ch);
}


void
on_button_retour_ajouter_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_bv;
ajouter_bv=lookup_widget(button,"window2ajouterbv");
gtk_widget_destroy(ajouter_bv);
GtkWidget *afficher_bv;
afficher_bv = create_window1gestionbv ();
  gtk_widget_show (afficher_bv);
}


void
on_button_taux_obs_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

float tn ;
float te;
char chnb[10];
char chnb1[10];
GtkWidget *nbResultat;
GtkWidget *nbResultat1;
taux(&te,&tn);
	printf("%f",te);
	printf("%f",tn);
sprintf(chnb,"%f",te);
sprintf(chnb1,"%f",tn);
        
nbResultat=lookup_widget(button,"label_te");
nbResultat1=lookup_widget(button,"label_tn");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);
gtk_label_set_text(GTK_LABEL(nbResultat1),chnb1);
gtk_widget_show (nbResultat);
gtk_widget_show (nbResultat1);
}


void
on_button_stat_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_bv;
ajouter_bv=lookup_widget(button,"window1gestionbv");
gtk_widget_destroy(ajouter_bv);
GtkWidget *afficher_bv;
afficher_bv = create_window4_stat ();
  gtk_widget_show (afficher_bv);
}


void
on_button_retour_stat_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *statt;
statt=lookup_widget(button,"window4_stat");
gtk_widget_destroy(statt);
GtkWidget *afficher_bv;
afficher_bv = create_window1gestionbv ();
  gtk_widget_show (afficher_bv);
}


void
on_button1_afficher_stat_gagne_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1_bv;
GtkWidget *afficher_bv;
afficher_bv=lookup_widget(button,"window4_stat");
treeview1_bv=lookup_widget(afficher_bv,"treeview_candidat_gagne");
cond_gagn();
afficher_candidat_gagnant(treeview1_bv);
}

