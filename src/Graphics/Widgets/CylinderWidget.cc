/*
For more information, please see: http://software.sci.utah.edu

The MIT License

Copyright (c) 2015 Scientific Computing and Imaging Institute,
University of Utah.

License for the specific language governing rights and limitations under
Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include <Graphics/Widgets/CylinderWidget.h>
#include <Graphics/Glyphs/GlyphGeom.h>
#include <Core/GeometryPrimitives/Point.h>
#include <Core/Datatypes/Legacy/Field/Field.h>
#include <Core/Datatypes/Legacy/Field/VMesh.h>
#include <Core/Datatypes/Color.h>

using namespace SCIRun;
using namespace SCIRun::Core::Datatypes;
using namespace SCIRun::Graphics::Datatypes;
using namespace SCIRun::Core::Geometry;

CylinderWidget::CylinderWidget(const Core::GeometryIDGenerator& idGenerator,
                               const std::string& name,
                               double radius,
                               const std::string& defaultColor,
                               const Point& p1,
                               const Point& p2,
                               const Point& origin,
                               const BBox& bbox,
                               int resolution)
  : WidgetBase(idGenerator, "CylinderWidget::" + name, true, Point(p1 + p2)/2, origin)
{
  if (radius < 0) radius = 1.;
  if (resolution < 0) resolution = 10;

  auto colorScheme = ColorScheme::COLOR_UNIFORM;
  std::stringstream ss;
  ss << radius << resolution << static_cast<int>(colorScheme);

  auto uniqueNodeID = uniqueID() + "widget" + ss.str();

  Graphics::GlyphGeom glyphs;
  ColorRGB node_color;
  glyphs.addCylinder(p1, p2, radius, resolution, node_color, node_color);

  auto renState = getWidgetRenderState(defaultColor);

  glyphs.buildObject(*this, uniqueNodeID, renState.get(RenderState::USE_TRANSPARENCY), 1.0,
    colorScheme, renState, SpireIBO::PRIMITIVE::TRIANGLES, bbox);
}

RenderState CylinderWidget::getWidgetRenderState(const std::string& defaultColor)
{
  RenderState renState;

  renState.set(RenderState::IS_ON, true);
  renState.set(RenderState::USE_TRANSPARENCY, false);

  renState.defaultColor = ColorRGB(defaultColor);
  renState.defaultColor = (renState.defaultColor.r() > 1.0 ||
    renState.defaultColor.g() > 1.0 ||
    renState.defaultColor.b() > 1.0) ?
    ColorRGB(
    renState.defaultColor.r() / 255.,
    renState.defaultColor.g() / 255.,
    renState.defaultColor.b() / 255.)
    : renState.defaultColor;

  renState.set(RenderState::USE_DEFAULT_COLOR, true);
  renState.set(RenderState::USE_NORMALS, true);
  renState.set(RenderState::IS_WIDGET, true);

  return renState;
}
