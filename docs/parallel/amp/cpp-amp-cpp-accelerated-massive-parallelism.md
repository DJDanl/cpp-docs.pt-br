---
title: C++ AMP (C++ Accelerated Massive Parallelism)
ms.date: 11/04/2016
helpviewer_keywords:
- C++ AMP (see C++ Accelerated Massive Parallelism)
- C++ Accelerated Massive Parallelism, getting started
ms.assetid: e27824cb-3167-409b-8c3f-a0e476d8f349
ms.openlocfilehash: f8ac71023f66868a66fb8c54a5e86678225378a1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50613168"
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

[Referência (C++ AMP)](../../parallel/amp/reference/reference-cpp-amp.md)<br/>
[Palavra-chave tile_static](../../cpp/tile-static-keyword.md)<br/>
[restrict (C++ AMP)](../../cpp/restrict-cpp-amp.md)

## <a name="other-resources"></a>Outros recursos

[Programação paralela no Blog de código nativo](http://go.microsoft.com/fwlink/p/?linkid=238472)<br/>
[Projetos de exemplo do C++ AMP para download](http://go.microsoft.com/fwlink/p/?linkid=248508)<br/>
[Analisando código AMP de C++ com o Visualizador de simultaneidade](https://blogs.msdn.microsoft.com/nativeconcurrency/2012/03/09/analyzing-c-amp-code-with-the-concurrency-visualizer/)