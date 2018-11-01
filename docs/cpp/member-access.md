---
title: Acesso de membro
ms.date: 11/04/2016
helpviewer_keywords:
- member-selection operators [C++]
- pointers, smart
- member access, overloaded operators
- operator overloading [C++], member access operators
- smart pointers, definition
- smart pointers
ms.assetid: 8c7b2c43-eb92-4d42-9a8e-61aa37d71333
ms.openlocfilehash: 34527f818b135fd5af629ebb69feaffd03b715fc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50617275"
---
# <a name="member-access"></a>Acesso de membro

Acesso de membro de classe pode ser controlado pela sobrecarga de operador de acesso a membro (**->**). Esse operador é considerado um operador unário nesse uso, e a função sobrecarregada do operador deve ser uma função de membro da classe. Portanto, a declaração dessa função é:

## <a name="syntax"></a>Sintaxe

```
class-type *operator->()
```

## <a name="remarks"></a>Comentários

em que *tipo de classe* é o nome da classe à qual esse operador pertence. A função do operador de acesso do membro deve ser uma função de membro não estático.

Esse operador é usado (frequentemente em conjunto com o operador de desreferência de ponteiro) para implementar "ponteiros inteligentes" que validam os ponteiros antes da desreferência ou do uso da contagem.

O elemento de linguagem **.** operador de acesso de membro não pode ser sobrecarregado.

## <a name="see-also"></a>Consulte também

[Sobrecarga de Operador](../cpp/operator-overloading.md)