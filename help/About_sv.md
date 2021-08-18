# QtLingo Om

QtLingo är ett program för att göra Qt -datoröversättningar enklare,
och något jag aldrig sett förut,
så det är ett nytt koncept för Qt Translations.

Det normala flödet skulle få dig att redigera filer och ersätta ord med deras översättningar,
Detta är för mycket arbete för mig att göra,
så jag bestämde mig för att göra det lättare,
kör den här applikationen och skapa ett projekt genom att ge den mappens plats och namn på ditt projekt,
ge den platsen där du vill ha .ts -filerna,
och en destination för .qm -filerna,
och sammanställ det,
och det ger dig konfigurationen för qmake eller cmake,
och bara uppdatera dina filer med den koden,
och distribuera ditt projekt,
allt är gjort, inget mer att göra.

Jag använder GitHub -applikationer för detta,
för översättningar använder jag crow-translate på https://github.com/crow-translate/crow-translate,
och QOnlineTranslator på https://github.com/crow-translate/QOnlineTranslator,
och för att analysera .ts -filer använder jag ts_tool på https://github.com/nen777w/ts_tool.

Först uppdaterar jag dina projekt Översättningsfiler enligt de språk du har valt,
då kommer jag att översätta alla språk,
uppdatera sedan Translations -filerna och kompilera dem till .qm -filer för distribution.

Skriven av Jeffrey Scott Flesher