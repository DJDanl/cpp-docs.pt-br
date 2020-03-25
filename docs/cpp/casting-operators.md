---
title: Operadores de conversão
ms.custom: index-page
ms.date: 11/04/2016
helpviewer_keywords:
- operators [C++], casting
- casting operators [C++]
ms.assetid: 16240348-26bc-4f77-8eab-57253f00ce52
ms.openlocfilehash: eac274a0207be675b8d13532c3110c6e71bd55c9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80190087"
---
# <a name="casting-operators"></a>Operadores de conversão

Há vários operadores de conversão específicos à linguagem C++. Esses operadores são destinados a remover qualquer ambiguidade e perigo inerente no estilo antigo de conversões da linguagem C. Esses operadores são:

- [dynamic_cast](../cpp/dynamic-cast-operator.md) Usado para conversão de tipos polimórficos.

- [static_cast](../cpp/static-cast-operator.md) Usado para conversão de tipos nonpolymorphic.

- [const_cast](../cpp/const-cast-operator.md) Usado para remover os atributos **const**, **volatile**e **__unaligned** .

- [reinterpret_cast](../cpp/reinterpret-cast-operator.md) Usado para reinterpretação simples de bits.

- [safe_cast](../extensions/safe-cast-cpp-component-extensions.md) Usado em C++/CLI para produzir MSIL verificável.

Use **const_cast** e **reinterpret_cast** como último recurso, já que esses operadores apresentam os mesmos perigos que as conversões de estilo antigas. No entanto, ainda são necessários para substituir completamente as conversões antigas.

## <a name="see-also"></a>Confira também

[Conversão](../cpp/casting.md)
