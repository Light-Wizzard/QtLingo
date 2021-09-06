/*
 @licstart  The following is the entire license notice for the JavaScript code in this file.

 The MIT License (MIT)

 Copyright (C) 1997-2020 by Dimitri van Heesch

 Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 and associated documentation files (the "Software"), to deal in the Software without restriction,
 including without limitation the rights to use, copy, modify, merge, publish, distribute,
 sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all copies or
 substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 @licend  The above is the entire license notice for the JavaScript code in this file
*/
var NAVTREE =
[
  [ "QtLingo", "index.html", [
    [ "QExample", "md_src_third_party_qonlinetranslator_docs_QExample.html", [
      [ "Content", "md_src_third_party_qonlinetranslator_docs_QExample.html#autotoc_md1", null ],
      [ "Public Members", "md_src_third_party_qonlinetranslator_docs_QExample.html#autotoc_md2", null ],
      [ "Public Functions", "md_src_third_party_qonlinetranslator_docs_QExample.html#autotoc_md3", null ],
      [ "Detailed Description", "md_src_third_party_qonlinetranslator_docs_QExample.html#autotoc_md4", null ],
      [ "Members Documentation", "md_src_third_party_qonlinetranslator_docs_QExample.html#autotoc_md6", [
        [ "<a id='example'/> <a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a> QExample::example", "md_src_third_party_qonlinetranslator_docs_QExample.html#autotoc_md7", null ],
        [ "<a id='description'/> <a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a> QExample::description", "md_src_third_party_qonlinetranslator_docs_QExample.html#autotoc_md9", null ]
      ] ],
      [ "Member Function Documentation", "md_src_third_party_qonlinetranslator_docs_QExample.html#autotoc_md10", [
        [ "<a id='tojson'/> <a href=\"https://doc.qt.io/qt-5/qjsonobject.html\" title=\"Qt Documentation\" >QJsonObject</a> QExample::toJson()", "md_src_third_party_qonlinetranslator_docs_QExample.html#autotoc_md11", null ]
      ] ]
    ] ],
    [ "QOnlineTranslator", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html", [
      [ "Content", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md13", null ],
      [ "Public Types", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md14", null ],
      [ "Public Functions", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md15", null ],
      [ "Signals", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md16", null ],
      [ "Static Public Members", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md17", null ],
      [ "Member Type Documentation", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md18", [
        [ "<a id='language'/> enum QOnlineTranslator::Language", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md19", null ],
        [ "<a id='engine'/> enum QOnlineTranslator::Engine", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md20", null ],
        [ "<a id='translation-error'/> enum QOnlineTranslator::TranslationError", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md21", null ]
      ] ],
      [ "Member Function Documentation", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md22", [
        [ "<a id='constructor'/> QOnlineTranslator::QOnlineTranslator(<em>QObject *parent = nullptr</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md23", null ],
        [ "<a id='translate'/> void QOnlineTranslator::translate(<em>const QString &text, Engine engine = Google, Language translationLang = Auto, Language sourceLang = Auto, Language uiLang = Auto</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md25", null ],
        [ "<a id='detect-language'/> void QOnlineTranslator::detectLanguage(<em>const QString &text, Engine engine = Google</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md27", null ],
        [ "<a id='abort'/> void QOnlineTranslator::abort()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md29", null ],
        [ "<a id='is-running'/> bool QOnlineTranslator::isRunning()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md31", null ],
        [ "<a id='tojson'/> <a href=\"https://doc.qt.io/qt-5/qjsonobject.html\" title=\"Qt Documentation\" >QJsonDocument</a> QOnlineTranslator::toJson()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md33", null ],
        [ "<a id='source'/> <a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a> QOnlineTranslator::source()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md35", null ],
        [ "<a id='source-transliteration'/> <a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a> QOnlineTranslator::sourceTranslit()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md37", null ],
        [ "<a id='finished-signal'/> void QOnlineTranslator::finished()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md39", null ],
        [ "<a id='source-language-name'/> <a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a> QOnlineTranslator::sourceLanguageName()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md41", null ],
        [ "<a id='source-language'/> Language QOnlineTranslator::sourceLanguage()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md43", null ],
        [ "<a id='translation'/> <a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a> QOnlineTranslator::translation()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md45", null ],
        [ "<a id='translation-translit'/> <a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a> QOnlineTranslator::translationTranslit()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md47", null ],
        [ "<a id='source-transcription'/> <a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a> QOnlineTranslator::sourceTranscription()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md49", null ],
        [ "<a id='translation-language-name'/> <a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a> QOnlineTranslator::translationLanguageName()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md51", null ],
        [ "<a id='translation-language'/> Language QOnlineTranslator::translationLanguage()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md53", null ],
        [ "<a id='translation-options'/> <a href=\"https://doc.qt.io/qt-5/qmap.html\" title=\"Qt Documentation\" >QMap</a><<a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a>, <a href=\"https://doc.qt.io/qt-5/qvector.html\" title=\"Qt Documentation\" >QVector</a><@ref /home/jflesher/workspace/QtLingo/QtLingo/src/third-party/qonlinetranslator/docs/QOption.md \"QOption\">> QOnlineTranslator::translationOptions()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md55", null ],
        [ "<a id='examples'/> <a href=\"https://doc.qt.io/qt-5/qmap.html\" title=\"Qt Documentation\" >QMap</a><<a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a>, <a href=\"https://doc.qt.io/qt-5/qvector.html\" title=\"Qt Documentation\" >QVector</a><@ref /home/jflesher/workspace/QtLingo/QtLingo/src/third-party/qonlinetranslator/docs/QExample.md \"QExample\">> QOnlineTranslator::examples()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md57", null ],
        [ "<a id='error'/> TranslationError QOnlineTranslator::error()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md59", null ],
        [ "<a id='error-string'/> <a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a> QOnlineTranslator::errorString()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md61", null ],
        [ "<a id='is-source-translit-enabled'/> bool QOnlineTranslator::isSourceTranslitEnabled()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md63", null ],
        [ "<a id='set-source-translit-enabled'/> void QOnlineTranslator::setSourceTranslitEnabled(<em>bool enable</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md65", null ],
        [ "<a id='is-translation-translit-enabled'/> bool QOnlineTranslator::isTranslationTranslitEnabled()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md67", null ],
        [ "<a id='set-translation-translit-enabled'/> void QOnlineTranslator::setTranslationTranslitEnabled(<em>bool enable</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md69", null ],
        [ "<a id='is-source-transcription-enabled'/> bool QOnlineTranslator::isSourceTranscriptionEnabled()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md71", null ],
        [ "<a id='set-source-transcription-enabled'/> void QOnlineTranslator::setSourceTranscriptionEnabled(<em>bool enable</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md73", null ],
        [ "<a id='is-dictionary-enabled'/> bool QOnlineTranslator::isDictionaryEnabled()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md75", null ],
        [ "<a id='set-dictionary-enabled'/> void QOnlineTranslator::setDictionaryEnabled(<em>bool enable</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md77", null ],
        [ "<a id='is-definitions-enabled'/> bool QOnlineTranslator::isDefinitionsEnabled()", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md79", null ],
        [ "<a id='set-definitions-enabled'/> void QOnlineTranslator::setDefinitionsEnabled(<em>bool enable</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md81", null ],
        [ "<a id='language-name'/> static <a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a> QOnlineTranslator::languageName(<em>Language language</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md83", null ],
        [ "<a id='language-code'/> static <a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a> QOnlineTranslator::languageCode(<em>Language language</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md85", null ],
        [ "<a id='language-1'/> static Language QOnlineTranslator::language(<em>const QLocale &locale</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md87", null ],
        [ "<a id='language-2'/> static Language QOnlineTranslator::language(<em>const QString &languageCode</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md89", null ],
        [ "<a id='is-support-translation'/> static bool QOnlineTranslator::isSupportTranslation(<em>Engine engine, Language lang</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTranslator.html#autotoc_md91", null ]
      ] ]
    ] ],
    [ "QOnlineTts", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html", [
      [ "Content", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html#autotoc_md93", null ],
      [ "Public Types", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html#autotoc_md94", null ],
      [ "Public Functions", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html#autotoc_md95", null ],
      [ "Static Public Members", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html#autotoc_md96", null ],
      [ "Member Type Documentation", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html#autotoc_md97", [
        [ "<a id='voice'/> enum QOnlineTts::Voice", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html#autotoc_md98", null ],
        [ "<a id='emotion'/> enum QOnlineTts::Emotion", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html#autotoc_md99", null ],
        [ "<a id='tts-error'/> enum QOnlineTts::TtsError", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html#autotoc_md100", null ]
      ] ],
      [ "Member Function Documentation", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html#autotoc_md101", [
        [ "<a id='constructor'/> QOnlineTts::QOnlineTts(<em>QObject *parent = nullptr</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html#autotoc_md102", null ],
        [ "<a id='generate-urls'/> void QOnlineTts::generateUrls(<em>const QString &text, QOnlineTranslator::Engine engine, QOnlineTranslator::Language lang, Voice voice = DefaultVoice, Emotion emotion = DefaultEmotion</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html#autotoc_md104", null ],
        [ "<a id='error'/> TranslationError QOnlineTts::error()", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html#autotoc_md106", null ],
        [ "<a id='error-string'/> <a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a> QOnlineTts::errorString()", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html#autotoc_md108", null ],
        [ "<a id='voice-code'/> static <a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a> QOnlineTts::voiceCode(<em>Voice voice</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html#autotoc_md110", null ],
        [ "<a id='emotion-code'/> static <a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a> QOnlineTts::emotionCode(<em>Emotion emotion</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html#autotoc_md112", null ],
        [ "<a id='emotion'/> static Emotion QOnlineTts::emotion(<em>const QString &emotionCode</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html#autotoc_md114", null ],
        [ "<a id='voice'/> static Voice QOnlineTts::voice(<em>const QString &voiceCode</em>)", "md_src_third_party_qonlinetranslator_docs_QOnlineTts.html#autotoc_md116", null ]
      ] ]
    ] ],
    [ "QOption", "md_src_third_party_qonlinetranslator_docs_QOption.html", [
      [ "Content", "md_src_third_party_qonlinetranslator_docs_QOption.html#autotoc_md118", null ],
      [ "Public Members", "md_src_third_party_qonlinetranslator_docs_QOption.html#autotoc_md119", null ],
      [ "Public Functions", "md_src_third_party_qonlinetranslator_docs_QOption.html#autotoc_md120", null ],
      [ "Detailed Description", "md_src_third_party_qonlinetranslator_docs_QOption.html#autotoc_md121", null ],
      [ "Members Documentation", "md_src_third_party_qonlinetranslator_docs_QOption.html#autotoc_md123", [
        [ "<a id='word'/> <a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a> QOption::word", "md_src_third_party_qonlinetranslator_docs_QOption.html#autotoc_md124", null ],
        [ "<a id='gender'/> <a href=\"https://doc.qt.io/qt-5/qstring.html\" title=\"Qt Documentation\" >QString</a> QOption::gender", "md_src_third_party_qonlinetranslator_docs_QOption.html#autotoc_md126", null ],
        [ "<a id='translations'/> <a href=\"https://doc.qt.io/qt-5/qstringlist.html\" title=\"Qt Documentation\" >QStringList</a> QOption::translations", "md_src_third_party_qonlinetranslator_docs_QOption.html#autotoc_md128", null ]
      ] ],
      [ "Member Function Documentation", "md_src_third_party_qonlinetranslator_docs_QOption.html#autotoc_md129", [
        [ "<a id='tojson'/> <a href=\"https://doc.qt.io/qt-5/qjsonobject.html\" title=\"Qt Documentation\" >QJsonObject</a> QOption::toJson()", "md_src_third_party_qonlinetranslator_docs_QOption.html#autotoc_md130", null ]
      ] ]
    ] ],
    [ "Namespaces", "namespaces.html", [
      [ "Namespace List", "namespaces.html", "namespaces_dup" ],
      [ "Namespace Members", "namespacemembers.html", [
        [ "All", "namespacemembers.html", null ],
        [ "Typedefs", "namespacemembers_type.html", null ]
      ] ]
    ] ],
    [ "Classes", "annotated.html", [
      [ "Class List", "annotated.html", "annotated_dup" ],
      [ "Class Index", "classes.html", null ],
      [ "Class Hierarchy", "hierarchy.html", "hierarchy" ],
      [ "Class Members", "functions.html", [
        [ "All", "functions.html", "functions_dup" ],
        [ "Functions", "functions_func.html", "functions_func" ],
        [ "Variables", "functions_vars.html", "functions_vars" ],
        [ "Typedefs", "functions_type.html", null ],
        [ "Enumerations", "functions_enum.html", null ],
        [ "Enumerator", "functions_eval.html", "functions_eval" ],
        [ "Related Functions", "functions_rela.html", null ]
      ] ]
    ] ],
    [ "Files", "files.html", [
      [ "File List", "files.html", "files_dup" ],
      [ "File Members", "globals.html", [
        [ "All", "globals.html", "globals_dup" ],
        [ "Functions", "globals_func.html", null ],
        [ "Typedefs", "globals_type.html", null ],
        [ "Macros", "globals_defs.html", "globals_defs" ]
      ] ]
    ] ]
  ] ]
];

var NAVTREEINDEX =
[
"MainWindow_8cpp.html",
"classMyOrgSettings.html#a2581082145269c6d97a03441ef55f23eae97546c444b231727d08f727f0990328",
"classQOnlineTranslator.html#aebb2566af08a68eb014fe0698a10f73daa96fb82b352ff44143166059154dd9d3",
"classUi__MainWindow.html#a87d9efce9e074ce57ff61c896a9ee71a",
"globals_defs_v.html",
"moc__predefs_8h.html#a4d4e419b93a42fbd34e0f4ae3640c4a9",
"moc__predefs_8h.html#ade7aebdae6e8389a450aac653544c33f"
];

var SYNCONMSG = 'click to disable panel synchronisation';
var SYNCOFFMSG = 'click to enable panel synchronisation';