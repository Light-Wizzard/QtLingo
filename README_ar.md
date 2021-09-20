# QtLingo

QtLingo هو تطبيق لتسهيل ترجمة Qt ،
سيطلب منك التدفق العادي تحرير الملفات واستبدال الكلمات بترجماتها ،
هذا الكثير من العمل بالنسبة لي ،
لذلك قررت أن أجعل الأمر أسهل ،
قم بتشغيل هذا التطبيق وقم بإعداد مشروع من خلال إعطائه موقع المجلد واسم مشروعك ،
أعطه الموقع حيث تريد ملفات .ts ،
ووجهة لملفات .qm ،
وتجميعها ،
وسوف يعطيك التكوين لـ qmake أو cmake ،
وقم فقط بتحديث ملفاتك بهذا الرمز ،
ونشر مشروعك ،
لقد تم كل شيء ، ليس هناك المزيد للقيام به.

## حالة

[! [حالة إصدار Appveyor] (https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6؟svg=true)] (https://ci.appveyor.com/project/Light-Wizzard/qtlingo)

###: الحزمة: ** التنزيلات: **

-: penguin: [Linux x64 zip] (https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Ubuntu-Release-x64.zip)
-: المكتب: [Windows x64 zip] (https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Windows-Release-x64.zip)
-: apple: [Apple x64 zip] (https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-MacOs-Release-x64.zip)

Windows (تم اختباره في 7 و 10 ، أخبرني إذا كان 8 يعمل): قم بتنزيل zip واستخرجه ،
وقم بتشغيل الملف QtLingo.exe داخل مجلد نشر AppDir.

أبل لا تختبر لأنني لا أملك واحدة.

# التوثيق

أحاول تحميل ملفات Doxygen على هذا الموقع ، لا يعمل حتى الآن.
[توثيق] (https://light-wizzard.github.io/QtLingo/)

# مشاريع GitHub والمشاريع الأخرى المستخدمة

أستخدم تطبيقات جيثب لهذا الغرض ،
بالنسبة إلى الترجمات ، أستخدم الترجمة الجماعية على https://github.com/crow-translate/crow-translate ،
و QOnlineTranslator على https://github.com/crow-translate/QOnlineTranslator ،
ولتحليل ملفات .ts أستخدم ts_tool على https://github.com/nen777w/ts_tool ،
واستخدمت https://wiki.qt.io/Simple_encryption_with_SimpleCrypt#Versions.

# معالجة

انقر أولاً على Compile لتحديث ملفات ترجمات مشاريعك وفقًا للغات التي اخترتها ،
أسميها compile لأن هذه هي جميع الملفات التي يتم تجميعها في تطبيقك ،
ثم انقر فوق قبول الكل أو استخدم Qt Lingustic لتجميع كل ترجمة ،
ثم انقر فوق "تحديث التعليمات" و "الملف التمهيدي" وترجمات تلك الملفات ،
إنشاء ملفات برمز اللغة.

# دوكسجين

أنا أستخدم Doxygen ، يمكنك تشغيله من الأوامر أدناه.

"" باش
دوكسجين Doxyfile

أو

دوكسيويارد
""

لدي مستندات Doxygen ضمن المستندات.

# مشاكل

التعامل مع انقطاع الاتصال بالإنترنت.

""
الحرجة: "انتهت مهلة عملية المقبس" (../QtLingo/src/MainWindow.cpp:2280، MainWindow :: translateWithReturn (const QString &، QOnlineTranslator :: Engine، QOnlineTranslator :: Language، QOnlineTranslator :: Language، QOnlineTranslator) :: <lambda ()>)
هام: "المضيف www.bing.com غير موجود" (../QtLingo/src/MainWindow.cpp:2280، MainWindow :: translateWithReturn (const QString &، QOnlineTranslator :: Engine، QOnlineTranslator :: Language، QOnlineTranslator :: Language، QOnlineTranslator :: اللغة) :: <lambda ()>)
الحرجة: "لم يتم العثور على Host translate.yandex.com" (../QtLingo/src/MainWindow.cpp:2280، MainWindow :: translateWithReturn (const QString &، QOnlineTranslator :: Engine، QOnlineTranslator :: Language، QOnlineTranslator :: Language، QOnline :: اللغة) :: <lambda ()>)
هام: "لم يتم العثور على Host translate.googleapis.com" (../QtLingo/src/MainWindow.cpp:2280، MainWindow :: translateWithReturn (const QString &، QOnlineTranslator :: Engine، QOnlineTranslator :: Language، QOnlineTranslator :: Language، QOnline :: اللغة) :: <lambda ()>)

""

# ائتمانات

لقد استخدمت عددًا قليلاً من مشاريع GitHub التي ذكرتها أعلاه ، كل شيء آخر
كتبه جيفري سكوت فليشر The Light Wizzard in the Flesh

### نهاية الملف