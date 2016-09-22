#include "GraphicsEngine.h"

#include <QRect>
#include <QSize>
#include <QPixmap>
#include <QPainter>

GraphicsEngine::GraphicsEngine(int width, int height)
{
    m_width = width;
    m_height = height;

    qDebug("width %d", m_width);
    qDebug("height %d", m_height);
}

QImage GraphicsEngine::toImage()
{
    QRect rect(0, 0, 400, 400);
    QSize size(rect.size());
    QPixmap pixmap(size);
    QPainter painter;
    painter.begin(&pixmap);

    painter.fillRect(rect, Qt::blue);

    painter.drawTiledPixmap(rect, QPixmap(":/qt-project.org/qmessagebox/images/qtlogo-64.png"));

    painter.setPen(QPen(Qt::green, 5));
    painter.setBrush(Qt::red);
    painter.drawEllipse(0, 100, 400, 200);
    painter.drawEllipse(100, 0, 200, 400);

    painter.setPen(QPen(Qt::white, 0));
    QFont font;
    font.setPointSize(24);
    painter.setFont(font);

    static auto flash = false;
    if (flash)
        painter.drawText(rect, "Hello Pixmap", QTextOption(Qt::AlignCenter));
    flash = !flash;

    painter.end();
    return pixmap.toImage();
}
