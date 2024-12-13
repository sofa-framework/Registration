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

/**
  A simple qt application featuring a Sofa simulation, using the SofaSimpleGUI API.

  @author Francois Faure, 2014
  */

#include <QApplication>
#include <QResource>
#include "QMainWindow_RegistrationRun.h"
#include <sofa/helper/system/glut.h>
#include <sofa/gui/ArgumentParser.h>
#include <string>
#include <iostream>

#include <sofa/helper/system/FileRepository.h>
#include <sofa/helper/system/FileSystem.h>
#include <sofa/helper/Utils.h>

using sofa::helper::system::FileSystem;
using sofa::helper::Utils;

int main(int argc, char** argv)
{
    glutInit(&argc,argv);

    std::string fileName;
    // these can be passed using the command line
//    fileName = std::string(registration_SRC_DIR) + "/examples/knee/precompute_model.py";
    fileName = std::string(registration_SRC_DIR) + "/example/knee/reg_frames.py";
    std::vector<std::string> plugins;
    plugins.push_back("SofaPython");
    sofa::helper::parse("Simple qt application featuring a Sofa scene.")
            .option(&plugins,'l',"load","load given plugins")
            .option(&fileName,'f',"file","scene file to load")
            (argc,argv);

    // Read command lines arguments.
    QApplication application(argc,argv);

    // Instantiate the main window and make it visible.
    QMainWindow_RegistrationRun mainWindow;
    mainWindow.sofaScene.loadPlugins( plugins );
    mainWindow.initSofa(fileName);
    mainWindow.setWindowTitle("registration");
    mainWindow.resize(800,600);
    mainWindow.show();
    //mainWindow.sofaScene.play();


    // Run main loop.
    return application.exec();
}
