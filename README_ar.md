# آلة حاسبة غالاكسي 2

تحتوي Galaxy Calculator 2 على 4 حاسبات مدمجة:

1.: Milky_way: Galatic Calculator
2.: مرتبك: حاسبة الجنون
3.: earth_americas: Planet Calculator
4.: الكمبيوتر: آلة حاسبة

لقد استخدمت ملفات المشروع من أول حاسبة جالاكسي مكتوبة باستخدام Qt QML و JavaScript ،
هذا واحد يستخدم Qt C ++ و Widgets ،
لذلك قد يكون التوثيق غريبًا حتى تسنح لي الفرصة لإصلاح جميع الروابط وتحويلها إلى هذا المشروع الجديد ،
سأضطر إلى جعل Travis و AppYeyer مشروعين ، لذلك هذا عمل قيد التقدم.

تعتمد حاسبات المجرة والجنون والكوكب على حسابات السير إسحاق نيوتن ،
وتم تحديثه ليشمل الرياضيات نيكولا تيسلا ،
وهكذا ابتكر نوعًا جديدًا من الرياضيات أسميه الرياضيات الثلاثية ، والتي تُستخدم لحساب المجرة.

هذا المشروع مفتوح المصدر ، بدون ترخيص مطلوب ، هذا تطبيق Qt C ++ ،
التي سيتم تشغيلها على سطح المكتب والأجهزة الأخرى ، يتم تضمين البرنامج النصي bash الذي استخدمته لنقل هذا التطبيق.

يمكن تجميع هذا التطبيق لأي نظام تشغيل تدعمه Qt: Linux و Windows و MAC و Android و iOS ،
بالإضافة إلى كل نظام تشغيل يدعمه Qt ، لذلك يجب أن يعمل هذا على معظم إن لم يكن جميع أنظمة التشغيل الشائعة.

سأحاول جعل المثبتات وقابلة للتنفيذ لجميع أنظمة تشغيل Qt المدعومة ، حاليًا لدي:

إذا كانت الشارات خضراء ، فيجب أن تكون قادرًا على تنزيل التطبيقات ، إذا لم تكن كذلك ،
ربما أعمل عليه ، لكن لا يستغرق الأمر سوى بضع دقائق للتحديث.

هذا المشروع قيد العمل ، لذلك قد تتعطل الملفات ، ولكن يجب تشغيل التعليمات البرمجية المصدر إذا تم تجميعها على أي جهاز.

يعمل Qt Installer Framework لنظام التشغيل Linux وربما Windows ولكن لن يتم تنزيل برنامج التثبيت ،
في العمل ، لدي برنامج تثبيت لنظام التشغيل Windows 10 أدناه ، لست متأكدًا من 8 ، ولكن ليس 7.

## قائمة المحتويات

1. [الحالة] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Status)
2. [التطور - التقدم] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Development-Progress)
3. [الخلفية] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Background)
4. [لقطات شاشة] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#Screen-Shots)
5. [لقطات شاشة] (https://github.com/Light-Wizzard/Galaxy-Calculator-2#3rd-Party-Code)
6. [Wiki] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki)
7. [وثائق Doxygen] (https://light-wizzard.github.io/Galaxy-Calculator-2)

# حالة

[! [حالة إصدار Appveyor] (https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6؟svg=true)] (https://ci.appveyor.com/project/Light-Wizzard/Galaxy- آلة حاسبة -2)

##: الحزمة: ** التنزيلات: **

 -: penguin: [Linux] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage)
 -: البطريق:: inbox_tray: [Linux ZSync] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage.zsync)
 -: penguin:: outbox_tray: [Linux Installer in work] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-Linux-Installer)
 -: المكتب: [Windows zip] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2-Windows.zip)
 -: office:: outbox_tray: [Windows Installer exe] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2.exe)
 -: apple: [Apple] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2.dmg)

Windows (تم اختباره في 7 و 10 ، أخبرني إذا كان 8 يعمل): قم بتنزيل zip واستخرجه ، وقم بتشغيل الملف Galaxy-Calculator-2.exe داخل مجلد النشر.

جميع كتبي مجانية عبر الإنترنت على http://LightWizzard.com ، ولكن طباعتها أو دفع ePubs إلى جهازك يكلف مالاً.

أنا لا أنشر كتبي هنا ، يمكنك قراءتها مجانًا على موقعي
[حساب Github Light-Wizzard / The-Principles-Of-The-Trinary-Universe] (https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe) ،
ولكن عليك أن تدفع مقابل الكتب المطبوعة ، أو سهولة الحصول على ePub من خلال أجهزتك ePub Reader ، دون الحاجة إلى تنزيله.

الكتاب المطبوع و ePub متوفران في:

لولو
*: الكتاب: الكمبيوتر: http://www.lulu.com/spotlight/LightWizzard

أمازون
*: كتاب: كتاب https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
*: الكمبيوتر: ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

يمكنك أيضًا الحصول عليها من أي متجر كتب كبير ، لكنني أوصي بقراءتها ، إذا كنت تريد معرفة كل التفاصيل حول الرياضيات ، فلن تجدها في الكود بنفس القدر.

إذا كنت لا ترى نظام التشغيل الخاص بك ، فما عليك سوى تنزيله واستخراجه إلى مجلد وافتحه باستخدام Qt Creator ، والذي يجب تثبيته وتجميعه أو تشغيله.

# التقدم في عملية التنمية

يجب أن تفهم العلوم الثلاثية والكون الثلاثي لفهم آلة حاسبة المجرة ،
ولكن في الأساس Trinary له نفس المعنى الذي استخدمه Trinity للسير إسحاق نيوتن ، فهو يصف التيار المتردد أو التيار المتردد ،
الآب هو +1 ، والابن هو -1 ، والروح القدس أو روح الطبيعة الأم هو 0 ، لذلك فهو منطق ثلاثي مع: +1 ، -1 و 0 كمستويات منطقية ،
أستخدم اسم ترياري لأن نيوتن كره تعاليم المسيح.

هناك شاشة التكوين حيث يمكنك تكوين Galaxy ، يمكنك تسمية Galaxy ، وتعيين حجم الشمس بالأميال في القطر ،
اضبط حجم الكواكب الحية بالأميال في القطر ، واضبط عدد المحركات الثلاثية ، وانظر التعليمات لمزيد من التفاصيل ،
ونصف قطر المجرة بالأميال في القطر ، وعدد المسارات التي تريد طباعتها.

أزلت ميزة التخزين المحلي بسبب الأذونات على بعض الأجهزة.

# خلفية

آلة حاسبة غالاكسي هي نقرة زر واحدة للحساب ، فهي تسجل رقم المسار ، وكم عدد المحركات الثلاثية اللازمة لتكون على هذا المسار ،
الحد الأدنى والأقصى لسرعة شموس بالأميال في الساعة ، وتكرار الكواكب الصالحة للعيش ، والمسافة المدارية للشمس بالأميال ، وتكرار المسارات ،
التي استخدمها السير إسحاق نيوتن لتحديد موعد نهاية الحضارة ، ووفقًا لحساباته وحساباتي ،
الذي سيحدث في عام 2060 وفقًا للتقويم اليولياني الذي لا يزال الجيش يستخدمه ، أو 2061 وفقًا للتقويم الغريغوري المستخدم اليوم ،
كانت هذه نفس العملية الحسابية التي أعطيت للجمهور ، لكن القليل منهم يعرفون كيف حسبها ، لقد كتبت معادلة جديدة ، لأنني لم أجد معادلته الأصلية.

أحرق السير إسحاق نيوتن نسخته من حساباته لعام 2060 ، وكتب أنها ثقيلة الوزن على روحه ، لذلك كان عليه أن يتركها ،
وكتب أن أي شخص يريد أن يعرف ، يمكنه معرفة ذلك ، كل الصيغ موجودة في الكتاب المقدس ، بعد 36 عامًا وجدتها جميعًا.

تمت كتابة Galaxy Calculator للاستخدام ، بعد أن فكرت في نص bash الذي أنشأ هذه الصفحة:

http://LightWizzard.com/books/trinary.universe/appendix.a.html

لم يقم البرنامج النصي bash بتخزين الصفحة فحسب ، بل قام بحساب قيم الجدول.

آمل أن يساعد هذا الجميع في تصور ما يحتاج التطبيق إلى القيام به ، وهو فقط رسم بياني ورسم مسار النجوم حول المجرة.

هذه ليست Galaxy Simulator ، فقط رسم بياني ومؤامرة ، وهذا أمر مهم جدًا لفهمه ،
أرغب في كتابة Galaxy Simulator الذي تم تصميمه باستخدام القوانين والقواعد أو الإلكترونيات فقط ،
وسيُطلق على هذا المشروع اسم Galaxy Simulator ، ولماذا يُطلق على هذا المشروع اسم آلة حاسبة غالاكسي ،
لكني أبحث في استخدام Qt 3D Studio لمحاكاة جهاز محاكاة.

لمزيد من المعلومات ، راجع: [Wiki] (https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki)

هذا عمل قيد التقدم ، يرجى الإبلاغ عن أي أخطاء وتعليقات.

# لقطات شاشة

! [تكوين Galaxy] (/ doc / images / screenshot-config.png؟ raw = true "تكوين Galaxy")

! [Galaxy Calculator] (/ doc / images / screenshot-galaxy.png؟ raw = true "Galaxy Calculator")

! [حاسبة الطاقة] (/ doc / images / screenshot-energy.png؟ raw = true "حاسبة الطاقة")

! [آلة حاسبة الجنون] (/ doc / images / screenshot-madness.png؟ raw = true "Madness Calculator")

! [World Calculator] (/ doc / images / screenshot-world.png؟ raw = true "حاسبة الكوكب")

! [الآلة الحاسبة] (/ doc / images / screenshot-calc.png؟ raw = true "الآلة الحاسبة")


# رمز الطرف الثالث

[QCalculator] (https://github.com/xenotux/qcalc)
https://github.com/xenotux/qcalc

GMP Dll لنظام التشغيل Windows
https://osdn.net/projects/mingw/releases/69295

MPFR Dll لنظام التشغيل Windows
https://osdn.net/projects/mingw/releases/69297


نهاية الملف README.md