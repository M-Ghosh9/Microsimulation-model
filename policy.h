// include/Policy.h
#ifndef POLICY_H
#define POLICY_H

#include "Patient.h"

class Policy {
public:
    virtual void apply(Patient& patient) const = 0;
    virtual ~Policy() = default;
};

class StandardPolicy : public Policy {
public:
    void apply(Patient& patient) const override;
};

class AggressivePolicy : public Policy {
public:
    void apply(Patient& patient) const override;
};

#endif // POLICY_H
