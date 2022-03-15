#pragma once

#include <QtWidgets>
#include <QLabel>
#include <QVBoxLayout>

#include <memory>

namespace EW
{
class EasyWidget : public QWidget
{
    Q_OBJECT
public:
    EasyWidget();
    ~EasyWidget();
    QLabel *GetLabel() const;

private:
    QVBoxLayout *m_layout;
    QLabel *m_label;
};
} // namespace EW