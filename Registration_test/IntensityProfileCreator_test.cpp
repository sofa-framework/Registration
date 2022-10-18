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
#include <Registration/IntensityProfileCreator.h>
#include <sofa/core/objectmodel/SPtr.h>

namespace sofa
{

TEST(IntensityProfileCreator, getTemplateName)
{
    {
        const auto engine = core::objectmodel::New<
            component::engine::IntensityProfileCreator<sofa::defaulttype::ImageUC>
        >();
        EXPECT_EQ(engine->getTemplateName(), "ImageUC");
    }

    {
        const auto engine = core::objectmodel::New<
            component::engine::IntensityProfileCreator<sofa::defaulttype::ImageUS>
        >();
        EXPECT_EQ(engine->getTemplateName(), "ImageUS");
    }

    {
        const auto engine = core::objectmodel::New<
            component::engine::IntensityProfileCreator<sofa::defaulttype::ImageS>
        >();
        EXPECT_EQ(engine->getTemplateName(), "ImageS");
    }

    {
        const auto engine = core::objectmodel::New<
            component::engine::IntensityProfileCreator<sofa::defaulttype::ImageD>
        >();
        EXPECT_EQ(engine->getTemplateName(), "ImageD");
    }

    {
        const auto engine = core::objectmodel::New<
            component::engine::IntensityProfileCreator<sofa::defaulttype::ImageB>
        >();
        EXPECT_EQ(engine->getTemplateName(), "ImageB");
    }

}

}

