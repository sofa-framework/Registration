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
#ifndef QTSOFAMAINWINDOW_H
#define QTSOFAMAINWINDOW_H

#include <QMainWindow>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "QSofaScene.h"
class QSofaViewer;

/**
 * @brief The QMainWindow_RegistrationRun class contains a Sofa simulation.
 *
 * @author Francois Faure, 2014
 */
class QMainWindow_RegistrationRun : public QMainWindow
{
    Q_OBJECT
public:
    explicit QMainWindow_RegistrationRun(QWidget *parent = 0);

    /**
     * @brief The simulated scene
     */
    QSofaScene sofaScene;

    /**
     * @brief Default viewer, set as central widget.
     * Additional viewers can be created during the session
     */
    QSofaViewer* mainViewer;

    /**
     * @brief initSofa
     * @param filename Scene to load on startup. If empty, create a default scene
     */
    void initSofa(string filename );


signals:

public slots:
    /**
     * @brief used to change the play/pause icon
     */
    void isPlaying(bool);
    /**
     * @brief Select a new scene file using the menu, clear the current scene and replace it with the new one
     */
    void open();
    /**
     * @brief Set the simulation time step
     * @param ms Value of the time step, in milliseconds.
     */
    void setDt( int ms );
    /**
     * @brief Toggle the application betwenn full screen/normal mode
     */
    void toggleFullScreen();
    /**
     * @brief Create an additional viewer in a dock widget
     */
    void createAdditionalViewer();
protected:
    QAction* _playPauseAct;  // play/pause
    bool _fullScreen; ///< true if currently displaying in full screen mode

};

#endif // QTSOFAMAINWINDOW_H
