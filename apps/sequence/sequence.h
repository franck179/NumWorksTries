#ifndef SEQUENCE_SEQUENCE_H
#define SEQUENCE_SEQUENCE_H

#include "../shared/function.h"

namespace Sequence {

class Sequence : public Shared::Function {
public:
  enum class Type {
    Explicite = 0,
    SingleRecurrence = 1,
    DoubleRecurrence = 2
  };
  Sequence(const char * text = nullptr, KDColor color = KDColorBlack);
  ~Sequence();
  Type type();
  void setType(Type type);
  Poincare::Expression * firstInitialConditionExpression();
  Poincare::Expression * secondInitialConditionExpression();
  Poincare::ExpressionLayout * firstInitialConditionLayout();
  Poincare::ExpressionLayout * secondInitialConditionLayout();
  void setFirstInitialConditionContent(const char * c);
  void setSecondInitialConditionContent(const char * c);
private:
  char symbol() const override;
  Type m_type;
  char m_firstInitialConditionText[Shared::Function::k_bodyLength];
  char m_secondInitialConditionText[Shared::Function::k_bodyLength];
  Poincare::Expression * m_firstInitialConditionExpression;
  Poincare::Expression * m_secondInitialConditionExpression;
  Poincare::ExpressionLayout * m_firstInitialConditionLayout;
  Poincare::ExpressionLayout * m_secondInitialConditionLayout;
};

}

#endif