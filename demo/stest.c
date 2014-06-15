/* A simple static test program. */
#include <tfm.h>

#ifdef GBA_MODE
#include <gba.h>
   #define DISPLAY(x) modetxt_puts(vfb, x, 1)
#endif

#ifndef DISPLAY
   #define DISPLAY(x) printf(x)
   #define DISPLAY_P(...) printf(__VA_ARGS__)
#else
   #define DISPLAY_P(...) (void)0
#endif


#ifdef GBA_MODE
int c_main(void)
#else
int main(void)
#endif
{
   fp_int a,b,c,d,e,f;
   fp_digit dp;

   fp_init(&a);
   fp_init(&b);
   fp_init(&c);
   fp_init(&d);
   fp_init(&e);
   fp_init(&f);

#ifdef GBA_MODE
   install_common();
   modetxt_init();
   modetxt_gotoxy(0,0);
#endif

   DISPLAY_P("TFM Ident string:\n%s\n\n", fp_ident());

   /* test multiplication */
   fp_read_radix(&a, "3453534534535345345341230891273", 10);
   fp_read_radix(&b, "2394873294871238934718923" , 10);
   fp_read_radix(&c, "8270777629674273015508507050766235312931312159028658979", 10);
   fp_mul(&a, &b, &d);
   if (fp_cmp(&c, &d)) {
      DISPLAY("mul failed\n");
      return 0;
   } else {
      DISPLAY("mul passed\n");
   }

   /* test multiplication */
   fp_read_radix(&a, "30481290320498235987349712308523652378643912563478232907782361237864278207235782364578264891274789264278634289739", 10);
   fp_read_radix(&b, "48761478126387263782638276327836287632836278362837627838736278362923698724823749238732" , 10);
   fp_read_radix(&c, "1486312771227034563307950634490737985563993459700941115664257275795366623795590136120579100118233580357115074068815507257715906295105536107921754177810976863679300283932188006885811950341132768970948", 10);
   fp_mul(&a, &b, &d);
   if (fp_cmp(&c, &d)) {
      DISPLAY("mul failed\n");
      return 0;
   } else {
      DISPLAY("mul passed\n");
   }

   /* test multiplication */
   fp_read_radix(&a, "115792089237316195423570985008687907853269984665640564039457584007913129639935", 10);
   fp_read_radix(&b, "174224571863520493293247799005065324265471" , 10);
   fp_read_radix(&c, "20173827172553973356686868531273530268200710714389071377794102651988800859098544338487575161443744102709980552583184385", 10);
   fp_mul(&a, &b, &d);
   if (fp_cmp(&c, &d)) {
      DISPLAY("mul failed\n");
      return 0;
   } else {
      DISPLAY("mul passed\n");
   }

   /* test squaring */
   fp_read_radix(&a, "298723982748923478923473927489237289347238947238947238947238972893", 10);
   fp_read_radix(&b, "89236017869379132235512787068367546521309689412262624434964313994127411682542855190667724226920696163962644836740110835385588789449" , 10);
   fp_sqr(&a, &c);
   if (fp_cmp(&c, &b)) {
      DISPLAY("sqr failed\n");
      return 0;
   } else {
      DISPLAY("sqr passed\n");
   }

   fp_read_radix(&a, "397823894238973128942895123894327123941724927848927349274897238978927593487012378490184789429812734982738972389", 10);
   fp_read_radix(&b, "158263850827461677491961439999264901067636282938352531932899298293270945997930087353471903166601507321298827087008336951419604640736464667188494668962822678461626245753696845719301945679092882499787869509090904187704367321" , 10);
   fp_sqr(&a, &c);
   if (fp_cmp(&c, &b)) {
      DISPLAY("sqr failed\n");
      return 0;
   } else {
      DISPLAY("sqr passed\n");
   }

   fp_read_radix(&a, "13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084095", 10);
   fp_read_radix(&b, "179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474097562152033539671286128252223189553839160721441767298250321715263238814402734379959506792230903356495130620869925267845538430714092411695463462326211969025" , 10);
   fp_sqr(&a, &c);
   if (fp_cmp(&c, &b)) {
      DISPLAY("sqr failed\n");
      return 0;
   } else {
      DISPLAY("sqr passed\n");
   }


   /* montgomery reductions */
   fp_read_radix(&a, "234892374892374893489123428937892781237863278637826327367637836278362783627836783678363", 10);
   fp_read_radix(&b, "4447823492749823749234123489273987393983289319382762756425425425642727352327452374521", 10);
   fp_read_radix(&c, "2396271882990732698083317035605836523697277786556053771759862552557086442129695099100", 10);
   fp_montgomery_setup(&b, &dp);
   fp_montgomery_reduce(&a, &b, dp);
   if (fp_cmp(&a, &c)) {
      DISPLAY("mont failed\n");
      return 0;
   } else {
      DISPLAY("mont passed\n");
   }

   fp_read_radix(&a, "2348923748923748934891234456645654645645684576353428937892781237863278637826327367637836278362783627836783678363", 10);
   fp_read_radix(&b, "444782349274982374923412348927398739398328931938276275642542542564272735232745237452123424324324444121111119", 10);
   fp_read_radix(&c, "45642613844554582908652603086180267403823312390990082328515008314514368668691233331246183943400359349283420", 10);
   fp_montgomery_setup(&b, &dp);
   fp_montgomery_reduce(&a, &b, dp);
   if (fp_cmp(&a, &c)) {
      DISPLAY("mont failed\n");
      return 0;
   } else {
      DISPLAY("mont passed\n");
   }

   fp_read_radix(&a, "234823424242342923748923748934891234456645654645645684576353424972378234762378623891236834132352375235378462378489378927812378632786378263273676378362783627555555555539568389052478124618461834763837685723645827529034853490580134568947341278498542893481762349723907847892983627836783678363", 10);
   fp_read_radix(&b, "44478234927456563455982374923412348927398739398328931938276275642485623481638279025465891276312903262837562349056234783648712314678120389173890128905425242424239784256427", 10);
   fp_read_radix(&c, "33160865265453361650564031464519042126185632333462754084489985719613480783282357410514898819797738034600484519472656152351777186694609218202276509271061460265488348645081", 10);
   fp_montgomery_setup(&b, &dp);
   fp_montgomery_reduce(&a, &b, dp);
   if (fp_cmp(&a, &c)) {
      DISPLAY("mont failed\n");
      return 0;
   } else {
      DISPLAY("mont passed\n");
   }


   return 0;
}


/* $Source$ */
/* $Revision$ */
/* $Date$ */
