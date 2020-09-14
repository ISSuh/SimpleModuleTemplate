/******************************************************************************
 * Copyright 2019 The ISSuh Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef SMT_LOADER_MODUL_LOADER_REGIST_MACRO    
#define SMT_LOADER_MODUL_LOADER_REGIST_MACRO    

#include <smt/loader/module_loader_util.hpp>

namespace smt {

namespace loader {

#define CLASS_LOADER_REGISTER_CLASS_INTERNAL(ModuleClass, ModuleBase, UniqueID)     \
  namespace {                                                             \
  struct ProxyType##UniqueID {                                            \
    ProxyType##UniqueID() {                                               \
        smt::loader::util::RegistClass<ModuleClass, ModuleBase>(                \
          #ModuleClass, #ModuleBase);                                               \
    }                                                                     \
  };                                                                      \
  static ProxyType##UniqueID g_register_class_##UniqueID;                 \
  }

// register class macro
#define CLASS_LOADER_REGISTER_CLASS(ModuleClass, ModuleBase) \
  CLASS_LOADER_REGISTER_CLASS_INTERNAL(ModuleClass, ModuleBase, __COUNTER__)

} // namespace loader

} // namespace smt

#endif