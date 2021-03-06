/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_MODULE_MODULEINFO_HPP_
#define SMT_MODULE_MODULEINFO_HPP_

#include <string>

#include "smt/util/JsonWrapper.hpp"

namespace smt {
namespace module {

class BaseModuleInfo {
 public:
  BaseModuleInfo(const std::string& baseModuleName, const std::string& baseClassName)
      : m_baseModuleName(baseModuleName), m_baseClassName(baseClassName) {}
  virtual ~BaseModuleInfo() = default;

  const std::string getBaseModuleName() const { return m_baseModuleName; }
  const std::string getBaseClassName() const { return m_baseClassName; }

 protected:
  const std::string m_baseModuleName;
  const std::string m_baseClassName;
};

class ModuleInfo : public BaseModuleInfo {
 public:
  ModuleInfo();
  virtual ~ModuleInfo() = default;

  bool parseModueInfoOnJson(util::JsonWrapper info);

  const std::string& getModuleName() const { return m_moduleName; }
  const std::string& getClassName() const { return m_className; }
  const std::string& getModulePath() const {return m_modulePath; }
  const util::JsonWrapper getModuleArgs() const { return m_moduleArgs; }
  const util::JsonWrapper getModuleConfigure() const { return m_moduleConfigure; }

  ModuleInfo operator=(const ModuleInfo& rhs) {
    if (this == &rhs) {
      return *this;
    }

    m_moduleName = rhs.m_moduleName;
    m_className = rhs.m_className;
    m_modulePath = rhs.m_modulePath;
    m_moduleArgs = rhs.m_moduleArgs;
    m_moduleConfigure = rhs.m_moduleConfigure;

    return *this;
  }

 private:
  void setModuleName(const std::string& moduleName);
  void setClassName(const std::string& className);
  void setModulePath(const std::string& modulePath);
  void setModuleArgs(const util::JsonWrapper& args);
  void setModuleConfigure(const util::JsonWrapper& configures);

 private:
  std::string m_moduleName;
  std::string m_className;
  std::string m_modulePath;
  util::JsonWrapper m_moduleArgs;
  util::JsonWrapper m_moduleConfigure;
};

}  // namespace module
}  // namespace smt

#endif  // SMT_MODULE_MODULEINFO_HPP_
