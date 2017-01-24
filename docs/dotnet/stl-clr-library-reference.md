---
title: "Refer&#234;ncia de biblioteca STL/CLR | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "diretório cliext"
  - "Biblioteca STL/CLR"
  - "STL/CLR, redistribuição"
ms.assetid: a9d9ca00-7bf2-48c1-b205-3ae6f8c25f82
caps.latest.revision: 17
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Refer&#234;ncia de biblioteca STL/CLR
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A Biblioteca STL\/CLR é um empacotamento da Biblioteca de Modelos Padrão \(STL\), de um subconjunto da Biblioteca Padrão do C\+\+, para uso com o common language runtime \(CLR\) do .NET Framework.  Com STL\/CLR, você pode usar todos os contêineres, iteradores, e algoritmos de STL em um ambiente gerenciado.  
  
 Para usar STL\/CLR:  
  
-   Inclui cabeçalhos do subdiretório incluso **cliext** em vez dos equivalentes usuais de biblioteca C\+\+ padrão.  
  
-   Qualifique nomes de biblioteca com `cliext::` em vez de `std::`.  
  
 STL\/CLR expõe os tipos e interfaces genéricos que usa em cenários entre assemblies no assembly do .NET **Microsoft.VisualC.STLCLR.dll**.  Essa DLL foi incluída no .NET Framework 3.5.  Se redistribuir um aplicativo que use STL\/CLR, você precisará incluir o .NET Framework 3.5, bem como todas as outras bibliotecas do Visual C\+\+ usadas pelo projeto, na seção de dependências do projeto de instalação.  
  
## Nesta seção  
 [Namespace cliext](../Topic/cliext%20Namespace.md)  
 Discute o namespace que contém todos os tipos de biblioteca de STL\/CLR.  
  
 [Contêineres STL\/CLR](../dotnet/stl-clr-containers.md)  
 Fornece uma visão geral de contêineres encontrados na biblioteca do C\+\+ Standard, incluindo requisitos para elementos do contêiner, tipos de elementos que podem ser inseridos e problemas de propriedade.  
  
 [Requisitos dos elementos de contêiner STL\/CLR](../Topic/Requirements%20for%20STL-CLR%20Container%20Elements.md)  
 Descreve os requisitos mínimos para todos os tipos de referência que são inseridos em contêineres STL.  
  
 [Como converter de um coleção .NET em um contêiner STL\/CLR](../dotnet/how-to-convert-from-a-dotnet-collection-to-a-stl-clr-container.md)  
 Descreve como converter uma coleção de .NET em um contêiner de STL\/CLR.  
  
 [Como converter de um contêiner STL\/CLR em uma coleção .NET](../dotnet/how-to-convert-from-a-stl-clr-container-to-a-dotnet-collection.md)  
 Descreve como converter um contêiner de STL\/CLR em uma coleção .NET.  
  
 [Como expor um contêiner STL\/CLR a partir de um assembly](../dotnet/how-to-expose-an-stl-clr-container-from-an-assembly.md)  
 Mostra como exibir os elementos de diversos contêineres de STL\/CLR escritos em um assembly C\+\+.  
  
 Além disso, esta seção também descreve os seguintes componentes de STL\/CLR:  
  
|||  
|-|-|  
|[adapter](../dotnet/adapter-stl-clr.md)|[algorithm](../Topic/algorithm%20\(STL-CLR\).md)|  
|[deque](../dotnet/deque-stl-clr.md)|[for each, in](../dotnet/for-each-in.md)|  
|[functional](../dotnet/functional-stl-clr.md)|[hash\_map](../dotnet/hash-map-stl-clr.md)|  
|[hash\_multimap](../dotnet/hash-multimap-stl-clr.md)|[hash\_multiset](../dotnet/hash-multiset-stl-clr.md)|  
|[hash\_set](../dotnet/hash-set-stl-clr.md)|[list](../dotnet/list-stl-clr.md)|  
|[map](../dotnet/map-stl-clr.md)|[multimapa](../dotnet/multimap-stl-clr.md)|  
|[multiset](../dotnet/multiset-stl-clr.md)|[numérico](../dotnet/numeric-stl-clr.md)|  
|[priority\_queue](../Topic/priority_queue%20\(STL-CLR\).md)|[queue](../Topic/queue%20\(STL-CLR\).md)|  
|[set](../dotnet/set-stl-clr.md)|[stack](../dotnet/stack-stl-clr.md)|  
|[utility](../dotnet/utility-stl-clr.md)|[vector](../dotnet/vector-stl-clr.md)|  
  
## Consulte também  
 [Biblioteca Padrão C\+\+](../standard-library/cpp-standard-library-reference.md)