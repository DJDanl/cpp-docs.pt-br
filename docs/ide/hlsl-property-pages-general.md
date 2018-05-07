---
title: 'Páginas de propriedade HLSL: Geral | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- VC.Project.FXCompilerTool.ShaderModel
- VC.Project.FXCompilerTool.PreprocessorDefinitions
- VC.Project.FXCompilerTool.ShaderType
- VC.Project.FXCompilerTool.EnableDebuggingInformation
- VC.Project.FXCompilerTool.AdditionalIncludeDirectories
- VC.Project.FXCompilerTool.DisableOptimizations
- VC.Project.FXCompilerTool.EntryPointName
dev_langs:
- C++
ms.assetid: 0e02f2a6-f123-43da-b04b-a0719a7c2b03
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 77cc9a44076999633fd17b049cbcfad75f65eb7e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="hlsl-property-pages-general"></a>Páginas de propriedade HLSL: geral
Para configurar as seguintes propriedades do compilador HLSL (fxc.exe), use seu **geral** página de propriedades. Para obter informações sobre como acessar o **geral** página de propriedades na pasta HLSL, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Adicionais diretórios de inclusão**  
 Adiciona um ou mais diretórios para o caminho de inclusão. Use ponto e vírgula para separar os diretórios.  
  
 Essa propriedade corresponde do **/I [caminho]** argumento de linha de comando.  
  
 **Nome do ponto de entrada**  
 Especifica o ponto de entrada para o sombreador. Por padrão, o valor é **principal**.  
  
 Essa propriedade corresponde do **/E [nome]** argumento de linha de comando.  
  
 **Desabilitar otimizações**  
 **Sim (/ Od)** para desabilitar otimizações; caso contrário, **não**. Por padrão, o valor é **Sim (/ Od)** para **depurar** configurações e **não** para **versão** configurações.  
  
 O **/Od** argumento de linha de comando para o compilador HLSL implicitamente se aplica a **/Gfp** argumento de linha de comando, mas a saída não pode ser idêntica à saída produzida passando ambos o **/Od**  e **/Gfp** argumentos de linha de comando explicitamente.  
  
 **Habilitar informações de depuração**  
 **Sim (/Zi)** para habilitar as informações de depuração; caso contrário, **não**. Por padrão, o valor é **Sim (/Zi)** para **depurar** configurações e **não** para **versão** configurações.  
  
 **Tipo de sombreador**  
 Especifica o tipo de sombreador. Tipos diferentes de sombreadores implementam diferentes partes do pipeline de gráficos. Determinados tipos de sombreadores estão disponíveis apenas em modelos de sombreador mais recentes (que são especificados pelo **Shader Model** propriedade) — por exemplo, computar sombreadores foram introduzidos no modelo de sombreador 5.  
  
 Essa propriedade corresponde do **[tipo]** parte do **/T [tipo] _ [modelo]** argumento de linha de comando para o compilador HLSL. O **modelos de sombreador** propriedade especifica o **[modelo]** parte do argumento.  
  
 **Modelo de sombreador**  
 Especifica o modelo de sombreador. Modelos de sombreador diferentes têm recursos diferentes. Em geral, modelos de sombreador mais recentes oferecem recursos expandidos, mas exigem mais moderna hardware de gráficos para executar o código de sombreador. Determinados tipos de sombreadores (que são especificados pelo **tipo de sombreador** propriedade) estão disponíveis apenas nos modelos de sombreador mais recentes — por exemplo, computar sombreadores foram introduzidos no modelo de sombreador 5.  
  
 Essa propriedade corresponde do **[modelo]** parte do **/T [tipo] _ [modelo]** argumento de linha de comando para o compilador HLSL. O **tipo de sombreador** propriedade especifica o **[tipo]** parte do argumento.  
  
 **Definições de pré-processador**  
 Adiciona uma ou mais definições de símbolo do pré-processador para aplicar o arquivo de código de origem HLSL. Use ponto e vírgula para separar as definições de símbolo.  
  
 Essa propriedade corresponde do **/D [definições]** argumento de linha de comando para o compilador HLSL.  
  
## <a name="see-also"></a>Consulte também  
 [Páginas de propriedade HLSL](../ide/hlsl-property-pages.md)   
 [Páginas de propriedade HLSL: avançado](../ide/hlsl-property-pages-advanced.md)   
 [Páginas de propriedades HLSL: arquivos de saída](../ide/hlsl-property-pages-output-files.md)