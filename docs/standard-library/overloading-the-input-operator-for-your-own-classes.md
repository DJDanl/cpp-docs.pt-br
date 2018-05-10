---
title: Sobrecarregando o operador &gt;&gt; para as suas próprias classes | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- operator>>
- operator>>, overloading for your own classes
- operator >>, overloading for your own classes
ms.assetid: 40dab4e0-3f97-4745-9cc8-b86e740fa246
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d98372009090b0241d9f0190a1d53a9416bbd7ba
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
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

[Fluxos de entrada](../standard-library/input-streams.md)<br/>
