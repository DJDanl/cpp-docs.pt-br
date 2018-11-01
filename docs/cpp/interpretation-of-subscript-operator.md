---
title: Interpretação do operador subscrito
ms.date: 08/27/2018
helpviewer_keywords:
- subscript operator [C++], interpretation of
- arrays [C++], subscripting
- interpreting subscript operators [C++]
- operators [C++], interpretation of subscript
ms.assetid: 8852ca18-9d5b-43f7-b8bd-abc89364fbf2
ms.openlocfilehash: 1c3d5bca66cb294503805fd5b7691331ac380ae5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50446599"
---
# <a name="interpretation-of-subscript-operator"></a>Interpretação do operador subscrito

Como outros operadores, o operador subscrito (**\[]**) pode ser redefinido pelo usuário. O comportamento padrão do operador subscrito, se não sobrecarregado, é combinar o nome da matriz e o subscrito usando o seguinte método:

\*((*nome da matriz*) + (*subscrito*))

Como em qualquer adição que envolve tipos do ponteiro, o dimensionamento é executado automaticamente para se ajustar ao tamanho do tipo. Portanto, o valor resultante não é *subscrito* bytes de origem de *nome da matriz*; em vez disso, é o *subscrito*º elemento da matriz. (Para obter mais informações sobre essa conversão, consulte [operadores aditivos](../cpp/additive-operators-plus-and.md).)

De maneira semelhante, para matrizes multidimensionais, o endereço é derivado usando o seguinte método:

((*nome da matriz*) + (*subscrito*1 \* *max*2 \* *máxima*3 \* ... \* *max*n) + (*subscrito*2 \* *max*3 \* ... \* *max*n) +... + *subscrito*n))

## <a name="see-also"></a>Consulte também

[Matrizes](../cpp/arrays-cpp.md)<br/>
