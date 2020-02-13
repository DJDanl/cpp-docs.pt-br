---
title: Como usar Alloc e Free para melhorar o desempenho da memória
ms.date: 11/04/2016
helpviewer_keywords:
- Alloc and Free, using [Concurrency Runtime]
- Using Alloc and Free [Concurrency Runtime]
ms.assetid: e1fab9e8-a97d-4104-bead-e95958db79f9
ms.openlocfilehash: 8438e833262d42c6083f48f759501c573a35c772
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142782"
---
# <a name="how-to-use-alloc-and-free-to-improve-memory-performance"></a>Como usar Alloc e Free para melhorar o desempenho da memória

Este documento mostra como usar as funções [Concurrency:: Alloc](reference/concurrency-namespace-functions.md#alloc) e [Concurrency:: Free](reference/concurrency-namespace-functions.md#free) para melhorar o desempenho da memória. Ele compara o tempo necessário para reverter os elementos de uma matriz em paralelo para três tipos diferentes que especificam o `new` e `delete` operadores.

As funções `Alloc` e `Free` são mais úteis quando vários threads freqüentemente chamam `Alloc` e `Free`. O tempo de execução mantém um cache de memória separado para cada thread; Portanto, o tempo de execução gerencia a memória sem o uso de bloqueios ou barreiras de memória.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra três tipos que especificam os operadores `new` e `delete`. A classe `new_delete` usa os operadores global `new` e `delete`, a classe `malloc_free` usa as funções [malloc](../../c-runtime-library/reference/malloc.md) e [Free](../../c-runtime-library/reference/free.md) de tempo de execução C e a classe `Alloc_Free` usa as funções tempo de execução de simultaneidade `Alloc` e `Free`.

[!code-cpp[concrt-allocators#1](../../parallel/concrt/codesnippet/cpp/how-to-use-alloc-and-free-to-improve-memory-performance_1.cpp)]

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra as funções `swap` e `reverse_array`. A função `swap` troca o conteúdo da matriz nos índices especificados. Ele aloca memória do heap para a variável temporária. A função `reverse_array` cria uma matriz grande e calcula o tempo necessário para reverter essa matriz várias vezes em paralelo.

[!code-cpp[concrt-allocators#2](../../parallel/concrt/codesnippet/cpp/how-to-use-alloc-and-free-to-improve-memory-performance_2.cpp)]

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir mostra a função `wmain`, que calcula o tempo necessário para a função `reverse_array` atuar nos tipos `new_delete`, `malloc_free`e `Alloc_Free`, cada um deles usando um esquema de alocação de memória diferente.

[!code-cpp[concrt-allocators#3](../../parallel/concrt/codesnippet/cpp/how-to-use-alloc-and-free-to-improve-memory-performance_3.cpp)]

## <a name="example"></a>{1&gt;Exemplo&lt;1}

Veja a seguir o exemplo completo.

[!code-cpp[concrt-allocators#4](../../parallel/concrt/codesnippet/cpp/how-to-use-alloc-and-free-to-improve-memory-performance_4.cpp)]

Este exemplo produz a seguinte saída de exemplo para um computador que tem quatro processadores.

```Output
Took 2031 ms with new/delete.
Took 1672 ms with malloc/free.
Took 656 ms with Alloc/Free.
```

Neste exemplo, o tipo que usa as funções `Alloc` e `Free` fornece o melhor desempenho de memória porque as funções `Alloc` e `Free` são otimizadas para alocar e liberar com frequência blocos de memória de vários threads.

## <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `allocators.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc alocadores. cpp**

## <a name="see-also"></a>Consulte também

[Funções de gerenciamento da memória](../../parallel/concrt/memory-management-functions.md)<br/>
[Função de alocação](reference/concurrency-namespace-functions.md#alloc)<br/>
[Função Free](reference/concurrency-namespace-functions.md#free)
