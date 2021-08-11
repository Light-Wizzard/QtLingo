/*
 *  Copyright © 2018-2021 Hennadii Chernyshchyk <genaloner@gmail.com>
 *
 *  This file is part of QOnlineTranslator.
 *
 *  QOnlineTranslator is free library; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a get of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "qonlinetranslator.h"
#include "qonlinetts.h"

/*! ***************************************************************************
   \fn s_genericLanguageCodes
   \brief languageCode(Language lang)
 *************************************************************************** */
const QMap<QOnlineTranslator::Language, QString> QOnlineTranslator::s_genericLanguageCodes =
{
    { Auto,                  QStringLiteral("auto")     },
    { Afrikaans,             QStringLiteral("af")       },
    { Albanian,              QStringLiteral("sq")       },
    { Amharic,               QStringLiteral("am")       },
    { Arabic,                QStringLiteral("ar")       },
    { Armenian,              QStringLiteral("hy")       },
    { Azerbaijani,           QStringLiteral("az")       },
    { Bashkir,               QStringLiteral("ba")       },
    { Basque,                QStringLiteral("eu")       },
    { Belarusian,            QStringLiteral("be")       },
    { Bengali,               QStringLiteral("bn")       },
    { Bosnian,               QStringLiteral("bs")       },
    { Bulgarian,             QStringLiteral("bg")       },
    { Cantonese,             QStringLiteral("yue")      },
    { Catalan,               QStringLiteral("ca")       },
    { Cebuano,               QStringLiteral("ceb")      },
    { Chichewa,              QStringLiteral("ny")       },
    { Corsican,              QStringLiteral("co")       },
    { Croatian,              QStringLiteral("hr")       },
    { Czech,                 QStringLiteral("cs")       },
    { Danish,                QStringLiteral("da")       },
    { Dutch,                 QStringLiteral("nl")       },
    { English,               QStringLiteral("en")       },
    { Esperanto,             QStringLiteral("eo")       },
    { Estonian,              QStringLiteral("et")       },
    { Fijian,                QStringLiteral("fj")       },
    { Filipino,              QStringLiteral("fil")      },
    { Finnish,               QStringLiteral("fi")       },
    { French,                QStringLiteral("fr")       },
    { Frisian,               QStringLiteral("fy")       },
    { Galician,              QStringLiteral("gl")       },
    { Georgian,              QStringLiteral("ka")       },
    { German,                QStringLiteral("de")       },
    { Greek,                 QStringLiteral("el")       },
    { Gujarati,              QStringLiteral("gu")       },
    { HaitianCreole,         QStringLiteral("ht")       },
    { Hausa,                 QStringLiteral("ha")       },
    { Hawaiian,              QStringLiteral("haw")      },
    { Hebrew,                QStringLiteral("he")       },
    { HillMari,              QStringLiteral("mrj")      },
    { Hindi,                 QStringLiteral("hi")       },
    { Hmong,                 QStringLiteral("hmn")      },
    { Hungarian,             QStringLiteral("hu")       },
    { Icelandic,             QStringLiteral("is")       },
    { Igbo,                  QStringLiteral("ig")       },
    { Indonesian,            QStringLiteral("id")       },
    { Irish,                 QStringLiteral("ga")       },
    { Italian,               QStringLiteral("it")       },
    { Japanese,              QStringLiteral("ja")       },
    { Javanese,              QStringLiteral("jw")       },
    { Kannada,               QStringLiteral("kn")       },
    { Kazakh,                QStringLiteral("kk")       },
    { Khmer,                 QStringLiteral("km")       },
    { Kinyarwanda,           QStringLiteral("rw")       },
    { Klingon,               QStringLiteral("tlh")      },
    { KlingonPlqaD,          QStringLiteral("tlh-Qaak") },
    { Korean,                QStringLiteral("ko")       },
    { Kurdish,               QStringLiteral("ku")       },
    { Kyrgyz,                QStringLiteral("ky")       },
    { Lao,                   QStringLiteral("lo")       },
    { Latin,                 QStringLiteral("la")       },
    { Latvian,               QStringLiteral("lv")       },
    { LevantineArabic,       QStringLiteral("apc")      },
    { Lithuanian,            QStringLiteral("lt")       },
    { Luxembourgish,         QStringLiteral("lb")       },
    { Macedonian,            QStringLiteral("mk")       },
    { Malagasy,              QStringLiteral("mg")       },
    { Malay,                 QStringLiteral("ms")       },
    { Malayalam,             QStringLiteral("ml")       },
    { Maltese,               QStringLiteral("mt")       },
    { Maori,                 QStringLiteral("mi")       },
    { Marathi,               QStringLiteral("mr")       },
    { Mari,                  QStringLiteral("mhr")      },
    { Mongolian,             QStringLiteral("mn")       },
    { Myanmar,               QStringLiteral("my")       },
    { Nepali,                QStringLiteral("ne")       },
    { Norwegian,             QStringLiteral("no")       },
    { Oriya,                 QStringLiteral("or")       },
    { Papiamento,            QStringLiteral("pap")      },
    { Pashto,                QStringLiteral("ps")       },
    { Persian,               QStringLiteral("fa")       },
    { Polish,                QStringLiteral("pl")       },
    { Portuguese,            QStringLiteral("pt")       },
    { Punjabi,               QStringLiteral("pa")       },
    { QueretaroOtomi,        QStringLiteral("otq")      },
    { Romanian,              QStringLiteral("ro")       },
    { Russian,               QStringLiteral("ru")       },
    { Samoan,                QStringLiteral("sm")       },
    { ScotsGaelic,           QStringLiteral("gd")       },
    { SerbianCyrillic,       QStringLiteral("sr")       },
    { SerbianLatin,          QStringLiteral("sr-Latin") },
    { Sesotho,               QStringLiteral("st")       },
    { Shona,                 QStringLiteral("sn")       },
    { SimplifiedChinese,     QStringLiteral("zh-CN")    },
    { Sindhi,                QStringLiteral("sd")       },
    { Sinhala,               QStringLiteral("si")       },
    { Slovak,                QStringLiteral("sk")       },
    { Slovenian,             QStringLiteral("sl")       },
    { Somali,                QStringLiteral("so")       },
    { Spanish,               QStringLiteral("es")       },
    { Sundanese,             QStringLiteral("su")       },
    { Swahili,               QStringLiteral("sw")       },
    { Swedish,               QStringLiteral("sv")       },
    { Tagalog,               QStringLiteral("tl")       },
    { Tahitian,              QStringLiteral("ty")       },
    { Tajik,                 QStringLiteral("tg")       },
    { Tamil,                 QStringLiteral("ta")       },
    { Tatar,                 QStringLiteral("tt")       },
    { Telugu,                QStringLiteral("te")       },
    { Thai,                  QStringLiteral("th")       },
    { Tongan,                QStringLiteral("to")       },
    { TraditionalChinese,    QStringLiteral("zh-TW")    },
    { Turkish,               QStringLiteral("tr")       },
    { Turkmen,               QStringLiteral("tk")       },
    { Udmurt,                QStringLiteral("udm")      },
    { Uighur,                QStringLiteral("ug")       },
    { Ukrainian,             QStringLiteral("uk")       },
    { Urdu,                  QStringLiteral("ur")       },
    { Uzbek,                 QStringLiteral("uz")       },
    { Vietnamese,            QStringLiteral("vi")       },
    { Welsh,                 QStringLiteral("cy")       },
    { Xhosa,                 QStringLiteral("xh")       },
    { Yiddish,               QStringLiteral("yi")       },
    { Yoruba,                QStringLiteral("yo")       },
    { YucatecMaya,           QStringLiteral("yua")      },
    { Zulu,                  QStringLiteral("zu")       }
};
/*! ***************************************************************************
   \fn s_genericLanguageCodesName
   \brief Added by Light-Wizzard s_genericLanguageCodesName
 *************************************************************************** */
const QMap<QString, QString> QOnlineTranslator::s_genericLanguageNameToCode =
{
    { QStringLiteral("Auto"),                  QStringLiteral("auto")     },
    { QStringLiteral("Afrikaans"),             QStringLiteral("af")       },
    { QStringLiteral("Albanian"),              QStringLiteral("sq")       },
    { QStringLiteral("Amharic"),               QStringLiteral("am")       },
    { QStringLiteral("Arabic"),                QStringLiteral("ar")       },
    { QStringLiteral("Armenian"),              QStringLiteral("hy")       },
    { QStringLiteral("Azerbaijani"),           QStringLiteral("az")       },
    { QStringLiteral("Bashkir"),               QStringLiteral("ba")       },
    { QStringLiteral("Basque"),                QStringLiteral("eu")       },
    { QStringLiteral("Belarusian"),            QStringLiteral("be")       },
    { QStringLiteral("Bengali"),               QStringLiteral("bn")       },
    { QStringLiteral("Bosnian"),               QStringLiteral("bs")       },
    { QStringLiteral("Bulgarian"),             QStringLiteral("bg")       },
    { QStringLiteral("Cantonese"),             QStringLiteral("yue")      },
    { QStringLiteral("Catalan"),               QStringLiteral("ca")       },
    { QStringLiteral("Cebuano"),               QStringLiteral("ceb")      },
    { QStringLiteral("Chichewa"),              QStringLiteral("ny")       },
    { QStringLiteral("Corsican"),              QStringLiteral("co")       },
    { QStringLiteral("Croatian"),              QStringLiteral("hr")       },
    { QStringLiteral("Czech"),                 QStringLiteral("cs")       },
    { QStringLiteral("Danish"),                QStringLiteral("da")       },
    { QStringLiteral("Dutch"),                 QStringLiteral("nl")       },
    { QStringLiteral("English"),               QStringLiteral("en")       },
    { QStringLiteral("Esperanto"),             QStringLiteral("eo")       },
    { QStringLiteral("Estonian"),              QStringLiteral("et")       },
    { QStringLiteral("Fijian"),                QStringLiteral("fj")       },
    { QStringLiteral("Filipino"),              QStringLiteral("fil")      },
    { QStringLiteral("Finnish"),               QStringLiteral("fi")       },
    { QStringLiteral("French"),                QStringLiteral("fr")       },
    { QStringLiteral("Frisian"),               QStringLiteral("fy")       },
    { QStringLiteral("Galician"),              QStringLiteral("gl")       },
    { QStringLiteral("Georgian"),              QStringLiteral("ka")       },
    { QStringLiteral("German"),                QStringLiteral("de")       },
    { QStringLiteral("Greek"),                 QStringLiteral("el")       },
    { QStringLiteral("Gujarati"),              QStringLiteral("gu")       },
    { QStringLiteral("HaitianCreole"),         QStringLiteral("ht")       },
    { QStringLiteral("Hausa"),                 QStringLiteral("ha")       },
    { QStringLiteral("Hawaiian"),              QStringLiteral("haw")      },
    { QStringLiteral("Hebrew"),                QStringLiteral("he")       },
    { QStringLiteral("HillMari"),              QStringLiteral("mrj")      },
    { QStringLiteral("Hindi"),                 QStringLiteral("hi")       },
    { QStringLiteral("Hmong"),                 QStringLiteral("hmn")      },
    { QStringLiteral("Hungarian"),             QStringLiteral("hu")       },
    { QStringLiteral("Icelandic"),             QStringLiteral("is")       },
    { QStringLiteral("Igbo"),                  QStringLiteral("ig")       },
    { QStringLiteral("Indonesian"),            QStringLiteral("id")       },
    { QStringLiteral("Irish"),                 QStringLiteral("ga")       },
    { QStringLiteral("Italian"),               QStringLiteral("it")       },
    { QStringLiteral("Japanese"),              QStringLiteral("ja")       },
    { QStringLiteral("Javanese"),              QStringLiteral("jw")       },
    { QStringLiteral("Kannada"),               QStringLiteral("kn")       },
    { QStringLiteral("Kazakh"),                QStringLiteral("kk")       },
    { QStringLiteral("Khmer"),                 QStringLiteral("km")       },
    { QStringLiteral("Kinyarwanda"),           QStringLiteral("rw")       },
    { QStringLiteral("Klingon"),               QStringLiteral("tlh")      },
    { QStringLiteral("KlingonPlqaD"),          QStringLiteral("tlh-Qaak") },
    { QStringLiteral("Korean"),                QStringLiteral("ko")       },
    { QStringLiteral("Kurdish"),               QStringLiteral("ku")       },
    { QStringLiteral("Kyrgyz"),                QStringLiteral("ky")       },
    { QStringLiteral("Lao"),                   QStringLiteral("lo")       },
    { QStringLiteral("Latin"),                 QStringLiteral("la")       },
    { QStringLiteral("Latvian"),               QStringLiteral("lv")       },
    { QStringLiteral("LevantineArabic"),       QStringLiteral("apc")      },
    { QStringLiteral("Lithuanian"),            QStringLiteral("lt")       },
    { QStringLiteral("Luxembourgish"),         QStringLiteral("lb")       },
    { QStringLiteral("Macedonian"),            QStringLiteral("mk")       },
    { QStringLiteral("Malagasy"),              QStringLiteral("mg")       },
    { QStringLiteral("Malay"),                 QStringLiteral("ms")       },
    { QStringLiteral("Malayalam"),             QStringLiteral("ml")       },
    { QStringLiteral("Maltese"),               QStringLiteral("mt")       },
    { QStringLiteral("Maori"),                 QStringLiteral("mi")       },
    { QStringLiteral("Marathi"),               QStringLiteral("mr")       },
    { QStringLiteral("Mari"),                  QStringLiteral("mhr")      },
    { QStringLiteral("Mongolian"),             QStringLiteral("mn")       },
    { QStringLiteral("Myanmar"),               QStringLiteral("my")       },
    { QStringLiteral("Nepali"),                QStringLiteral("ne")       },
    { QStringLiteral("Norwegian"),             QStringLiteral("no")       },
    { QStringLiteral("Oriya"),                 QStringLiteral("or")       },
    { QStringLiteral("Papiamento"),            QStringLiteral("pap")      },
    { QStringLiteral("Pashto"),                QStringLiteral("ps")       },
    { QStringLiteral("Persian"),               QStringLiteral("fa")       },
    { QStringLiteral("Polish"),                QStringLiteral("pl")       },
    { QStringLiteral("Portuguese"),            QStringLiteral("pt")       },
    { QStringLiteral("Punjabi"),               QStringLiteral("pa")       },
    { QStringLiteral("QueretaroOtomi"),        QStringLiteral("otq")      },
    { QStringLiteral("Romanian"),              QStringLiteral("ro")       },
    { QStringLiteral("Russian"),               QStringLiteral("ru")       },
    { QStringLiteral("Samoan"),                QStringLiteral("sm")       },
    { QStringLiteral("ScotsGaelic"),           QStringLiteral("gd")       },
    { QStringLiteral("SerbianCyrillic"),       QStringLiteral("sr")       },
    { QStringLiteral("SerbianLatin"),          QStringLiteral("sr-Latin") },
    { QStringLiteral("Sesotho"),               QStringLiteral("st")       },
    { QStringLiteral("Shona"),                 QStringLiteral("sn")       },
    { QStringLiteral("SimplifiedChinese"),     QStringLiteral("zh-CN")    },
    { QStringLiteral("Sindhi"),                QStringLiteral("sd")       },
    { QStringLiteral("Sinhala"),               QStringLiteral("si")       },
    { QStringLiteral("Slovak"),                QStringLiteral("sk")       },
    { QStringLiteral("Slovenian"),             QStringLiteral("sl")       },
    { QStringLiteral("Somali"),                QStringLiteral("so")       },
    { QStringLiteral("Spanish"),               QStringLiteral("es")       },
    { QStringLiteral("Sundanese"),             QStringLiteral("su")       },
    { QStringLiteral("Swahili"),               QStringLiteral("sw")       },
    { QStringLiteral("Swedish"),               QStringLiteral("sv")       },
    { QStringLiteral("Tagalog"),               QStringLiteral("tl")       },
    { QStringLiteral("Tahitian"),              QStringLiteral("ty")       },
    { QStringLiteral("Tajik"),                 QStringLiteral("tg")       },
    { QStringLiteral("Tamil"),                 QStringLiteral("ta")       },
    { QStringLiteral("Tatar"),                 QStringLiteral("tt")       },
    { QStringLiteral("Telugu"),                QStringLiteral("te")       },
    { QStringLiteral("Thai"),                  QStringLiteral("th")       },
    { QStringLiteral("Tongan"),                QStringLiteral("to")       },
    { QStringLiteral("TraditionalChinese"),    QStringLiteral("zh-TW")    },
    { QStringLiteral("Turkish"),               QStringLiteral("tr")       },
    { QStringLiteral("Turkmen"),               QStringLiteral("tk")       },
    { QStringLiteral("Udmurt"),                QStringLiteral("udm")      },
    { QStringLiteral("Uighur"),                QStringLiteral("ug")       },
    { QStringLiteral("Ukrainian"),             QStringLiteral("uk")       },
    { QStringLiteral("Urdu"),                  QStringLiteral("ur")       },
    { QStringLiteral("Uzbek"),                 QStringLiteral("uz")       },
    { QStringLiteral("Vietnamese"),            QStringLiteral("vi")       },
    { QStringLiteral("Welsh"),                 QStringLiteral("cy")       },
    { QStringLiteral("Xhosa"),                 QStringLiteral("xh")       },
    { QStringLiteral("Yiddish"),               QStringLiteral("yi")       },
    { QStringLiteral("Yoruba"),                QStringLiteral("yo")       },
    { QStringLiteral("YucatecMaya"),           QStringLiteral("yua")      },
    { QStringLiteral("Zulu"),                  QStringLiteral("zu")       }
};
/*! ***************************************************************************
   \fn s_genericLanguageCodesName
   \brief Added by Light-Wizzard s_genericLanguageCodesName
 *************************************************************************** */
const QMap<QString, QString> QOnlineTranslator::s_genericLanguageCodeToName =
{
    { QStringLiteral("auto"),       QStringLiteral("Auto")                  },
    { QStringLiteral("af"),         QStringLiteral("Afrikaans")             },
    { QStringLiteral("sq"),         QStringLiteral("Albanian")              },
    { QStringLiteral("am"),         QStringLiteral("Amharic")               },
    { QStringLiteral("ar"),         QStringLiteral("Arabic")                },
    { QStringLiteral("hy"),         QStringLiteral("Armenian")              },
    { QStringLiteral("az"),         QStringLiteral("Azerbaijani")           },
    { QStringLiteral("ba"),         QStringLiteral("Bashkir")               },
    { QStringLiteral("eu"),         QStringLiteral("Basque")                },
    { QStringLiteral("be"),         QStringLiteral("Belarusian")            },
    { QStringLiteral("bn"),         QStringLiteral("Bengali")               },
    { QStringLiteral("bs"),         QStringLiteral("Bosnian")               },
    { QStringLiteral("bg"),         QStringLiteral("Bulgarian")             },
    { QStringLiteral("yue"),        QStringLiteral("Cantonese")             },
    { QStringLiteral("ca"),         QStringLiteral("Catalan")               },
    { QStringLiteral("ceb"),        QStringLiteral("Cebuano")               },
    { QStringLiteral("ny"),         QStringLiteral("Chichewa")              },
    { QStringLiteral("co"),         QStringLiteral("Corsican")              },
    { QStringLiteral("hr"),         QStringLiteral("Croatian")              },
    { QStringLiteral("cs"),         QStringLiteral("Czech")                 },
    { QStringLiteral("da"),         QStringLiteral("Danish")                },
    { QStringLiteral("nl"),         QStringLiteral("Dutch")                 },
    { QStringLiteral("en"),         QStringLiteral("English")               },
    { QStringLiteral("eo"),         QStringLiteral("Esperanto")             },
    { QStringLiteral("et"),         QStringLiteral("Estonian")              },
    { QStringLiteral("fj"),         QStringLiteral("Fijian")                },
    { QStringLiteral("fil"),        QStringLiteral("Filipino")              },
    { QStringLiteral("fi"),         QStringLiteral("Finnish")               },
    { QStringLiteral("fr"),         QStringLiteral("French")                },
    { QStringLiteral("fy"),         QStringLiteral("Frisian")               },
    { QStringLiteral("gl"),         QStringLiteral("Galician")              },
    { QStringLiteral("ka"),         QStringLiteral("Georgian")              },
    { QStringLiteral("de"),         QStringLiteral("German")                },
    { QStringLiteral("el"),         QStringLiteral("Greek")                 },
    { QStringLiteral("gu"),         QStringLiteral("Gujarati")              },
    { QStringLiteral("ht"),         QStringLiteral("HaitianCreole")         },
    { QStringLiteral("ha"),         QStringLiteral("Hausa")                 },
    { QStringLiteral("haw"),        QStringLiteral("Hawaiian")              },
    { QStringLiteral("he"),         QStringLiteral("Hebrew")                },
    { QStringLiteral("mrj"),        QStringLiteral("HillMari")              },
    { QStringLiteral("hi"),         QStringLiteral("Hindi")                 },
    { QStringLiteral("hmn"),        QStringLiteral("Hmong")                 },
    { QStringLiteral("hu"),         QStringLiteral("Hungarian")             },
    { QStringLiteral("is"),         QStringLiteral("Icelandic")             },
    { QStringLiteral("ig"),         QStringLiteral("Igbo")                  },
    { QStringLiteral("id"),         QStringLiteral("Indonesian")            },
    { QStringLiteral("ga"),         QStringLiteral("Irish")                 },
    { QStringLiteral("it"),         QStringLiteral("Italian")               },
    { QStringLiteral("ja"),         QStringLiteral("Japanese")              },
    { QStringLiteral("jw"),         QStringLiteral("Javanese")              },
    { QStringLiteral("kn"),         QStringLiteral("Kannada")               },
    { QStringLiteral("kk"),         QStringLiteral("Kazakh")                },
    { QStringLiteral("km"),         QStringLiteral("Khmer")                 },
    { QStringLiteral("rw"),         QStringLiteral("Kinyarwanda")           },
    { QStringLiteral("tlh"),        QStringLiteral("Klingon")               },
    { QStringLiteral("tlh-Qaak"),   QStringLiteral("KlingonPlqaD")          },
    { QStringLiteral("ko"),         QStringLiteral("Korean")                },
    { QStringLiteral("ku"),         QStringLiteral("Kurdish")               },
    { QStringLiteral("ky"),         QStringLiteral("Kyrgyz")                },
    { QStringLiteral("lo"),         QStringLiteral("Lao")                   },
    { QStringLiteral("la"),         QStringLiteral("Latin")                 },
    { QStringLiteral("lv"),         QStringLiteral("Latvian")               },
    { QStringLiteral("apc"),        QStringLiteral("LevantineArabic")       },
    { QStringLiteral("lt"),         QStringLiteral("Lithuanian")            },
    { QStringLiteral("lb"),         QStringLiteral("Luxembourgish")         },
    { QStringLiteral("mk"),         QStringLiteral("Macedonian")            },
    { QStringLiteral("mg"),         QStringLiteral("Malagasy")              },
    { QStringLiteral("ms"),         QStringLiteral("Malay")                 },
    { QStringLiteral("ml"),         QStringLiteral("Malayalam")             },
    { QStringLiteral("mt"),         QStringLiteral("Maltese")               },
    { QStringLiteral("mi"),         QStringLiteral("Maori")                 },
    { QStringLiteral("mr"),         QStringLiteral("Marathi")               },
    { QStringLiteral("mhr"),        QStringLiteral("Mari")                  },
    { QStringLiteral("mn"),         QStringLiteral("Mongolian")             },
    { QStringLiteral("my"),         QStringLiteral("Myanmar")               },
    { QStringLiteral("ne"),         QStringLiteral("Nepali")                },
    { QStringLiteral("no"),         QStringLiteral("Norwegian")             },
    { QStringLiteral("or"),         QStringLiteral("Oriya")                 },
    { QStringLiteral("pap"),        QStringLiteral("Papiamento")            },
    { QStringLiteral("ps"),         QStringLiteral("Pashto")                },
    { QStringLiteral("fa"),         QStringLiteral("Persian")               },
    { QStringLiteral("pl"),         QStringLiteral("Polish")                },
    { QStringLiteral("pt"),         QStringLiteral("Portuguese")            },
    { QStringLiteral("pa"),         QStringLiteral("Punjabi")               },
    { QStringLiteral("otq"),        QStringLiteral("QueretaroOtomi")        },
    { QStringLiteral("ro"),         QStringLiteral("Romanian")              },
    { QStringLiteral("ru"),         QStringLiteral("Russian")               },
    { QStringLiteral("sm"),         QStringLiteral("Samoan")                },
    { QStringLiteral("gd"),         QStringLiteral("ScotsGaelic")           },
    { QStringLiteral("sr"),         QStringLiteral("SerbianCyrillic")       },
    { QStringLiteral("sr-Latin"),   QStringLiteral("SerbianLatin")          },
    { QStringLiteral("st"),         QStringLiteral("Sesotho")               },
    { QStringLiteral("sn"),         QStringLiteral("Shona")                 },
    { QStringLiteral("zh-CN"),      QStringLiteral("SimplifiedChinese")     },
    { QStringLiteral("sd"),         QStringLiteral("Sindhi")                },
    { QStringLiteral("si"),         QStringLiteral("Sinhala")               },
    { QStringLiteral("sk"),         QStringLiteral("Slovak")                },
    { QStringLiteral("sl"),         QStringLiteral("Slovenian")             },
    { QStringLiteral("so"),         QStringLiteral("Somali")                },
    { QStringLiteral("es"),         QStringLiteral("Spanish")               },
    { QStringLiteral("su"),         QStringLiteral("Sundanese")             },
    { QStringLiteral("sw"),         QStringLiteral("Swahili")               },
    { QStringLiteral("sv"),         QStringLiteral("Swedish")               },
    { QStringLiteral("tl"),         QStringLiteral("Tagalog")               },
    { QStringLiteral("ty"),         QStringLiteral("Tahitian")              },
    { QStringLiteral("tg"),         QStringLiteral("Tajik")                 },
    { QStringLiteral("ta"),         QStringLiteral("Tamil")                 },
    { QStringLiteral("tt"),         QStringLiteral("Tatar")                 },
    { QStringLiteral("te"),         QStringLiteral("Telugu")                },
    { QStringLiteral("th"),         QStringLiteral("Thai")                  },
    { QStringLiteral("to"),         QStringLiteral("Tongan")                },
    { QStringLiteral("zh-TW"),      QStringLiteral("TraditionalChinese")    },
    { QStringLiteral("tr"),         QStringLiteral("Turkish")               },
    { QStringLiteral("tk"),         QStringLiteral("Turkmen")               },
    { QStringLiteral("udm"),        QStringLiteral("Udmurt")                },
    { QStringLiteral("ug"),         QStringLiteral("Uighur")                },
    { QStringLiteral("uk"),         QStringLiteral("Ukrainian")             },
    { QStringLiteral("ur"),         QStringLiteral("Urdu")                  },
    { QStringLiteral("uz"),         QStringLiteral("Uzbek")                 },
    { QStringLiteral("vi"),         QStringLiteral("Vietnamese")            },
    { QStringLiteral("cy"),         QStringLiteral("Welsh")                 },
    { QStringLiteral("xh"),         QStringLiteral("Xhosa")                 },
    { QStringLiteral("yi"),         QStringLiteral("Yiddish")               },
    { QStringLiteral("yo"),         QStringLiteral("Yoruba")                },
    { QStringLiteral("yua"),        QStringLiteral("YucatecMaya")           },
    { QStringLiteral("zu"),         QStringLiteral("Zulu")                  }
};
/*! ***************************************************************************
   \fn s_googleLanguageCodes
   \brief s_googleLanguageCodes
 *************************************************************************** */
const QMap<QOnlineTranslator::Language, QString> QOnlineTranslator::s_googleLanguageCodes =
{
    { Hebrew, QStringLiteral("iw") }
};
/*! ***************************************************************************
   \fn s_yandexLanguageCodes
   \brief s_yandexLanguageCodes
 *************************************************************************** */
const QMap<QOnlineTranslator::Language, QString> QOnlineTranslator::s_yandexLanguageCodes =
{
    { SimplifiedChinese, QStringLiteral("zn") },
    { Javanese,          QStringLiteral("jv") }
};
/*! ***************************************************************************
   \fn s_bingLanguageCodes
   \brief s_bingLanguageCodes
 *************************************************************************** */
const QMap<QOnlineTranslator::Language, QString> QOnlineTranslator::s_bingLanguageCodes =
{
    { Auto,               QStringLiteral("auto-detect") },
    { Bosnian,            QStringLiteral("bs-Latn")     },
    { SerbianCyrillic,    QStringLiteral("sr-Cyrl")     },
    { SimplifiedChinese,  QStringLiteral("zh-Hans")     },
    { TraditionalChinese, QStringLiteral("zh-Hant")     },
    { Hmong,              QStringLiteral("mww")         }
};
/*! ***************************************************************************
   \fn QOnlineTranslator
   \brief QOnlineTranslator Constructor
 *************************************************************************** */
QOnlineTranslator::QOnlineTranslator(QObject *parent) : QObject(parent), m_stateMachine(new QStateMachine(this)), m_networkManager(new QNetworkAccessManager(this))
{
    connect(m_stateMachine, &QStateMachine::finished, this, &QOnlineTranslator::finished);
    connect(m_stateMachine, &QStateMachine::stopped,  this, &QOnlineTranslator::finished);
}
/*! ***************************************************************************
   \fn translate
   \brief translate
 *************************************************************************** */
void QOnlineTranslator::translate(const QString &text, Engine engine, Language translationLang, Language sourceLang, Language uiLang)
{
    abort();
    resetData();

    m_onlyDetectLanguage = false;
    m_source             = text;
    m_sourceLang         = sourceLang;
    m_translationLang    = translationLang == Auto ? language(QLocale()) : translationLang;
    m_uiLang             = uiLang == Auto ? language(QLocale()) : uiLang;

    // Check if the source selected languages ​​are supported by the engine
    if (!isSupportTranslation(engine, m_sourceLang))
    {
        resetData(ParametersError, QString("%1 %2 %3 %4").arg(tr("Selected source language"), languageName(m_sourceLang), QMetaEnum::fromType<Engine>().valueToKey(engine), tr("is not supported for")));
        emit finished();
        return;
    }
    // Check if the selected languages ​​are supported by the engine
    if (!isSupportTranslation(engine, m_translationLang))
    {
        resetData(ParametersError, QString("%1 %2 %3 %4").arg(tr("Selected translation language"), languageName(m_translationLang), QMetaEnum::fromType<Engine>().valueToKey(engine), tr("is not supported for")));
        emit finished();
        return;
    }
    // Check if the selected UI languages ​​are supported by the engine
    if (!isSupportTranslation(engine, m_uiLang))
    {
        resetData(ParametersError, QString("%1 %2 %3 %4").arg(tr("Selected ui language"), languageName(m_uiLang), QMetaEnum::fromType<Engine>().valueToKey(engine), tr("is not supported for")));
        emit finished();
        return;
    }

    switch (engine)
    {
        case Google: buildGoogleStateMachine(); break;
        case Yandex: buildYandexStateMachine(); break;
        case Bing:   buildBingStateMachine();   break;
    }

    m_stateMachine->start();
}
/*! ***************************************************************************
   \fn detectLanguage
   \brief detect Language
 *************************************************************************** */
void QOnlineTranslator::detectLanguage(const QString &text, Engine engine)
{
    abort();
    resetData();

    m_onlyDetectLanguage = true;
    m_source             = text;
    m_sourceLang         = Auto;
    m_translationLang    = English;
    m_uiLang             = language(QLocale());

    switch (engine)
    {
        case Google: buildGoogleDetectStateMachine(); break;
        case Yandex: buildYandexDetectStateMachine(); break;
        case Bing:   buildBingDetectStateMachine();   break;
    }

    m_stateMachine->start();
}
/*! ***************************************************************************
   \fn abort
   \brief abort
 *************************************************************************** */
void QOnlineTranslator::abort()
{
    if (m_currentReply != nullptr) { m_currentReply->abort(); }
}
/*! ***************************************************************************
   \fn isRunning
   \brief is Running
 *************************************************************************** */
bool QOnlineTranslator::isRunning() const
{
    return m_stateMachine->isRunning();
}
/*! ***************************************************************************
   \fn toJson
   \brief toJson
 *************************************************************************** */
QJsonDocument QOnlineTranslator::toJson() const
{
    QJsonObject translationOptions;
    for (auto it = m_translationOptions.cbegin(); it != m_translationOptions.cend(); ++it)
    {
        QJsonArray arr;
        for (const QOption &option : it.value())
        {
            arr.append(option.toJson());
        }
        translationOptions.insert(it.key(), arr);
    }

    QJsonObject examples;
    for (auto it = m_examples.cbegin(); it != m_examples.cend(); ++it)
    {
        QJsonArray arr;
        for (const QExample &example : it.value())
        {
            arr.append(example.toJson());
        }
        examples.insert(it.key(), arr);
    }

    QJsonObject object
    {
        {"examples",            qMove(examples)},
        {"source",              m_source},
        {"sourceTranscription", m_sourceTranscription},
        {"sourceTranslit",      m_sourceTranslit},
        {"translation",         m_translation},
        {"translationOptions",  qMove(translationOptions)},
        {"translationTranslit", m_translationTranslit},
    };

    return QJsonDocument(object);
}
/*! ***************************************************************************
   \fn source
   \brief source
 *************************************************************************** */
QString QOnlineTranslator::source() const
{
    return m_source;
}
/*! ***************************************************************************
   \fn sourceTranslit
   \brief source Translit
 *************************************************************************** */
QString QOnlineTranslator::sourceTranslit() const
{
    return m_sourceTranslit;
}
/*! ***************************************************************************
   \fn sourceTranscription
   \brief source Transcription
 *************************************************************************** */
QString QOnlineTranslator::sourceTranscription() const
{
    return m_sourceTranscription;
}
/*! ***************************************************************************
   \fn sourceLanguageName
   \brief source Language Name
 *************************************************************************** */
QString QOnlineTranslator::sourceLanguageName() const
{
    return languageName(m_sourceLang);
}
/*! ***************************************************************************
   \fn sourceLanguage
   \brief source Language
 *************************************************************************** */
QOnlineTranslator::Language QOnlineTranslator::sourceLanguage() const
{
    return m_sourceLang;
}
/*! ***************************************************************************
   \fn translation
   \brief translation
 *************************************************************************** */
QString QOnlineTranslator::translation() const
{
    return m_translation;
}
/*! ***************************************************************************
   \fn translationTranslit
   \brief translation Translit
 *************************************************************************** */
QString QOnlineTranslator::translationTranslit() const
{
    return m_translationTranslit;
}
/*! ***************************************************************************
   \fn translationLanguageName
   \brief translation Language Name
 *************************************************************************** */
QString QOnlineTranslator::translationLanguageName() const
{
    return languageName(m_translationLang);
}
/*! ***************************************************************************
   \fn translationLanguage
   \brief translation Language
 *************************************************************************** */
QOnlineTranslator::Language QOnlineTranslator::translationLanguage() const
{
    return m_translationLang;
}
/*! ***************************************************************************
   \fn translationOptions
   \brief translation Options
 *************************************************************************** */
QMap<QString, QVector<QOption>> QOnlineTranslator::translationOptions() const
{
    return m_translationOptions;
}
/*! ***************************************************************************
   \fn examples
   \brief examples
 *************************************************************************** */
QMap<QString, QVector<QExample>> QOnlineTranslator::examples() const
{
    return m_examples;
}
/*! ***************************************************************************
   \fn error
   \brief error
 *************************************************************************** */
QOnlineTranslator::TranslationError QOnlineTranslator::error() const
{
    return m_error;
}
/*! ***************************************************************************
   \fn errorString
   \brief error String
 *************************************************************************** */
QString QOnlineTranslator::errorString() const
{
    return m_errorString;
}
/*! ***************************************************************************
   \fn isSourceTranslitEnabled
   \brief is Source Translit Enabled
 *************************************************************************** */
bool QOnlineTranslator::isSourceTranslitEnabled() const
{
    return m_sourceTranslitEnabled;
}
/*! ***************************************************************************
   \fn setSourceTranslitEnabled
   \brief set Source Translit Enabled
 *************************************************************************** */
void QOnlineTranslator::setSourceTranslitEnabled(bool enable)
{
    m_sourceTranslitEnabled = enable;
}
/*! ***************************************************************************
   \fn isTranslationTranslitEnabled
   \brief is Translation Translit Enabled
 *************************************************************************** */
bool QOnlineTranslator::isTranslationTranslitEnabled() const
{
    return m_translationTranslitEnabled;
}
/*! ***************************************************************************
   \fn setTranslationTranslitEnabled
   \brief set Translation Translit Enabled
 *************************************************************************** */
void QOnlineTranslator::setTranslationTranslitEnabled(bool enable)
{
    m_translationTranslitEnabled = enable;
}
/*! ***************************************************************************
   \fn isSourceTranscriptionEnabled
   \brief is Source Transcription Enabled
 *************************************************************************** */
bool QOnlineTranslator::isSourceTranscriptionEnabled() const
{
    return m_sourceTranscriptionEnabled;
}
/*! ***************************************************************************
   \fn setSourceTranscriptionEnabled
   \brief set Source Transcription Enabled
 *************************************************************************** */
void QOnlineTranslator::setSourceTranscriptionEnabled(bool enable)
{
    m_sourceTranscriptionEnabled = enable;
}
/*! ***************************************************************************
   \fn isTranslationOptionsEnabled
   \brief is Translation Options Enabled
 *************************************************************************** */
bool QOnlineTranslator::isTranslationOptionsEnabled() const
{
    return m_translationOptionsEnabled;
}
/*! ***************************************************************************
   \fn setTranslationOptionsEnabled
   \brief set Translation Options Enabled
 *************************************************************************** */
void QOnlineTranslator::setTranslationOptionsEnabled(bool enable)
{
    m_translationOptionsEnabled = enable;
}
/*! ***************************************************************************
   \fn isExamplesEnabled
   \brief is Examples Enabled
 *************************************************************************** */
bool QOnlineTranslator::isExamplesEnabled() const
{
    return m_examplesEnabled;
}
/*! ***************************************************************************
   \fn setExamplesEnabled
   \brief set Examples Enabled
 *************************************************************************** */
void QOnlineTranslator::setExamplesEnabled(bool enable)
{
    m_examplesEnabled = enable;
}
/*! ***************************************************************************
   \fn languageName
   \brief language Name
 *************************************************************************** */
QString QOnlineTranslator::languageName(Language lang)
{
    switch (lang)
    {
        case Auto:                  return tr("Automatically detect");
        case Afrikaans:             return tr("Afrikaans");
        case Albanian:              return tr("Albanian");
        case Amharic:               return tr("Amharic");
        case Arabic:                return tr("Arabic");
        case Armenian:              return tr("Armenian");
        case Azerbaijani:           return tr("Azeerbaijani");
        case Basque:                return tr("Basque");
        case Bashkir:               return tr("Bashkir");
        case Belarusian:            return tr("Belarusian");
        case Bengali:               return tr("Bengali");
        case Bosnian:               return tr("Bosnian");
        case Bulgarian:             return tr("Bulgarian");
        case Catalan:               return tr("Catalan");
        case Cantonese:             return tr("Cantonese");
        case Cebuano:               return tr("Cebuano");
        case SimplifiedChinese:     return tr("Chinese (Simplified)");
        case TraditionalChinese:    return tr("Chinese (Traditional)");
        case Corsican:              return tr("Corsican");
        case Croatian:              return tr("Croatian");
        case Czech:                 return tr("Czech");
        case Danish:                return tr("Danish");
        case Dutch:                 return tr("Dutch");
        case English:               return tr("English");
        case Esperanto:             return tr("Esperanto");
        case Estonian:              return tr("Estonian");
        case Fijian:                return tr("Fijian");
        case Filipino:              return tr("Filipino");
        case Finnish:               return tr("Finnish");
        case French:                return tr("French");
        case Frisian:               return tr("Frisian");
        case Galician:              return tr("Galician");
        case Georgian:              return tr("Georgian");
        case German:                return tr("German");
        case Greek:                 return tr("Greek");
        case Gujarati:              return tr("Gujarati");
        case HaitianCreole:         return tr("Haitian Creole");
        case Hausa:                 return tr("Hausa");
        case Hawaiian:              return tr("Hawaiian");
        case Hebrew:                return tr("Hebrew");
        case HillMari:              return tr("Hill Mari");
        case Hindi:                 return tr("Hindi");
        case Hmong:                 return tr("Hmong");
        case Hungarian:             return tr("Hungarian");
        case Icelandic:             return tr("Icelandic");
        case Igbo:                  return tr("Igbo");
        case Indonesian:            return tr("Indonesian");
        case Irish:                 return tr("Irish");
        case Italian:               return tr("Italian");
        case Japanese:              return tr("Japanese");
        case Javanese:              return tr("Javanese");
        case Kannada:               return tr("Kannada");
        case Kazakh:                return tr("Kazakh");
        case Khmer:                 return tr("Khmer");
        case Kinyarwanda:           return tr("Kinyarwanda");
        case Klingon:               return tr("Klingon");
        case KlingonPlqaD:          return tr("Klingon (PlqaD)");
        case Korean:                return tr("Korean");
        case Kurdish:               return tr("Kurdish");
        case Kyrgyz:                return tr("Kyrgyz");
        case Lao:                   return tr("Lao");
        case Latin:                 return tr("Latin");
        case Latvian:               return tr("Latvian");
        case LevantineArabic:       return tr("Levantine Arabic");
        case Lithuanian:            return tr("Lithuanian");
        case Luxembourgish:         return tr("Luxembourgish");
        case Macedonian:            return tr("Macedonian");
        case Malagasy:              return tr("Malagasy");
        case Malay:                 return tr("Malay");
        case Malayalam:             return tr("Malayalam");
        case Maltese:               return tr("Maltese");
        case Maori:                 return tr("Maori");
        case Marathi:               return tr("Marathi");
        case Mari:                  return tr("Mari");
        case Mongolian:             return tr("Mongolian");
        case Myanmar:               return tr("Myanmar");
        case Nepali:                return tr("Nepali");
        case Norwegian:             return tr("Norwegian");
        case Oriya:                 return tr("Oriya");
        case Chichewa:              return tr("Chichewa");
        case Papiamento:            return tr("Papiamento");
        case Pashto:                return tr("Pashto");
        case Persian:               return tr("Persian");
        case Polish:                return tr("Polish");
        case Portuguese:            return tr("Portuguese");
        case Punjabi:               return tr("Punjabi");
        case QueretaroOtomi:        return tr("Queretaro Otomi");
        case Romanian:              return tr("Romanian");
        case Russian:               return tr("Russian");
        case Samoan:                return tr("Samoan");
        case ScotsGaelic:           return tr("Scots Gaelic");
        case SerbianCyrillic:       return tr("Serbian (Cyrillic)");
        case SerbianLatin:          return tr("Serbian (Latin)");
        case Sesotho:               return tr("Sesotho");
        case Shona:                 return tr("Shona");
        case Sindhi:                return tr("Sindhi");
        case Sinhala:               return tr("Sinhala");
        case Slovak:                return tr("Slovak");
        case Slovenian:             return tr("Slovenian");
        case Somali:                return tr("Somali");
        case Spanish:               return tr("Spanish");
        case Sundanese:             return tr("Sundanese");
        case Swahili:               return tr("Swahili");
        case Swedish:               return tr("Swedish");
        case Tagalog:               return tr("Tagalog");
        case Tahitian:              return tr("Tahitian");
        case Tajik:                 return tr("Tajik");
        case Tamil:                 return tr("Tamil");
        case Tatar:                 return tr("Tatar");
        case Telugu:                return tr("Telugu");
        case Thai:                  return tr("Thai");
        case Tongan:                return tr("Tongan");
        case Turkish:               return tr("Turkish");
        case Turkmen:               return tr("Turkmen");
        case Udmurt:                return tr("Udmurt");
        case Uighur:                return tr("Uighur");
        case Ukrainian:             return tr("Ukrainian");
        case Urdu:                  return tr("Urdu");
        case Uzbek:                 return tr("Uzbek");
        case Vietnamese:            return tr("Vietnamese");
        case Welsh:                 return tr("Welsh");
        case Xhosa:                 return tr("Xhosa");
        case Yiddish:               return tr("Yiddish");
        case Yoruba:                return tr("Yoruba");
        case YucatecMaya:           return tr("Yucatec Maya");
        case Zulu:                  return tr("Zulu");
        default:                    return QString();
    } // end switch (lang)
} // end languageName(Language lang)
/*! ***************************************************************************
   \fn languageCode
   \brief language Code
 *************************************************************************** */
QString QOnlineTranslator::languageCode(Language lang)
{
    return s_genericLanguageCodes.value(lang);
}
/*! ***************************************************************************
   \fn languageNameToCode
   \brief Added by Light-Wizzard language Name to Code
 *************************************************************************** */
QString QOnlineTranslator::languageNameToCode(const QString &lang)
{
    return s_genericLanguageNameToCode.value(lang);
} // end languageNameToCode
/*! ***************************************************************************
   \fn languageCodeToName
   \brief Added by Light-Wizzard language Code to Name
 *************************************************************************** */
QString QOnlineTranslator::languageCodeToName(const QString &lang)
{
    return s_genericLanguageCodeToName.value(lang);
} // end languageCodeToName
/*! ***************************************************************************
   \fn language
   \brief language
 *************************************************************************** */
QOnlineTranslator::Language QOnlineTranslator::language(const QLocale &locale)
{
    switch (locale.language())
    {
        case QLocale::Afrikaans:        return Afrikaans;
        case QLocale::Albanian:         return Albanian;
        case QLocale::Amharic:          return Amharic;
        case QLocale::Arabic:           return Arabic;
        case QLocale::Armenian:         return Armenian;
        case QLocale::Azerbaijani:      return Azerbaijani;
        case QLocale::Basque:           return Basque;
        case QLocale::Belarusian:       return Belarusian;
        case QLocale::Bengali:          return Bengali;
        case QLocale::Bosnian:          return Bosnian;
        case QLocale::Bulgarian:        return Bulgarian;
        case QLocale::Catalan:          return Catalan;
        case QLocale::Chinese:          return SimplifiedChinese;
        case QLocale::LiteraryChinese:  return TraditionalChinese;
        case QLocale::Corsican:         return Corsican;
        case QLocale::Croatian:         return Croatian;
        case QLocale::Czech:            return Czech;
        case QLocale::Danish:           return Danish;
        case QLocale::Dutch:            return Dutch;
        case QLocale::Esperanto:        return Esperanto;
        case QLocale::Estonian:         return Estonian;
        case QLocale::Finnish:          return Finnish;
        case QLocale::French:           return French;
        case QLocale::Frisian:          return Frisian;
        case QLocale::Galician:         return Galician;
        case QLocale::Georgian:         return Georgian;
        case QLocale::German:           return German;
        case QLocale::Greek:            return Greek;
        case QLocale::Gujarati:         return Gujarati;
        case QLocale::Haitian:          return HaitianCreole;
        case QLocale::Hausa:            return Hausa;
        case QLocale::Hawaiian:         return Hawaiian;
        case QLocale::Hebrew:           return Hebrew;
        case QLocale::Hindi:            return Hindi;
        case QLocale::Hungarian:        return Hungarian;
        case QLocale::Icelandic:        return Icelandic;
        case QLocale::Igbo:             return Igbo;
        case QLocale::Indonesian:       return Indonesian;
        case QLocale::Irish:            return Irish;
        case QLocale::Italian:          return Italian;
        case QLocale::Japanese:         return Japanese;
        case QLocale::Javanese:         return Javanese;
        case QLocale::Kannada:          return Kannada;
        case QLocale::Kazakh:           return Kazakh;
        case QLocale::Khmer:            return Khmer;
        case QLocale::Kinyarwanda:      return Kinyarwanda;
        case QLocale::Korean:           return Korean;
        case QLocale::Kurdish:          return Kurdish;
        case QLocale::Lao:              return Lao;
        case QLocale::Latin:            return Latin;
        case QLocale::Latvian:          return Latvian;
        case QLocale::Lithuanian:       return Lithuanian;
        case QLocale::Luxembourgish:    return Luxembourgish;
        case QLocale::Macedonian:       return Macedonian;
        case QLocale::Malagasy:         return Malagasy;
        case QLocale::Malay:            return Malay;
        case QLocale::Malayalam:        return Malayalam;
        case QLocale::Maltese:          return Maltese;
        case QLocale::Maori:            return Maori;
        case QLocale::Marathi:          return Marathi;
        case QLocale::Mongolian:        return Mongolian;
        case QLocale::Nepali:           return Nepali;
        case QLocale::NorwegianBokmal:  return Norwegian;
        case QLocale::Oriya:            return Oriya;
        case QLocale::Pashto:           return Pashto;
        case QLocale::Persian:          return Persian;
        case QLocale::Polish:           return Polish;
        case QLocale::Portuguese:       return Portuguese;
        case QLocale::Punjabi:          return Punjabi;
        case QLocale::Romanian:         return Romanian;
        case QLocale::Russian:          return Russian;
        case QLocale::Samoan:           return Samoan;
        case QLocale::Gaelic:           return ScotsGaelic;
        case QLocale::Serbian:          return SerbianCyrillic;
        case QLocale::Shona:            return Shona;
        case QLocale::Sindhi:           return Sindhi;
        case QLocale::Sinhala:          return Sinhala;
        case QLocale::Slovak:           return Slovak;
        case QLocale::Slovenian:        return Slovenian;
        case QLocale::Somali:           return Somali;
        case QLocale::Spanish:          return Spanish;
        case QLocale::Sundanese:        return Sundanese;
        case QLocale::Swahili:          return Swahili;
        case QLocale::Swedish:          return Swedish;
        case QLocale::Filipino:         return Filipino;
        case QLocale::Tajik:            return Tajik;
        case QLocale::Tamil:            return Tamil;
        case QLocale::Tatar:            return Tatar;
        case QLocale::Telugu:           return Telugu;
        case QLocale::Thai:             return Thai;
        case QLocale::Turkish:          return Turkish;
        case QLocale::Turkmen:          return Turkmen;
        case QLocale::Uighur:           return Uighur;
        case QLocale::Ukrainian:        return Ukrainian;
        case QLocale::Urdu:             return Urdu;
        case QLocale::Uzbek:            return Uzbek;
        case QLocale::Vietnamese:       return Vietnamese;
        case QLocale::Welsh:            return Welsh;
        case QLocale::Xhosa:            return Xhosa;
        case QLocale::Yiddish:          return Yiddish;
        case QLocale::Yoruba:           return Yoruba;
        case QLocale::Zulu:             return Zulu;
        default:                        return English;
    }
}
/*! ***************************************************************************
   \fn language
   \brief Returns general language code
 *************************************************************************** */
QOnlineTranslator::Language QOnlineTranslator::language(const QString &langCode)
{
    return s_genericLanguageCodes.key(langCode, NoLanguage);
}
/*! ***************************************************************************
   \fn isSupportTranslation
   \brief is Support Translation
 *************************************************************************** */
bool QOnlineTranslator::isSupportTranslation(Engine engine, Language lang)
{
    bool isSupported = false;

    switch (engine)
    {
        case Google:
            switch (lang)
            {
                case NoLanguage:
                case Bashkir:
                case Cantonese:
                case Fijian:
                case Filipino:
                case Georgian:
                case HillMari:
                case Klingon:
                case KlingonPlqaD:
                case LevantineArabic:
                case Mari:
                case Papiamento:
                case QueretaroOtomi:
                case SerbianLatin:
                case Tahitian:
                case Tongan:
                case Udmurt:
                case YucatecMaya:
                    isSupported = false;
                    break;
                default:
                    isSupported = true;
                    break;
            }
            break;
        case Yandex:
            switch (lang)
            {
                case NoLanguage:
                case Cantonese:
                case Chichewa:
                case Corsican:
                case Fijian:
                case Filipino:
                case Frisian:
                case Hausa:
                case Hawaiian:
                case Igbo:
                case Kinyarwanda:
                case Klingon:
                case KlingonPlqaD:
                case Kurdish:
                case LevantineArabic:
                case Oriya:
                case Pashto:
                case QueretaroOtomi:
                case Samoan:
                case SerbianLatin:
                case Sesotho:
                case Shona:
                case Sindhi:
                case Somali:
                case Tahitian:
                case Tongan:
                case Turkmen:
                case Uighur:
                case Yoruba:
                case YucatecMaya:
                case Zulu:
                    isSupported = false;
                    break;
                default:
                    isSupported = true;
                    break;
            }
            break;
        case Bing:
            switch (lang)
            {
                case NoLanguage:
                case Albanian:
                case Amharic:
                case Armenian:
                case Azerbaijani:
                case Basque:
                case Bashkir:
                case Belarusian:
                case Cebuano:
                case Corsican:
                case Esperanto:
                case Frisian:
                case Galician:
                case Georgian:
                case Gujarati:
                case Hausa:
                case Hawaiian:
                case HillMari:
                case Igbo:
                case Irish:
                case Javanese:
                case Kannada:
                case Kazakh:
                case Khmer:
                case Kinyarwanda:
                case Kurdish:
                case Kyrgyz:
                case Lao:
                case Latin:
                case Luxembourgish:
                case Macedonian:
                case Malayalam:
                case Maori:
                case Marathi:
                case Mari:
                case Mongolian:
                case Myanmar:
                case Nepali:
                case Oriya:
                case Chichewa:
                case Papiamento:
                case Pashto:
                case Punjabi:
                case ScotsGaelic:
                case Sesotho:
                case Shona:
                case Sindhi:
                case Sinhala:
                case Somali:
                case Sundanese:
                case Tagalog:
                case Tajik:
                case Tatar:
                case Turkmen:
                case Uighur:
                case Udmurt:
                case Uzbek:
                case Xhosa:
                case Yiddish:
                case Yoruba:
                case Zulu:
                    isSupported = false;
                    break;
                default:
                    isSupported = true;
                    break;
            }
    }

    return isSupported;
}
/*! ***************************************************************************
   \fn skipGarbageText
   \brief skip Garbage Text
 *************************************************************************** */
void QOnlineTranslator::skipGarbageText()
{
    m_translation.append(sender()->property(s_textProperty).toString());
}
/*! ***************************************************************************
   \fn requestGoogleTranslate
   \brief request Google Translate
 *************************************************************************** */
void QOnlineTranslator::requestGoogleTranslate()
{
    const QString sourceText = sender()->property(s_textProperty).toString();

    // Generate API url
    QUrl url(QStringLiteral("https://translate.googleapis.com/translate_a/single"));

    url.setQuery(QStringLiteral("client=gtx&ie=UTF-8&oe=UTF-8&dt=bd&dt=ex&dt=ld&dt=md&dt=rw&dt=rm&dt=ss&dt=t&dt=at&dt=qc&sl=%1&tl=%2&hl=%3&q=%4")
                 .arg(languageApiCode(Google, m_sourceLang), languageApiCode(Google, m_translationLang), languageApiCode(Google, m_uiLang), QUrl::toPercentEncoding(sourceText)));

    m_currentReply = m_networkManager->get(QNetworkRequest(url));
}
/*! ***************************************************************************
   \fn parseGoogleTranslate
   \brief parse Google Translate
 *************************************************************************** */
void QOnlineTranslator::parseGoogleTranslate()
{
    m_currentReply->deleteLater();

    // Check for error
    if (m_currentReply->error() != QNetworkReply::NoError)
    {
        if (m_currentReply->error() == QNetworkReply::ServiceUnavailableError)
            { resetData(ServiceError, tr("Error: Engine systems have detected suspicious traffic from your computer network. Please try your request again later.")); }
        else
            { resetData(NetworkError, m_currentReply->errorString()); }
        return;
    }

    // Check availability of service
    const QByteArray data = m_currentReply->readAll();
    if (data.startsWith('<'))
    {
        resetData(ServiceError, tr("Error: Engine systems have detected suspicious traffic from your computer network. Please try your request again later."));
        return;
    }

    // Read Json
    const QJsonDocument jsonResponse = QJsonDocument::fromJson(data);
    const QJsonArray jsonData = jsonResponse.array();

    if (m_sourceLang == Auto)
    {
        // Parse language
        m_sourceLang = language(Google, jsonData.at(2).toString());
        if (m_sourceLang == NoLanguage)
        {
            resetData(ParsingError, tr("Error: Unable to parse autodetected language"));
            return;
        }
        if (m_onlyDetectLanguage) { return; }
    }

    addSpaceBetweenParts(m_translation);
    addSpaceBetweenParts(m_translationTranslit);
    addSpaceBetweenParts(m_sourceTranslit);
    // FIXME https://github.com/KDE/clazy/blob/master/docs/checks/README-range-loop-detach.md
    for (const QJsonValueRef translationData : jsonData.at(0).toArray())
    {
        const QJsonArray translationArray = translationData.toArray();
        m_translation.append(translationArray.at(0).toString());
        if (m_translationTranslitEnabled) { m_translationTranslit.append(translationArray.at(2).toString()); }
        if (m_sourceTranslitEnabled)      { m_sourceTranslit.append(translationArray.at(3).toString());      }
    }

    if (m_source.size() >= s_googleTranslateLimit) { return; }

    // Translation options
    if (m_translationOptionsEnabled)
    {
        // FIXME https://github.com/KDE/clazy/blob/master/docs/checks/README-range-loop-detach.md
        for (const QJsonValueRef typeOfSpeechData : jsonData.at(1).toArray())
        {
            const QJsonArray typeOfSpeechDataArray = typeOfSpeechData.toArray();
            const QString typeOfSpeech = typeOfSpeechDataArray.at(0).toString();
            // FIXME https://github.com/KDE/clazy/blob/master/docs/checks/README-range-loop-detach.md
            for (const QJsonValueRef wordData : typeOfSpeechDataArray.at(2).toArray())
            {
                const QJsonArray wordDataArray = wordData.toArray();
                const QString word = wordDataArray.at(0).toString();
                const QString gender = wordDataArray.at(4).toString();
                const QJsonArray translationsArray = wordDataArray.at(1).toArray();
                QStringList translations;
                translations.reserve(translationsArray.size());
                for (const QJsonValue &wordTranslation : translationsArray)
                    { translations.append(wordTranslation.toString()); }
                m_translationOptions[typeOfSpeech].append({word, gender, translations});
            }
        }
    }

    // Examples
    if (m_examplesEnabled)
    {
        // FIXME https://github.com/KDE/clazy/blob/master/docs/checks/README-range-loop-detach.md
        for (const QJsonValueRef exampleData : jsonData.at(12).toArray())
        {
            const QJsonArray exampleDataArray = exampleData.toArray();
            const QString typeOfSpeech = exampleDataArray.at(0).toString();
            const QJsonArray example = exampleDataArray.at(1).toArray().first().toArray();

            m_examples[typeOfSpeech].append({example.at(2).toString(), example.at(0).toString()});
        }
    }
}
/*! ***************************************************************************
   \fn requestYandexKey
   \brief request Yandex Key
 *************************************************************************** */
void QOnlineTranslator::requestYandexKey()
{
    const QUrl url(QStringLiteral("https://translate.yandex.com"));
    m_currentReply = m_networkManager->get(QNetworkRequest(url));
}
/*! ***************************************************************************
   \fn parseYandexKey
   \brief parse Yandex Key
 *************************************************************************** */
void QOnlineTranslator::parseYandexKey()
{
    m_currentReply->deleteLater();

    if (m_currentReply->error() != QNetworkReply::NoError)
    {
        resetData(NetworkError, m_currentReply->errorString());
        return;
    }

    // Check availability of service
    const QByteArray webSiteData = m_currentReply->readAll();
    if (webSiteData.isEmpty() || webSiteData.contains("<title>Oops!</title>") || webSiteData.contains("<title>302 Found</title>"))
    {
        resetData(ServiceError, tr("Error: Engine systems have detected suspicious traffic from your computer network. Please try your request again later."));
        return;
    }

    const QByteArray sidBeginString = "SID: '";
    const int sidBeginStringPos = webSiteData.indexOf(sidBeginString);
    if (sidBeginStringPos == -1)
    {
        resetData(ParsingError, tr("Error: Unable to find Yandex SID in web version."));
        return;
    }

    const int sidBeginPosition = sidBeginStringPos + sidBeginString.size();
    const int sidEndPosition = webSiteData.indexOf('\'', sidBeginPosition);
    if (sidEndPosition == -1)
    {
        resetData(ParsingError, tr("Error: Unable to extract Yandex SID from web version."));
        return;
    }

    // Yandex show reversed parts of session ID, need to decode
    const QString sid = webSiteData.mid(sidBeginPosition, sidEndPosition - sidBeginPosition);
    QStringList sidParts = sid.split('.');
    for (int i = 0; i < sidParts.size(); ++i) { std::reverse(sidParts[i].begin(), sidParts[i].end()); }
    //
    s_yandexKey = sidParts.join('.');
}
/*! ***************************************************************************
   \fn request Yandex Translate
   \brief requestYandexTranslate
 *************************************************************************** */
void QOnlineTranslator::requestYandexTranslate()
{
    const QString sourceText = sender()->property(s_textProperty).toString();

    QString lang;
    if (m_sourceLang == Auto) { lang = languageApiCode(Yandex, m_translationLang); }
    else                      { lang = QString("%1-%2").arg(languageApiCode(Yandex, m_sourceLang), languageApiCode(Yandex, m_translationLang)); }

    // Generate API url
    QUrl url(QStringLiteral("https://translate.yandex.net/api/v1/tr.json/translate"));
    url.setQuery(QStringLiteral("id=%1-2-0&srv=tr-text&text=%2&lang=%3").arg(s_yandexKey, QUrl::toPercentEncoding(sourceText), lang));

    // Setup request
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setUrl(url);

    // Make reply
    m_currentReply = m_networkManager->post(request, QByteArray());
}
/*! ***************************************************************************
   \fn parseYandexTranslate
   \brief parse Yandex Translate
 *************************************************************************** */
void QOnlineTranslator::parseYandexTranslate()
{
    m_currentReply->deleteLater();

    // Check for errors
    if (m_currentReply->error() != QNetworkReply::NoError)
    {
        // Network errors
        if (m_currentReply->error() < QNetworkReply::ContentAccessDenied)
        {
            resetData(NetworkError, m_currentReply->errorString());
            return;
        }

        // Parse data to get request error type
        s_yandexKey.clear();
        const QJsonDocument jsonResponse = QJsonDocument::fromJson(m_currentReply->readAll());
        resetData(ServiceError, jsonResponse.object().value(QStringLiteral("message")).toString());
        return;
    }

    // Read Json
    const QJsonDocument jsonResponse = QJsonDocument::fromJson(m_currentReply->readAll());
    const QJsonObject jsonData = jsonResponse.object();

    // Parse language
    if (m_sourceLang == Auto)
    {
        QString sourceCode = jsonData.value(QStringLiteral("lang")).toString();
        sourceCode = sourceCode.left(sourceCode.indexOf('-'));
        m_sourceLang = language(Yandex, sourceCode);
        if (m_sourceLang == NoLanguage)
        {
            resetData(ParsingError, tr("Error: Unable to parse autodetected language"));
            return;
        }
        if (m_onlyDetectLanguage) { return; }
    }

    // Parse translation data
    m_translation += jsonData.value(QStringLiteral("text")).toArray().at(0).toString();
}
/*! ***************************************************************************
   \fn requestYandexSourceTranslit
   \brief request Yandex Source Translit
 *************************************************************************** */
void QOnlineTranslator::requestYandexSourceTranslit()
{
    requestYandexTranslit(m_sourceLang);
}
/*! ***************************************************************************
   \fn parseYandexSourceTranslit
   \brief parse Yandex Source Translit
 *************************************************************************** */
void QOnlineTranslator::parseYandexSourceTranslit()
{
    parseYandexTranslit(m_sourceTranslit);
}
/*! ***************************************************************************
   \fn requestYandexTranslationTranslit
   \brief request Yandex Translation Translit
 *************************************************************************** */
void QOnlineTranslator::requestYandexTranslationTranslit()
{
    requestYandexTranslit(m_translationLang);
}
/*! ***************************************************************************
   \fn parseYandexTranslationTranslit
   \brief parse Yandex Translation Translit
 *************************************************************************** */
void QOnlineTranslator::parseYandexTranslationTranslit()
{
    parseYandexTranslit(m_translationTranslit);
}
/*! ***************************************************************************
   \fn requestYandexDictionary
   \brief request Yandex Dictionary
 *************************************************************************** */
void QOnlineTranslator::requestYandexDictionary()
{
    // Check if language is supported (need to check here because language may be autodetected)
    if (!isSupportDictionary(Yandex, m_sourceLang, m_translationLang) && !m_source.contains(' '))
    {
        auto *state = qobject_cast<QState *>(sender());
        state->addTransition(new QFinalState(state->parentState()));
        return;
    }
    // Generate API url
    const QString text = sender()->property(s_textProperty).toString();
    QUrl url(QStringLiteral("https://dictionary.yandex.net/dicservice.json/lookupMultiple"));
    url.setQuery(QStringLiteral("text=%1&ui=%2&dict=%3-%4").arg(QUrl::toPercentEncoding(text), languageApiCode(Yandex, m_uiLang), languageApiCode(Yandex, m_sourceLang), languageApiCode(Yandex, m_translationLang)));
    //
    m_currentReply = m_networkManager->get(QNetworkRequest(url));
}
/*! ***************************************************************************
   \fn parseYandexDictionary
   \brief parse Yandex Dictionary
 *************************************************************************** */
void QOnlineTranslator::parseYandexDictionary()
{
    m_currentReply->deleteLater();

    if (m_currentReply->error() != QNetworkReply::NoError)
    {
        resetData(NetworkError, m_currentReply->errorString());
        return;
    }
    // Parse reply
    const QJsonDocument jsonResponse = QJsonDocument::fromJson(m_currentReply->readAll());
    const QJsonValue jsonData = jsonResponse.object().value(languageApiCode(Yandex, m_sourceLang) + '-' + languageApiCode(Yandex, m_translationLang)).toObject().value(QStringLiteral("regular"));

    if (m_sourceTranscriptionEnabled)
        { m_sourceTranscription = jsonData.toArray().at(0).toObject().value(QStringLiteral("ts")).toString(); }

    // FIXME https://github.com/KDE/clazy/blob/master/docs/checks/README-range-loop-detach.md
    for (const QJsonValueRef typeOfSpeechData : jsonData.toArray())
    {
        QJsonObject typeOfSpeechObject = typeOfSpeechData.toObject();
        const QString typeOfSpeech = typeOfSpeechObject.value(QStringLiteral("pos")).toObject().value(QStringLiteral("text")).toString();
        // FIXME https://github.com/KDE/clazy/blob/master/docs/checks/README-range-loop-detach.md
        for (const QJsonValueRef wordData : typeOfSpeechObject.value(QStringLiteral("tr")).toArray())
        {
            // Parse translation options
            const QJsonObject wordObject = wordData.toObject();
            const QString word = wordObject.value(QStringLiteral("text")).toString();
            const QString gender = wordObject.value(QStringLiteral("gen")).toObject().value(QStringLiteral("text")).toString();
            const QJsonArray translationsArray = wordObject.value(QStringLiteral("mean")).toArray();
            QStringList translations;
            translations.reserve(translationsArray.size());
            for (const QJsonValue &wordTranslation : translationsArray)
                { translations.append(wordTranslation.toObject().value(QStringLiteral("text")).toString()); }

            m_translationOptions[typeOfSpeech].append({word, gender, translations});

            // Parse examples
            if (m_examplesEnabled && wordObject.contains(QLatin1String("ex")))
            {
                // FIXME https://github.com/KDE/clazy/blob/master/docs/checks/README-range-loop-detach.md
                for (const QJsonValueRef exampleData : wordObject.value(QStringLiteral("ex")).toArray())
                {
                    const QJsonObject exampleObject = exampleData.toObject();
                    const QString example = exampleObject.value(QStringLiteral("text")).toString();
                    const QString description = exampleObject.value(QStringLiteral("tr")).toArray().first().toObject().value(QStringLiteral("text")).toString();

                    m_examples[typeOfSpeech].append({example, description});
                }
            }
        } // end for
    } // end for
} // end parseYandexDictionary
/*! ***************************************************************************
   \fn requestBingCredentials
   \brief request Bing Credentials
 *************************************************************************** */
void QOnlineTranslator::requestBingCredentials()
{
    const QUrl url(QStringLiteral("https://www.bing.com/translator"));
    m_currentReply = m_networkManager->get(QNetworkRequest(url));
}
/*! ***************************************************************************
   \fn parseBingCredentials
   \brief parse Bing Credentials
 *************************************************************************** */
void QOnlineTranslator::parseBingCredentials()
{
    m_currentReply->deleteLater();

    if (m_currentReply->error() != QNetworkReply::NoError)
    {
        resetData(NetworkError, m_currentReply->errorString());
        return;
    }

    const QByteArray webSiteData = m_currentReply->readAll();
    const QByteArray credentialsBeginString = "var params_RichTranslateHelper = [";
    const int credentialsBeginPos = webSiteData.indexOf(credentialsBeginString);
    if (credentialsBeginPos == -1)
    {
        resetData(ParsingError, tr("Error: Unable to find Bing credentials in web version."));
        return;
    }

    const int keyBeginPos = credentialsBeginPos + credentialsBeginString.size();
    const int keyEndPos   = webSiteData.indexOf(',', keyBeginPos);
    if (keyEndPos == -1)
    {
        resetData(ParsingError, tr("Error: Unable to extract Bing key from web version."));
        return;
    }
    s_bingKey = webSiteData.mid(keyBeginPos, keyEndPos - keyBeginPos);

    const int tokenBeginPos = keyEndPos + 2; // Skip two symbols instead of one because the value is enclosed in quotes
    const int tokenEndPos   = webSiteData.indexOf('"', tokenBeginPos);
    if (tokenEndPos == -1)
    {
        resetData(ParsingError, tr("Error: Unable to extract Bing token from web version."));
        return;
    }
    s_bingToken = webSiteData.mid(tokenBeginPos, tokenEndPos - tokenBeginPos);
}
/*! ***************************************************************************
   \fn requestBingTranslate
   \brief request Bing Translate
 *************************************************************************** */
void QOnlineTranslator::requestBingTranslate()
{
    const QString sourceText = sender()->property(s_textProperty).toString();
    // Generate POST data
    const QByteArray postData = QString("&text=%1&fromLang=%2&to=%3&token=%4&key=%5").arg(QUrl::toPercentEncoding(sourceText, languageApiCode(Bing, m_sourceLang).toUtf8()), languageApiCode(Bing, m_translationLang).toUtf8(), s_bingToken, s_bingKey).toLocal8Bit();
    // Setup request
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::UserAgentHeader, QString("%1/%2").arg(QCoreApplication::applicationName(), QCoreApplication::applicationVersion()));
    request.setUrl(QStringLiteral("https://www.bing.com/ttranslatev3"));

    // Make reply
    m_currentReply = m_networkManager->post(request, postData);
}
/*! ***************************************************************************
   \fn parseBingTranslate
   \brief parse Bing Translate
 *************************************************************************** */
void QOnlineTranslator::parseBingTranslate()
{
    m_currentReply->deleteLater();

    // Check for errors
    if (m_currentReply->error() != QNetworkReply::NoError)
    {
        resetData(NetworkError, m_currentReply->errorString());
        return;
    }

    // Parse translation data
    const QJsonDocument jsonResponse = QJsonDocument::fromJson(m_currentReply->readAll());
    const QJsonObject responseObject = jsonResponse.array().first().toObject();

    if (m_sourceLang == Auto)
    {
        const QString langCode = responseObject.value(QStringLiteral("detectedLanguage")).toObject().value(QStringLiteral("language")).toString();
        m_sourceLang = language(Bing, langCode);
        if (m_sourceLang == NoLanguage)
        {
            resetData(ParsingError, tr("Error: Unable to parse autodetected language"));
            return;
        }
        if (m_onlyDetectLanguage) { return; }
    }

    const QJsonObject translationsObject = responseObject.value(QStringLiteral("translations")).toArray().first().toObject();
    m_translation += translationsObject.value(QStringLiteral("text")).toString();
    m_translationTranslit += translationsObject.value(QStringLiteral("transliteration")).toObject().value(QStringLiteral("text")).toString();
}
/*! ***************************************************************************
   \fn requestBingDictionary
   \brief request Bing Dictionary
 *************************************************************************** */
void QOnlineTranslator::requestBingDictionary()
{
    // Check if language is supported (need to check here because language may be autodetected)
    if (!isSupportDictionary(Bing, m_sourceLang, m_translationLang) && !m_source.contains(' '))
    {
        auto *state = qobject_cast<QState *>(sender());
        state->addTransition(new QFinalState(state->parentState()));
        return;
    }
    // Generate POST data
    const QByteArray postData = QString("&text=%1&from=%2&to=%3").arg(QUrl::toPercentEncoding(sender()->property(s_textProperty).toString()), languageApiCode(Bing, m_sourceLang).toUtf8(), languageApiCode(Bing, m_translationLang).toUtf8()).toLocal8Bit();
    //
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setUrl(QStringLiteral("https://www.bing.com/tlookupv3"));

    m_currentReply = m_networkManager->post(request, postData);
}
/*! ***************************************************************************
   \fn parseBingDictionary
   \brief parse Bing Dictionary
 *************************************************************************** */
void QOnlineTranslator::parseBingDictionary()
{
    m_currentReply->deleteLater();

    // Check for errors
    if (m_currentReply->error() != QNetworkReply::NoError)
    {
        resetData(NetworkError, m_currentReply->errorString());
        return;
    }

    const QJsonDocument jsonResponse = QJsonDocument::fromJson(m_currentReply->readAll());
    const QJsonObject responseObject = jsonResponse.array().first().toObject();
    // FIXME https://github.com/KDE/clazy/blob/master/docs/checks/README-range-loop-detach.md
    for (const QJsonValueRef dictionaryData : responseObject.value(QStringLiteral("translations")).toArray())
    {
        const QJsonObject dictionaryObject = dictionaryData.toObject();
        const QString typeOfSpeech = dictionaryObject.value(QStringLiteral("posTag")).toString().toLower();
        const QString word = dictionaryObject.value(QStringLiteral("displayTarget")).toString().toLower();
        const QJsonArray translationsArray = dictionaryObject.value(QStringLiteral("backTranslations")).toArray();
        QStringList translations;
        translations.reserve(translationsArray.size());
        for (const QJsonValue &wordTranslation : translationsArray)
            { translations.append(wordTranslation.toObject().value(QStringLiteral("displayText")).toString()); }

        m_translationOptions[typeOfSpeech].append({word, {}, translations});
    }
}
/*! ***************************************************************************
   \fn buildGoogleStateMachine
   \brief build Google State Machine
 *************************************************************************** */
void QOnlineTranslator::buildGoogleStateMachine()
{
    // States (Google sends translation, translit and dictionary in one request, that will be splitted into several by the translation limit)
    auto *translationState = new QState(m_stateMachine);
    auto *finalState       = new QFinalState(m_stateMachine);
    m_stateMachine->setInitialState(translationState);

    translationState->addTransition(translationState, &QState::finished, finalState);

    // Setup translation state
    buildSplitNetworkRequest(translationState, &QOnlineTranslator::requestGoogleTranslate, &QOnlineTranslator::parseGoogleTranslate, m_source, s_googleTranslateLimit);
}
/*! ***************************************************************************
   \fn buildGoogleDetectStateMachine
   \brief build Google Detect State Machine
 *************************************************************************** */
void QOnlineTranslator::buildGoogleDetectStateMachine()
{
    // States
    auto *detectState = new QState(m_stateMachine);
    auto *finalState  = new QFinalState(m_stateMachine);
    m_stateMachine->setInitialState(detectState);

    detectState->addTransition(detectState, &QState::finished, finalState);

    // Setup detect state
    const QString text = m_source.left(getSplitIndex(m_source, s_googleTranslateLimit));
    buildNetworkRequestState(detectState, &QOnlineTranslator::requestGoogleTranslate, &QOnlineTranslator::parseGoogleTranslate, text);
}
/*! ***************************************************************************
   \fn buildYandexStateMachine
   \brief build Yandex State Machine
 *************************************************************************** */
void QOnlineTranslator::buildYandexStateMachine()
{
    // States
    auto *keyState                 = new QState(m_stateMachine); // Generate SID from web version first to access API
    auto *translationState         = new QState(m_stateMachine);
    auto *sourceTranslitState      = new QState(m_stateMachine);
    auto *translationTranslitState = new QState(m_stateMachine);
    auto *dictionaryState          = new QState(m_stateMachine);
    auto *finalState               = new QFinalState(m_stateMachine);
    m_stateMachine->setInitialState(keyState);

    // Transitions
    keyState->addTransition(keyState, &QState::finished, translationState);
    translationState->addTransition(translationState, &QState::finished, sourceTranslitState);
    sourceTranslitState->addTransition(sourceTranslitState, &QState::finished, translationTranslitState);
    translationTranslitState->addTransition(translationTranslitState, &QState::finished, dictionaryState);
    dictionaryState->addTransition(dictionaryState, &QState::finished, finalState);

    // Setup key state
    if (s_yandexKey.isEmpty())
        { buildNetworkRequestState(keyState, &QOnlineTranslator::requestYandexKey, &QOnlineTranslator::parseYandexKey); }
    else
        { keyState->setInitialState(new QFinalState(keyState)); }

    // Setup translation state
    buildSplitNetworkRequest(translationState, &QOnlineTranslator::requestYandexTranslate, &QOnlineTranslator::parseYandexTranslate, m_source, s_yandexTranslateLimit);

    // Setup source translit state
    if (m_sourceTranslitEnabled)
        { buildSplitNetworkRequest(sourceTranslitState, &QOnlineTranslator::requestYandexSourceTranslit, &QOnlineTranslator::parseYandexSourceTranslit, m_source, s_yandexTranslitLimit); }
    else
        { sourceTranslitState->setInitialState(new QFinalState(sourceTranslitState)); }

    // Setup translation translit state
    if (m_translationTranslitEnabled)
        { buildSplitNetworkRequest(translationTranslitState, &QOnlineTranslator::requestYandexTranslationTranslit, &QOnlineTranslator::parseYandexTranslationTranslit, m_translation, s_yandexTranslitLimit); }
    else
        { translationTranslitState->setInitialState(new QFinalState(translationTranslitState)); }

    // Setup dictionary state
    if (m_translationOptionsEnabled && !isContainsSpace(m_source))
        { buildNetworkRequestState(dictionaryState, &QOnlineTranslator::requestYandexDictionary, &QOnlineTranslator::parseYandexDictionary, m_source); }
    else
        { dictionaryState->setInitialState(new QFinalState(dictionaryState)); }
}
/*! ***************************************************************************
   \fn buildYandexDetectStateMachine
   \brief build Yandex Detect State Machine
 *************************************************************************** */
void QOnlineTranslator::buildYandexDetectStateMachine()
{
    // States
    auto *keyState    = new QState(m_stateMachine); // Generate SID from web version first to access API
    auto *detectState = new QState(m_stateMachine);
    auto *finalState  = new QFinalState(m_stateMachine);
    m_stateMachine->setInitialState(keyState);

    // Transitions
    keyState->addTransition(keyState, &QState::finished, detectState);
    detectState->addTransition(detectState, &QState::finished, finalState);

    // Setup key state
    if (s_yandexKey.isEmpty())
        { buildNetworkRequestState(keyState, &QOnlineTranslator::requestYandexKey, &QOnlineTranslator::parseYandexKey); }
    else
        { keyState->setInitialState(new QFinalState(keyState)); }

    // Setup detect state
    const QString text = m_source.left(getSplitIndex(m_source, s_yandexTranslateLimit));
    buildNetworkRequestState(detectState, &QOnlineTranslator::requestYandexTranslate, &QOnlineTranslator::parseYandexTranslate, text);
}
/*! ***************************************************************************
   \fn buildBingStateMachine
   \brief build Bing State Machine
 *************************************************************************** */
void QOnlineTranslator::buildBingStateMachine()
{
    // States
    auto *credentialsState = new QState(m_stateMachine); // Generate credentials from web version first to access API
    auto *translationState = new QState(m_stateMachine);
    auto *dictionaryState  = new QState(m_stateMachine);
    auto *finalState       = new QFinalState(m_stateMachine);
    m_stateMachine->setInitialState(credentialsState);

    // Transitions
    credentialsState->addTransition(credentialsState, &QState::finished, translationState);
    translationState->addTransition(translationState, &QState::finished, dictionaryState);
    dictionaryState->addTransition(dictionaryState, &QState::finished, finalState);

    // Setup credentials state
    if (s_bingKey.isEmpty() || s_bingToken.isEmpty())
        { buildNetworkRequestState(credentialsState, &QOnlineTranslator::requestBingCredentials, &QOnlineTranslator::parseBingCredentials); }
    else
        { credentialsState->setInitialState(new QFinalState(credentialsState)); }

    // Setup translation state
    buildSplitNetworkRequest(translationState, &QOnlineTranslator::requestBingTranslate, &QOnlineTranslator::parseBingTranslate, m_source, s_bingTranslateLimit);

    // Setup dictionary state
    if (m_translationOptionsEnabled && !isContainsSpace(m_source))
        { buildNetworkRequestState(dictionaryState, &QOnlineTranslator::requestBingDictionary, &QOnlineTranslator::parseBingDictionary, m_source); }
    else
        { dictionaryState->setInitialState(new QFinalState(dictionaryState)); }
}
/*! ***************************************************************************
   \fn buildBingDetectStateMachine
   \brief build Bing Detect State Machine
 *************************************************************************** */
void QOnlineTranslator::buildBingDetectStateMachine()
{
    // States
    auto *detectState = new QState(m_stateMachine);
    auto *finalState  = new QFinalState(m_stateMachine);
    m_stateMachine->setInitialState(detectState);

    detectState->addTransition(detectState, &QState::finished, finalState);

    // Setup translation state
    const QString text = m_source.left(getSplitIndex(m_source, s_bingTranslateLimit));
    buildNetworkRequestState(detectState, &QOnlineTranslator::requestBingTranslate, &QOnlineTranslator::parseBingTranslate, text);
}
/*! ***************************************************************************
   \fn buildSplitNetworkRequest
   \brief build Split Network Request
 *************************************************************************** */
void QOnlineTranslator::buildSplitNetworkRequest(QState *parent, void (QOnlineTranslator::*requestMethod)(), void (QOnlineTranslator::*parseMethod)(), const QString &text, int textLimit)
{
    QString unsendedText       = text;
    auto *nextTranslationState = new QState(parent);
    parent->setInitialState(nextTranslationState);

    while (!unsendedText.isEmpty())
    {
        auto *currentTranslationState = nextTranslationState;
        nextTranslationState = new QState(parent);

        // Do not translate the part if it looks like garbage
        const int splitIndex = getSplitIndex(unsendedText, textLimit);
        if (splitIndex == -1)
        {
            currentTranslationState->setProperty(s_textProperty, unsendedText.left(textLimit));
            currentTranslationState->addTransition(nextTranslationState);
            connect(currentTranslationState, &QState::entered, this, &QOnlineTranslator::skipGarbageText);

            // Remove the parsed part from the next parsing
            unsendedText = unsendedText.mid(textLimit);
        }
        else
        {
            buildNetworkRequestState(currentTranslationState, requestMethod, parseMethod, unsendedText.left(splitIndex));
            currentTranslationState->addTransition(currentTranslationState, &QState::finished, nextTranslationState);

            // Remove the parsed part from the next parsing
            unsendedText = unsendedText.mid(splitIndex);
        }
    }

    nextTranslationState->addTransition(new QFinalState(parent));
}
/*! ***************************************************************************
   \fn buildNetworkRequestState
   \brief build Network Request State
 *************************************************************************** */
void QOnlineTranslator::buildNetworkRequestState(QState *parent, void (QOnlineTranslator::*requestMethod)(), void (QOnlineTranslator::*parseMethod)(), const QString &text)
{
    // Network substates
    auto *requestingState = new QState(parent);
    auto *parsingState    = new QState(parent);

    parent->setInitialState(requestingState);

    // Substates transitions
    requestingState->addTransition(m_networkManager, &QNetworkAccessManager::finished, parsingState);
    parsingState->addTransition(new QFinalState(parent));

    // Setup requesting state
    requestingState->setProperty(s_textProperty, text);
    connect(requestingState, &QState::entered, this, requestMethod);

    // Setup parsing state
    connect(parsingState, &QState::entered, this, parseMethod);
}
/*! ***************************************************************************
   \fn requestYandexTranslit
   \brief request Yandex Translit
 *************************************************************************** */
void QOnlineTranslator::requestYandexTranslit(Language language)
{
    // Check if language is supported (need to check here because language may be autodetected)
    if (!isSupportTranslit(Yandex, language))
    {
        auto *state = qobject_cast<QState *>(sender());
        state->addTransition(new QFinalState(state->parentState()));
        return;
    }

    const QString text = sender()->property(s_textProperty).toString();

    // Generate API url
    QUrl url(QStringLiteral("https://translate.yandex.net/translit/translit"));
    url.setQuery(QString("text=%1&lang=%2").arg(QUrl::toPercentEncoding(text), languageApiCode(Yandex, language)));
    //
    m_currentReply = m_networkManager->get(QNetworkRequest(url));
}
/*! ***************************************************************************
   \fn parseYandexTranslit
   \brief parse Yandex Translit
 *************************************************************************** */
void QOnlineTranslator::parseYandexTranslit(QString &text)
{
    m_currentReply->deleteLater();

    if (m_currentReply->error() != QNetworkReply::NoError)
    {
        resetData(NetworkError, m_currentReply->errorString());
        return;
    }

    const QByteArray reply = m_currentReply->readAll();

    #if QT_VERSION >= QT_VERSION_CHECK(5, 10, 0)
    text += reply.mid(1).chopped(1);
    #else
    text += reply.mid(1);
    text.chop(1);
    #endif
}
/*! ***************************************************************************
   \fn resetData
   \brief reset Data
 *************************************************************************** */
void QOnlineTranslator::resetData(TranslationError error, const QString &errorString)
{
    m_error = error;
    m_errorString = errorString;
    m_translation.clear();
    m_translationTranslit.clear();
    m_sourceTranslit.clear();
    m_sourceTranscription.clear();
    m_translationOptions.clear();
    m_examples.clear();

    m_stateMachine->stop();
    // FIXME https://github.com/KDE/clazy/blob/master/docs/checks/README-range-loop-detach.md
    for (QAbstractState *state : m_stateMachine->findChildren<QAbstractState *>())
    {
        if (!m_stateMachine->configuration().contains(state))
           {  state->deleteLater(); }
    }
}
/*! ***************************************************************************
   \fn isSupportTranslit
   \brief is Support Translit
 *************************************************************************** */
bool QOnlineTranslator::isSupportTranslit(Engine engine, Language lang)
{
    switch (engine)
    {
        case Google:
            isSupportTranslation(Google, lang); // Google supports transliteration for all supported languages
            break;
        case Yandex:
            switch (lang)
            {
                case Amharic:
                case Armenian:
                case Bengali:
                case SimplifiedChinese:
                case Georgian:
                case Greek:
                case Gujarati:
                case Hebrew:
                case Hindi:
                case Japanese:
                case Kannada:
                case Korean:
                case Malayalam:
                case Marathi:
                case Nepali:
                case Punjabi:
                case Russian:
                case Sinhala:
                case Tamil:
                case Telugu:
                case Thai:
                case Yiddish:
                    return true;
                default:
                    return false;
            }
        case Bing:
            switch (lang)
            {
                case Arabic:
                case Bengali:
                case Gujarati:
                case Hebrew:
                case Hindi:
                case Japanese:
                case Kannada:
                case Malayalam:
                case Marathi:
                case Punjabi:
                case SerbianCyrillic:
                case SerbianLatin:
                case Tamil:
                case Telugu:
                case Thai:
                case SimplifiedChinese:
                case TraditionalChinese:
                    return true;
                default:
                    return false;
            }
    }

    return false;
}
/*! ***************************************************************************
   \fn isSupportDictionary
   \brief is Support Dictionary
 *************************************************************************** */
bool QOnlineTranslator::isSupportDictionary(Engine engine, Language sourceLang, Language translationLang)
{
    switch (engine)
    {
        case Google:
            return isSupportTranslation(Google, sourceLang) && isSupportTranslation(Google, translationLang); // Google supports dictionary for all supported languages
        case Yandex:
            switch (sourceLang)
            {
                case Belarusian:
                    switch (translationLang)
                    {
                        case Belarusian:
                        case Russian:
                            return true;
                        default:
                            return false;
                    }
                case Bulgarian:
                    switch (translationLang)
                    {
                        case Russian:
                            return true;
                        default:
                            return false;
                    }
                case Czech:
                case Danish:
                case Dutch:
                case Estonian:
                case Greek:
                case Latvian:
                case Norwegian:
                case Portuguese:
                case Slovak:
                case Swedish:
                    switch (translationLang)
                    {
                        case English:
                        case Russian:
                            return true;
                        default:
                            return false;
                    }
                case German:
                    switch (translationLang)
                    {
                        case German:
                        case English:
                        case Russian:
                        case Turkish:
                            return true;
                        default:
                            return false;
                    }
                case English:
                    switch (translationLang)
                    {
                        case Czech:
                        case Danish:
                        case German:
                        case Greek:
                        case English:
                        case Spanish:
                        case Estonian:
                        case Finnish:
                        case French:
                        case Italian:
                        case Lithuanian:
                        case Latvian:
                        case Dutch:
                        case Norwegian:
                        case Portuguese:
                        case Russian:
                        case Slovak:
                        case Swedish:
                        case Turkish:
                        case Ukrainian:
                            return true;
                        default:
                            return false;
                    }
                case Spanish:
                    switch (translationLang)
                    {
                        case English:
                        case Spanish:
                        case Russian:
                            return true;
                        default:
                            return false;
                    }
                case Finnish:
                    switch (translationLang)
                    {
                        case English:
                        case Russian:
                        case Finnish:
                            return true;
                        default:
                            return false;
                    }
                case French:
                    switch (translationLang)
                    {
                        case French:
                        case English:
                        case Russian:
                            return true;
                        default:
                            return false;
                    }
                case Hungarian:
                    switch (translationLang)
                    {
                        case Hungarian:
                        case Russian:
                            return true;
                        default:
                            return false;
                    }
                case Italian:
                    switch (translationLang)
                    {
                        case English:
                        case Italian:
                        case Russian:
                            return true;
                        default:
                            return false;
                    }
                case Lithuanian:
                    switch (translationLang)
                    {
                        case English:
                        case Lithuanian:
                        case Russian:
                            return true;
                        default:
                            return false;
                    }
                case Mari:
                case HillMari:
                case Polish:
                case Tatar:
                    switch (translationLang)
                    {
                        case Russian:
                            return true;
                        default:
                            return false;
                    }
                case Russian:
                    switch (translationLang)
                    {
                        case Belarusian:
                        case Bulgarian:
                        case Czech:
                        case Danish:
                        case German:
                        case Greek:
                        case English:
                        case Spanish:
                        case Estonian:
                        case Finnish:
                        case French:
                        case Italian:
                        case Lithuanian:
                        case Latvian:
                        case Mari:
                        case HillMari:
                        case Dutch:
                        case Norwegian:
                        case Portuguese:
                        case Russian:
                        case Slovak:
                        case Swedish:
                        case Turkish:
                        case Tatar:
                        case Ukrainian:
                            return true;
                        default:
                            return false;
                    }
                case Turkish:
                    switch (translationLang)
                    {
                        case German:
                        case English:
                        case Russian:
                            return true;
                        default:
                            return false;
                    }
                case Ukrainian:
                    switch (translationLang)
                    {
                        case English:
                        case Russian:
                        case Ukrainian:
                            return true;
                        default:
                            return false;
                    }
                default:
                    return false;
            }
        case Bing:
            // Bing support dictionary only to or from English
            Language secondLang;
            if      (sourceLang == English)      { secondLang = translationLang; }
            else if (translationLang == English) { secondLang = sourceLang; }
            else                                 { return false; }

            switch (secondLang)
            {
                case Afrikaans:
                case Arabic:
                case Bengali:
                case Bosnian:
                case Bulgarian:
                case Catalan:
                case SimplifiedChinese:
                case Croatian:
                case Czech:
                case Danish:
                case Dutch:
                case Estonian:
                case Finnish:
                case French:
                case German:
                case Greek:
                case HaitianCreole:
                case Hebrew:
                case Hindi:
                case Hmong:
                case Hungarian:
                case Icelandic:
                case Indonesian:
                case Italian:
                case Japanese:
                case Swahili:
                case Klingon:
                case Korean:
                case Latvian:
                case Lithuanian:
                case Malay:
                case Maltese:
                case Norwegian:
                case Persian:
                case Polish:
                case Portuguese:
                case Romanian:
                case Russian:
                case SerbianLatin:
                case Slovak:
                case Slovenian:
                case Spanish:
                case Swedish:
                case Tamil:
                case Thai:
                case Turkish:
                case Ukrainian:
                case Urdu:
                case Vietnamese:
                case Welsh:
                    return true;
                default:
                    return false;
            }
    }

    return false;
}
/*! ***************************************************************************
   \fn languageApiCode
   \brief  Returns engine-specific language code for translation
 *************************************************************************** */
QString QOnlineTranslator::languageApiCode(Engine engine, Language lang)
{
    if (!isSupportTranslation(engine, lang)) { return QString(); }

    switch (engine)
    {
        case Google: return s_googleLanguageCodes.value(lang, s_genericLanguageCodes.value(lang));
        case Yandex: return s_yandexLanguageCodes.value(lang, s_genericLanguageCodes.value(lang));
        case Bing:   return   s_bingLanguageCodes.value(lang, s_genericLanguageCodes.value(lang));
    }

    Q_UNREACHABLE();
}
/*! ***************************************************************************
   \fn language
   \brief Parse language from response language code
 *************************************************************************** */
QOnlineTranslator::Language QOnlineTranslator::language(Engine engine, const QString &langCode)
{
    // Engine exceptions
    switch (engine)
    {
        case Google: return s_googleLanguageCodes.key(langCode, s_genericLanguageCodes.key(langCode, NoLanguage));
        case Yandex: return s_yandexLanguageCodes.key(langCode, s_genericLanguageCodes.key(langCode, NoLanguage));
        case Bing:   return   s_bingLanguageCodes.key(langCode, s_genericLanguageCodes.key(langCode, NoLanguage));
    }

    Q_UNREACHABLE();
}
/*! ***************************************************************************
   \fn getSplitIndex
   \brief get Split Index
 *************************************************************************** */
// Get split index of the text according to the limit
int QOnlineTranslator::getSplitIndex(const QString &untranslatedText, int limit)
{
    if (untranslatedText.size() < limit) { return limit; }
    //
    int splitIndex = untranslatedText.lastIndexOf(QLatin1String(". "), limit - 1);
    if (splitIndex != -1) { return splitIndex + 1; }
    //
    splitIndex = untranslatedText.lastIndexOf(' ', limit - 1);
    if (splitIndex != -1) { return splitIndex + 1; }
    //
    splitIndex = untranslatedText.lastIndexOf('\n', limit - 1);
    if (splitIndex != -1) { return splitIndex + 1; }
    // Non-breaking space
    splitIndex = untranslatedText.lastIndexOf(0x00a0, limit - 1);
    if (splitIndex != -1) { return splitIndex + 1; }
    // If the text has not passed any check and is most likely garbage
    return limit;
}
/*! ***************************************************************************
   \fn isContainsSpace
   \brief is Contains Space
 *************************************************************************** */
bool QOnlineTranslator::isContainsSpace(const QString &text)
{
    return std::any_of(text.cbegin(), text.cend(), [](QChar symbol)
    {
        return symbol.isSpace();
    });
}
/*! ***************************************************************************
   \fn addSpaceBetweenParts
   \brief add Space Between Parts
 *************************************************************************** */
void QOnlineTranslator::addSpaceBetweenParts(QString &text)
{
    if (text.isEmpty()) { return; }

    #if QT_VERSION >= QT_VERSION_CHECK(5, 10, 0)
    if (!text.back().isSpace())
    #else
    if (!text.at(text.size() - 1).isSpace())
    #endif
    {
        text.append(' ');
    }
}
/******************************* End of File *********************************/
