#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QImage>

class OpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit OpenGLWidget(QWidget *parent = 0);
    ~OpenGLWidget();

public slots:
    void setImage(QImage image) { m_image = image; }
    void animate();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QImage m_image;
};

#endif // GLWIDGET_H
