---
title: "Compara&#231;&#227;o de recursos mistos, puros e verific&#225;veis (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "assemblies mistos [C++]"
  - "assemblies mistos [C++], vs. puro"
  - "assemblies mistos [C++], vs. seguro"
  - "assemblies puros [C++]"
  - "MSIL puro [C++]"
  - "MSIL puro [C++], em comparação com misto e seguro"
  - "MSIL puro [C++], vs. misto"
  - "MSIL puro [C++], vs. seguro"
  - "assemblies seguros [C++]"
  - "assemblies seguros [C++], vs. misto"
  - "assemblies seguros [C++], vs. puro"
  - "assemblies verificáveis [C++]"
  - "assemblies verificáveis [C++], vs. misto"
  - "assemblies verificáveis [C++], vs. puro"
ms.assetid: 3f7a82ba-0e69-4927-ba0c-fbc3160e4394
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Compara&#231;&#227;o de recursos mistos, puros e verific&#225;veis (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico compara recursos entre os diferentes modos de compilação de **\/clr** .  Para obter mais informações, consulte [\/clr \(compilação do Common Language Runtime\)](../build/reference/clr-common-language-runtime-compilation.md).  
  
## Comparação de recursos  
  
|Recurso|Misto \(\/clr\)|Puro \(\/clr:pure\)|Segura \(\/clr:safe\)|Informações relacionadas|  
|-------------|---------------------|-------------------------|---------------------------|------------------------------|  
|Biblioteca do CRT|suporte|suporte||[Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)|  
|MFC\/ATL|suporte|||[Aplicativos para desktop do MFC](../mfc/mfc-desktop-applications.md) &#124; [Visão geral de classe](../atl/atl-class-overview.md)|  
|Funções não gerenciado|suporte|||[Assemblies mistos \(nativos e gerenciados\)](../Topic/Mixed%20\(Native%20and%20Managed\)%20Assemblies.md)|  
|Dados não gerenciado|suporte|suporte||[Código puro e verificável](../dotnet/pure-and-verifiable-code-cpp-cli.md)|  
|Acessível de funções não gerenciado|suporte|||[Como migrar para \/clr:pure](../dotnet/how-to-migrate-to-clr-pure-cpp-cli.md)|  
|O oferece suporte a funções que chamam não gerenciado|suporte|o C \- estilo funciona somente|Somente P\/Invoke|[Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md)|  
|Reflexão da suporte|DLL apenas|suporte|suporte|[Reflexão](../dotnet/reflection-cpp-cli.md)|  
  
## Consulte também  
 [Código puro e verificável](../dotnet/pure-and-verifiable-code-cpp-cli.md)