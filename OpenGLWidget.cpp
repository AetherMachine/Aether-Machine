#include "OpenGLWidget.h"

#include <QSize>
#include <QOpenGLFramebufferObject>
#include <QOpenGLPaintDevice>
#include <QPaintEvent>
#include <QPainter>
#include <QColor>

OpenGLWidget::OpenGLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
}

OpenGLWidget::~OpenGLWidget()
{
}

void OpenGLWidget::animate()
{
    update();
}

void OpenGLWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(event->rect(), QBrush(Qt::black));
    auto destinationWidth = event->rect().width();
    auto destinationHeight = event->rect().height();
    auto scaledSourceImage = m_image.scaled(destinationWidth, destinationHeight, Qt::KeepAspectRatio);
    auto translationX = destinationWidth - scaledSourceImage.width();
    auto translationY = destinationHeight - scaledSourceImage.height();
    painter.translate(translationX / 2, translationY / 2);
    painter.drawImage(0, 0, scaledSourceImage);
    painter.end();
}
