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
#ifndef SOFA_COMPONENT_MISC_REGISTRATIONEXPORTER_H
#define SOFA_COMPONENT_MISC_REGISTRATIONEXPORTER_H

#include <Registration/config.h>
#include <sofa/core/objectmodel/BaseObject.h>
#include <sofa/defaulttype/VecTypes.h>
#include <sofa/core/objectmodel/DataFileName.h>
#include <sofa/core/behavior/BaseMechanicalState.h>


#include <fstream>

namespace sofa
{

namespace component
{

namespace misc
{

class SOFA_REGISTRATION_API RegistrationExporter : public core::objectmodel::BaseObject
{
public:
    SOFA_CLASS(RegistrationExporter,core::objectmodel::BaseObject);
	typedef type::Mat<4,4,SReal> Mat4x4;

protected:
	sofa::core::behavior::BaseMechanicalState* mstate;
    unsigned int stepCounter;

	std::vector<std::string> inFileNames;
	std::vector<std::string> outFileNames;
	std::vector<Mat4x4> inverseTransforms;
    std::string getMeshFilename(const char* ext);

public:
    sofa::core::objectmodel::DataFileName outPath;
    Data<defaulttype::Vec3Types::VecCoord> position; ///< points position (will use mechanical state if this is empty)
    Data<bool> applyInverseTransform; ///< apply inverse transform specified in loaders
    Data<unsigned int> exportEveryNbSteps; ///< export file only at specified number of steps (0=disable)
    Data<bool> exportAtBegin; ///< export file at the initialization
    Data<bool> exportAtEnd; ///< export file when the simulation is finished

	RegistrationExporter();
	~RegistrationExporter() override;

    void writeMesh();

	void init() override;
	void cleanup() override;
	void bwdInit() override;

	void handleEvent(sofa::core::objectmodel::Event *) override;
};

} // namespace misc

} // namespace component

} // namespace sofa

#endif // SOFA_COMPONENT_MISC_REGISTRATIONEXPORTER_H
