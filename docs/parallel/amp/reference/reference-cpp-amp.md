---
title: Referência (C++ AMP) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-amp
ms.topic: reference
f1_keywords:
- amp/Concurrency::Reference (C++ AMP)
dev_langs:
- C++
helpviewer_keywords:
- C++ Accelerated Massive Parallelism, reference
ms.assetid: 372a8aed-8a53-48c9-996f-9c3cf09c9fa8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8c39528bf3b1e6c9235e4b2daabcd8bbddd0d52f
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33685886"
---
# <a name="reference-c-amp"></a>Referência (C++ AMP)
Esta seção contém informações de referência para o tempo de execução C++ Accelerated Massive Parallelism (C++ AMP).  
  
> [!NOTE]
>  O padrão da linguagem C++ reserva o uso de identificadores que começam com um caractere de sublinhado (`_`) a implementações, como bibliotecas. Não use nomes que começam com um sublinhado no código. O comportamento de elementos de código cujos nomes seguem essa convenção não é garantido e está sujeito a alteração em versões futuras. Por esses motivos, esses elementos de código são omitidos desta documentação.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)  
 Fornece classes e funções que permitem a aceleração de código C++ no hardware paralelo de dados.  
  
 [Namespace Concurrency::direct3d](concurrency-direct3d-namespace.md)  
 Fornece funções que oferecem suporte à interoperabilidade D3D. Permite o uso direto de D3D recursos de computação no código de AMP e o uso de recursos criados em AMP D3D código, sem criar cópias redundantes de intermediárias. Você pode usar C++ AMP incrementalmente acelerar as seções de computação intensa de seus aplicativos DirectX e usar a API do D3D em dados produzidos de cálculos AMP.  
  
 [Namespace Concurrency::fast_math](concurrency-fast-math-namespace.md)  
 Funções no `fast_math` namespace não são compatíveis com C99. Somente as versões de precisão única de cada função são fornecidas. Essas funções usam as funções intrínsecas DirectX, que são mais rápidas que as funções correspondentes no `precise_math` namespace e não requerem suporte estendido de precisão dupla do Accelerator, mas eles são menos precisos. Há duas versões de cada função de compatibilidade de nível de origem com o código de C99; ambas as versões levar e retornam valores de precisão simples.  
  
 [Namespace Concurrency::graphics](concurrency-graphics-namespace.md)  
 Fornece tipos e funções que são projetadas para programação de elementos gráficos.  
  
 [Namespace Concurrency::precise_math](concurrency-precise-math-namespace.md)  
 Funções no `precise_math` namespace são C99 compatíveis. Versões de precisão simples e precisão dupla de cada função são incluídas. Essas funções — isso inclui as funções de precisão simples — requerem suporte estendido de precisão dupla no acelerador.  
  
## <a name="related-sections"></a>Seções relacionadas  
 [C++ AMP (C++ Accelerated Massive Parallelism)](../../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)  
 C++ AMP acelera a execução do código C++, que aproveita o hardware paralelo de dados que é comumente presente como uma unidade de processamento gráfico (GPU) em uma placa gráfica distinta.





