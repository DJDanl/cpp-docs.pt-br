---
title: "Suporte de biblioteca para assemblies mistos | Microsoft Docs"
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
  - "bibliotecas [C++], assemblies mistos"
  - "assemblies mistos [C++], suporte a biblioteca"
  - "msvcm90[d].dll"
  - "msvcmrt[d].lib"
ms.assetid: 1229595c-9e9d-414d-b018-b4e4c727576d
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Suporte de biblioteca para assemblies mistos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Visual C\+\+ oferece suporte ao uso da biblioteca padrão C\+\+, da biblioteca de tempo de execução comum \(\), CRT de ATL, e de MFC para os aplicativos criados com [\/clr \(compilação do Common Language Runtime\)](../build/reference/clr-common-language-runtime-compilation.md).  Isso permite que os aplicativos existentes que usam essas bibliotecas para também usar recursos do.NET Framework.  
  
 Esse suporte apresenta as seguintes novas bibliotecas da DLL e de importação:  
  
-   \[\] Msvcmrt de .lib se você compila com \/clr.  Links mistos de assemblies a esse biblioteca de importação.  
  
-   \[\] Msvcm90 de .dll e de Msvcurt \[\] .lib se você compila com \/clr:pure.  A DLL é um assembly do tipo misto que fornece suporte gerenciado \(CRT\) de tempo de execução C, e é parte de um assembly gerenciado instalado em cachê de assembly global \(GAC\).  Os assemblies puro vinculam a essa biblioteca de importação e terminam acima associado a Msvcm90.dll.  
  
 Esse suporte fornece vários benefícios relacionados:  
  
-   O CRT e a biblioteca padrão do C\+\+ estão disponíveis para o código misto e puro.  O CRT e a biblioteca padrão do C\+\+ fornecidos não são verificáveis; finalmente, seus chamadas são roteados no mesmo CRT e a biblioteca padrão do C\+\+ que você está usando o código nativo.  
  
-   Corrija a manipulação de exceção unificada nas imagens puras e mistas.  
  
-   Inicialização estático de variáveis C\+\+ em imagens puras e mistas.  
  
-   Suporte para variáveis do appdomains e do processo em código gerenciado.  
  
-   Resolve problemas de bloqueio de carregador se a DLL que foram mesclados no Visual C\+\+ .NET e Visual C\+\+ .NET 2003.  
  
 Além disso, esse suporte apresenta as seguintes restrições:  
  
-   Somente o modelo de DLL de CRT tem suporte \(para o código compilado com \/clr ou \/clr:pure\).  
  
-   Você não pode combinar objetos simples e mesclados em uma única imagem se esses objetos usarão as bibliotecas Visual C\+\+ \(como todos os objetos devem ser simples em uma imagem pura\).  Se você fizer isso, você receberá erros de link\- Horas.  
  
 Você deve atualizar o Common Language Runtime \(CLR\) para a versão atual como se não garante para trabalhar com versões anteriores.  O código compilado com essas alterações não será executado na versão 1.x. de CLR.  
  
## Consulte também  
 [Assemblies mistos \(nativos e gerenciados\)](../Topic/Mixed%20\(Native%20and%20Managed\)%20Assemblies.md)