---
title: C++ AMP (C++ Accelerated Massive Parallelism)
ms.date: 11/04/2016
helpviewer_keywords:
- C++ AMP (see C++ Accelerated Massive Parallelism)
- C++ Accelerated Massive Parallelism, getting started
ms.assetid: e27824cb-3167-409b-8c3f-a0e476d8f349
ms.openlocfilehash: c9ef7ab816ec0d17b9dc0b569a6f3a43af83cc68
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80167687"
---
# <a name="c-amp-c-accelerated-massive-parallelism"></a>C++ AMP (C++ Accelerated Massive Parallelism)

C++AMP (C++ grande paralelismo acelerado) acelera a execução do seu C++ código aproveitando o hardware paralelo de dados que normalmente está presente como uma GPU (unidade de processamento gráfico) em uma placa gráfica discreta. O C++ modelo de programação amp inclui suporte para matrizes multidimensionais, indexação, transferência de memória e colocação em blocos. Ele também inclui uma biblioteca de funções matemáticas. Você pode usar C++ extensões amp-Language para controlar como os dados são movidos da CPU para a GPU e de volta.

## <a name="related-topics"></a>Tópicos Relacionados

|Title|DESCRIÇÃO|
|-----------|-----------------|
|[Visão geral do C++ AMP](../../parallel/amp/cpp-amp-overview.md)|Descreve os principais recursos do C++ amp e da biblioteca matemática.|
|[Usando lambdas, objetos de função e funções restritas](../../parallel/amp/using-lambdas-function-objects-and-restricted-functions.md)|Descreve como usar expressões lambda, objetos de função e funções restritas em chamadas para o método [parallel_for_each](reference/concurrency-namespace-functions-amp.md#parallel_for_each) .|
|[Usando blocos](../../parallel/amp/using-tiles.md)|Descreve como usar blocos para acelerar seu C++ código de amp.|
|[Usando objetos accelerator e accelerator_view](../../parallel/amp/using-accelerator-and-accelerator-view-objects.md)|Descreve como usar os aceleradores para personalizar a execução do seu código na GPU.|
|[Usando C++ AMP em aplicativos UWP](../../parallel/amp/using-cpp-amp-in-windows-store-apps.md)|Descreve como usar C++ os aplicativos de AMP in plataforma universal do Windows (UWP) que usam Windows Runtime tipos.|
|[Elementos gráficos (C++ AMP)](../../parallel/amp/graphics-cpp-amp.md)|Descreve como usar a biblioteca C++ do amp Graphics.|
|[Passo a passo: multiplicação de matrizes](../../parallel/amp/walkthrough-matrix-multiplication.md)|Demonstra a multiplicação de C++ matriz usando amp Code e disposição em blocos.|
|[Passo a passo: depurando um aplicativo C++ AMP](../../parallel/amp/walkthrough-debugging-a-cpp-amp-application.md)|Explica como criar e depurar um aplicativo que usa a redução paralela para somar uma grande matriz de inteiros.|

## <a name="reference"></a>Referência

[Referência (C++ AMP)](../../parallel/amp/reference/reference-cpp-amp.md)<br/>
[Palavra-chave tile_static](../../cpp/tile-static-keyword.md)<br/>
[restrict (C++ AMP)](../../cpp/restrict-cpp-amp.md)

## <a name="other-resources"></a>Outros recursos

[Programação paralela no blog de código nativo](https://go.microsoft.com/fwlink/p/?linkid=238472)<br/>
[C++Projetos de exemplo AMP para download](https://go.microsoft.com/fwlink/p/?linkid=248508)<br/>
[Analisando C++ o amp Code com o Visualizador de simultaneidade](https://blogs.msdn.microsoft.com/nativeconcurrency/2012/03/09/analyzing-c-amp-code-with-the-concurrency-visualizer/)
