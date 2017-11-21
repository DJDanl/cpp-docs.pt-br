---
title: "Páginas de propriedade HLSL: Arquivos de saída | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.FXCompilerTool.AssemblerOutput
- VC.Project.FXCompilerTool.ObjectFileOutput
- VC.Project.FXCompilerTool.HeaderFileOutput
- VC.Project.FXCompilerTool.VariableName
- VC.Project.FXCompilerTool.AssemblerOutputFile
dev_langs: C++
ms.assetid: c5ba1e72-30de-43eb-a15a-5b0ae58e55c2
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 0d41e6f1fd4cf66b45d4f79f4f1b27b3fc4d67a8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="hlsl-property-pages-output-files"></a>Páginas de propriedades HLSL: arquivos de saída
Para configurar as seguintes propriedades do compilador HLSL (fxc.exe), use seu **arquivos de saída** propriedade. Para obter informações sobre como acessar o **arquivos de saída** página de propriedades na pasta HLSL, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Nome de variável de cabeçalho**  
 Especifica o nome de uma matriz que é usado para o código de objeto HLSL codificado. A matriz está contida em um arquivo de cabeçalho produzido pelo compilador HLSL. O nome do arquivo de cabeçalho é especificado pelo **nome de arquivo de cabeçalho** propriedade.  
  
 Essa propriedade corresponde do **/Vn [nome]** argumento de linha de comando.  
  
 **Nome do arquivo de cabeçalho**  
 Especifica o nome do arquivo de cabeçalho produzido pelo compilador HLSL. O cabeçalho contém código objeto HLSL que é codificado em uma matriz. O nome da matriz é especificado pelo **nome de variável de cabeçalho** propriedade.  
  
 Essa propriedade corresponde do **/Fh [nome]** argumento de linha de comando.  
  
 **Nome do arquivo de objeto**  
 Especifica o nome do arquivo de objeto produzido pelo compilador HLSL. Por padrão, o valor é **$(OutDir) % (Filename) .cso**.  
  
 Essa propriedade corresponde do **/Fo [name]** argumento de linha de comando.  
  
 **Saída do Assembler**  
 **Listagem de assembly (/ Fc)** para apenas as instruções de linguagem de assembly de saída. **Código de assembly e Hex (/ Fx)** para a saída de instruções de linguagem de assembly e o código op correspondente em hexadecimal. Por padrão, nenhuma lista é de saída.  
  
 **Arquivo de saída do Assembler**  
 Especifica o nome do arquivo de listagem de assembly de saída pelo compilador HLSL.  
  
 Essa propriedade corresponde do **/Fc [nome]** e **/Fx [nome]** argumentos de linha de comando.  
  
## <a name="see-also"></a>Consulte também  
 [Páginas de propriedade HLSL](../ide/hlsl-property-pages.md)   
 [Páginas de propriedade HLSL: geral](../ide/hlsl-property-pages-general.md)   
 [Páginas de propriedade HLSL: avançado](../ide/hlsl-property-pages-advanced.md)