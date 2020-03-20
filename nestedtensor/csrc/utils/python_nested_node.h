#pragma once
#include <nested_node.h>
#include <torch/csrc/jit/python/pybind_utils.h>
#include <py_utils.h>

namespace torch {
namespace nested_tensor {

<<<<<<< HEAD
using PythonNode = NestedNode<pybind11::object>;

=======
>>>>>>> Set up ShipIt
template <typename T>
struct THPNestedNode {
  THPNestedNode(NestedNode<T> size_node, std::string name)
      : _size_node(size_node), _name(name) {}
  int64_t len() {
    return _size_node.degree();
  }
  std::string str() {
    return NestedNode___str__(
        _size_node, _name, [](c10::IValue payload, const std::string& tabs) {
          std::stringstream ss;
          ss << tabs << payload;
          return ss.str();
        });
  }
  const NestedNode<T>& get_node() const {
    return _size_node;
  }
  pybind11::object unbind() {
    std::vector<pybind11::object> result;
    for (const auto& child : _size_node.unbind()) {
      if (child.height() == 0) {
        result.push_back(wrap_nested_node(child));
      } else {
        result.push_back(pybind11::cast(THPNestedNode<T>(child, _name)));
      }
    }
    return pybind11::cast(result);
  }

 private:
  NestedNode<T> _size_node;
  std::string _name;
};

template <>
struct THPNestedNode<py::object> {
  THPNestedNode(NestedNode<pybind11::object> size_node, std::string name)
      : _size_node(size_node), _name(name) {}
  int64_t len() {
    return _size_node.degree();
  }
  std::string str() {
    return NestedNode___str__(
        _size_node,
        _name,
        [](pybind11::object payload, const std::string& tabs) {
          std::stringstream ss;
          ss << tabs << payload;
          return ss.str();
        });
  }
  const NestedNode<pybind11::object>& get_node() const {
    return _size_node;
  }
  pybind11::object unbind() {
    std::vector<pybind11::object> result;
    for (const auto& child : _size_node.unbind()) {
      if (child.height() == 0) {
        result.push_back(child.payload());
      } else {
        result.push_back(
            pybind11::cast(THPNestedNode<pybind11::object>(child, _name)));
      }
    }
    return pybind11::cast(result);
  }
<<<<<<< HEAD
  pybind11::object operator[](size_t index) {
    TORCH_CHECK(index < _size_node.degree(), "Index out of range.");
    std::vector<pybind11::object> result;
    NestedNode<py::object> child = _size_node.unbind()[index];
    if (child.height() == 0) {
      return child.payload();
    } else {
      return pybind11::cast(THPNestedNode<pybind11::object>(child, _name));
    }
  }
=======
>>>>>>> Set up ShipIt

 private:
  NestedNode<pybind11::object> _size_node;
  std::string _name;
};

<<<<<<< HEAD
using THPSizeNode = THPNestedNode<c10::List<int64_t>>;
using THPIntegerNode = THPNestedNode<int64_t>;
using THPTensorNode = THPNestedNode<at::Tensor>;
using THPIValueNode = THPNestedNode<c10::IValue>;
using THPPythonNode = THPNestedNode<py::object>;

=======
>>>>>>> Set up ShipIt
void register_python_nested_node(pybind11::module m);

} // namespace nested_tensor
} // namespace torch