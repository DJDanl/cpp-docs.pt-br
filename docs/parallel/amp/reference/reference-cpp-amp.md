---
title: "Referência (C++ AMP) | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amp/Concurrency::Reference (C++ AMP)
dev_langs:
- C++
helpviewer_keywords:
- C++ Accelerated Massive Parallelism, reference
ms.assetid: 372a8aed-8a53-48c9-996f-9c3cf09c9fa8
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 22ba62ab8b3b4f9d14953dbab3edd8228ea85193
ms.openlocfilehash: cc654cedd8639377ab7011c91454f1508c730247
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="reference-c-amp"></a>Referência (C++ AMP)
Esta seção contém informações de referência para o tempo de execução C++ Accelerated Massive Parallelism (C++ AMP).  
  
> [!NOTE]
>  O padrão da linguagem C++ reserva o uso de identificadores que começam com um caractere de sublinhado (`_`) a implementações, como bibliotecas. Não use nomes que começam com um sublinhado no código. O comportamento de elementos de código cujos nomes seguem essa convenção não é garantido e está sujeito a alteração em versões futuras. Por esses motivos, esses elementos de código são omitidos desta documentação.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)  
 Fornece classes e funções que permitem a aceleração de código C++ no hardware paralelo de dados.  
  
 [Namespace Concurrency:: Direct3D](concurrency-direct3d-namespace.md)  
 Fornece funções que têm suporte D3D interoperabilidade. Permite o uso direto de D3D recursos de computação no código AMP e o uso de recursos criados em AMP D3D código, sem criar cópias redundantes de intermediárias. Você pode usar C++ AMP incrementalmente acelerar as seções de computação intensiva de seus aplicativos DirectX e usar a API D3D dados produzidos de computações AMP.  
  
 [Namespace Concurrency:: fast_math](concurrency-fast-math-namespace.md)  
 Funções no `fast_math` namespace não são compatíveis com C99. São fornecidas somente versões de precisão única de cada função. Essas funções usam as funções intrínsecas DirectX, que são mais rápidas que as funções correspondentes no `precise_math` namespace e não requerem suporte estendido de precisão dupla do Accelerator, mas eles são menos precisos. Há duas versões de cada função de compatibilidade de nível de origem com o código de C99; ambas as versões levarem e retornam valores de precisão única.  
  
 [Namespace Concurrency:: Graphics](concurrency-graphics-namespace.md)  
 Fornece tipos e funções que são projetadas para programação de gráficos.  
  
 [Namespace Concurrency:: precise_math](concurrency-precise-math-namespace.md)  
 Funções no `precise_math` namespace são compatíveis com C99. Versões de precisão única e de precisão dupla de cada função estão incluídas. Essas funções — isso inclui as funções de precisão simples — exigem suporte estendido de precisão dupla do Accelerator.  
  
## <a name="related-sections"></a>Seções relacionadas  
 [C++ AMP (C++ Accelerated Massive Parallelism)](../../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)  
 C++ AMP acelera a execução de seu código C++, tirando proveito do hardware paralelo de dados normalmente presente como uma unidade de processamento gráfico (GPU) em uma placa gráfica discreta.






