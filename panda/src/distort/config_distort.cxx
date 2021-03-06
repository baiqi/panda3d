/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file config_distort.cxx
 * @author drose
 * @date 2001-12-11
 */

#include "config_distort.h"
#include "cylindricalLens.h"
#include "fisheyeLens.h"
#include "pSphereLens.h"
#include "oSphereLens.h"
#include "projectionScreen.h"

#include "dconfig.h"

#if !defined(CPPPARSER) && !defined(BUILDING_PANDAFX)
  #error Buildsystem error: BUILDING_PANDAFX not defined
#endif

Configure(config_distort);
NotifyCategoryDef(distort, "");

ConfigureFn(config_distort) {
  init_libdistort();
}

ConfigVariableBool project_invert_uvs
("project-invert-uvs", false,
 PRC_DESC("If this is true, the UV's generated by all ProjectionScreens are "
          "inverted top-to-bottom.  This used to be required to compensate "
          "for buggy graphics drivers that rendered to a texture upside-down "
          "in this manner, but nowadays Panda should be able to autodetect "
          "these graphics drivers.  If it fails to do this, you should "
          "probably set copy-texture-inverted instead, which is more general."));

/**
 * Initializes the library.  This must be called at least once before any of
 * the functions or classes in this library can be used.  Normally it will be
 * called by the static initializers and need not be called explicitly, but
 * special cases exist.
 */
void
init_libdistort() {
  static bool initialized = false;
  if (initialized) {
    return;
  }
  initialized = true;

  CylindricalLens::init_type();
  FisheyeLens::init_type();
  PSphereLens::init_type();
  OSphereLens::init_type();
  ProjectionScreen::init_type();
}
