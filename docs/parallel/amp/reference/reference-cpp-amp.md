---
title: Referência (C++ AMP)
ms.date: 11/04/2016
f1_keywords:
- amp/Concurrency::Reference (C++ AMP)
helpviewer_keywords:
- C++ Accelerated Massive Parallelism, reference
ms.assetid: 372a8aed-8a53-48c9-996f-9c3cf09c9fa8
ms.openlocfilehash: a334c7873675183dc06abfc2fe51472190996bf3
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57257501"
---
# <a name="reference-c-amp"></a>Referência (C++ AMP)

Esta seção contém informações de referência para o tempo de execução C++ Accelerated Massive Parallelism (C++ AMP).

> [!NOTE]
>  O padrão da linguagem C++ reserva o uso de identificadores que começam com um caractere de sublinhado (`_`) a implementações, como bibliotecas. Não use nomes que começam com um sublinhado no código. O comportamento de elementos de código cujos nomes seguem essa convenção não é garantido e está sujeito a alteração em versões futuras. Por esses motivos, esses elementos de código são omitidos desta documentação.

## <a name="in-this-section"></a>Nesta seção

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)<br/>
Fornece classes e funções que habilitam a aceleração de código C++ no hardware paralelo de dados.

[Namespace Concurrency::direct3d](concurrency-direct3d-namespace.md)<br/>
Fornece funções que suportam a interoperabilidade D3D. Permite o uso contínuo de recursos de D3D para cálculos no código de AMP e o uso de recursos criados no AMP no código D3D, sem criar cópias intermediários redundantes. Você pode usar o C++ AMP acelerar de forma crescente as seções intensas de cálculo dos seus aplicativos DirectX e usar o D3D API em dados gerados pelos cálculos AMP.

[Namespace Concurrency::fast_math](concurrency-fast-math-namespace.md)<br/>
Funções no `fast_math` namespace não são compatíveis com C99. São fornecidas apenas versões de precisão simples de cada função. Essas funções usam as funções intrínsecas do DirectX, que são mais rápidas que as funções correspondentes no `precise_math` namespace e não exigem suporte de precisão dupla estendido no Acelerador, mas eles são menos precisos. Há duas versões de cada função para compatibilidade no nível de código-fonte com código C99; as duas versões adotam e retornam valores de precisão simples.

[Namespace Concurrency::graphics](concurrency-graphics-namespace.md)<br/>
Fornece tipos e funções projetadas para programação de elementos gráficos.

[Namespace Concurrency::precise_math](concurrency-precise-math-namespace.md)<br/>
Funções no `precise_math` namespace são compatíveis com C99. Versões de precisão simples e de precisão dupla de cada função são incluídas. Essas funções — isso inclui as funções de precisão simples — exigem suporte de precisão dupla estendido no acelerador.

## <a name="related-sections"></a>Seções relacionadas

[C++ AMP (C++ Accelerated Massive Parallelism)](../../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)<br/>
O C++ AMP acelera a execução do seu código C++, tirando proveito do hardware de dados paralelos comumente apresentado como uma unidade de processamento gráfico (GPU) em uma placa gráfica discreta.
