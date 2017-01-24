---
title: "P&#225;ginas de propriedade HLSL: geral | Microsoft Docs"
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
  - "VC.Project.FXCompilerTool.ShaderModel"
  - "VC.Project.FXCompilerTool.PreprocessorDefinitions"
  - "VC.Project.FXCompilerTool.ShaderType"
  - "VC.Project.FXCompilerTool.EnableDebuggingInformation"
  - "VC.Project.FXCompilerTool.AdditionalIncludeDirectories"
  - "VC.Project.FXCompilerTool.DisableOptimizations"
  - "VC.Project.FXCompilerTool.EntryPointName"
dev_langs: 
  - "C++"
ms.assetid: 0e02f2a6-f123-43da-b04b-a0719a7c2b03
caps.latest.revision: 8
caps.handback.revision: 8
author: "BrianPeek"
ms.author: "brpeek"
manager: "ghogen"
---
# P&#225;ginas de propriedade HLSL: geral
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para configurar as seguintes propriedades do compilador de HLSL \(fxc.exe\), use a página de propriedades de **Geral** .  Para obter informações sobre como acessar a página de propriedades de **Geral** na pasta de HLSL, consulte [Como especificar propriedades do projeto com páginas de propriedades](../Topic/How%20to:%20Specify%20Project%20Properties%20with%20Property%20Pages.md).  
  
## Lista UIElement  
 **Adicional inclui diretórios**  
 Adiciona um ou vários diretórios incluir o caminho.  Use semi\-confiáveis dois\-pontos para separar os diretórios.  
  
 Esta propriedade corresponde ao argumento de linha de comando **\/I\[path\]** .  
  
 **Nome de Entrypoint**  
 Especifica o ponto de entrada para o shader.  Por padrão, o valor é **main**.  
  
 Esta propriedade corresponde ao argumento de linha de comando **\/E\[name\]** .  
  
 **Otimizações de desativar**  
 **Sim \(\/Od\)** para desativar otimizações; caso contrário, **Não**.  Por padrão, o valor é **Sim \(\/Od\)** para configurações e **Não** de **Depurar** para configurações de **Versão** .  
  
 O argumento de linha de comando **\/Od** para o compilador de HLSL aplica implicitamente o argumento de linha de comando **\/Gfp** , mas saída não podem ser idênticos a saída que são geradas passando os argumentos de linha de comando de **\/Od** e de **\/Gfp** explicitamente.  
  
 **Ativar informações de depuração**  
 **Sim \(\/Zi\)** para ativar informações de depuração; caso contrário, **Não**.  Por padrão, o valor é **Sim \(\/Zi\)** para configurações e **Não** de **Depurar** para configurações de **Versão** .  
  
 **Tipo de Shader**  
 Especifica o tipo do shader.  Tipos diferentes de partes diferentes de implementam de shaders de pipeline gráficos.  Certos tipos de shaders estão disponíveis somente nos modelos mais recentes do shader \(que são especificados pela propriedade de **Shader Model** \) — por exemplo, shaders de cálculo foram introduzidos no modelo 5. do shader.  
  
 Esta propriedade corresponde a parte de **\[type\]** de argumento de linha de comando **\/T \[type\]\_\[model\]** para o compilador de HLSL.  A propriedade de **Modelos de Shader** especifica a parte de **\[model\]** do argumento.  
  
 **Shader Model**  
 Especifica o modelo de shader.  Os diferentes modelos de características têm recursos diferentes.  Geralmente, os modelos mais recentes do shader oferecem recursos expandidos mas exigem um hardware mais modernos hardwares gráficos executar o código do shader.  Certos tipos de shaders \(que são especificados pela propriedade de **Tipo de Shader** \) estão disponíveis somente em um shader mais recente modelo para o exemplo, shaders de cálculo foram introduzidos no modelo 5. do shader.  
  
 Esta propriedade corresponde a parte de **\[model\]** de argumento de linha de comando **\/T \[type\]\_\[model\]** para o compilador de HLSL.  A propriedade de **Tipo de Shader** especifica a parte de **\[type\]** do argumento.  
  
 **Definições do Pré\-processador**  
 Adiciona uma ou mais definições do símbolo pré\-processamento para aplicar o arquivo de código\-fonte de HLSL.  Use semi\-confiáveis dois\-pontos para separar as definições do símbolo.  
  
 Esta propriedade corresponde ao argumento de linha de comando **\/D \[definitions\]** para o compilador de HLSL.  
  
## Consulte também  
 [Páginas de propriedade HLSL](../ide/hlsl-property-pages.md)   
 [Páginas de propriedade HLSL: avançado](../ide/hlsl-property-pages-advanced.md)   
 [Páginas de propriedades HLSL: arquivos de saída](../ide/hlsl-property-pages-output-files.md)