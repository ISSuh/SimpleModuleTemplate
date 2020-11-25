/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_CONTROLLER_MODULECONTROLLER_HPP_
#define SMT_CONTROLLER_MODULECONTROLLER_HPP_

#include <vector>
#include <memory>

#include "smt/module/ModuleBase.hpp"
#include "smt/loader/ModuleLoaderManager.hpp"

namespace smt {
namespace controller {

// TODO(issuh) : Implement ModuleController Class
/**
 *  ModuleController Class
 * 
 **/
class ModuleController {
 public:
  ModuleController();

  bool Init();
  void Clear();

 private:
  bool LoadAllModule();
  // bool LoadMoule(const util::json& arg);

 private:
  smt::loader::ModuleLoadManager m_loadManager;
  std::vector<std::shared_ptr<module::ModuleBase>> m_moduleLists;
};

}  // namespace controller
}  // namespace smt

#endif  // SMT_CONTROLLER_MODULECONTROLLER_HPP_
