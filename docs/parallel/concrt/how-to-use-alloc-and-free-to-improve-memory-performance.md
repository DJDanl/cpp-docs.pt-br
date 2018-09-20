---
title: 'Como: usar Alloc e Free para melhorar o desempenho de memória | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Alloc and Free, using [Concurrency Runtime]
- Using Alloc and Free [Concurrency Runtime]
ms.assetid: e1fab9e8-a97d-4104-bead-e95958db79f9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0ce828d15d68ade5ba24c3a010e76e3d702f9a83
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46405859"
---
# <a name="how-to-use-alloc-and-free-to-improve-memory-performance"></a>Como usar Alloc e Free para melhorar o desempenho da memória

Este documento mostra como usar o [concurrency::Alloc](reference/concurrency-namespace-functions.md#alloc) e [concurrency::Free](reference/concurrency-namespace-functions.md#free) funções para melhorar o desempenho de memória. Ele compara o tempo necessário para reverter os elementos de uma matriz em paralelo para três diferentes tipos que especificam os `new` e `delete` operadores.

O `Alloc` e `Free` funções são mais úteis quando vários threads chamam frequentemente ambos `Alloc` e `Free`. O tempo de execução mantém um cache de memória separados para cada thread. Portanto, o tempo de execução gerencia a memória sem o uso de bloqueios ou as barreiras de memória.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra três tipos que especificam os `new` e `delete` operadores. O `new_delete` classe usa global `new` e `delete` operadores, o `malloc_free` classe usa o tempo de execução C [malloc](../../c-runtime-library/reference/malloc.md) e [livre](../../c-runtime-library/reference/free.md) funções e o `Alloc_Free` classe usa o tempo de execução de simultaneidade `Alloc` e `Free` funções.

[!code-cpp[concrt-allocators#1](../../parallel/concrt/codesnippet/cpp/how-to-use-alloc-and-free-to-improve-memory-performance_1.cpp)]

## <a name="example"></a>Exemplo

O exemplo a seguir mostra as funções `swap` e `reverse_array`. O `swap` função troca o conteúdo da matriz em que os índices especificados. Aloca memória do heap para a variável temporária. O `reverse_array` função cria uma matriz grande e calcula o tempo necessário para reverter essa matriz várias vezes em paralelo.

[!code-cpp[concrt-allocators#2](../../parallel/concrt/codesnippet/cpp/how-to-use-alloc-and-free-to-improve-memory-performance_2.cpp)]

## <a name="example"></a>Exemplo

A exemplo a seguir mostra a `wmain` função, que calcula o tempo necessário para o `reverse_array` função para agir sobre o `new_delete`, `malloc_free`, e `Alloc_Free` tipos, cada uma delas usa um esquema de alocação de memória diferentes.

[!code-cpp[concrt-allocators#3](../../parallel/concrt/codesnippet/cpp/how-to-use-alloc-and-free-to-improve-memory-performance_3.cpp)]

## <a name="example"></a>Exemplo

Segue o exemplo completo.

[!code-cpp[concrt-allocators#4](../../parallel/concrt/codesnippet/cpp/how-to-use-alloc-and-free-to-improve-memory-performance_4.cpp)]

Este exemplo produz a seguinte saída de exemplo para um computador com quatro processadores.

```Output
Took 2031 ms with new/delete.
Took 1672 ms with malloc/free.
Took 656 ms with Alloc/Free.
```

Neste exemplo, o tipo que usa o `Alloc` e `Free` functions fornece o melhor desempenho de memória porque as `Alloc` e `Free` funções são otimizadas para com frequência, alocando e liberando os blocos de memória de vários threads.

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `allocators.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc allocators.cpp**

## <a name="see-also"></a>Consulte também

[Funções de gerenciamento da memória](../../parallel/concrt/memory-management-functions.md)<br/>
[Função ALLOC](reference/concurrency-namespace-functions.md#alloc)<br/>
[Função Free](reference/concurrency-namespace-functions.md#free)

