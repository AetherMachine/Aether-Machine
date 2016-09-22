#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include <QImage>
#include <QColor>

class GraphicsEngine
{
public:
    GraphicsEngine(int width, int height);
    ~GraphicsEngine();

    QImage toImage();

private:
    int m_width;
    int m_height;
    QColor m_clearColor;
};

#endif // GRAPHICSENGINE_H
