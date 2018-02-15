---
title: C++ AMP (C++ Accelerated Massive Parallelism) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- C++ AMP (see C++ Accelerated Massive Parallelism)
- C++ Accelerated Massive Parallelism, getting started
ms.assetid: e27824cb-3167-409b-8c3f-a0e476d8f349
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 514c45599bce85bf66bf473ac597dab255888ba8
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="c-amp-c-accelerated-massive-parallelism"></a>C++ AMP (C++ Accelerated Massive Parallelism)
C++ AMP (C++ Accelerated Massive Parallelism) acelera a execução do código C++, que aproveita o hardware paralelo de dados que é comumente presente como uma unidade de processamento gráfico (GPU) em uma placa gráfica distinta. O modelo de programação C++ AMP inclui suporte para matrizes multidimensionais, indexação, transferência de memória e o lado a lado. Ele também inclui uma biblioteca de funções matemáticas. Você pode usar extensões de linguagem do C++ AMP para controlar como os dados são movidos da CPU para a GPU e fazer.  
  
## <a name="related-topics"></a>Tópicos relacionados  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Visão geral do C++ AMP](../../parallel/amp/cpp-amp-overview.md)|Descreve os principais recursos do C++ AMP e a biblioteca de matemática.|  
|[Usando lambdas, objetos de função e funções restritas](../../parallel/amp/using-lambdas-function-objects-and-restricted-functions.md)|Descreve como usar expressões lambda, objetos de função e funções restritas em chamadas para o [parallel_for_each](reference/concurrency-namespace-functions-amp.md#parallel_for_each) método.|  
|[Usando blocos](../../parallel/amp/using-tiles.md)|Descreve como usar blocos para acelerar o seu código C++ AMP.|  
|[Usando objetos accelerator e accelerator_view](../../parallel/amp/using-accelerator-and-accelerator-view-objects.md)|Descreve como usar aceleradores para personalizar a execução do código na GPU.|  
|[Usando C++ AMP em aplicativos UWP](../../parallel/amp/using-cpp-amp-in-windows-store-apps.md)|Descreve como usar C++ AMP em aplicativos do Windows UWP (plataforma Universal) que usam tipos de tempo de execução do Windows.|  
|[Elementos gráficos (C++ AMP)](../../parallel/amp/graphics-cpp-amp.md)|Descreve como usar a biblioteca de elementos gráficos do C++ AMP.|  
|[Passo a passo: multiplicação de matrizes](../../parallel/amp/walkthrough-matrix-multiplication.md)|Demonstra a multiplicação de matrizes usando o código C++ AMP e lado a lado.|  
|[Passo a passo: depurando um aplicativo C++ AMP](../../parallel/amp/walkthrough-debugging-a-cpp-amp-application.md)|Explica como criar e depurar um aplicativo que usa redução paralela para somar uma grande matriz de inteiros.|  
  
## <a name="reference"></a>Referência  
 [Referência (C++ AMP)](../../parallel/amp/reference/reference-cpp-amp.md)  
  
 [Palavra-chave tile_static](../../cpp/tile-static-keyword.md)  
  
 [restrict (C++ AMP)](../../cpp/restrict-cpp-amp.md)  
  
## <a name="other-resources"></a>Outros recursos  
 [Programação paralela no Blog de código nativo](http://go.microsoft.com/fwlink/p/?linkid=238472)  
  
 [Projetos de exemplo do C++ AMP para download](http://go.microsoft.com/fwlink/p/?linkid=248508)  
  
 [Análise de código do C++ AMP com o Visualizador de simultaneidade](http://go.microsoft.com/fwlink/p/?linkid=253987&clcid=0x409)

