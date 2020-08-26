---
title: Referência de biblioteca STL/CLR
ms.date: 09/18/2018
ms.topic: reference
helpviewer_keywords:
- STL/CLR Library
- STL/CLR, redistribution
- cliext directory
ms.assetid: a9d9ca00-7bf2-48c1-b205-3ae6f8c25f82
ms.openlocfilehash: e6804dab814eca4ecc5fd23c74cbbb21eac3be77
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88839693"
---
# <a name="stlclr-library-reference"></a>Referência de biblioteca STL/CLR

A biblioteca STL/CLR fornece uma interface semelhante aos contêineres de biblioteca padrão do C++ para uso com C++ e o Common Language Runtime de .NET Framework (CLR). STL/CLR é completamente separado da implementação da Microsoft da biblioteca do C++ Standard. A STL/CLR é mantida para suporte herdado, mas não é mantida atualizada com o padrão C++. É altamente recomendável usar os contêineres de [biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md) nativos em vez de STL/CLR sempre que possível.

Para usar STL/CLR:

- Incluir cabeçalhos do **cliext** incluir subdiretório em vez dos equivalentes da biblioteca padrão C++ comum.

- Qualifique nomes de biblioteca com `cliext::` em vez de `std::` .

A biblioteca STL/CLR fornece uma interface do tipo STL para uso com C++ e o .NET Framework Common Language Runtime (CLR). Essa biblioteca é mantida para suporte herdado, mas não é mantida atualizada com o padrão C++. É altamente recomendável usar os contêineres de [biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md) nativos em vez de STL/CLR.

## <a name="in-this-section"></a>Nesta seção

[Namespace cliext](../dotnet/cliext-namespace.md)<br/>
Discute o namespace que contém todos os tipos da biblioteca STL/CLR.

[Contêineres STL/CLR](../dotnet/stl-clr-containers.md)<br/>
Fornece uma visão geral dos contêineres encontrados na biblioteca padrão C++, incluindo requisitos para elementos de contêiner, tipos de elementos que podem ser inseridos e problemas de propriedade.

[Requisitos para elementos de contêiner STL/CLR](../dotnet/requirements-for-stl-clr-container-elements.md)<br/>
Descreve os requisitos mínimos para todos os tipos de referência que são inseridos em contêineres de biblioteca padrão C++.

[Como converter de uma coleção .NET em um contêiner STL/CLR](../dotnet/how-to-convert-from-a-dotnet-collection-to-a-stl-clr-container.md)<br/>
Descreve como converter uma coleção do .NET em um contêiner STL/CLR.

[Como converter de um contêiner STL/CLR em uma coleção .NET](../dotnet/how-to-convert-from-a-stl-clr-container-to-a-dotnet-collection.md)<br/>
Descreve como converter um contêiner STL/CLR em uma coleção .NET.

[Como: expor um contêiner STL/CLR de um assembly](../dotnet/how-to-expose-an-stl-clr-container-from-an-assembly.md)<br/>
Mostra como exibir os elementos de vários contêineres STL/CLR escritos em um assembly C++.

Além disso, esta seção também descreve os seguintes componentes da STL/CLR:

:::row:::
   :::column span="":::
      [`adapter` (STL/CLR)](../dotnet/adapter-stl-clr.md)\
      [`algorithm` (STL/CLR)](../dotnet/algorithm-stl-clr.md)\
      [`deque` (STL/CLR)](../dotnet/deque-stl-clr.md)\
      [`for each`, `in`](../dotnet/for-each-in.md)\
      [`functional` (STL/CLR)](../dotnet/functional-stl-clr.md)\
      [`hash_map` (STL/CLR)](../dotnet/hash-map-stl-clr.md)\
      [`hash_multimap` (STL/CLR)](../dotnet/hash-multimap-stl-clr.md)\
      [`hash_multiset` (STL/CLR)](../dotnet/hash-multiset-stl-clr.md)\
      [`hash_set` (STL/CLR)](../dotnet/hash-set-stl-clr.md)\
      [`list` (STL/CLR)](../dotnet/list-stl-clr.md)\
   :::column-end:::
   :::column span="":::
      [`map` (STL/CLR)](../dotnet/map-stl-clr.md)\
      [`multimap` (STL/CLR)](../dotnet/multimap-stl-clr.md)\
      [`multiset` (STL/CLR)](../dotnet/multiset-stl-clr.md)\
      [`numeric` (STL/CLR)](../dotnet/numeric-stl-clr.md)\
      [`priority_queue` (STL/CLR)](../dotnet/priority-queue-stl-clr.md)\
      [`queue` (STL/CLR)](../dotnet/queue-stl-clr.md)\
      [`set` (STL/CLR)](../dotnet/set-stl-clr.md)\
      [`stack` (STL/CLR)](../dotnet/stack-stl-clr.md)\
      [`utility` (STL/CLR)](../dotnet/utility-stl-clr.md)\
      [`vector` (STL/CLR)](../dotnet/vector-stl-clr.md)\
   :::column-end:::
:::row-end:::

## <a name="see-also"></a>Confira também

[Biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
