#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int buttonalas = 10;       // alas painikkeen määritys
int buttonState = 0;

int kerrat = 0;         // aloitus vain kerran

int A = 20;           //A vihollisen alkuarvo rivit
int a = 3;

int hipi = 0;
int pi = 0;           //pisteet

int hyp = 0;          //hyppymittari

int alkuN = 0;          //alku nappi

int nopeus = 150;       //A:n nopetutus

int hyp2 = 0;     //hyppymittari fix

int hyp3 = 0;      // hyppymittari fix 2

int ani = 22;
int anipg = 25;
int asd = 1;
int lul = 1;



//ALOTUKSEN MÄÄRITYS

void setup()
{
  pinMode(buttonalas, INPUT);   //määritetyt
  lcd.begin(20, 4);
}








void alku()
{ // alku button

  if (ani == 22 && anipg == 25) {
    do {
      lcd.setCursor(--ani, 0);
      lcd.print("The Glorious       ");

      lcd.setCursor(--anipg, 1);
      lcd.print("P Game       ");


    } while (ani > 1 && anipg > 5);
  }

  if (lul == 1) {
    do {
      delay(3000);
      lul = 0;
    } while (lul == 1);
  }
  lul = 0;

  if (asd == 1) {
    do {
      lcd.clear();
      asd = 0;
    } while (asd == 1);
  }

  asd = 0;
  ani = 0;
  anipg = 0;


  do
  {

    if (digitalRead(buttonalas) == HIGH)
    {
      ++alkuN;

    }



    if (digitalRead(buttonalas) == LOW && alkuN == 0)
    {
      lcd.setCursor(0, 0);
      lcd.print("PAINA NAPPIA");

      lcd.setCursor(0, 1);
      lcd.print("ALOITTAAKSESI");
    }



  } while (alkuN <= 1);
}






void laskuri()
{

  if (kerrat < 1)
  {


    //ALOITUS

    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("PELI");
    lcd.setCursor(5, 1);
    lcd.print("ALKAA: ");
    lcd.print("5");
    delay(500);
    lcd.setCursor(12, 1);
    lcd.print("4");
    delay(500);
    lcd.setCursor(12, 1);
    lcd.print("3");
    delay(500);
    lcd.setCursor(12, 1);
    lcd.print("2");
    delay(500);
    lcd.setCursor(12, 1);
    lcd.print("1");
    delay(500);
    lcd.clear();

    //hahmon lisäys
    lcd.setCursor(1, 3);
    lcd.print("P");


    kerrat++;         //alotus loppuu

    lcd.setCursor(14, 0);
    pi = 0;
    lcd.print(pi);
    A = 20;
    hyp = 0;
  }

}










//PELI



void peli()
{
  //A alkaa alusta ja Pisteet
  if (A == 0)
  {
    A = 20;
    nopeus = nopeus - 5;
    lcd.setCursor(14, 0);
    lcd.print(++pi);
  }


 // lcd.setCursor(7, 0);          //hyppymittari näkyy
 // lcd.print(hyp);




  //A LIIKUNTA PART I

  // do{

  lcd.setCursor(--A, a);
  lcd.print("A");
  delay(nopeus);       //A lisäys LISÄNOPEUS MUUTTUJALLA
  lcd.setCursor(A, a);
  lcd.print(" ");
  //A poisto

  //A LIIKUNTA PÄÄTTYY PART I









  //P LIIKUNTA YLÖS





  if (digitalRead(buttonalas) == HIGH && hyp < 4)
  { //PAINAT NAPPIA JA HYP ON PIENEMPI KUIN 4
    ++hyp;
    delay(10);
  }



  if (digitalRead(buttonalas) == HIGH && hyp == 1 && hyp2 == 0 ) {         //PAINAT NAPPIA JA HYP ON 1
    lcd.setCursor(1, 3);
    lcd.print(" ");       //tuhoaa alakerran
    lcd.setCursor(1, 2);
    lcd.print("P");
    delay(10);
  }

  if (digitalRead(buttonalas) == HIGH && hyp == 2 && hyp2 == 0) {         //PAINAT NAPPIA JA HYP ON 2
    lcd.setCursor(1, 3);
    lcd.print(" ");       //tuhoaa alakerran
    lcd.setCursor(1, 2);
    lcd.print(" ");
    lcd.setCursor(1, 1);
    lcd.print("P");
    delay(10);
  }

  if (digitalRead(buttonalas) == HIGH && hyp == 3 && hyp2 == 0) {         //PAINAT NAPPIA JA HYP ON 3
    lcd.setCursor(1, 3);
    lcd.print(" ");       //tuhoaa alakerran
    lcd.setCursor(1, 2);
    lcd.print("P");
    lcd.setCursor(1, 1);
    lcd.print(" ");
    delay(10);
    ++hyp3;
  }

  if (digitalRead(buttonalas) == HIGH && hyp == 4) {         //PAINAT NAPPIA JA HYP ON 2
    lcd.setCursor(1, 3);
    lcd.print(" ");       //tuhoaa alakerran
    lcd.setCursor(1, 2);
    lcd.print(" ");
    lcd.setCursor(1, 1);
    lcd.print(" ");
    delay(10);
    
  }







  //P LIIKUNTA ALAS


  if (digitalRead(buttonalas) == LOW)
  { //ET PAINA NAPPIA. --HYP
    --hyp;

    if (hyp < 0)
    { //hyp ei mene negatiiviseksi
      hyp = 0;
    }
    delay(10);
  }







  

  if (digitalRead(buttonalas) == LOW && hyp == 1 && hyp2 == 0 && hyp3 ==0) {      //ET PAINA NAPPIA JA HYP=2 JA HYP2=0 hyp3 = ei taphadu samaa aikaa ku highhyp4
    lcd.setCursor(1, 1);
    lcd.print(" ");   //JOS HYPPYMITTARI = 5 LAGFIX

    lcd.setCursor(1, 2);
    lcd.print("P");
    delay(10);
  }


   if (digitalRead(buttonalas) == LOW && hyp == 2 && hyp2 == 0 && hyp3 ==1) {      //ET PAINA NAPPIA JA HYP=2 JA HYP2=0 hyp3 = ei taphadu samaa aikaa ku highhyp4
    lcd.setCursor(1, 1);
    lcd.print(" ");   //JOS HYPPYMITTARI = 5 LAGFIX

    lcd.setCursor(1, 2);
    lcd.print(" ");
      lcd.setCursor(1, 3);
    lcd.print("P");
    delay(10);
  }

  if (digitalRead(buttonalas) == LOW && hyp == 1 && hyp2 == 0 && hyp3 ==1) {      //ET PAINA NAPPIA JA HYP=2 JA HYP2=0 hyp3 = ei taphadu samaa aikaa ku highhyp4
    lcd.setCursor(1, 1);
    lcd.print(" ");   //JOS HYPPYMITTARI = 5 LAGFIX

    lcd.setCursor(1, 2);
    lcd.print(" ");
    delay(10);
  }





  if (digitalRead(buttonalas) == LOW && hyp == 0) {           //ET PAINA NAPPIA JA HYP = 0 JOTEN HYP=0

    lcd.setCursor(1, 1);
    lcd.print(" ");
    lcd.setCursor(1, 2);
    lcd.print(" ");
    lcd.setCursor(1, 3);
    lcd.print("P");
    delay(10);
    hyp2 = 0;
    hyp3 = 0;
  }




  // P HYPPYMITTARI

  if (hyp == 4)                                                 //HYP=5 JOTEN HYP2=1
  {

    lcd.setCursor(1, 1);
    lcd.print(" ");
    lcd.setCursor(1, 2);
    lcd.print(" ");        //tuhoaa yläkerran

    lcd.setCursor(1, 3);
    lcd.print("P");
    ++hyp2;



    //lcd.setCursor(7, 0);
    //lcd.print(hyp);     //<--hyppymittari livenä
  }

  //P LIIKUNTA PÄÄTTYY




















  //PELI OHI



  if (digitalRead(buttonalas) == LOW && A == 3 || digitalRead(buttonalas) == HIGH && A == 3 && hyp >= 4)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("PELI OHI");
    lcd.setCursor(0, 1);
    lcd.print("Pisteet: ");
    lcd.setCursor(8, 1);
    lcd.print(pi);
    delay(2000);
    lcd.clear();
    kerrat = 0;        //alku tulee uudestaa
    alkuN = 0;
    nopeus = 150;




    if (pi > hipi)
    { //hipi (highscore pisteet) tekeminen
      hipi = pi;
      lcd.setCursor(0, 0);
      lcd.print("UUSI ENNATYS!");
      delay(2000);
      lcd.clear();
    }

    //TULOSTUS
    lcd.setCursor(0, 0);
    lcd.print("Pisteet: ");
    lcd.setCursor(8, 0);
    lcd.print(pi);



    lcd.setCursor(3, 1);
    lcd.print("HIGHSCORE");
    lcd.setCursor(13, 1);
    lcd.print(hipi);

    delay(2000);
    lcd.clear();
  }


}










void loop()      //game
{

  alku();
  laskuri();
  peli();


}








//https://www.youtube.com/watch?v=YWzCMtw3laI
//https://create.arduino.cc/projecthub/anime/ninja-dollar-lcd-game-7234fe?ref=similar&ref_id=103199&offset=3
