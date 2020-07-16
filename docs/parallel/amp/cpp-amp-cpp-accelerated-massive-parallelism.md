---
title: C++ AMP (C++ Accelerated Massive Parallelism)
ms.date: 11/04/2016
helpviewer_keywords:
- C++ AMP (see C++ Accelerated Massive Parallelism)
- C++ Accelerated Massive Parallelism, getting started
ms.assetid: e27824cb-3167-409b-8c3f-a0e476d8f349
ms.openlocfilehash: 516b69a0371ceb9365e79d5465879711289076c0
ms.sourcegitcommit: 6b3d793f0ef3bbb7eefaf9f372ba570fdfe61199
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/15/2020
ms.locfileid: "86404854"
---
# <a name="c-amp-c-accelerated-massive-parallelism"></a>C++ AMP (C++ Accelerated Massive Parallelism)

C++ AMP (C++ Accelerated Massive Parallelism) acelera a execução do seu código C++ aproveitando o hardware paralelo de dados que normalmente está presente como uma GPU (unidade de processamento gráfico) em uma placa gráfica discreta. O modelo de programação de C++ AMP inclui suporte para matrizes multidimensionais, indexação, transferência de memória e colocação em blocos. Ele também inclui uma biblioteca de funções matemáticas. Você pode usar C++ AMP extensões de idioma para controlar como os dados são movidos da CPU para a GPU e de volta.

## <a name="related-topics"></a>Tópicos Relacionados

|Título|Descrição|
|-----------|-----------------|
|[Visão geral de C++ AMP](../../parallel/amp/cpp-amp-overview.md)|Descreve os principais recursos de C++ AMP e a biblioteca matemática.|
|[Usando lambdas, objetos de função e funções restritas](../../parallel/amp/using-lambdas-function-objects-and-restricted-functions.md)|Descreve como usar expressões lambda, objetos de função e funções restritas em chamadas para o método [parallel_for_each](reference/concurrency-namespace-functions-amp.md#parallel_for_each) .|
|[Usando blocos](../../parallel/amp/using-tiles.md)|Descreve como usar blocos para acelerar seu código de C++ AMP.|
|[Usando o acelerador e objetos accelerator_view](../../parallel/amp/using-accelerator-and-accelerator-view-objects.md)|Descreve como usar os aceleradores para personalizar a execução do seu código na GPU.|
|[Usando C++ AMP em aplicativos UWP](../../parallel/amp/using-cpp-amp-in-windows-store-apps.md)|Descreve como usar C++ AMP em aplicativos Plataforma Universal do Windows (UWP) que usam Windows Runtime tipos.|
|[Elementos gráficos (C++ AMP)](../../parallel/amp/graphics-cpp-amp.md)|Descreve como usar a biblioteca de gráficos C++ AMP.|
|[Walkthrough: multiplicação de matriz](../../parallel/amp/walkthrough-matrix-multiplication.md)|Demonstra a multiplicação de matriz usando código de C++ AMP e colocação em blocos.|
|[Walkthrough: Depurando um aplicativo C++ AMP](../../parallel/amp/walkthrough-debugging-a-cpp-amp-application.md)|Explica como criar e depurar um aplicativo que usa a redução paralela para somar uma grande matriz de inteiros.|

## <a name="reference"></a>Referência

[Referência (C++ AMP)](../../parallel/amp/reference/reference-cpp-amp.md)<br/>
[Palavra-chave tile_static](../../cpp/tile-static-keyword.md)<br/>
[restrita (C++ AMP)](../../cpp/restrict-cpp-amp.md)

## <a name="other-resources"></a>Outros recursos

[Programação paralela no blog de código nativo](https://go.microsoft.com/fwlink/p/?linkid=238472)<br/>
[C++ AMP projetos de exemplo para download](https://go.microsoft.com/fwlink/p/?linkid=248508)<br/>
[Analisando C++ AMP código com o Visualizador de simultaneidade](/archive/blogs/nativeconcurrency/analyzing-c-amp-code-with-the-concurrency-visualizer)
