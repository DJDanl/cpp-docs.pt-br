---
title: 'Como: usar Combinável para combinar conjuntos | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- combinable class, example
- combining sets with combinable [Concurrency Runtime]
ms.assetid: 66ffe8e3-6bbb-4e9f-b790-b612922a68a7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 69f48ed099fe033ba1847a3414ed8e5c5ce88f71
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46433667"
---
# <a name="how-to-use-combinable-to-combine-sets"></a>Como usar combinável para combinar conjuntos

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

