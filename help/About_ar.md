# حول QtLingo

QtLingo هو تطبيق لتسهيل ترجمة Qt للكمبيوتر ،
وشيء لم أره من قبل ،
لذلك فهو مفهوم جديد لترجمات Qt.

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

أستخدم تطبيقات جيثب لهذا الغرض ،
بالنسبة إلى الترجمات ، أستخدم الترجمة الجماعية على https://github.com/crow-translate/crow-translate ،
و QOnlineTranslator على https://github.com/crow-translate/QOnlineTranslator ،
ولتحليل ملفات .ts أستخدم ts_tool على https://github.com/nen777w/ts_tool.

أولاً سوف أقوم بتحديث ملفات ترجمات مشاريعك وفقًا للغات التي اخترتها ،
ثم سأترجم كل اللغات ،
ثم قم بتحديث ملفات الترجمات وتجميعها في ملفات .qm للنشر.

كتبه جيفري سكوت فليشر