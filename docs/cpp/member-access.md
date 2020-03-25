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
ms.openlocfilehash: 12ea612625e21a8a13021b75e92f3752b0b5ce80
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80179413"
---
# <a name="member-access"></a>Acesso de membro

O acesso de membro de classe pode ser controlado pela sobrecarga do operador de acesso de membro ( **->** ). Esse operador é considerado um operador unário nesse uso, e a função sobrecarregada do operador deve ser uma função de membro da classe. Portanto, a declaração dessa função é:

## <a name="syntax"></a>Sintaxe

```
class-type *operator->()
```

## <a name="remarks"></a>Comentários

em que *tipo de classe* é o nome da classe à qual esse operador pertence. A função do operador de acesso do membro deve ser uma função de membro não estático.

Esse operador é usado (frequentemente em conjunto com o operador de desreferência de ponteiro) para implementar "ponteiros inteligentes" que validam os ponteiros antes da desreferência ou do uso da contagem.

O elemento de linguagem **.** o operador de acesso de membro não pode ser sobrecarregado.

## <a name="see-also"></a>Confira também

[Sobrecarga de Operador](../cpp/operator-overloading.md)
