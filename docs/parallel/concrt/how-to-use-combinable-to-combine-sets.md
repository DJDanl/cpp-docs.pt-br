---
title: 'Como: Usar Combinável para combinar conjuntos'
ms.date: 11/04/2016
helpviewer_keywords:
- combinable class, example
- combining sets with combinable [Concurrency Runtime]
ms.assetid: 66ffe8e3-6bbb-4e9f-b790-b612922a68a7
ms.openlocfilehash: bf8a5bee65ea0ba1718c1d4d436b6af3e0b95961
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62345572"
---
# <a name="how-to-use-combinable-to-combine-sets"></a>Como: Usar Combinável para combinar conjuntos

Este tópico mostra como usar o [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe para calcular o conjunto de números primos.

## <a name="example"></a>Exemplo

O exemplo a seguir calcula o conjunto de números primos duas vezes. Cada computação armazena o resultado em uma [std::bitset](../../standard-library/bitset-class.md) objeto. O exemplo primeiro calcula o conjunto em série e, em seguida, calcula o conjunto em paralelo. O exemplo também imprime no console a hora em que é necessária executar ambos os cálculos.

Este exemplo usa o [Concurrency:: parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo e um `combinable` objeto para gerar conjuntos de thread local. Ele usa o [concurrency::combinable::combine_each](reference/combinable-class.md#combine_each) método para combinar os conjuntos de thread local em conjunto final.

[!code-cpp[concrt-parallel-combine-primes#1](../../parallel/concrt/codesnippet/cpp/how-to-use-combinable-to-combine-sets_1.cpp)]

A saída de exemplo a seguir é para um computador com quatro processadores.

```Output
serial time: 312 ms

parallel time: 78 ms
```

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `parallel-combine-primes.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc paralelo-combinar-primes.cpp**

## <a name="see-also"></a>Consulte também

[Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)<br/>
[Classe combinable](../../parallel/concrt/reference/combinable-class.md)<br/>
[combinable:: combine_each método](reference/combinable-class.md#combine_each)
