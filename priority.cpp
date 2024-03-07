#include "priority.h"

priority::priority(QObject *parent) : QObject{parent}
{
    enum e_priority
    {
        e_msg3,
        e_msg2,
        e_msg4,
        e_msg1,
    };

    enum e_msgtype
    {
        e_m_msg1,
        e_m_msg2,
        e_m_msg3,
        e_m_msg4,
    };
    QHash<QHash<e_priority, e_msgtype>, QString> myMap;
    QHash<e_priority, e_msgtype> innermap;
    innermap[e_msg1] = e_m_msg1;
    myMap[innermap]  = "this message inset first";

    innermap[e_msg2] = e_m_msg4;
    myMap[innermap]  = "this message inset second";

    innermap[e_msg2] = e_m_msg1;
    myMap[innermap]  = "this message inset thirth";

    for (QHash<e_priority, e_msgtype> var : myMap.keys())
    {
        qDebug() << myMap[var];
    }
}
