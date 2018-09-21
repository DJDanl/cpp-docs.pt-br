---
title: Referência de biblioteca STL/CLR | Microsoft Docs
ms.custom: ''
ms.date: 09/18/2018"
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
ms.openlocfilehash: 14217396801731505753be121e98f0aebf5b5f22
ms.sourcegitcommit: 338e1ddc2f3869d92ba4b73599d35374cf1d5b69
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/20/2018
ms.locfileid: "46494381"
---
# <a name="stlclr-library-reference"></a>Referência de biblioteca STL/CLR

A biblioteca STL/CLR fornece uma interface semelhante para os contêineres da biblioteca padrão C++ para uso com C++ e o .NET Framework common language runtime (CLR). STL/CLR é completamente separado da implementação da Microsoft a biblioteca C++ padrão. STL/CLR é mantida para dar suporte, mas não é mantido atualizado com o padrão C++. É altamente recomendável usar nativo [biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md) contêineres em vez de STL/CLR sempre que possível.

Para usar STL/CLR:

- Incluir cabeçalhos do **cliext** incluem o subdiretório em vez dos equivalentes usuais de biblioteca padrão C++.

- Qualificar nomes de biblioteca com `cliext::` em vez de `std::`.

A biblioteca STL/CLR fornece uma interface de STL para uso com C++ e o .NET Framework common language runtime (CLR). Essa biblioteca é mantida para dar suporte, mas não é mantida atualizada com o padrão C++. É altamente recomendável usar nativo [biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md) contêineres em vez de STL/CLR.

## <a name="in-this-section"></a>Nesta seção

[Namespace cliext](../dotnet/cliext-namespace.md)<br/>
Discute o namespace que contém todos os tipos da biblioteca STL/CLR.

[Contêineres STL/CLR](../dotnet/stl-clr-containers.md)<br/>
Fornece uma visão geral dos contêineres que são encontradas na biblioteca padrão C++, incluindo requisitos de elementos de contêiner, tipos de elementos que podem ser inseridos e problemas de propriedade.

[Requisitos dos elementos de contêiner STL/CLR](../dotnet/requirements-for-stl-clr-container-elements.md)<br/>
Descreve os requisitos mínimos para todos os tipos de referência que são inseridos em contêineres da biblioteca padrão C++.

[Como converter de um coleção .NET em um contêiner STL/CLR](../dotnet/how-to-convert-from-a-dotnet-collection-to-a-stl-clr-container.md)<br/>
Descreve como converter uma coleção .NET em um contêiner STL/CLR.

[Como converter de um contêiner STL/CLR em uma coleção .NET](../dotnet/how-to-convert-from-a-stl-clr-container-to-a-dotnet-collection.md)<br/>
Descreve como converter um contêiner STL/CLR em uma coleção .NET.

[Como expor um contêiner STL/CLR de um assembly](../dotnet/how-to-expose-an-stl-clr-container-from-an-assembly.md)<br/>
Mostra como exibir os elementos de vários contêineres STL/CLR escritos em um assembly C++.

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
