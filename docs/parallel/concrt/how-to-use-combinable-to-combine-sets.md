---
title: Como usar combinável para combinar conjuntos
ms.date: 11/04/2016
helpviewer_keywords:
- combinable class, example
- combining sets with combinable [Concurrency Runtime]
ms.assetid: 66ffe8e3-6bbb-4e9f-b790-b612922a68a7
ms.openlocfilehash: 7ccbb3e8bad5c4d3b6f4177afbfdba3e200681a5
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142125"
---
# <a name="how-to-use-combinable-to-combine-sets"></a>Como usar combinável para combinar conjuntos

Este tópico mostra como usar a classe [Concurrency:: combinável](../../parallel/concrt/reference/combinable-class.md) para calcular o conjunto de números primos.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir computa o conjunto de números primos duas vezes. Cada computação armazena o resultado em um objeto [std:: conjunto](../../standard-library/bitset-class.md) . O exemplo primeiro computa o conjunto em série e, em seguida, computa o conjunto em paralelo. O exemplo também imprime no console o tempo necessário para executar os dois cálculos.

Este exemplo usa o algoritmo [Concurrency::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for) e um objeto `combinable` para gerar conjuntos de threads locais. Em seguida, ele usa o método [Concurrency:: Combining:: combine_each](reference/combinable-class.md#combine_each) para combinar os conjuntos de threads locais no conjunto final.

[!code-cpp[concrt-parallel-combine-primes#1](../../parallel/concrt/codesnippet/cpp/how-to-use-combinable-to-combine-sets_1.cpp)]

A saída de exemplo a seguir é para um computador com quatro processadores.

```Output
serial time: 312 ms

parallel time: 78 ms
```

## <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `parallel-combine-primes.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc Parallel-Combine-Primes. cpp**

## <a name="see-also"></a>Consulte também

[Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)<br/>
[Classe combinable](../../parallel/concrt/reference/combinable-class.md)<br/>
[Método combinable:: combine_each](reference/combinable-class.md#combine_each)
