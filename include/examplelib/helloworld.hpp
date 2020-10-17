#pragma once

#include <string>

namespace examplelib {

/** << NOTE
 * \brief Defines a class with a helloworld message.
 * \tparam _StringType String-type.
 */
template <typename _StringType = std::string>
struct hello_world {
  _StringType message{"Hello World!"};
};

}  // namespace examplelib
