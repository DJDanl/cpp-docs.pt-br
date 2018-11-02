---
title: void (C++)
ms.date: 11/04/2016
f1_keywords:
- void_cpp
helpviewer_keywords:
- void keyword [C++]
- functions [C++], void
- pointers, void
ms.assetid: d203edba-38e6-4056-8b89-011437351057
ms.openlocfilehash: cb4be000c3c41862d5b4df766d21ae1cddeb6838
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50594100"
---
# <a name="void-c"></a>void (C++)

Quando usado como um tipo de retorno de função, o **void** palavra-chave especifica que a função não retorna um valor. Quando usado para a lista de parâmetros de uma função, um item nulo especifica que a função não usa parâmetros. Quando usado em declaração de um ponteiro nulo, especifica que o ponteiro é “universal”.

Se for do tipo de um ponteiro `void *`, o ponteiro pode apontar para qualquer variável que não é declarado com o **const** ou **volátil** palavra-chave. Um ponteiro nulo não pode ter a referência removida a menos que seja convertido para outro tipo. Um ponteiro nulo pode ser convertido em outro tipo de ponteiro de dados.

Um ponteiro nulo pode apontar para uma função, mas não para um membro da classe em C++.

Você não pode declarar uma variável de tipo nulo.

## <a name="example"></a>Exemplo

```cpp
// void.cpp
void vobject;   // C2182
void *pv;   // okay
int *pint; int i;
int main() {
   pv = &i;
   // Cast optional in C required in C++
   pint = (int *)pv;
}
```

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Tipos fundamentais](../cpp/fundamental-types-cpp.md)