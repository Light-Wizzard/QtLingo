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
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "qoption.h"

#include <QJsonObject>
#include <QJsonArray>

/************************************************
 * @brief toJson.
 * toJson
 ***********************************************/
QJsonObject QOption::toJson() const
{
    QJsonObject object
    {
        {"gender", gender},                                         //!< \c gender       @brief gender
        {"translations", QJsonArray::fromStringList(translations)}, //!< \c translations @brief translations
        {"word", word},                                             //!< \c word         @brief word
    };
    return object;
}
/******************************* End of File *********************************/
