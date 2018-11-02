---
title: Operadores de conversão
ms.custom: index-page
ms.date: 11/04/2016
helpviewer_keywords:
- operators [C++], casting
- casting operators [C++]
ms.assetid: 16240348-26bc-4f77-8eab-57253f00ce52
ms.openlocfilehash: 4d6c8a0dc448e08ae2f344faeeb27756cdd27eff
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50549737"
---
# <a name="casting-operators"></a>Operadores de conversão

Há vários operadores de conversão específicos à linguagem C++. Esses operadores são destinados a remover qualquer ambiguidade e perigo inerente no estilo antigo de conversões da linguagem C. Esses operadores são:

- [dynamic_cast](../cpp/dynamic-cast-operator.md) usado para a conversão de tipos polimórficos.

- [static_cast](../cpp/static-cast-operator.md) usado para a conversão de tipos não polimórficos.

- [const_cast](../cpp/const-cast-operator.md) usado para remover o **const**, **volátil**, e **unaligned** atributos.

- [reinterpret_cast](../cpp/reinterpret-cast-operator.md) usado para a reinterpretação simples de bits.

- [Safe_cast](../windows/safe-cast-cpp-component-extensions.md) usado para produzir MSIL verificável.

Use **const_cast** e **reinterpret_cast** como último recurso, pois esses operadores apresentam os mesmos perigos das conversões antigas. No entanto, ainda são necessários para substituir completamente as conversões antigas.

## <a name="see-also"></a>Consulte também

[Conversão](../cpp/casting.md)