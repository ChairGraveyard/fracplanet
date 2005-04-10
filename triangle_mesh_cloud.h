// Source file for fracplanet
// Copyright (C) 2005 Tim Day
/*
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

/*! \file
  \brief Interface for class TriangleMeshCloud and derived classes.
*/

#ifndef _triangle_mesh_cloud_h_
#define _triangle_mesh_cloud_h_

#include "triangle_mesh.h"
#include "parameters_cloud.h"

//! This class holds all the cloud-related methods.  
/*! It's intended to be used as a "mix-in", adding cloud generating 
  functionality to cloud objects subclassed from simpler geometries.
  \todo Ugh!!!  This is really yucky use of multiple inheritance.  Switch to a "Factory" pattern.
 */
class TriangleMeshCloud : virtual TriangleMesh
{
 protected:
  void do_cloud(const ParametersCloud& parameters);

 public:
  
  //! Constructor.
  TriangleMeshCloud(Progress* progress);

  //! Destructor.
    virtual ~TriangleMeshCloud();
};

//! Class constructing specific case of a planetary cloud.
class TriangleMeshCloudPlanet : public TriangleMeshSubdividedIcosahedron, virtual public TriangleMeshCloud
{
 protected:
 public:
  //! Constructor.
  TriangleMeshCloudPlanet(const ParametersCloud& param,Progress* progress);

  //! Destructor.
  virtual ~TriangleMeshCloudPlanet()
    {}
};

//! Class constructing specific case of a flat-base terrain area.
class TriangleMeshCloudFlat : public TriangleMeshFlat, virtual public TriangleMeshCloud
{
 public:
  //! Constructor.
  TriangleMeshCloudFlat(const ParametersCloud& parameters,Progress* progress);

  //! Destructor.
  virtual ~TriangleMeshCloudFlat()
    {}
};



#endif
