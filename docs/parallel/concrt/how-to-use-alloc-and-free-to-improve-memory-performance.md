---
title: Como usar Alloc e Free para melhorar o desempenho da memória
ms.date: 11/04/2016
helpviewer_keywords:
- Alloc and Free, using [Concurrency Runtime]
- Using Alloc and Free [Concurrency Runtime]
ms.assetid: e1fab9e8-a97d-4104-bead-e95958db79f9
ms.openlocfilehash: e5e5207fe435e73df60b757d4f595aacbb70fe72
ms.sourcegitcommit: 94893973211d0b254c8bcdcf0779997dcc136b0c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/28/2020
ms.locfileid: "91414016"
---
# <a name="how-to-use-alloc-and-free-to-improve-memory-performance"></a>Como usar Alloc e Free para melhorar o desempenho da memória

Este documento mostra como usar as funções [Concurrency:: Alloc](reference/concurrency-namespace-functions.md#alloc) e [Concurrency:: Free](reference/concurrency-namespace-functions.md#free) para melhorar o desempenho da memória. Ele compara o tempo necessário para reverter os elementos de uma matriz em paralelo para três tipos diferentes que especificam os `new` `delete` operadores e.

As `Alloc` `Free` funções e são mais úteis quando vários threads costumam chamar `Alloc` e `Free` . O tempo de execução mantém um cache de memória separado para cada thread; Portanto, o tempo de execução gerencia a memória sem o uso de bloqueios ou barreiras de memória.

## <a name="example-types-that-specify-new-and-delete-operators"></a>Exemplo: tipos que especificam operadores New e Delete

O exemplo a seguir mostra três tipos que especificam `new` os `delete` operadores e. A `new_delete` classe usa os `new` operadores global e `delete` , a `malloc_free` classe usa as funções [malloc](../../c-runtime-library/reference/malloc.md) e [Free](../../c-runtime-library/reference/free.md) de tempo de execução C e a `Alloc_Free` classe usa a tempo de execução de simultaneidade `Alloc` e as `Free` funções.

[!code-cpp[concrt-allocators#1](../../parallel/concrt/codesnippet/cpp/how-to-use-alloc-and-free-to-improve-memory-performance_1.cpp)]

## <a name="example-swap-and-reverse_array-functions"></a>Exemplo: funções de permuta e reverse_array

O exemplo a seguir mostra as funções `swap` e `reverse_array`. A `swap` função troca o conteúdo da matriz nos índices especificados. Ele aloca memória do heap para a variável temporária. A `reverse_array` função cria uma matriz grande e calcula o tempo necessário para reverter essa matriz várias vezes em paralelo.

[!code-cpp[concrt-allocators#2](../../parallel/concrt/codesnippet/cpp/how-to-use-alloc-and-free-to-improve-memory-performance_2.cpp)]

## <a name="example-wmain-function"></a>Exemplo: função wmain

O exemplo a seguir mostra a `wmain` função, que calcula o tempo necessário para que a `reverse_array` função atue nos `new_delete` `malloc_free` tipos, e `Alloc_Free` , cada um deles usando um esquema de alocação de memória diferente.

[!code-cpp[concrt-allocators#3](../../parallel/concrt/codesnippet/cpp/how-to-use-alloc-and-free-to-improve-memory-performance_3.cpp)]

## <a name="complete-code-example"></a>Exemplo de código completo

Veja a seguir o exemplo completo.

[!code-cpp[concrt-allocators#4](../../parallel/concrt/codesnippet/cpp/how-to-use-alloc-and-free-to-improve-memory-performance_4.cpp)]

Este exemplo produz a seguinte saída de exemplo para um computador que tem quatro processadores.

```Output
Took 2031 ms with new/delete.
Took 1672 ms with malloc/free.
Took 656 ms with Alloc/Free.
```

Neste exemplo, o tipo que usa as `Alloc` funções e `Free` fornece o melhor desempenho de memória porque as `Alloc` `Free` funções e são otimizadas para alocar e liberar blocos de memória com frequência de vários threads.

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `allocators.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **cl.exe alocadores/EHsc. cpp**

## <a name="see-also"></a>Confira também

[Funções de gerenciamento de memória](../../parallel/concrt/memory-management-functions.md)<br/>
[Função Alloc](reference/concurrency-namespace-functions.md#alloc)<br/>
[Função Free](reference/concurrency-namespace-functions.md#free)
