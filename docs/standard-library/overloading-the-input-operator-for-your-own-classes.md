---
title: Sobrecarregando o operador &gt;&gt; para as suas próprias classes
ms.date: 11/04/2016
helpviewer_keywords:
- operator>>
- operator>>, overloading for your own classes
- operator >>, overloading for your own classes
ms.assetid: 40dab4e0-3f97-4745-9cc8-b86e740fa246
ms.openlocfilehash: 672dfb7ec40b2f18cbde0adc92522d3194a5e738
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68450131"
---
# <a name="overloading-the-gtgt-operator-for-your-own-classes"></a>Sobrecarregando o operador &gt;&gt; para as suas próprias classes

Fluxos de entrada usam o operador de extração (`>>`) para os tipos padrão. Você pode escrever operadores de extração semelhantes para seus próprios tipos. Seu êxito depende do uso preciso do espaço em branco.

Veja aqui um exemplo de um operador de extração para a classe `Date` apresentada anteriormente:

```cpp
istream& operator>> (istream& is, Date& dt)
{
    is>> dt.mo>> dt.da>> dt.yr;
    return is;
}
```

## <a name="see-also"></a>Consulte também

[Fluxos de entrada](../standard-library/input-streams.md)
