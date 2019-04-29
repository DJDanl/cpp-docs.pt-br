---
title: 'Páginas de propriedade HLSL: Arquivos de saída'
ms.date: 11/04/2016
f1_keywords:
- VC.Project.FXCompilerTool.AssemblerOutput
- VC.Project.FXCompilerTool.ObjectFileOutput
- VC.Project.FXCompilerTool.HeaderFileOutput
- VC.Project.FXCompilerTool.VariableName
- VC.Project.FXCompilerTool.AssemblerOutputFile
ms.assetid: c5ba1e72-30de-43eb-a15a-5b0ae58e55c2
ms.openlocfilehash: 6ee8042fccf2e0b635535a77d9c9a6bc68bd9999
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62291542"
---
# <a name="hlsl-property-pages-output-files"></a>Páginas de propriedade HLSL: Arquivos de saída

Para configurar as propriedades a seguir do compilador HLSL (fxc.exe), use sua propriedade **Arquivos de Saída**. Para obter informações sobre como acessar o **arquivos de saída** página de propriedades na pasta HLSL, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

## <a name="uielement-list"></a>Lista UIElement

- **Nome da Variável de Cabeçalho**

   Especifica o nome de uma matriz que é usada para codificar o código de objeto HLSL. A matriz está contida em um arquivo de cabeçalho produzido pelo compilador HLSL. O nome do arquivo de cabeçalho é especificado pela propriedade **Nome do Arquivo de Cabeçalho**.

Essa propriedade corresponde ao argumento de linha de comando **/Vn[name]**.

- **Nome do Arquivo de Cabeçalho**

   Especifica o nome do arquivo de cabeçalho produzido pelo compilador HLSL. O cabeçalho contém um código de objeto HLSL que é codificado em uma matriz. O nome da matriz é especificado pela propriedade **Nome da Variável de Cabeçalho**.

Essa propriedade corresponde ao argumento de linha de comando **/Fh[name]**.

- **Nome do Arquivo-objeto**

   Especifica o nome do arquivo-objeto produzido pelo compilador HLSL. Por padrão, o valor é **$(OutDir)%(Nome do arquivo).cso**.

Essa propriedade corresponde ao argumento de linha de comando **/Fo[name]**.

- **Saída do Assembler**

   **Listagem Somente de Assemblies (/Fc)** para produzir somente as instruções de linguagem assembly. **Código assembly e hexadecimal (/Fx)** para produzir as instruções de linguagem assembly e o código op correspondente em hexadecimal. Por padrão, nenhuma listagem é produzida.

- **Arquivo de Saída do Assembler**

   Especifica o nome do arquivo de listagem de assembly produzido pelo compilador HLSL.

   Essa propriedade corresponde aos argumentos de linha de comando **/Fc[name]** e **/Fx [name]**.

## <a name="see-also"></a>Consulte também

[Páginas de propriedade HLSL](hlsl-property-pages.md)<br>
[Páginas de propriedades de HLSL: geral](hlsl-property-pages-general.md)<br>
[Páginas de propriedades de HLSL: avançado](hlsl-property-pages-advanced.md)
