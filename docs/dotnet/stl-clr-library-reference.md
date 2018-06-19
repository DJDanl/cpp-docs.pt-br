---
title: Referência de biblioteca STL/CLR | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- STL/CLR Library
- STL/CLR, redistribution
- cliext directory
ms.assetid: a9d9ca00-7bf2-48c1-b205-3ae6f8c25f82
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 8cab573b0c1de57ef2629f662108098095b722eb
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33171816"
---
# <a name="stlclr-library-reference"></a>Referência de biblioteca STL/CLR
A biblioteca STL/CLR é um pacote de um subconjunto da biblioteca C++ padrão para uso com C++ e .NET Framework common language runtime (CLR). Com STL/CLR, você pode usar os contêineres, iteradores e algoritmos da biblioteca padrão em um ambiente gerenciado.  
  
 Para usar STL/CLR:  
  
-   Incluir cabeçalhos do **cliext** incluem subdiretório em vez dos equivalentes de biblioteca padrão C++ normais.  
  
-   Qualificar nomes de biblioteca com `cliext::` em vez de `std::`.  
  
 STL/CLR expõe os tipos genéricos e interfaces que ele usa em cenários entre os assemblies no assembly .NET **Microsoft.VisualC.STLCLR.dll**. Essa DLL está incluída no .NET Framework 3.5. Se você redistribuir um aplicativo que usa STL/CLR, você precisará incluir o .NET Framework 3.5, bem como quaisquer outras bibliotecas do Visual C++ que usa seu projeto, na seção de dependências do seu projeto de instalação.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Namespace cliext](../dotnet/cliext-namespace.md)  
 Aborda o namespace que contém todos os tipos de biblioteca STL/CLR.  
  
 [Contêineres STL/CLR](../dotnet/stl-clr-containers.md)  
 Fornece uma visão geral dos contêineres que são encontrados na biblioteca padrão C++, incluindo requisitos de elementos de contêiner, tipos de elementos que podem ser inseridos e problemas de propriedade.  
  
 [Requisitos dos elementos de contêiner STL/CLR](../dotnet/requirements-for-stl-clr-container-elements.md)  
 Descreve os requisitos mínimos para todos os tipos de referência que são inseridos em contêineres de biblioteca padrão C++.  
  
 [Como converter de um coleção .NET em um contêiner STL/CLR](../dotnet/how-to-convert-from-a-dotnet-collection-to-a-stl-clr-container.md)  
 Descreve como converter uma coleção .NET em um contêiner STL/CLR.  
  
 [Como converter de um contêiner STL/CLR em uma coleção .NET](../dotnet/how-to-convert-from-a-stl-clr-container-to-a-dotnet-collection.md)  
 Descreve como converter um contêiner STL/CLR em uma coleção do .NET.  
  
 [Como expor um contêiner STL/CLR de um assembly](../dotnet/how-to-expose-an-stl-clr-container-from-an-assembly.md)  
 Mostra como exibir os elementos de vários contêineres STL/CLR gravados em um assembly C++.  
  
 Além disso, esta seção também descreve os seguintes componentes de STL/CLR:  
  
|||  
|-|-|  
|[adapter (STL/CLR)](../dotnet/adapter-stl-clr.md)|[algorithm (STL/CLR)](../dotnet/algorithm-stl-clr.md)|  
|[deque (STL/CLR)](../dotnet/deque-stl-clr.md)|[for each, in](../dotnet/for-each-in.md)|  
|[functional (STL/CLR)](../dotnet/functional-stl-clr.md)|[hash_map (STL/CLR)](../dotnet/hash-map-stl-clr.md)|  
|[hash_multimap (STL/CLR)](../dotnet/hash-multimap-stl-clr.md)|[hash_multiset (STL/CLR)](../dotnet/hash-multiset-stl-clr.md)|  
|[hash_set (STL/CLR)](../dotnet/hash-set-stl-clr.md)|[list (STL/CLR)](../dotnet/list-stl-clr.md)|  
|[map (STL/CLR)](../dotnet/map-stl-clr.md)|[multimap (STL/CLR)](../dotnet/multimap-stl-clr.md)|  
|[multiset (STL/CLR)](../dotnet/multiset-stl-clr.md)|[numeric (STL/CLR)](../dotnet/numeric-stl-clr.md)|  
|[priority_queue (STL/CLR)](../dotnet/priority-queue-stl-clr.md)|[queue (STL/CLR)](../dotnet/queue-stl-clr.md)|  
|[set (STL/CLR)](../dotnet/set-stl-clr.md)|[stack (STL/CLR)](../dotnet/stack-stl-clr.md)|  
|[utility (STL/CLR)](../dotnet/utility-stl-clr.md)|[vector (STL/CLR)](../dotnet/vector-stl-clr.md)|  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)