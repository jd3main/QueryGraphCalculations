#ifndef WDDATA_HPP
#define WDDATA_HPP

#include <string>

using std::string;

namespace wdgq
{
    enum class WdDataType {
        CommonsMedia,
        GlobeCoordinate,
        Item,
        Property,
        String,
        MonolingualText,
        ExternalIdentifier,
        Quantity,
        Time,
        URL,
        MathematicalExpression,
        GeographicShape,
        MusicalNotation,
        TabularData,
        Lexemes,
        Forms,
        Senses
    };

    struct WdData {
        virtual string Text();
    };

    struct EntityData : public WdData {
        string id;
        string Text() { return id; }
    };

    struct ItemData : public EntityData {};
    struct PropertyData : public EntityData {};
    struct LexemesData : public EntityData {};
    struct FormsData : public EntityData {};
    struct SensesData : public EntityData {};
}

#endif // WDDATA_HPP

