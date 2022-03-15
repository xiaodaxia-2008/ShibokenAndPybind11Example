#include "EasyWidget.h"

namespace EW
{
EasyWidget::EasyWidget()
{
    m_layout = new QVBoxLayout;
    setLayout(m_layout);
    m_label = new QLabel;
    m_label->setText("EasyWidget");
    m_layout->addWidget(m_label);
}

EasyWidget::~EasyWidget() {}

QLabel *EasyWidget::GetLabel() const { return m_label; }
} // namespace EW