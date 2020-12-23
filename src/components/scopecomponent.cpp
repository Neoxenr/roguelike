#include "../include/components/scopecomponent.h"

float ScopeComponent::getXMin() const {
  return x_min;
}

float ScopeComponent::getXMax() const {
  return x_max;
}

float ScopeComponent::getYMin() const {
  return y_min;
}

float ScopeComponent::getYMax() const {
  return y_max;
}

bool ScopeComponent::IsNext() const {
  return is_next;
}

bool ScopeComponent::IsBack() const {
  return is_back;
}

void ScopeComponent::setNext(bool flag) {
  is_next = flag;
}

void ScopeComponent::setBack(bool flag) {
  is_back = flag;
}
