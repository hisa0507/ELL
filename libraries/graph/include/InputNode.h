#pragma once
//
// InputNode
// 

#include "Node.h"
#include "NodeOutput.h"

#include <vector>
#include <memory>
#include <string>

template <typename ValueType>
class InputNode: public Node
{
public:
    InputNode(size_t dimension) : Node({}, {&_output}), _output(this, 0, dimension) {};

    virtual std::string Type() const override { return "Input"; }

    const NodeOutput<ValueType>& output = _output; // This is a (perhaps too-)clever way to make a read-only property. I don't know if I like it.

private:
    NodeOutput<ValueType> _output;
};
