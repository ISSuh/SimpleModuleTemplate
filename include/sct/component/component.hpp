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

#ifndef SCT_COMPONENT_COMPONENT
#define SCT_COMPONENT_COMPONENT

#include <iostream>
#include <memory>

#include <sct/component/component_base.hpp>

namespace sct {

namespace component {

class Component : public sct::component::ComponentBase{
public:
    Component() {}
    ~Component() override {}

    bool Initialize() override { 
        if(!Init()){
            return false;
        }

        return true; 
    }

    bool Process() override {
        if(!Run()){
            return false;
        }

        return true; 
    }

    bool Shutdown() override {
        if(!Clear()){
            return false;
        }

        return true; 
    }

protected:
    /**
    * @brief init the user fuction. write your own code.
    *
    * @param 
    *
    * @return returns true if successful, otherwise returns false
    */
    virtual bool Init() = 0;

    /**
    * @brief init the user fuction. write your own code.
    *
    * @param 
    *
    * @return returns true if successful, otherwise returns false
    */
    virtual bool Init() = 0;

    /**
    * @brief run the user fuction. write your own code.
    *
    * @param 
    *
    * @return returns true if successful, otherwise returns false
    */
    virtual bool Run() = 0;

    /**
    * @brief clear the user fuction. write your own code.
    *
    * @param 
    *
    * @return returns true if successful, otherwise returns false
    */
    virtual bool Clear() = 0;

private:
    std::string str;
};

} // namspace component

} // namspace sct

#endif