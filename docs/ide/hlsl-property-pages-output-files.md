---
title: "P&#225;ginas de propriedades HLSL: arquivos de sa&#237;da | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.FXCompilerTool.AssemblerOutput"
  - "VC.Project.FXCompilerTool.ObjectFileOutput"
  - "VC.Project.FXCompilerTool.HeaderFileOutput"
  - "VC.Project.FXCompilerTool.VariableName"
  - "VC.Project.FXCompilerTool.AssemblerOutputFile"
dev_langs: 
  - "C++"
ms.assetid: c5ba1e72-30de-43eb-a15a-5b0ae58e55c2
caps.latest.revision: 5
caps.handback.revision: 5
author: "BrianPeek"
ms.author: "brpeek"
manager: "ghogen"
---
# P&#225;ginas de propriedades HLSL: arquivos de sa&#237;da
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para configurar as seguintes propriedades do compilador de HLSL \(fxc.exe\), use a propriedade de **Arquivos de Saída** .  Para obter informações sobre como acessar a página de propriedades de **Arquivos de Saída** na pasta de HLSL, consulte [Como especificar propriedades do projeto com páginas de propriedades](../Topic/How%20to:%20Specify%20Project%20Properties%20with%20Property%20Pages.md).  
  
## Lista UIElement  
 **Nome de variável de cabeçalho**  
 Especifica o nome de uma matriz que é código objeto codificado usado de HLSL.  A matriz é contida em um arquivo de cabeçalho que é saída pelo compilador de HLSL.  O nome do arquivo de cabeçalho é especificado pela propriedade de **Nome de arquivo de cabeçalho** .  
  
 Esta propriedade corresponde ao argumento de linha de comando **\/Vn\[name\]** .  
  
 **Nome de arquivo de cabeçalho**  
 Especifica o nome do arquivo de cabeçalho que é saída pelo compilador de HLSL.  O cabeçalho contém o código de objeto de HLSL que é codificado em uma matriz.  O nome da matriz é especificado pela propriedade de **Nome de variável de cabeçalho** .  
  
 Esta propriedade corresponde ao argumento de linha de comando **\/Fh\[name\]** .  
  
 **Nome de arquivo do objeto**  
 Especifica o nome do arquivo de objeto que é saída pelo compilador de HLSL.  Por padrão, o valor é **% $ \(OutDir\) \(nome de arquivo\) .cso**.  
  
 Esta propriedade corresponde ao argumento de linha de comando **\/Fo\[name\]** .  
  
 **Saída de assembler**  
 **Listagem do assembly \(Somente \/Fc\)** as instruções de linguagem de assembly " de saída apenas.  **O código do assembly e encanta \(\/Fx\)** as instruções de linguagem de assembly " de saída e o op\- código correspondente em hexadecimal.  Por padrão, nenhuma lista é saída.  
  
 **Arquivo de saída de assembler**  
 Especifica o nome do arquivo de listagem de assembly que é saída pelo compilador de HLSL.  
  
 Esta propriedade corresponde aos argumentos de linha de comando **\/Fc\[name\]** e de **\/Fx \[name\]** .  
  
## Consulte também  
 [Páginas de propriedade HLSL](../ide/hlsl-property-pages.md)   
 [Páginas de propriedade HLSL: geral](../ide/hlsl-property-pages-general.md)   
 [Páginas de propriedade HLSL: avançado](../ide/hlsl-property-pages-advanced.md)