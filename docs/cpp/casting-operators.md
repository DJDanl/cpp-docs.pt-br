---
title: Operadores de conversão | Microsoft Docs
ms.custom: index-page
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- operators [C++], casting
- casting operators [C++]
ms.assetid: 16240348-26bc-4f77-8eab-57253f00ce52
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 341812299d8cf95e351a087e9957dc0425cb25b2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46075937"
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