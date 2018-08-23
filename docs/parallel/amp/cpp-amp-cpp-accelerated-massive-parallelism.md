---
title: C++ AMP (C++ Accelerated Massive Parallelism) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-amp
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- C++ AMP (see C++ Accelerated Massive Parallelism)
- C++ Accelerated Massive Parallelism, getting started
ms.assetid: e27824cb-3167-409b-8c3f-a0e476d8f349
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a990acd8f27be476ce35d682a19912dcc85bbeed
ms.sourcegitcommit: e9ce38decc9f986edab5543de3464b11ebccb123
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/13/2018
ms.locfileid: "42545719"
---
# <a name="c-amp-c-accelerated-massive-parallelism"></a>C++ AMP (C++ Accelerated Massive Parallelism)
C++ AMP (C++ Accelerated Massive Parallelism) acelera a execução do seu código C++, tirando proveito do hardware de dados paralelos comumente apresentado como uma unidade de processamento gráfico (GPU) em uma placa gráfica discreta. O modelo de programação do C++ AMP inclui suporte para matrizes multidimensionais, indexação, transferência de memória e lado a lado. Ele também inclui uma biblioteca de funções matemáticas. Você pode usar extensões de linguagem do C++ AMP para controlar como os dados são movidos da CPU para a GPU e de volta.  
  
## <a name="related-topics"></a>Tópicos relacionados  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Visão geral do C++ AMP](../../parallel/amp/cpp-amp-overview.md)|Descreve os principais recursos do C++ AMP e da biblioteca de matemática.|  
|[Usando lambdas, objetos de função e funções restritas](../../parallel/amp/using-lambdas-function-objects-and-restricted-functions.md)|Descreve como usar expressões lambda, objetos de função e funções restritas em chamadas para o [parallel_for_each](reference/concurrency-namespace-functions-amp.md#parallel_for_each) método.|  
|[Usando blocos](../../parallel/amp/using-tiles.md)|Descreve como usar tiles para acelerar seu código C++ AMP.|  
|[Usando objetos accelerator e accelerator_view](../../parallel/amp/using-accelerator-and-accelerator-view-objects.md)|Descreve como usar aceleradores para personalizar a execução do seu código na GPU.|  
|[Usando C++ AMP em aplicativos UWP](../../parallel/amp/using-cpp-amp-in-windows-store-apps.md)|Descreve como usar o C++ AMP em aplicativos de plataforma Universal do Windows (UWP) que usam tipos de tempo de execução do Windows.|  
|[Elementos gráficos (C++ AMP)](../../parallel/amp/graphics-cpp-amp.md)|Descreve como usar a biblioteca de gráficos do C++ AMP.|  
|[Passo a passo: multiplicação de matrizes](../../parallel/amp/walkthrough-matrix-multiplication.md)|Demonstra a multiplicação de matriz usando código C++ AMP e tiling.|  
|[Passo a passo: depurando um aplicativo C++ AMP](../../parallel/amp/walkthrough-debugging-a-cpp-amp-application.md)|Explica como criar e depurar um aplicativo que usa a redução paralela para somar uma grande matriz de inteiros.|  
  
## <a name="reference"></a>Referência  

[Referência (C++ AMP)](../../parallel/amp/reference/reference-cpp-amp.md)    
[palavra-chave tile_static](../../cpp/tile-static-keyword.md)    
[restrict (C++ AMP)](../../cpp/restrict-cpp-amp.md)  
  
## <a name="other-resources"></a>Outros recursos  
 
[Programação paralela no Blog de código nativo](http://go.microsoft.com/fwlink/p/?linkid=238472)  
[Projetos de exemplo do C++ AMP para download](http://go.microsoft.com/fwlink/p/?linkid=248508)  
[Analisando código AMP de C++ com o Visualizador de simultaneidade](http://go.microsoft.com/fwlink/p/?linkid=253987&clcid=0x409)