#pragma once

#include <QString>
#include <QStringList>

namespace UiFont
{

inline QStringList systemHanFallbackFamilies()
{
#ifdef Q_OS_DARWIN
    return {QStringLiteral("PingFang SC")};
#elif defined(Q_OS_WIN32)
    return {
        QStringLiteral("Microsoft YaHei UI"),
        QStringLiteral("Microsoft YaHei"),
        QStringLiteral("Noto Sans SC"),
        QStringLiteral("DengXian"),
    };
#else
    return {
        QStringLiteral("Noto Sans CJK SC"),
        QStringLiteral("Source Han Sans SC"),
    };
#endif
}

// Manrope has no Thai glyphs. Without an explicit choice Windows may fall back
// to legacy Thai fonts (e.g. Angsana New) whose glyphs render far smaller than
// the Latin text at the same point size, so name modern Thai UI fonts first.
inline QStringList systemThaiFallbackFamilies()
{
#ifdef Q_OS_DARWIN
    return {QStringLiteral("Thonburi")};
#elif defined(Q_OS_WIN32)
    return {
        QStringLiteral("Leelawadee UI"),
        QStringLiteral("Tahoma"),
    };
#else
    return {
        QStringLiteral("Noto Sans Thai UI"),
        QStringLiteral("Noto Sans Thai"),
    };
#endif
}

inline QStringList familyChain(const QString& primaryFamily)
{
    QStringList families;
    if (!primaryFamily.isEmpty()) {
        families << primaryFamily;
    }
    families << systemThaiFallbackFamilies();
    families << systemHanFallbackFamilies();
    return families;
}

} // namespace UiFont
