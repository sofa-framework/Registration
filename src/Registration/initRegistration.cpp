/******************************************************************************
*                 SOFA, Simulation Open-Framework Architecture                *
*                    (c) 2006 INRIA, USTL, UJF, CNRS, MGH                     *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this program. If not, see <http://www.gnu.org/licenses/>.        *
*******************************************************************************
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#include <Registration/config.h>
#include <sofa/core/ObjectFactory.h>
#include <sofa/helper/system/PluginManager.h>

namespace sofa::component
{
    extern void registerInertiaAlign(sofa::core::ObjectFactory* factory);
}
namespace sofa::component::engine
{
    extern void registerGroupwiseRegistrationEngine(sofa::core::ObjectFactory* factory);
#ifdef REGISTRATION_USES_IMAGE
    extern void registerIntensityProfileCreator(sofa::core::ObjectFactory* factory);
#endif
}
namespace sofa::component::forcefield
{
#ifdef REGISTRATION_USES_IMAGE
    extern void registerIntensityProfileRegistrationForceField(sofa::core::ObjectFactory* factory);
#endif
    extern void registerClosestPointRegistrationForceField(sofa::core::ObjectFactory* factory);
}
namespace sofa::component::interactionforcefield
{
    extern void registerRegistrationContactForceField(sofa::core::ObjectFactory* factory);
}
namespace sofa::component::misc
{
    extern void registerRegistrationExporter(sofa::core::ObjectFactory* factory);
}

namespace registration
{
  //Here are just several convenient functions to help user to know what contains the plugin

  extern "C" {
    SOFA_REGISTRATION_API void initExternalModule();
    SOFA_REGISTRATION_API const char* getModuleName();
    SOFA_REGISTRATION_API const char* getModuleVersion();
    SOFA_REGISTRATION_API const char* getModuleLicense();
    SOFA_REGISTRATION_API const char* getModuleDescription();
    SOFA_REGISTRATION_API void registerObjects(sofa::core::ObjectFactory* factory);
  }
  
  void initExternalModule()
  {
    static bool first = true;
    if (first)
    {
      // make sure that this plugin is registered into the PluginManager
      sofa::helper::system::PluginManager::getInstance().registerPlugin(MODULE_NAME);

      first = false;
    }
  }

  const char* getModuleName()
  {
    return MODULE_NAME;
  }

  const char* getModuleVersion()
  {
    return MODULE_VERSION;
  }

  const char* getModuleLicense()
  {
    return "QPL";
  }


  const char* getModuleDescription()
  {
    return "Model/image registration force fields";
  }

  void registerObjects(sofa::core::ObjectFactory* factory)
  {
      sofa::component::registerInertiaAlign(factory);
      sofa::component::engine::registerGroupwiseRegistrationEngine( factory);
#ifdef REGISTRATION_USES_IMAGE
      sofa::component::engine::registerIntensityProfileCreator(factory);
      sofa::component::forcefield::registerIntensityProfileRegistrationForceField(factory);
#endif
      sofa::component::forcefield::registerClosestPointRegistrationForceField(factory);
      sofa::component::interactionforcefield::registerRegistrationContactForceField(factory);
      sofa::component::misc::registerRegistrationExporter(factory);
  }

} // namespace registration