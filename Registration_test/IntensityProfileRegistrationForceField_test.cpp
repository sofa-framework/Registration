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
#include <gtest/gtest.h>
#include <Registration/IntensityProfileRegistrationForceField.h>
#include <sofa/core/objectmodel/SPtr.h>

namespace sofa
{

TEST(IntensityProfileRegistrationForceField, getTemplateName)
{
    {
        const auto engine = core::objectmodel::New<
            component::forcefield::IntensityProfileRegistrationForceField<sofa::defaulttype::Vec3Types, defaulttype::ImageUC>
        >();
        EXPECT_EQ(engine->getTemplateName(), "Vec3d,ImageUC");
    }

    {
        const auto engine = core::objectmodel::New<
            component::forcefield::IntensityProfileRegistrationForceField<sofa::defaulttype::Vec3Types, defaulttype::ImageUS>
        >();
        EXPECT_EQ(engine->getTemplateName(), "Vec3d,ImageUS");
    }

    {
        const auto engine = core::objectmodel::New<
            component::forcefield::IntensityProfileRegistrationForceField<sofa::defaulttype::Vec3Types, defaulttype::ImageD>
        >();
        EXPECT_EQ(engine->getTemplateName(), "Vec3d,ImageD");
    }

    {
        const auto engine = core::objectmodel::New<
            component::forcefield::IntensityProfileRegistrationForceField<sofa::defaulttype::Vec3Types, defaulttype::ImageC>
        >();
        EXPECT_EQ(engine->getTemplateName(), "Vec3d,ImageC");
    }

    {
        const auto engine = core::objectmodel::New<
            component::forcefield::IntensityProfileRegistrationForceField<sofa::defaulttype::Vec3Types, defaulttype::ImageI>
        >();
        EXPECT_EQ(engine->getTemplateName(), "Vec3d,ImageI");
    }

    {
        const auto engine = core::objectmodel::New<
            component::forcefield::IntensityProfileRegistrationForceField<sofa::defaulttype::Vec3Types, defaulttype::ImageUI>
        >();
        EXPECT_EQ(engine->getTemplateName(), "Vec3d,ImageUI");
    }

    {
        const auto engine = core::objectmodel::New<
            component::forcefield::IntensityProfileRegistrationForceField<sofa::defaulttype::Vec3Types, defaulttype::ImageS>
        >();
        EXPECT_EQ(engine->getTemplateName(), "Vec3d,ImageS");
    }

    {
        const auto engine = core::objectmodel::New<
            component::forcefield::IntensityProfileRegistrationForceField<sofa::defaulttype::Vec3Types, defaulttype::ImageL>
        >();
        EXPECT_EQ(engine->getTemplateName(), "Vec3d,ImageL");
    }

    {
        const auto engine = core::objectmodel::New<
            component::forcefield::IntensityProfileRegistrationForceField<sofa::defaulttype::Vec3Types, defaulttype::ImageUL>
        >();
        EXPECT_EQ(engine->getTemplateName(), "Vec3d,ImageUL");
    }

    {
        const auto engine = core::objectmodel::New<
            component::forcefield::IntensityProfileRegistrationForceField<sofa::defaulttype::Vec3Types, defaulttype::ImageF>
        >();
        EXPECT_EQ(engine->getTemplateName(), "Vec3d,ImageF");
    }

    {
        const auto engine = core::objectmodel::New<
            component::forcefield::IntensityProfileRegistrationForceField<sofa::defaulttype::Vec3Types, defaulttype::ImageB>
        >();
        EXPECT_EQ(engine->getTemplateName(), "Vec3d,ImageB");
    }
}

}







