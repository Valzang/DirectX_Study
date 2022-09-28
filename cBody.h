#pragma once
#include "cCubeNode.h"
class cBody : public cCubeNode
{
public:
    cBody();
    ~cBody();

    virtual void SetUp() override;
};

