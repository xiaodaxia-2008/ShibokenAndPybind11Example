#pragma once

#include <QtWidgets>
#include <QLabel>
#include <QVBoxLayout>

#include <memory>

using RVS::GenericRobotController;

namespace EW
{
class EasyWidget : public QWidget
{
    Q_OBJECT
public:
    EasyWidget();
    ~EasyWidget();
    QLabel* GetLabel() const;

private:
    std::shared_ptr<GenericRobotController> m_controller;
    QVBoxLayout *m_layout;
    QLabel *m_label;
};
} // namespace EW