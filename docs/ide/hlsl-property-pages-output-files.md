---
title: 'Páginas de propriedades de HLSL: Arquivos de Saída | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- VC.Project.FXCompilerTool.AssemblerOutput
- VC.Project.FXCompilerTool.ObjectFileOutput
- VC.Project.FXCompilerTool.HeaderFileOutput
- VC.Project.FXCompilerTool.VariableName
- VC.Project.FXCompilerTool.AssemblerOutputFile
dev_langs:
- C++
ms.assetid: c5ba1e72-30de-43eb-a15a-5b0ae58e55c2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1f04b5f56511975851f4314f2977b84799c2f4e0
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46410514"
---
# <a name="hlsl-property-pages-output-files"></a>Páginas de propriedades HLSL: arquivos de saída

Para configurar as propriedades a seguir do compilador HLSL (fxc.exe), use sua propriedade **Arquivos de Saída**. Para obter informações sobre como acessar a página de propriedades **Arquivo de Saída** na pasta HLSL, confira [Trabalhando com propriedades do projeto](../ide/working-with-project-properties.md).

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

[Páginas de propriedade HLSL](../ide/hlsl-property-pages.md)<br>
[Páginas de propriedade HLSL: geral](../ide/hlsl-property-pages-general.md)<br>
[Páginas de propriedade HLSL: avançado](../ide/hlsl-property-pages-advanced.md)