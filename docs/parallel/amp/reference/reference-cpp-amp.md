---
title: Referência (C++ AMP)
ms.date: 11/04/2016
f1_keywords:
- amp/Concurrency::Reference (C++ AMP)
helpviewer_keywords:
- C++ Accelerated Massive Parallelism, reference
ms.assetid: 372a8aed-8a53-48c9-996f-9c3cf09c9fa8
ms.openlocfilehash: ff7c2b0894a2fa3de7674a72bc93dd3f781398b9
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77126403"
---
# <a name="reference-c-amp"></a>Referência (C++ AMP)

Esta seção contém informações de referência para C++ o tempo de execução aceleradaC++ de grande paralelismo (amp).

> [!NOTE]
> O padrão da linguagem C++ reserva o uso de identificadores que começam com um caractere de sublinhado (`_`) a implementações, como bibliotecas. Não use nomes que começam com um sublinhado no código. O comportamento de elementos de código cujos nomes seguem essa convenção não é garantido e está sujeito a alteração em versões futuras. Por esses motivos, esses elementos de código são omitidos desta documentação.

## <a name="in-this-section"></a>Nesta seção

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)<br/>
Fornece classes e funções que permitem a aceleração C++ do código em hardware paralelo de dados.

[Namespace Concurrency::direct3d](concurrency-direct3d-namespace.md)<br/>
Fornece funções que dão suporte à interoperabilidade do D3D. Permite o uso contínuo de recursos do D3D para computação no código de AMP e o uso de recursos criados no código do AMP in D3D, sem a criação de cópias intermediárias redundantes. Você pode usar C++ o amp para acelerar de forma incremental as seções de computação intensiva de seus aplicativos do DirectX e usar a API do D3D em dados produzidos por meio de cálculos de amp.

[Namespace Concurrency::fast_math](concurrency-fast-math-namespace.md)<br/>
As funções no namespace `fast_math` não são compatíveis com C99. Somente as versões de precisão única de cada função são fornecidas. Essas funções usam as funções intrínsecas do DirectX, que são mais rápidas do que as funções correspondentes no namespace `precise_math` e não exigem suporte estendido de precisão dupla no acelerador, mas elas são menos precisas. Há duas versões de cada função para compatibilidade em nível de origem com o código C99; ambas as versões levam e retornam valores de precisão única.

[Namespace Concurrency::graphics](concurrency-graphics-namespace.md)<br/>
Fornece tipos e funções que são projetados para programação de gráficos.

[Namespace Concurrency::precise_math](concurrency-precise-math-namespace.md)<br/>
As funções no namespace `precise_math` são compatíveis com C99. As versões de precisão única e de precisão dupla de cada função são incluídas. Essas funções – isso inclui as funções de precisão única — exigem suporte estendido de precisão dupla no acelerador.

## <a name="related-sections"></a>Seções Relacionadas

[C++ AMP (C++ Accelerated Massive Parallelism)](../../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)<br/>
C++Acelera a execução do seu C++ código aproveitando o hardware de dados paralelos que normalmente está presente como uma GPU (unidade de processamento gráfico) em uma placa gráfica discreta.
