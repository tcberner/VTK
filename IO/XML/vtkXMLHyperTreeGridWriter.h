/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkXMLHyperTreeGridWriter.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkXMLHyperTreeGridWriter
 * @brief   Write VTK XML HyperTreeGrid files.
 *
 * vtkXMLHyperTreeGridWriter writes the VTK XML HyperTreeGrid file
 * format. The standard extension for this writer's file format is "xhg".
*/

#ifndef vtkXMLHyperTreeGridWriter_h
#define vtkXMLHyperTreeGridWriter_h

#include "vtkIOXMLModule.h" // For export macro
#include "vtkXMLWriter.h"

class vtkHyperTreeGrid;
class vtkHyperTreeGridCursor;

class VTKIOXML_EXPORT vtkXMLHyperTreeGridWriter : public vtkXMLWriter
{
public:
  vtkTypeMacro(vtkXMLHyperTreeGridWriter,vtkXMLWriter);
  void PrintSelf(ostream& os, vtkIndent indent) override;
  static vtkXMLHyperTreeGridWriter* New();

  /**
   * Get/Set the writer's input.
   */
  vtkHyperTreeGrid* GetInput();

  /**
   * Get the default file extension for files written by this writer.
   */
  const char* GetDefaultFileExtension() override;

protected:
  vtkXMLHyperTreeGridWriter();
  ~vtkXMLHyperTreeGridWriter() override;

  const char* GetDataSetName() override;

  // specify that we require HyperTreeGrid input
  int FillInputPortInformation(int port, vtkInformation* info) override;

  // The most important method, make the XML file for my input.
  int WriteData() override;

  // <HyperTreeGrid ...
  int StartPrimaryElement(vtkIndent);

  // ... dim, size, origin>
  void WritePrimaryElementAttributes(ostream &, vtkIndent) override;

  // Grid coordinates (if origin and scale are not specified)
  int WriteGridCoordinates(vtkIndent);

  // Tree Structure
  int WriteDescriptor(vtkIndent);

  // Writes PointData and CellData attribute data.
  int WriteAttributeData(vtkIndent);

  // </HyperTreeGrid>
  int FinishPrimaryElement(vtkIndent);

private:
  vtkXMLHyperTreeGridWriter(const vtkXMLHyperTreeGridWriter&) = delete;
  void operator=(const vtkXMLHyperTreeGridWriter&) = delete;
};

#endif
